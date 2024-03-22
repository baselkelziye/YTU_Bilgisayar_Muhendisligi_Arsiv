#include <stdio.h>

int fibonaci(int i){
   if(i == 0)
      return 0;
   else if(i == 1)
      return 1;
      
   return fibonaci(i-1) + fibonaci(i-2);
}

int  main(){
    int i; //Çevrim deðiþkeni
    int n; //Kac tane fibonacci sayisi hesaplanacak. Onu tutuyor.
    
    printf("Fibonacci serisi kacinci elemana kadar hesaplansin: ");
    scanf("%d",&n);
    
    for (i = 1; i <= n; i++)
       printf("%d\t%n", fibonaci(i));
    
    return 0;
}