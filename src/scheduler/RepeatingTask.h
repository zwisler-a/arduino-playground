//
// Created by Alex on 05.06.2023.
//

#ifndef PLAYGROUND_REPEATINGTASK_H
#define PLAYGROUND_REPEATINGTASK_H


#include "Task.h"

class RepeatingTask : public Task {

public:
    RepeatingTask(unsigned long executionOffset, int interval);

private:
    int interval;

protected:
    void run() override;
};


#endif //PLAYGROUND_REPEATINGTASK_H
