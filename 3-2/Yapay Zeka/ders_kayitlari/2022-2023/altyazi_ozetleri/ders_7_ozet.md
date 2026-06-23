# Ders 7 Çalışma Özeti

## Genel Konular

- Oyun problemlerine giriş
  - Yapay zekada oyunların, karar verme ve arama problemlerini modellemek için uygun örnekler sunduğu anlatılır.
- İki oyunculu sıfır toplamlı oyunlar
  - Bir oyuncunun kazancının diğer oyuncunun kaybı olduğu oyun yapıları üzerinden akıl yürütme yapılır.
- Oyun ağacı
  - Olası hamlelerin ve karşı hamlelerin ağaç yapısı içinde modellenebileceği açıklanır.
- Minimax algoritması
  - Oyuncunun kendi kazancını maksimize etmeye, rakibin ise bunu minimize etmeye çalıştığı karar verme yaklaşımı anlatılır.
- Alfa-beta budama
  - Minimax aramasında sonucu değiştirmeyecek dalların elenerek aramanın hızlandırılabileceği açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Oyunlarda arama tek taraflı değildir.
  - Rakibin de en iyi hamleyi yapacağı varsayımı hesaba katılmalıdır.
- Minimax mantığını anlamak, oyun yapay zekasının temelidir.
  - En iyi hamle yalnızca mevcut kazanca değil, rakibin olası cevaplarına göre seçilir.
- Alfa-beta budama sonucu değiştirmeden arama maliyetini azaltır.
  - Budama, gereksiz dalları incelemeyerek aynı karara daha az işlemle ulaşmayı amaçlar.
- Derinlik sınırı pratikte önemlidir.
  - Büyük oyun ağaçlarında tüm olasılıkları sona kadar aramak mümkün olmayabilir; değerlendirme fonksiyonları gerekir.

## Kısa Tekrar Notları

- Oyun ağacı hamle ve karşı hamleleri temsil eder.
- Minimax, oyuncuların rasyonel davrandığı varsayımıyla karar seçer.
- Maks oyuncu skoru artırmaya, min oyuncu azaltmaya çalışır.
- Alfa-beta budama gereksiz dalları eler.
- Büyük oyunlarda derinlik sınırı ve değerlendirme fonksiyonu kullanılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Yapay zekada oyun oynama problemleri, rakibin de akıllı ve rasyonel davrandığı dinamik ve düşmanca (adversarial) arama problemleri olarak ele alınır. İki oyunculu sıfır toplamlı (zero-sum) oyunlarda bir oyuncunun kazancı diğerinin kaybına eşittir. Minimax algoritması, bu tür oyunlarda karar vermek için kullanılır. MAX oyuncusu kendi kazancını maksimize etmeye çalışırken, MIN oyuncusu MAX'ın kazancını minimize etmeye çalışır. Oyun ağacının tamamını taramak üstel zaman alacağından (O(b^d)), performansı artırmak için Alfa-Beta Budama (Alpha-Beta Pruning) yöntemi uygulanır. Alfa-Beta budama, optimal kararı değiştirmeden ağacın değerlendirilmesi gerekmeyen dallarını budayarak arama süresini yarı yarıya azaltabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
