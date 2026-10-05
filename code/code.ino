#include <Encoder.h>

const int step = 25;
const int dir = 26;

const int encoderA = 12;
const int encoderB = 14;

Encoder myEnc(encoderA, encoderB);

void setup() {

  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);

  myEnc.write(0);

}

void loop() {

  long rpm = myEnc.read();

  if (rpm > 0) {

    digitalWrite(dir, HIGH);

    int delayt = 150000 / rpm;

    if (delayt < 1) {
      delayt = 1;
    }

    digitalWrite(step, HIGH);
    delayMicroseconds(delayt);
    digitalWrite(step, LOW);
    delayMicroseconds(delayt);

  } else if (rpm < 0) {

    digitalWrite(dir, LOW);

    int delayt = 150000 / abs(rpm);

    if (delayt < 1) {
      delayt = 1;
    }

    digitalWrite(step, HIGH);
    delayMicroseconds(delayt);
    digitalWrite(step, LOW);
    delayMicroseconds(delayt);

  }

}