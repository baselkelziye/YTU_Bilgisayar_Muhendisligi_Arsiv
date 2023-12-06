#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	printf("Deneme");
	printf("\nArguman Sayisi=%d",argc);
	int i=0;
	for(i=0;i<argc;i++){
		printf("%s\n",argv[i]);
	}
	
	
	printf("%d\n",atoi(argv[1])+3);
	scanf("%d",&i);
	printf("%f\n",atof(argv[0])+3);
	printf("%d-----%d\n",i,atoi(argv[2])+3);
	
	return 0; 
}

