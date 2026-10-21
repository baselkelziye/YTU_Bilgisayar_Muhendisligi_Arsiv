#include<stdio.h>
#include<stdlib.h>

int** satir_ekle(int** matris,int* satir_sayisi,int sutun_sayisi);
void matrisi_yazdir(int** matris,int satir);
void matrisi_free(int** matris,int satir);
int hacim_hesapla(int g,int y,int u);
void urun_ekle(int** matris,int* satir,int sutun,int g,int y,int u);

int main(){
	int sutun=4;
	int **matris;
	int max,toplam=0,flag=0,hacim;
	int satir=0;
	int i,x,y,z;

	printf("Maximum depo kapasitesi giriniz:");
	scanf("%d",&max);

	matris=NULL;

	while(toplam<=max&&flag==0){
		printf("genislik:");
		scanf("%d",&x);
		printf("yukseklik:");
		scanf("%d",&y);
		printf("uzunluk:");
		scanf("%d",&z);

		hacim=hacim_hesapla(x,y,z);
		if(toplam+hacim>max){
			flag=1;
		}else{
			urun_ekle(matris,&satir,sutun,x,y,z);
			toplam=toplam+hacim;
			printf("Paketin kapladigi toplam hacim:%d\n",toplam);
		}
	}

	if(flag==1){
		printf("Gunluk siparis limitiniz dolmustur:\n\ndepoda bulunan paketler:\n");
	}

	matrisi_yazdir(matris,satir);
	matrisi_free(matris,satir);

	return 0;
}

int** satir_ekle(int** matris,int* satir_sayisi,int sutun_sayisi){
	int** yeni_matris;
	yeni_matris=(int**)realloc(matris,(*satir_sayisi+1)*sizeof(int*));
	if(yeni_matris==NULL){
		printf("Bellekte yer ayrilamadi");
		exit(-1);
}

yeni_matris[*satir_sayisi]=(int*)malloc(sutun_sayisi*sizeof(int));
	if(yeni_matris[*satir_sayisi]==NULL){
printf("Bellekte yer ayrilamadi");
exit(-1);
}

*satir_sayisi=*satir_sayisi+1;
return yeni_matris;
}

int hacim_hesapla(int x,int y,int z){
return x*y*z;
}

void urun_ekle(int** matris,int* satir,int sutun,int g,int y,int u){
int i=0;
int bulundu=0,bayrak=0;

while(i<*satir&&bayrak==0){
if(*(*(matris+i))==g&&*(*(matris+i)+1)==y&&*(*(matris+i)+2)==u){
*(*(matris+i)+3)=*(*(matris+i)+3)+1;
bulundu=1;
bayrak=1;
}
i++;
}

if(bulundu==1){
matris=satir_ekle(matris,satir,sutun);
if(matris==NULL){
printf("Satir eklenemedi.\n");
exit(-1);
}

*(*(matris+*satir-1))=g;
*(*(matris+*satir-1)+1)=y;
*(*(matris+*satir-1)+2)=u;
*(*(matris+*satir-1)+3)=1;
}
}

void matrisi_yazdir(int** matris,int satir){
	int i;
	for(i=0;i<satir;i++){
	printf("(%d,%d,%d)-%d\n",*(*(matris+i)),*(*(matris+i)+1),*(*(matris+i)+2),*(*(matris+i)+3));
	}
}

void matrisi_free(int** matris,int satir){
	int i;
	for(i=0;i<satir;i++){
	free(*(matris+i));
	}
	free(matris);
}

