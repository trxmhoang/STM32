/*
 * sch.c
 *
 *  Created on: Oct 26, 2025
 *      Author: tramhoang
 */

#include "sch.h"
uint32_t ERROR_CODE_G;
sTask SCH_tasks_G[SCH_MAX_TASKS];
sTask *head = NULL;
uint32_t idx;
uint32_t tick = 0;

/*
void SCH_Init(void){
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++){
		SCH_tasks_G[i].pTask = NULL;
		SCH_tasks_G[i].next = NULL;
	}

	ERROR_CODE_G = 0;
	head = NULL;

	unsigned char j;
	for (j = 0; j < 9; j++){
		HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin << j, 1);
	}
}
*/

void SCH_Init(void){
	ERROR_CODE_G = 0;
	idx = 0;
	head = NULL;

	for (int j = 0; j < 9; j++){
		HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin << j, 1);
	}
}

void SCH_Update(void){
	tick += 10;
	sTask *current = head;
	sTask *pre = NULL;

	while(current != NULL){
		if(current->Delay > 1){
			current->Delay--;
			pre = current;
			current = current->next;
		}else{
			current->RunMe++;
			if(current->Period > 0){
				current->Delay = current->Period;
				pre = current;
				current = current->next;
			}else{
				if(pre == NULL) head = current->next;
				else pre->next = current->next;
				current->next = NULL;
				current = (pre == NULL) ? head : pre->next;
			}
		}
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if(idx >= SCH_MAX_TASKS){
		ERROR_CODE_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	}

	SCH_tasks_G[idx].pTask = pFunction;
	SCH_tasks_G[idx].Delay = DELAY;
	SCH_tasks_G[idx].Period = PERIOD;
	SCH_tasks_G[idx].RunMe = 0;
	SCH_tasks_G[idx].TaskID = idx;
	SCH_tasks_G[idx].next = head;
	head = &SCH_tasks_G[idx];

	return ++idx;
}

/*
void SCH_Delete_Task(sTask *dl_task){
	if(dl_task == NULL) return;
	sTask **current = &head;
	while (*current != NULL){
		if(*current == dl_task){
			*current = dl_task->next;
			dl_task->next = NULL;
			dl_task->pTask = NULL;
			return;
		}
		current = &(*current)->next;
	}
}
*/

void SCH_Delete_Task(sTask *dl_task){
	if(dl_task == NULL) return;

	if(head == dl_task){
		head = dl_task->next;
		dl_task->next = NULL;
		dl_task->pTask = NULL;
		return;
	}

	sTask* current = head;
	while(current != NULL && current->next != dl_task){
		current = current->next;
	}

	if(current != NULL){
		current->next = dl_task->next;
		dl_task->next = NULL;
		dl_task->pTask = NULL;
	}
}


void SCH_Dispatch_Tasks(void){
	for(uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			(*SCH_tasks_G[i].pTask)();
			SCH_tasks_G[i].RunMe--;

			if(SCH_tasks_G[i].Period == 0) SCH_Delete_Task(&SCH_tasks_G[i]);
		}
	}
}


