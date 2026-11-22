# Ders 9 Çalışma Özeti

## Genel Konular

- Laboratuvar problemi: ardışık sayılardan oluşan dizide kayıp sayıyı bulmak
  - Problem metni: ardışık sayılardan oluşan bir dizide ardışıklığı bozan kayıp sayıyı bulan algoritmanın kodlanması (ekrandan, 00:10:00).
  - Girdi: sıralı sayılardan oluşan dizinin boyutu ve dizi elemanları. Boyut da elemanlar da kullanıcıdan okunur; programın içinde sabit dizi verilmez.
  - Çıktı: kayıp sayı varsa sayının kendisi, yoksa kayıp sayı olmadığı ekrana yazılır.
  - Ekrandaki örnekler (ekrandan, 00:10:00):
    - Girdi 2 3 4 5 7 8 9 10, çıktı 6.
    - Girdi -8 -7 -6 -5 -3 -2 -1 0, çıktı -4 (negatif sayılarla da çalışmalı).
    - Girdi 10 11 12, çıktı "No missing value" (dizi boyu kullanıcıya bağlıdır, kayıp olmayabilir).
- Problemin varsayımları (derste sorulan sorulara verilen cevaplardan)
  - Dizi artan sıradadır; azalan sıralı dizi düşünülmez.
  - Ardışıklık birer birerdir (1, 2, 3, ...); 1, 3, 5, 7 gibi farklı adımlı diziler kapsam dışıdır.
  - En çok bir kayıp sayı vardır: ya tam bir kayıp sayı vardır ya da hiç yoktur.
- Verimlilik beklentisi
  - Kullanıcı 10, 100 ya da 1000 eleman girebilir. Program büyük boyutlu diziler düşünülerek verimli tasarlanmalıdır.
  - İpucu: ardışık sayılar sıralı olduğu için sıralı bir dizide aramayı kolaylaştıracak yöntemler kullanılmalıdır (ekrandan, 00:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yalnız sonuca ulaşmak yeterli değil
  - Elemanlara tek tek bakan bir çözüm istenmiyor; problemin nasıl çözüldüğü, yani çözümün verimli olup olmadığı değerlendiriliyor. İpucuna bağlı kalan çözüm tam karşılığı alır.
- Kod yazım kısıtları
  - `break`, `continue`, `goto` gibi komutlardan kaçınılmalı, global değişken kullanılmamalıdır.
- Kayıpsız durum kontrol edilmeli
  - Dizide kayıp eleman olmayabilir (üçüncü örnekteki gibi); program bunu ayrıca kontrol etmelidir.

## Kısa Tekrar Notları

- Girdi: boyut $n$ ve artan sıralı, birer birer ardışık $n$ eleman; en çok bir sayı eksik.
- Kayıp yoksa son eleman ile ilk elemanın farkı $n-1$'dir.
- Kayıp yoksa her konumda $a[i] - a[0] = i$ olur; kayıptan sonraki konumlarda bu fark $i+1$'e çıkar.
- Bu özellik sıralı olduğu için ikili aramayla (her adımda aralığı yarıya indirerek) yaklaşık $\log_2 n$ adımda bulunabilir; tek tek bakmak $n$ adım sürer.
- Negatif sayılarda da aynı mantık geçerlidir.

## Detaylı Açıklamalar

- Bu kayıt dersin ilk laboratuvar oturumudur. Problem ekranda paylaşılan laboratuvar belgesinden alınmıştır ve öğrencilerden kendi başlarına çözmeleri istenmiştir; çözüm derste anlatılmamıştır.
- Problemin özü şudur: elemanlar birer birer arttığı için, kayıp olmayan bir dizide $i$. konumdaki eleman $a[0] + i$ olmalıdır. Kayıp sayı bir konumdan sonra bütün elemanları bir kaydırır. Bu yüzden "$a[i] - a[0] = i$ mi?" sorusunun cevabı dizinin başında "evet", kayıptan sonra "hayır" olur. Bu iki bölgeli yapı, sıralı dizide aramayı hızlandıran yöntemlerle (ipucunda kastedilen) sınır noktasının hızlıca bulunmasını sağlar.
- Kayıp olup olmadığı tek karşılaştırmayla anlaşılır: $a[n-1] - a[0] = n - 1$ ise kayıp yoktur. Örneğin 10 11 12 için $12 - 10 = 2 = 3 - 1$ olduğundan çıktı "No missing value" olur; 2 3 4 5 7 8 9 10 için $10 - 2 = 8 \neq 7$ olduğundan bir sayı eksiktir.
- Aşağıdaki çözüm derste yazılmadı; ajan tarafından ikili aramayla yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki üç girdiyle denendi (çıktılar 6, -4 ve "No missing value"). Derste istenen kısıtlara uygun olarak `break`, `continue`, `goto` ve global değişken içermez.

```c
#include <stdio.h>

int main(void) {
    int n, i, sol, sag, orta, kayip;
    int a[1000];

    printf("Dizinin boyutu: ");
    scanf("%d", &n);
    printf("Elemanlar (artan sirada): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (a[n - 1] - a[0] == n - 1) {
        printf("No missing value\n");
    } else {
        /* a[i] - a[0] == i olan son konumu ikili aramayla bul */
        sol = 0;
        sag = n - 1;
        while (sag - sol > 1) {
            orta = (sol + sag) / 2;
            if (a[orta] - a[0] == orta)
                sol = orta;
            else
                sag = orta;
        }
        kayip = a[sol] + 1;
        printf("%d\n", kayip);
    }
    return 0;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
