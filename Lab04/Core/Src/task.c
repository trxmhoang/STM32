/*
 * task.c
 *
 *  Created on: Oct 26, 2025
 *      Author: tramhoang
 */
#include "task.h"

void blink_int(void){
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
}
void blink_led(void){
	HAL_GPIO_TogglePin(led6_GPIO_Port, led6_Pin);
}

void oneshot_1(void){
	HAL_GPIO_TogglePin(led7_GPIO_Port, led7_Pin);
}

void oneshot_2(void){
	HAL_GPIO_TogglePin(led8_GPIO_Port, led8_Pin);
}

void task1(void){
	HAL_GPIO_TogglePin(led0_GPIO_Port, led0_Pin);
}
void task2(void){
	get_time(2);
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
}

void task3(void){
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
}
void task4(void){
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
}

void task5(void){
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
}


