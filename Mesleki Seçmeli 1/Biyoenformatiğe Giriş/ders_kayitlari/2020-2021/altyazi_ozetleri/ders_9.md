# Ders 9 Çalışma Özeti

## Genel Konular

- Dinamik programlama ile dizi hizalama
  - Dinamik programlama, dizi hizalama problemlerinde optimal hizalamayı bulmak için kullanılan temel yaklaşımdır.
  - Problem, bir matrisin belirli bir puanlama şemasına göre doldurulması ve sonra geriye izleme yapılması şeklinde ele alınır.
- Matris kurulumu
  - Hizalanacak iki diziden biri satırlara, diğeri sütunlara yerleştirilir.
  - Matris boyutu genellikle dizi uzunluklarının bir fazlası olacak biçimde kurulur.
- Puanlama şeması
  - Eşleşme için pozitif puan, uyuşmazlık için negatif puan ve boşluk için ceza tanımlanır.
  - Örnekte eşleşme, uyuşmazlık ve gap değerleri seçilerek matris doldurma anlatılır.
- Hizalama türleri
  - Global hizalama, dizileri uçtan uca hizalamaya çalışır.
  - Lokal hizalama, diziler içindeki en iyi benzer alt bölgeleri bulmaya odaklanır.
  - Örtüşme hizalaması, dizilerin kısmi örtüşmelerini değerlendirmek için kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dinamik programlama matris doldurma problemidir
  - Satır ve sütunlar boyunca hesaplama yapılarak her hücreye en iyi ara çözüm yerleştirilir.
- Geriye izleme gereklidir
  - Matris değerleri yalnızca skor üretmez; hizalamanın nasıl oluştuğunu bulmak için traceback yapılır.
- Puanlama seçimi sonucu etkiler
  - Match, mismatch ve gap değerleri hizalamanın biçimini değiştirebilir.

## Kısa Tekrar Notları

- Dinamik programlama dizi hizalamada optimal çözüm için kullanılır.
- İşlem: matrisi başlatma, doldurma, geriye izleme.
- Match pozitif, mismatch ve gap genellikle negatif puan alır.
- Global, lokal ve örtüşme hizalaması farklı amaçlara hizmet eder.

## Detaylı Açıklamalar

- Dinamik programlama, büyük hizalama problemini daha küçük alt problemlere ayırarak çözer. Her matris hücresi, o noktaya kadar olan en iyi hizalama skorunu temsil eder. Bu sayede tüm olası hizalamaları doğrudan denemek yerine sistematik ve hesaplanabilir bir yol izlenir.
- İlk adım matrisin kurulması ve başlatılmasıdır. Başlatma biçimi seçilen hizalama türüne göre değişebilir. Daha sonra matris, belirlenen puanlama şemasına göre satır satır veya sütun sütun doldurulur.
- Matris doldurulduktan sonra en iyi skoru veren yoldan geriye doğru izleme yapılır. Bu izleme, hangi karakterlerin eşleştiğini, nerede boşluk açıldığını ve hangi uyuşmazlıkların kabul edildiğini gösteren hizalamayı üretir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
