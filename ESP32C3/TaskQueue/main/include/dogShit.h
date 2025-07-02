#ifndef DOGSHIT
#define DOGSHIT

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include <stdio.h>

#define QUEUE_LENGTH 10

extern QueueHandle_t xQueue;

void producer(void*);
void consumer(void*);
#endif // !DOGSHIT
