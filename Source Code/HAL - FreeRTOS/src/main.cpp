#include "main.h"
	#include "threads.h"

	#define BLOCK_

	#ifdef CUSTOM_NEW

		void *operator new(size_t size) 
		{
			return malloc(size);
		}

		void *operator new[](size_t size) 
		{
			return malloc(size);
		}

		void operator delete(void *p) 
		{
			free(p);
		}

		void operator delete[](void *p) 
		{
			free(p);
		}
		
	#endif


	int main(void)
	{
		Threads_Init();
		
		OS_Start();
	
		while(1); 
	}
