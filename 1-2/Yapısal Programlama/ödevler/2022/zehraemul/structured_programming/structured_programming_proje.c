#include<stdio.h>
#include<time.h>
#define SIZE 30

//Degiskenleri tanimliyorum.

int b[SIZE][SIZE],queue[SIZE],visited[SIZE],n,i,j,front=0,back=-1;

//Bfs algoritmasinin fonksiyonunu olusturuyorum.

void bfs(int v) {
	for (i=1;i<=n;i++)
	  if(b[v][i] && !visited[i])
	   queue[++back]=i;
	if(front<=back) {
		visited[queue[front]]=1;
		bfs(queue[front++]);
	}
}
int main() {
	
		
	//Zaman analizini yapmak icin programin baslangic saatini ayarliyorum.
	
	clock_t baslangic,bitis;
	baslangic=clock();
	
	int v;
	
	//kose sayisini kullanicidan aliyorum.
	
	printf("\n enter the number of vertices \n");
	scanf("%d",&n);
	
	//iki adet n'lik bos dizi tanimliyorum.
	
	for (i=1;i<=n;i++) {
		queue[i]=0;
		visited[i]=0;
	}
	
	//Grafin matrisini komsuluk matris olacak sekilde kullanicidan aliyorum.
	//Komsuluk matris: Dugumlerden dugume baglantiyi gosteren bir kare matristir.
	
	printf("\n enter the values of the graph in adjacency  matrix form: \n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&b[i][j]);
	   
	//Baslangic dugumunu kullanicidan aliyorum.
	   
	printf("\n enter the starting node \n");
	scanf("%d",&v);
	
	//Bfs fonksiyonunu cagiriyorum.

	bfs(v);
	
	//Ulasilabilir dügümleri yazdiriyorum.
	
	printf("\n  accessible nodes: \n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d\t\n",i); else
	   printf("\n  Bfs is not possible \n");
	   
	//Yine zaman analizinde kullanmak adina programin bitis saatini alip calisma suresini hesapliyorum.
	   
	bitis=clock();
	
	//Calisma suresini yazdiriyorum.
	
	printf("Run time =%f:\n",((float)(bitis-baslangic)/CLOCKS_PER_SEC));
	return 0;

}
