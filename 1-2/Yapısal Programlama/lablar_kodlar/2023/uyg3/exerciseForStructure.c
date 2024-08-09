#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#pragma pack(1)
//struct car{
//	int a;
//	char name[20];
//};
//
//
//
//normalde struct içinde char dizisi varsa ona mainde structname.dizi = "araba" þeklinde atama yapamýyorsun ama 
//struct structname varname = {5, "araba"}; þeklinde olunca atama yapýlabiliyor bunu da anca bu þekilde yapýyor
// declaration yapýp sonra initializon yapýnca kabul etmiyor

struct car{
	int age;
	char name[20];
};

struct test{
	char a;
	int c;
	char b;
	
};

struct ogrenciler{
	char ad[20];
	char bolum[30];
	int sinif;
	float orta;
	
}ogr[3]={
	{
		"Ali", "Kamu Yonetimi", 3, 3.15
	},
	{
		"Mahmut", "Ýktisat", 1, 2.50
	},
	{
		"Ayse", "Isletme", 4, 4.0
	}

};//farklý bir kullaným
int main() {
	
	//struct car c1 = {1, "araba"};
	struct car c1 = {.name = "madem", .age = 5}; // böyle de alternatif bir yol varmýs 
	//c1.name = "madem"; // olmuyor
	
	struct car c2 = {6, "mazda"};
	struct car *ptr = &c2;
	
	//c2 = c1; //bu sekilde birbirine esitleyebiliyorsun
	printf("%d %s\n",c1.age, c1.name);
	printf("%d %s\n", (*ptr).age, (*ptr).name); // -> = *(var.field)  (*ptr).age
	printf("%d",sizeof(struct test));  // structure padding structure tanýmlarken fieldlarýn sýralarý hafýzada tutulan alaný
	//direkt olarak etkiliyor çünkü iþlemci tek seferde 4 byte yani bir word okuyor bu sebeple dizilim önemli sýra deðiþirse
	// kapladýðý alan deðiþiyor dene de gör
	//#pragma pack(1) diye özel bir þey var bunu yazýnca baþa o zaman waste memory önleniyor
	printf("\n%s",ogr[0].ad);
	
	// ayrýca struct içinde unionlar kullanarak ya da tersi þekilde uygun þekilde dizayn edilince hafýza tasarrufu
	// saðlanabilir
	return 0;
}
