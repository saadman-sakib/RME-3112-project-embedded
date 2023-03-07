#include <Arduino.h>
#include "Servo.h"

const int BUFFER_SIZE = 5;
char buf[BUFFER_SIZE];
Servo servo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(1);
  servo.attach(3);
}

bool on = false;
String data="";

void loop() {

    // check if data is available
    if (Serial.available()) {
      // read the incoming bytes:
      data = Serial.readStringUntil('\r');

      // prints the received data
      // Serial.print("I received: ");
      // for(int i = 0; i < rlen; i++)
      //   Serial.print(buf[i]);
      if(data=="ON"){
        // digitalWrite(13, HIGH);
        servo.write(180);
      } else if (data=="OFF") {
        // digitalWrite(13,LOW);
        servo.write(0);
      }
    }
}

