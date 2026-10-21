#include <stdio.h>

#define MAX 50

void fonksiyon1(int matris[][3], int N);
void fonksiyon2(int matris[][3], int N, int head);

int main() {
	
	int i, N, matris[MAX][3], head;
	
	printf("N giriniz: ");
	scanf("%d", &N);
	
	
	fonksiyon1(matris, N);
	
	printf("\nhead indisini giriniz: ");
	scanf("%d", &head);
	
	matris[head][2] = -1;
	
	printf("\nsirasiyla hangi islemin hangi oncelikte oldugunu girin: \n");
	for (i = 0; i < N; i++) {
		printf("%d birim suren \"%c\" isleminin linki: ", matris[i][1], matris[i][0]);
		scanf("%d", &matris[i][2]);
	}	
	
	fonksiyon2(matris, N, head);
	
	return 0;
}

void fonksiyon1(int matris[][3], int N) {
	int i, j, control;
	
	printf("yapilacak islerin harf kodlarini giriniz: \n");	
	i = 0;
	while (i < N) {
		printf("%d.is kodunu giriniz: ", i + 1);
		scanf(" %c", &matris[i][0]);
	
		control = 0;
		j = i - 1;
		while (j >= 0 && control == 0) {
			if ((char)matris[i][0] == (char)matris[j][0]) control = 1;
			else j--;
		}
		
		if (control == 0) i++;
	}
	
	printf("\nsirasiyla her bir islemin ne kadar surecegini giriniz: \n");
	i = 0;
	while (i < N) {
		printf("\"%c\" islemi: ", matris[i][0]);
		scanf(" %d", &matris[i][1]);
		if (matris[i][1] >= 1) i++;		
	}
	
}

void fonksiyon2(int matris[][3], int N, int head) {
	int i, j;
	
	j = head;
	while (j != -1)	{
		for (i = 0; i < matris[j][1]; i++) {
			printf("%c ",matris[j][0]);
		}
		j = matris[j][2];
	}	
}
