#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,k;
    int satir,sutun,yemekSayisi,yenilenYem=0,yilanUzunluk=1;
    int yemekSayac=0,yilanYerlestirmeControl=0,oyunControl=1,hamleSayisi=0;
    int yemekX,yemekY,tempX,tempY;
    int oyunBitis=0;
    int oyunAlani[100][100];
    int yilanX[100];
    int yilanY[100];
    char yon;

    // Oyun alani boyutu tanimlamaları
    printf("Lutfen oyun alaninin satir ve sutun sayisini giriniz: ");
    scanf("%d %d",&satir,&sutun);

    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            oyunAlani[i][j]=-1;
        }
    }
    
    // Oyun alaninda bulunacak yemek sayisini tanimlama
    printf("Lutfen oyun alaninda bulunmasini istediginiz yemek sayisini giriniz: ");
    scanf("%d",&yemekSayisi);

    // Yemek oyun alanina sıgmiyorsa kullanicidan bir daha sayi girmesini istenir
    while(yemekSayisi>=satir*sutun)
    {
        printf("Girdiginiz yemek sayisi oyun alanina sigmiyor! Lutfen tekrar giriniz: ");
        scanf("%d",&yemekSayisi);
    }

    // Yemekler oyun alanina random yerlestirilir
    srand(time(NULL));
    while(yemekSayac<yemekSayisi)
    {
        yemekX=-1+rand()%sutun+1;
        yemekY=-1+rand()%satir+1;

        // Eger random secilen yerde zaten yemek varsa bos gecip bir daha random yer belirlenir
        if(oyunAlani[yemekY][yemekX]!=0)
        {
            oyunAlani[yemekY][yemekX]=0;
            yemekSayac++;
        }
    }

    // Yilan oyun alanina random yerlestirilir 
    while(yilanYerlestirmeControl==0)
    {
        yilanX[0]=-1+rand()%sutun+1;
        yilanY[0]=-1+rand()%satir+1;

        // Eger yilani yerlestirecek yerde yemek varsa bos gecip bir daha random yer belirlenir
        if(oyunAlani[yilanY[0]][yilanX[0]]!=0)
        {
            oyunAlani[yilanY[0]][yilanX[0]]=1;
            yilanYerlestirmeControl=1;
        }
    }

    // Oyun daha baslamadan oyun alaninin yemekler ve yilanin oldugu hali kullaniciya gosterilir
    for(int i=0;i<satir;i++)
    {
        printf("|");
        for(int j=0;j<sutun;j++)
        {
            if(oyunAlani[i][j]==-1)
            {
                printf("  |");
            }

            // Yılanın uzunlugu 9'u gectiginde yazdirirken matriste satir kaymalari olmasın güzel gozuksun diye yapilan ufak düzenlemeler
            else if(oyunAlani[i][j]<10)
            {
                printf("%d |",oyunAlani[i][j]);
            }
            else if(oyunAlani[i][j]>=10)
            {
                printf("%d|",oyunAlani[i][j]);
            }
        }
        printf("\n");
    }

    // Hareket ve buyume islemleri
    printf("Hareket etmek istediginiz yonu giriniz: ");
    while(oyunControl==1)
    {
        scanf(" %c",&yon);
        hamleSayisi++;

        // Eger yilan bir birimden uzunsa butun birimleri kendinden bir sonrakine kaydırır
        if(yenilenYem>0)
        {
            yilanUzunluk=yenilenYem+1;
                
            tempX=yilanX[yenilenYem];
            tempY=yilanY[yenilenYem];
            
            for(i=yenilenYem;i>0;i--)
            {
                yilanX[i]=yilanX[i-1];
                yilanY[i]=yilanY[i-1];
            }
        }
        
        // Yukarı hareket islemi
        if(yon=='u')
        {
            // Yilan bir birimden uzunsa yilanin kafasininin yerini kendinden onceki birimin bir yukarisi yapar
            if(yenilenYem>0)
            {
                yilanX[0]=yilanX[1];
                yilanY[0]=yilanY[1]-1;
            }
            
            // Yilan bir birimden uzun degilse sadece kafasinin Y degiskenini azaltır yani yilan yukari hareket eder
            else
            {
                tempX=yilanX[yenilenYem];
                tempY=yilanY[yenilenYem];
                yilanY[0]--;
            }
        }

        // Asagi hareket islemi
        else if(yon=='d')
        {
            if(yenilenYem>0)
            {
                yilanX[0]=yilanX[1];
                yilanY[0]=yilanY[1]+1;
            }
            else
            {
                tempX=yilanX[yenilenYem];
                tempY=yilanY[yenilenYem];
                yilanY[0]++;
            }
        }

        // Saga hareket islemi
        else if(yon=='r')
        {
            if(yenilenYem>0)
            {
                yilanX[0]=yilanX[1]+1;
                yilanY[0]=yilanY[1];
            }
            else
            {
                tempX=yilanX[yenilenYem];
                tempY=yilanY[yenilenYem];
                yilanX[0]++;
            }
        }

        // Sola hareket islemi
        else if(yon=='l')
        {
            if(yenilenYem>0)
            {
                yilanX[0]=yilanX[1]-1;
                yilanY[0]=yilanY[1];
            }
            else
            {
                tempX=yilanX[yenilenYem];
                tempY=yilanY[yenilenYem];
                yilanX[0]--;
            }
        }
                
        // Yilanin yem yeme durumu
        if(oyunAlani[yilanY[0]][yilanX[0]]==0)
        {
            yenilenYem++;
            oyunAlani[tempY][tempX]=-1;
        }

        // Yilanin bos bir alana hareket etme durumu
        else if(oyunAlani[yilanY[0]][yilanX[0]]==-1)
        {
            oyunAlani[tempY][tempX]=-1;
        }

        // Yilanin kendini yeme durumu
        else if(oyunAlani[yilanY[0]][yilanX[0]]>0)
        {
            oyunControl=0;
            oyunBitis=1;
        }
                
        // Yilanin alanin disina cikmasi durumu
        if(yilanY[0]<0 || yilanY[0]>=satir || yilanX[0]<0 || yilanX[0]>=sutun)
        {
            oyunControl=0;
            oyunBitis=2;
        }
            
        // Butun yemlerin bitip oyunu kazanma durumu
        if(yenilenYem==yemekSayisi)
        {
            oyunControl=0;
            oyunBitis=3;
        }

        // Yilanin yeni koordinatlarini oyun alanina entegre eder.
        for(i=0;i<yilanUzunluk;i++)
        {
            oyunAlani[yilanY[i]][yilanX[i]]=i+1;
        }

        // Oyun alaninin yeni halini yazdirir
        for(int i=0;i<satir;i++)
        {
            printf("|");
            for(int j=0;j<sutun;j++)
            {
                if(oyunAlani[i][j]==-1)
                {
                    printf("  |");
                }
                else if(oyunAlani[i][j]<10)
                {
                    printf("%d |",oyunAlani[i][j]);
                }
                else if(oyunAlani[i][j]>=10)
                {
                    printf("%d|",oyunAlani[i][j]);
                }
            }
            printf("\n");
        }
            
        // Her turun sonunda eger oyun bitmemis ve bir sonraki tura gecilecekse gerekli bilgiler verilir
        if(oyunControl==1)
        {
            printf("Yapilan Hamle Sayisi: %d\n",hamleSayisi);
            printf("Gidilecek yon: ");
        }
    }

    // Yilanin kendini yemesi durumu
    if(oyunBitis==1)
    {
        printf("\n*****************\nKaybettiniz! Yilan kendini yedi!\nYilanin Buyuklugu: %d\nHamle Sayisi: %d\nKalan Yem: %d",yilanUzunluk,hamleSayisi,yemekSayisi-yilanUzunluk+1);
    }

    // Yilanin alandan disari cikmasi durumu
    else if(oyunBitis==2)
    {
        printf("\n*****************\nKaybettiniz! Yilan alandan disari cikti!\nYilanin Buyuklugu: %d\nHamle Sayisi: %d\nKalan Yem: %d",yilanUzunluk,hamleSayisi,yemekSayisi-yilanUzunluk+1);
    }

    // Yilanin butun yemleri bitirmesi durumu
    else
    {
        printf("\n*****************\nTebrikler Kazandiniz!\nYilanin Buyuklugu: %d\nHamle Sayisi: %d\n",yilanUzunluk,hamleSayisi);
    }
    
    return 0;
}