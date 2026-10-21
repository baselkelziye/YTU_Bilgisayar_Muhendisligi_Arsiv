#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXEXPRLEN 100

typedef struct{
    char expr[MAXEXPRLEN];
    int pos;
}FUNCTION;

typedef struct{
    int error;
    double value;
}EVALUATERESULT;

void FindMethod();							

//Function Calculations:
int isspacechar(char c);											
int isalphachar(char c);										
int isdigitchar(char c);										
void enterfunction(FUNCTION* p);										
FUNCTION createparser(char* expr);										
void skipspaces(FUNCTION* p);										
char peek(FUNCTION* p);										
char next(FUNCTION* p);
EVALUATERESULT evaluateexpression(FUNCTION* p, double x);						
EVALUATERESULT evaluateterm(FUNCTION* p, double x);						
EVALUATERESULT evaluatefactor(FUNCTION* p, double x);						
EVALUATERESULT evaluatepower(FUNCTION* p, double x);						
EVALUATERESULT evaluateatom(FUNCTION* p, double x);						
EVALUATERESULT evaluatefunction(FUNCTION* p,double x,char* func);						
EVALUATERESULT evaluatelogarithm(FUNCTION* p, double x);						
EVALUATERESULT evaluatenumber(FUNCTION* p);						

//Methods 1-10:
void BisectionMethod();								
void RegulaFalsiMethod ();							
void NewtonRaphsonMethod();							
void MatrixInverse();								
void FindingInverse(double**, int);					
void Cholesky ();  									
void GaussSeidal();										
double** Allocate(int ,int);						
double calculateDet(double**, int);					
double** MakingSubmatrix(double**,int,int,int);		
void FreeMatrix (double**, int);					
void NumericalDifferentiation();					
void SimpsonRules();								
void TrapezMethod();								
void GregoryNewton();								

int main (){
	FindMethod();
	return 0;
}

void FindMethod(){
	int m=1;
	char c;
	while(m!=0){
		printf("----- Numerical Analysis Methods -----\n\n");
		printf("0.  Quit \n");
		printf("1.  Bisection Method\n");
		printf("2.  Regula-Falsi Method \n");
		printf("3.  Newton-Raphson Method\n");
		printf("4.  Inverse of NxN Matrix\n");
		printf("5.  Cholesky (ALU) Method\n");
		printf("6.  Gauss Seidal Method\n");
		printf("7.  Numerical Differentiation\n");
		printf("8.  Simpson's Rules (1/3 ve 3/8)\n");
		printf("9.  Trapez Method\n");
		printf("10. Gregory Newton Interpolation (without the change of variable)\n\n");
		printf("Choose one of the above methods (write its number): ");
		scanf("%d", &m);
		printf("\n");
		
		if(m==1){
			printf("--- Bisection Method: ---\n\n");
			BisectionMethod();
		}
		else if(m==2){
			printf("--- Regula-Falsi Method: ---\n\n");
			RegulaFalsiMethod();
		}
		else if(m==3){
			printf("--- Newton-Raphson Method: ---\n\n");
			NewtonRaphsonMethod();
		}
		else if(m==4){
			printf("--- Inverse of NxN Matrix: ---\n\n");
			MatrixInverse();
		}
		else if(m==5){
			printf("--- Cholesky (ALU) Method: ---\n\n");
			Cholesky();
		}
		else if(m==6){
			printf("--- Gauss Seidal Method: ---\n\n");
			GaussSeidal();
		}
		else if(m==7){
			printf("--- Numerical Differentiation: ---\n\n");
			NumericalDifferentiation();
		}
		else if(m==8){
			printf("--- Simpson's Rules (1/3 ve 3/8): ---\n\n");
			SimpsonRules();
		}
		else if(m==9){
			printf("--- Trapez Method: ---\n\n");
			TrapezMethod();						
		}
		else if(m==10){
			printf("--- Gregory Newton Interpolation: ---\n\n");
			GregoryNewton();
		} else if (m<0 || m>10){
			printf("Wrong Choice");
		}
		
		if(m!=0){
			printf("\n\nDo you want to check a new method? (Y or y for yes): ");
			scanf(" %c",&c);
			if(c=='Y' || c=='y') FindMethod();
			else m=0;
		}
	}
}

int isspacechar(char c){
    if (c==' '){
    	return 1;
	}
	else{
		return 0;
	}
}

int isalphachar(char c){
    if ((c>='a' && c<='z') || (c>='A' && c<='Z')){
    	return 1;
	}
	else{
		return 0;
	}
}

int isdigitchar(char c){
    if (c>='0' && c<='9'){
    	return 1;
	}
	else{
		return 0;
	}
}

void enterfunction(FUNCTION* p){
	char func[MAXEXPRLEN];
	int len;
	char ch;
	scanf("%c",&ch);
	printf("Enter function: f(x) = ");
	scanf("%[^\n]", func);

	len=strlen(func);
	if(len>0 && func[len-1]=='\n')
		func[len-1]='\0';

	*p=createparser(func);
}

FUNCTION createparser(char* expr){
    FUNCTION p;
    strcpy(p.expr, expr);
    p.pos = 0;
    return p;
}

void skipspaces(FUNCTION* p) {
    while (peek(p) && isspacechar(peek(p))) next(p);
}

char peek(FUNCTION* p) {
    return p->expr[p->pos];
}

char next(FUNCTION* p) {
    char c = peek(p);
    if (c) p->pos++;
    return c;
}

EVALUATERESULT evaluateexpression(FUNCTION* p,double x){
    EVALUATERESULT right, left;
    char op;
    
	skipspaces(p);
    left = evaluateterm(p, x);
    if (left.error) return left;

    skipspaces(p);
    op = peek(p);
    while (op == '+' || op == '-'){
		next(p);
		right=evaluateterm(p, x);
		if (right.error) return right;
		if (op == '+') left.value += right.value;
		else left.value -= right.value;
		skipspaces(p);
        op=peek(p);
    }
    return left;
}

EVALUATERESULT evaluateterm(FUNCTION* p,double x){
    EVALUATERESULT left, right;
    char op;
	skipspaces(p);
    left=evaluatefactor(p, x);
    if (left.error) return left;

    skipspaces(p);
    op=peek(p);
    while (op == '*' || op == '/') {
        next(p);
        right = evaluatefactor(p, x);
        if (right.error) return right;
        if (op == '*') left.value *= right.value;
        else {
            if (right.value == 0.0) {
                left.error = 1;
                return left;
            }
            left.value /= right.value;
        }
        skipspaces(p);
        op=peek(p);
    }
    return left;
}

EVALUATERESULT evaluatefactor(FUNCTION* p,double x){
    EVALUATERESULT left, right;
    
	skipspaces(p);
    left = evaluatepower(p, x);
    if (left.error) return left;

    skipspaces(p);
    if (peek(p) == '^') {
        next(p);
        right = evaluatefactor(p, x);
        if (right.error) return right;
        if (left.value < 0 && fmod(right.value, 1.0) != 0.0){
            left.error = 1;
            return left;
        }
        left.value = pow(left.value, right.value);
    }
    return left;
}

EVALUATERESULT evaluatepower(FUNCTION* p,double x){
	EVALUATERESULT res;
	skipspaces(p);
	
	if (peek(p) == '+') {
		next(p);
		return evaluatepower(p, x);
	}
	if (peek(p) == '-') {
		next(p);
		res = evaluatepower(p, x);
		if (res.error) return res;
		res.value = -res.value;
		return res;
	}
	return evaluateatom(p, x);
}

EVALUATERESULT evaluateatom(FUNCTION* p,double x){
	EVALUATERESULT result;
	char name[8] = {0};
	int i=0, j;
	char c;

	skipspaces(p);
	c = peek(p);

	if (c == '(') {
		next(p);
		result = evaluateexpression(p,x);
		if (result.error) return result;
		skipspaces(p);
		if (peek(p) != ')'){
			result.error=1;
			return result;
		}
		next(p);
		return result;
	}

	if (isalphachar(c)) {
		while (isalphachar(peek(p)) && i<7){
			name[i++] = next(p);
		}
		name[i]='\0';
		skipspaces(p);

		if (strcmp(name,"sin")==0||strcmp(name,"cos")==0||strcmp(name,"tan")==0||strcmp(name,"arcsin")==0||strcmp(name,"arccos")==0|| strcmp(name,"arctan")==0){
			return evaluatefunction(p,x,name);
		}

		if (strcmp(name,"log")==0){
			return evaluatelogarithm(p,x);
		}

		if (strcmp(name,"e")==0){
			result.error = 0;
			if (peek(p)=='^'){
				next(p);
				skipspaces(p);
				if (peek(p)!='('){
					result.error=1;
					return result;
				}
				next(p);
				result=evaluateexpression(p,x);
				if (result.error) return result;
				skipspaces(p);
				if (peek(p)!=')'){
					result.error=1;
					return result;
				}
				next(p);
				result.value=exp(result.value);
				return result;
			}
			result.value=exp(1.0);
			return result;
		}

		if (strcmp(name,"x")==0) {
			result.error=0;
			result.value=x;
			return result;
		}

		result.error = 1;
		return result;
	}

	return evaluatenumber(p);
}

EVALUATERESULT evaluatefunction(FUNCTION* p,double x,char* func)
{
	EVALUATERESULT result;
	EVALUATERESULT arg;
	result.error=0;
	result.value=0.0;

	skipspaces(p);
	if (peek(p) != '(') {
		result.error = 1;
		return result;
	}
	next(p);

	arg=evaluateexpression(p, x);
	if (arg.error) {
		return arg;
	}

	skipspaces(p);
	if (peek(p) != ')') {
		result.error = 1;
		return result;
	}
	next(p);

	result.error = 0;
	if (strcmp(func,"sin")==0){
		result.value=sin(arg.value);
	}
	else if (strcmp(func,"cos")==0){
		result.value=cos(arg.value);
	}
	else if (strcmp(func,"tan")==0){
		result.value=tan(arg.value);
	}
	else if (strcmp(func,"arcsin")==0){
		if (arg.value<-1.0 || arg.value>1.0){
			result.error=1;
			return result;
		}
		result.value=asin(arg.value);
	}
	else if (strcmp(func,"arccos")==0){
		if (arg.value<-1.0 || arg.value>1.0){
			result.error=1;
			return result;
		}
		result.value=acos(arg.value);
	}
	else if (strcmp(func,"arctan")==0){
		result.value=atan(arg.value);
	}
	else {
		result.error=1;
	}

	return result;
}

EVALUATERESULT evaluatelogarithm(FUNCTION* p,double x)
{
	EVALUATERESULT base,arg;
	skipspaces(p);
	
	if (peek(p)=='_') {
		next(p);
		base=evaluateexpression(p,x);
		if (base.error) return base;
		if (base.value <= 0.0 || base.value == 1.0){
			base.error=1;
			return base;
		}
		skipspaces(p);
	} else{
		base.error=0;
		base.value=M_E;
	}
	if (peek(p)!='('){
		base.error=1;
		return base;
	}
	next(p);
	arg=evaluateexpression(p,x);
	if (arg.error) return arg;
	skipspaces(p);
	if (peek(p)!=')'){
		arg.error=1;
		return arg;
	}
	next(p);
	if (arg.value <= 0.0){
		arg.error=1;
		return arg;
	}
	arg.value=log(arg.value)/log(base.value);
	return arg;
}

EVALUATERESULT evaluatenumber(FUNCTION* p) {
    int j;
    skipspaces(p);
    char numstr[64] = {0};
    int i=0;
    int decimalfound=0;
    char c;
    EVALUATERESULT result;
    c=peek(p);

    while ((isdigitchar(c) || (!decimalfound && c == '.')) && i < 63) {
        if (c == '.') decimalfound = 1;
        numstr[i++] = next(p);
        c = peek(p);
    }

    if (i==0) {
    	result.error=1;
    	result.value=0;
    	return result;
	}

    double value = 0.0, fraction = 1.0;
    int founddecimal = 0;
    for (j=0;j<i;j++) {
        if (numstr[j]=='.') {
            founddecimal=1;
        } else if (!founddecimal) {
            value=value*10.0+(numstr[j] - '0');
        } else {
            fraction*=0.1;
            value+=(numstr[j]-'0')*fraction;
        }
    }
    
    result.error=0;
    result.value=value;
    return result;
}

//Method 1:
void BisectionMethod(){
	int k, maxiterations;
	FUNCTION p;
    EVALUATERESULT ra, rb, rm;
    double a, b, m, epsilon, variation;
    
    enterfunction(&p);
    printf("Enter a: ");
    scanf("%lf",&a);
    printf("Enter b: ");
    scanf("%lf",&b);
    printf("Enter epsilon: ");
    scanf("%lf", &epsilon);
    printf("Enter max interation number: ");
    scanf("%d", &maxiterations);
    
    ra = evaluateexpression(&p, a);
    if (ra.error) {printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    p.pos=0;
    	
	rb = evaluateexpression(&p, b);
    if (rb.error) { printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    p.pos=0;
    if(ra.value*rb.value<0){
    	k=1;
    	variation=b-a;
    	while(k<=maxiterations && variation>epsilon){
    		m=(a+b)/2;
    		rm = evaluateexpression(&p, m);
    		if (rm.error) {printf("Error evaluating function at x (pos %d)\n", p.pos);  return;}
    		p.pos=0;
			printf("Iteration: %d \n",k);
			printf("f(%lf) = %lf \n",a,ra.value);
			printf("f(%lf) = %lf\n",m,rm.value);
			printf("f(%lf) = %lf \n",b,rb.value);
			if(ra.value*rm.value<0){
    			variation=m-a;
    			b=m;
    			rb.value=rm.value;
			}
			else {
				variation=b-m;
				a=m;
				ra.value=rm.value;
			}
			printf("|x| = %lf \n\n",variation);
			k++;
		}
		if(k>maxiterations) printf("Maximum iteration has reached \n");
		printf("Root x = %lf",m);
	} else{
		printf("No root in this range [f(a)*f(b)>0]");
	}
}

//Method 2:
void RegulaFalsiMethod (){
	int k, flag=0, maxiterations;
	FUNCTION p;
    EVALUATERESULT ra, rb, rm;
    double a, b, m, epsilon, variation;
    
    enterfunction(&p);
    printf("Enter a: ");
    scanf("%lf",&a);
    printf("Enter b: ");
    scanf("%lf",&b);
    printf("Enter epsilon: ");
    scanf("%lf", &epsilon);
    printf("Enter max iteration number: ");
    scanf("%d", &maxiterations);
    
    ra = evaluateexpression(&p, a);
    if (ra.error) {printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    p.pos=0;
    	
	rb = evaluateexpression(&p, b);
    if (rb.error) { printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    p.pos=0;
    if(ra.value*rb.value<0){
    	k=1;
    	variation=b-a;
    	while(k<=maxiterations && variation>=epsilon && flag==0){
    		m=((b*ra.value)-(a*rb.value))/(ra.value-rb.value);
    		rm = evaluateexpression(&p, m);
    		if (rm.error) { printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    		p.pos=0;
			printf("Iteration: %d \n",k);
			printf("f(%lf) = %lf \n",a,ra.value);
			printf("f(%lf) = %lf\n",m,rm.value);
			printf("f(%lf) = %lf \n",b,rb.value);
			if(rm.value==0){
				flag++;
			}
			else if(ra.value*rm.value<0){
    			variation=m-a;
    			b=m;
    			rb.value=rm.value;
			}
			else {
				variation=b-m;
				a=m;
				ra.value=rm.value;
			}
			printf("|x| = %lf \n\n",variation);
			k++;
		}
		if(k>maxiterations) printf("Maximum iteration has reached \n");
		printf("Root x = %lf",m);
	} else{
		printf("No root in this range [f(a)*f(b)>0]");
	}
}

//Method 3:
void NewtonRaphsonMethod(){
	int k, flag=0, maxiterations;
	FUNCTION p;
    EVALUATERESULT ra, rm, rh1, rh2;
    double a, b, m, epsilon, variation,h=0.1,derivative,previousm;
    
    enterfunction(&p);
    printf("Enter a (starting point) : ");
    scanf("%lf",&previousm); a=previousm;
    printf("(b is used to check for any divergence)\nEnter b: ");
    scanf("%lf",&b);
    printf("Enter epsilon: ");
    scanf("%lf", &epsilon);
    printf("Enter max iteration number: ");
    scanf("%d", &maxiterations);
    
    ra =evaluateexpression(&p, a);
    if (ra.error) { printf("Error evaluating function at x (pos %d)\n", p.pos); return;}
    p.pos=0;
    
	rh1=evaluateexpression(&p, a+h);
    p.pos=0;
	rh2=evaluateexpression(&p, a-h);
	p.pos=0;
	derivative=(rh1.value-rh2.value)/(2*h); 
	
	m=a-(ra.value/derivative);
	variation=fabs(m-a);
	rm = evaluateexpression(&p, m);
    p.pos=0;
	printf("Iteration: 1 \n");
	printf("x(1) = %lf; f(%lf) = %lf\n",m,m,rm.value);
	printf("|x| = %lf \n\n",variation);	
	
	k=2;
	while(k<=maxiterations && variation>epsilon && flag<5){
		previousm=m;
		ra =evaluateexpression(&p, previousm);
		p.pos=0;
		
		rh1=evaluateexpression(&p, previousm+h);
    	p.pos=0;
		rh2=evaluateexpression(&p, previousm-h);
    	p.pos=0;
    	derivative= (rh1.value-rh2.value)/(2*h);
		
		m=previousm-(ra.value/derivative);
		rm = evaluateexpression(&p, m);
    	p.pos=0;
    	
		printf("Iteration: %d \n",k);
		printf("x(%d) = %lf; f(%lf) = %lf\n",k,m,m,rm.value);
		variation = fabs(previousm-m);
		printf("|x| = %lf \n\n",variation);
    	
		if (m<a || m>b) flag++;
		k++;
	}
	if (flag>=5) printf("Divergence ");
	if(k>maxiterations) printf("Maximum iteration has reached \n");
	printf("Root x = %lf",m);
}

//Method 4:
void MatrixInverse(){
	int i,j,N;
	double **Matrix;
	printf("Enter the value of N for (NxN) Matrix: ");
	scanf("%d",&N);

	Matrix = Allocate(N,N*2);
	printf("Enter your Matrix: \n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Enter [%d][%d] = ",i,j);
			scanf("%lf",&Matrix[i][j]);
		}
	}
	for(i=0,j=N;i<N;i++,j++){
		Matrix[i][j]=1.0;
	}
	
	printf("\nYOUR MATRIX: \n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lf   ",Matrix[i][j]);
		}
		printf("\n");
	}
	
	if (calculateDet(Matrix,N)) {
		FindingInverse(Matrix, N);
	}
	else {
		printf("This matrix doesn't have inverse");
	}
	FreeMatrix(Matrix, N);
}

void FindingInverse(double**Matrix, int N){
	int i, j, k, temp, flag=0;
	double Number;
	for(i=0;i<N;i++){
		if(Matrix[i][i]==0){
			for(k=i;k<N;k++){
				if(Matrix[k][i]!=0){
					for(j=i;j<N*2;j++){
						temp=Matrix[i][j];
						Matrix[i][j]=Matrix[k][j];
						Matrix[k][j]=temp;
					}
				}
			}
		}
		
		if (Matrix[i][i]!=1){
			Number = Matrix[i][i];
			for(j=i;j<N*2;j++){
				Matrix[i][j]/=Number;
			}
		}
		
		for(k=0;k<N;k++){
			if(k!=i && Matrix[k][i]!=0){
				Number=Matrix[k][i];
				for(j=0;j<N*2;j++){
					Matrix[k][j]-=Number*Matrix[i][j];
				}
			}
		}
	}
    
	printf("\nMATRIX INVERSE:\n");
	for(i=0;i<N;i++){
		for(j=N;j<N*2;j++){
			printf("%lf\t",Matrix[i][j]);
		}
		printf("\n");
	}

}

void Cholesky(){
	int i,j,k,N;
	double sum,temp;
	double **A, **L, **U, **X, **Y, **C;
	printf("Write the number of unknowns : ");
	scanf("%d",&N);
	A=Allocate(N,N);
	L=Allocate(N,N);
	U=Allocate(N,N);
	X=Allocate(N,1);
	Y=Allocate(N,1);
	C=Allocate(N,1);
	
	printf("Enter Matrix A [Coefficient Matrix]: \n");
	for(i=0;i<N;i++){
		printf("Equation no: %d\n",i+1);
		for(j=0;j<N;j++){
			printf("Coefficient of x[%d] = ",j%N);
			scanf("%lf",&A[i][j]);
		}
	}
	
	
	printf("\nEnter result matrix [C]: \n");
	for(i=0;i<N;i++){
		printf("Enter the result of equation no %d: ",i+1);
		scanf("%lf",&C[i][0]);
	}
	
	printf("\nYour Equations:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lf*x[%d] ",A[i][j],j);
			if(j<N-1)printf("+ ");
		}
		printf("= %lf\n",C[i][0]);
	}
		
	if (calculateDet(A,N)){
		for(i=0;i<N;i++){
			U[i][i]=1.0;
		}
		
		for(j=0;j<N;j++){
			for(i=j;i<N;i++){
				sum=0.0;
				for(k=0;k<j;k++){
					sum=sum+L[i][k]*U[k][j];
				}
				L[i][j]=A[i][j]-sum;
			}
			for(i=j+1;i<N;i++){
				sum=0.0;
				for(k=0;k<j;k++){
					sum=sum+L[j][k]*U[k][i];
				}
				U[j][i]=(A[j][i]-sum)/L[j][j];
			}
		}
		
		printf("\nLower [L] Matrix:\n");
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("%lf\t",L[i][j]);
			}
			printf("\n");
		}
		
		printf("\nUpper [U] Matrix:\n");
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("%lf\t",U[i][j]);
			}
			printf("\n");
		}
		
		printf("\nFrom [L][Y] = [C] we get: \n");
		for(i=0;i<N;i++){
			sum=0.0;
			for(j=0;j<i;j++){
				sum=sum+L[i][j]*Y[j][0];
			}
			Y[i][0]=(C[i][0]-sum)/L[i][i];
			printf("Y[%d] = %lf\n",i,Y[i][0]);
		}
		
		printf("\nFrom [U][X] = [Y] we get: \n");
		for(i=N-1;i>=0;i--){
			sum=0.0;
			for(j=i+1;j<N;j++){
				sum=sum+U[i][j]*X[j][0];
			}
			X[i][0]=(Y[i][0]-sum)/U[i][i];
			printf("X[%d] = %lf\n",i,X[i][0]);
		}
		
	}else {
		printf("\nNO SOLUTION [THE DETERMINANT OF 'A' matrix iz ZERO]");
	}
	
	FreeMatrix(A, N);
	FreeMatrix(L, N);
	FreeMatrix(U, N);
	FreeMatrix(X, N);
	FreeMatrix(Y, N);
	FreeMatrix(C, N);
}

//Method 6:
void GaussSeidal(){
	int i,j,k,N,maxiterations,maxrow,flag=1;
	double epsilon,*x,*previousx,temp,variation;
	double **Matrix;
	
	printf("Enter the number of unknowns: ");
	scanf("%d",&N);
	printf("Enter max number of iterations: ");
	scanf("%d",&maxiterations);
	printf("Enter epsilon value: ");
	scanf("%lf",&epsilon);
	
	Matrix=Allocate(N,N+1);
	x=(double*)calloc(N,sizeof(double));
	previousx=(double*)calloc(N,sizeof(double));
	
	printf("\nEnter coefficients of the variables in matrix format:\n");
	for(i=0;i<N;i++){
		printf("Equation no: %d\n",i+1);
		for(j=0;j<N;j++){
			printf("Coefficient of x[%d] = ",j%N);
			scanf("%lf",&Matrix[i][j]);
		}
	}
	
	printf("\nEnter the results of the equations:\n");
	for(i=0;i<N;i++){
		printf("The answer of equation no %d: ",i+1);
		scanf("%lf",&Matrix[i][N]);
	}
	
	printf("\nYour Equations:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lf*x[%d] ",Matrix[i][j],j);
			if(j<N-1)printf("+ ");
		}
		printf("= %lf\n",Matrix[i][N]);
	}
	
	if(calculateDet(Matrix,N)){
		printf("\nWrite the initial starting values for the variables: \n");
		for(i=0;i<N;i++){
			printf("x[%d] = ",i);
			scanf("%lf",&x[i]);
		}
		
		for(j=0;j<N;j++){
			maxrow=j;
			for(i=j+1;i<N;i++){
				if(fabs(Matrix[i][j])>fabs(Matrix[maxrow][j])){
					maxrow=i;
				}
			}
			if(maxrow!=j){
				for(i=0;i<=N;i++){
					temp=Matrix[j][i];
					Matrix[j][i]=Matrix[maxrow][i];
					Matrix[maxrow][i]=temp;
				}
			}
		}
		
		k=1;
		while(k<=maxiterations && flag!=0){
			flag=0;
			for(i=0;i<N;i++){
				previousx[i]=x[i];
			}
			
			for(i=0;i<N;i++){
				temp=Matrix[i][N];
				for(j=0;j<N;j++){
					if(j!=i)temp-=Matrix[i][j]*x[j];
				}
				x[i]=temp/Matrix[i][i];
			}
			
			printf("\nIteration: %d\n",k);
			for(i=0;i<N;i++){
				variation=fabs(x[i]-previousx[i]);
				printf("x[%d] = %.6f \t |x| = %lf\n",i,x[i],variation);
				if(variation>=epsilon){
					flag++;
				}
			}
			if(k==maxiterations) printf("\nMaximum number of iterations is reached.\n");
			k++;
		}
		
		printf("\nFinal solution:\n");
		for(i=0;i<N;i++){
			printf("x[%d]=%.6f\n",i,x[i]);
		}
	} else {
		printf("No unique solution [determinant is zero]");
	}
	
	free(x);
	free(previousx);
	FreeMatrix(Matrix,N);
}

//For Methods 4,5,6:
double** Allocate(int N, int M){
	int i;
	double **Matrix;
	Matrix=(double**)calloc(N,sizeof(double*));
	if(Matrix==NULL){
		printf("No enough memory");
		exit(-1);
	}
	for(i=0;i<N;i++){
		Matrix[i]=(double*)calloc(M,sizeof(double));
		if(Matrix[i]==NULL){
			printf("No enough memory");
			exit(-1);
		}
	}
	return Matrix;
}

void FreeMatrix(double** matrix,int N){
	int i;
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
}

double calculateDet(double** matrix,int N){
	double det,subdeterminant;
	double** submatrix;
	int col,sign;

	if(N==1)
		return matrix[0][0];

	if(N==2)
		return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];

	det=0;
	sign=1;

	col=0;
	while(col<N){
		submatrix=MakingSubmatrix(matrix,N,0,col);
		subdeterminant=calculateDet(submatrix,N-1);
		det=det+sign*matrix[0][col]*subdeterminant;
		sign=sign*-1;
		FreeMatrix(submatrix,N-1);
		col=col+1;
	}
	return det;
}

double** MakingSubmatrix(double** matrix,int N,int row,int col){
	double** submatrix;
	int i,j,submatrixi,submatrixj;

	submatrix=Allocate(N-1,N-1);

	submatrixi=0;
	for(i=0;i<N;i++){
		if(i!=row){
			submatrixj=0;
			for(j=0;j<N;j++){
				if(j!=col){
					submatrix[submatrixi][submatrixj]=matrix[i][j];
					submatrixj=submatrixj+1;
				}
			}
			submatrixi=submatrixi+1;
		}
	}
	return submatrix;
}

//Method 7:
void NumericalDifferentiation() {
    FUNCTION p;
    EVALUATERESULT r, r1, r2;
    double x;
    double h;
    double derivative;

    enterfunction(&p);
    printf("Enter point x: ");
    scanf("%lf", &x);
    printf("Enter h: ");
    scanf("%lf", &h);

	r=evaluateexpression(&p, x);
    if (r.error) {
        printf("Error evaluating function at x (pos %d)\n", p.pos);
        return;
    }
    p.pos=0;
    r1=evaluateexpression(&p, x + h);
    if (r1.error) {
        printf("Error evaluating function at x+h (pos %d)\n", p.pos);
        return;
    }
    p.pos=0;
    r2=evaluateexpression(&p, x - h);
    if (r2.error) {
        printf("Error evaluating function at x-h (pos %d)\n", p.pos);
        return;
    }
	
	derivative=(r1.value-r.value)/h;
	printf("Forward difference:\nf'(%lf) = %lf\n", x, derivative);
	
	derivative=(r.value-r2.value)/h;
	printf("Backward difference:\nf'(%lf) = %lf\n", x, derivative);
	
    derivative=(r1.value-r2.value)/(2*h);
    printf("Central difference:\nf'(%lf) = %lf\n", x, derivative);
}

//Method 8:
void SimpsonRules(){
	int i, n;
	FUNCTION p;
    EVALUATERESULT r,r1,r2,r3,r4;
    double **Matrix;
    double a, b, h, initial,x0;
    double simpson1_3=0, simpson3_8=0,total1=0,total2=0;
    
    enterfunction(&p);
    printf("Enter the boundaries [a,b]:\na = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    printf("Enter n: ");
	scanf("%d", &n);
	h=(b-a)/n;
    
    Matrix=Allocate(n+1,2);
    for(i=0;i<n+1;i++){
    	Matrix[i][0]=a+(i*h);
    	r = evaluateexpression(&p, Matrix[i][0]);
    	if (r.error) { printf("Error evaluating function at x (pos %d)\n", p.pos); FreeMatrix(Matrix, n+1);	return;}
		else{
    		Matrix[i][1] = r.value;
		}
    	p.pos = 0;
	}
	
	for (i=1;i<=n-1;i+=2){
		total1+=Matrix[i][1];
	}
	for (i=2;i<=n-2;i+=2){
		total2+=Matrix[i][1];
	}
	simpson1_3=Matrix[0][1]+Matrix[n][1]+(4*total1)+(2*total2);
	simpson1_3*=(h/3);
	printf("Simpson 1/3\nResult: %lf\n",simpson1_3);
	
	initial=a;
	for(i=0;i<n;i++){
		x0=initial;
		r1=evaluateexpression(&p, x0);
		if(r1.error) {printf("Error at x = %lf\n",x0); FreeMatrix(Matrix, n+1); return;}
		p.pos = 0;

		r2=evaluateexpression(&p,x0+h/3);
		if(r2.error) {printf("Error at x = %lf\n",x0+h/3); FreeMatrix(Matrix, n+1); return;}
		p.pos = 0;

		r3=evaluateexpression(&p,x0+2*(h/3));
		if(r3.error) {printf("Error at x = %lf\n",x0+2*h/3); FreeMatrix(Matrix, n+1); return;}
		p.pos = 0;

		r4=evaluateexpression(&p,x0+h);
		if(r4.error) {printf("Error at x = %lf\n",x0+h); FreeMatrix(Matrix, n+1); return;}
		p.pos = 0;

		simpson3_8 += (h/8)*(r1.value + 3*r2.value + 3*r3.value + r4.value);
		initial+=h;
	}
	printf("Simpson 3/8:\nResult: %lf\n",simpson3_8);
	FreeMatrix(Matrix, n+1);
}

//Method 9:
void TrapezMethod(){
	int i,n;
	FUNCTION p;
    EVALUATERESULT r;
    double **Matrix;
    double a, b, h;
    double trapez, total=0;
    
    enterfunction(&p);
    printf("Enter the boundaries:\na = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    printf("Enter n: ");
    scanf("%d", &n);
    h=(b-a)/n;
    
    Matrix=Allocate(n+1,2);
    for(i=0;i<n+1;i++){
    	Matrix[i][0]=a+(i*h);
    	r = evaluateexpression(&p, Matrix[i][0]);
    	if (r.error) {printf("Error evaluating function at x (pos %d)\n", p.pos); FreeMatrix(Matrix, n+1); return;}
		else{
    		Matrix[i][1] = r.value;
		}
    	p.pos=0;
	}
	
	trapez=(Matrix[0][1]+Matrix[n][1])*(0.5);
	for(i=1;i<n;i++){
		total+=Matrix[i][1];
	}
	trapez+=total;
	trapez*=h;
	printf("From %lf to %lf, the answer of integral of f(x) is: %lf",a,b,trapez);
	FreeMatrix(Matrix, n+1);
}

//Method 10:
void GregoryNewton(){
	int i,j,N;
	double **Matrix;
	double totalgregory,total,x0,h,xi,factorial;
	
	printf("Enter initial x0 value: ");
	scanf("%lf",&x0);
	printf("Enter h value: ");
	scanf("%lf",&h);
	printf("Enter total number of points that you will enter: ");
	scanf("%d",&N);	
	Matrix = Allocate(N,N+1);
	printf("\nx\tf(x)\n");
	for(i=0;i<N;i++){
		Matrix[i][0]=x0+(i*h);
		printf("%.2lf\t",Matrix[i][0]);
		scanf("%lf",&Matrix[i][1]);
	}
	
	for(j=2;j<N+1;j++){	 //Ileri fark matrisi
		for(i=j-1;i<N;i++) {
			Matrix[i][j]=Matrix[i][j-1]-Matrix[i-1][j-1];
		}
	}
	
	printf("\nEnter the x value that you need to find its image: ");
	scanf("%lf",&xi);
	
	totalgregory=Matrix[0][1];
	for(i=1;i<N;i++){
		total=Matrix[i][i+1];
		for(j=0;j<i;j++){
			total=total*(xi-Matrix[j][0]);
		}
		factorial=1.0;
		for(j=1;j<=i;j++) {
		factorial*=j;
		}
		total=total/(factorial*pow(h,i));
		totalgregory+=total;
	}

	printf("\n\nf(%lf) = %lf",xi,totalgregory);
	FreeMatrix(Matrix,N);
}
