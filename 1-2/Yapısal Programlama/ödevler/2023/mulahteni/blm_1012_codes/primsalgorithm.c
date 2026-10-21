#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/time.h>

double prim(int [][20],int);
int valueMST(int [],bool [],int);
void printM(int [][20],int);
void readM(int [][20],int);


int main(){
	int i,j,secim=1,count=0,size,dizi[20][20],yildiz[20],yildiz1[20];
	double zamanlar[20];
	printf(" Prim Algoritmasi");
	while(secim==1){
		printf("\n\n\t%d. Agac\n", count+1);
		printf("\n\t\tAgacta bulunan nokta sayisi = ");
		scanf("%d",&size);yildiz1[count]=size*size;// O(n*2) hesaplýyor
		readM(dizi,size);system("cls");
		printf("\n %d.Agacin matris hali...\n\n",count+1);
		printM(dizi, size);
		zamanlar[count] = prim(dizi,size);// döndürülen gerçek zamaný dizide tutuyor
		printf("\n %d. Islem boyunca gecen zaman = %lf saniye\n", count+1, zamanlar[count]);// zamaný yazdýrýyor
		yildiz[count] = (int)(zamanlar[count] * 100000);// zamaný yýldýza çeviriyor
		printf("\n 1- Yeni Agac Girisi...\n\n 2- Cikis...\n ");scanf(" %d", &secim);system("cls");
		count++;
	}
	for(i=0;i<count;i++){
		printf("\n\t\t%d. Agac", i+1);		
		printf("\n\n  O(n^2), Islem Sayisina Bagli Zamanin Yildiz Diyagrami...\n   ");
		for(j=0;j<yildiz1[i];j++){
			printf("*");
		}printf("\n  Yildiz Sayisi = %d",yildiz1[i]);
		printf("\n");
		printf("\n  Gercek Zaman = %lf saniye",zamanlar[i]);	
		printf("\n  Gercek Zamana Bagli Yildiz Diyagrami...\n   ");		
		for(j=0;j<yildiz[i];j++){
			printf("*");
		}printf("\n  Yildiz Sayisi = %d",yildiz[i]);
	}

	return 0;
}

double prim(int dizi[20][20], int size){
	int i,j,edge,path;
	int deger[20];// düðümler arasýndaki kýsa mesafeyi tutacak
	int former[20];// önceki düðümleri tutacak
	bool visited[20];
	struct timeval start,stop;
	do{
		gettimeofday(&start,NULL);// gerçek zaman sayacýný baþlatýyor
		for(i=0;i<size;i++){
			visited[i] = false;// düðümlerin hiçbiri ziyaret edilmedi
			deger[i] = INT_MAX;// tüm düðümlerin büyüklüðü
		}
		deger[0] = 0;// baþladýðýmýz düðüm
		former[0] = -1;// basladýðýmýz dügümün atasý yok
		for(path=0;path<size-1;path++){
			edge = valueMST(deger,visited,size);// en kýsa kenarý döndürüyor
			visited[edge] = true;// artýk ziyaret edilmiþ oldu	
			for(j=0; j<size; j++){		
				if(dizi[edge][j]!=0 && visited[j] == false && dizi[edge][j] < deger[j]){// düðümün varlýðýný, ziyaret edilmemiþ olmasýný, yolun daha kýsa olmasýný kontrol ediyor
					deger[j] = dizi[edge][j];// deðeri tutuyor
					former[j] = edge;// eski düðümü kaydediyor
				}
			}
		}
		gettimeofday(&stop,NULL);// gerçek zaman sayacýný durduruyor
	}while(((double)(stop.tv_usec-start.tv_usec)/1000000 + (double)(stop.tv_sec-start.tv_sec))==0.0);// gerçek zaman 0 çýkmasýn diye
	int sum=0;
	printf("\n\n\n Ilk Dugum\tSon Dugum\tUzaklik");
	for(i=1;i<size;i++){
		printf("\n\n     %d\t\t    %d\t\t   %d\n",former[i],i,deger[i]);// ilk ve gidilen düðümü, uzaklýðý yazdýrýyor
	}
	for(i=1;i<size;i++){
		sum += deger[i];// toplam uzaklýðý hesaplýyor
	}
	printf("\n Tum dugumlere ulasilabilecek en az uzaklik = %d\n",sum);// toplam uzaklýðý yazdýrýyor
	return (double)(stop.tv_usec-start.tv_usec) / 1000000 + (double)(stop.tv_sec-start.tv_sec);// zamaný döndürüyor
}

int valueMST(int deger[],bool visited[],int size){
	int i,minIndex;
	int min = INT_MAX;
	for(i=0; i<size; i++){
		if(visited[i] == false && deger[i] < min){//düðüm ziyaret edilmemiþ ve min deðerden küçük olacak
			min = deger[i];
			minIndex = i;
		}
	}

	return minIndex;//en kýsa kenarýn indexi döndürüyor
}

void printM(int dizi[20][20],int n){
	int i,j;printf(" \\");
	for(j=0;j<n;j++){
		printf("\t %d",j+1);
	}
	for(i=0;i<n;i++){
		printf("\n\n\n %d",i+1);
		for(j=0;j<n;j++){
			printf("\t %d",dizi[i][j]);
		}
	}

}

void readM(int dizi[20][20],int n){
	int i,j;
	printf("\n\t Matrisin elemanlari...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				dizi[i][j] = 0;
				printf("\t\tM[%d][%d] = %d\n",i,j,dizi[i][j]);
			}else{
				printf("\t\tM[%d][%d] = ",i,j);
				scanf("%d",&dizi[i][j]);
			}
		}
		printf("\n");
	}

}
