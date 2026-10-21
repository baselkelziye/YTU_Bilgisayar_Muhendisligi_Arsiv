#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hasta{     
	int  randevu_no;      
	char isim[10];       
	char poliklinik[10];  
	char gun[10];	      
}HASTA;

int main(){
	FILE *fp;
	HASTA h[4]={{1,"ali","dahiliye","salý"},{2,"veli","goz","cuma"},{3,"ayse","cerrahi","pazar"},{4,"fatma","goz","salý"}};
	int N = 4;
	HASTA *ptr = (HASTA*) malloc(N*sizeof(HASTA));
	fp = fopen("input.txt","w+");
	fwrite(&N,sizeof(int),1,fp);
	fwrite(h,sizeof(HASTA)*N,1,fp);
	fclose(fp);
}

