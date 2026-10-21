// 18011072 - Mustafa Kemal Ekim
#include <stdio.h>
#include <math.h>	// sqrt()
#include <stdlib.h> // qsort()

typedef struct Point {
    int x, y;
} Point;

int compareX(const void* a, const void* b);
int compareY(const void* a, const void* b);
float minimum(float x, float y);
float distance(Point p1, Point p2);
float closestLast(Point controlArr[], int size, float dMin);

float bruteForce(int size, Point P[]){
	int i,j;
	float minimum = 10000.0; // max float da kullanilabilirdi
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(distance(P[i],P[j]) < minimum){
			minimum = distance(P[i],P[j]);
			printf("\nNoktalar: %d %d",P[i].x,P[i].y);
			printf("\nNoktalar: %d %d",P[j].x,P[j].y);
			//printf("\nbruteForce dMin:%f",minimum);
			}
		}
	}
	
	return minimum;
}

float closestFirst(int size, Point P[]){
//	printf("\nClosestFirst");
	if (size <= 3){	// 2 veya 3 nokta kaldiysa -> bruteForce
//		printf("\nBruteForce");
		return bruteForce(size, P);
	}
	
	int mid = size/2; // orta noktayi bulma
	Point midPoint = P[mid];
	
	printf("\ndleft -> mid=%d",mid);
	float dLeft = closestFirst(mid, P);				// sol parca
	printf("\ndLeft: %f",dLeft);
	
	printf("\ndright -> size-mid=%d",size-mid);
    float dRight = closestFirst(size-mid, P + mid);	// sag parca
    printf("\ndRight: %f",dRight);
    
    float dMin = minimum(dLeft,dRight); // kucuk olani secme
    printf("\ndMin: %f\n",dMin);
    
    Point controlArr[size]; // d uzakligindaki noktalari tutmak icin
    int i,j=0;
    for(i=0;i<size;i++){
    	if(abs(P[i].x - midPoint.x) < dMin){ // x'ler farki < d ise sakla
    		controlArr[j] = P[i];
    		j++;
    		//printf("\ncontrolArr noktalari: %d %d\n",P[i].x,P[i].y);
		}
	}
    
	return minimum(dMin,closestLast(controlArr,j,dMin));
}


int main(){
	
	FILE * fp; 
	fp = fopen("sample.txt", "r");
	
	int ch;
	int count=0; // satir sayisi saymak icin
	ch = fgetc(fp); // fgetc -> siradaki karakteri okur
	while(ch != EOF){ // karakterler bitene kadar loop
		if(ch == '\n'){
			count ++;
		}
		ch = fgetc(fp);
	}
	
	rewind(fp); // basa donmek icin
	
	count += 1;
	printf("Satir sayisi: %d",count);
	printf("\n");
	
	Point P[count]; // struct dizisi (x,y) ikilileri

	int i;
	for(i=0;i<count;i++){
		fscanf(fp, "%d %d\n", &P[i].x, &P[i].y); // dosyadan scan ve store islemi
	}
	
	qsort(P, count, sizeof(Point), compareX); // x'e gore siralama
	
	for(i=0;i<count;i++){
		printf("%d %d\n",P[i].x,P[i].y); // sirali ikilileri yazdirma
	}
	
	printf("\nEn kisa mesafe: %f ", closestFirst(count, P));
	
	fclose(fp);
	return 0;
}

// x'e gore siralama
int compareX(const void* a, const void* b){
    Point *p1 = (Point *)a;
	Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// y'ye gore siralama
int compareY(const void* a, const void* b){
    Point *p1 = (Point *)a;
	Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// minimumu bulma
float minimum(float x, float y){
    return (x < y)? x : y;
}

// iki nokta arasi uzaklik bulma
float distance(Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float closestLast(Point controlArr[], int size, float dMin){
	float minimum = dMin;

	qsort(controlArr, size, sizeof(Point), compareY);
	
	int i,j;
	for(i=0;i<size;i++){
		for(j=i+1;j<size && (controlArr[j].y - controlArr[i].y) < minimum; j++){
			if(distance(controlArr[i],controlArr[j]) < minimum ){
				minimum = distance(controlArr[i],controlArr[j]);
				printf("\nNoktalar: %d %d",controlArr[i].x,controlArr[i].y);
				printf("\nNoktalar: %d %d",controlArr[j].x,controlArr[j].y);
			} 
		}
	}
	
	return minimum;
}
