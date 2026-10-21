// M.Ali Bugday
// Date created: 05.05.2022
// Date modified: 10.05.2022

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct baglanti{
	int first_node;
	int second_node;
	int mesafe;
}BAGLANTI; 

int flag=0;
int minimum=999;

void kruskal(int n, int matrix[][n]);
int find(int i, int n, int label[n]);
int uni(int i,int j, int n, int label[n]);
void print(int n, int matrix[][n]);
void depthFirstSearch(int n, int matrix[][n], int start, int marked[n], int edgeTo[n], int eklenecek, int ikinci_nokta);
void pathTo(int n, int marked[n], int edgeTo[n], int aranan);

int main() {
	int i, j, n, max=-1000;
	
	printf("Baglanti sayisini giriniz: ");
	scanf("%d",&n);	

	struct baglanti *dizi = (BAGLANTI*)malloc((n+1)*sizeof(BAGLANTI));
	
	for(i=0;i<n;i++){
		printf("baglantinin oldugu birinci noktayi giriniz: ");
		scanf("%d",&dizi[i].first_node);
		printf("baglantinin oldugu ikinci noktayi giriniz: ");
		scanf("%d",&dizi[i].second_node);
		
		if(max < dizi[i].first_node){
			max = dizi[i].first_node;
		}
		if(max < dizi[i].second_node){
			max = dizi[i].second_node;
		}
		
		printf("iki nokta arasindaki mesafeyi giriniz: ");
		scanf("%d",&dizi[i].mesafe);	
	}
	
	max+=1;
	
	int marked[max], edgeTo[max];
	for(i=0;i<max;i++){
		marked[i]=0;
		edgeTo[i]=0;
	}
	
	int matrix[max][max], directedMatrix[max][max];
	
	for (i = 0; i < max; i++){
  		for (j = 0; j < max; j++){
			matrix[i][j] = 999;
			directedMatrix[i][j] = 999;  			
		}
	}
	
	for(i=0;i<n;i++){
		matrix[dizi[i].first_node][dizi[i].second_node] = dizi[i].mesafe;
		matrix[dizi[i].second_node][dizi[i].first_node] = dizi[i].mesafe;
		directedMatrix[dizi[i].first_node][dizi[i].second_node] = dizi[i].mesafe;
	} 
	
	print(max, matrix);
	
	printf("Ekleneck baglantinin  birinci noktasini giriniz: ");
	scanf("%d",&dizi[n].first_node);
	printf("Eklenecek baglantinin ikinci noktasini giriniz: ");
	scanf("%d",&dizi[n].second_node);
	printf("iki nokta arasindaki mesafeyi giriniz: ");
	scanf("%d",&dizi[n].mesafe);
	
	matrix[dizi[n].first_node][dizi[n].second_node] = dizi[n].mesafe;
	matrix[dizi[n].second_node][dizi[n].first_node] = dizi[n].mesafe;
	directedMatrix[dizi[n].first_node][dizi[n].second_node] = dizi[n].mesafe;
	
	//print(max, directedMatrix);
	
	for(i=0;i<max;i++){
		flag=0;
		minimum=(-999);
		for(j=0;j<max;j++){
			marked[j] = 0;
		}
		depthFirstSearch(max, directedMatrix, i, marked, edgeTo, dizi[n].mesafe, dizi[n].second_node);
	
	}
		
	
	kruskal(max, matrix);
	
	return 0;
}


void depthFirstSearch(int n, int matrix[][n], int start, int marked[n], int edgeTo[n], int eklenecek, int ikinci_nokta){
	int i,j;
	
	marked[start] = 1;
	i=start;
	for(j=0;j<n;j++){
		if(matrix[i][j]!=999){
			if(!marked[j]){
				edgeTo[j]=i;
				flag++;
				if(minimum < matrix[i][j]){
					if(i > ikinci_nokta){
						//pass
					}
					else{
						minimum = matrix[i][j];	
					}
					
				}
				depthFirstSearch(n, matrix, j, marked, edgeTo, eklenecek, ikinci_nokta);
			}
			else{
				if(flag>0){
					if(eklenecek >= minimum){
						//pathTo(n, marked, edgeTo, j);
						printf("\neklenecek eleman cycledaki tüm elemanlardan buyuk, kruskal calistirilmadi. ");	
						exit(0);	
					}
					//flag=0;
				}
			}
		}
	}
}


void pathTo(int n, int marked[n], int edgeTo[n], int aranan){
	int x;
	printf("\n");
	if(!marked[aranan]){
		printf("aranan sayiya yol bulunamadi");
		exit(0);
	}
	for(x=aranan;x!=0;x=edgeTo[x]){
		printf("%d-",x);
	}
	
}


void kruskal(int n, int matrix[][n]){
	int i, j, u, v, a, b, s=0, mincost=0, label[n], min;
	
	for(i=0;i<n;i++){
		label[i] = 0;
	}
	
	
	
	while(s < n-2)
	{
		
		for(i=0,min=999;i<n;i++)
		{
			
			for(j=0;j < n;j++)
			{
				
				if(matrix[i][j] < min)
				{
					min=matrix[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u, n, label);
		v=find(v, n, label);
		if(uni(u,v, n, label))
		{
			printf("%d inci baginti: %d----%d-->%d\n",s++,a,b,min);
			mincost +=min;
		}
		matrix[a][b]=matrix[b][a]=999;
	}
	printf("\nmincost:%d",mincost);
		
}

int find(int i, int n, int label[n])
{
	while(label[i])
	i=label[i];
	return i;
}
int uni(int i,int j, int n, int label[n])
{
	if(i!=j)
	{
		label[j]=i;
		return 1;
	}
	return 0;
}


void print(int max, int matrix[][max]){
	int i, j;
	
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%d-",matrix[i][j]);
		}
		printf("\n");
	}
}

