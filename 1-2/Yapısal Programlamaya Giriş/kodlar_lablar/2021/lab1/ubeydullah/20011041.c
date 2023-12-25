#include <stdio.h>

#define MAX 10000
int main() {
	int nums[MAX];
	int i, n;
	int begin, middle, end;
	
	int keepit = 1;
	int thenum;
	
	printf("Enter length of array: ");
	scanf("%d", &n);
	
	if (n == 1) {
		printf("What? ._. \n");
		return 1;
	}
	for (i = 0; i < n; i++) {
		printf("Enter %d.th number: ", i + 1);
		scanf("%d", &nums[i]);
	}
	
	begin = 0;
	end = n - 1;
	middle = (end + begin) / 2;
	/*
	**************** FOR DEBUG PURPOSES **************
	printf("\n--\n");
	for (i = 0; i < n; i++) {
		printf("%d,", nums[i]);
	}
	printf("\n--\n");*/
	// !!
	while (end - begin > 1 && keepit == 1) {
		if (nums[middle] - nums[begin] != middle - begin) {
			end = middle;
			middle = (end + begin) / 2;
		} else if (nums[end] - nums[middle] != end - middle) {
			begin = middle;
			middle = (end + begin) / 2;
		} else {
			keepit = 0;
		}
		/*
		**************** FOR DEBUG PURPOSES **************
		printf("begin: %d, middle: %d, end: %d\n", begin, middle, end);
		*/
	}
	
	
	if (keepit == 0) {
		printf("Everything is okay! Nothing is missing. \n");
	} else {
		thenum = nums[begin] + 1;
		printf("The missing number is: %d\n", thenum);
	}
}
