#include<stdio.h>
#include<math.h>
float calculate(float coefficients[10],float root,int degree);
int main(){
	int i;
	float first, last, mid, result1, result2, eps, error;
	int degree, iteration;
	float coefficients[10];
	printf("Enter the degree of the equation.");
	scanf("%d", &degree);
	for(i=degree; i>=0; i--){
		printf("Enter the coefficient of the %d-order element.",i);
		scanf("%f",&coefficients[i]);
	}
	
	
	do{
		printf("Enter the start and end of the range in order.(if the range is not suitable you will try again.)");
		scanf("%f %f",&first,&last);
	}
	while(calculate(coefficients,first,degree)*calculate(coefficients,last,degree)>0||calculate(coefficients,first,degree)*calculate(coefficients,last,degree)==0);
	printf("Enter number of iterations.");
	scanf("%d",&iteration);
	printf("Enter the eps value.");
	scanf("%d", &eps);
	mid=0.0;
	printf("a		b		f(a)		f(b)		error\n");
	
	i=0;
	do{
		result1=calculate(coefficients,first,degree);
		result2=calculate(coefficients,last,degree);
		error=result2-result1;
		printf("%f	%f	%f	%f	%f\n",first,last,result1,result2,error);
		mid=(first+last)/2;
		if(result1>0&&calculate(coefficients,mid,degree)>0||result1<0&&calculate(coefficients,mid,degree)<0){
			first=mid;
		}
		else{
			last=mid;
		}
		i++;
	}
	while(i<iteration||error<eps);
	return 0;
}

float calculate(float coefficients[10],float root,int degree){
	int i;
	float result=0;
	for(i=1; i<=degree; i++){
			result+=coefficients[i]*pow(root,i);
	}
	result+=coefficients[0];
	return result;
}

