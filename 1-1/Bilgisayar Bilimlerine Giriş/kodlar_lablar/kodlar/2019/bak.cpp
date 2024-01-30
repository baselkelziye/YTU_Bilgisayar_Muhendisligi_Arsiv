#include<stdio.h>
#include<math.h>

/*
int main(){
	printf("Deger Gir : \n");
	int i=1,N,toplam=0;	
	scanf("%d",&N);
	while(i<N+1){printf("%d nin karesi : \n",i);i=i*i;printf("%d\n",i);i=sqrt(i);i++;}}
*/
/*
int main(){
int N,Basamak=0;	
printf("Basamagi bulunacak sayiyi gir : \n");
scanf("%d",&N);
while(N!=0){N=N/10;Basamak++;}
printf("%d",Basamak);	
}
*/	

int Oku(){static int N=0;scanf("%d",&N);return N;}
int hesap(){
if(10%5==0){printf("Sayi 5 in kuvveti");}
else{s="Sayi 5in kuvveti degildir"}
}
int yazdir(){char s[100];printf("%c",s);}
int main(){
	Oku();
	hesap();
	yazdir();	
}

