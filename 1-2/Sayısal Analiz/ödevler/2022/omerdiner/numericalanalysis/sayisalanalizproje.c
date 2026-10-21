#include <stdio.h>
#include <math.h>
#define MAX 20
#define SIZE 15

typedef struct terim{
	int derece;
	double katsayi;
}TERIM;

double polinomuHesapla(TERIM polinom[MAX],double x,int derece);
int polinomuAl(TERIM polinom[MAX]);
void bisection();
void regulaFalsi();
void newtonRaphson();
void sayisalTurev();
void trapezYontemi();
void simpsonYontemi();
void matrisinTersi();
void gaussSeidal();
void gaussEliminasyon();
void gregoryNewtonEnterpolasyon();
double klarCarpimi(double x, int n,int x0,int h);
int faktoriyel(int n);

int main(){

    int devamMi=1;
	
    while(devamMi==1){
    	int yontem;
    	printf("\nHangi yontemi denemek istersiniz?:");
    	printf("\n1.Bisection\n2.Regula Falsi\n3.Newton Raphson\n4.Matrisin Tersi\n5.Gauss Eliminasyon\n6.Gauss Seidal\n7.Sayisal Turev\n8.Simpson Yontemi\n9.Trapez Yontemi\n10.Gregory Newton\n");
    	printf("0.Cikis");
    	printf("\nSeciminiz:");
    	scanf("%d",&yontem);
    	
    	switch(yontem){
    		case 1:bisection();
    		       break;
    		case 2:regulaFalsi();
			       break;  
		    case 3:newtonRaphson();
			       break;   
		    case 4:matrisinTersi();
			       break;  
		    case 5:gaussEliminasyon();
		           break;
    	    case 6:gaussSeidal();
    	           break;
			case 7:sayisalTurev();
			       break;
			case 8:simpsonYontemi();
			        break;	
			case 9:trapezYontemi();
			       break;        
			case 10:gregoryNewtonEnterpolasyon();
			        break;          
					 
			case 0:printf("Program sonlaniyor.");
			       devamMi=0;
				   break;       	   	   
		    default:printf("Yanlis bir secim girdiniz.");     
		}
	}
  return 0;
}


int polinomuAl(TERIM polinom[MAX]){
	int i,derece;
	printf("Kacinci dereceden bir polinom gireceksiniz?:");
	scanf("%d",&derece);
	
	for(i=0;i<=derece;i++){
		printf("%d. inci terimin derecesini giriniz:",i+1);
		scanf("%d",&polinom[i].derece);
		printf("%d. inci terimin katsayisini giriniz:",i+1);
		scanf("%lf",&polinom[i].katsayi);
	}
	
	return derece;
	

}

double polinomuHesapla(TERIM polinom[MAX],double x,int derece){
	double toplam=0.0;
	double carpan;
	int i,j;
	for(i=0;i<=derece;i++){
		carpan=1.0;
		for(j=0;j<polinom[i].derece;j++){
			carpan=carpan*x;
		}
		toplam=toplam+(polinom[i].katsayi*carpan);	
	}
	return toplam;
}

void bisection(){

	
	int iterasyon;
	double hataPayi,a,b,c;
	TERIM polinom[MAX];
    int derece=	polinomuAl(polinom);
	iterasyon=0;
	
	printf("Hata payini giriniz:");
	scanf("%lf",&hataPayi);
	
	
	//kok olmasi için verilen degerler carpimi negatif olmali
		do{
	printf("Araligin baslangic degerini giriniz:");
	scanf("%lf",&a);
	
	printf("Araligin bitis degerini giriniz:");
	scanf("%lf",&b);	
	}while(polinomuHesapla(polinom,a,derece)*polinomuHesapla(polinom,b,derece)>0);
	
		do{    

		    double Fa=polinomuHesapla(polinom,a,derece);
		    double Fb=polinomuHesapla(polinom,b,derece);
		    
		    c=(a+b)/2;  //orta deger
		    double Fc=polinomuHesapla(polinom,c,derece);
	          
	          //carpimin negatif geldiði araliktan devam ederiz
	          
            if (Fa*Fc < 0) {  //bu if olursa aralik sola kayiyor
                b=c;                   
            }else if(Fa*Fc > 0){  //bu ifte aralik saga kayiyor
                a=c;
            }
            iterasyon++;
            
           
	}while((b - a) / pow(2, iterasyon) > hataPayi);    

        printf("\nYakinsanan kok: %lf ",c);
        
}

void regulaFalsi(){
	int iterasyon;
	double hataPayi,a,b,c;
	TERIM polinom[MAX];
    int derece=	polinomuAl(polinom);
   	iterasyon=0;
   	
   	printf("Hata payini giriniz:");
	scanf("%lf",&hataPayi);
	
		//kok olmasi için verilen degerler carpimi negatif olmali
	do{
	printf("Araligin baslangic degerini giriniz:");
	scanf("%lf",&a);
	
	printf("Araligin bitis degerini giriniz:");
	scanf("%lf",&b);	
	}while(polinomuHesapla(polinom,a,derece)*polinomuHesapla(polinom,b,derece)>0);

	
	do{    

		    double Fa=polinomuHesapla(polinom,a,derece);
		    double Fb=polinomuHesapla(polinom,b,derece);
		    
		    c=(a*Fb-b*Fa)/(Fb-Fa);    //yeni kokun formulu
		    double Fc=polinomuHesapla(polinom,c,derece);
	
	    // carpimin negatif olduðu araliktan devam ederiz
            if (Fa*Fc < 0) {
                b=c;
            }else if(Fa*Fc > 0){
                a=c;
            }
            iterasyon++;
            
	}while((b - a) / pow(2, iterasyon) > hataPayi);
	
        
        printf("\nYakinsanan kok: %lf ",c);
}

void newtonRaphson(){
	int iterasyon;
	double hataPayi,a;
	TERIM polinom[MAX];
	TERIM turev[MAX];
	double eskiDeger,yeniDeger;
    int derece=	polinomuAl(polinom);
    printf("\n---Girdiginiz polinomun turevini giriniz:--\n");
    int derece2=polinomuAl(turev); 
	int cikilsinMi=0;
	
	printf("\nHata payini giriniz:");
	scanf("%lf",&hataPayi);
	
	printf("Araligin baslangic degerini giriniz:");
	scanf("%lf",&a);	
	
	eskiDeger=a;
	
		do{    

		    double Fpolinom=polinomuHesapla(polinom,eskiDeger,derece);   //polinomdan gelen deger	
		    double Fturev=polinomuHesapla(turev,eskiDeger,derece2);   // turevinden gelen deger
		    
		    yeniDeger=eskiDeger-(Fpolinom/Fturev);  // formul :  x1= x0 - (f / fturev)
		    
		    
            if(yeniDeger-eskiDeger>hataPayi){     //hata payindan buyuk hata varsa eski degeri yeni deger yaparak iterasyona devam
            	eskiDeger=yeniDeger;
			}else{   // hata payindan küçükse  çýkmak için degeri 1 yapýyoruz
				cikilsinMi=1;
			}
            
	}while(cikilsinMi==0);

        printf("\nYakinsanan kok: %lf ",yeniDeger);
}
void sayisalTurev(){
	
	int secim;
	double x,h,turev;
	TERIM polinom[MAX];
    int derece=	polinomuAl(polinom);
	
	printf("\nHangi yontem ile turevi hesaplamak istiyorsunuz?(1.Geri Farklar 2.Ileri Farklar 3.Merkezi Farklar):");
	scanf("%d",&secim);	
	printf("\nHangi noktadaki turev degerini hesaplamak istiyorsunuz?:");
	scanf("%lf",&x);
	printf("h degerini giriniz:");
	scanf("%lf",&h);
	
	
	switch(secim){
		case 1: turev=(polinomuHesapla(polinom,x,derece)-polinomuHesapla(polinom,x-h,derece))/h;//geri fark yöntemi   f(x) - f(x-h)  / h
                break;
		case 2:	turev=(polinomuHesapla(polinom,x+h,derece)-polinomuHesapla(polinom,x,derece))/h;//ileri fark yöntemi   f(x+h) - f(x)  / h
		        break;	 
		case 3:turev=(polinomuHesapla(polinom,x+h,derece)-polinomuHesapla(polinom,x-h,derece))/(2.0*h);//merkezi fark yöntemi   f(x+h) - f(x-h)  / 2h
		        break;  
		
		default: printf("Yanlis secim.");		      
	}
	
	printf("\nSayisal olarak hesaplanan turev degeri:%lf\n",turev);


}
void trapezYontemi(){
	double integral,xi,a,b,h,yToplam=0;
	int i,n;
	TERIM polinom[MAX];
    int derece=	polinomuAl(polinom);
	
		
	printf("\nIntegralin alt sinirini giriniz:");
	scanf("%lf",&a);
	
	printf("\nIntegralin ust sinirini giriniz:");
	scanf("%lf",&b);
	
	printf("\n n degerini giriniz:");
	scanf("%d",&n);	
	
	h=(b-a)/n;    // x ler arasi aralik
	xi=a;      // baslangic x i
	
	yToplam=yToplam+(polinomuHesapla(polinom,a,derece)+polinomuHesapla(polinom,b,derece))/2.0;   // ilk ve son degerler toplamnýn yarýsý ana toplama ekleniyor
	for(i=1;i<=n-1;i++){
		xi=xi+h;
		yToplam=yToplam+polinomuHesapla(polinom,xi,derece);    // ara degerler ana toplama ekleniyor
	}
	
	integral=h*yToplam;   // ana toplam aralik degeri ile çarpýlýyor
	
	printf("\nTrapez yontemiyle hesaplanan integral degeri:%lf",integral);
	
}

void simpsonYontemi(){
	double integral,xi,a,b,h,yToplam=0;
	int i,n;
	TERIM polinom[MAX];
    int derece=	polinomuAl(polinom);
	
		
	printf("\nIntegralin alt sinirini giriniz:");
	scanf("%lf",&a);
	
	printf("\nIntegralin ust sinirini giriniz:");
	scanf("%lf",&b);
	do{
		printf("\n n degerini giriniz:");
	    scanf("%d",&n);	
	}while(n%2!=0);    // bu yontemde aralik sayisi cift olmalý
	
	
	h=(b-a)/n;  // aralik mesafesi
	xi=a;
	
	yToplam=yToplam+(polinomuHesapla(polinom,a,derece)+polinomuHesapla(polinom,b,derece));   // ana toplama ilk ve son deger ekleniyor
	for(i=1;i<=n-1;i++){
		xi=xi+h;
		if(i%2==1){
			yToplam=yToplam+4.0*polinomuHesapla(polinom,xi,derece);// ara degerler tek indisli ise 4 ile çarpýlarak ekleniyor
		}else{
			yToplam=yToplam+2.0*polinomuHesapla(polinom,xi,derece);// ara degerler cift indisli ise 2 ile çarpýlarak ekleniyor
		}
	
	}
	
	integral=(h/3.0)*yToplam;    // ana toplam  h/3 ile çarpýlarak sonuc çýkýyor
	
	printf("\nSimpson yontemiyle hesaplanan integral degeri:%lf",integral);
}

void gaussSeidal(){
    double denklem[SIZE][SIZE],degerler[SIZE],tmp[SIZE];
    double hataPayi,toplam;
    int n,i,j,k;
    int iterasyon=0;
    int hataKontrol=1;
    
    printf("Denklem sayisi:");
    scanf("%d",&n);
    printf("Hata payi:");
    scanf("%lf",&hataPayi);
    
	
    for(i=1;i<=n;i++)
    { 
        printf("%d. denklemin bilinmeyenlerinin katsayilarini giriniz:",i);
        for(j=1;j<=n;j++){
        	 scanf("%lf",&denklem[i][j]);
		}
           
        printf("\n");
    }
    
    printf("Sonuc sutununu giriniz:");
    for(i=1;i<=n;i++){	
    	scanf("%lf",&denklem[i][n+1]);
	}
	
    printf("Bilinmeyenlerin baslangic degerini sirayla giriniz(x1,x2.....)=");
    for(i=1;i<=n;i++){
    	scanf("%lf",&degerler[i]);
	}
	// matrisi kosegenlere mutlak olarak en büyük sayýlar gelcek þekilde deðiþtirmek için
    for(i=1;i<=n;i++){
		for(k=i+1;k<=n;k++){
		    if(abs(denklem[i][i])<abs(denklem[k][i])){
		    	for(j=1;j<=n+1;j++){
		    		double tmp=denklem[i][j];
		    		denklem[i][j]=denklem[k][j];
		    		denklem[k][j]=tmp;
				}
			}
		}
	}
	//iterasyonlar
    while(hataKontrol==1)
    {
    	hataKontrol=0;
    	iterasyon++;
    	
        for(i=1;i<=n;i++)
        {
            toplam=0;
            tmp[i]=degerler[i];
            
            for(j=1;j<=n;j++)
            {
                if(j!=i)
                toplam+=denklem[i][j]*degerler[j];
            }
            
            degerler[i]=(denklem[i][n+1]-toplam)/denklem[i][i];
        }
        
        //herhangi bir deðer için yapýlan kontrol belirtilen hatapayýndan fazla ise programýn devam etmesi için flagi 1 yapýyor
        for(i=1;i<=n;i++)
        {
            if(fabs(tmp[i]-degerler[i])>=hataPayi)  // bilinmeyenlerin bi iterasyon önceki degerini tutuypr degerler ise güncel olan
                  hataKontrol=1;
        }
    }
    printf("\n%d iterasyon sonucu yakinsanan degerler\n\n",iterasyon);
    
    for(i=1;i<=n;i++){
    	printf("%d.kok=%lf\n",i,degerler[i]);
	}
	
}
void matrisinTersi(){
		
	double a[SIZE][SIZE];
	int i,j,k,x,n;
	int anlikSatir=0;
	int bolunecekSatir=1;
    int sutun=0;
    
    printf("N :");
    scanf("%d",&n);
    
    //matrisin sag tarafini birim matris yerleþtirme
     for(i=1;i<=n;i++) {
        for (j=1;j<=2*n;j++){
 
            if (j==(i+n)){
                 a[i][j] =1;
			}else{
				a[i][j]=0;
			}
                
        }
    }
    
	
    for(i=1;i<=n;i++){
    	printf("%d. satiri girin:",i);
    	for(j=1;j<=n;j++){
    		scanf("%lf",&a[i][j]);
		}
	}
    //pdfteki satýr iþlemlerini birebir uyguladým  matrisin solu birim matrise dönüþünce saðýnda aradýðýmýz ters matris kalýyor
	for(i=1;i<=n*n;i++){
	        
			if((i+n)%n==1){
				sutun++;
				anlikSatir++;
				double bolen=a[bolunecekSatir][sutun];
				for(k=1;k<=2*n;k++){
					a[bolunecekSatir][k]=a[bolunecekSatir][k]/bolen;
				}
				bolunecekSatir++;
				
			}else{
			   for(k=1;k<=n;k++){
			   	if(k!=bolunecekSatir-1){
			   		double carpan=a[k][sutun];
			   		for(x=1;x<=2*n;x++){
			   			a[k][x]=a[k][x]-a[anlikSatir][x]*carpan;
					   }
				   }
			   }
			   
			   i=i+(n-2);
			  
			}	
		
	}
	printf("\nMatrisin tersi:\n");
	for(i=1;i<=n;i++){
		for(j=1+n;j<=2*n;j++){
			printf("%lf ",a[i][j]);
		}
		printf("\n");
	}
}
void gaussEliminasyon(){
	double a[SIZE][SIZE+1],x[SIZE];	
	double tmp;
    int i,j,k,n;
    
    printf("Denklem sayisi:");
	scanf("%d",&n);
	
    for(i=0;i<n;i++){
            printf("%d. satirdaki bilinmeyenlerin katsayilari:",i+1);
            for(j=0;j<n;j++){
                scanf("%lf",&a[i][j]);
            }
        }
        
    printf("Sonuc sutunu:");
    for(i=0;i<n;i++){
                scanf("%lf",&a[i][n]);
       }
       
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
           //kosegenlere mutlakca maksimumu elemanlarý getirmek için
            if(abs(a[i][i])<abs(a[j][i])){
                for(k=0;k<n+1;k++){                
                    tmp=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=tmp;
                }
            }
        }
        // üst üçgen matris haline getiren yer
        for(j=i+1;j<n;j++){
            double  oran=a[j][i]/ a[i][i];
            for(k=0;k<n+1;k++){
                a[j][k]=a[j][k]-oran*a[i][k];
            }
        }
         
    }
   
    //sondan baþlayarak yukarýya doðru bilinmeyenleri buluyor
    for(i=n-1;i>=0;i--){
        x[i]=a[i][n];
        for(j=i+1;j<n;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];   
    }
    
      printf("\n");
     for(i=0;i<n;i++){
     	printf("x%d=%lf ",i+1,x[i]);
	 }
	  printf("\n");
        
}


void gregoryNewtonEnterpolasyon(){
	int n,i,j,h;
    double k,arananY,arananX;
    double x[SIZE],y[SIZE][SIZE];
    
    printf("Kac adet x ve y degeri girilecek:");
    scanf("%d",&n);
    printf("Fonksiyonda hangi x degerinin sonucunu gormek istiyorsun?:");
    scanf("%lf",&arananX);
    
   
    for(i=0;i<n;i++){
        printf("%d. x - > f(x) = ",i+1);
   	    scanf("%lf %lf",&x[i],&y[i][0]);
    }
    
    h=x[1]-x[0];//iki x deðeri arasý mesafe
   
 // ileri farklarý bulan döngü 
    for (i=1;i<n;i++) {
        for (j= 0;j<n-i;j++){
        	y[j][i] = y[j + 1][i - 1]-y[j][i - 1];
		}
            
    }
 
    arananY = y[0][0];//f0 toplama eklenerek baþlanýyor döngü (x-x0 /1 !/h)* deltaf0 ile baþlayýp formülü takip edicek her deðeri de arananY ye ekleyecek toplam formülü olduðu için
   
    for ( i = 1; i < n; i++) {
        arananY = arananY + (klarCarpimi(arananX, i,x[0],h) * y[0][i]) /(pow(h,i)*faktoriyel(i));
    }
 
    printf("\nf(%d)=%lf ",(int)arananX,arananY);
    
    
}
int faktoriyel(int n){
	int i;
    int f = 1;
    
    for(i=2; i<=n;i++){
    	    f =f * i;
	}
    return f;
}
//xi-x0 * xi-x1  * xi-x2  * xi-x3 ........
double klarCarpimi(double x, int n,int x0,int h){
	
    int i;
    double tmp=x-x0;
    
    for (i=1;i<n;i++){
         x0=x0+h; 
    	 tmp = tmp * (x - x0);
    	
	} 
	     
    return tmp;
}













































