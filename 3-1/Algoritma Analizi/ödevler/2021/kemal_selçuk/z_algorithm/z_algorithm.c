#include <stdio.h>
#include <string.h>
#include <time.h>


void Z_algorithm(char a[], char b[]){
	int n,r;
	int i=0,cnt,k,j;
	r=strlen(b);   //ilerde kullanmak üzere z dizisini kontrol etmek için b stringinin uzunluðunu r ye atadým
	strcat(b,"$");  //pattern stringine özel karakter ekledim
	strcat(b,a);   //patterný prefix yapýp analiz yapýlacak stringi oluþturmak için text ile pattern'ý birleþtirdim
	n=strlen(b);
	int z[n];
	z[0]=0;   //z[] dizisinin ilk elemaný her zaman 0'dýr
	for(i=1;i<n;i++){  //z[] dizisini oluþturmak için bir for döngüsü
		cnt=0; 
		k=i;
		for(j=0;j<n-1;j++,k++){ //ayný harflere rastlanýldýysa counter'ý 1 arttýracak, rastlanýlmazsa counterý z dizisine atacak olan for döngüsü
			if(b[k]==b[j]){
				cnt++;
				continue;
			}
			else break;
		}
		z[i]=cnt;
	}
	printf("\nStringe bu indexlerde rastlandi : ");
	cnt=0;
	for(i=0;i<n;i++){ //rastlanýlan indexin yerini aramak için bir for döngüsü

		if(z[i]==r){
		printf("%d ",i-r-1);
		cnt++;
		}
	}
	if(cnt==0) printf("Eslesen hic bir stringe rastlanmadi.\n");
}




void gen_random(char s[], const int len) {  //uzunluða göre rastgele string atayan bir fonksiyon yazdým
	srand(time(NULL));
    static const char alphanum[] =     "abc"; //daha fazla rastlanýlan index çýkmasý adýna rastgele string gelme olasýlýðýný 'abc' harfleriyle sýnýrladým
    int i;
    for (i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}



int main(){
	int i,j,k,p,n,r,count;
	clock_t before,after; //time.h kütüphanesinden clock() fonksiyonunu çaðýrmak için tanýmladým
	double time[100]; //diyagram kurarken harcanan süreleri tutumasý için bir array
	char a[40],b[20],c[100000], d[100000]; 
	printf("Lutfen ana stringi(text) giriniz:\n");
	scanf("%s",a);
	printf("Lutfen rastlantisini bulmak istediginiz stringi(pattern) giriniz:\n");
	scanf("%s",b);
	
	Z_algorithm(a,b);  //Z algoritmasýný uygulamak üzere fonksiyonumu çaðýrdým
	
	getch();
	
	//Algoritmanýn temel mantýðý buraya kadardý, þimdi zaman analizini inceleyelim
	
	printf("\n\n** Simdi , farkli inputlar icin harcanan surelere bakalim **\n");
	count = 0;
	while(count<5){ //5 farklý input için zaman analizi yapacak bir while(for döngüsü de yapýlabilir) dongüsü açtým
		printf("\nLutfen ana stringin(text) uzunlugunu girin:");
		scanf("%d", &k);
		gen_random(c, k); //Girilen uzunluða göre text için random bir string atandý
		
		printf("Lutfen rastlantisini bulmak istediginiz stringin(pattern) uzunlugunu girin :");
		scanf("%d", &p);
		gen_random(d, p); //Girilen uzunluða göre pattern için random bir string atandý 
		
		before = clock (); //Ýþlemin baþlangýç zamanýný tutmak için
			
			Z_algorithm(c,d);
	    
		after = clock(); //Ýþlemin bitiþ zamanýný tutmak için
		double elapsed = (double) (after-before)*1000 / CLOCKS_PER_SEC;  //Saniye deðerlerim süre olarak çok küçük sayýlar çýktýðý için saniyeyi milisaniyeye çevirdim
		time[count] = elapsed;   //Diyagram için süre deðerlerini bir diziye attým
		printf("\n\nHarcanan Zaman: %lf milisaniye. \n\n", elapsed);     
		count++;	
	}
	printf("***Analizin Diyagrami***\n");
	char show = '#';
	for(i=0; i<5; i++){ //5 farklý input için diyagram yapacaðým için 5 kere döndürdüm
		printf("\n");
		printf("%i. aramanin diyagrami: ", i+1);
		for(j=0; j<time[i]; j++){
			printf("%c", show); // diyagramý bastýrýrken '#' iþaretini kullandým
		}
	}
	
	
	
	
	return 0;
}
