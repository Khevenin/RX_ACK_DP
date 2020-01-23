#include <Arduino.h>
#include <RF24.h>
#include <SPI.h>
#include <nRF24l01.h>
#include <printf.h>

#include "definedPins.h"
#include "driveModule.h"

#define TX_BUF_SIZE 32     //Size of TX buffer
#define RX_BUF_SIZE 32     //Size of RX buffer
#define ADDRESS_BUF_SIZE 5 //Size of buffer with pipeline address
#define TO_SEND_SIZE 5     //Size of data to send

const uint8_t addressRX[ADDRESS_BUF_SIZE] = {'P', 'I', 'L', 'O', 'T'};
const uint8_t addressTX[ADDRESS_BUF_SIZE] = {'S', 'L', 'A', 'V', 'E'};

uint8_t bufferTX[TX_BUF_SIZE];
uint8_t bufferRX[RX_BUF_SIZE];

uint32_t ackCounter = 0;
uint32_t *pAckCounter = &ackCounter;

uint8_t axisX = 128; //data from joystick
uint8_t axisY = 128;
uint8_t *pAxisX = &axisX;
uint8_t *paxisY = &axisY;

RF24 RX(CE, CSN); //set CE, CSN pins

/* funtions's prototypes */
void resetShort(uint8_t *buf, size_t size);
void printBuffer(uint8_t *buf, size_t size);
void updateCounter(uint32_t *counter);

void setup()
{

  Serial.begin(115200);
  Serial.println("Serial port init done.");

  /* RF config */
  Serial.println("RF init start.\n");
  RX.begin();
  RX.setPALevel(RF24_PA_LOW); //set Power Amp output power
  Serial.println("Set PA power.");
  RX.setDataRate(RF24_250KBPS); //set Data Rate of speed tramission
  Serial.println("Set data rate.");
  RX.setChannel(0x64); //set Channel
  Serial.println("Set RF channel.");

  RX.setRetries(4, 3); //set Retries of package trasmission
  Serial.println("Set retries feature.");
  RX.setCRCLength(RF24_CRC_8);
  Serial.println("Set CRC.");

  RX.setAutoAck(1);
  Serial.println("Enable ACK.");
  RX.enableDynamicPayloads();
  Serial.println("Enable Dynamic Payload size.");
  RX.enableAckPayload(); //enable transmission ACK signal with Payload
  Serial.println("Enable ACK payload.");
  RX.enableDynamicPayloads();
  Serial.println("Enable dynamic payload size.");
  Serial.println("nRF24 init done.");

  /* Open pipeline */
  RX.openWritingPipe(addressTX);    //enable pipeline to transmit on TX address
  RX.openReadingPipe(1, addressRX); //enable pipeline to receive from RX address

  Serial.println("nRF24 pipeline addresses done.");

  /* Reset MCU TX and RX buffers */
  resetShort(bufferTX, TX_BUF_SIZE);
  resetShort(bufferRX, RX_BUF_SIZE);
  printBuffer(bufferTX, TX_BUF_SIZE);
  printBuffer(bufferRX, RX_BUF_SIZE);
  Serial.println("TX and RX buffers reset done.\n");
  bufferTX[0] = 65;                                  // 'A'
  bufferTX[1] = 68;                                  // 'D';
  bufferTX[2] = 72;                                  // 'K';                                 //init ACK - Payload message
  bufferTX[4] = 0x0A;                                //EOL
  RX.writeAckPayload(1, bufferTX, sizeof(bufferTX)); //prepare msg to send
  Serial.println("RF transmission start.\n");
  RX.startListening();
  Serial.println("Engines enable.\n");
  digitalWrite(MOTOR_EN_L, HIGH);
  digitalWrite(MOTOR_EN_R, HIGH);
}

void loop()
{
  if (RX.available()) 
  {
    //Receiving
    uint8_t lenghtRX = RX.getDynamicPayloadSize();
    RX.read(bufferRX, lenghtRX);
    //prit recived
    Serial.print("\nReceived data.");
    printBuffer(bufferRX, RX_BUF_SIZE);
    *pAxisX = bufferRX[0];
    *paxisY = bufferRX[1];

    //Transmitting
    bufferTX[3] = ackCounter >> 24;
    bufferTX[4] = ackCounter >> 16;
    bufferTX[5] = ackCounter >> 8;
    bufferTX[6] = ackCounter;
    RX.writeAckPayload(1, &bufferTX, TO_SEND_SIZE);
    Serial.print("\nTransmitted data.");
    printBuffer(bufferTX, TX_BUF_SIZE);
    ackCounter++;
    if (ackCounter == 100000)
    {
      ackCounter;
    }
  }
}

void updateCounter(uint32_t *counter)
{
  *counter++;
  if (*counter == 100000)
    *counter = 0;
}

void printBuffer(uint8_t *buf, size_t size)
{
  Serial.print("\nBuffer content.");
  for (size_t i = 0; i < size; i++)
  {
    Serial.print(buf[i]);
    Serial.print("\t");
    if (i % 2)
    {
      Serial.print("\n");
    }
  }
}

void resetShort(uint8_t *buf, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    buf[i] = 0;
  }
}
