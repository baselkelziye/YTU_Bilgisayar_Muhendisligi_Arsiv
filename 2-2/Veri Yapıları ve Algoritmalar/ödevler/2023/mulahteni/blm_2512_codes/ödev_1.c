#include <stdio.h>
#include <time.h>
#include <stdlib.h>



typedef struct Lock{
	int value;
	struct Lock* next;
	struct Lock* prev;
	
}Lock;

int prevControl(Lock *, int);
void lockSetter(Lock *, int, int);
void printer(Lock *, int);
int numFinder(Lock *, int, int);
void numPrinter(int, int, int, int);
void leftRightPrinter(int, int, int, int);
void rotateCircle(Lock **);
void lockCreator2(Lock **, Lock *, Lock *, int, int);
int lockNum(Lock *, Lock *, Lock *, int);

int main(){
	int N = -1, M = -1, i;
	srand(time(NULL));
	do{
		system("cls");
		printf("\n M : ");
		scanf("%d", &M);
	}while(M < 2);
	
	do{
		system("cls");
		printf("\n M value set %d ", M);
		printf("\n N : ");
		scanf("%d", &N);
	}while(N < 2*M);
	
	system("cls");
	printf("\n M value set %d\n\n N value set %d \n", M, N);
	
	int num = rand() % N +1;
	
	Lock* lock1 = (Lock*)malloc(sizeof(Lock));
	lock1->prev = NULL;
	Lock* lock2 = (Lock*)malloc(sizeof(Lock));
	lock2->prev = NULL;
	Lock* lock3 = (Lock*)malloc(sizeof(Lock));
	lock3->prev = NULL;
	Lock* head1 = lock1;
	Lock* head2 = lock2;
	Lock* head3 = lock3;
	for(i=0; i<M; i++){		// randomizing lock3
		lockCreator2(&lock1, lock2, lock3, N, num);
		lockCreator2(&lock2, lock1, lock3, N, num);
		lockCreator2(&lock3, lock1, lock2, N, num);
	}
	
	head1 = head1->next;
	head2 = head2->next;
	head3 = head3->next;
	
	head1->prev = lock1;
	lock1->next = head1;
	head2->prev = lock2;
	lock2->next = head2;
	head3->prev = lock3;
	lock3->next = head3;
	
	int position1 = rand()%M +1, position2, position3;
	do{
		position2 = rand()%M +1;
	}while(position1==position2);
	do{
		position3 = rand()%M +1;
	}while(position3==position2 || position3==position1);

	lockSetter(lock1, num, position1);
	lockSetter(lock2, num, position2);
	lockSetter(lock3, num, position3);

	int num2 = lockNum(lock1, lock2, lock3, M);

	int where1 = numFinder(lock1, num2, M);
	int where2 = numFinder(lock2, num2, M);
	int where3 = numFinder(lock3, num2, M);

	int loop = 1, choice=0, lockRotate=0, nextt;
	while(loop){
		system("cls");
		printf("\n 1-) Print locks\n 2-) Print password locations\n 3-) Print number of turns to be rotated\n 4-) Rotate circle\n 5-) Exit\n Choice : ");
		do{
			scanf("%d", &choice);
		}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5);

		if(choice==1){
			system("cls");
			printf("\n First lock...");
			printer(lock1, M);
			printf("\n Second lock...");
			printer(lock2, M);
			printf("\n Third lock...");
			printer(lock3, M);
			printf("\n Enter any number : ");
			scanf("%d",&nextt);
		}else if(choice==2){
			system("cls");
			numPrinter(where1, where2, where3, num);
			printf("\n Enter any number : ");
			scanf("%d",&nextt);
		}else if(choice==3){
			system("cls");
			leftRightPrinter(where1, where2, where3, M);
			printf("\n Enter any number : ");
			scanf("%d",&nextt);
		}else if(choice==4){
			system("cls");
			printf("\n To rotate circle 1 press \"1\"\n To rotate circle 2 press \"2\"\n To rotate circle 3 press \"3\"\n Choice :");
			do{
				scanf("%d", &lockRotate);
			}while(lockRotate!=1 && lockRotate!=2 && lockRotate!=3);
			if(lockRotate==1){
				rotateCircle(&lock1);
			}else if(lockRotate==2){
				rotateCircle(&lock2);
			}else{
				rotateCircle(&lock3);
			}
			printf("\n Locks after rotate...");
			printf("\n First lock...");
			printer(lock1, M);
			printf("\n Second lock...");
			printer(lock2, M);
			printf("\n Third lock...");
			printer(lock3, M);
			printf("\n Enter any number : ");
			scanf("%d",&nextt);
		}else if(choice==5){
			printf("asd");
			system("cls");
			loop = 0;
		}
	}
	printf("\n return value 0\n");
	return 0;
}

int prevControl(Lock *tmp, int rNum){
	Lock* tmp2 = tmp;
	while(tmp2->prev !=NULL){
		if(tmp2->value == rNum){
			return 0;
		}
		tmp2 = tmp2->prev;
	}
	if(tmp2->value == rNum){
		return 0;
	}
	return 1;
}

void lockCreator2(Lock **lock, Lock *control1, Lock *control2, int N, int num){
	Lock* newL = (Lock*)malloc(sizeof(Lock));
	Lock* tmp = (*lock);
	Lock* tmp1 = control1;
	Lock* tmp2 = control2;

	int randNum, flag = 0, ret1, ret2, ret3;
	while(flag<2){
		flag = 0;
		randNum = rand()%N + 1;
		if(randNum != num){
			ret1 = prevControl(tmp, randNum);
			if(ret1){
				ret2 = prevControl(tmp1, randNum);
				ret3 = prevControl(tmp2, randNum);
				flag = ret1 + ret2 + ret3;
			}
		}
	}
	newL->value = randNum;
	(*lock)->next = newL;
	newL->prev = (*lock);
	(*lock) = newL;
	(*lock)->next = NULL;
}

void lockSetter(Lock* lSet, int num, int position){
	int i;
	Lock* tmp = lSet;
	for(i = 0; i<position; i++){
		tmp = tmp->next;
	}
	tmp->value = num;
}

void printer(Lock *prt, int M){
	int i;
	printf("\n");
	for(i = 0; i<M; i++){
		printf(" %d\t", prt->value);
		prt = prt->next;
	}
	printf("\n");
}

int numFinder(Lock *find, int num, int M){
	int place = 0;
	Lock *tmp = find;
	while(tmp->value != num){
		tmp = tmp->next;
		place++;
	}
	return place;
}

void numPrinter(int w1, int w2, int w3, int num){
	printf("\n Lock number : %d", num);
	printf("\n All locks password places...\n First lock  : %d\n Second lock : %d\n Third lock  : %d", w1+1, w2+1, w3+1);
}

void leftRightPrinter(int w1, int w2, int w3, int M){
	printf("\n\n For the second circle...");
	if(w1>w2){
		if(w1-w2<abs(M-(w1-w2))){
			printf("\n %d times right ", w1-w2);
		}else if(w1-w2==abs(M-(w1-w2))){
			printf("\n %d times left or right ", w1-w2);
		}else{
			printf("\n %d times left ", abs(M-(w1-w2)));
		}
	}else{
		if(w2-w1<abs(M-(w2-w1))){
			printf("\n %d times left ", w2-w1);
		}else if(w1-w3==abs(M-(w1-w3))){
			printf("\n %d times left or right ", w1-w3);
		}else{
			printf("\n %d times right ", abs(M-(w2-w1)));
		}
	}

	printf("\n\n For the third circle...");
	if(w1>w3){
		if(w1-w3<abs(M-(w1-w3))){
			printf("\n %d times right ", w1-w3);
		}else{
			printf("\n %d times left ", abs(M-(w1-w3)));
		}
	}else{
		if(w3-w1<abs(M-(w3-w1))){
			printf("\n %d times left ", w3-w1);
		}else{
			printf("\n %d times right ", abs(M-(w3-w1)));
		}
	}
}

void rotateCircle(Lock **lock){
	char t;
	printf("\n To rotate right enter \"r\" \n To rotate left enter \"l\"\n Choice :");
	while(t!='l' && t!='r'){
		printf(" ");
		scanf("%c", &t);
	}
	if(t=='r'){
		(*lock) = (*lock)->prev;
	}else if(t=='l'){
		(*lock) = (*lock)->next;
	}
}

int lockNum(Lock *l1, Lock *l2, Lock *l3, int M){
	Lock *tmp1 = l1;
	Lock *tmp2;
	Lock *tmp3;
	int num, i, j, count=0;
	for(i = 0; i<M && count<2; i++){
		count=0;
		num = tmp1->value;
		tmp2 = l2;
		for(j = 0; j<M && count<1; j++){
			if(tmp2->value == num){
				count++;
			}
			tmp2 = tmp2->next;
		}

		tmp3 = l3;
		for(j = 0; j<M && count<2; j++){
			if(tmp3->value == num){
				count++;
			}
			tmp3 = tmp3->next;
		}
		tmp1 = tmp1->next;
	}
	return num;
}
