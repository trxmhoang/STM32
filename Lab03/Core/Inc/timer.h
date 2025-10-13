/*
 * timer.h
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "fsm.h"
#define CYCLE 10

extern int flagTimer1, flagTimer2, flagTimer3, flagTimer4, flagTimer5;

void setTimer1(int);
void setTimer2(int);
void setTimer3(int);
void setTimer4(int);
void setTimer5(int);

void runTimer1();
void runTimer2();
void runTimer3();
void runTimer4();
void runTimer5();
void resetTimer();

#endif /* INC_TIMER_H_ */
