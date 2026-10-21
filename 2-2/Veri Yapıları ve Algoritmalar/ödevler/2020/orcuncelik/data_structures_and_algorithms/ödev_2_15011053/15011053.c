// C program for Huffman Coding 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct FREQ{
	int frekans;
	char harf;
}FREQ;

// A Huffman tree node 
typedef struct NODE{ 
    char data; 
    int freq; 
    struct NODE *left, *right; 
}NODE; 
  
// A Min Heap:  Collection of 
// min-heap (or Huffman tree) nodes 
typedef struct heapCollection { 
    unsigned size; 
    unsigned capacity; 
    struct NODE** array; //minHeap nodelarindan olusan array.
}heapCollection; 
   
NODE* newNode(char data, unsigned freq) { 
    NODE* temp = ( NODE*)malloc(sizeof(NODE)); 
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
  
    return temp; 
} 
  
heapCollection* createMinHeap(unsigned capacity) {   
    heapCollection* minHeap = ( heapCollection*)malloc(sizeof(heapCollection)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (NODE**)malloc(minHeap -> capacity * sizeof(NODE*)); 
    return minHeap; 
} 
void swapMinHeapNode(NODE** a, NODE** b){ //Nodelari swap yapar. 
	NODE* t = *a; 
    *a = *b; 
    *b = t; 
} 
  //--------------------------------------------------------------------------

void minHeapify(heapCollection* minHeap, int indis) {  //Minheap'in butunlugunu saglar
    int smallest = indis; 
    int left = 2 * indis + 1; 
    int right = 2 * indis + 2; 
  
    if ( (left < minHeap->size) && ( (minHeap->array[left]-> freq) < (minHeap->array[smallest]->freq) ) )
        smallest = left; 
  
    if ( (right < minHeap->size) && ( (minHeap->array[right]-> freq) < (minHeap->array[smallest]->freq) ) )
        smallest = right; 
  
    if (smallest != indis) { 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[indis]); 
        minHeapify(minHeap, smallest); 
    } 
} 

int isSizeOne(heapCollection* minHeap){//Huffman tree olusturulurken kullanilacak olan size'in 1 olup olmadigini belirtir.
    return (minHeap->size == 1); 
} 
  

NODE* extractMin(heapCollection* minHeap){ //Minimum degeri cikarir.
  
    NODE* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
    minHeap->size--; 
    minHeapify(minHeap, 0);  //Butunlugun saglanmasi icin heapify edilir.
  
    return temp; 
} 

void insertMinHeap(heapCollection* minHeap, NODE* minHeapNode){  //Collection'a yeni bir node ekler.
    minHeap->size++; 
    int i = minHeap->size - 1; 
  
    while ((i) && (minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)) {  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    }  
    minHeap->array[i] = minHeapNode; 
} 
  
void buildMinHeap(heapCollection* minHeap){ //Building min heap
    int x = minHeap->size - 1; 
    int i; 
    for (i = (x - 1) / 2; i >= 0; i--) 
        minHeapify(minHeap, i); 
} 

int isLeaf(NODE* node){
    return !(node->left) && !(node->right); //Left root ve right root NULL ise gonderir agacin en assagisi
} 
  //----------------------------------------------------------------------------------
// Creates a min heap of capacity 
// equal to size and inserts all character of// data[] in min heap. Initially size of 
// min heap is equal to capacity 
heapCollection* createAndBuildMinHeap(char data[], int freq[], int size) { 
    heapCollection* minHeap = createMinHeap(size); 
    int i;
    for (i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
    minHeap->size = size; 
    buildMinHeap(minHeap); 
    return minHeap; 
} 
  
//Huffman Tree build eder.
NODE* buildHuffmanTree(char* data, int *freq, int size) { 
    NODE *left, *right, *top;  
    heapCollection* minHeap = createAndBuildMinHeap(data, freq, size);   
    while (!isSizeOne(minHeap)) {  //Boyutu 1 olmayana kadar deva
        //EN kucuk frekansa sahip olanlarin cikarilmasi
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
        top = newNode('$', left->freq + right->freq); //$ ic nodelar icindir.
        top->left = left; 
        top->right = right; 
        insertMinHeap(minHeap, top); 
    } 
	//Son kalan node root node.
    return extractMin(minHeap); 
} 
//---------------------------------------------------------------------------
  
// Prints huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 

void printPreorder(NODE* node) { 
    if (node == NULL){
    	printf("\t");
   	return;
	} 
	if(node->freq){
		printf("%d", node->freq); 
   		if(isLeaf(node)){
     		printf("%c", node->data);
     		printf("\t");
		}	
	 	
   		printf("\n");
     	printPreorder(node->left);  
    	printPreorder(node->right); 
			
	}
	 
}     
// The main function that builds a 
// Huffman Tree and print codes by traversing 
// the built Huffman Tree 
void initHufman(char data[], int freq[], int size) {
    NODE* root  = buildHuffmanTree(data, freq, size); 
    printPreorder(root); 
} 
void insertionSort(FREQ *arr, int n) {
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i].frekans; 
        j = i - 1; 
        while (j >= 0 && arr[j].frekans > key) { 
            arr[j + 1].frekans = arr[j].frekans; 
            j = j - 1; 
        } 
        arr[j + 1].frekans = key; 
    } 
} 
  
// Driver program to test above functions 
int main() { 
	NODE *head = NULL; //initilazing head
	char *arr = "huffman coding is a data compression algorithm";
	int i;
	int freq[26];
	int size = strlen(arr); //Stores length of the array.
	FREQ *frekans = (FREQ*) calloc(size, sizeof(FREQ));

	
	for(i=0; i<26; i++) //initilazing frequency array
		freq[i] = 0;
	for(i=0; i<size; i++){ 
		if(arr[i] >= 'a' && arr[i] <= 'z') 
			freq[arr[i] - 97]++;	//a starts from 97 in ASCII table
	}
	char c[26]; //Linkedliste char olarak gondermek icin.

	int k = 0; //Char ve Int dizisinin indisi
	for(i=0; i<26; i++){
		if((freq[i] != 0)){
			frekans[k].harf = i+97;
			frekans[k].frekans = freq[i];
		//	printf("%c %d \n",frekans[k].harf,frekans[k].frekans );
			k++;
		}	
	}
	insertionSort(frekans,k);
	int *newFreq = (int*) calloc(k,sizeof(int));
	char *newChar = (char*) calloc (k,sizeof(char));
	for(i=0; i<k; i++){
		newFreq[i] = frekans[i].frekans;
		newChar[i] = frekans[i].harf;
		printf("%d %c\n",frekans[i].frekans, frekans[i].harf);
	}

  //  initHufman(newChar, newFreq, size); 
  
    return 0; 
} 
