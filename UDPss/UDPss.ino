#include "_WiFi.h"
#include "_udp.h"

unsigned long lastTxTime = 0;
unsigned long txInterval = 100;

int c = 0;
float x = 0;
float y = 0;
float z = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  startAP("UDPss", "udpsspassword");
  beginSS_UDP();
}

void loop() {

  if (millis() > lastTxTime + txInterval) {
    lastTxTime = millis();

    x = sin(c / 90.0);
    y = cos(c / 90.0);
    z = tan(c / 90.0);

    String dati = "";
    dati = String(c) + "," + String(x) + "," + String(y) + "," + String(z);

    if (transmit) {
      Serial.println(dati);
      sendStringSS_UDP(dati);
      c = c + 1;
    }
  }

  receiveStringSS_UDP();
}
