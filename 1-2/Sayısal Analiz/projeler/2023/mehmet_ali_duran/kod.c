#include<stdio.h>
#define MAX 200
#define mMAX 20


typedef struct function{
	float coefficient[MAX];
	int exponent;
}func;

void MainMenu(void);
void Bisection(void);
void Regula_Falsi(void);
void Newton_Rapshon(void);
void Inverse_Matrix(void);
void Gauss_Elimination(void);
void Gauss_Seidel(void);
void Numerical_Differentiation(void);
void Simpson(void);
void Trapez(void);
void Gregory_Newton(void);
void get_matrix(int N, float matrix[][mMAX]);
void print_matrix(float matrix[][mMAX], int N);
func get_function(void);
void print_function(func function);
float calculate_function(func function, float x);
int delta_control(int N, float matrix[][mMAX]);
double power(double base, int exponent);
float my_abs(float num);
func derivativer(func function);
int factorial(int N);
void line_swap(int t, int i1, int N, float matrix[][mMAX]);
void matrix_copy(float matrix1[][mMAX], float matrix2[][mMAX], int N);


int main(){
	
	MainMenu();
	//Bisection();
	//Regula_Falsi();
	//Newton_Rapshon();
	//Inverse_Matrix();
	//Gauss_Elimination();
	//Gauss_Seidel();
	//Numerical_Differentiation();
	//Simpson();
	//Trapez();
	//Gregory_Newton();
	//get_matrix(int N, float matrix[][N]);
	//print_matrix(float matrix[][3], int N);
	//power(double base, int exponent);
	//get_function(void);
	//print_function(func function);
	//calculate_function(func function, float x);
	//delta_control(int N, float matrix[][3]);
	return 0;
}

void MainMenu(void){
	int choice;
	char pause;
	
	do{
		printf("\n************Menu************\n\n");
		printf("0-Quit\n");
		printf("1-Bisection Method\n");
		printf("2-Regula-Falsi Method\n");
		printf("3-Newton-Rapshon Method\n");
		printf("4-Inverse Matrix\n");
		printf("5-Gauss Elimination\n");
		printf("6-Gauss-Seidal\n");
		printf("7-Numerical Differentiation\n");
		printf("8-Simpson Method\n");
		printf("9-Trapez Method\n");
		printf("10-Gregory Newton Interpolation\n");
		printf("\npress 0 to exit or operation number to select operation: ");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:
				
				Bisection();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
			
			case 2:
				
				Regula_Falsi();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 3:
				
				Newton_Rapshon();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
			
			case 4:
				
				Inverse_Matrix();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 5:
				
				Gauss_Elimination();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 6:
				
				Gauss_Seidel();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 7:
				
				Numerical_Differentiation();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 8:
				
				Simpson();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 9:
				
				Trapez();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
				
			case 10:
				
				Gregory_Newton();
				printf("\n\n\nPlease press any key to continue: ");
				pause = getch();
				system("cls");
				break;
			
		}
				
	}while(choice != 0);
}

void Bisection(void){
	
	func function;
	int i, iter=0;
	float a, b, result_minor, result_major, root_verify, error_sensitivity, mid_point, mid_result;
	
	function = get_function();
	
	printf("please enter the root interval numbers a and b\na: ");
	scanf("%f",&a);
	printf("b: ");
	scanf("%f",&b);
	printf("please enter the error sensitivity which stop condition: ");
	scanf("%f",&error_sensitivity);
	printf("b: ");
	print_function(function);
	
	result_minor = calculate_function(function, a);
	result_major = calculate_function(function, b);
	root_verify = result_minor * result_major;
	
	if(root_verify>0){
		printf("no root between these two values or too many roots");
		
	}else if(root_verify==0){
		
		if(result_minor == 0){
			printf("%f is one of roots of function",a);
		}
		
		if(result_major == 0){
			printf("%f is one of roots of function",b);
		}
		
		
	}else{
		
		printf("there is at least one root between a and b\n");
		
		while(error_sensitivity<(my_abs(b-a)/power(2,iter))){
			
			mid_point = (a+b)/2;
			mid_result = calculate_function(function, mid_point);
			
			if(result_minor<0 && mid_result>0){
				b = mid_point;
				
			}else if(result_minor<0 && mid_result<0)
				a = mid_point;
				
			iter++;
		}
		
		printf("about root is %f",mid_point);
		
	}
	
}

void Regula_Falsi(void){
	
	func function;
	int i, iter=1;
	float a, b, result_minor, result_major, root_verify, error_sensitivity, triangle_center, triangle_result;
	
	function = get_function();
	
	printf("please enter the root interval numbers a and b\na: ");
	scanf("%f",&a);
	printf("b: ");
	scanf("%f",&b);
	printf("please enter the error sensitivity which stop condition: ");
	scanf("%f",&error_sensitivity);
	print_function(function);
	
	result_minor = calculate_function(function, a);
	result_major = calculate_function(function, b);
	root_verify = result_minor * result_major;
	
	if(root_verify>0){
		printf("no root between these two values or too many roots");
		
	}else if(root_verify==0){
		
		if(result_minor == 0){
			printf("%f is one of roots of function",a);
		}
		
		if(result_major == 0){
			printf("%f is one of roots of function",b);
		}
		
		
	}else{
		
		printf("there is at least one root between a and b\n");
		
		while(error_sensitivity<(my_abs(b-a)/power(2,iter))){
			
			triangle_center = ((b*result_minor)-(a*result_major))/(result_minor-result_major);
			triangle_result = calculate_function(function, triangle_center);
			
			if(result_minor<0 && triangle_result>0){
				b = triangle_center;
				
			}else if(result_minor<0 && triangle_result<0)
				a = triangle_center;
				
			iter++;
		}
		
		printf("about root is %f",triangle_center);	
	}
}

void Newton_Rapshon(void){
	
	int i;
	float a, b, new_iter, error_sensitivity;
	func function;
	func derivative_function;
	function = get_function();
	derivative_function = derivativer(function);
	
	printf("enter the a and b range, a: ");
	scanf("%f",&a);
	printf("b: ");
	scanf("%f",&b);
	
	printf("enter the error sensitivity: ");
	scanf("%f",&error_sensitivity);
	
	print_function(function);
	
	if(calculate_function(derivative_function, a)!=0){
		
		new_iter = a - (calculate_function(function, a)/calculate_function(derivative_function, a));
	
		while(error_sensitivity<(my_abs(new_iter-a))){
			a = new_iter;
			new_iter = a - (calculate_function(function, a)/calculate_function(derivative_function, a));
		}
		
		printf("%f is root",new_iter);
	}else{
		printf("DIVISION 0 Error");
	}
	
	
	
}

void Inverse_Matrix(void){
	
	float matrix[mMAX][mMAX];
	int N, all_zero = 0, i, j, k, zero_counter = 0;
	float identity_matrix[mMAX][mMAX], determinant, temp, spare, a, b;
	
	printf("Please enter the N that dimension of matrix: ");
	scanf("%d",&N);
	printf("Please enter the elements of NxN matrix\n");
	get_matrix(N,matrix);
	
	if(N == 1){
		if(matrix[0][0]!=0){
			printf("Inverse of matrix: 1/%f",matrix[0][0]);
		}else{
			printf("There isn't inverse of matrix because determinant is equal to zero");
		}
		
	}else if(N == 2){
		
		temp = matrix[0][0];
		matrix[0][0] = matrix[1][1];
		matrix[1][1] = temp;
		matrix[0][1] *= -1;
		matrix[1][0] *= -1;
		
		determinant = (matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]);
		if(determinant == 0){
			printf("There isn't inverse of matrix because determinant is equal to zero");
		}else{
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					matrix[i][j] = (matrix[i][j])*(1/determinant);
				}
			}
			print_matrix(matrix, N);
		}
	}else{
		
		//forming identity matrix
		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {
				if(i==j) {
					identity_matrix[i][j] = 1;
				}else{
					identity_matrix[i][j] = 0;
				}
			}
		}
		
		k=0;
		
		all_zero = delta_control(N, matrix);
		if(all_zero){
				printf("\nThe matrix you entered has no inverse because there is a row or column of all zeros\n");
			}
		while((k!=N) && (all_zero != 1)){
						
			if(all_zero){
				printf("\nThe matrix you entered has no inverse because there is a row or column of all zeros\n");
			}else{
				spare = matrix[k][k];
				
				for(j=0;j<N;j++){
					identity_matrix[k][j] = identity_matrix[k][j] / spare;
					matrix[k][j] = (matrix[k][j] / spare);
				}
				
				for(i=0;i<N;i++){
					temp = matrix[i][k];
					if(k!=i){
						
						for(j=0;j<N;j++){
							identity_matrix[i][j] = identity_matrix[i][j] - (identity_matrix[k][j]*temp);
						}
						
						for(j=0;j<N;j++){
							matrix[i][j] = matrix[i][j] - (matrix[k][j]*temp);
						}
					}				
				}
			}
			
			all_zero = delta_control(N, matrix);
			k++;
		}
		if(all_zero != 1){
			
			printf("\nInverse of matrix: \n\n");
			print_matrix(identity_matrix,N);
			
		}
		
		if(all_zero){
				printf("\nThe matrix you entered has no inverse because there is a row or column of all zeros\n");
			}
			
	}
}

void Gauss_Elimination(void){
	
	char letter[mMAX] = {'x','y','z','t','v','c','m','n','k','a','b','c','d','e','f','g','h','j','i','l'};
	int i, j, k, N;
	float matrix[mMAX][mMAX],x[mMAX];
	float temp, spare, sum;
	
	printf("---Reminding----\nThis method only solves equations with the same number of equations and unknowns\n");
	printf("Enter the equation quantity: ");
	scanf("%d",&N);
	
	printf("\nenter your equations\n");
	for(i=0;i<N;i++){
		for(j=0;j<N+1;j++){
			if(j!=N){
				printf("coefficient of the %c for %dst equation: ",letter[j],i+1);
				scanf("%f",&matrix[i][j]);
			}else{
				printf("equal to ?: ");
				scanf("%f",&matrix[i][j]);
			}
		}
	}
	
	for(k=0;k<N;k++){
		
		temp = matrix[k][k];
		for(j=k;j<N+1;j++){
			matrix[k][j] = matrix[k][j] / temp;
		}
		
		for(i=k+1;i<N;i++){
			spare = matrix[i][k];
			for(j=0;j<N+1;j++){
				matrix[i][j] /= spare;
			}
			for(j=0;j<N+1;j++){
				matrix[i][j] = matrix[i][j] - matrix[k][j];
			}
			for(j=0;j<N+1;j++){
				matrix[i][j] *= spare;
			}
		}
	}
	
	
    for (i = N - 1; i >= 0; i--) {
        x[i] = matrix[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] = x[i] - matrix[i][j] * x[j];
        }
        x[i] = x[i] / matrix[i][i];
    }

	printf("\nResult:\n");
	for(i=0;i<N;i++){
		printf("%c = %f\n",letter[i],x[i]);
	}
	
}

void Gauss_Seidel(void){
	
	char letter[mMAX] = {'x','y','z','t','v','c','m','n','k','a','b','c','d','e','f','g','h','j','i','l'};
	int i, j, N, t, flag=0, k;
	float matrix[mMAX][mMAX],x[mMAX],x_diff[mMAX],x_init[mMAX],backup_matrix[mMAX][mMAX];
	float max_value=0, err_sens, sum=0;
	

		
	printf("---Reminding----\nThis method only solves equations with the same number of equations and unknowns\n");
	printf("Enter the equation quantity: ");
	scanf("%d",&N);
	
	printf("\nenter your equations\n");
	for(i=0;i<N;i++){
		for(j=0;j<N+1;j++){
			if(j!=N){
				printf("coefficient of the %c for %dst equation: ",letter[j],i+1);
				scanf("%f",&matrix[i][j]);
			}else{
				printf("equal to ?: ");
				scanf("%f",&matrix[i][j]);
			}
		}
	}
	
	for(i=0;i<N;i++){
		printf("enter the initial value of %c: ",letter[i]);
		scanf("%f",&x_init[i]);
	}
	
	printf("enter the error sensitivity: ");
	scanf("%f",&err_sens);
	
	matrix_copy(backup_matrix, matrix, N);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			backup_matrix[i][j] = my_abs(backup_matrix[i][j]);
		}
	}
	
	
	for(i=0;i<N;i++){
		max_value=0;
		for(j=0;j<N;j++){
			//sorting
			if(backup_matrix[j][i] > max_value){
				max_value = backup_matrix[j][i];
				t = j;
			}
		}
		line_swap(t, i, N, matrix);
		line_swap(t, i, N, backup_matrix);
	}
	
	while(flag<N){
		
		flag=0;
		for(i=0;i<N;i++){
			sum=0;
			for(j=0;j<N;j++){
				if(i!=j){
					sum += x_init[j]*matrix[i][j];
				}		
			}
			
			x[i] = matrix[i][N]-sum;
			x[i] = x[i] / matrix[i][i];
			
			for(k=0;k<N;k++){
				x_diff[k] = my_abs(x[k] - x_init[k]);
			}
			
			x_init[i] = x[i];
		}
		
		for(i=0;i<N;i++){
			if(x_diff[i]<err_sens)
				flag++;
		}
	}
	
	
	for(i=0;i<N;i++){
		printf("result value of %c is %f: ",letter[i],x[i]);
	}
}

void Numerical_Differentiation(void){
	
	func function;
	function = get_function();	
	float forward_derivative, backward_derivative, central_derivative, h, x;
	
	printf("enter the x value you want to calculate: ");
	scanf("%f",&x);
	
	printf("enter the h that difference value: ");
	
	do{
		scanf("%f",&h);
		if(h<=0){
			printf("h should be greater than 0 and not equal to 0");
		}
	}while(h<=0);
	
	print_function(function);
	
	forward_derivative = (1/(2*h))*((-3*calculate_function(function,x))+(4*calculate_function(function,x+h))+(-1*calculate_function(function,x+2*h)));
	
	backward_derivative = (1/(2*h))*((3*calculate_function(function,x))+(-4*calculate_function(function,x-h))+(1*calculate_function(function,x-2*h)));
	
	printf("forward_derivative: %f\n",forward_derivative);
	printf("backward_derivative: %f",backward_derivative);
	
}

void Simpson(void){
	
	func function;
	printf("enter the function whose area you want to calculate\n");
	function = get_function();	
	float h, a, b, result=0;
	int n, i;
	
	printf("enter lower and upper limits, lower: ");
	scanf("%f",&a);
	
	printf("upper: ");
	scanf("%f",&b);
	
	printf("enter how many parts you want to divide(it should be even): ");
	
	do{
		scanf("%d",&n);
		if(n%2 == 1)
			printf("please enter again value that valid");	
	}while(n%2 == 1);
	
	h = (b-a)/n;
	
	
	for(i=0;i<n+1;i++){
		
		if((i==0) || (i==n)){
			result += calculate_function(function,a+(h*i));
		}else if(i%2 == 1){
			result += 4*calculate_function(function,a+(h*i));
		}else if(i%2 == 0){
			result += 2*calculate_function(function,a+(h*i));
		}
	}	
	result *= (h/3);
	
	printf("size of the field is %f br^2",result);
	
	
}

void Trapez(void){
	
	func function;
	printf("enter the function whose area you want to calculate\n");
	function = get_function();	
	float h, a, b, result=0;
	int n, i;
	
	printf("enter lower and upper limits, lower: ");
	scanf("%f",&a);
	
	printf("upper: ");
	scanf("%f",&b);
	
	printf("enter how many parts you want to divide: ");
	scanf("%d",&n);
	
	h = (b-a)/n;
		
	result += calculate_function(function,a+(h*0))/2;
	result += calculate_function(function,a+(h*n))/2;
		
	for(i=1;i<n;i++){
		
		result += calculate_function(function,a+(h*i));
	}
	
	result *= h;
	
	printf("size of the field is %f br^2",result);
	
}

void Gregory_Newton(void){
	
	int N, i, j, h;
	int points[mMAX][mMAX];
	float sum = 0, a, carpan = 1, p;
	
	printf("how many dots will you enter: ");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		for(j=0;j<2;j++){
			if(j == 0){
				printf("x of %d. point: ",i+1);
			}else{
				printf("y of %d. point: ",i+1);
			}
			scanf("%d",&points[i][j]); 
		}
	}
	
	printf("which point do you want to find the estimated value of: ");
	scanf("%f",&a);
	
	printf("\nDot pairs:\n");
	for(i=0;i<N;i++){
		printf("(%d,%d)",points[i][0],points[i][1]);
		printf("\n");
	}
	
	h = points[1][0] - points[0][0];
	
	for(i=1;i<4;i++){
		for(j=0;j<N-i;j++){
			points[j][i+1] = points[j+1][i] - points[j][i];
		}
	}
	
	printf("\n The forward difference table is:\n");
    for (i = 0; i < N; i++) {
        printf("\n");
        for (j = 0; j < N - i -1; j++) {
            printf("%d\t", points[i][j]);
        }
    }
    
    sum = points[0][1];
    
    for (j = 1; j < N; j++) {
    	carpan *= a-points[j-1][0];
        p = (points[0][j+1])/((power(h, j))*(factorial(j)));
        sum += carpan*p;
    }
    
    printf("value of %f is %f",a,sum);
}




void get_matrix(int N, float matrix[][mMAX]){
	
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("matrix[%d][%d]: ",i,j);
			scanf("%f",&matrix[i][j]);
		}
	}
}

void print_matrix(float matrix[][mMAX], int N){
	
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}	
}

func get_function(void){
	
	int i;
	char c = 'a';
	func function;
	
	printf("what is the exponent of the function: ");
	do{
		scanf("%d",&function.exponent);
		if(function.exponent<0)
			printf("please enter positive number: ");
	}while(function.exponent<0);
	
	
	printf("enter the coefficients of function from lowest exponent to highest exponent \n");
	for(i=0;i<function.exponent+1;i++){
		printf("%cX^%d, %c= :",c+i ,i ,c+i);
		scanf("%f",&function.coefficient[i]);
	}
	return function;
}

void print_function(func function){
	int i;
	printf("Your function is :\n\n");
	for(i=0;i<function.exponent+1;i++){
		printf("%fX^%d",function.coefficient[i],i);
		if(i!=function.exponent)
			printf(" + ");
	}
	printf("\n\n");
}

float calculate_function(func function, float x){
	
	float result=0;
	int i;
	for(i=0;i<function.exponent+1;i++){
		result += function.coefficient[i]*power(x, i);
	}
	
	return result;
}

int delta_control(int N, float matrix[][mMAX]){
	
	int i, j, zero_counter;
 	int all_zero_row = 0, all_zero_column = 0, all_zero = 0;
 	
 	for(i=0;i<N;i++){
		zero_counter = 0;
		for(j=0;j<N;j++){
			if(matrix[i][j] == 0){
				zero_counter++;
			}
		}
		if(zero_counter == N)
			all_zero_row = 1;
	}
	
	for(i=0;i<N;i++){
		zero_counter = 0;
		for(j=0;j<N;j++){
			if(matrix[j][i] == 0){
				zero_counter++;
			}
		}
		if(zero_counter == N)
			all_zero_column = 1;
	}
	
	if ((all_zero_row == 1) || (all_zero_column == 1))
		all_zero = 1;
		
	return all_zero;
}

double power(double base, int exponent) {
	
    double result = 1.0;
    
    while (exponent != 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

float my_abs(float num){
    if (num < 0) {
        num = -num;
    }
    return num;
}

func derivativer(func function){
	
	int i;
	
	for(i=1;i<function.exponent+1;i++){
		function.coefficient[i-1] = function.coefficient[i]*i;
	}
	function.exponent-=1;
	
	return function;
}

int factorial(int N){
	
	int i,result=1;
	
	for(i=2; i<=N ; i++)     
		result = result * i; 
		
	return result;

}

void line_swap(int t, int i1, int N, float matrix[][mMAX]){
	
	int i;
	float temp;
	
	for(i=0;i<N+1;i++){
		temp = matrix[i1][i];
		matrix[i1][i] = matrix[t][i];
		matrix[t][i] = temp;
		
	}	
}

void matrix_copy(float matrix1[][mMAX], float matrix2[][mMAX], int N){
	
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix1[i][j] = matrix2[i][j];
		}
	}
}



