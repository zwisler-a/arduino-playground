//
// Created by Alex on 05.06.2023.
//

#include <Arduino.h>
#include "RepeatingTask.h"
#include "Scheduler.h"

void RepeatingTask::run() {
    Scheduler::schedule(this, interval);
}

RepeatingTask::RepeatingTask(unsigned long executionOffset, int interval) : Task(executionOffset),
                                                                                      interval(interval) {}
