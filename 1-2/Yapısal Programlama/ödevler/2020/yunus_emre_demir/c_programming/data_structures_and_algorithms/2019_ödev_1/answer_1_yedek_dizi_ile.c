#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char chYaz( char dizi[]){
	printf(" %s \n\n",dizi);
}

int oncelik(char oprnt){
    switch (oprnt) {
    	case '(': return 1;
    	
	    case '+':
	    case '-': return 2;
	    
	    case '*':
	    case '/': return 3;	        
    }
    return -1;
}

int hesapla(char operand, int x , int y){
	if(operand == '+')
		return (x + y);
	else if(operand == '-')
		return (x - y);
	else if(operand == '*')
		return (x * y);
	else if(operand == '/')
		return (x / y);
	return -1;
}

char oprStack[20]={'\0'}; 
int sayiStack[20]={'\0'};
int op = 0;  // operand stack pointer
int sp = 0, yp=0;  // sayi stack pointer
int i=0; // str pointer
	//char str[] ="21/((4+08)*2-17)"; //3+
	//char str[] = "8+2*(21/(7-4))+2";	//24+
	 char str[] ="(12+4-3)*(7*2+5)";   //247+
	//char str[] = "3+4*5*4+3-1/2+1";

void yaz(char oprStack[], int sayiStack[], int sp){
	if(oprStack[0] == '\0')
		printf("Isaret yigini : Bos\n");
	else
		printf("Isaret yigini : %s \n",oprStack);
	//----------------------------------------
	if(sayiStack[0] == '\0') 
		printf("Sayi yigini : Bos\n");
	else{
		int i=0;
		printf("Sayi yigini : ");
		for(i=0; i<sp ;i++)
			printf("%d ",sayiStack[i]); 
	}
	printf("\n\n");
}
	
int pop(){
	return sayiStack[--sp];
}

void push(int sayi){
	sayiStack[sp++]=sayi;
}

void popop(){
	oprStack[op]='\0';	
}

void pushop(char operand){
	oprStack[op++]=operand;	
}

int aa(char *samamama){
	int size=0, j=0, don=0;
	size=strlen(samamama);
	if(size==1)
		don= (samamama[j] - '0');
	else{
		for(j=0; j<size; ++j){
			don += pow(10,size-j-1) * (samamama[j]- '0');
		}
	}
	return don;
}


int main(void){
	
	int a=0, b=0, sonuc=0;
	int sizeStr = sizeof(str)/sizeof(char);
	printf("\nstr nin boyutu : %d \n",sizeStr);
	printf("Islem yapilacak ana dizi :"); chYaz(str);
	char yedek[10];
	
	
	while(str[i] != '\0' ){  
		
/*1*/	if (str[i] == '('){
			pushop('(');  // parantezi staðe at ve op deðiþkenini bir arttýr yani imleci bir saða kaydýr
			yaz(oprStack, sayiStack, sp);
		}
		
/*2*/	else if (str[i] == ')') {
			while(oprStack[--op]!= '('){	
				a = pop();  // stakten ilk deðeri al a ya ata sonra imleci bir sola kaydýr 
				sayiStack[sp]='\0';
				
				b = pop();  // stackten ikinci deðeri al imleci bir sola kaydýr
				sayiStack[sp]='\0';	
			
				sonuc = hesapla(oprStack[op],b,a); // asonuc = a ? b  && o iþlem için kullanýlan operandý da kaldýrdýk 
				push(sonuc); // hesaplama sonrasý çýkan sayýyý sayý stackine koyduk
				oprStack[op]='\0';
			}
			oprStack[op]='\0'; // en son ( iþaretininde kaldýrýyoruz stackten
			yaz(oprStack, sayiStack, sp);   
		}
		
			
/*3*/	else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
			int yeniopr = oncelik(str[i]);
			int tmp=op;
			while(oprStack[0] != '\0' && oncelik(oprStack[--tmp]) >= yeniopr){ 
			  	a = pop();   // stakten ilk deðeri al a ya ata sonra imleci bir sola kaydýr yani pop yap
				sayiStack[sp]='\0';
		
				b = pop(); 
				sayiStack[sp]='\0';	// stackten ikinci deðeri al imleci bir sola kaydýr yani pop yap 
		
				sonuc = hesapla(oprStack[tmp],b,a);//not burada --op yok çünkü zaten -- ledik yukarda
				push(sonuc); 
				oprStack[tmp]='\0';
				op--;
				yaz(oprStack, sayiStack, sp);
			}
			pushop(str[i]); //eðer gelen ordakinden küçükse direk üstüne ekle oparandý bir saða götür
			yaz(oprStack, sayiStack, sp);
		}
//ÞAHESER BURADAN BAÞLIYOR :) YEDEK DÝZÝ ÝLE ÇÖZÜMÜ	
		else if (str[i] != '\0' && str[i]<='9' && str[i]>='0' ){
			yp=0;
			while(str[i] != '\0' && str[i]<='9' && str[i]>='0'){
				yedek[yp++] = str[i++];
			}
			yedek[yp]='\0';
			push(aa(yedek));
			yaz(oprStack, sayiStack, sp);
			i--;
		}
		
	i++;
	}
		
	while( op != 0 ){ 
		a =pop();
		sayiStack[sp]='\0';
		
		b = pop();
		sayiStack[sp]='\0';
			
		sonuc = hesapla(oprStack[--op],b,a);
		push(sonuc); 
		oprStack[op]='\0';
	}
	
	yaz(oprStack, sayiStack, sp);
	return 0;
}

	
	
	
	
	
