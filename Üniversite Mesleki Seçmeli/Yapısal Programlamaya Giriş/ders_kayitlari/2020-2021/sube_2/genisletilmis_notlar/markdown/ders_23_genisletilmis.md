# Ders 23 Genişletilmiş Notu: Laboratuvar 4: Ampul ve Butonlar (Özyinelemeli Üçlü Toplam)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın Bağlamı
- 2. Problem: Ampul ve Butonlar
- 3. Özyineleme Şartı
- 4. Sorularla Netleşen Noktalar
- 5. Sayısal Örnek
- 6. Çözüm Yaklaşımı

## 1. Laboratuvarın Bağlamı

Bu kayıt dönemin son laboratuvarıdır. Bugün konu anlatılmadı. Dr. Ahmet Elbir kaydın başında sorunun özyineleme (recursion) ile ilgili olduğunu söyledi. Çözümünün ayrıca yapılabileceğini de ekledi. Laboratuvardan sonra öğrenciler yorgun olacağı için derse devam etmedi. Sıradaki konuları Cuma günü rahat kafayla sürdüreceklerini söyledi.

> **Hocanın vurgusu:** Bundan sonra anlatılacak konular gelecek dönem çok işe yarayacak.

> **Hocanın vurgusu:** İyi durumda olduğunuzu düşünseniz bile soruyu görün ve çözmeye çalışın. Bu size çok şey katacaktır.

Soruyu laboratuvarı yürüten Mustafa Hoca anlattı.

<!-- BELİRSİZ: Soru ekranda gösterildi ve sohbete yazıldı. Soru metninin kendisi altyazıda yok; aşağıdaki tanım sözlü anlatımdan kuruldu. -->

## 2. Problem: Ampul ve Butonlar

### 2.1 Senaryo

Bir ampulümüz var ve yanması için belirli bir enerji gerekiyor. Sağlanan enerji bu değerin altında da üstünde de olursa ampul yanmıyor. Enerji, ampulün etrafındaki düğmelerden üçüne basılarak sağlanıyor. Her butonun verdiği enerji farklı bir değer olabilir ve bu değerler kullanıcıdan bir dizi olarak alınıyor.

Program bu diziden 3 buton seçmeye çalışır. Seçilen üç butonun toplamı ampulün yanması için gereken enerjiye tam olarak eşit olmalıdır. Hoca seçim için iki noktayı özellikle belirtti:

- Değerler dizide sıralı olmak zorunda değildir, karışık olabilir.
- Seçilen üç buton ardı ardına olmak zorunda değildir. Dizinin herhangi bir yerinden alınabilir.

Buton sayısı girdiye göre değişir, seçilecek buton sayısı ise hep 3'tür.

### 2.2 Programın Akışı

Kullanıcıdan üç şey alınır: buton sayısı, butonların değerleri ve gerekli enerji. Programın adımları şöyledir:

1. Kullanıcıdan kaç buton olduğunu al.
2. Bu butonların değerlerini kullanıcıdan diziye al.
3. Ampulün yanması için gerekli enerjiyi kullanıcıdan al.
4. Dizide toplamı gerekli enerjiye eşit olan 3 sayı olup olmadığını özyinelemeli olarak ara.
5. Böyle bir üçlü varsa "Ampul yanar", yoksa "Ampul yanmaz" yazdır.

Bir tane üçlü bulmak yeterlidir, çünkü sonuçta yalnız ampulün yanıp yanmadığı isteniyor.

## 3. Özyineleme Şartı

Hoca aranan üç sayının özyinelemeli (recursive) olarak bulunması gerektiğini anlatırken "lineer bir çözüm istemiyoruz" dedi ve bu şartı sonradan tekrar hatırlattı.

> **Hocanın vurgusu:** Bu soruda önemli olan kısım çözümün özyinelemeli olmasıdır. Soru çok zor değildir, benzeri uygulamada çözülmüştür.

> **Ders sonrası not:** Buradaki "lineer" büyük olasılıkla zaman karmaşıklığı anlamında değil, özyinelemesiz, döngüyle yazılan çözüm anlamında söylendi. Altyazıda hoca bunu ayrıca açıklamıyor.

## 4. Sorularla Netleşen Noktalar

Hoca soruyu anlattıktan sonra öğrenciler soruyu netleştirmek için sorular sordu. Bazı soruların kendisi kayıtta duyulmuyor, yalnız cevapları var. Bu soruları cevaptan anlaşıldığı kadarıyla yazdık.

**Soru:** Bulunan üçlüyü de yazdırmak gerekiyor mu? **Cevap:** Gerekmiyor. Yazdırmanızda bir sakınca yok, ama yalnız "Ampul yanar" veya "Ampul yanmaz" demeniz de yeterli.

**Soru:** Seçilecek buton sayısı değişiyor mu? **Cevap:** Hayır. Hep 3 buton seçilecek. Değişen yalnız kaç buton içinde arandığıdır. Hoca bunu sonraki bir soruda da aynı şekilde tekrar etti.

**Soru:** Seçilen üç butonu biz mi gireceğiz? **Cevap:** Hayır. Kullanıcı butonları, gerekli enerjiyi ve kaç buton olduğunu girer. Siz toplamı gerekli enerjiyi veren üç buton olup olmadığını kontrol edersiniz.

<!-- BELİRSİZ: 00:10:18'de altyazı "seçilen üç butonu siz gireceksiniz" diyor. Aynı cevabın devamı ve 00:11:31'deki "şu kısmını siz bulacaksınız" ifadesi üçlüyü programın bulduğunu gösteriyor, bu yüzden cevap buna göre yazıldı. -->

**Soru:** Bütün kombinasyonları bulmak zorunda mıyız? **Cevap:** Hayır, zorunda değilsiniz.

**Soru:** Butonları kullanıcıya mı girdireceğiz? Yani kullanıcı örneğin birinci, dördüncü ve beşinci butonu mu seçiyor? **Cevap:** Kullanıcıdan alınan şey, ampulün etrafındaki butonların değerleridir. Üçlüyü siz bulacaksınız.

**Soru:** Yani üçlüyü rastgele mi seçeceğiz, `random` fonksiyonuyla mı? **Cevap:** Hayır.

**Soru:** Dizi mutlaka 7 elemanlı mı olacak? **Cevap:** Hayır. Buton sayısı da kullanıcıdan alınır. Kullanıcı 5, 8 ya da 10 buton olduğunu söyleyebilir.

**Soru:** Toplam gerekli enerjiden fazla çıkarsa ne olur? Örneğin toplam 9, gerekli enerji 8 ise? **Cevap:** Ampul yanmaz. Ampul örneği üzerinden "patlıyor" diye düşünebilirsiniz. Toplam 8 olmak zorundadır.

**Soru:** Gerekli enerjiyi siz mi belirliyorsunuz? **Cevap:** Hayır, onu da kullanıcıdan alacaksınız.

Kaydın sonlarına doğru gelen kısa bir soruya hoca "`int` olacak" diye cevap verdi.

<!-- BELİRSİZ: 00:16:45'teki soru kayıtta duyulmuyor. "int olacak" cevabının hangi değerler için söylendiği altyazıdan anlaşılmıyor, büyük olasılıkla buton değerleri ve enerji içindir. -->

## 5. Sayısal Örnek

Hoca ekrandaki örneği şöyle açıkladı.

**Verilen:** Buton değerleri 3, 5, 1, 2, 0, 9, 6. Yani 7 buton var ve bu değerler kullanıcıdan alınıyor. Gerekli enerji 8.

**İstenen:** Bu değerlerin içinde toplamı 8 eden 3 sayı var mı?

**İşlem (ara adım eklendi):** Dizideki sayılardan toplamı 8 eden üçlüler şunlardır:

$$3 + 5 + 0 = 8$$

$$5 + 1 + 2 = 8$$

$$2 + 0 + 6 = 8$$

**Sonuç:** Üçlü vardır, program "Ampul yanar" yazar. Bir üçlü bulmak yeter, üçünü de bulmak gerekmez.

> **Ders sonrası not:** Enerji 20 ve 60 örnekleri altyazıda geçmiyor, kısa nottan alındı ve büyük olasılıkla soru metnindedir. Aynı dizi için enerji 20 ise $9 + 6 + 5 = 20$ olduğundan ampul yanar. Dizinin en büyük üç sayısının toplamı 20 olduğundan enerji 60 ise üçlü bulunamaz ve ampul yanmaz.

## 6. Çözüm Yaklaşımı

Hoca kayıtta çözümü yazmadı.

> **Ek bilgi (derste anlatılmadı):** Aşağıdaki çözüm ders sonrasında hazırlandı ve `gcc -Wall` ile derlenip denendi. Her buton için iki seçenek vardır: seç ya da seçme. Seçilirse kalan sayı 1 azalır ve kalan enerjiden butonun değeri çıkar. Seçilmezse yalnız sıradaki butona geçilir. 3 buton seçildiğinde kalan enerjinin 0 olup olmadığına bakılır.

```c
#include <stdio.h>
#define MAX 100

int ucluVar(int dizi[], int n, int i, int kalanSayi, int kalanEnerji){
    if (kalanSayi == 0) return kalanEnerji == 0;
    if (i == n) return 0;
    if (ucluVar(dizi, n, i + 1, kalanSayi - 1, kalanEnerji - dizi[i])) return 1;
    return ucluVar(dizi, n, i + 1, kalanSayi, kalanEnerji);
}

int main(void){
    int dizi[MAX], n, i, enerji;

    printf("Buton sayisi: ");
    scanf("%d", &n);
    if (n < 0 || n > MAX) return 1;
    for (i = 0; i < n; i++){
        printf("%d. buton: ", i + 1);
        scanf("%d", &dizi[i]);
    }
    printf("Gerekli enerji: ");
    scanf("%d", &enerji);

    if (ucluVar(dizi, n, 0, 3, enerji))
        printf("Ampul yanar\n");
    else
        printf("Ampul yanmaz\n");
    return 0;
}
```

> **Ek bilgi (derste anlatılmadı):** Bölüm 5'teki dizi ve enerji 8 için fonksiyon önce 3'ü, sonra 5'i seçer. Kalan enerji 0 olduğundan üçüncü buton için sırayla 1 ve 2 denenip reddedilir, 0 seçilince 3 + 5 + 0 bulunur ve 1 değeri bütün çağrılar boyunca geri döner. Fonksiyon en fazla $\binom{n}{3}$ üçlü dener, yani en kötü durumda $n^3$ mertebesindedir. Bu, üç iç içe döngüyle yazılan çözümle aynı mertebedir. Dolayısıyla bu soruda istenen performans değil, özyinelemeli düşünmedir.

## Dersin Toparlaması

Bu laboratuvarda bir dizide toplamı verilen bir değere tam olarak eşit olan 3 eleman aranıyor. Buton sayısı, buton değerleri ve gerekli enerji kullanıcıdan alınıyor, seçilecek buton sayısı ise hep 3 kalıyor. Sonuç yalnız "Ampul yanar" ya da "Ampul yanmaz" olarak veriliyor. Sorunun asıl amacı aramayı özyinelemeyle yazmaktır.

Bugün konu anlatılmadı. Hoca kalan konulara Cuma günü devam edileceğini, bu konuların gelecek dönem için önemli olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
