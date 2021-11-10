/*
 * tasks.c
 *
 *  Created on: Nov 10, 2021
 *      Author: guerin
 */
#include "tasks.h"
#include "cmsis_os.h"

/*
 * Global variables
 */
SemaphoreHandle_t Sem_Sleep;
SemaphoreHandle_t Sem_ToCall;

void vTask_Test_Sleep(void *pvParameters){
	xSemaphoreTake(Sem_Sleep, portMAX_DELAY);
	while(1){
		printf("Sleepy buddy \r\n");
		vTaskDelay(500);
	}
	vTaskDelete(NULL);
}

void vTask_ToCall(void *pvParmaeters){
	xSemaphoreTake(Sem_ToCall, portMAX_DELAY);
	while(1){
		printf("I am synchronised by the master task \r\n");
		vTaskDelay(500);
	}
	vTaskDelete(NULL);
}

void vTask_Synchronising(void *pvParameters){
	int i=0;								//Initiating tick count
	/*
	 * Creating Semaphore
	 */
	Sem_Sleep= xSemaphoreCreateBinary();
	Sem_ToCall= xSemaphoreCreateBinary();
	/*
	 * Distributing tasks Semaphores
	 */
	while(1){
		if(i%5000==0){
			xSemaphoreGive(Sem_ToCall);
		}
		if(i%7000==0){
			xSemaphoreGive(Sem_Sleep);
		}
		vTaskDelete(NULL);
	}
}


