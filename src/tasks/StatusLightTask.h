//
// Created by Alex on 05.06.2023.
//

#ifndef PLAYGROUND_STATUSLIGHTTASK_H
#define PLAYGROUND_STATUSLIGHTTASK_H


#include <vector>
#include <Arduino.h>
#include "scheduler/Task.h"

class StatusLightTask: public Task {
private:
public:
    StatusLightTask();

private:
    int ledState = LOW;
    std::vector<int> pattern;
    int currentPatternStep = 0;
public:
    void run() override;
    void setPattern(const std::vector<int> &newPattern);
};


#endif //PLAYGROUND_STATUSLIGHTTASK_H
