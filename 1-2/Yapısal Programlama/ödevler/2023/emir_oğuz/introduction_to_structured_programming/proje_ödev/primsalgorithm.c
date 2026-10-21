#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/time.h>
#define N 20

// Graf yapisini kullanicidan matris seklinde alan fonksiyon
void readMatrix(int graph[N][N], int size)
{
	int i, j;
	
	printf("\nBir matris olusturacak sekilde graf uzerindeki mesafeleri giriniz...\n");
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			
			if(i < j){
				printf("- Eleman[%d][%d] = ", i, j);
				scanf("%d", &graph[i][j]); 
			}
			else if(i == j){
				graph[i][j] = 0; // Kosegen degerleri sifira esitlenir.
				printf("- Eleman[%d][%d] = %d\n", i, j, graph[i][j]);
			}
			else{
				graph[i][j] = graph[j][i]; // Kullanicinin girdigi elemanlarin degerleri, matris kosegenine gore simetrik olan elemanlara esitlenir.
				printf("- Eleman[%d][%d] = %d\n", i, j, graph[i][j]);
			}
		}
		
		printf("\n");
	}
}

// Kullanicinin girdigi matrisi yazdiran fonksiyon
void printMatrix(int graph[N][N], int size)
{
	int i, j;
	
	for(j=0; j<size; j++){
		printf("\t(%d)", j); // Sutun numaralari yazdirilir.
	}
	
	for(i=0; i<size; i++){
		printf("\n\n\n(%d)", i); // Satir numaralari yazdirilir.
		
		for(j=0; j<size; j++){
			printf("\t %d", graph[i][j]); // Matrisin elemanlari yazdirilir.
		}
	}
}

// En kisa mesafeyi ve bu mesafenin bitis noktasindaki indeksi bulan fonksiyon
int valueMST(int pathValue[], bool visited[], int size)
{
	int i, minIndex;
	int min = INT_MAX;
	
	for(i=0; i<size; i++){
		
		if(visited[i] == false && pathValue[i] < min){
			min = pathValue[i]; // "min" degiskenine guncel olan en kisa mesafe degeri atanir.
			minIndex = i; // "minIndex" degiskenine en kisa mesafeye sahip olan indeks degeri atanir.
		}
	}
	
	return minIndex;
}

// Gidilen yolda, baslangic-bitis dugumlerini ve mesafeyi yazdiran fonksiyon
void printMST(int parent[], int pathValue[], int size)
{
	int i, sum = 0;
	
	printf("\n\n\n Dugumler\tMesafe");
	for(i=1; i<size; i++){
		printf("\n\n %d ---> %d\t  %d\n", parent[i], i, pathValue[i]); // Sirasiyla baslangic, bitis ve mesafe degerleri yazdirilir.
	}
	
	for(i=1; i<size; i++){
		sum += pathValue[i]; // Mesafe degerleri toplanir, toplam mesafe bulunur.
	}
	
	printf("\nToplam mesafe = %d\n", sum);
}

// Prim Algoritmasi'nin islendigi fonksiyon
int primsAlgorithm(int graph[N][N], int size)
{
	int i, j, node, path, counter = 0;
	int pathValue[N], parent[N]; // "pathValue" dizisi, yol degerlerini tutar, "parent" dizisi, guncel indeksteki dugumun ata dugumunu tutar.
	bool visited[N]; // "visited" dizisi, dugumlerin ziyaret edilip edilmedigi bilgisini tutar.
	
	for(i=0; i<size; i++){
		visited[i] = false; // Baslangic icin tum dugumlerin ziyaret bilgisine '0' degeri atanir.
		pathValue[i] = INT_MAX; // Baslangic icin tum yol degerlerine en buyuk tam sayi degeri atanir.
	}
	
	pathValue[0] = 0; // Tepe noktasi olan '0' dugumunun yol degerine '0' atanir. Cunku burasi baslangic noktasidir.
	parent[0] = -1; // Tepe noktasi olan dugumun ata dugumu olamaz. Bu nedenle bu noktanin ata dugum degerine '-1' atanir.
	
	for(path=0; path<size; path++){
		node = valueMST(pathValue, visited, size); // "valueMST" fonksiyonu cagirilir. "node" degiskenine fonksiyonun dondurdugu "minIndex" degeri atanir.
		visited[node] = true; // "node" degerine atanan dugum numarasinin ziyaret bilgisine '1' degeri atanir.
		
		for(j=0; j<size; j++){
			counter++; // Zaman karmasikligi icin ic ice dongulere giris sayisi hesaplanir.
			
			if(graph[node][j] != 0 && visited[j] == false && graph[node][j] < pathValue[j]){
				pathValue[j] = graph[node][j];
				parent[j] = node;
			}
		}
	}
	
	printMST(parent, pathValue, size);
	
	return counter;
}

int main()
{
	int i, j, choice = 1, process = 0, size, graph[N][N], star[N], complexity[N];
	double time[N];
	struct timeval start, stop;
		
	while(choice == 1){
		system("cls");
		
		printf("--> PRIM ALGORITMASI");
			
		printf("\n\n--> %d. ISLEM\n\n", process + 1);
		printf("Graf uzerinde bulunan dugum (nokta) sayisini giriniz: ");
		scanf("%d", &size);
	
		readMatrix(graph, size);
	
		printf("\nGirdiginiz graf yapisinin matris hali:\n\n");
		printMatrix(graph, size);
	
		gettimeofday(&start, NULL);
		complexity[process] = primsAlgorithm(graph, size);
		gettimeofday(&stop, NULL);
	
		time[process] = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		printf("\n%d. Islem icin Prim Algoritmasi'nin baslatilmasindan sonlanmasina kadar gecen sure: %lf saniye\n", process + 1, time[process]);
		star[process] = (int)(time[process] * 15000);
		
		printf("\n1) ISLEME BASTAN BASLA");
		printf("\n2) CIKIS");
		printf("\n\nSeciminiz: ");
		scanf("%d", &choice);
		
		process++;
	}
	
	for(i=0; i<process; i++){
		printf("\n%d. COZUM", i + 1);
		printf("\n- Sure: %lf saniye", time[i]);
		
		printf("\n- Sayaca Bagli Yildiz Gostergesi (N^2): ");
		for(j=0; j<complexity[i]; j++){
			printf("*");
		}
		printf(" (%d Yildiz)", complexity[i]);
		
		printf("\n- 'gettimeofday()' Fonksiyonuna Bagli Sapka Gostergesi: ");
		for(j=0; j<star[i]; j++){
			printf("^");
		}
		printf(" (%d Sapka)", star[i]);
		
		printf("\n");
	}
	
	getch();
	
	return 0;
}

