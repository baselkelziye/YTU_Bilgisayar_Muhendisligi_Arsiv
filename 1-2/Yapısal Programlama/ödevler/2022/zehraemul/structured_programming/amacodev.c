#include<stdio.h>
#include<math.h>

int main(){
	
	
	int r,c=8,i,j,result,fDg,result1,result2,result3;
	int b[20][20],d[20];
	
	printf("please enter number of the rows: ");
	scanf("%d",&r);
	
	
	printf("please enter elements of the matrix:\n ");
	for(i=0;i<r;++i)
	
		for(j=0;j<8;++j){
			printf("enter [%d][%d] element of the matrix: ",i,j);
			scanf("%d",&b[i][j]);
			
		}
		

	for(i=0;i<r;i++){
		result=0;
		result1=0;
		for(j=0;j<8;j++){
			if(b[i][0]==1){
			
			
			
				fDg=(b[i][0]*pow(2,7)*(-1));
				result=result+(b[i][j+1]*pow(2,6-j));
				result2=result+fDg;
				d[i]=result2;
			
			
		}
	
				else{
				
					result1=result1+(b[i][j]*pow(2,7-j));
					d[i]=result1;
		
				
		}
}

}
	printf("decimal number system equivalents of the rows of the matrix");
        for(i=0;i<r;i++){
			printf(" %d ",d[i]);
}

	return 0;
}
