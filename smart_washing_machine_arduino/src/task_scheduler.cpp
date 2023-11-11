

#include "task_scheduler.hpp"

#include "TaskManagerIO.h"

#include "output/buzzer/buzzer.hpp"

#include "washing_machine/washing_machine_controller.hpp"

#include "input/buttons/buttons.hpp"
#include "input/keypad/keypad.hpp"



TaskScheduler::TaskScheduler()
{
}

void TaskScheduler::setup()
{
    Serial.begin(115200);
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