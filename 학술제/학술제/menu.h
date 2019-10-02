// made by 김종은

#pragma once
#include<stdio.h>
#include<windows.h>
#include"character.h"
#include"skill.h"
#include"item.h"
#include"map.h"
#include"monster.h"
#include"map.h"

void dun_menu(CHA clist[3], MON mlist[3]);
void town_menu(CHA clist[3]);
void town_inventory0(CHA clist[3]);
void town_inventory1();
void town_inventory2();
void town_inventory3();
void town_inventory4();
void town_inventory5();
void town_equip(int cnum, int inum);
void town_inf_cha(CHA clist[3]);
void dun_inventory(CHA clist[3]);
void dun_inf_cha(CHA clist[3]);
void dun_inf_mon(MON mlist[3]);
void use_item(CHA clist[3], ITEM ilist[40], int inum);
void effect_item(CHA clist[3], ITEM ilist[41], int cnum, int inum);
void prologue_dun_inventory(CHA clist[3]);

void dun_menu(CHA clist[3], MON mlist[3]) {
	while (1) {
		char a;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		printf("  1. 인벤토리\n\n  2. 캐릭터 정보\n\n  3. 몬스터 정보\n\n  4. 돌아가기\n\n\n\n\n\n\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  원하는 메뉴를 선택해주세요.\n");
		a = (_getch());
		if (a == '1')
			dun_inventory(clist);
		if (a == '2')
			dun_inf_cha(clist);
		if (a == '3')
			dun_inf_mon(mlist);
		if (a == '4')
			break;
	}
}

void town_menu(CHA clist[3]) {
	while (1) {
		char a;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		printf("  1. 인벤토리\n\n  2. 캐릭터 정보\n\n  3. 돌아가기\n\n\n\n\n\n\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  원하는 메뉴를 선택해주세요.\n");
		a = (_getch());
		if (a == '1')
			town_inventory0(clist);
		if (a == '2')
			town_inf_cha(clist);
		if (a == '3')
			break;
	}
}

void town_inventory0(CHA clist[3]) {
	while (1) {
		char a;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		printf("  1. 조장 전용 아이템\n\n");
		printf("  2. 서기 전용 아이템\n\n");
		printf("  3. 지갑 전용 아이템\n\n");
		printf("  4. 소비 아이템\n\n");
		printf("  5. 전체 아이템\n\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  열람하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == '1')
			town_inventory1();
		if (a == '2')
			town_inventory2();
		if (a == '3')
			town_inventory3();
		if (a == '4')
			town_inventory4();
		if (a == '5')
			town_inventory5();
		if (a == 'b')
			break;
	}
}

void town_inventory1() {
	while (1) {
		char a;
		int n[10] = { 0 };
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 10; i < 20; i++) {
				if (ilist[i].ea > 0) {
					printf("  %d. %s                   리더십(공격력) : %d   필기력(방어력) : %d   부(최대마나) : %d   남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_readership, ilist[i].add_noteship, ilist[i].add_wealth, ilist[i].ea);
					n[i - 10] = i;
					index++;
				}
			
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  장착하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == '1')
			if (ilist[0].name != 0)
				town_equip(0, ilist[n[0]].num);
			else
				continue;
		if (a == '2')
			if (ilist[1].name != 0)
				town_equip(0, ilist[n[1]].num);
			else
				continue;
		if (a == '3')
			if (ilist[2].name != 0)
				town_equip(0, ilist[n[2]].num);
			else
				continue;
		if (a == '4')
			if (ilist[3].name != 0)
				town_equip(0, ilist[n[3]].num);
			else
				continue;
		if (a == '5')
			if (ilist[4].name != 0)
				town_equip(0, ilist[n[4]].num);
			else
				continue;
		if (a == '6')
			if (ilist[5].name != 0)
				town_equip(0, ilist[n[5]].num);
			else
				continue;
		if (a == '7')
			if (ilist[6].name != 0)
				town_equip(0, ilist[n[6]].num);
			else
				continue;
		if (a == '8')
			if (ilist[7].name != 0)
				town_equip(0, ilist[n[7]].num);
			else
				continue;
		if (a == '9')
			if (ilist[8].name != 0)
				town_equip(0, ilist[n[8]].num);
			else
				continue;
		if (a == '0')
			if (ilist[9].name != 0)
				town_equip(0, ilist[n[9]].num);
			else
				continue;
		if (a == 'b')
			break;
	}
}

void town_inventory2() {
	while (1) {
		char a;
		int n[10] = { 0 };
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 20; i < 30; i++) {
				if (ilist[i].ea > 0) {
					printf("  %d. %s                   리더십(공격력) : %d   필기력(방어력) : %d   부(최대마나) : %d   남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_readership, ilist[i].add_noteship, ilist[i].add_wealth, ilist[i].ea);
					n[i - 20] = i;
					index++;
				}
			
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  장착하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == '1')
			if (ilist[0].name != 0)
				town_equip(1, ilist[n[0]].num);
			else
				continue;
		if (a == '2')
			if (ilist[1].name != 0)
				town_equip(1, ilist[n[1]].num);
			else
				continue;
		if (a == '3')
			if (ilist[2].name != 0)
				town_equip(1, ilist[n[2]].num);
			else
				continue;
		if (a == '4')
			if (ilist[3].name != 0)
				town_equip(1, ilist[n[3]].num);
			else
				continue;
		if (a == '5')
			if (ilist[4].name != 0)
				town_equip(1, ilist[n[4]].num);
			else
				continue;
		if (a == '6')
			if (ilist[5].name != 0)
				town_equip(1, ilist[n[5]].num);
			else
				continue;
		if (a == '7')
			if (ilist[6].name != 0)
				town_equip(1, ilist[n[6]].num);
			else
				continue;
		if (a == '8')
			if (ilist[7].name != 0)
				town_equip(1, ilist[n[7]].num);
			else
				continue;
		if (a == '9')
			if (ilist[8].name != 0)
				town_equip(1, ilist[n[8]].num);
			else
				continue;
		if (a == '0')
			if (ilist[9].name != 0)
				town_equip(1, ilist[n[9]].num);
			else
				continue;
		if (a == 'b')
			break;
	}
}

void town_inventory3() {
	while (1) {
		char a;
		int n[10] = { 0 };
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 30; i < 40; i++) {
				if (ilist[i].ea > 0) {
					printf("  %d. %s                   리더십(공격력) : %d   필기력(방어력) : %d   부(최대마나) : %d   남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_readership, ilist[i].add_noteship, ilist[i].add_wealth, ilist[i].ea);
					n[i - 30] = i;
					index++;
				}
			
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  장착하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == '1')
			if (ilist[0].name != 0)
				town_equip(2, ilist[n[0]].num);
			else
				continue;
		if (a == '2')
			if (ilist[1].name != 0)
				town_equip(2, ilist[n[1]].num);
			else
				continue;
		if (a == '3')
			if (ilist[2].name != 0)
				town_equip(2, ilist[n[2]].num);
			else
				continue;
		if (a == '4')
			if (ilist[3].name != 0)
				town_equip(2, ilist[n[3]].num);
			else
				continue;
		if (a == '5')
			if (ilist[4].name != 0)
				town_equip(2, ilist[n[4]].num);
			else
				continue;
		if (a == '6')
			if (ilist[5].name != 0)
				town_equip(2, ilist[n[5]].num);
			else
				continue;
		if (a == '7')
			if (ilist[6].name != 0)
				town_equip(2, ilist[n[6]].num);
			else
				continue;
		if (a == '8')
			if (ilist[7].name != 0)
				town_equip(2, ilist[n[7]].num);
			else
				continue;
		if (a == '9')
			if (ilist[8].name != 0)
				town_equip(2, ilist[n[8]].num);
			else
				continue;
		if (a == '0')
			if (ilist[9].name != 0)
				town_equip(2, ilist[n[9]].num);
			else
				continue;
		if (a == 'b')
			break;
	}
}
/////////소비템///////////
void town_inventory4() {
	while (1) {
		char a;
		int n[10] = { 0 };
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 0; i < 10; i++) {
				if (ilist[i].ea > 0) {
					printf("  %d. %s                   hp 회복 : %d    mp 회복 : %d    남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_hp, ilist[i].add_mp, ilist[i].ea);
					n[i] = i;
					index++;
				}
			
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  마을 안에서는 소비형 아이템을 사용할 수 없습니다.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == 'b')
			break;
	}
}
/////////소비템///////////

void town_inventory5() {
	while (1) {
		char a;
		int n[40] = { 0 };
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 0; i < 40; i++) {
				if (ilist[i].ea > 0) {
					if (i < 10) {
						printf("  %d. %s                   hp 회복 : %d    mp 회복 : %d    남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_hp, ilist[i].add_mp, ilist[i].ea);
						n[i] = i;
						index++;
					}
					if (i >= 10 && i < 40) {
						printf("  %d. %s                   리더십(공격력) : %d   필기력(방어력) : %d   부(최대마나) : %d   남은 개수 : %d\n\n", index, ilist[i].name, ilist[i].add_readership, ilist[i].add_noteship, ilist[i].add_wealth, ilist[i].ea);
						n[i] = i;
						index++;
					}
				}
			
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  이 화면에서는 아이템 소지 현황을 확인만 할 수 있습니다.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == 'b')
			break;
	}
}

////////////////////////	이거아래 고칠 차례//////////////////////////////////////////

void town_equip(int cnum, int inum) {
	while (1) {
		char a;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");

		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  이 화면에서는 아이템 소지 현황을 확인만 할 수 있습니다.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  마을 안에서는 장비형 아이템만 장착이 가능합니다.\n");
		a = (_getch());
		if (a == 'b')
			break;
	}
}

////////////////////////	이거위에 고칠 차례//////////////////////////////////////////

void town_inf_cha(CHA clist[3]) {

}

//////////////////////  이거 아래 수정  /////////////////////////

void dun_inventory(CHA clist[3]) {
	while (1) {
		char a;
		int n[10];
		for (int i = 0; i < 10; i++) {
			n[i] = 40;
			ilist[i].index = 0;
		}
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 0; i < 10; i++) {
			if (ilist[i].ea > 0) {
				printf("  %d. %10s                   hp 회복 : %2d    mp 회복 : %2d    남은 개수 : %2d\n\n", index, ilist[i].name, ilist[i].add_hp, ilist[i].add_mp, ilist[i].ea);
				n[index - 1] = i;
				ilist[i].index = index;
				index++;
			}
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  사용하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  던전 안에서는 소비형 아이템만 사용이 가능합니다.\n");
		a = (_getch());

		if (a == '1') {
			if (ilist[n[0]].ea != 0)
				use_item(clist, ilist, ilist[n[0]].index);
			else
				continue;
		}
		if (a == '2') {
			if (ilist[n[1]].ea != 0)
				use_item(clist, ilist, ilist[n[1]].index);
			else
				continue;
		}
		if (a == '3') {
			if (ilist[n[2]].ea != 0)
				use_item(clist, ilist, ilist[n[2]].index);
			else
				continue;
		}
		if (a == '4') {
			if (ilist[n[3]].ea != 0)
				use_item(clist, ilist, ilist[n[3]].index);
			else
				continue;
		}
		if (a == '5') {
			if (ilist[n[4]].ea != 0)
				use_item(clist, ilist, ilist[n[4]].index);
			else
				continue;
		}
		if (a == '6') {
			if (ilist[n[5]].ea != 0)
				use_item(clist, ilist, ilist[n[5]].index);
			else
				continue;
		}
		if (a == '7') {
			if (ilist[n[6]].ea != 0)
				use_item(clist, ilist, ilist[n[6]].index);
			else
				continue;
		}
		if (a == '8') {
			if (ilist[n[7]].ea != 0)
				use_item(clist, ilist, ilist[n[7]].index);
			else
				continue;
		}
		if (a == '9') {
			if (ilist[n[8]].ea != 0)
				use_item(clist, ilist, ilist[n[8]].index);
			else
				continue;
		}
		if (a == '0') {
			if (ilist[n[9]].ea != 0)
				use_item(clist, ilist, ilist[n[9]].index);
			else
				continue;
		}

		if (a == 'b')
			break;
	}
}

//////////////////////  이거 위에 수정  /////////////////////////

void dun_inf_cha(CHA clist[3]) {

}

void dun_inf_mon(MON mlist[3]) {

}

void use_item(CHA clist[3], ITEM ilist[40], int index) {
	while (1) {
		int check=100;
		for (int i = 0; i < 10; i++) {
			if (ilist[i].index == index) {
				check = i;
				break;
			}
		}
		char a;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
		if (clist[0].hp > 0)
			printf("  %s                                                           ○                                                        \n", clist[0].name);
		if (clist[0].hp <= 0)
			printf("                                                                   ○                                                        \n");

		if (clist[1].hp > 0)
			printf("  %s                                                           ○                                                        \n", clist[1].name);
		if (clist[1].hp <= 0)
			printf("                                                                   ○                                                        \n");

		if (clist[2].hp > 0)
			printf("  %s                                                           ○                                                        \n", clist[2].name);
		if (clist[2].hp <= 0)
			printf("                                                                   ○                                                        \n");
		printf("\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
		
		if (clist[0].hp > 0)
			printf("  1. %s의 체력 : %3d / %3d    마나 : %3d / %3d                 ○                                     \n", clist[0].name, clist[0].hp, clist[0].fhp, clist[0].mp, clist[0].fmp);
		if (clist[0].hp <= 0)
			printf("                                                                 ○                                     \n");

		if (clist[1].hp > 0)
			printf("  2. %s의 체력 : %3d / %3d    마나 : %3d / %3d                 ○                                     \n", clist[1].name, clist[1].hp, clist[1].fhp, clist[1].mp, clist[1].fmp);
		if (clist[1].hp <= 0)
			printf("                                                                 ○                                     \n");

		if (clist[2].hp > 0)
			printf("  3. %s의 체력 : %3d / %3d    마나 : %3d / %3d                 ○                                     \n", clist[2].name, clist[2].hp, clist[2].fhp, clist[2].mp, clist[2].fmp);
		if (clist[2].hp <= 0)
			printf("                                                                 ○                                     \n");

		printf("\n\n\n");

		printf("  아이템 이름 : %10s             hp : %2d   mp : %2d   남은 개수 : %2d", ilist[check].name, ilist[check].add_hp, ilist[check].add_mp, ilist[check].ea);

		printf("\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  사용할 캐릭터를 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  던전 안에서는 소비형 아이템만 사용이 가능합니다.\n");
		a = (_getch());
		if (a == '1') {
			effect_item(clist, ilist, 0, check);
		}
		if (a == '2') {
			effect_item(clist, ilist, 1, check);
		}
		if (a == '3') {
			effect_item(clist, ilist, 2, check);
		}
		if (a == 'b')
			break;
	}
}

void effect_item(CHA clist[3], ITEM ilist[41], int cnum, int inum) {
	if (ilist[inum].add_hp > 0 && ilist[inum].add_mp == 0 && ilist[inum].ea > 0) {
		if (clist[cnum].hp + ilist[inum].add_hp >= clist[cnum].fhp)
			clist[cnum].hp = clist[cnum].fhp;
		else
			clist[cnum].hp += ilist[inum].add_hp;
		ilist[inum].ea--;
	}
	if (ilist[inum].add_hp == 0 && ilist[inum].add_mp > 0 && ilist[inum].ea > 0) {
		if (clist[cnum].mp + ilist[inum].add_mp >= clist[cnum].fmp)
			clist[cnum].mp = clist[cnum].fmp;
		else
			clist[cnum].mp += ilist[inum].add_mp;
		ilist[inum].ea--;
	}
	if (ilist[inum].add_hp > 0 && ilist[inum].add_mp > 0 && ilist[inum].ea > 0) {
		if (clist[cnum].hp + ilist[inum].add_hp >= clist[cnum].fhp)
			clist[cnum].hp = clist[cnum].fhp;
		else
			clist[cnum].hp += ilist[inum].add_hp;
		if (clist[cnum].mp + ilist[inum].add_mp >= clist[cnum].fmp)
			clist[cnum].mp = clist[cnum].fmp;
		else
			clist[cnum].mp += ilist[inum].add_mp;
		ilist[inum].ea--;
	}


}


void prologue_dun_inventory(CHA clist[3]) {
	while (1) {
		char a;
		int n[10];
		for (int i = 0; i < 10; i++) {
			n[i] = 40;
			ilist[i].index = 0;
		}
		int index = 1;
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
		for (int i = 0; i < 10; i++) {
			if (ilist[i].ea > 0) {
				printf("  %d. %10s                   hp 회복 : %2d    mp 회복 : %2d    남은 개수 : %2d\n\n", index, ilist[i].name, ilist[i].add_hp, ilist[i].add_mp, ilist[i].ea);
				n[index - 1] = i;
				ilist[i].index = index;
				index++;
			}
		}
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("  사용하고 싶은 아이템을 선택해주세요.\n\n  뒤로가기는 'b'를 선택해주세요.\n\n  던전 안에서는 소비형 아이템만 사용이 가능합니다.\n");
		a = (_getch());

		if (a == '1') {
			if (ilist[n[0]].ea != 0)
				use_item(clist, ilist, ilist[n[0]].index);
			else
				continue;
		}
		if (a == '2') {
			if (ilist[n[1]].ea != 0)
				use_item(clist, ilist, ilist[n[1]].index);
			else
				continue;
		}
		if (a == '3') {
			if (ilist[n[2]].ea != 0)
				use_item(clist, ilist, ilist[n[2]].index);
			else
				continue;
		}
		if (a == '4') {
			if (ilist[n[3]].ea != 0)
				use_item(clist, ilist, ilist[n[3]].index);
			else
				continue;
		}
		if (a == '5') {
			if (ilist[n[4]].ea != 0)
				use_item(clist, ilist, ilist[n[4]].index);
			else
				continue;
		}
		if (a == '6') {
			if (ilist[n[5]].ea != 0)
				use_item(clist, ilist, ilist[n[5]].index);
			else
				continue;
		}
		if (a == '7') {
			if (ilist[n[6]].ea != 0)
				use_item(clist, ilist, ilist[n[6]].index);
			else
				continue;
		}
		if (a == '8') {
			if (ilist[n[7]].ea != 0)
				use_item(clist, ilist, ilist[n[7]].index);
			else
				continue;
		}
		if (a == '9') {
			if (ilist[n[8]].ea != 0)
				use_item(clist, ilist, ilist[n[8]].index);
			else
				continue;
		}
		if (a == '0') {
			if (ilist[n[9]].ea != 0)
				use_item(clist, ilist, ilist[n[9]].index);
			else
				continue;
		}
		if (a == 'b')
			break;
	}
}
