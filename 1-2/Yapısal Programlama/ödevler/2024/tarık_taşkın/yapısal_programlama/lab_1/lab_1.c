#include <stdio.h>
void enler(int dizi[], int N);
void sirala(int dizi[],int N);

int main(){
    int N;
    int dizi[100];
    int i;

    printf("Dizinin boyutunu giriniz: ");
    scanf("%d",&N);
    
    if(N<6){
        do{
            printf("Dizinin boyutu 6'dan buyuk olmalidir.\n");
            printf("Dizinin boyutunu tekrar giriniz: ");
            scanf("%d",&N);
        }while(N<6);
    }

    for(i=0;i<N;i++){
        printf("%d. ogrencinin notunu giriniz: ",i+1);
        scanf("%d",&dizi[i]);

    }

    sirala(dizi,N);
    
    for(i=0;i<N;i++){
    	printf("%d ",dizi[i]);
	}
	printf("\n");
    
    enler(dizi,N);

    return 0;
}

void sirala(int dizi[],int N){
    int i,j;
    int temp;

    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(dizi[j]>dizi[j+1]){
                temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }

}

void enler(int dizi[], int N){
    int toplam;
    toplam = dizi[N-1] + dizi[N-2] + dizi[N-3];
    printf("En buyuk 3 elemanin toplami: %d\n",toplam);
    printf("En buyuk uc eleman: %d , %d , %d\n",dizi[N-1],dizi[N-2],dizi[N-3]);
    toplam = dizi[0] + dizi[1] + dizi[2];
    printf("En kucuk 3 elemanin toplami: %d\n",toplam);
    printf("En kucuk uc eleman: %d , %d , %d\n",dizi[0],dizi[1],dizi[2]);
}
