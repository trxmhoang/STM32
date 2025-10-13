/*
 * led.h
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "fsm.h"

#define ON 0
#define OFF 1

extern int horLed, verLed;

void setHor(int);
void setVer(int);

#endif /* INC_LED_H_ */
