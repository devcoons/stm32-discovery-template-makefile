#include "threads.h"

	void Thread_1(void *pvParameters)
	{  
		DigitalOut myled1(PD_12);
		
		while (1) 
		{
			myled1 = myled1 ^ 1;
			vTaskDelay(1000 / portTICK_RATE_MS);
	  	}
	}
	
	void Thread_2(void *pvParameters)
	{
		int sig = 1;
		DigitalIn pb(PA_0);
	  
		while (1) 
		{
			if(pb > 0) 
			{
				while(pb > 0)
					vTaskDelay(100 / portTICK_RATE_MS);
				while(pb == 0)
					vTaskDelay(100 / portTICK_RATE_MS);
				xQueueSendToBack(pbq, &sig, 0);
			}
		}
	}
	
	void Thread_3(void *pvParameters) 
	{
		int sig;
		portBASE_TYPE status;
		DigitalOut myled2(PD_14);
			  
		while (1) 
		{
			status = xQueueReceive(pbq, &sig, portMAX_DELAY); 
			if(status == pdTRUE)
				myled2 = myled2 ^ 1;
		}
	}

	void Threads_Init(void)
	{
		if ( (pbq = xQueueCreate(10,sizeof(int))) == 0)
			while(1);	// Fucked Up
	
		xTaskCreate(Thread_1, "Task1", configMINIMAL_STACK_SIZE, (void*) NULL, tskIDLE_PRIORITY + 2UL, NULL); 
		xTaskCreate(Thread_2, "Task2", configMINIMAL_STACK_SIZE, (void*) NULL, tskIDLE_PRIORITY + 2UL, NULL);
		xTaskCreate(Thread_3, "Task3", configMINIMAL_STACK_SIZE, (void*) NULL, tskIDLE_PRIORITY + 2UL, NULL);
	}

	void OS_Start(void)
	{
		vTaskStartScheduler();
	}
