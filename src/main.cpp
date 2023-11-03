#include <Arduino.h>

#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>


AsyncWebServer server(80);

#include "WifiCredentials.h"
//const char* ssid = "Your_SSID";
//const char* password = "Your_Password";


void notFound(AsyncWebServerRequest *req){
    req->send(404,"text/plain","Not Found");
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.serveStatic("/",SPIFFS,"/my-app/");
    server.onNotFound(notFound);

    server.begin();
}

void loop() {
    
}