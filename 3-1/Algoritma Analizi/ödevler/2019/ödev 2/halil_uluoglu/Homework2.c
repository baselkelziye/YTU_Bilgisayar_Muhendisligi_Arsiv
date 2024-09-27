#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 11
#define MAX 1000

typedef struct node
{
	char *fileName;
}NODE;

NODE *hashTable;

int addFileNameToHash(char *fileName,int control);
char * getAllText(char *compositeName);
int convertTextToKey(char *text);
int hashFunction(int key,int i);
void moveFileToDirectory(char *fileName);

void main()
{
	
	FILE *file;
	char string[MAX];
	char destination[MAX];
	char **filesName=(char**)malloc(sizeof(char*)*2);
	int fileCounter=0;
	int sizeOfString=0,i=0;
	int cont=1;
	char newFileName[MAX];
	
	
	hashTable=(NODE *)calloc(sizeof(NODE),M);
	
	file=fopen("samples.txt", "r");
	if(file==NULL)
	{
		printf("[ERROR!]The samples.txt file could not open-1!\n");
		exit(-1);
	}
	
	while(fgets(string,MAX,file)!=NULL)
	{
		
		while(string[i]!='\n')
		{
			i++;
			sizeOfString++;
		}
		string[i]='\0';
		
		filesName=(char **)realloc(filesName, (fileCounter+1)*sizeof(char *));
		filesName[fileCounter]=(char *)malloc(sizeof(char)*sizeOfString);
		strcpy(filesName[fileCounter], string);
		fileCounter++;
		sizeOfString=0;
		i=0;	
	}
	
	printf("[INFO!]These are the read files from samples.txt file.\n");
	for(i=0; i<fileCounter; i++)
	{
		printf("%s\n", filesName[i]);	
	}	
	fclose(file);
	
	i=0;
	while(i<fileCounter)
	{
		strcpy(destination,"directory/");
		strcat(destination,filesName[i]);
		addFileNameToHash(destination,0);
		i++;
	}
	
	while(cont)
	{
		printf("Enter your new file name, please.\n");
		scanf("%s", newFileName);
		if(addFileNameToHash(newFileName,1))
		{
			
			file=fopen("samples.txt", "a");
			fprintf(file,"\n%s",newFileName);
			fclose(file);
			moveFileToDirectory(newFileName);
		}
	}
}

int addFileNameToHash(char *fileName,int control)
{
	char destination[MAX];
	char *text,*tempText;
	int key,add=1;
	int hash_i=0,hash;
	
	
	text=getAllText(fileName);
	
	key=convertTextToKey(text);
	hash=hashFunction(key,hash_i);
	
	while(hashTable[hash].fileName && add)
	{
		if(control)
		{
			tempText=getAllText(hashTable[hash].fileName);
			if(!strcmp(text,tempText))
			{
				printf("[INFO!]This file has been added into Hash Table.\n");
				add=0;
			}
			free(tempText);
		}
		if(add)
		{
			printf("[INFO!]This %s file can not add.%d hash value is full!\n", fileName, hash);
			hash_i++;
			key=convertTextToKey(text);
			hash=hashFunction(key,hash_i);
		}
	}
	
	if(add)
	{
		hashTable[hash].fileName=(char *)(malloc(strlen(fileName)* sizeof(fileName)));
		strcpy(hashTable[hash].fileName,fileName);
		printf("[INFO!]This %s file added into this value %d.\n", fileName,hash);
	}
	free(text);
	
	return add;
}

char * getAllText(char *compositeName)
{
	FILE *file;
	char *allText=(char *)calloc(sizeof(char),0);
	char string[MAX];
	int textLength=0;
	
	file=fopen(compositeName,"r");
	if(file==NULL)
	{
		printf("[ERROR!]The samples.txt file could not open-2!\n");
		
		exit(-2);
	}
	
	while(fgets(string,MAX,file)!=NULL)
	{
		textLength=textLength+strlen(string);
		allText=(char *)realloc(allText,sizeof(char)*textLength);
	}
	strcat(allText,string);
	fclose(file);
	
	return allText;
}

int convertTextToKey(char *text)
{
	int i;
	int key=0;
	int R=5;
	int length=strlen(text)-1;
	int tempLen=length;
	
	for(i=0; i<=length; i++)
	{
		key+=text[i]*pow(5,tempLen);
		tempLen--;
	}
	return key;
}

int hashFunction(int key,int i)
{
	int h1,h2;
	int hash;
	
	h1=key%M;
	h2=1+(key%(M-1));	
	hash=(h1+i*h2)%M;
	
	if(hash<0)
	{
		hash*=-1;
	}
	return hash;
}
void moveFileToDirectory(char *fileName)
{
	FILE *file1,*file2;
	char string1[MAX],string2[MAX];
	char ch;
	
	file1=fopen(fileName,"r");
	if(file1==NULL)
	{
		printf("[ERROR!]The file could not open-3!\n");
		fclose(file1);
		exit(-3);
	}
	
	strcpy(string1,"directory/");
	strcat(string1,fileName);
	
	file2=fopen(string1,"w");
	if(file2==NULL)
	{
		printf("[ERROR!]The file could not open-4!\n");
		fclose(file2);
		exit(-4);
	}
	printf("[INFO!]The new file is moving...\n");
	while(ch=fgetc(file1)!=EOF)
	{
		fputc(ch,file2);
	}
	printf("[INFO!]The new file moved.\n");
	fclose(file1);
	fclose(file2);
}
