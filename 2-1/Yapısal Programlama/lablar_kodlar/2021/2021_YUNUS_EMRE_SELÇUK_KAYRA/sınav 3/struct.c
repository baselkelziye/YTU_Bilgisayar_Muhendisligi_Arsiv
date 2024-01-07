#include <stdio.h>
typedef struct oki{
	char name[20];
	int id;
}sinif;
sinif* elemanoku(sinif *a){
	int i;
	a=(sinif*)malloc(3*sizeof(sinif));
	for(i=0;i<3;i++){
		printf("Lutfen name gir\n");
		scanf("%s",a[i].name);
		printf("Lutfen id gir\n");
		scanf("%d",&a[i].id);
	}
	return a;}
int main(){
	sinif *a;int i;
	a=elemanoku(a);
	for(i=0;i<3;i++)
		printf("%s    %d\n",a[i].name,a[i].id);
	
	return 0;
}
