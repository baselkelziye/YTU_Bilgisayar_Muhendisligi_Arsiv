#include <stdio.h>
#include <stdlib.h>
#define N 10

int solvable(int, int[], int);//rek�rsif fonksiyonun imzas�
int main(){
	srand(time(NULL));
	int LeapCount[N] = {3,6,4,1,3,4,2,5,3,0};//{3,1,2,3,0};
	
	//Dizi konsol ekran�ndan girilmek istenirse
	/*printf("Diziyi giriniz : \n");
	int i;int LeapCount[N];
	for(i = 0; i < N; i++ ){
		scanf("%d",&LeapCount[i]);
	}*/
	
	solvable(0,LeapCount,N);//ba�lang�� olarak dizinin 0. indisinden ba�lad�k
	return 0;
}

int solvable(int start, int leapCount[], int n){
	//printf("%d ",start);
	printf("%d ",leapCount[start]);
	if( start == n-1 )//leapCount[start] == 0
		return 1;
	else{
		if( start - leapCount[start] < 0 ){//sola gitmesi imkans�z ise mecbur sa�a gidecek
			solvable(start + leapCount[start],leapCount,n);//sa�a git
			return 0;
		}
		else if( start + leapCount[start] > n-1 ){//sa�a gitmesi imkans�z mecburen sola y�nlendir
			solvable(start - leapCount[start],leapCount,n);//sola git
			return 0;
		}
	}
	//return 0;
	
	int ciftyon = rand() % 2;
	if( ciftyon == 0 ){//sola git
		start = start - leapCount[start];
		solvable(start,leapCount,n);
		return 0;
	}
	else{//sa�a git
		start = start + leapCount[start];
		solvable(start,leapCount,n);
		return 0;
	}
	//printf("%d ",start);	
}

