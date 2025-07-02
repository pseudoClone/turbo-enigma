#ifndef HELPER
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "freertos/semphr.h"
#include "stdio.h"

#define TAG "TaskNotifiyExample"

void task1(void*);
void task2(void*);

extern TaskHandle_t xTask2Handle;

#endif // !HELPER
