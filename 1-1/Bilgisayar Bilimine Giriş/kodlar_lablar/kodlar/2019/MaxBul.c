// this program gets the grades of n students and counts the average, and the max grade
#include <stdio.h>
int main()
{
	int i,n;
	float sum=0;
	float max=0;
	float student[50]; //you have to determine the limitations of your array
	do
	{
	printf("give the number of the students\n");	//you may check the size of the array
	scanf("%d",&n);
	}while (n>50);
	
	printf("give the grades of the students\n");
	for (i=0;i<n;i++)	
	{
		scanf("%f",&student[i]);
		sum+=student[i];
		if (max<student[i])	
			max=student[i];
	}
	printf("Average: %f  max grade:%f\n",sum/n,max);
	return 0;
}
