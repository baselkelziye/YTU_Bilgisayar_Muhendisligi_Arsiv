#include<stdio.h>
#include<conio.h>
#include<math.h>

/* denklem sistemi:
   -x + 4y - 3z=-8
   3x + y - 2z= 9
   x - y + 4z=1
*/
/* Eþitlik:
   x = (9-y+2z)/3
   y = (-8+x+3z)/4
   z = (1-x+y)/4
*/

float f1(float x,float y,float z);
float f2(float x,float y,float z);
float f3(float x,float y,float z);

int main()
{
	//baslangic noktalari
    float x0=5, y0=5, z0=5, x1, y1, z1, e1, e2, e3, e;
    int iterate=1;
	
	
    printf("epsilon degeri:");
    scanf("%f", &e);

    printf("\niteration\tx\ty\tz\n");
    do
    {
    	//bulunnan degerler direk kullanýlýyor	
     	x1 = f1(x0,y0,z0);
     	y1 = f2(x1,y0,z0);
     	z1 = f3(x1,y1,z0);
     	printf("%d\t%0.4f\t%0.4f\t%0.4f\n",iterate, x1,y1,z1);

     	e1 = fabs(x0-x1);
     	e2 = fabs(y0-y1);
     	e3 = fabs(z0-z1);

     	iterate++;

     	x0 = x1;
     	y0 = y1;
     	z0 = z1;

    }while(e1>e && e2>e && e3>e);

    printf("\ncozum: x=%0.4f, y=%0.4f ve z = %0.4f\n",x1,y1,z1);

    return 0;
}

//X
float f1(float x,float y,float z){
	return (9-y+2*z)/3;
}

//Y
float f2(float x,float y,float z){
	return  (-8+x+3*z)/4;
}

//Z
float f3(float x,float y,float z){
	return (1-x+y)/4;
}


/*
#include<stdio.h>

#define MAX 20

 denklem sistemi:
   -x + 4y - 3z=-8
   3x + y - 2z= 9
   x - y + 4z=1

Eþitlik:
   x = (9-y+2z)/3
   y = (-8+x+3z)/4
   z = (1-x+y)/4


float f1(float x,float y,float z,int dizi[][MAX]);
float f2(float x,float y,float z,int dizi[][MAX]);
float f3(float x,float y,float z,int dizi[][MAX]);

int main()
{
	//x0,y0,z0 degerlerini al
    float x0, y0, z0, x1, y1, z1, e1, e2, e3, e;
    int iterate=1;
	
	
	float dizi[MAX][MAX];
	int n,i,j;
	
	printf("matris N degerini giriniz: ");
	scanf("%d", &n);
	 
	 for(i=1;i<=n;i++)
     {
	     for(j=1;j<=n+1;j++)
	  {
		   printf("%d inci satir %d inci stun matris degeri = ",i,j);
		   scanf("%f", &dizi[i][j]);
	  }
	}
	
	printf("baslangic noktalari:\n");
		
	printf("X baslangic degeri:");
    scanf("%f", &x0);
    printf("y baslangic degeri:");
    scanf("%f", &y0);
    printf("z baslangic degeri:");
    scanf("%f", &z0);
	
    printf("epsilon degeri:");
    scanf("%f", &e);

    printf("\niteration\tx\ty\tz\n");
    do
    {
    	//bulunnan degerler direk kullanýlýyor	
     	x1 = f1(x0,y0,z0,dizi);
     	y1 = f2(x1,y0,z0,dizi);
     	z1 = f3(x1,y1,z0,dizi);
     	printf("%d\t%0.4f\t%0.4f\t%0.4f\n",iterate, x1,y1,z1);

     	e1 = fabs(x0-x1);
     	e2 = fabs(y0-y1);
     	e3 = fabs(z0-z1);

     	iterate++;

     	x0 = x1;
     	y0 = y1;
     	z0 = z1;

    }while(e1>e && e2>e && e3>e);

    printf("\ncozum: x=%0.4f, y=%0.4f ve z = %0.4f\n",x1,y1,z1);

    return 0;
}

//X
float f1(float x,float y,float z,int dizi[][MAX]){
	return (dizi[1][4]+dizi[1][2]*y+dizi[1][3]*z)/dizi[1][1];
}

//Y
float f2(float x,float y,float z,int dizi[][MAX]){
	return (dizi[2][4]+dizi[2][1]*x+dizi[2][3]*z)/dizi[2][2];
}

//Z
float f3(float x,float y,float z,int dizi[][MAX]){
	return (dizi[3][4]+dizi[3][1]*x+dizi[3][2]*y)/dizi[3][3];
}
*/
