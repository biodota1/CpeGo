//STANDARD LIB
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <unistd.h> 
#include <stdbool.h>
#include <time.h>
//STATES LIB
#include "state.h"
#include "game.h"
#include "battlestate.h"
#include "explorestate.h"
#include "fightstate.h"
#include "bagstate.h"
#include "studystate.h"

//INITIALIZE VALUES
bool _isRootState = true;
bool _isExploring = false;
bool _isBattling  = false;
bool _isFighting  = false;
bool _isStudying  = false;
bool _isBag       = false;
bool _isAbsent    = false;
bool _actionComplete = false;
bool _isIntro     = true;

float _playerHp;
float _playerHpMultiple;
float _playerCurrentHp;
float _npcHp;
float _npcHpMultiple;
float _npcCurrentHp;

int *_noOfItems;
int *_selectedItem;
int _currentBag=0;
int _item = 0;

State currentRootState;
State currentSubState;
Subject *currentSubject;
Player *currentPlayer;
Npc *currentNpc;
Bag *Inventory;

void CheckSwitchStates();
void SwitchStates(State *currentState, State newState);

extern void BattleEnterState();

int main() {
	int i;
	
	hideCursor();
	
	Player player = newGame();
	currentPlayer = &player;
	_playerHp = currentPlayer->hp;
	_playerHpMultiple = _playerHp/20;
	_playerCurrentHp = _playerHp;
	currentPlayer->move = (Move*) realloc(currentPlayer->move, sizeof(Move)*2);
	currentPlayer->move[1] = getMove(1);
	currentPlayer->noOfMove++;
	currentPlayer->move = (Move*) realloc(currentPlayer->move, sizeof(Move)*3);
	currentPlayer->move[2] = getMove(2);
	currentPlayer->noOfMove++;
	currentPlayer->move = (Move*) realloc(currentPlayer->move, sizeof(Move)*4);
	currentPlayer->move[3] = getMove(4);
	currentPlayer->noOfMove++;
	
	currentSubject = &player.subject[0];

	Npc npc1 = spawnNpc(0);
	currentNpc = &npc1;
	_npcHp = currentNpc->hp;
	_npcHpMultiple = _npcHp/20;
	_npcCurrentHp = _npcHp;
	
	
	Bag *bag = (Bag*) calloc(3, sizeof(Bag));
	for(i=0;i<3;i++){
		bag[i].item = (Item*) calloc(9, sizeof(Item));
	}
	addItem(&bag[0], getItem(0));
	addItem(&bag[0], getItem(0));
	addItem(&bag[1], getItem(1));
	addItem(&bag[1], getItem(1));
	addItem(&bag[2], getItem(1));
	addItem(&bag[2], getItem(2));
	addItem(&bag[2], getItem(3));
	
	Inventory = bag;
	
//	int selectedItem = 0;
//	*_selectedItem = &selectedItem;
	
	
//	introduction();
	_isBattling = true;
	currentRootState = BattleState;
	while(1){
		if(_isRootState){
			currentRootState.updateState();
			CheckSwitchStates();
		}else{
			currentSubState.updateState();
			CheckSwitchStates();
		}
		
	}
	
	free(currentPlayer->move);
	return 0;
}

void SwitchState(State *current, State *sub, State newState){
	clearScreen();
	printf("\n");
	if(_isRootState){
		if(_actionComplete){
			(*sub).exitState();
			_actionComplete=false;
		}
		*current=newState;
		(*current).enterState();
	}
	else{
		(*sub)=newState;
		(*sub).enterState();
	}
}

void CheckSwitchStates(){
	if(_isExploring){
		SwitchState(&currentRootState, &currentSubState, ExploreState);
	}
	if(_isBattling && !_isFighting && !_isBag){
		SwitchState(&currentRootState, &currentSubState, BattleState);
	}
	if(_isBattling && _isFighting){
		SwitchState(&currentRootState, &currentSubState, FightState);
	}
	if(_isBattling && _isBag){
		SwitchState(&currentRootState, &currentSubState, BagState);
	}
	if(_isBattling && _isStudying){
		SwitchState(&currentRootState, &currentSubState, StudyState);
	}
}
