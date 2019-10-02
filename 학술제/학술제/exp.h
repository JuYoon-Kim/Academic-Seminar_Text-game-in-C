// made by 김종은

#pragma once
#include<stdio.h>

typedef struct experiment {
	int level;		//캐릭터 레벨
	int fexp;		//레벨당 풀경험치
	int exp;		//캐릭터의 현재 경험치
	int persent;	//현재 경험치/풀경험치
}EXP;

void initial_exp();

EXP explist[11] = { 0 };

void initial_exp() {
	for (int i = 1; i < 11; i++) {
		explist[i].level = i;
		explist[i].exp = 0;
	}
	explist[1].fexp = 100;
	explist[2].fexp = 200;
	explist[3].fexp = 400;
	explist[4].fexp = 700;
	explist[5].fexp = 1100;
	explist[6].fexp = 1600;
	explist[7].fexp = 2200;
	explist[8].fexp = 2900;
	explist[9].fexp = 3700;
	explist[10].fexp = 4600;

	for (int i = 1; i < 11; i++) {
		explist[i].persent = explist[i].exp / explist[i].fexp;
	}
}