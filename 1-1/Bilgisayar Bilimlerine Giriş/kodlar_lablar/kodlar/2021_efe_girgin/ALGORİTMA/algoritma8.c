#include <stdio.h>
int main(){
	int a,b,c;
	printf("please enter first dimension of the triangle:");
	scanf("%d",&a);
	
	printf("please enter second dimension of the triangle");
	scanf("%d",&b);
	
	scanf("please enter third dimension of the triangle");
	scanf("%d",&c);
	
	if(a==b){
		if(b==c){
			printf("eþkenar ucgen \n");	
		}
		else{
			printf("ikizkenar ucgen\n");
		}
	}
	else{	
		if(b==c){
			printf("ikizkenar ucgen \n");
		}
		else if(a==c){
			printf("ikizkenar ucgen \n");
		}
		else{
			printf("cesitkenar ucgen \n");
		}
	}
		
		
	
	
	return 0;
}
//kod calýsdý
//iç açýlarý verilen üçgenin karar agacý ile algoritmasi ve programi
//sayfa 4
