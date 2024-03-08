#include <stdio.h>
#include <string.h>
#include "image_processing.cpp"

int main(void){
    int M1, M2, N1, N2, Q1, Q2;
    bool type1, type2;
    FILE *txt_dosya;
	char ogrno[10], metin[60];
    
    char resimadi1[] = "lena.pgm";
    readImageHeader(resimadi1, N1, M1, Q1, type1);
	int** lena = resimOku(resimadi1); 
	
    char resimadi2[] = "ste_fc\\09011038.pgm";			
	readImageHeader(resimadi2, N1, M1, Q1, type1);
	int** steganografik = resimOku(resimadi2);
		
	int i, j;
		
	for(i = M1-1; i >= 0; i--)
		for(j = 0; j < N1; j++)
			if(lena[j][i] != steganografik[j][i])
				printf("%c", (((steganografik[j][i] + 256) - lena[j][i]) % 256));
	printf("\n");
	
	
	system("PAUSE");
	return 0;
}

