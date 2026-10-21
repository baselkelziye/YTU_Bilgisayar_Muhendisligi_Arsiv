#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Points{
	int x;
	int y;
}Points;

int howManyRows(); //verilen dosyadaki satir sayisini(nokta sayisi) int cinsinden dondurur.
Points *readFromFile(); //noktalarin koordinatlarinin dosyadan okunmasi islemini yapar. 
float bruteForce(Points *, int, Points *, Points *); //iki veya uc nokta arasindaki mesafeyi bulur.
float findingSmallestDistance(Points *, int, Points *, Points  *); //veri setindeki noktalar arasindaki en kisa mesafeyi 
																   //ve bu noktalarin hangileri oldugunu bulur.
void merge(Points *, int , int , int ); 
void mergeSort(Points *, int , int ); //noktalari x'e gore kucukten buyuge siralar.

int main(){
	
	Points *p4Points; //fonksiyonlardan donen struct dizisini tutabilmek icin.
	int numberOfPoints; //fonksiyona nokta sayisini gonderebilmek icin.
	float min; //findingSmallestdistance fonksiyonundan donen en kisa mesafeyi tutabilmek icin.
	Points p1 ; //findingSmallestdistance fonksiyonunda hesaplanan en kisa mesafeye sahip noktalardan birincisi. 
	Points p2 ; //findingSmallestdistance fonksiyonunda hesaplanan en kisa mesafeye sahip noktalardan ikincisi. 
	
	p4Points=readFromFile(); 
	numberOfPoints=howManyRows();
	mergeSort(p4Points,0,numberOfPoints-1);
	min=findingSmallestDistance(p4Points,numberOfPoints,&p1,&p2);
	printf("the smallest difference is: %f between p1: (%d, %d) and p2: (%d, %d)",min,p1.x,p1.y,p2.x,p2.y);
	
	return 0;
}

int howManyRows(){
	
	FILE *fp;
	int rows=0; //dosyadaki satir sayisi(yani nokta sayisi) tutulacak
	int junk; //dosyayi okurken degerleri almak icin 
	
	fp=fopen("sample.txt","r");
	if(fp==NULL){
		printf("Error.\n");
		return;
	};

	while(!feof(fp)){
		fscanf(fp,"%d %d\n",&junk,&junk);
		rows++; 
	};
	fclose(fp);
	
	return rows;
};

Points  *readFromFile(){
	
	FILE *fp; //sample.txt dosyasini acabilmek icin file pointer.
	Points *points; //sample.txt dosyasindan verileri dynamic memory allocation kullanarak diziye kaydetmek icin pointer.
	int i,j; //dizi indisi
	int row=0; //sample.txt dosyasinda kac adet nokta oldugunu hesaplamak icin

	row=howManyRows();
	
	fp=fopen("sample.txt","r");
	if(fp==NULL){
		printf("Error.\n");
		return;
	};
	
	points=(Points*)malloc(row*sizeof(Points));

	for(i=0;i<row;i++){
		fscanf(fp,"%d %d\n",&points[i].x,&points[i].y); 
	};
	fclose(fp);
	
	return points;
	
};

void merge(Points *points, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1; //sol bolgenin eleman sayisi
    int n2 = r - m; //sag bolgenin eleman sayisi
  
    Points L[n1], R[n2]; //gecici diziler tanimlanir
  
    for (i=0;i<n1;i++)
        L[i]=points[l+i];
    for (j=0;j<n2;j++)
        R[j]=points[m+1+j];
  
    i=0; 
    j=0; 
    k=l; 
    while (i<n1&&j<n2) {
        if (L[i].x <= R[j].x) {
            points[k]=L[i];
            i++;
        }
        else {
            points[k]=R[j];
            j++;
        }
        k++;
    };
  
    while (i<n1) {
        points[k]=L[i];
        i++;
        k++;
    };
  
    while (j<n2) {
        points[k]=R[j];
        j++;
        k++;
    };
};

void mergeSort(Points *points, int l, int r){
    if (l<r) {
        int m=l+(r-l)/2;
  
        mergeSort(points,l,m); 
        mergeSort(points,m+1,r); 
  
        merge(points,l,m,r); 
    };
};

float findingSmallestDistance(Points *points, int numOfPoints, Points *p1, Points *p2){
	
	int middle; //medyan degerini tutar.
	float dleft; //sol bolgeden gelen, iki nokta arasindaki en kucuk mesafeyi tutar.
	float dright; //sag bolgeden gelen, iki nokta arasindaki en kucuk mesafeyi tutar.
	float d; //sag ve sol bolgeden gelen degerlerin en kucunu tutar.
	
	if(numOfPoints>=2 && numOfPoints<=3){ //initial condition
		return bruteForce(points,numOfPoints,p1,p2);
	};
	
	middle=numOfPoints/2; //medyan degerini hesapla
	Points minLeft1, minLeft2; // sol bolgeden gelen en kucuk mesafeli noktalari tutar
	dleft=findingSmallestDistance(points,middle,&minLeft1,&minLeft2);
	Points minRight1, minRight2; //sag bolgeden gelen en kucuk mesafeli noktalari tutar
	dright=findingSmallestDistance(points+middle,numOfPoints-middle,&minRight1,&minRight2);
	
	if(dleft<dright){
		d=dleft;
		*p1=minLeft1;
		*p2=minLeft2;
	}else{
		d=dright;
		*p1=minRight1;
		*p2=minRight2;
	};
	
	Points close2Med[6];
	int i;
	int j=0;
	for(i=0;i<numOfPoints;i++){
		if(abs(points[i].x-points[middle].x)<d){
			close2Med[j]=points[i];
			j++;
		};
	};
	
	int size=j;
	
	for(i=0;i<size;++i){
		for(j=i+1;j<size;++j){
			if(abs(close2Med[i].y-close2Med[j].y)<d){
				if(sqrt((close2Med[i].y-close2Med[j].y)*(close2Med[i].y-close2Med[j].y) + (close2Med[i].x-close2Med[j].x)*(close2Med[i].x-close2Med[j].x))<d){
					d=sqrt((close2Med[i].y-close2Med[j].y)*(close2Med[i].y-close2Med[j].y) + (close2Med[i].x-close2Med[j].x)*(close2Med[i].x-close2Med[j].x));
					*p1=close2Med[i];
					*p2=close2Med[j];
				};
			};
		};
	};
	
	return d;
	
};

float bruteForce(Points *points, int numOfPoints, Points *p1, Points *p2){
	
	int i,j; //indisler
	int distance; //iki nokta arasindaki uzaklik degeri
	float min=10000.0; //hesaplanan degerler arasindan cikacak olan en kucuk mesafeyi tutar.
	
	for(i=0;i<numOfPoints;i++){
		for(j=i+1;j<numOfPoints;j++){
			distance=sqrt((points[i].y-points[j].y)*(points[i].y-points[j].y) + (points[i].x-points[j].x)*(points[i].x-points[j].x));
			if(distance<min){
				min=distance;
				*p1=points[i];
				*p2=points[j];
			};
		};
	};
	
	return min;
};


