#include <stdio.h>
#include <math.h>
//karekok bulma(newton)
int main(void){
	int i=1;
	float x,new,old,th,e;
	
	printf("please enter a number:");
	scanf("%f",&x);
	
	printf("please enter a threshold:");
	scanf("%d",&th);
	
	old=1;
	new=(old+x/old)/2;
	e=fabs(new-old);
	
	while(e>th){
		printf("#%d>old:%f-new:%f-e:%f\n",i,old,new,e);
		
		i++;
		old=new;
		new=(old+x/old)/2;
		e=fabs(new-old);
	}
	
	printf("square root of %f is %f at iteration:%d\n",x,new,i);
	
	return 0;
}
//anlasýldý
//deneme ve compile yapildi
