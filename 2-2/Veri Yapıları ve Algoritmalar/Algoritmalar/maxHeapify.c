#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void maxHeap(int *heap,int n,int i){
	if(n!=1){
	int largest=i;
	int left=2*i+1,right=2*i+2;
	
	if(left<n && heap[left]>heap[largest])
	largest=left;
	if(right<n && heap[right]>heap[largest])
	largest=right;
	
	if(largest!=i){
		swap(&heap[i],&heap[largest]);
		maxHeap(heap,n,largest);
	}	
	}	
}

void insertRoot(int *heap,int *n){
	int num,i;
	printf("Enter An Element: "); scanf("%d",&num);
	if(*n==0){
		heap[*n]=num;
		*n+=1;
		printHeapTree(heap,*n);	
	}else{
	heap[*n]=num;
	*n+=1;
	}	
	
}

void deleteRoot(int *heap,int num,int *n){
	int i=0;
	
	while(num!=heap[i]){
		i++;
	}
	swap(&heap[i],&heap[*n-1]);
	
	*n-=1;
	for(i=*n/2-1;i>=0;i--){
		maxHeap(heap,*n,i);
	}
	printHeapTree(heap,*n);
}

printHeapTree(int *heap,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}

int main(){
	
	int opt=1,heap[MAX],n=0,i;
	
	
	while(opt!=0){
		printf("Add New Element 1\nHeapify The Array 2\nDelete An Element 3\nClose The Program 0\nWhich One: "); 
		scanf("%d",&opt);		
		if(opt==1){
			insertRoot(heap,&n);
		}else if(opt==2){
		for(i=n/2-1;i>=0;i--)
		maxHeap(heap,n,i);
		printHeapTree(heap,n);	
		}else if(opt==3){
			int num;
			printf("Enter The ELement To Deleted: "); scanf("%d",&num);
			deleteRoot(heap,num,&n);
		}else{
			opt=0;
		}
	}
	
	return 0;
}
