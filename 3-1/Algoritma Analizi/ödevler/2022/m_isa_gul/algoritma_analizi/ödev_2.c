#include <stdio.h>
#include <stdlib.h>

#define MIN -10000

int max(int a, int b, int c){
	if(a>=b && a>= c){
		return a;
	}
	else if(b>=a && b>=c){
		return b;
	}
	return c;
}

int max_sum_with_mid(int* blocks, int left, int mid, int right, int *res)
{
	int left_sum = 0;
	int right_sum = 0;
	int i, left_start, left_end, right_start, right_end;
	int left_max = MIN;
	for ( i = mid; i >= left; i--) {
		left_sum += blocks[i];
		if (left_sum > left_max){
			left_max = left_sum;
			left_start = i;
			left_end = mid;
		}
	}

	int right_max = MIN;
	for ( i = mid; i <= right; i++) {
		right_sum += blocks[i];
		if (right_sum > right_max){
			right_max = right_sum;
			right_start = mid;
			right_end = i;
		}
	}
	int with_mid_sum = left_max + right_max - blocks[mid];
	if( with_mid_sum > left_max && with_mid_sum > right_max){
		if(with_mid_sum > res[0]){
			res[0] = with_mid_sum;
			res[1] = left_start;
			res[2] = right_end;
			return with_mid_sum;
		}
	}
	else if(left_max > with_mid_sum && left_max > right_max){
		if(left_max > res[0]){
			res[0] = left_max;
			res[1] = left_start;
			res[2] = left_end;
			return left_max;
		}
	}
	else{
		if(right_sum > res[0]){
			res[0] = right_max;
			res[1] = right_start;
			res[2] = right_end;
			return right_max;
		}		
	}
}

int max_sum(int* blocks, int left, int right, int *res){
	if (left > right){
		return MIN;
	}
	if (left == right){
		return blocks[left];
	}
	int mid = (left + right) / 2;
	return max(max_sum(blocks, left, mid - 1,res),
			max_sum(blocks, mid + 1, right,res),
			max_sum_with_mid(blocks, left, mid, right, res));
}

void brute_force(int* blocks, int n, int* res){
	int sub_sum, i, j;
	for(i=0;i<n;i++){
		sub_sum = 0;
		for(j=i;j<n;j++){
			sub_sum += blocks[j];
			if(sub_sum>res[0]){
				res[0] = sub_sum;
				res[1] = i;
				res[2]=j;
			}
		}
	}
}

int main(void){
	int opt=1;
	int opt2;
	while(opt==1){
		int i,n;
		printf("Blocks count: ");
		scanf("%d", &n);
		int* blocks;
		blocks = (int*)malloc(n*sizeof(int));
		if(blocks == NULL){
			printf("Fail!"),
			exit(0);
		}
		int res[3] = {-100,0,0};
		for(i=0;i<n;i++){
			printf("Block %d: ", i);
			scanf("%d", &blocks[i]);
		}
		printf("\n1-Divide and Conquer\n2-Brute Force\nWhich one? -> ");
		scanf("%d",&opt2);
		if(opt2==1){
			max_sum(blocks, 0, n - 1, res);
			printf("\nMax: %d\nStart: %d\nEnd: %d\n\n", res[0], res[1], res[2]);
		}
		else{
			brute_force(blocks, n, res);
			printf("\nMax: %d\nStart: %d\nEnd: %d\n\n", res[0], res[1], res[2]);
		}
		free(blocks);
		printf("\n1-Yes\n2-No\nAgain? -> ");
		scanf("%d", &opt);
	}
}

