#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#include <math.h>

int main(){
int i,m,t,j,k=4,s=4,n,start,end,saga,sola,yukari,asagi,min=0;
int Board[5][5]={{-10,5,30,-20,40},{20,0,10,5,50},{5,50,-40,15,60},{10,-10,0,-5,70},{15,20,30,-20,0}};
printf("1- Saga\n");
printf("2- Sola\n");
printf("3- Yukari\n");
printf("4- Asagi\n");
i=0;
j=0;
printf("Lutfen matrisin boyutunu giriniz ");
scanf("%d",&n);
printf("Lutfen Start degerlerinin satir ve sutununu sirayla giriniz ");
scanf("%d",&m);
scanf("%d",&t);
printf("Lutfen Stop degerlerinin satir ve sutununu sirayla giriniz ");
scanf("%d",&k);
scanf("%d",&s);
while(k!=i+m || j+t!=s){
	if(k>=m && s>=t){
	if(i+m<k && j+t<s){
	if(Board[i+1+m][j+t]>Board[i+m][t+j+1]){
		min+=Board[i+m][j+1+t];
		printf("a[%d][%d] = %d\n",i+m,j+1+t,Board[i+m][j+1+t]);
		j++;
	}
	else{
		min+=Board[i+1+m][j+t];
		printf("a[%d][%d] = %d\n",i+m+1,j+t,Board[i+m+1][j+t]);
		i++;
	}
}
else{
	if(i+m>k){
			min+=Board[i+m][j+1+t];
			printf("a[%d][%d] = %d\n",i+m,j+1+t,Board[i+m][j+1+t]);
		j++;
		if(j+t==s){
		}
		
	}
	else{
	min+=Board[m+i+1][t+j];
	printf("a[%d][%d] = %d\n",i+m+1,j+t,Board[i+m+1][j+t]);
		i++;
		if(i+m==k){
		}	
	}
}}
else{
	if(i+m>=k && j+t>=s){
	if(Board[i-1+m][j+t]>Board[i+m][t+j-1]){
		printf("a[%d][%d] = %d\n",i+m,j-1+t,Board[i+m][j-1+t]);
		min+=Board[i+m][j-1+t];
		j--;
	}
	else{
		min+=Board[i-1+m][j+t];
		printf("a[%d][%d] = %d\n",i-1+m,j+t,Board[i-1+m][j+t]);
		i--;
	}
}
else{
	if(i+m<k){
		printf("a[%d][%d] = %d\n",i+m,j-1+t,Board[i+m][j-1+t]);
			min+=Board[i+m][j-1+t];
		j--;
		if(j+t==s){
		}
		
	}
	else{
		printf("a[%d][%d] = %d\n",i+m-1,j+t,Board[i+m-1][j+t]);
	min+=Board[m+i-1][t+j];
		i++;
		if(i+m==k){
		}	
	}
}
		
}
}
printf("\n");
printf("min deger = %d\n",min);

	
return 0;
}
