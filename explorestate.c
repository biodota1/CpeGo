#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "state.h"
#include "game.h"

extern char mapLines[40][220];
extern void copyLines();
extern bool _isBattling;
extern bool _isExploring;
extern int x;
extern int y;
extern int _currentTriggerY;
extern int _currentTriggerX;
extern Player *currentPlayer;
extern Bag *Inventory;

int currentBag = 0;

void changeMoves(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 10;
    //SET FRAME
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("____________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|       Select a move        |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|____________________________|");
    //SET CONTENTS
    mapCoord.X += 2;
    mapCoord.Y = 4;
    int y =1;
    int i;
    for(i=0;i<currentPlayer->noOfMove;i++){
    	SetConsoleCursorPosition(hConsole, mapCoord);
    	printf("[%d] %s",i+1, currentPlayer->moves[i].name);
    	mapCoord.Y += 2;
	}
}

bool checkCollisionLeft(int x, int y){
	bool collied = false;
	if(x==-33){
		if(y<-3 && y>-22){
			collied = true;
		}
	}
	if(x==-40){
		if(y<-32 && y>-64){
			collied = true;
		}
	}
	if(x==19){
		if(y<-38 && y>-71){
			collied = true;
		}
	}
	return collied;
}
bool checkCollisionRight(int x, int y){
	bool collied = false;
	if(x==67){
		collied = true;
	}
	if(x==-34){
		if(y<-38 && y>-71){
			collied = true;
		}
	}
	if(x==35){
		if(y<-19 && y>-72){
			collied = true;
		}
	}	
	return collied;
}
bool checkCollisionUp(int x, int y){
	bool collied = false;
	if(y==-3){
		if(x<-33 && x>-74){
			collied = true;
		}
	}
	if(y==-32){
		if(x<-40 && x>-74){
			collied = true;
		}
	}
	if(y==-38){
		if(x<19 && x>-34){
			collied = true;
		}
	}
	if(y==-19){
		if(x<68 && x>35){
			collied = true;
		}
	}
	return collied;
}
bool checkCollisionDown(int x, int y){
	bool collied = false;
	if(y==-22){
		if(x<-33 && x>-74){
			collied = true;
		}
	}
	if(y==-64){
		if(x<-40 && x>-74){
			collied = true;
		}
	}
	if(y==-71){
		if(x<19 && x>-34){
			collied = true;
		}
	}
	if(y==-72){
		if(x<68 && x>35){
			collied = true;
		}
	}
	return collied;
}

void upgradeSuccess(){
	char line1[] = {"Upgrade successfully."};
	char line2[] = {""};
	worldDialogBox(line1, line2);
}

void upgradeStudy(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 10;
    //SET FRAME
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("____________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|         UPGRADE            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|____________________________|");
    //SET CONTENTS
    mapCoord.X += 5;
    mapCoord.Y = 4;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("[Y] YES    [N] NO"); 
}

void selectStats(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 40;
    //SET FRAME
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("______________________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                STATS                 |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|______________________________________|");
    //SET CONTENTS
    mapCoord.X += 10;
    mapCoord.Y = 4;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("%s", currentPlayer->name);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("Lvl.     %d", currentPlayer->lvl);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("Hp       %.0f", currentPlayer->hp);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT      %.0f", currentPlayer->attack);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("DEF      %.0f", currentPlayer->defense);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("SPD      %.0f", currentPlayer->speed);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("EXP      %d/%d", currentPlayer->exp, currentPlayer->nextLvl);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("TALENT   %d", currentPlayer->talent);
}

void selectStudy(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 40;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("______________________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|               STUDY                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|______________________________________|");
    
    //SET CONTENTS
    mapCoord.X += 3;
    mapCoord.Y = 4;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("GENERAL      Lvl. %d   [1] UPGRADE", currentPlayer->subject[0].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[0].attack*100,currentPlayer->subject[0].defense*100);
    mapCoord.Y+=2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ENGINEERING  Lvl. %d   [2] UPGRADE", currentPlayer->subject[1].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[1].attack*100,currentPlayer->subject[1].defense*100);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("SCITECH      Lvl. %d   [3] UPGRADE", currentPlayer->subject[2].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[2].attack*100,currentPlayer->subject[2].defense*100);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("MATHEMATICS  Lvl. %d   [4] UPGRADE", currentPlayer->subject[3].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[3].attack*100,currentPlayer->subject[3].defense*100);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("PROGRAMMING  Lvl. %d   [5] UPGRADE", currentPlayer->subject[4].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[4].attack*100,currentPlayer->subject[4].defense*100);
    mapCoord.Y += 2;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("PE           Lvl. %d   [6] UPGRADE", currentPlayer->subject[0].lvl);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("ATT %.0f%%      DEF  %.0f%%", currentPlayer->subject[5].attack*100,currentPlayer->subject[5].defense*100);
}

void selectBag(){
	int i;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 40;
    //SET FRAME
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("______________________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|          <Q     BAG %d     E>         |",currentBag+1);
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|______________________________________|");
    
    //SET CONTENTS
	mapCoord.X += 13;
    mapCoord.Y = 4;
    for(i=0;i<Inventory[currentBag].noOfItems;i++){
    	SetConsoleCursorPosition(hConsole, mapCoord);
	    printf("[%d] %s",i+1, Inventory[currentBag].item[i].name);
	    mapCoord.Y += 2;
	}

}

void selectMoves(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 40;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("______________________________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|               MOVES                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|       Select a move to change        |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                                      |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|______________________________________|");
    //SET CONTENTS
	mapCoord.X += 4;
    mapCoord.Y = 6;
    int y =1;
    int i;
    for(i=0;i<4;i++){
    	SetConsoleCursorPosition(hConsole, mapCoord);
    	if(strlen(currentPlayer->move[i].name) > 0){
    		printf("[%d] %s",y, currentPlayer->move[i].name);
    		mapCoord.Y += 3;
    		y++;
		}else{
			
		}
	    
	}
}

void selectSave(){
	
}

void selectExit(){
}

void selectMenu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 0;
    mapCoord.X = 80;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("__________________");
    mapCoord.Y++;
    mapCoord.X--;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  Myer            |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  Lvl. 1          |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  HP: 25/25       |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [1] STATS       |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [2] STUDY       |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [3] BAG         |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [4] MOVES       |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [5] SAVE        |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|  [6] EXIT        |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|                  |");
    mapCoord.Y++;
    SetConsoleCursorPosition(hConsole, mapCoord);
    printf("|__________________|");
    
}

void character(int anim){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 13;
    mapCoord.X = 40;
    SetConsoleCursorPosition(hConsole, mapCoord);
	printf(" _____");
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf(" ('-')");
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("/|_;_|7");
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
    if(anim==0){	
		printf(" |   |");
	}else if(anim==1){
		printf("  \\   \\");
	}
    
}

void EnterExploreState(){
	
}
void UpdateExploreState(){
	copyLines();
	HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    int currentCoordY =88;
    int currentCoordX =72;
    int currentLimitNegY = -75;
    int currentLimitNegX = -73;
    int currentLimitPosY = 0;
    int currentLimitPosX = 67;
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = { 0, 0};

	int i;
	int anim =0;
	char displays[30][100];
	for(i=0;i<30;i++){
		displays[i][99] = '\0';
	}
	
	while(1){
	mapCoord.X = 0;
	mapCoord.Y = 0;
	for(i=0;i<30;i++){
		memcpy(displays[i], mapLines[currentCoordY+y+i] + x + currentCoordX, 99);
	}
	
	for(i=0;i<30;i++){
		SetConsoleCursorPosition(hConsole, mapCoord);
		printf("%s",displays[i]);
		mapCoord.Y++;
	}
	printf("%d,%d",x,y);
	character(anim);
	
	
	
	if(_currentTriggerY==y && _currentTriggerX==x){
		_isBattling = true;
		_isExploring = false;
		break;
	}
	
	char keyInput = getch();
	
	//KEYINPUT UP
	if(keyInput=='w')
	{
		if(y>currentLimitNegY && checkCollisionUp(x,y)==false){
			y--;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			//y=currentLimitNegY;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
	//KEYINPUT LEFT	
	}else if(keyInput=='d' )
	{
		if(x<currentLimitPosX && checkCollisionRight(x, y)==false){
			x++;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
//			x=currentLimitPosX;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
	//KEYINPUT DOWN		
	}else if(keyInput=='s' ){
		if(y<currentLimitPosY && checkCollisionDown(x,y)==false){
			y++;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
//			y=currentLimitPosY;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
	//KEYINPUT RIGHT		
	}else if(keyInput=='a'){
		if(x>currentLimitNegX && checkCollisionLeft(x,y)==false){
			x--;
			
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			//x=currentLimitNegX;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
	//KEYINPUT MENU		
	}else if(keyInput==' '){
		selectMenu();
		while(1){
			char select = getch();
			if(select == ' ' || select == 'b'){
				break;
			//STATS MENU		
			}else if(select == '1'){
				selectStats();
				while(1){
					char select = getch();
					if(select=='b'){
						break;
					}
				}
				break;
			//STUDY MENU
			}else if(select == '2'){
				selectStudy();
				while(1){
					char select = getch();
					if(select=='1'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[0].lvl++;
								currentPlayer->subject[0].attack+=.10;
								currentPlayer->subject[0].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}else if(select=='2'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[1].lvl++;
								currentPlayer->subject[1].attack+=.10;
								currentPlayer->subject[1].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}else if(select=='3'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[2].lvl++;
								currentPlayer->subject[2].attack+=.10;
								currentPlayer->subject[2].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}else if(select=='4'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[3].lvl++;
								currentPlayer->subject[3].attack+=.10;
								currentPlayer->subject[3].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}else if(select=='5'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[4].lvl++;
								currentPlayer->subject[4].attack+=.10;
								currentPlayer->subject[4].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}else if(select=='6'){
						upgradeStudy();
						while(1){
							char select = getch();
							if(select=='y'){
								upgradeSuccess();
								currentPlayer->subject[5].lvl++;
								currentPlayer->subject[5].attack+=.10;
								currentPlayer->subject[5].defense+=.10;
								break;
							}else if(select=='n' || select=='b'){
								break;
							}
							
						}
						break;
					}
					if(select=='b'){
						break;
					}
				}
				break;
			//BAG MENU	
			}else if(select == '3'){
				selectBag();
				while(1){
					char select = getch();
					
					if(select=='q'){
						if(currentBag>0){
							currentBag--;	
						}else{
							currentBag=0;
						}
						
						selectBag();
					}
					else if(select=='e'){
						if(currentBag<2){
							currentBag++;
						}else{
							currentBag=2;
						}
						
						selectBag();
					}
					else if(select=='b'){
						break;
					}
				}
				break;
			//MOVES MENU	
			}else if(select == '4'){
				selectMoves();
				while(1){
					char select = getch();
					if(select=='1'){
						changeMoves();
					}
					if(select=='b'){
						break;
					}
				}
				break;
			//SAVE	
			}else if(select == '5'){
				selectSave();
				while(1){
					char select = getch();
					if(select=='b'){
						break;
					}
				}
				break;
			//EXIT	
			}else if(select == '6'){
				selectExit();
				while(1){
					char select = getch();
					if(select=='b'){
						break;
					}
				}
				break;		
			}	
		}
	}
	}
	

}
void ExitExploreState(){
	
}

State ExploreState = {EnterExploreState, UpdateExploreState,ExitExploreState};
