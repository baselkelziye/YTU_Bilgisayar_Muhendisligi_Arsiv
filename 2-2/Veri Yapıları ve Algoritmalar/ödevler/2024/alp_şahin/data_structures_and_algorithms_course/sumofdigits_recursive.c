#include <stdio.h>

unsigned long long int sumofDigits(unsigned long long int N);
int main(){

    printf("%lld",sumofDigits(9999999999999999999));
    return 0;
}

unsigned long long int sumofDigits(unsigned long long int N)
{
    if(N == 0)
    {
        return 0;
    }
    return (long long int)N % 10 + sumofDigits(N/10);
}