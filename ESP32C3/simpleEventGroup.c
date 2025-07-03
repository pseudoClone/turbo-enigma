#include "freeRTOS/FreeRTOS.h"
#include "freeRTOS/event_groups.h"
#include "freeRTOS/task.h"
#include "esp_log.h"

static EventGroupHandle_t myEventGroup;

#define BIT_WIFI_CONNECTED BIT0
#define BIT_IP_ACQUIRED    BIT1

void wifiSimulatorTask(void *pvParams){
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP_LOGI("WIFI", "WIFI Connectetd!!!\n");
        xEventGroupSetBits(myEventGroup, BIT_WIFI_CONNECTED);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xEventGroupSetBits(myEventGroup, BIT_IP_ACQUIRED);
        vTaskDelete(NULL);
}

void app_main(){
        myEventGroup = xEventGroupCreate();
        xTaskCreate(wifiSimulatorTask, "WIFI SIM", 2028, NULL, 5, NULL);
        ESP_LOGI("MAIN", "Waiting for wifi connection....");
        xEventGroupWaitBits(myEventGroup, BIT_WIFI_CONNECTED | BIT_IP_ACQUIRED,
                            pdTrue /** clear on exit **/,
                            pdTrue, /** wait for both bits **/,
                            portMAX_DELAY );
        ESP_LOGI("MAIN", "WIFI Connected and IP acquired.....");
}
