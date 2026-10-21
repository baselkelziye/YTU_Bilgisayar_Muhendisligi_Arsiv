#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void shift_right(int* arr, int times, int n);
bool is_valid(int** board, int n);
bool backtrack(int** board, int n, int row, int mode);
int** get_board(int n);
void display_numeric_board(int** board, int n);
void display_colorful_board(int** board, int n, int mode);

/*
Input olarak girilebilecek renkler:
- kirmizi, mavi, yesil, sari, 
- turuncu, mor, siyah, beyaz, 
- gri, lacivert, pembe, turkuaz

Toplam 12 renk var.
 */


int main() {

    int i, j, N, mode;
    char tmp;
    printf("\n\n  Matrisin boyutunu giriniz: ");
    scanf("%d", &N);
    int** board = get_board(N);

    printf("\n  Choose mode:  \n1) Normal Mode\n2) Detailed Mode\nChoice: ");
    scanf("%d", &mode);
    scanf("%c", &tmp); //escape for enter char
    switch (mode){
        
    case 1:
        display_numeric_board(board, N);
        display_colorful_board(board, N, mode);
        for (i = 0; i < N; i++) {
            free(board[i]);
        }
        free(board);
        break;

    case 2:
        backtrack(board, N, 0, mode);
        display_numeric_board(board, N);
        display_colorful_board(board, N, 1);
        for (i = 0; i < N; i++) {
            free(board[i]);
        }
        free(board);
        break;
    
    default:
        printf("Not an available choice.");
        break;
    }

    return 0;
}



/**
 * @brief Satiri saga kaydirir
 * 
 * Bu fonksiyon, tamsayi dizisi row ve tamsayi n gibi girdiler alir
 * ve row dizisinin elemanlarini n pozisyon saga kaydirir. 
 * Bunu yapmak icin, gecici bir dizi temp olusturur ve row
 * dizisinin elemanlarini temp dizisine su sekilde kopyalar: 
 * temp dizisinin i indeksli elemani, row dizisinin (i + n) % size 
 * pozisyon sagindaki elemanidir.
 * 
 * ornegin, row dizisi {1, 2, 3, 4, 5} ve n degeri 2 ise, 
 * sonuc olarak olusacak temp dizisi {4, 5, 1, 2, 3} olacaktir. 
 * Fonksiyon daha sonra temp dizisinin elemanlarini row dizisine 
 * tekrar kopyalar.
 * 
 * Dizinin boyutu "size" adli girdi parametresi ile verilir.
 *** "n" degiskeni bu fonksiyona ozel farkli amaca sahiptir.
 *** Diger fonksiyonlarda dizinin boyut bilgisi (burasi icin size)
 *** icin n degeri kullanilir.
 *
 * Bu, dizinin eleman sayisini belirlemek ve dizinin basina donmek
 * icin kullanilir, indeks dizinin boyutunu astiginda. 
 * ornegin, size degeri 5 ise, (i + n) % bize ifadesi 0 ile 4 arasinda
 * (dahil) bir indeks degeri uretecektir.
 * 
 * @param row 
 * @param n 
 * @param size 
 */
void shift_right(int* row, int n, int size) {
    int temp[size], i, j;
    for (i = 0; i < size; i++) {
        temp[(i + n) % size] = row[i];
    }
    for (i = 0; i < size; i++) {
        row[i] = temp[i];
    }
}


/**
 * @brief Tahtanin gecerliligini kontrol eder
 * 
 * Bu fonksiyon, tamsayi dizisi board ve tamsayi n gibi 
 * girdiler alir ve board'un gecerli bir tahta olup 
 * olmadigini kontrol eder. Bunu yapmak icin, board'un her 
 * sutununun yinelenen degerler icerip icermedigini kontrol eder.
 * 
 * Fonksiyon, dis for dongusuyle board'un her satirini dolasmaya baslar. 
 * Her satir icin, 13 tane tamsayidan olusan bir counts dizisi olusturur 
 * ve memset kullanarak tum elemanlarini 0'a initalize eder. 
 * Daha sonra, ic for dongusuyle satirin her sutununu dolasir
 * ve counts dizisinin board[j][i] indeksindeki degeri artirir. 
 * Eger counts[board[j][i]] degeri zaten 1'den buyukse, fonksiyon 
 * hemen false degerini dondurur ve boylece board'un gecerli 
 * bir tahta olmadigini gosterir. 
 * 
 * Eger fonksiyon, false dondurmeden tum satirlari ve 
 * sutunlari dolasirsa, true degerini dondurur ve boylece
 * board'un gecerli bir tahta oldugunu gosterir.
 * 
 * @param board 
 * @param n 
 * @return true 
 * @return false 
 */
bool is_valid(int** board, int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        int counts[13];
        memset(counts, 0, 13 * sizeof(int));
        for (j = 0; j < n; j++) {
            counts[board[j][i]]++;
            if (counts[board[j][i]] > 1) {
                return false;
            }
        }
    }
    return true;
}


/**
 * @brief Tahtayi cozmeye calisir
 * 
 * Fonksiyon, tahtanin row. satirindan baslayarak tahtadaki her 
 * satira bir deger koymayi dener. row. satirdaki deger konuldugunda, 
 * fonksiyon bir sonraki satira gecer ve bu islemi tekrar eder ve 
 * n. satira ulasana kadar devam eder. Eger fonksiyon n. satira ulasirsa,
 * is_valid fonksiyonunu cagirarak tahtadaki gecerli cozum olup
 * olmadigini kontrol eder. Eger gecerli bir cozum ise, fonksiyon
 * true dondurur. Degilse, fonksiyon row. satira farkli bir deger
 * koymayi dener ve bu islemi tekrar eder ve gecerli bir cozum bulana
 * kadar devam eder veya tum olasi degerleri dener ve hala bir cozum
 * bulamazsa, fonksiyon false dondurur.
 * 
 * @param board 
 * @param n 
 * @param row 
 * @param mode 
 * @return true 
 * @return false 
 */
bool backtrack(int** board, int n, int row, int mode) {
    int i;
    int* original_row;

    if (row == n)
        return is_valid(board, n); 

    for (i = 0; i < n; i++) {
        original_row = malloc(n * sizeof(int));
        memcpy(original_row, board[row], n * sizeof(int)); 
        shift_right(board[row], i, n);
        if (backtrack(board, n, row + 1, mode)) {
            if(mode == 2 && !(is_valid(board, n)))
                display_numeric_board(board, n);
            
            free(original_row);
            return true;
        }
        memcpy(board[row], original_row, n * sizeof(int)); 
        free(original_row);
    }

    if(mode == 2)
        display_numeric_board(board, n);

    return false;
}





/**
 * @brief Tahtayi kullanicidan alir
 * 
 * @param n 
 * @return int** 
 */
int** get_board(int n){

    int i, j;
    char color[12];

    int** board = malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%s", color);
            if (strcmp(color, "kirmizi") == 0) {
                board[i][j] = 1;
            } else if (strcmp(color, "mavi") == 0) {
                board[i][j] = 2;
            } else if (strcmp(color, "yesil") == 0) {
                board[i][j] = 3;
            } else if (strcmp(color, "sari") == 0) {
                board[i][j] = 4;
            } else if (strcmp(color, "turuncu") == 0) {
                board[i][j] = 5;
            } else if (strcmp(color, "mor") == 0) {
                board[i][j] = 6;
            } else if (strcmp(color, "siyah") == 0) {
                board[i][j] = 7;
            } else if (strcmp(color, "beyaz") == 0) {
                board[i][j] = 8;
            } else if (strcmp(color, "gri") == 0) {
                board[i][j] = 9;
            } else if (strcmp(color, "lacivert") == 0) {
                board[i][j] = 10;
            } else if (strcmp(color, "pembe") == 0) {
                board[i][j] = 11;
            } else if (strcmp(color, "turkuaz") == 0) {
                board[i][j] = 12;
            } else {
                printf("Hatali renk girisi\n");
                return 0;
            }
        }
    }
    return board;
}


/**
 * @brief Tahtanin sayisal halini ekrana basar
 * 
 * @param board 
 * @param n 
 */
void display_numeric_board(int** board, int n){
    int i,j;
    printf("\nSayisal Tahta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            printf("%d ", board[i][j]);
        printf("\n");
    }
}


/**
 * @brief Tahtanin renkli halini ekrana basar
 * 
 * @param board 
 * @param n 
 * @param mode 
 */
void display_colorful_board(int** board, int n, int mode){
    
    int i,j;
    if (backtrack(board, n, 0, mode)) {
        if(mode == 1)
            printf("\n\nTahta duzenlendi:) Artik her sutun rengarenk.\n____________________________________________________\n\n");
        else
            printf("\n\nTahta duzenlendi:\n____________________________________________________\n\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(board[i][j] == 1){
                    printf("kirmizi ");
                } else if(board[i][j] == 2){
                    printf("mavi ");
                } else if(board[i][j] == 3){
                    printf("yesil ");
                } else if(board[i][j] == 4){
                    printf("sari ");
                } else if(board[i][j] == 5){
                    printf("turuncu ");
                } else if(board[i][j] == 6){
                    printf("mor ");
                } else if(board[i][j] == 7){
                    printf("siyah ");
                } else if(board[i][j] == 8){
                    printf("beyaz ");
                } else if(board[i][j] == 9){
                    printf("gri ");
                } else if(board[i][j] == 10){
                    printf("lacivert ");
                } else if(board[i][j] == 11){
                    printf("pembe ");
                } else if(board[i][j] == 12){
                    printf("turkuaz ");
                }
            }
            printf("\n");
        }   
    } else {
        printf("\n_______________________________________________\n\n!!! Tahta duzenlenemedi !!!\n\n");
        printf("Duzenlenemeyen tahtanin son hali\n_______________________________________________\n\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(board[i][j] == 1){
                    printf("kirmizi ");
                } else if(board[i][j] == 2){
                    printf("mavi ");
                } else if(board[i][j] == 3){
                    printf("yesil ");
                } else if(board[i][j] == 4){
                    printf("sari ");
                } else if(board[i][j] == 5){
                    printf("turuncu ");
                } else if(board[i][j] == 6){
                    printf("mor ");
                } else if(board[i][j] == 7){
                    printf("siyah ");
                } else if(board[i][j] == 8){
                    printf("beyaz ");
                } else if(board[i][j] == 9){
                    printf("gri ");
                } else if(board[i][j] == 10){
                    printf("lacivert ");
                } else if(board[i][j] == 11){
                    printf("pembe ");
                } else if(board[i][j] == 12){
                    printf("turkuaz ");
                }
            }
            printf("\n");
        }
    }
    printf("____________________________________________________\n\n");
}