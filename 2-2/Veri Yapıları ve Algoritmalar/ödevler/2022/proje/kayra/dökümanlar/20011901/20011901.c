#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Labirentte komşuluk kontrolünde sıkıntı oluşmasın diye
int isSafe(int** maze, int x, int y,int N,int M)
{
    if (x >= 0 && x < N && y >= 0 && y < M)
        return 1;
    return 0;
}
//Her sayı bir karakteri temsil ediyor. Bu da temsil tablosu
void mySwitchCase(int i){
	switch(i){
		case 1:
			printf("   ");
			break;
		case 0:
			printf(" - ");
			break;
		case -11:
			printf("*b ");
			break;	
		case 2:
			printf(" O ");
			break;
		case -1:
			printf(" b ");
			break;
		case -2:
			printf(" c ");
			break;
		case -3:
			printf(" + ");
			break;
		case 3:
			printf(" * ");
			break;
		case 7:
			printf("*O ");
			break;
		case -21:
			printf("*c ");
			break;
		case 12:
			printf("   ");
			break;
		case 1237:
			printf(" O ");
			break;
		default:
			printf(" | ");
	}
}
//Labirenti yazdırmak için.
void matrisPrint(int ** matris,  int n,int m,int puan){
	int i,j;
	printf("Puan: ---> %d\n",puan);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(matris[i][j]==0){
				if(j+1!=n){
					if(matris[i][j+1]==-3 || matris[i][j+1]==0){
							mySwitchCase(0);
					}
					else{
							mySwitchCase(21);
					}
				}
				else{
						mySwitchCase(121);
				}
			}
			else{
				mySwitchCase(matris[i][j]);
			}
		}
		printf("\n");
	}
	
}
//Labirent gösteriminin takip edilebilir olması için.
void delay(float number_of_seconds)
{
    int milli_seconds = (int)1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
//Bu fonksiyon rekürsif şekilde, eğer kendisi geçilebilirse komşularını çağırıyor.
//Verilen başlangıçtan çıkışa ulaşılamıyorsa myFlag'i güncellemiyor. Bu şekilde çıkışın ulaşılabilirliği denetleniyor.
void solveMazeUtil(int **maze, int x, int y,int N,int M,int * puan,int *myFlag)
{
	delay(0.1);
	int i=0,j=0;
			matrisPrint(maze,N,M,*puan);
        if (maze[x][y] == 1 || maze[x][y]==2 || maze[x][y]==-1){
        
        	if(maze[x][y]==2){
        		*puan+=10;
			}
			if(maze[x][y]==1)
				maze[x][y]=3;
			else if(maze[x][y]==2)
				maze[x][y]=7;
			else{
				maze[x][y]=-11;
			}
			if(*myFlag==0){	
				solveMazeUtil(maze,x+1,y,N,M,puan,myFlag);
			}
        	if(*myFlag==0){
        		solveMazeUtil(maze,x,y+1,N,M,puan,myFlag);
        		
				
				}
			if(*myFlag==0){
				solveMazeUtil(maze,x-1,y,N,M,puan,myFlag);
			
					
					
				}
			if(*myFlag==0){	
					
					solveMazeUtil(maze,x,y-1,N,M,puan,myFlag);	
								
			}
			if(maze[x][y]==3 && *myFlag==0){
				maze[x][y]=12;
				matrisPrint(maze,N,M,*puan);
			}
				
			else if(maze[x][y]==7 && *myFlag==0)
				maze[x][y]=1237;}
		else{
			if(maze[x][y]==0){
				matrisPrint(maze,N,M,*puan);
				*puan-=5;
			}
			else{
				if(maze[x][y]==-2){
					maze[x][y]=-21;
					*myFlag=-1;	
				}
				
			}
		}
}
//Bu fonksiyon en az bir başlangıç ve biriş var mı kontrolü yapıyor. Eğer yoksa solveMazeUtil'i çağırıyor.
//Aynı zamanda başlangıç indislerini bulup gönderiyor.
void solveMaze(int ** maze,int N,int M,int * puan,int * myFlag)
{
    int i,j;
    i=0;j=0;
    int flag=0;
        while(flag==0 && i<N){
    	while(flag==0 && j<M){
    		if(maze[i][j]==-2){
    			flag=1;
			}	
    		j++;
		}
		j=0;
		i++;}
	if(flag!=0){
		
	flag=0;
	i=0;j=0;
    while(flag==0 && i<N){
    	while(flag==0 && j<M){
    		if(maze[i][j]==-1){
    			solveMazeUtil(maze,i,j,N,M,puan,myFlag);
    			flag=1;
			}
    			
    		j++;
		}
		j=0;
		i++;}}
}
int main()
{
	int N,M,puan=0,i,j,yolVarMi=0,degisiklik=0;
	FILE * fp;
    int** maze;
    if((fp=fopen("maze1.txt","r"))!=NULL){
    fscanf(fp,"%d %d\n",&N,&M);
    maze=(int**)malloc(N*sizeof(int*));
    for(i=0;i<N;i++){
    	maze[i]=(int*)malloc(M*sizeof(int));
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		fscanf(fp,"%d\n",&maze[i][j]);
		}
		fscanf(fp,"\n");
	}
	fclose(fp);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		if(maze[i][j]==0){
		maze[i][j]=1;
		}
		else{
		 if(maze[i][j]==1){
			maze[i][j]=0;	
		}}
		
		}
		
	}
   	solveMaze(maze,N,M,&puan,&yolVarMi);
   	matrisPrint(maze,N,M,puan);
   	if(yolVarMi==0)
   		printf("Yol bulunamadi... Son durumdaki puan ----> %d\n",puan);
   	else
   		printf("Yol bulundu... Son durumdaki puan ----> %d\n",puan);}
   	else
   		printf("Dosya bulunamadi!!!\n");
    return 0;
}
