#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

#include "gamefield.h"
#include "graph.h"

_Bool printMapsFolder(char* fileName){
	DIR* dir = opendir("../maps");
	if(dir == NULL) { perror("Error "); return 0;}
	struct dirent *entry;
	char files[25][25]={0};
	int fileCount=0;
	system("cls");
	printf("\n\t\t\t\t# GAMEPLAY #\n\n");
	printf("\n\t\t $ Maps $");
	while((entry = readdir(dir)) != NULL){
		if( strcmp(entry->d_name,".") && strcmp(entry->d_name,"..")){	
			strcpy(files[fileCount++],strtok(entry->d_name,"."));
		}	
	}
	int i;
	for(i=0;i<fileCount;i++){
		printf("\n\t %d)  %s",i+1,files[i]);
	}
	printf("\n\n\t  Enter Map Number: ");
	do{
		scanf("%d",&i);
		if (i < 0 || i> fileCount) printf("\t  Enter a Valid Number: ");		
	}while(i < 0 || i> fileCount);
	strcpy(fileName,files[i-1]);
	closedir(dir);
	return 1;
}

void* readGameField(char* fileName){
	char f[30] = "../maps/"; 
	strcat(f,fileName);
	FILE* file = fopen(f,"r");
	FIELD* field = (FIELD*)calloc(1,sizeof(FIELD));
	
	if(file == NULL) {perror("Error "); }
	
	int x,y; 
	// takes in field sizes via parameters at the begining of a map (eg: 3x5)
	fscanf(file,"%dx%d",&field->fieldSize[0],&field->fieldSize[1]);
	
	field->gameField = (char**)calloc(field->fieldSize[0],sizeof(char*));
	for(x=0; x<field->fieldSize[0] ;x++) 
		field->gameField[x] = (char*)calloc(field->fieldSize[1],sizeof(char));
	
	for(y=0; y<field->fieldSize[0] ;y++){
		if(!feof(file)) fgetc(file);
		for(x=0; x<field->fieldSize[1] ;x++ ){
			field->gameField[y][x] = fgetc(file);
			if(field->gameField[y][x] == 'X'){ 
				field->curLocation[0] = y; 
				field->curLocation[1] = x; 
				} 
		}
	}
	printf("\nRead Successfull!");
	return field;
}

void displayGameField(FIELD* field,int moveCount){
	int i,j;
	printf("\n\t\t%s#",_C_DEFAULT);
	for(i=0; i<field->fieldSize[1] ;i++) printf("===");
	printf("#\n\t\t|");
	for(i=0; i<field->fieldSize[0] ;i++){
		for(j=0; j<field->fieldSize[1] ;j++)
			printf(" %s%c ", (field->curLocation[0]== i && field->curLocation[1] == j) ? _C_GREEN :
							 (field->gameField[i][j] == 'P' || field->gameField[i][j] == 'p') ? _C_CYAN :
							 (field->gameField[i][j] == '1') ? _C_YELLOW : (field->gameField[i][j] == 'C') ? _C_RED :
							 (field->gameField[i][j] == 'e' || field->gameField[i][j] == 'E') ?	_C_CYAN	: _C_DEFAULT,
			field->curLocation[0]== i && field->curLocation[1] == j ?
			'X' : field->gameField[i][j] );
		if(i == field->fieldSize[0]/2) printf("|\t\t\t  |> %d Moves Left <",moveCount);
		if(i != field->fieldSize[0]-1)
			printf("%s|\n\t\t|",_C_DEFAULT);
	}
	printf("|\n\t\t#");
	for(i=0; i<field->fieldSize[1];i++) printf("===");
	printf("#");
	
}

