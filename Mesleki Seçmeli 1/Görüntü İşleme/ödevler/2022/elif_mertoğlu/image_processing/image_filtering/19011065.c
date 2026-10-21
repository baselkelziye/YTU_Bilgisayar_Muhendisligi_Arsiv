#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.142857

typedef struct{
	int **matrix;
	int width; 
	int height; 
	char type[3];
	int maxVal;
}pgm;

void read_comments(FILE *);
pgm *readPGMFile(char*, pgm* );
void writePGMFile(pgm *, int **, char *);
double **createGaussianFilter(int ,float );
int **doConvolution(pgm *, int , double **);
void minMaxNor(pgm*, int **);
void doSobelFilter(pgm *);
void doGaussianFilter(int , float , pgm *);
void doSobelOnGaussian(char *);
void doLaplacianFilter1(pgm *image);
void doLaplacianFilter2(pgm *image);
void doLaplacianOnGaussian(int , char *);

int main(){
	
	int i,j;
	pgm *mypgm, *readpgm;
	char filename[20];
	
	mypgm = (pgm*)malloc(sizeof(pgm));
	
	printf("Enter the PGM file name.\n");
	scanf("%s",filename);
	
	readpgm = readPGMFile(filename,mypgm);
	doGaussianFilter(7,4.0,readpgm);
	doSobelFilter(readpgm);
	doSobelOnGaussian(filename);
	doLaplacianOnGaussian(1,filename);
	
	return 0;
}

pgm *readPGMFile(char *filename, pgm* mypgm){
	
	FILE *fp;
	int i,j;
	fp=fopen(filename,"rb");
	if(fp == NULL){
		printf("File could not be opened.\n");
		exit(1);
	}
	
	fscanf(fp,"%s",mypgm->type);
	read_comments(fp);
	fscanf(fp,"%d %d",&mypgm->width,&mypgm->height); 
	fscanf(fp,"%d",&mypgm->maxVal);
		
	mypgm->matrix = (int**)malloc(mypgm->height*sizeof(int*));
	if(mypgm->matrix == NULL){
		printf("Null pointer error.\n");
		exit(1);
	}
	for(i = 0; i < mypgm->height; i++) {
		mypgm->matrix[i]=(int*)malloc(mypgm->width*sizeof(int));
		if(mypgm->matrix[i]==NULL){
			printf("Null pointer error.\n");
			exit(1);
		}	
	}
	
	if(strcmp(mypgm->type,"P2") == 0){
		
		for(i=0;i<mypgm->height;i++){
			for(j=0;j<mypgm->width;j++){
				fscanf(fp,"%d",&mypgm->matrix[i][j]);
			}
		}
	}else{
		unsigned char tmp;
		for (i = 0; i < (mypgm->height); i++) {
			for(j=0;j<mypgm->width;j++){
				fread(&tmp,sizeof(unsigned char),1,fp); 
		  		mypgm->matrix[i][j]=tmp;
			}   
	   	}	
	}
	fclose(fp);
	
	return mypgm;
	
}

void writePGMFile(pgm *mypgm, int **matrix, char *filename){
	
	FILE *fp;
	int i,j;
	
	fp=fopen(filename,"wb");
	if(fp == NULL){
		printf("File could not be opened.\n");
		exit(1);
	}
	
	fprintf(fp, "%s\n", mypgm->type);
	fprintf(fp, "%d %d\n", mypgm->width, mypgm->height);
	fprintf(fp, "%d\n", mypgm->maxVal);
	
	if(strcmp(mypgm->type,"P2") == 0){
		for(i=0;i<mypgm->height;i++){
			for(j=0;j<mypgm->width;j++){
				if(j!=(mypgm->width-1)){
					fprintf(fp,"%d ",matrix[i][j]);
				}else{
					fprintf(fp,"%d",matrix[i][j]);
					fprintf(fp, "\n");
				}
			}
		}
	}else{
		for(i=0;i<mypgm->height;i++){
			for(j=0;j<mypgm->width;j++){
				char data = matrix[i][j];
				fprintf(fp,"%c", data);
			}		
		}
	}
	fclose(fp);
	
}

double **createGaussianFilter(int size, float sigma){
	
	double **gaussianFilter, sum = 0.0;
	int i,j;
	float constant, e, denominator;
	int numerator;
	
	gaussianFilter = (double**)malloc(size*sizeof(double*));
	if(gaussianFilter == NULL){
		printf("Error allocating.\n");
		exit(1);
	}
	for(i=0;i<size;i++){
		gaussianFilter[i] = (double*)malloc(size*sizeof(double));
		if(gaussianFilter[i] == NULL){
			printf("Error allocating.\n");
			exit(1);
		}
	}
	
	constant = 2 * PI * sigma * sigma;
	denominator = 2 * sigma * sigma;
	
	if(size == 3){
		for(i=-1;i<2;i++){
			for(j=-1;j<2;j++){
				numerator = -(i*i+j*j);
				e = numerator/denominator;
				gaussianFilter[i+1][j+1] = exp(e)/constant;
				sum += gaussianFilter[i+1][j+1];
			}
		}
	}else if(size == 5){
		for(i=-2;i<3;i++){
			for(j=-2;j<3;j++){
				numerator = -(i*i+j*j);
				e = numerator/denominator;
				gaussianFilter[i+2][j+2] = exp(e)/constant;
				sum += gaussianFilter[i+2][j+2];

			}
		}
	}else if(size == 7){
		for(i=-3;i<4;i++){
			for(j=-3;j<4;j++){
				numerator = -(i*i+j*j);
				e = numerator/denominator;
				gaussianFilter[i+3][j+3] = exp(e)/constant;
				sum += gaussianFilter[i+3][j+3];
			}
		}
	}
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			gaussianFilter[i][j] /= sum;
		}
	}	

	return gaussianFilter;
}

int **doConvolution(pgm *image, int filterSize, double **filter){
	int i,j,x,y,k=0,l=0,outsiders,output_width, output_height,limit = filterSize-1;
	double sum = 0.0, **temp;
	
	pgm *image_temp = (pgm*)malloc(sizeof(pgm));
	strcpy(image_temp->type,image->type);
	image_temp->height = image->height;
	image_temp->width = image->width;
	image_temp->maxVal = image->maxVal;
	image_temp->matrix = (int**)malloc(image_temp->height*sizeof(int*));
	for(i=0;i<image_temp->height;i++){
		image_temp->matrix[i] = (int*)malloc(image_temp->width*sizeof(int));
	}
	
	for(i=0;i<image->height;i++){
		for(j=0;j<image->width;j++){
			image_temp->matrix[i][j] = image->matrix[i][j];
		}
	}
	
	output_width = image_temp->width-filterSize+1;
	output_height = image_temp->height-filterSize+1;
	
	temp = (double**)malloc(output_height*sizeof(double*));
	for(i=0;i<output_height;i++){
		temp[i] = (double*)malloc(output_width*sizeof(double));
	}
	
	for(i=0;(i<image_temp->height-limit);i++){
		for(j=0;j<(image_temp->width-limit);j++){
			for(x=0;x<filterSize;x++){
				for(y=0;y<filterSize;y++){
					sum += image_temp->matrix[x+i][y+j] * filter[x][y];
				}
			}
			if(l == output_width-1){
				temp[k][l] = sum;
				l = 0;
				k++;
			}else{
				temp[k][l] = sum;
				l++;
			}
			sum = 0;
		}
	}
	
	outsiders = (filterSize-1)/2; // 1 for 3x3 kernel
	k = 0;
	l = 0;
	
	for(i=outsiders;i<(image_temp->height-outsiders);i++){
		for(j=outsiders;j<(image_temp->width-outsiders);j++){
			if(l == output_width-1){
				image_temp->matrix[i][j] = round(temp[k][l]);
				l = 0;
				k++;
			}else{
				image_temp->matrix[i][j] = round(temp[k][l]);
				l++;
			}	
		}
	}
	
	free(temp);
	return image_temp->matrix;
	
}

void doSobelFilter(pgm *image){
	
	int i,j;
	pgm *output_image = (pgm*)malloc(sizeof(pgm));
	double **sobelx = (double**)malloc(3*sizeof(double*));
	for(i=0;i<3;i++){
		sobelx[i] = (double*)malloc(3*sizeof(double));
	}
	
	double **sobely = (double**)malloc(3*sizeof(double*));
	for(i=0;i<3;i++){
		sobely[i] = (double*)malloc(3*sizeof(double));
	}
	
	int **outx = (int**)malloc(image->height*sizeof(int*));
	for(i=0;i<image->height;i++){
		outx[i] = (int*)malloc(image->width*sizeof(int));
	}
	
	int **outy = (int**)malloc(image->height*sizeof(int*));
	for(i=0;i<image->height;i++){
		outy[i] = (int*)malloc(image->width*sizeof(int));
	}
	
	output_image->matrix = (int**)malloc(image->height*sizeof(int*));
	for(i=0;i<image->height;i++){
		output_image->matrix[i] = (int*)malloc(image->width*sizeof(int));
	}
	strcpy(output_image->type,image->type);
	output_image->height = image->height;
	output_image->width = image->width;
	output_image->maxVal = image->maxVal;
	
	sobelx[0][0] = -1.0;
	sobelx[0][1] = 0.0;
	sobelx[0][2] = 1.0;
	sobelx[1][0] = -2.0;
	sobelx[1][1] = 0.0;
	sobelx[1][2] = 2.0;
	sobelx[2][0] = -1.0;
	sobelx[2][1] = 0.0;
	sobelx[2][2] = 1.0;
	
	sobely[0][0] = -1.0;
	sobely[0][1] = -2.0;
	sobely[0][2] = -1.0;
	sobely[1][0] = 0.0;
	sobely[1][1] = 0.0;
	sobely[1][2] = 0.0;
	sobely[2][0] = 1.0;
	sobely[2][1] = 2.0;
	sobely[2][2] = 1.0;
	
	outx = doConvolution(image,3,sobelx);
		
	outy = doConvolution(image,3,sobely);

	for(i=0;i<image->height;i++){
		for(j=0;j<image->width;j++){
			output_image->matrix[i][j] = sqrt(outx[i][j]*outx[i][j] + outy[i][j]*outy[i][j]);
		}
	}
	
	minMaxNor(image,outx);
	writePGMFile(image,outx,"sobelx.pgm");
	minMaxNor(image,outy);
	writePGMFile(image,outy,"sobely.pgm");
	minMaxNor(output_image,output_image->matrix);
	writePGMFile(output_image,output_image->matrix,"sobelxy.pgm");
	
}

void doGaussianFilter(int filterSize, float sigma, pgm *image){
	
	double **filter;
	int **convolved_image;
	
	filter = createGaussianFilter(filterSize,sigma);
	convolved_image = doConvolution(image,filterSize,filter);
	minMaxNor(image,convolved_image);
	writePGMFile(image, convolved_image, "gauss.pgm");
	
}

void doSobelOnGaussian(char *filename){
	
	pgm *sobGaussPgm = (pgm*)malloc(sizeof(pgm));
	doSobelFilter(readPGMFile(filename, sobGaussPgm));
	
}

void doLaplacianFilter1(pgm *image){
	
	int ** output_image;
	int i;
	double **lapFil1;
	
	output_image = (int**)malloc(image->height*sizeof(int*));
	for(i=0;i<image->height;i++){
		output_image[i] = (int*)malloc(image->width*sizeof(int));
	}
	
	lapFil1 = (double**)malloc(3*sizeof(double*));
	for(i=0;i<3;i++){
		lapFil1[i] = (double*)malloc(3*sizeof(double));
	}

	lapFil1[0][0] = 0.0;	lapFil1[0][1] = -1.0;	lapFil1[0][2] = 0.0;
    lapFil1[1][0] = -1.0;	lapFil1[1][1] = 4.0;	lapFil1[1][2] = -1.0;
    lapFil1[2][0] = 0.0;	lapFil1[2][1] = -1.0;	lapFil1[2][2] = 0.0;
    
    
    output_image = doConvolution(image,3,lapFil1);
    minMaxNor(image, output_image);
    writePGMFile(image, output_image, "laplacian1.pgm");
}

void doLaplacianFilter2(pgm *image){
	
	int **output_image;
	double **lapFil2;
	int i;
	
	output_image = (int**)malloc(image->height*sizeof(int*));
	for(i=0;i<image->height;i++){
		output_image[i] = (int*)malloc(image->width*sizeof(int));
	}
	
	lapFil2 = (double**)malloc(3*sizeof(double*));
	for(i=0;i<3;i++){
		lapFil2[i] = (double*)malloc(3*sizeof(double));
	}
    
    lapFil2[0][0] = -1.0;	lapFil2[0][1] = -1.0;	lapFil2[0][2] = -1.0;
    lapFil2[1][0] = -1.0;	lapFil2[1][1] = 8.0;	lapFil2[1][2] = -1.0;
    lapFil2[2][0] = -1.0;	lapFil2[2][1] = -1.0;	lapFil2[2][2] = -1.0;
    
    output_image = doConvolution(image,3,lapFil2);
    minMaxNor(image, output_image);
    writePGMFile(image, output_image, "laplacian2.pgm");
}

void doLaplacianOnGaussian(int number, char *filename){
	
	pgm *lapGaussPgm = (pgm*)malloc(sizeof(pgm));
	
	if(number == 1){
		doLaplacianFilter1(readPGMFile(filename, lapGaussPgm));
	}else if(number == 2){
		doLaplacianFilter2(readPGMFile(filename, lapGaussPgm));
	}
	
}

void minMaxNor(pgm* image, int **matrix) {
	int min = 1000001, max = 0, i, j;
	
	for(i=0;i<image->height;i++) {
		for(j=0;j<image->width;j++) {
			if(matrix[i][j] < min) {
				min = matrix[i][j];
			}
			else if(matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
	}
	
	for(i=0;i<image->height;i++) {
		for(j=0;j<image->width;j++) {
			double ratio = (double) (matrix[i][j] - min) / (max - min);
			matrix[i][j] = ratio * 255;
		}
	} 
}

void read_comments(FILE *input_image) {
	char ch;
	char line[100];

	while ((ch = fgetc(input_image)) != EOF && (isspace(ch)))  {
		;
    }
	if (ch == '#') {
        fgets(line, sizeof(line), input_image);
    } 
	else {
		fseek(input_image, -2L, SEEK_CUR);
	}
}

