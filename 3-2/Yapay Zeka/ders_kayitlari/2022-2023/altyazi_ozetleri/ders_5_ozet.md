# Ders 5 Çalışma Özeti

## Genel Konular

- Sezgisel aramanın devamı
  - Önceki dersteki sezgisel arama mantığı hatırlatılır ve arama problemlerinde sezgisel yönlendirmenin önemi pekiştirilir.
- Lokal arama
  - Tüm çözüm yolunu genişletmek yerine mevcut durumdan komşu durumlara geçerek daha iyi çözümler arayan yöntemler tanıtılır.
- Tepe tırmanma yaklaşımı
  - Mevcut çözümün komşuları arasından daha iyi görünen duruma geçerek ilerleyen bir lokal arama yöntemi olarak anlatılır.
- Lokal optimum problemi
  - Bir yöntemin bulunduğu noktada daha iyi komşu göremediği için durabileceği, fakat bunun global en iyi çözüm olmayabileceği açıklanır.
- Sezgisel değerlendirme ve komşuluk
  - Lokal aramada çözüm kalitesini ölçen fonksiyonun ve hangi durumların komşu sayılacağının yöntemin başarısını etkilediği vurgulanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lokal arama, durum uzayının tamamını saklamadan çalışabilir.
  - Bu nedenle büyük problemlerde bellek açısından avantaj sağlayabilir.
- Tepe tırmanma basit ama sınırlı bir yöntemdir.
  - Yerel en iyi noktalara takılabilir; plato veya omuz gibi durumlarda ilerleme zorlaşabilir.
- Komşuluk tanımı problemin çözüm kalitesini belirler.
  - Hangi hareketlerin mümkün sayıldığı, algoritmanın ulaşabileceği çözümleri doğrudan etkiler.
- Değerlendirme fonksiyonu yalnızca teknik ayrıntı değildir.
  - Yanlış kalite ölçütü, algoritmanın yanlış çözümleri iyi sanmasına neden olabilir.

## Kısa Tekrar Notları

- Lokal arama mevcut çözümden başlayıp komşu çözümleri dener.
- Tepe tırmanma, daha iyi komşuya geçerek ilerler.
- Lokal optimum, global optimum olmak zorunda değildir.
- Büyük durum uzaylarında lokal arama pratik avantaj sağlayabilir.
- Komşuluk ve değerlendirme fonksiyonu doğru kurulmazsa sonuçlar yanıltıcı olur.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Lokal arama algoritmaları, hedefe giden yolu saklamak yerine sadece mevcut durumu (current state) ve onun komşularını inceleyerek çalışır. Bu nedenle bellek gereksinimleri son derece azdır (O(1)) ve çok büyük durum uzaylarında tercih edilirler. Tepe Tırmanma (Hill Climbing) algoritması, her adımda mevcut durumun komşuları arasından değeri (uygunluğu) en yüksek olan duruma geçerek sürekli "yukarı" tırmanır. Ancak bu algoritma lokal optimum (yerel en iyi) noktalarına, düzlüklere (plateau) veya sırtlara (ridge) takılarak küresel en iyiye (global optimum) ulaşamayabilir. Bu problemleri aşmak için rastgele adımlarla tırmanma, tavlama benzetimi (simulated annealing) veya lokal ışın arama (local beam search) gibi yöntemler kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
