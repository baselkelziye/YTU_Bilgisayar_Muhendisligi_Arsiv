#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256 //buffer'in maksimum boyutu

/*
	UYARI : Ciktinin duzgun gozukmesi icin tum stack'ler ekrana her seferinde yazdirilmamistir.
			Sadece cozum varsa yazdirilmistir. Egerki tum stack'ler ekrana yazdirilmak isteniyorsa
			103. satirdaki yorum satiri kaldirilmalidir.
*/

//Sozlukteki kelimeler asagidaki struct yapisinda tutulur.
struct WORD{
	char *word;
	int label;
};

//Stack'in her bir dugumu icin kullanilan struct.
struct STACK{
	char *word;
	struct STACK* next;
};

//Queue'nun her bir dugumu icin kullanilan struct.
struct QUEUE{
	struct STACK* stack;
	struct QUEUE* next;
};

void findWordLadder();
struct WORD* getDictionary(char** source, char** target, int *N);
int isStackEmpty(struct STACK* stack);
struct STACK* createStackNode(char* word, struct STACK* next);
void push(struct STACK** stack, char *word);
char* pop(struct STACK** stack);
struct STACK* copyStack(struct STACK** stack);
void printStack(struct STACK* stack);
void freeStack(struct STACK** stack);
int compare(char* str1, char* str2);
int isQueueEmpty(struct QUEUE* head);
struct QUEUE* createQueueNode(struct STACK* stack);
void enqueue(struct QUEUE** head, struct QUEUE** tail, struct STACK* stack);
struct STACK* dequeue(struct QUEUE** head, struct QUEUE** tail);
void freeQueue(struct QUEUE** head, struct QUEUE** tail);

int main(){
	int choice;
	
	do{
		printf("1- New Word Ladder\n");
		printf("0- Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				findWordLadder();
				break;
			case 0:
				printf("\nExiting...");
				break;
			default:
				printf("You made a wrong choice!\n\n");
				break;
		}
	}while(choice != 0);

	return 0;
}

/*
@brief Kullanicidan alinan kaynaktan hedefe dogru kelime merdiveni olup olmadigin bulur.

@return
*/
void findWordLadder(){
	int N; //Sozluk boyutu
	char *source;
	char *target;	
	struct WORD* dictionary = getDictionary(&source, &target, &N); 
	
	if(dictionary == NULL){ //Kaynak ve hedef kelimeler dogru secilmediyse cozum durdurulur.
		return;
	}
	
	struct QUEUE* head = NULL; //Queue'nun bas kismini tutar.
	struct QUEUE* tail = NULL; //Queue'nun kuyruk kismini tutar.
	struct STACK* stack = NULL; //Dequeue edilen stack'i tutar.
	struct STACK* newStack = NULL; //Enqueue edilecek stack'i tutar.
	int i;
	
	push(&stack, source); //Ilk once kaynak kelime bir stack'e aktarilir ve stack queue'ya aktarilir.
	enqueue(&head, &tail, stack); //Ardindan asagidaki while dongusunda bu stack dequeue edilerek algoritma baslar.
	while((stack = dequeue(&head, &tail)) != NULL){ //Queue bosalincaya kadar dequeue islemi gerceklestirilir.
		if(!strcmp(stack->word, target)){ //Dequeue edilen stack'e eklenen son eleman hedefe esitse fonksiyondan cikilir.
			printStack(stack); //Stack'i ilk elemanindan baslayacak sekilde yazdirir.
			printf("\n\n");
			freeQueue(&head, &tail); //Queue'da kalan diger stack'leri temizler.
			return;
//			sleep(5);
		}
//		printStack(stack); printf("\n");
		for(i=0;i<N;i++){ //Sozlukteki tum kelimeleri kontrol ederek stack'e eklenen son elemanla aralarinda bir kelime fark olanlari yeni bir stack'e ekler ve enqueue islemini gerceklestirir.
			if(!dictionary[i].label && compare(dictionary[i].word, stack->word)){
				newStack = copyStack(&stack); //Mevcut stack'i kopyalar.
				push(&newStack, dictionary[i].word); //Kopyalanan stack'e yeni kelimeyi ekler.
				enqueue(&head, &tail, newStack); //Yeni stack'i kuyruga ekler.
				dictionary[i].label = 1; //Kelimenin tekrar kullanilmamasi icin isareti degistirilir.
			}
		}
		
		freeStack(&stack); //Dequeue edilen stack'in isi bittigi icin bellekten silinir.
	}
	printf("There is no word ladder from '%s' to '%s'!\n\n", source, target);
}

/*
@brief Kullanicidan alinan kaynak ve hedef kelime gerekli kontrolleri saglamasi kosuluyla bunlarla ayni uzunluktaki kelimeler dosyadan alinir.

@param source, kaynak kelimenin adresi.
@param target, hedef kelimenin adresi.
@param N, sozluk boyutu.

@return Gerekli sartlarin saglanmasiyla dosyadan alinan sozlugun adresi dondurulur, eger saglanmiyorsa NULL dondurur.
*/
struct WORD* getDictionary(char** source, char** target, int *N){
	char buffer[MAX];
	char fileName[] = "dictionary.txt";
	
	FILE* file = fopen(fileName, "r");
	if(file == NULL){
		printf("File cannot opened!\n\n");
		return NULL;
	}
	
	printf("\nSource: ");
	scanf("%s",buffer);
	*(source) = strdup(buffer);
	
	printf("Target: ");
	scanf("%s",buffer);
	*(target) = strdup(buffer);
	
	if(strlen(*(source)) != strlen(*(target))){ //Kaynak ve hedef kelimelerin uzunlugu farkli olmamalidir.
		printf("Target has a different length from source!\n\n");
		return NULL;
	}
	
	int isSourceFound = 0; 
	int isTargetFound = 0;
	
	struct WORD* dictionary = (struct WORD*) calloc(1, sizeof(struct WORD));
	int n = 0;
	
	while(!feof(file) && fscanf(file,"%s\n",buffer)){ //Dosyanin sonuna gelene kadar tum kelimeleri gezer.
		if(strlen(buffer) == strlen(*(source))){ //Dosyada bulunan kelimenin uzunlugu kaynak kelimeyle ayniysa sozluge eklenir.
			if(!strcmp(*(target), buffer)){ //Hedef kelime sozlukte olmalidir.
				isTargetFound = 1;
			}
			if(!strcmp(*(source), buffer)){ //Kaynak kelime sozlukte olmalidir.
				isSourceFound = 1;
			}else{ //Kaynak ile ayni uzunluktaki kelimeler sozluge eklenir. Kaynak sozluge eklenmez, hedef kelime eklenir.
				dictionary[n].word = strdup(buffer);
				dictionary[n].label = 0; //'0' ifadesi kelimenin daha once kullanilmadigini ifade eder.
				n++;
				dictionary = (struct WORD*) realloc(dictionary, (n+1)*sizeof(struct WORD));
			}			
		}
	}
	
	if(!(isSourceFound || isTargetFound)){
		printf("Source and Target are not in the dictionary!\n\n");
		return NULL;
	}else if(!isSourceFound){
		printf("Source is not in the dictionary!\n\n");
		return NULL;
	}else if(!isTargetFound){
		printf("Target is not in the dictionary!\n\n");
		return NULL;
	}
	
	*N = n;
	fclose(file);
	return dictionary;
}

/*
@brief Verilen iki kelime arasinda sadece bir harf fark olup olmadigini kontrol eden fonksiyon.

@param str1, ilk kelime
@param str2, ikinci kelime

@return Kelimeler arasinda sadece bir harf fark varsa '1', diger durumlardaysa '0' dondurur.
*/
int compare(char* str1, char* str2){
	int length = strlen(str1);
	int i=0, difference = 0;
	
	while(i<length){		
		if(str1[i] != str2[i]){
			if(difference){ //Egerki kelimede daha onceden farkli bir harf varsa bu iki kelime arasinda birden fazla harf farki vardir.
				return 0;
			}
			difference = 1;			
		}
		i++;
	}
	
	return 1;
}

/*
@brief Stack'in bos olup olmadigini kontrol eder.

@param stack, stack'e son eklenen eleman.

@return Stack bos ise '1', degil ise '0' dondurur.
*/
int isStackEmpty(struct STACK* stack){
	if(stack == NULL){
		return 1;
	}
	
	return 0;
}

/*
@brief Stack'e eklenmek uzere yeni bir dugum olusturur.

@param word, stack'e eklenecek olan kelime.
@param next, olusturulacak dugumden sonra gelecek olan dugum.

@return Olusturulan dugumu dondurur.
*/
struct STACK* createStackNode(char* word, struct STACK* next){
	struct STACK* newNode = (struct STACK*) malloc(sizeof(struct STACK));
	newNode->word = strdup(word);
	newNode->next = next;
	
	return newNode;
}

/*
@brief Verilen kelimeyi verilen stack'e ekler.

@param stack, stack'e son eklenmis dugumun adresi.
@param word, stack'e eklenecek olan kelime

@return
*/
void push(struct STACK** stack, char *word){
	if(isStackEmpty(*stack)){ //Stack bos yada olusturulmamis ise ilk dugumu olusturur.
		(*stack) = createStackNode(word, NULL);
	}else{
		struct STACK* temp = createStackNode(word, *(stack));
		*(stack) = temp;
	}	
}

/*
@brief Stack bos degil ise stack'e son eklenmis elemani stack'ten cikartir.

@param stack, stack'e son eklenmis dugumun adresi.

@return Stack'ten cikartilan son dugumde bulunan kelimeyi dondurur.
*/
char* pop(struct STACK** stack){
	if(isStackEmpty(*stack)){
		return NULL;
	}
	
	char* poppedWord = strdup((*stack)->word);
	struct STACK* temp = (*stack); //Dugum stack'ten silinecegi icin bellekten temizlenir.
	*stack = (*stack)->next;
	free(temp);
	
	return poppedWord;
}

/*
@brief Verilen stack'in kopyasini olusturup dondurur.

@param stack, stack'e son eklenmis dugumun adresi.

@return Kopyalanan stack'i dondurur.
*/
struct STACK* copyStack(struct STACK** stack){
	char* word;
	struct STACK* newStack = NULL;
	struct STACK* temp = NULL;
	
	while((word = pop(stack)) != NULL){ //Stack'in sirasi bozulmamasi icin once stack baska bir stack'e bosaltilir yani ters cevrilir.
		push(&temp, word);
	}
	
	while((word = pop(&temp)) != NULL){ //Ters cevrilen stack'ten kelimeler tek tek eski ve yeni stack'e eklenerek sira korunur.
		push(&newStack, word);
		push(stack, word);
	}
	
	return newStack;
}

/*
@brief Stack'i ilk eklenen elemandan baslayacak sekilde yazdirir.

@param stack, stack'e son eklenmis dugum.

@return
*/
void printStack(struct STACK* stack){
	if(stack == NULL){
		return;
	}
	else if(stack->next == NULL){
		printf("%s", stack->word);
		return;
	}
	
	printStack(stack->next);
	printf(" -> %s", stack->word);
}

/*
@brief Stack'i bellekten temizler.

@param stack, stack'e son eklenmis dugumun adresi.

@return
*/
void freeStack(struct STACK** stack){
	struct STACK* temp;
	
	while(!isStackEmpty(*stack)){ //Stack bosalana kadar bu islemi gerceklestirir.
		temp = *stack;
		*stack = (*stack)->next;
		free(temp->word);
		free(temp);
	}
}

/*
@brief Queue'nun bos olup olmadigini kontrol eder.

@param head, queue'ya ilk eklenen eleman.

@return Queue bos ise '1', degil ise '0' dondurur.
*/
int isQueueEmpty(struct QUEUE* head){
	if(head == NULL){
		return 1;
	}
	
	return 0;
}

/*
@brief Queue'ya eklenmek uzere yeni bir dugum olusturur.

@param stack, queue'ya eklenecek olan stack.

@return Olusturulan dugumu dondurur.
*/
struct QUEUE* createQueueNode(struct STACK* stack){
	struct QUEUE* newNode = (struct QUEUE*) malloc(sizeof(struct QUEUE));
	newNode->stack = stack;
	newNode->next = NULL;
	
	return newNode;
}

/*
@brief Verilen stack'i verilen queue'ya ekler.

@param head, queue'ya ilk eklenen dugumun adresi.
@param tail, queue'ya son eklenen dugumun adresi.
@param stack, queue'ya eklenecek olan stack.

@return
*/
void enqueue(struct QUEUE** head, struct QUEUE** tail, struct STACK* stack){
	if(isQueueEmpty(*head)){ //Queue bos ise queue'nun sonuna stack'i bulunduran dugumu ekler ve head de bu dugumu gosterir. 
		*tail = createQueueNode(stack);
		*head = *tail;
	}else{ //Queue bos degil ise en sona stack'i bulunduran dugum eklenir.
		(*tail)->next = createQueueNode(stack);
		(*tail) = (*tail)->next;
	}
}

/*
@brief Queue bos degil ise queue'ya ilk eklenmis stack'i queue'dan cikartir.

@param head, queue'ya ilk eklenen dugumun adresi.
@param tail, queue'ya son eklenen dugumun adresi.

@return Queue'dan cikartilan stack'i dondurur.
*/
struct STACK* dequeue(struct QUEUE** head, struct QUEUE** tail){
	if(isQueueEmpty(*head)){
		return NULL;
	}
	
	struct STACK* popped = (*head)->stack; //Queue'dan cikartilan dugum icindeki stack saklanacak sekilde bellekten temizlenir.
	struct QUEUE* temp = *head;
	(*head) = (*head)->next;
	free(temp);
	
	if(isQueueEmpty(*head)){ //Queue'dan dugum cikartildiktan sonra queue bosaliyorsa tail de NULL gosterir.
		*tail = NULL;
	}
	
	return popped;
}

/*
@brief Queue'da bulunan elemanlari bosaltir ve bellekten temizler.

@param head, queue'ya ilk eklenen dugumun adresi.
@param tail, queue'ya son eklenen dugumun adresi.

@return
*/
void freeQueue(struct QUEUE** head, struct QUEUE** tail){
	struct STACK* temp;
	
	while((temp = dequeue(head, tail)) != NULL){ //Dequeue islemi ile queue'dan bir dugum silinir, dondurdugu stack de freeStack() fonksiyonu ile bellekten silinir.
		freeStack(&temp);
	}
}
