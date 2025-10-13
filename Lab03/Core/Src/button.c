/*
 * button.c
 *
 *  Created on: Oct 13, 2025
 *      Author: ADMIN
 */
#include "button.h"
int btFlag[NO_BT] = {0, 0, 0};
int cnt[NO_BT] = {NORMAL_CNT, NORMAL_CNT, NORMAL_CNT};

int current[NO_BT] = {RELEASE, RELEASE, RELEASE};
int previous[NO_BT] = {RELEASE, RELEASE, RELEASE};
int older[NO_BT] = {RELEASE, RELEASE, RELEASE};
int stable[NO_BT] = {RELEASE, RELEASE, RELEASE};

int isPress(int idx){
	if(btFlag[idx]){
		btFlag[idx] = 0;
		return 1;
	}
	return 0;
}

void btRead(){
	for(int i = 0; i < NO_BT; i++){
		older[i] = previous[i];
		previous[i] = current[i];
		current[i] = HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin << i);

		if ((previous[i] == current[i]) && (previous[i] == older[i])){
			if(older[i] != stable[i]){
				stable[i] = older[i];

				if(current[i] == PRESS){
					cnt[i] = NORMAL_CNT;
					btFlag[i] = 1;
				}
			}else{
				cnt[i]--;
				if(cnt[i] == 0){
					cnt[i] = AUTO_CNT;
					if(stable[i] == PRESS) btFlag[i] = 1;
				}
			}
		}
	}
}
