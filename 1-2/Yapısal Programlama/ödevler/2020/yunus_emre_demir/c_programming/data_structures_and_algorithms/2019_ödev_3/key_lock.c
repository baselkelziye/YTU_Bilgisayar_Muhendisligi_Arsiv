#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void Random(int *Key, int *Lock, int l, int r, int size) {
 int boyut=r-l;
 int piv2,piv1;
 srand((unsigned) time(NULL));//for take random number
    
 if(boyut>0){
     
    piv1=Key[(rand() % boyut)+l];//  en onemli kýsým
    
    piv2=QuickS(Lock,l,r,piv1);
    QuickS(Key,l,r,Lock[piv2]);
     
    Random(Key,Lock,l,piv2-1,size);
    Random(Key,Lock,piv2+1,r,size);
 
    }
}

int QuickS(int *dizi, int sol, int sag, int piv1){
    int gecici,l,r;
    if(sol<sag){
        l=sol;
        r=sag;
        while(l<r){ 
            while(piv1>dizi[l])
                l++;
            while(piv1<dizi[r])
                r--;
        gecici=dizi[l];
        dizi[l]=dizi[r];
        dizi[r]=gecici;
        }
        int i=0;
        printf("\n piv1= %d : ",  piv1);
        while(i<10){
            printf("%d ",dizi[i]);
            i++;
      	}
    }
    return l;
}
void show(int *dizi, int size){
	int j=0;
	for(j=0;j<size;j++)
	    printf("%d  ",dizi[j]);
	
}

int main() {
   	int Key[100],Lock[100],j,size;

    printf("Array size : ");
    scanf("%d",&size);
    
		printf("Enter Key[] array : \n");
		for(j=0; j<size; j++)
	        scanf("%d",&Key[j]);
	    
	    printf("Enter Lock[] array : \n");
	    for(j=0; j<size; j++)
	        scanf("%d",&Lock[j]);

	
    Random(Lock,Key,0,size-1,size);
    
	    printf("\n Sorted Key[] array : ");
	    show(Key,size);
	    
	    printf("\nSorted Lock[] array : ");
    	show(Lock,size);
    return 0;
}
