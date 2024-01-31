#include<stdio.h>
int main(){
	
	int ar[5]={1,2};
	int *p=ar;
	int i;
	//p=ar[0];
	printf("%d\n",*p);
	printf("%d\n",ar[0]);//1
	printf("%d\n",&ar[0]);//address
	printf("%d\n",ar);//address
	//printf("%d\n",&&ar[0]);//illegal
	p++;
	printf("%d---%d\n",p,*p);
	p--;
	p+=3;
	printf("%d---%d\n",p,*p);
	*p=*p+5;//ar[3]+=5;
	printf("%d---%d\n",p,*p);
	printf("==============\n");
	for(i=0;i<5;i++){
		printf("%d----%d\n",ar[i],&ar[i]);
	}
	printf("==============\n");
	for(p=&ar[0],i=0;i<5;i++,p++){
		printf("%d----%d\n",*p,p);
	}
	
	printf("==============\n");
	for(p=ar,i=0;i<5464;i++){
		printf("%d %d----%d\n",i,*(p+i),(p+i));
	}
	
	printf("%d----%d\n",sizeof(int),sizeof(short));
	printf("%d----%d",sizeof(int*),sizeof(short*));
	return 0;
}
