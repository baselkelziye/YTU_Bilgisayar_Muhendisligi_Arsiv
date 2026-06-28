// uygulama11.cpp : ozdeger hesabý.
//

#include "stdafx.h"
#include <math.h>
int main()
{
	
  double A[9]={-1,1,2,3,4,5,6,7,8};
	double t1,t2,teta,t,c,s,oz1,oz2;
	int n=2;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			printf("(%d,%d):%2.1f\t",i+1,j+1,A[i*n+j]);
			A[j*n+i]=A[i*n+j];
		}
		printf("\n");
	}
	teta=(A[3]-A[0])/(2*A[1]);
	printf("teta=%3.2f\n",teta);
	t1=-teta+sqrt(teta*teta+1);
	t2=-teta-sqrt(teta*teta+1);
	printf("t1=%3.2f, t2=%3.2f\n",t1,t2);
	if(fabs(t1)<fabs(t2))
		t=t1;
	else
		t=t2;
	c=1.0/sqrt(1.0+t*t);
	s=c*t;
	oz1=c*c*A[0]-2.0*c*s*A[1]+s*s*A[3];
	oz2=c*c*A[3]+2.0*c*s*A[1]+s*s*A[1];
	printf("c=%3.2f, s=%3.2f\n",c,s);
	printf("ozdeger1=%2.1f\t ozdeger2=%2.1f\n",oz1,oz2);
	printf("ozvektor:\n");
	printf("(1,1):%2.1f\t(1.2):%2.1f\n",c,-s);
	printf("(2,1):%2.1f\t(2,2):%2.1f\n",s,c);
	return 0;
}

