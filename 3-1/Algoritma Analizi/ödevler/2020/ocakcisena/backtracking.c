#include<stdio.h>
#include<stdlib.h>
int backTracking(int **,int *,int ,int , int );
void yazdir(int **,int );
int sameColumn(int **,int , int ,int );
int sameRow(int **,int , int ,int );

int main(){
	int i,j,n,renkler[8]; //i,j dongu degiskenleri, n matrisin boyutu, renkler renk dizisi
	printf("Matrisin boyutunu giriniz: ");
	scanf("%d",&n);
	printf("\nKirmizi-1,Turuncu-2,Sari-3,Yesil-4,Mavi-5,Mor-6,Beyaz-7,Kahverengi-8\n");
	printf("%d tane FARKLI renk giriniz. \n",n);
	for(i=0;i<n;i++){
		printf("	%d. renk: ",i+1);
		scanf("%d",&renkler[i]);	//renklerin int karsiliklarini kullanicidan aliyoruz.
	}
	
	int **matris=(int**)malloc(n*sizeof(int*));		//
	for(i=0;i<n;i++){								//
		matris[i]=(int*)malloc(n*sizeof(int));		//matris icin yer aciyoruz.
	}												//
	
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			matris[i][j]=0;		//matrisin elemanlarini sifir olarak belirliyoruz.
		}
	}
	int cagir=backTracking(matris,renkler,0,0,n);	//backtracking algoritmasini calistiriyoruz.
	yazdir(matris,n);		//matrisin son halini yazdiralim
	return 0;
}

int sameColumn(int **matrix,int x, int num,int n){	//matrisi, satirini, degeri ve matrisin boyutunu alýp o sutunda varsa 1 yoksa 0 dondurur
	int i;
	for(i=0;i<n;i++){
		if(matrix[x][i]==num){
			return 1;	//var
		}
	}
	return 0;	//yok
}

int sameRow(int **matrix,int y, int num,int n){	//matrisi, sutununu, degeri ve matrisin boyutunu alýp o satirda varsa 1 yoksa 0 dondurur
	int i;
	for(i=0;i<n;i++){
		if(matrix[i][y]==num){
			return 1;	//var
		}
	}
	return 0;	//yok
}

int backTracking(int **matrix,int *renkler,int x,int y, int n){	//backtracking algoritmasini uygulayan fonk
	int i=0;
	if(x==n-1&&y==n){ //matris dolmus mu
		return 1;
	}
	if(y==n){	//sutun sonuna gelmis mi
		y=0;	//sutunu sifirla
		x++;	//satir sonuna gelene kadar ilerle
	}
	for(i=0;i<n;i++){
		if(sameRow(matrix,y,renkler[i],n)!=1&&sameColumn(matrix,x,renkler[i],n)!=1){	//ayný satir ve sutunda yok ise
			matrix[x][y]=renkler[i];		//rengi matrise yaz
			if(backTracking(matrix,renkler,x,y+1,n)==1){	//backtracking recursive (sutundan kontrol)
				return 1;
			}	
		}
		matrix[x][y]=0;	//bosalt
	}
	return 0;
	
}
void yazdir(int **matrix,int n){	//matrisi ve eleman sayisini parametre alip, matrisin son halini ekrana yazdiran fonksiyon
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matrix[i][j]==1){		//1 ise kirmizi demistik
				printf("kirmizi    ");
			}
			else if(matrix[i][j]==2){	//2 ise turuncu demistik
				printf("turuncu    ");
			}
			else if(matrix[i][j]==3){	//3 ise sari demistik
				printf("sari    ");
			}
			else if(matrix[i][j]==4){	//4 ise yesil demistik
				printf("yesil    ");
			}
			else if(matrix[i][j]==5){	//5 ise mavi demistik
				printf("mavi    ");
			}
			else if(matrix[i][j]==6){	//6 ise mor demistik
				printf("mor    ");
			}
			else if(matrix[i][j]==7){	//7 ise beyaz demistik
				printf("beyaz    ");
			}
			else {
				printf("kahverengi ");	//baska ise kahve
			}
//			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
