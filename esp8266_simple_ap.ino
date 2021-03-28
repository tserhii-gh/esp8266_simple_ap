#include <ESP8266WiFi.h>

#define LED_ONBOARD 2
const char* ssid     = ""; //SSID
const char* password = ""; //PASSWORD

IPAddress local_IP(10, 0, 0, 1);
IPAddress gateway(10, 0, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
    pinMode(LED_ONBOARD, OUTPUT);
    digitalWrite(LED_ONBOARD, HIGH);

    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.mode(WIFI_AP);
    boolean ap = WiFi.softAP(ssid, password, 10, false, 2); // no pass, 13 channel, max 2 connections
}

void loop()
{
    if (WiFi.softAPgetStationNum())
    {
        digitalWrite(LED_ONBOARD, LOW);
        delay(3000);
    }
    else
    {
        digitalWrite(LED_ONBOARD, HIGH);
    }
    delay(500);
}
