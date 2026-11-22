# Ders 23 Genişletilmiş Notu: Laboratuvar 4: Üç Butonla Ampul Yakma (Özyinelemeli Çözüm)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar problemi
- 2. Programdan istenenler
- 3. Derste netleşen varsayımlar
- 4. Çözüm fikri ve örnek bir C programı
- Örnek Sorular
- Dersin Toparlaması

Bu kayıt dersin dördüncü laboratuvar oturumudur ve kısa sürmüştür. Oturumda laboratuvar sorusu ekranda paylaşıldı, problem sözlü olarak anlatıldı ve öğrencilerin soruları cevaplandı; ardından öğrenciler soruyu kendi başlarına çözmeye başladı. Problemin çözümü derste anlatılmadı. Aşağıdaki çözüm bölümü bu yüzden ajan tarafından eklenmiştir ve öyle işaretlenmiştir.

## 1. Laboratuvar problemi

### 1.1 Senaryo

Basit bir sistem düşünülür: bir ampul ve onun çevresinde, her birinin üzerinde bir enerji değeri yazan butonlar vardır. Ekrandaki şekilde ampulün çevresinde 1, 2, 0, 9, 6, 3 ve 5 değerli yedi buton görülür (ekrandan, 00:05:00). Belgedeki problem metni şöyledir (ekrandan, 00:10:00):

Bir ampulün çalışması için farklı değerde enerjiler sağlayan butonlar kullanılmalıdır. Ampulün çalışması için 3 butona basılmalıdır ve buton değerlerinin tam olarak gerekli enerjiyi sağlaması gerekmektedir; eksik veya fazla olmamalıdır. Butonlara aynı anda basıldığı varsayılmaktadır, sırası önemli değildir. Girilen buton değerleri ile gerekli enerji sağlanırsa program "Ampul Yanar" çıktısı, sağlanamazsa "Ampul Yanmaz" çıktısı vermelidir.

<!-- BELİRSİZ: Belgenin devamındaki "aşağıdaki kurallar" listesi (2. sayfa) karelerde görünmüyor; kurallar yalnız sözlü anlatımdan aktarıldı. -->

Ampul yalnız üç butona basılınca çalışır: ne iki ne dört, daha az ya da daha fazla değil, tam olarak üç buton. Butonlara aynı anda basıldığı için hangi butona önce basıldığının önemi yoktur. Yani aranan şey, butonlardan seçilen ve toplamı gerekli enerjiye eşit olan üç elemanlı gruplardır.

### 1.2 Ekrandaki örnekler

Belgede aynı buton kümesiyle üç örnek verilir (ekrandan, 00:05:00):

| Butonlar | Gerekli enerji | Bulunan üçlü gruplar | Çıktı |
|---|---|---|---|
| {3, 5, 1, 2, 0, 9, 6} | 8 | {1, 5, 2}, {5, 3, 0}, {6, 2, 0} | AMPUL YANAR |
| {3, 5, 1, 2, 0, 9, 6} | 20 | {5, 6, 9} | AMPUL YANAR |
| {3, 5, 1, 2, 0, 9, 6} | 50 | yok | AMPUL YANMAZ |

İlk örnekte gerekli enerji 8'dir. $1+5+2=8$, $5+3+0=8$ ve $6+2+0=8$ olduğundan üç farklı grup bulunur. En az bir grup bulunduğu için ampul en az bir kez yanabilir demektir ve çıktı "Ampul Yanar" olur.

İkinci örnekte gerekli enerji 20'dir. Toplamı 20 olan tek üçlü grup $5+6+9=20$'dir. Bir grup da yeterli olduğu için çıktı yine "Ampul Yanar"dır.

Üçüncü örnekte gerekli enerji 50'dir. Hiçbir üçlü grup 50'yi sağlamaz; en büyük üç değerin toplamı bile $9+6+5=20$'dir (ara adım eklendi). Bu yüzden çıktı "Ampul Yanmaz"dır.

Bu tablodaki gruplar python ile yedi butonun bütün üçlü kombinasyonları ($\binom{7}{3}=35$ grup) denenerek doğrulandı; ekrandaki listeler eksiksizdir.

## 2. Programdan istenenler

### 2.1 Girdi ve çıktı

Program önce kullanıcıdan kaç buton olduğunu alır, sonra o kadar buton değerini okur. Ardından ampulün çalışması için gereken enerjiyi kullanıcıdan alır. Örnekteki yedi buton yalnız bir örnektir; kullanıcı beş buton olacak derse beş değer okunur.

Program, bu girdilerle gerekli enerjiyi sağlayan en az bir üçlü grup bulabiliyorsa ekrana "Ampul Yanar", bulamıyorsa "Ampul Yanmaz" yazar. Belgedeki örneklerde grupların listesi gösterilse de bulunan grupları ekrana yazdırmak istenmez. Grupları bir yerde tutup tutmamak öğrenciye kalmıştır; ama yazdırılmayacaktır. Kaç grup olduğu da önemli değildir.

### 2.2 Özyineleme zorunluluğu

Problemin asıl amacı, öğrencilerin özyinelemeli (recursive) bir fonksiyon yazıp yazamadığını görmektir. Bu yüzden program, yani grubu arayan fonksiyon, özyinelemeli yazılmalıdır.

> **Hocanın vurgusu:** Önemli olan programın, yani fonksiyonun recursive oluşturulmasıdır. Çıktı olarak yalnız "Ampul Yanar" ya da "Ampul Yanmaz" verilmesi yeterlidir.

Süre bu soru için bol olduğundan çözümün yapılabilecek en iyi biçimde yazılması istendi.

## 3. Derste netleşen varsayımlar

Öğrencilerin sorularıyla şu varsayımlar netleşti:

- **Tam olarak üç buton.** İki ya da dört butonlu grupların kontrol edilmesi gerekmez; yalnız üçlü gruplar aranır.
- **Tam olarak gerekli enerji.** Grubun toplamı gerekli enerjiye eşit olmalıdır. Gerekli enerji 8 iken toplamı 10 olan bir grup bulunursa "10 enerji elde ettim, 8 her türlü çalışır" diye düşünülmez.
- **Buton değerleri tamsayıdır.** Değerler `double` değil, tamsayıdır.
- **Aynı değer tekrar edebilir, 0 girilebilir.** Buton değerlerinin birbirinden farklı olması gerekmez; kullanıcı aynı değeri birden çok kez ya da 0 girebilir. Farklı senaryolar denenebilir.
- **Değerler pozitif girilir.** Değerlerin pozitif girilmesi yeterlidir. Negatif değer olsa da yapılacak işlem değişmez.
- **Sıra ve grup sayısı önemsizdir.** Butonların sırası da kaç grup bulunduğu da önemli değildir; bir grup bulmak yeterlidir.
- **Dizi için en büyük boyut kabul edilebilir.** Butonları dizide tutmak için bir en büyük buton sayısı (örneğin 10-15) kabul edilebilir. Bu zorunludur, çünkü değişken boyutlu yer ayırma henüz kullanılmıyor.
- **Global değişken kullanılmaz.** Dizi ve diğer değerler fonksiyona parametre olarak verilmeli, global değişkenden kaçınılmalıdır.

> **Ders sonrası not:** En büyük buton sayısı sorusunu cevaplarken "Dinamik programlama sanırım hâlâ görmediniz" denildi. Bağlamda kastedilen büyük olasılıkla dizinin boyutunu çalışma anında belirleyen dinamik bellek ayırmadır (`malloc` gibi); dinamik programlama ayrı bir algoritma tasarım yöntemidir.

## 4. Çözüm fikri ve örnek bir C programı

Bu bölüm derste anlatılmadı. Çözüm ajan tarafından, problem metni ve derste netleşen varsayımlar izlenerek yazıldı.

### 4.1 Al ya da alma

Butonlardan üç tanesini seçmenin doğal özyinelemeli tanımı şudur: sıradaki butona bakılır ve iki yol denenir.

- Butonu gruba almak: seçilecek buton sayısı bir azalır, sağlanması gereken enerji bu butonun değeri kadar düşer, sıradaki butona geçilir.
- Butonu almamak: seçilecek buton sayısı ve kalan enerji aynı kalır, sıradaki butona geçilir.

İki yoldan biri başarılı olursa grup vardır. Butonlar dizide hep ileri doğru tarandığı için aynı üç buton farklı sıralarda iki kez sayılmaz; bu da "sıra önemli değil" kuralına uyar.

Temel durumlar şunlardır:

- Seçilecek buton sayısı 0 olmuşsa üç buton seçilmiştir. Kalan enerji tam olarak 0 ise toplam gerekli enerjiye eşittir ve grup bulunmuştur; değilse bu yol başarısızdır. Böylece "eksik ya da fazla olmamalı" kuralı da kendiliğinden sağlanır.
- Geriye seçilmesi gereken sayıdan az buton kalmışsa bu yoldan grup çıkamaz.

Fonksiyon bu sayede yalnız tam üç elemanlı grupları dener. Değerlerin pozitif ya da negatif olması bu mantığı değiştirmez; bu, derste söylenen "negatif değer işlemi etkilemez" cevabıyla uyumludur.

### 4.2 Ekrandaki ilk örnekte arama

Butonlar {3, 5, 1, 2, 0, 9, 6} ve gerekli enerji 8 iken fonksiyon önce 3'ü alır (kalan enerji 5, seçilecek 2), sonra 5'i alır (kalan enerji 0, seçilecek 1). Üçüncü buton olarak 1 alınırsa kalan enerji $-1$, 2 alınırsa $-2$ olur; ikisi de başarısızdır. 0 alındığında kalan enerji 0 ve seçilecek buton sayısı 0 olur, yani {3, 5, 0} grubu bulunur ve fonksiyon 1 döndürür. `||` işlecinin kısa devre davranışı nedeniyle bir grup bulunduktan sonra kalan dallar denenmez.

### 4.3 Program

Aşağıdaki program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki girdilerle denendi: butonlar 3, 5, 1, 2, 0, 9, 6 iken gerekli enerji 8 ve 20 için "Ampul Yanar", 50 için "Ampul Yanmaz" çıktısı verdi. Dersin genel kurallarına uygun olarak `break`, `continue`, `goto` ve global değişken içermez. Dizi boyutu `MAX` (50) ile sınırlıdır.

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

Fonksiyon, seçilecek buton sayısını (`k`) parametre olarak aldığı için yalnız 3 ile çağrılması yeterlidir. Buton sayısı 3'ten azsa ikinci temel durum hemen 0 döndürür ve çıktı "Ampul Yanmaz" olur.

> **Ek bilgi (derste anlatılmadı):** Bu "al ya da alma" yapısı, bir kümenin belirli büyüklükteki alt kümelerini özyinelemeyle gezmenin genel kalıbıdır. En kötü durumda $n$ butondan seçilebilecek bütün üçlüler, yani $\binom{n}{3}$ grup denenir. Aynı problem iç içe üç `for` döngüsüyle de çözülebilir; ama bu laboratuvarda özyinelemeli çözüm istendiği için döngülü çözüm beklenen cevap değildir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00 ve 00:10:00): Bir ampulün çalışması için 3 butona basılmalıdır ve buton değerlerinin toplamı tam olarak gerekli enerjiyi sağlamalıdır; eksik veya fazla olmamalıdır. Butonlara aynı anda basıldığı varsayılır, sırası önemli değildir. Buton sayısı, buton değerleri ve gerekli enerji kullanıcıdan alınır. Gerekli enerji sağlanabiliyorsa "Ampul Yanar", sağlanamıyorsa "Ampul Yanmaz" çıktısını veren programı C dilinde, özyinelemeli olarak yazın. Örnek: butonlar {3, 5, 1, 2, 0, 9, 6} iken gerekli enerji 8 için gruplar {1, 5, 2}, {5, 3, 0}, {6, 2, 0} ve çıktı AMPUL YANAR; 20 için grup {5, 6, 9} ve çıktı AMPUL YANAR; 50 için grup yok ve çıktı AMPUL YANMAZ.

> **Çözüm (derste verilmedi):** Özyinelemeli fonksiyon sıradaki butonu ya gruba alır (seçilecek buton sayısı 1 azalır, kalan enerji buton değeri kadar düşer) ya da almaz. Üç buton seçildiğinde kalan enerji 0 ise grup bulunmuştur; seçilecek kadar buton kalmamışsa o yol başarısızdır. Bölüm 4.3'teki program `gcc -Wall` ile derlendi ve ekrandaki üç örnekte beklenen çıktıları verdi.

**Soru 2** (derste sözlü, 00:07:15): Buton değerlerinin birbirinden farklı olması gerekiyor mu?

> **Cevap (derste verildi):** Hayır. Değerleri kullanıcı girer; aynı değer de, 0 da girilebilir. Farklı senaryolar denenebilir.

**Soru 3** (derste sözlü, 00:07:39): Kaç buton olacağı sabit mi?

> **Cevap (derste verildi):** Hayır. Buton sayısı ve değerleri kullanıcıdan alınır; örnekteki yedi buton yalnız bir örnektir. Kullanıcı beş buton derse beş değer okunur.

**Soru 4** (derste sözlü, 00:07:56): Buton değerleri tamsayı mı, `double` mı?

> **Cevap (derste verildi):** Bütün değerler tamsayıdır.

**Soru 5** (derste sözlü, 00:08:08): İki buton ya da dört buton olma durumlarını da kontrol edecek miyiz?

> **Cevap (derste verildi):** Hayır, yalnız üç buton. Toplam da tam olarak gerekli enerji olmalı; gerekli enerji 8 iken 10 enerji veren bir grup ampulü yakmaz.

**Soru 6** (derste sözlü, 00:08:34): Butonları dizide tutmak için bir en büyük buton sayısı (örneğin 10-15) kabul edebilir miyiz?

> **Cevap (derste verildi):** Evet, bunu yapmak zorundasınız; bir en büyük değer kabul edilebilir. Ama global değişkenden kaçınılmalıdır.

**Soru 7** (derste sözlü, 00:09:50): Buton değerleri pozitif mi?

> **Cevap (derste verildi):** Evet, pozitif değer girmek yeterlidir. Negatif değer olsa da yapılacak işlem aynıdır.

**Soru 8** (derste sözlü, 00:13:58): Bulunan grupları ekrana yazdıracak mıyız?

> **Cevap (derste verildi):** Hayır, yazdırılmayacak. Grupları tutup tutmamak size kalmış; bir grup bulmak yeterlidir. Önemli olan özyinelemeli bir fonksiyon yazabilmektir.

## Dersin Toparlaması

Bu laboratuvar oturumunun konusu özyinelemeydi. Problem, kullanıcıdan alınan tamsayı buton değerleri arasından toplamı tam olarak gerekli enerjiye eşit olan üç elemanlı bir grup bulunup bulunamayacağını sormaktaydı. Butonlara aynı anda basıldığı için sıra önemsizdir; aranan şey bir kombinasyondur. Program yalnız "Ampul Yanar" ya da "Ampul Yanmaz" yazmalı, grupları listelememeli ve grubu arayan fonksiyon özyinelemeli olmalıydı.

Derste yalnız üçlü grupların arandığı, toplamın gerekli enerjiye tam eşit olması gerektiği, değerlerin tamsayı olduğu, aynı değerin ve 0'ın girilebileceği, dizi için bir en büyük boyut kabul edilebileceği ve global değişkenden kaçınılması gerektiği netleşti. Problemin doğal özyinelemeli çözümü, her butonu "al ya da alma" diye iki dala ayırıp üç buton seçildiğinde kalan enerjinin 0 olup olmadığına bakmaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
