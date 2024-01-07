#include <stdio.h>
#include <stdbool.h>
#define N 4
#define SUM 15

int arr[N] = {3, 5, 6, 7};

bool isSubsetSum(int *set, int n, int sum){
	
	if(sum == 0)
		return true;
	
	if(!n && sum != 0)
		return false;
		
	if(set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);
		
	return (isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]));

}	

int main(){
	
	if(isSubsetSum(arr, N, SUM))
		printf("Found A Subset");
	else
		printf("Not Found");
	
	return 0;
}
