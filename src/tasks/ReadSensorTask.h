//
// Created by Alex on 05.06.2023.
//

#ifndef PLAYGROUND_READSENSORTASK_H
#define PLAYGROUND_READSENSORTASK_H


#include "scheduler/Task.h"
#include "scheduler/RepeatingTask.h"

class ReadSensorTask : public RepeatingTask {
public:
    unsigned int sensorValue = 0;
    int pin;
    int interval;

    ReadSensorTask(int pin, int interval);

    void run() override;

};


#endif //PLAYGROUND_READSENSORTASK_H
