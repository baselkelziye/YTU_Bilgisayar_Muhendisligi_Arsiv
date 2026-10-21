#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 200
double turevAl(double dizi[SIZE] , double xTurevYer , int derece);
double denklemSonucu(int denkDer , double arrDer[SIZE] , double x);
double sayisalTurev(double xKucuk , double xBuyuk , double fxKucuk , double fxBuyuk);
double sonucHesapla(int MevcutSatir , int BasDeger , int MatrisBoyut , double DegerDizi[SIZE] , double KatsayiMatris[SIZE][SIZE]);	
double ileriFarkMatrisi(double fxMatrisi[SIZE][SIZE] , int kokSayisi);
double ileriFarkBul(double fxMatrisi[SIZE][SIZE] , int ileriFarkNumarasi );
int faktoriyelBul(int k);
double carpimBul(double x1 , double x0 , double h , int kokSayisi , double sonucMatris[SIZE][SIZE] );
void denklemYazdir(double fxMatrisi[SIZE][SIZE] , int kokSayisi , double diziInput[SIZE] , double h);
int main() {
    srand(time(NULL));
	int menu;
	//Bisection
	int denkDer , ite , iteCount= 1 ,  i , j , k , dongu=1 , flag=0;
	double epsInput , x1Res , x2Res , x1 , x2 , epsSolution , temp , midSol , midSolLoc , pos, neg , arrDerTemp[SIZE] , arrDer[SIZE];
	//Regula Falsi

	double      midPointRes , midPointLoc  ,fPos , fNeg , fx1 , fx2 ;
	
	//Newton Raphson

	double    startPoint , startPointDiff , fStart ;
	//Matris Tersi
	int  size ;
	double matrisInput[SIZE][SIZE] , matrisUnit[SIZE][SIZE] , temp1 , temp2;
	//Gauss Eleminasyon
	int matrisBoyut , locMatris;
	double   diziKokler[SIZE] = {0} , kokTemp;
	//Gauss Seidel
	int absMaxLoc , loopControl;
	double  absMaxValue  , arrVar[SIZE] , eps , tempArrVar[SIZE] , mutlakDelta;
	//Sayýsal Türev
	int  sayisalTurevSecim;
	double merkeziTurevSonuc , farkDeger;
	//Simpson
	int	 simpsonSecim , parcaSayi ;
	double	 arrSonuc[SIZE] , alanToplam , tempToplam , tempLoc , aralikBuyukluk;
	//Trapez
	//Gregory Newton
	int kokSayisi;
	double diziInput[SIZE] , fxMatris[SIZE][SIZE] , Sonuc , h;

	
	
	while(dongu == 1){
		
		
		system("cls");
		printf("1.Bisection yontemi\n2.Regula-Falsi yontemi\n3.Newton-Raphson yontemi\n4.NxN'lik matrisin tersi\n5.Gauss Eleminasyon yontemi\n6.Gauss Seidel yontemi\n7.Sayisal Turev\n8.Simpson yontemi\n9.Trapez yontemi\n10.Degisken donusumsuz Gregory Newton Enterpolasyonu\n11.Cikis");
		printf("\n\nSeciminizi Yapiniz: ");
		scanf("%d",&menu);
	//	sleep(1);
		system("cls");
			switch(menu){
				//-----------------------------BÝSECTÝON BAÞLANGIÇ------------------------------------------------------------------------------------------------------------------------------
				case 1:{
		
					printf("* Bisection Yontemi *\n\nDenklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
					printf("Iterasyon Sayisini Giriniz : ");
					scanf("%d",&ite);
					ite++;
					printf("Hata Payini Giriniz : ");
					scanf("%lf",&epsInput);
					for(i=denkDer;i>=0;i-=1){
						for(i=denkDer;i>=0;i-=1){
							arrDerTemp[i]=arrDer[i];
						}
					}
					printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
					printf("Baslangic : ");
					scanf("%lf",&x1);
					printf("Bitis: ");
					scanf("%lf",&x2);
					x1Res=0;
					x2Res=0;
					x1Res = denklemSonucu(denkDer,arrDerTemp,x1);
					x2Res = denklemSonucu(denkDer,arrDerTemp,x2);
					
					if(x1Res * x2Res > 0){
						while(( x1Res < 0 && x2Res < 0) || ( x1Res > 0 && x2Res > 0)){
							printf("!! Girdiginiz Degerler Arasinda Bir Kok Bulunmamaktadir");
							printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
							printf("Baslangic : ");
							scanf("%lff",&x1);
							printf("Bitis: ");
							scanf("%lff",&x2);
							x1Res=0;
							x2Res=0;
							x1Res = denklemSonucu(denkDer,arrDerTemp,x1);
							x2Res = denklemSonucu(denkDer,arrDerTemp,x2);
						}
					}
					else if (x1Res * x2Res == 0){
						if(x1Res == 0 && x2Res == 0){
							printf("Girdiginiz Iki Deger De Bu Denklemin Kokleridir");
						}
						else if(x2Res == 0){
							printf("Bu Denklemin Bir Koku = %lf",x2);
						}
						else if(x1Res== 0){
							printf("Bu Denklemin Bir Koku = %lf",x1);
						}
					}
					else{
						if(x1Res > 0){
							pos = x1;
							neg = x2;
						}
						else if(x1Res < 0){
							pos = x2;
							neg = x1;
						}
							do{
								midSol = 0;
								midSolLoc = (pos + neg) / 2;
								midSol = denklemSonucu(denkDer,arrDerTemp,midSolLoc);
								epsSolution = (pos - neg) / (pow (2,iteCount));
								printf("Sonuc = %lf\t",midSol);
								printf("Ust = %lf  Alt = %lf\t",pos,neg);
						//		printf("\n\nepsSolution = (%lf + %lf) / (2 ussu %d)",pos,neg,iteCount);
								if(midSol > 0){
									pos = midSolLoc;
								}
								else if(midSol < 0){
									neg = midSolLoc;
								}
								
								
								
								printf("Yeni Tahmin = %lf\n",midSolLoc);
								
						//		printf("epsInput = %lf | epsSolution = %lf\n",epsInput,epsSolution);
								iteCount++;
								getch();
							}
							while( (epsSolution >= epsInput )&& (iteCount <= ite) && (midSol != 0));
							printf("Bu Denklemin Bir Koku = %2.6lf\n",midSolLoc);
						
						
					}
					break;
				}
				//-----------------------------BÝSECTÝON BÝTÝÞ----------------------------------------------------------------------------------------------------------------------------------
				//-----------------------------REGULA FALSÝ BAÞLANGIÇ---------------------------------------------------------------------------------------------------------------------------		
				case 2:{
					
					printf("* Regula-Falsi Yontemi *\n\nDenklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
						
					printf("Iterasyon Sayisini Giriniz : ");
					scanf("%d",&ite);
					ite++;
					printf("Hata Payini Giriniz : ");
					scanf("%lf",&epsInput);
					for(i=denkDer;i>=0;i-=1){
						for(i=denkDer;i>=0;i-=1){
							arrDerTemp[i]=arrDer[i];
						}
					}
					printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
					printf("Baslangic : ");
					scanf("%lf",&x1);
					printf("Bitis: ");
					scanf("%lf",&x2);
					fx1 = 0;
					fx2 = 0;
					fx1 = denklemSonucu(denkDer,arrDerTemp,x1);
					fx2 = denklemSonucu(denkDer,arrDerTemp,x2);
					
					if(fx1 * fx2 > 0){
						while(( fx1 < 0 && fx2 < 0) || ( fx1 > 0 && fx2 > 0)){
							printf("!! Girdiginiz Degerler Arasinda Bir Kok Bulunmamaktadir");
							printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
							printf("Baslangic : ");
							scanf("%lf",&x1);
							printf("Bitis: ");
							scanf("%lf",&x2);
							fx1=0;
							fx2=0;
							fx1 = denklemSonucu(denkDer,arrDerTemp,x1);
							fx2 = denklemSonucu(denkDer,arrDerTemp,x2);
						}
					}
					else if (fx1* fx2 == 0){
						if(fx1 == 0 && fx2 == 0){
							printf("Girdiginiz Iki Deger De Bu Denklemin Kokleridir");
						}
						else if(fx2 == 0){
							printf("Bu Denklemin Bir Koku = %lf",x2);
						}
						else if(fx1== 0){
							printf("Bu Denklemin Bir Koku = %lf",x1);
						}
					}
					else{
						if(fx1 > 0){
							pos = x1;
							fPos = fx1;
							neg = x2;
							fNeg = fx2;
						}
						else if(fx1 < 0){
							pos = x2;
							fPos = fx2;
							neg = x1;
							fNeg = fx1;
						}
						epsSolution = (pos + neg) / (pow (2,iteCount));
						
						if(epsSolution > epsInput){
							do{
								
								midPointLoc = ((neg * fPos) - (pos * fNeg)) / (fPos - fNeg);
								midPointRes = 0;
								midPointRes = denklemSonucu(denkDer,arrDerTemp,midPointLoc);
								
								printf("Sonuc = %lf\t",midPointRes);
								if(midPointRes > 0){
									pos = midPointLoc;
									fPos = midPointRes;
								}
								else if(midPointRes < 0){
									neg = midPointLoc;
									fNeg = midPointRes;
								}
								iteCount++;
								epsSolution = (pos + neg) / (pow (2,iteCount));
								printf("Yeni Tahmin = %lf\t",midPointLoc);
								printf("Ust = %lf  Alt = %lf\n\n",pos,neg);
								printf("Girilen Hata Payi = %lf  Mevcut Hata Payi = %lf\n\n",epsInput,epsSolution);
								getch();
							}
							while((epsInput < epsSolution) && (iteCount < ite) && (midPointRes != 0));
							printf("Bu Denklemin Bir Koku = %2.6lf\n",midPointLoc);
						}
						else{
							printf("Bu Denklemin Koku : %lf",epsSolution);
						}	
					}
					
					
					
			
					break;
				}
				//-----------------------------REGULA FALSÝ BÝTÝÞ-------------------------------------------------------------------------------------------------------------------------------
				//-----------------------------NEWTON RAPHSON BAÞLANGIÇ----------------------------------------------------------------------------------------------------------------------
				case 3:{
					
					printf("* Newton-Raphson Yontemi***\n\nDenklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
						
					printf("Iterasyon Sayisini Giriniz : ");
					scanf("%d",&ite);
					ite++;
					printf("Hata Payini Giriniz : ");
					scanf("%lf",&epsInput);
					for(i=denkDer;i>=0;i-=1){
						for(i=denkDer;i>=0;i-=1){
							arrDerTemp[i]=arrDer[i];
						}
					}
					printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
					printf("1. Nokta : ");
					scanf("%lf",&x1);
					printf("2. Nokta : ");
					scanf("%lf",&x2);
					printf("2 Nokta Arasinda Bir Baslangic Noktasi Seciniz :");
					scanf("%lf",&startPoint);
					fStart = 0;
					fx1=0;
					fx2=0;
					fx1 = denklemSonucu(denkDer,arrDerTemp,x1);
					fx2 = denklemSonucu(denkDer,arrDerTemp,x2);
					fStart = denklemSonucu(denkDer,arrDerTemp,startPoint);
					startPointDiff = turevAl(arrDer,startPoint,denkDer);
					printf("fx1 = %lf - fx2 = %lf - fStart = %lf\n",fx1,fx2,fStart);
					if(fx1 * fx2 > 0){
						while(( fx1 < 0 && fx2 < 0) || ( fx1 > 0 && fx2 > 0)){
							printf("!! Girdiginiz Degerler Arasinda Bir Kok Bulunmamaktadir");
							printf("\n\n!! Sirasiyla Araliklari Giriniz !!\n\n");
							printf("1. Nokta : ");
							scanf("%lf",&x1);
							printf("2. Nokta : ");
							scanf("%lf",&x2);
							printf("2 Nokta Arasinda Bir Baslangic Noktasi Seciniz :");
							scanf("%lf",&startPoint);
							fStart = 0;
							fx1=0;
							fx2=0;
							fx1 = denklemSonucu(denkDer,arrDerTemp,x1);
							fx2 = denklemSonucu(denkDer,arrDerTemp,x2);
							
						}
					}
					if (fx1* fx2 == 0){
						if(fx1 == 0 && fx2 == 0){
							printf("Girdiginiz Iki Deger De Bu Denklemin Kokleridir");
						}
						else if(fx2 == 0){
							printf("Bu Denklemin Bir Koku = %lf",x2);
						}
						else if(fx1== 0){
							printf("Bu Denklemin Bir Koku = %lf",x1);
						}
					}
					else if(fx1 * fx2 < 0){
						printf("Baslama Noktasi = %lf\tSonuc = %lf\n",startPoint,fStart);
						do{	
							temp = startPoint;
							startPoint = startPoint - ((fStart) / (startPointDiff));
							startPointDiff = turevAl(arrDer,startPoint,denkDer);
							fStart = denklemSonucu(denkDer,arrDerTemp,startPoint);
							
							
							
							printf("Yeni Tahmin = %lf\tSonuc = %lf\n",startPoint,fStart);
						//	printf("fabs = %lf | epsInput = %lf \n",fabs(startPoint - temp),epsInput);
							
							iteCount++;
							getch();
						}
						while((iteCount < ite) && ( fabs(startPoint - temp) > epsInput ));
						printf("Bu Denklemin Bir Koku = %2.6f\n",startPoint);
					}
					break;
				}
				//-----------------------------NEWTON RAPHSON BÝTÝÞ----------------------------------------------------------------------------------------------------------------------
				//-----------------------------MATRÝSÝN TERSÝ BAÞLANGIÇ-------------------------------------------------------------------------------------------------------------------------
				case 4:{
					
					printf ("* NxN Matrisin Tersini Alma *\n\nMatrisin Boyutunu Giriniz: ");
					scanf("%d",&size);
					for(i = 0 ; i < size ; i++){
						for(j = 0 ; j < size ; j++){
							printf("%d - %d : ",i+1,j+1);
							scanf("%lf",&matrisInput[i][j]);
							if(j == i){
								matrisUnit[i][j] = 1;
							}
							else{
								matrisUnit[i][j] = 0;
							}
						}
					}
				
					printf("\nMevcut Matris : \n\n");
					for(i = 0 ; i < size ; i++){
						for(j = 0 ; j < (size) ; j++){
							printf("%lf  ",matrisInput[i][j]);      //MATRÝSÝ YAZDIRMA
						}
						printf("\n");
					}
				
					printf("\n\n");
					for(i=0;i<size;i++){
						temp1 = matrisInput[i][i];
						for(j=0;j<size;j++){
							matrisInput[i][j] = matrisInput[i][j] / temp1;
							matrisUnit[i][j] = matrisUnit[i][j] / temp1;
							if (temp1 == 0){
								flag = 1;
							}
						}
						for(j=0;j<size;j++){
							if(j != i){
								temp2  = matrisInput[j][i];
								for(k=0;k<size;k++){
									matrisInput[j][k] = matrisInput[j][k] - (temp2 * matrisInput[i][k]);
									matrisUnit[j][k] = matrisUnit[j][k] - (temp2 * matrisUnit[i][k]);
								}
							}
						}
					}
					if(flag == 0){
						printf("\n\nTers Matris:\n\n");
						for(i = 0 ; i < size ; i++){
							for(j = 0 ; j < (size) ; j++){
								printf("%lf  ",matrisUnit[i][j]);      //MATRÝSÝ YAZDIRMA
							}
							printf("\n");
						}
					}
					else if(flag == 1){
						printf("\n**** Girdiginiz Matrisin Tersi Bulunmamaktadir ****\n");
					}
					
					
					break;
				}
				//-----------------------------MATRÝSÝN TERSÝ BÝTÝÞ-------------------------------------------------------------------------------------------------------------------------	
				//-----------------------------GAUSS ELEMÝNASYON BAÞLANGIÇ------------------------------------------------------------------------------------------------------------------------
				case 5:{
					printf("* GAUSS ELEMINASYON YONTEMI *\n\n");
					printf("Katsayilar Matrisin Boyutunu Giriniz : ");
					scanf("%d",&matrisBoyut);
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j < matrisBoyut ; j++){
							printf("%d. Denklemin %d. Degiskeninin Katsayisi : ",i+1,j+1);
							scanf("%lf",&matrisInput[i][j]);
						}
					}
					for(i=0;i<matrisBoyut;i++){
						printf("%d. Denklemin Sonucu = ",i+1);
						scanf("%lf",&matrisInput[i][matrisBoyut]);
					}
					printf("Matrisin Ilk Hali :\n\n");
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j <= matrisBoyut ; j++){
							printf("%lf   ",matrisInput[i][j]);
						}
						printf("\n");
					}
					for(i=0;i<matrisBoyut;i++){
						for(j=i;j<matrisBoyut;j++){
							temp1 = matrisInput[j][i];
							for(k=0;k<=matrisBoyut;k++){
								//	printf("\ni = %d - j = %d - k = %d\n",i+1,j+1,k+1);
								if(j == i){
									matrisInput[j][k] = matrisInput[j][k] / temp1;
								//	printf("%d. Satiri matris[%d][%d]'ye böl\n\n",j+1,j+1,i+1);
								}
								else{
									
									matrisInput[j][k] = matrisInput[j][k] / temp1;
									matrisInput[j][k] = matrisInput[j][k] - matrisInput[i][k];
									matrisInput[j][k] = matrisInput[j][k] * temp1;
								//	printf("%d. Satiri matris[%d][%d] bol\n%d. Satirdan %d. Satiri Cikar ve %d. Satiri matris[%d][%d] ile carp\n\n",j+1,j+1,+i+1,j+1,i+1,j+1,j+1,i+1);
								}
							}
						}
					}
					printf("\n\nMatrisin Son Hali :\n\n");
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j <= matrisBoyut ; j++){
							printf("%lf   ",matrisInput[i][j]);
						}
						printf("\n");
					}
					
					diziKokler[matrisBoyut-1] = matrisInput[matrisBoyut-1][matrisBoyut];
					for(i = matrisBoyut-1 ; i >= 0 ; i-=1){
					//	locMatris = matrisBoyut-1; 
						j=matrisBoyut-1;
						kokTemp = matrisInput[i][matrisBoyut];
						while( j != i ){
					//		printf("\n%lf - ( %lf  * %lf )yapildi\n",kokTemp,matrisInput[i][j],diziKokler[j]);
							kokTemp = kokTemp - (matrisInput[i][j] * diziKokler[j] );
					
							j=j-1;
						}
						diziKokler[i] = kokTemp;
						printf("\n%d . Kok = %lf\n",i+1,diziKokler[i]);
					}
					break;
				}
				//-----------------------------GAUSS ELEMÝNASYON BÝTÝÞ------------------------------------------------------------------------------------------------------------------------
				//-----------------------------GAUSS SEÝDEL BAÞLANGIÇ------------------------------------------------------------------------------------------------------------------------
				case 6:{
					printf("* GAUSS SEIDEL YONTEMI *\n\n");
					printf("Katsayilar Matrisin Boyutunu Giriniz : ");
					scanf("%d",&matrisBoyut);
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j < matrisBoyut ; j++){
							printf("%d. Denklemin %d. Degiskeninin Katsayisi : ",i+1,j+1);
							scanf("%lf",&matrisInput[i][j]);
						}
					}
					for(i=0;i<matrisBoyut;i++){
						printf("%d. Denklemin Sonucu = ",i+1);
						scanf("%lf",&matrisInput[i][matrisBoyut]);
					}
					printf("Matrisin Ilk Hali :\n\n");
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j <= matrisBoyut ; j++){
							printf("%lf   ",matrisInput[i][j]);
						}
						printf("\n");
					}
					for(i=0 ; i<matrisBoyut-1 ; i++){
						absMaxValue = fabs(matrisInput[i][i]);
						absMaxLoc = i;
						for(j=i+1 ; j<matrisBoyut ; j++){
							if(abs(matrisInput[j][i]) > absMaxValue){
								absMaxLoc = j;
								absMaxValue = fabs(matrisInput[j][i]);
							}
						}
						for(j=0 ; j<=matrisBoyut ; j++){
							temp = matrisInput[i][j];
							matrisInput[i][j] = matrisInput[absMaxLoc][j];
							matrisInput[absMaxLoc][j] = temp;
						}
					}
					printf("\nMatrisin Duzenlenmis Hali :\n\n");
					for(i = 0 ; i < matrisBoyut ; i++){
						for(j = 0 ; j <= matrisBoyut ; j++){
							printf("%lf   ",matrisInput[i][j]);
						}
						printf("\n");
					}
					for(i=0 ; i<matrisBoyut ; i++){
						printf("%d. Degiskenin Baslangic Degerini Giriniz :",i+1);
						scanf("%lf",&arrVar[i]);
					}
					printf("\nHata Payini Giriniz : ");
					scanf("%lf",&eps);
					loopControl = 0;
					while(loopControl != matrisBoyut ){
						loopControl = 0;
						for(i=0 ; i<matrisBoyut ; i++){
							tempArrVar[i]=arrVar[i];
							arrVar[i] = sonucHesapla(i,i,matrisBoyut,arrVar,matrisInput);
							printf("%d. Degisken = %lf  -  ",i+1,arrVar[i]);
						}
						for(i=0 ; i<matrisBoyut ; i++){
							mutlakDelta = fabs(arrVar[i] - tempArrVar[i]);
							printf("%d. Degiskenin Deltasi = %lf   -   ",i+1,mutlakDelta);
							if( ( mutlakDelta ) <= eps){
								loopControl++;
							}
						}
						printf("\n\n");
					}
					
					break;
				}
				//-----------------------------GAUSS SEÝDEL BÝTÝÞ------------------------------------------------------------------------------------------------------------------------
				//-----------------------------SAYISAL TÜREV BAÞLANGIÇ-------------------------------------------------------------------------------------------------------------------------	
				case 7:{
					
					printf("*** Sayisal Turev ***\n\n");
					printf("Denklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
					printf("Turevini Hesaplamak Istediginiz Noktayi Giriniz :");
					scanf("%lf",&x1);
					fx1 = denklemSonucu(denkDer,arrDer,x1);
					printf("Ileri(1) Geri(2) Veya Merkezi(3) Farktan Birisini Seciniz = ");
					scanf("%d",&sayisalTurevSecim);
					if(sayisalTurevSecim == 1){
						printf("Ileri Farkýn Degerini Giriniz :");
						scanf("%lf",&farkDeger);
						x2 = x1 + farkDeger;
						fx2 = denklemSonucu(denkDer,arrDer,x2);
						printf("Yapilan Islem ==> (%lf - %lf ) / (%lf - %lf)\n\n",fx2,fx1,x2,x1);
						merkeziTurevSonuc = sayisalTurev(x2,x1,fx2,fx1);
						printf("Sayisal Turevin Sonucu = %lf",merkeziTurevSonuc);
					}
					else if(sayisalTurevSecim == 2){
						printf("Geri Farkýn Degerini Giriniz :");
						scanf("%lf",&farkDeger);
						
						x2 = x1 - farkDeger;
						fx2 = denklemSonucu(denkDer,arrDer,x2);
						printf("Yapilan Islem ==> (%lf - %lf ) / (%lf - %lf)\n\n",fx1,fx2,x1,x2);
						merkeziTurevSonuc = sayisalTurev(x1,x2,fx1,fx2);
						printf("Sayisal Turevin Sonucu = %lf",merkeziTurevSonuc);
						
					}
					else if(sayisalTurevSecim == 3){
						printf("Merkezi Farkýn Degerini Giriniz :");
						scanf("%lf",&farkDeger);
					//	printf("x1 once = %lf\n",x1);
						x1 = x1 + (farkDeger/2);
					//	printf("x1 sonra = %lf",x1);
						x2 = x1 - (farkDeger);
						fx1 = denklemSonucu(denkDer,arrDer,x1);
						fx2 = denklemSonucu(denkDer,arrDer,x2);
						printf("Yapilan Islem ==> (%lf - %lf ) / (%lf - %lf)\n\n",fx1,fx2,x1,x2);
						merkeziTurevSonuc = sayisalTurev(x1,x2,fx1,fx2);
						printf("Sayisal Turevin Sonucu = %lf",merkeziTurevSonuc);
					}
					
					break;
				}
				//-----------------------------SAYISAL TÜREV BÝTÝÞ-------------------------------------------------------------------------------------------------------------------------	
				//-----------------------------SIMPSON BAÞLANGIÇ-------------------------------------------------------------------------------------------------------------------------	
				case 8:{
					
					printf("* Simpson Yontemi *\n\nDenklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
					printf("* Simpson 1/3 (1) Simpson 3/8 (2) *\nSecim Yapiniz :");
					scanf("%d",&simpsonSecim);
					if(simpsonSecim == 1){
						system("cls");
						printf("* Simpson 1/3 Yontemi *\n\n");
						printf("Alanini Hesaplamak Istediginiz Aralýgý Giriniz\nx1 =");
						scanf("%lf",&x1);
						printf("x2 =");
						scanf("%lf",&x2);
						do{
							printf("\nn degerini giriniz = ");
							scanf("%d",&parcaSayi);
						}
						while(parcaSayi % 2 != 0);
						aralikBuyukluk = ( x2 - x1 ) / ( parcaSayi );
						tempLoc=x1;
						printf("%lf",tempLoc);
						for(i=0 ; i<=parcaSayi ; i++){
							
							arrSonuc[i] = 0;
							arrSonuc[i] = denklemSonucu(denkDer,arrDer,tempLoc); 
							tempLoc = tempLoc + aralikBuyukluk;
							printf("\n%lf",tempLoc);
						}
						printf("\n\n");
						alanToplam = 0;
						j=0;
						for(i=0 ; i<parcaSayi ; i=i+2){
							
							tempToplam=0;
							printf("Yapilan Islem = %lf / 3 * (y%d + 4*y%d + y%d)\n",aralikBuyukluk,i,i+1,i+2);
							printf("Yapilan Islem = %lf / 3 * (%lf + 4*%lf + %lf)\n",aralikBuyukluk,arrSonuc[i],arrSonuc[i+1],arrSonuc[i+2]);
							printf("----------------------------------------------\n");
							tempToplam = (aralikBuyukluk / 3) * (arrSonuc[i] + 4 * arrSonuc[i+1] + arrSonuc[i+2]);
							alanToplam = alanToplam + tempToplam;
							
						}
						printf("* Sonuc = %lf *",alanToplam);
						
					}	
					else if(simpsonSecim == 2){
						system("cls");
						printf("* Simpson 3/8 Yontemi *\n\n");
						printf("Alanini Hesaplamak Istediginiz Aralýgý Giriniz\nx1 =");
						scanf("%lf",&x1);
						printf("x2 =");
						scanf("%lf",&x2);
				//		do{
							printf("\nn degerini giriniz = ");
							scanf("%d",&parcaSayi);
				//		}
				//		while(parcaSayi % 2 != 0);
						aralikBuyukluk = ( x2 - x1 ) / ( 3 );
						tempLoc=x1;
						printf("%lf",tempLoc);
						for(i=0 ; i<=parcaSayi+1 ; i++){
							
							arrSonuc[i] = 0;
							arrSonuc[i] = denklemSonucu(denkDer,arrDer,tempLoc); 
							tempLoc = tempLoc + aralikBuyukluk;
							printf("\n%lf",tempLoc);
						}
						printf("\n\n");
						alanToplam = 0;
						
						for(i=0 ; i<parcaSayi ; i=i+3){
							
							tempToplam=0;
							printf("Yapilan Islem = %lf / 3 * (y%d + 3*y%d + 3*y%d + y%d)\n",aralikBuyukluk,i,i+1,i+2,i+3);
							printf("Yapilan Islem = %lf / 3 * (%lf + 3*%lf + 3*%lf + %lf)\n",aralikBuyukluk,arrSonuc[i],arrSonuc[i+1],arrSonuc[i+2],arrSonuc[i+3]);
							printf("----------------------------------------------\n");
							tempToplam = ((x2 - x1) / 8) * (arrSonuc[i] + 3 * arrSonuc[i+1] + 3 * arrSonuc[i+2] + arrSonuc[i+3]);
							alanToplam = alanToplam + tempToplam;
						}
						printf("* Sonuc = %lf *",alanToplam);
					}
					break;
				}
				//-----------------------------SIMPSON BÝTÝÞ-------------------------------------------------------------------------------------------------------------------------	
				//-----------------------------TRAPEZ BAÞLANGIÇ-------------------------------------------------------------------------------------------------------------------------	
				case 9:{
					
					
					printf("* Trapez Yontemi *\n\nDenklemin Derecesini Giriniz : ");
					scanf("%d",&denkDer);
					for(i=denkDer;i>=0;i-=1){
						if(i == 0){
							printf("Sabit Terimi Giriniz: ");
							scanf("%lf",&arrDer[i]);
						}
						else{
							printf("Denklemin %d. Derecesinin Katsayisini Giriniz : ",i);
							scanf("%lf",&arrDer[i]);
						}
					}
					printf("Alanini Hesaplamak Istediginiz Aralýgý Giriniz\nx1 =");
					scanf("%lf",&x1);
					printf("x2 = ");
					scanf("%lf",&x2);
					printf("\nAraligi Bolmek Istediginiz Parca Sayisi = ");
					scanf("%d",&parcaSayi);
					aralikBuyukluk = ( x2 - x1 ) / ( parcaSayi );
					tempLoc=x1;
					for(i=0 ; i<=parcaSayi ; i++){
						arrSonuc[i] = 0;
						arrSonuc[i] = denklemSonucu(denkDer,arrDer,tempLoc); 
						tempLoc = tempLoc + aralikBuyukluk;
					}
				
					printf("\n");
					alanToplam = 0;
					for(i=0 ; i<parcaSayi ; i++){
						alanToplam = alanToplam + ( (aralikBuyukluk / 2 ) * (arrSonuc[i] + arrSonuc[i+1]));
					}
					printf("\n\nAlan Toplami = %lf",alanToplam);
					
					break;
				}
				//-----------------------------TRAPEZ BÝTÝÞ-------------------------------------------------------------------------------------------------------------------------		
				//----------------------------GREGORY NEWTON ENTERPOLASYONU BAÞLANGIÇ------------------------------------------------------------------------------------------------------------------------
				case 10:{
					
					printf("* Gregory Newton Enterpolasyonu *\n\n");
					printf("Kok Sayisini Giriniz: ");
					scanf("%d",&kokSayisi);
					printf("\n\n**  Kokleri !! Esit Araliklarla !! Giriniz  **\n\n");
					for(i=0 ; i<kokSayisi ; i++){
						printf("1 - %d = ",i+1);
						scanf("%lf",&diziInput[i]);
					}
					printf("\n** Sirasiyla Sonuclari Giriniz **\n");
					for(i=0 ; i<kokSayisi ; i++){
						printf("1 - %d = ",i+1);
						scanf("%lf",&fxMatris[0][i]);
					}
					ileriFarkMatrisi(fxMatris,kokSayisi);
					for(i=0 ; i<kokSayisi ; i++){
						//for(j=0 ; j<kokSayisi-i ; j++){
							printf("%d. ileri fark = %lf  |   ",i,fxMatris[i][0]);
					//	}
						printf("\n");
					}
					h = diziInput[1] - diziInput[0];
					denklemYazdir(fxMatris,kokSayisi,diziInput,h);
					printf("\n\nSonucunu Aradiginiz Degeri Giriniz : ");
					scanf("%lf",&x1);
				
				//	printf("\nh = %lf - %lf",diziInput[1],diziInput[0]);
					Sonuc = fxMatris[0][0];
				//	printf("\nSonucun Baslangic Degeri = %lf",Sonuc);
					Sonuc = Sonuc + carpimBul(x1,diziInput[0],h,kokSayisi,fxMatris);
					printf("\n\nSonuc = %lf",Sonuc);
					break;
				}
				//---------------------------GREGORY NEWTON ENTERPOLASYONU BÝTÝÞ------------------------------------------------------------------------------------------------------------------------------			
				//---------------------------ÇIKIÞ-------------------------------------------------------------------------------------------------------------------------------------------
				case 11:{
					dongu = 0;
					break;
				}
						
			}
			printf("\nDevam Etmek Icin Enter'a Basiniz");
			getch();
		}
		
		
		return 0;
	}
	
	
double turevAl(double dizi[SIZE] , double xTurevYer , int derece){
	int i;
	double xTurevSonuc;
	xTurevSonuc = 0;
	for(i=derece;i>=1;i-=1){
		xTurevSonuc = xTurevSonuc + (dizi[i] * i * pow(xTurevYer , i-1));
	}
	return xTurevSonuc;
}
double denklemSonucu(int denkDer , double arrDer[SIZE] , double x){
	int i;
	double xRes = 0;
	for(i=denkDer;i>=0;i-=1){
		xRes = xRes + (arrDer[i] * pow(x , i));
	}
	return xRes;
}
double sayisalTurev(double xKucuk , double xBuyuk , double fxKucuk , double fxBuyuk){
	double turevSonuc;
	turevSonuc = (fxBuyuk - fxKucuk) / (xBuyuk - xKucuk);
	return turevSonuc;
}
double sonucHesapla(int MevcutSatir , int BasDeger , int MatrisBoyut , double DegerDizi[SIZE] , double KatsayiMatris[SIZE][SIZE]){
	double Sonuc , temp;
	int i;
	temp = KatsayiMatris[MevcutSatir][MatrisBoyut];
	for(i=0 ; i<MatrisBoyut ; i++){
		if(i != BasDeger){
			temp = temp - ( KatsayiMatris[MevcutSatir][i] * DegerDizi[i] );
			
		}
	}
	Sonuc = (temp / KatsayiMatris[MevcutSatir][BasDeger] );	
	return Sonuc;
}
double ileriFarkMatrisi(double fxMatrisi[SIZE][SIZE] , int kokSayisi){
	int i , j=0;
	int temp;
	temp = (kokSayisi / 2) +1 ;
	while(temp!= 0){
		for(j=0 ; j<kokSayisi-1 ; j++){
			fxMatrisi[i+1][j] = fxMatrisi[i][j+1] - fxMatrisi[i][j];
		}
		i++;
		temp = temp-1;
	}
	fxMatrisi[kokSayisi-1][0] = fxMatrisi[kokSayisi-2][1] - fxMatrisi[kokSayisi-2][0];	
}
double ileriFarkBul(double fxMatrisi[SIZE][SIZE] , int ileriFarkNumarasi ){
	int i;
	double Sonuc;
	Sonuc = fxMatrisi[ileriFarkNumarasi][0];
	return Sonuc;
}
int faktoriyelBul(int k){
	int j;
	int Sonuc=1;
	if((k == 0) || (k == 1)){
		return 1;
	}
	else{
		for(j = k ; j>0 ; j=j-1){
			Sonuc = Sonuc * j;
		}
		return Sonuc;
	}
	
}
double carpimBul(double x1 , double x0 , double h , int kokSayisi , double sonucMatris[SIZE][SIZE] ){
	int i ,j ;
	double toplam= 0,temp=1;
	for(i=1 ; i<kokSayisi ; i++){
		temp=1;
		for(j=0 ; j<i ; j++){
		//	printf("\nYapilan Islem = %lf * %lf\n",temp,( ( x1 - x0 - (h*j) ) / h ));
			temp = temp *  ( ( x1 - x0 - (h*j) ) / h );
			
		//	printf("Yapilan Islem = temp * ( ( %lf - %lf - ( %lf * %d ) ) / %lf) \n\n",x1,x0,h,j,h);
		}
		temp = ( temp *  ( sonucMatris[i][0] ) ) / ( faktoriyelBul(i) );
	//	printf("2. Yapilan Islem = ( temp * ( %lf ) ) / %d\n\n",sonucMatris[i][0],faktoriyelBul(i));
		toplam = toplam + temp;
	//	printf("-------------------------------------------------------------------------------\n");
	}
	return toplam;
}
void denklemYazdir(double fxMatrisi[SIZE][SIZE] , int kokSayisi , double diziInput[SIZE] , double h){
	int i , j , k;
	int counter = 0;
	int loop = 1;
		i=0;
		j=-1;
		while( loop == 1 ){
			loop=0;
			j++;
			for(i = j ; i<kokSayisi ; i++){
		//		printf("%lf  ",fxMatrisi[i][0]);
				if(fxMatrisi[i][0] != 0 ){
					loop = 1;
				} 
			}
	//		printf("\n");
			
		}
		
		printf("\n*** Denklem ***\n\n");
		for(i=0 ; i<j ; i++){
			if ( i == 0 ){
				printf("%lf + ",fxMatrisi[i][0]);
			}
			else if( i == 1 ){
				printf("(x - %lf) * %lf / %lf ",diziInput[i-1],fxMatrisi[i][0],h);
			}
			else{
				printf(" + ( ");
				for(k=0 ; k<i ; k++){
					printf("(x - %lf) +",diziInput[k]);
				}
				printf("\b)");
				printf(" / %lf * (%lf / %d)",pow(h,i),fxMatrisi[i][0],faktoriyelBul(i));
			}
		}
}
