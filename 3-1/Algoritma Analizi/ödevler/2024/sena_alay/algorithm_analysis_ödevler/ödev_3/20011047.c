//
//  main.c
//  20011047algohw3
//
//  Created by Sena ALAY on 2.12.2023.
//

/*
@brief Bu program, bir Hash Table  üzerinde ekleme, silme, arama ve düzenleme islemleri yapar.
       Kullanıcı adlarını saklamak için Horner Kuralı kullanarak karma degerler hesaplar ve cakisma olursa double hashing yöntemi uygular
       Program, kullanıcıdan alınan N değeri ve load factor göre dinamik olarak boyutlandırılmış bir hash tablosu oluşturur.
       Bu tablo, kullanıcı adlarını saklamak ve hızlı erisim sağlamak için kullanabilir.

       Programın icerdigi islevler:
       - Kullanıcıdan N değeri ve load factoru alarak tablo boyutunu hesaplama
       - Horner Kuralı kullanarak ile stringlerin key karsilgiini hesaplama
       - Double hashing yöntemiyle çakışma çözümü
       - Ekleme, silme, arama ve tablo düzenleme işlevleri
       - Karma tablonun durumunu ekrana yazdırma
       - DEBUG ve NORMAL modlarda çalışma yeteneği

       Programın sonunda, kullanıcı karma tablonun güncel durumunu görebilir ve yaptığı işlemlerin sonuçlarını inceleyebilir.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 30
#define EMPTY_ENTRY(entry) ((entry).userName[0] == '\0')
#define DELETED_ENTRY(entry) ((entry).deleted)


typedef struct {
    char userName[MAX_NAME_LENGTH];
    int deleted;
} HashEntry;

typedef struct {
    HashEntry *table;
    int size;
    float loadFactor;
    int elementCount;
} HashTable;

// Fonksiyon prototipleri, aşağıda detaylı olarak açıklanmıştır
unsigned long hornerHash(char *str, int tableSize);
int isPrime(int num);
int calculateTableSize(int n, float loadFactor);
int h1(unsigned long key, int tableSize);
int h2(unsigned long key, int tableSize);
int hasDeletedEntry(HashTable *table);
HashTable createHashTable(int size, float loadFactor);
void freeHashTable(HashTable *table);
void displayHashTable(HashTable *table);
int findSlot(HashTable *table, char *userName, char *mode, int h1Value, int h2Value);
void insertEntry(HashTable *table, char *userName, char *mode, int n);
void deleteEntry(HashTable *table, char *userName, char *mode);
HashEntry *searchEntry(HashTable *table, char *userName, char *mode);
void rehash(HashTable *table, char *mode);
void reorganizeTable(HashTable *table, char *mode);

/*
@brief Bu fonksiyon, bir string degrini alıp ona Horner Kuralı uygular bu metnin degerini hesaplar
@param str[] -> Karma değeri hesaplanacak metin
@param tableSize -> hash tablosunun boyutu
@return Hesaplanan degeri return eder
*/
unsigned long hornerHash(char *str, int tableSize) {
    unsigned long hash = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % tableSize;
    }
    return hash;
}

/*
@brief Bu fonksiyon, verilen bir sayinin asallik durumunu asal olup olmadigini check etmek icindir
@param num -> asalligi kontrol edilecek sayı
@return Asal ise 1, değilse 0 dondurecek
*/
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    int i;

    // 5 ve 5'ten büyük tüm asal sayılar 6k ± 1 formundadır
    for (i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

/*
@brief Bu fonksiyon, verilen N değeri ve load factor göre ideal hash tablosu boyutunu hesaplayabilmek icindir.
@param n -> Tabloya eklenecek eleman sayısı
@param loadFactor -> Tablonun load factoru kullancii tarafindan girilir
@return Hesaplanan tablo boyutu
*/
int calculateTableSize(int n, float loadFactor) {
    int theoreticalSize = (int)ceil(n / loadFactor);
        
        // En küçük asal sayıyı bulana kadar döngü

    while (!isPrime(theoreticalSize)) {
        theoreticalSize++;
    }
    return theoreticalSize;
}

/*
@brief Bu fonksiyon, verilen (key) ve tablo boyutu için primary hash fonksiyonunu (h1) hesaplar.
@param key -> hash değeri
@param tableSize -> hash tablosunun boyutu
@return Hesaplanan birincil hash indeksi
*/
int h1(unsigned long key, int tableSize) {
    return key % tableSize;
}

/*
@brief Bu fonksiyon, verilen değeri (key) ve tablo boyutu için secondary hash fonksiyonunu (h2) hesaplar.
@param key -> hash değeri
@param tableSize -> hash tablosunun boyutu
@return Hesaplanan ikincil hash indeksi
*/
int h2(unsigned long key, int tableSize) {
    return 1 + (key % (tableSize - 2));
}

/*
@brief Bu fonksiyon, hash tablosunda silinmiş bir username olup olmadigini kontrol eder.
@param table -> Kontrol edilecek hash tablosu
@return Silinmiş bir giriş varsa 1, yoksa 0 döndürür
*/
int hasDeletedEntry(HashTable *table) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (DELETED_ENTRY(table->table[i])) {
            return 1;
        }
    }
    return 0;
}

/*
@brief Bu fonksiyon, belirtilen boyut ve load factoru ile yeni bir hash tablosu oluşturur.
@param size -> Tablonun boyutu
@param loadFactor -> load factor kullanici tarafından girilen en basta
@return olusturulan hash tablosu
*/
HashTable createHashTable(int size, float loadFactor) {
    HashTable table;
    table.size = size;
    table.loadFactor = loadFactor;
    table.elementCount = 0;
    table.table = (HashEntry *)calloc(size, sizeof(HashEntry));
    return table;
}

/*
@brief Bu fonksiyon, bir hash tablosunu free etmek icin ve kaynaklari temizleme icin.
@param table -> Serbest bırakılacak hash tablosu
*/
void freeHashTable(HashTable *table) {
    free(table->table);
    table->table = NULL;
    table->size = 0;
    table->elementCount = 0;
}

/*
@brief Bu fonksiyon, hash tablosunun icerigini ekrana yazdirir.
@param table -> yazdirilicak hash tablosu
*/
void displayHashTable(HashTable *table) {
    printf("\nHash Tablosu Boyutu: %d\n", table->size);
    printf("Hash Tablosu İcerigi:\n");
    int i;
    for ( i = 0; i < table->size; i++) {
        if (!EMPTY_ENTRY(table->table[i])) {
            printf("Adres: %d, kullanici adi: %s, Durum: %s\n",
                   i,
                   table->table[i].userName,
                   DELETED_ENTRY(table->table[i]) ? "Silinmis" : "Aktif");
        }
    }
}

/*
@brief Bu fonksiyon, verilen kullanıcı adı için hash tablosunda uygun bir yuva (slot) bulur.
@param table -> Arama yapılacak hash tablosu
@param userName -> Aranacak kullanıcı adı
@param mode -> Çalışma modu (DEBUG veya NORMAL)
@param h1Value -> Birincil karma değeri
@param h2Value -> İkincil karma değeri
@return Bulunan yuva indeksi veya -1
*/
int findSlot(HashTable *table, char *userName, char *mode, int h1Value, int h2Value) {
    int index;
    int i;

    if (strcmp(mode, "DEBUG") == 0) {
        printf("h1(%s) = %d\n", userName, h1Value);
        printf("h2(%s) = %d\n", userName, h2Value);
    }

    for (i = 0; i < table->size; i++) {
        index = (h1Value + i * h2Value) % table->size;

        if (strcmp(mode, "DEBUG") == 0) {
            printf("Deneme %d: Adres: %d\n", i + 1, index);
        }

        if (EMPTY_ENTRY(table->table[index]) || DELETED_ENTRY(table->table[index]) || strcmp(table->table[index].userName, userName) == 0) {
            if (strcmp(mode, "DEBUG") == 0) {
                printf("%s kelimesi %d. adreste %s.\n", userName, index, EMPTY_ENTRY(table->table[index]) || DELETED_ENTRY(table->table[index]) ? "bulunamadı" : "bulundu");
            }
            return index;
        }
    }
    return -1;
}

/*
@brief Bu fonksiyon, hash tablosuna yeni bir giriş ekler.
@param table -> Ekleme yapılacak hash tablosu
@param userName -> Eklenecek kullanıcı adı
@param mode -> Çalışma modu (DEBUG veya NORMAL)
@param n -> Maksimum eleman sayısı
*/
void insertEntry(HashTable *table, char *userName, char *mode, int n) {
    unsigned long key = hornerHash(userName, table->size);
    int h1Value = h1(key, table->size);
    int h2Value = h2(key, table->size);

    if (table->elementCount >= n) {
        printf("Tabloya %d kadar eleman girdiniz. Tekrar ekleme yapamazsiniz.\n", n);
        return;
    }

    int index = findSlot(table, userName, mode, h1Value, h2Value);


    if (index == -1) {
        printf("Tablo dolu, daha fazla eleman ekleyemezsiniz.\n");
        return;
    }

    if (EMPTY_ENTRY(table->table[index]) || DELETED_ENTRY(table->table[index])) {
        strcpy(table->table[index].userName, userName);
        table->table[index].deleted = 0;
        table->elementCount++;
        printf("Elemaniniz %d. adrese yerlestirildi.\n", index);
    } else {
        printf("Eleman tabloda mevcut oldugu icin ekleme islemi yapilmadi\n");
    }
}

/*
@brief Bu fonksiyon, hash tablosundan bir girişi siler.
@param table -> Silme işlemi yapılacak hash tablosu
@param userName -> Silinecek kullanıcı adı
@param mode -> Çalışma modu (DEBUG veya NORMAL)
*/
void deleteEntry(HashTable *table, char *userName, char *mode) {
    unsigned long key = hornerHash(userName, table->size);
    int h1Value = h1(key, table->size);
    int h2Value = h2(key, table->size);

    int index = findSlot(table, userName, mode, h1Value, h2Value);

    if (!EMPTY_ENTRY(table->table[index]) && !DELETED_ENTRY(table->table[index])) {
        table->table[index].deleted = 1;
        printf("%d adresindeki %s elemani silindi.\n", index, userName);
    } else {
        printf("%s elemani tabloda bulunmuyor.\n", userName);
    }
}

/*
@brief Bu fonksiyon, hash tablosunda belirtilen kullanıcı adını arar.
@param table -> Arama yapılacak hash tablosu
@param userName -> Aranacak kullanıcı adı
@param mode -> Çalışma modu (DEBUG veya NORMAL)
@return Bulunan HashEntry nesnesinin adresi veya NULL
*/
HashEntry *searchEntry(HashTable *table, char *userName, char *mode) {
    unsigned long key = hornerHash(userName, table->size);
    int h1Value = h1(key, table->size);
    int h2Value = h2(key, table->size);

    int index = findSlot(table, userName, mode, h1Value, h2Value);
    if (!EMPTY_ENTRY(table->table[index]) && !DELETED_ENTRY(table->table[index])) {
        printf("%s elemani %d adresinde bulunuyor.\n", userName, index);
        return &table->table[index];
    } else {
        printf("%s elemani tabloda bulunamadi.\n", userName);
        return NULL;
    }
}

/*
@brief Bu fonksiyon, hash tablosunu yeniden düzenler (rehash).
@param table -> Yeniden düzenlenecek hash tablosu
@param mode -> Çalışma modu (DEBUG veya NORMAL)
*/
void rehash(HashTable *table, char *mode) {
    int i;
    int oldSize = table->size;
    HashEntry *oldTable = table->table;

    // Aynı boyutta yeni bir tablo oluştur
    HashEntry *newTable = (HashEntry *)calloc(oldSize, sizeof(HashEntry));
    HashTable tempTable;
    tempTable.table = newTable;
    tempTable.size = oldSize;
    tempTable.elementCount = 0;  // Yeni tablonun eleman sayısını sıfırla


    for (i = 0; i < oldSize; i++) {
        if (!EMPTY_ENTRY(oldTable[i]) && !DELETED_ENTRY(oldTable[i])) {
            unsigned long key = hornerHash(oldTable[i].userName, oldSize);
            int h1Value = h1(key, oldSize);
            int h2Value = h2(key, oldSize);

            // Eski tablodaki eleman için yeni adresi bul
            int newIndex = findSlot(&tempTable, oldTable[i].userName, mode, h1Value, h2Value);
            newTable[newIndex] = oldTable[i];

            if (strcmp(mode, "DEBUG") == 0) {
                printf("Rehash: Eski Adres: %d, Yeni Adres: %d, Kullanici: %s\n", i, newIndex, oldTable[i].userName);
            }

            // Yeni tablonun eleman sayısını güncelle
            tempTable.elementCount++;
        }
    }

    // Eski tabloyu serbest bırak ve yeni tabloyu atama
    free(oldTable);
    table->table = newTable;
    table->elementCount = tempTable.elementCount;
}

/*
@brief Bu fonksiyon, hash tablosunu düzenler, silinmiş girişleri yeni bir tabloya taşır.
@param table -> Düzenlenecek hash tablosu
@param mode -> Çalışma modu (DEBUG veya NORMAL)
*/
void reorganizeTable(HashTable *table, char *mode) {
    if (table->elementCount == 0) {
        printf("Tablo bos, eleman ekleyip silmeden duzenleme yapilamaz.\n");
        return;
    }

    if (!hasDeletedEntry(table)) {
        printf("Tabloda silinmis eleman yok. once eleman silin ve sonra duzenleyin.\n");
        return;
    }

    // Yeni tablo oluştur
    HashTable newTable = createHashTable(table->size, table->loadFactor);
    int i;
    for (i = 0; i < table->size; i++) {
        if (DELETED_ENTRY(table->table[i])) {
            unsigned long key = hornerHash(table->table[i].userName, table->size);
            int h1Value = h1(key, table->size);
            int h2Value = h2(key, table->size);

            int newIndex = findSlot(&newTable, table->table[i].userName, mode, h1Value, h2Value);
            strcpy(newTable.table[newIndex].userName, table->table[i].userName);
            newTable.table[newIndex].deleted = 1; // Taşınan eleman silinmis olarak işaretlenmeli
            newTable.elementCount++;

            if (strcmp(mode, "DEBUG") == 0) {
                printf("Duzenleme: Eski Adres: %d, Yeni Adres: %d, Kullanici: %s\n", i, newIndex, table->table[i].userName);
            }
        }
    }

    freeHashTable(table);
    *table = newTable;
}

/*
@brief Programın ana fonksiyonu. Kullanıcıdan giriş alır ve hash tablosu işlemlerini yönetir.
*/
int main(int argc, char *argv[]) {
    int n, i;
    float loadFactor;
    char mode[10];
    char action = '\0', userName[MAX_NAME_LENGTH];
    HashTable table;

    printf("Tabloya eklemek istediginiz eleman sayisini girin: ");
    scanf("%d", &n);

    int loadFactorValid = 0;

    while (!loadFactorValid) {
        printf("Load factor degerini girin (pozitif bir sayi olmali): ");
        if (scanf("%f", &loadFactor) == 1 && loadFactor > 0) {
            loadFactorValid = 1; // Geçerli bir load factor girildi
        } else {
            printf("gecersiz load factor. Lutfen gecerli bir load factor degeri girin.\n");
            while (getchar() != '\n'); // Geçersiz girişi temizle
        }
    }

    int tableSize = calculateTableSize(n, loadFactor);
    printf("Tablonuzun boyutu %d olarak hesaplandi.\n", tableSize);

    int modeValid = 0;
    while (!modeValid) {
        printf("Modu girin (NORMAL/DEBUG): ");
        scanf("%s", mode);

        // Kullanıcının girdiği modu küçük harfe çevir
        for ( i = 0; mode[i]; i++) {
            mode[i] = toupper(mode[i]);
        }

        // Mod kontrolü
        if (strcmp(mode, "NORMAL") == 0 || strcmp(mode, "DEBUG") == 0) {
            modeValid = 1;
        } else {
            printf("gecersiz mod. Lutfen 'NORMAL' veya 'DEBUG' girin.\n");
        }
    }

    table = createHashTable(tableSize, loadFactor);

    int shouldExit = 0;

    while (!shouldExit) {
        printf("\nEkleme (e), Silme (s), Arama (a), Goruntule (g), Duzenle (d), Cikis (q): ");
        scanf(" %c", &action);

        switch (action) {
            case 'e':
                printf("Eklemek istediginiz kullanicinin adini girin: ");
                scanf("%s", userName);
                insertEntry(&table, userName, mode, n);  
                break;
            case 's':
                printf("Silmek istediginiz kullanicinin adini girin: ");
                scanf("%s", userName);
                deleteEntry(&table, userName, mode);
                break;
            case 'a':
                printf("Aramak istediginiz kullanicinin adini girin: ");
                scanf("%s", userName);
                searchEntry(&table, userName, mode);
                break;
            case 'g':
                displayHashTable(&table);
                break;
            case 'd':
                if (table.elementCount == 0) {
                    printf("once tabloya eleman ekleyin ve sonra silin.\n");
                } else if (!hasDeletedEntry(&table)) {
                    printf("duzenlemeden önce tablodan en az bir eleman silin.\n");
                } else {
                    reorganizeTable(&table, mode);
                }
                break;
            case 'q':
                shouldExit = 1;
                break;
            default:
                printf("Gecersiz islem. Lutfen gecerli bir komut girin.\n");
        }
    }


    freeHashTable(&table);
    return 0;
}
