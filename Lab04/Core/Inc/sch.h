/*
 * sch.h
 *
 *  Created on: Oct 26, 2025
 *      Author: tramhoang
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "main.h"
#include <stdint.h>

#define SCH_MAX_TASKS 20
#define NO_TASK_ID 0

#define ERROR_SCH_TOO_MANY_TASKS 101
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 102
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 103
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 104
#define ERROR_SCH_LOST_SLAVE 105
#define ERROR_SCH_CAN_BUS_ERROR 106
#define ERROR_I2C_WRITE_BYTE_AT24C64 107

typedef struct sTask{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
	struct sTask *next;
} sTask;

extern uint32_t ERROR_CODE_G;
extern sTask SCH_tasks_G[SCH_MAX_TASKS];
extern sTask *head;
extern uint32_t idx;

void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(sTask *dl_task);

#endif /* INC_SCH_H_ */
