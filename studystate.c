#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>

#include "studystate.h"
#include "state.h"
#include "utils.h"
#include "game.h"

extern bool _isStudying;
extern bool _isRootState;
extern bool _actionComplete;
extern Subject *currentSubject;
extern Player *currentPlayer;

int _subject;

void StudyDisplay(){
	clearScreen();
	BattleScene();
	int i =0;
	int j=0;
	printf(" \n ");
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("\n|\t\t\t\t\t\t\t\t\t|");

	printf("\n|\t\t\t\tStudy\t\t\t\t\t|\n|");
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("|");
	printf("\n|\t\t\t\t\t\t\t\t\t|");
	printf("\n|\t[1] GENERAL    \tLvl 1\t\t[4] MATHEMATICS\t Lvl 1\t\t|");
	printf("\n|\t\t\t\t\t\t\t\t\t|");
	printf("\n|\t[2] ENGINEERING\tLvl 1\t\t[5] PROGRAMMING\t Lvl 1\t\t|");
	printf("\n|\t\t\t\t\t\t\t\t\t|");
	printf("\n|\t[3] SCITECH\tLvl 1\t\t[6] PE\t         Lvl 1\t\t|");
	printf("\n|\t\t\t\t\t\t\t\t\t|\n|");
	for(i =0;i<71;i++){
		printf("_");
	}
	printf("|");
}

void StudyEnterState(){
	printf("Enter STUDY");
}
void StudyUpdateState(){
	while(1){
		StudyDisplay();
		char select = getch();
		if(select=='1'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 0;
			break;
		}
		if(select=='2'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 1;
			break;
		}
		if(select=='3'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 2;
			break;
		}
		if(select=='4'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 3;
			break;
		}
		if(select=='5'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 4;
			break;
		}
		if(select=='6'){
			_isStudying = false;
			_actionComplete = true;
			_isRootState = true;
			_subject = 5;
			break;
		}
		if(select=='b'){
			_isStudying = false;
			_isRootState = true;
			break;
		}
	}
}
void StudyExitState(){
	*currentSubject = currentPlayer->subject[_subject];
	char text1[40] = {""};
	char text2[40] = {""};
	char text3[40] = {""};
	char text4[40] = {""};

	strcat(text1, currentPlayer->name);
	strcat(text1, "  study");
	strcat(text2, currentSubject->name);
	
	strcat(text3, currentSubject->name);
	strcat(text3, " Attack rose.");
	strcat(text4, currentSubject->name);
	strcat(text4, " Defense rose.");
	clearScreen();
	BattleScene();
	dialogBox(text1, text2);
	sleep(1);
	clearScreen();
	BattleScene();
	dialogBox(text3, text4);
}


State StudyState = {StudyEnterState, StudyUpdateState, StudyExitState};
