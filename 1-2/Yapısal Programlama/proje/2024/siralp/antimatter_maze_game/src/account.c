#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
////////////////////////
#include "account.h"

struct USER* head;

_Bool readUserDatas(){
	FILE* file = fopen("../data/usr.bin","rb");
	if ( file == NULL ) {
		perror("Error ");
		return 0;	
	}
	head = calloc(1,sizeof(struct USER));
	fread(head,1,sizeof(struct USER),file);
	
	struct USER* iter = head;
	struct USER* buffer = calloc(1,sizeof(struct USER));
	while ( 1 == fread(buffer,sizeof(struct USER),1,file)){	// SIRA DEGIS!
		iter->next = buffer;
		iter = buffer;
		buffer = calloc(1,sizeof(struct USER));
	}
	fclose(file);
	return 1;	
}

void mergeSort(struct USER** headRef) {
    struct USER* head = *headRef;
    struct USER* left;
    struct USER* right;

    if (head == NULL || head->next == NULL) {
        return;
    }
	// split the list 
    split(head, &left, &right);
	
    mergeSort(&left);
    mergeSort(&right);
	// merge them back together
    *headRef = merge(left, right);
}

struct USER* merge(struct USER* left, struct USER* right) {
    struct USER* result = NULL;

    // Base cases
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    if (left->score >= right->score) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void split(struct USER* source, struct USER** left, struct USER** right) {
    struct USER* fast;
    struct USER* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
  
    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

_Bool saveUsers(){
	FILE* file = fopen("../data/usr.bin","wb");
	if ( file == NULL ) {perror("Error "); return 0;}
	
	struct USER* iter = head;	
	while( iter != NULL ){
		fwrite(iter,sizeof(struct USER),1,file);
		iter = iter->next;
	}
	fclose(file);
	return 1;
}

struct USER* findLastNode(){
	struct USER* iter = head;
	if ( iter == NULL) return NULL;
	while( iter->next != NULL) 
		iter = iter->next; 
	return iter;	
}

_Bool userRegister(char username[],char psw[],char name[],char lname[]){
	_Bool cond1= isUserExist(username);
	_Bool cond2= isPswValid(psw);
	_Bool cond3= isNameValid(name,lname);
	if( !cond1 && cond2 && cond3){
		struct USER* newUser = (struct USER*)calloc(1,sizeof(struct USER));
		strcpy(newUser->username,username);
		strcpy(newUser->name,name);
		strcpy(newUser->lastname,lname);
		strcpy(newUser->password,psw);
		newUser->next = NULL;
		
		
		struct USER* lastNode = findLastNode();
		if ( lastNode == NULL) 	// meaning our newUser element will be 
			head = newUser;		// the head of the list
		else 			
			lastNode->next = newUser; // adding at the end
		_Bool _success = saveUsers();
		 
		if ( _success ) printf("\n\n\tYou have signed up successfully!");
		else printf("\n\n\tError: Unsuccessful registeration !");
		Sleep(1500);
		return 1;
	}
	else { 
		if(cond1) printf("\n\n\tThis user is already exist!");
		else if(!cond2) printf("\n\n\tYour password is invalid!");
		else if(!cond3) printf("\n\n\tYour Name/Last Name is invalid!");
		Sleep(2000);
		return 0;
	}
}

_Bool userLogin(char* username){
	struct USER* current = findUser(username);
	char psw[25];
	if ( current != NULL ){
		printf("\t\tPassword : ");
		scanf("%s",psw);
		if( !strcmp(psw,current->password) ){
			printf("\n\t\tSuccessfully logged in!");
			Sleep(800);
			return 1;
		}
		else{
			printf("\n\t\tWrong Password !");
			Sleep(750);
			return 0;
		} 
	}
	else
		printf("\n\t\tCouldn't find the user !");
	Sleep(800);
	return 0;
}

struct USER* findUser(char username[]){
	struct USER* iter = head;
	while(iter != NULL){
		if ( !strcmp(username,iter->username) )
			break;
		else iter = iter->next;
	}
	return iter;
}

_Bool isUserExist(char username[]){
	struct USER* temp = findUser(username);
	if(temp == NULL) 
		return 0;
	else 
		return 1;
}

_Bool isPswValid(char* psw){
	int len = strlen(psw);
	if ( len<3 ) return 0;
	int i;
	for(i=0; i<len ;i++){
		if( !isalpha(psw[i]) && !isdigit(psw[i]))
			return 0;
	} 
	return 1;
}

_Bool isNameValid(char* name,char* lname){
	int len1= strlen(name);
	int len2= strlen(lname);
	int i;
	for(i=0;i<len1;i++)
		if( !isalpha(name[i]))
			return 0;
	for(i=0;i<len2;i++)
		if( !isalpha(lname[i]))
			return 0;
	return 1;		
}

