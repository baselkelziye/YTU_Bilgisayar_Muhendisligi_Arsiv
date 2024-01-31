#include<stdio.h>

int findTheFourth(int array[]); // Finds the fourth element of the array

int main()
{
    int result,e1,e2,e3;
    int array[3];
    printf("Enter First Three Elements\n");
    scanf("%d%d%d",&e1,&e2,&e3);
    array[0]=e1;
    array[1]=e2;
    array[2]=e3;
    result=findTheFourth(array);
    if(result!=0)
        printf("Fourth Element of The Array is: %d\n",result);
    return 0;
}

int findTheFourth(int array[])
{   
    int fourth;
	double xA,xM;
    xM=1.0*array[2]/array[1];
    xA=1.0*array[2]-array[1];
    if(xM==1.0*array[1]/array[0])
    {
        printf("x=%f\n",xM);
        fourth=array[2]*xM;
    }
    else if(xA==1.0*array[1]-array[0])
    {
        printf("x=%f\n",xA);
        fourth=array[2]+xA;
    }
    else
    {
        printf("ARRAY FITS NEITHER OF THE RULES\n");
        fourth=0;
    }
    
    return fourth;
}
