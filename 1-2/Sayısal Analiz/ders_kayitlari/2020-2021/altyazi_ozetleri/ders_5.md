# Ders 5 Çalışma Özeti

## Genel Konular

- Fonksiyonların bilgisayarda modellenmesi
  - Polinom fonksiyonları: aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀ biçiminde ifade edilen fonksiyonlar.
  - Polinomu modellemek için katsayı dizisi (coefficient array) kullanılır; dizinin indisleri polinomun derecelerini temsil eder.
  - Örneğin x³ + 2x + 5 polinomu için dört elemanlı bir dizi oluşturulur: [5, 2, 0, 1].
- Veri yapıları kullanımı
  - Fonksiyonları bilgisayarda temsil etmek için veri yapıları (diziler, matrisler) kullanılır.
  - Polinomun katsayıları ve dereceleri dizilerde saklanır.
  - Arada herhangi bir dereceli terim sıfırsa, o terimin katsayısı 0 olarak dizide yer alır.
- Kök bulma yöntemleri için hazırlık
  - Bisection, regula falsi ve Newton-Raphson gibi yöntemlerin uygulanabilmesi için fonksiyonun bilgisayarda temsil edilmesi gerekir.
  - Fonksiyon türleri: polinom, trigonometrik, logaritmik, üstel (eksponansiyel) fonksiyonlar.
  - Her bir fonksiyon türü farklı veri yapılarıyla modellenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fonksiyon türlerinin kullanıcıdan alınması ve dizilerde saklanması gerektiği vurgulandı.
- Karmaşık fonksiyonların (ör. eˣ × sin(2x) + x²) modellenmesinde birden fazla terimin bir arada ele alınması gerektiği belirtildi.
- Polinom modelinde sadece katsayıların saklanması yeterlidir; indisler zaten dereceleri gösterir.

## Kısa Tekrar Notları

- Polinom modeli: katsayı dizisi ile temsil; indis = derece.
- x³ + 2x + 5 → [5, 2, 0, 1] (dört elemanlı dizi).
- Fonksiyon türleri: polinom, trigonometrik, logaritmik, üstel.
- Kök bulma yöntemleri için fonksiyonun bilgisayar temsili şarttır.

## Detaylı Açıklamalar

Bu derste fonksiyonların bilgisayarda nasıl modelleneceği ayrıntılı olarak ele alındı. Polinom fonksiyonları için en pratik temsil yöntemi, katsayıları bir dizide saklamaktır. Dizinin her bir indisi polinomun ilgili derecesinin katsayısını tutar. Bu sayede polinomun derecesi ve terimleri kolayca erişilebilir hale gelir.

Örneğin x³ + 2x + 5 polinomu için dört elemanlı bir dizi kullanılır: dizinin 0. indisi sabit terimi (5), 1. indisi birinci dereceden terimin katsayısını (2), 2. indisi ikinci dereceden terimin katsayısını (0), 3. indisi ise üçüncü dereceden terimin katsayısını (1) tutar.

Trigonometrik fonksiyonlar (sin, cos, tan vb.), logaritmik fonksiyonlar ve üstel fonksiyonlar da benzer şekilde dizilerle temsil edilebilir. Her bir fonksiyon türü için giren parametreler dizide saklanır.

Kök bulma yöntemlerinin (bisection, regula falsi, Newton-Raphson) uygulanabilmesi için önce fonksiyonun bilgisayarda temsil edilmesi gerekir. Bu temsil sayesinde fonksiyonun belirli noktalardaki değerleri hesaplanabilir ve iteratif yöntemler çalıştırılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
