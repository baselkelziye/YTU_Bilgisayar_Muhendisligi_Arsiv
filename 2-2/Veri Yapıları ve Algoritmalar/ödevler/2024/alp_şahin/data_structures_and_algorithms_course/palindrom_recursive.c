#include <stdio.h>

int reverse(int N);
int compare(int N);

int main()
{
    printf("%d",compare(1));
    return 0;
}

int reverse(int N)
{
    int tmp;
    static int sum;
    if(N == 0)
    {
        return sum;
    }
    tmp = N%10;
    sum = sum*10+tmp;
    reverse(N/10);
}
int compare(int N)
{
    int sum = reverse(N);
    if(sum == N)
    {
        return 1;
    }
    return 0;
}