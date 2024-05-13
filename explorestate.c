#include<stdio.h>
#include "state.h"
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

extern char mapLines[40][220];
extern void copyLines();

void character(int anim){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = {0, 0};
	mapCoord.Y = 10;
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
	printf("Enter Explore");
}
void UpdateExploreState(){
	copyLines();
	HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    int currentCoordY =91;
    int currentCoordX =72;
    int currentLimitNegY = -75;
    int currentLimitNegX = -73;
    int currentLimitPosY = 0;
    int currentLimitPosX = 67;
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mapCoord = { 0, 0};

	int x=0,y=0;
	int anim =0;
	char display01[100];
	char display02[100];
	char display03[100];
	char display04[100];
	char display05[100];
	char display06[100];
	char display07[100];
	char display08[100];
	char display09[100];
	char display10[100];
	char display11[100];
	char display12[100];
	char display13[100];
	char display14[100];
	char display15[100];
	char display16[100];
	char display17[100];
	char display18[100];
	char display19[100];
	char display20[100];
	char display21[100];
	char display22[100];
	char display23[100];
	char display24[100];
	char display25[100];
	char display26[100];
	char display27[100];
	char display28[100];
	char display29[100];
	char display30[100];
	display01[99] - '\0';
	display02[99] - '\0';
	display03[99] - '\0';
	display04[99] - '\0';
	display05[99] - '\0';
	display06[99] - '\0';
	display07[99] - '\0';
	display08[99] - '\0';
	display09[99] - '\0';
	display10[99] - '\0';
	display11[99] - '\0';
	display12[99] - '\0';
	display13[99] - '\0';
	display14[99] - '\0';
	display15[99] - '\0';
	display16[99] - '\0';
	display17[99] - '\0';
	display18[99] - '\0';
	display19[99] - '\0';
	display20[99] - '\0';
	display21[99] - '\0';
	display22[99] - '\0';
	display23[99] - '\0';
	display24[99] - '\0';
	display25[99] - '\0';
	display26[99] - '\0';
	display27[99] - '\0';
	display28[99] - '\0';
	display29[99] - '\0';
	display30[99] - '\0';

	
loop:
	mapCoord.X = 0;
	mapCoord.Y = 0;
	memcpy(display01, mapLines[currentCoordY+y] + x + currentCoordX, 99);
	memcpy(display02, mapLines[currentCoordY+y+1] + x + currentCoordX, 99);
	memcpy(display03, mapLines[currentCoordY+y+2] + x + currentCoordX, 99);
	memcpy(display04, mapLines[currentCoordY+y+3] + x + currentCoordX, 99);
	memcpy(display05, mapLines[currentCoordY+y+4] + x + currentCoordX, 99);
	memcpy(display06, mapLines[currentCoordY+y+5] + x + currentCoordX, 99);
	memcpy(display07, mapLines[currentCoordY+y+6] + x + currentCoordX, 99);
	memcpy(display08, mapLines[currentCoordY+y+7] + x + currentCoordX, 99);
	memcpy(display09, mapLines[currentCoordY+y+8] + x + currentCoordX, 99);
	memcpy(display10, mapLines[currentCoordY+y+9] + x + currentCoordX, 99);
	memcpy(display11, mapLines[currentCoordY+y+10] + x + currentCoordX, 99);
	memcpy(display12, mapLines[currentCoordY+y+11] + x + currentCoordX, 99);
	memcpy(display13, mapLines[currentCoordY+y+12] + x + currentCoordX, 99);
	memcpy(display14, mapLines[currentCoordY+y+13] + x + currentCoordX, 99);
	memcpy(display15, mapLines[currentCoordY+y+14] + x + currentCoordX, 99);
	memcpy(display16, mapLines[currentCoordY+y+15] + x + currentCoordX, 99);
	memcpy(display17, mapLines[currentCoordY+y+16] + x + currentCoordX, 99);
	memcpy(display18, mapLines[currentCoordY+y+17] + x + currentCoordX, 99);
	memcpy(display19, mapLines[currentCoordY+y+18] + x + currentCoordX, 99);
	memcpy(display20, mapLines[currentCoordY+y+19] + x + currentCoordX, 99);
	memcpy(display21, mapLines[currentCoordY+y+20] + x + currentCoordX, 99);
	memcpy(display22, mapLines[currentCoordY+y+21] + x + currentCoordX, 99);
	memcpy(display23, mapLines[currentCoordY+y+22] + x + currentCoordX, 99);
	memcpy(display24, mapLines[currentCoordY+y+23] + x + currentCoordX, 99);
	memcpy(display25, mapLines[currentCoordY+y+24] + x + currentCoordX, 99);
	memcpy(display26, mapLines[currentCoordY+y+25] + x + currentCoordX, 99);
	memcpy(display27, mapLines[currentCoordY+y+26] + x + currentCoordX, 99);
	memcpy(display28, mapLines[currentCoordY+y+27] + x + currentCoordX, 99);
	memcpy(display29, mapLines[currentCoordY+y+28] + x + currentCoordX, 99);
	memcpy(display30, mapLines[currentCoordY+y+29] + x + currentCoordX, 99);
	
	
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display01);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display02);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display03);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display04);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display05);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display06);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display07);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display08);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display09);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display10);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display11);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display12);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display13);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display14);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display15);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display16);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display17);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display18);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display19);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display20);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display21);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display22);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display23);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display24);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display25);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display26);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display27);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display28);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display29);
	mapCoord.Y++;
	SetConsoleCursorPosition(hConsole, mapCoord);
	printf("%s",display30);
	printf("%d",y);	
	character(anim);
	
	
	char keyInput = getch();
	
	if(keyInput=='w')
	{
		if(y>currentLimitNegY){
			y--;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			y=currentLimitNegY;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
		goto loop;
	}else if(keyInput=='d')
	{
		if(x<currentLimitPosX){
			x++;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			x=currentLimitPosX;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
		goto loop;
	}else if(keyInput=='s'){
		if(y<currentLimitPosY){
			y++;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			y=currentLimitPosY;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
		goto loop;
	}else if(keyInput=='a'){
		if(x>currentLimitNegX){
			x--;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}else{
			x=currentLimitNegX;
			if(anim<1){
				anim++;
			}else{
				anim=0;
			}
		}
		goto loop;
	}else{
		goto loop;
	}

}
void ExitExploreState(){
	
}

State ExploreState = {EnterExploreState, UpdateExploreState,ExitExploreState};
