// made by 김종은

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"character.h"
#include"monster.h"
#include"skill.h"
#include"item.h"
#include"stage.h"

void damage_character_to_monster(CHA clist[3], MON mlist[3], int cnum, int mnum, int snum);			//캐릭터배열, 몬스터배열, 캐릭터번호, 몬스터번호, 스킬번호
void damage_monster_to_character(CHA clist[3], MON mlist[3], int cnum, int mnum);
int choice_monster_to_character();
int check_exter(CHA clist[3], MON mlist[3]);
void kill_monster(CHA clist[3], MON mlist[3], STAGE stlist[6], int cnum, int stnum);
void kill_character(CHA clist[3], MON mlist[3], STAGE stlist[6], int mnum);

int hit_damage;

void damage_character_to_monster(CHA clist[3], MON mlist[3], int cnum, int mnum, int snum) {
	if (clist[cnum].readership >= 10)
		mlist[mnum].hp = mlist[mnum].hp - ((clist[cnum].att + clist[cnum].skill[snum].add_att) * clist[cnum].readership / 10);
	else
		mlist[mnum].hp = mlist[mnum].hp - (clist[cnum].att + clist[cnum].skill[snum].add_att);
	if (clist[cnum].readership >= 10)
		hit_damage = (clist[cnum].att + clist[cnum].skill[snum].add_att) * clist[cnum].readership / 10;
	else
		hit_damage = (clist[cnum].att + clist[cnum].skill[snum].add_att);
}

void damage_monster_to_character(CHA clist[3], MON mlist[3], int cnum, int mnum) {
	clist[cnum].hp = clist[cnum].hp - (mlist[mnum].att);
	hit_damage = mlist[mnum].att;
}

int choice_monster_to_character() {
	srand((unsigned)time(NULL));

	if (clist[0].hp > 0 && clist[1].hp > 0 && clist[2].hp > 0) {
		int n = rand() % 10;			//n이 6보다 작거나 같으면 cnum1 즉 탱커를 공격
		int m = rand() % 2;				//아닐경우 m이 0일때 cnum0 즉 딜러 공격, m이 1일때 cnum2 즉 힐러 공격
		if (n <= 6)
			return 1;
		else {
			if (m == 0)
				return 0;
			else
				return 2;
		}
	}
	if (clist[0].hp > 0 && clist[1].hp > 0 && clist[2].hp <= 0) {
		int n = rand() % 10;			//n이 6보다 작거나 같으면 cnum1 즉 탱커를 공격
		if (n <= 6)
			return 1;
		else
			return 0;
	}
	if (clist[0].hp <= 0 && clist[1].hp > 0 && clist[2].hp > 0) {
		int n = rand() % 10;			//n이 6보다 작거나 같으면 cnum1 즉 탱커를 공격
		if (n <= 6)
			return 1;
		else
			return 2;
	}
	if (clist[0].hp > 0 && clist[1].hp > 0 && clist[2].hp > 0) {
		int m = rand() % 2;				//아닐경우 m이 0일때 cnum0 즉 딜러 공격, m이 1일때 cnum2 즉 힐러 공격
		if (m == 0)
			return 0;
		else
			return 2;
	}
	if (clist[0].hp > 0 && clist[1].hp <= 0 && clist[2].hp <= 0) {
		return 0;
	}
	if (clist[0].hp <= 0 && clist[1].hp > 0 && clist[2].hp <= 0) {
		return 1;
	}
	if (clist[0].hp <= 0 && clist[1].hp <= 0 && clist[2].hp > 0) {
		return 2;
	}
}



int check_exter(CHA clist[3], MON mlist[3]) {
	int die_character = 0, die_monster = 0;
	for (int i = 0; i < 3; i++) {
		if (clist[i].hp <= 0)
			die_character++;
	}
	for (int i = 0; i < 3; i++) {
		if (mlist[i].hp <= 0)
			die_monster++;
	}
	if (die_character == 3)
		return 1;
	else if (die_monster == 3)
		return 2;
	else
		return 0;
}

void kill_monster(CHA clist[3], MON mlist[3], STAGE stlist[6], int cnum, int stnum) {
	srand((unsigned)time(NULL));
	int add_gold = rand() % 10 + 1;
	int chance_drop = rand() % 3;		//33%확률로 드랍 => 0일때 드랍
	int item_num;
	for (int i = 0; i < 3; i++) {
		if (mlist[i].hp <= 0 && mlist[i].condition == 0) {
			printf("\n\n  %s이(가) 죽었습니다!!            %s이(가) %d의 골드를 드랍했습니다!!\n", mlist[i].name, mlist[i].name, add_gold);
			gold += add_gold;
			if (chance_drop == 0) {
				item_num = rand() % stlist[stnum].num_item;
				printf("  %s을(를) 획득!!\n", stlist[stnum].drop_item[item_num].name);
				for (int j = 0; j < 30; j++) {
					if (ilist[j].name != 0)
						ilist[j] = aitem[stlist[stnum].drop_item[item_num].num];
					else
						ilist[j].ea++;
				}
			}
			clist[cnum].exp->exp += mlist[i].mexp;
			mlist[i].condition = 1;
		}
	}
}

void kill_character(CHA clist[3], MON mlist[3], STAGE stlist[6], int mnum) {
	for (int i = 0; i < 3; i++) {
		if (clist[i].hp <= 0 && clist[i].condition == 0) {
			printf("\n\n  %s이(가) 죽었습니다!!", clist[i].name);
		}
		clist[i].condition = 1;
	}
}

void prologue_kill_monster(CHA clist[3], MON mlist[3], STAGE stlist[6], int cnum, int stnum) {
	srand((unsigned)time(NULL));
	int add_gold = rand() % 10 + 1;
	int chance_drop = 1;		//100%확률로 드랍 => 0일때 드랍
	int item_num;
	for (int i = 0; i < 3; i++) {
		if (mlist[i].hp <= 0 && mlist[i].condition == 0) {
			printf("\n\n  %s이(가) 죽었습니다!!                                        %s이(가) %d의 골드를 드랍했습니다!!\n\n", mlist[i].name, mlist[i].name, add_gold);
			gold += add_gold;
			if (chance_drop == 0) {
				item_num = rand() % stlist[stnum].num_item;
				printf("  %s을(를) 획득!!\n", stlist[stnum].drop_item[item_num].name);
				
						ilist[stlist[stnum].drop_item[item_num].num].ea++;
				
			}
			clist[cnum].exp->exp += mlist[i].mexp;
			mlist[i].condition = 1;
		}
	}
}