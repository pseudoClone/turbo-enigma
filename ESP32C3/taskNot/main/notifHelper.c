#include "notifHelper.h"
#include "freertos/projdefs.h"
#include <stdint.h>

void task1(void* pvParams){
        while(1){
                ESP_LOGI(TAG, "TASK1: Send notification\n");
                xTaskNotifyGive(xTask2Handle);
                vTaskDelay(pdMS_TO_TICKS(1000));
        }
}

void task2(void* pvParams){
        uint32_t notificationValue;
        while (1) {
                notificationValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

                if(notificationValue) {
                        ESP_LOGI(TAG, "Task 2: Notification Received\n");
                }
        }
}
