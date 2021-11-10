/*
 * tasks.c
 *
 *  Created on: Nov 10, 2021
 *      Author: guerin
 */
#include "tasks.h"

void vTask_Test_Sleep(void *pvParameters){
	printf("Sleepy buddy \r\n");
	vTaskDelay(10);
}


