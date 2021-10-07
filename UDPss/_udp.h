#include <WiFiUdp.h>
WiFiUDP Udp;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

IPAddress remoteAddress;
unsigned int remotePort;
bool transmit = false;

#define LOCAL_PORT 6977

void sendStringSS_UDP(String s) {
  //if ( transmit ) {
    s = "/*" + s + "*/";
    //Udp.beginPacket(REMOTE_HOST, REMOTE_PORT);
    Udp.beginPacket(remoteAddress, remotePort);
    Udp.write(s.c_str());
    Udp.write("\n");
    Udp.endPacket();
  //}
}

void receiveStringSS_UDP() {
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    remoteAddress = Udp.remoteIP();
    remotePort = Udp.remotePort();
    for (int i = 0; i < 4; i++)
    {
      Serial.print(remoteAddress[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);
    if ( packetBuffer[0] == '+') {
      Serial.println("Starting send data.");
      transmit = true;
    } else if ( packetBuffer[0] == '-') {
      Serial.println("Stop send data.");
      transmit = false;
    }
  }
}

void beginSS_UDP() {
  Udp.begin(LOCAL_PORT);
}
