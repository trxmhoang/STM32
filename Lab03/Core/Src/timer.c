/*
 * timer.c
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */
#include "timer.h"

int cntTimer1 = 0, cntTimer2 = 0, cntTimer3 = 0, cntTimer4 = 0, cntTimer5 = 0;
int flagTimer1 = 0, flagTimer2 = 0, flagTimer3 = 0, flagTimer4 = 0, flagTimer5 = 0;

void setTimer1(int duration){
	cntTimer1 = duration/CYCLE;
	flagTimer1 = 0;
}

void setTimer2(int duration){
	cntTimer2 = duration/CYCLE;
	flagTimer2 = 0;
}

void setTimer3(int duration){
	cntTimer3 = duration/CYCLE;
	flagTimer3 = 0;
}

void setTimer4(int duration){
	cntTimer4 = duration/CYCLE;
	flagTimer4 = 0;
}

void setTimer5(int duration){
	cntTimer5 = duration/CYCLE;
	flagTimer5 = 0;
}

void runTimer1(){
	if(cntTimer1 > 0){
		cntTimer1--;
		if(cntTimer1 == 0) flagTimer1 = 1;
	}
}

void runTimer2(){
	if(cntTimer2 > 0){
		cntTimer2--;
		if(cntTimer2 == 0) flagTimer2 = 1;
	}
}

void runTimer3(){
	if(cntTimer3 > 0){
		cntTimer3--;
		if(cntTimer3 == 0) flagTimer3 = 1;
	}
}

void runTimer4(){
	if(cntTimer4 > 0){
		cntTimer4--;
		if(cntTimer4 == 0) flagTimer4 = 1;
	}
}

void runTimer5(){
	if(cntTimer5 > 0){
		cntTimer5--;
		if(cntTimer5 == 0) flagTimer5 = 1;
	}
}

void resetTimer(){
	cntTimer1 = 0;
	cntTimer2 = 0;
	cntTimer3 = 0;
	cntTimer4 = 0;
	cntTimer5 = 0;

	flagTimer1 = 0;
	flagTimer2 = 0;
	flagTimer3 = 0;
	flagTimer4 = 0;
	flagTimer5 = 0;
}
