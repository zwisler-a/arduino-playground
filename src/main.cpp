#include <Arduino.h>
#include "Wifi.h"
#include "scheduler/Scheduler.h"
#include "tasks/StatusLightTask.h"
#include "tasks/ReadSensorTask.h"
#include "tasks/WebserverTask.h"


//please enter your sensitive data in the Secret tab
char ssid[] = "Kleene Moni";
char pass[] = "60991482985711367461";
Wifi wifi = Wifi();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A0, INPUT);
//    pinMode(9, INPUT);
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {};
    digitalWrite(LED_BUILTIN,HIGH);
    wifi.connect(ssid, pass);
    digitalWrite(LED_BUILTIN,LOW);
    // set the LED as output
    auto *blinker = new StatusLightTask();
    blinker->setPattern({200, 100, 200, 2000});
//    blinker->setPattern({100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 500});
//    Scheduler::schedule(blinker);
    auto sensorReader = new ReadSensorTask(A0, 5000);
    Scheduler::schedule(sensorReader);
//    auto webserver = new WebserverTask(50, wifi);
//    Scheduler::schedule(webserver);

}

void loop() {
    Scheduler::loop();
}


