# Ders 17 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Bu kayıt yaklaşık yedi dakikalık bir sınav başlangıcıdır. Konu anlatımı yapılmadı. Hoca struct konusunu içeren tek bir programlama sorusunu ekranda gösterip okudu, soru maddelerini açıkladı ve öğrencilerin sorularını cevapladı. Sınavdan sonra çözüm yapılmadı.
- Soru: Oda bilgilerini dinamik struct dizisinde tutmak (ekrandan, 00:05:00)
  - Bir odanın id, yükseklik, genişlik ve uzunluk bilgisi bir struct yapısında tutulur. Oda sayısı $N$ `main` içinde kullanıcıdan alınır ve bu sayıya göre dinamik bir oda struct dizisi oluşturulur.
  - İstenen fonksiyonlar: `GetInfo` (verileri kullanıcıdan okuyup diziye yazar), `ScanRooms` (sağ ve sol komşusundan hacimce büyük odaları yazar), `sortbyVolume` (odaları hacme göre sıralar), `printInfo` (her odanın id, yükseklik, genişlik, uzunluk ve hacmini yazar).
  - Fonksiyonların dönüş türleri boş bırakılmıştır (`__________ GetInfo(...)` gibi). Parametreleri ve dönüş türlerini öğrencinin doğru çıkarması istenir.
  - Hacim formülü: $\text{Hacim} = \text{genişlik} \times \text{yükseklik} \times \text{uzunluk}$ (ekrandan, 00:05:00).
  - `main` içindeki çağrı sırası: `GetInfo`, `ScanRooms`, `printInfo`, `sortbyVolume`, yeniden `printInfo`. Ardından dinamik olarak ayrılan bellek serbest bırakılır.
- Kodlama kısıtları (ekrandan, 00:05:00)
  - Global ve statik değişken kullanılmaz; ana programda ilave (gereksiz) değişken tanımlanmaz.
  - Döngü içinde `break`, `continue` ve `goto` kullanılmaz.
  - Kod C olarak yazılır, C++ kodu kabul edilmez; Dev-C++ ya da Code::Blocks üzerinde derlenip çalışmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `ScanRooms` için komşu karşılaştırması
  - Bir oda, hem solundaki hem sağındaki odadan hacimce büyükse yazdırılır. Örneğin ikinci odanın hacmi hem birinciden hem üçüncüden büyükse ikinci oda yazılır.
  - İlk odanın solunda, son odanın sağında komşu olmadığı için bu iki oda değerlendirmeye alınmaz ve ekrana yazılmaz.
- "Odanın ismi" ile "odanın bilgileri" farkı
  - `ScanRooms` odaların isimlerini yazar; burada isimden kasıt odanın id'sidir ("3 numaralı oda" gibi). Bütün bilgiler (id, yükseklik, genişlik, uzunluk, hacim) yalnız `printInfo` içinde yazılır.
- Sıralama orijinal diziyi değiştirir
  - `sortbyVolume` yeni bir dizi üretmez; gönderilen dizinin içeriği yer değiştirir.
- `for` içinde değişken tanımlamamak
  - Döngü değişkeni `for (int i = 0; ...)` biçiminde döngünün içinde tanımlanmamalı, döngüden önce ayrı bir satırda tanımlanmalıdır. Bazı derleyicilerde derlenen bu yazım, değerlendirmede kullanılan ortamda derlenmezse kod çalışmamış sayılır.

## Kısa Tekrar Notları

- Struct alanları: id, yükseklik, genişlik, uzunluk.
- Dinamik dizi: $N$ kullanıcıdan alınır, dizi `malloc`/`calloc` ile açılır, iş bitince `free` ile bırakılır.
- Diziyi değiştiren fonksiyonlar diziyi (adresini) parametre olarak alır; sıralama yerinde yapılır.
- Komşu taraması ikinci elemandan sondan bir önceki elemana kadar yapılır.
- Hacim = genişlik × yükseklik × uzunluk.
- Döngü sayacı döngüden önce tanımlanır; global değişken, `break`, `continue`, `goto` yok.

## Detaylı Açıklamalar

- Sorunun bütün parçaları, önceki derslerde işlenen dinamik bellek ve struct dizisi konularının birleşimidir. Struct, odaya ait dört bilgiyi tek bir tür altında toplar. Oda sayısı derleme zamanında bilinmediği için dizi çalışma zamanında, kullanıcının girdiği $N$ değerine göre heap'te açılır. Dizinin başlangıç adresi ve eleman sayısı fonksiyonlara gönderilir; böylece fonksiyonların hepsi aynı bellek bölgesinde çalışır ve `main` içinde ek değişken gerekmez.
- `ScanRooms` taramasında her iç oda iki komşusuyla karşılaştırılır. İlk ve son odanın bir komşusu eksik olduğu için döngü sınırları buna göre seçilir; böylece dizinin dışına taşan bir erişim de oluşmaz.
- `sortbyVolume` herhangi bir sıralama algoritmasıyla yazılabilir. Önemli olan, karşılaştırmanın struct alanlarından hesaplanan hacimle yapılması ve takasın bütün struct'ı kapsamasıdır. Hoca sıralamanın yönünü (artan ya da azalan) söylemedi.
  <!-- BELİRSİZ: Sıralamanın artan mı azalan mı olacağı ne ekranda ne altyazıda belirtiliyor. -->
- Derste sorunun çözümü verilmedi. Aşağıdaki çözüm ajan tarafından yazıldı, `gcc -Wall -std=c89 -pedantic` ile uyarısız derlendi ve beş odalık bir girdiyle denendi. Sıralama artan yönde seçildi.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct room {
    int id;
    float height, width, length;
} ROOM;

float volume(ROOM r) {
    return r.width * r.height * r.length;
}

void GetInfo(ROOM *rooms, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d. oda (id yukseklik genislik uzunluk): ", i + 1);
        scanf("%d %f %f %f", &rooms[i].id, &rooms[i].height,
              &rooms[i].width, &rooms[i].length);
    }
}

void ScanRooms(ROOM *rooms, int n) {
    int i;
    for (i = 1; i < n - 1; i++) {
        if (volume(rooms[i]) > volume(rooms[i - 1]) &&
            volume(rooms[i]) > volume(rooms[i + 1])) {
            printf("Komsularindan buyuk oda: %d\n", rooms[i].id);
        }
    }
}

void sortbyVolume(ROOM *rooms, int n) {
    int i, j;
    ROOM tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (volume(rooms[j]) > volume(rooms[j + 1])) {
                tmp = rooms[j];
                rooms[j] = rooms[j + 1];
                rooms[j + 1] = tmp;
            }
        }
    }
}

void printInfo(ROOM *rooms, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("id=%d yukseklik=%.2f genislik=%.2f uzunluk=%.2f hacim=%.2f\n",
               rooms[i].id, rooms[i].height, rooms[i].width,
               rooms[i].length, volume(rooms[i]));
    }
}

int main() {
    int n;
    ROOM *rooms;
    printf("Oda sayisi: ");
    scanf("%d", &n);
    rooms = (ROOM *)calloc(n, sizeof(ROOM));
    if (rooms == NULL) {
        printf("Bellek ayrilamadi\n");
        return 1;
    }
    GetInfo(rooms, n);
    ScanRooms(rooms, n);
    printInfo(rooms, n);
    sortbyVolume(rooms, n);
    printInfo(rooms, n);
    free(rooms);
    return 0;
}
```

- Deneme girdisi olarak id'leri 1-5, hacimleri sırasıyla 24, 27, 1, 20, 4 olan beş oda verildiğinde `ScanRooms` 2 ve 4 numaralı odaları yazar; sıralamadan sonra id sırası 3, 5, 4, 1, 2 olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
