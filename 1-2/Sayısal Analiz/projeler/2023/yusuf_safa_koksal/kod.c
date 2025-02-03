#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 50

void printMainMenu(int *whichMethod);
void bisection();
void regulaFalsi();
void newtonRaphson();
void inverseMatrix();
void gaussElimination();
void gaussSeidel();
void numericalDifferentiation();
void simpsonRule();
void trapezoidalRule();
void gregoryNewton();
void takeMatrix(float matrix[][MAX],int *len);
void printMatrix(float matrix[][MAX],int len);
void printEquation(float equation[],int len);
void takeEquation(float coefficients[],int *len);
void takeDifferential(float differantial[],int len);
float calculateEquationValue(float coefficients[],int len,float xValue);
void determineRange(float coefficients[],int len,float *a,float *b);
float calculateCombination(float topNumber, int bottomNumber);


int main()
{
    int whichMethod;
    int stop=0;
    char continueControl;
    
    printf("***** Welcome *****\n\n");
	while(stop==0)
	{
	    printMainMenu(&whichMethod);
		switch (whichMethod)
	    {
	        case 0:
	        stop=1;
	        break;
	        
	        case 1:
	        bisection();
	        break;
	        
	        case 2:
	        regulaFalsi();
	        break;
	        
	        case 3:
	        newtonRaphson();
	        break;
	        
	        case 4:
	        inverseMatrix();
	        break;
	        
	        case 5:
	        gaussElimination();
	        break;
	        
	        case 6:
	        gaussSeidel();
	        break;
	        
	        case 7:
	        numericalDifferentiation();
	        break;
	        
	        case 8:
	        simpsonRule();
	        break;
	        
	        case 9:
	        trapezoidalRule();
	        break;
	        
	        case 10:
	        gregoryNewton();
	        break;
	
	        default:
	        printf("\nPlease, enter a valid number!!!\n\n");
	        sleep(1);
	        system("cls");
	    }
	    
	    if(whichMethod>=1 && whichMethod<=10)
		{
		    printf("\n\nDo you want to make another calculation? (Y/N) : ");
		    scanf(" %c",&continueControl);
		    
		    if(continueControl=='Y' || continueControl=='y')
				system("cls");
			else if(continueControl=='N' || continueControl=='n')
				stop=1;
		}
		printf("\n");
	}
    
    return 0;
}

void printMainMenu(int *whichMethod)
{
    printf("Quit (0)\nBisection (1)\nRegula-Falsi (2)\nNewton Raphson (3)\nInverse Matrix (4)\nGauss Elimination (5)\nGauss-Seidel (6)\nNumerical Differentiation (7)\nSimpson's Rule (8)\nTrapezoidal Rule (9)\nGregory-Newton (10)\nYour Choice : ");
    scanf(" %d",whichMethod);
}

void bisection()
{
	int len, iteration=1 ,maxIteration;
	float coefficients[MAX];
	float a, b, c, resultA, resultB, resultC, epsilon;
	float error=10;
	
	takeEquation(coefficients,&len);
	
	printf("Function: ");
	printEquation(coefficients,len);
	
	printf("\n\nPlease, enter epsilon value: ");
	scanf("%f",&epsilon);
	
	printf("\nPlease, enter max iteration amount: ");
	scanf("%d",&maxIteration);
	
	printf("\nPlease enter range you want to examine for root");
	determineRange(coefficients,len,&a,&b);
	
	while(fabs(error)>=epsilon && iteration<=maxIteration)
	{
		resultA=calculateEquationValue(coefficients,len,a);
		resultB=calculateEquationValue(coefficients,len,b);
		
		error=(a-b)/pow(2,iteration);
		
		if(resultA*resultB<0)
		{
			c=(a+b)/2;
			resultC=calculateEquationValue(coefficients,len,c);
			
			if(resultC==0)
				a=b=c;
			else if(resultC*resultA>0)
				a=c;
			else
				b=c;
		}
		
		printf("\nIteration---->%d     f(%9f)= %9f     error: %f",iteration,c,resultC,fabs(error));
		iteration++;
	}
	
	printf("\n\nRoot: %f",c);
}

void regulaFalsi()
{
	int len, iteration=1, maxIteration;
	float coefficients[MAX];
	float a, b, c, resultA, resultB, resultC, epsilon;
	float error=10;
	
	takeEquation(coefficients,&len);
	
	printf("Function: ");
	printEquation(coefficients,len);
	
	printf("\n\nPlease, enter epsilon value: ");
	scanf("%f",&epsilon);
	
	printf("\nPlease, enter max iteration amount: ");
	scanf("%d",&maxIteration);
	
	printf("\nPlease enter range you want to examine for root: ");
	determineRange(coefficients,len,&a,&b);
	
	while(fabs(error)>=epsilon && iteration<=maxIteration)
	{
		resultA=calculateEquationValue(coefficients,len,a);
		resultB=calculateEquationValue(coefficients,len,b);
		
		error=(a-b)/pow(2,iteration);
		
		if(resultA*resultB<0)
		{
			c=((b*resultA)-(a*resultB))/(resultA-resultB);
			resultC=calculateEquationValue(coefficients,len,c);
			
			if(resultC==0)
				a=b=c;
			else if(resultC*resultA>0)
				a=c;
			else
				b=c;
		}
		
		printf("\nIteration---->%d     f(%9f)= %9f     error: %f",iteration,c,resultC,fabs(error));
		iteration++;
	}
	
	printf("\n\nRoot: %f",c);
}

void newtonRaphson()
{
	int i;
	float epsilon;
	int len ,iteration=0, maxIteration, flag=1, resultControl=1;
	float newRoot=0,oldRoot;
	float coefficients[MAX];
	float differential[MAX];
	
	takeEquation(coefficients,&len);
	
	for(i=0;i<len;i++)
	{
		differential[i]=coefficients[i];
	}
	takeDifferential(differential,len);
	
	printf("\nFunction:  ");
	printEquation(coefficients,len);
	
	printf("\n\nPlease, enter epsilon value: ");
	scanf("%f",&epsilon);
	
	printf("\nPlease, enter max iteration amount: ");
	scanf("%d",&maxIteration);
	
	printf("\nPlease, enter starting value: ");
	scanf("%f",&newRoot);
	printf("\n");
	
	do
	{
		iteration++;
		
		if(iteration>=maxIteration)
			flag=0;  
		
		oldRoot=newRoot;
		
		if(calculateEquationValue(differential,len-1,oldRoot)!=0)
			newRoot=oldRoot-(calculateEquationValue(coefficients,len,oldRoot)/calculateEquationValue(differential,len-1,oldRoot));
		else
		{
			flag=0;
			resultControl=0;
		}
					
		printf("Iteration-->%d     f(%9f)=%9f         error: %f\n",iteration,newRoot,calculateEquationValue(coefficients,len,newRoot),fabs(newRoot-oldRoot));
	}while((fabs(oldRoot-newRoot)>=epsilon) && flag==1);
	
	if(resultControl==1)
	{
		if(iteration<maxIteration)
		printf("\n\nRoot: %f",newRoot);
		else
		printf("\n\nRoot not found because of divergence!");
	}
	else
		printf("\nNo results were found because the derivative of the function was 0 at some point.");
	
}

void inverseMatrix()
{
    int i, j, k;
	int len ,noInverse=0;
    float tmp;
	float matrix[MAX][MAX];
	float tmpLine[MAX];
	float tmpLineUnit[MAX];
	float unitMatrix[MAX][MAX]={0};

    takeMatrix(matrix,&len);         

	printf("\nMatrix:\n");
    printMatrix(matrix,len);   

    for(i=0; i<len;i++)  
    {
        unitMatrix[i][i]=1;
    }
    
	
    for(i=0;i<len;i++)
    {
	    if(matrix[i][i]==0)           // matrisin 1 yapilacak olan elemani sifirsa satir degistirme islemi uygulanir.
		{
			for(j=i+1;j<len;j++)
			{
				if(matrix[j][i]!=0)
				{
					for(k=0;k<len;k++)
					{
						tmpLine[k]=matrix[j][k];
						matrix[j][k]=matrix[i][k];
						matrix[i][k]=tmpLine[k];
						
						tmpLineUnit[k]=unitMatrix[j][k];
						unitMatrix[j][k]=unitMatrix[i][k];
						unitMatrix[i][k]=tmpLineUnit[k];
					}
					
					j=len;
				}
			}
		}
		
		tmp=matrix[i][i];
		
		if(tmp==0)                // Matrisin determinanti 0 ise buraya girer ve donguden cikar matrisin tersi yoktur
		{
			noInverse=1;      
			i=len;
		}
		
		else                     // Elementer satir islemleri yapilir
		{
			for(j=0;j<len;j++)
	        {
	            matrix[i][j]/=tmp;
	            unitMatrix[i][j]/=tmp;
	        }
			
	        for(j=0;j<len;j++)
	        {
	            tmp=matrix[j][i];
	            for(k=0;k<len;k++)
	            {
	                if(j!=i)
	                {
	                    matrix[j][k] -= matrix[i][k]*tmp;
	                    unitMatrix[j][k] -= unitMatrix[i][k]*tmp;
	                }
	            }
	        }
		}
    }
	
	if(noInverse==0)
	{
		printf("\nInverse Matrix:\n");
    	printMatrix(unitMatrix,len);
	}
	else if(noInverse==1)
		printf("\nSince the determinant of the matrix is 0, there is no inverse.");
    
}

void gaussElimination()
{
	int i, j, k;
	int len, noResult=0;
	float tmp;
	float matrix[MAX][MAX];
	float resultMatrix[MAX];
	float answerMatrix[MAX];
	float tmpLine[MAX];
	
	takeMatrix(matrix,&len);
	
	printf("\n");
	printMatrix(matrix,len);
	
	printf("\nPlease, enter result matrix:\n");
	for(i=0;i<len;i++)
	{
		printf("[%d]:",i);
		scanf("%f",&resultMatrix[i]);
	}
	
	for(i=0;i<len;i++)
	{
		if(matrix[i][i]==0)           // Matrisin 1 yapilacak olan elemani sifirsa satir degistirme islemi uygulanir.
		{
			for(j=i+1;j<len;j++)
			{
				if(matrix[j][i]!=0)
				{
					for(k=0;k<len;k++)
					{
						tmpLine[k]=matrix[j][k];
						matrix[j][k]=matrix[i][k];
						matrix[i][k]=tmpLine[k];
					}
					
					tmp=resultMatrix[i];
					resultMatrix[i]=resultMatrix[j];
					resultMatrix[j]=tmp;
					
					j=len;
				}
			}
		}
		
		tmp=matrix[i][i];
		
		if(tmp==0)                // Matrisin determinanti 0 ise buraya girer ve donguden cikar sonuc bulunamaz
		{
			noResult=1;      
			i=len;
		}
		
		else                      // Matris ust ucgen matris haline getirilir
		{
			for(j=0;j<len;j++)
			{
				matrix[i][j]/=tmp;
			}
			resultMatrix[i]/=tmp;
			
			for(j=i+1;j<len;j++)
			{	
				tmp=matrix[j][i];
				for(k=i;k<len;k++)
				{
					matrix[j][k]-=matrix[i][k]*tmp;
				}
				resultMatrix[j]-=resultMatrix[i]*tmp;
			}	
		}
	}
	
	answerMatrix[len-1]=resultMatrix[len-1]/matrix[len-1][len-1];     // Sondan baslayarak sonuclarý bulur.
	for(i=1;i<len;i++)
	{
		tmp=0;
		for(j=len-1;j>=len-i;j--)
		{
			tmp+=matrix[len-1-i][j]*answerMatrix[j];
		}
		answerMatrix[len-1-i]=(resultMatrix[len-1-i]-tmp)/matrix[len-1-i][len-1-i];
	}
	
	if(noResult==0)
	{
		printf("\nResult\n");
		for(i=0;i<len;i++)
		{
			printf("x%d= %f\n",i,answerMatrix[i]);
		}
	}
	else
	{
		printf("\nSince the determinant of the matrix is 0, there is no result.");
	}
}

void gaussSeidel()
{
	int i, j, k;
	int len, flag=1;
	int maxIndex=0, maxIteration,iteration=1;
	float epsilon, tmp, initialValue=5;
	float matrix[MAX][MAX];
	float resultMatrix[MAX];
	float tmpArray[MAX];
	float answerArray[MAX];
	float oldAnswerArray[MAX];
		
	printf("\nPlease, enter epsilon value: ");
	scanf("%f",&epsilon);
	printf("\nPlease, enter max iteration amount: ");
	scanf("%d",&maxIteration);
	printf("\nPlease, enter initial value of points: ");
	scanf(" %f",&initialValue);
	
	takeMatrix(matrix,&len);
	
	printf("\nMatrix:\n");
	printMatrix(matrix,len);

	printf("\nPlease, enter result matrix:\n");
	for(i=0;i<len;i++)
	{
		printf("[%d]: ",i);
		scanf("%f",&resultMatrix[i]);
	}
	
	for(i=0;i<len;i++)   // Baslangic degeri atanir.   
	{
		answerArray[i]=initialValue;                     
	}
	
	for(i=0;i<len;i++)   // En buyuk katsayilar kosegene getirilir
	{
		for(j=0;j<len;j++)
		{
			if(fabs(matrix[i][j])>fabs(matrix[i][maxIndex]))
			{
				maxIndex=j;
			}
		}
		                                                 
		if(maxIndex!=i)
		{
			for(j=0;j<len;j++)
			{
				tmpArray[j]=matrix[i][j];
				matrix[i][j]=matrix[maxIndex][j];
				matrix[maxIndex][j]=tmpArray[j];
			}
			tmp=resultMatrix[i];
			resultMatrix[i]=resultMatrix[maxIndex];
			resultMatrix[maxIndex]=tmp;
		}
	}
	
	
	while(iteration<=maxIteration && flag==1)
	{
		for(i=0;i<len;i++)
		{
			oldAnswerArray[i]=answerArray[i];
		}
		
		for(i=0;i<len;i++)
		{
			tmp=0;
			for(j=0;j<len;j++)
			{
				if(i!=j)
				{
					tmp+=matrix[i][j]*answerArray[j];	
				}
			}
			answerArray[i]=(resultMatrix[i]-tmp)/matrix[i][i];
		}
		
		flag=0;
		for(i=0;i<len;i++)
		{
			if(fabs(oldAnswerArray[i]-answerArray[i])>=epsilon)
				flag=1;
		}
		
		printf("\nIteration----->%d\n",iteration);
		for(i=0;i<len;i++)
		{
			printf("x%d= %9f       error: %f\n",i,answerArray[i],fabs(answerArray[i]-oldAnswerArray[i]));
		}
		
		iteration++;
	}
	
	printf("\nResult:\n");
	for(i=0;i<len;i++)
	{
		printf("x%d= %9f\n",i,answerArray[i]);
	}
}

void numericalDifferentiation()
{
	int len;
	int derivativeDegree;
	float xValue, h ,result;
	float coefficients[MAX];
	
	takeEquation(coefficients,&len);
	
	printf("Function: ");
	printEquation(coefficients,len);
	
	printf("\n\nWhich derivative do you want to calculate(1,2 or 3): ");
	scanf("%d",&derivativeDegree);
	
	printf("\nx: ");
	scanf("%f",&xValue);
	
	printf("\nh: ");
	scanf("%f",&h);
	
	if(derivativeDegree==1) // 1. turev hesabi
	{
		result=(-3*calculateEquationValue(coefficients,len,xValue)+4*calculateEquationValue(coefficients,len,xValue+h)-calculateEquationValue(coefficients,len,xValue+2*h))/(2*h);
		printf("\nResult:\nf'(%f)= %f",xValue,result);
	}
	else if(derivativeDegree==2) // 2. turev hesabi
	{
		result=(calculateEquationValue(coefficients,len,xValue)-2*calculateEquationValue(coefficients,len,xValue+h)+calculateEquationValue(coefficients,len,xValue+2*h))/(h*h);
		printf("\nResult:\nf''(%f)= %f",xValue,result);
	}
	else if(derivativeDegree==3) // 3. turev hesabi
	{
		result=(-calculateEquationValue(coefficients,len,xValue)+3*calculateEquationValue(coefficients,len,xValue+h)-3*calculateEquationValue(coefficients,len,xValue+2*h)+calculateEquationValue(coefficients,len,xValue+3*h))/(h*h*h);
		printf("\nResult:\nf'''(%f)= %f",xValue,result);
	}
}

void simpsonRule()
{
	int i, n;
	int len;
	float a, b ,h;
	float resultA=0, resultB=0, initialRange;
	float coefficients[MAX];
	
	takeEquation(coefficients,&len);
	
	printf("\nYour function: ");
	printEquation(coefficients,len);
	
	printf("\n\nPlease, enter range of integral: ");
	scanf("%f %f",&a,&b);
	
	printf("\nn: ");
	scanf("%d",&n);
	
	h=(b-a)/n;
	
	for(i=1;i<n;i++)  // Simpson 1/3
	{
		if(i%2==1)
			resultA+=4*calculateEquationValue(coefficients,len,a+h*i);
		else
			resultA+=2*calculateEquationValue(coefficients,len,a+h*i);
		
	}
	resultA+=calculateEquationValue(coefficients,len,a)+calculateEquationValue(coefficients,len,b);
	resultA*=h/3;
	
	
	initialRange=a;
	for(i=0;i<n;i++)   // Simpson 3/8
	{
		resultB+=h*(calculateEquationValue(coefficients,len,initialRange)+3*calculateEquationValue(coefficients,len,initialRange+h/3)+3*calculateEquationValue(coefficients,len,initialRange+2*h/3)+calculateEquationValue(coefficients,len,initialRange+3*h/3))/8;
		initialRange+=h;
	}
	
	printf("\nSimpson 1/3 --->  Result: %f\nSimpson 3/8 --->  Result: %f",resultA,resultB);
}

void trapezoidalRule()
{
	int i, n;
	int len;
	float a, b, h;
	float result=0;
	float coefficients[MAX];

	takeEquation(coefficients,&len);
	
	printf("\nYour function: ");
	printEquation(coefficients,len);
	
	printf("\n\nPlease, enter range of integral: ");
	scanf("%f %f",&a,&b);
	
	printf("\nn: ");
	scanf("%d",&n);
	
	h=(b-a)/n;
	
	for(i=1;i<n;i++)
	{
		result+=2*calculateEquationValue(coefficients,len,a+h*i);
	}
	result+=calculateEquationValue(coefficients,len,a)+calculateEquationValue(coefficients,len,b);
	
	result*=h/2;
	
	printf("\nResult: %f",result);
}

void gregoryNewton()
{
	int i, j;
	float k, h;
	float xValue, result, tmp;
	int pointsAmount, maxDifferencesDegree;
	int flag=1;
	float function[2][MAX];
	float differences[MAX][MAX];
	
	printf("\nPlease, enter x0: ");
	scanf("%f",&function[0][0]);
	
	printf("\nPlease, enter h: ");
	scanf("%f",&h);
	
	printf("\nPlease, enter the number of points you will enter: ");
	scanf("%d",&pointsAmount);
	
	printf("\n");
	for(i=0;i<pointsAmount;i++)     // Noktalarin fonksiyondaki degerini kullanicidan alir
	{
		function[0][i]=function[0][0]+h*i;
		printf("f(%.1f)= ",function[0][i]);
		scanf("%f",&function[1][i]);
	}
	
	printf("\nWhich value do you want to calculate: ");
	scanf("%f",&xValue);
	
	k=(xValue-function[0][0])/h;
	
	for(i=0;i<pointsAmount;i++)
	{
		flag=1;
		tmp=differences[0][i];
		for(j=0;j<pointsAmount-1-i;j++)  // Farklar matrisini doldurur 
		{
			if(i==0)
				differences[j][i]=function[1][j+1]-function[1][j];
			else
				differences[j][i]=differences[j+1][i-1]-differences[j][i-1];
				
			if(differences[j][i]!=tmp)
				flag=0;
			
			tmp=differences[j][i];
		}
		
		if(flag==1)
		{
			maxDifferencesDegree=i;
			i=pointsAmount;
		}
	}
	
	result+=function[1][0];
	for(i=0;i<maxDifferencesDegree;i++)
	{
		result+=calculateCombination(k,i+1)*differences[0][i];
	}
	
	printf("\nf(%f)= %f",xValue,result);
}

void takeMatrix(float matrix[][MAX],int *len)   // Matrisi kullanicidan alir
{
    int i ,j;
    
    printf("\nN: ");
    scanf("%d",len);
    printf("\n");
    
    for(i=0;i<*len;i++)
    {
        for(j=0;j<*len;j++)
        {
            printf("[%d][%d] :",i,j);
            scanf("%f",&matrix[i][j]);
        }
    }
}

void printMatrix(float matrix[][MAX],int len)   // Verilen matrisi yazdirir
{
    int i, j;
    
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            printf("%5.2f   ",matrix[i][j]);
        }
        printf("\n");
    }
}

void printEquation(float equation[],int len)    // Verilen denklemi yazdirir
{
	int i;
	
	for(i=len-1;i>=0;i--)
	{
		if(i!=0)
		{
			if(equation[i]>0)
				printf("+%.2fx^%d ",equation[i],i);
			else if(equation[i]<0)
				printf("%.2fx^%d ",equation[i],i);
		}
		else
		{
			if(equation[i]>0)
				printf("+%.2f",equation[i]);
			else if(equation[i]<0)
				printf("%.2f",equation[i]);
		}
			
	}
}

void takeEquation(float coefficients[],int *len) // Denklemi kullanicidan alir
{
	int i;
	int tmp;
	
	printf("\nPlease, enter polynomial's degree: ");
	scanf("%d",&tmp);
	
	*len=tmp+1;
	printf("\n");
	for(i=*len-1;i>=0;i--)
	{
		printf("Coefficient of x^%d: ",i);
		scanf("%f",&coefficients[i]);
	}
	printf("\n");
}

void takeDifferential(float differantial[],int len)  // Turev alir
{
	int i;
	
	for(i=0;i<len-1;i++)
	{
		differantial[i]=differantial[i+1]*(i+1);
	}
}

float calculateEquationValue(float coefficients[],int len,float xValue) // Veriilen denklemin verilen noktadaki degerini hesaplar
{
	int i;
	float result=0;
	
	for(i=0;i<len;i++)
	{
		result+=coefficients[i]*pow(xValue,i);
	}
	
	return result;
}

void determineRange(float coefficients[],int len,float *a,float *b)  // Islem yapilacak araliði kullanicidan alir
{
	short isRangeStepPassed=0;
	float resultA, resultB;
	
	while(isRangeStepPassed==0)
	{
		isRangeStepPassed=1;
		
		printf("\nA: ");
		scanf(" %f",a);
		printf("B: ");
		scanf(" %f",b);                                                         // A B araliklarini belirleme
		while(*b<*a)
		{
			printf("B range has to be bigger than A range!\nB: ");
			scanf(" %f",b);
		}
	
		resultA=calculateEquationValue(coefficients,len,*a);
		resultB=calculateEquationValue(coefficients,len,*b);
	
		if(resultA*resultB>=0)
		{
			printf("There might be no root in the range of A and B. Please, enter different range.");
			isRangeStepPassed=0;
		}
	}
}

float calculateCombination(float topNumber, int bottomNumber)  // Kombinasyon hesaplar
{
	int i;
	float result=1;
	
	for(i=0;i<bottomNumber;i++)
	{
		result*=topNumber/(bottomNumber-i);
		topNumber--;
	}
	
	return result;
}

