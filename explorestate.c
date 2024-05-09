#include<stdio.h>
#include "state.h"


void EnterExploreState(){
	printf("Enter Explore");
}

State ExploreState = {EnterExploreState};
