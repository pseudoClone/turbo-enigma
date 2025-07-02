#include "notifHelper.h"
#include <stdlib.h>

TaskHandle_t xTask2Handle = NULL;
void app_main(void)
{
        xTaskCreate(task2, "Task2", 2048, NULL, 5, &xTask2Handle);
        xTaskCreate(task1, "Task1", 2048, NULL, 5, NULL);
}
