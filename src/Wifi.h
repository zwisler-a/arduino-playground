//
// Created by Alex on 02.06.2023.
//

#ifndef PLAYGROUND_WIFI_H
#define PLAYGROUND_WIFI_H
#include <WiFiNINA.h>

class Wifi {
public:
    void connect(char ssid[], char pass[]);
    void listenForClients();

    void printPage(WiFiClient client);
};


#endif //PLAYGROUND_WIFI_H
