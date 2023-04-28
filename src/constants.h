#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <Servo.h>
#include "CustomSocketIoClient.h"

String SOCKET_HOST = "10.0.0.2";
const int SOCKET_PORT = 3001;

CustomSocketIoClient socket;
WiFiManager wifiManager;
Servo servo;