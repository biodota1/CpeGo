#include<stdbool.h>

#ifndef GAME_H
#define GAME_H



typedef struct Item{
	char name[20];
	float value;
	char effects[20];
}Item;

typedef struct Bag{
	int noOfItems;
	Item *item;
}Bag;

typedef struct Move{
	char name[30];
	char subject[20];
	float damage;
	int pp;
	char status[20];
}Move;

typedef struct Subject{
	char name[20];
	int lvl;
	float attack;
	float defense;
}Subject;

typedef struct Npc{
	char name[40];
	int lvl;
	float hp;
	float attack;
	float defense;
	int speed;
	int exp;
	int talent;
	int noOfMove;
	Subject *subject;
	Move *move;
	Item *item;
}Npc;

typedef struct Player{
	char name[40];
	int lvl;
	float hp;
	float attack;
	float defense;
	int speed;
	int exp;
	int nextLvl;
	int talent;
	int noOfMove;
	Move *move;
	Subject *subject;
	Move *moves;
	Item *item;
}Player;

typedef struct Event{
	Npc *npc;
	int coordTriggerX;
	int coordTriggerY;
	bool isImportant;
	void (*initEvent)();
	struct Event *next;
}Event;

Player newGame();
Npc spawnNpc(int select);
Move getMove(int select);
Item getItem(int select);
Subject getSubject(int select);
void addItem(Bag *bag, Item item);
bool isItemExist(int item, int noOfItem);
void Introduction();
float matchUp(char *effect, char attackerSubject[],char defenderSubject[]);
float studyUp(char moveSubject[], Subject currentSubject);
Move npcMove(Npc *currentNpc);
Move skillTree(Player **currentPlayer);


#endif
