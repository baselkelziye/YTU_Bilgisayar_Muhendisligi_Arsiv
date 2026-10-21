#include <stdio.h>
#include <math.h>

#define max 100


float fonksiyon(int derece, float x, float katsayi[]){
  int i;
  float f = 0.0;

  for ( i = 0; i <= derece; i++){
    f += katsayi[i]*pow(x,i);
  }
  
  return f;
}

int faktoriyel(int sayi){
  if(sayi == 0){
    return 1;
  }
  else{
    return sayi * faktoriyel(sayi-1);
  }
  
}

int bisection(){
  
  int derece,i,payda,itr=1;
  float a,b,kok,fA,fB,fX,hata,katsayi[max];


  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for (i = derece; i >= 0; i--){
    printf("x^%d katsayisi: ", i);
    scanf("%f", &katsayi[i]);
  }
  printf("Hata payi giriniz: ");
  scanf("%f", &hata);
  printf("[a,b] araligi giriniz: \n");
  printf("a= ");
  scanf("%f", &a);
  printf("b= ");
  scanf("%f", &b);



  fA = fonksiyon(derece, a, katsayi);
  fB = fonksiyon(derece, b, katsayi);

  if(fA == 0){
    printf("\nKok: %+f\n",a);
  }
  if(fB==0){
    printf("\nKok: %+f\n",b);
  }
  if (fA * fB < 0){
    printf("\nBelirtilen aralikta kok var\n\n");
    payda=1;

    while ((b-a)/payda > hata){
      
      kok = (a + b) / 2;
      fX = fonksiyon(derece, kok, katsayi);
      fA = fonksiyon(derece, a, katsayi);
      fB = fonksiyon(derece, b, katsayi);
      
      printf("%d. iterasyon\na: %+f, b: %+f x: %+f\nf(a): %+f, f(b): %+f, f(x): %+f \n\n",itr,a,b,kok,fA,fB,fX);
      itr+=1;
      if (fX * fA < 0){
        b = kok; 
      }
      if (fX * fB < 0){
        a = kok;
      }  
      payda *=2;
    }
    printf("Kok: %+f\n\n", kok);
  }
  else{
    printf("Belirtilen aralikta kok yok");
  }
  return 0;
}

int regulaFalsi(){
  int derece,i,itr=1,payda;
  float katsayi[max],hata,a,b,fA,fB,fX,kok;


  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for (i = derece; i >= 0; i--){
    printf("x^%d katsayisi: ", i);
    scanf("%f", &katsayi[i]);
  }
  printf("Hata payi giriniz: ");
  scanf("%f", &hata);
  printf("[a,b] araligi giriniz: \n");
  printf("a= ");
  scanf("%f", &a);
  printf("b= ");
  scanf("%f", &b);

  fA = fonksiyon(derece, a, katsayi);
  fB = fonksiyon(derece, b, katsayi);

  if(fA==0){
    printf("Kok: %+f",a);
  }
  if(fB==0){
    printf("Kok: %+f",b);
  }
  if (fA * fB < 0){
    printf("\nBelirtilen aralikta kok var\n\n");
    payda = 1;

    while ((b-a)/payda > hata){
      
      fA = fonksiyon(derece, a, katsayi);
      fB = fonksiyon(derece, b, katsayi);
      kok = ((a*fB) - (b*fA))/(fB-fA);
      fX = fonksiyon(derece, kok, katsayi);


      printf("%d. iterasyon\na: %+f, b: %+f x: %+f\nf(a): %+f, f(b): %+f, f(x): %+f \n\n",itr,a,b,kok,fA,fB,fX);
      itr+=1;
      if (fX * fA < 0){
        b = kok; 
      }
      if (fX * fB < 0){
        a = kok;
      }  
      payda *=2;
    }
    printf("Kok: %+f\n\n", kok);
  }
  else{
    printf("Belirtilen aralikta kok yok");
  }
  return 0;
}

int newtonRaphson(){

  int derece,i,itr=1,payda;
  float katsayi[max], h,hata,x0,x1, a, b, fx0, dfx0,fx1, katsayiTurev[max];

  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for (i = derece; i >= 0; i--){
    printf("x^%d katsayisi: ", i);
    scanf("%f", &katsayi[i]);
  }
  printf("Hata payi giriniz: ");
  scanf("%f", &hata);

  printf("[a,b] araligi giriniz: \n");
  printf("a= ");
  scanf("%f", &a);
  printf("b= ");
  scanf("%f", &b);

  x0 = a;

  for(i=1;i<=derece;i++){
    katsayiTurev[i-1]=katsayi[i]*i;
  } 
  

  do{
    fx0=fonksiyon(derece,x0,katsayi);
    dfx0=fonksiyon(derece-1,x0,katsayiTurev);
    
    x1 = x0 - (fx0/dfx0);
    fx1=fonksiyon(derece,x1,katsayi);
    h = x1 - x0;
    


    printf("\n\n%d. iterasyon\nx0: %+f, f(x0): %+f\nx1: %+f, f(x1): %+f",itr,x0,fx0,x1,fx1);
    itr+=1;
    
    x0=x1;
  }while(fabs(h)>hata);

  printf("\n\nKok: %+f\n\n",x1);
  return 0;
}

int matrisTersi(){
  //Gauss Jordan yöntemi kullanılmıştır.
  int n,i,j,k;
  float m[max][max],oran;

  printf("Matrisi boyutunu giriniz: ");
  scanf("%d",&n);
  printf("Matris elemanlarini giriniz:\n\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("m[%d][%d]: ",i,j);
      scanf("%f",&m[i][j]);
    }
  }
  printf("\nGirilen matris: \n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%+f\t",m[i][j]);
    }
    printf("\n");    
  }
  //matrisin yanına birim matris ekleniyor...
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j){
				m[i][j+n] = 1;
			}
			else{
				m[i][j+n] = 0;
			}
    }
  }
  //  m[j][i]/m[i][i] oranı alınır.
  //  m[j][k] dan oran*m[i][k] çıkarılır.
  //  son olarak m[i][j], m[i][i] ye bölünür.
  for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		  if(i!=j){
				oran = m[j][i]/m[i][i];
				for(k=0;k<2*n;k++){
					m[j][k] -= oran*m[i][k];
				}
			}
		}
	}
  for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			m[i][j] /= m[i][i];
		}
	}
  printf("\nGirilen Matrisin tersi:\n");
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
		  printf("%+f\t",m[i][j]);
		}
		printf("\n");
	}
  
  return 0;
}

int gaussEle(){
    int n,i,j,k;
    float toplam=0.0,m[20][20],oran,sonuc[10];

    printf("\nDenklem sistemi sayisi: ");
    scanf("%d",&n);
    printf("\nKatsayilari matris elemanlari olarak giriniz:\n\n");
    for(i=1; i<=n; i++){
      for(j=1; j<=n+1; j++){
        printf("m[%d][%d] : ", i-1,j-1);
        scanf("%f",&m[i][j]);
      }
    }
    //  üst üçgen matris haline getirilir
    for(j=1; j<=n; j++) {
      for(i=1; i<=n; i++){
        if(i>j){
          oran=m[i][j]/m[j][j];
          for(k=1; k<=n+1; k++){
            m[i][k] -= oran*m[j][k];
          }
        }
      }
    }
    sonuc[n]=m[n][n+1]/m[n][n];

    //  son denklemden başlanır.
    //  geriye doğru işlem yapılır.
    for(i=n-1; i>=1; i--){
      toplam=0;
      for(j=i+1; j<=n; j++){
          toplam += m[i][j]*sonuc[j];
      }
      //  kokler diziye eklenir.
      sonuc[i]=(m[i][n+1]-toplam)/m[i][i];
    }
    printf("\nBulunan kokler: \n");
    for(i=1; i<=n; i++)
    {
      printf("\nx%d= %+f\t",i,sonuc[i]); 
    }
  return 0;
}

int gaussSeidel(){
  int i,j,n,k=0,sayac,itr=1;
  float a,m[max][max],sonuc1[max],sonuc2[max],cikar,hatalar[max],hata;
  //  sonuc2 matrisi hata hesaplamak için eklenmiştir.

  printf("Denklem sistemi sayisi giriniz: ");
  scanf("%d",&n);

  printf("Denklem sistemlerini matris olarak giriniz:\n");
  for(i=0;i<n;i++){
    for(j=0;j<n+1;j++){
      printf("m[%d][%d]: ",i,j);
      scanf("%f",&m[i][j]);
    }
  }
  printf("Baslangic degerlerini giriniz:\n");
  for(i=0;i<n;i++){
    printf("x%d: ",i+1);
    scanf("%f",&sonuc1[i]);
    
  }
  printf("Hata giriniz: ");
  scanf("%f",&hata);

  do{
    
    if(k==0){

      
      printf("\n%d. iterasyon: \n",itr);
      itr += 1;
      for(i=0;i<n;i++){
        printf("x%d: %+f  hata: %+f\n",i+1,sonuc1[i],fabs(sonuc2[i]-sonuc1[i]));  
      }
    }
  
    cikar = 0.0;

    //  tüm bilinmeyenler toplanır
    for(i=0;i<n;i++){
      cikar += m[k][i]*sonuc1[i];
    }

    //  aranan bilinmeyen çıkarılır
    cikar -= m[k][k]*sonuc1[k];
    sonuc2[k]=sonuc1[k];
    sonuc1[k] = (m[k][n]-cikar) / m[k][k];

    if(fabs(sonuc1[k]-sonuc2[k])<hata){
      sayac += 1;
    }
    k++;
    if(k==n){
      k = 0;
      if(sayac != n){
        sayac = 0;
      }

    }
    
  }while(sayac != n);
  printf("\nKokler:\n");
  for(i=0;i<n;i++){
    printf("x%d: %+f\n",i+1,sonuc1[i]);
  }
  return 0;
}

int turev(){
  int i,derece;
  float x,h,katsayi[max],t_ileri,t_merkezi,t_geri;
  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for (i = derece; i >= 0; i--){
    printf("x^%d katsayisi: ", i);
    scanf("%f", &katsayi[i]);
  }
  printf("x: ");
  scanf("%f",&x);
  printf("h: ");
  scanf("%f",&h);

  t_ileri = (fonksiyon(derece,x+h,katsayi)- fonksiyon(derece,x,katsayi))/h;
  t_merkezi = (fonksiyon(derece,x+h,katsayi)- fonksiyon(derece,x-h,katsayi))/2/h;
  t_geri = (fonksiyon(derece,x,katsayi)- fonksiyon(derece,x-h,katsayi))/h;

  printf("\nIleri farklar ile sayisal turev: \t%+f\n",t_ileri);
  printf("Merkezi farklar ile sayisal turev: \t%+f\n",t_merkezi);
  printf("Geri farklar ile sayisal turev: \t%+f\n",t_geri);

  return 0;
}


int simpson(){
  int i,derece;
  float n,katsayi[max],a,b,h,tek=0.0,cift=0.0,sonuc,fA,fB;

  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for (i = derece; i >= 0; i--){
    printf("x^%d katsayisi: ", i);
    scanf("%f", &katsayi[i]);
  }
  
  printf("a: ");
  scanf("%f",&a);
  printf("b: ");
  scanf("%f",&b);
  printf("n: ");
  scanf("%f", &n);
  h =(b-a)/n; 
  printf("\n");
  printf("f(%f): %+f\n",a,fonksiyon(derece,a,katsayi));
  for(i=1; i<n; i++)
		if(i%2 == 0){
      cift += fonksiyon(derece,a+(i*h),katsayi);
      printf("f(%f): %+f\n",a+(i*h),fonksiyon(derece,a+(i*h),katsayi));
    }
    else{
      tek += fonksiyon(derece,a+(i*h),katsayi);
      printf("f(%f): %+f\n",a+(i*h),fonksiyon(derece,a+(i*h),katsayi));
    }
  printf("f(%f): %+f\n",b,fonksiyon(derece,b,katsayi));
  fA = fonksiyon(derece,a,katsayi);
  fB = fonksiyon(derece,b,katsayi);
  sonuc= (h/3)*(fA+fB+ (4*tek) + (2*cift));
  printf("\nSonuc: %+f\n",sonuc);



  return 0;
}

int trapez(){
  int i,derece;
  float katsayi[max],h,a,b,n,toplam=0,sonuc,fA,fB;

  printf("\nFonksiyonu giriniz\n\n");
  printf("Fonksiyonun derecesi: ");
  scanf("%d", &derece);

  for(i=derece;i>=0;i--){
    printf("x^%d katsayisi: ",i);
    scanf("%f",&katsayi[i]);
  }
  printf("a: ");
  scanf("%f",&a);
  printf("b: ");
  scanf("%f",&b);
  printf("n: ");
  scanf("%f",&n);
  
  h = (b-a)/n;
  printf("f(%f): %+f\n",a,fonksiyon(derece,a,katsayi));
  for(i=1;i<n;i++){
    printf("f(%f): %+f\n",a+(i*h),fonksiyon(derece,a+(i*h),katsayi));
    toplam += fonksiyon(derece,a+(i*h),katsayi);
  }
  printf("f(%f): %+f\n",b,fonksiyon(derece,b,katsayi));
  fA = fonksiyon(derece,a,katsayi);
  fB = fonksiyon(derece,b,katsayi);

  sonuc = h* (((fA+fB)/2) +toplam);

  printf("\nSonuc: %+f\n",sonuc);

  return 0;
}

int gregory(){
  int i,j,k,n,kosul=1,adim;
  float fark_m[max][max],x,h,sum,result,x_deger[max],sonuc,komb;

  printf("Nokta sayisi: ");
  scanf("%d",&n);

  for(i=0;i<n;i++){
    printf("\nx%d: ",i+1);
    scanf("%f",&x_deger[i]);
    printf("f(x%d): ",i+1);
    scanf("%f",&fark_m[i][0]);
  }
  printf("\nx: ");
  scanf("%f",&x);

  h=x_deger[1]-x_deger[0];

  i=1;
  while(i>=1 && i<n){
    for(j=0;j<n-i;j++){
      fark_m[j][i] = fark_m[j+1][i-1] - fark_m[j][i-1];
    }
    for(j=0;j<n-i;j++){
      if(fark_m[1][i]==fark_m[0][i]){
        i *= -1;
      }
    }
    i++;
  }
  if(i<0){
    i *=-1;
  }else{
    i=n;
  }
  adim = i-1;

  printf("\nFarklar matrisi:\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n-i ; j++){
      printf("%+f\t", fark_m[i][j]);
    }
    printf("\n");
  }
  sonuc = fark_m[0][0];
  
  while(adim > 0){
    komb = 1;
    for (i=0;i<adim;i++){
      komb *= (x-x_deger[i]);
    }
    komb = komb * fark_m[0][adim] / pow(h,adim) / faktoriyel(adim);
    sonuc += komb; 
    adim --;
  }
  printf("\nf(%f)= %+f\n",x,sonuc);

  return 0;
}
int main(void){
  int secim,devam = 1;

  while(devam == 1){

    printf("\n1. Bisection\n");
    printf("2. Regula-Falsi\n");
    printf("3. Newton Raphson\n");
    printf("4. Matris Tersi\n");
    printf("5. Gauss Eleminasyon\n");
    printf("6. Gauss Seidel\n");
    printf("7. Sayisal Turev\n");
    printf("8. Simpson (1/3)\n");
    printf("9. Trapez\n");
    printf("10. Gregory Newton\n");

    printf("\nSecim yapiniz: ");
    scanf("%d",&secim);

    switch (secim){
      case 1:
        bisection();
        break;
      case 2:
        regulaFalsi();
        break;
      case 3:
        newtonRaphson();
        break;
      case 4:
        matrisTersi();
        break;
      case 5:
        gaussEle();
        break;
      case 6:
        gaussSeidel();
        break;
      case 7:
        turev();
        break;
      case 8:
        simpson();
        break;
      case 9:
        trapez();
        break;
      case 10:
        gregory();
        break;
        
    }
    printf("\nDevam etmek ister misiniz? \n1- Evet\n2- Hayir\n");
    scanf("%d",&devam);
  }
  return 0;
}
