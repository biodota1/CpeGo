#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "game.h"
#include "utils.h"
#include "event.h"

extern Npc *currentNpc;
extern float _npcHp;
extern float _npcHpMultiple;
extern float _npcCurrentHp;
extern int _currentTriggerX;
extern int _currentTriggerY;
extern bool _isImportantEvent;

void initEvent(Event **event){
	currentNpc = (*event)->npc;
	_currentTriggerY = (*event)->coordTriggerY;
	_currentTriggerX = (*event)->coordTriggerX;
	_isImportantEvent = (*event)->isImportant;
	_npcHp = currentNpc->hp;
	_npcHpMultiple = _npcHp/20;
	_npcCurrentHp = _npcHp;
}

Event *createEvent(int x, int y, bool important, Npc *npc){
	Event *event = malloc(sizeof(Event));
	event->npc = npc;
	event->coordTriggerX=x;
	event->coordTriggerY=y;
	event->isImportant=important;
	return event;
}



void getEvents(Event **currentEvent){
	Npc *npc1 = malloc(sizeof(Npc));
	Npc *npc2 = malloc(sizeof(Npc));
	Npc *npc3 = malloc(sizeof(Npc));
	Npc *npc4 = malloc(sizeof(Npc));
	Npc *npc5 = malloc(sizeof(Npc));
	*npc1 = spawnNpc(0);
	*npc2 = spawnNpc(1);
	*npc3 = spawnNpc(2);
	*npc4 = spawnNpc(3);
	*npc5 = spawnNpc(4);
	Event *event1 = createEvent(0,-10,false,npc1);
	Event *event2 = createEvent(0,-2,false,npc2);
	Event *event3 = createEvent(0,-20,false,npc3);
	Event *event4 = createEvent(0,-30,false,npc4);
	Event *event5 = createEvent(0,-40,false,npc5);
	event1->next = event2;
	event2->next = event3;
	event3->next = event4;
	event4->next = event5;
	event5->next = NULL;
	*currentEvent = event1;
}


