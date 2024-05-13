#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "bagstate.h"
#include "state.h"
#include "utils.h"
#include "game.h"

extern bool _isBag;
extern bool _isRootState;
extern Player *currentPlayer;
extern Bag *Inventory;
extern int _currentBag;
extern int _item;
extern int *_noOfItems;
int _selectedItem;
extern int _currentBag;
extern bool _isBag;
extern bool _actionComplete;



void BagDisplay(){
	int i,j;
	clearScreen();
	BattleScene();
	printf(" ");
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("\n|\t\t\t\t\t\t\t\t\t|");

	printf("\n|\t\t\t[Q] < Bag %d > [E]\t\t\t\t|\n|", _currentBag+1);
	
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("|");
	printf("\n|\t\t\t\t\t\t\t\t\t|");
	for(i=0;i<*_noOfItems;i++){
		printf("\n|\t\t\t[%d]",i+1);
		for(j=0;j<20;j++){
			if(Inventory[_currentBag].item[i].name[j]!='\0'){
				printf("%c",Inventory[_currentBag].item[i].name[j]);
			}else{
				printf(" ");	
			}
		}
		printf("x%d\t\t\t|",i+1);
	}
	printf("\n|");
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("|");
}

void BagEnterState(){

}
void BagUpdateState(){

	while(1){
		_noOfItems=&Inventory[_currentBag].noOfItems;	
		BagDisplay();
		char select = getch();
		if(select=='1'){
			if(isItemExist(1, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=1;
			}
			break;
		}
		if(select=='2'){
			if(isItemExist(2, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=2;
			}
			break;
		}
		if(select=='3'){
			if(isItemExist(3, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=3;
			}
			break;
		}
		if(select=='4'){
			if(isItemExist(4, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=4;
			}
			break;
		}
		if(select=='5'){
			if(isItemExist(5, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=5;
			}
			break;
		}
		if(select=='6'){
			if(isItemExist(6, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=6;
			}
			break;
		}
		if(select=='7'){
			if(isItemExist(7, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=7;
			}
			break;
		}
		if(select=='8'){
			if(isItemExist(8, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=8;
			}
			break;
		}
		if(select=='9'){
			if(isItemExist(9, *_noOfItems)){
				_isBag = false;
				_actionComplete = true;
				_isRootState = true;
				_selectedItem=9;
			}
			break;
		}
		if(select=='q'){
			if(_currentBag>0){
				_currentBag--;	
			}
		}
		if(select=='e'){
			if(_currentBag<2){
				_currentBag++;	
			}	
		}
		if(select=='b'){
			_isBag = false;
			_isRootState = true;
			break;
		}
	}
}
void BagExitState(){
	char text1[50] = {""};
	char text2[50] = {""};
	char space[] = "  ";
	char used[] = {"   used"};
	strcat(text1, currentPlayer->name);
	strcat(text1, used);
	strcat(text2, Inventory[_currentBag].item[_selectedItem-1].name);
	clearScreen();
	BattleScene();
	dialogBox(text1, text2);
}

State BagState = {BagEnterState, BagUpdateState, BagExitState};
