#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h> 
#include <unistd.h>
#define n 11
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int kacoyunculu();
int zar_atma();
void display(char *Matris[n][n]);
//void play(struct oyuncu ornek, char *Matris[n][n]);


static int t10=0;
static int t11=0;
static int t20=0;
static int t21=1;
static int t30=1;
static int t31=0;
static int t40=1;
static int t41=1;

static int bt10=0;
static int bt11=9;
static int bt20=0;
static int bt21=10;
static int bt30=1;
static int bt31=9;
static int bt40=1;
static int bt41=10;

static int yt10=9;
static int yt11=0;
static int yt20=9;
static int yt21=1;
static int yt30=10;
static int yt31=0;
static int yt40=10;
static int yt41=1;

static int gt10=9;
static int gt11=9;
static int gt20=9;
static int gt21=10;
static int gt30=10;
static int gt31=9;
static int gt40=10;
static int gt41=10;

static int z;

struct oyuncu {
	char tas1[3];
	char tas2[3];
	char tas3[3];
	char tas4[3];
	
};

int main() {
	int i,j,player;
	char temp[3];
	int x;
	
	printf("                         =kizma birader oyununa hosgeldiniz=\n");
	
	do{
		printf(" \n \n");
		printf("============================= \n");
	    x=menu();
		
		printf(" \n \n");	
	}while (x!=1);
	
	
	
	
	char *M[n][n];
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			
			strcpy(&M[i][j],". ");
		}
	}
	
    strcpy(&M[0][2],"  ");
 	strcpy(&M[0][3]," |");
 	strcpy(&M[1][2],"  ");
 	strcpy(&M[1][3]," |");
 	strcpy(&M[2][0],"  ");
 	strcpy(&M[2][1],"  ");
 	strcpy(&M[2][2],"  ");
 	strcpy(&M[2][3]," |");
 	strcpy(&M[3][0],"__");
 	strcpy(&M[3][1],"__");
 	strcpy(&M[3][2],"__");
 	strcpy(&M[3][3],"_|");
 	
 	
 	strcpy(&M[0][7]," |");
 	strcpy(&M[0][8],"  ");
 	strcpy(&M[1][7]," |");
 	strcpy(&M[1][8],"  ");
 	strcpy(&M[2][7]," |");
 	strcpy(&M[2][8],"  ");
 	strcpy(&M[2][9],"  ");
 	strcpy(&M[2][10],"  ");
 	strcpy(&M[3][7],"_|");
 	strcpy(&M[3][8],"__");
 	strcpy(&M[3][9],"__");
 	strcpy(&M[3][10],"__");
 	
 	strcpy(&M[7][0],"--");
 	strcpy(&M[8][0],"  ");
 	strcpy(&M[7][1],"--");
 	strcpy(&M[8][1],"  ");
 	strcpy(&M[7][2],"--");
 	strcpy(&M[8][2],"  ");
 	strcpy(&M[9][2],"  ");
 	strcpy(&M[10][2],"  ");
 	strcpy(&M[7][3],"-|");
 	strcpy(&M[8][3]," |");
 	strcpy(&M[9][3]," |");
 	strcpy(&M[10][3]," |");
 	
 	strcpy(&M[9][7],"| ");
 	strcpy(&M[9][8],"  ");
 	strcpy(&M[10][7],"| ");
 	strcpy(&M[10][8],"  ");
 	strcpy(&M[7][7],"|-");
 	strcpy(&M[7][8],"--");
 	strcpy(&M[7][9],"--");
 	strcpy(&M[7][10],"--");
 	strcpy(&M[8][7],"| ");
 	strcpy(&M[8][8],"  ");
 	strcpy(&M[8][9],"  ");
 	strcpy(&M[8][10],"  ");
    
	
	player = kacoyunculu();
	
	/*
	z=(strcmp(&M[5][0],". ")==0) || (strcmp(&M[5][1],". ")==0) || (strcmp(&M[5][2],". ")==0);
	x=(strcmp(&M[5][10],". ")==0) || (strcmp(&M[5][9],". ")==0) || (strcmp(&M[5][8],". ")==0);
	c=(strcmp(&M[0][5],". ")==0) || (strcmp(&M[1][5],". ")==0) || (strcmp(&M[2][5],". ")==0);
	x=(strcmp(&M[10][5],". ")==0) || (strcmp(&M[9][5],". ")==0) || (strcmp(&M[8][5],". ")==0);
	*/
	if (player==2)
	{
		struct oyuncu oyuncu1;
		
		strcpy(oyuncu1.tas1,"r1");
		strcpy(oyuncu1.tas2,"r2");
		strcpy(oyuncu1.tas3,"r3");
		strcpy(oyuncu1.tas4,"r4");
		strcpy(&M[0][0],oyuncu1.tas1);
	    strcpy(&M[0][1],oyuncu1.tas2);
	    strcpy(&M[1][0],oyuncu1.tas3);
	    strcpy(&M[1][1],oyuncu1.tas4);
	    
	    struct oyuncu oyuncu2;
	    
	    strcpy(oyuncu2.tas1,"b1");
		strcpy(oyuncu2.tas2,"b2");
		strcpy(oyuncu2.tas3,"b3");
		strcpy(oyuncu2.tas4,"b4");
		strcpy(&M[0][9],oyuncu2.tas1);
	    strcpy(&M[0][10],oyuncu2.tas2);
	    strcpy(&M[1][9],oyuncu2.tas3);
	    strcpy(&M[1][10],oyuncu2.tas4);
  	 	    
	    i=0;
	    int flagred = 1;
	    int flagblue = 1;
		while (((strcmp(&M[5][0],". ")==0) || (strcmp(&M[5][1],". ")==0) || (strcmp(&M[5][2],". ")==0)) && ((strcmp(&M[0][5],". ")==0) || 
		(strcmp(&M[1][5],". ")==0) || (strcmp(&M[2][5],". ")==0)))
		{
					
			if (flagred==1)
			{
				flagred=playilkred(oyuncu1, &M);	
			}
			else if (flagred==0)
			{
				playred(oyuncu1, &M);
			}
			
			if (flagblue==1)
			{
				flagblue=playilkblue(oyuncu2, &M);	
			}
			else if (flagblue==0)
			{
				playblue(oyuncu2, &M);;
			}
			i++;
		}	
	}
	
	if (player==3)
	{
		struct oyuncu oyuncu1;
		
		strcpy(oyuncu1.tas1,"r1");
		strcpy(oyuncu1.tas2,"r2");
		strcpy(oyuncu1.tas3,"r3");
		strcpy(oyuncu1.tas4,"r4");
		strcpy(&M[0][0],oyuncu1.tas1);
	    strcpy(&M[0][1],oyuncu1.tas2);
	    strcpy(&M[1][0],oyuncu1.tas3);
	    strcpy(&M[1][1],oyuncu1.tas4);
	    
	    struct oyuncu oyuncu2;
	    
	    strcpy(oyuncu2.tas1,"b1");
		strcpy(oyuncu2.tas2,"b2");
		strcpy(oyuncu2.tas3,"b3");
		strcpy(oyuncu2.tas4,"b4");
		strcpy(&M[0][9],oyuncu2.tas1);
	    strcpy(&M[0][10],oyuncu2.tas2);
	    strcpy(&M[1][9],oyuncu2.tas3);
	    strcpy(&M[1][10],oyuncu2.tas4);
	    
	    struct oyuncu oyuncu3;
		
		strcpy(oyuncu3.tas1,"y1");
		strcpy(oyuncu3.tas2,"y2");
		strcpy(oyuncu3.tas3,"y3");
		strcpy(oyuncu3.tas4,"y4");
		strcpy(&M[9][0],oyuncu3.tas1);
	    strcpy(&M[9][1],oyuncu3.tas2);
	    strcpy(&M[10][0],oyuncu3.tas3);
	    strcpy(&M[10][1],oyuncu3.tas4);
  	 	    
	    
	    int flagred = 1;
	    int flagblue = 1;
	    int flagyellow = 1;
		while (((strcmp(&M[5][0],". ")==0) || (strcmp(&M[5][1],". ")==0) || (strcmp(&M[5][2],". ")==0)) && ((strcmp(&M[0][5],". ")==0) || 
		(strcmp(&M[1][5],". ")==0) || (strcmp(&M[2][5],". ")==0)) && ((strcmp(&M[8][5],". ")==0) || (strcmp(&M[9][5],". ")==0) || (strcmp(&M[10][5],". ")==0)))
		{
					
			if (flagred==1)
			{
				flagred=playilkred(oyuncu1, &M);	
			}
			else if (flagred==0)
			{
				playred(oyuncu1, &M);
			}
			
			if (flagblue==1)
			{
				flagblue=playilkblue(oyuncu2, &M);	
			}
			else if (flagblue==0)
			{
				playblue(oyuncu2, &M);;
			}
			
			if (flagyellow==1)
			{
				flagyellow=playilkyellow(oyuncu3, &M);	
			}
			else if (flagyellow==0)
			{
				playyellow(oyuncu3, &M);
			}
		}	
	}
	
	if (player==4)
	{
		struct oyuncu oyuncu1;
		
		strcpy(oyuncu1.tas1,"r1");
		strcpy(oyuncu1.tas2,"r2");
		strcpy(oyuncu1.tas3,"r3");
		strcpy(oyuncu1.tas4,"r4");
		strcpy(&M[0][0],oyuncu1.tas1);
	    strcpy(&M[0][1],oyuncu1.tas2);
	    strcpy(&M[1][0],oyuncu1.tas3);
	    strcpy(&M[1][1],oyuncu1.tas4);
	    
	    struct oyuncu oyuncu2;
	    
	    strcpy(oyuncu2.tas1,"b1");
		strcpy(oyuncu2.tas2,"b2");
		strcpy(oyuncu2.tas3,"b3");
		strcpy(oyuncu2.tas4,"b4");
		strcpy(&M[0][9],oyuncu2.tas1);
	    strcpy(&M[0][10],oyuncu2.tas2);
	    strcpy(&M[1][9],oyuncu2.tas3);
	    strcpy(&M[1][10],oyuncu2.tas4);
	    
	    struct oyuncu oyuncu3;
		
		strcpy(oyuncu3.tas1,"y1");
		strcpy(oyuncu3.tas2,"y2");
		strcpy(oyuncu3.tas3,"y3");
		strcpy(oyuncu3.tas4,"y4");
		strcpy(&M[9][0],oyuncu3.tas1);
	    strcpy(&M[9][1],oyuncu3.tas2);
	    strcpy(&M[10][0],oyuncu3.tas3);
	    strcpy(&M[10][1],oyuncu3.tas4);
	    
	    struct oyuncu oyuncu4;
	    
	    strcpy(oyuncu4.tas1,"g1");
		strcpy(oyuncu4.tas2,"g2");
		strcpy(oyuncu4.tas3,"g3");
		strcpy(oyuncu4.tas4,"g4");
		strcpy(&M[9][9],oyuncu4.tas1);
	    strcpy(&M[9][10],oyuncu4.tas2);
	    strcpy(&M[10][9],oyuncu4.tas3);
	    strcpy(&M[10][10],oyuncu4.tas4);
  	 	    
	    
	    int flagred = 1;
	    int flagblue = 1;
	    int flagyellow = 1;
	    int flaggreen = 1;
		while (((strcmp(&M[5][0],". ")==0) || (strcmp(&M[5][1],". ")==0) || (strcmp(&M[5][2],". ")==0)) && ((strcmp(&M[0][5],". ")==0) || (strcmp(&M[1][5],". ")==0) || (strcmp(&M[2][5],". ")==0))
		 && ((strcmp(&M[8][5],". ")==0) || (strcmp(&M[9][5],". ")==0) || (strcmp(&M[10][5],". ")==0)) && ((strcmp(&M[5][8],". ")==0) || (strcmp(&M[5][9],". ")==0) || (strcmp(&M[5][10],". ")==0)))
		{
					
			if (flagred==1)
			{
				flagred=playilkred(oyuncu1, &M);	
			}
			else if (flagred==0)
			{
				playred(oyuncu1, &M);
			}
			
			if (flagblue==1)
			{
				flagblue=playilkblue(oyuncu2, &M);	
			}
			else if (flagblue==0)
			{
				playblue(oyuncu2, &M);;
			}
			
			if (flagyellow==1)
			{
				flagyellow=playilkyellow(oyuncu3, &M);	
			}
			else if (flagyellow==0)
			{
				playyellow(oyuncu3, &M);
			}
			
			if (flaggreen==1)
			{
				flaggreen=playilkgreen(oyuncu4, &M);	
			}
			else if (flaggreen==0)
			{
				playgreen(oyuncu4, &M);
			}
		}	
	}

	
	display(&M);
	
	if ((strcmp(&M[5][0],". ")!=0) && (strcmp(&M[5][1],". ")!=0) && (strcmp(&M[5][2],". ")!=0)){
		printf("\n");
		printf("=======kazanan kirmizi oyuncu==========");
	}
	if ((strcmp(&M[0][5],". ")!=0) && (strcmp(&M[1][5],". ")!=0) && (strcmp(&M[2][5],". ")!=0)){
		printf("\n");
		printf("=======kazanan mavi oyuncu==========");
	}
	if ((strcmp(&M[8][5],". ")!=0) && (strcmp(&M[9][5],". ")!=0) && (strcmp(&M[10][5],". ")!=0)){
		printf("\n");
		printf("=======kazanan sari oyuncu==========");
	}
	if ((strcmp(&M[5][8],". ")!=0) && (strcmp(&M[5][9],". ")!=0) && (strcmp(&M[5][10],". ")!=0)){
		printf("\n");
		printf("=======kazanan yesil oyuncu==========");
	}
	
	
	return 0;
}


int menu(){
	printf("1. play \n");
	printf("2. Hakkinda \n");
	printf("3. Readme \n");
	printf("============================= \n");
	printf("1-3 arsýnda gecerli bir sayý giriniz \n");
	scanf("%i",&z);
	
	if (z==1)
	{
		printf("oyun basliyor... \n");
		sleep(2);
		return 1;
	}
	if (z==2)
	{
		printf("ludo(turkcesi  kizma birader) tarihi eskilere dayanan bir oyundur ilk olarak hindistanda ciktigi dusunulmektedir\n"
		"2, 3 ya da  4 kisiyle berebaer oynanabilen bu oyunun amacý baslangicta sahip oldugunuz 4 tasin 3 tanesini kendi bitis alaniniza goturmektir. oyuncular saat yonunde hareket eder\n"
		"oyunda bir zar vardýr. oyuna ilk 6 atan tasini cikarmaya hakkini kazanir. oyunda kendi tasinizin ustune gelemezsiniz gelmeye calisirsaniz siraniz gecer\n"
		"bunun yaninda rakip tasin üstüne gelirseniz karsi takimin tasini yiyip onu baslangic noktasina dondurebilirsiniz \n");
		return 0;
	}
	if (z==3)
	{
		printf("**oyunu yaparken bircok sikinti ile karsilastim hepsini hatirlamiyom ama cozdugum bazi ana sikintilar sunlardir:\n"
		"-oyun tahtasini yaparken her hucresi pointer olan 2D bir matris kullandim \n"
		"-daha sonra taslarin hareketi beni biraz zorladi bu sorunu kullaniciya tasin gidecegi yerin satir ve stun numarasini sorarak cözmeye calistim\n"
		"-tas yeme ve kendi tasinin ustune gelme problemini ise uzun bir arastirma sonucu static veri tipi tanimlayarak cozdum.\n"
		"bu degiskenlerde tasýn bulundugu satir ve stun numaralarini sakladim normal degiskenler tanýmladýgým zaman fonksiyonlarýn icerisinde bu degiskenlerin degeri degismiyordu \n"
		
		"**Cozum uretemdigim ya da zamaným yetmeyen kisimlar ise \n"
		"-oyuncular attigi zardan daha fazla gidebiliyor yani harakete kýsýtlama getirmedim mesela oyuncu 3 atip direk bitis noktasina gidebiliyor tabi bu kullanici hatasi olarak da kabul edilebilir \n"
		"bu sorun icin aslinda bir cozum dusunmustum eger oyuncu gittigi yerin satýr ve stun numarasinin eski konumundaki satýr ve stun degerlerinin mutlak farki- \n" 
		"attigi zardan buyukse tekrar deneyin gibi bir sey olacakti ama implamente edemedim \n"
		"-diger bir eksik oyuncular rakip bitis noktasina bulunan rakip tasi yiyebiliyor \n"
		"-bir de kucuk bir bug var onu videoda gostercegim \n"
		);
		return 0;	
	}
	

}


int kacoyunculu()
{
	
	int os=2;
	
	do
	{
		printf("kaç oyunculu? ");
		scanf("%i",&os);
		
	}
	while((os<2) || (os>4));
	
	
	
	return os;
}



int zar_at () {
   int num;
   time_t t;
   
   srand((unsigned) time(&t));

   //printf("%d\n", (rand() % 6)+1);
   
   num=(rand() % 6)+1;
   
   return num;
}

void display(char *Matris[n][n])
{
	int i,j;
	
	for (i=0;i<n;i++)
	{
		if (i==10)
		{
			printf("%i",i);
		}
		else
		{
			printf("%i ",i);
		}
			
		for (j=0;j<n;j++)
		{
			
			printf("%s",&Matris[i][j]);
			
			
		}
		printf("\n");
	}
	printf(" ");
	for (i=0;i<n;i++)
	{
		printf(" %i",i);
	}
	printf("\n");
}

int playilkred(struct oyuncu ornek, char* Matris[n][n])
{
	char harf;
	int zar;
	int k,l,r,y;
	zar=zar_at();
	printf("kirmizi oyuncu zar attý: %i \n",zar);
	sleep(3);
	
	if (zar==6)
	{	
		display(Matris);
		
		printf("%s -",ornek.tas1);
		printf("%s -",ornek.tas2);
		printf("%s -",ornek.tas3);
		printf("%s\n",ornek.tas4);
		printf("hangi taþ ile baslamak istersin? 1,2,3,4\n");
		scanf("%i",&r);
		
		printf("taþýn gideçeði yerin satir numarasi:");
		scanf("%i",&k);
		printf("taþýn gideçeði yerin sütün numarasi:");
		scanf("%i",&l);

		if (r==1)
		{			
		    strcpy(&Matris[k][l],ornek.tas1);
		    strcpy(&Matris[t10][t11],". ");
		    t10=k;
		    t11=l;   
		}
		if (r==2)
		{
		 	strcpy(&Matris[k][l],ornek.tas2);
		 	strcpy(&Matris[t20][t21],". ");
		    t20=k;
		    t21=l;
		}
		if (r==3)
		{
			strcpy(&Matris[k][l],ornek.tas3);
		 	strcpy(&Matris[t30][t31],". ");
		    t30=k;
		    t31=l;
		}
		if (r==4)
		{
			strcpy(&Matris[k][l],ornek.tas4);
		 	strcpy(&Matris[t40][t41],". ");
		    t40=k;
		    t41=l;
		}
		return 0;
    }
    else{
        return 1;	
	}
}
void playred(struct oyuncu ornek, char* Matris[n][n])
{

	int zar,k,l,r;
	zar=zar_at();
	printf("kirmizi oyuncu zar atti: %i \n",zar);
	
	if (strcmp(&Matris[t10][t11],"r1")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas1);
		strcpy(&Matris[0][0],ornek.tas1);
	}
	if (strcmp(&Matris[t20][t21],"r2")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas2);
		strcpy(&Matris[0][1],ornek.tas2);
	}
	if (strcmp(&Matris[t30][t31],"r3")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas3);
		strcpy(&Matris[1][0],ornek.tas3);
	}
	if (strcmp(&Matris[t40][t41],"r4")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas4);
		strcpy(&Matris[1][1],ornek.tas4);
	}
	
	display(Matris);
	
	printf("%s -",ornek.tas1);
	printf("%s -",ornek.tas2);
	printf("%s -",ornek.tas3);
	printf("%s\n",ornek.tas4);
	printf("hangi tasý oynatmak istersin? 1,2,3,4 ya da pass gecmek için 0 tuslayin\n");
	scanf("%i",&r);
	
	if (r==0)
	{
		printf("pass gectiniz\n");
		sleep(1);
	}
	else
	{
		if (r==1){
			printf("R1 tasiniz %i satirda %i stunda bulunmaktadir \n ",t10,t11);
		}
		if (r==2){
			printf("R2 tasiniz %i satirda %i stunda bulunmaktadir \n ",t20,t21);
		}
		if (r==3){
			printf("R3 tasiniz %i satirda %i stunda bulunmaktadir \n ",t30,t31);
		}
		if (r==4){
			printf("R4 tasiniz %i satirda %i stunda bulunmaktadir \n ",t40,t41);
		}
		
		printf("tasýn gideçeði yerin satýr sayýsý:");
		scanf("%i",&k);
		printf("tasýn gideçeði yerin sütün sayýsý:");
		scanf("%i",&l);
		
		if ((strcmp(&Matris[k][l],"r1")==0) || (strcmp(&Matris[k][l],"r2")==0) || (strcmp(&Matris[k][l],"r3")==0) || (strcmp(&Matris[k][l],"r4")==0) ) 
		{
			printf("gideceginiz yerde %s tasýnýz var sýranýz gecti \n",&Matris[k][l]);
		}
		else{
			if (r==1)
			{
				if (strcmp(&Matris[t10][t11],"r1")!=0)
				{
					t10=0;
					t11=0;
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[t10][t11],". ");
					t10=k;
					t11=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[t10][t11],". ");
					t10=k;
					t11=l;
			    }
			}
			if (r==2)
			{
				if (strcmp(&Matris[t20][t21],"r2")!=0)
				{
					t20=0;
					t21=1;
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[t20][t21],". ");
				    t20=k;
				    t21=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[t20][t21],". ");
				    t20=k;
				    t21=l;
			    }
			}
			if (r==3)
			{
				if (strcmp(&Matris[t30][t31],"r3")!=0)
				{
					t30=1;
					t31=0;
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[t30][t31],". ");
				    t30=k;
				    t31=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[t30][t31],". ");
				    t30=k;
				    t31=l;
			    }
			 	
			}
			if (r==4)
			{
				if (strcmp(&Matris[t40][t41],"r4")!=0)
				{
					t40=1;
					t41=1;
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[t40][t41],". ");
				    t40=k;
				    t41=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[t40][t41],". ");
				    t40=k;
				    t41=l;
			    }
			}
		}
   }
   sleep(1);
   printf("\n \n");	 
}

int playilkblue(struct oyuncu ornek, char* Matris[n][n])
{
	
	
	int zar,k,l,r,y;
	zar=zar_at();
	printf("mavi oyuncu zar atti: %i \n",zar);
	sleep(3);
	//printf("asdasa");
	//scanf("%i",y);
	if (zar==6)
	{
		display(Matris);
		
		printf("%s -",ornek.tas1);
		printf("%s -",ornek.tas2);
		printf("%s -",ornek.tas3);
		printf("%s\n",ornek.tas4);
		printf("hangi tas ile baslamak istersiniz? 1,2,3,4\n");
		scanf("%i",&r);
		
		printf("tasýn gideçeði yerin satýr numarasi:");
		scanf("%i",&k);
		printf("tasýn gideçeði yerin sutun numarasi:");
		scanf("%i",&l);
		//display(&Matris);
		
		
		
		if (r==1)
		{
		    strcpy(&Matris[k][l],ornek.tas1);
		    strcpy(&Matris[bt10][bt11],". ");
		    bt10=k;
		    bt11=l;   
		}
		if (r==2)
		{
		 	strcpy(&Matris[k][l],ornek.tas2);
		 	strcpy(&Matris[bt20][bt21],". ");
		    bt20=k;
		    bt21=l;
		}
		if (r==3)
		{
			strcpy(&Matris[k][l],ornek.tas3);
		 	strcpy(&Matris[bt30][bt31],". ");
		    bt30=k;
		    bt31=l;
		 	
		}
		if (r==4)
		{
			strcpy(&Matris[k][l],ornek.tas4);
		 	strcpy(&Matris[bt40][bt41],". ");
		    bt40=k;
		    bt41=l;
		 	
		}
		return 0; 
	}
    else
    {
   	 return 1;
    }
	
	
}

void playblue(struct oyuncu ornek, char* Matris[n][n])
{
	int zar,k,l,r;
	zar=zar_at();
	printf("mavi oyuncu zar attý: %i \n",zar);
	
	if (strcmp(&Matris[bt10][bt11],"b1")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas1);
		strcpy(&Matris[0][9],ornek.tas1);
	}
	if (strcmp(&Matris[bt20][bt21],"b2")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas2);
		strcpy(&Matris[0][10],ornek.tas2);
	}
	if (strcmp(&Matris[bt30][bt31],"b3")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas3);
		strcpy(&Matris[1][9],ornek.tas3);
	}
	if (strcmp(&Matris[bt40][bt41],"b4")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas4);
		strcpy(&Matris[1][10],ornek.tas4);
	}
	
	display(Matris);
	
	printf("%s -",ornek.tas1);
	printf("%s -",ornek.tas2);
	printf("%s -",ornek.tas3);
	printf("%s\n",ornek.tas4);
	printf("hangi tasý oynatmak istersin? 1,2,3,4 ya da pass gecmek için 0 tuslayin\n");
	scanf("%i",&r);
	
	if (r==0)
	{
		printf("pass gectiniz\n");
		sleep(1);
	}
	else
	{
		printf("tasýn gideçeði yerin satir numarasi:");
		scanf("%i",&k);
		printf("tasýn gideçeði yerin sütün numarasi:");
		scanf("%i",&l);
		//display(&Matris);
		
		if ((strcmp(&Matris[k][l],"b1")==0) || (strcmp(&Matris[k][l],"b2")==0) || (strcmp(&Matris[k][l],"b3")==0) || (strcmp(&Matris[k][l],"b4")==0) ) 
		{
			printf("gideceginiz yerde %s tasiniz var siraniz gecti \n",&Matris[k][l]);
		}
		else{
			if (r==1)
			{
				if (strcmp(&Matris[bt10][bt11],"b1")!=0)
				{
					bt10=0;
					bt11=9;
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[bt10][bt11],". ");
					bt10=k;
					bt11=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[bt10][bt11],". ");
					bt10=k;
					bt11=l;
			    }
			}
			if (r==2)
			{
				if (strcmp(&Matris[bt20][bt21],"b2")!=0)
				{
					bt20=0;
					bt21=10;
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[bt20][bt21],". ");
				    bt20=k;
				    bt21=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[bt20][bt21],". ");
				    bt20=k;
				    bt21=l;
			    }
			}
			if (r==3)
			{
				if (strcmp(&Matris[bt30][bt31],"b3")!=0)
				{
					bt30=1;
					bt31=9;
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[bt30][bt31],". ");
				    bt30=k;
				    bt31=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[bt30][bt31],". ");
				    bt30=k;
				    bt31=l;
			    }
			 	
			}
			if (r==4)
			{
				if (strcmp(&Matris[bt40][bt41],"b4")!=0)
				{
					bt40=1;
					bt41=10;
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[bt40][bt41],". ");
				    bt40=k;
				    bt41=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[bt40][bt41],". ");
				    bt40=k;
				    bt41=l;
			    }
			}
		}
   }	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int playilkyellow(struct oyuncu ornek, char* Matris[n][n])
{
	
	int zar;
	int k,l,r,y;
	zar=zar_at();
	printf("sari oyuncu zar atti: %i \n",zar);
	sleep(3);

	if (zar==6)
	{	
		display(Matris);
		
		printf("%s -",ornek.tas1);
		printf("%s -",ornek.tas2);
		printf("%s -",ornek.tas3);
		printf("%s\n",ornek.tas4);
		printf("hangi tas ile baslamak istersin? 1,2,3,4\n");
		scanf("%i",&r);
		
		printf("tasýn gideçegi yerin satýr numarasi:");
		scanf("%i",&k);
		printf("tasýn gideçegi yerin sütün  numarasi:");
		scanf("%i",&l);

		if (r==1)
		{			
		    strcpy(&Matris[k][l],ornek.tas1);
		    strcpy(&Matris[yt10][yt11],". ");
		    yt10=k;
		    yt11=l;   
		}
		if (r==2)
		{
		 	strcpy(&Matris[k][l],ornek.tas2);
		 	strcpy(&Matris[yt20][yt21],". ");
		    yt20=k;
		    yt21=l;
		}
		if (r==3)
		{
			strcpy(&Matris[k][l],ornek.tas3);
		 	strcpy(&Matris[yt30][yt31],". ");
		    yt30=k;
		    yt31=l;
		}
		if (r==4)
		{
			strcpy(&Matris[k][l],ornek.tas4);
		 	strcpy(&Matris[yt40][yt41],". ");
		    yt40=k;
		    yt41=l;
		}
		return 0;
    }
    else{
        return 1;	
	}
}
void playyellow(struct oyuncu ornek, char* Matris[n][n])
{

	int zar,k,l,r;
	zar=zar_at();
	printf("sari oyuncu zar atti: %i \n",zar);
	
	if (strcmp(&Matris[yt10][yt11],"y1")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas1);
		strcpy(&Matris[9][0],ornek.tas1);
	}
	if (strcmp(&Matris[yt20][yt21],"y2")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas2);
		strcpy(&Matris[9][1],ornek.tas2);
	}
	if (strcmp(&Matris[yt30][yt31],"y3")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas3);
		strcpy(&Matris[10][0],ornek.tas3);
	}
	if (strcmp(&Matris[yt40][yt41],"y4")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas4);
		strcpy(&Matris[10][1],ornek.tas4);
	}
	
	display(Matris);
	
	printf("%s -",ornek.tas1);
	printf("%s -",ornek.tas2);
	printf("%s -",ornek.tas3);
	printf("%s\n",ornek.tas4);
	printf("hangi tasý oynatmak istersin? 1,2,3,4 ya da pass gecmek için 0 tuslayin yazýn\n");
	scanf("%i",&r);
	
	if (r==0)
	{
		printf("pass geçtiniz\n");
		sleep(1);
	}
	else
	{
		printf("taþýn gidecegi yerin satir numarasi:");
		scanf("%i",&k);
		printf("taþýn gidecegi yerin sutun numarasi:");
		scanf("%i",&l);
		
		if ((strcmp(&Matris[k][l],"y1")==0) || (strcmp(&Matris[k][l],"y2")==0) || (strcmp(&Matris[k][l],"y3")==0) || (strcmp(&Matris[k][l],"y4")==0) ) 
		{
			printf("gideceginiz yerde %s tasiniz var siraniz gecti \n",&Matris[k][l]);
		}
		else{
			if (r==1)
			{
				if (strcmp(&Matris[yt10][yt11],"y1")!=0)
				{
					yt10=9;
					yt11=0;
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[yt10][yt11],". ");
					yt10=k;
					yt11=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[yt10][yt11],". ");
					yt10=k;
					yt11=l;
			    }
			}
			if (r==2)
			{
				if (strcmp(&Matris[yt20][yt21],"y2")!=0)
				{
					yt20=9;
					yt21=1;
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[yt20][yt21],". ");
				    yt20=k;
				    yt21=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[yt20][yt21],". ");
				    yt20=k;
				    yt21=l;
			    }
			}
			if (r==3)
			{
				if (strcmp(&Matris[yt30][yt31],"y3")!=0)
				{
					yt30=10;
					yt31=0;
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[yt30][yt31],". ");
				    yt30=k;
				    yt31=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[yt30][yt31],". ");
				    yt30=k;
				    yt31=l;
			    }
			 	
			}
			if (r==4)
			{
				if (strcmp(&Matris[yt40][yt41],"y4")!=0)
				{
					yt40=10;
					yt41=1;
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[yt40][yt41],". ");
				    yt40=k;
				    yt41=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[yt40][yt41],". ");
				    yt40=k;
				    yt41=l;
			    }
			}
		}
   }
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------


int playilkgreen(struct oyuncu ornek, char* Matris[n][n])
{
	
	int zar;
	int k,l,r,y;
	zar=zar_at();
	printf("yesil oyuncu zar attý: %i \n",zar);
	sleep(3);

	if (zar==6)
	{	
		display(Matris);
		
		printf("%s -",ornek.tas1);
		printf("%s -",ornek.tas2);
		printf("%s -",ornek.tas3);
		printf("%s\n",ornek.tas4);
		printf("hangi tas ile baslamak istersin? 1,2,3,4\n");
		scanf("%i",&r);
		
		printf("tasin gidecegi yerin satýr numarasi:");
		scanf("%i",&k);
		printf("tasin gidecegi yerin sutun numarasi:");
		scanf("%i",&l);

		if (r==1)
		{			
		    strcpy(&Matris[k][l],ornek.tas1);
		    strcpy(&Matris[gt10][gt11],". ");
		    gt10=k;
		    gt11=l;   
		}
		if (r==2)
		{
		 	strcpy(&Matris[k][l],ornek.tas2);
		 	strcpy(&Matris[gt20][gt21],". ");
		    gt20=k;
		    gt21=l;
		}
		if (r==3)
		{
			strcpy(&Matris[k][l],ornek.tas3);
		 	strcpy(&Matris[gt30][gt31],". ");
		    gt30=k;
		    gt31=l;
		}
		if (r==4)
		{
			strcpy(&Matris[k][l],ornek.tas4);
		 	strcpy(&Matris[gt40][gt41],". ");
		    gt40=k;
		    gt41=l;
		}
		return 0;
    }
    else{
        return 1;	
	}
}
void playgreen(struct oyuncu ornek, char* Matris[n][n])
{

	int zar,k,l,r;
	zar=zar_at();
	printf("yesil oyuncu zar attý: %i \n",zar);
	
	if (strcmp(&Matris[gt10][gt11],"g1")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas1);
		strcpy(&Matris[9][9],ornek.tas1);
	}
	if (strcmp(&Matris[gt20][gt21],"g2")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas2);
		strcpy(&Matris[9][10],ornek.tas2);
	}
	if (strcmp(&Matris[gt30][gt31],"g3")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas3);
		strcpy(&Matris[10][9],ornek.tas3);
	}
	if (strcmp(&Matris[gt40][gt41],"g4")!=0)
	{
		printf("%s tasiniz baslangic noktasina dondu \n",ornek.tas4);
		strcpy(&Matris[10][10],ornek.tas4);
	}
	
	display(Matris);
	
	printf("%s -",ornek.tas1);
	printf("%s -",ornek.tas2);
	printf("%s -",ornek.tas3);
	printf("%s\n",ornek.tas4);
	printf("hangi tasý oynatmak istersin? 1,2,3,4 ya da pass gecmek için 0 tuslayin yazýn\n");
	scanf("%i",&r);
	
	if (r==0)
	{
		printf("pass gectiniz\n");
		sleep(1);
	}
	else
	{
		printf("tasýn gidecegi yerin satir sayisi:");
		scanf("%i",&k);
		printf("taþin gidecegi yerin sütün sayisi:");
		scanf("%i",&l);
		
		if ((strcmp(&Matris[k][l],"g1")==0) || (strcmp(&Matris[k][l],"g2")==0) || (strcmp(&Matris[k][l],"g3")==0) || (strcmp(&Matris[k][l],"g4")==0) ) 
		{
			printf("gideceginiz yerde %s tasiniz var siraniz gecti \n",&Matris[k][l]);
		}
		else{
			if (r==1)
			{
				if (strcmp(&Matris[gt10][gt11],"g1")!=0)
				{
					gt10=9;
					gt11=9;
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[gt10][gt11],". ");
					gt10=k;
					gt11=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas1);
					strcpy(&Matris[gt10][gt11],". ");
					gt10=k;
					gt11=l;
			    }
			}
			if (r==2)
			{
				if (strcmp(&Matris[gt20][gt21],"g2")!=0)
				{
					gt20=9;
					gt21=10;
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[gt20][gt21],". ");
				    gt20=k;
				    gt21=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas2);
				 	strcpy(&Matris[gt20][gt21],". ");
				    gt20=k;
				    gt21=l;
			    }
			}
			if (r==3)
			{
				if (strcmp(&Matris[gt30][gt31],"g3")!=0)
				{
					gt30=10;
					gt31=9;
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[gt30][gt31],". ");
				    gt30=k;
				    gt31=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas3);
				 	strcpy(&Matris[gt30][gt31],". ");
				    gt30=k;
				    gt31=l;
			    }
			 	
			}
			if (r==4)
			{
				if (strcmp(&Matris[gt40][gt41],"g4")!=0)
				{
					gt40=10;
					gt41=10;
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[gt40][gt41],". ");
				    gt40=k;
				    gt41=l;
				}
				else{
					strcpy(&Matris[k][l],ornek.tas4);
				 	strcpy(&Matris[gt40][gt41],". ");
				    gt40=k;
				    gt41=l;
			    }
			}
		}
   }
	
}
