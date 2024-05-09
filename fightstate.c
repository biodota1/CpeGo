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
	
	int length1 = strlen(currentPlayer->move[0].name);
	int length2 = strlen(currentPlayer->move[2].name);

	strcat(text1, currentPlayer->move[0].name);
	
	for(i = 0;i<30-length1;i++){
		strcat(text1, " ");
	}
	strcat(text1, currentPlayer->move[1].name);
	
	
	strcat(text2, currentPlayer->move[2].name);
	for(i = 0;i<30-length2;i++){
		strcat(text2, " ");
	}
	strcat(text2, currentPlayer->move[3].name);
	

	
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
	char text4[] = {""};
	char space[] = "  ";
	
	float studyAttBoost = currentPlayer->move[_move].damage*studyUp(currentPlayer->move[_move].name,*currentSubject);
	
	strcat(text1, currentPlayer->name);
	strcat(text1, text3);
	strcat(text2, currentPlayer->move[_move].name);
	clearScreen();
	BattleScene();
	dialogBox(text1, text2);
	sleep(1);
	_npcCurrentHp-=(((currentPlayer->move[_move].damage/100)*currentPlayer->attack*matchUp(text4, currentPlayer->move[_move].subject, currentNpc->subject[0].name))+studyAttBoost);
	clearScreen();
	BattleScene();
	dialogBox(text4, space);
}

State FightState = {FightEnterState, FightUpdateState, FightExitState};
