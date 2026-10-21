#include<stdio.h>
#include<stdlib.h>

void print_intmat(int **,int);
void print_colormat(int **,char*,int);
int** hesapla(int**,int,int,int,int);
int** satir_kaydir(int**,int,int);
	
int main(){
	
	int i,j,N;
	char renkler[8][11]={"sari","mavi","yesil","kirmizi","beyaz","mor","acikmavi","siyah"};
	printf("kac renk gireceksiniz? 3-8 arasinda bir sayi giriniz :");
	scanf("%d",&N);
	
	int **mat = (int **)malloc(N * sizeof(int*));  
	for(i = 0; i < N; i++){
		mat[i] = (int *)malloc(N * sizeof(int));  	// oyun matrisimiz icin alan ayirdik
	}

	
	printf("renk matrisini giriniz \nrenkleri sayi karsiliklari ile giriniz \n");
	for(i=0;i<N;i++){
		printf("%d ---> %s  \n",i,renkler+i);
	}
	
	printf("her bir satirda hucreleri bosluklar koyarak tek seferde giriniz \n");
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);	// kullaniciden renkleri aliyoruz
		}
	}
	
	printf("girilen matris:  \n");
	
	print_colormat(mat,(char*)renkler,N); // girilen matrisi ekrana yazdiriyoruz
	printf("\n\n");
	
	mat=hesapla(mat,1,0,N,0); // girilen matrisi fonksiyona gonderiyoruz
	if(mat!=NULL){		// fonksiyondan donen deger null degil ise uygun bir sonuc var demektir
		printf("Sonuc bulundu  \n Sonuc matrisi: \n");
		print_intmat(mat,N);
		printf("\n");
		print_colormat(mat,(char*)renkler,N);
	}
	else{
		printf("Sonuc bulunamadi \n");
	}

	printf("\n\n\n\n\n\n\n");
	return 0;
}


void print_colormat(int **mat,char* renkler,int size){
	int i,j;	//renkleri isimleri ile yazdirabilmek icin
				// fonksiyona renk char matrisini de gonderiyoruz

	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			int renk=mat[i][j];
			printf("%s", (renkler)+11*renk); //renk matrisin
			printf("\t");		// 8*11 boyutlu oldugu icin							
		}					//uygun renge erismek icin 11 ile carp
		printf("\n");
	}
}

void print_intmat(int **mat,int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}


int** hesapla(int** mat,int row,int col,int size,int shift_sayac){
			//parametreler; 1: matrisin adresi, 2: satir indisi 3:sutun indisi:
					// 4:matris boyutu(girilen renk sayisi)  5: kullanici 
					// ayni rengi birden fazla girmisse sonsuz shift etmek icin
	
	if((row==size-1)&&(col==size-1)&&(mat[row][col]!=mat[row-1][col])){
		return mat;  // bu blok en sag en alt hucreye sorunsuz geldigimizde
	}			//calisacak ve bulunan matris sonuc matrisimiz olarak donecek
	
	else if(mat==NULL){
		return NULL;	//backtrace ederken matrisi bir yerde
							// null olarak dondurduysek bu, matrisin sarti
							// saglamadigi anlamina geliyor. null done done ilk 
	}						//cagrildigimiz duruma kadar gelip fonksiyondan cikiyoruz
	else if((col==size-1)&&(row!=size-1)){ //kontrolde satir sonuna geldik ise
		int next_onay=0,i=0; //for dongusunde next_onay degiskeninin
		for(i=0;i<=row-1;i++){ // durumu belli olacak
			if(mat[i][col]==mat[row][col]){ //onceki satirlarda ayni sutunda 
				next_onay=0; 	 //ayni sayi varsa bu siralama 
				break;  //ile bir sonraki satira gecemeyiz
			}
			else{
				next_onay=1;  //bu siralama uygun ise next_onay=1 
			}
		}
		if(next_onay==1){ 
			print_intmat(mat,size);  // uygun siralamada matrisin durumu yazdirildi
			return hesapla(mat,row+1,0,size,0);  //sonraki satira gecmek icin
		}									//return olarak ayni fonksiyon, satir
							//degeri 1 arttirilarak ve sutun=0 lanarak cagrildi
		else{
			if(shift_sayac<size-1){
				mat=satir_kaydir(mat,row,size); //siralama uygun olmadigi icin satir kaydirildi
				shift_sayac++;  //ayni renkten birden fazla girme durumu varsa diye sayac arttirildi
				return hesapla(mat,1,0,size,shift_sayac);  //satir kaydirildiktan sonra 
												// kontrol icin fonksiyon tekrar cagrildi
			}
			else
				return NULL;
		}
	}
	else if((col!=size-1)&&(row!=size)){  //satir sonu hucresinde degil isek
		
		int next_onay=0,i=0;
		for(i=0;i<=row-1;i++){
			if(mat[i][col]==mat[row][col]){  //ust satirdaki cakismalar kontrol edildi
				next_onay=0;
				break;
			}
			else{
				next_onay=1;
			}
		}
		if(next_onay==1){   // hucrede cakisma yok, bi sonraki hucreye gecildi
			return hesapla(mat,row,col+1,size,shift_sayac);  //fonksiyon bir sonraki 
												//sutun indisi ile cagrildi
		}
		else{
			if(shift_sayac<size-1){
				mat=satir_kaydir(mat,row,size); //cakisma var, satiri kaydir
				shift_sayac++;
				return hesapla(mat,row,0,size,shift_sayac); //kaydirdiktan sonra fonk.
									//ayni satir indisi ile tekrar cagir
			}
			else 
				return NULL;		//ayni renk girilme durumunda maks shift sayisina 
								//ulasildi ve null donduruldu
		}
	}
}


int** satir_kaydir(int** mat,int row,int size){
	int i;
	int tmp=mat[row][size-1];		//satirdaki en sagdaki hucre temp'e alindi
	for(i=size-1;i>0;i--){			//size-1 e kadar olan tum hucreler saga 1 shift edildi
		mat[row][i]=mat[row][i-1];	
	}
	mat[row][0]=tmp;		//en sagdaki hucre en basa atandi
	return mat;			//matrisin bu hali return degeri olarak donduruldu
}