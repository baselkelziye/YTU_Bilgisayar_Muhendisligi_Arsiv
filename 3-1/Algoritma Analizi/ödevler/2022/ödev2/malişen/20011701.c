#include <stdio.h>
#include <stdlib.h>
#define BIGGEST(x, y, z) ( (x > y && x > z) ? x : ( y > z) ? y : z )

typedef struct various{
	int startIndex;
	int stopIndex;
	int maximumValue;
}VAR;

void swap(int start,int stop, int maximum, VAR *variable,int border){
	if(border>variable->maximumValue){
		variable->maximumValue=maximum;
		variable->stopIndex=stop;
		variable->startIndex=start;
	}
	
}
void totalResultBruteForce(int *arr, int n,VAR *variable){
	
	int i, j, tmp;	
	for(i = 0; i < n; i++){
		tmp = 0;
		for(j = i; j < n; j++){
			tmp += arr[j];
			if(tmp > variable->maximumValue){	
				variable->maximumValue = tmp;
				variable->startIndex = i;
				variable->stopIndex = j;
			}
		}
	}
	
}
int totalResult(int *arr, int left, int right,VAR * variable) {
	int i,tmpLeft,tmpRight;
    if (left == right) {
	if (arr[left] > 0) return arr[left];
	else return 0;
    }
    int center = (left + right) / 2;
    int totalMaxLeft = totalResult(arr, left, center,variable);
    int totalMaxRight = totalResult(arr, center + 1, right,variable);
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (i = center; i >= left; i--) {
	leftBorderSum += arr[i];
	if (leftBorderSum > maxLeftBorderSum){
		maxLeftBorderSum = leftBorderSum;
		tmpLeft=i;
		swap(i,center,leftBorderSum,variable,leftBorderSum);
	}
		 
    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {
	rightBorderSum += arr[i];
	if (rightBorderSum > maxRightBorderSum){
		maxRightBorderSum = rightBorderSum;
		tmpRight=i;
		swap(center+1,i,rightBorderSum,variable,rightBorderSum);
	} 
    }
    	swap(tmpLeft,tmpRight,totalMaxLeft+totalMaxRight,variable,totalMaxLeft+totalMaxRight);

    return BIGGEST(totalMaxLeft, totalMaxRight, maxLeftBorderSum + maxRightBorderSum);
}

int main() {
	VAR *variable;
	int *arr;
    int i,N;
    
    variable = (VAR*)malloc(sizeof(VAR));
		if(!variable) {
 	 	printf("omg malloc failed var");
	}
	variable->maximumValue = -1000000;
	variable->startIndex = 0;
	variable->stopIndex = 0;
    printf("Array uzunlugunu giriniz\n");
    scanf("%d", &N);
    
    arr = (int *)malloc(sizeof(int) * N);
    	if(!arr) {
 	 	printf("omg malloc failed arr");
	}

    printf("Degerleri giriniz\n ");
    for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
    }
    printf("Girilen Degerler: ");
        for (i = 0; i < N; ++i) {
            printf("%d, ", arr[i]);
   
	}
    /*

  int N,i;
  // int arr[]={8,-30,36,2,-6,52,8,-1,-11,10,4};
  //  N=sizeof(arr)/sizeof(arr[0]);
  int *arr;
  VAR* variable;
	printf("Array uzunlugunu giriniz\n");
	scanf("%d", &N);

   arr = (int*)malloc(sizeof(int)*N);
   
    if (arr == NULL) {
        printf("Bellek ayrilamadi.\n");
        return 0;
    }
    else {
    	printf("Degerleri giriniz\n");
        for (i = 0; i < N; ++i) {
            scanf("%d", &arr[i]);
        }
        printf("The elements of the array are: ");
        for (i = 0; i < N; ++i) {
            printf("%d, ", arr[i]);
        }
     }
     
    
    
    //printf("Input array: ");
   // for (int i = 0; i < N; i++) {
	//scanf("%d", &arr[i]);
   // }
   
   
   */
    printf("\n");
	totalResultBruteForce(arr,N,variable);
	printf("BRUTE FORCE SONUCU : %d, baslangic indisi: %d, son indis: %d\n",variable->maximumValue,variable->startIndex,variable->stopIndex);
    variable->maximumValue=totalResult(arr, 0, N - 1,variable);
    printf("DIVIDE&CONQ SONUCU : %d, baslangic indisi: %d, son indis: %d\n",variable->maximumValue,variable->startIndex,variable->stopIndex);
	return 0;
}
