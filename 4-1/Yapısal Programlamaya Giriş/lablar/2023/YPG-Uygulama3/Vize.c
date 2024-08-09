#include <stdio.h>
#include <time.h>
#include<stdlib.h>

void First_Question(){
	int N;
	int i;
	float s1,s2;
	int say=0;
	printf("First Question N: ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		s1=(rand()%1000)/1000.0;
		s2=(rand()%1000)/1000.0;
	//	printf("s1: %f, s2: %f s1*s1: %f\n",s1,s2,s1*s1);
		if(s1*s1<=s2)
			say+=1;
	}
	
	printf("First Question Result: %f\n",1.0*say/N);
}


void Second_Question(){
	int N;
	int i;
	float s1,s2;
	int say=0;
	printf("Second Question N: ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		s1=(rand()%1000)/1000.0;
		s2=(rand()%1000)/1000.0;
	//	printf("s1: %f, s2: %f s1*s1: %f\n",s1,s2,s1*s1);
		if((s1>(1-s2))&&(s2<0.5))
			say+=1;
	}
	
	printf("Second Question Result: %f\n",1.0*say/N);
}

int Third_Question(i,j){
	if(i==0)
		return 0;
	else{
		printf("Ara sonuc: %d %d",i,i/j);
		return Third_Question(i/j,j)+1;
	}
		
	
}

void Fourth_Question(int n){
	int i;
	if(n==0)
		return;
	Fourth_Question(n-1);
	for(i=n;i>0;i--)
		printf("*");
printf("\n");
}

int main(){	
	srand(time(NULL));
	First_Question();
	Second_Question();
	
	int i=82,j=3;
	int Res=Third_Question(i,j);
	printf("Third Question Res: %d\n",Res);
	printf("Fourth Question Results: \n");
	Fourth_Question(3);
	
}
