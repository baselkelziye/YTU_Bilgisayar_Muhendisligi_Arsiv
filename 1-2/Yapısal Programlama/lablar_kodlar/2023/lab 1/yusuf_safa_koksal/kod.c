#include <stdio.h>

#define MAX 50

void bubbleSort(int grades[],int len);
void getMaxAndMinGrades(int grades[],int minGrades[3],int maxGrades[3],int len);
void printMaxAndMinGradesAndSum(int minGrades[3],int maxGrades[3]);

int main(){
	int i;
	int len;
	int grades[MAX] ,minGrades[3] ,maxGrades[3];
	
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d",&len);
	
	while(len<6){
		printf("Girilecek not sayisi 6'dan buyuk olmalidir!'\nDizinin boyutunu giriniz: ");
		scanf("%d",&len);
	}
	
	printf("Dizinin elemanlarini giriniz:\n");
	for(i=0;i<len;i++){
		scanf("%d",&grades[i]);
	}
	
	bubbleSort(grades,len);
	getMaxAndMinGrades(grades,minGrades,maxGrades,len);
	printMaxAndMinGradesAndSum(minGrades,maxGrades);
	
	return 0;
}

void bubbleSort(int grades[],int len){
	int i ,j ,tmp;
	
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			if(grades[j]>grades[j+1]){
				tmp=grades[j];
				grades[j]=grades[j+1];
				grades[j+1]=tmp;
			}
		}
	}
}

void getMaxAndMinGrades(int grades[],int minGrades[3],int maxGrades[3],int len){
	int i=0;
	
	for(i=0;i<3;i++){
		minGrades[i]=grades[i];
	}
	
	for(i=len-1;i>=len-3;i--){
		maxGrades[len-i-1]=grades[i];
	}
}

void printMaxAndMinGradesAndSum(int minGrades[3],int maxGrades[3]){
	int i=0, totalMin=0, totalMax=0;
	
	printf("En dusuk 3 not:");
	for(i=0;i<3;i++){
		printf(" %d",minGrades[i]);
		totalMin+=minGrades[i];
	}
	printf("\nEn dusuk 3 not toplami: %d",totalMin);
	
	printf("\nEn yuksek 3 not:");
	for(i=0;i<3;i++){
		printf(" %d",maxGrades[i]);
		totalMax+=maxGrades[i];
	}
	printf("\nEn yuksek 3 not toplami: %d",totalMax);
}
