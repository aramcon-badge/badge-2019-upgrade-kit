#define LED PB1

#define GPIO1 PA6
#define GPIO2 PA7

const byte buttons[] = {
  PA0, PA1, PA2, PA3, PA4
};

void setup() {
  pinMode(LED, OUTPUT);
  for (byte i = 0; i < sizeof(buttons); i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

bool ledState = false;

void loop() {
  digitalWrite(LED, !ledState);
  for (byte i = 0; i < sizeof(buttons); i++) {
    if (!digitalRead(buttons[i])) {
      ledState  = !ledState;
      delay(10);
      while (!digitalRead(buttons[i]));
    }
  }
}
