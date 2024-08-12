#include<stdio.h>
#include<string.h>

void String_concat(char* dest,char source){
	int First_len=strlen(dest);
	dest[First_len]=source;
	dest[First_len+1]='\0';
}



void printAllKLengthrec(char set[],char *prefix,int n,int k){
	int i;
	char NewPrefix[100];
	if(k==0){
		printf("%s \n",prefix);
		return;
	}
	
	for(i=0;i<n;i++){
		strcpy(NewPrefix,prefix);
		String_concat(NewPrefix,set[i]);
		printAllKLengthrec(set,NewPrefix,n,k-1);
	}
	
	
}

void printAllKLenthnorep(char set[],char *prefix,int n,int k,int LastAdded){
	int i;
	char NewPrefix[100];
	if(k==0){
		printf("%s \n",prefix);
		return;
	}
	
	for(i=LastAdded+1;i<n;i++){
		strcpy(NewPrefix,prefix);
		String_concat(NewPrefix,set[i]);
		printAllKLenthnorep(set,NewPrefix,n,k-1,i);
	}
	
	
}

int main(){
	char set1[]={'a','b','c','d','e','f','g'};
	int k=4;
	int n=7;
	char Prefix[100]={""};
	//printAllKLengthrec(set1,Prefix,n,k);
	printAllKLenthnorep(set1,Prefix,n,k,-1);
}
