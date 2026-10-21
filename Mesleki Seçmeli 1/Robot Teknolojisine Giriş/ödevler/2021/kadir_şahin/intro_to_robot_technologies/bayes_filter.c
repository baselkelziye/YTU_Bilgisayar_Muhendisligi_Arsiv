    #include <stdio.h>
    #include <conio.h>
    #include <stdlib.h>
    #include <time.h>               
    #include <math.h>               


    void bayes_filter(float*,float*,int,float,float,float,float,float,float,char);
    /*

    bayes_filter() fonksiyonunun parametreleri;

    belx_acik: kapÄ±nÄ±n acik olmasi icin oncul belief yani bir onceki iterasyonun son belief'i

    belx_kapali: aslinda bu parametreye bizim ornegimiz icin ihtiyac yoktu dogrudan fonksiyonun
                 icinde 1-belx_acik olarak bulabilirdik ama genel problemlerde sadece acik ve 
                 kapali durumundancok daha x rastgele degiskeni olabilecegi icin genel prosedur
                olarak parametreye dahil ettik
 
    per_or_act: bayes_filter fonksiyonumuz her iterasyon icin hem olcum guncelleme  
                hem de tahmin adminini yapabiliyor, bunlardan hangisini yapacagini 
                bu parametre ile gonderiyoruz

    ps_acik_acik: sensorun kapi gercekten acikken acik olcme dogrulugu
 
    ps_acik_kapali: sensorun kapi kapaliyken acik olcmesi yani false positive 
 
    pk_acik_it_acik: robot kolun acik kapiyi itmesiyle kapinin acik kalmasi olasiligi

    pk_acik_it_kapali: kapali kapinin itilme sonucu acilma olasiligi

    pk_acik_itme_acik: acik kapinin itmeden bagimsiz olarak 
                       acik kalmaya devam etmesi olasiligi (ortam sartlari)

    pk_acik_itme_kapali: kapali kapinin itmeden bagimsiz olarak acilabilmesi olasiligi (ruzgar vs)

    act_type: bayes_filter'i tahmin adimi icin kullanirken gonderilen robot kol komutu secimi

    */

    void bayes_filter(float* belx_acik, float* belx_kapali,int per_or_act,float ps_acik_acik,
                                float ps_acik_kapali,float pk_acik_it_acik,float pk_acik_it_kapali,
                             float pk_acik_itme_acik,float pk_acik_itme_kapali,char act_type){
        
        float ps_kapali_acik,ps_kapali_kapali,pk_kapali_it_acik,
        pk_kapali_it_kapali,pk_kapali_itme_acik,pk_kapali_itme_kapali;

        // kapali hipotezlerimiz icin gereken degerleri burada ayarlayabiliriz, 
        // cunku sadece acik ve kapali durumu var

        pk_kapali_it_acik=1-pk_acik_it_acik;
        pk_kapali_it_kapali=1-pk_acik_it_kapali;

        pk_kapali_itme_acik=1-pk_acik_itme_acik;
        pk_kapali_itme_kapali=1-pk_acik_itme_kapali;



        if(per_or_act==0){          //OLCUM GUNCELLE

            float mu=1/((ps_acik_acik*(*belx_acik))+(ps_acik_kapali*(*belx_kapali)));

                                //acik beliefi ile sensorun true positive'ini carpÄ±p
                                //kapali beliefi ile de false positive'ini carparak
                                //kapi acik olculme olasiligimizi buluruz,
                                //bu olasiligin tersi ise normalizasyonu veriyor
                            
            *belx_acik=mu*ps_acik_acik*(*belx_acik);   // P(kapi=acik | olcum=acik) icin bayes
            *belx_kapali=mu*ps_acik_kapali*(*belx_kapali); // P(kapi=kapali | olcum=acik) icin bayes
        }
        else{                       //TAHMIN

                                    // aslinde bizim ornegimiz icin kapali beliefleri
                                    // hesaplamaya gerek yok ama genel prosedur icin
                                    // tum beliefleri ayri olarak hesapladik

            if(act_type=='0')  // u_t=it 
            {
                *belx_acik=pk_acik_it_acik*(*belx_acik)+pk_acik_it_kapali*(*belx_kapali);  
                                            //P(xt=acik | u_t=it ,bel_xt-1=acik)
                                            // +  P(xt=acik | u_t=it ,bel_xt-1=kapali)  

                *belx_kapali=pk_kapali_it_acik*(*belx_acik)+pk_kapali_it_kapali*(*belx_kapali);
                                            //P(xt=kapali | u_t=it ,bel_xt-1=acik) 
                                            // +  P(xt=kapali | u_t=it ,bel_xt-1=kapali)
            }
            else{             // u_t= itme
                 
                *belx_acik=pk_acik_itme_acik*(*belx_acik)+pk_acik_itme_kapali*(*belx_kapali);
                                            //P(xt=acik | u_t=itme ,bel_xt-1=acik)
                                            // +  P(xt=acik | u_t=itme ,bel_xt-1=kapali)
                *belx_kapali=pk_kapali_itme_acik*(*belx_acik)+pk_kapali_itme_kapali*(*belx_kapali);
                                            //P(xt=kapali | u_t=itme ,bel_xt-1=acik) 
                                            // +  P(xt=kapali | u_t=itme ,bel_xt-1=kapali)

            }
        }
    }

    int main(){

        int i;
        char secim,act_type;


        float belx0_acik,belx0_kapali;       // t=0 icin belieflerimiz

        float ps_acik_acik;
        float ps_acik_kapali;

        float pk_acik_it_acik;
        float pk_acik_it_kapali;

        float pk_acik_itme_acik;
        float pk_acik_itme_kapali;

        float belx_old_acik,belx_rep;  // durma kosulu icin iterasyon oncesi beliefi
                                                  // iterasyon sonrasi beliefi degiskenlerde tutuyoruz,

                                                    // bazi durumlarda iterasyonlar surekli   
                                                    // 2 tane degeri uretmeye baslayip,
                                                    // durma kosulunu saglamadan sonsuz
                                                    // donguye girebiliyor 
                                                    //bunu cozmek icin mesela sadece 2 iterasyonda bir
                                                    // belief kaydetmek icin bir repeat beliefi tanimladik


        printf("Parametre degerleri icin secim yapiniz: \n\nRastgele:  [0] \nKullanici: [1]    ");

        secim=getch();
        printf("%c   \n\n", secim);

        if(secim=='0'){         // rastgele parametreler olusturuluyor

            srand(time(NULL));


            int tmp;

            tmp=rand()%100;
            printf("Oncul belief  (belx0_acik): 0.%d \n",tmp);    
            belx0_acik=tmp*0.01;         

            tmp=rand()%100;
            printf("Sensor  P(acik algila | acik): 0.%d \n",tmp);
            ps_acik_acik=tmp*0.01;  

            tmp=rand()%100;
            printf("Sensor  P(acik algila | kapali): 0.%d \n",tmp);
            ps_acik_kapali=tmp*0.01;  

            tmp=rand()%100;
            printf("Robot kolu P(acik(t) | it(t), acik(t-1) ): 0.%d \n",tmp);
            pk_acik_it_acik=tmp*0.01;  

            tmp=rand()%100;
            printf("Robot kolu P(acik(t) | it(t), kapali(t-1) ): 0.%d \n",tmp);
            pk_acik_it_kapali=tmp*0.01;

            tmp=rand()%100;
            printf("Robot kolu P(acik(t) | itme(t), acik(t-1) ): 0.%d \n",tmp);
            pk_acik_itme_acik=tmp*0.01;

            tmp=rand()%100;
            printf("Robot kolu P(acik(t) | itme(t), kapali(t-1) ): 0.%d \n\n",tmp);
            pk_acik_itme_kapali=tmp*0.01;

        }
        else{
            printf("Sensorun dogruluk,robot kolunun basari degerini ve oncul belief'i giriniz: \n\n");

            printf("Oncul belief   (belx0_acik):  ");
            scanf("%f",&belx0_acik);

            printf("Sensor   P(acik algila | acik):  ");
            scanf("%f",&ps_acik_acik);

            printf("Sensor   P(acik algila | kapali):  ");
            scanf("%f",&ps_acik_kapali);

            printf("Robot kolu P(acik(t) | it(t), acik(t-1) ):  ");
            scanf("%f",&pk_acik_it_acik);

            printf("Robot kolu P(acik(t) | it(t), kapali(t-1) ):  ");
            scanf("%f",&pk_acik_it_kapali);

            printf("Robot kolu P(acik(t) | itme(t), acik(t-1) ):  ");
            scanf("%f",&pk_acik_itme_acik);

            printf("Robot kolu P(acik(t) | itme(t), kapali(t-1) ):  ");
            scanf("%f",&pk_acik_itme_kapali);

            printf("\n\n");
        }

        
        

        i=1;

        belx0_kapali=1-belx0_acik;     // ilk iterasyonumuz icin kapali oncul beliefini 
                                       // 1-belx0_acik olarak ayarliyoruz,
                                       // sadece acik ve kapali durumlarindan daha fazla 
                                       // durum olsaydi bunu yapamazdik

        printf("\n Uyari: Iterasyonlarda belief degerinin 1'e veya 0'a cok yaklasmasi\n");
        printf("durumunda derleyici tarafindan 1'e veya 0'a yuvarlanarak ekrana \n");
        printf("bastirilabilmektedir.     Bu bir hata degildir. \n\n");

        printf("\n Iterasyonlarda u_t komutu verirken \n u_t= it  : [0]\n u_t= itme: [1]   giriniz\n\n");
        



        printf("belx_acik t=0 :  0.%d0000   belx_kapali t=0 : 0.%d0000  ",
                                         (int)roundf(belx0_acik*100),(int)roundf(belx0_kapali*100));
                                        // round islemini, derleyici tarafindan yanlis 
                                        // bastirilan float degerini duzgun bastirmak icin
                                        // sadece ilk belief icin yaptik.

        belx_old_acik=belx0_acik; 

        do{ 
            belx_old_acik=belx0_acik;  // iterasyon oncesinde, durma kosulu kontrolu icin 
                                       // onceki beliefimizi degiskende tuttuk

            if(i%2==1){                // ard arda sonsuz donguye giren 2 belief denk gelme
                                       // ihtimali icin her 2 seferde bir beliefi de ayrica kaydediyoruz
                                       // durma kosulu icin yuksek bir hassasiyet degeri belirlersek
                                       // bu ihtimal gerceklesebiliyor
                belx_rep=belx_old_acik;
            }

            printf("   u_t? :  ");
            act_type=getch();
            printf("%c   \n", act_type);



            //      TAHMIN 

            bayes_filter(&belx0_acik,&belx0_kapali,1,ps_acik_acik,ps_acik_kapali,
            pk_acik_it_acik,pk_acik_it_kapali,pk_acik_itme_acik,pk_acik_itme_kapali,act_type); 
            

            //      OLCUM GUNCELLEMESI

            bayes_filter(&belx0_acik,&belx0_kapali,0,ps_acik_acik,ps_acik_kapali,
            pk_acik_it_acik,pk_acik_it_kapali,pk_acik_itme_acik,pk_acik_itme_kapali,act_type);
           
            printf("belx_acik t=%d :  %f   belx_kapali t=%d : %f  ",i,belx0_acik,i,belx0_kapali);

            i++;

        }while((fabs(belx_old_acik-belx0_acik)>0.00001)&&(belx_rep!=belx0_acik));
                                //iterasyon oncesi ve sonrasi belief 
                                // farki belli bir degerin altina    
                                // duserse iterasyonu durduruyoruz cunlu o beliefi 
                                // 

                                //  surekli ayni komut girilme durumunda
                                //       kapinin durumu hakkinda bir beliefe
                                //       yuksek bir hassasiyet derecesinde sahip olmak
                                // icin iterasyondan sonra belief'in artik degismeme yani
                                //  (belx_old_acik!=belx0_acik)  kosulunu da kullanabilirdik
                                
                                // mesela surekli itme komutu verirken kapinin acik olma 
                                // belief'i artik degismiyorsa daha fazla itmeye gerek yoktur

                                //belx_rep belief'i de tekrarlayan 2 belief ihtimali
                                //icin kontrol ettik

        printf("\n Cikis yapmak icin [ENTER] 'a basin ");

        

        while(secim!=13){
            secim=getch();
        }
 
        return 0;
    }