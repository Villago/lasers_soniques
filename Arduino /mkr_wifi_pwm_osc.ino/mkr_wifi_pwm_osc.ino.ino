/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32

  Example for receiving open sound control (OSC) messages on the ESP8266/ESP32
  Send integers '0' or '1' to the address "/led" to turn on/off the built-in LED of the esp8266.

  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */

#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCData.h>


#include "Adafruit_TLC5947.h"

// How many boards do you have chained?
#define NUM_TLC5974 1

#define data   4
#define clock   5
#define latch   6

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);


char ssid[] = "OSC_2.4G";          // your network SSID (name)
char pass[] = "ableton27";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const IPAddress outIp(10,40,10,105);        // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


OSCErrorCode error;
unsigned int ledState = LOW;              // LOW means led is *on*

void setup() {

  Serial.begin(115200);
  tlc.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
}


void led(OSCMessage &msg) {
  Serial.print("/led: ");
  for (int i=0;i<24;i++) {
    tlc.setPWM(i,msg.getInt(i) );
    Serial.print( msg.getInt(i) );
    Serial.print(" ");
  }  
  Serial.println();
  tlc.write();
}

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/led", led);
    } 
  else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}
