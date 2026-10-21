#include<stdio.h>
#include<stdlib.h>
//19011065
typedef struct advert{
	int startTime;
	int duration;
	int value;
	int no;
}advert;

int howManyRows();									//kac adet reklam oldugunu bulur
advert *readFromFile(int );							//reklamlari dosyadan okur
advert *sort(advert *, int );						//reklamlari bitis zamanlarina gore siralar
int theLastnonOverlappingAd(advert *, int , int );	//kendinden once olup kendisiyle cakismayan en son reklami bulur
int *profitCalculator(advert *, int );				//reklamlarin profit'lerini hesaplar
int *whichAdsAreUsed(advert *, int *, int );		//en yuksek profit secildiginde hangi reklamlarin kullanildigini bulur

int main(){
	
	int numOfAds,i,j;	//numOfAds-->reklamlarin adedini tutar
	advert *ads; 		//reklamlari tutacak struct dizisi
	int *profit;		//reklamlarin profit'lerini tutacak dizi
	int *usedAds; 		//hangi reklamlarin kullanildigi bilgisini tutacak dizi
	
	numOfAds=howManyRows();
	ads=readFromFile(numOfAds);
	ads=sort(ads,numOfAds);
	profit=profitCalculator(ads,numOfAds);
	usedAds=whichAdsAreUsed(ads,profit,numOfAds);
	
	i=0;
	while(usedAds[i]!=-1){	
		i++;
	};
	printf("For this example the total profit would be %d and the ads are: ",profit[numOfAds-1]);
	for(j=0;j<i;j++){
		printf("%d ",usedAds[j]);
	};
	
	return 0;
}

int howManyRows(){
	
	FILE *fp;
	int rows=0; //dosyadaki satir sayisi(yani reklam sayisi) tutulacak
	int junk; //dosyayi okurken degerleri almak icin 
	
	fp=fopen("sample.txt","r");
	if(fp==NULL){
		printf("Error.\n");
		return;
	};

	while(!feof(fp)){
		fscanf(fp,"%d %d %d\n",&junk,&junk,&junk,&junk);
		rows++; 
	};
	fclose(fp);
	
	return rows;
};

advert *readFromFile(int numofads){
	
	FILE *fp;
	int i=0,j=1;
	advert *ads;	//icinde reklamlari tutacak diziyi olusturmak icin
	
	fp=fopen("sample.txt","r");
	if(fp==NULL){
		printf("file could not opened.\n");
		return;
	};
	
	ads=(advert*)malloc(numofads*sizeof(advert));
	if(ads==NULL){
		printf("memory not allocated.\n");
		return;
	};
	
	while(!feof(fp)){
		fscanf(fp,"%d %d %d\n",&ads[i].startTime,&ads[i].duration,&ads[i].value);
		ads[i].no=j;
		i++;
		j++;
	}
	fclose(fp);
	printf("Ad No	Start Time	Duration	Value\n");
	for(i=0;i<numofads;i++){
		printf("%3d %10d %13d %14d\n",ads[i].no,ads[i].startTime,ads[i].duration,ads[i].value);
	}
	
	printf("\n");
	
	return ads;	
	
};

advert *sort(advert *ads, int numofads){
	
	int i,j,key;
	advert indexOfKey;
	
	for(i=1;i<numofads;i++){
		key=ads[i].startTime+ads[i].duration;
		indexOfKey.startTime=ads[i].startTime;
		indexOfKey.duration=ads[i].duration;
		indexOfKey.value=ads[i].value;
		indexOfKey.no=ads[i].no;
		j=i-1;

		while(j>=0 && ((ads[j].startTime+ads[j].duration)>key)){
			ads[j+1].startTime=ads[j].startTime;
			ads[j+1].duration=ads[j].duration;
			ads[j+1].value=ads[j].value;
			ads[j+1].no=ads[j].no;
			j=j-1;
		};
		ads[j+1].startTime=indexOfKey.startTime;
		ads[j+1].duration=indexOfKey.duration;
		ads[j+1].value=indexOfKey.value;
		ads[j+1].no=indexOfKey.no;
	};
	
	printf("The sorted ads are:\n");
	printf("Ad No	Start Time	Duration	Value\n");
	for(i=0;i<numofads;i++){
		printf("%3d %10d %13d %14d\n",ads[i].no,ads[i].startTime,ads[i].duration,ads[i].value);
	}
	printf("\n");
	return ads;
	
};

int *profitCalculator(advert *ads, int numofads){
	
	int i,key;
	int *profit;
	profit=(int*)malloc((numofads)*sizeof(int));
	if(profit==NULL){
		printf("memory not allocated.\n");
		return;
	};
	
	profit[0]=ads[0].value+0;	//profit'in ilk degerine ilk reklamin degeri atilir ve 0'la toplanir cunku baslangicta profit 0'dir.
	
	for(i=1;i<numofads;i++){
		key=theLastnonOverlappingAd(ads,numofads,i); //i. reklamin kendinden once cakistigi en son reklamin indisini dondurur.
		if(key==-1){ 								 //i. reklam kendinden onceki butun reklamlarla cakisiyor.
			if(profit[i-1]<ads[i].value){ 		 	 //i. reklamin value'su+0, kendinden onceki reklamin profit'inden kucuk mu kontrolu.
				profit[i]=ads[i].value+0;			 //kucukse eger kendinden onceki reklamin profit'i yerine kendi value'su +... 
			}else{									 //...bastaki profit degeri (0) alinir.
				profit[i]=profit[i-1];				 //buyukse kendinden onceki reklamin profit'i alinir.
			}
		}else{										 //i. reklamin kendinden once cakismadigi bir reklam var ve indisi key'de sakli.
			if(profit[key]+ads[i].value>profit[i-1]){//kendinden once cakismayan reklamin profit'i + i.reklamin value'su, i. reklamdan bir onceki reklamin profit'inden buyuk mu kontrolu.
				profit[i]=profit[key]+ads[i].value;	 //buyukse i. reklamin profit'i kendinden once cakismayan reklamin profit'i + i.reklamin value'su olur.
			}else{
				profit[i]=profit[i-1];				 //kucukse i. reklamin profit'i kendinden bir onceki reklamin profit'ine esit olur.
			}
		}
	}
	
	printf("The profits are:\n");
	printf("Ad No	Start Time	Duration	Value	  Profit\n");
	for(i=0;i<numofads;i++){
		printf("%3d %10d %13d %14d %10d\n",ads[i].no,ads[i].startTime,ads[i].duration,ads[i].value,profit[i]);
	}
	printf("\n");
	
	return profit;
	
}

int theLastnonOverlappingAd(advert *ads, int numofads, int index){ 
	
	int st,dur,ft,j;
	st=ads[index].startTime;	//profitCalculator()'dan gelen reklamin baslangic zamanini tutar.
	dur=ads[index].duration;	//profitCalculator()'dan gelen reklamin suresini tutar.
	ft=st+dur;					//profitCalculator()'dan gelen reklamin bitis zamanini tutar.
	j=index-1;					//profitCalculator()'dan gelen reklamdan bir onceki reklamin indisini tutar.
	
	while(j>=0 && !(  (st<ads[j].startTime)&&(ft<=(ads[j].startTime+ads[j].duration))  || (st>=ads[j].startTime+ads[j].duration)&&(ft>ads[j].startTime+ads[j].duration)) ){
		j--;
	};
	/*if(j==-1){
		printf("%d numarali reklamin kendinden once cakismadigi bir reklam bulunmamaktadir.\n",ads[index].no);
	}else{
		printf("%d numarali reklamin kendinden once cakismadigi en son reklam %d numarali reklamdir.\n",ads[index].no,ads[j].no);
	}*/
	
	//while dongusu cakisma oldugu surece devam eder ve cakisma oldukca indisi bir azaltarak 1. reklama ulasana kadar(1.reklam dahil) devam eder.
	//cakisma kontrolu 3 durum, cakisma olmama kontrolu 2 durum getireceginden while'in icinde cakisma olmama kontrolunu yapip degilini aliyorum.
	//kendisinden once cakisma olmayan ilk reklami buldugunda donguden cikar ve j icinde bize cakisma olmayan reklamin indisini dondurur.
	
	return j;
	
}

int *whichAdsAreUsed(advert *ads, int *profit, int numofads){

	int value=profit[numofads-1]; 	//hesaplanan profit degerini tutar
	int i=numofads-1;				//en son reklamin indisini tutar
	int k=0,j;						//k-->usedAds dizisinin indisi, j-->usedAds dizisinin elemanlarini -1'lemek icin indis
	int *usedAds;					//en yuksek profit'i veren reklamlarin indislerini tutacak olan dizi
	
	usedAds=(int*)malloc(numofads*sizeof(int));	//usedAds dizisi olusturulur. En fazla reklam sayisi kadar olabilecegi icin o kadarlik acilir.
	if(usedAds==NULL){
		printf("memory not allocated.\n");
		return;
	};
	
	for(j=0;j<numofads;j++){	//kac adet reklamin secilecegi bilinmedigi icin hepsine -1 atanir. 
		usedAds[j]=-1;			//dizi main'e donunce -1'den farkli olan sayilar secilen reklamlarin siralanmadan onceki numaralari olucak demektir.
	};
	
	
	while(value!=0){					//profit degeri sifirdan buyuk oldukca devam eder
		while(profit[i]==profit[i-1]){	//eger bir profit degeri kendinden bir onceki profit'e esitse o profit'e ait reklam secilmemis demektir.
			i--;						//siradaki reklama gecer
		}								//ustteki while'dan cikildiginda reklam kesinlikle secilmis demektir cunku profit'ler farkli.
		value=profit[i]-ads[i].value;	//bu yuzden reklamin profit'inden reklamin value'su cikarilarak value degeri bir sonraki reklami bulabilmek icin guncellenir.
		usedAds[k]=ads[i].no;			//bulunan reklamin numarasi usedAds dizisinin musait olan siradaki gozune atilir.
		k++;							//usedAds dizisinin indisi bir artirilir.
		while(value!=profit[i]){		//guncellenen value, reklamlarin profit'lerine uymadigi surece dongu devam eder.
			i--;						//reklamlar gezilir
		}
										//reklamin profit'iyle elimizdeki value degeri uyusmus, yani secilmeye aday reklam bulunmus demektir. 
	}									//basa doner ve profit'lerin art arda ayni gelip gelmedigi kontrolu yapilir, ayni gelmiyorsa secilmeye aday reklam secilecek demektir.
	printf("\n");
	
	return usedAds;
	
};
