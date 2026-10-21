#include <stdio.h>
#include <stdlib.h>
#include <time.h>//rasgele matris oluşturmak için kullanıldı

/*
	Dosyadan inputları okuyarak matris için hafızada yer açar.
	Matrisi ve uzunluğu döndürür.
	Uzunluğu döndürme işlemi parametre pointer üzerinden yapılır.
	
	@param1 int *   : Uzunluğu geri döndürmek için kullanılacak pointer paramaetre
	@return int **  : Okunan matrisi geri döndürür.
*/
int** getInputs(int *);
/*
	Verilen diziyi 1 adım sağa kaydırır.
	
	@param 1 int *  : Kaydırılacak dizi.
	@param 2 int 	: Dizinin boyutu.
*/
void slideToRight(int *,int);
/*
	Verilen satırın üstteki satırlarla çakışıp çakışmadığı bilgisini döndürür.
	Çakışma varsa 0 yoksa 1 döner.
	
	@param 1 int ** : Kontrolün yapılacağı kare matris
	@param 2 int    : Kare marisin satır uzunluğu
	@param 3 int    : Kontrolün yapılacağı satır adresi
	@return char    : Çakışma olup olmadığı bilgisi döndürülür.
*/
char isPosAvaliable(int **,int,int);
/*
	Recursive backtrack algoritması.
	Algoritma, satır numarası [0,size) arasında olduğu sürece devam eder.
	Eper slide parametresi(@param5) 1 ise kaydırma yapılır.
	Bu algoritmada her satırda kaç kaydırma yapıldığını tutan bir dizi kullandım.(slideCount)
	Satır numarasını colIndex değişkeni tutuyor.
	Algoritmanın akışı : 
		1.Ilk satırdan başlanır, eğer uzunluk kadar kaydırma yapıldıysa kaydırma sayısı sıfırlanır ve bir üst satıra gidilir.
		2.Eğer kaydırma sayısı sona ulaşmadıysa(tüm olasılıklar denenmediyse) ve satırın şu anki durumu üsttekilerle çakışıyorsa bulunan satır kaydırılır.
		3.Eğer kaydırma sayısı sona ulaşmadıysa ve satırın şu anki durumu üsttekilerle çakışmıyorsa sonraki satıra geçilir.
	
	@param1 int ** : Algoritmanın uygulanacağı matris.
	@param2 int *  : Satırların kaydırılma sayılarını tutan dizi.
	@param3 int    : Matrisin satır uzunluğu.
	@param4 int    : Aktif satır indexi.
	@param5 char   : Matrisin o satırının kaydırılıp kaydırılmayacağı bilgisini tutar.
	@return char   : Uygun pozisyon oluşturulup oluşturulmadığı blgisini döner
*/
char backTrack(int **,int *,int,int,char);
/*
	Backtrack algoritması çalıştırılmadan önce yapılması gereken işlemleri yapar.
	Her satırın kaydırma sayısı için kullanılacak diziyi tanımlar ve backtrack algortimasını çalıştırır.
	
	@param1 int **  : Backtrack uygulanacak kare matris
	@param2 int     : Kare matrisin satır uzunluğu
	@return char    : Uygun pozisyon oluşturulup oluşturulmadığı blgisini döner(recursive backtrack algoritmasından dönen değer)
*/
char runBackTrack(int **,int);
/*
	Verilen diziyi ekrana yazdırır.
	
	@param1 int*  : Ekrana yazdırılacak dizi.
	@param2 int   : Ekrana yazdırılacak dizinin boyutu.
*/
void printArr(int *,int);
/*
	Verilen kare matrisi ekrana yazdırı.
	
	@param1 int**  : Ekrana yazdırılacak kare matris
	@param2 int    : Ekrana yazdırılacak kare matrisin satır uzunluğu
*/
void printMtr(int **,int);
/*
	Bu fonksiyonun asıl kodla bir ilgisi yoktur.Farklı inputları denemek ve hataları bulmak için kullanılmıştır.
	Kare matris uzunluğunu kullanarak her satırda 1,N arasında değerler olacak şekilde rastgele bir matris oluşturur.
	(1,2,3,4,....,N) şeklinde bir dizi oluşturur daha sonra her satır için 1,N arası bir index seçer ve o indexteki değeri satırın istenen sırasına koyar 
	daha sonra seçilen değeri sonuncuyla değiştirerek N değerini 1 azaltır ve o satırdaki tüm sıralar için bunu uygular sonunda 1,N arası elemanlar 
	farklı sırada o satıra eklenmiş olur.
	
	@param1 int** : Rasgele değerlerin oluşturulacağı kare matris.
	@param2 int   : Kare matrisin satır uzunluğu.
*/
void createRandomInput(int **,int);


int main(){
    int **mtr;//renk kodlarının tutulduğu kare matris
    int n;//renk kodlarının tutulduğu kare matrisin satır uzunluğu
    char result;//backtrack sonucu dönecek değeri tutan değişken(1 veya 0)
    //srand(time(NULL));//bu bölüm random matris oluşturmak için kullanıldı asıl program için gereksiz
    printf("Getting Inputs From input.txt\n");
    mtr = getInputs(&n);
    if(n < 3 || n > 8){
    	printf("N must be beetwen [3,8]\n");
    	return 0;
    }
    printf("N : %d\n",n);
    printf("----------COLOR MATRIX--------\n");
    printMtr(mtr,n);
    result = runBackTrack(mtr,n);
    if(result){
    	printf("MATRIX FINDED WITH BACKTRACKING\n");
    	printMtr(mtr,n);
    }
    else
    	printf("MATRIX COULDN'T FINDED\n");
    return 0;
}
int** getInputs(int *n){
    int **mtr;//renk kodlarının tutulduğu kare matris
    FILE *file = fopen("input.txt","r");//inputların alınacağı dosya
    fscanf(file,"%d",n);
    mtr = (int**)malloc(sizeof(int*)*(*n));
    for(int i = 0;i < *n;i++)
        mtr[i] = (int*)malloc(sizeof(int)*(*n));
    
    for(int i = 0;i < *n;i++){
        for(int j = 0;j < *n;j++){
        	fscanf(file,"%d",&mtr[i][j]);    
        }
    }

    fclose(file);
    return mtr;
}

void slideToRight(int *mtr,int size){
	int lastOne = mtr[size-1];//kaydırma işleminde dizideki son karakteri tutan değer.
	for(int i = size-1;i > 0;i--)
		mtr[i] = mtr[i-1];
	mtr[0] = lastOne;
}

char runBackTrack(int **mtr,int size){
	int slideCount[size];//Belirlenen satırda kaç kaydırma işlemi yapıldığı bilgisini tutan dizi.
	for(int i = 0;i < size;i++)
		slideCount[i] = 0;
	return backTrack(mtr,slideCount,size,0,0);
}

char backTrack(int **mtr,int *slideCount,int size,int colIndex,char slide){
	if(colIndex < 0)
		return 0;
	else if(colIndex >= size)
		return 1;
	if(slide){
		slideCount[colIndex]++;
		slideToRight(mtr[colIndex],size);
	}
	if(slideCount[colIndex] >= size){
		slideCount[colIndex] = 0;	
		return backTrack(mtr,slideCount,size,colIndex-1,1);		
	}
	else if(isPosAvaliable(mtr,colIndex,size))
		return backTrack(mtr,slideCount,size,colIndex+1,0);		
	else
		return backTrack(mtr,slideCount,size,colIndex,1);
	return 1;
}

char isPosAvaliable(int **mtr,int colIndex,int size){
	int i = 0;//satır sayısını takip etmek için kullanılacak indis
	int j = 0;//sütun sayısını takip etmek için kullanılacak indis
	char sameFinded = 0;//kontrol sırasında aynı sayıların aynı satırda olup olmadığını tutan değişken
	while(j < size && !sameFinded){
		i = 0;
		while(i < colIndex && !sameFinded){
			sameFinded = (mtr[i][j] == mtr[colIndex][j]);
			i++;
		}
		j++;
	}
	return !sameFinded;
}


void printArr(int *arr,int size){
	for(int i = 0;i < size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void printMtr(int **mtr,int size){
    printf("---------------------\n");
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            printf("%d ",mtr[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void createRandomInput(int **mtr,int size){
	int exampleMtr[size];//1 den N e kadar sayıların tutulduğu dizi
	int tmpSize;//exempleMtr nin uzunluğunu satır içinde tutar
	int rndIndex;//bulunan random index
	int swap;//swap işlemi için kullanılacak değişken
	for(int i = 0;i < size;i++)
		exampleMtr[i] = i+1;
	for(int i = 0;i < size;i++){
		tmpSize = size;
		for(int j = 0;j < size;j++){
			rndIndex = rand()%tmpSize;
			mtr[i][j] = exampleMtr[rndIndex];
			//sonuncuyla swapla 
			swap = exampleMtr[tmpSize-1];
			exampleMtr[tmpSize-1] = exampleMtr[rndIndex];
			exampleMtr[rndIndex] = swap; 
			//sonuncuyu kullanmamak için geçici dizi boyutu indexini 1 küçült
			tmpSize--;
		}
	}
}