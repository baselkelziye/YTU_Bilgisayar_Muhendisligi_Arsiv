# Ders 23 Çalışma Özeti

## Genel Konular

- Laboratuvar problemi: üç butonla ampul yakma
  - Problem metni (ekrandan, 00:10:00): bir ampulün çalışması için farklı değerde enerjiler sağlayan butonlar kullanılır. Ampulün çalışması için 3 butona basılmalıdır ve buton değerlerinin toplamı tam olarak gerekli enerjiyi sağlamalıdır; eksik ya da fazla olmamalıdır.
  - Butonlara aynı anda basıldığı varsayılır, butonların sırası önemli değildir.
  - Girilen buton değerleriyle gerekli enerji sağlanabiliyorsa program "Ampul Yanar", sağlanamıyorsa "Ampul Yanmaz" çıktısı verir.
- Ekrandaki örnekler (ekrandan, 00:05:00)
  - Butonlar = {3, 5, 1, 2, 0, 9, 6}, gerekli enerji 8: üçlü gruplar {1, 5, 2}, {5, 3, 0}, {6, 2, 0}; çıktı AMPUL YANAR.
  - Aynı butonlar, gerekli enerji 20: tek üçlü grup {5, 6, 9}; çıktı AMPUL YANAR.
  - Aynı butonlar, gerekli enerji 50: hiçbir üçlü grubun toplamı 50 değildir; çıktı AMPUL YANMAZ.
- Programdan istenenler
  - Buton sayısı, buton değerleri ve gerekli enerji kullanıcıdan alınır. Örnekteki yedi buton yalnız bir örnektir.
  - Program özyinelemeli (recursive) yazılmalıdır. Laboratuvarın amacı özyinelemeli bir fonksiyon yazılıp yazılamadığını görmektir.
  - Bulunan grupların listelenmesi gerekmez; yalnız "Ampul Yanar" ya da "Ampul Yanmaz" yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tam olarak üç buton
  - Ampul yalnız üç butonla çalışır; iki ya da dört butonlu gruplar kontrol edilmez.
- Tam olarak gerekli enerji
  - Toplam, gerekli enerjiye eşit olmalıdır. Örneğin gerekli enerji 8 iken toplamı 10 olan bir grup ampulü yakmaz.
- Bir grup yeterli
  - En az bir üçlü grup bulunduğunda ampul yanar. Kaç grup olduğu ya da grupların içeriği yazdırılmaz.
- Özyineleme zorunlu
  - Çözüm özyinelemeli bir fonksiyonla yazılmalıdır.
- Global değişken kullanılmaz
  - Butonları tutmak için bir dizi gerekir ve dizi için bir en büyük buton sayısı kabul edilebilir; ama global değişkenden kaçınılmalıdır.

## Kısa Tekrar Notları

- Girdi: buton sayısı $n$, $n$ tane tamsayı buton değeri, gerekli enerji $E$.
- Soru: dizide toplamı tam olarak $E$ olan üç elemanlı bir grup var mı?
- Butonların sırası önemsizdir; aynı üç buton farklı sırada yeni grup sayılmaz.
- Buton değerleri tamsayıdır; aynı değer birden çok kez, 0 da girilebilir.
- Değerlerin pozitif girilmesi yeterlidir; negatif değer olsa da yapılacak işlem değişmez.
- Çıktı yalnız "Ampul Yanar" ya da "Ampul Yanmaz".
- Fonksiyon özyinelemeli olmalı, global değişken kullanılmamalı.

## Detaylı Açıklamalar

- Problemin özü
  - Problem, verilen tamsayı dizisinden tam üç eleman seçip toplamlarının hedef değere eşit olup olamayacağını sormaktadır. Butonlar aynı anda basıldığı için seçimde sıra yoktur; bu bir kombinasyon (alt küme) seçimidir.
  - Ekrandaki ilk örnekte $1+5+2=8$, $5+3+0=8$ ve $6+2+0=8$ olduğundan üç grup vardır. İkinci örnekte $5+6+9=20$ tek gruptur. Üçüncü örnekte en büyük üç değerin toplamı bile $9+6+5=20$ olduğu için 50'ye ulaşılamaz. Bu gruplar python ile bütün üçlü kombinasyonlar denenerek doğrulandı; ekrandaki listeler eksiksizdir.
- Derste netleşen varsayımlar
  - Buton sayısı ve değerleri kullanıcıdan alınır; kullanıcı beş buton derse beş değer okunur.
  - Değerler tamsayıdır (double değil). Aynı değer birden çok kez girilebilir, 0 girilebilir.
  - Butonları dizide tutmak için bir en büyük buton sayısı (örneğin 10-15) kabul edilebilir. Dinamik bellek kullanılması beklenmez.
- Çözüm fikri (derste anlatılmadı, ajan tarafından eklendi)
  - Özyinelemeli fonksiyon her adımda sıradaki butonu ele alır ve iki yolu dener: butonu gruba almak (kalan buton sayısı bir azalır, kalan enerji buton değeri kadar düşer) ya da almamak.
  - Temel durumlar: kalan buton sayısı 0 olmuşsa kalan enerji 0 ise grup bulunmuştur; geriye seçilecek kadar buton kalmamışsa bu yol başarısızdır.
  - Aşağıdaki program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki üç örnekle denendi (8 ve 20 için "Ampul Yanar", 50 için "Ampul Yanmaz"). `break`, `continue`, `goto` ve global değişken içermez.

```c
#include <stdio.h>
#define MAX 50

/* butonlar[i..n-1] arasindan tam k buton secilerek
   toplam enerji tam olarak 'enerji' yapilabiliyor mu? */
int grupVarMi(int butonlar[], int n, int i, int k, int enerji) {
    if (k == 0) {
        return enerji == 0;
    }
    if (n - i < k) {
        return 0;
    }
    /* i. butonu gruba al ya da alma */
    return grupVarMi(butonlar, n, i + 1, k - 1, enerji - butonlar[i])
        || grupVarMi(butonlar, n, i + 1, k, enerji);
}

int main() {
    int butonlar[MAX];
    int n, i, enerji;

    do {
        printf("Buton sayisi (en fazla %d): ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (i = 0; i < n; i++) {
        printf("%d. buton degeri: ", i + 1);
        scanf("%d", &butonlar[i]);
    }

    printf("Gerekli enerji: ");
    scanf("%d", &enerji);

    if (grupVarMi(butonlar, n, 0, 3, enerji)) {
        printf("Ampul Yanar\n");
    } else {
        printf("Ampul Yanmaz\n");
    }
    return 0;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
