# Ders 9 Genişletilmiş Notu: Aktif ve Yarı Eğiticili Öğrenme Sunumları, Metin Sınıflandırma ve Duygu Durum Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev Sunumları: BERT ile Aktif Öğrenme
- 2. Ödev Sunumları: BERT ile Yarı Eğiticili Öğrenme
- 3. Uygulamalar Bölümüne Giriş ve Metin Sınıflandırma
- 4. Duygu Durum Analizi
- 5. Metni Resim Gibi Görmek: Kelime ve Karakter Tabanlı CNN
- 6. Duygu Durum Analizi Neden Zordur?
- 7. Proje Konularında Anlatılan Yöntemler
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödev Sunumları: BERT ile Aktif Öğrenme

Dersin ilk yarısı, bir önceki derste anlatılan bağlam farkında dil modellerinin (özellikle BERT) uygulandığı ödevin sunumlarına ayrıldı. Ödevde BERT'in aktif öğrenme (active learning) ya da yarı eğiticili öğrenme (semi-supervised learning) ile birlikte en az iki doğal dil işleme probleminde denenmesi isteniyordu. Sunumlar bir öğrenci ya da bir grup tarafından yapıldı; aşağıda yalnız akademik içerikleri ve hocanın yorumları aktarılmıştır.

> **Ek bilgi (derste anlatılmadı):** Aktif öğrenmede model, etiketlenecek örnekleri kendisi seçer. Havuz tabanlı (pool-based) senaryoda büyük bir etiketsiz havuzdan, modelin en çok bilgi kazanacağı düşünülen örnekler seçilip etiketlenir. Belirsizlik örneklemesinin (uncertainty sampling) yaygın türleri en düşük güven (least confidence), en olası iki sınıfın olasılık farkı (margin) ve entropidir. Amaç, aynı başarıya daha az etiketli örnekle ulaşmaktır.

### 1.1 Margin selection ile BERT ince ayarı

İlk grup iki veri kümesi kullandı. Birincisi 7 sınıflı haber metinleridir: her sınıftan 700 örnek, toplam 4900 metin. Bunun üzerinde metin sınıflandırma yapıldı. İkincisi film yorumlarıdır: yaklaşık 57 bin olumlu ve 25 bin olumsuz yorum. Bunun üzerinde duygu analizi yapıldı.

Ön işlem adımları şunlardı:

- Büyük-küçük harf dönüşümü.
- Linklerin ve hashtag'lerin kaldırılması.
- Noktalama işaretlerinin ve özel karakterlerin kaldırılması.
- Fazla boşlukların ve `\n`, `\r` satır sonu karakterlerinin silinmesi.

Senaryo havuz tabanlı örneklemeydi (pool-based sampling). Veri %80 eğitim ve %20 test olarak bölündü; eğitim kısmından rastgele seçilen küçük bir parça başlangıç eğitim kümesi (initial train set), kalanı havuz oldu. BERT önce başlangıç kümesinde eğitildi. Sonra havuzdaki her örnek için sınıf olasılıkları hesaplandı ve sınıf olasılıkları arasındaki fark incelendi. Fark çok küçükse model o örnekte kararsızdır, yani onu iyi öğrenememiştir. Farkı en küçük olan örnekler havuzdan çıkarılıp eğitim kümesine eklendi ve model yeniden eğitildi (margin selection, bir tür uncertainty sampling). Karşılaştırma için aynı sayıda örnek rastgele de seçildi (random selection).

Toplam 10 iterasyon yapıldı. Duygu analizinde her iterasyonda 200 örnek seçildi; veri kümesi 80 bin civarında olduğu için bu sayı büyük tutuldu. BERT'in eğitimi yavaş olduğu için iterasyon sayısı 10'da kesildi. Sunumdaki grafikte (ekrandan, 00:13:20) iki yöntem 0 numaralı iterasyonda yaklaşık 0,815 test başarısıyla başlıyor. Margin selection sonraki iterasyonlarda yaklaşık 0,805 ile 0,82 arasında kalırken rastgele seçim 0,77'nin altına kadar düşen büyük sıçramalar yaptı. Bu veri kümesinde loss beklenmedik biçimde arttı; sunanlar bunu veri kümesinin dengesiz olmasına ve verinin az bir kısmıyla eğitime bağladı.

Haber sınıflandırmada veri daha az ve dengeli olduğu için iterasyon başına 100 örnek seçildi. Sonuçlar çok daha iyiydi; 10 iterasyondan sonra iki yöntemin başarıları birbirine yaklaştı. Margin selection'ın eğrisi daha çok sıçrama yaptı, rastgele seçimin eğrisi daha düzgün görünüyordu. Loss beklendiği gibi düştü ve margin selection daha düşük loss değerlerine indi. Sunanların çıkarımı: belirsizlik örneklemesi farklı doğal dil işleme problemlerinde, en azından ilk iterasyonlarda, rastgele seçime göre daha iyi ve tutarlı sonuçlar veriyor; önceden eğitilmiş BERT ile aktif öğrenme birlikte kullanılınca başarı ilk iterasyonlardan itibaren iyileşiyor.

### 1.2 Özellik tabanlı BERT: katman katman [CLS] temsilleri

İkinci sunumda BERT ince ayar yerine özellik çıkarıcı (feature-based) olarak kullanıldı. Duygu analizinde film yorumu veri kümesi, BERT'le işlem uzun sürdüğü için 10 bin örneğe indirildi; tek özellik yorum metni, iki sınıf vardı. Her yorum BERT'e verildi ve 12 katmanın her birinden [CLS] temsili alındı. Her temsil 768 boyutludur; böylece veri kümesi 768 sütunlu, örnek sayısı kadar satırlı bir matrise dönüştü.

Hoca burada sunumu durdurup yöntemi netleştirdi:

**Soru:** [CLS] gömmeleri 768 boyutlu ve her katmanda ayrı bir tane dönüyor, 12 katman var. Bu katmanların her birini ayrı ayrı alıp nasıl performans gösterdiklerini mi incelediniz? **Cevap:** Evet; aynı veriyi temsil eden ama farklı katmanlardan gelen 12 ayrı veri kümesi oluştu ve her biri için ayrı model kuruldu.

Veri %6 eğitim, %24 test ve %70 etiketsiz olarak bölündü. Aktif öğrenme kısmında BERT değil lojistik regresyon kullanıldı ve süreç 20 iterasyon boyunca tekrarlandı. İki sorgu stratejisi denendi (ekrandan, 00:20:00):

- Ardışık örnekleme: her iterasyonda etiketsiz veriden sırayla 100 örnek alınır.
- Olasılıksal örnekleme: tahmin olasılığı 0,4 ile 0,6 arasında kalan örnekler alınır.

Duygu analizinde en yüksek başarı 10. katmanın [CLS] temsiliyle ve olasılıksal örneklemeyle elde edildi: %90,5. 11. katmanın sonuçları neredeyse aynıydı, 12. katman biraz daha düşüktü. Sunanlar bunu önceki derste söylenen "en iyi temsil her zaman son katmandan gelmez" gözlemiyle ilişkilendirdi. Grafiklerde olasılıksal örneklemenin başarısı genelde 12. iterasyondan sonra sabitlenirken ardışık örnekleme sürekli iniş çıkış gösterdi; iki yöntem arasındaki fark çoğunlukla %2-3, bazen %4 idi. İlk altı katmanın grafiklerinde (ekrandan, 00:21:00) olasılıksal örneklemenin eğrisi (mavi) ardışık örneklemenin (turuncu) çoğunlukla üstündeydi.

Metin sınıflandırmada aynı büyüklükte olsun diye haber veri kümesinden 10 bin örnek seçildi; yalnız haber başlıkları kullanıldı, sınıf sayısı 6'ya indirildi. Burada sonuç farklıydı: en yüksek başarı ardışık örneklemede ve 3. katmanda elde edildi. İlk beş katmanın başarısı diğerlerinden iyi ya da onlarla aynıydı, son katmanlarda başarı düştü. Olasılıksal örneklemede 3. katmanla %84 küsur başarı alındı. Olasılıksal örnekleme bu veride çok erken (5.-6. iterasyonda) sabitlendi, ardışık örnekleme ise sürekli yükseldi.

Sunanlar nedenini şöyle yorumladı: olasılıksal örnekleme her iterasyonda etiketsiz veriden yalnız 20-30 örnek alıyordu. Sınıf sayısı fazla olunca model %6'lık başlangıç kümesini iyi öğrenemiyor, olasılık değerleri de yanıltıcı oluyor; model ya zaten iyi temsil ettiği örnekleri yeniden alıyor ya da bazı sınıflardan hiç örnek alamıyor. Sonuçta eğitim verisi bütün veriyi temsil etmiyor.

**Soru:** Bir sınıf dengesizliği olabilir mi orada? **Cevap:** Hoca bunu şöyle açıkladı. Olasılıkları birbirine yakın, yani modelin emin olamadığı örnekler seçiliyor. Bir sınıfın örnekleri diğerlerinden daha kolay ya da daha zor olabilir. Öyle bir durumda o sınıfın örnekleri başlarda hiç seçilemez; model o sınıftan çok az örnek görür ve onu çok az öğrenir.

> **Hocanın vurgusu:** Sıralamayı bütün veriler üzerinden tek seferde yapmak yerine her sınıfın örneklerini kendi içinde sıralayıp her birinden belli bir yüzde almak gerekir. Sınıfların dağılımları farklılaşırsa orada bir şey yapmak oldukça zorlaşır.

**Soru:** Hem başlangıç eğitim kümesinde hem de her iterasyonda sınıflardan eşit sayıda veri almak mı gerekiyor? **Cevap:** Eşit değil, orantılı. Orijinal eğitim kümesinde sınıflar birbirine hangi oranda ise, her yeni üretilen eğitim kümesi de sınıf bazında bu oranı aşağı yukarı korumalıdır.

### 1.3 Varyans tabanlı zor örnek seçimi

Üçüncü sunumda benzer bir aktif öğrenme döngüsü kuruldu. Veri havuzundan başlangıç için 100 rastgele örnek seçildi, bunlarla BERT ince ayar yapıldı. Sonra geri kalan veriler için her sınıfın skoru hesaplandı. Skorların bir kısmı negatifti (bir sınıfa 3, başka bir sınıfa 4 gibi değerler veriyordu), bu yüzden skorlar 0-1 aralığına normalize edildi ve her örnek için skorların varyansı hesaplandı. Varyansı en küçük 100 örnek (model sınıflar arasında kararsız) etiketli havuza eklendi ve model yeniden ince ayar yapıldı. Bu yönteme "hard sample selection" dendi ve rastgele seçimle karşılaştırıldı.

Metin sınıflandırma problemi için haber veri kümesi kullanıldı. Hiperparametreler: en fazla 50 token, batch boyutu 32, 7 sınıf, 4 epoch. Başlangıç kümesindeki 100 örneğin sınıf dağılımı dengeliydi (her sınıftan yaklaşık 10-15). Bütün veriyi kapsayacak biçimde 38 iterasyon yapıldı, her adımda 100 örnek eklendi. Test F1 grafiğinde (ekrandan, 00:31:40) değerler 0,915 ile 0,937 arasında dalgalanıyor; en yüksek değer 20. iterasyonda rastgele seçimde (yaklaşık 0,937) görülüyor. Sunan kişinin çıkarımı: bütün veriyi vermek çok daha yüksek bir başarı getirmiyor, bu problem için yaklaşık 2100 etiketli örnek yeterli görünüyor.

Duygu analizi problemi için Twitter verisi kullanıldı: iki sınıf (olumlu, olumsuz), %80 eğitim ve %20 test, toplam 9174 örnek. Hiperparametreler: en fazla 30 token, batch 32, 4 epoch. 90 iterasyon yapıldı, her iterasyonda 100 örnek eklendi. Sonuçlar inişli çıkışlıydı; en iyi sonuç ilk iterasyonda alındı, rastgele seçimde 70'li iterasyonlarda bir tepe görüldü.

**Soru:** Son grafik istenen gibi değil, değil mi? Varyansı küçük olanları alınca sonuçların daha iyi olması beklenirken rastgele seçim daha iyi görünüyor. 90. iterasyon bütün eğitim kümesini kullanmak demek; yani veri kümesinden rastgele bir kısım seçince daha iyi sonuç çıkıyor gibi. Sınıfların birbirine göre oranları nasıldı? Bunlar F1 skoru mu, ayrı bir test kümesinde mi? **Cevap:** Değerler F1 skorudur ve ayrı bir test kümesinde ölçülmüştür. Sunan kişi eğitimi birkaç kez tekrarlamış, sonuç aynı çıkmış.

> **Hocanın vurgusu:** Etiketli verinin büyüklüğü arttıkça normalde başarının da artması beklenir. Burada öyle olmamış; bu iyi bir veri kümesi değil, üzerinde çalışmak çok mantıklı olmayabilir.

## 2. Ödev Sunumları: BERT ile Yarı Eğiticili Öğrenme

> **Ek bilgi (derste anlatılmadı):** Sözde etiketleme (pseudo-labeling) ya da öz-eğitim (self-training), yarı eğiticili öğrenmenin basit bir türüdür. Etiketli veriyle eğitilen model etiketsiz verinin etiketlerini tahmin eder, güvenli görünen tahminler etiket gibi kabul edilip eğitim kümesine katılır ve model yeniden eğitilir. Yanlış sözde etiketler modele geri beslendiği için hatalar birikebilir; bu yüzden genelde yalnız yüksek güvenli tahminler alınır ve ekleme kademeli yapılır.

### 2.1 BERTurk ile sözde etiketleme

Bir sunumda BERTurk'ün önceden eğitilmiş parametreleri bir dizi sınıflandırma (sequence classification) modeline yüklendi. Sınıflandırma için BERT'in üzerine eklenen son katmanın parametreleri hazır olmadığı için ince ayar gerekiyordu; bunun için dersin paylaştığı yarışma eğitim verisi kullanıldı. Ardından etiketsiz yarışma test verisindeki 3 bin tweet için sözde etiketler belirlendi ve model bunlarla da eğitildi.

Deneyler sırasıyla şöyleydi. İşlem uzun sürdüğü için önce etiketli verinin %70'i eğitim için, kalanı doğrulama ve test için kullanıldı. Model geliştiricilerinin önerdiği epoch aralığı 1-4'tür. 4 epoch'ta model ince ayar sırasında aşırı öğrendi (overfit). Daha fazla veriyle (%90 eğitim, %10 doğrulama) denendiğinde yine aşırı öğrendi. Epoch sayısı 2'ye indirilince ince ayar tamamlandı. Yarı eğiticili aşamada da 4 epoch'ta training loss çok düşerken validation loss arttı ve doğruluk artmadı. 2 epoch'luk son deneyde (ekrandan, 00:40:00) training loss 0,23'ten 0,13'e indi, validation loss 0,76'dan 0,81'e çıktı, validation accuracy 0,76'dan 0,77'ye çıktı. Etiketli veriyle yalnız ince ayar ile sözde etiketli veri de eklenince elde edilen doğruluk arasındaki fark küçüktü (76'dan 77'ye).

Hoca deney düzenini sorguladı:

**Soru:** Elinde kaç etiketli, kaç etiketsiz veri var? 13 bini kullanınca ne oluyor, 16 bini (13 bin + 3 bin) kullanınca ne oluyor, karşılaştırma nerede? **Cevap:** Yaklaşık 13 bin etiketli ve 3 bin etiketsiz veri var; etiketli verinin %10'u test için ayrıldı. Yalnız ince ayarla doğruluk 76, sözde etiketli veri de eklenince 77 oldu.

> **Hocanın vurgusu:** 13 bin etiketli veri varken 3 bin etiketsiz veri eklemek gerçek durumun tersidir. Gerçekte etiketsiz veri çok, etiketli veri azdır. Deney daha az etiketli ve daha çok etiketsiz veriyle kurulmalıydı.

Sunan kişi, sözde etiketli verinin kalitesine de bakılabileceğini ekledi: sınıf aidiyeti olasılığı yeterince yüksek olmayan örnekler alınmayabilirdi. Hoca bu tür stratejilerin kullanılabileceğini, yarı eğiticili öğrenmenin önceki derslerde görülen türlerinde olduğu gibi 3000 örneğin tek seferde değil parça parça etiketlenip bir yere kadar ilerletilebileceğini hatırlattı; çünkü bir noktadan sonra başarı düşebiliyordu.

### 2.2 BERT vektörleri ve Random Forest ile sözde etiketleme

Başka bir sunumda yarışma eğitim verisi (13 bin örnek; yaklaşık 3 bin "diğer" sınıfı, 5'er bin civarında olumlu ve olumsuz) önce karıştırıldı. 4000 örnek etiketli, 4000 örnek etiketsizmiş gibi, 2000 örnek test olarak ayrıldı. Ön işlemde metin normalizasyonu ve URL silme gibi basit adımlar uygulandı. Her kısa metin BERT ile 768 boyutlu bir vektöre çevrildi; bu, bir cümleyi vektöre dönüştürmeye ve aynı zamanda bir transfer öğrenmeye karşılık geliyordu.

Adımlar:

- 4000 etiketli örnekle küçük bir Random Forest modeli eğitildi.
- Bu model etiketsiz 4000 örneği tahmin etti; sözde etiketli veri oluştu.
- 8000 örneklik büyütülmüş veriyle yeni bir Random Forest eğitildi.

Sonuçlar (ekrandan, 00:44:45):

| Model | Train Accuracy | Test Accuracy |
|---|---|---|
| Küçük veri seti ile eğitim | 0,9067 | 0,884 |
| Büyütülmüş veri seti ile eğitim | 0,9376 | 0,9140 |

Test başarısı yaklaşık 3 puan arttı; sunan kişiye göre bu, model tarafından etiketlenmiş verilerin eklenmesinin başarıyı artırdığını gösteriyor. Tek iterasyon yapılmıştı.

**Soru:** 4000'in hepsini birden kullanmak yerine iteratif bir yolla ilerlemek mümkün olmaz mıydı? **Cevap:** Hoca bunu önerdi: sözde etiketli örnekler biner biner eklenip geçiş izlenebilir ve bir yerde durulabilir; belki 4000'in hepsini değil 2000'ini katmak daha iyi sonuç verir. En azından ilerleme görülmüş olur.

## 3. Uygulamalar Bölümüne Giriş ve Metin Sınıflandırma

Aradan sonra hoca ders notlarının 6. bölümüne, "Uygulamalar"a geçti. Önceki derste sinirsel dil modelleri tamamlanmıştı. Bu bölümde çeşitli uygulamalar ve bu problemlere yayınlarda ne tür çözümler bulunduğu incelenecek. Slayttaki içerik (ekrandan, 01:10:00):

- Metin sınıflandırma
- Duygu durum analizi
- Varlık ismi tanıma
- Paragraf anlama
- Soru cevaplama
- Metinlerde çıkarım
- CNN ve RNN hakkında
- Metin / haber / hikaye / şiir üretimi
- Sohbet ve sanal asistan uygulamaları
- Ne yapayım diyenlere

Bu derste ilk iki konu işlendi.

Metin sınıflandırmayı herkes ödevlerde yapmıştı, hoca bu yüzden kısa geçti. Paylaşılan `text_classify_lsi.m` kodu 13 sınıflı haber metinlerini sınıflandırır (ekrandan, 01:10:20). Metinler LSI ile $13 \times 5 = 65$ boyutta ifade edilir. Normalde metinlerin boyutu en azından 3-5 bin civarındadır, LSI bunu 65'e indirir. Test örnekleri sabittir, her sınıf için 250 tanedir. Slayttaki grafikte yatay eksen eğitim örneği sayısı (0'dan 250'ye), dikey eksen test başarısıdır; eğitim örneklerinin sayısı arttıkça test başarısı yaklaşık %18-19'dan %50'ye çıkıyor. LSI yapmadan metinleri tf, binary, tf-idf, kelime ve n-gram olarak temsil eden sürüm de `text_classify_tfidf.m` kodunda vardır.

## 4. Duygu Durum Analizi

Duygu durum analizinin amacı bir firma, kişi, parti, kurum, olay vb. hakkında kamuoyu algısını ölçmektir (ekrandan, 01:11:20). Hoca bunun günümüzde yalnız fikir paylaşımıyla sınırlı olmadığını söyledi: algı yönetimi de temel olarak Twitter gibi ortamlar üzerinden yapılabiliyor. Algı operatörü botlar belli bir konuya dikkat çekmek ya da bir konuyu farklı biçimde düşündürmek için mesaj atıyor; slayta göre tahminen mesajların %20'si bu tür botlardan geliyor ve bunlara dikkat edilmeli.

Slayttaki diğer noktalar:

- Eğitim kümeleri genelde eskir.
- Metin temsilinde klasik yaklaşımlar: kelime, kelime kökü, n-gram.
- Yeni yaklaşımlar: semantik uzaylar, LSTM, CNN.
- Kodlar: `https://github.com/mfatihamasyali/sentiment_deep_or_classical`.

## 5. Metni Resim Gibi Görmek: Kelime ve Karakter Tabanlı CNN

### 5.1 CNN'i hatırlamak

Hoca, kelime vektörlerinin CNN ile nasıl kullanıldığını anlatmadan önce CNN'i bir çizimle hatırlattı. Elde bir resim (matris) vardır. Kernel ya da filtre denen küçük bir matris resmin üzerinde gezdirilir: soldan sağa ilerlenir, sonra bir satır alta geçilip yeniden soldan sağa ilerlenir. Bu, bilinen konvolüsyon işlemidir; filtre resmin üzerinde her yöne hareket edebilir.

### 5.2 Metni matrise çevirmek

Soru şudur: aynı işlem metinlere uygulanabilir mi? Bunun için metindeki kelimelerin vektörleri alınıp alt alta yazılır. Hocanın çiziminde dikdörtgenin yatay boyutu kelime vektörünün boyutudur (örneğin 300), dikey boyutu ise veri kümesindeki bir örneğin alabileceği maksimum kelime sayısıdır. Birinci satır birinci kelimenin vektörü, ikinci satır ikinci kelimenin vektörüdür. Kelime vektörleri word2vec gibi hazır kaynaklardan alınabilir ya da öğrenilebilir.

Böylece metin de bir resim, yani sabit boyutlu bir matris olur. Sütun sayısı zaten sabittir. Her metindeki kelime sayısı farklıdır ama bir maksimum kelime sayısı seçilir; daha kısa metinlerde kalan satırlar sıfırlarla doldurulur (padding).

Slayttaki makale düzeni (ekrandan, 01:12:20) bunu biçimsel olarak verir:

- M matrisi: metin ($n_m$ satır, $d_m$ sütun). $d_m$, kelimelerin temsil edildiği vektörlerin boyutudur.
- Metnin her bir kelimesine karşılık gelen vektörler metindeki sıralarıyla bu matrisin bir satırına yazılır.
- $n_m$ maksimum metin uzunluğudur. Bir metin bu değerden kısa ise matrisin geri kalan alt kısmı 0'larla doldurulur.
- M matrisinin üzerinde $t$ adet $k_m \times d_m$'lik filtre gezdirilir ve evrişim sonuçları F'de tutulur. F'nin her bir sütunu bir filtrenin sonuçlarını gösterir.
- Her bir sütunun maksimum değeri bulunup B vektörüne yazılır.
- B vektörü ile S çıkış vektörü arasında tam bağlı bir katman bulunur.

### 5.3 Filtreler nasıl gezdirilir ve ne öğrenir?

Hoca şunu sordu: bu matrisin üzerinde, resimlerdeki gibi $3 \times 3$'lük bir filtreyi her yöne gezdirmenin bir anlamı olur mu? Genelde çok anlamlı olmaz, çünkü böyle bir filtre kelimenin tamamını içermez. İmkânsız değildir, ama genelde yapılan şey $2 \times 300$'lük ya da $3 \times 300$'lük filtreler tasarlamak ve bunları yalnız aşağı doğru kaydırmaktır (matris transpoze edilmişse yana doğru). Konvolüsyon başka bir yöne gitmez.

Her filtrenin kayma sonuçları bir sütun oluşturur; başka bir filtre başka bir sütun üretir. Bunların hepsi birleştirilir, pooling yapılır ve en sonda çıkış vektörü bulunur. Kelime vektörleri word2vec'ten de gelebilir, metin BERT'e verilip BERT'ten gelen çıktılar da kullanılabilir; fark etmez, sonuçta metin bir resme dönüşür.

Filtrelerin anlamı şudur: $2 \times 300$'lük bir filtre ardışık kelime ikilileri üzerinde hareket eder ve ardışık kelime ikili örüntülerini yakalar. $3 \times 300$'lük bir filtre ardışık kelime üçlülerini yakalamaya çalışır. Yani filtreler, metindeki kısa kelime dizisi örüntülerini bulan sistemler gibi düşünülebilir.

> **Ek bilgi (derste anlatılmadı):** Bu mimari, literatürde genelde Kim'in "Convolutional Neural Networks for Sentence Classification" çalışmasıyla (büyük olasılıkla 2014) bilinen yapıya benzer. Her filtrenin çıktısının en büyük değerinin alınmasına "max-over-time pooling" denir; böylece metin uzunluğundan bağımsız, filtre sayısı kadar boyutlu bir vektör elde edilir.

### 5.4 Kelime tabanlı ve karakter tabanlı M matrisleri

Slayttaki örnek tweet "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah ." için iki M matrisi gösterildi; solda kelime vektörü tabanlı, sağda karakter tabanlı (ekrandan, 01:20:40).

Kelime vektörü tabanlı matriste "Allah" kelimesinin vektörü birinci satır, "cezanı" ikinci satır, "versin" üçüncü satır, "XXX" dördüncü satırdır. Cümlede 8 kelime ve muhtemelen bir nokta olduğu için 9 satır dolu; altı 40. satıra kadar boştur (sıfır). 40, bu derlemdeki tweet'ler için seçilen en uzun kelime sayısıdır; daha uzun olan tweet'lerin fazlası alınmaz. Ekrandaki matrisin yatay ekseni 100'e kadar gider.

Sağdaki matris karakter tabanlıdır. Kelimeler kodlanabildiği gibi karakterler de kodlanabilir; en basit yol one-hot kodlamadır. Bu veri kümesinde 82-83 farklı karakter vardı; her satırda o karakterin indisine 1 yazılır. İlk satır "A" harfinin kodu, ikinci ve üçüncü satır "l" harfinin kodudur; sonra yine "a", "h", boşluk vb. gelir. Satır sayısı en uzun tweet'in karakter sayısıdır; hoca bunun 140 küsur olduğunu söyledi, ekrandaki eksen 140'ın biraz üstüne gider. Bu yaklaşımda kelime vektörlerine (word2vec gibi) ihtiyaç yoktur.

Karakter matrisi de bir resim olduğu için üzerinde yine filtreler çalıştırılabilir. Örneğin $3 \times 85$'lik bir filtre ardışık üç karakter, yani karakter 3-gramları üzerinde çalışır.

### 5.5 Karşılaştırma sonuçları

Slayttaki tablo (ekrandan, 01:23:20):

| Yöntem | Elde edilen en yüksek başarı % |
|---|---|
| Kelime torbası | 66,28 |
| Karakter 3gram torbası | 66,92 |
| Kelime vektörü ortalamaları | 66,33 |
| Kelime bazlı uzun kısa süreli bellek ağları | 65,35 |
| Kelime bazlı evrişimsel sinir ağları | 67,14 |
| Karakter bazlı evrişimsel sinir ağları | 69,25 |

Slayt notu: son 3 yaklaşımın çok fazla hiperparametresi var. Bu veri kümesinde karakter bazlı CNN, kelime bazlı CNN'den daha başarılı oldu. Hoca, klasik yaklaşımların 65-66 civarında kaldığını, CNN gibi daha karmaşık yöntemlerle 67-69'a çıkıldığını söyledi. Bu tabloda BERT yoktur; BERT gibi harici veri kaynaklarını kullanan modellerle daha yüksek başarılara erişmek mümkündür.

<!-- BELİRSİZ: Hoca bu veri kümesinde BERT ile başarının "herhalde %75'lere" çıkabildiğini "yanlış hatırlamıyorsam" diyerek söyledi; değer slaytta yok. -->

> **Ders sonrası not:** Hoca anlatırken "karakter vektörü ortalamaları 66.33" dedi; slayttaki satır "Kelime vektörü ortalamaları"dır.

## 6. Duygu Durum Analizi Neden Zordur?

Slayttaki örnekler (ekrandan, 01:24:45):

- "Yemeğimi 5 dakikada getirdiniz çok teşekkürler."
- "Yemeğimi 55 dakikada getirdiniz çok teşekkürler"
- "2500 tl lik fatura için çok teşekkürler"

İlk iki metin arasında yalnız tek bir karakter farkı vardır, ama biri olumlu, diğeri olumsuz (ironik) bir şey söyler. Üçüncüsünün olumlu mu olumsuz mu olduğunu bilmek için hayat bilgisi gerekir. Hoca, böyle bariz örnekleri birbirinden ayırt edecek kadar çok eğitim örneği varsa sorun olmadığını, ama o kadar örneğe sahip olmanın pek mümkün olmadığını söyledi. Bu durumda önceki derslerde konuşulduğu gibi dış bilgi kaynaklarına ihtiyaç duyulabilir.

## 7. Proje Konularında Anlatılan Yöntemler

Dersin sonunda hoca, dönem projesi için önerdiği konuları anlattı (ekrandan, 01:30:00 ve 01:40:00). Aşağıda yalnız konuların akademik içeriği aktarılmıştır.

### 7.1 Yapay veri üretimi (veri zenginleştirme)

Elde bir veri kümesi varken içindeki örneklerden yeni örnekler üretmek istenir. Üç yöntem anlatıldı:

- **Back translation:** A dilindeki bir metin otomatik çeviri araçlarıyla B diline çevrilir, sonra yeniden A diline çevrilir. Sonuç birebir aynı olmayabilir (olabilir de, ama istenen o değildir); istenen, bir miktar farklı ama benzer anlamı taşıyan yeni bir metindir.
- **fastText ile kelime değiştirme:** Metinde rastgele bir kelime seçilir ve fastText vektörüne en yakın kelimeyle değiştirilir. Örneğin "bugün elma yedim" cümlesinde "elma" seçilir, en yakın kelime "armut" çıkarsa "bugün armut yedim" cümlesi elde edilir.
- **BERT önerileri:** BERT'in ön eğitiminde maskelenmiş kelime tahmini (masked word prediction) ve NSP vardı. Cümledeki bir kelime kapatılıp maske olarak BERT'e gönderilir ("ben bugün bir ... yedim"); BERT "yemek", "dayak" gibi öneriler verir. Orijinal kelimeden farklı olan, rastgele değil yüksek olasılıklı bir öneri seçilir.

Bu konuda incelenecek sorular: yapay veri kullanmak ile kullanmamak arasındaki fark, ne kadar yapay veri kullanılacağı (10 orijinal örnek varken 100 yapay örnek mantıklı mı, yoksa 2 tane mi üretilmeli), yöntemleri bir arada kullanmanın etkisi (back translation, fastText ve BERT önerileri birlikte yalnız BERT'ten iyi mi). Analizler en az 3 veri kümesinde sınıflandırma başarısı üzerinden yapılacaktır.

### 7.2 NER yapısıyla sebep-sonuç ve "ne, nerede" bilgisi

Klasik varlık ismi tanımada (Named Entity Recognition, NER) bir kelime dizisi girilir ve her kelime için bir etiket tahmin edilir. Hocanın gösterimi (ekrandan, 01:34:30):

```text
w1  w2  w3  w4  w5 ...
s1  i   b   b
```

Etiketler kişi ismi, şehir ismi, organizasyon ismi, para birimi, tarih, telefon numarası, e-posta adresi gibi türlerdir; bir kelime boş (hiçbir varlık değil) etiketi de alabilir. Hocanın önerisi, aynı yapıyı sebep-sonuç ya da "ne, nerede yapılır" bilgisini bulmak için kullanmaktır (ekrandan, 01:34:55):

```text
yağmur  yağınca  yerler  ıslandı
SE      SE       SO      SO

lokantada  yemek  yedim
NER        NE     NE
```

Burada SE sebep, SO sonuç, NER "nerede", NE "ne" etiketidir. Her cümlede sebep-sonuç ilişkisi olması gerekmez, olanlar işaretlenir. Yapının geri kalanı NER ile tamamen aynıdır; NER'i çözmek için kullanılan yöntemler aynen uygulanabilir. Zorluk veridedir: NER için hazır veri kümeleri vardır, bunun için yoktur. Hocanın önerisi, önceki derslerde toplanan sebep-sonuç ve ne-nerede kelime ikililerini internette (örneğin Twitter'da) aratıp ikisini birden içeren cümleleri indirmek ve bunları otomatik ya da yarı otomatik etiketlemektir; bir metni baştan sona elle işaretlemek çok zordur. Sonra model normal metinlerde bu ilişkileri bulabiliyor mu diye etiketli veride test edilir ve NER için kullanılan en az iki yöntem karşılaştırılır.

> **Ek bilgi (derste anlatılmadı):** NER'de çok kelimeli varlıkları işaretlemek için yaygın olarak BIO (IOB) şeması kullanılır: B- varlığın ilk kelimesini, I- devamını, O varlık dışı kelimeleri gösterir. Hocanın SE SE / SO SO gösterimi, aynı etiketin ardışık kelimelere verildiği daha sade bir biçimdir.

### 7.3 Diğer konular

- **Başlıktan haber, haberden başlık üretimi:** Haberlerin başlığı, özeti ve metni vardır. Başlık verilince haber özeti, özet verilince başlık üretilir (haber metinleri uzun olduğu için özet kullanılabilir). Bu bir metin üretme (text generation) problemidir; en az iki yöntem karşılaştırılır.
- **En benzer 10 cümleyi bulma:** 100 MB'lık bir Türkçe derlemde verilen bir cümleye en benzer 10 cümle bulunur ve en az 4 yöntem hem doğruluk hem hız açısından karşılaştırılır. Bir yöntem diğerlerinden çok daha doğru ama 10 kat daha yavaş olabilir. Bu bir metin getirme (text retrieval) işidir; klasik yöntemler de kullanılabilir.
- **Parafraz tespiti:** Kaggle'daki Quora Question Pairs verisinde her satırda iki soru ve bir etiket vardır; 1 iki sorunun aynı anlama geldiğini, 0 farklı anlama geldiğini gösterir. Bu bir parafraz üretme değil parafraz tespiti (paraphrase detection) verisidir. Eğitim verisi otomatik makine çevirisiyle Türkçeye çevrilip en az iki yöntem karşılaştırılır. Hocaya göre veri 150 bin civarında örnek içerir.
- **Film/dizi altyazılarıyla sohbet botu:** Altyazı derlemleri kullanılarak en az iki yöntemle sohbet botu oluşturulur; derlemlerin ve yöntemlerin başarıları karşılaştırılır.

### 7.4 İki boyutlu kelime gömmeleri

Bu konu, metni resim olarak görme fikrinin devamıdır (ekrandan, 01:44:30). Klasik yapıda metin $x$ satır ve 100 sütunlu bir matristir; her satır 100 sayıdan oluşan, bir kelimeyi temsil eden $1 \times 100$'lük bir vektördür. Üzerinde $2 \times 100$'lük ya da $3 \times 100$'lük filtreler gezdirilir.

Önerilen fikirde bir kelime $1 \times 100$'lük bir vektör yerine $10 \times 10$'luk bir matristir; yine 100 sayı içerir ama iki boyutludur. Metin bu matrislerin yan yana (ya da transpozu biçiminde alt alta) dizilmesiyle oluşur:

```text
metin: (x satır * 100 sütun)
1 kelime = 1*100  ->  10*10
(10*10) (10*10) ... (10*10)
```

Bu durumda, resimlerdeki gibi $3 \times 3$'lük, $4 \times 4$'lük, $5 \times 5$'lik filtreler gezdirilebilir. Önceki yapılarda filtreler hep kelimenin tamamını içeriyordu ($3 \times 300$, $2 \times 100$ gibi); burada kelime vektörünün yalnız bir parçasına bakan filtreler üretilebilir. Bunun için iki boyutlu bir kelime gömme katmanı (word embedding layer) oluşturmak ve eğitmek gerekir; hazır bir katman alınıp değiştirilir. Genel gösterimle $1 \times d$ boyutlu standart gömmeler ile $k \times k$ boyutlu gömmeler ($d = k^2$) karşılaştırılır; $x \times d$'lik filtreler yerine $g \times g$'lik CNN filtreleri gezdirilir. Etki iki veri kümesinde gösterilir.

**Soru:** Projeler doğal dil işlemeyle mi ilgili olmalı, başka tür veriler kullanılabilir mi? **Cevap:** İşin içinde metin (text) olması şarttır; örneğin hem resim hem metin içeren çok kipli (multimodal) uygulamalar olabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:16:45): Kelime vektörlerinin alt alta yazılmasıyla elde edilen metin matrisinin üzerinde $3 \times 3$'lük bir filtreyi resimlerdeki gibi her yöne gezdirmenin bir anlamı olur mu? Neden?

> **Çözüm:** Genelde çok anlamlı olmaz. $3 \times 3$'lük bir filtre kelime vektörünün yalnız küçük bir parçasını görür, kelimenin tamamını içermez. Bu yüzden filtreler $k \times d$ boyutunda tasarlanır (örneğin $2 \times 300$, $3 \times 300$) ve yalnız aşağı doğru kaydırılır; böylece her filtre $k$ ardışık kelimenin tamamına bakar.

**Soru 2** (derste sözlü, 01:18:43): Metin CNN'inde $2 \times 300$'lük ve $3 \times 300$'lük filtreler ne anlatır?

> **Çözüm:** $2 \times 300$'lük filtre ardışık kelime ikilileri üzerinde hareket eder ve ikili kelime örüntülerini yakalar; $3 \times 300$'lük filtre ardışık kelime üçlülerini yakalar.

**Soru 3** (derste sözlü, 01:22:20): Karakterlerin one-hot kodlandığı matriste $3 \times 85$'lik bir filtrenin anlamı nedir?

> **Çözüm:** Ardışık üç karakter, yani karakter 3-gramları üzerinde çalışan bir filtredir.

**Soru 4** (ekrandan, 01:24:45): "Yemeğimi 5 dakikada getirdiniz çok teşekkürler" ile "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" cümleleri duygu durum analizinin neden zor olduğunu nasıl gösterir?

> **Çözüm:** İki metin arasında tek karakter fark vardır ama biri olumlu, diğeri ironik olarak olumsuzdur. Ayırt etmek için dünya bilgisi (5 dakika hızlı, 55 dakika yavaş) ya da bu tür örnekleri ayıracak kadar çok eğitim örneği gerekir.

**Soru 5** (ekrandan, 01:12:20): Duygudurum analizi denemesindeki tabloda satır ve sütun toplamları tutarlı mı?

> **Çözüm (derste verilmedi):** Satır toplamları tutarlıdır: $3663 + 5511 + 4658 = 13832$, $916 + 1377 + 1164 = 3457$, $13832 + 3457 = 17289$. Sütunlarda olumlu $3663 + 916 = 4579$ ve nötr $4658 + 1164 = 5822$ doğrudur, ama olumsuz sütun $5511 + 1377 = 6888$ olmalıdır; slaytta 6887 yazıyor. $4579 + 6888 + 5822 = 17289$ ile genel toplam da tutarlı olur (python ile hesaplandı).

**Soru 6** (derste sözlü, 00:25:36): Belirsizliğe dayalı aktif öğrenmede çok sınıflı bir veride bir sınıftan neredeyse hiç örnek seçilmemesi neden olabilir, nasıl önlenir?

> **Çözüm:** Hocanın cevabına göre bir sınıfın örnekleri diğerlerinden daha kolay ya da daha zor olabilir; tek bir belirsizlik sıralaması yapılınca o sınıfın örnekleri başlarda hiç seçilmez ve model o sınıfı az öğrenir. Çözüm, sıralamayı her sınıf içinde ayrı yapmak ve yeni eklenen örneklerin orijinal eğitim kümesindeki sınıf oranlarını aşağı yukarı korumasını sağlamaktır.

**Soru 7** (derste sözlü, 00:40:43): 13 bin etiketli ve 3 bin etiketsiz örnekle yapılan bir yarı eğiticili öğrenme deneyinde düzen açısından sorun nedir?

> **Çözüm:** Oran gerçek durumun tersidir. Yarı eğiticili öğrenmenin kullanıldığı gerçek durumda etiketsiz veri çok, etiketli veri azdır; deney az etiketli ve çok etiketsiz veriyle kurulmalıdır. Sözde etiketli veri de tek seferde değil kademeli eklenmelidir.

**Soru 8** (derste sözlü, 01:43:30): Kelimeler $1 \times 100$ yerine $10 \times 10$'luk matrislerle temsil edilirse metin nasıl bir yapıya dönüşür ve bunun ne yararı olabilir?

> **Çözüm:** Metin, $10 \times 10$'luk kelime matrislerinin yan yana (ya da alt alta) dizilmesiyle oluşan bir resme dönüşür. Böylece resimlerdeki gibi $3 \times 3$, $4 \times 4$, $5 \times 5$'lik filtreler gezdirilebilir ve kelime vektörünün tamamına değil bir parçasına bakan filtreler öğrenilebilir. Bunun için iki boyutlu gömme katmanının eğitilmesi gerekir.

## Dersin Toparlaması

Dersin ilk yarısında BERT'in aktif öğrenme ve yarı eğiticili öğrenmeyle birlikte kullanıldığı ödevler tartışıldı. Belirsizlik örneklemesi (margin, olasılık aralığı ya da varyans ölçütüyle) bazı veri kümelerinde ilk iterasyonlarda rastgele seçimden daha iyi ve tutarlı sonuç verdi, bazılarında vermedi. Hocanın ana uyarıları şunlardı: seçimde sınıf dağılımı korunmalı; yarı eğiticili deneylerde etiketsiz veri etiketliden çok olmalı ve sözde etiketli örnekler kademeli eklenmeli; etiketli veri arttıkça başarı artmıyorsa veri ya da deney sorgulanmalı. Özellik tabanlı kullanımda en iyi [CLS] temsilinin son katmandan değil, göreve göre 10. ya da 3. katmandan gelebildiği görüldü.

İkinci yarıda "Uygulamalar" bölümüne geçildi. Metin sınıflandırmada LSI ile boyut indirgeme, duygu durum analizinde kamuoyu algısı ölçümü ve bot mesajları ele alındı. Metnin, kelime vektörleri ya da one-hot karakterler alt alta yazılarak bir resme dönüştürülebileceği, üzerinde $k \times d$'lik filtrelerin aşağı doğru kaydırıldığı CNN yapısı anlatıldı; bir duygu analizi denemesinde karakter bazlı CNN %69,25 ile en iyi sonucu verdi. İroni ve dünya bilgisi gerektiren örnekler duygu analizinin zorluğunu gösterdi. Son olarak proje konuları üzerinden veri zenginleştirme (back translation, fastText, BERT maske önerileri), NER yapısıyla sebep-sonuç çıkarımı, metin getirme, parafraz tespiti ve iki boyutlu kelime gömmeleri fikirleri tanıtıldı. İçerik slaytındaki diğer uygulamalar (varlık ismi tanıma, soru cevaplama, metin üretimi vb.) sonraki derslerin konusudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
