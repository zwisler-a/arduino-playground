//
// Created by Alex on 05.06.2023.
//
#include <Arduino.h>
#include "ReadSensorTask.h"
#include "scheduler/Scheduler.h"

void ReadSensorTask::run() {
    RepeatingTask::run();
    sensorValue = analogRead(pin);
    Serial.print("Reading sensor data: ");
    Serial.println(sensorValue);
}

ReadSensorTask::ReadSensorTask(
        int pin, int interval) :
        RepeatingTask(0, interval), pin(pin), interval(interval) {}


