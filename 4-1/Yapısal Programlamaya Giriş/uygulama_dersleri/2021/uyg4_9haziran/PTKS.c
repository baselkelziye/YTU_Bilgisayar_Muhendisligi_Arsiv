#include<stdio.h>
#include<math.h>

#define TILL 9

int main()
{
    int p,t,product,k,s,i;
	
    for(p=2;p<=TILL;p++) //1^9=1 2^9=512 üç basamaklý kuvvet olusturabilecek ilk p degeri=2 
    {
        for(t=3;t<=TILL;t++) //9^1=9 9^2=81 9^3=729 üç basamaklý kuvvet olusturabilecek ilk t degeri=3
        {
            product=p;
            i=1;
			while ((i<t) && (product<999))	//product 3 basamagi geçiyorsa çarpmaya devam etme
			{
				product=product*p;
				i++;
			}
			if ((i==t) && (product/100==t))	//üç basamaklý bir product varsa  ve ilk digit=t ise
			{
				s=product%10;
				k=(product%100)/10;
				printf("p:%d t:%d k:%d s:%d\n",p,t,k,s);
			}
			
        }
    }
}

