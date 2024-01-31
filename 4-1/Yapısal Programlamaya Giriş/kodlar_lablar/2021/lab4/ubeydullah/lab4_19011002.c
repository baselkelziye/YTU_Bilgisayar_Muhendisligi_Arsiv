#include<stdio.h>


int recursive(int arr[], int n, int gerekenE, int dongu)
{
    // if triplet has the desired sum, return true
    if (dongu == 3 && gerekenE == 0) {
        return 1;
    }
 
    if (dongu == 3 || n == 0 || gerekenE < 0) {
        return 0;
    }
 
    return recursive(arr, n - 1, gerekenE - arr[n - 1], dongu + 1)||recursive(arr, n - 1, gerekenE, dongu);
}



int main(){
	int butonlar[20],n,gerekenE,i;
	
	printf("Kac buton bulunmakta?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("buton[%d]=  ",i);
		scanf("%d",&butonlar[i]);
	}
	printf("Gereken Enerji Ne Kadar\n");
	scanf("%d",&gerekenE);
	
	if(recursive(butonlar,n,gerekenE,0)==1){
		printf("Ampul Yanar");
	}
	else{
		printf("Ampul Yanmaz");
	}
	
	return 0;
}


