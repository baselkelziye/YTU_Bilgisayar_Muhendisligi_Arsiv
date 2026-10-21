#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node{
	int deger;
	struct Node *next;
	struct Node *prev;
}node;
void printNodes(node* head_ref1,node* head_ref2,node* head_ref3,int M);
int* findCommonNumber(node* head_ref1,node* head_ref2,node* head_ref3,int commonNumber);
int calculateRotation(int curLocation,int topLocation,int M,int row,node** head_ref);
void rotateMatrix(node** head_ref,int rotateNum,int rotateDir,int M);
int uniqueControl(node** head_ref,int num,int control,int loc);
void setComNumber(node** head_ref,int comNum,int comNumLoc);
void addNode(node** head_ref,int M,int j,int N,int comNum,node** other1,node** other2,int control1,int control2);
int main() {
	srand(time(NULL));
	int N,M,j,error=1,tmp;
	node *nodeMain1 = NULL;
	node *nodeMain2 = NULL;
	node *nodeMain3 = NULL;
	int comNum;
	int mainMatrix[3] = {0,0,0};
	int *commonLoc = (int*)calloc(3,sizeof(int));
	int comNumLoc1,comNumLoc2,comNumLoc3,tmpComNumLoc;
	while(error == 1){
		printf("\n\n");
		printf("\tN: ");
		scanf("%d",&N);
		printf("\tM: ");
		scanf("%d",&M);
		tmp = 1 + ((M-1)*3 / 2) + ((M-1)*3)%2;
		if(N<tmp){
			printf("\n\t!!! M degeri %d iken N degeri %d veya %d den buyuk olmalidir !!!",M,tmp,tmp);
			sleep(1);
			system("cls");
		}
		else if(M<2){
			printf("\n\t!!! M degeri 2 den kucuk olamaz!!!");
			sleep(1);
			system("cls");
		}
		else{
			error = 0;
		}
	}

	comNum = (rand() % N) +1; // GENERATING COMMON NUMBER
	printf("\tOrtak Sayi : %d\n\n",comNum);



	for(j=0;j<M;j++){		// CREATING THE LOCK SYSTEM
		addNode(&nodeMain1,M,j,N,comNum,&nodeMain2,&nodeMain3,0,0);
	}
	for(j=0;j<M;j++){
		addNode(&nodeMain2,M,j,N,comNum,&nodeMain1,&nodeMain3,1,0);
	}
	for(j=0;j<M;j++){
		addNode(&nodeMain3,M,j,N,comNum,&nodeMain1,&nodeMain2,1,1);
	}
	// ADDING THE COMMON NUMBER ON THE LOCK SYSTEM
	comNumLoc1 = rand()%M;
	setComNumber(&nodeMain1,comNum,comNumLoc1);
	comNumLoc2 = rand()%M;
	setComNumber(&nodeMain2,comNum,comNumLoc2);
	comNumLoc3 = rand()%M;
	
	setComNumber(&nodeMain3,comNum,comNumLoc3);
	printf("\tKilit Sistemi : \n\n");
	printNodes(nodeMain1,nodeMain2,nodeMain3,M);printf("\n\n");
	
	// ROTATING THE LOCK SYSTEM
	calculateRotation(comNumLoc2,comNumLoc1,M,2,&nodeMain2);
	calculateRotation(comNumLoc3,comNumLoc1,M,3,&nodeMain3);
	printf("\n\tKilidin Cozulmus Hali : \n\n");
	printf("\n");
	printNodes(nodeMain1,nodeMain2,nodeMain3,M);
	return 0;
}

void setComNumber(node** head_ref,int comNum,int comNumLoc){
	int i;
	node* tmp = *head_ref;
	for(i=0;i<comNumLoc;i++){
		tmp = tmp->next;
	}
	tmp->deger = comNum;
}
int uniqueControl(node** head_ref,int num,int control,int loc){
	node* tmp = *head_ref;
	int i=0;
	if(control == 0){
		while(tmp!= NULL){
			if(tmp->deger == num){
				return 1;
			}
			else{
				tmp = tmp->next;
			}
		}
		return 0;
	}
	else{
		for(i=0;i<loc;i++){
			if(tmp->deger == num){
				return 1;
			}
			else{
				tmp = tmp->next;
			}
		}
		return 0;
	}
	
}
int calculateRotation(int curLocation,int topLocation,int M,int row,node** head_ref){
	int inWay = abs(topLocation-curLocation);
	int outWay = M - inWay;
	if(inWay<outWay){
		if(topLocation>curLocation){
			printf("\n\t%d. Satirda Ortak Sayinin %d Adim Saat Yonunde Donmesi Gerekiyor !!\n",row,inWay);
			if(inWay == outWay){
				printf("\t(Saatin Ters Yonunde De %d Adim Cevrilebilir)\n",outWay);
			}
			rotateMatrix(head_ref,inWay,1,M);
		}
		else{
			printf("\n\t%d. Satirda Ortak Sayinin %d Adim Saat Yonunun Tersine Donmesi Gerekiyor !!\n",row,inWay);
			if(inWay == outWay){
				printf("\t(Saat Yonunde De %d Adim Cevrilebilir)\n",outWay);
			}
			rotateMatrix(head_ref,inWay,0,M);
		}
	}
	else{
		if(topLocation>curLocation){
			printf("\n\t%d. Satirda Ortak Sayinin %d Adim Saat Yonunun Tersine Donmesi Gerekiyor !!\n",row,outWay);
			if(inWay == outWay){
				printf("\t(Saat Yonunde De %d Adim Cevrilebilir)\n",inWay);
			}
			rotateMatrix(head_ref,inWay,1,M);
		}
		else{
			printf("\n\t%d. Satirda Ortak Sayinin %d Adim Saat Yonunde Donmesi Gerekiyor !!\n",row,outWay);
			if(inWay == outWay){
				printf("\t(Saat Yonunde De %d Adim Cevrilebilir)\n",inWay);
			}
			rotateMatrix(head_ref,inWay,0,M);
		}
	}
	
}
void rotateMatrix(node** head_ref,int rotateNum,int rotateDir,int M){
	int i,j;
	int tmp,tmp2;
	node* lastNode = *head_ref;
	node* tmpNode = (node*)malloc(sizeof(node));
	if(rotateDir == 0){ //SAAT YÖNÜNÜN TERSÝ
		for(i=0;i<rotateNum;i++){
			node* lastNode = *head_ref;
			for(j=0;j<M-1;j++){
				tmp = lastNode->deger;
				lastNode->deger = lastNode->next->deger;
				lastNode->next->deger = tmp;
				lastNode = lastNode->next;
			}
		}
	}
	else{ //SAAT YÖNÜ
		for(i=0;i<rotateNum;i++){
			node* lastNode = *head_ref;
			lastNode = lastNode->prev;
			for(j=0;j<M-1;j++){
				tmp = lastNode->deger;
				lastNode->deger = lastNode->prev->deger;
				lastNode->prev->deger = tmp;
				lastNode = lastNode->prev;
			}
		}
	}
}
void addNode(node** head_ref,int M,int j,int N,int comNum,node** other1,node** other2,int control1,int control2){
	node* lastNode = *head_ref;
	node* newNode = (node*)malloc(sizeof(node));
	int unique1,unique2,unique3;
	int run=0;
	int tmp;
    while(run == 0){
        tmp=(rand() % N) +1;
        unique1 = uniqueControl(head_ref,tmp,0,j);
        unique2 = uniqueControl(other1,tmp,control1,j);
        unique3 = uniqueControl(other2,tmp,control2,j);
        if( (tmp != comNum) && (unique1== 0) && ((unique1+unique2+unique3)<3)){
            newNode->deger = tmp;
            run = 1;
        } 
    }
	if((*head_ref) == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		*head_ref = newNode;
		return;
	}
	while(lastNode->next != NULL){
		lastNode = lastNode->next;
	}
	newNode->prev = lastNode;
	lastNode->next = newNode;
	lastNode = lastNode->next;
	if(j == (M-1)){
		lastNode->next = *head_ref;
		(*head_ref)->prev = lastNode;
		return;
	}
	else{
		lastNode->next = NULL;
		return;
	}
}
void printNodes(node* head_ref1,node* head_ref2,node* head_ref3,int M){
	int i;
	node* lastNode = head_ref1;
	printf("\t");
	for(i=0;i<M;i++){
		printf("%2d\t",lastNode->deger);
		lastNode = lastNode->next;
	}
	printf("\n\n\t");
	lastNode = head_ref2;
	for(i=0;i<M;i++){
		printf("%2d\t",lastNode->deger);
		lastNode = lastNode->next;
	}
	printf("\n\n\t");
	lastNode = head_ref3;
	for(i=0;i<M;i++){
		printf("%2d\t",lastNode->deger);
		lastNode = lastNode->next;
	}
}
int* findCommonNumber(node* head_ref1,node* head_ref2,node* head_ref3,int commonNumber){
	int *commonLoc = (int*)calloc(3,sizeof(int));
	int i;
	int j = 0;
	node* lastNode = head_ref1;
	i = 0;
	printf("\n\n\tOrtak Sayinin Konumlari :\n\n\t");
	while(lastNode->deger != commonNumber){
		lastNode = lastNode->next;
		i++;
	}
	printf("Ortak Sayi %d. Carkta %d. Sirada\n\t",j+1,i+1);
	commonLoc[j] = i;
	j++;
	i=0;
	lastNode = head_ref2;
	while(lastNode->deger != commonNumber){
		lastNode = lastNode->next;
		i++;
	}
	printf("Ortak Sayi %d. Carkta %d. Sirada\n\t",j+1,i+1);
	commonLoc[j] = i;
	j++;
	i=0;
	lastNode = head_ref3;
	while(lastNode->deger != commonNumber){
		lastNode = lastNode->next;
		i++;
	}
	printf("Ortak Sayi %d. Carkta %d. Sirada\n",j+1,i+1);
	commonLoc[j] = i;
	return commonLoc;
}
int compare(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}


