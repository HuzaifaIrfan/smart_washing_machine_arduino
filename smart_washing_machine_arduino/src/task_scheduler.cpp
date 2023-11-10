

#include "task_scheduler.hpp"

#include "TaskManagerIO.h"

#include "washing_machine/washing_machine_controller.hpp"
#include "keypad/keypad.hpp"



TaskScheduler::TaskScheduler()
{
}

void TaskScheduler::setup()
{
    Serial.begin(9600);
    display.setup();
    keypad.setup();
    washing_machine_controller.setup();


taskManager.scheduleFixedRate(1000, [] {
      washing_machine_controller.loop();
});

taskManager.scheduleFixedRate(100, [] {
      keypad.loop();
});

}

void TaskScheduler::loop()
{
    taskManager.runLoop();
}

TaskScheduler task_scheduler;