/**
   Badge upgrade kit I2C Controller.

   Copyright (C) 2019, Uri Shaked. Released under the MIT license.
*/

#include <Wire.h>

#define LED PB1

#define GPIO1 PA6
#define GPIO2 PA7

#define I2C_ADDR 0x35

const byte buttons[] = {
  PA0, PA1, PA2, PA3, PA4
};

byte gpioReg = 0;

typedef struct {
  byte btn0: 1;
  byte btn1: 1;
  byte btn2: 1;
  byte btn3: 1;
  byte btn4: 1;
  byte gpio1: 1;
  byte gpio2: 1;
} status_report_t;

void updateGpio() {
  digitalWrite(LED, !(gpioReg & 0x1));
}

void receiveEvent(int count) {
  int i = 0;
  while (Wire.available()) {
    gpioReg = Wire.read();
  }
  updateGpio();
}

void requestEvent() {
  status_report_t status;
  status.btn0 = digitalRead(buttons[0]);
  status.btn1 = digitalRead(buttons[1]);
  status.btn2 = digitalRead(buttons[2]);
  status.btn3 = digitalRead(buttons[3]);
  status.btn4 = digitalRead(buttons[4]);
  status.gpio1 = digitalRead(GPIO1);
  status.gpio2 = digitalRead(GPIO2);

  Wire.write((byte*)&status, 1);
}

void setup() {
  Wire.begin(I2C_ADDR);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  for (byte i = 0; i < sizeof(buttons); i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
}
