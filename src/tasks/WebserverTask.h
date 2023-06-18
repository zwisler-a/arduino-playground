//
// Created by Alex on 05.06.2023.
//

#ifndef PLAYGROUND_WEBSERVERTASK_H
#define PLAYGROUND_WEBSERVERTASK_H


#include "scheduler/RepeatingTask.h"
#include "Wifi.h"

class WebserverTask : public RepeatingTask {
public:
    WebserverTask(int interval, const Wifi &wifi);

private:
    Wifi wifi;
protected:
    void run() override;

};


#endif //PLAYGROUND_WEBSERVERTASK_H
