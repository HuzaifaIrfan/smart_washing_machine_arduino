
#include "watch_dog.hpp"

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

    taskManager.scheduleFixedRate(200, []
                                  { buzzer.loop(); });

    taskManager.scheduleFixedRate(1000, []
                                  {
      washing_machine_controller.loop();
      watch_dog.reset(); });

    taskManager.scheduleFixedRate(100, []
                                  { keypad.loop(); });

    delay(2000);
    display.init();
    watch_dog.setup();
}

void TaskScheduler::loop()
{
    taskManager.runLoop();
}

TaskScheduler task_scheduler;