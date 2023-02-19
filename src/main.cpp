#include <Arduino.h>

const int BUFFER_SIZE = 4;
char buf[BUFFER_SIZE];

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(1);
}

bool on = false;

void loop() {

    // check if data is available
    if (Serial.available() > 0) {
      // read the incoming bytes:
      int rlen = Serial.readBytes(buf, BUFFER_SIZE);

      // prints the received data
      // Serial.print("I received: ");
      // for(int i = 0; i < rlen; i++)
      //   Serial.print(buf[i]);
      if(buf[1]=='N'){
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13,LOW);
      }
    }
}


// void loop() {

// }