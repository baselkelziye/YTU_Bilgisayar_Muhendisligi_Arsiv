#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_FILE_NAME 100
#define MAX_TEXT_LENGTH 1000
#define MAX_SUBSTRING_LENGTH 20
void shiftTable(char*,int*,int,int);
int BoyerMoore(char*,char*,int*,int*);
int BoyerMoore_noncase(char*,char*,int*,int*);
int abs_sub(char,char);
void replace(char*,char*,char*,int);
int main(int argc, char** argv) {

	char filename[MAX_FILE_NAME];
	char* buffer = (char*)malloc(MAX_TEXT_LENGTH*sizeof(char));
	char* substring = (char*)malloc(MAX_SUBSTRING_LENGTH*sizeof(char));
	char* replaced = (char*)malloc(MAX_SUBSTRING_LENGTH*sizeof(char));
	int* table = (int*)malloc(sizeof(int)*256);
	int case_ctrl;
	int found=0;
	int index;

	printf("Enter the file name that has your string: ");
	scanf("%s",filename);

	FILE* fp = fopen(filename,"r+");
	if(fp == NULL) {
		fprintf(stderr,"File have not opened!\n");
		exit(0);
	}

	fread(buffer,sizeof(char)*MAX_TEXT_LENGTH,1,fp);

	printf("For case sensitivity press 1, else 0: ");
	scanf("%d",&case_ctrl);
	printf("Enter the substring you want to find and replace: ");
	scanf(" %[^\n]s",substring);
	printf("Replace with: ");
	scanf(" %[^\n]s",replaced);

	clock_t t;
	t = clock();

	if(case_ctrl == 0) {
		char o1 = 'A';
		shiftTable(substring,table,o1,256);
		index = BoyerMoore_noncase(buffer,substring,table,&found);
		while(index != -1) {
			replace(buffer,substring,replaced,index);
			index = BoyerMoore_noncase(buffer,substring,table,&found);
		}
		fclose(fp);
		fp = fopen(filename,"w");
		printf("%s",buffer);
		fprintf(fp,"%s",buffer);
  	fclose(fp);

	}
	else if(case_ctrl == 1) {
		char o2 = 'A';
		shiftTable(substring,table,o2,256);
		index = BoyerMoore(buffer,substring,table,&found);
		while(index != -1) {
    	replace(buffer,substring,replaced,index);
			index = BoyerMoore(buffer,substring,table,&found);
    }
		fclose(fp);
		fp = fopen(filename,"w");
		printf("%s",buffer);
	  fprintf(fp,"%s",buffer);
  	fclose(fp);

	}
	else{
		fprintf(stderr,"Operation cannot be recognized! \n");
		exit(0);
	}
	t= clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Found and replaced: %d \n",found);
	printf("Running time is %f seconds.\n",time_taken);

	return 0;
}
int abs_sub(char a,char b) {
	if(a-b > 0) {
		return a-b;
	}
	else{
		return -(a-b);
	}
}

void shiftTable(char* sub, int* right, int offset, int size){
	int i;
	int M = strlen(sub);
	for(i=0; i<size; i++) {
		right[i] = -1;
	}
	for(i=0; i<M; i++) {
		right[(int)sub[i]] = i;
		if((int)sub[i]>= 65 || (int)sub[i]<=90) {
			right[(int)sub[i] + 32] = 1;
		}
	}
}

int BoyerMoore(char* buffer, char* substring, int* table, int* found) {
	int i,j,skip=0;
	int M = strlen(substring);
	int N = strlen(buffer);
	for(i=0; i<N-M; i+=skip){
		j = M-1;
		while(substring[j] == buffer[i+j] && j>=0) {
			j--;
		}
		if(j>=0) {
			skip =j- table[(int)buffer[i+j]];
			if(skip<=0) {
				skip = 1;
			}
		}
		else{
			(*found)++;
			return i;
		}
	}
	return -1;
}

int BoyerMoore_noncase(char* buffer, char* substring, int* table, int* found) {
  int i,j,skip=0;
  int M = strlen(substring);
  int N = strlen(buffer);
  for(i=0; i<N-M; i+=skip){
    j = M-1;
//	printf("skip: %d\n",skip);
    while(j>=0 && (abs_sub(substring[j], buffer[i+j]) == 0 || abs_sub(substring[j],buffer[i+j])==32)) {
      j--;
    }
    if(j>=0) {
      skip =j-table[(int)buffer[i+j]];
      if(skip<=0) {
        skip = 1;
      }
    }
    else{
			(*found)++;
			return i;
    }
  }
	return -1;
}


void replace(char* buffer,char* sub, char* with, int start) {
	int i,j,k;
	if(strlen(sub) == strlen(with)) {
		i = 0;
		for(j=start; j<start+strlen(with); j++) {
			buffer[j] = with[i];
			i++;
		}
	}
	else if(strlen(sub) > strlen(with)) {
		i = 0;
		for(j=start; j<start+strlen(with); j++) {
			buffer[j] = with[i];
			i++;
		}
		k = j;
		while(buffer[k+strlen(sub) - strlen(with)] != '\0'){
			buffer[k] = buffer[k+strlen(sub) - strlen(with)];
			k++;
		}
		buffer[k] = buffer[k+strlen(sub) - strlen(with)];
	}
	else if(strlen(sub) < strlen(with)) {
		for(i=strlen(buffer)+1; i>=strlen(sub)+start; i--) {
			buffer[i+strlen(with)-strlen(sub)] = buffer[i];
		}
		i=0;
		for(j=start; j<strlen(with)+start; j++) {
			buffer[j] = with[i];
			i++;
		}
	}
}
