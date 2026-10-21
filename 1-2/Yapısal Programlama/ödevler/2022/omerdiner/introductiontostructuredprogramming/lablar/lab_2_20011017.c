#include <stdio.h>
#define SIZE 100

int main(){
	 
	 int i,j,satir,sutun;
	 int rota[SIZE],matris[SIZE][SIZE];
	 int kontrol=1,k=0;
	
	 
	 printf("Satir sayisini giriniz:");
	 scanf("%d",&satir);
	 printf("Sutun sayisini giriniz:");
	 scanf("%d",&sutun);
	
	
	for(i=0;i<satir;i++){
		for(j=0;j<sutun;j++){
			printf("[%d %d] indisli eleman:",i,j);
			scanf("%d",&matris[i][j]);
		}
	}
	
	
	if(matris[0][0]==1){
		i=0;
		j=0;
	}else if(matris[0][1]==1){
		rota[0]=1;
		k++;
		i=0;
		j=1;
	}else if(matris[1][0]==1){
		i=1;
		j=0;
		rota[0]=2;
		k++;
	}
    
    		
    		while((i<satir&&j<sutun&&(matris[i][j+1]==1||matris[i+1][j]==1))){
    			
    			if(matris[i+1][j]==1){
    				i=i+1;
    				rota[k]=2;
    				k++;
    				kontrol=0;
				}else if(matris[i][j+1]==1){
					j=j+1;
					rota[k]=1;
					k++;
					kontrol=0;
				}
			}
    		
		if(kontrol==0){
				for(i=0;i<k;i++){
		          	printf("%d ",rota[i]);
		}
		}else{
			printf("ROTA YOK");
		}
	
		
	
	return 0;
}
