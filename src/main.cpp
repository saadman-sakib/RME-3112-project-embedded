#include "constants.h"


void setup() {
	pinMode(5, OUTPUT);
	Serial.begin(9600);
	delay(10);
	servo.attach(15);

	socket.on("initial", [](String payload){
		// Serial.println("");
		// Serial.println("event: test");
		// Serial.printf("payload: %s\n", payload.c_str());
		// Serial.println("");
	});

	socket.on("esp-signal", [](String payload){
		// Serial.println("");
		// Serial.println("event: esp-signal");
		// Serial.printf("payload: %s\n", payload.c_str());
		// Serial.println("");
    if (payload == "ON"){
      servo.write(150);
	  digitalWrite(5, HIGH);
    } if (payload == "OFF"){
      servo.write(0);
	  digitalWrite(5, LOW);
    }

	});

	wifiManager.autoConnect("AutoConnectAP");
    socket.begin(SOCKET_HOST, SOCKET_PORT);
    Serial.println("connected to wifi)");

}


void loop() {
	socket.loop();
	delay(10);
}

