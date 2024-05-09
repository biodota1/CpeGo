#include<stdio.h>
#include<string.h>
#include<windows.h>

#include "utils.h"


void clearScreen() {
    system("cls"); 
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void dialogBox(char getText1[50], char getText2[50]){
	int i =0;
	char text1[50] = {""};
	char text2[50] = {""};
	strcat(text1, getText1);
	strcat(text2, getText2);
	printf("\n");
	for(i=0;i<73;i++){
		printf("_");
	}
	printf("\n\n\t\t");
	for(i=0;i<50;i++){
		printf("%c",text1[i]);
		Sleep(30);
	}
	printf("\n\n\t\t");
	for(i=0;i<50;i++){
		printf("%c",text2[i]);
		Sleep(30);
	}
	printf("\n");
	for(i=0;i<73;i++){
		printf("_");
	}
	Sleep(1);

}
void selectionBox(char getText1[], char getText2[]){
	int i =0;
	char text1[62] = {""};
	char text2[62] = {""};
	strcat(text1,getText1);
	strcat(text2,getText2);
	
	printf("\n ");
	for(i=0;i<71;i++){
		printf("_");
	}
	printf("\n|\t\t\t\t\t\t\t\t\t|\n|\t  ");
	for(i=0;i<sizeof(text1);i++){
		if(text1[i]=='\0'){
			printf(" ");
		}else{
			printf("%c",text1[i]);
		}	
	}
	printf("|");
	printf("\n|\t\t\t\t\t\t\t\t\t|\n|\t  ");
	for(i=0;i<sizeof(text2);i++){
		if(text2[i]=='\0'){
			printf(" ");
		}else{
			printf("%c",text2[i]);
		}	
	}
	printf("|\n|");
	for(i=0;i<71;i++){
		printf("_");
	}
	printf("|");
	
}

