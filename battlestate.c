#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <unistd.h> 
#include <stdbool.h>
#include <time.h>

#include "battlestate.h"
#include "state.h"
#include "game.h"
#include "utils.h"
#include "event.h"

extern bool _isBattling;
extern bool _isExploring;
extern bool _isFighting;
extern bool _isRootState;
extern bool _isBag;
extern bool _isStudying;
extern bool _isAbsent;
extern bool _isIntro;
extern bool _isImportantEvent;
extern bool _isEventCompleted;
extern bool _isExitState;
extern bool _isWin;
extern bool _isLose;

extern float _playerHp;
extern float _playerCurrentHp;
extern float _playerHpMultiple;
extern float _npcHp;
extern float _npcCurrentHp;
extern float _npcHpMultiple;

extern Player *currentPlayer;
extern Npc *currentNpc;
extern Event *currentEvent;



void BattleScene(){
	
	float playerHpDisplay = _playerCurrentHp/_playerHpMultiple;
	float playerHpTaken = 20-playerHpDisplay;
	float npcHpDisplay = _npcCurrentHp/_npcHpMultiple;
	float npcHpTaken = 20-npcHpDisplay;
	int i=0;
	char text1[15] = {""};
	char text2[48] = {""};
	strcat(text1, currentPlayer->name);
	strcat(text2, currentNpc->name);
	
	//ENEMY
	printf("\n");
	int npcNameSize = 0;
	for(i=sizeof(text2)-1;i>-1;i--){
		if(text2[i]=='\0'){
			printf(" ");
		}else{
			break;
		}	
	}
	printf("%s", text2);
	printf("  Lvl: 1");
	printf("\n\t\t\t\t\t\t  HP:");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WCHAR hpChar[] = { 0x2588, 0 };
    WCHAR hpCharTaken[] = { 0x2592, 0 };          
    for(i =0;i<npcHpDisplay;i++){
        WriteConsoleW(hConsole, hpChar, 1, NULL, NULL);
    }
    for(i =0;i<npcHpTaken;i++){
        WriteConsoleW(hConsole, hpCharTaken, 1, NULL, NULL);
    }
	printf("\n\t\t\t\t\t\t\t    %0.f/%0.f",_npcCurrentHp,_npcHp);
	printf("\n\n\n");
	
	//PLAYER
	printf("\n");
	for(i=sizeof(text1);i>-1;i--){
		if(text1[i]=='\0'){
			printf(" ");
		}else{
			break;
		}	
	}

	printf("%s", text1);
	printf("  Lvl: 1");
	printf("\n\t\t  HP:");
	 for(i =0;i<playerHpDisplay;i++){
        WriteConsoleW(hConsole, hpChar, 1, NULL, NULL);
    }
    for(i =0;i<playerHpTaken;i++){
        WriteConsoleW(hConsole, hpCharTaken, 1, NULL, NULL);
    }
	printf("\n\t\t\t    %0.f/%0.f",_playerCurrentHp,_playerHp);
	
	printf("\n");
}

void BattleDisplay(){	
	char text3[] = {"What will                        [1] FIGHT  [2] BAG"};
	char text4[] = {"you do?                          [3] STUDY  [4] ABSENT"};
	clearScreen();
	BattleScene();
	selectionBox(text3, text4);
}
void BattleAbsent(){
	clearScreen();
	BattleScene();
	char text1[] = {"You can't run away"};
	char text2[] = {"from your responsibilities."};
	dialogBox(text1, text2);
}
void BattleEnterState(){
	if(!_isIntro){
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		char text1[50];
		char text2[50] = {"approaching..."};
		strcpy(text1, currentNpc->name);
		strcat(text1, " is");
		dialogBox(text1, text2);
//		char line1[] = {""};
//		char line2[] = {"is approaching..."};
//		strcpy(line1, currentNpc->name);
//		worldDialogBox(line1, line2);
		sleep(1);
	}
	_isIntro = true;
}
void BattleUpdateState(){
	while(1){		
		if(_isWin || _isLose){
			_isBattling = false;
			_isExploring = true;
			_isExitState = true;
			break;
		}
		BattleDisplay();
		char select = getch();
		if(select=='1'){
			_isFighting = true;
			_isRootState = false;
			break;
		}
		if(select=='2'){
			_isBag = true;
			_isRootState = false;
			break;
		}
		if(select=='3'){
			_isStudying = true;
			_isRootState = false;
			break;
		}
		if(select=='4'){
			if(_isImportantEvent){
				BattleAbsent();
			}else{
				_isBattling = false;
				_isExploring = true;
				_isAbsent = true;
				_isExitState = true;
				break;
			}
		}
		
	}	
}
void BattleExitState(){
	_isIntro=false;
	char text1[50];
	char expText[10];
	char talentText[10];
	char text2[20] = {"You have gained "};
	char text3[20] = {"and acquired "};
	char text4[20] = {"You have level up!"};
	int exp = currentNpc->exp;
	int nextLvl = currentPlayer->nextLvl;
	int talent = currentNpc->talent;
	
	sprintf(expText, "%d", exp);
	sprintf(talentText, "%d", talent);
	strcat(text1, currentNpc->name);
	strcat(text1, " has been");
	strcat(text2,expText);
	strcat(text2," exp");
	strcat(text3,talentText);
	strcat(text3," talent points.");
	clearScreen();
	BattleScene();
	if(_isAbsent){		
		_isAbsent = false;
		dialogBox("It's time", "to absent.");
		sleep(1);
	}
	if(_isWin){
		_isWin = false;
		_isEventCompleted =true;
		currentEvent=currentEvent->next;
		dialogBox(text1, "defeated.");
		sleep(1);
		clearScreen();
		BattleScene();
		dialogBox(text2, text3);
		clearScreen();
		BattleScene();
		do{
			int excessExp = nextLvl-exp;
			if(excessExp>0){
				currentPlayer->exp = excessExp;
			}else{
				currentPlayer->lvl++;
				currentPlayer->exp = (excessExp*-1);
				float floatNextLvl = (float)currentPlayer->nextLvl;
				floatNextLvl *= 1.25;
				currentPlayer->nextLvl = (int)floatNextLvl;
				dialogBox(text4,"");
				Move move = skillTree(&currentPlayer);
				clearScreen();
				BattleScene();
				dialogBox("You have learned",move.name);
			}
		}while(currentPlayer->exp>nextLvl);
	}
	if(_isLose){
		_isLose = false;
		clearScreen();
		BattleScene();
		dialogBox("Player has been", "whited out...");
		sleep(1);
	}
}

State BattleState = {BattleEnterState, BattleUpdateState, BattleExitState};
