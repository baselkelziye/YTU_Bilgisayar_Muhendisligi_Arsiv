#include <stdio.h>
#include <math.h>

float greg(float [][9],float, float , float , float , int );
float carpim(float, float, float, int);
int faktoriyel(int);

float greg(float xt[10][9], float y, float x, float x0, float h, int n){
	int i,j;
	float res=0;
	res = y;
	for(i=0;i<n;i++){
		res += (xt[i][0]/faktoriyel(i+1))*carpim(x,x0,h,i)/pow(h,i+1);		
	}
	return res;
}


int faktoriyel(int n){
	int i,res=1;
	if(n==0){
		res=1;
	}else{
		for(i=n;i>0;i--){
			res=res*i;
		}
	}
	
	return res;
}


float carpim(float x, float x0, float h, int n){//x -x0 -h çarpýmlarý
	int i;
	float res=1;
	for(i=0;i<=n;i++){
		res *= (x-x0-h*i);
	}
	return res;
}


int main(){
	int i,j,n,count=0;
	float h,x,res,xler[10],yler[10],xt[10][9];
	printf(" Gregory Newton Enterpolasyon Metodu \n\n");
	printf("\tGirilecek (x,y) ikilisi sayisi = ");scanf("%d",&n);
	for(i=0;i<n;i++){//x deðerlerinin artýþ miktarýnýn sabit olduðunu kabul ediyorum
		printf("\n %d. (x,y) degerleri",i+1);
		printf("\n\t x = ");scanf("%f",&xler[i]);
		printf("\t y = ");scanf("%f",&yler[i]);
	}
	h = xler[1]-xler[0];
	printf("\n F(x) fonksiyonunda cevabi bulumak istenen x degeri = ");scanf("%f",&x);
	//F0 türevlerini buluyorum
	for(i=0;i<n-1;i++){
			xt[count][i]=yler[i+1] - yler[i];
		}count++;
	for(j=n;j>0;j--){
		for(i=0;i<j-2;i++){
			xt[count][i]=xt[count-1][i+1] - xt[count-1][i];		
		}count++;
	}
	res = greg(xt,yler[0],x,xler[0],h,n);
	printf("\n\n\t F(%.2f) = %f ",x,res);
	return 1;
}

