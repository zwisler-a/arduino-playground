//
// Created by Alex on 05.06.2023.
//

#include "StatusLightTask.h"
#include "scheduler/Scheduler.h"

StatusLightTask::StatusLightTask() : Task(
        0) {
}

void StatusLightTask::run() {
    if (pattern.empty()) {
        Scheduler::schedule(this, 100);
    }
    if (currentPatternStep >= pattern.size()) {
        currentPatternStep = 0;
    }
    ledState = ledState ? LOW : HIGH;
    digitalWrite(LED_BUILTIN, ledState);
    Scheduler::schedule(this, pattern[currentPatternStep]);
    currentPatternStep++;

}

void StatusLightTask::setPattern(const std::vector<int> &newPattern) {
    pattern = newPattern;
    currentPatternStep = 0;
    ledState = LOW;
}


