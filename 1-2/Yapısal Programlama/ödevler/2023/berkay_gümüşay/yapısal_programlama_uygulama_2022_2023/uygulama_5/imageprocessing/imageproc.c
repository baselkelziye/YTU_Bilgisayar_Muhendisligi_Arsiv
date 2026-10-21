#include <stdio.h>
#include <stdlib.h>

typedef struct pixel{
	unsigned char r, g, b;
}PIXEL;

#define SIZE 550
int main(){
	FILE *fIn, *fOut;
	fIn = fopen("images/lena_color.bmp","r");
	fOut= fopen("images/lena_rotate2.bmp","w+");
	int height, width, bitDepth;
	PIXEL source[SIZE][SIZE], dest[SIZE][SIZE];
	int i, j;
	unsigned char byte[54];
	for(i=0;i<54;i++){
		byte[i] = getc(fIn);
	}
	
	fwrite(byte,sizeof(unsigned char),54,fOut);
	height = *(int*)&byte[18];
	width = *(int*)&byte[22];
	bitDepth = *(int*)&byte[28];
	
	printf("Height %d, Width %d, Depth %d\n",height, width, bitDepth);
	
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			source[i][j].b = getc(fIn);
			source[i][j].g = getc(fIn);
			source[i][j].r = getc(fIn);
		}
	}
	
	
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			dest[j][height-1-i].r = source[i][j].b;
			dest[j][height-1-i].g = source[i][j].g;
			dest[j][height-1-i].b = source[i][j].r;
			/*dest[j][height-1-i].r = source[i][j].b; // bu şekilde yazılırsa resim farklı bir renkte görünür, çünkü bmp formatı bgr sırasıyla veri kaydeder.
			dest[j][height-1-i].g = source[i][j].g;
			dest[j][height-1-i].b = source[i][j].r;*/
		}
	}
	
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			putc(dest[i][j].r,fOut);
			putc(dest[i][j].g,fOut);
			putc(dest[i][j].b,fOut);	
		}
	}
	
	fclose(fIn);
	fclose(fOut);
	
}

