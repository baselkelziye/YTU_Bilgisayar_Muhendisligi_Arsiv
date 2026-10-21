#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Yazar yapısı: Linked list olarak tanımlanmış.
// Her yazarın ID, adı, soyadı ve bir sonraki yazara işaretçi vardır.
typedef struct yazar
{
    int ID;
    char* name;
    char* surname;
    struct yazar *next;
} YAZARLAR;

// Öğrenci yapısı: Doubly linked list olarak tanımlanmış.
// Her öğrencinin numarası, adı, soyadı, puanı ve önceki/sonraki öğrencilere işaretçi bulunur.
typedef struct student
{
    char num[9];
    char* name;
    char* surname;
    int score;
    struct student *prev;
    struct student *next;
} STUDENT;

// Kitap ödünç alma yapısı: Bit-field kullanılarak bellekten tasarruf edilmiş.
// ISBN, öğrenci numarası ve ödünç alma tarihi içerir.
typedef struct {
    char kitap_ISBN[16];
    char ogr_num[9];
    unsigned int odunc : 1;
    unsigned int gün : 5;
    unsigned int ay : 4;
    unsigned int yıl : 11;
} KITAP_ODUNC;

// Tekil kitap kopyaları yapısı: Her kitap kopyasının ISBN'i ve durumu (örneğin ödünçte/raflarda) tutulur.
typedef struct book_isbn {
    char ISBN[16];
    char *durum;
    struct book_isbn *next;
} BOOK_ISBN;

// Kitap yapısı: Kitap adı, ISBN, adet sayısı ve bağlı kopya listesi içerir.
typedef struct books {
    char *name;
    char book_ISBN[14];
    int adet;
    BOOK_ISBN *ISBN_head;
    struct books *next;
} BOOKS;

// Kitap-yazar eşleştirme yapısı: Bir kitabın hangi yazara ait olduğunu gösterir.
typedef struct {
    char ISBN[14];
    int ID;
} KITAP_YAZAR;

// Fonksiyon prototipleri:
// Yazarlarla ilgili işlemler
YAZARLAR* yazarlar_to_list(FILE *fp);
void yazar_to_Free(YAZARLAR* head);
void yazar_list_print(YAZARLAR* head);
void yazar_file_save(YAZARLAR* head);
void yazar_ekle(char* name, char* surname, YAZARLAR** end_node);
void yazar_sil(int id, YAZARLAR** head, KITAP_YAZAR* kitapYazar, int kitap_yazar_count);
void yazar_güncel(int id, YAZARLAR *head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count);
int compareAuthorsByNameSurname(YAZARLAR *yazar_node, char *name, char *surname);
void yazar_bilgi(int (*compare_func)(YAZARLAR*, char*, char*), char *yazar_name, char *yazar_surname, YAZARLAR *yazar_head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count, BOOKS *book_head );

// Öğrencilerle ilgili işlemler
STUDENT* student_to_list(FILE *fp);
void student_to_free(STUDENT *head);
void student_file_save(STUDENT *head);
void student_append(char *student_name, char *student_surname, char *student_num, STUDENT **student_head);
void student_delete(char *student_num, STUDENT **head);
void student_update(char *student_num, STUDENT *student_head, BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count);
void student_info(char *student_num, STUDENT *student_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, BOOKS *book_head);
void kitap_teslim_etmeyen(STUDENT *student_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count);
void punish_student(STUDENT *head);
void student_list_print(STUDENT *head);

// Kitap ödünç işlemleri
void kitap_odunc_al(char *student_num, char* book_name, STUDENT *student_head, KITAP_ODUNC **kitapOdunc, int *kitap_odunc_count, BOOKS *book_head, struct tm *zaman);
void kitap_teslim_et(char *student_num, char *book_name, STUDENT *student_head, KITAP_ODUNC **kitapOdunc, int *kitap_odunc_count, BOOKS *book_head, struct tm *zaman);

// Kitap listesi işlemleri
BOOKS* books_to_list(FILE *fp, FILE *fp_isbn);
BOOK_ISBN* bookISBN_to_list(FILE *fp, int count);
void book_and_bookSample_to_free(BOOKS *head);
void books_list_print(BOOKS* head);
void book_and_bookSample_file_save (BOOKS *head);
void book_append(char *book_name, char *book_ISBN, int book_count, BOOKS **end_node);
void book_delete( char *book_name, BOOKS **head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count);
void book_update( char *book_name, BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, KITAP_YAZAR *kitapYazar, int kitap_yazar_count);
void book_info(char *book_name, BOOKS *head);
void geç_teslim_kitaplar(BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, struct tm *zaman);

// Kitap-yazar eşleştirmeleri
void pair(char *yazar_name, char *yazar_surname, char *book_name, YAZARLAR *yazar_head, BOOKS *book_head, KITAP_YAZAR **kitapYazar, int *kitap_yazar_count);
void kitap_yazar_change(char *book_name, char *yazar_name, char *yazar_surname, BOOKS *book_head, YAZARLAR* yazar_head, KITAP_YAZAR* kitapYazar, int kitap_yazar_count );
KITAP_YAZAR* kitap_yazar_save(FILE *fp, int *kitap_yazar_count);
void kitap_yazar_file_save(KITAP_YAZAR *kitapYazar, int kitap_yazar_count);

// Kitap ödünç işlemi dosya kaydetme/yükleme
KITAP_ODUNC* kitap_odunc_save(FILE *fp, int *kitap_odunc_count);
void kitap_odunc_file_save(KITAP_ODUNC *kitapOdunc, int kitap_odunc_count);

// Ana program fonksiyonu
int main(void) {
    // Sistem zamanını al
    time_t simdi = time(NULL);
    struct tm *zaman = localtime(&simdi);

    /* -------------------- DOSYA İŞLEMLERİ -------------------- */
    
    // Kitap-Yazar ilişki dosyasını aç veya oluştur
    FILE *fp_kitap_yazar = fopen("Dataset/KitapYazar.csv", "r");
    if (fp_kitap_yazar == NULL) { // Dosya yoksa oluştur
        fp_kitap_yazar = fopen("Dataset/KitapYazar.csv", "w");
        if (fp_kitap_yazar == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Kitap-Yazar dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_kitap_yazar); // Önce kapat
        fp_kitap_yazar = fopen("Dataset/KitapYazar.csv", "r"); // Şimdi okuma modunda aç
    }
    int kitap_yazar_count;
    KITAP_YAZAR *kitapYazar = kitap_yazar_save(fp_kitap_yazar, &kitap_yazar_count);
    fclose(fp_kitap_yazar);

    // Kitap ödünç alma dosyasını aç veya oluştur
    FILE *fp_kitap_odunc = fopen("Dataset/KitapOdunc.csv", "r");
    if (fp_kitap_odunc == NULL) { // Dosya yoksa oluştur
        fp_kitap_odunc = fopen("Dataset/KitapOdunc.csv", "w");
        if (fp_kitap_odunc == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Kitap ödünç dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_kitap_odunc); // Önce kapat
        fp_kitap_odunc = fopen("Dataset/KitapOdunc.csv", "r"); // Şimdi okuma modunda aç
    }
    int kitap_odunc_count;
    KITAP_ODUNC *kitapOdunc = kitap_odunc_save(fp_kitap_odunc, &kitap_odunc_count);
    fclose(fp_kitap_odunc);

    // Öğrenci dosyasını aç veya oluştur
    FILE *fp_student = fopen("Dataset/Ogrenciler.csv","r");
    if (fp_student == NULL) { // Dosya yoksa oluştur
        fp_student = fopen("Dataset/Ogrenciler.csv", "w");
        if (fp_student == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Öğrenci dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_student); // Önce kapat
        fp_student = fopen("Dataset/Ogrenciler.csv", "r"); // Şimdi okuma modunda aç
    }
    STUDENT *student_head = student_to_list(fp_student);
    fclose(fp_student);

    // Kitap ve ISBN dosyalarını aç veya oluştur
    FILE *fp_books = fopen("Dataset/Kitaplar.csv", "r");
    FILE *fp_isbn = fopen("Dataset/KitapOrnekleri.csv","r");
    if (fp_books == NULL) { // Dosya yoksa oluştur
        fp_books = fopen("Dataset/Kitaplar.csv", "w");
        if (fp_books == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Kitaplar dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_books); // Önce kapat
        fp_books = fopen("Dataset/Kitaplar.csv", "r"); // Şimdi okuma modunda aç
    }
    if (fp_isbn == NULL) { // Dosya yoksa oluştur
        fp_isbn = fopen("Dataset/KitapOrnekleri.csv", "w");
        if (fp_isbn == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Kitap örnekleri dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_isbn); // Önce kapat
        fp_isbn = fopen("Dataset/KitapOrnekleri.csv", "r"); // Şimdi okuma modunda aç
    }    
    BOOKS *book_head = books_to_list(fp_books, fp_isbn);
    fclose(fp_books);
    fclose(fp_isbn);

    // Yazar dosyasını aç veya oluştur
    FILE *fp_yazar = fopen("Dataset/Yazarlar.csv", "r");
    if (fp_yazar == NULL) { // Dosya yoksa oluştur
        fp_yazar = fopen("Dataset/Yazarlar.csv", "w");
        if (fp_yazar == NULL) { // Açma başarısız olduysa hata ver
            fprintf(stderr, "Hata: Yazarlar dosyası oluşturulamadı!\n");
            return 1;
        }
        fclose(fp_yazar); // Önce kapat
        fp_yazar = fopen("Dataset/Yazarlar.csv", "r"); // Şimdi okuma modunda aç
    }
    YAZARLAR *yazar_head = yazarlar_to_list(fp_yazar);
    fclose(fp_yazar);

    /* -------------------- KULLANICI GİRİŞLERİ İÇİN BELLEK AYIRMA -------------------- */
    char *student_name =  (char*)malloc(sizeof(char) * 100);
    char *student_surname = (char*)malloc(sizeof(char) * 100);
    char student_num[9];
    char *book_name = (char*)malloc(sizeof(char) * 100);
    char book_ISBN[14];
    char *yazar_name =  (char*)malloc(sizeof(char) * 100);
    char *yazar_surname = (char*)malloc(sizeof(char) * 100);
    int yazar_id, book_count;
    int student_choice, book_choice, yazar_choice, choice = 1;

    /* -------------------- ANA MENÜ DÖNGÜSÜ -------------------- */
    while (choice) {
        printf("\n============ KÜTÜPHANE YÖNETİM SİSTEMİ ============\n");
        printf(" Lütfen yapmak istediğiniz işlemi seçin:\n");
        printf("  1. Öğrenci İşlemleri\n");
        printf("  2. Kitap İşlemleri\n");
        printf("  3. Yazar İşlemleri\n");
        printf("  0. Çıkış\n");
        printf("\n Seçiminiz: ");
        scanf("%d", &choice);
        
        // Öğrenci işlemleri menüsü
        if (choice == 1) {
            student_choice = 1;
            while (student_choice) {
                printf("\n---------- ÖĞRENCİ İŞLEMLERİ ----------\n");
                printf(" Lütfen yapmak istediğiniz işlemi seçin:\n");
                printf("  1. Öğrenci Ekle\n");
                printf("  2. Öğrenci Sil\n");
                printf("  3. Öğrenci Güncelle\n");
                printf("  4. Öğrenci Bilgisi Görüntüle\n");
                printf("  5. Kitap Teslim Etmemiş Öğrenciler\n");
                printf("  6. Cezalı Öğrenciler\n");
                printf("  7. Tüm Öğrencileri Listele\n");
                printf("  8. Kitap Ödünç Al\n");
                printf("  9. Kitap Teslim Et\n");
                printf("  0. Öğrenci İşlemlerinden Çıkış\n");
                printf("\n Seçiminiz: ");    
                scanf("%d",&student_choice);   
                
                if (student_choice == 1) {
                    printf("\n>> Yeni Öğrenci Ekleme <<\n");
                    printf(" Öğrenci adı: ");
                    scanf(" %[^\n]",student_name);
                    printf(" Öğrenci soyadı: ");
                    scanf(" %[^\n]",student_surname);
                    printf(" Öğrenci numarası: ");
                    scanf(" %s",student_num);
                    student_append(student_name, student_surname, student_num, &student_head);
                    
                } else if (student_choice == 2) {
                    printf("\n>> Öğrenci Silme <<\n");
                    printf(" Silinecek öğrenci numarası: ");
                    scanf(" %s",student_num);
                    student_delete(student_num, &student_head);
                } else if (student_choice == 3) {
                    printf("\n>> Öğrenci Bilgilerini Güncelleme <<\n");
                    printf(" Güncellenecek öğrenci numarası: ");
                    scanf(" %s",student_num);
                    student_update(student_num, student_head, book_head, kitapOdunc, kitap_odunc_count);
                    
                } else if (student_choice == 4) {
                    printf("\n>> Öğrenci Bilgilerini Görüntüleme <<\n");
                    printf(" Bilgileri görüntülenecek öğrenci numarası: ");
                    scanf(" %[^\n]",student_num);
                    student_info(student_num, student_head, kitapOdunc, kitap_odunc_count, book_head);
                    
                } else if (student_choice == 5) {
                    printf("\n>> Kitabı Teslim Etmeyen Öğrenciler <<\n");
                    kitap_teslim_etmeyen(student_head, kitapOdunc, kitap_odunc_count);
                    
                } else if (student_choice == 6) {
                    printf("\n>> Cezalı Öğrenciler (Puanı -10'dan düşük olanlar) <<\n");
                    punish_student(student_head);
                    
                } else if (student_choice == 7) {
                    printf("\n>> Tüm Öğrencilerin Listesi <<\n");
                    student_list_print(student_head);
                    
                } else if (student_choice == 8) {
                    printf("\n>> Kitap Ödünç Alma İşlemi <<\n");
                    printf(" Öğrenci numarası: ");
                    scanf(" %s",student_num);
                    printf(" Ödünç alınacak kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    kitap_odunc_al(student_num, book_name, student_head, &kitapOdunc, &kitap_odunc_count, book_head, zaman);
                    
                } else if (student_choice == 9) {
                    printf("\n>> Kitap Teslim Etme İşlemi <<\n");
                    printf(" Öğrenci numarası: ");
                    scanf(" %s", student_num);
                    printf(" Teslim edilecek kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    kitap_teslim_et(student_num, book_name, student_head, &kitapOdunc, &kitap_odunc_count, book_head, zaman);
                }
                // Değişiklikleri dosyalara kaydet
                kitap_odunc_file_save(kitapOdunc, kitap_odunc_count);
                book_and_bookSample_file_save(book_head);
                student_file_save(student_head);
            }

        } else if (choice == 2) {  // Kitap işlemleri menüsü
            BOOKS *book_end_node = NULL;
            book_choice = 1;
            while (book_choice) {
                printf("\n---------- KİTAP İŞLEMLERİ ----------\n");
                printf(" Lütfen yapmak istediğiniz işlemi seçin:\n");
                printf("  1. Kitap Ekle\n");
                printf("  2. Kitap Sil\n");
                printf("  3. Kitap Güncelle\n");
                printf("  4. Kitap Bilgilerini Görüntüle\n");
                printf("  5. Tüm Kitapları Listele\n");
                printf("  6. Zamanında Teslim Edilmeyen Kitaplar\n");
                printf("  7. Kitap-Yazar Eşleştir\n");
                printf("  8. Kitabın Yazarını Güncelle\n");
                printf("  0. Kitap İşlemlerinden Çıkış\n");
                printf("\n Seçiminiz: ");
                scanf("%d",&book_choice);
                
                if (book_choice == 1) {
                    book_end_node = book_head;
                    while (book_end_node->next != NULL) book_end_node = book_end_node->next;
                    printf("\n>> Yeni Kitap Ekleme <<\n");
                    printf(" Kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    printf(" ISBN numarası: ");
                    scanf(" %s", book_ISBN);
                    printf(" Kitap örnek sayısı: ");
                    scanf("%d", &book_count);
                    book_append(book_name, book_ISBN, book_count, &book_end_node);

                } else if (book_choice == 2) {
                    printf("\n>> Kitap Silme <<\n");
                    printf(" Silinecek kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    book_delete(book_name, &book_head, kitapYazar, kitap_yazar_count);
                    
                } else if (book_choice == 3) {
                    printf("\n>> Kitap Bilgilerini Güncelleme <<\n");
                    printf(" Güncellenecek kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    book_update(book_name, book_head, kitapOdunc, kitap_odunc_count, kitapYazar, kitap_yazar_count);
                    
                } else if (book_choice == 4) {
                    printf("\n>> Kitap Bilgilerini Görüntüleme <<\n");
                    printf(" Bilgileri görüntülenecek kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    book_info(book_name, book_head);
                    
                } else if (book_choice == 5) {
                    printf("\n>> Tüm Kitapların Listesi <<\n");
                    books_list_print(book_head);
                    
                } else if (book_choice == 6) {
                    printf("\n>> Zamanında Teslim Edilmeyen Kitaplar <<\n");
                    geç_teslim_kitaplar(book_head, kitapOdunc, kitap_odunc_count, zaman);
                    // Bu fonksiyon henüz implemente edilmemiş
                    
                } else if (book_choice == 7) {
                    printf("\n>> Kitap-Yazar Eşleştirme <<\n");
                    printf(" Yazar adı: ");
                    scanf(" %[^\n]", yazar_name);
                    printf(" Yazar soyadı: ");
                    scanf(" %[^\n]",yazar_surname);
                    printf(" Kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    pair(yazar_name, yazar_surname, book_name, yazar_head, book_head, &kitapYazar, &kitap_yazar_count);
                    
                } else if (book_choice == 8) {
                    printf("\n>> Kitabın Yazarını Güncelleme <<\n");
                    printf(" Kitap adı: ");
                    scanf(" %[^\n]", book_name);
                    printf(" Yeni yazar adı: ");
                    scanf(" %[^\n]", yazar_name);
                    printf(" Yeni yazar soyadı: ");
                    scanf(" %[^\n]",yazar_surname);
                    kitap_yazar_change(book_name, yazar_surname, yazar_name, book_head, yazar_head, kitapYazar, kitap_yazar_count);
                }
                
                // Değişiklikleri dosyalara kaydet
                book_and_bookSample_file_save(book_head);
                kitap_yazar_file_save(kitapYazar, kitap_yazar_count);
            }
        } else if (choice == 3) {  // Yazar işlemleri menüsü
            YAZARLAR *yazar_end_node = NULL;
            yazar_choice = 1;
            while (yazar_choice) {
                printf("\n---------- YAZAR İŞLEMLERİ ----------\n");
                printf(" Lütfen yapmak istediğiniz işlemi seçin:\n");
                printf("  1. Yazar Ekle\n");
                printf("  2. Yazar Sil\n");
                printf("  3. Yazar Bilgilerini Güncelle\n");
                printf("  4. Yazar Bilgilerini Görüntüle\n");
                printf("  0. Yazar İşlemlerinden Çıkış\n");
                printf("\n Seçiminiz: "); 
                scanf("%d",&yazar_choice);

                if (yazar_choice == 1) {
                    yazar_end_node = yazar_head;
                    while (yazar_end_node->next != NULL) yazar_end_node = yazar_end_node->next;
                    printf("\n>> Yeni Yazar Ekleme <<\n");
                    printf(" Yazar adı: ");
                    scanf(" %[^\n]", yazar_name);
                    printf(" Yazar soyadı: ");
                    scanf(" %[^\n]", yazar_surname);
                    yazar_ekle(yazar_name, yazar_surname, &yazar_end_node);
                    printf("\n Bilgi: Yazar başarıyla eklendi.\n");
                    
                } else if (yazar_choice == 2) {
                    printf("\n>> Yazar Silme <<\n");
                    printf(" Silinecek yazar ID: ");
                    scanf("%d",&yazar_id);
                    yazar_sil(yazar_id, &yazar_head, kitapYazar, kitap_yazar_count);
                    
                } else if (yazar_choice == 3) {
                    printf("\n>> Yazar Bilgilerini Güncelleme <<\n");
                    printf(" Güncellenecek yazar ID: ");
                    scanf("%d",&yazar_id);   
                    yazar_güncel(yazar_id, yazar_head, kitapYazar, kitap_yazar_count);
                    
                } else if (yazar_choice == 4) {
                    printf("\n>> Yazar Bilgilerini Görüntüleme <<\n");
                    printf(" Yazar adı: ");
                    scanf(" %[^\n]",yazar_name);
                    printf(" Yazar soyadı: ");
                    scanf(" %[^\n]",yazar_surname);
                    yazar_bilgi(compareAuthorsByNameSurname, yazar_name, yazar_surname, yazar_head, kitapYazar, kitap_yazar_count, book_head);
                }
                
                // Değişiklikleri dosyalara kaydet
                yazar_file_save(yazar_head);
                kitap_yazar_file_save(kitapYazar, kitap_yazar_count);
            } 
        }
    }

    /* -------------------- BELLEK TEMİZLEME VE PROGRAM SONU -------------------- */
    free(student_name);
    free(student_surname);
    free(book_name);
    free(yazar_name);
    free(yazar_surname);
    student_to_free(student_head);
    book_and_bookSample_to_free(book_head);
    yazar_to_Free(yazar_head);
    free(kitapOdunc);
    free(kitapYazar);
    
    printf("\nProgram sonlandırıldı. İyi günler!\n");
    return 0;
}

// Dosyadan yazar bilgilerini okuyarak bir bağlı liste oluşturan fonksiyon.
YAZARLAR* yazarlar_to_list(FILE *fp) {
    YAZARLAR *head = NULL, *temp = NULL, *new_node = NULL;
    char *token;
    char buffer[256]; // Buffer boyutu artırıldı

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        new_node = (YAZARLAR*)malloc(sizeof(YAZARLAR));
        new_node->name = (char*)malloc(sizeof(char) * 100);
        new_node->surname = (char*)malloc(sizeof(char) * 100);

        token = strtok(buffer, ",");
        new_node->ID = atoi(token);

        token = strtok(NULL, ",");
        // Baştaki boşlukları atla
        while (*token == ' ') token++;
        strcpy(new_node->name, token);

        token = strtok(NULL, "\n\r");
        // Baştaki boşlukları atla
        while (*token == ' ') token++;
        strcpy(new_node->surname, token);

        new_node->next = NULL;

        if (head == NULL) {
            temp = head = new_node;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    return head;
}

// Yazar bağlı listesinin belleğini serbest bırakan fonksiyon.
void yazar_to_Free(YAZARLAR* head) {
    YAZARLAR *to_free = NULL;

    while (head != NULL) {
        to_free = head;
        free(head->name);
        free(head->surname);
        head = head->next;
        free(to_free);
    }
}

// Yazar bağlı listesindeki tüm yazarları ekrana yazdıran fonksiyon.
void yazar_list_print(YAZARLAR* head) {
    while ( head != NULL) {
        printf("Yazar ID: %d, Adı: %s, Soyadı: %s\n",
            head->ID,
            head->name,
            head->surname);
        head = head->next;
    }
}

// Yazar bağlı listesindeki bilgileri bir dosyaya kaydeden fonksiyon.
void yazar_file_save(YAZARLAR* head) {
    FILE *new_fp = fopen("Dataset/Yazarlar.csv", "w");
    if (new_fp == NULL) {
        perror("Dosya açılamadı.");
        return;
    }

    while ( head != NULL) {
            fprintf(new_fp, "%d, %s, %s\n",
                head->ID,
                head->name,
                head->surname);
            head = head->next;
    }
    fclose(new_fp);
    printf("\nYazar bilgileri dosyaya kaydedildi.\n");
}

// Bağlı listenin sonuna yeni bir yazar ekleyen fonksiyon.
void yazar_ekle(char* name, char* surname, YAZARLAR** end_node) {
    (*end_node)->next = (YAZARLAR*)malloc(sizeof(YAZARLAR));
    (*end_node)->next->name = (char*)malloc(sizeof(char) * 100);
    (*end_node)->next->surname = (char*)malloc(sizeof(char) * 100);

    (*end_node)->next->ID = (*end_node)->ID + 1;
    strcpy((*end_node)->next->name, name);
    strcpy((*end_node)->next->surname, surname);

    *end_node = (*end_node)->next;
    (*end_node)->next = NULL;

    printf("\nYazar başarıyla kaydedildi.\n");
}

// Belirli bir ID'ye sahip yazarı bağlı listeden silen fonksiyon.
void yazar_sil(int id, YAZARLAR** head, KITAP_YAZAR* kitapYazar, int kitap_yazar_count) {
    YAZARLAR *to_delete = NULL;
    int i;

    // Silinecek yazar listenin başındaysa.
    if (*head != NULL && (*head)->ID == id) {
        to_delete = *head;
        *head = (*head)->next;
    } else {
        YAZARLAR *temp = *head;
        while ( temp != NULL && temp->next != NULL && temp->next->ID != id ) {
            temp = temp->next;
        }
        // Yazar bulunursa
        if (temp != NULL && temp->next != NULL) {
            to_delete = temp->next;
            temp->next = temp->next->next;
        } else {
            printf("\nBelirtilen ID'ye sahip yazar bulunamadı.\n");
            return;
        }
    }

    for ( i = 0; i < kitap_yazar_count; i++) {
        if (kitapYazar[i].ID == to_delete->ID)    kitapYazar[i].ID = -1;
    }

    free(to_delete->name);
    free(to_delete->surname);
    free(to_delete);
    printf("\nYazar başarıyla silindi.\n");
}

// Belirli bir ID'ye sahip yazarın bilgilerini güncelleyen fonksiyon.
void yazar_güncel(int id, YAZARLAR *head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count) {
    while ( head != NULL && head->ID != id) head = head->next;

    if (head == NULL) {
        printf("\nBelirtilen ID'ye sahip yazar bulunamadı.\n");
        return;
    }

    int new_id, i;

    printf("\nYazarın güncel bilgilerini giriniz:\n");
    printf("Yazar Adı: ");
    scanf(" %[^\n]",head->name);
    printf("Yazar Soyadı: ");
    scanf(" %[^\n]",head->surname);
    printf("Yazar ID: ");
    scanf("%d",&new_id);

    for (i = 0; i < kitap_yazar_count; i++) {
        if (kitapYazar[i].ID == head->ID) {
            kitapYazar[i].ID = new_id;
        }
    }
    head->ID = new_id;

    printf("\nYazar bilgileri başarıyla güncellendi.\n");
}

// Yazar bilgilerini karşılaştırmak için kullanılan fonksiyon (isim ve soyisime göre)
int compareAuthorsByNameSurname(YAZARLAR *yazar_node, char *name, char *surname) {
    return (!strcmp(yazar_node->name, name) && !strcmp(yazar_node->surname, surname));
}

// Yazarın bilgilerini ve yazdığı kitapları listeleyen fonksiyon (fonksiyon işaretçisi ile)
void yazar_bilgi(int (*compare_func)(YAZARLAR*, char*, char*), char *yazar_name, char *yazar_surname, YAZARLAR *yazar_head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count, BOOKS *book_head ) {
    int i;
    BOOKS *book = NULL;
    BOOK_ISBN *isbn_head = NULL;
    YAZARLAR *found_yazar = NULL;

    YAZARLAR *current_yazar = yazar_head;
    while (current_yazar != NULL) {
        if (compare_func(current_yazar, yazar_name, yazar_surname)) {
            found_yazar = current_yazar;
            // Yazar bulundu, döngüden çık
            current_yazar = NULL; // Döngüyü sonlandırmak için
        } else {
            current_yazar = current_yazar->next;
        }
    }

    if (found_yazar == NULL) {
        printf("\nBelirtilen yazar bulunamadı.\n");
        return;
    }

    printf("\nYazarın Adı Soyadı: %s %s, ID: %d\n", found_yazar->name, found_yazar->surname, found_yazar->ID);
    printf("\nYazarın Kitapları ve Kitaplarının Durumları:\n");

    for ( i = 0; i < kitap_yazar_count; i++) {
        if ( kitapYazar[i].ID == found_yazar->ID) {
            book = book_head;
            while (book != NULL) {
                if (!strcmp(book->book_ISBN, kitapYazar[i].ISBN)) { // strcmp 0 döndürünce ! ile true yaparız
                    printf("\nKitap İsmi: %s, Kitap ISBN: %s, Kitap Adet Sayısı: %d\n\n",book->name, book->book_ISBN, book->adet);
                    isbn_head = book->ISBN_head;
                    while ( isbn_head != NULL) {
                        printf("Örnek Kitap ISBN: %s, Örnek Kitabın Durumu: %s\n", isbn_head->ISBN, isbn_head->durum);
                        isbn_head = isbn_head->next;
                    }
                }
                book = book->next;
            }
        }
    }
}

// Dosyadan öğrenci bilgilerini okuyarak bir bağlı liste (çift yönlü) oluşturan fonksiyon.
STUDENT* student_to_list(FILE *fp) {
    STUDENT *head = NULL, *temp = NULL, *new_node = NULL; // Bağlı liste için başlangıç, geçici ve yeni düğüm işaretçileri.
    char *token; // String parçalamak için kullanılacak işaretçi.
    char buffer[100]; // Dosyadan okunacak satırı tutmak için tampon bellek.

    // Dosyanın sonuna kadar her satırı oku.
    while (fgets(buffer, 100, fp) != NULL) {
        new_node = (STUDENT*)malloc(sizeof(STUDENT)); // Yeni bir öğrenci düğümü için bellek ayır.
        if (new_node == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            return NULL;
        }
        new_node->name = (char*)malloc(sizeof(char) * 100); // Öğrenci adı için bellek ayır.
        if (new_node->name == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            free(new_node);
            return NULL;
        }
        new_node->surname = (char*)malloc(sizeof(char) * 100); // Öğrenci soyadı için bellek ayır.
        if (new_node->surname == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            free(new_node->name);
            free(new_node);
            return NULL;
        }

        token = strtok(buffer, ","); // Satırı virgülle ayırarak öğrenci numarasını al.
        strcpy(new_node->num, token); // Numarayı yeni düğüme kopyala.

        token = strtok(NULL, ",") + 1; // Bir sonraki virgülle ayırarak öğrenci adını al (başıdaki boşluğu atla).
        strcpy(new_node->name , token); // Adı yeni düğüme kopyala.

        token = strtok(NULL, ",") + 1; // Bir sonraki virgülle ayırarak öğrenci soyadını al (başıdaki boşluğu atla).
        strcpy(new_node->surname , token); // Soyadı yeni düğüme kopyala.

        token = strtok(NULL, "\n") + 1; // Yeni satır karakterine kadar ayırarak puanı al (başıdaki boşluğu atla).
        new_node->score = atoi(token); // Puanı tamsayıya çevir.

        new_node->next = NULL; // Yeni düğümün sonraki işaretçisini NULL yap.
        new_node->prev = NULL; // Yeni düğümün önceki işaretçisini NULL yap.

        // Bağlı listeye yeni düğümü ekle.
        if (temp == NULL) {
            temp = head = new_node; // Liste boşsa, yeni düğüm hem baş hem de geçici düğüm olur.
        } else {
            temp->next = new_node; // Listenin sonuna yeni düğümü ekle.
            new_node->prev = temp; // Yeni düğümün önceki işaretçisini bir önceki düğüme bağla.
            temp = temp->next; // Geçici düğümü yeni eklenen düğüme taşı.
        }
    }
    return head; // Oluşturulan bağlı listenin başını döndür.
}

// Öğrenci bağlı listesinin belleğini serbest bırakan fonksiyon.
void student_to_free(STUDENT *head) {
    STUDENT *to_free = NULL; // Serbest bırakılacak düğümü tutmak için geçici işaretçi.

    // Liste boş olana kadar döngüyü sürdür.
    while ( head != NULL) {
        to_free = head; // Mevcut düğümü serbest bırakılacak olarak işaretle.
        free(head->name); // Öğrenci adının belleğini serbest bırak.
        free(head->surname); // Öğrenci soyadının belleğini serbest bırak.
        head = head->next; // Bir sonraki düğüme geç.
        free(to_free); // Mevcut düğümün belleğini serbest bırak.
    }
}

// Öğrenci bağlı listesindeki bilgileri bir dosyaya kaydeden fonksiyon.
void student_file_save(STUDENT *head) {
    FILE *fp = fopen("Dataset/Ogrenciler.csv", "w"); // "Ogrenciler.csv" dosyasını yazma modunda aç.

    // Liste boş olana kadar her düğümü gez.
    while (head != NULL) {
        // Öğrenci bilgilerini dosyaya formatlı bir şekilde yaz.
        fprintf(fp, "%s, %s, %s, %d\n", head->num, head->name, head->surname, head->score);
        head = head->next; // Bir sonraki düğüme geç.
    }
    fclose(fp); // Dosyayı kapat.
    printf("\nÖğrenci bilgileri dosyaya kaydedildi.\n");
}

// Bağlı listenin başına yeni bir öğrenci ekleyen fonksiyon.
void student_append(char *student_name, char *student_surname, char *student_num, STUDENT **student_head) {
    // Mevcut baş düğümün öncesine yeni bir düğüm için bellek ayır.
    (*student_head)->prev = (STUDENT*)malloc(sizeof(STUDENT));

    // Yeni düğümün adı için bellek ayır.
    (*student_head)->prev->name = (char*)malloc(sizeof(char) * 100);

    // Yeni düğümün soyadı için bellek ayır.
    (*student_head)->prev->surname = (char*)malloc(sizeof(char) * 100);

    strcpy((*student_head)->prev->name, student_name); // Yeni öğrencinin adını kopyala.
    strcpy((*student_head)->prev->surname, student_surname); // Yeni öğrencinin soyadını kopyala.
    strcpy((*student_head)->prev->num, student_num); // Yeni öğrencinin numarasını kopyala.
    (*student_head)->prev->score = 100; // Yeni öğrencinin başlangıç puanını ayarla.

    (*student_head)->prev->next = *student_head; // Yeni düğümün sonraki işaretçisini mevcut baş düğüme bağla.
    *student_head = (*student_head)->prev; // Baş işaretçisini yeni eklenen düğüme taşı.
    (*student_head)->prev = NULL; // Yeni baş düğümün önceki işaretçisini NULL yap.

    printf("\nÖğrenci başarıyla kaydedildi.\n");
}

// Belirli bir öğrenci numarasına sahip öğrenciyi bağlı listeden silen fonksiyon.
void student_delete(char *student_num, STUDENT **head) {
    STUDENT *to_delete = NULL; // Silinecek düğümü tutmak için işaretçi.
    STUDENT *temp = NULL;
    // Silinecek öğrenci listenin başındaysa.
    if ( !strcmp((*head)->num, student_num)) {
        to_delete = *head; // Silinecek düğümü işaretle.
        *head = (*head)->next; // Baş işaretçisini bir sonraki düğüme taşı.
        if (*head != NULL) { // Yeni baş düğüm varsa, önceki işaretçisini NULL yap.
            (*head)->prev = NULL;
        }
    } else {
        temp = *head; // Geçici bir işaretçi ile listenin başından başla.
        // Silinecek düğümü bulana veya listenin sonuna gelene kadar ilerle.
        while (temp->next != NULL && strcmp(temp->next->num, student_num))   temp = temp->next;

        // Öğrenci bulunamadıysa.
        if (temp->next == NULL) {
            printf("\nUyarı: Belirtilen öğrenci numarası bulunamadı.\n");
            return;
        }
        to_delete = temp->next; // Silinecek düğümü işaretle.
        temp->next = temp->next->next; // Silinecek düğümü listeden çıkar.
        if (temp->next != NULL) { // Silinen düğümden sonra bir düğüm varsa, önceki işaretçisini güncelle.
            temp->next->prev = temp;
        }
    }

    free(to_delete->name); // Silinecek öğrencinin adının belleğini serbest bırak.
    free(to_delete->surname); // Silinecek öğrencinin soyadının belleğini serbest bırak.
    free(to_delete); // Silinecek düğümün belleğini serbest bırak.
    printf("\nÖğrenci başarıyla silindi.\n");
}

// Belirli bir öğrenci numarasına sahip öğrencinin bilgilerini güncelleyen fonksiyon.
void student_update(char *student_num, STUDENT *student_head, BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count) {
    // Belirtilen öğrenci numarasını bulana veya listenin sonuna gelene kadar ilerle.
    while (student_head != NULL && strcmp(student_head->num, student_num))   student_head = student_head->next;

    // Öğrenci bulunamadıysa.
    if (student_head == NULL) {
        printf("\nUyarı: Belirtilen öğrenci numarası bulunamadı.\n");
        return;
    }

    char new_num[9]; // Yeni öğrenci numarası için tampon.
    char *new_name = (char*)malloc(sizeof(char) * 100); // Yeni isim için bellek ayır.
    char *new_surname = (char*)malloc(sizeof(char) * 100); // Yeni soyisim için bellek ayır.
    
    int new_score; // Yeni puan.
    int i; // Döngü sayacı.
    BOOK_ISBN *isbn_head; // Kitap ISBN düğümü için işaretçi.
    BOOKS *book; // Kitap düğümü için işaretçi.

    printf("\nÖğrencinin güncel bilgilerini giriniz:\n");
    printf("Yeni Numara: ");
    scanf(" %s",new_num); // Yeni numarayı al.
    printf("Yeni İsim: ");
    scanf(" %[^\n]",new_name); // Yeni ismi al.
    printf("Yeni Soyisim: ");
    scanf(" %[^\n]",new_surname); // Yeni soyismi al.
    printf("Yeni Puan: ");
    scanf("%d",&new_score); // Yeni puanı al.

    // Kitap ödünç alma kayıtlarını güncelle (eğer öğrenci numarası değiştiyse).
    for ( i = 0; i < kitap_odunc_count; i++) {
        if (strcmp(kitapOdunc[i].ogr_num, student_num) == 0) {
            book = book_head;
            // Kitabı ISBN'sine göre bul.
            while (book != NULL && strncmp(book->book_ISBN, kitapOdunc[i].kitap_ISBN, 13) != 0 )   book = book->next;
            if (book != NULL) {
                isbn_head = book->ISBN_head;
                // Kitap ISBN'sine göre alt listeyi bul.
                while (isbn_head != NULL && strcmp(isbn_head->ISBN, kitapOdunc[i].kitap_ISBN) != 0 )   isbn_head = isbn_head->next;
                if (isbn_head != NULL) {
                    strcpy(isbn_head->durum, new_num); // Kitap örneğinin durumunu yeni öğrenci numarasıyla güncelle.
                    strcpy(kitapOdunc[i].ogr_num, new_num); // Ödünç kaydındaki öğrenci numarasını güncelle.
                }
            }
        }
    }
    // Öğrenci bilgilerini güncelle.
    strcpy(student_head->num, new_num);
    strcpy(student_head->name, new_name);
    strcpy(student_head->surname, new_surname);
    student_head->score = new_score;

    free(new_name); // Ayırılan belleği serbest bırak.
    free(new_surname); // Ayırılan belleği serbest bırak.
    printf("\nÖğrenci bilgileri başarıyla güncellendi.\n");
}

// Belirli bir öğrencinin bilgilerini ve ödünç aldığı kitapları gösteren fonksiyon.
void student_info(char *student_num, STUDENT *student_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, BOOKS *book_head) {
    int i; // Döngü sayacı.
    BOOKS *current_book_head = NULL;

    // Belirtilen öğrenci numarasını bulana veya listenin sonuna gelene kadar ilerle.
    while ( student_head != NULL && strcmp(student_head->num, student_num))    student_head = student_head->next;

    // Öğrenci bulunamadıysa.
    if (student_head == NULL) {
        printf("\nUyarı: Belirtilen öğrenci numarası bulunamadı.\n");
        return;
    }

    printf("\nÖğrencinin Numarası: %s, Adı Soyadı: %s %s, Puanı: %d\n\n",student_head->num, student_head->name, student_head->surname, student_head->score);

    // Öğrencinin ödünç aldığı kitapları kontrol et.
    for ( i = 0; i < kitap_odunc_count; i++) {
        if ( !strcmp(kitapOdunc[i].ogr_num, student_head->num)) {
            current_book_head = book_head; // Her döngüde kitap listesinin başına dönmek için geçici işaretçi
            // Kitabı ISBN'sine göre bul.
            while (current_book_head != NULL && strncmp(current_book_head->book_ISBN, kitapOdunc[i].kitap_ISBN, 13))    current_book_head = current_book_head->next;

            if (current_book_head != NULL) { // Kitap bulunduysa
                if (kitapOdunc[i].odunc == 0) { // Kitap ödünç alındıysa
                    printf("Öğrencinin ödünç aldığı kitap adı: %s, Kitabı ödünç alma tarihi: %d.%d.%d\n", current_book_head->name, kitapOdunc[i].gün, kitapOdunc[i].ay, kitapOdunc[i].yıl);
                } else { // Kitap teslim edildiyse
                    printf("Öğrencinin teslim ettiği kitap adı: %s, Kitabı teslim etme tarihi: %d.%d.%d\n", current_book_head->name, kitapOdunc[i].gün, kitapOdunc[i].ay, kitapOdunc[i].yıl);
                }
            }
        }
    }
}

// Henüz teslim edilmemiş kitapları olan öğrencileri listeleyen fonksiyon.
void kitap_teslim_etmeyen(STUDENT *student_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count) {
    int i, j; // Döngü sayaçları.
    STUDENT *temp = NULL; // Geçici öğrenci düğümü işaretçisi.

    // Tüm kitap ödünç alma kayıtlarını gez.
    for (i = 0; i < kitap_odunc_count; i++) {
        // Eğer kitap ödünç alınmışsa (odunc == 0).
        if (kitapOdunc[i].odunc == 0) {
            j = i + 1;
            // Aynı öğrencinin aynı kitabı teslim edip etmediğini kontrol et.
            while (j < kitap_odunc_count && (kitapOdunc[j].odunc == 0 || strcmp(kitapOdunc[i].kitap_ISBN, kitapOdunc[j].kitap_ISBN) != 0 || strcmp(kitapOdunc[i].ogr_num, kitapOdunc[j].ogr_num) != 0))  j++;

            // Eğer ilgili kitap ödünç kaydına karşılık gelen bir teslim kaydı bulunamadıysa.
            if ( j == kitap_odunc_count) {
                temp = student_head; // Öğrenci listesinin başına dön.
                // Öğrenci numarasını bul.
                while (temp != NULL && strcmp(temp->num, kitapOdunc[i].ogr_num) != 0)   temp = temp->next;

                if (temp != NULL) { // Öğrenci bulunduysa bilgilerini yazdır.
                    printf("Kitabı henüz teslim etmeyen öğrenci: İsim: %s %s, Numara: %s, Puan: %d\n",
                        temp->name, temp->surname, temp->num, temp->score);
                } else { // Öğrenci bulunamadıysa uyarı ver.
                    printf("Uyarı: Kayıtlı olmayan bir öğrenci numarası bulundu: %s (Kitabı henüz teslim etmemiş olabilir)\n", kitapOdunc[i].ogr_num);
                }
            }
        }
    }
}

// Cezalı öğrencileri (puanı -10 olanları) listeleyen fonksiyon.
void punish_student(STUDENT *head) {
    int is_on = 1; // Cezalı öğrenci olup olmadığını kontrol eden bayrak.

    // Öğrenci listesini gez.
    while ( head != NULL ) {
        if ( head->score == -10) { // Eğer öğrencinin puanı -10 ise cezalıdır.
            printf("Cezalı Öğrenci: İsim: %s %s, Numara: %s\n",head->name, head->surname, head->num);
            is_on = 0; // Cezalı öğrenci bulundu, bayrağı sıfırla.
        }
        head = head->next; // Bir sonraki öğrenciye geç.
    }
    if ( is_on ) { // Eğer hiçbir cezalı öğrenci bulunamadıysa.
        printf("\nUyarı: Sistemde cezalı öğrenci bulunmamaktadır.\n");
    }
}

// Tüm öğrencileri listeleyen fonksiyon.
void student_list_print(STUDENT *head) {
    // Öğrenci listesini gez.
    while ( head != NULL) {
        printf("Öğrenci Numarası: %s, Öğrenci İsim Soyisim: %s %s, Öğrenci Puanı: %d\n", head->num, head->name, head->surname, head->score);
        head = head->next; // Bir sonraki öğrenciye geç.
    }
}

// Öğrencinin kitap ödünç almasını sağlayan fonksiyon.
void kitap_odunc_al(char *student_num, char* book_name, STUDENT *student_head, KITAP_ODUNC **kitapOdunc, int *kitap_odunc_count, BOOKS *book_head, struct tm *zaman) {
    BOOK_ISBN *isbn_head; // Kitap ISBN düğümü için işaretçi.

    // Öğrenciyi numarasından bul.
    while (student_head != NULL && strcmp(student_head->num, student_num))  student_head = student_head->next;
    if (student_head == NULL) {
        printf("\nUyarı: Belirtilen öğrenci numarası bulunamadı.\n");
        return;
    }
    // Öğrenci cezalıysa kitap ödünç alamaz.
    if (student_head->score == -10) {
        printf("\nUyarı: Öğrenci cezalıdır, bu yüzden kitap ödünç verilemez.\n");
        return;
    }

    // Kitabı adından bul.
    while (book_head != NULL && strcmp(book_head->name, book_name))   book_head = book_head->next;
    if (book_head == NULL) {
        printf("\nUyarı: Belirtilen kitap bulunmamaktadır.\n");
        return;
    }

    isbn_head = book_head->ISBN_head; // Kitap örneklerinin listesine eriş.
    // Rafta olan (ödünç alınmamış) bir kitap örneğini bul.
    while ( isbn_head != NULL && strcmp(isbn_head->durum, "Rafta"))   isbn_head = isbn_head->next;
    if ( isbn_head == NULL) {
        printf("Uyarı: Rafta ödünç verilebilecek fazladan kitap bulunmamaktadır.\n");
        return;
    }

    strcpy(isbn_head->durum, student_num); // Kitap örneğinin durumunu öğrenci numarasıyla güncelle.
    // Kitap ödünç alma kayıtları dizisini yeniden boyutlandır.
    *kitapOdunc = (KITAP_ODUNC*)realloc(*kitapOdunc, sizeof(KITAP_ODUNC) * (*kitap_odunc_count + 1));

    // Yeni ödünç kaydını doldur.
    strcpy((*kitapOdunc)[*kitap_odunc_count].kitap_ISBN, isbn_head->ISBN);
    strcpy((*kitapOdunc)[*kitap_odunc_count].ogr_num, student_num);
    (*kitapOdunc)[*kitap_odunc_count].odunc = 0; // Ödünç alındı (0).
    (*kitapOdunc)[*kitap_odunc_count].gün = zaman->tm_mday;
    (*kitapOdunc)[*kitap_odunc_count].ay = zaman->tm_mon + 1; // tm_mon 0-11 arası olduğu için +1 ekle.
    (*kitapOdunc)[*kitap_odunc_count].yıl = zaman->tm_year + 1900; // tm_year 1900'den beri olduğu için +1900 ekle.
    *kitap_odunc_count += 1; // Kayıt sayısını artır.

    printf("\nKitap başarıyla ödünç alındı.\n");
}

// Öğrencinin kitabı teslim etmesini sağlayan fonksiyon.
void kitap_teslim_et(char *student_num, char *book_name, STUDENT *student_head, KITAP_ODUNC **kitapOdunc, int *kitap_odunc_count, BOOKS *book_head, struct tm *zaman) {
    BOOK_ISBN *isbn_head = NULL; // Kitap ISBN düğümü için işaretçi.
    int i; // Döngü sayacı.

    // Öğrenciyi numarasından bul.
    while (student_head != NULL && strcmp(student_head->num, student_num))  student_head = student_head->next;
    if (student_head == NULL) {
        printf("\nUyarı: Belirtilen öğrenci numarası bulunamadı.\n");
        return;
    }
    // Öğrenci cezalıysa kitap teslim edemez (ya da puanı yükselmez, bu durum ödünç almaktan farklı).
    if (student_head->score == -10) {
        printf("\nUyarı: Öğrenci cezalıdır. Kitap teslim edebilir ancak bu işlem cezasını etkilemeyecek. \n");
        return; 
    }

    // Kitabı adından bul.
    while (book_head != NULL && strcmp(book_head->name, book_name))   book_head = book_head->next;
    if (book_head == NULL) {
        printf("\nUyarı: Belirtilen kitap bulunmamaktadır.\n");
        return;
    }

    isbn_head = book_head->ISBN_head; // Kitap örneklerinin listesine eriş.
    // Öğrencinin ödünç aldığı belirli bir kitap örneğini bul.
    while ( isbn_head != NULL && strcmp(isbn_head->durum, student_num))   isbn_head = isbn_head->next;
    if ( isbn_head == NULL) {
        printf("Uyarı: Bu öğrenci, belirtilen kitabı daha önce ödünç almamıştır.\n");
        return;
    }

    // İlgili ödünç alma kaydını bulmak için diziyi tersten kontrol et.
    i = *kitap_odunc_count - 1; // Dizinin sonundan başla.
    while (i >= 0 && (strcmp((*kitapOdunc)[i].kitap_ISBN, isbn_head->ISBN) != 0 || strcmp((*kitapOdunc)[i].ogr_num, student_head->num) != 0 || (*kitapOdunc)[i].odunc == 1)) i--;

    // Eğer kitap 15 günden fazla gecikmeli teslim edildiyse öğrenci puanını düşür.
    if (i >= 0 && ((zaman->tm_year + 1900) - (*kitapOdunc)[i].yıl > 0 || (zaman->tm_mon + 1) - (*kitapOdunc)[i].ay > 0 || zaman->tm_mday - (*kitapOdunc)[i].gün > 15)) {
        student_head->score -= 10;
        printf("\nKitap gecikmeli teslim edildiği için öğrencinin puanı düşürüldü. Güncel puan: %d\n", student_head->score);
    }

    strcpy(isbn_head->durum, "Rafta"); // Kitap örneğinin durumunu "Rafta" olarak güncelle.
    // Kitap ödünç alma kayıtları dizisini yeniden boyutlandır.
    *kitapOdunc = (KITAP_ODUNC*)realloc(*kitapOdunc, sizeof(KITAP_ODUNC) * (*kitap_odunc_count + 1));

    // Yeni teslim kaydını doldur.
    strcpy((*kitapOdunc)[*kitap_odunc_count].kitap_ISBN, isbn_head->ISBN);
    strcpy((*kitapOdunc)[*kitap_odunc_count].ogr_num, student_num);
    (*kitapOdunc)[*kitap_odunc_count].odunc = 1; // Teslim edildi (1).
    (*kitapOdunc)[*kitap_odunc_count].gün = zaman->tm_mday;
    (*kitapOdunc)[*kitap_odunc_count].ay = zaman->tm_mon + 1;
    (*kitapOdunc)[*kitap_odunc_count].yıl = zaman->tm_year + 1900;
    *kitap_odunc_count += 1; // Kayıt sayısını artır.

    printf("\nKitap başarıyla teslim edildi.\n");
}

// Dosyalardan kitap ve kitap örneği bilgilerini okuyarak bağlı liste oluşturan fonksiyon.
BOOKS* books_to_list(FILE *fp, FILE *fp_isbn) {
    BOOKS *head = NULL, *temp = NULL, *new_node = NULL; // Ana kitap listesi için işaretçiler.
    char *token; // String parçalamak için kullanılacak işaretçi.
    char buffer[100]; // Dosyadan okunacak satırı tutmak için tampon bellek.

    // Ana kitaplar dosyasının sonuna kadar her satırı oku.
    while ( fgets(buffer, 100, fp) != NULL) {
        new_node = (BOOKS*)malloc(sizeof(BOOKS)); // Yeni bir kitap düğümü için bellek ayır.
        if (new_node == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            return NULL;
        }
        new_node->name = (char*)malloc(sizeof(char) * 100); // Kitap adı için bellek ayır.
        if (new_node->name == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            free(new_node);
            return NULL;
        }

        token = strtok(buffer, ","); // Satırı virgülle ayırarak kitap adını al.
        strcpy(new_node->name, token); // Adı yeni düğüme kopyala.

        token = strtok(NULL, ",") + 1; // Bir sonraki virgülle ayırarak ISBN'yi al (başıdaki boşluğu atla).
        strcpy(new_node->book_ISBN, token); // ISBN'yi yeni düğüme kopyala.

        token = strtok(NULL, "\n") + 1; // Yeni satır karakterine kadar ayırarak adet sayısını al (başıdaki boşluğu atla).
        new_node->adet = atoi(token); // Adet sayısını tamsayıya çevir.

        // Kitap örnekleri için ayrı bir bağlı liste oluştur ve ana kitaba bağla.
        new_node->ISBN_head = bookISBN_to_list(fp_isbn, new_node->adet);

        new_node->next = NULL; // Yeni düğümün sonraki işaretçisini NULL yap.

        // Bağlı listeye yeni düğümü ekle.
        if ( temp == NULL) {
            temp = head = new_node; // Liste boşsa, yeni düğüm hem baş hem de geçici düğüm olur.
        } else {
            temp->next = new_node; // Listenin sonuna yeni düğümü ekle.
            temp = temp->next; // Geçici düğümü yeni eklenen düğüme taşı.
        }
    }
    return head; // Oluşturulan bağlı listenin başını döndür.
}

// Kitap örnekleri dosyasından bilgileri okuyarak bir bağlı liste oluşturan fonksiyon.
BOOK_ISBN* bookISBN_to_list(FILE *fp, int count) {
    BOOK_ISBN* head = NULL, *temp = NULL, *new_node = NULL; // Kitap örnekleri listesi için işaretçiler.
    char isbn[16]; // ISBN numarası için tampon.
    char state[100];

    int i = 0; // Sayı sayacı.
    // Belirtilen 'count' miktarınca veya dosyanın sonuna kadar oku.
    while ( i < count && fscanf( fp, "%15s, %s", isbn, state) == 2 ) {
        new_node = (BOOK_ISBN*)malloc(sizeof(BOOK_ISBN)); // Yeni bir kitap örneği düğümü için bellek ayır.
        new_node->durum = (char*)malloc(sizeof(char) * 100); // Durum bilgisi için bellek ayır.

        strcpy(new_node->ISBN, isbn); // ISBN'yi yeni düğüme kopyala.
        strcpy(new_node->durum, state); // Durumu yeni düğüme kopyala.

        new_node->next = NULL; // Yeni düğümün sonraki işaretçisini NULL yap.

        // Bağlı listeye yeni düğümü ekle.
        if ( temp == NULL) {
            temp = head = new_node; // Liste boşsa, yeni düğüm hem baş hem de geçici düğüm olur.
        } else {
            temp->next = new_node; // Listenin sonuna yeni düğümü ekle.
            temp = temp->next; // Geçici düğümü yeni eklenen düğüme taşı.
        }
        i++; // Sayacı artır.
    }
    // Okunan örnek sayısı beklenenle eşleşmiyorsa hata mesajı yazdır.
    if ( i != count) {
        fprintf(stderr, "Kitabın örnek sayılarının bilgileri eksik veya dosya formatı hatalı.\n");
        exit(1); 
    }
    return head; // Oluşturulan bağlı listenin başını döndür.
}

// Kitap ve kitap örnekleri bağlı listelerinin belleğini serbest bırakan fonksiyon.
void book_and_bookSample_to_free(BOOKS *head) {
    BOOKS *to_free = NULL; // Ana kitap düğümünü serbest bırakmak için işaretçi.
    BOOK_ISBN *to_ISBN_free = NULL; // Kitap örneği düğümünü serbest bırakmak için işaretçi.
    BOOK_ISBN *isbn_head = NULL; // Kitap örneği listesi için geçici işaretçi.

    // Ana kitap listesi boş olana kadar döngüyü sürdür.
    while ( head != NULL) {
        to_free = head; // Mevcut ana kitap düğümünü serbest bırakılacak olarak işaretle.
        free(head->name); // Kitap adının belleğini serbest bırak.

        isbn_head = head->ISBN_head; // Kitap örneği listesinin başına eriş.
        // Kitap örneği listesi boş olana kadar döngüyü sürdür.
        while (isbn_head != NULL) {
            to_ISBN_free = isbn_head; // Mevcut kitap örneği düğümünü serbest bırakılacak olarak işaretle.
            free(isbn_head->durum); // Kitap örneği durumunun belleğini serbest bırak.
            isbn_head = isbn_head->next; // Bir sonraki kitap örneği düğümüne geç.
            free(to_ISBN_free); // Mevcut kitap örneği düğümünün belleğini serbest bırak.
        }
        head = head->next; // Bir sonraki ana kitap düğümüne geç.
        free(to_free); // Mevcut ana kitap düğümünün belleğini serbest bırak.
    }
}

// Bağlı listenin sonuna yeni bir kitap ekleyen fonksiyon.
void book_append(char *book_name, char *book_ISBN, int book_count, BOOKS **end_node) {
    int i; // Döngü sayacı.
    BOOK_ISBN *head = NULL, *temp = NULL, *new_node = NULL; // Yeni kitap örneği listesi için işaretçiler.

    // Mevcut son düğümün sonrasına yeni bir kitap düğümü için bellek ayır.
    (*end_node)->next = (BOOKS*)malloc(sizeof(BOOKS));

    // Yeni kitap düğümünün adı için bellek ayır.
    (*end_node)->next->name = (char*)malloc(sizeof(char) * 100);

    strcpy((*end_node)->next->name, book_name); // Yeni kitabın adını kopyala.
    strcpy((*end_node)->next->book_ISBN, book_ISBN); // Yeni kitabın ISBN'sini kopyala.
    (*end_node)->next->adet = book_count; // Yeni kitabın adet sayısını ayarla.

    // Belirtilen adet kadar yeni kitap örneği oluştur.
    for ( i = 0; i < book_count; i++) {
        new_node = (BOOK_ISBN*)malloc(sizeof(BOOK_ISBN)); // Yeni bir kitap örneği düğümü için bellek ayır.

        new_node->durum = (char*)malloc(sizeof(char) * 100); // Durum bilgisi için bellek ayır.

        sprintf(new_node->ISBN, "%s_%d", book_ISBN, i + 1); // Kitap örneği ISBN'sini oluştur.
        strcpy(new_node->durum, "Rafta"); // Durumu "Rafta" olarak ayarla.

        new_node->next = NULL; // Yeni düğümün sonraki işaretçisini NULL yap.

        // Kitap örneği bağlı listesine yeni düğümü ekle.
        if ( temp == NULL) {
            temp = head = new_node; // Liste boşsa, yeni düğüm hem baş hem de geçici düğüm olur.
        } else {
            temp->next = new_node; // Listenin sonuna yeni düğümü ekle.
            temp = temp->next; // Geçici düğümü yeni eklenen düğüme taşı.
        }
    }
    printf("\nKitap Örnek Sayısı Eklendi: %d\n", i); // Eklenen örnek sayısını yazdır.

    (*end_node)->next->ISBN_head = head; // Ana kitaba kitap örneği listesini bağla.
    (*end_node) = (*end_node)->next; // Ana listenin son düğüm işaretçisini yeni eklenen kitaba taşı.
    (*end_node)->next = NULL; // Yeni son düğümün sonraki işaretçisini NULL yap.

    printf("\nYeni kitap başarıyla kaydedildi.\n");
}

// Belirli bir isme sahip kitabı ve tüm örneklerini bağlı listeden silen fonksiyon.
void book_delete( char *book_name, BOOKS **head, KITAP_YAZAR *kitapYazar, int kitap_yazar_count) {
    BOOKS *to_delete = NULL; // Silinecek ana kitap düğümünü tutmak için işaretçi.
    BOOK_ISBN *to_delete_isbn = NULL; // Silinecek kitap örneği düğümünü tutmak için işaretçi.
    int i; // Döngü sayacı.

    // Silinecek kitap listenin başındaysa.
    if ( !strcmp((*head)->name, book_name)) {
        to_delete = *head; // Silinecek düğümü işaretle.
        *head = (*head)->next; // Baş işaretçisini bir sonraki düğüme taşı.
    } else {
        BOOKS *temp = *head; // Geçici bir işaretçi ile listenin başından başla.
        // Silinecek düğümü bulana veya listenin sonuna gelene kadar ilerle.
        while ( temp->next != NULL && strcmp(temp->next->name, book_name))   temp = temp->next;

        // Kitap bulunamadıysa.
        if ( temp->next == NULL) {
            printf("\nUyarı: Belirtilen isimde kitap bulunamadı.\n");
            return;
        }
        to_delete = temp->next; // Silinecek düğümü işaretle.
        temp->next = temp->next->next; // Silinecek düğümü listeden çıkar.
    }

    // Kitabın tüm örneklerini ve belleğini serbest bırak.
    while (to_delete->ISBN_head != NULL) {
        to_delete_isbn = to_delete->ISBN_head; // Silinecek kitap örneği düğümünü işaretle.
        to_delete->ISBN_head = to_delete->ISBN_head->next; // Bir sonraki örneğe geç.
        free(to_delete_isbn->durum); // Durum bilgisinin belleğini serbest bırak.
        free(to_delete_isbn); // Kitap örneği düğümünün belleğini serbest bırak.
    }

    // Kitap-yazar ilişkilerini güncelle (silinen kitabın ISBN'sini -1 yaparak veya başka bir uygun şekilde işaretleyerek).
    for( i = 0; i < kitap_yazar_count; i++) {
        if ( !strcmp(kitapYazar[i].ISBN, to_delete->book_ISBN))  kitapYazar[i].ID = -1; // Bu ilişkiyi geçersiz kıl.
    }

    free(to_delete->name); // Kitap adının belleğini serbest bırak.
    free(to_delete); // Ana kitap düğümünün belleğini serbest bırak.

    printf("\nKitap ve ilgili tüm örnekleri başarıyla silindi.\n");
}

// Belirli bir kitaba ait bilgileri güncelleyen fonksiyon.
void book_update( char *book_name, BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, KITAP_YAZAR *kitapYazar, int kitap_yazar_count) {
    // Kitabı adından bul.
    while ( book_head != NULL && strcmp(book_head->name, book_name) != 0)    book_head = book_head->next;
    if ( book_head == NULL) {
        printf("\nUyarı: Belirtilen isimde kitap bulunamadı.\n");
        return;
    }

    char *new_name = (char*)malloc(sizeof(char) * 100); // Yeni isim için bellek ayır.

    char new_ISBN[14]; // Yeni ISBN için tampon.
    int new_count; // Yeni adet sayısı.
    int i, count = 1; // Döngü sayaçları ve örnek sayısı takipçisi.
    BOOK_ISBN *isbn_head; // Kitap örnek listesi için işaretçi.

    printf("\nKitabın güncel bilgilerini giriniz:\n");
    printf("\nKitabın yeni ismi: ");
    scanf(" %[^\n]",new_name); // Yeni kitap adını al.
    printf("Kitabın yeni ISBN numarası: ");
    scanf(" %s",new_ISBN); // Yeni ISBN'yi al.
    printf("Kitabın yeni örnek kitap sayısı (öncekiden az olmamalı): ");
    scanf("%d",&new_count); // Yeni adet sayısını al.

    // Yeni adet sayısı mevcut adetten az ise uyarı ver ve işlemi sonlandır.
    if (book_head->adet > new_count) {
        printf("\nUyarı: Yeni kitap sayısı, mevcut kitap sayısından az olamaz. Güncelleme iptal edildi.\n");
        free(new_name);
        return;
    }

    // Kitap ödünç alma kayıtlarını güncelle (ISBN değiştiyse).
    for ( i = 0; i < kitap_odunc_count; i++) {
        if (strncmp(kitapOdunc[i].kitap_ISBN, book_head->book_ISBN, 13) == 0) {
            strncpy(kitapOdunc[i].kitap_ISBN, new_ISBN, 13);
        }
    }
    // Kitap-yazar ilişkilerini güncelle (ISBN değiştiyse).
    for ( i = 0; i < kitap_yazar_count; i++) {
        if (strcmp(kitapYazar[i].ISBN, book_head->book_ISBN) == 0) {
            strcpy(kitapYazar[i].ISBN, new_ISBN);
        }
    }

    isbn_head = book_head->ISBN_head; // Kitap örnek listesinin başına eriş.
    // Mevcut kitap örneklerinin ISBN'lerini güncelle ve sayısını bul.
    while (isbn_head != NULL && isbn_head->next != NULL) {
        count++;
        strncpy(isbn_head->ISBN, new_ISBN, 13);
        isbn_head = isbn_head->next;
    }
    if (isbn_head != NULL) { // Son düğümü de güncelle.
        count++;
        strncpy(isbn_head->ISBN, new_ISBN, 13);
    }

    // Yeni eklenmesi gereken örnekler varsa oluştur ve listeye ekle.
    BOOK_ISBN *new_node = NULL; // Yeni kitap örneği düğümü için işaretçi.
    for ( i = 0; i < new_count - book_head->adet; i++) {
        new_node = (BOOK_ISBN*)malloc(sizeof(BOOK_ISBN)); // Yeni düğüm için bellek ayır.
        if (new_node == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            free(new_name);
            return;
        }
        new_node->durum = (char*)malloc(sizeof(char) * 100); // Durum için bellek ayır.
        if (new_node->durum == NULL) { // Bellek ayırma hatası kontrolü
            perror("Bellek ayrılamadı.");
            free(new_node);
            free(new_name);
            return;
        }
        strcpy(new_node->durum, "Rafta"); // Durumu "Rafta" olarak ayarla.
        sprintf(new_node->ISBN, "%s_%d", new_ISBN, count++); // Yeni örnek ISBN'sini oluştur.
        new_node->next = NULL; // Sonraki işaretçiyi NULL yap.

        if (isbn_head != NULL) { // Mevcut örnek listesinin sonuna ekle.
            isbn_head->next = new_node;
            isbn_head = isbn_head->next;
        } else { // Hiç örnek yoksa, ilk örnek olarak ekle.
            book_head->ISBN_head = new_node;
            isbn_head = new_node;
        }
    }
    // Ana kitap bilgilerini güncelle.
    strcpy(book_head->name, new_name);
    strcpy(book_head->book_ISBN, new_ISBN);
    book_head->adet = new_count;

    free(new_name); // Ayırılan belleği serbest bırak.
    printf("\nKitap bilgileri başarıyla güncellendi.\n");
}

// Kitap ve kitap örnekleri bilgilerini dosyalara kaydeden fonksiyon.
void book_and_bookSample_file_save (BOOKS *head) {
    FILE *fp_book =fopen("Dataset/Kitaplar.csv", "w"); // Kitaplar dosyasını yazma modunda aç.
    if (fp_book == NULL) { // Dosya açma hatası kontrolü
        perror("Kitaplar dosyası açılamadı.");
        return;
    }
    FILE *fp_bookSample = fopen("Dataset/KitapOrnekleri.csv", "w"); // Kitap örnekleri dosyasını yazma modunda aç.
    if (fp_bookSample == NULL) { // Dosya açma hatası kontrolü
        perror("Kitap Ornekleri dosyası açılamadı.");
        fclose(fp_book); // Diğer dosyayı kapat.
        return;
    }

    BOOK_ISBN *isbn_head = NULL; // Kitap örnek listesi için işaretçi.

    // Ana kitap listesi boş olana kadar her düğümü gez.
    while (head != NULL) {
        fprintf(fp_book, "%s, %s, %d\n", head->name, head->book_ISBN, head->adet); // Kitap bilgilerini yaz.
        isbn_head = head->ISBN_head; // Kitap örnek listesinin başına eriş.
        // Kitap örnek listesi boş olana kadar her düğümü gez.
        while ( isbn_head != NULL) {
            fprintf(fp_bookSample, "%s, %s\n", isbn_head->ISBN, isbn_head->durum); // Kitap örneği bilgilerini yaz.
            isbn_head = isbn_head->next; // Bir sonraki örneğe geç.
        }
        head = head->next; // Bir sonraki ana kitaba geç.
    }
    fclose(fp_book); // Kitaplar dosyasını kapat.
    fclose(fp_bookSample); // Kitap örnekleri dosyasını kapat.
    printf("\nKitap ve örnek bilgileri dosyalara kaydedildi.\n");
}

// Belirli bir kitabın bilgilerini ve tüm örneklerinin durumlarını gösteren fonksiyon.
void book_info(char *book_name, BOOKS *head) {
    BOOK_ISBN *isbn_head = NULL; // Kitap örnek listesi için işaretçi.

    // Kitabı adından bul.
    while ( head != NULL) {
        if ( !strcmp(head->name, book_name)) { // Kitap bulunduysa
            printf("\nKitap İsmi: %s, Kitap ISBN: %s, Kitap Mevcut Adet: %d\n\n",head->name, head->book_ISBN, head->adet);
            isbn_head = head->ISBN_head; // Kitap örnek listesinin başına eriş.
            // Tüm kitap örneklerinin bilgilerini yazdır.
            while ( isbn_head != NULL) {
                printf("Örnek Kitap ISBN: %s, Durumu: %s\n", isbn_head->ISBN, isbn_head->durum);
                isbn_head = isbn_head->next; // Bir sonraki örneğe geç.
            }
            return; // Kitap bulunduğu için döngüden çık.
        }
        head = head->next; // Bir sonraki kitaba geç.
    }
    printf("\nUyarı: Belirtilen isimde kitap bulunamadı.\n");
}

// Tüm kitapları ve tüm örneklerinin durumlarını listeleyen fonksiyon.
void books_list_print(BOOKS* head) {
    BOOK_ISBN *isbn_head = NULL; // Kitap örnek listesi için işaretçi.

    // Ana kitap listesi boş olana kadar her düğümü gez.
    while ( head != NULL) {
        printf("\nKitap İsmi: %s, Kitap ISBN: %s, Kitap Mevcut Adet: %d\n\n",head->name, head->book_ISBN, head->adet);
        isbn_head = head->ISBN_head; // Kitap örnek listesinin başına eriş.
        // Tüm kitap örneklerinin bilgilerini yazdır.
        while ( isbn_head != NULL) {
            printf("Örnek Kitap ISBN: %s, Durumu: %s\n", isbn_head->ISBN, isbn_head->durum);
            isbn_head = isbn_head->next; // Bir sonraki örneğe geç.
        }
        head = head->next; // Bir sonraki ana kitaba geç.
    }
}

// Bu fonksiyon, kütüphanedeki geç teslim edilmiş kitapları bulur ve bilgilerini ekrana yazdırır.
void geç_teslim_kitaplar(BOOKS *book_head, KITAP_ODUNC *kitapOdunc, int kitap_odunc_count, struct tm *zaman) {
    int i, j; // Döngüler için sayaç değişkenleri
    BOOKS *book = NULL; // Kitap listesinde gezinmek için geçici işaretçi

    // Tüm kitap ödünç kayıtları üzerinde döngü başlatılır
    for ( i = 0; i < kitap_odunc_count; i++) {
        // Yalnızca ödünç alınmış (teslim edilmemiş) kayıtları kontrol et
        if ( kitapOdunc[i].odunc == 0 ) {
            j = i + 1; // Aynı kitabın ve öğrencinin sonraki kayıtlarını aramak için ikinci bir sayaç başlatılır

            // Aynı kitabın aynı öğrenci tarafından yapılmış bir sonraki ödünç kaydını arar.
            while ( j < kitap_odunc_count && (strcmp(kitapOdunc[i].kitap_ISBN, kitapOdunc[j].kitap_ISBN) != 0 || // ISBN farklıysa devam et
                    strcmp(kitapOdunc[i].ogr_num, kitapOdunc[j].ogr_num) != 0 || // Öğrenci numarası farklıysa devam et
                    kitapOdunc[j].odunc == 0)) { // Sonraki kayıt da ödünç ise (yani henüz iade edilmemişse) devam et
                        j++; 
                }

            if ( j == kitap_odunc_count) {
                // Kitap teslim tarihinin şu anki zamana göre gecikip gecikmediğini kontrol et
                if ((zaman->tm_year + 1900) - kitapOdunc[i].yıl > 0 || // Yıl farkı varsa
                    (zaman->tm_mon + 1) - kitapOdunc[i].ay > 0 || // Ay farkı varsa
                    zaman->tm_mday - kitapOdunc[i].gün > 15) { // Gün farkı 15'ten büyükse
                    
                    book = book_head; // Kitap listesinin başına dön
                    // Kitabı ISBN'ye göre bul (strncmp ile 13 karakter karşılaştırma)
                    while ( book != NULL && strncmp(book->book_ISBN, kitapOdunc[i].kitap_ISBN, 13))  book = book->next;
                    
                    // Kitap bulunduysa, gecikmiş teslimat bilgilerini yazdır
                    if (book != NULL) { // NULL kontrolü eklendi
                        printf("Kitabın ismi: %s, kitabın örneğinin isbn numarası: %s, kitabı teslim etmeyen öğrencinin numarası: %s\n", book->name, kitapOdunc[i].kitap_ISBN, kitapOdunc[i].ogr_num);
                    }
                }
            } else {
                // ödünç alma ve iade tarihleri arasındaki farkın 15 günden fazla olup olmadığını kontrol et.
                if (kitapOdunc[j].yıl - kitapOdunc[i].yıl > 0 || // Yıl farkı varsa
                    kitapOdunc[j].ay - kitapOdunc[i].ay > 0 || // Ay farkı varsa
                    kitapOdunc[j].gün - kitapOdunc[i].gün > 15) { // Gün farkı 15'ten büyükse
                        
                        book = book_head; // Kitap listesinin başına dön
                        // Kitabı ISBN'ye göre bul (strncmp ile 13 karakter karşılaştırma)
                        while ( book != NULL && strncmp(book->book_ISBN, kitapOdunc[i].kitap_ISBN, 13))  book = book->next;
                        
                        // Kitap bulunduysa, gecikmiş teslimat bilgilerini yazdır
                        if (book != NULL) { // NULL kontrolü eklendi
                            printf("Kitabın ismi: %s, kitabın örneğinin isbn numarası: %s, kitabı teslim etmeyen öğrencinin numarası: %s\n", book->name, kitapOdunc[i].kitap_ISBN, kitapOdunc[i].ogr_num);
                        }
                    }
                }
            }
        }
    }

// Yazar ve kitap arasında ilişki kuran (eşleştiren) fonksiyon.
void pair(char *yazar_name, char *yazar_surname, char *book_name, YAZARLAR *yazar_head, BOOKS *book_head, KITAP_YAZAR **kitapYazar, int *kitap_yazar_count) {
    // Yazarı ad ve soyadına göre bul.
    while ( yazar_head != NULL && (strcmp(yazar_head->name, yazar_name) != 0 && strcmp(yazar_head->surname, yazar_surname) != 0 )) {
        yazar_head = yazar_head->next;
    }
    if ( yazar_head == NULL) {
        printf("\nUyarı: Belirtilen isim ve soyisimde yazar bulunamadı.\n");
        return;
    }
    // Kitabı adına göre bul.
    while ( book_head != NULL && strcmp(book_head->name, book_name) != 0 ) {
        book_head = book_head->next;
    }
    if ( book_head == NULL) {
        printf("\nUyarı: Belirtilen isimde kitap bulunamadı.\n");
        return;
    }

    // KITAP_YAZAR dizisini yeniden boyutlandır.
    *kitapYazar = (KITAP_YAZAR*)realloc(*kitapYazar, sizeof(KITAP_YAZAR) * (*kitap_yazar_count + 1));
    if (*kitapYazar == NULL) { // Bellek ayırma hatası kontrolü
        perror("Bellek yeniden ayrılamadı.");
        return;
    }
    // Yeni ilişki kaydını doldur.
    strcpy((*kitapYazar)[*kitap_yazar_count].ISBN, book_head->book_ISBN);
    printf("\nYazar ID: %d\n",yazar_head->ID); // Yazar ID'sini doğrulama amaçlı yazdır.
    (*kitapYazar)[*kitap_yazar_count].ID = yazar_head->ID; // Yazar ID'sini ata.
    *kitap_yazar_count += 1; // Kayıt sayısını artır.
    printf("\nYazar ve kitap arasında başarıyla eşleştirme yapıldı.\n");
}

// Bir kitabın yazarını değiştiren fonksiyon.
void kitap_yazar_change(char *book_name, char *yazar_surname, char *yazar_name, BOOKS *book_head, YAZARLAR* yazar_head, KITAP_YAZAR* kitapYazar, int kitap_yazar_count ) {
    int i ; // Döngü sayacı.

    // Yeni yazarı ad ve soyadına göre bul.
    while ( yazar_head != NULL && (strcmp(yazar_head->name, yazar_name) != 0 || strcmp(yazar_head->surname, yazar_surname) != 0) ) {
        yazar_head = yazar_head->next;
    }
       
    if ( yazar_head == NULL) {
        printf("\nUyarı: Belirtilen isim ve soyisimde yazar bulunamadı.\n");
        return;
    }

    // Kitabı adına göre bul.
    while ( book_head != NULL && strcmp(book_head->name, book_name) != 0)    book_head = book_head->next; 
    if ( book_head == NULL) {
        printf("\nUyarı: Belirtilen isimde kitap bulunamadı.\n");
        return;
    }

    // Kitabın mevcut yazar ilişkilerini güncelle.
    for (i = 0; i < kitap_yazar_count; i++) {
        if ( !strcmp(book_head->book_ISBN, kitapYazar[i].ISBN)) {
            kitapYazar[i].ID = yazar_head->ID; // Yazar ID'sini yeni yazarın ID'si ile değiştir.
        }
    }
    printf("\nKitabın yazarı başarıyla güncellendi.\n");
}

// Dosyadan kitap-yazar ilişkilerini okuyarak bir diziye kaydeden fonksiyon.
KITAP_YAZAR* kitap_yazar_save(FILE *fp, int *kitap_yazar_count) {
    KITAP_YAZAR *kitapYazar = NULL; // Kitap-yazar ilişkilerini tutacak dinamik dizi.
    char isbn[14]; // ISBN numarası için tampon.
    int id; // Yazar ID'si için değişken.
    int i = 0; // Satır sayacı.

    // Dosyadaki toplam satır sayısını (ilişki sayısını) belirlemek için ilk geçiş.
    while (fscanf(fp, "%13s, %d", isbn, &id) == 2) {
        i++; // Her başarılı okumada sayacı artır.
    }

    // Toplam satır sayısına göre dinamik dizi için bellek ayır.
    kitapYazar = (KITAP_YAZAR*)malloc( sizeof(KITAP_YAZAR) * i);

    fseek(fp, 0, SEEK_SET); // Dosya işaretçisini dosyanın başına geri taşı.
    i = 0; // Sayacı sıfırla, veri okumaya başla.

    // Dosyadan tekrar okuma yaparak verileri diziye kaydet.
    while ( fscanf(fp, "%13s, %d", isbn, &id) == 2) {
        strcpy(kitapYazar[i].ISBN, isbn); // Kitap ISBN'sini kopyala.
        kitapYazar[i].ID = id; // Yazar ID'sini ata.
        i++; // Bir sonraki elemana geç.
    }

    *kitap_yazar_count = i; // Toplam ilişki sayısını güncelle.
    printf("\nKitap-yazar ilişkileri dosyadan başarıyla yüklendi. Toplam ilişki: %d\n", *kitap_yazar_count);
    return kitapYazar; // Yüklenen diziyi döndür.
}

// Kitap-yazar ilişkilerini bir dosyaya kaydeden fonksiyon.
void kitap_yazar_file_save(KITAP_YAZAR *kitapYazar, int kitap_yazar_count) {
    FILE *new_fp = fopen("Dataset/KitapYazar.csv", "w"); // "KitapYazar.csv" dosyasını yazma modunda aç.

    int i; // Döngü sayacı.
    // Dizideki tüm kitap-yazar ilişkilerini dosyaya yaz.
    for ( i = 0; i < kitap_yazar_count; i++) {
        // Her bir ilişkiyi "ISBN,ID" formatında dosyaya yaz.
        fprintf ( new_fp, "%s, %d\n", kitapYazar[i].ISBN, kitapYazar[i].ID);
    }
    fclose(new_fp); // Dosyayı kapat.
    printf("\nKitap-yazar ilişkileri dosyaya başarıyla kaydedildi.\n");
}

// Dosyadan kitap ödünç alma kayıtlarını okuyarak bir diziye kaydeden fonksiyon.
KITAP_ODUNC* kitap_odunc_save(FILE *fp, int *kitap_odunc_count) {
    KITAP_ODUNC *kitapOdunc = NULL; // Kitap ödünç alma kayıtlarını tutacak dinamik dizi.
    char buffer[100]; // Dosyadan okunacak satırı tutmak için tampon bellek.
    char *token; // String parçalamak için kullanılacak işaretçi.
    int i = 0; // Satır sayacı.

    // Dosyadaki toplam satır sayısını (kayıt sayısını) belirlemek için ilk geçiş.
    while (fgets(buffer, 100, fp) != NULL) {
        i++; // Her başarılı okumada sayacı artır.
    }

    // Toplam satır sayısına göre dinamik dizi için bellek ayır.
    kitapOdunc = (KITAP_ODUNC*)malloc(sizeof(KITAP_ODUNC) * i);

    fseek(fp, 0, SEEK_SET); // Dosya işaretçisini dosyanın başına geri taşı.
    i = 0; // Sayacı sıfırla, veri okumaya başla.

    // Dosyadan tekrar okuma yaparak verileri diziye kaydet.
    while ( fgets(buffer, 100, fp) != NULL) {
        token = strtok(buffer, ","); // İlk virgülle ayırarak kitap ISBN'sini al.
        strcpy(kitapOdunc[i].kitap_ISBN, token); // ISBN'yi diziye kopyala.

        token = strtok(NULL, ","); // Bir sonraki virgülle ayırarak öğrenci numarasını al.
        strcpy(kitapOdunc[i].ogr_num, token); // Öğrenci numarasını diziye kopyala.

        token = strtok(NULL,","); // Bir sonraki virgülle ayırarak ödünç durumunu al.
        kitapOdunc[i].odunc = atoi(token); // Ödünç durumunu tamsayıya çevir.

        token = strtok(NULL, "."); // İlk noktaya kadar ayırarak günü al.
        kitapOdunc[i].gün = atoi(token); // Günü tamsayıya çevir.

        token = strtok(NULL, "."); // İkinci noktaya kadar ayırarak ayı al.
        kitapOdunc[i].ay = atoi(token); // Ayı tamsayıya çevir.

        token = strtok(NULL, "\n"); // Yeni satır karakterine kadar ayırarak yılı al.
        kitapOdunc[i].yıl = atoi(token); // Yılı tamsayıya çevir.

        i++; // Bir sonraki elemana geç.
    }
    *kitap_odunc_count = i; // Toplam kayıt sayısını güncelle.
    printf("\nKitap ödünç alma kayıtları dosyadan başarıyla yüklendi. Toplam kayıt: %d\n", *kitap_odunc_count);
    return kitapOdunc; // Yüklenen diziyi döndür.
}

// Kitap ödünç alma kayıtlarını bir dosyaya kaydeden fonksiyon.
void kitap_odunc_file_save(KITAP_ODUNC *kitapOdunc, int kitap_odunc_count) {
    int i; // Döngü sayacı.
    FILE *new_fp = fopen("Dataset/KitapOdunc.csv", "w"); // "KitapOdunc.csv" dosyasını yazma modunda aç.

    // Dizideki tüm kitap ödünç alma kayıtlarını dosyaya yaz.
    for ( i = 0; i < kitap_odunc_count; i++) {
        // Her bir kaydı belirli bir formatta (ISBN,ogr_num,odunc,gün.ay.yıl) dosyaya yaz.
        fprintf(new_fp, "%s,%s,%d,%02d.%02d.%d\n",
            kitapOdunc[i].kitap_ISBN,
            kitapOdunc[i].ogr_num,
            kitapOdunc[i].odunc,
            kitapOdunc[i].gün,
            kitapOdunc[i].ay,
            kitapOdunc[i].yıl
            );
    }
    fclose(new_fp); // Dosyayı kapat.
    printf("\nKitap ödünç alma kayıtları dosyaya başarıyla kaydedildi.\n");
}
