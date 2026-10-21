#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct tree{
	int data;
	int damaged;
	struct tree* leftc;
	struct tree* rightc;
}Tree;

typedef struct kova{
	int data;
	struct kova *next;
}Kova;

int checklist(int arr[], int M);
void push(Kova **head, int data);
int pop(Kova **head);
void printStack(Kova *head);
Tree* createNode(int number);
Tree* createBST(Tree *root, int M, int N, int** numbers);
Tree* insert(Tree *root, int number);
Tree* decreaseValue(Tree *root, Kova **head, int value, int power, int *control);
Tree* deleteNode(Tree* root, int data);
Tree* getMinValueNode(Tree *root);
void inorderTraversal(Tree *root);
void printTree(Tree* root, int space, int count);

int main(){
	srand(time(NULL));
	int M,N;
	printf("Enter M and N:");
	scanf("%d%d",&M,&N);
	Tree *root = NULL;
	int *numbers = (int*) malloc(sizeof(int) * M);
	root = createBST(root,M,N,&numbers);
	printTree(root,0,M);
	
	int i = 0;
	Kova *head = NULL;
	int *values = (int*) malloc(sizeof(int) * M);
	int *powers = (int*) malloc(sizeof(int) * M);
	int control = M; //while döngüsü eleman sayýsý kadar dönecek
	while(control > 0){
		printf("Enter K and P: ");
		scanf("%d%d",&values[i],&powers[i]);
		root = decreaseValue(root,&head,values[i],powers[i],&control);
		printTree(root,0,M);
		printf("Kova: ");
		printStack(head);	
	}
	
	Kova *ekKova = NULL;
	for(i = 0; i < M; i++)
		push(&ekKova,pop(&head));
	printf("Output: ");
	printStack(ekKova);
	return 0;
}

void push(Kova **head, int data){
	Kova *newNode = (Kova*) malloc(sizeof(Kova));
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL) //stack boþsa
		*head = newNode;
	else{
		newNode->next = *head;
		*head = newNode;
	}
}

int pop(Kova **head){
	Kova *tmp = *head;
	int data;
	if(*head == NULL) //stack boþsa
		return;
	data = (*head)->data;
	*head = (*head)->next;
	free(tmp);
	return data;
}

void printStack(Kova *head){
	Kova *tmp = head;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

Tree* decreaseValue(Tree *root, Kova **head, int value, int power, int *control){
	Tree *tmp = root;
	if(tmp == NULL)
		return NULL;
	else if(value == tmp->data){
		tmp->damaged -= power;
		if(tmp->damaged <= 0){
			push(head, tmp->data);
			tmp = deleteNode(tmp,tmp->data);
			(*control)--;
		}
	}
	else if(value > tmp->data)
		tmp->rightc = decreaseValue(tmp->rightc,head,value,power,control);
	else
		tmp->leftc = decreaseValue(tmp->leftc,head,value,power,control);
	return tmp;
}

Tree* deleteNode(Tree* root, int data){
	Tree *tmp;
	if(root == NULL) //eleman yoksa
		return root;
	if(data < root->data)
		root->leftc = deleteNode(root->leftc,data);
	else if(data > root->data)
		root->rightc = deleteNode(root->rightc,data);
	else{
		if (root->leftc == NULL && root->rightc == NULL) {  //leaf node ise
    		free(root);
   			return NULL;
		}
	 	//tek çocuklu parent child durumu
		else if(root->leftc == NULL){
			tmp = root->rightc;
			free(root);
			return tmp;
		}
		else if(root->rightc == NULL){
			tmp = root->leftc;
			free(root);
			return tmp;
		}
		//çift çocuklu parent child durumu
		else{
			tmp = getMinValueNode(root->rightc); //mevcut root un sað tarafýndaki aðacýn en küçük deðeri root un yeni deðeri olmalý
			root->data = tmp->data;
			root->damaged = tmp->damaged;
			root->rightc = deleteNode(root->rightc,tmp->data);
			return root;
		}
	}
}

Tree* getMinValueNode(Tree *root){
	Tree *tmp = root;
	while(tmp->leftc != NULL)
		tmp = tmp->leftc;
	return tmp;
}

Tree* createBST(Tree *root, int M, int N, int** numbers){
	int i,j,number,check = 0;
	int *numberList = *numbers;
	
	while(check == 0){ //sürekli farklý sayýlardan oluþan bir array üretmek için
		for(i = 0; i < M; i++)
			numberList[i] = rand()%N+1;
		check = checklist(numberList,M);
	}
	
	for(i = 0; i < M; i++){ //elemanlarý aðaca yerleþtirmek için
		root = insert(root,numberList[i]);
		inorderTraversal(root); //her turda aðacýn durumu ekrana bastýrýlacak
		printf("\n");
	}
	return root;
}

int checklist(int arr[], int M){ //isSame = 0 olursa arrayde ayný elemanlar vardýr
	int isSame = 1,i=0,j;
	while(i < M && isSame != 0){
		j = i+1;
		while(j < M && isSame != 0){
			if(arr[i] == arr[j]){
				isSame = 0;
			}
			j++;
			}
			i++;
		}
	return isSame;
}

Tree* createNode(int number){
	Tree* node = (Tree*) malloc(sizeof(Tree));
	node->data = number;
	node->damaged = number;
	node->leftc = NULL;
	node->rightc = NULL;
	return node;
}

Tree* insert(Tree *root, int number){
	if(root == NULL){
		root = createNode(number);
		return root;
	}
	else if(number < root->data)
		root->leftc = insert(root->leftc,number);
	else
		root->rightc = insert(root->rightc,number);
	return root;
}

void inorderTraversal(Tree* root){ //a+b
	if(root == NULL)
		return;
	inorderTraversal(root->leftc);
	printf("%d ",root->data);
	inorderTraversal(root->rightc);
}

void printTree(Tree* root, int space, int count){
    int i;
    if (root == NULL)
        return;
    space += count;
    printTree(root->rightc, space, count);
    printf("\n");
    for (i = count; i < space; i++)
        printf(" ");
    if (root->damaged != root->data)
        printf("%d(%d)\n", root->data, root->damaged);
    else
        printf("%d\n", root->data);
    printTree(root->leftc, space, count);
}

