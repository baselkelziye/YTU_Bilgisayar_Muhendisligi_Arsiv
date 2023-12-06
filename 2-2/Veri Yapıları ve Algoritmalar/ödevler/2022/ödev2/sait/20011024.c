#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct{
	char items[MAX_STACK_SIZE];
	int top;
}STACK;

int calculateBitLength(int x);
// Stack Operations
void initStack(STACK* s);
int isEmpty(STACK* s);
int isFull(STACK* s);
int push(STACK* s, char x);
int pop(STACK* s);

void generateSignificantBitsForPositiveDecimals(int bitLength, char* signBits);
void generateSignificantBitsForNegativeDecimals(int bitLength, char* signBits);
void decimalToBinary(int bitLength, int decimal, char* binary);
void differenceBtwnZerosAndOnes(STACK *s, char* binary);

int main(void){
	int i,bitLength,decimalNumber;
	char binary[100];
	STACK *s;
	
	s = (STACK*)malloc(sizeof(STACK));
	
	printf("Sayiyi giriniz: ");
	scanf("%d", &decimalNumber);
	
	bitLength = calculateBitLength(decimalNumber);
	decimalToBinary(bitLength,decimalNumber,binary);
	
	printf("Binary: %s\n", binary);
	
	initStack(s);
	differenceBtwnZerosAndOnes(s,binary);
	
	return 0;
}

int calculateBitLength(int x){
	int counter = 0;
	
	while(x != 0){
		x /= 2;
		counter++;
	}	
	
	return counter;
}

void initStack(STACK* s){
	s->top = 0;
}

int isEmpty(STACK* s){
	if(s->top == 0)	return 1;
	return 0;
}

int isFull(STACK* s){
	if(s->top == MAX_STACK_SIZE) return 1;
	return 0;
}

int push(STACK* s, char x){
	if(isFull(s))
		return 0;
	
	else {
		s->items[(s->top)++] = x;
		return 1; 
	}
}

int pop(STACK* s){
	if(isEmpty(s))	return 0;
	
	else{
		s->items[--(s->top)];
		return 1;
	}
}

void generateSignificantBitsForPositiveDecimals(int bitLength, char* binary){
	int i = bitLength;
	char temp[100] = "",zero[2];
	
	zero[0] = '0';
	zero[1] = '\0';
	
	if(bitLength%8 != 0){
		bitLength = (bitLength/8+1)*8;
	}
	
	while(i < bitLength){
		strcat(temp,zero);
		i++;
	}
	strcat(temp,binary);
	strcpy(binary,temp);
}

void generateSignificantBitsForNegativeDecimals(int bitLength, char* signBits){
	int i = bitLength,j,maxBitLength = 32;
	char temp[100] = "",one[2];
	
	one[0] = '1';
	one[1] = '\0';
	
	if(signBits[0] == '0')
		bitLength++;	// Ýsaret bitinin kaybýný engellemek icin burdada bit uzunlugu bir artiriliyor.
	
	if(bitLength%8 != 0){
		bitLength = (bitLength/8+1)*8;
	}

	for(j=0; j<bitLength; j++){
		signBits[j] = signBits[maxBitLength-bitLength+j];
	}
	
	signBits[j] = '\0';
}

void decimalToBinary(int bitLength, int decimal, char* binary){
	itoa(decimal,binary,2);
	if(decimal > 0){
		generateSignificantBitsForPositiveDecimals(bitLength,binary);
	}
	else{
		generateSignificantBitsForNegativeDecimals(bitLength,binary);
	}
}

void differenceBtwnZerosAndOnes(STACK *s, char* binary){
	int i = 0;
	
	/*
		Stack bos olmasi durumunda bir sonraki gelen eleman herhangi bir kosula bakilmaksizin push'lanýr.
		Daha sonra gelecek elemanlarda stack icinde bulunan elemanlarla ayni olmasi kosulu saglaniyorsa 
		push'lanýrlar. Eger farklilarsa stack'den bir eleman pop'lanýr.
		
		binary sayiyi tuttugumuz string'in sonuna gelindiginde stack'de eleman kalmamissa 0 ve 1'ler esit sayida diye cikti verir,
		stack bos degilse stack'in en ustundeki deger top isaretcisinin konumu kadar fazladýr diye cikti verir.	
	*/
	
	while(binary[i] != '\0'){
		if(isEmpty(s))
			push(s,binary[i]);
		
		else{
			if(s->items[s->top-1] == binary[i]){
				push(s,binary[i]);
			}
			else{
				pop(s);
			}
		}
		i++;
	}
	
	if(s->top == 0)
		printf("Girilen Sayida 0 ve 1 esit sayida bulunmaktadir.");
	
	else{
		printf("%c'larin sayisi %d daha fazladir.\n", s->items[s->top-1], s->top);
		if(s->items[s->top-1] == '0'){
			printf("%c'lar fazladir. Ek %d adet 1 gereklidir.\n", s->items[s->top-1], s->top);		
		}	
		else{
			printf("%c'lar fazladir. Ek %d adet 0 gereklidir.\n", s->items[s->top-1], s->top);	
		}
	}			
}

