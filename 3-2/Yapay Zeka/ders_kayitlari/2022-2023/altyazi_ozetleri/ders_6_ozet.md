# Ders 6 Çalışma Özeti

## Genel Konular

- Genetik algoritmalara giriş
  - Doğal seçilim ve evrim fikrinden esinlenen arama/optimizasyon yaklaşımı olarak genetik algoritmalar tanıtılır.
- Popülasyon ve birey
  - Tek bir çözüm yerine birçok aday çözümden oluşan bir popülasyonla çalışıldığı açıklanır.
- Kromozom gösterimi
  - Aday çözümlerin genler veya kromozomlar biçiminde temsil edilmesi gerektiği anlatılır.
- Uygunluk fonksiyonu
  - Bir çözümün ne kadar iyi olduğunu ölçen fonksiyonun genetik algoritmanın yönünü belirlediği belirtilir.
- Seçilim, çaprazlama ve mutasyon
  - İyi bireylerin seçilmesi, bireylerden yeni bireyler üretilmesi ve rastgele değişikliklerle çeşitlilik sağlanması süreçleri ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Genetik algoritmada çözüm temsili çok önemlidir.
  - Kromozom yapısı problemi iyi temsil etmezse algoritma anlamlı çözümler üretemez.
- Uygunluk fonksiyonu algoritmanın hedefini belirler.
  - Neyin iyi çözüm sayılacağı açık tanımlanmadığında seçilim de doğru çalışmaz.
- Çaprazlama ve mutasyon farklı amaçlara hizmet eder.
  - Çaprazlama iyi özellikleri birleştirirken mutasyon çeşitlilik sağlar ve aramanın sıkışmasını azaltabilir.
- Genetik algoritmalar kesin çözüm garantisi vermekten çok iyi aday çözümler üretmeye yöneliktir.
  - Özellikle büyük ve karmaşık arama uzaylarında kullanışlıdır.

## Kısa Tekrar Notları

- Genetik algoritma popülasyon tabanlı bir optimizasyon yaklaşımıdır.
- Bireyler aday çözümleri, kromozomlar bu çözümlerin temsilini ifade eder.
- Uygunluk fonksiyonu çözüm kalitesini ölçer.
- Seçilim iyi bireyleri öne çıkarır.
- Çaprazlama yeni birey üretir; mutasyon çeşitliliği korur.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Genetik algoritmalar (Genetic Algorithms), doğadaki evrimsel süreçleri ve doğal seçilim mekanizmasını taklit eden popülasyon tabanlı bir lokal arama ve optimizasyon yöntemidir. Arama uzayındaki olası çözümler "kromozom" (genellikle bit dizileri veya reel sayı dizileri) olarak temsil edilir. Algoritma; başlangıç popülasyonunun oluşturulması, her bireyin kalitesini ölçen uygunluk (fitness) fonksiyonunun hesaplanması, rulet tekerleği veya turnuva gibi yöntemlerle ebeveyn seçimi, çaprazlama (crossover - gen değişimi) ve mutasyon (rastgele genetik değişim) adımlarıyla yeni nesiller üretir. Başarının anahtarı, problemin kromozom üzerinde doğru şekilde kodlanması ve çeşitliliğin korunarak lokal minimumlardan kaçınılmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
