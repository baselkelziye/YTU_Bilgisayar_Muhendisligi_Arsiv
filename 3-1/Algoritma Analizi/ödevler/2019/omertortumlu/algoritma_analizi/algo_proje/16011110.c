#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define fCount 20161	//tablo uzunlugu icin gereken fCount = EnküçükAsalSayý >= TablodakiElemanSayýsý / LoadFactor? Film sayýsý=14130, Load faktör=0,7
#define RfCount 20149	//RfCount degerini fCount’den küçük ilk asal sayý olarak alýndý 
#define l 100   //en uzun kelimeyi tutmak için gereken indis sayýsý///
#define aCount 243613	//Aktor sayýsý=170517, Load Faktor=0,7
#define RaCount 243589 	//RaCount degerini aCount’den küçük ilk asal sayý olarak alýndý
///////////////////////////////Filmleri hashlemek için kulllnadýðým fonksiyonlar////////////////////////////////////////////
int encrypt(char str[]){
	int i,key;
	for(i=key=0;i < strlen(str); i++) 
		key +=(str[i]-'a')*26*i ;
	return key;
}
int h1(int key){
	return key % fCount;
}
int offset(int key){
	return RfCount-(key%RfCount);
}						//films[h(encrypt(word),i)][0]!='\0'
int h(int key,int x){
	int v=(h1(key) + x*offset(key)) % fCount;
	if(v>=0)
		return v ;
	else
		return v*-1;
}
///////////////////////////////Aktörleri hashlemek için kulllnadýðým fonksiyonlar////////////////////////////////////////////
int aEncrypt(char str[]){
	int i,key;
	for(i=key=0;i < strlen(str); i++) 
		key +=(str[i]-'a')*26*i ;
	return key;
}
int aH1(int key){
	return key % aCount;
}
int aOffset(int key){
	return RaCount-(key%RaCount);
}
int aH(int key,int x){
	int v=(aH1(key) + x*aOffset(key)) % aCount;
	if(v>=0)
		return v ;
	else
		return v*-1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int wordLength(char str[l]){
	return strlen(str);
}
int filmSearch(char **hash,char str[l]){
	int i=0;
		while(hash[h(encrypt(str),i)][0]!='\0' && (strcmp(hash[h(encrypt(str),i)],str)!=0) ){		//hash tablosunda bir deðer varsa
			i++;
		}				
	if(strcmp(hash[h(encrypt(str),i)],str)==0){
		return -1;
	}
	else{
		return h(encrypt(str),i);
	}	
}
int actorSearch(char **aHash,char str[l]){
	int i=0;
		while(aHash[aH(aEncrypt(str),i)][0]!='\0' && (strcmp(aHash[aH(aEncrypt(str),i)],str)!=0) ){		//hash tablosunda bir deðer varsa
			i++;
		}				
	if(strcmp(aHash[aH(aEncrypt(str),i)],str)==0){
		return -1;
	}
	else{
		return aH(aEncrypt(str),i);
	}
		
}
void wordFree(char *word){
	int j;
	for(j=0;j<l;j++){
		word[j]='\0';
	}
}
int* filmTree(char **matris,char **films,char **actors,char *sActor,int *totalActor){
	int index=totalActor[actorSearch(actors,sActor)];
	int *filmTrees=(int*)calloc(index,sizeof(int));
	int i,j;
	for(i=0;i<fCount;i++){
		if(matris[i][index]==1&&j<index){
			filmTrees[j]=i;
			j++;
		}		
	}
	return filmTrees;
}
void filmTreePrint(char **films,int *filmTrees){
	int i;
	for(i=0;i<sizeof(filmTrees);i++){
		printf(" %s ",filmTrees[i]);
	}
}
int* actorTree(char **matris,char **films,char **actors,char *sFilm,int *totalFilm){
	int index=totalFilm[filmSearch(actors,sFilm)];
	int *actorTrees=(int*)calloc(index,sizeof(int));
	int i,j;
	for(i=0;i<aCount;i++){
		if(matris[index][i]==1&&j<index){
			actorTrees[j]=i;
			j++;
		}		
	}
	return actorTrees;
}
void actorTreePrint(char **actors,int *actorTrees){
	int i;
	for(i=0;i<sizeof(actorTrees);i++){
		printf(" %s ",actorTrees[i]);
	}
}
int main(){
		char txtName[100]="input-mpaa.txt";// = "input-mpaa.txt";
		FILE * fpr = fopen(txtName, "r");
		if (fpr == NULL){
			printf("Boyle bir dosya bulunmamaktadir.");				//Böyle bir dosya yoksa çalýþma duruyor
			return 1;
		}   	
		
  		char cr;						//okunan deðerin atandýðý karakter deðiþkeni;  			
  		int i,j;
  		///////////////////////////////////////////////////
  		char **films=(char**)malloc(fCount*sizeof(char*));
     	for(i=0;i<fCount;i++)
        	films[i] = (char*)malloc(l*sizeof(char));
        printf("\nBos film[film] dizisi olusturuldu.");
		///////////////////////////////////////////////////	 		
 		char **actors=(char**)malloc(aCount*sizeof(char*));
    	for(i=0;i<aCount;i++)
        	actors[i] = (char*)malloc(l*sizeof(char)); 		
        printf("\nBos aktor[aktor] dizisi olusturuldu.");
 		///////////////////////////////////////////////////
	 	bool **matris = (bool**)calloc(fCount,sizeof(bool*));
    	for(i=0;i<fCount;i++)
    		matris[i] = (bool*)calloc(aCount,sizeof(bool));
        printf("\nBos matris[film][aktor] olusturuldu.");	
  		///////////////////////////////////////////////////
		for(i=0;i<aCount;i++){
			actors[i][0]='\0';				
		}
		for(i=0;i<fCount;i++){
			films[i][0]='\0';				
		}
		for(i=0;i<fCount;i++){
			for(j=0;j<aCount;j++){
					matris[i][j]=0;
			}
		}			
  		if(matris==0||films==0||actors==0) {
  			printf("Bellekten yer ayrilmadi\n");
  			printf("Matris: %d\n",matris);
  			printf("Films: %d\n",films);
  			printf("Actors: %d\n",actors);
  			return 1;
		}  		
  		int film=1,actor,value=0;
  		
  		char word[l];
		wordFree(word);
		int column=0,row=0,totalAc=0,x,y=0,z,ret;
		while((cr = fgetc(fpr)) != '^'){			//Dosyanýn son karakterine kadar okunuyor 
			if(film==1){
				if(cr=='/'){	//hashleme iþlemi sonradan yapýlacak.	
					x=0;					
					while(films[h(encrypt(word),x)][0]!='\0'){
						x++;
					}
					row=h(encrypt(word),x);
					strcpy(films[row],word);
					film=0;
					value=0;
					wordFree(word);					
				}
				else{
					word[value]=cr;
					value++;	
				}
			}
			else{		//actoru alýyorum
				if(cr=='/'||cr=='\n'){					
					ret=actorSearch(actors,word);
					if(ret==-1){
						x=0;
						while(actors[aH(aEncrypt(word),x)][0]!='\0'){
							x++;
						}
						
						column=aH(aEncrypt(word),x);						
						totalAc++;				
					}
					else{
						column=ret;	
						strcpy(actors[column],word);	
					}				
					matris[row][column]=1;
						//hashleme yapýlýnca bundan kurtul
					value=0;
					wordFree(word);						
				}
				else{
					word[value]=cr;
					value++;	
				}								
			}
			if(cr=='\n'){
				film=1;
			}					
		}//while bitiþ
		int u;
		for(i=0;i<fCount;i++){
			if(films[i][0]!='\0'){
				u++;
			}			
		}
		printf("\nFilm Hash tablosundaki film sayisi: %d",u);
		u=0;
		for(i=0;i<aCount;i++){
			if(actors[i][0]!='\0'){
				u++;
			}
			//printf("%s\n",actors[i]);				
		}
		printf("\nActor Hash tablosundaki aktor sayisi: %d",u);
		
		int s=0,m,totalFilm[fCount],totalActor[aCount];
		for(i=0;i<fCount;i++){
			m=0;
			for(j=0;j<aCount;j++){
				
				if(matris[i][j]){
					s++;
					m++;
				}
			}
			totalFilm[i]=m;
		}
		for(j=0;j<aCount;j++){
			m=0;
			for(i=0;i<fCount;i++){				
				if(matris[i][j]){
					m++;
				}
			}
			totalActor[j]=m;
		}		
		int max=0,max2=0;
		for(i=0;i<fCount;i++){
			if(totalFilm[i]>max){
				max=totalFilm[i];
			}				
		}
		for(i=0;i<aCount;i++){
			if(totalActor[i]>max2){
				max2=totalActor[i];
			}				
		}		
		printf("\n1 filmde oynayan max oyuncu sayisi: %d",max);
		printf("\n1 oyuncu en fazla kac filmde oynamis: %d",max2);
		printf("\nMatristeki 1 sayisi:%d",s);
		printf("\nCakisan aktor sayisi:%d",totalAc);
		printf("\n***************\nBaslanacak aktor ismi: ");
	
		char startActor[l];
		scanf("%s",&startActor);
		printf("\n***************\nBaglantisi aranacak aktor ismi: ");
		char endActor[l];
		scanf("%s",&endActor);
		int index=actorSearch(actors,startActor);
		if(index!=-1){
			int *filmTrees=(matris,films,actors,startActor,totalActor);
			filmTreePrint(films,filmTrees);
		}		
		free(matris);
		free(films);
		free(actors);
		fclose(fpr);

		
	
	return 0;
}
