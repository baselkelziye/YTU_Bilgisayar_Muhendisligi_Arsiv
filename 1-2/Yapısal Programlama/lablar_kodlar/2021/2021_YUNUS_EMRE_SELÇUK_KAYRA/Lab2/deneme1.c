#include <stdio.h>
int main(void){
	int a,i,b=5,j;
	int**p;
	printf("ni gir");
	scanf("%d",&a);
	
	p= (int**)calloc(a,sizeof(int*));
	if(p==NULL){
	printf("olmadý");
	return -1;
	}
		for(i=0;i<a;i++){
		*(p+i)=(int*)calloc(b,sizeof(int));
		if(*(p+i)==NULL);
		return -1;
	}
		for(i=0;i<a;i++){
		for(j=0;j<b;j++){
		printf("\n%d %d\t",i,j);
		scanf("%d",(*(p+i)+j));//&a[i][j]
		}
		printf("\n");
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			
			printf("%d\t",*(*(p+i)+j));
		}
		printf("\n");
	}
	for(i=0;i<a;i++){
		free(*(p+i));
	}
	free(p);
	return 0;
}
