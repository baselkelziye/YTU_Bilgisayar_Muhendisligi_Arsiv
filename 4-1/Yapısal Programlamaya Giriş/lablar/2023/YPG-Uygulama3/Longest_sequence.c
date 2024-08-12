#include <stdio.h>
#include <stdlib.h>

void Brute(int *Arr,int len){
	int i,j;
	int currNumber;
	int currSeq=1;
	int Max=0;
	int Start;
	for(i=0;i<len;i++){
		j=0;
		currSeq=1;
		currNumber=Arr[i];
		while(j<len){
			if(Arr[j]-1==currNumber){
				currNumber+=1;
				currSeq+=1;
				j=0;
			}else{
				j++;
			}
		}
		if(Max<currSeq){
			Max=currSeq;
			Start=Arr[i];
			
		}
	}
	printf("Longest Sequence: ");
	j=0;
		currNumber=Start;
		
		while(j<len){
			if(Arr[j]-1==currNumber){
				printf("%d ",currNumber);
				currNumber+=1;
				currSeq+=1;
				j=0;
				
			}else{
				j++;
			}
		}
		printf("%d ",currNumber);
}


void sorted(int * Arr,int len){
	int i;
	int Max=0;
	int Start=0;
	int End;
	int currSeq=1;
	for(i=0;i<len-1;i++){
		if(Arr[i]+1==Arr[i+1]){
			currSeq++;
		}else{
			if(currSeq>Max){
				End=i;
				Max=currSeq;
				currSeq=1;
			}
		}
	}
	
	printf("Maximum Sequence is: ");
	for(i=0;i<Max;i++){
		printf("%d ",Arr[(End-Max)+i+1]);
	}
}

int main(){
	int Arr[7]={199, 198, 200, 1, 0, 2,3};
	//int Arr[6]={1,2,3,4,100,200};
	int len=7;
	//sorted(Arr,len);
	Brute(Arr,len);	
	
	return 0;
}
