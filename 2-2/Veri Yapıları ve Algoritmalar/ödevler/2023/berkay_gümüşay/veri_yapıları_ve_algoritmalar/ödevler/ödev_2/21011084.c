#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Stack{
	struct Stack *next;
	int value;
}stack;
typedef struct BSTreeNode{
	int mainValue;
	int tmpValue;
	struct BSTreeNode *rightLeaf;
	struct BSTreeNode *leftLeaf;
}node;
void makeBST(int N,int M,node** head_ref);
int insertNode(node** head_ref, int value, int N);
node* createNode(int value);
int uniqueControl(node* head_ref,int value);
void printTree(node* root);
void printNode(node* root, int space);
void print(node* root);
int hitTheNode(node** head_ref, int fruitValue, int power, stack** top);
node* findNode(node* head_ref, int fruitValue);
node* getParent(node* head_ref,node* tmpNode);
int deleteNode(node** head_ref,node* tmpNode);
int isLeaf(node* tmpNode);
int isOneChild(node* tmpNode);
void deleteOneChild(node** head_ref,node* tmpNode);
int isTwoChild(node* tmpNode);
node* deleteTwoChild(node* head_ref,int key);
node* findMinValue(node* tmpNode);
void printStack(stack* top);
void pushStack(int p, stack** top);
stack* createStackNode(int value);
void deleteLastNode(node** head_ref);
int isLastNode(node** head_ref,node* tmpNode);
int popStack(stack** top);
void transferStacks(stack** stack1, stack** stack2);


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int N,M,k,p,control,run=1;
	stack* top = NULL;
	stack* finalBucket = NULL;
	node *head_ref = NULL;
	while(run == 1){
		printf("N degerini giriniz: ");
		scanf("%d",&N);
		printf("M degerini giriniz: ");
		scanf("%d",&M);
		if(N < M){
			system("cls");
			printf("!!! HATALI DEGERLER GIRDINIZ !!!\n\n");
		}
		else{
			run = 0;
		}
	}
	printf("\n\n");
	makeBST(N,M,&head_ref);
	while(head_ref != NULL){
		printTree(head_ref);
		printf("\n\nVurmak Istediginiz Meyvenin Degerini Giriniz (k) : ");
		scanf("%d",&k);
		printf("Atis Gucunu Giriniz (p) : ");
		scanf("%d",&p);
		sleep(1);
		system("cls");printf("\n");
		control = hitTheNode(&head_ref,k,p,&top);
		printTree(head_ref);
		if(control != -1){
			pushStack(control,&top);
		}
		printf("\nKova : ");printStack(top);printf("\n\n");
		printf("Devam Etmek Icin Enter'a Basiniz...");
		getch();
		system("cls");
	}
	transferStacks(&top,&finalBucket);
	printf("Cikti: ");
	printStack(finalBucket);
	return 0;
}

void makeBST(int N,int M,node** head_ref){
	int i, tmp;
	int run = 0;
	for(i=0;i<M;i++){
		do{
			tmp = rand()%N +1;
		}while(uniqueControl((*head_ref),tmp) != 1);
		insertNode(head_ref, tmp, N);
	}	
}
int insertNode(node** head_ref, int value, int N){
	node* tmpNode = *head_ref;
	if(tmpNode == NULL){
		(*head_ref) = createNode(value);
		return 1;
	}
	if(tmpNode->mainValue == value){
		do{
			value = rand()%N +1;
		}while(uniqueControl((*head_ref),value) != 1);	
	}
	if( value < tmpNode->mainValue ){
		return insertNode(&(tmpNode->leftLeaf),value,N);
	}
	else{
		return insertNode(&(tmpNode->rightLeaf),value,N);
	}
}
node* createNode(int value){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->mainValue = value;
	newNode->tmpValue = value;
	newNode->leftLeaf = NULL;
	newNode->rightLeaf = NULL;
	return newNode;
}
int uniqueControl(node* head_ref,int value){
	node* tmpNode = head_ref;
	tmpNode = findNode(tmpNode,value);
	if(tmpNode != NULL){
		return 0;
	}
	else{
		return 1;
	}
}
void printNode(node* head_ref, int space){
	int i;
    if (head_ref == NULL)
        return;
    space += 10;
    printNode(head_ref->rightLeaf, space);
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d", head_ref->mainValue);
    if((head_ref->tmpValue != head_ref->mainValue) && (head_ref->tmpValue > 0)){
    	printf("(%d)",head_ref->tmpValue);
	}
	printf("\n");
    printNode(head_ref->leftLeaf, space);
}
void printTree(node* head_ref){
    printNode(head_ref, 0);
}
int hitTheNode(node** head_ref, int fruitValue, int power, stack** top){
	node* tmpNode = *head_ref;
	int p;
	node* pNode;
	tmpNode = findNode(tmpNode,fruitValue);
	if(tmpNode == NULL){
		printf("!!! Girdiginiz Degerde Bir Meyve Yok !!!");
		return -1;
	}
	(tmpNode->tmpValue) = (tmpNode->tmpValue) - power;
	if(tmpNode->tmpValue <= 0){
		p = tmpNode->mainValue;
		printf("\n!!! %d Degeri Agactan Dustu !!!\n",p);
		if(isLeaf(tmpNode) == 1){ // Deleting Leaf Node
			if(isLastNode(head_ref,tmpNode) == 1){
				deleteLastNode(head_ref);
			}
			else{
				deleteNode(head_ref,tmpNode);
			}
			return p;
		}
		else if(isOneChild(tmpNode) == 1){ // Deleting One Child Node
		
			deleteOneChild(head_ref,tmpNode);
	//		pushStack(p,top);
			return p;
		}
	
		else if(isTwoChild(tmpNode) == 1){ // Deleting Two Child Node
			pNode = deleteTwoChild(*head_ref,tmpNode->mainValue);
		//	p = pNode->mainValue;
		//	pushStack(p,top);
			return p;
		}
	}
	return -1;
	
}
node* findNode(node* head_ref, int mainValue){
	node* tmpNode = head_ref;

	if(tmpNode == NULL || tmpNode->mainValue == mainValue){
		return tmpNode;
	}
	else if(mainValue < tmpNode->mainValue){
		findNode(tmpNode->leftLeaf,mainValue);
	}
	else{
		findNode(tmpNode->rightLeaf,mainValue);
	}
}
int isLeaf(node* tmpNode){
	if(tmpNode->leftLeaf == NULL && tmpNode->rightLeaf == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int deleteNode(node** head_ref,node* tmpNode){
	node* parent = getParent(*head_ref,tmpNode);
	int p = tmpNode->mainValue;
	
//	if(parent != NULL){
	if(parent->leftLeaf->mainValue == tmpNode->mainValue){
		parent->leftLeaf = NULL;
		free(parent->leftLeaf);
		return p;
	}
	if(parent->rightLeaf->mainValue == tmpNode->mainValue){
		parent->rightLeaf = NULL;
		free(parent->rightLeaf);
		return p;
	}
//	}
	
/*	else{
		*head_ref = NULL;
	}*/
}
node* getParent(node* head_ref,node* tmpNode){
	
	if(head_ref == NULL || tmpNode == NULL || tmpNode == head_ref){
		return NULL;
	}
	if((head_ref->leftLeaf == tmpNode) || (head_ref->rightLeaf == tmpNode)){
		return head_ref;
	}
	if(tmpNode->mainValue < head_ref->mainValue){
		return getParent(head_ref->leftLeaf,tmpNode);
	}
	else{
		return getParent(head_ref->rightLeaf,tmpNode);
	}
}

int isOneChild(node* tmpNode){
	if((tmpNode->leftLeaf == NULL && tmpNode->rightLeaf != NULL) || (tmpNode->rightLeaf == NULL && tmpNode->leftLeaf !=NULL)){
		return 1;
	}
	else{
		return 0;
	}
}
void deleteOneChild(node** head_ref,node* tmpNode){
	node* parent = getParent(*head_ref,tmpNode);
	if(parent != NULL){
		if(parent->leftLeaf->mainValue == tmpNode->mainValue){
			if(tmpNode->leftLeaf == NULL){
				parent->leftLeaf = tmpNode->rightLeaf;
			}
			else{
				parent->leftLeaf = tmpNode->leftLeaf;
			}
		}
		else{
			if(tmpNode->leftLeaf == NULL){
				parent->rightLeaf = tmpNode->rightLeaf;
			}
			else{
				parent->rightLeaf = tmpNode->leftLeaf;
			}
		}
	}
	else{
		node* temp = *head_ref;
		if(temp->leftLeaf == NULL){
			*head_ref = temp->rightLeaf;
		}
		else{
			*head_ref = temp->leftLeaf;
		}
	}
}
int isTwoChild(node* tmpNode){
	if(tmpNode->leftLeaf != NULL && tmpNode->rightLeaf != NULL){
		return 1;
	}
	else{
		return 0;
	}
}
node* deleteTwoChild(node *root, int mainValue) {
    if (root == NULL) {
        return root;
    }
    if (mainValue < root->mainValue) {
        root->leftLeaf = deleteTwoChild(root->leftLeaf, mainValue);
    } else if (mainValue > root->mainValue) {
        root->rightLeaf = deleteTwoChild(root->rightLeaf, mainValue);
    } else {
        if (root->leftLeaf == NULL) {
            node *temp = root->rightLeaf;
            free(root);
            return temp;
        } else if (root->rightLeaf == NULL) {
            node *temp = root->leftLeaf;
            free(root);
            return temp;
        }
        node *temp = findMinValue(root->rightLeaf);
        root->mainValue = temp->mainValue;
        root->tmpValue = temp->tmpValue;
        root->rightLeaf = deleteTwoChild(root->rightLeaf, temp->mainValue);
    }

    return root;
}
node* findMinValue(node* tmpNode){
	node* current = tmpNode;
	while(current && current->leftLeaf != NULL){
		current = current->leftLeaf;
	}
	return current;
}
void pushStack(int p, stack** top){
	stack* tmpNode = createStackNode(p);
	tmpNode->next = (*top);
	(*top) = tmpNode;
}
int popStack(stack** top){
	if(*top == NULL){
		return -1;
	}
	int data = (*top)->value;
	stack* tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return data;
}
void printStack(stack* top){
	if(top == NULL){
		printf("Kova Bos");
		return;
	}
	stack* current = top;
	while(current != NULL){
		printf("%d  ",current->value);
		current = current->next;
	}
}
stack* createStackNode(int value){
	stack* newNode = (stack*)malloc(sizeof(stack));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}
int isLastNode(node** head_ref,node* tmpNode){
	node* parent = getParent(*head_ref,tmpNode);	
	if(parent == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void deleteLastNode(node** head_ref){
	*head_ref = NULL;
}
void transferStacks(stack** stack1, stack** stack2){
	int value;
	while(1==1){
		value = popStack(stack1);
		if(value == -1){
			return;
		}
		pushStack(value,stack2);
	}
}



