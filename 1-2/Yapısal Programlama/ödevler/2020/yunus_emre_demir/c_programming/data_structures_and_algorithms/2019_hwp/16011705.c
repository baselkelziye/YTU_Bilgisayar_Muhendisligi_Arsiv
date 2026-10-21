#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2415

char *kelimeDizisi[SIZE];							//dosyadan okunan kelimelerin tutuldugu dizi
int komsMtrs[SIZE][SIZE];
int indisBaslangic;
int indisBitis;	

int stack[SIZE*SIZE];								
int pointStk=0;	

int yol[SIZE];										
int pointYol=0;



int kontrolYol(int check){
	int i=0;
	while ( i<pointYol && check != yol[i] ){
		i++;
	}
	if ( i<pointYol )
		return 1;
	else
		return 0;
}
	
void ekleYol(int item){
	yol[pointYol] = item;
	pointYol++;	
} 

void silYol(){ 
	pointYol--; 
}
	
void yazYol(char bitis[]){
	int i=0;
	while ( i<pointYol ) {
		printf ("%s",kelimeDizisi[yol[i]]);
		i++;
	}
	printf ("%s\t %d harf degisikligi var.\n",bitis,pointYol);
	getch(); // bunu kaldýrýrsan tum aternatifleri yazar
}

int isEmpty(){
	if(pointStk == 0)
		return 1;
	else
		return 0;
}

void enqueue(int yeni){
	if (pointStk == SIZE)
		printf ("Stack Dolu.\n");
	else
		stack[pointStk++] = yeni;
}

int dequeue(){
	int enUst=0;
	if(isEmpty() == 1){
		printf ("Stack Bos.\n");
		return -1;
	}
	else{
		//pointStk--;
		enUst = stack[--pointStk];
		return enUst;
	}
}

//Komsuluk matrisi yarat!
void matrisOlustur(){
	int i=0,j=0;
	char *temp;
	for (i=0; i<SIZE; i++){
		temp = kelimeDizisi[i]; 
		for (j=0;j<SIZE;j++){
			if (harfFark(temp,kelimeDizisi[j]) != 1)
				komsMtrs[i][j] = 0;
			else
				komsMtrs[i][j] = 1;
		}
	}
}		
	
//Ýki kelime arasindaki harf farkina bakiyor(1 olup olmamasi bizi ilgilendiriyor.)
int harfFark (char* ilk, char* son){
	int i=0,fark=0;
	while (ilk[i] != '\0'){
		if ( ilk[i] != son[i] ){
			fark++;
		}
		i++;
	}
	// burada fark hala sifirsa kelimeler esittir diyip, if else için bir return daha döndürebilirdik ama gerek yok.
	// Eðer word kendisin eþitse bile sýfýr donecek.
	if (fark == 1)
		return 1;
	else
		return 0;
}		

//verilen kelimelerin bir-birlerine bagli olup-olmadigini kontrol eder
void komsuMu(char baslangic[], char bitis[]){
	int k=0, l=0;
	while (strcmp(baslangic,kelimeDizisi[k]) != 0){			//ilk kelimenin matrisde yerinin bulunmasi
		k++;
	}
	indisBaslangic = k;
	
	while (strcmp(bitis,kelimeDizisi[l]) != 0){				//ikinci kelimenin matrisde yerinin bulunmasi
		l++;
	}
	indisBitis = l;
	
	if (komsMtrs[k][l] == 1)					
		printf ("\n  [Verilen kelimeler komsudur.]\n\n\n",baslangic,bitis);
	else
		printf ("\n  [Verilen kelimeler komsu degildir.]\n\n\n",baslangic,bitis);
} 

void tumKomsu(char baslangic[]){
	int i=0;
	while(i<SIZE){
		while (komsMtrs[indisBaslangic][i] != 1) {
			i++;
		}
		printf("   %s   ",kelimeDizisi[i++]);	
	}
} 
		

void bfs(char baslangic[], char bitis[]){
	int yer = 0;   
	int bulundu = 0;
	int tmp=0 ;
		
	enqueue(indisBaslangic);
	ekleYol(indisBaslangic);
	
	while(isEmpty() != 1 && bulundu==0 ){									//&& bulundu==0  kaldýrýsak tüm gidiþ yollarýný gosterir.
		while (yer<SIZE && komsMtrs[indisBaslangic][yer] != 1) {		//matris taranarak kelimenin komsulari bulunur. Her seferinde bir komþu bulunur.
			yer++;
		}
		
		if ( (yer<SIZE) && (indisBitis != yer) ){						//eger bulunan komsu istenen bitis kelimesi degilse stacke at
			if (kontrolYol(yer) != 1){							
				enqueue(yer);										
			}
			yer++;
		}	
		else if (yer<SIZE && indisBitis == yer){						//eger bulunan komsu istenen bitis kelimesi ise print et.
			yazYol(bitis);											
			bulundu = 1;											
			yer++;
		}
		else{
			tmp = dequeue();
			while (kontrolYol(tmp) == 1 && isEmpty() != 1){
				silYol();						
				tmp = dequeue();
			}
			if (isEmpty() != 1){
				indisBaslangic = tmp;									//enqueue(indisBaslangic);
				ekleYol(indisBaslangic);
				yer = 0;
			}	
		}
	}

	if (bulundu == 0 )
		printf ("[ Hicbir yol bulunamadi. ]\n\n\n");		
} 

int main() {
	char baslangic[5], bitis[5], kelime[5];								// baslangic kelimesi ve bitis kelimesi
	int i=0, j=0;
    char line[7];

    FILE *file;
    file = fopen("kelime.txt", "r");

    while(fgets(line, sizeof line, file)!= NULL) {
        kelimeDizisi[i++]=strdup(line); 								//okunan kelimelerin "kelimeDizisi" dizisine yazilmasi
    }
    
	printf ("------ Baslangic ve bitis kelimeleri arasindaki  yollar -----\n\n" );
	printf ("Baslangic kelimesi: ");
	scanf ("%s",baslangic);
	strcat(baslangic,"\n");												// kelimenin hemen sonuna newline karakteri ekledik
	
	printf ("Bitis kelimesi: ");
	scanf ("%s",bitis);
	strcat (bitis,"\n"); 							
	
	matrisOlustur();
	komsuMu(baslangic,bitis);
	bfs(baslangic,bitis);

	fclose(file);
	return 0;
}

