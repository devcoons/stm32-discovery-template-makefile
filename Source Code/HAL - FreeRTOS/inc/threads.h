#ifndef _THREADS_H
	#define _THREADS_H
	
		#include "mbed.h"
		#include "FreeRTOS.h"
		#include "task.h"
		#include "timers.h"
		#include "semphr.h"
	
		static xQueueHandle pbq;
	
		void Thread_1			(void *);
		void Thread_2			(void *);
		void Thread_3			(void *);
	
		void Threads_Init		(void  );
		void OS_Start			(void  );
	
#endif
