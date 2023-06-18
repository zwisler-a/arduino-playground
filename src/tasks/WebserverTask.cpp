//
// Created by Alex on 05.06.2023.
//

#include "WebserverTask.h"
#include "Wifi.h"

void WebserverTask::run() {
    RepeatingTask::run();
    wifi.listenForClients();
}

WebserverTask::WebserverTask(int interval, const Wifi &wifi) : RepeatingTask(
        0, interval), wifi(wifi) {}
