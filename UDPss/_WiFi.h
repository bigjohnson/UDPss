boolean DEBUG_WIFI = true;

//Wi-Fi
#include <ESP8266WiFi.h>  // built in ESP8266 Core

IPAddress AP_local_IP(192, 168, 42, 254);
IPAddress AP_gateway(192, 168, 42, 254);
IPAddress AP_subnet(255, 255, 255, 0);

void startAP(String APssid , String APpassword) {
  WiFi.setOutputPower(20.5);
  WiFi.mode(WIFI_AP);

  Serial.println();
  Serial.print("Configuring access point: " + APssid + " ");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAPConfig(AP_local_IP, AP_gateway, AP_subnet);
  if (WiFi.softAP(APssid.c_str(), APpassword.c_str(), 1, false, 8)) { //ssid,pass,channel,hidden, clients
    Serial.println("OK");
  } else {
    Serial.println("ERROR");
  }
  delay(200);
  Serial.println("AP IP address: " + WiFi.softAPIP().toString());

}
