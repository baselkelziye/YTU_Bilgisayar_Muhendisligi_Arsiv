/* Program Yay sabiti k olan yaya baðlý kütlesi m olam ve konumundan A kadar çekilmis  Bir cismin hareketinin  Basit moleküler dinemik Sim. yöntemiyle NVT ist. topluluðu için  zamana baðluÇözümünü yapmaktadýr.
Program Linux/unix iþletim sistemlerinde terminalde datalarýn grafiklerini
gnuplot grafik programýi ile cizmektedir.
   Çýktýlar: koordinat-> MDyay.out, Enerjiler : MDEyay.out
                         "Önder EYECÝOÐLU 01.04.2009"
   */

#include <stdio.h>
#include <math.h>

int main(){
	int i,MDStp,n;
	double k=0.5;
	double m,A, dt,t,T;
	double x[1000],V[1000],a[1000], F[1000], U[1000], K[1000], E[1000];
	double beta,kb;
	m=2.;
	kb=pow(1.33,-23);
	MDStp=500;
	T=300.;
	n=1;
	A=1.;
	dt=0.1;
	x[0]=A;
	V[0]=1.;
	a[0]=0.;
	i=0;
	FILE * fp;
	  fp = fopen ("MDyay.out","w");
	FILE * fp1;
	fp1=fopen("MDEyay.out","w");
 //	if (fp!=NULL)
 //	{
//  		fputs ("fopen example",fp);
// 		fclose (fp);
// 	}
	while(i<MDStp){
		x[i+1]=x[i]+V[i]*dt+a[i]*(dt*dt);
		F[i+1]=-k*x[i+1];
                a[i+1]=F[i+1]/m;
		V[i+1]=V[i]+0.5*dt*(a[i]+a[i+1]);
		U[i]=-0.5*k*(x[i]*x[i]);
		K[i]=0.5*m*(V[i]*V[i]);
		beta=sqrt(3*kb*T/K[i]);
		V[i]=beta*V[i];
		K[i]=0.5*m*(V[i]*V[i]);
		E[i]=U[i]+K[i];
	fprintf( fp,"%3.1f\t%4.3f\t%4.3f\t%4.3f\n",i*dt,x[i],V[i],a[i]);
	fprintf(fp1,"%3d\t%5.4f\t%5.4f\t%5.4f\n",i,U[i],K[i],E[i]);
	 printf("%3.1f\t%4.3f\t%4.3f\t%4.3f\n",i*dt,x[i],V[i],a[i]);
		i++;
	}
	FILE *pipe = popen("gnuplot -persist","w");
   fprintf(pipe, "plot 'MDEyay.out' 1:3 w l\n");
	fclose(fp);
	fclose(fp1);
	
return 0;
}
