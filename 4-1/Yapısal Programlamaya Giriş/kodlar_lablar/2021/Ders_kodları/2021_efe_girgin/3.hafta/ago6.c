#include <stdio.h>
int main(){
	int i,tutucu,ori,orijinal,hane;
	for(i=100000;i<=999999;i++){
			orijinal=i;
			ori=i;
			hane=0;
		while(ori!=0){
		
			tutucu=ori%10;
			hane=hane*10+tutucu;
			ori=ori/10;
			
			
		}
		if(hane==orijinal){
				printf("%d\n",hane);
			}
	}
	return 0;
}
//kod calýsýyor
//sayfa 7
