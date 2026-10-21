#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
void function(int arr[]){
	int max,mid,min,temp,temp2;
	int i,j,k,run=1;
	
	max = arr[0];
	if(arr[1] >=- max){
		max = arr[1];
		mid = arr[0];
	}
	else{
		mid = arr[1];
	}
	if((arr[2] >= mid) && (arr[2] < max)){
		temp = mid;
		mid = arr[2];
		min = temp;
	}
	else if(arr[2] >= max){
		temp = max;
		temp2 = mid;
		max = arr[2];
		mid = temp;
		min = temp2;
	}
	else{
		min = arr[2];
	}
	i = 3;
	while(run){
		if(arr[i] > max){
			temp = max;
			temp2 = mid;
			max = arr[i];
			mid = temp;
			min = temp2;
		}
		else if((arr[i] <= max) && (arr[i] > mid)){
			temp = mid;
			mid = arr[i];
			min = temp;
		}
		else if((arr[i] <= mid) && (arr[i] > min)){
			min = arr[i];
		}
	
		i++;
		if(i == 10 ){
			run = 0;
		}
	}
	printf("1- %d\n2- %d\n3- %d",max,mid,min);
	
}
