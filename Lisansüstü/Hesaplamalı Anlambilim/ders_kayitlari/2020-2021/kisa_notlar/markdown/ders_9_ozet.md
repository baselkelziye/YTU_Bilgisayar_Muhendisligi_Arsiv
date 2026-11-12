# Ders 9 Çalışma Özeti

## Genel Konular

- Ödev sunumları: BERT ile aktif öğrenme ve yarı eğiticili öğrenme
  - Dersin ilk yarısında öğrenciler, bir önceki derste görülen BERT'i aktif öğrenme (active learning) ve yarı eğiticili öğrenme (semi-supervised learning) ile birleştirdikleri çalışmaları sundu. Veri kümeleri: haber metinleri (metin sınıflandırma), film yorumları ve tweet'ler (duygu analizi), dersin paylaştığı yarışma verisi (olumlu/olumsuz/nötr tweet'ler).
  - Aktif öğrenmenin ortak şeması: küçük bir başlangıç eğitim kümesiyle model eğitilir, etiketsiz havuzdaki (pool-based sampling) örnekler için sınıf olasılıkları tahmin edilir, modelin en emin olmadığı örnekler seçilip eğitim kümesine eklenir ve model yeniden eğitilir. Bu seçim rastgele seçimle (random selection) karşılaştırılır.
  - Belirsizlik ölçütleri sunumlarda farklıydı: en olası iki sınıfın olasılık farkının küçük olması (margin selection), olasılığı 0,4 ile 0,6 arasında kalan örnekler (olasılıksal örnekleme), normalize edilmiş sınıf skorlarının varyansının küçük olması (hard sample selection).
  - BERT iki biçimde kullanıldı: ince ayar (fine-tuning) ile doğrudan sınıflandırıcı olarak ya da özellik çıkarıcı (feature-based) olarak. Özellik tabanlı kullanımda 12 katmanın her birinden 768 boyutlu [CLS] temsili alınıp üzerinde lojistik regresyon eğitildi.
  - Yarı eğiticili öğrenmede etiketli veriyle eğitilen model etiketsiz veriye sözde etiket (pseudo-label) verdi, iki veri birleştirilip model yeniden eğitildi.
- Metin sınıflandırma (ekrandan, 01:10:20)
  - Hocanın paylaştığı kodda (`text_classify_lsi.m`) 13 sınıflı haber metinleri LSI ile $13 \times 5 = 65$ boyuta indirgenip sınıflandırılıyor. Test örnekleri sabit, her sınıf için 250 tane. Eğitim örneği sayısı arttıkça test başarısı artıyor (slayttaki grafikte yaklaşık %18'den %50'ye).
  - Aynı metinler LSI olmadan tf, binary, tf-idf, kelime ve n-gram temsilleriyle de sınıflandırılabilir (`text_classify_tfidf.m`).
- Duygu durum analizi (ekrandan, 01:11:20)
  - Amaç: bir firma, kişi, parti, kurum, olay vb. hakkında kamuoyu algısını ölçmek.
  - Algı operatörü botlara dikkat edilmeli; slayta göre atılan mesajların tahminen %20'si bu tür botlardan geliyor.
  - Eğitim kümeleri genelde eskir. Metin temsilinde klasik yaklaşımlar (kelime, kelime kökü, n-gram) ve yeni yaklaşımlar (semantik uzaylar, LSTM, CNN) vardır.
- Kelime vektörleriyle ve karakterlerle CNN (ekrandan, 01:12:20 ve 01:20:40)
  - Metin bir resim (matris) gibi düşünülür: her satıra bir kelimenin vektörü yazılır. Satır sayısı veri kümesindeki en uzun metnin kelime sayısıdır; kısa metinlerin kalan satırları 0 ile doldurulur (padding).
  - Filtreler kelime vektörünün tamamını kapsar ($k_m \times d_m$) ve yalnız aşağı doğru kaydırılır. $2 \times d$'lik filtre ardışık kelime ikililerindeki, $3 \times d$'lik filtre üçlülerdeki örüntüleri yakalar. Her filtrenin çıktısı F'nin bir sütunudur; her sütunun maksimumu B vektörüne yazılır; B ile çıkış vektörü S arasında tam bağlı bir katman vardır.
  - Karakter tabanlı yaklaşımda her karakter one-hot kodlanır (veri kümesinde 80 küsur farklı karakter). Matris en çok 140 küsur karakter satırından oluşur; $3 \times$ (karakter sayısı)'lık filtre karakter 3-gramları üzerinde çalışır. Kelime vektörü gerekmez.
  - Karşılaştırma sonuçları (ekrandan, 01:23:20): kelime torbası %66,28; karakter 3-gram torbası %66,92; kelime vektörü ortalamaları %66,33; kelime bazlı LSTM %65,35; kelime bazlı CNN %67,14; karakter bazlı CNN %69,25. Slayt notu: son üç yaklaşımın çok fazla hiperparametresi var.
- Duygu durum analizi neden zordur? (ekrandan, 01:24:45)
  - "Yemeğimi 5 dakikada getirdiniz çok teşekkürler" ile "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" arasında tek karakter fark var ama biri olumlu, biri olumsuz (ironi). "2500 tl lik fatura için çok teşekkürler" cümlesini anlamak için de dünya bilgisi gerekir.
- Proje konularında anlatılan yöntemler (ekrandan, 01:30:00 ve 01:40:00)
  - Yapay veri üretimi (veri zenginleştirme): back translation, fastText ile en yakın kelimeyle değiştirme, BERT'in maskelenmiş kelime tahmini önerileri.
  - Sebep-sonuç ve "ne, nerede" bilgisini varlık ismi tanıma (NER) gibi kelime başına etiketleme ile bulmak.
  - Başlıktan haber özeti, özetten başlık üretme; 100 MB'lık Türkçe derlemde bir cümleye en benzer 10 cümleyi bulma (doğruluk ve hız karşılaştırması); Quora soru çiftlerinin Türkçeye çevrilmesiyle parafraz tespiti; iki boyutlu kelime gömmeleri; film/dizi altyazılarıyla sohbet botu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aktif öğrenmede sınıf dağılımını korumak
  - Bir sınıfın örnekleri diğerlerinden daha kolay ya da daha zor olabilir. Belirsizliğe göre tek bir sıralama yapılırsa o sınıftan başlarda hiç örnek seçilmeyebilir ve model o sınıfı az öğrenir.
  - Öneri: sıralamayı her sınıfın örnekleri içinde ayrı yapıp her sınıftan belli oranda örnek almak. Yeni eklenen örnekler, orijinal eğitim kümesindeki sınıf oranlarını aşağı yukarı korumalı.
- Yarı eğiticili öğrenmenin gerçekçi deney düzeni
  - 13 bin etiketli ve 3 bin etiketsiz örnekle yapılan deney gerçek durumu yansıtmaz. Gerçekte etiketsiz veri çok, etiketli veri azdır; deney bu orana göre kurulmalı.
  - Sözde etiketli veri tek seferde değil, parça parça (örneğin biner biner) eklenmeli; ilerleme izlenip başarının düştüğü yerde durulmalı. Sınıf olasılığı yeterince yüksek olmayan sözde etiketli örnekler alınmayabilir.
  - Normalde etiketli veri arttıkça başarının artması beklenir; artmıyorsa veri kümesi ya da deney sorgulanmalı.
- BERT katmanlarının temsilleri
  - Önceki derste söylendiği gibi en iyi temsil her zaman son katmandan gelmez. Bir sunumda duygu analizinde en iyi sonuç 10. katmandan (%90,5), haber sınıflandırmada 3. katmandan alındı; hoca katmanların ayrı ayrı incelenmesini yararlı buldu.
- Metni resim olarak görmek
  - Kelime vektörleri alt alta yazılınca metin sabit boyutlu bir matris olur. Kelime vektörü word2vec'ten de BERT'ten de gelebilir; sonuçta CNN uygulanabilir.
  - Bu matriste $3 \times 3$'lük bir filtreyi her yöne gezdirmek genelde anlamlı değildir, çünkü filtre kelimenin tamamını içermez.

## Kısa Tekrar Notları

- Aktif öğrenme: küçük etiketli küme ile başla, modelin en emin olmadığı örnekleri etiketleyip ekle, yeniden eğit. Rastgele seçimle karşılaştır.
- Belirsizlik ölçütleri: en olası iki sınıfın olasılık farkı (margin), 0,4-0,6 aralığı, sınıf skorlarının varyansı.
- Seçimde sınıf dağılımı korunmalı; aksi halde zor sınıftan hiç örnek seçilmeyebilir.
- Yarı eğiticili öğrenme: etiketli veriyle eğit, etiketsize sözde etiket ver, birleştirip yeniden eğit. Etiketsiz veri etiketliden çok olmalı; ekleme kademeli yapılmalı.
- BERT özellik çıkarıcı olarak: 12 katman, her katmanda 768 boyutlu [CLS] temsili. En iyi katman göreve göre değişir.
- LSI ile 13 sınıflı haber verisi 65 boyuta indirgenebilir; eğitim örneği arttıkça başarı artar.
- Duygu durum analizi: kamuoyu algısı, bot mesajlar (tahminen %20), eskiyen eğitim kümeleri.
- Metin CNN'i: satır = kelime vektörü, sütun = boyut; filtre $k \times d$, yalnız aşağı kayar; max pooling ile B vektörü; tam bağlı katmanla çıkış.
- Karakter tabanlı CNN one-hot karakterlerle çalışır; denemede en iyi sonuç (%69,25) budur.
- İroni ve dünya bilgisi duygu analizini zorlaştırır (5 dakika / 55 dakika örneği).
- Veri zenginleştirme: back translation, fastText komşu kelime, BERT maske önerisi.
- NER gibi kelime başına etiketleme, sebep-sonuç ya da "ne/nerede" etiketleriyle de yapılabilir.

## Detaylı Açıklamalar

- Aktif öğrenme sunumları
  - Birinci sunumda haber metinleri (7 sınıf, sınıf başına 700 örnek) ve film yorumları (yaklaşık 57 bin olumlu, 25 bin olumsuz) kullanıldı. Ön işlem: küçük harfe çevirme, link ve hashtag silme, noktalama ve özel karakterleri kaldırma, fazla boşlukları ve satır sonu karakterlerini (`\n`, `\r`) silme. Veri %80 eğitim, %20 test; eğitim kümesinin bir kısmı rastgele seçilen başlangıç eğitim kümesi, kalanı havuz. BERT başlangıç kümesinde eğitildi, havuzdaki tahminlerde en olası sınıfların olasılık farkı en küçük olan örnekler eğitim kümesine eklendi. 10 iterasyon yapıldı: duygu analizinde her iterasyonda 200, haber sınıflandırmada 100 örnek. Duygu analizinde margin selection test başarısını yaklaşık 0,81-0,82 aralığında tutarken rastgele seçim 0,77'ye kadar dalgalandı (ekrandan, 00:13:20). Haber verisinde (dengeli ve küçük) iki yöntem 10 iterasyon sonunda birbirine yaklaştı ve loss düştü. Sunanların çıkarımı: belirsizlik örneklemesi en azından ilk iterasyonlarda rastgele seçimden daha iyi ve tutarlı sonuç veriyor.
  - İkinci sunumda BERT özellik çıkarıcı olarak kullanıldı. Her örnek için 12 katmanın her birinden 768 boyutlu [CLS] temsili alındı; böylece aynı veriyi temsil eden 12 ayrı veri kümesi elde edildi. Veri %6 eğitim, %24 test, %70 etiketsiz bölündü. Aktif öğrenme lojistik regresyonla, 20 iterasyon boyunca yapıldı. Sorgu stratejileri: ardışık örnekleme (her iterasyonda etiketsiz veriden sırayla 100 örnek) ve olasılıksal örnekleme (olasılığı 0,4 ile 0,6 arasındaki tahminler) (ekrandan, 00:20:00). Duygu analizinde en yüksek başarı 10. katmanda olasılıksal örneklemeyle %90,5; 11. katman çok yakın, 12. katman biraz düşük. Haber başlıklarıyla 6 sınıflı sınıflandırmada ise en iyi sonuç 3. katmanda ve ardışık örneklemede alındı; ilk katmanlar son katmanlardan iyi ya da onlarla aynıydı. Olasılıksal örnekleme iterasyon başına yalnız 20-30 örnek ekliyordu; sınıf sayısı fazla ve başlangıç kümesi küçük olunca model olasılıkları iyi kestiremiyor, seçilen örnekler bütün veriyi temsil etmiyor. Hoca burada sınıf dengesizliği olasılığını sordu ve sınıf bazında seçim önerdi.
  - Üçüncü sunumda BERT 100 rastgele başlangıç örneğiyle ince ayar yapıldı. Sınıf skorları negatif değerler de içerdiği için 0-1 aralığına normalize edildi ve her örnek için skorların varyansı hesaplandı; varyansı en küçük 100 örnek (model sınıflar arasında kararsız) etiketli kümeye eklenip yeniden ince ayar yapıldı (hard sample selection). Haber verisinde (7 sınıf, en fazla 50 token, batch 32, 4 epoch) 38 iterasyon yapıldı; en yüksek F1 20. iterasyonda rastgele seçimde görüldü (yaklaşık 0,937; ekrandan, 00:31:40). Sunan kişiye göre yaklaşık 2100 etiketli örnek bu problem için yeterli. Twitter duygu verisinde (2 sınıf, 9174 örnek, 90 iterasyon) sonuçlar dalgalı çıktı ve rastgele seçim beklenenden iyi göründü; hoca bu veri kümesinin üzerinde çalışmaya uygun olmadığını belirtti.
- Yarı eğiticili öğrenme sunumları
  - Bir sunumda BERTurk tabanlı bir dizi sınıflandırma modeli yarışma verisinde ince ayar yapıldı, sonra 3 bin etiketsiz tweet'e sözde etiket verilip birlikte eğitildi. 4 epoch'ta model aşırı öğrendi (training loss düşerken validation loss arttı), 2 epoch'a inildi. Sözde etiketli veri eklenince doğrulama başarısı 0,76'dan 0,77'ye çıktı (ekrandan, 00:40:00). Hoca, etiketli/etiketsiz oranının gerçek durumun tersi olduğunu söyledi.
  - Başka bir sunumda yarışma verisi (13 bin örnek) karıştırılıp 4000 etiketli, 4000 etiketsiz, 2000 test olarak bölündü. Metinler BERT ile 768 boyutlu vektörlere çevrildi (transfer öğrenme), etiketli veriyle Random Forest eğitildi, etiketsiz veri bu modelle etiketlendi ve 8000 örnekle yeni bir Random Forest eğitildi. Test başarısı 0,884'ten 0,9140'a, eğitim başarısı 0,9067'den 0,9376'ya çıktı (ekrandan, 00:44:45). Hoca, 4000 sözde etiketli örneğin tek seferde değil kademeli eklenmesini önerdi.
- Metin sınıflandırma ve duygu durum analizi
  - LSI ile boyut indirgeme metinleri birkaç bin boyuttan 65 boyuta indirir. Grafikte yatay eksen eğitim örneği sayısı (0-250), dikey eksen test başarısıdır; eğitim örneği arttıkça başarı artar (ekrandan, 01:10:20).
  - Duygu durum analizi bugün yalnız fikir ölçme değil, algı yönetimiyle de ilgilidir: Twitter'daki algı operatörü botlar belli bir konuya dikkat çekmek ya da onu farklı düşündürmek için mesaj atar.
  - Denemede kullanılan veri (Amasyalı ve ark. 2018, ASYU, "Duygudurum Analizinde Kelimeler, Anlamlar, Karakterler") (ekrandan, 01:12:20):

    | | Olumlu | Olumsuz | Nötr | Toplam |
    |---|---|---|---|---|
    | Eğitim | 3663 | 5511 | 4658 | 13832 |
    | Test | 916 | 1377 | 1164 | 3457 |
    | Toplam | 4579 | 6887 | 5822 | 17289 |

  - Ders sonrası not: slayttaki "Olumsuz" sütun toplamı $5511 + 1377 = 6888$ olmalıdır; satır toplamları (13832 ve 3457) ve genel toplam (17289) buna göre tutarlıdır (python ile hesaplandı).
  - Örnek tweet "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah ." için iki M matrisi gösterildi (ekrandan, 01:20:40). Kelime vektörü tabanlı matriste 40 satır (en uzun tweet 40 kelime alınmış) ve 100 sütun var; yalnız ilk 9 satır dolu, kalanı sıfır. Karakter tabanlı matriste yaklaşık 140 satır ve 80 küsur sütun var; her satırda tek bir 1 bulunur.
  - Bu veri kümesinde BERT kullanılınca başarının %75 civarına çıkabildiğini hoca hafızadan söyledi. <!-- BELİRSİZ: hoca "yanlış hatırlamıyorsam" dedi; kesin değer slaytta yok. -->
- Proje konularındaki yöntem fikirleri
  - Back translation: A dilindeki metin otomatik çeviriyle B diline, sonra yeniden A diline çevrilir. Sonuç benzer anlamlı ama bir miktar farklı yeni bir örnektir.
  - fastText ile değiştirme: cümlede rastgele bir kelime seçilir ve fastText vektörüne en yakın kelimeyle değiştirilir ("bugün elma yedim" → "bugün armut yedim").
  - BERT önerileri: bir kelime [MASK] ile kapatılıp maskelenmiş kelime tahmini istenir; orijinalden farklı, yüksek olasılıklı bir öneri seçilir.
  - İncelenecek sorular: yapay veri kullanmanın etkisi, ne kadar yapay veri üretileceği (10 orijinal örneğe 100 yapay mı, 2 yapay mı), yöntemleri bir arada kullanmanın etkisi.
  - NER ile sebep-sonuç: "yağmur yağınca yerler ıslandı" cümlesinde ilk iki kelime SE (sebep), son iki kelime SO (sonuç) etiketi alır; "lokantada yemek yedim" cümlesinde "lokantada" nerede, "yemek yedim" ne etiketi alır (ekrandan, 01:34:55). Veri, sebep-sonuç ilişkili kelime ikilileri internette aratılıp bunları içeren cümlelerin yarı otomatik etiketlenmesiyle oluşturulabilir.
  - İki boyutlu kelime gömmesi: kelime $1 \times d$ yerine $k \times k$ ($d = k^2$, örneğin $1 \times 100$ yerine $10 \times 10$) matrisle temsil edilir. Metin bu matrislerin yan yana ya da alt alta dizilmesiyle oluşur. Böylece $x \times d$'lik filtreler yerine $g \times g$'lik CNN filtreleri gezdirilebilir ve kelimenin bir parçasına bakan filtreler öğrenilir (ekrandan, 01:44:30).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
