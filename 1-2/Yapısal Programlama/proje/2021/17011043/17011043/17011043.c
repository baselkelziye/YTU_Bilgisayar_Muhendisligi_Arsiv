#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct hocalar{
	char hocaID[20];
	char hocaAd[20];
	char hocaSoyad[20];
	char unvan[20];
	
}hoca;

typedef struct dersler{
	char dersKod[10];
	char dersAd[40];
	int kredi; // dersin kredisi 
	int kont; // kontenjan
	hoca dershoca; // dersler ve hocalar aras�nda ba�lant� kurmak i�in ders[i].
}ders;

typedef struct ogrenci{
	char ogrNo[10];
	char ogrAd[15];
	char ogrSoyad[15];
	int toplamDers;
	int topKredi;
}ogr;

typedef struct ogr_ders_kayit{
	char ogrDurum[15]; // 1 ise kay�tl� 0 ise b�rakt�.
	ders dersbilg; //
	ogr ogrbilg; // ogrNo �ekmek i�in
	char kayitTarih[15];
}kayit;

//hoca *hocaEkle(hoca *hocalar,int *h);
//hoca *hocaSil(hoca *hocalar,int *h);
//hoca *hocaGuncelle(hoca *hocalar,int h);
ders *dersEkle(ders *dersler,int *h2,char temp1[25]);
ders *dersSil(ders *dersler,int *h2);
ders *dersGuncelle(ders *dersler,int h2,char temp1[25]);
ogr *ogrEkle(ogr *ogrler,int *h3);
ogr *ogrSil(ogr *ogrler,int *h3,kayit *kayitlar,int h4);
ogr *ogrGuncelle(ogr *ogrler,int h3);
kayit *kayitEkle(kayit *kayitlar,int *h4,ders *dersler,int h2,ogr *ogrler,int h3,int maxKredi,int maxDers);
kayit *kayitSil(kayit *kayitlar,int h4,ders *dersler,int h2,ogr *ogrler,int h3);
void fonk1(ders *dersler,int h3,char temp1[20]);
void fonk2(kayit *kayitlar,int h4,ogr *ogrler,int h3,char temp1[20]);
void fonk3(kayit *kayitlar,int h4,ders *dersler,int h2,char temp1[20]);
void fonk4(kayit *kayitlar,int h4,ogr *ogrler,int h3,char temp1[20]);
int main()
{
	//int n1,n2,n3,n4;
	int secim;
	int secim3=0;
	int count;
	int maxKredi;
	int maxDers;
	int var=0;
	char secim2='b';
	int h=0, h2=0, h3=0,h4=0,e;		//Hoca Sayisi
	hoca *hocalar;
	ders *dersler;
	ogr *ogrler;
	kayit *kayitlar;
	int temp, tmp2,tmp1;
	int onay=0; int onay2=0; int onay3=0;
	printf("\n NOT!  : Veritabani olusturma mantigina gore tablolarin bagliligi sebebiyle ilk eklemeler (ogruyesi,dersler,ogrenciler,derskayit) sirasiyla yapilmalidir..\n ");
	char temp1[20];
	char temp2[20];
	char temp3[20];
	char tempDosya[30];
	char ogrDosya[15],hocaDosya[15],dersDosya[15],kayitDosya[15];
	char bos;
	printf("\n\n Lutfen olusturmak istediginiz dosya isimlerinizi txt'siz olarak giriniz.. (.txt uzantisi programda otomatik ekleniyor)");
	printf("\n\n Ogretim uyeleri dosyasi : "); scanf("%s",hocaDosya);
	printf("\n Dersler dosyasi : "); scanf("%s",dersDosya);
	printf("\n Ogrenci dosyasi : "); scanf("%s",ogrDosya);
	printf("\n Ders Kayit dosyasi : "); scanf("%s",kayitDosya); 
	strcat(hocaDosya,".txt"); strcat(ogrDosya,".txt");  strcat(kayitDosya,".txt");
	strcat(dersDosya,".txt");
	printf("\n\n\t Lutfen bir ogrencinin alabilecegi maksimum krediyi sayisini giriniz : "); scanf("%d",&maxKredi);
	printf("\n\n\t Lutfen bir ogrencinin alabilecegi maksimum ders    sayisini giriniz : "); scanf("%d",&maxDers);
	FILE *fw;
	int i=0;
	printf("\n\n\n Lutfen yapmak istediginiz islem numarasini giriniz ");
	while(secim!=6)
	{
		secim=0;
		printf("\n\n\n\n 1: Ogretim Uyesi Islemleri    2: Ders Islemleri    3: Ogrenci Islemleri    4: Ders Kayit Islemleri    5: Ekstra Islemler  6: Cikis ||   Secim -->");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1: 
				secim2='b';
				while(secim2!='A' && secim2!='a')
				{
				
					printf("\n\n\tOgretim Uyesi   -->   Ekle(E)    Sil(S)    Guncelle(G)    Ana Menuye Don(A)   ||   Secim --> ");
					scanf(" %c",&secim2);
					
					if(secim2=='E' || secim2=='e')
					{
							e=h;
							while(e==h)
							{
								 hocalar=hocaEkle(hocalar,&h);
							}
							
							fw=fopen(hocaDosya,"w");
							for(i=0;i<h;i++)
							{
								fprintf(fw,"%s %s %s %s\n",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad,hocalar[i].unvan);
							}
							fclose(fw);
					}
					else if(secim2=='S' || secim2=='s')
					{
						e=h;
						while(e==h)
						{
							hocalar=hocaSil(hocalar,&h);
							
						}
						fw=fopen(hocaDosya,"w");
						for(i=0;i<h;i++)
						{
							fprintf(fw,"%s %s %s %s\n",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad,hocalar[i].unvan);
						}
						fclose(fw);
					}
					else if(secim2=='G' || secim2=='g')
					{
						hocalar=hocaGuncelle(hocalar,h);
						fw=fopen(hocaDosya,"w");
						for(i=0;i<h;i++)
						{
							fprintf(fw,"%s %s %s %s\n",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad,hocalar[i].unvan);
						}
						fclose(fw);
					}
					else if(secim2=='A' || secim2=='a')
					{
						printf("\n\n\t\t ------ ANA MENUYE YONLENDIRILIYORSUNUZ ------");
					}
					else
					{
						printf("\n\tUyari ! : Yanlis bir deger girdiniz lutfen tekrar deneyiniz..");
					}
				}
					break;
					
			case 2:
					
					secim2='b';
					if(h==0)
					{
						printf("\n\n\n\t\tUYARI !!! -----   Ogretim uyesi eklemeden ders islemleri yapilamaz! Ana Menuye yonlendiriliyorsunuz..   ----- UYARI !!!\n");
						secim2='A';
					}
				while(secim2!='A' && secim2!='a')
				{
					
					printf("\n\n\tDers   -->   Ekle(E)    Sil(S)    Guncelle(G)    Ana Menuye Don(A)   ||   Secim --> ");
					scanf(" %c",&secim2);
					
					if(secim2=='E' || secim2=='e')
					{
							e=h2;
							onay=0;
							while(e==h2)
							{
								 
								 while(onay!=1)
								 {
								 	printf("\n\n\n\t Lutfen eklemek istediginiz dersi veren hocanin ID'sini giriniz.. : ");
								 	scanf("%s",temp1);
								 	for(i=0;i<h;i++)
								 	{
								 		if(strcmp(hocalar[i].hocaID,temp1)==0)
								 		{
								 			onay=1;
										}
									}
									if(onay==0)
									{
										count=0;
										printf("\n\t\t\t\t Girilen degere ait ogretim uyesi bulunmamaktadir..Lutfen farkli bir ID deneyiniz.\n");
										printf("\n\n\t\t\t --- Mecvut olan ogretim uyesi bilgileri ---\n\n");
										for(i=0;i<h;i++)
										{
											count++;
											printf("   ID: %s  Ad: %s %s",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad);
											if(count%4==0)
											{
												printf("\n\n");
											}
										}
										
									}
								 }
								 onay=1;
								 dersler=dersEkle(dersler,&h2,temp1);
							}
						fw=fopen(dersDosya,"w");
						for(i=0;i<h2;i++)
						{
							fprintf(fw,"%s, %s, %s, %d, %d\n",dersler[i].dersKod,dersler[i].dersAd,dersler[i].dershoca.hocaID,dersler[i].kredi,dersler[i].kont);
						}
						fclose(fw);
					}
					else if(secim2=='S' || secim2=='s')
					{
						e=h2;
							
						while(e==h2)
						{
							dersler=dersSil(dersler,&h2);
						}
							
						fw=fopen(dersDosya,"w");
						
						for(i=0;i<h2;i++)
						{
							fprintf(fw,"%s, %s, %s, %d, %d\n",dersler[i].dersKod,dersler[i].dersAd,dersler[i].dershoca.hocaID,dersler[i].kredi,dersler[i].kont);
						}
						
						fclose(fw);
					}
					else if(secim2=='G' || secim2=='g')
					{
						onay=0;
								 
						while(onay!=1)
						{
							printf("\n\n\tLutfen guncellemek istediginiz dersi yeni verecek olan Ogretim Uyesi ID giriniz.. : ");
							scanf("%s",temp1);
							for(i=0;i<h;i++)
							{
							 	if(strcmp(hocalar[i].hocaID,temp1)==0)
								{	
				 		 			onay=1;
								}
							}
								if(onay==0)
								{
									count=0;
									printf("\n\t\t\t\t Girilen degere ait ogretim uyesi bulunmamaktadir..Lutfen farkli bir ID deneyiniz.\n");
									printf("\n\n\t\t\t --- Mecvut olan ogretim uyesi bilgileri ---\n\n");
									for(i=0;i<h;i++)
									{
										count++;
										printf("   ID: %s  Ad: %s %s",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad);
										if(count%4==0)
										{
											printf("\n\n");
										}
									}
										
								}
						}
						 	onay=1;
							dersler=dersGuncelle(dersler,h2,temp1);
						
						fw=fopen(dersDosya,"w");
						for(i=0;i<h2;i++)
						{
							fprintf(fw,"%s, %s, %s, %d, %d\n",dersler[i].dersKod,dersler[i].dersAd,dersler[i].dershoca.hocaID,dersler[i].kredi,dersler[i].kont);
						}
						fclose(fw);
					}
					else if(secim2=='A' || secim2=='a')
					{
						printf("\n\n\t\t ------ ANA MENUYE YONLENDIRILIYORSUNUZ ------");
					}
					else
					{
						printf("\n\tUyari ! : Yanlis bir deger girdiniz lutfen tekrar deneyiniz..");
					}
				}
					break;
						
				case 3: 
					secim2='b';
					while(secim2!='A' && secim2!='a')
					{
						
						printf("\n\n\tOgrenci   -->   Ekle(E)    Sil(S)    Guncelle(G)    Ana Menuye Don(A)   ||   Secim -->");
						scanf(" %c",&secim2);
					
						
						if(secim2=='E' || secim2=='e')
						{
							e=h3;
							while(e==h3)
							{
								 ogrler=ogrEkle(ogrler,&h3);
							}
							
							fw=fopen(ogrDosya,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s %s %s %d %d\n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad,ogrler[i].toplamDers,ogrler[i].topKredi);
							}
							fclose(fw);
						}
						else if(secim2=='S' || secim2=='s')
						{
							e=h3;
							while(e==h3)
							{
								ogrler=ogrSil(ogrler,&h3,kayitlar,h4);
								
							}
							fw=fopen(kayitDosya,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s %s %s %s\n",kayitlar[i].ogrbilg.ogrNo,kayitlar[i].dersbilg.dersKod,kayitlar[i].kayitTarih,kayitlar[i].ogrDurum);
							}
							fclose(fw);	
							fw=fopen(ogrDosya,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s %s %s %d %d\n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad,ogrler[i].toplamDers,ogrler[i].topKredi);
							}
							
						
							fclose(fw);
						}
						else if(secim2=='G' || secim2=='g')
						{
							ogrler=ogrGuncelle(ogrler,h3);
							fw=fopen(ogrDosya,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s %s %s %d %d\n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad,ogrler[i].toplamDers,ogrler[i].topKredi);
							}
							fclose(fw);
						}
					
						else if(secim2=='A' || secim2=='a')
						{
							printf("\n\n\t\t ------ ANA MENUYE YONLENDIRILIYORSUNUZ ------");
						}
						else
						{
							printf("\n\tUyari ! : Yanlis bir deger girdiniz lutfen tekrar deneyiniz..");
						}
					}
						break;
						
				case 4: 
					secim2='b';
					if(h==0 || h2==0 || h3==0)
					{
						printf("\n\n\n\t\tUYARI !!! -----   Ogretim uyesi-Ders-Ogrenci eklemeden ders islemleri yapilamaz! Ana Menuye yonlendiriliyorsunuz..   ----- UYARI !!!\n");
						secim2='A';
					}
				
					while(secim2!='A' && secim2!='a')
					{
						
						printf("\n\n   Ogrenci Kaydi   -->   Ekle(E)   Sil(S)   Ana Menuye Don(A)  ||  Secim --> ");
						scanf(" %c",&secim2);
						
						if(secim2=='E' || secim2=='e')
						{
							e=h4;
							while(e==h4)
							{
								 kayitlar=kayitEkle(kayitlar,&h4,dersler,h2,ogrler,h3,maxKredi,maxDers);
							}
							fw=fopen(ogrDosya,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s %s %s %d %d\n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad,ogrler[i].toplamDers,ogrler[i].topKredi);
							}
							fclose(fw);
							fw=fopen(kayitDosya,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s %s %s %s\n",kayitlar[i].ogrbilg.ogrNo,kayitlar[i].dersbilg.dersKod,kayitlar[i].kayitTarih,kayitlar[i].ogrDurum);
							}
							fclose(fw);		
						}
						else if(secim2=='S' || secim2=='s')
						{
							kayitlar=kayitSil(kayitlar,h4,dersler,h2,ogrler,h3);
							fw=fopen(ogrDosya,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s %s %s %d %d\n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad,ogrler[i].toplamDers,ogrler[i].topKredi);
							}
							fclose(fw);
							fw=fopen(kayitDosya,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s %s %s %s\n",kayitlar[i].ogrbilg.ogrNo,kayitlar[i].dersbilg.dersKod,kayitlar[i].kayitTarih,kayitlar[i].ogrDurum);
							}
							fclose(fw);	
						}
						else if(secim2=='A' || secim2=='a')
						{
							printf("\n\n\t\t ------ ANA MENUYE YONLENDIRILIYORSUNUZ ------");
						}
						else
						{
							printf("\n\tUyari ! : Yanlis bir deger girdiniz lutfen tekrar deneyiniz..");
						}
					}
				
					secim2='b';
					
				break;
							
					
				case 5:
					
					while(secim3!=5)
					{
						
						printf("\n\n\t Odev dosyasinin son kisminda istenen durumlara hosgeldiniz.. ");
						printf("\n\n\t ID'si verilen ogretim uyesinin verdigi dersleri gosteren fonksiyon icin (1) ");
						printf("\n\n\t Ders kodu verilen bir derse kayitli olan tum ogrencileri gosteren fonksiyon icin (2) ");
						printf("\n\n\t Ogrenci Numarasi verilen bir ogrencinin aldigi tum dersleri veren fonksiyon icin (3) ");
						printf("\n\n\t ID'si verilen bir ogretim uyesinin verdigi bir dersi alan tum ogrenciler (4)");
						printf("\n\n\t\t\t\t ANA MENUYE DONUS (5)\t\t\t\t\t\t Secim--> ");
						scanf(" %d",&secim3);
						
						if(secim3==1)
						{
							temp1[0]='\0';
							count=0;
							printf("\n\n\t\t\t --- Mevcut olan ogretim uyesi bilgileri ---\n\n");
							for(i=0;i<h;i++)
							{
								count++;
								printf("   ID: %s  Ad: %s %s",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad);
								if(count%4==0)
								{
									printf("\n\n");
								}
							}
							printf("\n\t Verdigi dersleri ogrenmek istediginiz Ogretim Uyesi ID : ");
							scanf("%s",temp1);
							for(i=0;i<h;i++)
							{
								if(strcmp(hocalar[i].hocaID,temp1)==0)
								{
									printf("\n\n ID : %s   %s %s'in verdigi dersler \n",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad);							
								}							
							}
							
							fonk1(dersler,h3,temp1);
							printf("\n\n\t\t\t------  PROGRAM 2 SANIYE BEKLETILIYOR  ------ ");
							sleep(2);
							printf("\n\n\n\t\t\t Menuye donuluyor..");
							sleep(1);
						}
						
						else if(secim3==2)
						{
							temp1[0]='\0';
							count=0;
							printf("\n\n\t\t\t --- Mevcut olan Ders bilgileri ---\n\n");
							for(i=0;i<h2;i++)
							{
								count++;
								printf("   ID: %s  Ad: %s ",dersler[i].dersKod,dersler[i].dersAd);
								if(count%4==0)
								{
									printf("\n\n");
								}
							}
							printf("\n\n Kayitli ogrencileri ogrenmek istediginiz Ders Kodu : ");
							scanf("%s",temp1);
							fonk2(kayitlar,h4,ogrler,h3,temp1);
							printf("\n\n\t\t\t------  PROGRAM 2 SANIYE BEKLETILIYOR  ------ ");
							sleep(2);
							printf("\n\n\n\t\t\t Menuye donuluyor..");
							sleep(1);
						}
						else if(secim3==3)
						{
							temp1[0]='\0';
							count=0;
							printf("\n\n\t\t\t --- Mevcut Ogrenci Bilgileri ---\n\n");
							for(i=0;i<h3;i++)
							{
								count++;
								printf("   Ogrenci NO: %s  Ad: %s %s ",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad);
								if(count%4==0)
								{
									printf("\n\n");
								}
							}
							printf("\n\n Kayitli oldugu dersleri ogrenmek istediginiz Ogrenci NO : ");
							scanf("%s",temp1);
							for(i=0;i<h;i++)
							{
								if(strcmp(ogrler[i].ogrNo,temp1)==0)
								{
									printf("\n\n Ogrenci NO : %s   %s %s'in aldigi tum dersler \n",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad);							
								}							
							}
							fonk3(kayitlar,h4,dersler,h2,temp1);
							printf("\n\n\t\t\t------  PROGRAM 2 SANIYE BEKLETILIYOR  ------ ");
							sleep(2);
							printf("\n\n\n\t\t\t Menuye donuluyor..");
							sleep(1);
						}
						else if(secim3==4)
						{
							var=0;
							while(var!=1)
							{
								count=0;
								temp1[0]='\0';
								printf("\n\n\t\t\t --- Mevcut olan ogretim uyesi bilgileri ---\n\n");
								for(i=0;i<h;i++)
								{
									count++;
									printf("   ID: %s  Ad: %s %s",hocalar[i].hocaID,hocalar[i].hocaAd,hocalar[i].hocaSoyad);
									if(count%4==0)
									{
										printf("\n\n");
									}
								}
								printf("\n\t Verdigi derslerden birine ait ogrenci listesi olusturmak istediginiz Ogretim Uyesi ID : ");
								scanf("%s",temp1);
								for(i=0;i<h;i++)
								{
									if(strcmp(hocalar[i].hocaID,temp1)==0)
									{
										tmp1=i; // Hoca bilgileri icin
										var=1;
									}
								}
							}
						
							for(i=0;i<h2;i++)
							{
								if(strcmp(dersler[i].dershoca.hocaID,temp1)==0)
								{
									tmp2=i;			// Ders bilgileri adi kodu icin
									strcpy(temp1,dersler[i].dersKod);
									i=h2+1;''
								}
							}
							fonk4(kayitlar,h4,ogrler,h3,temp1);
							tempDosya[0]='\0';
							strcpy(tempDosya,temp1);
							strcat(tempDosya,"_SINIFLISTESI.txt");
							fw=fopen(tempDosya,"a");
							fprintf(fw,"\n\n\n\n\t  Dokuman Adi :  %s  \n  Yurutucusu   %s %s    unvani   %s   olan     %s     kodlu   %s   dersine ait ogrenci sinif listesi ",tempDosya,hocalar[tmp1].hocaAd,hocalar[tmp1].hocaSoyad,hocalar[tmp1].unvan,dersler[tmp2].dersKod,dersler[tmp2].dersAd);
							fclose(fw);
							printf("\n\n\t\t\t------  PROGRAM 2 SANIYE BEKLETILIYOR  ------ ");
							sleep(2);
							printf("\n\n\n\t\t\t Menuye donuluyor..");
							sleep(1);
						}
						else if(secim3==5)
						{
							printf("\n\n\n\t\t\t\t ------------- ANA MENUYE YONLENDIRILIYORSUNUZ -------------");
						}
						
					
					}
						break;
						
						default:
						break;
		}
	}
	return 0;
}

hoca *hocaEkle(hoca *hocalar,int *h)
{
	char tempID[15];
	int i;
	if(*h==0) // �lk giri� oldu�u i�in kontrol yok.Ogr uyesi ID'si �ak��amaz.
	{
		(*h)++;
		//printf("%d",*h);
		hocalar=(hoca*)malloc((*h)*sizeof(hoca));
		printf("\n\tOgretim Uyesi ID    : "); scanf("%s",hocalar[(*h)-1].hocaID);
		printf("\tOgretim Uyesi Ad    : "); scanf("%s",hocalar[(*h)-1].hocaAd);	
		printf("\tOgretim Uyesi Soyad : "); scanf("%s",hocalar[(*h)-1].hocaSoyad);
		printf("\tOgretim Uyesi Unvan : "); scanf("%s",hocalar[(*h)-1].unvan);
		return hocalar;
	}
	else
	{
		tempID[0]='\0';
		printf("\n\tOgretim Uyesi ID    : "); 
		scanf("%s",tempID);
		
		for(i=0;i<*h;i++)
		{
			if(strcmp(hocalar[i].hocaID,tempID)==0) 
			{
				printf("\n\t\t\t\t\t Girdiginiz Ogretim Uyesi ID sistemde mevcut! Lutfen baska bir Ogretim Uyesi ID giriniz.. \n ");
				return hocalar;				
			}
		}
		(*h)++;
		hocalar=(hoca*)realloc(hocalar,(*h)*sizeof(hoca));
		strcpy(hocalar[*h-1].hocaID,tempID);
		printf("\tOgretim Uyesi Ad    : "); scanf("%s",hocalar[*h-1].hocaAd);	
		printf("\tOgretim Uyesi Soyad : "); scanf("%s",hocalar[*h-1].hocaSoyad);
		printf("\tOgretim Uyesi Unvan : "); scanf("%s",hocalar[*h-1].unvan);
		return hocalar;
	}
}

hoca *hocaSil(hoca *hocalar,int *h)
{
	int j,i;
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Silmek istediginiz ogretim uyesi ID giriniz : ");		
	scanf("%s",tempID);

	for(i=0;i<*h;i++)					//		1 5 9 12 17
	{
		if(strcmp(hocalar[i].hocaID,tempID)==0) // Girilen ID de�erinde bir ogruyesi varsa silme islemleri baslatiliyor
		{
			if(i==*h-1) // Son elemandir.
			{
				(*h)--;
				hocalar=(hoca*)realloc(hocalar,(*h)*sizeof(hoca));
				printf("\n\n\t\t\t Ogretim Uyesi ID :  %s  silindi..",tempID);
				return hocalar;
			}
			
			else // Arada ya da 
			{
								
				for(j=i;j<*h-1;j++) 
				{
					strcpy(hocalar[j].hocaID,hocalar[j+1].hocaID);
					strcpy(hocalar[j].hocaAd,hocalar[j+1].hocaAd);
					strcpy(hocalar[j].hocaSoyad,hocalar[j+1].hocaSoyad);
					strcpy(hocalar[j].unvan,hocalar[j+1].unvan);
				}	
			}
			(*h)--;
			hocalar=(hoca*)realloc(hocalar,(*h)*sizeof(hoca));
			printf("\n\n\t\t\t Ogretim Uyesi ID :  %s  silindi..",tempID);
			return hocalar;
		}
	}
					
		printf("\n\n\t\t\t Ogretim Uyesi ID :  %s  olan ogretim uyesi bulunmamaktadir..",tempID);			
		return hocalar;
}

hoca *hocaGuncelle(hoca *hocalar,int h)
{
	char tempAd[20];
	char tempSoyad[20];
	char tempUnvan[20];
	int j,i;
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Guncellemek istediginiz ogretim uyesi ID  : ");		
	scanf("%s",tempID);

	for(i=0;i<h;i++)					//		1 5 9 12 17
	{
		if(strcmp(hocalar[i].hocaID,tempID)==0) 
		{
			printf("\tOgretim Uyesi Yeni Ad    : "); scanf("%s",tempAd);	
			printf("\tOgretim Uyesi Yeni Soyad : "); scanf("%s",tempSoyad);
			printf("\tOgretim Uyesi Yeni Unvan : "); scanf("%s",tempUnvan);
			strcpy(hocalar[i].hocaAd,tempAd);
			strcpy(hocalar[i].hocaSoyad,tempSoyad);
			strcpy(hocalar[i].unvan,tempUnvan);
			return hocalar;
			
		}
	}
	printf("\n\n Guncellenmek istenen degere ait ogretim uyesi bulunmamaktadir. ");
	return hocaGuncelle(hocalar,h);
}
		
ders *dersEkle(ders *dersler,int *h2,char temp1[20])
{
	char tempID[20];
	char bos;
	int i;
	if(*h2==0)
	{
		(*h2)++;
		//printf("%d",*h);
		dersler=(ders*)malloc((*h2)*sizeof(ders));
		strcpy(dersler[(*h2)-1].dershoca.hocaID,temp1);
		printf("\n\tDers Kodu  : "); scanf("%s",dersler[(*h2)-1].dersKod);
		scanf("%c",&bos);
		printf("\tDers Ad    : "); gets(dersler[(*h2)-1].dersAd);	
		printf("\tKredisi    : "); scanf("%d",&dersler[(*h2)-1].kredi);
		printf("\tKontenjani : "); scanf("%d",&dersler[(*h2)-1].kont);
		return dersler;
	}
	else
	{
		tempID[0]='\0';
		printf("\n\tDers Kodu   : "); 
		scanf("%s",tempID);
		for(i=0;i<*h2;i++)
		{
			if(strcmp(dersler[i].dersKod,tempID)==0) 
			{
				printf("\n\n\t\t\t\t\t Girdiginiz Ders Kodu sistemde mevcut! Lutfen baska bir Ders Kodu giriniz.. \n ");
				return dersler;				
			}
		}
		(*h2)++;
		dersler=(ders*)realloc(dersler,(*h2)*sizeof(ders));
		strcpy(dersler[(*h2)-1].dershoca.hocaID,temp1);
		strcpy(dersler[(*h2)-1].dersKod,tempID);
		scanf("%c",&bos);
		printf("\tDers Ad     : "); gets(dersler[(*h2)-1].dersAd);	
		printf("\tKredisi     : "); scanf("%d",&dersler[(*h2)-1].kredi);
		printf("\tKontenjani  : "); scanf("%d",&dersler[(*h2)-1].kont);
		return dersler;
	}
}	
	
ders *dersSil(ders *dersler,int *h2)
{
	
	
	int j,i;
	char tempID[20];
	tempID[0]='\0';
	printf("\n\n Silmek istediginiz Ders Kodunu giriniz : ");		
	scanf("%s",tempID);

	for(i=0;i<*h2;i++)					//		1 5 9 12 17
	{
		if(strcmp(dersler[i].dersKod,tempID)==0) 
		{
			if(i==*h2-1) // Son elemandir.
			{
				(*h2)--;
				dersler=(ders*)realloc(dersler,(*h2)*sizeof(ders));
				printf("\n\n\t\t\t Ders Kodu :  %s  silindi..",tempID);
				return dersler;
			}
			
			else // Arada ya da 
			{
								
				for(j=i;j<*h2-1;j++) 
				{
					strcpy(dersler[j].dersAd,dersler[j+1].dersAd);
					strcpy(dersler[j].dersKod,dersler[j+1].dersKod);
					strcpy(dersler[j].dershoca.hocaID,dersler[j+1].dershoca.hocaID);
					dersler[j].kredi=dersler[j+1].kredi;
					dersler[j].kont=dersler[j+1].kont;
				}	
			}
			(*h2)--;
			dersler=(ders*)realloc(dersler,(*h2)*sizeof(ders));
			printf("\n\n\t\t\t Ders Kodu :  %s  silindi..",tempID);
			return dersler;
		}
	}
					
		printf("\n\n\t\t\t Ders Kodu :  %s  olan ders bulunmamaktadir..",tempID);			
		return dersler;
}

ders *dersGuncelle(ders *dersler,int h2,char temp1[20])
{
	char tempAd[20];
	int tempKredi;
	int tempKont;
	int j,i;
	char tempID[20];
	
	
	printf("\n\n Guncellemek istediginiz Dersin Kodu  : ");		
	scanf("%s",tempID);

	for(i=0;i<h2;i++)					//		1 5 9 12 17
	{
		if(strcmp(dersler[i].dersKod,tempID)==0) 
		{
			strcpy(dersler[i].dershoca.hocaID,temp1);
			printf("\tDersin Yeni Kredisi    : "); scanf("%d",&tempKredi);
			printf("\tDersin Yeni Kontenjani : "); scanf("%d",&tempKont);
			dersler[i].kredi=tempKredi;
			dersler[i].kont=tempKont;
			return dersler;
			
		}
	}
	printf("\n\n Guncellenmek istenen degere ait Ders Kodu bulunmamaktadir. ");
	return dersGuncelle(dersler,h2,temp1);
}
ogr *ogrEkle(ogr *ogrler,int *h3)
{
	char tempID[15];
	int i;
	if(*h3==0) 
	{
		(*h3)++;
		ogrler=(ogr*)malloc((*h3)*sizeof(ogr));
		printf("\n\tOgrenci No       : "); scanf("%s",ogrler[(*h3)-1].ogrNo);
		printf("\tOgrenci Ad       : "); scanf("%s",ogrler[(*h3)-1].ogrAd);	
		printf("\tOgrenci Soyad    : "); scanf("%s",ogrler[(*h3)-1].ogrSoyad);
		printf("\tOgrenci TopDers  : 0             (Ogrenci yeni eklendigi icin suan aldigi ders otomatik 0 atandi)\n");
		printf("\tOgrenci TopKredi : 0             (Ogrenci yeni eklendigi icin suan aldigi kredi otomatik 0 atandi)\n");
		ogrler[(*h3)-1].topKredi=0;
		ogrler[(*h3)-1].toplamDers=0;
		return ogrler;
	}
	else
	{
		tempID[0]='\0';
		printf("\n\tOgrenci No       : ");
		scanf("%s",tempID);
		
		for(i=0;i<*h3;i++)
		{
			if(strcmp(ogrler[i].ogrNo,tempID)==0) 
			{
				printf("\n\t\t\t\t\t Girdiginiz Ogrenci No sistemde mevcut! Lutfen baska bir Ogrenci No giriniz.. \n ");
				return ogrler;				
			}
		}
		(*h3)++;
		ogrler=(ogr*)realloc(ogrler,(*h3)*sizeof(ogr));
		strcpy(ogrler[*h3-1].ogrNo,tempID);
		printf("\tOgrenci Ad       : "); scanf("%s",ogrler[(*h3)-1].ogrAd);	
		printf("\tOgrenci Soyad    : "); scanf("%s",ogrler[(*h3)-1].ogrSoyad);
		printf("\tOgrenci TopDers  : 0             (Ogrenci yeni eklendigi icin suan aldigi ders otomatik 0 atandi)\n");
		printf("\tOgrenci TopKredi : 0             (Ogrenci yeni eklendigi icin suan aldigi kredi otomatik 0 atandi)\n");
		ogrler[(*h3)-1].topKredi=0;
		ogrler[(*h3)-1].toplamDers=0;
		
		return ogrler;
	}
}


ogr *ogrSil(ogr *ogrler,int *h3,kayit *kayitlar,int h4)
{
	int j,i,k;
	char tempID2[20]="Birakti";
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Silmek istediginiz Ogrenci No giriniz : ");		
	scanf("%s",tempID);

	for(i=0;i<*h3;i++)					//		1 5 9 12 17
	{
		if(strcmp(ogrler[i].ogrNo,tempID)==0) 
		{
			if(i==*h3-1) // Son elemandir.
			{
				(*h3)--;
				ogrler=(ogr*)realloc(ogrler,(*h3)*sizeof(ogr));
				printf("\n\n\t\t\t Ogr No :  %s  silindi..",tempID);
				if(h4>0)
				{
					for(k=0;k<h4;k++)
					{
						if(strcmp(kayitlar[k].ogrbilg.ogrNo,tempID)==0)
						{
							strcpy(kayitlar[k].ogrDurum,tempID2);
							printf("\n\nt\t\t\t Kayitli oldugu %s kodlu dersteki kaydi 'Birakti' olarak guncellendi.. ",kayitlar[k].dersbilg.dersKod);
						}
					}
					
				}
				
				return ogrler;
			}
			
			else // Arada ya da 
			{
								
				for(j=i;j<*h3-1;j++) 
				{
					strcpy(ogrler[j].ogrAd,ogrler[j+1].ogrAd);
					strcpy(ogrler[j].ogrSoyad,ogrler[j+1].ogrSoyad);
					strcpy(ogrler[j].ogrNo,ogrler[j+1].ogrNo);
					ogrler[j].topKredi=ogrler[j+1].topKredi;
					ogrler[j].toplamDers=ogrler[j+1].toplamDers;
				}	
			}
			(*h3)--;
			ogrler=(ogr*)realloc(ogrler,(*h3)*sizeof(ogr));
			printf("\n\n\t\t\t Ogr No :  %s  silindi..",tempID);
			if(h4>0)
			{
				for(k=0;k<h4;k++)
				{
					if(strcmp(kayitlar[k].ogrbilg.ogrNo,tempID)==0)
					{
						strcpy(kayitlar[k].ogrDurum,tempID2);
						printf("\n\nt\t\t\t Kayitli oldugu %s kodlu dersteki kaydi 'Birakti' olarak guncellendi.. ",kayitlar[k].dersbilg.dersKod);
					}
				}
					
			}
			return ogrler;
		}
	}
					
		printf("\n\n\t\t\t Ogr No :  %s  olan ogrenci bulunmamaktadir..",tempID);				
		return ogrler;
}

ogr *ogrGuncelle(ogr *ogrler,int h3){
	
	char tempAd[20];
	char tempSoyad[20];
	int j,i;
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Guncellemek istediginiz Ogrenci No : ");		
	scanf("%s",tempID);

	for(i=0;i<h3;i++)					//		1 5 9 12 17
	{
		if(strcmp(ogrler[i].ogrNo,tempID)==0) 
		{
			printf("\n\tOgrenci Yeni Ad    : "); scanf("%s",tempAd);	
			printf("\tOgrenci Yeni Soyad : "); scanf("%s",tempSoyad);
			strcpy(ogrler[i].ogrAd,tempAd);
			strcpy(ogrler[i].ogrSoyad,tempSoyad);
			return ogrler;
			
		}
	}
	printf("\n\n\t\t\tGuncellenmek istenen Ogrenci No bulunmamaktadir. ");
	return ogrGuncelle(ogrler,h3);
	
}

kayit *kayitEkle(kayit *kayitlar,int *h4,ders *dersler,int h2,ogr *ogrler,int h3,int maxKredi,int maxDers)
{
	int count,i,j;
	int tmp1,tmp2;
	int onay=0; 
	int onay2=0; 
	char temp1[20]; char temp2[20]; char temp3[20]="Kayitli";
	temp1[0]='\0';
	temp2[0]='\0';
	while(onay2!=1)
	{
	 	printf("\n\n\tLutfen ders kaydi yapacak Ogrenci No giriniz :");
	 	scanf("%s",temp2);
 	
	 	for(i=0;i<h3;i++)
	 	{
	 		if(strcmp(ogrler[i].ogrNo,temp2)==0)
	 		{
	 			onay2=1;
	 			tmp2=i;
			}
		}
		if(onay2==0)
		{
			count=0;
			printf("\n\t\t\t\t Girilen degere ait Ogrenci bulunmamaktadir..Lutfen farkli bir Ogrenci No deneyiniz.\n");
			printf("\n\n\n\t\t\t --- Mevcut olan Ogrenci bilgileri ---\n\n");				
		
			for(i=0;i<h3;i++)
			{
				count++;
				printf("    No: %s  Ad: %s %s",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad);
				if(count%4==0)		
				{
					printf("\n\n");
				}
			}
		}
		
	}
										
	onay2=1;
	while(onay!=1)				 
	{
		printf("\n\n\tLutfen ogrencinin kayit olacagi Ders Kodunu giriniz..  ");
	 	scanf("%s",temp1);
	 	for(i=0;i<h2;i++)
		{
									 						 		 
			if(strcmp(dersler[i].dersKod,temp1)==0)
	 		{
	 			tmp1=i;
	 			onay=1;			
			}							
		}
		
		if(onay==0)
		{
			count=0;				
			printf("\n\t\t\t\t Girilen degere ait Ders bulunmamaktadir..Lutfen farkli bir Ders Kodu deneyiniz.\n");
			printf("\n\n\t\t\t --- Mevcut olan Dersler ve Kodlari ---\n\n");
			for(i=0;i<h2;i++)
			{
				count++;
				printf("  Ders Kodu: %s  Ad: %s ",dersler[i].dersKod,dersler[i].dersAd);
				if(count%4==0)
				{
					printf("\n\n");
				}
			}
		}
	}
		onay=1;
		
		if(*h4==0)
		{
			(*h4)++;
			kayitlar=(kayit*)malloc((*h4)*sizeof(kayit));
			strcpy(kayitlar[(*h4)-1].ogrbilg.ogrNo,temp2);
			strcpy(kayitlar[(*h4)-1].dersbilg.dersKod,temp1);
			printf("\n\tOgrencinin Kayit Durumu : %s ",temp3);
			strcpy(kayitlar[(*h4)-1].ogrDurum,temp3);
			printf("\n\tOgrencinin Kayit Oldugu Tarih : "); scanf("%s",kayitlar[(*h4)-1].kayitTarih);
			ogrler[tmp2].topKredi+=dersler[tmp1].kredi;
			ogrler[tmp2].toplamDers++;
			return kayitlar;
		}
		else if(*h4>0)
		{
			for(i=0;i<*h4;i++)
			{
				if(strcmp(kayitlar[i].ogrbilg.ogrNo,temp2)==0 && strcmp(kayitlar[i].dersbilg.dersKod,temp1)==0)
				{
					printf("\n\n\t\tUYARI!!!      --- Ogrenci bu dersi zaten aliyor!!--- ");
					return kayitlar;
				}
			}
			ogrler[tmp2].topKredi+=dersler[tmp1].kredi;
			ogrler[tmp2].toplamDers++;
			if(ogrler[tmp2].topKredi>maxKredi)
			{
				printf("\n\n\t\t No : %s   %s %s ogrencisi bu dersi aldigi takdirde kredisi %d olarak maxKredi sinirini asmaktadir.. (OGRENCI DERSI ALAMAZ!)",ogrler[tmp2].ogrNo,ogrler[tmp2].ogrAd,ogrler[tmp2].ogrSoyad,ogrler[tmp2].topKredi);
				ogrler[tmp2].topKredi-=dersler[tmp1].kredi;
				return kayitlar;
			}
			else if(ogrler[tmp2].toplamDers>maxDers)
			{
				printf("\n\n\t\t No : %s   %s %s ogrencisi bu dersi aldigi takdirde ders sayisi %d olarak maxDers sinirini asmaktadir.. (OGRENCI DERSI ALAMAZ!)",ogrler[tmp2].ogrNo,ogrler[tmp2].ogrAd,ogrler[tmp2].ogrSoyad,ogrler[tmp2].toplamDers);
				ogrler[tmp2].toplamDers--;
				return kayitlar;
			}
			else
			{
				(*h4)++;
				kayitlar=(kayit*)realloc(kayitlar,(*h4)*sizeof(kayit));
				strcpy(kayitlar[(*h4)-1].ogrbilg.ogrNo,temp2);
				strcpy(kayitlar[(*h4)-1].dersbilg.dersKod,temp1);
				printf("\n\tOgrencinin Kayit Durumu : %s ",temp3);
				strcpy(kayitlar[(*h4)-1].ogrDurum,temp3);
				printf("\n\tOgrencinin Kayit Oldugu Tarih : "); scanf("%s",kayitlar[(*h4)-1].kayitTarih);
				return kayitlar;
			}
		}
}
kayit *kayitSil(kayit *kayitlar,int h4,ders *dersler,int h2,ogr *ogrler,int h3)
{
	int count,i,j;
	int tmp1=0;
	int tmp2=0;
	int onay=0; 
	int onay2=0; 
	char temp1[20]; char temp2[20]; char temp3[20]="Birakti";
	temp1[0]='\0';
	temp2[0]='\0';
	while(onay2!=1)
	{
	 	printf("\n\n\t Ders kaydini sileceginiz Ogrenci No :");
	 	scanf("%s",temp2);
 	
	 	for(i=0;i<h3;i++)
	 	{
	 		if(strcmp(ogrler[i].ogrNo,temp2)==0)
	 		{
	 			onay2=1;
	 			tmp2=i;
			}
		}
		if(onay2==0)
		{
			count=0;
			printf("\n\t\t\t\t Girilen degere ait Ogrenci bulunmamaktadir..Lutfen farkli bir Ogrenci No deneyiniz.\n");
			printf("\n\n\n\t\t\t --- Mevcut olan Ogrenci bilgileri ---\n\n");				
		
			for(i=0;i<h3;i++)
			{
				count++;
				printf("    No: %s  Ad: %s %s",ogrler[i].ogrNo,ogrler[i].ogrAd,ogrler[i].ogrSoyad);
				if(count%4==0)		
				{
					printf("\n\n");
				}
			}
		}
		
	}
										
	onay2=1;
	while(onay!=1)				 
	{
		printf("\n\n\tOgrenci No'su girilen ogrencenin kaydi silinecegi Ders Kodu :  ");
	 	scanf("%s",temp1);
	 	for(i=0;i<h2;i++)
		{
									 						 		 
			if(strcmp(dersler[i].dersKod,temp1)==0)
	 		{
	 			tmp1=i;
	 			onay=1;			
			}							
		}
		
		if(onay==0)
		{
			count=0;				
			printf("\n\t\t\t\t Girilen degere ait Ders bulunmamaktadir..Lutfen farkli bir Ders Kodu deneyiniz.\n");
			printf("\n\n\t\t\t --- Mevcut olan Dersler ve Kodlari ---\n\n");
			for(i=0;i<h2;i++)
			{
				count++;
				printf("  Ders Kodu: %s  Ad: %s ",dersler[i].dersKod,dersler[i].dersAd);
				if(count%4==0)
				{
					printf("\n\n");
				}
			}
		}
	}
		onay=1;
			
		for(i=0;i<h4;i++)
		{
			if(strcmp(kayitlar[i].dersbilg.dersKod,temp1)==0 && strcmp(kayitlar[i].ogrbilg.ogrNo,temp2)==0)
			{
				strcpy(kayitlar[i].ogrDurum,temp3);
				printf("\n\n\t\t %s No'lu ogrencinin %s Kodlu ders kayit durumu 'Birakti' olarak degistirildi",temp2,temp1);
				ogrler[tmp2].topKredi-=dersler[tmp1].kredi;
				ogrler[tmp2].toplamDers--;
				return kayitlar;
			}
		}
		printf("\n\n\t\t %s No'lu ogrencinin %s Kodlu derse ait kaydi yok! ",temp2,temp1);
		return kayitSil(kayitlar,h4,dersler,h2,ogrler,h3);
	
}

void fonk1(ders *dersler,int h3,char temp1[20])
{
	int var=0;
	int i;
	for(i=0;i<h3;i++)
	{
		if(strcmp(dersler[i].dershoca.hocaID,temp1)==0)
		{
			printf("\n\n\t\t Ders Kodu : %s     Dersin Adi : %s",dersler[i].dersKod,dersler[i].dersAd);
			var=1;
		}
	}
	if(var==0)
	{
		printf("\n\n\tHocanin verdigi ders bulunmamaktadir..");
	}
}

void fonk2(kayit *kayitlar,int h4,ogr *ogrler,int h3,char temp1[20])
{
	int var=0;
	char temp2[20]="Kayitli";
	int i,j;
	printf("\n");
	for(i=0;i<h4;i++)
	{
		if(strcmp(kayitlar[i].dersbilg.dersKod,temp1)==0 && strcmp(kayitlar[i].ogrDurum,temp2)==0)
		{
			for(j=0;j<h3;j++)
			{
				if(strcmp(kayitlar[i].ogrbilg.ogrNo,ogrler[j].ogrNo)==0)
				{
					printf("\n\tOgrenci No : %s, Ogrenci Ad : %s %s",ogrler[j].ogrNo,ogrler[j].ogrAd,ogrler[j].ogrSoyad);
					var=1;
				}
			}
		}
	}
	if(var==0)
	{
		printf("\n\n\tVerilen ders koduna ait dersi alan ogrenci bulunmamaktadir..");
	}
	
}

void fonk3(kayit *kayitlar,int h4,ders *dersler,int h2,char temp1[20])
{
	int var=0;
	char temp2[20]="Kayitli";
	int i,j;
	printf("\n");
	for(i=0;i<h4;i++)
	{
		if(strcmp(kayitlar[i].ogrbilg.ogrNo,temp1)==0 && strcmp(kayitlar[i].ogrDurum,temp2)==0)
		{
			for(j=0;j<h2;j++)
			{
				if(strcmp(kayitlar[i].dersbilg.dersKod,dersler[j].dersKod)==0)
				{
					printf("\n\tDers Kod : %s, Ders Ad : %s ",dersler[j].dersKod,dersler[j].dersAd);
					var=1;
				}
			}
		}
	}
	if(var==0)
	{
		printf("\n\n\tVerilen ders koduna ait dersi alan ogrenci bulunmamaktadir..");
	}
	
}
void fonk4(kayit *kayitlar,int h4,ogr *ogrler,int h3,char temp1[20])
{
	int i,j;
	char tempDosya[30];
	tempDosya[0]='\0';
	strcpy(tempDosya,temp1);
	strcat(tempDosya,"_SINIFLISTESI.txt");
	FILE *fw;
	int var=0;
	char temp2[20]="Kayitli";
	printf("\n");
	fw=fopen(tempDosya,"w");
	for(i=0;i<h4;i++)
	{
		if(strcmp(kayitlar[i].dersbilg.dersKod,temp1)==0 && strcmp(kayitlar[i].ogrDurum,temp2)==0)
		{
			for(j=0;j<h3;j++)
			{
				if(strcmp(kayitlar[i].ogrbilg.ogrNo,ogrler[j].ogrNo)==0)
				{
					fprintf(fw,"\n\tOgrenci No : %s, Ogrenci Ad : %s %s",ogrler[j].ogrNo,ogrler[j].ogrAd,ogrler[j].ogrSoyad);
					var=1;
				}
			}
		}
	}
	if(var==0)
	{
		fprintf(fw,"\n\n\t Girilen Ogretim Uyesi ID'ye ait dersi alan ogrenci bulunmamaktadir..");
	}
	fclose(fw);
}
