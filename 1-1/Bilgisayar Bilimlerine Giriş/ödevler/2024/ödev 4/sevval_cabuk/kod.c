#include <stdio.h>

int main(){
    int i, j, k, roadNum, noRoad;
    int n, m, tmp;
    int count=0;

    printf("\t\tENTER YOUR MATRIX SIZE IN NXM FORMAT:\n");
    scanf("%dx%d",&n,&m);
    int matrix[n][m];

    printf("\t\tENTER YOUR MATRIX:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("\n\n");
    for(i=0;i<n;i++){
        while(matrix[i][0]!=0){
            roadNum=matrix[i][0];
            tmp=i;
            count=1;
            j=0;
            noRoad=0;
            while(j<m-1){ //not controlling last column to not get out of the edges
                if(j>0 && matrix[i][j] == matrix[i][j-1]){  // left control
                    matrix[i][j] = 0;
                    j--;
                    count++;
                } else if(j<m-1 && matrix[i][j] == matrix[i][j+1]){ // right control
                    matrix[i][j] = 0;
                    j++;
                    count++;
                } else if(i>0 && matrix[i][j] == matrix[i-1][j]){ // top control
                    matrix[i][j] = 0;
                    i--;
                    count++;
                } else if(i<n-1 && matrix[i][j] == matrix[i+1][j]){ // bottom control
                    matrix[i][j] = 0;
                    i++;
                    count++;
                } else if(i<n-1 && j<m-1 && matrix[i][j] == matrix[i+1][j+1]){ // bottom right control
                    matrix[i][j] = 0;
                    i++;
                    j++;
                    count++;
                } else if(i>0 && j>0 && matrix[i][j] == matrix[i-1][j-1]){ // left top control
                    matrix[i][j] = 0;
                    i--;
                    j--;
                    count++;
                } else if(i>0 && j<m-1 && matrix[i][j] == matrix[i-1][j+1]){ // right top control
                    matrix[i][j] = 0;
                    i--;
                    j++;
                    count++;
                } else if(i<n-1 && j>0 && matrix[i][j] == matrix[i+1][j-1]){ // left bottom control
                    matrix[i][j] = 0;
                    i++;
                    j--;
                    count++;
                } else{ // to get out of the while loop
                    j = m;
                    noRoad = 1;
                }
            }
            for(k=0;k<m;k++){
                if(matrix[k][m-1] == roadNum && noRoad == 0){
                    matrix[k][m-1] =0;
                    printf("Road --> %d Lenght --> %d\n", roadNum, count);
                }
            } // controlling last column
            i=tmp;
        }
    }
    return 0;
} 