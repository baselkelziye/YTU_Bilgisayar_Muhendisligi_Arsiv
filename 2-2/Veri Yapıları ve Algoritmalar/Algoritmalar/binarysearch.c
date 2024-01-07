#include <stdio.h>
#include <stdlib.h>

int* getElements(int n){
	int i,*arr;
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
	printf("%d. Element: ",i+1); scanf("%d",&arr[i]); 	
	}
	return arr;
}

int binarySearch(int *arr,int h,int l,int wanted){
	
	if(h>=l){
		int mid=l+(h-l-1)/2;	
	
	if(arr[mid]==wanted)
		return mid;
	if(arr[mid]>wanted)
		return binarySearch(arr,mid-1,l,wanted);
	if(arr[mid]<wanted)
		return binarySearch(arr,h,mid+1,wanted);	
	}
	return -1;
}

int main(){
	
	int *arr,n,i,opt=1,wanted;
	
	printf("Enter Number Of Element: "); scanf("%d",&n);
	
	arr=(int*)malloc(n*sizeof(int));
	
	arr=getElements(n);
	
	while(opt!=0){
		printf("Press 1 To Search Number\nPress 2 To Shut The Program\n"); scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter The Element To Be Searched: "); scanf("%d",&wanted);
				int h=n,l=0,isFound=0;
				isFound=binarySearch(arr,h,l,wanted);
				if(isFound!=-1){
					printf("Element Found At %d. Index\n",isFound);
				}
				break;
			default:
			opt=0;	
		}
	}
	free(arr);
return 0;	
}
	
