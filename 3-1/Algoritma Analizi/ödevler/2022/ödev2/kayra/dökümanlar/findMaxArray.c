#include <stdio.h> 
#include <limits.h>
int buyukSayiIndis(int num1, int num2,int low, int high,int lmom[],int flag) {
    if(num1 > num2)
    return num1;
	if(flag != 1){
		if(lmom[2]<num2){
			
		lmom[1] = high;
    	lmom[0] = low;	
		}
    	
	}
    return num2;
}
int minimum(int dizi[],int n){
	int i=0,min=dizi[0];
	for(i=1;i<n;i++){
		if(dizi[i]<min)
			min=dizi[i];
	}
	return INT_MIN;
}
int maximum_sum(int sayiDizisi[], int low, int high,int lmom[]){
	int i,arrlow,arrhigh;
    if (high > low) {
    int mid = (low + high) / 2,left_max = minimum(sayiDizisi,(low-high)),sum = 0,right_max = minimum(sayiDizisi,(low-high+1));;
    for (i = mid + 1; i <= high; i++){
        sum += sayiDizisi[i];
        if (sum > right_max) {
        	if(lmom[2] < sum){
        		lmom[0] = mid + 1;
        		lmom[1] = i;
        		lmom[2] = sum;	
			}
			right_max = sum;
			arrhigh = i;
        }
    }
    sum=0;
    for (i = mid; i >= low; i--){
        sum += sayiDizisi[i];
        if (sum > left_max) {
        	if(lmom[2] < sum){
        		lmom[0] = i;
        		lmom[1] = mid;
				lmom[2] = sum;	
			}
			arrlow = i;
            left_max = sum;
        }
    }
    
    int mapmax = buyukSayiIndis(maximum_sum(sayiDizisi, low, mid, lmom),
                            maximum_sum(sayiDizisi, mid + 1, high, lmom),low,high,lmom,1);
 
    return buyukSayiIndis(mapmax, left_max + right_max,arrlow,arrhigh,lmom,0);}
    return sayiDizisi[low];   
}

void findMaxValueBruteForce(int *arr, int n,int lmom[]){
	
	int i, j, tmp;	
	for(i = 0; i < n; i++){
		tmp = 0;
		for(j = i; j < n; j++){
			tmp += arr[j];
			if(tmp > lmom[2]){	
				lmom[2] = tmp;
				lmom[0] = i;
				lmom[1] = j;
			}
		}
	}
	
}
void printData(int lmom[],int flag){
	if(flag == 0){
		printf("Brute Force Sonucu\n");
	}
	else{
		printf("Divide And Conquer Sonucu\n");
	}
	printf("En Yuksek Deger ---> %d\nAralik -----> %d ==== %d\n", lmom[2], lmom[0], lmom[1]);
}

int main(){
	
	int dizi[] = {-1,-2,2,4,6,123,-3,-4,-2,-3,-5,-7,123};
	int lmom[3],size;
	
	size = sizeof(dizi)/sizeof(dizi[0]);
	lmom[2]=INT_MIN;
	findMaxValueBruteForce(dizi,size,lmom);
	printData(lmom,0);
	
	lmom[2] = minimum(dizi,size);
	lmom[2]=maximum_sum(dizi, 0, size-1,lmom);
	printData(lmom,1);
	return 0;
}
