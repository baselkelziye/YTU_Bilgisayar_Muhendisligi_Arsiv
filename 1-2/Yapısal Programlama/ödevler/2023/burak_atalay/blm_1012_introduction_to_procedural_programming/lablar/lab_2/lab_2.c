#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 9
int main(){
    int n, a[max][max], b[max][max], i, j, k, lower, upper, betul, ayse;
    char devam;
    srand(time(0));
    do{
    	printf("matrisin boyutunu gir:\n");
    	scanf("%d", &n);
    	lower=1, upper=n*n;
    	for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j]=rand()%(upper-lower+1)+lower;
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%.2d ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		betul=ayse=0;
    	for(k=0;k<3;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					b[i][j]=a[n-1-j][i];
				}
			}
			printf("90 derece donmus hali:\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%.2d ", b[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			i=n-1;
			for(j=0;j<n;j++){
				betul+=b[i][j];
			}
			printf("betul: %d ayse: %d\n", betul, ayse);
			printf("\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					a[i][j]=b[n-1-j][i];
				}
			}
			printf("90 derece donmus hali:\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%.2d ", a[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			i=n-1;
			for(j=0;j<n;j++){
				ayse+=a[i][j];
			}
			printf("betul: %d ayse: %d\n", betul, ayse);	
			printf("\n");
		}
		if(betul>ayse) printf("betul kazandi.\n");
		else if(ayse>betul) printf("ayse kazandi.\n");
		else printf("sonuc berabere.\n");
		printf("\ndevam etmek ister misin?\n");
		scanf(" %c", &devam);
	}while(devam=='e' || devam=='E');
    return 0;
}
