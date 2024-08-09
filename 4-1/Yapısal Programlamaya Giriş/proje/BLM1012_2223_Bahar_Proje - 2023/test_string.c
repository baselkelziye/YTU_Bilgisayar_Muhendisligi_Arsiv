#include<stdio.h>
#include<string.h>
#include<time.h>

int findUser(char users[][20], int *p_userNum, char *user);
void userAdd(char users[][20], int *p_userNum);
int main() {
	/*
	char users[20][20] = {"Ahmet", "Mehmet", "Huso", "Salih2"};
	
	char *user = "Salih";
	
	int userNum=4;
	int *p_userNum = &userNum;
	int result;
	
	printf("a");
	userAdd(users, p_userNum);
	user = "Salih3";
	strcpy(users[0] ,"Ahmet2");
	result = findUser(users, p_userNum, user);
	printf("%s",users[4]);
	*/
	/*
	int a;
	float b=6.25;
	printf("%d",(int)b);
	
	clock_t start_t, end_t;
	
	start_t = clock();
	int i=1;
	while(i!=0)
		scanf("%d",&i);
		
	end_t = clock();
	
	printf("time is %d", (int)(end_t - start_t) / CLOCKS_PER_SEC);	
	
	*/
		
	return 0;
}


int findUser(char users[20][20], int *p_userNum, char *user) {
	
	int i, isThere=0;
	for(i=0;i<*p_userNum;i++){
		if(!strcmp(users[i], user))
			isThere = 1;
	}
	
	return isThere;
}

void userAdd(char users[][20], int *p_userNum) {
	
	char user[30];
	int isThere=0;
	
	printf("enter user name that add: ");
	scanf("%[^\n]s",user);
	if((*p_userNum) == 0){
		*p_userNum++;
		strcpy(users[0], user);
		printf("copy is succesfull");
	}else{
		isThere = findUser(users, p_userNum, user);
		if(isThere){
			printf("this user is already registered");
		}else{
			strcpy(users[(*p_userNum)++] ,user);
		}
	}
}
