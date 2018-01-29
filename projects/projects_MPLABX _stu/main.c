/* ***************************************************************************
 * File: main.c
 * Description: Main source file for lab 2.
 *	TODO: add source files for task1 and task2
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                                  - v1
 *****************************************************************************/

/* Standard includes. */
#include <stdio.h>

/* Scheduler includes. */
#include "../../Source/include/FreeRTOS.h"
#include "../../Source/include/task.h"
#include "../../Source/include/queue.h"
#include "../../Source/include/croutine.h"

/* Demo application includes. */
#include "include/initBoard.h"


/* Prototypes for the standard FreeRTOS callback/hook functions implemented
within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

int main( void )
{
    OSCILLATOR_Initialize();
    initIO();
    _TRISG13=0;
    //Tasks creation
    
	xTaskCreate(	vTask1,						/* Pointer to the function that implements the task. */
					( char * ) "Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					240,						/* Stack depth in words. */
					NULL,						/* We are not using the task parameter. */
					1,							/* This task will run at priority 1. */
					NULL );						/* We are not using the task handle. */
 
    xTaskCreate( vTask2, ( char * ) "Task 2", 240, NULL, 1, NULL );

	/* Finally start the scheduler. */
	vTaskStartScheduler();

	/* Will only reach here if there is insufficient heap available to start
	the scheduler. */
    while(1);
	return 0;
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
    pvParameters = pvParameters ; // This is to get rid of annoying warnings
	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{

    }
}
/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
       pvParameters = pvParameters ;    // This is to get rid of annoying warnings
}

void vApplicationIdleHook( void )
{
              
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
       
		for( ;; );
}

