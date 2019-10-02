// made by 김종은

#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"character.h"
#include"monster.h"
#include"combet.h"
#include"menu.h"

void print_line();
void town();
void hit1();
void hit2();
void event_hit();
void print_map(CHA clist[3], MON mlist[3]);
void print_hp(CHA clist[3], MON mlist[3]);
void print_choice_mon(CHA clist[3], MON mlist[3]);
void dungeon(CHA clist[3], MON mlist[3]);
void prologue();
void c_choice(CHA clist[3], MON mlist[3], int cnum);
void c_attack(CHA clist[3], MON mlist[3], int cnum);
void cs_attack(CHA clist[3], MON mlist[3], int cnum, int snum);
void c_skill(CHA clist[3], MON mlist[3], int cnum);
void turn_player();
void turn_monster();

void print_line() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void town() {
	char a;
	while (1) {
		system("cls");
		printf("\n      마을");
	


		a = (_getch());
		
	}
}

void print_map(CHA clist[3], MON mlist[3]) {
	printf("\n");
	if (clist[0].hp > 0 && mlist[0].hp > 0)
		printf("  %s                                                           ○                                                        %s\n", clist[0].name, mlist[0].name);
	if (clist[0].hp <= 0 && mlist[0].hp > 0)
		printf("                                                                 ○                                                        %s\n", mlist[0].name);
	if (clist[0].hp > 0 && mlist[0].hp <= 0)
		printf("  %s                                                           ○                                                             \n", clist[0].name);
	if (clist[0].hp <= 0 && mlist[0].hp <= 0)
		printf("                                                                 ○                                                             \n");
	if (clist[1].hp > 0 && mlist[1].hp > 0)
		printf("  %s                                                           ○                                                        %s\n", clist[1].name, mlist[1].name);
	if (clist[1].hp <= 0 && mlist[1].hp > 0)
		printf("                                                                 ○                                                        %s\n", mlist[1].name);
	if (clist[1].hp > 0 && mlist[1].hp <= 0)
		printf("  %s                                                           ○                                                             \n", clist[1].name);
	if (clist[1].hp <= 0 && mlist[1].hp <= 0)
		printf("                                                                 ○                                                             \n");
	if (clist[2].hp > 0 && mlist[2].hp > 0)
		printf("  %s                                                           ○                                                        %s\n", clist[2].name, mlist[2].name);
	if (clist[2].hp <= 0 && mlist[2].hp > 0)
		printf("                                                                 ○                                                        %s\n", mlist[2].name);
	if (clist[2].hp > 0 && mlist[2].hp <= 0)
		printf("  %s                                                           ○                                                             \n", clist[2].name);
	if (clist[2].hp <= 0 && mlist[2].hp <= 0)
		printf("                                                                 ○                                                             \n");
	printf("\n");
}

void print_hp(CHA clist[3], MON mlist[3]) {
	if (clist[0].hp > 0 && mlist[0].hp > 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                     %s의 체력 : %3d / %3d\n", clist[0].name, clist[0].hp, clist[0].fhp, mlist[0].name, mlist[0].hp, mlist[0].fhp);
	if (clist[0].hp <= 0 && mlist[0].hp > 0)
		printf("                                                                 ○                                     %s의 체력 : %3d / %3d\n", mlist[0].name, mlist[0].hp, mlist[0].fhp);
	if (clist[0].hp > 0 && mlist[0].hp <= 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                                             \n", clist[0].name, clist[0].hp, clist[0].fhp);
	if (clist[0].hp <= 0 && mlist[0].hp <= 0)
		printf("                                                                 ○                                                             \n");
	if (clist[1].hp > 0 && mlist[1].hp > 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                     %s의 체력 : %3d / %3d\n", clist[1].name, clist[1].hp, clist[1].fhp, mlist[1].name, mlist[1].hp, mlist[1].fhp);
	if (clist[1].hp <= 0 && mlist[1].hp > 0)
		printf("                                                                 ○                                     %s의 체력 : %3d / %3d\n", mlist[1].name, mlist[1].hp, mlist[1].fhp);
	if (clist[1].hp > 0 && mlist[1].hp <= 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                                             \n", clist[1].name, clist[1].hp, clist[1].fhp);
	if (clist[1].hp <= 0 && mlist[1].hp <= 0)
		printf("                                                                 ○                                                             \n");
	if (clist[2].hp > 0 && mlist[2].hp > 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                     %s의 체력 : %3d / %3d\n", clist[2].name, clist[2].hp, clist[2].fhp, mlist[2].name, mlist[2].hp, mlist[2].fhp);
	if (clist[2].hp <= 0 && mlist[2].hp > 0)
		printf("                                                                 ○                                     %s의 체력 : %3d / %3d\n", mlist[2].name, mlist[2].hp, mlist[2].fhp);
	if (clist[2].hp > 0 && mlist[2].hp <= 0)
		printf("  %s의 체력 : %3d / %3d                                        ○                                                             \n", clist[2].name, clist[2].hp, clist[2].fhp);
	if (clist[2].hp <= 0 && mlist[2].hp <= 0)
		printf("                                                                 ○                                                             \n");
	printf("\n");
}

void print_choice_mon(CHA clist[3], MON mlist[3]) {
	if (mlist[0].hp > 0)
		printf("  1. %s                                                        = %s을 공격합니다.\n", mlist[0].name, mlist[0].name);
	if (mlist[0].hp <= 0)
		printf("                                                                \n");
	if (mlist[1].hp > 0)
		printf("  2. %s                                                        = %s을 공격합니다.\n", mlist[1].name, mlist[1].name);
	if (mlist[1].hp <= 0)
		printf("                                                                \n");
	if (mlist[2].hp > 0)
		printf("  3. %s                                                        = %s을 공격합니다.\n", mlist[2].name, mlist[2].name);
	if (mlist[2].hp <= 0)
		printf("                                                                \n");
}

void dungeon(CHA clist[3], MON mlist[3]) {
	system("cls");
	print_line();
	printf("\n");
	printf("%s                                                          ○                                                          %s\n", clist[0].name, mlist[0].name);
	printf("%s                                                          ○                                                          %s\n", clist[1].name, mlist[1].name);
	printf("%s                                                          ○                                                          %s\n", clist[2].name, mlist[2].name);
	printf("\n");
	print_line();
	print_hp(clist, mlist);
	print_line();
	printf("\n");
}


void hit1() {
	system("cls");
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
	print_line();
}

void hit2() {
	system("cls");
}

void event_hit() {
	hit1();
	hit2();
	hit1();
	hit2();
	hit1();
	hit2();
	hit1();
	hit2();
	hit1();
	hit2();
}

////////////////////////////////////////////////////////////   여기부터 프롤로그   ////////////////////////////////////////////////////////////

void prologue() {
	while (1) {
		system("cls");
		print_line();
		printf("  프롤로그입니다.~~~~~~\n    이 게임은 저장기능을 지원하지 않습니다!!!!!\n    신중하게 선택을 해주세요!!!!!\n    방향키를 누르면 여러 페이지가 한번에 넘어갈 수도 있습니다.ㅠㅠ\n\n\n    계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {
		system("cls");
		print_line();
		printf("  설명1111111111111111설명11111111111111설명11111111111111\n\n계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {
		system("cls");
		print_line();
		printf("  설명222222222222222설명222222222222222설명222222222222222\n\n계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {
		system("cls");
		print_line();
		printf("  설명333333333333333설명333333333333333설명333333333333333\n\n계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	turn_player();

	while (1) {															//////////////// 프롤로그 c0 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[0].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '2'를 누르세요.\n");
		print_line();
		printf("\n    ※아군 캐릭터는 조장, 서기, 지갑 순으로 진행됩니다.\n    ※취소 기능은 지원하지 않습니다!! \n    신중히 선택하세요.");
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c0 스킬선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 스킬!!                                                   = 선택한 캐릭터의 이름입니다.\n\n", clist[0].name);
		printf("  1. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[0].skill[1].name, clist[0].skill[1].add_att, clist[0].skill[1].add_def, clist[0].skill[1].diff_mp, clist[0].name);
		printf("  2. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[0].skill[2].name, clist[0].skill[2].add_att, clist[0].skill[2].add_def, clist[0].skill[2].diff_mp, clist[0].name);
		printf("\n\n  계속 하시려면 '2'를 누르세요.\n");
		print_line();
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c0 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 %s 스킬!!                                              = 선택한 캐릭터의 스킬입니다.\n\n", clist[0].name, clist[0].skill[1].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '3'을 누르세요.\n");
		print_line();
		a = _getch();
		if (a == '3')
			break;
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c0 기술 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		damage_character_to_monster(clist, mlist, 0, 2, 2);
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 %s 스킬!!                                              = 선택한 캐릭터의 스킬입니다.\n\n", clist[0].name, clist[0].skill[1].name);
		printf("  %s가 %d의 데미지를 입음!!!                                   = %s이(가) %d의 데미지를 입었습니다.\n", mlist[2].name, hit_damage, mlist[2].name, hit_damage);
		clist[0].mp -= clist[0].skill[2].diff_mp;
		kill_monster(clist, mlist, stlist, 0, 0);
		printf("\n\n");
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {															//////////////// 프롤로그 c1 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[1].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '1'을 누르세요.\n");
		print_line();
		printf("\n    ※조장은 공격에 특화(딜러)되어있고, 서기는 방어(탱커), 지갑은 회복에 특화(힐러)되어 있습니다.");
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c1 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터의 공격입니다.\n\n", clist[1].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '3'을 누르세요.\n");
		print_line();
		a = _getch();
		if (a == '3') {
			damage_character_to_monster(clist, mlist, 1, 2, 0);
			break;
		}
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c1 공격 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터입니다.\n\n", clist[1].name);
		printf("  %s이(가) %d의 데미지를 입음!!!                               = %s이(가) %d의 데미지를 입었습니다.\n", mlist[2].name, hit_damage, mlist[2].name, hit_damage);
		prologue_kill_monster(clist, mlist, stlist, 1, 0);
		printf("\n\n");
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {															//////////////// 프롤로그 c2 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[2].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '1'을 누르세요.\n");
		print_line();
		printf("\n    ※각자 특성은 있지만 모두 기본공격은 할 수 있습니다.");
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c2 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터의 공격입니다.\n\n", clist[2].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '2'를 누르세요.\n");
		print_line();
		damage_character_to_monster(clist, mlist, 2, 1, 0);
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c2 공격 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터입니다.\n\n", clist[2].name);
		printf("  %s이(가) %d의 데미지를 입음!!!                               = %s이(가) %d의 데미지를 입었습니다.\n", mlist[1].name, hit_damage, mlist[1].name, hit_damage);
		kill_monster(clist, mlist, stlist, 2, 0);
		printf("\n\n");
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	turn_monster();
	
	{
		int who;
		who = choice_monster_to_character();
		while (1) {															//////////////// 프롤로그 m0 공격 
			system("cls");
			print_line();
			print_map(clist, mlist);
			print_line();
			printf("\n");
			print_hp(clist, mlist);
			print_line();
			printf("\n");
			printf("  %s이(가) %s을(를) 공격!!                                              = 선택된 몬스터입니다.\n\n", mlist[0].name, clist[who].name);
			printf("\n\n");
			printf("\n\n");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			damage_monster_to_character(clist, mlist, who, 0);
			print_line();
			if (_getch())
				break;
		}

		event_hit();

		while (1) {															//////////////// 프롤로그 m0 공격 효과
			system("cls");
			print_line();
			print_map(clist, mlist);
			print_line();
			printf("\n");
			print_hp(clist, mlist);
			print_line();
			printf("\n");
			printf("\n\n");
			printf("  %s이(가) %d의 데미지를 입음!!!                                = %s이(가) %d의 데미지를 입었습니다.\n", clist[who].name, hit_damage, clist[who].name, hit_damage);
			kill_character(clist, mlist, stlist, 0);
			printf("\n\n");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			print_line();
			if (_getch())
				break;
		}
	}

	{
		int who;
		who = choice_monster_to_character();
		while (1) {															//////////////// 프롤로그 m1 공격
			system("cls");
			print_line();
			print_map(clist, mlist);
			print_line();
			printf("\n");
			print_hp(clist, mlist);
			print_line();
			printf("\n");
			printf("  %s이(가) %s을(를) 공격!!                                              = 선택된 몬스터입니다.\n\n", mlist[1].name, clist[who].name);
			printf("\n\n");
			printf("\n\n");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			damage_monster_to_character(clist, mlist, who, 1);
			print_line();
			if (_getch())
				break;
		}

		event_hit();

		while (1) {															//////////////// 프롤로그 m1 공격 효과
			system("cls");
			print_line();
			print_map(clist, mlist);
			print_line();
			printf("\n");
			print_hp(clist, mlist);
			print_line();
			printf("\n");
			printf("\n\n");
			printf("  %s이(가) %d의 데미지를 입음!!!                                = %s이(가) %d의 데미지를 입었습니다.\n", clist[who].name, hit_damage, clist[who].name, hit_damage);
			kill_character(clist, mlist, stlist, 1);
			printf("\n\n");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			print_line();
			if (_getch())
				break;
		}
	}

	turn_player();

	while (1) {															//////////////// 프롤로그 c0 기술 효과
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[0].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '2'를 누르세요.\n");
		print_line();
		printf("\n    ※취소 기능은 지원하지 않습니다!! \n    신중히 선택하세요.");
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c0 스킬 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 스킬!!                                                   = 선택한 캐릭터의 이름입니다.\n\n", clist[0].name);
		printf("  1. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[0].skill[1].name, clist[0].skill[1].add_att, clist[0].skill[1].add_def, clist[0].skill[1].diff_mp, clist[0].name);
		printf("  2. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[0].skill[2].name, clist[0].skill[2].add_att, clist[0].skill[2].add_def, clist[0].skill[2].diff_mp, clist[0].name);
		printf("\n\n  계속 하시려면 '1'를 누르세요.\n");
		print_line();
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c0 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 %s 스킬!!                                              = 선택한 캐릭터의 스킬입니다.\n\n", clist[0].name, clist[0].skill[1].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '1'을 누르세요.\n");
		print_line();
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c0 기술 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		damage_character_to_monster(clist, mlist, 0, 0, 1);
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 %s 스킬!!                                              = 선택한 캐릭터의 스킬입니다.\n\n", clist[0].name, clist[0].skill[0].name);
		printf("  %s가 %d의 데미지를 입음!!!                                   = %s이(가) %d의 데미지를 입었습니다.\n", mlist[0].name, hit_damage, mlist[0].name, hit_damage);
		prologue_kill_monster(clist, mlist, stlist, 0, 0);
		clist[0].mp -= clist[0].skill[1].diff_mp;
		printf("\n\n");
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {															//////////////// 프롤로그 c1 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[1].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '1'을 누르세요.\n");
		print_line();
		printf("\n    ※조장은 공격에 특화(딜러)되어있고, 서기는 방어(탱커), 지갑은 회복에 특화(힐러)되어 있습니다.\n    ※특화되어있는  능력 외에 기본공격은 누구나 가능합니다.\n");
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c1 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터의 공격입니다.\n\n", clist[1].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '2'을 누르세요.\n");
		print_line();
		damage_character_to_monster(clist, mlist, 1, 1,0);
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c1 공격 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터입니다.\n\n", clist[1].name);
		printf("  %s이(가) %d의 데미지를 입음!!!                               = %s이(가) %d의 데미지를 입었습니다.\n", mlist[2].name, hit_damage, mlist[2].name, hit_damage);
		prologue_kill_monster(clist, mlist, stlist, 1, 0);
		printf("\n\n");
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}

	while (1) {															//////////////// 프롤로그 c2 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[2].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '3'을 누르세요.\n");
		print_line();
		printf("\n    ※각자 특성은 있지만 모두 기본공격은 할 수 있습니다.");
		a = _getch();
		if (a == '3') {
			dun_inventory(clist);
			break;
		}
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c2 기술선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[2].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  계속 하시려면 '1'을 누르세요.\n");
		print_line();
		printf("\n    ※각자 특성은 있지만 모두 기본공격은 할 수 있습니다.");
		a = _getch();
		if (a == '1')
			break;
		else
			continue;
	}

	while (1) {															//////////////// 프롤로그 c2 대상 선택
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터의 공격입니다.\n\n", clist[2].name);
		print_choice_mon(clist, mlist);
		printf("\n\n  계속 하시려면 '2'를 누르세요.\n");
		print_line();
		damage_character_to_monster(clist, mlist, 2, 1, 0);
		a = _getch();
		if (a == '2')
			break;
		else
			continue;
	}

	event_hit();

	while (1) {															//////////////// 프롤로그 c2 공격 효과
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                                   = 선택한 캐릭터입니다.\n\n", clist[2].name);
		printf("  %s이(가) %d의 데미지를 입음!!!                               = %s이(가) %d의 데미지를 입었습니다.\n", mlist[1].name, hit_damage, mlist[1].name, hit_damage);
		kill_monster(clist, mlist, stlist, 2, 0);
		printf("\n\n");

		if (check_exter(clist, mlist) == 1) {
			printf("  캐릭터가 모두 밤샘에 지켜 쓰러졌습니다!!!!\n  해당 과제에서 최하 점수를 맞았습니다...\n\n");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			print_line();
			if (_getch())
				break;
		}
		if (check_exter(clist, mlist) == 2) {
			printf("모든 과제를 성공적으로 완수했습니다!!!\n  하지만 성적은 교수님만이 알고계십니다.");
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			print_line();
			if (_getch())
				break;
		}
		if (check_exter(clist, mlist) == 0) {
			printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
			print_line();
			if (_getch())
				break;
		}

	}
}

////////////////////////////////////////////////////////////   여기까지 프롤로그   ////////////////////////////////////////////////////////////

void c_choice(CHA clist[3], MON mlist[3], int cnum) {
	while (1) {
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 기술!!                                                   = 공격하는 아군 캐릭터의 이름입니다.\n\n", clist[cnum].name);
		printf("  1. 기본공격                                                     = 캐릭터의 기본 공격을 합니다.\n");
		printf("  2. 스킬                                                         = 캐릭터의 스킬을 선택합니다.\n");
		printf("  3. 아이템                                                       = 인벤토리에서 사용 가능한 아이템을 선택합니다.\n");
		printf("  4. 도망치기!                                                    = 이번 스테이지는 포기합니다.\n");
		printf("\n\n  기술을 선택하시오.\n");
		print_line();
		a = _getch();
		if (a == '1')
			c_attack(clist, mlist, cnum);
		if (a == '2')
			c_attack(clist, mlist, cnum);
		else
			continue;
	}
}
void c_attack(CHA clist[3], MON mlist[3], int cnum) {
	while (1) {
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 공격!!                                              = 선택한 캐릭터의 공격!\n\n", clist[cnum].name);

		if (mlist[0].hp > 0)
			printf("  1. %s                                                        = %s을 공격합니다.\n", mlist[0].name, mlist[0].name);
		if (mlist[0].hp <= 0)
			printf("  1.                                                              \n");

		if (mlist[1].hp > 0)
			printf("  2. %s                                                        = %s을 공격합니다.\n", mlist[1].name, mlist[1].name);
		if (mlist[1].hp <= 0)
			printf("  2.                                                              \n");

		if (mlist[2].hp > 0)
			printf("  3. %s                                                        = %s을 공격합니다.\n", mlist[2].name, mlist[2].name);
		if (mlist[2].hp <= 0)
			printf("  3.                                                              \n");


		printf("\n\n  공격할 적을 선택하세요.\n");
		print_line();
		a = _getch();
		if (a == '1')
			damage_character_to_monster(clist, mlist, cnum, 0, 0);
		if (a == '2')
			damage_character_to_monster(clist, mlist, cnum, 1, 0);
		if (a == '3')
			damage_character_to_monster(clist, mlist, cnum, 2, 0);
		else
			continue;
	}
}

void cs_attack(CHA clist[3], MON mlist[3], int cnum, int snum) {
	while (1) {
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 %s 스킬!!                                              = 선택한 캐릭터의 스킬입니다.\n\n", clist[0].name, clist[0].skill[1].name);
		printf("  1. %s                                                        = %s스킬로 %s을 공격합니다.\n", mlist[0].name, clist[0].skill[1].name, mlist[0].name);
		printf("  2. %s                                                        = %s스킬로 %s을 공격합니다.\n", mlist[1].name, clist[0].skill[1].name, mlist[1].name);
		printf("  3. %s                                                        = %s스킬로 %s을 공격합니다.\n", mlist[2].name, clist[0].skill[1].name, mlist[2].name);
		printf("\n\n  공격할 적을 선택하세요.\n");
		print_line();
		a = _getch();
		if (a == '1') {
			damage_character_to_monster(clist, mlist, cnum, 0, 1);
			clist[cnum].mp -= clist[cnum].skill[0].diff_mp;
		}
		if (a == '2') {
			damage_character_to_monster(clist, mlist, cnum, 1, 2);
			clist[cnum].mp -= clist[cnum].skill[1].diff_mp;
		}
		else
			continue;
	}
}

void c_skill(CHA clist[3], MON mlist[3], int cnum) {
	while (1) {
		char a;
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  %s의 스킬!!                                                   = 선택한 캐릭터의 이름입니다.\n\n", clist[cnum].name);
		printf("  1. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[cnum].skill[1].name, clist[cnum].skill[1].add_att, clist[cnum].skill[1].add_def, clist[cnum].skill[1].diff_mp, clist[cnum].name);
		printf("  2. %s  : att + %2d def + %2d mp - %2d                            = %s의 스킬을 선택합니다.\n", clist[cnum].skill[2].name, clist[cnum].skill[2].add_att, clist[cnum].skill[2].add_def, clist[cnum].skill[2].diff_mp, clist[cnum].name);
		printf("\n\n  스킬을 선택하세요.\n");
		print_line();
		a = _getch();
		if (a == '1')
			cs_attack(clist, mlist, cnum, 1);
		if (a == '2')
			cs_attack(clist, mlist, cnum, 2);
		else
			continue;
	}
}

void turn_player() {
	while (1) {
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  플레이어의 턴!!\n\n");
		printf("  플레이어의 턴입니다!!\n");
		printf("  \n");
		printf("\n\n\n");
		print_line();
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}
}

void turn_monster() {
	while (1) {
		system("cls");
		print_line();
		print_map(clist, mlist);
		print_line();
		printf("\n");
		print_hp(clist, mlist);
		print_line();
		printf("\n");
		printf("  몬스터의 턴!!\n\n");
		printf("  몬스터의 턴입니다!!\n");
		printf("  \n");
		printf("\n\n\n");
		print_line();
		printf("\n\n  계속 하시려면 아무키나 누르세요.\n");
		print_line();
		if (_getch())
			break;
	}
}