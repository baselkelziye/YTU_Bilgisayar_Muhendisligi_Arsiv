#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

															//ELIF MERTOGLU 19011065
					//ÖNEMLÝ!! örnek input dosyasý 'input.zip'te verilen  sütun sayýsý önce yazýlmýþ olduðu için
					//kodumu yazarken ben de .pgm uzantýlý input dosyasýnda ilk sýrada sütun bilgisi verildiðini varsaydým.
					//Girilecek olan .pgm uzantýlý input dosyasýnda önce satýr sonra sütun yer alýyorsa lütfen
					//girmeden önce dosyada satýrla sütunun yerini deðiþtirin. Yoksa yanlýþ çalýþacaktýr.

typedef struct pgm{
	unsigned char **matrix;
	int width; //geniþlik columns
	int height; //uzunluk rows
	char type[3];
	int maxVal;
}pgm;


int main(){
	
	int place, sayac=1, k, r, dizi[256], count[256], encode[100], size, toplam, kontrol1=1,kontrol2=1,kontrol3=1, encode2[100],m;
	pgm *mypgm;
	mypgm=(pgm*)malloc(sizeof(pgm));
	FILE *fileptr, *fp;
	char filename[30];
	char filename2[30];
	int i,j;
	printf("PGM dosyanin adini giriniz.\n");
	scanf("%s",filename);
	fileptr=fopen(filename,"rb");
	if(fileptr==NULL){
		printf("dosya acilamadi.\n");
		exit(1);
	}
	
	fscanf(fileptr,"%s",mypgm->type);

	if(strcmp(mypgm->type,"P2")!=0){
		printf("Hatali dosya tipi.");
		return 0;
	}
	
	
	fscanf(fileptr,"%d %d",&mypgm->width,&mypgm->height); //height satir, width sutun ONCE SUTUN OKUYORUM
	fscanf(fileptr,"\n");
	
	fscanf(fileptr,"%d",&mypgm->maxVal);
	fscanf(fileptr,"\n");
	mypgm->matrix=(unsigned char**)malloc(mypgm->height*sizeof(unsigned char*));
	if(mypgm->matrix==NULL){
		printf("yer yok\n");
		return 0;
	}
		for(i=0;i<mypgm->height;i++){
			mypgm->matrix[i]=(unsigned char*)malloc(mypgm->width*sizeof(unsigned char));
			if(mypgm->matrix[i]==NULL){
				printf("yer yok\n");
				return 0;
			}
		}
	
		mypgm->matrix[i]=(unsigned char*)malloc(1*sizeof(unsigned char));
	
	mypgm->matrix[mypgm->height][0]=3;
	for(i=0;i<mypgm->height;i++){
			for(j=0;j<mypgm->width;j++){
				fscanf(fileptr,"%d ",&mypgm->matrix[i][j]);
			}
			fscanf(fileptr,"\n");
	}
	printf("\n\n");
	for(i=0;i<mypgm->height;i++){
		for(j=0;j<mypgm->width;j++){
			printf("%d ",mypgm->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	fp=fopen("test_encoded.txt","wb");
	if(fp==NULL){
		printf("dosya acilamadi.\n");
		exit(1);
	}
	
	k=0;
	r=0;
	for(i=0;i<mypgm->height;i++){
		for(j=0;j<mypgm->width;j++){
			if(j==mypgm->width-1){ 
				if(mypgm->matrix[i][j]==mypgm->matrix[i+1][0]){
					sayac=sayac+1;
				}else{
					dizi[k]=mypgm->matrix[i][j];
					k=k+1;
					count[r]=sayac;
					r=r+1;
					sayac=1;
				}
			}else{
				if(mypgm->matrix[i][j]==mypgm->matrix[i][j+1]){
					sayac=sayac+1;
				}else{
					dizi[k]=mypgm->matrix[i][j];
					k=k+1;
					count[r]=sayac;
					r=r+1;
					sayac=1;
				}
			}
		}
	}
	
	printf("\n");
	encode[0]=mypgm->width; //ENCODE DOSYASINA ONCE SUTUN YAZIYORUM
	encode[1]=mypgm->height;
	j=2;
		for(i=0;i<=r-1;i++){
		if(i==r-1){
			encode[j]=count[i];
		}else{
			encode[j]=count[i];
			j=j+2;
		}
	}
	
	j=3;
	
	for(i=0;i<=k-1;i++){
		if(i==k-1){
			encode[j]=dizi[i];
		}else{
			encode[j]=dizi[i];
			j=j+2;
		}
	}
	printf("PGM goruntunun RLE metoduyla daraltilmis hali: \n");
	for(i=0;i<=j;i++){
		printf("%d ",encode[i]);
	}
	for(i=0;i<=j;i++){
		fprintf(fp,"%d ",encode[i]);
	}
	
	fclose(fp);
	size =j ; 
	toplam=0;
	printf("\n");
	fp=fopen("test_encoded.txt","rb");
	m=0;
	while(!feof(fp)){
		fscanf(fp,"%d",&encode2[m]); //Kontrol iþlemlerinin yapýlabilmesi için matris deðerleri dosyadan diziye okunur.
		m++;						//Kontrol iþlemleri sonrasýnda bu dizi üzerinden yapýlacaktýr.
	}

	for(i=2;i<m-1;i=i+2){
		toplam+=encode2[i];
	}
	printf("\n");
	if(toplam==encode2[0]*encode2[1]){
		printf("Goruntudeki piksel sayisi satirSayisi*sutunSayisi kadardir.\n");
	}else{
		fp==NULL;
		kontrol1=-1;
	}
	for(i=3;i<m-1;i=i+2){
		if(encode2[i]<0 && encode2[i]>255){
			fp=NULL;
			kontrol2=-1;
		}else{
		}
	}
	if(kontrol2!=-1){
		printf("Goruntudeki renk kodlari 0-255 arasindadir.\n");
	}
	for(i=3;i<m-1;i=i+2){
		if(encode2[i]==encode2[i+2]){
			kontrol3=-1;
			fp=NULL;
		}else{
		}
	}
	
	if(kontrol3!=-1){
		printf("Goruntude hatali sikistirma bulunmamaktadir.\n");
	}
	printf("\n");
	if(fp==NULL && kontrol1==-1){
		printf("Goruntudeki piksel sayisi satirSayisi*sutunSayisi kadar degildir. Dosya acilamadi.\n");
		exit(1);
	}else if(fp==NULL && kontrol2==-1){
		printf("Goruntude 0-255 harici renk kodu bulunmaktadir. Dosya acilamadi.\n");
		exit(1);
	}else if(fp==NULL && kontrol3==-1){
		printf("test_encoded dosyasinda iki adet ayni olan renk kodu pes pese gelmektedir. Dosya acilamadi.\n ");
		exit(1);
	}
	
	fclose(fp);
	fp=fopen("test_encoded.txt","rb");
	if(fp==NULL){
		printf("Dosya acilamadi.\n");
		exit(1);
	}
	int secim,from,to,secim2,secim3;
	int encode3[100];
	m=0;
	FILE *fp1;
	while(!feof(fp)){
		fscanf(fp,"%d",&encode3[m]);
		m++;
	}
	fclose(fp);
	
		int sira,remember,encode4[100],newnum,satir,sutun,control=1,temp,temp2,remval,artiuc,artibir,control2;
		int histogram[256];
		printf("Renk kodu degistirmek istiyor musunuz?\nEvet icin 1'e, hayir icin 0'a basiniz.\n");
		scanf("%d",&secim);
		if(secim==1){
			printf("Hangi renk kodunu degistireceginizi ve neye degistireceginizi giriniz.\n");
				scanf("%d%d",&from,&to);
				for(i=3;i<m-1;i=i+2){
					if(encode3[i]==from){
						encode3[i]=to;
					}
				}
				fp1=fopen("test_encoded.txt","wb+");
				if(fp1==NULL){
					printf("dosya acilamadi.\n");
					exit(1);
				}
				for(i=0;i<m-1;i++){
					fprintf(fp1,"%d ",encode3[i]);
				}
				for(i=0;i<m-1;i++){
					printf("%d ",encode3[i]);
				}
				fclose(fp1);
		}
		printf("Koordinat girerek renk kodu degistirmek istiyor musunuz?\nEvet icin 1'e, hayir icin 0'a basiniz.\n");
		scanf("%d",&secim2);
		if(secim2==1){
			toplam=0;
			i=2;
				printf("Degistirmek istediginiz renk kodunun satir ve sutun sayisini giriniz.\n");
				scanf("%d%d",&satir,&sutun);
				printf("Neye degistirmek istediginizi giriniz.\n");
				scanf("%d",&newnum);
				sira=satir*mypgm->width;
				sira+=sutun+1;
				while(i<m-1 && control==1){
					if(toplam>sira){
						remember=i-2; 
						control=-1;
						remval=encode3[i-1];
					}else{
						toplam+=encode3[i];
						i=i+2;
					}
				}
				temp=toplam-sira; //benden sonra kaç adet olacak
				temp2=(encode3[remember]-temp)-1; //benden once kac adet olacak
				//printf("%d %d %d %d\n",toplam,sira,temp,temp2);
				j=0;
				for(i=0;i<remember;i++){
					encode4[i]=encode3[i];
					j++;
				}
				
				if(temp2>0 ){
					artiuc=1;
					encode4[remember] = temp2;
					encode4[remember+1] = remval;
					encode4[remember+2] = 1;
					encode4[remember+3] = newnum;
					encode4[remember+4] = temp;
					encode4[remember+5] = remval;
					for(i=remember+6;i<m+3;i++){
					encode4[i]=encode3[j+2];
					j++;
					}
					for(i=0;i<m+3;i++){
					printf("%d ",encode4[i]);
					} 
					for(i=0;i<m+3;i++){
						encode3[i]=encode4[i];
					} 
					printf("\n");
					for(i=0;i<m+3;i++){
						printf("%d ",encode3[i]);
					} 
					printf("\n");
					fp1=fopen("test_encoded.txt","wb+");
					if(fp1==NULL){
					printf("dosya acilamadi.\n");
					exit(1);
				}
				for(i=0;i<m+3;i++){
					fprintf(fp1,"%d ",encode3[i]);
				}
				fclose(fp1);
					
				}else{
					artibir=1;
					encode4[remember]=1;
					encode4[remember+1]=newnum;
					encode4[remember+2]=encode3[remember]-1;
					encode4[remember+3]=encode3[remember+1];
					for(i=remember+4;i<m+1;i++){
					encode4[i]=encode3[j+2];
					j++;
					}
					for(i=0;i<m+1;i++){
					printf("%d ",encode4[i]);
					} 
					for(i=0;i<m+1;i++){
						encode3[i]=encode4[i];
					} 
					printf("\n");
					for(i=0;i<m+1;i++){
						printf("%d ",encode3[i]);
					} 
					printf("\n");
					}
					fp1=fopen("test_encoded.txt","wb+");
					if(fp1==NULL){
					printf("dosya acilamadi.\n");
					exit(1);
				}
				for(i=0;i<m+1;i++){
					fprintf(fp1,"%d ",encode3[i]);
				}
				fclose(fp1);
		}
	
		printf("Goruntunun histogramini cikarmak istiyor musunuz?\nEvet icin 1'e, hayir icin 0'a basiniz.\n");
		scanf("%d",&secim3);
		if(secim3==1 &&secim2==0){
			for(i=0;i<256;i++){
					histogram[i]=0;
				}
				for(i=3;i<m-1;i=i+2){
					histogram[encode3[i]]+=encode3[i-1];
				}
				for(i=0;i<256;i++){
					if(histogram[i]!=0){
						printf("%d adet %d rengi\n",histogram[i],i);
					}
				}
		}else if(secim3==1 && secim2==1 && artibir==1){
			for(i=0;i<256;i++){
					histogram[i]=0;
				}
				for(i=3;i<m+1;i=i+2){
					histogram[encode3[i]]+=encode3[i-1];
				}
				for(i=0;i<256;i++){
					if(histogram[i]!=0){
						printf("%d adet %d rengi\n",histogram[i],i);
					}
				}
		}else if(secim3==1 && secim2==1 && artiuc==1){
			for(i=0;i<256;i++){
					histogram[i]=0;
				}
				for(i=3;i<m+3;i=i+2){
					histogram[encode3[i]]+=encode3[i-1];
				}
				for(i=0;i<256;i++){
					if(histogram[i]!=0){
						printf("%d %d\n",histogram[i],i);
					}
				}
		}

			

	
	FILE *fp3;
	int deMatrix[50][50],p=0,s=0,l,sayac2=0;
	fp3=fopen("test_decoded.pgm","wb");
	if(fp3==NULL){
		printf("dosya acilamadi.\n");
		exit(1);
	}
	
	fprintf(fp3,"%s\n",mypgm->type);
	fprintf(fp3,"%d %d\n",mypgm->width,mypgm->height);
	fprintf(fp3,"%d\n",mypgm->maxVal);
	
	if(secim2==1 && artibir==1){
		for(l=2;l<m+1;l=l+2){
		sayac2=0;
		while(sayac2<encode3[l]){
			if(s==mypgm->width){
				p=p+1;
				s=0;
			}else{
			}
		deMatrix[p][s]=encode3[l+1];
		s=s+1;
		sayac2=sayac2+1;	
		}
		}
	}else if(secim2==1 && artibir!=1 && artiuc!=1){
		for(l=2;l<m-1;l=l+2){
		sayac2=0;
		while(sayac2<encode3[l]){
			if(s==mypgm->width){
				p=p+1;
				s=0;
			}else{
			}
		deMatrix[p][s]=encode3[l+1];
		s=s+1;
		sayac2=sayac2+1;	
		}
		}
	}else if(secim2==1 && artiuc==1){
		for(l=2;l<m+3;l=l+2){
		sayac2=0;
		while(sayac2<encode3[l]){
			if(s==mypgm->width){
				p=p+1;
				s=0;
			}else{
			}
		deMatrix[p][s]=encode3[l+1];
		s=s+1;
		sayac2=sayac2+1;	
		}
		}
	}else{
		for(l=2;l<m-1;l=l+2){
		sayac2=0;
		while(sayac2<encode3[l]){
			if(s==mypgm->width){
				p=p+1;
				s=0;
			}else{
			}
		deMatrix[p][s]=encode3[l+1];
		s=s+1;
		sayac2=sayac2+1;	
		}
		}
	}
	
	printf("Matrisin acik hali:");
	for(i=0;i<mypgm->height;i++){
		printf("\n");
		for(j=0;j<mypgm->width;j++){
			printf("%d ",deMatrix[i][j]);
		}
	}
	for(i=0;i<mypgm->height;i++){
		for(j=0;j<mypgm->width;j++){
			fprintf(fp3,"%d ",deMatrix[i][j]);
		}
		fprintf(fp3,"\n");
	}
	
	
	return 0;
}

