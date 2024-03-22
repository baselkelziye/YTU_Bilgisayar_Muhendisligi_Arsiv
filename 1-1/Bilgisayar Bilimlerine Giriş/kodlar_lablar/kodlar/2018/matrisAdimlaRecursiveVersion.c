#include <stdio.h>

int yolBilgisiGetir(char (*)[10],int, int, int , int *);
int adimAt(char (*)[10],int , int, int,int *, int *,int *);

int main()
{
	char yollar[8][10]=			{	{0, 0, 0, 0, 0, 2, 0, 0, 2, 2},
									{1, 0, 0, 1, 2, 0, 2, 2, 0, 0},
									{0, 1, 1, 2, 1, 0, 0, 1, 1, 1},
									{0, 0, 0, 2, 0, 1, 1, 0, 0, 0},
									{2, 2, 0, 2, 0, 0, 0, 0, 0, 0},
									{0, 0, 2, 0, 3, 0, 0, 0, 0, 0},
									{3, 3, 0, 3, 0, 3, 0, 0, 0, 0},
									{0, 0, 3, 0, 0, 0, 3, 0, 0, 0}};
						
	int sonuc,uzunluk=0,max=0,i;
	char yolId;
	for (i=0;i<8;i++)
	{
		if (yollar[i][0]!=0)
		{
			sonuc=yolBilgisiGetir(yollar,8,10,i,&uzunluk);
			
			if ((sonuc!=0) && (uzunluk>max)) 
			{
				max=uzunluk;
				yolId=sonuc;	
			}
		}
	}
		printf("\nEn uzun yol no:%d uzunlugu:%d\n",yolId,max);
		
	
}

int yolBilgisiGetir(char yollar[][10],int boy, int en, int baslangic, int *uzunluk)
{
	int i=baslangic, j=0, id=yollar[baslangic][0], adimVarmi;
	(*uzunluk)=1;
    adimAt(yollar,boy,en,id,&i, &j, uzunluk);
	if (j==(en-1)) return id;
	return 0;
}


int adimAt(char yollar[][10],int boy, int en, int id,int *i, int *j,int *uzunluk)
{
	
	printf("id:%d i:%d j:%d uzunluk:%d\n",id,(*i),(*j),(*uzunluk));
	yollar[(*i)][(*j)]=0;
	if (((*i)-1>=0) 	&&  (yollar[(*i)-1][(*j)]==id))				{ (*i)--;  (*uzunluk)++; adimAt(yollar,boy,en,id,i, j, uzunluk);}
	if (((*i)+1<=boy) 	&&  (yollar[(*i)+1][(*j)]==id))				{ (*i)++;  (*uzunluk)++; adimAt(yollar,boy,en,id,i, j, uzunluk);}
	if (((*j)+1<=en) 	&&  (yollar[(*i)][(*j)+1]==id))				{ (*j)++;  (*uzunluk)++; adimAt(yollar,boy,en,id,i, j, uzunluk);}
	if (((*i)-1>=0) 	&& ((*j)+1<=en) &&  (yollar[(*i)-1][(*j)+1]==id))	{ (*i)--; (*j)++; (*uzunluk)++; adimAt(yollar,boy,en,id,i, j, uzunluk);}
	if (((*i)+1<=boy) 	&& ((*j)+1<=en) &&  (yollar[(*i)+1][(*j)+1]==id))	{ (*i)++; (*j)++; (*uzunluk)++; adimAt(yollar,boy,en,id,i, j, uzunluk);}
	return 0;
}

