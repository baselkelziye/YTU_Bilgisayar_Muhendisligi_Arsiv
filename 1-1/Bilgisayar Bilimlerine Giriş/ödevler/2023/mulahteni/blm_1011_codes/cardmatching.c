#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int diff,menu=1,t,n,n1,timek;char c;srand(time(NULL));int p=0;int i,r,j;char *winner;
	bool game,player,computer;
	int memo,memoN,gamec=0,w=0;
	int GD[10][3];
	int sat1,sut1,sat2,sut2,pp,ss;
	int fsat1,fsat2,fsut1,fsut2,prsat1,prsat2,prsut1,prsut2,f2sat,f2sut,cp=0,cfor,cfor1,cm,css;
	int M[][3]={{100,1,1},{101,1,1},{102,1,1},{103,1,1},{104,1,1},{105,1,1},{106,1,1},{107,1,1},{108,1,1},{109,1,1},{110,1,1},{111,1,1},{112,1,1},{113,1,1},{114,1,1},{115,1,1}};
	while(menu!=5){
		diff=0;pp=0;cp=0;memoN=0,ss=0,css=0;
		while (diff==0&&menu!=5){
		printf(" KART ESLESTIRME OYUNUNA HOS GELDIN \n\n1- OYNA \n\n2- GECMIS OYUNLARI GORUNTULE\n\n3- NASIL OYNANIR \n\n4- YARDIM \n\n5- CIKIS \n");
		scanf("%d",&menu);system("cls");
		while(menu>5||menu<1){
			printf("Hatali giris tekrar girin\n");
			scanf("%d",&menu);
		}
		switch(menu){
			case 1: printf("OYNAMAK ISTEDIGIN ZORLUGU SEC\n\n1- KOLAY SEVIYE\n\n2- ORTA SEVIYE\n\n3- ZOR SEVIYE \n"); break;
			case 2: if(gamec==0){printf("Oynanmis oyun bulunmamaktadir...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!\n");scanf("%char",&c);system("cls");break;}else{for(i=0;i<gamec;i++){if(GD[i][0]==0){winner="Oyuncu";}else if(GD[i][0]==1){winner="Bilgisayar";}else if(GD[i][0]==2){winner="Hem Oyuncu Hem Bilgisayar Yani Berabere";}printf("%d. Oyunu kazanan : %s\n\n%d. Oyunda oyuncunun deneme sayisi : %d\n\n%d. Oyunda bilgisayarin deneme sayisi : %d\n\n",i+1,winner,i+1,GD[i][1],i+1,GD[i][2]);}printf("Ana menuye donmek icin \"ENTER\" tusuna bas!\n");scanf("%char",&c);system("cls");break;}
			case 3: printf("Sira sendeyken acilmasini istedigin kartin once satir sonra sutun sirasini gir... \n\nAcilan kartlardaki numaralari aklinda tut... \n\nAyni numaralari iceren kartlari gir ve puan kazan... \n\nDogru kartlari eslestirdiginde bir deneme hakki daha kazanirsin... \n\nBir tarafin kazandigi kesinlesince veya tum kartlar acilip berabere kalindiginda oyun biter... \n\nBilgisayara karsi yarisiyorsun... \n\nAna menuye donmek icin \"ENTER\" tusuna bas!\n");scanf("%char",&c);system("cls");break;
			case 4: printf("Destek, oneri, soru ve sikayetleriniz icin :\n\nMail : melihtunaipek.mti@gmail.com \n\nLinkedin : https://www.linkedin.com/in/melih-tuna-ipek-1498831b6 \n\nInstagram : https://instagram.com/mulah.teni*utm_medium=copy_link \n\nAna menuye donmek icin \"ENTER\" tusuna bas!\n");scanf("%char",&c);system("cls");break;
			case 5: system("cls");
		}
		if(menu==1){
			scanf("%d",&diff);
			while(diff>3||diff<1){
				printf("Hatali giris tekrar girin\n");
				scanf("%d",&diff);
			}system("cls");
		}
	}
	if(menu!=5){
		t=(diff+1)*2;timek=5*diff;
		n=t*t/2;n1=n/2;
		char A[t][t][2]; int B[32]={0};	
		for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
		for(i=0;i<t;i++){printf("%d",i+1);
			for(j=0;j<t;j++){
				r = rand()%n;
				if(B[r]!=2){
					A[i][j][0]=r+1;
					A[i][j][1]='*';
					B[r]=B[r]+1;
					printf("\t%d",A[i][j][0]);
				}else{j--;
				}
			}printf("\n\n");
		}
		printf("Kartlari hafizaniza kazimaniz icin kalan sureniz : ");
		for(i=timek-1;i>=0;i--){if(i>=10){printf("%d",i);sleep(1);printf("\b\b");}else{printf(" %d",i);sleep(1);printf("\b\b");}}system("cls");
		switch(diff){case 1: memo=2; break; case 2: memo=6; break; case 3: memo=16; break;
		} M[memo][3];
		game=true;player=true;computer=true;
		while(game){
			player=true;
			while(player){
				for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
				for(i=0;i<t;i++){printf("%d",i+1);
					for(j=0;j<t;j++){
						printf("\t%c",A[i][j][1]);
					}printf("\n\n");
				}printf("Sira oyuncuda...\n\nIlk kartinizi seciyorsunuz...\n");
				printf("\nSecmek istediginiz satiri girin : ");scanf("%d",&sat1);sat1--;
				printf("\n\nSecmek istediginiz sutunu girin : ");scanf("%d",&sut1);sut1--;
				while((sat1<0||sat1>=t)||(sut1<0||sut1>=t)||(A[sat1][sut1][1]!='*')){
					printf("\n\nSatir veya sutunu hatali girdiniz...\n\nHata daha onceden acilan bir karti acmaya calismanizdan, \n\nolmayan bir satiri veya sutunu girmenizden kaynaklaniyor olabilir, \n\ntekrar deneyin...");
					printf("\n\nSecmek istediginiz satiri girin : ");scanf("%d",&sat1);sat1--;
					printf("\n\nSecmek istediginiz sutunu girin : ");scanf("%d",&sut1);sut1--;
				}system("cls");
				for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
				for(i=0;i<t;i++){printf("%d",i+1);
					for(j=0;j<t;j++){
						if((sat1==i)&&(sut1==j)){
							printf("\t%d",A[sat1][sut1][0]);
						}else {printf("\t%c",A[i][j][1]);
						}
					}printf("\n\n");				
				}printf("Ikinci kartinizi seciyorsunuz...\n\n");
				printf("\nSecmek istediginiz satiri girin : ");scanf("%d",&sat2);sat2--;
				printf("\nSecmek istediginiz sutunu girin : ");scanf("%d",&sut2);sut2--;
				while((sat2<0||sat2>t)||(sut2<0||sut2>t)||(A[sat2][sut2][1]!='*')||((sat1==sat2)&&(sut1==sut2))){
					printf("Satir veya sutunu hatali girdiniz,\nHata daha onceden acilan bir karti acmaya calismanizdan \nveya olmayan bir satiri veya sutunu girmenizden kaynaklaniyor olabilir, \ntekrar deneyin...");
					printf("\n\nSecmek istediginiz satiri girin : ");scanf("%d",&sat2);sat2--;
					printf("\n\nSecmek istediginiz sutunu girin : ");scanf("%d",&sut2);sut2--;
				}system("cls");
				for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
				for(i=0;i<t;i++){printf("%d",i+1);
					for(j=0;j<t;j++){
						if((sat1==i)&&(sut1==j)){
							printf("\t%d",A[sat1][sut1][0]);
						}else if((sat2==i)&&(sut2==j)){
							printf("\t%d",A[sat2][sut2][0]);
						}else {printf("\t%c",A[i][j][1]);
						}
					}printf("\n\n");				
				}if(A[sat1][sut1][0]==A[sat2][sut2][0]){
					printf("Eslesen kartlar buldunuz ve 1 puan kazandiniz...\n\nOynama sirasi tekrar sizde..."); pp++; A[sat1][sut1][1]='-';A[sat2][sut2][1]='-';sleep(2);
				}else{printf("Eslesen kart bulamadiniz... \n\nSiranin bilgisayara gecmesi icin kalan sure : ");for(i=5;i>=0;i--){printf("%d",i);sleep(1);printf("\b");}
				M[memoN][0]=A[sat1][sut1][0];M[memoN][1]=sat1;M[memoN][2]=sut1;memoN++;
				M[memoN][0]=A[sat2][sut2][0];M[memoN][1]=sat2;M[memoN][2]=sut2;memoN++;
				if(memoN>=(memo)){memoN=0;}
				player=false;				
				}system("cls");
				if(n==pp+cp){player=false;
			}ss++;
			}
			if(n==pp+cp){}else if(pp>n1){}else if(cp>n1){}else{computer=true;}
			while(computer){printf("Oynama sirasi bilgisayarda...\n\n");sleep(2);system("cls");
				cfor=0,cfor1=0,cm=0;
				for(i=0;i<memo-1;i++){//printf("\n\n%d\n\n",i);
					for(j=i+1;j<memo;j++){
						if(((M[i][0]==M[j][0])&&!((M[i][1]==M[j][1])&&(M[i][2]==M[j][2])))&&(A[M[i][1]][M[i][2]][1]!='-')&&(A[M[j][1]][M[j][2]][1]!='-')){
							A[M[i][1]][M[i][2]][1]='-';A[M[j][1]][M[j][2]][1]='-';fsat1=M[i][1];fsat2=M[j][1];fsut1=M[i][2];fsut2=M[j][2];i=memo-1;j=memo;
							cfor=1;cp++;																					
						}
					}
				}
				if(cfor==1){
					for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
					for(i=0;i<t;i++){printf("%d",i+1);
						for(j=0;j<t;j++){
							if((i==fsat1)&&(j==fsut1)){printf("\t%d",A[i][j][0]);
							}else if((i==fsat2)&&(j==fsut2)){printf("\t*");
							}else{printf("\t%c",A[i][j][1]);
							}				
						}printf("\n\n");
					}printf("Bilgisayar ilk secimini yapti... \n\n");sleep(3);system("cls");
					for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
					for(i=0;i<t;i++){printf("%d",i+1);
						for(j=0;j<t;j++){
							if((i==fsat2)&&(j==fsut2)){printf("\t%d",A[i][j][0]);
							}else if((i==fsat1)&&(j==fsut1)){printf("\t%d",A[i][j][0]);
							}else{printf("\t%c",A[i][j][1]);
							}
						}printf("\n\n");
					}printf("Bilgisayar ikinci secimini yapti ve kartlari dogru eslestirdi... \n\n");sleep(2);system("cls");
				}else{
					do{prsat1=rand()%t;prsut1=rand()%t;
					}while(A[prsat1][prsut1][1]!='*');				
					for(i=0;i<memo;i++){
						if((A[prsat1][prsut1][0]==M[i][0])&&!((prsat1==M[i][1])&&(prsut1==M[i][2]))){						
							f2sat=M[i][1];f2sut=M[i][2];A[prsat1][prsut1][1]='-';A[f2sat][f2sut][1]='-';cfor1=1;cp++;
						}
					}if(cfor1==1){
						for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
						for(i=0;i<t;i++){printf("%d",i+1);
							for(j=0;j<t;j++){
								if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
								}else if((i==f2sat)&&(j==f2sut)){printf("\t*");
								}else{printf("\t%c",A[i][j][1]);
								}							
							}printf("\n\n");
						}printf("Bilgisayar ilk secimini yapti... \n\n");sleep(3);system("cls");
						for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
						for(i=0;i<t;i++){printf("%d",i+1);
							for(j=0;j<t;j++){
								if((i==f2sat)&&(j==f2sut)){printf("\t%d",A[i][j][0]);
								}else if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
								}else{printf("\t%c",A[i][j][1]);
							 }							
							}printf("\n\n");
						}printf("Bilgisayar ikinci secimini yapti ve kartlari dogru eslestirdi... \n\n");sleep(2);system("cls");
					}else{
						do{prsat2=rand()%t;prsut2=rand()%t;
						}while((A[prsat2][prsut2][1]!='*')||((prsat1==prsat2)&&(prsut1==prsut2)));
						if(A[prsat1][prsut1][0]==A[prsat2][prsut2][0]){
							A[prsat1][prsut1][1]='-';A[prsat2][prsut2][1]='-';cp++;cm=1;
						}if(cm==1){
							for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
							for(i=0;i<t;i++){printf("%d",i+1);
								for(j=0;j<t;j++){
									if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
									}else if((i==prsat2)&&(j==prsut2)){printf("\t*");
									}else{printf("\t%c",A[i][j][1]);
									}							
								}printf("\n\n");
							}printf("Bilgisayar ilk secimini yapti... \n\n");sleep(3);system("cls");
							for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
							for(i=0;i<t;i++){printf("%d",i+1);
								for(j=0;j<t;j++){
									if((i==prsat2)&&(j==prsut2)){printf("\t%d",A[i][j][0]);
									}else if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
									}else{printf("\t%c",A[i][j][1]);
									}
								}printf("\n\n");
							}printf("Bilgisayar ikinci secimini yapti ve kartlari dogru eslestirdi...\n\n");sleep(2);system("cls");					
						}else{
							for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
							for(i=0;i<t;i++){printf("%d",i+1);
								for(j=0;j<t;j++){
									if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
									}else{printf("\t%c",A[i][j][1]);
									}							
								}printf("\n\n");
							}printf("Bilgisayar ilk secimini yapti... \n\n");sleep(3);system("cls");
							for(i=0;i<t;i++){printf("\t%d",i+1);}printf("\n\n");
							for(i=0;i<t;i++){printf("%d",i+1);
								for(j=0;j<t;j++){
									if((i==prsat2)&&(j==prsut2)){printf("\t%d",A[i][j][0]);
									}else if((i==prsat1)&&(j==prsut1)){printf("\t%d",A[i][j][0]);
									}else{printf("\t%c",A[i][j][1]);
									}
								}printf("\n\n");
							}printf("Bilgisayar ikinci secimini yapti ve kartlari dogru eslestiremedi... \n\nOynama sirasinin oyuncuya gecmesi icin kalan sure : ");for(i=5;i>=0;i--){printf("%d",i);sleep(1);printf("\b");};system("cls");
							M[memoN][0]=A[prsat1][prsut1][0];M[memoN][1]=prsat1;M[memoN][2]=prsut1;memoN++;
							M[memoN][0]=A[prsat2][prsut2][0];M[memoN][1]=prsat2;M[memoN][2]=prsut2;memoN++;
							if(memoN>=(memo)){memoN=0;
							}computer=false;
						}
					}
				}if(n==pp+cp){computer=false;
				}css++;
			}
			printf("Oyuncu puani : %d \n\n",pp);
			printf("Bilgisayar puani : %d\n\n",cp);
			if(n==pp+cp){game=false;
				if(pp>cp){GD[gamec][0]=0;GD[gamec][1]=ss;GD[gamec][2]=css;printf("Tebrikler kazandin...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!");scanf("%char",&c);system("cls");
				}else if(cp>pp){GD[gamec][0]=1;GD[gamec][1]=ss;GD[gamec][2]=css;printf("Kaybettin, bilgisayar kazandi...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!");scanf("%char",&c);system("cls");
				}else if(cp==pp){GD[gamec][0]=2;GD[gamec][1]=ss;GD[gamec][2]=css;printf("Bilgisayarla berabere kaldiniz...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!");scanf("%char",&c);system("cls");
				}gamec++;
			}else if(pp>n1){game=false;GD[gamec][0]=0;GD[gamec][1]=ss;GD[gamec][2]=css;printf("Kaybettin, bilgisayar kazandi...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!");gamec++;scanf("%char",&c);system("cls");
			}else if(cp>n1){game=false;GD[gamec][0]=1;GD[gamec][1]=ss;GD[gamec][2]=css;printf("Kaybettin, bilgisayar kazandi...\n\nAna menuye donmek icin \"ENTER\" tusuna bas!");gamec++;scanf("%char",&c);system("cls");
			}
		}
	}
	}return 0;
}
