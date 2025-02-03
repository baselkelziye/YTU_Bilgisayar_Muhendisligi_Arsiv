#include <stdio.h>

int main()
{
    char D[5] =  {'a','e','r','k','s'};
    char kelimeler[][6] = {"asker","serak","kars","kase","sera","akse","ark","kes","kas","ser","sek","kar"};
    int puan, toplamSkor,inputUzunluk,karakterUzunluk;
    int harfControl,kelimeControl;
    int i,j,k;
    char input[10];

    // D dizisinin karakter sayisini hesaplama
    karakterUzunluk=0;
    for(i=0;i<10;i++)
    {
        if(D[i]!='\0')
        {
            karakterUzunluk++;
        }
    }
    
    // For dongusunde bulunan karakter sayisina kadar dizideki elemanlari yazdirma
    printf("Kullanabileceginiz karakterler: ");
    for(i=0;i<karakterUzunluk;i++)
    {
        printf("%c ",D[i]);
    }
    
    printf("\nLutfen tahmininizi giriniz: ");
    scanf("%s",&input);
    
    
    while(input[0]!='0')
    {
        // Inputun karakter sayısını hesaplama
        inputUzunluk=0;
        while(input[inputUzunluk]!='\0')
        {
            inputUzunluk++;
        }
        
        // Inputtaki harflerin dogru olup olmadigini kontrol etme 
        harfControl=0;
        for(i=0;i<inputUzunluk;i++)
        {
            for(j=0;j<10;j++)
            {
                if(input[i]!=D[j])
                {
                    harfControl=0;
                } 

                else
                {
                    harfControl=1;
                    j=10;
                } 
            }
        }

        if(harfControl==1)
        {
            // Bir harfin birden fazla kullanilip kullanilmadiginin kontrolunu gerceklestirme
            for(j=0;j<inputUzunluk-1;j++)
            {
                for(k=j+1;k<inputUzunluk;k++)
                {
                    if(input[j]==input[k])
                    {
                        k=inputUzunluk;
                        j=inputUzunluk;
                        harfControl=0;
                    }
                }
            }
        }

        // else if yapilirsa bir harf birden fazla varsa dongu ilk yukaridakine girip sonra da asagidaki if'e girmeden geciyordu bu yuzden iki ayri if actim.
        if(harfControl==0)
        {
            printf("Hatali harf kullanimi, puan: %d",-inputUzunluk);
            toplamSkor+=-inputUzunluk;
        }

        

        // Eger hatali harf kullanimi yoksa buraya girer
        if(harfControl==1)
        {
            // Inputun kelime dizisinde olup olmadigini karakter karakter kontrol etme
            int kelimeControl=0;
            for(i=0;i<100;i++)
            {
                j=0;
                while(j<inputUzunluk)
                {
                    if(kelimeler[i][j]==input[j] && kelimeler[i][j+1]=='\0')
                    {
                        kelimeControl=1;
                    }
                
                    else if(kelimeler[i][j]!=input[j])
                    {
                        kelimeControl=0;
                        j=inputUzunluk;
                    }
                    j++;
                }
            
                if(kelimeControl==1)
                {
                    // Kelimenin bir daha girilme ihtimalinden dolayi kelime arrayda null olarak degistirilir birdaha yazilirsa kullanici puan alamaz
                    for(k=0;k<inputUzunluk;k++)
                    {
                        kelimeler[i][k]='\0';
                    }
                    i=100;
                }
                    
            }

            // Input karakter dizisinde varsa buraya girer ve gerekli skor islemleri yapilir
            if(kelimeControl==1)
            {
                toplamSkor+=inputUzunluk;
                printf("Puan: +%d",inputUzunluk);
            }
            
            //Input karakter dizisinde yoksa buraya girer ve gerekli skor islemleri yapilir
            else if(kelimeControl==0)
            {
                toplamSkor+=-inputUzunluk;
                printf("Puan: -%d",inputUzunluk);
            }
        }
        
        // Yeni input degerini alir ve while döngüsü 0 girilmedigi surece tekrar eder
        printf("\nLutfen tahmininizi giriniz: ");
        scanf("%s",&input);
    }

    printf("\nOyun bitmistir. Tebrikler! Toplam puaniniz: %d",toplamSkor);
    
    return 0;
}