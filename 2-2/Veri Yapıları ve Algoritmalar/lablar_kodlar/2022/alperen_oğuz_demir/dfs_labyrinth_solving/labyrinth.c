#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void printLabyrinth(int **a, int point, int bi, int bj, int ci, int cj, int mx, int my){
	int i,j;
	static int ok=0;
	ok++;
	usleep(500000);
	printf("Guncel Puan = %d\n",point);
	printf("%d. Adim\n",ok);
	for(i=0;i<mx;i++){
		for(j=0;j<my;j++){
			if(a[i][j]==0 && i%2==0 && j%2==0){
				printf("+");
			}
			else if(a[i][j]==0 && i%2==1 && j%2==0){
				printf("|");
			}
			else if(a[i][j]==0 && i%2==0 && j%2==1){
				printf("-");
			}
			else if(a[i][j]==4){
				printf("c");
			}
			else if(a[i][j]==5){
				if(i==bi && j==bj){
					printf("b");
				}
				else{
					printf("*");
				}
			}
			else if(a[i][j]==2){
				printf("O");
			}
			else{
				printf(" ");
			}		
		}
		printf("\n");
	}
	
}




void DFS(int **a, int bi, int bj, int ci, int cj, int mx, int my, int ti, int tj){  // hareket önceliði up left right down
	static int point=0, end=0;//baþlangýç ve çýkýþ noktasýnýn printi için
	printLabyrinth(a,point,bi,bj,ci,cj,mx,my);
	printf("\n\n");
	if(ti==ci && tj==cj){
		printf(" Labirentin sonuna gelindi. Puan : %d",point);
		return;
	}
	if(a[ti-1][tj]==1 && a[ti-2][tj]<5){  // duvar ya da  önceden ilerlenmiþ yol olmadýðýnýn kontrolleri
		end=0;
		if(a[ti-2][tj]==2){
			point+=10;
		}
		a[ti-2][tj]=5;
		DFS(a,bi,bj,ci,cj,mx,my,ti-2,tj);
	}
	else if(a[ti][tj-1]==1 && a[ti][tj-2]<5){
		end=0;
		if(a[ti][tj-2]==2){
			point+=10;
		}
		a[ti][tj-2]=5;
		DFS(a,bi,bj,ci,cj,mx,my,ti,tj-2);
	}
	else if((a[ti][tj+1]==1) && a[ti][tj+2]<5){
		end=0;
		if(a[ti][tj+2]==2){
			point+=10;
		}
		a[ti][tj+2]=5;
		DFS(a,bi,bj,ci,cj,mx,my,ti,tj+2);
	}		
	else if((a[ti+1][tj]==1) && a[ti+2][tj]<5){
		end=0;
		if(a[ti+2][tj]==2){
			point+=10;
		}
		a[ti+2][tj]=5;
		DFS(a,bi,bj,ci,cj,mx,my,ti+2,tj);
	}								
	else{								//çýkmaz yola ulaþýldýðýnda geriye dönme algoritmasý
		a[ti][tj]++;					//çýkmaz yola tekrar girmesini engellemek için pathi backtracked pathe çevirdim.
		if(end==0){
			point-=5;
			printf("Cikmaz sona girildi.\n\n");
		}
		usleep(500000);
		end=1;
		if(a[ti-1][tj]==1 && a[ti-2][tj]==5 && ti>1){
			DFS(a,bi,bj,ci,cj,mx,my,ti-2,tj);
		}
		else if(a[ti][tj+1]==1 && a[ti][tj+2]==5 && tj<41){
			DFS(a,bi,bj,ci,cj,mx,my,ti,tj+2);
		}
		else if(a[ti+1][tj]==1 && a[ti+2][tj]==5 && ti<29){
			DFS(a,bi,bj,ci,cj,mx,my,ti+2,tj);
		}
		else if(a[ti][tj-1]==1 && a[ti][tj-2]==5 && tj>1){
			DFS(a,bi,bj,ci,cj,mx,my,ti,tj-2);
		}
	} 
	
}
void readFile(int **a, int mx, int my){   //   duvarlar 0   açýk yol 1     elma 2       baþlangýç 3      çýkýþ 4    path "*"   5   backtracked path 6
	int i,j,bi,bj,ci,cj;
	char c;
	FILE *fp;
	fp=fopen("maze.txt","r");
	
	for(i=0;i<mx;i++){
		for(j=0;j<my;j++){
			c=fgetc(fp);
			if(c=='+' || c=='-' || c=='|'){
				a[i][j]=0;
			}
			else if(c=='O'){
				a[i][j]=2;
			}
			else if(c=='b'){
				a[i][j]=3;
				bi=i;
				bj=j;
			}
			else if(c=='c'){
				a[i][j]=4;
				ci=i;
				cj=j;
			}
			else{
				a[i][j]=1;
			}
		}
		fgetc(fp);
	}
	fclose(fp);	
	a[bi][bj]=5;
	DFS(a,bi,bj,ci,cj,mx,my,bi,bj);
}

int main(){
	int mx=31,my=43,i;
	int **a;   		
	a=(int**)malloc(mx*sizeof(int*));
	for(i=0;i<my;i++){
		a[i]=(int*)malloc(my*sizeof(int));
	}
	printf("Alperen Oguz Demir DFS Labirenti\n");
	readFile(a,mx,my);
	return 0;
}
