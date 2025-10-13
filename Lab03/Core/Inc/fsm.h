/*
 * fsm.h
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */
#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "button.h"
#include "timer.h"
#include "led.h"
#include "segment.h"
#include "main.h"

#define IDLE -1
#define NONE 0
#define INIT 1
#define RED 2
#define YELLOW 3
#define GREEN 4
#define EDIT_RED 6
#define EDIT_YELLOW 7
#define EDIT_GREEN 8

void isBt1();
void horRun();
void verRun();
void editRun();
void runAll();


#endif /* INC_FSM_H_ */
