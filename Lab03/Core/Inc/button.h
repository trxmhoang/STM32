/*
 * button.h
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "fsm.h"

#define NO_BT 3
#define PRESS 0
#define RELEASE 1
#define NORMAL_CNT 100
#define AUTO_CNT 50

int isPress (int);
void btRead();

#endif /* INC_BUTTON_H_ */
