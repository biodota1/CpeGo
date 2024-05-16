#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

#include "fightstate.h"
#include "state.h"
#include "utils.h"
#include "game.h"

extern bool _isBattling;
extern bool _isExploring;
extern bool _isFighting;
extern bool _isRootState;
extern bool _isBag;
extern bool _isStudying;
extern bool _isAbsent;
extern bool _isIntro;
extern bool _actionComplete;
extern bool _isWin;
extern bool _isLose;
extern Player *currentPlayer;
extern Npc *currentNpc;
extern Subject *currentSubject;
extern float _playerCurrentHp;
extern float _npcCurrentHp;

int _move;

void FightDisplay(){
	clearScreen();
	int i;
	int j=0;
	int k=0;
	char text1[50] = {""};
	char text2[50] = {""};
	int length1 =0;
	int length2 =0;
	int length3 =0;
	int length4 =0;
	
	if(currentPlayer->move[0].name != '\0'){
		length1 = strlen(currentPlayer->move[0].name);
		strcat(text1, currentPlayer->move[0].name);
		for(i = 0;i<30-length1;i++){
			strcat(text1, " ");
		}	
	}
	if(currentPlayer->move[0].name != '\0'){
		length2 = strlen(currentPlayer->move[1].name);
		strcat(text1, currentPlayer->move[1].name);
		for(i = 0;i<30-length2;i++){
			strcat(text1, " ");
		}	
	}
	if(currentPlayer->move[0].name != '\0'){
		length3 = strlen(currentPlayer->move[2].name);
		strcat(text2, currentPlayer->move[2].name);
		for(i = 0;i<30-length3;i++){
			strcat(text2, " ");
		}	
	}
	if(currentPlayer->move[0].name != '\0'){
		length4 = strlen(currentPlayer->move[3].name);
		strcat(text2, currentPlayer->move[3].name);
		for(i = 0;i<30-length4;i++){
			strcat(text2, " ");
		}	
	}
	BattleScene();
	selectionBox(text1, text2);
}

void FightEnterState(){
}
void FightUpdateState(){
	int noOfMove = currentPlayer->noOfMove;
	FightDisplay();	
	while(1){
		char select = getch();
		if(select=='1' && noOfMove>=1){
			_isFighting = false;
			_actionComplete = true;
			_isRootState = true;
			_move = 0;
			break;
		}
		if(select=='2' && noOfMove>=2){
			_isFighting = false;
			_actionComplete = true;
			_isRootState = true;
			_move = 1;
			break;
		}
		if(select=='3' && noOfMove>=3){
			_isFighting = false;
			_actionComplete = true;
			_isRootState = true;
			_move = 2;
			break;
		}
		if(select=='4' && noOfMove>=4){
			_isFighting = false;
			_actionComplete = true;
			_isRootState = true;
			_move = 3;
			break;
		}
		if(select=='b' ){
			_isFighting = false;
			_isRootState = true;
			break;
		}
	}
}
void FightExitState(){
	char text1[40] = {""};
	char text2[40] = {""};
	char text3[40] = {" used"};
	char text4[40] = {""};
	char text5[40] = {""};
	char text6[40] = {""};
	char text7[40] = {""};
	char space[40] = {"    "};
	
	Move npcMoves = npcMove(currentNpc);
	
	float studyAttBoost = currentPlayer->move[_move].damage*studyUp(currentPlayer->move[_move].name,*currentSubject);
	float studyDefBoost = npcMoves.damage*studyUp(npcMoves.name, *currentSubject);
	
	strcat(text1, currentPlayer->name);
	strcat(text1, text3);
	strcat(text2, currentPlayer->move[_move].name);
	
	strcat(text5, currentNpc->name);
	strcat(text5, text3);
	strcat(text6, npcMoves.name);

	clearScreen();
	BattleScene();
	dialogBox(text1, text2);
	sleep(1);
	_npcCurrentHp-=(((currentPlayer->move[_move].damage/100)*currentPlayer->attack*matchUp(text4, currentPlayer->move[_move].subject, currentNpc->subject[0].name))+studyAttBoost+20);
	if(_npcCurrentHp<=0){
		_npcCurrentHp=0;
		_isWin = true;
		clearScreen();
		BattleScene();
		dialogBox(text4, space);
	}else{
		clearScreen();
		BattleScene();
		dialogBox(text5, text6);
		sleep(1);
		_playerCurrentHp-=(((npcMoves.damage/100)*currentNpc->attack*matchUp(text7, npcMoves.subject, currentSubject->name))-studyDefBoost);
		if(_playerCurrentHp<=0){
			_isLose = true;
			_playerCurrentHp=0;
		}
		clearScreen();
		BattleScene();
		dialogBox(text7, space);
		sleep(1);
	}
	
	
	
}

State FightState = {FightEnterState, FightUpdateState, FightExitState};
