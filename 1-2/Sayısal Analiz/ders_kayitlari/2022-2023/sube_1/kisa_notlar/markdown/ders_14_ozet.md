# Ders 14 Çalışma Özeti

## Genel Konular

- Dönemin son haftası. Yeni konu işlenmedi, kayıt proje gösterimlerinin son haftasıdır.
- Gösterimlerde görülen tipik hatalar
  - Katsayıları veya ara değişkenleri `int` tanımlamak: 0.1 gibi ondalıklı katsayılar girilince sonuç yanlış çıktı. Simpson ve trapezde hata veren bir öğrencinin sorunu da `double` yerine `int` kullanmasıymış. Hoca sonraki öğrencilere "inşallah katsayılar değişkenini integer tanımlamadınız" diye sordu.
  - Gauss-Seidel'de maksimum köşegen kontrolünün yanlış çalışması (iki ayrı programda, 00:19:17 ve 00:23:05): köşegeni zaten büyük olan bir sistem verildiğinde doğru sonuç çıkmadı.
  - Polinom katsayılarını hesaplayan ortak bir fonksiyonda dizi/işaretçi aktarımı hatası: katsayıların yalnızca ilk iki elemanı kullanılıyordu. <!-- BELİRSİZ: Öğrenci önce "ilk iki" (01:32:08), hemen sonra "son iki" dedi (01:32:14). --> Bu fonksiyona bağlı altı yöntemin hepsi bozuldu. Hoca "parametre göndermede hata var demek" dedi ve sordu: "Çalışan bir kodu bozmadan önce neden kopyasını almadın?"
  - Bazı programlar polinomun "terim sayısını" sorduğu için eksik kuvvetler (ör. $x^3$ ve $x^4$ olmayan bir polinom) karışıklığa yol açtı. Ders sonrası öneri: programınız katsayısı sıfır olan terimlerin nasıl girileceğini açıkça belirtsin.
- Gösterimlerde kullanılan bazı girdiler
  - Kök bulma: $x^2 - 4x - 5$ (kökler −1 ve 5).
  - Sayısal türev: merkezi fark, $h = 0.25$.
  - Gauss eliminasyon (3 bilinmeyen): $x_1 + x_2 + x_3 = 25$, $5x_1 + 3x_2 + 2x_3 = 0$, $x_2 - x_3 = 6$. Çözüm $x_1 = -26.2$, $x_2 = 28.6$, $x_3 = 22.6$ (00:57:19; Python ile hesaplandı).

## Hocanın Özellikle Vurguladığı Kısımlar

- Çalışan kodun yedeğini almadan değişiklik yapmayın.
- Ondalıklı sayılarla çalışan değişkenleri `double` tanımlayın.

## Kısa Tekrar Notları

- Sık hata: `int` yerine `double`, dizi aktarımı, maksimum köşegen kontrolü.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **`int` hatası neden olur?** C'de `int a = 0.1;` ataması 0 değerini verir ve `1/2` gibi tam sayı bölmeleri 0 sonucunu üretir. Sayısal yöntemlerde katsayılar, adım uzunluğu $h$ ve ara sonuçlar hep ondalıklı olduğundan `double` kullanılmalıdır. Döngü sayaçları ve dizi indisleri ise `int` kalabilir.
- **Ortak fonksiyonlarda dizi aktarımı:** C'de bir diziyi fonksiyona gönderince dizinin boyutu kaybolur, yalnızca ilk elemanın adresi gider. `sizeof(dizi)` fonksiyon içinde işaretçinin boyutunu verir. Bu yüzden boyutu (ör. polinomun derecesi) ayrı bir parametre olarak gönderin. Gösterimdeki "yalnızca ilk iki katsayıyı alıyor" belirtisi bu tür bir boyut veya aktarım hatasına benziyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
