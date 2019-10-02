#pragma once
#include<stdio.h>
#include<string.h>

typedef struct skill {
	char name[20];
	int add_att;
	int add_def;
	int add_hp;
	int diff_mp;
}SKILL;

SKILL slist[31] = { 0 };

void skill_set() {
	strcpy(slist[1].name, "돌격");
	strcpy(slist[2].name, "강타");
	slist[1].add_att = 20;
	slist[1].diff_mp = 20;
	slist[2].add_att = 10;
	slist[2].diff_mp = 10;
}