#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_LENGTH 30 //Maksimum kelime uzunlugu 30 olarak belirlendi.

struct node{
	char word[MAX_WORD_LENGTH];
	struct node* next;
};

struct queue{
	struct node* stack;
	struct queue* next;
};
//stack e ait fonksiyonlar
struct node* createNode();
void push(struct node** stack, char* word);
void pop(struct node** stack, char* word);
int stackIsEmpty(struct node* stack);
char* peek(struct node* stack);
void printList(struct node* stack);
void freeStack(struct node** stack);
//queue ya ait fonksiyonlar
struct queue* createQueueNode();
void enque(struct queue** front,struct queue** rear, struct node* stack);
struct node* deque(struct queue** front);
int isQueueEmpty(struct queue* queue);
//diger fonksiyonlar
struct node* parseWordsToLists(char* fileName, int length);
int isWordValid(struct node* list, char* word);
struct node* oneLetterDifferList(char* word, struct node* liste, int* counter);
int isUsed(struct node* list, char* word);


int main(){
	int length, i, isValid, found=0, stackElementCount = 0;
	struct node  *reducedDictionaryByLength, *list, *tempp, *currStack;
	struct node* usedWords = NULL;
	struct queue* front = NULL;
	struct queue* rear = NULL;
	
	char* fileName = "dictionary.txt";	
	char* sourceWord = malloc(MAX_WORD_LENGTH);
	char* targetWord = malloc(MAX_WORD_LENGTH);
	char* added = malloc(MAX_WORD_LENGTH);
	char* tempWord = malloc(MAX_WORD_LENGTH);
	
	//kaynek ve hedef kelime kullanicidan alinir	
	do{
		printf("Enter the source word: ");
		scanf("%s",sourceWord);
		length = strlen(sourceWord);
		reducedDictionaryByLength = parseWordsToLists(fileName, length);
		if(length < 2 ){
			printf("Please enter min 2 length words\n");
		}
		else if(!isWordValid(reducedDictionaryByLength, sourceWord)){
			printf("Please enter valid word(The word you entered is not in the dictionary\n");
		}
			
			
	}while((length < 2) || (!isWordValid(reducedDictionaryByLength, sourceWord)));
	
	do{
		printf("Enter the target word: ");
		scanf("%s", targetWord);
		if(strlen(targetWord)!=length) {
			printf("Enter same length word\n");
		}
		else if(!isWordValid(reducedDictionaryByLength, targetWord)){
			printf("Please enter valid word(The word you entered is not in the dictionary\n");
		}
			
	}while((strlen(targetWord)!=length) || (!isWordValid(reducedDictionaryByLength, targetWord)));
		
	//kaynak kelimeden sadece bir harfi farkli olan kelimeleri bulup listeye atar
	list = oneLetterDifferList(sourceWord, reducedDictionaryByLength, &stackElementCount);
	push(&usedWords, sourceWord);
	
	//bulunan kelimeleri once kaynak kelime sonra bulunan kelime olacak sekilde
	//ayri stacklere atar bu stackleri de kuyruga atar
	for(i=0;i<stackElementCount;i++){
		currStack = NULL;
		push(&currStack, sourceWord);
		push(&currStack, list->word);
		if(!isUsed(usedWords,list->word)){
			push(&usedWords, list->word);
		}
		enque(&front, &rear, currStack);
		list = list->next;
	}
	currStack = NULL;
	//bu dongude de kuruktan bir stack cekip tepesine bakar aranan kelime ise dongu biter ya da kuruk bosalirsa
	//diger durumlarda en ustteki kelimeden farkli kelimelri bulup yeni bir stack olarak kuyruga eklemeye devam eder
	
	do{
		currStack = deque(&front);
		strcpy(added, peek(currStack));
		if(!strcmp(added, targetWord)){
			found = 1;
			tempp = NULL;
			while(currStack){
				push(&tempp, currStack->word);
				currStack = currStack->next;
			}printList(tempp);
		}else{	
			list = oneLetterDifferList(added, reducedDictionaryByLength, &stackElementCount);
			for(i=0;i<stackElementCount;i++){
				strcpy(tempWord, list->word);
				if(!isUsed(usedWords, tempWord)){
					push(&usedWords, tempWord);
					tempp = currStack;
					push(&tempp, tempWord);
					enque(&front, &rear, tempp);
				}
				list = list->next;
			}
		}
		
	}while((found!=1) && (!isQueueEmpty(front)));
	
	if(!found){
		printf("\nThere is not kind of path");
	}
	
	freeStack(&usedWords);
	freeStack(&tempp);
	freeStack(&reducedDictionaryByLength);
	freeStack(&list);
	free(front);
	free(targetWord);
	free(sourceWord);
	free(added);
	free(tempWord);
	return 0;
}

/**
 * @brief Yeni bir dugum olusturur.
 * @return Olusturulan yeni dugumun adresini dondurur.
 */
struct node* createNode(){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	
	if(node==NULL){
		printf("\noccured an error while creating node...\n");
		return NULL;
	}
	node->next = NULL;
	
	return node;
}

/**
 * @brief Yeni bir kuyruk dugumu olusturur.
 * @return Olusturulan yeni kuyruk dugumunun adresini dondurur.
 */
struct queue* createQueueNode(){
	struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
	
	if(queue==NULL){
		printf("\noccured an error while creating queue...\n");
		return NULL;
	}
	queue->next = NULL;
	
	return queue;
}

/**
 * @brief Verilen stack'e yeni bir kelime ekler.
 * @param stack Kelimenin eklenecegi stack'in adresi.
 * @param word Eklenecek kelime.
 */
void push(struct node** stack, char* word) {
    struct node* newNode = createNode();
    if (newNode == NULL) {
        printf("\nOccurred a problem while adding new node...\n");
        return;
    }
    strcpy(newNode->word, word);
    newNode->next = *stack; // Yeni düðümü stack'in baþýna ekler
    *stack = newNode;
}

/**
 * @brief Verilen kuyruga yeni bir stack ekler.
 * @param front Kuyrugun onu.
 * @param rear Kuyrugun arkasi.
 * @param stack Eklenecek stack.
 */
void enque(struct queue** front,struct queue** rear, struct node* stack){
	struct queue* newNode = createQueueNode();
	
	if(newNode!=NULL){
		newNode->stack = stack;
		if(*front==NULL){
			*front = newNode;
			*rear = newNode;
		}else{
			(*rear)->next = newNode;
			*rear = newNode;
		}
	}else{
		printf("\noccured a problem while adding new element to queue...\n");
		return;
	}
}

/**
 * @brief Kuyruktan bir stack cikarir.
 * @param front Kuyrugun onu.
 * @return Cikarilan stack.
 */
struct node* deque(struct queue** front){
	struct queue* temp = *front;
	struct node* returned;
	if(*front==NULL){
		printf("\nYou are lucky all work is done, stack is empty");
	}else{
		*front = (*front)->next;
		temp->next = NULL;
		returned = temp->stack;
		free(temp);
		return returned;
	}
}

/**
 * @brief Verilen stack'ten bir kelime cikarir.
 * @param stack Kelimenin cikarilacagi stack'in adresi.
 * @param word Cikarilan kelimenin saklanacagi degisken.
 */
void pop(struct node** stack, char* word){
	struct node* temp = *stack;
	
	if(stackIsEmpty(*stack)){
		printf("\nThere isn't any element to pop\n'");
		return;
 	}
 	strcpy(word, temp->word);
 	*stack = (*stack)->next;
	free(temp);
}

/**
 * @brief Verilen stack'i yazdirir.
 * @param stack Yazdirilacak stack.
 */
void printList(struct node* stack){
	struct node* temp = stack;
	int counter = 0;
	if(stackIsEmpty(stack)){
		printf("\nYou are lucky all work is done, stack is empty");
	}else{
		while(temp){
			printf("%s-> ", temp->word);
			temp = temp->next;
			counter++;
		}printf("Top Of The Stack\n");
	}
	printf("\nTotal word number: %d", counter);
}

/**
 * @brief Verilen stack'in bos olup olmadigini kontrol eder.
 * @param stack Kontrol edilecek stack.
 * @return Stack bos ise 1, degilse 0 dondurur.
 */
int stackIsEmpty(struct node* stack){
	
	if(stack==NULL) return 1;
	else return 0;
}

/**
 * @brief Stack'in en ustundeki kelimeyi dondurur.
 * @param stack Kelimenin okunacagi stack.
 * @return Stack'in en ustundeki kelimeyi dondurur.
 */
char* peek(struct node* stack) {
    if (stackIsEmpty(stack)) {
        printf("\nStack is empty\n");
        return NULL;
    }
    return stack->word; 
}

/**
 * @brief Belirli bir uzunluktaki kelimeleri dosyadan okuyup liste haline getirir.
 * @param fileName Okunacak dosyanin adi.
 * @param length Aranan kelime uzunlugu.
 * @return Uzunluga gore filtrelenmis kelime listesi.
 */
struct node* parseWordsToLists(char* fileName, int length){
	struct node* list = (struct node*)calloc(MAX_WORD_LENGTH, sizeof(struct node));
	char buffer[MAX_WORD_LENGTH + 1];
	if (!list) {
        printf("Could not allocate memory\n");
        return NULL;
    }
	
	FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file\n");
        free(list);
        return NULL;
    }
	
	while (fscanf(file, "%s", buffer) == 1) {
        if(length == strlen(buffer))
			push(&list,buffer);
    }

    fclose(file);
	
	return list;
}

/**
 * @brief Verilen listede belirli bir kelimenin olup olmadigini kontrol eder.
 * @param list Kontrol edilecek kelime listesi.
 * @param word Aranacak kelime.
 * @return Kelime listede varsa 1, yoksa 0 dondurur.
 */
int isWordValid(struct node* list, char* word){
	struct node* temp = list;
	int length = strlen(word);
	while(temp){
		if(!strcmp(temp->word, word))
			return 1;
		temp = temp->next;
	}return 0;
}

/**
 * @brief Verilen kelimeye bir harf farkiyla eslesen kelimeleri listeler.
 * @param word Aranacak kelime.
 * @param liste Aramanin yapilacagi kelime listesi.
 * @param counter Eslesen kelime sayisini tutar.
 * @return Eslesen kelimelerin listesi.
 */
struct node* oneLetterDifferList(char* word, struct node* liste, int* counter){
	int length, differ, i;
	*counter = 0;
	struct node* list = NULL;
	length = strlen(word);
	struct node* temp = liste;
	while(temp){
		differ=0;
		for (i = 0; word[i] != '\0'; i++) {
    		if(word[i] != temp->word[i]){
    			differ++;
			}
		}
		if(differ==1){
			//printf("bir harfi farkli olan kelime: %s\n",temp->word);
			(*counter)++;
			push(&list, temp->word);
		}
		temp = temp->next;
	}
	return list;
}

/**
 * @brief Verilen listede belirli bir kelimenin daha once kullanilip kullanilmadigini kontrol eder.
 * @param list Kontrol edilecek kullanilmis kelime listesi.
 * @param word Kontrol edilecek kelime.
 * @return Kelime daha once kullanildiysa 1, kullanilmadiysa 0 dondurur.
 */
int isUsed(struct node* list, char* word){
	struct node* temp = list;
	int isUsed=0;
	while(temp){
		if(!strcmp(temp->word, word)){
			isUsed=1;
			return isUsed;
		}
		temp = temp->next;
	}
	return isUsed;
}

/**
 * @brief Verilen kuyrugun bos olup olmadigini kontrol eder.
 * @param queue Kontrol edilecek kuyruk.
 * @return Kuyruk bos ise 1, degilse 0 dondurur.
 */
int isQueueEmpty(struct queue* queue){
	if(queue==NULL) return 1;
	else return 0;
}

/**
 * @brief Verilen stack'i serbest birakir.
 * @param stack Serbest birakilacak stack'in adresi.
 */
void freeStack(struct node** stack) {
    struct node* current = *stack;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *stack = NULL; 
}

