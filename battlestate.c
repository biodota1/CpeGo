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

extern bool _isBattling;
extern bool _isExploring;
extern bool _isFighting;
extern bool _isRootState;
extern bool _isBag;
extern bool _isStudying;
extern bool _isAbsent;
extern bool _isIntro;
extern Player *currentPlayer;
extern Npc *currentNpc;
extern float _playerHp;
extern float _playerCurrentHp;
extern float _playerHpMultiple;
extern float _npcHp;
extern float _npcCurrentHp;
extern float _npcHpMultiple;


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
void BattleEnterState(){
	printf("print");
	if(!_isIntro){
		clearScreen();
		
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		char text1[50];
		char text2[50] = {"approaching..."};
		strcpy(text1, "janine");
		strcat(text1, "is");
		dialogBox(text1, text2);
		sleep(2);
	}
	_isIntro=true;
}
void BattleUpdateState(){
	while(1){
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
			_isBattling = false;
			_isExploring = true;
			_isAbsent = true;
			break;
		}
	}	
}
void BattleExitState(){
	_isIntro=false;
	char text1[] = {"It's time"};
	char text2[] = {"to absent."};
	char text3[] = {""};
	char text4[] = {" has been"};
	char text5[] = {"defeated."};
	char text6[] = {"You have gained "};
	char text7[] = {""};
	char text8[] = {"and acquired "};
	char text9[] = {""}; 
	sprintf(text7, "%d exp", 15);
	sprintf(text9, "%d talent points", 20);
	strcat(text3,"janine");
	strcat(text3, text4);
	strcat(text6,text7);
	strcat(text8, text9);
	clearScreen();
	BattleScene();
	if(_isAbsent){
		dialogBox(text1, text2);
		_isAbsent = false;
	}else{
		dialogBox("Player has been", text5);
		sleep(1);
		clearScreen();
		BattleScene();
		dialogBox(text6, text8);
	}
}

State BattleState = {BattleEnterState, BattleUpdateState, BattleExitState};
