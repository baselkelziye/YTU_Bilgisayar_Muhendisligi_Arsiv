#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct image_pr{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};
typedef struct image_pr Image;

unsigned char rgb2gray(Image buff){
	return (buff.r*0.3) + (buff.g*0.59)	+ (buff.b*0.11); //conversion formula of rgb to gray
}

int main()
{
	int i,j; 
	unsigned char byte[54],tmp;
	int size;
	
	
	
	clock_t start, stop;

	start = clock();											// Note the start time for profiling purposes.


	FILE *fIn = fopen("images/lena_color.bmp","r");					//Input File name
	FILE *fOut = fopen("images/lena_gray.bmp","w+");		    	//Output File name
	
	if(fIn==NULL)												// check if the input file has not been opened succesfully.
	{											
		printf("File does not exist.\n");
	}

	for(i=0;i<54;i++)											//read the 54 byte header from fIn
	{									
		byte[i] = getc(fIn);								
	}

	fwrite(byte,sizeof(unsigned char),54,fOut);					//write the header back

	// extract image height, width and bitDepth from imageHeader 
	int height = *(int*)&byte[18];
	int width = *(int*)&byte[22];
	int bitDepth = *(int*)&byte[28];

	printf("width: %d\n",width);
	printf("height: %d\n",height );

	size = height*width;									//calculate image size
								
	//buffer=(Image*)malloc(size*sizeof(Image));				//to store the image data
	Image buffer[size];
	for(i=0;i<size;i++)											//RGB to gray
	{
		buffer[i].b=getc(fIn);									//blue
		buffer[i].g=getc(fIn);									//green
		buffer[i].r=getc(fIn);									//red
			
		tmp=rgb2gray(buffer[i]);		

		putc(tmp,fOut);
		putc(tmp,fOut);
		putc(tmp,fOut);
	}
	
	fclose(fOut);
	fclose(fIn);

	stop = clock();
	printf("\nCLOCKS_PER_SEC = %ld\n",stop-start); 
	printf("%lf ms\n",((double)(stop-start) * 1000.0)/CLOCKS_PER_SEC );
	return 0;
}


