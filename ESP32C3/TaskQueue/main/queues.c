#include "dogShit.h"
#include "freertos/idf_additions.h"
#include <stdio.h>

QueueHandle_t xQueue;

void app_main(void)
{
        xQueue = xQueueCreate(10, sizeof(int));
        if(xQueue == NULL){
                printf("Failed to create queue\n");
                return;
        }
        xTaskCreate(producer, "Producer", 2048, NULL, 1, NULL);
        xTaskCreate(consumer, "Consumer", 2048, NULL, 1, NULL);
}
