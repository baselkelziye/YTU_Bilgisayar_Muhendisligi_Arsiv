//M.Ali Bugday
//date created:01.04.2022
//date modified:02.04.2022  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50 
//maximum stack size

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct stack{
	int top;
	int dizi[MAX];
}STACK;


void initialize(STACK *s);
void *anaFonksiyon(int n);

int main() {
	int n;
	char *kelime;
	
	printf("Decimal bir sayi degeri giriniz:");
	scanf("%d", &n);
	
	anaFonksiyon(n);
	
	return 0;
}//end of main function
	
void initialize(STACK *s){
	s->top=0;
}
	
int isEmpty(STACK *s){
	if(s->top==0){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(STACK *s){
	if (s->top==MAX){
		return 1;
	}
	else{
		return 0;
	}
}

void push(STACK *s, int item){
	if(isFull(s)){
		printf("Full");
	}
	else{
		s->dizi[s->top]=item;
		s->top+=1;
	}	 
}

int pop(STACK *s){
	if(isEmpty(s)){
		printf("stack bos hatasi!");
		exit(0);		
	}
	else{
		s->top-=1;
		return s->dizi[s->top];
	}
}


void *anaFonksiyon(int n)
{
	STACK s;
	int i, m, counter, uzunluk, toplam=0;
	char *str;
	
	initialize(&s);
	
	for(i=7;i<65;i+=8){//max siniri 2 üzeri 64 koydum bundan byük sayi girilmeyecegini düsünerek.
		if(abs(n) < pow(2,i)){
			uzunluk=i;
			break;
		}
	}
	
	
	str = (char*)malloc(uzunluk+1);
	
	if (str == NULL){
		exit(EXIT_FAILURE);	
	}
	
	
	counter = 0;
	for (i = uzunluk;i >= 0; i--)
	{
		//shift islemi: Sayinin i kadar sonraki bitindeki deger sifir mi bir mi diye kontrol ediliyor
		m = n >> i;
		
		if (m & 1){
			push(&s, 1);
		    *(str+counter) = 1 + '0';
		}
		else{
			push(&s, 0);
			*(str+counter) = 0 + '0';	
		}
		counter++;
	}
	*(str+counter) = '\0';
	
	while(!isEmpty(&s)){
		toplam+=pop(&s);
	}
	
	
	printf("%d sayisinin string olarak binary karsiligi: %s\n", n, str);
	
		
	if(2*toplam == uzunluk+1){
		printf("Esit sayida sifir ve bir icerir");
	}
	else if(toplam > (uzunluk+1)/2){
		printf("Birler fazladir %d adet sifir gereklidir",(toplam-((uzunluk+1)-toplam)));
	}
	else{
		printf("sifirlar fazladir %d adet bir gereklidir",((uzunluk+1)-toplam)-toplam);
	}
	
}
