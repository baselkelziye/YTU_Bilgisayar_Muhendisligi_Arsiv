//M Ali Bugday
//date started: 16.03.2022
//last modified: 29.03.2022

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define bos 1000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	int value;
	struct node* next;
	struct node* down;	 
}NODE;


NODE* initialize(int **matrix, int i, int j, int x, int y);
void display(NODE *last);
int randomNumber(int lower, int upper);
NODE* search(NODE* head);
int brutesearch(NODE* head, int aranan);
NODE* sil(NODE* head, int **matrix, int *x, int *y);
NODE* ekle(NODE* head, int **matrix, int *x, int *y);

int main() {
	int i, j, k, y, x, n, rows, ran_num, option,*dizi, **matrix;
	int rows_dizi[10] = {0};
	struct node *head,*temp;
	time_t t1;
	srand ( (unsigned) time (&t1));
	
	printf("Dizi uzunlugu giriniz:");
	scanf("%d",&n);
	
	int secim[n];
	for(i=0;i<n;i++){
		secim[i]=bos;
	}
	
	dizi = (int*)malloc(n*sizeof(int));
	
    for(i=0;i<n;i++){
    	printf("%d inci dizi elemanini giriniz:",i);
    	scanf("%d",&dizi[i]);
	}
	
	//finding how many rows are there
	i=0;
	rows=n;
	do{
		rows=rows/2;
		rows_dizi[i] = rows+1;//keeping every layout degree.
		i++;
	}while(rows!=0);
	rows=i+2;//bir arirma ozel katman
	matrix=(int**)malloc(rows*sizeof(int*));
	if(matrix == NULL)  {
		printf("coud not allocate memory...\n");
		exit(0);
	}
	
	//for head nodes incrementing n.
	n+=1;
	for(i=0;i<n;i++){
		matrix[i]=(int*)malloc(n*sizeof(int));
		if(matrix[i] == NULL)  {
			printf("coud not allocate memory...\n");
			exit(0);
		}
	}
	
	for (i=0;i<rows;i++){
		for (j=0;j<n;j++){
			matrix[i][j] = bos;		
		}
	}
	
	
	k=0;
	for (i=1;i<n;i++){
		matrix[rows-1][i]=dizi[i-1];
	}
	
	
	for (i=0;i<rows-1;i++){
		
		for(k=0;k<n-1;k++){
			secim[k]=bos;
		}
		
		for (j=0;j<rows_dizi[i];j++){
			
				
			do{
				ran_num = randomNumber(1, n-2);
				
			}while((dizi[ran_num]==bos) || (secim[ran_num]==dizi[ran_num]));
			
			secim[ran_num]=dizi[ran_num];
			
			
			matrix[rows-i-2][ran_num+1]=dizi[ran_num];
			
			
			/*
			do{
				//printf("flag6\n");
				ran_num = randomNumber(1, n-1);
				printf("i:%d\n",i);
				if(i!=0){
					printf("flag\n");
					if ((matrix[rows-i-1][ran_num]==bos)){
						printf("ileri2:%d\n",matrix[rows-i-2][ran_num]);
						ran_num = randomNumber(1, n-1);
						continue;
					}
				}
				printf("ileri:%d\n",matrix[rows-i-2][ran_num]);
				printf("geri:%d\n",matrix[rows-i-1][ran_num]);
			}while((matrix[rows-i-2][ran_num]==bos));
			printf("ran_num:%d\n",ran_num);
			
			matrix[rows-i-2][ran_num]=matrix[rows-i-1][ran_num];
			*/
		
		
		}
		for (k=0;k<n-1;k++){
			dizi[k]=secim[k];
		}
	}
    
	x=rows;
	y=n;
	
	head=initialize(matrix,0,0,x,y);
	
	
	do{
		printf("\n ******** MAIN MENU *********");
		printf("\n 1. Display ");
		printf("\n 2. Arama islemi");
		printf("\n 3. Cikarma islemi");
		printf("\n 4. Ekleme islemi");
		printf("\n 5. Cikis");
		printf("\n Secenek giriniz: ");
		scanf("%d", &option);		
		
		switch (option)
		{
	    	case 1:
	      		display(head);
	      		break;
	
	    	case 2:
	      		search(head);
	      		break;
			
			case 3:
	      		head=sil(head, matrix, &x, &y);
	      		break;
	      		
	      	case 4:
	      		head=ekle(head, matrix, &x, &y);
	      		break;
		}
	}while(option!=5);
	
		
	return 0;
}//end of main func.


NODE* initialize(int **matrix, int i, int j, int x, int y)
{
	struct node* temp;
	
	temp = (NODE*)malloc(sizeof(struct node));
	
	if (temp == NULL){
		printf("coudn't allocate memory");
		exit(0);
	} 
	
	//case where recursive'll stop
	if ((i>x-1) || (j>y-1)){
		return NULL;
	}
	
	//if temp->value == bos return ifadesi yok else ifadesinde var. Bir de if icersinde temp->nextler de var
	
	temp->value=matrix[i][j];
	temp->next=initialize(matrix, i, j+1, x, y);
	temp->down=initialize(matrix, i+1, j, x, y);
	
	return temp;
	
}//end of initialze function

void display(NODE *last)
{
	struct node *right_side, *down_side;
	
	down_side = last;
	
	//loop untill down side null
	while(down_side != NULL){
		right_side=down_side;
		
		//loop until right side is null
		while(right_side != NULL)
		{
			if(right_side->value==bos){
				printf("._");
			}
			else{
				printf("%d_",right_side->value);	
			}
			
			right_side = right_side->next;	
		
		}
		printf("\n");
		right_side=down_side;
		while(right_side != NULL)
		{	
			if(down_side->down!=NULL){
				printf("| ");
			}
			right_side = right_side->next;	
		}
		printf("\n");
		down_side=down_side->down;
		
	}
	
		
}//end of display function

NODE* sil(NODE* head, int **matrix, int *x, int *y){
	int i, j, m, n, aranan, flag=0, sira, tmp, kontrol;
	struct node *ds, *rs, *min, *temp;
	n=*x;
	m=*y;
	
	temp=head;

	printf("silinecek olan sayiyi giriniz:");
	scanf("%d",&aranan);
	
	
	kontrol=brutesearch(head, aranan);
	if(kontrol==0){
		printf("silinecek terim dizide bulunmuyor");
		return head;
	}
	
	
	for(i=0;i<m;i++){
		if(matrix[n-1][i] == aranan){
			sira = i;
		}
	}

	for(i=0;i<n;i++){
		matrix[i][sira]=bos;
	}
	
	for(i=0;i<n;i++){
		tmp=matrix[i][sira];
		matrix[i][sira] = matrix[i][m-1];
	}
	
	i=sira;
	
	while(i!=m-1){
		j=0;
		while(j<n){
			tmp=matrix[j][i];
			matrix[j][i]=matrix[j][i+1];
			matrix[j][i+1]=tmp;
			j++;
		}
		i++;
	}
	
	
	m-=1;
	*y=m;
	
	temp = initialize(matrix,0,0,n,m);
	
	return temp;
}

NODE* ekle(NODE* head, int **matrix, int *x, int *y){
	int i ,j ,n ,m ,dizi[*y-1], eklenecek, derece, **matrix2, tmp, kontrol, flag2=0, sinir;
	struct node *temp;
	
	n=*x;
	m=*y;
	
	printf("eklenecek sayiyi giriniz:");
	scanf("%d",&eklenecek);
	
	kontrol=brutesearch(head, eklenecek);
	if(kontrol==1){
		printf("\nBu sayi zaten dizide bulunuyor");
		return head;
	}
	
	for(i=1;i<m;i++){
		dizi[i-1]=matrix[*x-1][i];	
	}
	
	printf("eklenecek sayiyinin derecesini giriniz:");
	scanf("%d",&derece); 
	
	
	
	if(n < derece){
		matrix2 = (int**)malloc(derece*sizeof(int*));
		if(matrix2 == NULL){
			printf("coud not allocate memory...\n");
			exit(0);
		}
		for(i=0;i<derece;i++){
			matrix2[i] = (int*)malloc((m+1)*sizeof(int));
			if(matrix2[i] == NULL)  {
				printf("coud not allocate memory...\n");
				exit(0);
			}
		}
		
		for(i=0;i<derece;i++){
			for(j=0;j<m+1;j++){
				matrix2[i][j]=bos;
			}
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				matrix2[i+derece-n][j]=matrix[i][j];
			}
		}
		
		n=derece;
		m+=1;
		/*
		for(i=0;i<derece-(*x);i++){
			for(j=0;j<m;j++){
				matrix2[i][j]=bos;
			}
		}
		*/
		for(i=1;i<n;i++){
			matrix2[i][m-1]=eklenecek;
		}
		flag2=1;
	}
	else{
		matrix2 = (int**)malloc((n)*sizeof(int*));
		if(matrix2 == NULL)  {
			printf("coud not allocate memory...\n");
			exit(0);
		}
		for(i=0;i<n;i++){
			matrix2[i] = (int*)malloc((m+1)*sizeof(int));
			if(matrix2[i] == NULL)  {
				printf("coud not allocate memory...\n");
				exit(0);
			}
		}
		m+=1;
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				matrix2[i][j]=matrix[i][j];
			}
		}
		
		for(i=0;i<n-derece;i++){
			matrix2[i][m-1]=bos;
		}
		for(i=0;derece>i;i++){
			matrix2[n-i-1][m-1]=eklenecek;
		}
		
	}
	
	
	i=*y;
	
	if(flag2==1){
		sinir=*x;
	}else{
		sinir=*x-1;
	}
	
	while((matrix2[*x-1][i] < matrix[*x-1][i-1]) && (i!=1)){
		j=0;
		while(j<=sinir){
			tmp=matrix2[j][i];
			matrix2[j][i]=matrix2[j][i-1];
			matrix2[j][i-1]=tmp;
			j++;
		}
		i--;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matrix[i][j]=matrix2[i][j];
		}
	} 
	
	*x=n;
	*y=m;
	
	temp=initialize(matrix, 0, 0, *x, *y);
	
	return temp;
	
	
}


NODE* search(NODE* head){
	int i, j, aranan, counter, flag=0;
	struct node *ds, *rs, *min;
	
	printf("Aranilan sayiyi giriniz:");
	scanf("%d",&aranan);
	
	
	
	
	ds=head;
	
	//finding first node 
	while(ds!=NULL){
		rs=ds;
		
		while(rs!=NULL){
			if(rs->value != bos){
				if(flag==0){
					if(rs->value <= aranan){
						min=rs;
						flag=1;
					}
				}
			}		
			rs = rs->next;
		}
		
		ds = ds->down;
	}
	
	//ilk baktigimiz noda eþit durumu
	if(min->value==aranan){
		printf("\nAranan eleman dizide bulunuyor.\n");
		return min;
	}
	
	if(flag == 0){
		printf("\naranan eleman dizide bulunamadi!\n");
		return head;
	}
	
	
	
	ds=min;
	flag=0;//flag aranan sayinin bulunup bulunmadigini kontrol edecek
	while(ds!=NULL){
		rs=ds;
		
		while(rs!=NULL){
			if(rs->value != bos){
				if(flag==0){
					if(rs->value == aranan){
						printf("%d ile aranan sayi esit dizi aranan sayiyi icerir.\n",rs->value);
						flag=1;
						min=rs;
						counter++;
					}
					else if(rs->value < aranan){//and ifadesi
						if(rs->value != ds->value){
							printf("%d aranan sayidan kücük yeni min artik %d\n",rs->value,rs->value);
							counter++;
						}
						ds=rs;
					}
					else{
						printf("%d degerli node aranan degerden buyuktur\n",rs->value);
						counter++;
					}
				}
			}		
			rs = rs->next;
		}
		
		ds = ds->down;
	}
	
	printf("toplam yapilan karsilastirma:%d\n",counter);
	
	if(flag==0){
		printf("\naranan eleman bulunamamistir.\n");
		return head;
	}
	else{
		printf("\nAranan eleman dizide bulunuyor.\n");
		return min;
	}
	
}//end of search func.


int brutesearch(NODE* head, int aranan){
	int flag=0;
	struct node *ds, *rs, *min;
	
	ds=head;
	
	//finding first node 
	while(ds!=NULL){
		rs=ds;
		
		while(rs!=NULL){
			if(rs->value == aranan){
				flag=1;
			}		
			rs = rs->next;
		}
		
		ds = ds->down;
	}
	
	if(flag==1){
		return 1;
	}else{
		return 0;
	}
}


int randomNumber(int lower, int upper)
{
    int i;
    
    int num = (rand() %(upper - lower + 1)) + lower;
    
    return num;
}//end of random number func.
