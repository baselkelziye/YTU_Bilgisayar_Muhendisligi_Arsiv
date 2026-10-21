#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int i, j, n, m, a, b;
	int yemeksayisi; 
	int flag=0;
	int flag2=0;
	char hamle; 
	int yenenyemek=0; 
	int hamlesayisi=0; 
	int oyunalani[50][50];
	printf("oyun alaninin satir sayisini girin: ");
	scanf("%d",&n);
	printf("oyun alaninin sutun sayisini girin: ");
	scanf("%d",&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			oyunalani[i][j]=-1; //oyun alani integer bir 2-D array oldugundan bosluk yerine -1 degerlerini atadým. Yazdirirken -1 gördüðünde bosluk yazdiriyor.  
		}
	}
	printf("oyun alanindaki yemek sayisini girin: ");
	scanf("%d",&yemeksayisi);
	while(yemeksayisi>n*m-1){
		printf("oyun alanindaki kare sayisindan fazla yemek girdiginiz icin tekrar bir deger girin: ");
		scanf(" %d",&yemeksayisi);	
	}
	srand(time(0));
	i=0;
	while(i<yemeksayisi){
		a=rand()%n;
		b=rand()%m;
		if(oyunalani[a][b]!=0){
			oyunalani[a][b]=0;
			i++; // i sadece 0 atanmayan yere 0 atandýgýnda artýyor.
		}
	}
	while(flag==0){
		a=rand()%n;
		b=rand()%m;
		if(oyunalani[a][b]!=0){
			oyunalani[a][b]=1;
			flag=1;
		}
	}
	flag=0;
	while(flag==0){ //yukarida (degiskeni tanýmladigim satýrda) belirttigim durumlar olusup flag degiskeni 0 oldugunda donguden cýkýlýyor ve oyun bitiyor.
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(oyunalani[i][j]==-1){ //eger eleman -1 ise bosluk yazdýrdým.
					printf("|   ");
				}
				else{
					printf("| %d",oyunalani[i][j]);
					if(oyunalani[i][j]<10){
						printf(" ");
					}
				}
			}
			printf("|\n");
		}
		printf("kalan yemek sayisi: %d\n",yemeksayisi-yenenyemek);
		printf("yapilan hamle sayisi: %d\n",hamlesayisi);
		while(flag2==0){ //degiskeni tanimladigim satirda belirttigim gibi hamle hatali girilirse tekrardan almak için donguye sokup flag2 diye bir degisken kullandim.
			printf("hamlenizi  girin: ");
			scanf(" %c",&hamle);
			if(hamle=='u'){
				a--;
				flag2=1;
			}
			else if(hamle=='d'){
				a++;
				flag2=1;
			}
			else if(hamle=='l'){
				b--;
				flag2=1;
			}
			else if(hamle=='r'){
				b++;
				flag2=1;
			}
			else{
				printf("############################\n");
				printf("hatali hamle girdiniz.\n");
			}
		}
		flag2=0; //bir daha hamle yapilacagi zaman tekrardan donguye girilmesi icin deðiskeni sifirladim.
		hamlesayisi+=1;
		if(a<0||a>=n){ //satir disina cikildi mi diye kontrol icin. flag ile kontrol ettim.
			flag=1;
			printf("############################\n"); //sonuclar ekrana yazilirken daha okunakli olmasi icin bunu asagida bir cok yerde kullandim.
			printf("oyun alaninin disina ciktiginiz icin kaybettiniz.\n");
		}
		else if(b<0||b>=n){ //sutun disina cikildi mi diye kontrol icin.
			flag=1;
			printf("############################\n");
			printf("oyun alaninin disina ciktiginiz icin kaybettiniz.\n");
		}
		else if(oyunalani[a][b]>0){ //yilanin kuyruguna hamleyi bu sekilde flag degiskeni ile kontrol ettim.
			flag=1;
			printf("############################\n");
			printf("yilanin kuyruguna hamle yaptiginiz icin kaybettiniz.\n");
		}
		if(yenenyemek==yemeksayisi){ //yemek sayisi bittiginde cikilmasini saglamak icin yine flag ile kontrol ettim. 
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if((oyunalani[i][j]!=0)&&(oyunalani[i][j]!=-1)){
						oyunalani[i][j]+=1;	
					}
				}
			}
			printf("############################\n");
			printf("tebrikler, oyunu kazandiniz.\n");
			flag=1;
		}
		i=0;
		while((i<n)&&(flag==0)){ //burda for yerine while kullanma sebebim, flag'i 1 yapan durumlar yasanirsa bu donguye girmeden devam etmesini saðlamak.
			for(j=0;j<m;j++){
				if((oyunalani[i][j]!=0)&&(oyunalani[i][j]!=-1)){
					oyunalani[i][j]+=1; //Hamleden bagimsiz sekilde 0 ve -1 olmayan tumn elemanlari 1 artýrdým.
					if(oyunalani[i][j]>=yenenyemek+2){ 						
						oyunalani[i][j]=-1;						
					}
				}
			}
			i++;	
		}
		if(oyunalani[a][b]==0){ //yenen yemek var mi diye burada kontrol ediyorum cunku eleman artirimlarindan once kontrol edersem hamle sirasinda buyume gerceklesiyor. Siz bizden hamleden sonraki turda buyume istemistiniz.
			yenenyemek+=1; 
		}
		oyunalani[a][b]=1; //hamle yapilan yere yilanýn basini koyma islemini en son yapiyorum eger artirma islemlerinden once yaparsam, tur sonunda gözüken oyun alaninda 1 yazan kare bulunmaz. Cunku yazdirma dongu basinda yapiliyor. 
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(oyunalani[i][j]==-1){
				printf("|   ");
			}
			else if(oyunalani[i][j]==0){
				printf("|%d  ", oyunalani[i][j]);
			}
			else if(yenenyemek==yemeksayisi){	
				printf("| %d",oyunalani[i][j]);
				if(oyunalani[i][j]<10){
					printf(" ");
				}	
			}
			else{
				printf("|   ");
			}
		}
		printf("|\n");
	}
	printf("kalan yemek sayisi: %d\n",yemeksayisi-yenenyemek);
	printf("yapilan hamle sayisi: %d\n",hamlesayisi);
	printf("yilanin buyuklugu: %d\n", yenenyemek+1);
	return 0;
}    
