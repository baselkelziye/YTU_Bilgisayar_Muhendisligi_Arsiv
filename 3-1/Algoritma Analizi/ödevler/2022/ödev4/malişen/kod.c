

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

typedef enum {false, true} bool;

typedef struct user
{
    int id;
    char *name;
    char *surname;
    int *followings;
    int *followers;
    int followingsCount;
    int followersCount; //INDEGREE
    int *totalFollowers;
    int totalFollowersCount;
}USER;

/**/
typedef struct stack {
  int data[MAX];
  int top;
}STACK;

void calculateAlltotalFollowers(USER* userArray, int** adjMatrix, int numUsers);
void stackPush(STACK* stack, int element) {
	int i;
	if(stack->top == MAX - 1){
		printf("Stack is full");
	}else{
		i = 0;
		if(stack->top == -1){
			stack->top++;
			stack->data[stack->top] = element;
		}else{
			while(stack->data[i] != element && i < stack->top){
			i++;
		}
		if(i == stack->top){
			stack->top++;
			stack->data[stack->top] = element;
		}else{
			printf("This element is already in the stack");
		}

		}
		
		
	}
			
}
		


// stackPop the top element from the stack
int stackPop(STACK* stack) {
 if(stack->top == -1){
	return -1;
 }else{
	  int element = stack->data[stack->top];
  	stack->top--;
  	return element;
 }

}

	
bool stackIsEmpty(STACK* stack) {
  return stack->top == -1;
}

bool stackIsFull(STACK* stack) {
  return stack->top == MAX - 1;
}

void printAdjMatrix(int **adjMatrix, int allUser)
{printf("adjMatrix================================\n");
    int i,j;
    for(i=0;i<allUser+1;i++){
	for(j=0;j<allUser+1;j++){
		if(i == 0){
			adjMatrix[i][j] = j;
		}else if(j == 0){
			adjMatrix[i][j] = i;
		}

		printf("%d |", adjMatrix[i][j]);
		
	}
	printf("\n");
    }
}


void addUser2Array(FILE *fp,USER *userArray ,int allUser,USER *user)
{
    char line[100];
    char *token;
    char delimit[]= " ,\t\r\n\v\f";
    int check = 1;
    int userID;
    //userArray[0] = *user;
    int i = 1;
    while(fgets(line, 100, fp) != NULL){
	if(check %2 == 1){
		user = (USER*)malloc(sizeof(USER));
		token = strtok(line, delimit);
		userID = atoi(token);

		user->id = userID;

		token = strtok(NULL, delimit);
		user->name = (char*)malloc(sizeof(char)*strlen(token));
		strcpy(user->name, token);
		token = strtok(NULL, delimit);
		user->surname = (char*)malloc(sizeof(char)*strlen(token));
		strcpy(user->surname, token);
		user->followingsCount = 0;
		user->followersCount = 0;
		user->followings = NULL;
		user->followers = NULL;
		user->totalFollowers = NULL;
		user->totalFollowersCount = 0;
		userArray[i] = *user;
		check++;
	}else{

		check++;
		i++;
	}
	
    }
    fseek(fp, 0, 0);
    
}

int countUserId(FILE *fp)
{
    char line[100];
    char *token;
     char delimit[]= " ,\t\r\n\v\f";
    int check = 0;
    int userID;
    int i = 0;
    while(fgets(line, 100, fp) != NULL){
	if(check %2 == 1){
		token = strtok(line, delimit);
		userID = atoi(token);

		i++;
	}
	check++;
    }
    fseek(fp, 0, 0);
    return i;
}
void beingAdjMatrix(FILE *fp, int **adjMatrix, int allUser){
	int i,j;
	int check;
    check = 1;
    int userID;
    int followingID;
    char line[100];
    char *token;
    char delimit[]= " ,\t\r\n\v\f";
    while(fgets(line, 100, fp) != NULL){
	if(check %2 == 1){
		token = strtok(line, delimit);
		userID = atoi(token);
		check++;
	}else{
		token = strtok(line, delimit);
		while(token != NULL){
			followingID = atoi(token);
			adjMatrix[userID][followingID] = 1;
			token = strtok(NULL, delimit);
		}
		check++;
	}

    }
    fseek(fp, 0, 0);
}	

void createFollowingsFollowers(USER *userArray, int **adjMatrix, int allUser)
{
    int i,j;
    for(i=1; i<allUser+1; i++){
	for(j=1; j<allUser+1; j++){
	    if(adjMatrix[i][j] == 1){
		userArray[i].followings = (int*)realloc(userArray[i].followings, sizeof(int)*(userArray[i].followingsCount+1));
		userArray[i].followings[userArray[i].followingsCount] = j;
		userArray[i].followingsCount++;
		userArray[j].followers = (int*)realloc(userArray[j].followers, sizeof(int)*(userArray[j].followersCount+1));
		userArray[j].followers[userArray[j].followersCount] = i;
		userArray[j].followersCount++;
	    }
	}
    }
}
void printUserArray(USER *userArray, int allUser){	
	printf("printUserArray\n");
	//printf("userId, name, surname, followingsCount, followersCount, followings, followers\n")
    int i,j;
    for(i=1; i<allUser+1; i++){
		if(userArray[i].followingsCount != 0){
		printf("%d, %s, %s,D. F.ings: %d, D. F.wer(inDegree):%d ==> ", userArray[i].id, userArray[i].name, userArray[i].surname, userArray[i].followingsCount, userArray[i].followersCount);
	// Follower ve Following id degerlerini gormek istiyorsan yorum satirlarini ac
	
	/*
		printf("Followings: ");
		for(j=0; j<userArray[i].followingsCount; j++){
	    	 printf("%d ", userArray[i].followings[j]);
		}	
	if(userArray[i].followersCount != 0){
	printf("Followers: ");
		for(j=0; j<userArray[i].followersCount; j++){
	   	 printf("%d ", userArray[i].followers[j]);
		}
	}
	*/

		if(userArray[i].totalFollowersCount != 0){
			printf("TotalDegree Cnt: %d", userArray[i].totalFollowersCount-1);
		}
	printf("\n");
		}	
	}
}


void updateFollowingsFollowersByMatrix(USER *userArray, int **adjMatrix, int allUser){
	int i,j;
    if(userArray != NULL){
	for(i=1; i<allUser+1; i++){
	    userArray[i].followersCount = 0;
	    userArray[i].followingsCount = 0;
	    free(userArray[i].followers);
	    free(userArray[i].followings);
	    userArray[i].followers = NULL;
	    userArray[i].followings = NULL;
	    userArray[i].totalFollowers = NULL; 
	    userArray[i].totalFollowersCount = 0;

	}
    }
    for(i=1; i<allUser+1; i++){
	for(j=1; j<allUser+1; j++){
	    if(adjMatrix[i][j] == 1){
		userArray[i].followings = (int*)realloc(userArray[i].followings, sizeof(int)*(userArray[i].followingsCount+1));
		userArray[i].followings[userArray[i].followingsCount] = j;
		userArray[i].followingsCount++;
		userArray[j].followers = (int*)realloc(userArray[j].followers, sizeof(int)*(userArray[j].followersCount+1));
		userArray[j].followers[userArray[j].followersCount] = i;
		userArray[j].followersCount++;
	    }
	}
    }
}

void eliminateMatrix(int **adjMatrix, USER *userArray, int allUser, int N)
{
	int i,j;
	int check = 1;
	int *eliminate = (int*)malloc(sizeof(int)*allUser);
	for(i=0; i<allUser+1; i++){
		eliminate[i] = 0;
	}
	
	while(check != 0){
		for(i=1; i<allUser+1; i++){
			if(userArray[i].followersCount < N){
				eliminate[i] = 1;
			}
		}
		check = 0;
		for(i=1; i<allUser+1; i++){
			if(eliminate[i] == 1){
				for(j=1; j<allUser+1; j++){
					if(adjMatrix[i][j] == 1){
						adjMatrix[i][j] = 0;
						check++;
					}
				}for(j=1; j<allUser+1; j++){
					if(adjMatrix[j][i] == 1){
						adjMatrix[j][i] = 0;
						check++;
					}
				}
			}
		}
		for(i=1; i<allUser+1; i++){
			if(eliminate[i] == 1){
				userArray[i].followingsCount = 0;
				userArray[i].followersCount = 0;
				free(userArray[i].followers);
				free(userArray[i].followings);
				userArray[i].followers = NULL;
				userArray[i].followings = NULL;
				userArray[i].totalFollowers = NULL;
				userArray[i].totalFollowersCount = 0;
			}
		}		
	}
    free(eliminate);
}
   

void calculatetotalFollowersDFS(USER* userArray, int** adjMatrix, int userId, int** totalFollowers, int* totalFollowersCount, int* visited) {
  int i;
  for ( i = 0; i < userArray[userId].followersCount; i++) {
    int followerId = userArray[userId].followers[i];
    if (!visited[followerId] && followerId != 0) {

      visited[followerId] = 1;

      *totalFollowers = (int*)realloc(*totalFollowers, (*totalFollowersCount + 1) * sizeof(int));
      (*totalFollowers)[(*totalFollowersCount)++] = followerId;

      calculatetotalFollowersDFS(userArray, adjMatrix, followerId, totalFollowers, totalFollowersCount, visited);
    }
  }
}

void calculateAlltotalFollowers(USER* userArray, int** adjMatrix, int numUsers) {
  int i,j;
  int visited[numUsers+1];
  for ( i = 1; i < numUsers+1; i++) {
	if(userArray[i].id != 0){


  if(userArray[i].totalFollowers != NULL){
		free(userArray[i].totalFollowers);
		userArray[i].totalFollowers = NULL;
		userArray[i].totalFollowersCount = 0;
	}

    int* totalFollowers = NULL;
    int totalFollowersCount = 0;


    for(j=1; j<numUsers+1; j++){
		visited[j] = 0;
		if(j==i){
			visited[j] = 1;
		}
    }
    
	
	totalFollowers = (int*)realloc(totalFollowers, (totalFollowersCount + 1) * sizeof(int));
	totalFollowers[totalFollowersCount++] = i;

    calculatetotalFollowersDFS(userArray, adjMatrix, i, &totalFollowers, &totalFollowersCount, visited);

    userArray[i].totalFollowers = totalFollowers;
    userArray[i].totalFollowersCount = totalFollowersCount;
	}
  }
}
void printByFollowers(USER *userArray, int allUser, int X, int Y)
{
 	int i,j;
	int *print = (int*)malloc(sizeof(int)*allUser);
	for(i=1; i<allUser+1; i++){
		print[i] = 0;
	}
	for(i=1; i<allUser+1; i++){
		if(userArray[i].followersCount >= X && userArray[i].totalFollowersCount-1 >= Y){
			print[i] = 1;
		}
	}
	for(i=1; i<allUser+1; i++){
		if(print[i] == 1){
			printf("%d, %s, %s, D. F.ings:%d, D. F.er(inDegree):%d  ==> ", userArray[i].id, userArray[i].name, userArray[i].surname, userArray[i].followingsCount, userArray[i].followersCount);
			/*
			printf("Followings: ");
				for(j=0; j<userArray[i].followingsCount; j++){
	    			 printf("%d ", userArray[i].followings[j]);
				}	
			}
			if(userArray[i].followersCount != 0){
				printf("Followers: ");
				for(j=0; j<userArray[i].followersCount; j++){
	   	 			printf("%d ", userArray[i].followers[j]);
				}

			*/
			
			if(userArray[i].totalFollowersCount != 0){
				printf("TotalDegree: %d", userArray[i].totalFollowersCount-1);
				//eger dogrudan veya dolayli tum baglantilarini gormek istersen yorum satirlarini kaldir
				/*
				printf(" TotalFollowers: ");
				for(j=0; j<userArray[i].totalFollowersCount; j++){
	    			 printf("%d ", userArray[i].totalFollowers[j]);
				}
				*/
			}
			printf("\n");
		}
	}
	free(print);
}
	

int main()
{
    USER *user = malloc(sizeof(USER));
    user = NULL;
    FILE *fp;
    int allUser;
    int i ,j,m ,x, y;
    int** adjMatrix;
    int** adjMatrixFirst;
    USER *userArray;
    USER *userArrayFirst;
    STACK *stack = malloc(sizeof(STACK));
    stack->top = -1;
    int choice;
    int choice2;

    fp = fopen("socialNET.txt", "r");
    allUser = countUserId(fp);
    //define a user Array that consists of elements of the user struct type 
    userArray = (USER*)malloc(sizeof(USER)*allUser);
    userArrayFirst = (USER*)malloc(sizeof(USER)*allUser);
    addUser2Array(fp,userArray,allUser,user);
    
    //build adjacency matrix
    adjMatrix = (int**)calloc(allUser+1, sizeof(int*));
    for(i=0;i<allUser+1;i++){
	adjMatrix[i] = (int*)calloc(allUser+1, sizeof(int));
    }
    beingAdjMatrix(fp, adjMatrix, allUser);
    adjMatrixFirst = (int**)calloc(allUser+1, sizeof(int*));
    for(i=0;i<allUser+1;i++){
	adjMatrixFirst[i] = (int*)calloc(allUser+1, sizeof(int));
    }
    for(i=0;i<allUser+1;i++){
	for(j=0;j<allUser+1;j++){
		adjMatrixFirst[i][j] = adjMatrix[i][j];
	}
    }
    createFollowingsFollowers(userArray, adjMatrix, allUser);
    for(i=1;i<allUser+1;i++){
	userArrayFirst[i] = userArray[i];
    }

/*
eliminateMatrix(adjMatrix, userArray, allUser, 1);
	updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
	printAdjMatrix(adjMatrix, allUser);
	calculateAlltotalFollowers(userArray, adjMatrix, allUser);
	printByFollowers(userArray, allUser, 2, 2);
*/
	


    	
    //calculateAlltotalFollowers(userArray, adjMatrix, allUser);
    //printUserArray(userArray,allUser);	
    //printByFollowers(userArray, allUser, 2, 2);
    //updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
    //printf("=====================================\n");
    //printUserArray(userArray,allUser);
    //printUserArray(userArrayFirst,allUser);

   //eliminateMatrix(adjMatrix, userArray, allUser, 2);
    //updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
    //printf("=====================================\n");
    //printUserArray(userArray,allUser);
    //printAdjMatrix(adjMatrix,allUser);
    //printf("=====================================\n");
    //updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);   
    //printUserArray(userArray,allUser);




printf("1. Normal Mode\n2. Detay Mode\n0. Cikis\n");
    scanf("%d", &choice2);
    switch(choice2){
	case 1:
		printf("M degerini giriniz: ");
		scanf("%d", &m);
		printf("X,Y degerlerini giriniz: \n");
		do{
			printf("X degeri: \n");
	   		scanf("%d", &x);
		}while(m>=x);
		printf("Y degeri: \n");
		scanf("%d", &y);
		eliminateMatrix(adjMatrix, userArray, allUser, m);
		updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
		calculateAlltotalFollowers(userArray, adjMatrix, allUser);
	    printByFollowers(userArray, allUser, x, y);
	    printf("Komsuluk Matrisini Yazdirmak Ister misiniz?:\n");
	    printf("1. Evet\n2. Hayir\n");
	    scanf("%d", &choice2);
	    switch (choice2) 
	    {
	    case 1:
		printAdjMatrix(adjMatrix,allUser);
	    	break;
	    case 2:
		break;
	    }
		break;
	case 2: 
	printf("1. Tum Dugumleri Ekrana Yazdir\n2. Komsuluk Matrisini Ekrana Yazdir\n3. M Degeri Sonrasi Kalanlari Ekrana Yazdr\n4. X,Y (istenirse M) Sonrasi Influencer Yazdir\n0. Cikis\n");
	scanf("%d", &choice);
	switch (choice) 
	{
	case 1:
	    calculateAlltotalFollowers(userArrayFirst, adjMatrix, allUser);
	    printUserArray(userArrayFirst,allUser);
	    break;
	case 2:	
	    printAdjMatrix(adjMatrixFirst,allUser);
	    break;
	case 3:
	    printf("M degerini giriniz: ");
	    scanf("%d", &m);
	    eliminateMatrix(adjMatrix, userArray, allUser, m);
	    updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
	    calculateAlltotalFollowers(userArray, adjMatrix, allUser);
	    printUserArray(userArray,allUser);
	    //printInfluencer(userArray, allUser);
	    printf("Komsuluk Matrisini Yazdirmak Ister misiniz?:\n");
	    printf("1. Evet\n2. Hayir\n");
	    scanf("%d", &choice2);
	    switch (choice2) 
	    {
	    case 1:
		printAdjMatrix(adjMatrix,allUser);
	    	break;
	    case 2:
		break;
	    }
	    break;
	case 4:
		printf("X,Y degerlerini giriniz: \n");
		
		printf("X degeri: \n");
	   	scanf("%d", &x);
		
		printf("Y degeri: \n");
		scanf("%d", &y);
		printf("M Degerini girmek Ister misiniz?:\n");
	    printf("1. Evet\n2. Hayir\n");
	    scanf("%d", &choice2);
	    switch (choice2) 
	    {
	    case 1:
	    printf("M degerini giriniz: ");
	    scanf("%d", &m);	
		eliminateMatrix(adjMatrix, userArray, allUser, m);

	    	break;
	    case 2:
		break;
	    }
		updateFollowingsFollowersByMatrix(userArray, adjMatrix, allUser);
		calculateAlltotalFollowers(userArray, adjMatrix, allUser);
	    printByFollowers(userArray, allUser, x, y);
		break;
		
	case 0:
	    printf("Exiting...\n");
	    return 0;	
	    break;
	}
	
}    
	fclose(fp); 
	
	return 0;
}
