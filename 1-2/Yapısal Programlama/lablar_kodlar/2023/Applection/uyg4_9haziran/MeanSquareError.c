#include <stdio.h> 

float meanSquare(int size, float P[][2], float m, float n){
	int i;
	float pre_y, error, sum=0;
	
	for(i=0;i<size;i++){
    	pre_y=m*P[i][0]+n; //y'=mx+n
    	error=pre_y-P[i][1]; //y'-y (tahmin edilen - gercek)
    	sum=sum+error*error;
	}
	return(sum/size);
}

void getPoints(int size, float P[][2])
{
	int i,j;
	printf("%d adet 2 boyutlu (x,y) nokta giriniz:\n", size);
    for(i=0;i<size;i++)
    	for(j=0;j<2;j++)
    		scanf("%f", &P[i][j]);
}

int main()
{ 
	float P[10][2];
    int i, j, size; 
    float m, n, MSE;
       
    printf("Nokta sayisi:");
    scanf("%d",&size);
    
    getPoints(size, P);
    
    printf("y=mx+n dogrusunun m  ve n degerlerini giriniz:");
    scanf("%f %f",&m,&n);
   	
	MSE=meanSquare(size,P,m,n);
      
    printf("Ortalama karesel hata = %f", MSE);
    return 0;
} 

