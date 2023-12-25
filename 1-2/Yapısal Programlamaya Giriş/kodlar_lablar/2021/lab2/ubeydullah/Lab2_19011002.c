#include<stdio.h>


int main(){
	int mtr[20][20],smtr[20][20],n,m,i,j,ssat[20],ssut[20],s=0;
	int seyrekmtr[20][20],seyreksat[20],seyreksut[20],seyreksatmax,seyreksutmax,seyrekeleman[20],esayisi,bitis=1,secim;
	
while(bitis==1){
	
	printf("Hos Geldiniz...\n[1]-Seyrek matristen sikistirilmis matrise\n[2]-Sikistirilmis matristen seyrek matrise\n[3]-Cikis\n");
	scanf("%d",&secim);

if(secim==1)
{
	printf("matrisin 1-satir 2-sutun sayisini giriniz.\n");
	scanf("%d",&n);
	scanf("%d",&m);	
	printf("\nmatrisi giriniz\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("[%d][%d] elemanini giriniz",i,j);
			scanf("%d",&mtr[i][j]);
			if(mtr[i][j]!=0){
				ssat[s]=i;
				ssut[s]=j;
				s+=1;
			}
		}
	}
	
	
	//sýkýþtýrýlmýþ
	for(i=0;i<s;i++){
		smtr[i][0]=ssat[i];
		smtr[i][1]=ssut[i];
		smtr[i][2]=mtr[ssat[i]][ssut[i]];
	}
	
	
	for(i=0;i<s;i++){
		for(j=0;j<3;j++){
			printf("%d\t",smtr[i][j]);
			
		}
		printf("\n");
	}
}
	
	

	//seyrek
if(secim==2){

	printf("Matriste kac tane sifirdan farkli eleman var?\n");
	scanf("%d",&esayisi);
	for(i=0;i<esayisi;i++){
		printf("%d. eleman icin satir,sutun ve degeri giriniz.",i+1);
		scanf("%d",&seyreksat[i]);
		if(seyreksat[i]>seyreksatmax){
			seyreksatmax=seyreksat[i];
		}
		scanf("%d",&seyreksut[i]);
		if(seyreksut[i]>seyreksutmax){
			seyreksutmax=seyreksut[i];
		}
		scanf("%d",&seyrekeleman[i]);
	}
	
	
	for(i=0;i<=seyreksatmax;i++){
		for(j=0;j<=seyreksutmax;j++){
			seyrekmtr[i][j]=0;
		}
	}
	
	printf("Sikistirilmis Matris\n");
	for(i=0;i<esayisi;i++){
		printf("%d\t",seyreksat[i]);
		printf("%d\t",seyreksut[i]);
		printf("%d\n",seyrekeleman[i]);
		//seyrek matristeki deðerler yerine yazýlýyor
		seyrekmtr[seyreksat[i]][seyreksut[i]]=seyrekeleman[i];
		
	}
	
	printf("\nSeyrek Matris\n");
	for(i=0;i<=seyreksatmax;i++){
		for(j=0;j<=seyreksutmax;j++){
			printf("%d\t",seyrekmtr[i][j]);
		}
		printf("\n");
	}
	
}

if (secim==3){
	bitis =2;
}
}

	
	return 0;
}
