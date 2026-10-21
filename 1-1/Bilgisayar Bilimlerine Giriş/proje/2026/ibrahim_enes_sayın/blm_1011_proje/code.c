#include <stdio.h>
#include <time.h>   // Rastgelelik için kullandığımız kütüphanedir //
#include <stdlib.h>  // Ekrani temizlemek  için kullandığımız kütüphanedir //
#include <windows.h> // system("cls") ve Sleep için kullandığımız kütüphanedir//

int main() {
    
    setbuf(stdout, NULL);   // Tampon belleği kapatma kodudur (Çıktıların anında görünmesi için)//
    //değişkenlerimizi tanımladık//
    char oyun_alani[20][20];
    int N, M, mod, tercih, i, j, k, r, tur;
    int yer_degisikligi = 0, patlatilan = 0, devam = 1;

    srand(time(NULL)); // Rastgeleliği sağlayan bölümdür //

    // ------------------- GİRİŞ KISMI ------------------------------------------//
    printf("-Oyun alaninin boyutlarini giriniz (N M): ");
    scanf("%d %d", &N, &M);
    
    // Boyut güvenlik kontrolü//
    if (N > 20) N = 20;
    if (M > 20) M = 20;

    printf("-Oyun Modu (1: Oynama modu , 2: Kontrol modu): ");
    scanf("%d", &mod);

    // Tahtayı başta tamemen boş olarak tanımlama//
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) { oyun_alani[i][j] = ' '; }
    }

    // Tahtayı Doldurma bölümü//
    if (mod == 1) {
        char el[] = {'*', '/', '+', '%', 'O'};
        for (i = N / 2; i < N; i++) {
            for (j = 0; j < M; j++) { oyun_alani[i][j] = el[rand() % 5]; }
        }
    } else {
        printf("Oyun tahtasini giriniz:\n");
        for (i = N / 2; i < N; i++) {
            for (j = 0; j < M; j++) { scanf(" %c", &oyun_alani[i][j]); }
        }
    }

    // ------------------------------- OYUN DÖNGÜSÜ ------------------------------


    while (devam == 1) {
        
        //  Ekranı başta  tamamen temizliyoruzki (Sadece Mod 1'de) baştaki scanfler sonra görünmesin
        if(mod == 1){
            system("cls"); //panel temizleme komutu
        }

        //  Tahtayı oluşturma

        printf("\n");
        for (i = 0; i < N; i++) {
            printf("|");
            for (j = 0; j < M; j++) { printf(" %c ", oyun_alani[i][j]); }
            printf("|\n");
        }
        
        // Skorları Gösterme

        printf("\n[Yer Degistirme: %d | Patlatma: %d]\n", yer_degisikligi, patlatilan);

        // Bitiş Kontrolü

        int bitis = 0;
        for (j = 0; j < M; j++) { if (oyun_alani[0][j] != ' ') bitis = 1; }
        if (bitis == 1) { 
            printf("\nOyun Sonlandi - Oyun Alani Doldu!\n"); 
            devam = 0; 
            break; 
        }

        // Kullanıcıdan Seçim Al

        if (devam == 1) {
            printf("\n1) Yer Degistir  2) Patlat  0) Cikis\nSecim: ");
            scanf("%d", &tercih);

            if (tercih == 0) {
                devam = 0;
            } 
            else if (tercih == 1) { // ---------------------------------YER DEĞİŞTİRME-----------------------------------
                int r1, c1, r2, c2;
                printf("Koordinatlar (r1 c1 r2 c2): ");
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                r1--; c1--; r2--; c2--; // 0 tabanlıya çevirme
                
                // Koordinat Kontrolü
                if(r1>=0 && r1<N && c1>=0 && c1<M && r2>=0 && r2<N && c2>=0 && c2<M) {
                    
                    // Yer Değiştirme İşlemi
                    char t = oyun_alani[r1][c1];
                    oyun_alani[r1][c1] = oyun_alani[r2][c2];
                    oyun_alani[r2][c2] = t;
                    yer_degisikligi++;

                    //  ARA ANİMASYON 
                    if (mod == 1) {
                        system("cls"); // Ekranı temizliyorizki girdiğimiz koordinatlar daha sonra ekranda kalmasın diye
                        
                        // Güncel hali (kaydırmadan önce) çizme 
                        printf("\n");
                        for (i = 0; i < N; i++) {
                            printf("|");
                            for (j = 0; j < M; j++) { printf(" %c ", oyun_alani[i][j]); }
                            printf("|\n");
                        }
                        printf("\n[Yer Degistirme: %d | Patlatma: %d]\n", yer_degisikligi, patlatilan);
                        printf("\n...Taslar degisti, yeni satir geliyor...\n");
                        
                        Sleep(1500); // 1.5 saniye bekleme
                    }

                    //  Yukarı Kaydırma
                    for (i = 0; i < N - 1; i++) {
                        for (j = 0; j < M; j++) { oyun_alani[i][j] = oyun_alani[i + 1][j]; }
                    }
                    
                    //  Yeni Satır Ekleme
                    char el[] = {'*', '/', '+', '%', 'O'};
                    for (j = 0; j < M; j++) { oyun_alani[N - 1][j] = el[rand() % 5]; }
                
                } else {
                    printf("Hatali koordinat girdiniz!\n");
                    Sleep(1000);
                }
            } 
            else if (tercih == 2) { // -----------------------------------PATLATMA-----------------------------------------
                int pr, pc;
                printf("Patlatilacak Koordinat (r c): ");
                scanf("%d %d", &pr, &pc);
                pr--; pc--;
                //koordinat kontrolü ve boş hücre kontrolü
                if (pr >= 0 && pr < N && pc >= 0 && pc < M) { 
                    if (oyun_alani[pr][pc] == ' ') {
                        printf("Bos hucre patlatilamaz!\n");
                        Sleep(1000);
                    } else {
                        char h = oyun_alani[pr][pc];
                        int y = 0, d = 0;
                        
                        // Eşleşme Sayma

                        k = pc; while (k < M && oyun_alani[pr][k] == h) { y++; k++; }
                        r = pr; while (r < N && oyun_alani[r][pc] == h) { d++; r++; }

                        if (y >= 3 || d >= 3) {
                            int s = 0;



                            // En çok puan getireni patlatma 

                            if (y >= d) { 
                                for (k = 0; k < y; k++) { oyun_alani[pr][pc + k] = ' '; s++; } 
                            }
                            else { 
                                for (r = 0; r < d; r++) { oyun_alani[pr + r][pc] = ' '; s++; } 
                            }
                            patlatilan += s;

                            // Yerçekimi 

                            for (j = 0; j < M; j++) {
                                for (tur = 0; tur < N; tur++) {
                                    for (i = N - 1; i > 0; i--) {
                                        if (oyun_alani[i][j] == ' ' && oyun_alani[i - 1][j] != ' ') {
                                            oyun_alani[i][j] = oyun_alani[i - 1][j];
                                            oyun_alani[i - 1][j] = ' ';
                                        }
                                    }
                                }
                            }
                        } else {//patlama olma şartı sağlanmıyorsa 
                            printf("En az 3 ayni eleman yok!\n");
                            Sleep(1000);
                        }
                    }
                } else {//koordinat hatası
                    printf("Hatali koordinat!\n");
                    Sleep(1000);
                }
            }
        }
    }
    return 0;
}