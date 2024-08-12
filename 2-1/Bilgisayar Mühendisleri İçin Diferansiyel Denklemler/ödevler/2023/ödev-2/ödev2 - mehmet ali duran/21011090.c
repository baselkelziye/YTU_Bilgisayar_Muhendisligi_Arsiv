#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct equation{
	int N;
	float *coefficient;
	int *order;
	int *var;	
};

float calculate_new_iter(float h, float xi, float current_value, struct equation func, int i);
float calculate_derivative(float xi, float yi, struct equation func);
float calculate_k(float xi, float yi, struct equation func);


int main(){
	
	float x, initial_xi, initial_yi, current_value, k1, k2, k3, k4, h, error;
	int iter, i;
	float *coefficient, *real_values;
	int *order, *var;
	struct equation func;
	
	
	printf("please enter the term number N: ");
	scanf("%d",&func.N);
	
	coefficient = (float*)malloc(func.N*sizeof(float));
	func.coefficient = coefficient;
	
	order = (int*)malloc(func.N*sizeof(int));
	func.order = order;
	
	var = (int*)malloc(func.N*sizeof(int));
	func.var = var;
		
	
	for(i=0;i<func.N;i++){
		printf("Please enter %d.th terms if x or y (1 for x, 0 for y): ",i+1);
		do{
			scanf("%d",&func.var[i]);
			if(func.var[i] != 0 && func.var[i] != 1){
				printf("please enter a valid value");
			}
		}while(func.var[i]!=0 && func.var[i]!=1);
		
		printf("Please enter the %d.th terms coefficient: ",i+1);
		scanf("%f",&func.coefficient[i]);
		
		printf("Please enter the %d.th terms order: ",i+1);
		scanf("%d",&func.order[i]);
	}
	
	
	printf("please enter the initial xi: ");
	scanf("%f",&initial_xi);
	printf("please enter the initial yi: ");
	scanf("%f",&initial_yi);
	printf("please enter the target x: ");
	scanf("%f",&x);
	printf("please enter the h value: ");
	scanf("%f",&h);
	
		
	iter = (int)((x-initial_xi)/h+0.5);
	printf("\ncounted iter number is %d\n",iter);
	current_value = initial_yi;
	
	real_values = (float*)malloc(iter*sizeof(float));
	
	
	for(i=0;i<iter;i++){
		printf("please enter the %d.th iteration real value for y(%.3f): ",i+1 ,initial_xi+h*(i+1));
		scanf("%f",&real_values[i]);
	}
	
	printf("\n");
	
	for(i=0;i<iter;i++){
		
		current_value = calculate_new_iter(h, initial_xi, current_value, func, i);
		error = real_values[i]-current_value;
		if(error<0)error*=-1;
		printf("%d.th iteration result for y(%.3f) is %f\t\terror:%f\n\n",i+1 ,initial_xi+h*(i+1) ,current_value, error);
	}
	
	free(coefficient);
	free(order);
	free(var);
	free(real_values);
	
	return 0;
}

float calculate_derivative(float xi, float yi, struct equation func){
	float result=0;
	int i;
	
	for(i=0;i<func.N;i++){
		if(func.var[i] == 1){
			result += func.coefficient[i]*pow(xi, func.order[i]);
		}else{
			result += func.coefficient[i]*pow(yi, func.order[i]);
		}
	}
	
	//test function
	//result += xi + (yi/xi);
	
	return result;
}

float calculate_k(float xi, float yi, struct equation func){
	float result;
	result = calculate_derivative(xi, yi, func);
	return result;
}


float calculate_new_iter(float h, float xi, float current_value, struct equation func, int i){
	float result, k1, k2, k3, k4;
	xi = xi+h*i;
	
	k1 = calculate_k(xi, current_value, func);
	k2 = calculate_k(xi+(h/2.0), current_value+((k1*h)/2.0), func);
	k3 = calculate_k(xi+(h/2.0), current_value+((k2*h)/2.0), func);
	k4 = calculate_k(xi+h, current_value+(k3*h), func);
	
	printf("\nk1:%f\tk2:%f\tk3:%f\tk4:%f\n",k1, k2, k3, k4);
	
	result = current_value + (h/6.0)*(k1 + (2*k2) + (2*k3) + k4);
	
	return result;
}
