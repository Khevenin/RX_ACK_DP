/**
 * @Autor: khevenin
 * @Date:23.01.2020
 * */
#include <Arduino.h>
#include "checkMove.h"
#include "rescale.h"

void moveDecide(uint8_t x, uint8_t);

void forward(uint8_t y);
void reverse(uint8_t y);
void left(uint8_t x);
void right(uint8_t x);
void stop();

void forwardRight(uint8_t x, uint8_t y);
void forwardLeft(uint8_t x, uint8_t y);

void reversRight(uint8_t x, uint8_t y);
void reversLeft(uint8_t x, uint8_t y);
