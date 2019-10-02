// made by 김종은

#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"skill.h"
#include"item.h"
#include"map.h"
#include"exp.h"

typedef struct charac {
	char name[20];
	ITEM item[2];
	SKILL skill[3];
	EXP exp[11];
	int fhp;						//총 hp
	int fmp;						//총 mp
	int hp;							//남은 hp
	int mp;							//남은 mp
	int att;						//실제로 들어가는 데미지
	int def;						//공격에 대한 방어력 => def == 10 일때 att == 100 공격을 받으면 실제 데미지 99
	int readership;					//리더십 : 공격력 관련 스텟
	int noteship;					//필기력 : 방어력 관련 스텟
	int wealth;						//부 : 마나 관련 스텟      
	double damage;					// 예시 => (double)(att * (readership / 10))
	double protect;					// 예시 => (double)(def * (noteship / 10))
	int condition;				//0일 경우 살아있음, 1일경우 죽어있음
	int spare_stat;
}CHA;

void initial_charac(CHA clist[3], SKILL slist[30]);

CHA clist[3] = { 0 };

void initial_charac(CHA clist[3], SKILL slist[30]) {
	skill_set();
	strcpy(clist[0].name, "조장");
	strcpy(clist[1].name, "서기");
	strcpy(clist[2].name, "지갑");
	for (int i = 0; i < 3; i++) {
		clist[i].exp->level = 1;
		clist[i].exp->exp = 0;
		clist[i].fhp = 100;
		clist[i].fmp = 100;
		clist[i].hp = 100;
		clist[i].mp = 100;
		clist[i].att = 10;
		clist[i].def = 10;
		clist[i].readership = rand() % 5 + 5;
		clist[i].noteship = rand() % 5 + 5;
		clist[i].wealth = rand() % 5 + 5;
		if (clist[i].readership >= 10)
			clist[i].damage = clist[i].att * (double)clist[i].readership / 10;
		else
			clist[i].damage = clist[i].att;
		if (clist[i].noteship >= 10)
			clist[i].protect = clist[i].def * (double)clist[i].noteship / 10;
		else
			clist[i].protect = clist[i].def;
		clist[i].condition = 0;
		clist[i].spare_stat = 0;
	}
	clist[0].skill[0] = slist[0];
	clist[0].skill[1] = slist[1];
	clist[0].skill[2] = slist[2];
}