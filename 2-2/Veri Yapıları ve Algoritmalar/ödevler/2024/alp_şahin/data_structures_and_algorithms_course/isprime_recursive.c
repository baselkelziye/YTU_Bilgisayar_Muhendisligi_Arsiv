#include <stdio.h>

int isPrime(int n, int i);

int main()
{
    printf("%d",isPrime(11,2));
    return 0;
}
int isPrime(int n, int i)
{
    if(n<=2)
        return (n==2) ? 1 : 0;
    if(n%i==0)
        return 0;
    if(n < i *i)
        return 1;
    return isPrime(n,i+1);
}