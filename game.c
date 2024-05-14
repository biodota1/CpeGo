#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "game.h"
#include "utils.h"


Item getItem(int select){
	if(select==0){
		Item item = {"Ballpen"};
		return item;
	}
	if(select==1){
		Item item = {"Calculator"};
		return item;
	}
	if(select==2){
		Item item = {"Paper"};
		return item;
	}
	if(select==3){
		Item item = {"Milo"};
		return item;
	}
	if(select==4){
		Item item = {"Meatroll"};
		return item;
	}
}
void addItem(Bag *bag, Item item){
	bag->item = (Item*) realloc(bag->item, sizeof(Item)*(bag->noOfItems+1));
	bag->item[bag->noOfItems] = item;
	bag->noOfItems++;
}
bool isItemExist(int item, int noOfItem){
	if(item<=noOfItem){
		return true;
	}else{
		return false;
	}
}
Move getMove(int select){
	if(select==0){
		Move move = {"Psychoanalytic Theory", "GENERAL", 15, 20, "NORMAL"};
		return move;
	}
	if(select==1){
		Move move = {"CpE Orientation", "ENGINEERING", 15, 20, "NORMAL"};
		return move;
	}
	if(select==2){
		Move move = {"Scalar and Vector", "SCITECH", 15, 20, "NORMAL"};
		return move;
	}
	if(select==3){
		Move move = {"Algebraic Expression", "MATHEMATICS", 15, 20, "NORMAL"};
		return move;
	}	
	if(select==4){
		Move move = {"C Data Types", "PROGRAMMING", 15, 20, "NORMAL"};
		return move;
	}
	if(select==5){
		Move move = {"Squats", "PE", 15, 20, "NORMAL"};
		return move;
	}
}
Subject getSubject(int select){
	if(select==0){
		Subject subject = {"GENERAL", 1, 0.10, 0.10};
		return subject;	
	}
	if(select==1){
		Subject subject = {"ENGINEERING", 1, 0.10, 0.10};
		return subject;	
	}
	if(select==2){
		Subject subject = {"SCITECH", 1, 0.10, 0.10};
		return subject;	
	}
	if(select==3){
		Subject subject = {"MATHEMATICS", 1, 0.10, 0.10};
		return subject;	
	}
	if(select==4){
		Subject subject = {"PROGRAMMING", 1, 0.10, 0.10};
		return subject;	
	}
	if(select==5){
		Subject subject = {"PE", 1, 0.10, 0.10};
		return subject;	
	}
	
	
}
Player newGame(){
	int i;
	Player player = {"", 1, 25, 30, 30, 100, 0, 0, 1};
	player.subject = (Subject*) malloc(6*sizeof(Subject));
	for(i=0;i<6;i++){
		player.subject[i] = getSubject(i);
	}
	printf("\n\n\n\t\t\t\tNEW GAME");
	printf("\n\n\n\t\tPlayer Name: ");
	scanf("%s",player.name);
	printf("\n\n\n\t\tChoose your favorite SUBJECT:");
	printf("\n\t\t[1] GENERAL\n\t\t[2] ENGINEERING\n\t\t[3] SCITECH\n\t\t[4] MATHEMATICS\n\t\t[5] PROGRAMMING\n\t\t[6] PE\n");
	printf("\n\t\tEnter your choice: ");
	while(1){
		char choice = getch();
		if(choice=='1'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(0);
			break;
		}
		if(choice=='2'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(1);
			break;
		}
		if(choice=='3'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(2);
			break;
		}
		if(choice=='4'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(3);
			break;
		}
		if(choice=='5'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(4);
			break;
		}
		if(choice=='6'){
			player.move = (Move*) malloc(sizeof(Move));
			*player.move = getMove(5);
			break;
		}
		
	}
	return player;
	
}
Npc spawnNpc(int select){
	if(select==0){
		Npc npc = {"Manong Guard", 1, 20, 20, 20, 100, 20, 10, 2};
		npc.move = (Move*) calloc(npc.noOfMove,sizeof(Move));
		npc.move[0] = getMove(0);
		npc.move[1] = getMove(1);
		npc.subject = (Subject*) malloc(sizeof(Subject));
		npc.subject[0] = getSubject(5);
		return npc;
	}
	if(select==1){
		Npc npc = {"Engr. Jundith Alterado", 3, 30, 30, 30, 150, 20, 10, 2};
		npc.move = (Move*) calloc(npc.noOfMove,sizeof(Move));
		npc.move[0] = getMove(0);
		npc.move[1] = getMove(1);
		npc.subject = (Subject*) malloc(sizeof(Subject));
		npc.subject[0] = getSubject(5);
		return npc;
	}
	if(select==2){
		Npc npc = {"Engr. Jovelyn B. Buhawe", 5, 30, 30, 30, 150, 20, 10, 2};
		npc.move = (Move*) calloc(npc.noOfMove,sizeof(Move));
		npc.move[0] = getMove(0);
		npc.move[1] = getMove(1);
		npc.subject = (Subject*) malloc(sizeof(Subject));
		npc.subject[0] = getSubject(5);
		return npc;
	}
	if(select==3){
		Npc npc = {"Engr. Jovelyn B. Buhawe", 5, 30, 30, 30, 150, 20, 10, 2};
		npc.move = (Move*) calloc(npc.noOfMove,sizeof(Move));
		npc.move[0] = getMove(0);
		npc.move[1] = getMove(1);
		npc.subject = (Subject*) malloc(sizeof(Subject));
		npc.subject[0] = getSubject(5);
		return npc;
	}
	if(select==4){
		Npc npc = {"Engr. Julian P. Semblante ", 5, 30, 30, 30, 150, 20, 10, 2};
		npc.move = (Move*) calloc(npc.noOfMove,sizeof(Move));
		npc.move[0] = getMove(0);
		npc.move[1] = getMove(1);
		npc.subject = (Subject*) malloc(sizeof(Subject));
		npc.subject[0] = getSubject(5);
		return npc;
	}
}
void introduction(){
	char text1[] = {"All Hail, Maroon and Gold!!"};
	char text2[] = {"Oh Hello there! Student"};
	char text3[] = {"I'm Dean Lauron"};
	char text4[] = {"The Dean of Computer Engineering Department"};
	char text5[] = {"Welcome to CIT - University"};
	char text6[] = {"The home of the top engineers of the country."};
	char text7[] = {"You have chosen Computer Engineering"};
	char text8[] = {"as your course."};
	char text9[] = {"Upon entering school grounds"};
	char text10[] = {"You are expected to encounter challenges."};
	char text11[] = {"Win challenges and complete your quests,"};
	char text12[] = {"Buy items and upgrade your subjects."};
	char text13[] = {"And you will be hail as"};
	char text14[] = {"THE KING OF ENGINEERS."};
	char text15[] = {"Goodluck and enjoy studying in CIT-U."};
	char text16[] = {"LABAN WILDCATS!!"};
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text1, text2);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text3, text4);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text5, text6);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text7, text8);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text9, text10);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text11, text12);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text13, text14);
	clearScreen();
	printf("\n\n\n\n\n\n\n\n\n\n");
	dialogBox(text15, text16);
}
float matchUp(char *effect, char attackerSubject[],char defenderSubject[]){
	char subjects[6][20] = {"GENERAL","ENGINEERING", "SCITECH", "MATHEMATICS", "PROGRAMMING", "PE"};
	float plusDamage = 1;
	int i,j;
	int result1;
	int result2;
	int effective;
	int notEffective;


	for(i=0;i<6;i++){
		result1 = strcmp(attackerSubject, subjects[i]);
		if(result1==0){
			if(i==5){
				effective = strcmp(defenderSubject, subjects[0]);
			}else{
				effective = strcmp(defenderSubject, subjects[i+1]);
			}
			
			if(i==0){
				notEffective = strcmp(defenderSubject, subjects[i+5]);
			}else{
				j=i+5;
				notEffective = strcmp(defenderSubject, subjects[j-5]);
			}
			
			if(effective==0){
				plusDamage = 2;
			}
			if(notEffective==0){
				plusDamage = 0.5;
			}
		}
	}
	
	if(plusDamage==2){
		strcpy(effect, "It's very effective");
	}else if(plusDamage==0.5){
		strcpy(effect, "It's not very effective");
	}else if(plusDamage==1){
		strcpy(effect, "");
	}
	return plusDamage;
	
}
float studyUp(char moveSubject[], Subject currentSubject){
	float attackUp = 0;
	int result = strcmp(moveSubject, currentSubject.name);
	if(result==0){
		attackUp = currentSubject.attack;
	}
	
	return attackUp;
}


