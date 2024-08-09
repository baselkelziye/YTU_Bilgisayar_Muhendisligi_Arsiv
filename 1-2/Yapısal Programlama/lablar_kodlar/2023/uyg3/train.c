#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	int a;
	char name[20];
};

int main() {
	
	//struct car c1 = {1, "araba"};
	struct car c1 = {.name = "madem", .a = 5}; // böyle de alternatif bir yol varmýs 
	//c1.name = "madem"; // olmuyor
	printf("%d %s",c1.a, c1.name);
	
	
	return 0;
}
