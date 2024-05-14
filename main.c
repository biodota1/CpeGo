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
#include "event.h"

//INITIALIZE VALUES
bool _isRootState = true;
bool _isExploring = false;
bool _isBattling  = false;
bool _isFighting  = false;
bool _isStudying  = false;
bool _isBag       = false;
bool _isAbsent    = false;
bool _actionComplete = false;
bool _isIntro     = false;
bool _isImportantEvent = false;
bool _isEventCompleted = false;

float _playerHp;
float _playerHpMultiple;
float _playerCurrentHp;
float _npcHp;
float _npcHpMultiple;
float _npcCurrentHp;

int *_noOfItems;
int _currentBag=0;
int _item = 0;
int _currentTriggerX;
int _currentTriggerY;
int x=0;
int y=0;

State currentRootState;
State currentSubState;
Subject *currentSubject;
Player *currentPlayer;
Event *currentEvent;
Npc *currentNpc;
Bag *Inventory;

void CheckSwitchStates();
void SwitchStates(State *currentState, State newState);


int main() {
	int i;
	
	hideCursor();
	//NEW GAME
	Player player = newGame();
	currentPlayer = &player;
	currentSubject = &player.subject[0];
	_playerHp = currentPlayer->hp;
	_playerHpMultiple = _playerHp/20;
	_playerCurrentHp = _playerHp;

//	//BAG SETTING
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
	
//	introduction();
	_isExploring = true;
	currentRootState = ExploreState;
	getEvents(&currentEvent);
	initEvent(&currentEvent);
	_npcHp = currentNpc->hp;
	_npcHpMultiple = _npcHp/20;
	_npcCurrentHp = _npcHp;

	while(1){
		if(_isRootState){
			if(_isEventCompleted){
				_isEventCompleted=false;
				initEvent(&currentEvent);
				if(currentEvent==NULL){
					break;
				}
			}
			currentRootState.updateState();
			CheckSwitchStates();
		}else{
			currentSubState.updateState();
			CheckSwitchStates();
		}	
	}
	printf("You win");
	
	//free(currentPlayerj->move);
	return 0;
}

void SwitchState(State *current, State *sub, State newState){
	if(_isRootState){
		if(_actionComplete){
			(*sub).exitState();
			_actionComplete=false;
		}
		(*current).exitState();
		*current=newState;
		(*current).enterState();
	}
	else{
		(*sub)=newState;
		(*sub).enterState();
	}
}

void CheckSwitchStates(){
	if(_isExploring == true){
		SwitchState(&currentRootState, &currentSubState, ExploreState);
	}
	if(_isBattling && !_isFighting && !_isBag && !_isStudying){
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


