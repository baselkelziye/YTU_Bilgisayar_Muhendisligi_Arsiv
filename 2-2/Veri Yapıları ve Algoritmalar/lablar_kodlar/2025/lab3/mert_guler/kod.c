#include<stdio.h>
#include<stdlib.h>


//Lab4-Question2

//Disaridan iki farkli KUYRUKía girdi olarak basamak basamak okunan iki adet sayinin toplamini
// hesaplamak icin bir YIGIN kullanilmasi istenmektedir. Bahsi gecen islemleri yapan ve ilgili
// YIGINída basamak basamak yer alan TOPLAM degerin ekrana sira ile basamak basamak
// yazdirilmasini saglayan programin kodunu C dilinde yaziniz.

// Her Y˝˝n ve Queue i˛leminde kulland˝˝n˝z veri yap˝s˝n˝n son halini kullan˝c˝ya yazd˝r˝n.

//Not: Her iki sayinin disaridan en dusuk anlamli basamaktan en yuksek anlamli basamaga dogru okunmasi onerilmektedir. STACK ve QUEUE fonksiyonlari hazir verilmektedir. Yeniden yazmayiniz.

//Girdi:  Sayi 1:  5 4 7 8 9
//        Sayi 2:  1 2 3

//Cikti:  5 4 9 1 2

// Form Linki: https://l24.im/eidgr9u
//////////////////
// Write the code of the program that performs the operations mentioned and prints the TOTAL value in the related STACK to the screen in order, step by step, in C language.
// It is desired to use a STACK to calculate the sum of two numbers read as input to two different QUEUEs from outside.

// Print the final version of the data structure you used in each Stack and Queue operation to the user.

//Note: It is recommended that both numbers be read from the outside from the least significant digit to the most significant digit. STACK and QUEUE functions are provided as is. Do not rewrite.

//Input: Number 1: 5 4 7 8 9
// Number 2: 1 2 3

//Output: 5 4 9 1 2

// Form Link: https://l24.im/eidgr9u

typedef struct QUEUE{
    int *arr;
    int size;
    int queueEnd;
    int currItem;
}queue;

typedef struct STACK{
    int *arr;
    int size;
    int currP;
}stack;


stack* createStack(int size){
    stack* newStack=(stack*)malloc(sizeof(stack));
    newStack->arr=(int*)malloc(size*sizeof(int));
    newStack->size=size;
    newStack->currP=0;
    return newStack;
}

void reSizeStack(stack *Stack){
    printf("Resizing Stack from %d to %d\n",Stack->size,Stack->size*2);
    Stack->size*=2;
    Stack->arr=realloc(Stack->arr,Stack->size*sizeof(int));
}


void push(stack* Stack,int newItem){
    Stack->arr[Stack->currP++]=newItem;
    if(Stack->currP==Stack->size)
        reSizeStack(Stack);
}

int pop(stack* Stack){
    if(Stack->currP<=0)
        return -1;
    return Stack->arr[--Stack->currP];
}

void printStack(stack* Stack){
    int i;
    printf("Current Stack: ");
    for(i=0;i<Stack->currP;i++)
        printf("%d ",Stack->arr[i]);
        
    printf("\n");
    
}

queue* createQueue(int size){
    queue* newQueue=(queue*)malloc(sizeof(queue));
    newQueue->arr=(int*)malloc(size*sizeof(int));
    newQueue->size=size;
    newQueue->queueEnd=0;
    newQueue->currItem=0;
    return newQueue;
}

void reSizeQueue(queue *Queue){
    printf("Resizing Queue from %d to %d\n",Queue->size,Queue->size*2);
    Queue->size*=2;
    Queue->arr=realloc(Queue->arr,Queue->size*sizeof(int));
}


void enq(queue* Queue,int newItem){
    Queue->arr[Queue->queueEnd++]=newItem;
    if(Queue->queueEnd==Queue->size)
        reSizeQueue(Queue);
}

int deq(queue* Queue){
    if((Queue->currItem>=Queue->queueEnd)||(Queue->queueEnd==0))
        return -1;
    return Queue->arr[Queue->currItem++];
}


void printQueue(queue* Queue){
    int i;
    printf("Current Queue: ");
    for(i=Queue->currItem;i<Queue->queueEnd;i++)
        printf("%d ",Queue->arr[i]);
        
    printf("\n");
    
}

void freeQueue(queue* Queue){
    free(Queue->arr);
    free(Queue);
}

void freeStack(stack* Stack){
    free(Stack->arr);
    free(Stack);
}

void sumAndPrint(queue* queue1, queue* queue2, int n1, int n2){
    int carry = 0;
    int i = 0, j = 0;
    int a, b, sum;
    int size;
    
    if (n1 > n2){
        size = n1;
    } else {
        size = n2;
    }
    
    stack* stack = createStack(size + 1); // extra + 1
    
    // Sum all for equal powers
    while (i < n1 && j < n2) {
        a = deq(queue1);
        b = deq(queue2);
        sum = (a + b + carry) % 10;
        carry = (a + b + carry) / 10;
        push(stack, sum);
        i++;
        j++;
    }
    
    // push if anything left in queue1
    while (i < n1){
        a = deq(queue1);
        sum = (a + carry) % 10;
        carry = (a + carry) / 10;
        push(stack, sum);
        i++;
    }
    
    // push if anything left in queue2 (Not happening in this example because n2 <= n1 is always true)
    while (j < n2){
        a = deq(queue1);
        sum = (a + carry) % 10;
        carry = (a + carry) / 10;
        push(stack, sum);
        j++;
    }
    
    // Push if any carry left like 1 + 9 + 10
    if (carry == 1){
        push(stack, 1);
    }
    
    printf("\nResult:\n");
    for (i = 0; i < size; i++) {
        printf(" %d ", pop(stack));
    }
    
    // If extra number created like 99 + 99 = 198
    a = pop(stack);
    if (a != -1){
        printf(" %d ", a);
    }
}


int main(void){
    // Ters girilecek dendigi icin inputu 9 8 7 4 5 ve 3 2 1 olarak vermeniz gerekli
    
    //Input: Number 1: 5 4 7 8 9
    // Number 2: 1 2 3
    //Cikti:  5 4 9 1 2
    
    int n1, n2;
    int i;
    int temp;
    
    printf("Enter n1 (Basamak sayisi): ");
    scanf("%d", &n1);
    
    printf("Enter n2 (Basamak sayisi): ");
    scanf("%d", &n2);
    
    queue* queue1 = createQueue(n1);
    queue* queue2 = createQueue(n2);
    
    for (i = 0; i < n1; i++) {
        printf("Q1 eleman %d: ", i + 1);
        scanf("%d", &temp);
        enq(queue1, temp);
    }
    
    for (i = 0; i < n2; i++) {
        printf("Q2 eleman %d: ", i + 1);
        scanf("%d", &temp);
        enq(queue2, temp);
    }
    
    // Stack fonksiyon icerisinde olusturulur.
    // n2 > n1 olamayacagi belirtiligi icin kontrol edilmedi.
    sumAndPrint(queue1, queue2, n1, n2);
    
    // Ters girilecek dendigi icin inputu n1:5, n2: 3 ve  9 8 7 4 5 ve 3 2 1 olarak vermeniz gerekli
    
    //Input: Number 1: 5 4 7 8 9
    // Number 2: 1 2 3
    //Cikti:  5 4 9 1 2

    return 0;
}
