#include<stdio.h>
#include<time.h>
#define MAX 300
int main() {
	
	int i, j, k, m, N, deger, ayse_puan=0, betul_puan=0, puan=0;
	char cevap;
	int matris[MAX][MAX];
	int temp[MAX][MAX];
	srand(time(NULL));
	
	do{
		printf("Lutfen N degerini giriniz: ");
		scanf("%d",&N);
		
		//maatris rastgele dolum;
		
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				
				deger = rand()%(N*N);
				matris[i][j] = deger;
			}
			printf("\n");
		}
		
		printf("ilk hali:\n");
		for(i=0; i<N; i++){
				for(j=0; j<N; j++){
				
				printf("%d",matris[i][j]);
				}
				printf("\n");
			}
		printf("\n");
		
		
		ayse_puan= 0;
		betul_puan= 0;
		
		//puanlarý hesaplama,matrisi 90derece dondurme
		for(m=0;m<6;m++){
			
			puan=0;
			
			for(i=0;i<N;i++){
				
        		for(j=0;j<N;j++){
        			
            		temp[j][N-i-1] = matris[i][j];
        		}
			}
			
			printf("90 derece donmus hali:\n");
			for(i=0; i<N; i++){
				
				for(j=0; j<N; j++){
				
					printf("%4d",temp[i][j]);
				}
				printf("\n");
			}
		
			for(i=0;i<N;i++){
				
        		for(j=0;j<N;j++){
        			
            		matris[i][j] = temp[i][j];
            		
					if(i==N-1){
            			puan+=matris[i][j];
					}
        		}
			}
			
			if(m%2 == 0){
				betul_puan+=puan;
			}else{
				ayse_puan+=puan;
			}
			
			printf("\nBetul: %d      Ayse:  %d\n",betul_puan, ayse_puan);
		
		}
		
		if(betul_puan>ayse_puan){
			printf("Betul Kazandi\n");
		}else if(betul_puan==ayse_puan){
			printf("berabere\n");
		}else{
			printf("Ayse Kazandi\n");
		}
		
		
		printf("Devam etmek istiyorsanýz 'e' veya 'E' giriniz\n");
		scanf(" %c",&cevap);
		
	}while(cevap == 'e' || cevap == 'E');
	
	return 0;
}
