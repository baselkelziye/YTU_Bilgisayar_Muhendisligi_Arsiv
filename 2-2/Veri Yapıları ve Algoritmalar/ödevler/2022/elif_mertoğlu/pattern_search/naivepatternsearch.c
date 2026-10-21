#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
int main(){
	
	int r, k=0;
	printf("Kac kez desen arayacaginizi giriniz:"); 
	scanf("%d",&r);
	int t,p,i,x,j,n,sayac,w=0; 
	
	
	double zaman[50]; 
	int patfound[10000]; 
	char text[200000], pattern[50]; 
	srand(time(NULL)); 
	while(k<r){ 
		printf("\nmetnin boyutunu giriniz:");
	    scanf("%d",&t);
	    printf("\ndesenin boyutunu giriniz:");
	    scanf("%d",&p);
		int lower = 65, upper = 67; 
		long after,before; 
		for(i=0;i<t;i++){
			before=clock(); 
			text[i]=(rand()% (upper - lower + 1)) + lower; 
		}
		printf("\nmetin:");
		for(i=0;i<t;i++){
			printf("%c",text[i]); 
		}
		printf("\n\n");
		for(i=0;i<p;i++){
			pattern[i]=(rand()% (upper - lower + 1)) + lower; 
		}
		printf("desen:");
		for(i=0;i<p;i++){
			printf("%c",pattern[i]); 
		}
		printf("\n\n");
		n=0; sayac=0;
		x=t-p; 
		

		for(i=0;i<=x;i++){ 
			for(j=0;j<p;j++){ 
			if(text[i+j]!=pattern[j]) 
		    break;
		}
			if(j==p){
				patfound[n]=i;  
				n=n+1;
			}
			after=clock(); 
			
		}
	        double elapsed=(double)(after-before)/CLOCKS_PER_SEC; 
			
			zaman[w]=elapsed; 
			w=w+1;
			
		if(n!=0){
	for(i=0;i<n;i++){
			printf("%d.indexte desen bulundu.\n",patfound[i]);
		}
}else{
	printf("desen bulunamadi\n");
}
		k=k+1;	
	}
	
	for(i=0;i<r;i++){
		printf("\nzaman=%lf\n",zaman[i]); 
	}
	
	double grafik[100];
	for(i=0;i<r;i++){
		grafik[i]=zaman[i]*100; 
	}
	
	int graphic[100];
	for(i=0;i<r;i++){
		graphic[i]=round(grafik[i]); 
	}
	
	char c='#';
	for(i=0;i<r;i++){
		printf("\n");
		printf("%d.aramanin grafigi:",i+1);
		for(j=0;j<graphic[i];j++){ 
			printf("%c",c);
		}
	}
	
	return 0;
}
