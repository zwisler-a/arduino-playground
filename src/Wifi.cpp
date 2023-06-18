//
// Created by Alex on 02.06.2023.
//
#include <WiFiNINA.h>
#include "Wifi.h"
#include "scheduler/Scheduler.h"

int status = WL_IDLE_STATUS;             // the Wi-Fi radio's status
WiFiServer server = WiFiServer(80);

void Wifi::connect(char *ssid, char *pass) {
    // attempt to connect to Wi-Fi network:
    while (status != WL_CONNECTED) {
//        Serial.print("Attempting to connect to network: ");
//        Serial.println(ssid);
        // Connect to WPA/WPA2 network:
        status = WiFi.begin(ssid, pass);
        // wait 10 seconds for connection:
        delay(3000);
    }

    // you're connected now, so print out the data:
//    Serial.println("Wifi connection established");
//    Serial.print("IP: ");
//    Serial.println(WiFi.localIP());
//    Serial.println("---------------------------------------");
    server = WiFiServer(80);
    server.begin();
}

void Wifi::listenForClients() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("new client");
        String currentLine = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        this->printPage(client);
                        break;
                    } else {    // if you got a newline, then clear currentLine:
                        currentLine = "";
                    }
                } else if (c != '\r') {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }
                // Check to see if the client request was "GET /H" or "GET /L":
                if (currentLine.endsWith("GET /H")) {
                    digitalWrite(11, HIGH);               // GET /H turns the LED on
                }
                if (currentLine.endsWith("GET /L")) {
                    digitalWrite(11, LOW);                // GET /L turns the LED off
                }
            }
        }
        // close the connection:
        client.stop();
        Serial.println("client disconnected");
    }
}

void Wifi::printPage(WiFiClient client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    // the content of the HTTP response follows the header:
    client.print("<a href=\"/H\"><button>ON</button></a><br>");
    client.print("<a href=\"/L\"><button>OFF</button></a><br>");
    client.print("Currently: ");
    client.print(analogRead(A0));
    // The HTTP response ends with another blank line:
    client.println();
}
