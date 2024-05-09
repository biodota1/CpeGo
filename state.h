#ifndef STATE_H
#define STATE_H

typedef struct {
   	void (*enterState)();
	void (*updateState)();
	void (*exitState)();
} State;

#endif
