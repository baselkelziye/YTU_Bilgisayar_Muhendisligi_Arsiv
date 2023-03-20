#include<stdio.h>// basel kelziye 20011906
#include<math.h>

double degerbulan(double currentx, double  poldiz[], int degr ){//fonksiyonun gorunutusu bulmak icin yazilmistir
		int i;
		 double sum =0 ,z = 0;
			for(i = 0; i<= degr; i++){
			z = poldiz[i] * pow(currentx , degr- i);
			sum = sum + z;
		}	
		return sum;
	}

	double fonksiyonun_turevi(double currentx, double poldiz[], int degr){// fonksiyonun turevi icin yazilmistir
		int i;
		double sum = 0, z = 0;
		for(i = 0; i< degr; i++){
		z = (degr-i)* poldiz[i] * pow(currentx , degr- i-1);

		sum = sum + z;
	
		}
		
		return sum;
	}

		int faktoriyel_hesaplayan(int n){//faktoriyel hesaplayan fonksiyon
			int sum = 1,i;
			
			for(i = n; i >=1; i--){
				sum = sum * i;
			}
			return sum;
			
		}
		
			double r_hesaplayan(double a /*istenilen nokta*/, double elemanlar[], double b/*aradaki fark (h)*/,int iterasyon ){
			double sum = 1;
			int i;
			
			for(i = 0; i <= iterasyon; i++){
				sum = sum * (a - elemanlar[i])/b;
				
			}
		
			return sum;
			
		}
		
			double fark_operator( double goruntu_kumesi[], double tmp_goruntu[],int eleman_sayisi,int *t){// fark operatorda goruntunun farki olacaktir duzeltilmeli
			 int i;		 
			 for(i = 0; i < eleman_sayisi-1; i++){
			 	goruntu_kumesi[i] = tmp_goruntu[i+1] - tmp_goruntu[i];		 	
			 }
					*t = *t +1;
				goruntu_kumesi[eleman_sayisi - *t] = 0;
			for(i = 0; i < eleman_sayisi; i++){
				tmp_goruntu[i] = goruntu_kumesi[i];
				
			}
					
			return goruntu_kumesi[0];
		}
		
		
		
void bisection_yontemi(){
		int i,degr,t =0, k= 0, flag =1;
	 double hata,currentx,poldiz[20],z;
	 double left,right,mid,sum,j = 1,current_hata;
	printf("\n\nLutfen Polinomun derecesini giriniz\n");
	scanf("%d", &degr);
	
	for(i = 0; i <= degr; i++){
		printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
		scanf("%lf", &poldiz[i]);
						
	}
	
	printf("\nLutfen araliklari sirayla giriniz\n");
	scanf(" %lf \t%lf", &left, &right);//assigning  left and right values	

	if(degerbulan(left, poldiz, degr) * degerbulan(right, poldiz, degr) <= 0){ // checking if there is a root
		printf("\nAradginiz aralikta kok bulunuyor!");
	}
	else{
		
				flag = 0;
		printf("\nVerilen aralikta kok bulunamamaktadir!\n");
		
		printf("\n\n Lutfen farkli degerler giriniz");
		
	
	}
	if(flag == 1){
	
	printf("\nSinirlarimiz = [%lf, %lf]",left, right);
	printf("\nLutfen Max hata degerinizi giriniz\n");
	scanf("%lf", &hata);
		
			do {
		mid = (left + right)/2;
		j = j*2;
		current_hata = (right - left)/j;
		printf("\nSinirlarimiz : [%lf, %lf]\n", left, right);
		printf("\nOrta Noktamiz : %lf\n", mid);
		 if(degerbulan(mid, poldiz, degr) * degerbulan(left, poldiz, degr) > 0){
			left = mid;
		}
		else if (degerbulan(mid, poldiz, degr) * degerbulan(right, poldiz, degr) > 0){
			right = mid;
		}
				k++;
				printf("\n%d. Iterasyonunda bulunan hata degeri : %lf",k,current_hata);			
  			} 			  
  		while(current_hata >= hata); 
  		printf("\n\nAradigimiz yaklasik kok = %lf", mid);
}
}

void regula_falsi(){
	int i, degr,t = 0,flag =1;
		double poldiz[20],hata,currentx,left,right,mid,possible_root[20];
		printf("\n\nLutfen Polinomun derecesini giriniz\n");
		scanf("%d", &degr);
		
		for(i = 0; i <= degr; i++){
		printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
		scanf("%lf", &poldiz[i]);
						
	}
	
	printf("\nLutfen araliklari sirayla giriniz\n");
	scanf(" %lf \t%lf", &left, &right);
	
	if(degerbulan(left, poldiz, degr) * degerbulan(right, poldiz, degr) <= 0){ // checking if there is a root
		printf("\nAradginiz aralikta kok bulunuyor!");
	}
	else{
		flag = 0;
		printf("\nVerilen aralikta kok bulunamamaktadir!\n");
		printf("\n \n Lutfen Farkli degerler deneyiniz");
	}
	if(flag ==1){
	
	printf("\nSinirlarimiz = [%lf, %lf]",left, right);
	printf("\nLutfen Max hata degerinizi giriniz\n");
	scanf("%lf", &hata);
	possible_root[t] = 0;
//	printf(" Possible_root is : %lf", possible_root[t]);
	
	
	
		do {
			
			t++;
			printf("\n\n\n%d. Iterasyon",t);
			possible_root[t] = (left*degerbulan(right, poldiz, degr)-right*degerbulan(left, poldiz, degr))/(degerbulan(right, poldiz, degr)-degerbulan(left, poldiz, degr));
			printf("\npossible_root[%d] is : %lf",t,possible_root[t]);
		possible_root[t] = (left*degerbulan(right, poldiz, degr)-right*degerbulan(left, poldiz, degr))/(degerbulan(right, poldiz, degr)-degerbulan(left, poldiz, degr));
			if(degerbulan(left, poldiz, degr) * degerbulan(possible_root[t], poldiz, degr) >0){
				left = possible_root[t];
			}
			else if(degerbulan(right, poldiz, degr) * degerbulan(possible_root[t], poldiz, degr) > 0){
				right = possible_root[t];
			}
			
			printf("\nOlusan yeni araligimiz [%lf,%lf]",left, right);
			if(t > 1){
				printf("\n\n Durma Kosulu Kontrolu!\n bu adimdaki hata : %lf",fabs(possible_root[t] - possible_root[t-1]));
			}
			
			
		}
		while(	fabs(possible_root[t] - possible_root[t-1]) > hata );
		
		printf("\n\nYaklasik kok bulundu! : %lf", possible_root[t]);
		printf("\n\n yaklasik hata degeri : %lf", possible_root[t]- possible_root[t-1]);
	
	}
}

	

void newton_raphson(){
	
		int degr,i,t = 0, flag = 1;
		double left,right,possible_root[20],poldiz[20],hata,baslangic_deger;
		
		printf("\n\nLutfen Polinomun derecesini giriniz\n");
		scanf("%d", &degr);
		
		for(i = 0; i <= degr; i++){
		printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
		scanf("%lf", &poldiz[i]);
		}
	//	printf("\n turevli fonksiyon deneme : %lf", fonksiyonun_turevi(5,poldiz, degr));
		printf("\nLutfen araliklari sirayla giriniz\n");
		scanf(" %lf \t%lf", &left, &right);//assigning  left and right values	
		
		if(degerbulan(left, poldiz, degr) * degerbulan(right, poldiz, degr) <= 0)	// checking if there is a root
			{ 
		printf("\nAradginiz aralikta kok bulunuyor!");
			}
	else{
		flag = 0;
		printf("\nVerilen aralikta kok bulunamamaktadir!\n");
		}
	
	if(flag == 1){
	
	printf("\nSinirlarimiz = [%lf, %lf]",left, right);
	printf("\n \nLutfen baslangic  degerinizi giriniz\n"); // ayri bir kosul yapilmali flag 0 icin girilmesi
	scanf("%lf", &baslangic_deger);
	printf("\nLutfen Max hata degerinizi giriniz\n");
	scanf("%lf", &hata);
		possible_root[0] = baslangic_deger;
		
	
		
		do{
			t++;
			printf("\n \n%d. Iterasyon",t);
		possible_root[t] = possible_root[t-1] - (degerbulan(possible_root[t-1], poldiz, degr)/fonksiyonun_turevi(possible_root[t-1],poldiz,degr));
		printf("\n kok adayimiz : %lf",possible_root[t]);
		if(degerbulan(left,poldiz,degr)*degerbulan(possible_root[t],poldiz,degr) > 0){
			left = possible_root[t];
		}
		else if(degerbulan(right,poldiz,degr) * degerbulan(possible_root[t],poldiz,degr)){
			right = possible_root[t];
		}
		printf("\n Yeni araligimiz : [%lf,%lf]",left,right);
		printf("\nBu Adimdaki Hata degeri : %lf",fabs(possible_root[t] - possible_root[t-1]));
		}
		while(fabs(possible_root[t] - possible_root[t-1]) > hata);
		
		printf("\n\n\n%lf yaklasik hata ile %lf koku bulundu! ",fabs(possible_root[t]-possible_root[t-1]), possible_root[t]);
	
	}
	
}

void matrisin_tersi(){
	
		int dimension,i,j,z, flag =1;
	double birim_matris[20][20], matris[20][20],bas_kat_sayi,m_kat_sayi,temp;
	printf("\n\n Bir matrisin tersi alinabilmesi icin Kare matrisi Olmak zorundadir\n\n");
	printf("\n Lutfen Matrisin Boyutunu giriniz\n");// bir matrisin tersi alinabilmesi icin kare matrisi olmak zorunda o yuzden bir boyut alinip NxN seklinde yapilmistir
	scanf("%d", &dimension);
	
	
	
		for(i = 0; i < dimension; i++){
			for(j = 0; j < dimension; j++){
			printf("\n lutfen matris[%d][%d] i giriniz\t", i+1,j+1);
			scanf("%lf", &matris[i][j]);
		}
		printf("\n");
	}
	
	if(dimension == 1 && matris[0][0] == 0){
		flag = 0;
		printf("\n girdiginiz matrisin determinanti 0 oldugu icin tersi bulunamamaktadir");
		
	}
	
	if(flag == 1){
	
	for(i = 0; i < dimension; i++){
		for(j = 0; j < dimension; j++){
			if(i == j){
				birim_matris[i][j] = 1;
			}
			else{
				birim_matris[i][j] = 0;
			}
		}
	}
	
	j = 0;
j = 0;
	while(j < dimension){
		
		if(matris[j][j] != 0){
		
		bas_kat_sayi = matris[j][j];
		
			for(z = 0; z < dimension; z++){
				matris[j][z] = matris[j][z]/bas_kat_sayi;
				birim_matris[j][z] = (birim_matris[j][z])/(bas_kat_sayi);
			}
			for(i = 0; i < dimension; i++){
				m_kat_sayi = (matris[i][j] / matris[j][j])*(-1);
				if(j != i){
					for(z = 0; z < dimension; z++){
						
					matris[i][z] +=  (matris[j][z] * m_kat_sayi);	
					birim_matris[i][z] +=  (birim_matris[j][z] * m_kat_sayi);
											
						
					}
				}
			}
			j++;
		
		}
		else{
			if(j+1 >= dimension){
				printf("\nMatrisin determinanti 0 oldugu icin tersi bulunmamaktadir\n");
				j = dimension+1;
				flag = -1;
			}
			else{
				for(z = 0; z < dimension; z++){
				
				temp = matris[j][z];
				matris[j][z] = matris[j+1][z];
				matris[j+1][z] = temp;
				
				
				temp = birim_matris[j][z];
				birim_matris[j][z] = birim_matris[j+1][z];
				birim_matris[j+1][z] = temp;					
			}
		}
			}
			
	}
	
	
	if(flag != -1){
			printf(" \n\n\n matris inversi:\n\n");
	
	for(i = 0; i < dimension; i++){
		for(j = 0; j < dimension; j++){
			printf(" %lf ", birim_matris[i][j]);
		}
		printf(" \n ");
	}
	}
	


	}
	
}

void gauss_eleminasyon(){
	
	int i,j,sutun,satir,t,k,z,w;
	double matris[10][10],tmp_matris[10][10],tmp1,tmp,tmp2,toplam,sonuc_dizisi[20];
	printf("\n Lutfen sonuc matrisi ile bir ortak matris olarak giriniz");
	printf("\n\nLutfen satir sayisini giriniz ");
	scanf("%d", &satir);
	
	printf("\nLutfen sutun sayisini giriniz ");
	scanf("%d", &sutun);
	
	for(i = 0; i < satir; i++){
		for(j = 0; j < sutun; j++){
			printf(" Lutfen matris[%d][%d]. elemani giriniz\n",i+1,j+1);
			scanf("%lf", &matris[i][j]);
			tmp_matris[i][j] = matris[i][j];
			}

		}
	
	for(i = 0; i < satir; i++){
		for(j = 0; j < sutun; j++){
			printf(" %lf ", matris[i][j]);
		}
		printf("\n");
	}
	
	
	for(i = 0; i < satir; i++){		
	tmp1 =  tmp_matris[i][i];
		for(j = i; j <= sutun  ; j++){		
			tmp_matris[i][j] = (tmp_matris[i][j]) / tmp1;						 			
		}	
		
								printf("\n \n ");
	for(z = 0; z < satir; z++){
		for(w = 0; w < sutun; w++){
			printf(" %lf ", tmp_matris[z][w]);
		}
		printf("\n");
	}
			
			printf("\n \n ");
	
		for(t = i+1; t < satir; t++){
			
	
	
			tmp = tmp_matris[t][i];// 
			
			for(k = i; k <= sutun +1; k++){
		
				tmp_matris[t][k] = tmp_matris[t][k] - (tmp * tmp_matris[i][k]); 
			}
		}
			printf("\n \n ");
	for(z = 0; z < satir; z++){
		for(w = 0; w < sutun; w++){
			printf(" %lf ", tmp_matris[z][w]);
		}
		printf("\n");
	}
				
				}
				
				
				sonuc_dizisi[satir-1] = tmp_matris[satir-1][sutun-1]; 
				
				for(i = satir -2; i >= 0; i--){
					sonuc_dizisi[i] = tmp_matris[i][sutun-1];
					for(j = i+1; j < sutun-1; j++ ){
						sonuc_dizisi[i] = sonuc_dizisi[i] - tmp_matris[i][j] * sonuc_dizisi[j];
					}
					sonuc_dizisi[i] = sonuc_dizisi[i]/tmp_matris[i][i];
				}
	
				
				printf("\n Koklerimiz : \n");				
			for(i = 0; i< satir; i++){
			printf("\n x%d : %lf", i+1, sonuc_dizisi[i]);
			}
				
	
}

void gauss_seidal(){
	
		double x1,x2,x3, y1,y2,y3,z1,z2,z3, current_x[10], current_y[10],current_z[10],sonuc1,sonuc2,sonuc3,hata;
	int i = 0;
	

	
	printf("\n \nLutfen Sirayla X1,  Y1,  Z1 ve sonucu sirayla giriniz\n");
	scanf("%lf %lf %lf %lf", &x1, &y1, &z1, &sonuc1);
	
	printf("\n Lutfen Sirayla X2,  Y2,  Z2 ve sonucu sirayla giriniz\n");
	scanf("%lf %lf %lf %lf", &x2, &y2, &z2, &sonuc2);
	
	printf("\n Lutfen Sirayla X3,  Y3,  Z3 ve sonucu sirayla giriniz\n");
	scanf("%lf %lf %lf %lf", &x3, &y3, &z3, &sonuc3);
	
	
	printf("\nLutfen Hata degerinizi giriniz\n");
	scanf("%lf", &hata);
	system("cls");
	
	printf("\nGirdiginiz denklemler : \n\n %+lfX %+lfY %+lfZ = %+lf ", x1,y1,z1,sonuc1);
	printf("\n\n %+lfX %+lfY %+lfZ = %+lf ", x2,y2,z2,sonuc2);
	printf("\n\n %+lfX %+lfY %+lfZ = %+lf \n", x3,y3,z3,sonuc3);

	printf("\n Lutfen sira ile X, Y, Z nin baslangic degerlerini giriniz\n");
	scanf("%lf %lf %lf", &current_x[1], &current_y[1], &current_z[1]);
	
		
	do{
		i++;
		current_x[i+1] = ( sonuc1 - (y1 * current_y[i]) - (z1 * current_z[i]) )/x1;
		
	
		current_y[i+1] = ( sonuc2 - (x2 * current_x[i+1]) - (z2 * current_z[i]) )/y2;
	
		current_z[i+1] = ( sonuc3 - (x3 * current_x[i+1]) - (y3 * current_y[i+1]) ) /z3;
	
		
		printf("\n%d. iterasyonda hata degerleri:", i);
		printf("\n X : %lf \n Y : %lf \n ",fabs(current_x[i+1] - current_x[i]), fabs(current_y[i+1] - current_y[i]));
		printf("Z : %lf", fabs(current_z[i+1] - current_z[i]));
		
	}
	while( (fabs(current_x[i+1] - current_x[i]) > hata) && (fabs(current_y[i+1] - current_y[i]) > hata) && (fabs(current_z[i+1] - current_z[i]) > hata));
	
	printf("\n Koklerimiz Bulundu \n X : %lf \n Y : %lf \n Z : %lf", current_x[i+1], current_y[i+1], current_z[i+1]);
	
}

void sayisal_turev(){
	int i,degr, menu_belirleyici;
		double poldiz[20],currentx,h,istenilen_nokta,sonuc_degeri;
		
		printf("\n\nLutfen Polinomun derecesini giriniz\n");
		scanf("%d", &degr);
		
		
		for(i = 0; i <= degr; i++){
		printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
		scanf("%lf", &poldiz[i]);
		}
		
		printf("\n Lutfen Turevini hesaplamak istediginiz noktayi giriniz\n");
		scanf("%lf", &istenilen_nokta);
		printf("\n Lutfen Fark(h) degerinizi giriniz\n");
		scanf("%lf", &h);
		
		printf("\n Lutfen yontem secin.\n 1. Geri Farklarla Turev icin 1\n 2. ileri farkla Turev icin 2\n 3. Merkezi farklar ile turev icin 3 e basin\n");
		scanf("%d", &menu_belirleyici);
		
		if(menu_belirleyici == 1){
			
			sonuc_degeri = (degerbulan(istenilen_nokta, poldiz, degr) - degerbulan(istenilen_nokta - h, poldiz, degr))/h;
			printf("Geri farklar ile hesaplanan sonuc: %lf", sonuc_degeri);	
		}
		else if(menu_belirleyici == 2){
			sonuc_degeri = (degerbulan(istenilen_nokta + h, poldiz, degr) - degerbulan(istenilen_nokta, poldiz, degr))/h;
			printf("Ileri farklar ile hesaplanan sonuc: %lf", sonuc_degeri);	
		}
		else if(menu_belirleyici == 3){
			sonuc_degeri = (degerbulan(istenilen_nokta + h, poldiz, degr) - degerbulan(istenilen_nokta - h, poldiz, degr))/(h*2);
				printf("Merkezi farklar ile hesaplanan sonuc: %lf", sonuc_degeri);	
		}
}

void simpson_yontemi(){
	
	int i, degr;
		double currentx, poldiz[10],alt_sinir, ust_sinir, h,total_sum = 0, n,k,total_sum_tek = 0, total_sum_cift = 0, total_sum_ozel = 0;		
			printf("\n\nLutfen Polinomun derecesini giriniz\n");
			scanf("%d", &degr);		
			for(i = 0; i <= degr; i++){
			printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
			scanf("%lf", &poldiz[i]);					
				}
				
			printf("\n Lutfen alt sinir ve ust siniri sirayla giriniz giriniz\n");
			scanf("%lf %lf", &alt_sinir, &ust_sinir);			
			printf("\nLutfen Olusturmak istediginiz Alan sayisini giriniz (n)\n");
			scanf("%lf", &n);
			
			
			h = (ust_sinir - alt_sinir)/n;
			k = alt_sinir;
			
			for(i = 1; i <= n-1; i = i+2){
				k = alt_sinir + i * h;

				total_sum_tek = total_sum_tek + degerbulan(k, poldiz, degr);
			}
			total_sum_tek = (total_sum_tek) * ((4 * h) / 3);
			
			k = alt_sinir;
			
			for(i = 2; i <= n-2; i = i+2){
				k = alt_sinir + i* h;
			
				total_sum_cift = total_sum_cift + degerbulan(k, poldiz, degr);
			}
			
			total_sum_cift = (total_sum_cift) *( (2*h)/3);
			
			total_sum_ozel = total_sum_ozel + (h * (degerbulan(alt_sinir, poldiz, degr) + degerbulan(ust_sinir, poldiz, degr)) / 3);
			
			total_sum = total_sum_cift + total_sum_tek + total_sum_ozel;
			printf("\n\n Simpsons 1/3 Metodu ile Hesaplanan yaklasik alan : %lf", total_sum);
	
	
	
}
 void trapez_yontemi(){
 		int i, degr;
		double currentx, poldiz[10],alt_sinir, ust_sinir, h,total_sum = 0, n,k;		
			printf("\nLutfen Polinomun derecesini giriniz\n");
			scanf("%d", &degr);		
			for(i = 0; i <= degr; i++){
			printf("\n x^%d lu terimin baskatsayisini giriniz\n", degr - i); // filling the polynom's baskatsayilari :D
			scanf("%lf", &poldiz[i]);					
				}			
			printf("\n Lutfen alt sinir ve ust siniri sirayla giriniz giriniz\n");
			scanf("%lf %lf", &alt_sinir, &ust_sinir);			
			printf("\nLutfen Olusturmak istediginiz Alan sayisini giriniz (n)\n");
			scanf("%lf", &n);		
			
			h = (ust_sinir - alt_sinir)/n;			
			k = alt_sinir;			
			for(i = 1; i < n; i++){				
				k = k+h;			
				total_sum = total_sum + degerbulan(k, poldiz,degr);		
			}		
			total_sum = total_sum * h;
			 total_sum = total_sum + h *(degerbulan(alt_sinir, poldiz, degr) + degerbulan(ust_sinir, poldiz, degr))/2;						
			printf("\n Trapez metodu ile Hesaplanan Alan = %lf", total_sum);
 	
 }
 
 void gregory_newton(){
 	
 	double istenilen_nokta,elemanlar[20],h, tmp_goruntu[20],sum = 0,goruntu_kumesi[20];
			int i, t = 0,eleman_sayisi;
			
			
			
			printf("\nLutfen elemanlarin  sayisini giriniz");
			scanf("%d", &eleman_sayisi);
			
			
			
			for(i = 0; i < eleman_sayisi; i++){
				printf("\nLutfen X%d i goruntusu ile birlikte giriniz \n", i+1);
				scanf(" %lf %lf", &elemanlar[i], &goruntu_kumesi[i]);
				tmp_goruntu[i] = goruntu_kumesi[i];
			}
			sum = sum + goruntu_kumesi[0];
			printf("\nlutfen aradiginiz noktayi giriniz");
			scanf("%lf", &istenilen_nokta);
			
			h = elemanlar[1] - elemanlar[0];
//			for(i = 0; i < eleman_sayisi; i++){
//				printf("\n%d. fordaki fark operatoru :  %lf",i, fark_operator(goruntu_kumesi, tmp_goruntu, eleman_sayisi, &t));
//				
//			}
			
			for(i = 0; i < eleman_sayisi; i++){

				sum = sum + (r_hesaplayan(istenilen_nokta, elemanlar, h, i) * (fark_operator(goruntu_kumesi, tmp_goruntu, eleman_sayisi, &t)))/faktoriyel_hesaplayan(i+1);
			
			}
			printf(" \n\n Gregory Newton Interpolasyonu ile hesaplanan yaklasik Deger  :%lf ", sum);
 	
 }

int  main(){


int method;

printf("\n Numerik metodlarina hosgeldiniz\n");

printf("\n Lutfen bir Metod secin\n");
printf("\n 1. Bisection Yontemi");
printf("\n 2. Regula-False Yontemi");
printf("\n 3. Newton-Raphson Yontemi");
printf("\n 4. NxN'lik bir matrisin tersi");
printf("\n 5. Gauss Eleminasyon");
printf("\n 6. Gauss Seidal Yontemi");
printf("\n 7. Sayisal Turev Yontemleri");
printf("\n 8. Simpson Yontemi");
printf("\n 9. Trapez Yontemi");
printf("\n 10. Gregory Newton Enterpolasyonu Yontemi\n");
scanf("%d", &method);
//bisection

switch(method){
	
	case 1:
	system("cls");
	printf("\n\t\tBISECTION YONTEMI");
	bisection_yontemi();
	break;
	
	case 2:
	system("cls");
	printf("\n\t\t REGULA-FALSE");
	regula_falsi();
	break;
	
	case 3:
	system("cls");
	printf("\n\t\t NEWTON-RAPHSON");
	newton_raphson();
	break;
	
	case 4:
	system("cls");
	printf("\n\t\tMATRISIN TERSI");
	matrisin_tersi();
	break;
	
	case 5:
	system("cls");
	printf("\n\t\tGAUSS YOK ETME METODU");
	gauss_eleminasyon();
	break;
	
	case 6:
	system("cls");
	printf("\n\t\tGAUSS SEIDAL YONTEMI");
	gauss_seidal();
	break;
	
	case 7:
	system("cls");
	printf("\n\t\tSAYISAL TUREV YONTEMLERI");
	sayisal_turev();
	break;
	
	case 8:
	system("cls");
	printf("\n\t\t SIMPSON 1/3 YONTEMI");
	simpson_yontemi();
	break;
	
	case 9:
	system("cls");
	printf("\n\t\tTRAPEZ YONTEMI");
	trapez_yontemi();
	break;
	
	case 10:
	system("cls");
	printf("\n\t\tGREGORY NEWTON INTERPOLASYON");
	gregory_newton();
	break;
	
	default : 
	system("cls");
	printf("\n girdiginiz yontem bulunamamaktadir");
	break;
}



return 0;
}
