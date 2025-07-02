#include "dogShit.h"
void producer(void *pvParams){
        int count = 0;
        while(1){
                if(xQueueSend(xQueue, &count, portMAX_DELAY)) {
                        printf("Produced %d\n", count++);
                }
                vTaskDelay(pdMS_TO_TICKS(1000));
        }
}

void consumer(void* pvParams){
        int received;
        while(1){
                if(xQueueReceive(xQueue, &received, portMAX_DELAY)){
                        printf("Consumed %d\n", received);
                }
        }
}
