# Ders 12 Genişletilmiş Notu: Makine Öğrenmesinde Yeni Problemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konusu ve Önemi
- 2. Aktif Öğrenme
- 3. Yarı Eğiticili Öğrenme
- 4. Öğrenmenin Transferi
- 5. Çok Görevli Eğitim
- 6. Hiperparametre Optimizasyonu
- 7. Aktif Örnekleme
- 8. İnsan-Makine İşbirliği
- 9. Az Sayıda Örnekle Eğitim: One-shot ve Zero-shot
- 10. Veri Zenginleştirme
- 11. Makine Öğrenmesi Algoritmalarını Kandırmak
- 12. Planlı Öğrenme
- 13. Hayat Boyu Öğrenme
- 14. Proje Soru-Cevaplarından Akademik Noktalar
- Örnek Sorular

## 1. Dersin Konusu ve Önemi

Bu dersin konusu "makine öğrenmesinde yeni problemler"dir. Slaytların kapağında "ML v2" yazıyordu; altbilgileri "Hesaplamalı Anlambilim Ders Notları"dır, yani slaytlar başka bir dersin notlarından alınmıştır (ekrandan, 00:15:00). Konuların bir kısmı daha eski olsa da hepsi makine öğrenmesinde önemli ve aktif araştırma alanlarıdır.

Hocaya göre bu alanları bilmek yüksek lisans ve doktora tezleri için faydalıdır. Örneğin tez konusu doğrudan aktif öğrenme olmayabilir, ama tezdeki problemde aktif öğrenme kullanılabilir. Bazı konular için hocanın yazdığı kodlar dersin sayfasında paylaşılmıştır.

## 2. Aktif Öğrenme

### 2.1 Tanım ve amaç

Klasik öğrenmede eğitim kümesindeki örneklerin hem özellikleri hem etiketleri bellidir. Aktif öğrenmede (active learning) ise eğitim örneklerinin özellikleri bellidir ama etiketleri başta bilinmez. Algoritma etiketini istediği örnekleri seçer, kullanıcı bu örneklerin etiketlerini verir; algoritma yeni örnekler ister, kullanıcı yine verir ve bu süreç bir noktada durur (ekrandan, 00:15:00).

Amaç veri etiketleme maliyetini azaltmaktır. Örneğin bir milyon örneğiniz varsa hepsini etiketlemeye gücünüz yetmeyebilir, bir kısmını etiketleyebilirsiniz. Soru, hangi kısmın etiketleneceğidir. Bu kısım rastgele seçilebilir; aktif öğrenme ise onu akıllıca seçmeye çalışır.

Slayttaki yöntem tanımı şöyledir: tüm eğitim seti yerine bir kısmını kullanmak; belirli bir test seti üzerinde, tüm eğitim setini kullanmış olmaya göre benzer, kabul edilebilir derecede düşük ya da daha yüksek başarı elde etmek. Hoca, daha yüksek başarının özellikle veride gürültü olduğunda mümkün olduğunu ekledi.

### 2.2 Adımlar

Slayttaki adımlar (ekrandan, 00:20:00):

- A: Küçük bir eğitim setiyle (E) başla. Eğitim kümesinin az bir kısmının etiketlerini iste.
- B: Bir model üret. Bu modele göre etiketsiz eğitim örneklerine (EE) dair tahminlerini üret.
- C: Bu tahminlere göre bu örneklerden bir kısmını seç (tahmin varyasyonuna göre) ve etiketlerini iste. Seçilenleri EE'den çıkar, E'ye ekle.
- B ve C adımlarını tekrar et.

Başlangıç kümesi rastgele seçilebilir ya da bir ilklendirme yapılabilir, örneğin kümeleme yapılıp her kümeden bir örnek seçilebilir. Örnek olarak tüm örneklerin %5'i ile başlamak verildi. B adımında üretilen tahminlerin doğru olup olmadığı bilinmez, çünkü bu örneklerin gerçek etiketleri bilinmemektedir. Süreç en fazla bütün örneklerin etiketi alınana kadar sürer; ama amaç daha az etiketle yetinebilmektir.

### 2.3 Tahmin varyasyonuna göre seçim

Tahminin gerçeği bilinmeden seçimin nasıl yapılacağını hoca bir soruyla açıkladı. İki sınıflı bir problemde model bir örnek için "%90 A, %10 B", başka bir örnek için "%51 A, %49 B" diyor olsun. Hangi örneğin etiketini öğrenmek modele daha çok katkı sağlar?

Birinci örnekte model kararından epey emindir, ikincisinde karar ortadadır. Modeli iyileştirmek için ikinci örneğin etiketine bakmak gerekir. Model, kendisine göre en belirsiz etiket dağılımına sahip örnekler eklenerek değiştirilir. Bunun tersi de yapılabilir: %90'a %10 gibi örnekler model için kolay, 51'e 49 gibi sınırda olanlar zordur. Dolayısıyla önce kolay örnekleri ya da önce zor örnekleri seçmek iki ayrı strateji olarak düşünülebilir.

Hoca, Iris veri kümesi olduğunu tahmin ettiği üç sınıflı bir görsel gösterdi. Mevcut etiketli eğitim kümesi üçgenlerle, seçilen yeni örnekler yuvarlaklarla gösteriliyordu. Seçilen örnekler, birbirine çok yakın olan iki sınıfın (kırmızı ve sarı) etiketli örneklerinin arasındaki bölgedeydi. Diğer sınıftan uzak olan bölgeden örnek seçilmemişti, çünkü model oradaki örnekler için büyük olasılıkla tek bir sınıf diyordu.

### 2.4 Aktif öğrenmenin soruları

Hoca slayttaki soruları tek tek ele aldı (ekrandan, 00:25:00):

- İlk eğitim seti (E) nasıl seçilebilir? Önemi var mı? Önemi vardır. Bu global bir optimizasyon problemi olmadığı için başlangıç yeri varılacak yeri epey etkiler. Rastgele seçim bir yaklaşımdır; kümeleme yapıp her kümeden bir örnek almak da geçerlidir.
- EE'deki örneklerin sınıflandırma problemlerinde tahmin varyasyonu nasıl hesaplanır? Algoritmaların verdiği sınıf olasılıkları (confidence değerleri) kullanılır. Bu olasılıklar birbirine ne kadar yakınsa tahmin o kadar kararsızdır. Örneğin üç sınıf için %34, %33, %33 diyen model karar verememiştir; örnek mevcut modelin sınırlarına yakındır ve o bölgeden alınan bir etiket sınırı değiştirir.
- Tahmin varyasyonu regresyon problemlerinde nasıl ölçülebilir? Hoca varyans üzerinden bir düşünce yapılabileceğini söyleyip soruyu düşünülmek üzere açık bıraktı.
- Tahmin varyasyonu çok (zor) mu, az (kolay) mı olan örnekler seçilmeli? Bu soru deney sonuçlarıyla cevaplandı (bkz. 2.5).
- B ve C adımlarının tekrarı ne zaman durmalı? Bir bütçe sınırı olabilir. Örneğin her etiketleme bir dolarsa ve yüz bin dolarınız varsa yüz bin örneğe erişince durursunuz.
- C adımında ne kadar örnek eklenmeli? Eğitim kümesini küçük küçük mü, büyük parçalarla mı büyütmek gerekir? Hoca bunların her birinin aktif öğrenmenin bir hiperparametresi olduğunu söyledi.

### 2.5 Deney sonuçları

UCI veri kümelerinde yapılan deneylerin grafiklerinde x ekseni zamanı, yani etiketli eğitim kümesinin büyüklüğünü gösteriyordu. En son noktada bütün örnekler etiketli hâle geldiği için iki yöntemin eğitim kümesi aynıdır ve başarıları da aynı çıkar; farklar ara noktalarda oluşur. Eğitim kümesi büyüdükçe test başarıları genel olarak artar.

Önce kolay örneklerin eklendiği aktif öğrenme (mavi) ile rastgele ekleme (turuncu) karşılaştırıldığında, rastgele ekleme genel olarak daha yukarıda çıktı. %90'a %10 gibi tahmin edilen örneklerin etiketini öğrenmek modele hızlı fayda sağlamaz.

Önce zor örneklerin eklendiği aktif öğrenme (mavi) ise çoğu veri kümesinde rastgeleden daha yukarıda çıktı ve süreci daha hızlı ilerletti. Daha hızlı, daha az etiketle aynı sonuca varmak demektir. Hoca bazı grafiklerde eğitim kümesinin dörtte biri ya da yarısının etiketleriyle yeterli başarıya erişildiğini gösterdi.

Slayttaki bulgular (ekrandan, 00:30:00):

- Önce kolay örnekleri eklemek iyileştirmiyor.
- Önce zor örnekleri eklemenin yararlı olduğu veri kümeleri var.
- Bazı veri kümelerinde tüm eğitim örnekleri yerine daha az örnekle daha yüksek test başarılarına erişilebiliyor.

Hoca son bulgunun büyük olasılıkla veride gürültülü örnekler bulunmasından kaynaklandığını, gürültülü verileri eklemenin süreci iyileştirmediğini söyledi. Slaytta daha fazlası için "Human-in-the-Loop Machine Learning" kitabına bağlantı verilmişti.

## 3. Yarı Eğiticili Öğrenme

### 3.1 Tanım

Yarı eğiticili öğrenme (semi-supervised learning), modelin oluşturulmasında etiketli verilerin yanında etiketsiz verilerin de kullanıldığı problemlerdir (ekrandan, 00:35:00). Aktif öğrenmeden farkı, etiketsiz verilerin etiketlerinin kullanıcıdan alınmamasıdır. Temel fikir şudur: elde hem etiketli hem etiketsiz veri varsa, belirli bir test seti üzerinde sadece etiketli verileri kullanmak yerine etiketsizleri de kullanmak daha iyi olur.

Hoca bunun her zaman tutmayacağını, ama fikir vermesi açısından klasik örneğin en güzeli olduğunu söyledi. Elde iki etiketli örnek (bir beyaz, bir siyah) varsa, sadece bunlara bakarak aralarından düz bir sınır çizilir. Yanında gri renkli, etiketi bilinmeyen ve iki kıvrımlı küme oluşturan etiketsiz örnekler de varsa, sınırın bu iki kümenin arasından kıvrılarak geçmesi daha mantıklıdır. Böyle bir sınır üretebilmek için bir kümedeki etiketsizlerin hepsini siyah, diğerindekilerin hepsini beyaz olarak tahmin etmek gerekir.

### 3.2 Etiketsiz veri neden değerli?

Etiketli veriye ulaşmak pahalı, etiketsiz veriye ulaşmak ise birçok senaryoda ucuzdur. Hoca ilaç geliştirmeyi örnek verdi. Bir molekülün ilaç olup olamayacağını anlamak için önce basit simülasyonlar, sonra daha gerçekçi denemeler, sonra hayvan deneyleri ve en son insan deneyleri yapılır; moleküller bu aşamalarda elenir. Bir molekülün "işe yaradı / yaramadı", "toksik etki gösterdi / göstermedi" etiketini bulmak için milyonlarca dolar harcanır. Hocanın verdiği bilgiye göre klasik manada bir ilacın piyasaya sürülmesine kadarki harcama 800 milyon dolar civarındadır ve bunun büyük kısmı bu etiketleri elde etmenin maliyetidir. Hoca, pahalı ilaçların pahalılığının etken maddelerden değil, bu araştırma süreçlerinin maliyetinden kaynaklandığını söyledi. Bu yüzden etiketsiz veriden yararlanabilmek çok değerlidir.

### 3.3 Etiketsiz örneklerin sınıfları nasıl tahmin edilir?

İlk akla gelen yol, her gri noktayı en yakın etiketli noktanın sınıfına atamaktır. Ancak örnekte yalnız iki etiketli nokta olduğu için bu, iki noktanın tam ortasından geçen düz bir çizgi çizmekle aynı sonucu verir. Çizginin bir tarafındakiler siyah, diğer tarafındakiler beyaz olur ve bu işe yaramaz.

Bu yüzden genelde iteratif yaklaşımlar kullanılır. Önce etiketli noktalara en yakın olan noktalar etiketlenir; sonra yeni etiketlenenlere en yakın olanlar, sonra onlara en yakın olanlar etiketlenir. Etiket bu şekilde adım adım yayılırsa kıvrımlı kümelerden birinin tamamı siyah, diğerinin tamamı beyaz yapılabilir. Hoca bunun bu örneğe özel olduğunu, ama aktif öğrenmede olduğu gibi işin iteratif ilerletilmesinin çok daha mantıklı olduğunu ve tek seferde yapmanın efektif olmadığının görüldüğünü söyledi. Regresyon problemlerinde tahminlerin nasıl hesaplanacağını düşünmeye bıraktı.

Slayttaki diğer sorular şunlardı: etiket tahminleri tek seferde mi iteratif mi yapılmalı; iteratif yöntemde etiketlerin toplamda ne kadarı tahmin edilmeli; her iterasyonda etiketlerin ne kadarı tahmin edilmeli.

### 3.4 Kod ve deneyler

`semi_supervised_learning.m` kodunun çıktısında (ekrandan, 00:40:00) yıldızlar etiketli eğitim örneklerini, yuvarlaklar etiketi tahmin edilen eğitim örneklerini gösteriyordu. Alt sırada üç grafik vardı: orijinal etiketler, orijinal + batch semi-supervised ile tahmin ve orijinal + iteratif semi-supervised ile tahmin. Batch yöntemde bazı noktalar sarı sınıfa atanmışken iteratif yöntemde aynı noktalar kırmızıya atanmıştı.

Deney grafiklerinde mavi çizgi supervised durumu, yani bütün örneklerin etiketleri elde varmış gibi eğitimi gösteriyordu. Kırmızı batch, sarı iteratif yarı eğiticili öğrenmeydi. Hoca supervised başarısını geçmenin kolay olmadığını, ama orijinal etiketler yerine bu şekilde etiketlenmiş örnekleri kullanmanın işe yaradığı durumlar olabileceğini söyledi. Bazı veri kümelerinde iteratif yöntem batch'ten daha iyiydi, örneğin segment veri kümesinde ise tek seferde tahmin daha iyi çıktı.

Sonuç olarak tahmini etiketleri hiç kullanmamanın, tek seferde tahmin etmenin ve iteratif tahminin her birinin diğerlerinden daha iyi olduğu sonuçlar vardır. İteratif tahminde kritik nokta nerede durulacağıdır: en sona kadar gitmek yerine bir yerde kesildiğinde daha yüksek başarılara erişilebilir.

## 4. Öğrenmenin Transferi

Öğrenmenin transferi (transfer learning), bir problemi çözdükten sonra benzer başka bir problemi sıfırdan çözmek yerine önceki verileri, modelleri ve parametreleri gerekirse dönüştürerek kullanmaktır. Beklenen fayda, yeni problemi sıfırdan çözmeye göre daha az maliyet (daha az süre, daha az hesaplama) ya da transfer yapılmadan elde edilecek çözümden daha başarılı bir çözümdür. Yaygın kullanımı ilk olarak görüntü işlemede başlamıştır.

Transfer edilebilecekler şunlardır: veriler, tüm model, metinler için kelime vektörleri, resimler için CNN filtreleri ve çıktıları (ör. ResNet ya da VGG çıktılarıyla resimleri temsil etmek). Başka bir modelin öğrenilmiş ağırlıkları kendi modelinize konup eğitime oradan devam edilebilir. Transfer özellikle az etiketli veri olan veri kümelerinde daha hızlı öğrenmeyi sağlar.

Slayta göre transfer şu durumlarda işe yarar (ekrandan, 00:45:00):

- Eldeki yeni problem için yeterli veri yoksa. Yeterli veri varsa transfere gerek kalmaz.
- Eski ve yeni problem ilgili ise. Problemler birbirinden tamamen bağımsızsa transferden çok fayda sağlanmaz.

Slayttaki grafikte transfer performansı görevlerin ilgililiğine (task relatedness) göre çizilmişti. "Aggressive" çok fazla bilgi transferini gösterir: görevler ilgiliyse kazanç büyük, ilgisizse kayıp da büyüktür. "Safe" çizgisi daha temkinlidir. Slaytta benzer bir karakteristiğin yarı eğiticili öğrenme için de söylenebileceği yazıyordu.

Hoca görüntü işlemede şuna dikkat çekti: ağların ilk katmanları çizgi var mı, köşe var mı gibi alana bağlı olmayan özellikler üretir. Bu katmanlardaki bilgi başka alanlara rahatça transfer edilebilir. Son katmanlara gelindikçe özellikler veri kümesine özgüleşir. ImageNet'te sınıf olasılıklarını veren son katmanı başka bir yerde kullanmanın anlamı yoktur, çünkü o yalnız ImageNet sınıfları için öğrenilmiştir; softmax'tan bir önceki katmanı almak ise sık kullanılan bir yaklaşımdır.

## 5. Çok Görevli Eğitim

### 5.1 Transferden farkı

Transferde bir kaynak görev (source task) için model oluşturulur, sonra o modeldeki bir şeyler başka bir problem için kullanılır. Çok görevli eğitimde (multitask learning) ise birden fazla görev aynı yapı içinde eş zamanlı öğrenilir; örneğin hem satranç hem dama oynamayı öğrenen bir sistem.

Görüntü örneğinde aynı resim için segmentasyon yapmak, nesneleri ayrı ayrı bulmak ve resmin derinlik bilgisini çıkarmak ayrı görevlerdir. Bunların hepsi tek bir mimari içinde aynı anda öğrenilirse görevler birbirinin öğrenmesine yardım eder. Bu yüzden tek bir kayıp yerine farklı görevler için tanımlanmış kayıpların hepsinin birleşiminden bir çok görevli kayıp (multitask loss) hesaplanır ve geriye yayılır.

NLP alanında NLP Decathlon (decaNLP) örneği verildi. Makine çevirisi, varlık ismi tanıma (NER), metin sınıflandırma, soru cevaplama, sözcük türü etiketleme (POS tagging), anlam belirsizliği giderme gibi farklı görevler soru-cevap biçiminde ortak bir formata dönüştürülür ve hepsi aynı modelle çözdürülmeye çalışılır. Varsayım, görevlerin birbirinden bir şeyler öğrenebileceğidir: bir görev için örnek sayısı azsa, başka görevler için bol olan örnekler o göreve de faydalı olabilir.

### 5.2 Hocanın deneyi

Hoca `multi_task_learning.m` koduyla bir deney yapmıştı: 2 boyutlu, 2 sınıflı 5 veri kümesi için 10 gizli nöronlu tek bir YSA, eşit eğitim süresi, 3 deneme (ekrandan, 00:50:00). Tek başına eğitimde her veri kümesi için ayrı bir ağ eğitilir. Çok görevli eğitimde beş veri kümesinin örnekleri birleştirilip tek bir veri kümesi yapılır. Bu durumda her örneğin hangi veri kümesinden geldiğini belirten bir kodun hem eğitim hem test örneklerine eklenmesi gerekir; yoksa veri kümeleri birbirine karışır.

Ekrandaki sonuçlar şöyledir (her satırda 5 veri kümesinin başarısı; `single` tek başına, `multi` çok görevli, `tr` eğitim başarısı, `acc` test başarısı):

```text
Deneme 1
single_tr_acc = 1.0000  0.5875  0.8462  0.9714  0.7663
single_acc    = 0.9067  0.5017  0.6923  0.9771  0.7554
multi_tr_acc  = 0.9333  0.5611  0.7483  0.9657  0.7609
multi_acc     = 0.8667  0.4785  0.7343  0.9656  0.7935

Deneme 2
single_tr_acc = 1.0000  0.5479  0.8671  0.9771  0.7989
single_acc    = 0.9467  0.5050  0.7063  0.9656  0.7228
multi_tr_acc  = 0.8133  0.5446  0.7692  0.9600  0.7935
multi_acc     = 0.7200  0.4983  0.7413  0.9656  0.7446

Deneme 3
single_tr_acc = 0.9733  0.5380  0.8112  0.9686  0.7935
single_acc    = 0.9200  0.4521  0.6783  0.9656  0.7772
multi_tr_acc  = 0.9600  0.4785  0.7692  0.9571  0.7446
multi_acc     = 0.9600  0.4884  0.7203  0.9570  0.7772
```

Hoca test başarılarını veri kümesi veri kümesi okudu:

- 1. veri kümesi: 0.9067'den 0.8667'ye ve 0.9467'den 0.7200'e düştü; üçüncü denemede 0.9200'den 0.9600'e çıktı.
- 2. veri kümesi: 0.5017'den 0.4785'e ve 0.5050'den 0.4983'e düştü, 0.4521'den 0.4884'e çıktı; başarılar zaten şans düzeyine yakın.
- 3. veri kümesi: üç denemenin üçünde de iyileşme var (0.6923'ten 0.7343'e, 0.7063'ten 0.7413'e, 0.6783'ten 0.7203'e).
- 4. veri kümesi: 0.9771-0.9656, 0.9656-0.9656, 0.9656-0.9570; anlamlı bir fark yok.
- 5. veri kümesi: 0.7554'ten 0.7935'e, 0.7228'den 0.7446'ya, 0.7772-0.7772; bir tık iyileşme.

> **Ders sonrası not:** Altyazıda hocanın 3. veri kümesi için okuduğu değerler "79, 73" gibi geçiyor; ekrandaki tabloya göre ilk çift 0.6923 ve 0.7343'tür. Değerler tablodan alınmıştır. Python ile hesaplanan üç denemenin ortalama test başarıları tek başına eğitim için 0.9245, 0.4863, 0.6923, 0.9694, 0.7518; çok görevli eğitim için 0.8489, 0.4884, 0.7320, 0.9627, 0.7718'dir.

Hocanın dikkat çektiği nokta şudur: görüntü ve NLP örneklerinde görevler birbiriyle ilişkilidir, ama bu deneyde UCI'den alınan beş veri kümesinin birbiriyle hiçbir ilgisi yoktur. Buna rağmen beş ayrı ağ yerine tek ağ eğitildiğinde bazı veri kümelerinde iyileşme görülmesi enteresandır. Hoca, 5 veri kümesi ve 3 denemenin genel bir şey söylemek için az olduğunu belirtti. Slayttaki "Bulgu-Yorum" kısmında iyileşmenin olduğu veri kümeleri olduğu, genel bir şey söylemek için daha fazla deneme gerektiği, bir ağın kaç problemi kapsayabileceği ve ağın karmaşıklığı artarsa ne olacağı soruları yer alıyordu. Hoca bir soru daha ekledi: veri kümelerinin sınıf sayısı aynı olsa bile boyut sayıları çok farklı olabilir (biri 3, biri 300 boyutlu); bunlar aynı ağa nasıl konup birlikte eğitilir? Hocaya göre bu, araştırması zevkli olabilecek bir alandır.

## 6. Hiperparametre Optimizasyonu

Hiperparametreler, algoritmanın kendisinin bulamadığı ve kullanıcıdan beklediği parametrelerdir. Özellikle derin öğrenme mimarilerinde çok sayıda hiperparametre vardır ve değerleri bir veri kümesindeki performansı epey etkiler. Bu yüzden bir mimari, denenmiş tek bir hiperparametre konfigürasyonunda iyi çalışmadı diye "bu veri kümesinde bu yapı çalışmıyor" denemez; bir hiperparametre araması yapmak gerekir.

Üç yaklaşım anlatıldı:

- Izgara (grid) arama: sistematik aramadır. Her hiperparametre için denenecek değerler belirlenir (ör. learning rate için binde beş, yüzde beş gibi) ve bunların oluşturduğu iki, üç ya da daha çok boyutlu ızgaranın noktaları tek tek taranır. Sürekli bir arama pratikte mümkün olmadığı için belirli noktalar seçilir.
- Rastgele arama: konfigürasyonlar rastgele oluşturulur ve bunlarla arama yapılır.
- Bayesçi optimizasyon: eldeki deneme sonuçlarına göre en fazla iyileşmeyi sağlayabilecek değer tahmin edilir.

Bayesçi optimizasyonu hoca tek bir hiperparametre üzerinden anlattı. Üç değer için deneme yapılıp üç sonuç elde edilmiş olsun. Yöntem, iki deneme noktası arasında fonksiyonun düz bir çizgi gibi gitmediğini, bir miktar yukarı çıkıp inebileceğini varsayar. Buna göre bir sonraki denemenin en çok iyileşme beklenen yerde yapılmasını önerir. O noktada deneme yapılır, sonuç eldeki denemelere eklenir ve bir sonraki nokta yine bu denemelere göre seçilir. Yani arama sistematik ya da rastgele değil, eldeki verilere dayanarak ilerler. 10 hiperparametre varsa bu optimizasyon 10 boyutlu bir uzayda yapılır.

## 7. Aktif Örnekleme

Aktif örnekleme (active sampling), aktif öğrenmeden farklıdır. Aktif öğrenmede elde özellikleri bilinen ama etiketi bilinmeyen örnekler vardı ve bunlardan hangisinin etiketinin isteneceğine karar veriliyordu. Aktif örnekleme ise Bayesçi optimizasyondan esinlenir: kullanıcıdan input uzayı için yeni örnekler istenir. Yani "bana şu noktada bir örnek üret ve etiketini söyle" denir (ekrandan, 01:15:00). Örneklerin kendileri (input ve çıkış) istenir.

> **Hocanın vurgusu:** Aktif öğrenme etiketleme sürecini, aktif örnekleme ise veri toplama sürecini optimize etmeye çalışır.

Slayttaki "Experimental Design by Bayesian Optimization" şemasında başlangıç eğitim kümesiyle Bayesçi bir model tahmin üretir; tahminin belirsizlik bandı en geniş olan yerde deney ya da simülasyon yapılır, sonuç eklenip model yeniden tahmin yapar. Regresyon problemi olarak düşünülürse tahminlerin alt ve üst sınırları vardır. Varyansın yüksek olduğu bölgeden bir örnek alınıp çıktısı öğrenildiğinde o bölgedeki varyasyon azalır; sonra varyansı en yüksek olan bir sonraki bölgeye geçilir.

`active_sampling.m` örneğinin anlatımına göre modelin varyansının en yüksek olduğu yerler, tahminlere en az güvenebileceğimiz yerlerdir. Burada "yer" bir örnek değil, bir koordinattır. Modelin bir noktadaki varyansı, farklı eğitim kümeleriyle eğitilmiş modellerin o noktadaki tahminlerinin standart sapmasıdır ve yeni örnekler bu noktalardan istenmelidir. Hocanın örneğinde bir veri kümesi üzerinde çok sayıda ağaç eğitilmişti. Bazı bölgelerde ağaçların tahminleri birbirine yakındı; bir bölgede ise farklı ağaçların tahminleri arasında çok büyük fark vardı. Yeni örnekler bu bölgeden istenmelidir.

## 8. İnsan-Makine İşbirliği

İnsan-makine işbirliği, son zamanların aktif alanlarından biridir ve "human in the loop" ya da "weak supervision" adlarıyla da geçer (ekrandan, 01:20:00). Fikir, insanların ve makinelerin iyi oldukları yerleri birlikte kullanmaktır.

Slayta göre insanlar yavaş ama doğrudur. İnsanlar:

- Veri etiketleyebilir.
- Tahminleri düzeltebilir.
- Tahminler arasından seçim yapabilir. Örneğin 100 sınıflı bir etiketleme probleminde kullanıcıdan 100 sınıftan birini seçmesi istenmez; makinenin en olası bulduğu 5 sınıftan doğru olanı seçmesi istenir. Böylece etiketleme süreci makineyle basitleştirilir.
- Örneklerin ortak bir özelliği için kural verebilir. Örneğin "içinde şu ifade geçenler negatiftir" ya da "kedilerin kuyruğu vardır". Burada tek tek örneklere etiket verilmez; tek bir ifadeyle çok sayıda veri etiketlenebilir. Bunun için sistemin kuyruğu olan ve olmayanları algılayabilmesi gerekir, bu ayrı bir mevzudur.

Makineler ise hızlıdır, çok sayıda bilgiyle başa çıkabilir ama daha az doğrudur; tahmin üretebilirler.

Örnekler:

- Video etiketleme: bir videoda saniyede 30 kare vardır ve her karedeki nesneleri kutu içinde işaretlemek bezdiricidir. Sabit kameralı bir otoparkta bir arabanın hareketini düşünün. İnsan yalnız ilk ve son karedeki arabanın yerini işaretler, aradaki kareleri makine tahmin eder, insan bu tahminlerin üzerinden geçip düzeltir. 5 saniyelik bir videoda 150 karenin her birini işaretlemek gerekmez.
- Çeviri: günümüzde çeviri kabaca otomatik çeviri artı insan düzeltmesi olarak yapılabilmektedir.
- Weak supervision için Stanford'un geliştirdiği Snorkel altyapısı (Python kütüphanesi): haber sınıflandırmada "içinde dolar geçen ifadeler büyük ihtimalle ekonomi haberidir" ya da "içinde ünlü bir futbol teknik direktörünün adı geçenler büyük ihtimalle spor haberidir" gibi kurallar verilir. Bu kurallar tam doğru değildir, ama tek seferde çok sayıda örnek için olası etiketler üretir.

## 9. Az Sayıda Örnekle Eğitim: One-shot ve Zero-shot

### 9.1 Motivasyon

Hoca, Keras'ı yazan François Chollet'nin bir sözünü gösterdi (ekrandan, 01:25:00): "Any problem can be treated as a pattern recognition problem if your training data covers a sufficiently dense sampling of the problem space. What's interesting is what happens when your training data is a sparse sampling of the space -- to extrapolate, you will need intelligence."

Hocanın yorumuna göre uzay yeterince yoğun örneklenmişse her problem klasik makine öğrenmesi teknikleriyle çözülebilir. Örneklerin seyrek olduğu ya da bulunmadığı bölgelerde bir şey yapabilmek için zekâ gerekir. Çok fazla örneğe ihtiyaç duyan yöntemler aslında bir eşleme (mapping) yapmaktadır; az sayıda örnekle çalışabilen sistemler "zeki" denmeyi daha çok hak eder.

### 9.2 One-shot learning

One-shot (tek çekimle) öğrenme, eğitim kümesinde her sınıf için tek bir örnek olan problemlerdir. Eğitim kümesinde zürafa sınıfı için tek bir resim varsa, yüzlerce zürafa resmi olmasına göre problem çok daha zordur; zürafanın farklı açılardan görünüşü hiç görülmez. Tek örnek yalnız zürafanın başını içeren bir resimse, boynunun uzun olduğu bile öğrenilemeyebilir.

### 9.3 Zero-shot learning

Zero-shot (sıfır çekimle) öğrenme daha da zordur: test örnekleri, eğitim kümesinde hiç örneği bulunmayan sınıflara atanmalıdır. Eğitim kümesindeki sınıflarla test kümesindeki sınıflar ayrıdır. Bu, çok modlu (multimodal) yaklaşımlarla mümkün olur. Eğitim sırasında örneklerin hem sınıfı ve resmi hem de tanımları vardır. Çıkarım sırasında ise yeni sınıfların tanımları ve test örneği vardır, ama bu sınıflara ait eğitim resmi yoktur. Olmayan bir sınıfı doğrudan tahmin etmek mümkün değildir; tanımlar ile resimler arasında geçiş yapmayı sağlayan çok modlu yapılar bunu mümkün kılar.

### 9.4 Zero-shot makine çevirisi

Zero-shot öğrenmenin yaygın bir kullanımı Google'ın makine çevirisidir (ekrandan, 01:30:00). Her olası dil ikilisi için ayrı bir model eğitmek, 100 dilden 100 dile çeviri için 10.000 model demektir. Bunun yerine bütün dillerden bütün dillere çeviri yapan tek bir yapı kullanılır: girişler ortak bir katmana gider, çıkışlar ortak katmandan gelir.

Bu yapının güzel tarafı şudur: elde A→B ve B→C paralel derlemleri olup A→C derlemi olmasa da A'dan C'ye çeviri yapılabilir. Örneğin Türkçe-İngilizce ve İngilizce-İspanyolca paralel derlem varken Türkçe-İspanyolca derlem olmasa bile Türkçeden İspanyolcaya çeviri yapılabilir. Bütün diller ortak bir temsile dönüştürülür, sonra bu ortak temsilden bütün dillere dönüşüm yapılır. Slayttaki çok dilli gömme (multilingual embedding) görselinde aynı anlama sahip farklı dillerdeki cümlelerin temsilleri birbirine yakın koordinatlarda çıkmıştı.

## 10. Veri Zenginleştirme

<!-- BELİRSİZ: Altyazıda 01:29:55 ile 01:30:43 arasında boşluk var; veri zenginleştirme konusunun giriş cümleleri kayıtta okunmuyor ve bu anın karesi yok. Bölüm, altyazının devamından kurulmuştur. -->

Veri zenginleştirmede (data augmentation) mevcut örneklere etiketi değiştirmeyen dönüşümler uygulanarak yeni örnekler üretilir. El yazısı rakam örneğinde yatay eksende eğme, döndürme ve çeşitli elastik deformasyonlarla orijinal örneklerden yapay görüntüler üretilmişti. Veri kümesi bu dönüşümlerle genişletildiğinde, sadece orijinal veriyi kullanmaya göre daha başarılı sonuçlar alınması ümit edilir. Örneğin elde yüz tane "6" varken her birinden dört tane daha üretilirse beş yüz tane "6" olur; bunlarla eğitilen sistemin 6'yı daha iyi tanıması beklenir. Hoca bunun bir varsayım olduğunu vurguladı.

### 10.1 Görüntüler

Görüntüler için rastgele kırpma, ayna yansıması ve renk bilgilerinde değişim kullanılır. Bunlar CNN'leri ünlü yapan ImageNet makalesinde bile vardı. Kırpmada resmin içinden rastgele parçalar seçilerek tek resimden çok sayıda resim üretilir. Bunun gerekçesi, resmin hangi bölgesinin sınıfı belirlediğini tam bilmememizdir. Filtreler, kırpmalar ve döndürmeler yaygın kullanılır. Yeni veri üretmek için üretici çekişmeli ağlar (GAN) da kullanılır.

### 10.2 Metin verileri

Metin için yöntemlerden biri eş anlamlı ifadelerle dönüşüm yapmaktır: "Bizim oğlan komşu kızına abayı yakmış" cümlesi "Bizim oğlan komşu kızına âşık olmuş" cümlesine dönüştürülebilir. Hoca, deyimli bir cümleden aynı anlamdaki farklı bir cümleyi otomatik üretmenin kendi başına kolay bir iş olmadığını belirtti.

Diğer yöntem geri çeviridir (back translation): orijinal cümle başka bir dile çevrilir, sonra o dilden geri çevrilir. Örneğin Türkçe bir cümle İngilizceye, sonra tekrar Türkçeye çevrilir. Sonuçta baştaki cümleye benzer anlamlı ama ondan farklı bir cümle çıkar.

### 10.3 Genel amaçlı (tablo) veriler

Slayta göre görüntülerde ve metinlerde etiketi değiştirmeyen dönüşümler kullanılır; UCI gibi genel amaçlı veri kümeleri için şunlar yapılabilir (ekrandan, 01:35:00):

- Her sınıf için bir olasılık yoğunluk fonksiyonu (pdf) tahmin edip ondan yeni örnekler üretmek (üretici model).
- SMOTE: az örnekli sınıftan bir örneğe en yakın k komşusunu bul. Bunlardan onunla aynı sınıfta olan birini seç. Bu ikisini birleştiren çizgi üzerinde yeni bir örnek üret.

SMOTE genelde sınıf dengesizliği (class imbalance) olan problemlerde, örneğin bir sınıf veri kümesinin %10'unu, diğeri %90'ını oluşturuyorsa, az olan sınıfı çoğaltmak için kullanılır. Slayttaki görselde $X_1$ ile $X_3$ arasında A örneği, $X_1$ ile $X_4$ arasında B örneği üretilmişti. SMOTE-IPF bu yöntemi biraz daha iyileştirir.

> **Ek bilgi (derste anlatılmadı):** SMOTE'ta yeni örnek genellikle $x_{\text{yeni}} = x_i + \lambda\,(x_k - x_i)$, $\lambda \in [0,1]$ rastgele ve $x_k$ seçilen komşu olmak üzere, biçiminde üretilir. Bu, iki örneği birleştiren doğru parçası üzerinde rastgele bir noktadır. SMOTE-IPF, büyük olasılıkla SMOTE'tan sonra gürültülü örnekleri yinelemeli bir filtreyle (Iterative-Partitioning Filter) temizleyen bir genişletmedir.

## 11. Makine Öğrenmesi Algoritmalarını Kandırmak

### 11.1 Problem

Makine öğrenmesinde genel amaç bir şeyi tahmin edebilen ya da sınıflandırabilen yapılar kurmaktır. Son zamanların önemli alanlarından biri ise makine öğrenmesini kandırmaktır (adversarial attacks); kandırmak için de makine öğrenmesi teknikleri kullanılır. Kararlar makinelere bırakıldığı anda onları kandırma çalışmaları da başlar; istenmeyen e-postalar bunun bir örneğidir (ekrandan, 01:40:00). Hocaya göre ileride daha çok karar makinelere bırakıldıkça, insanları kandırmaya çalışan yapılar gibi makineleri kandırmaya çalışan yapılar da ortaya çıkacaktır.

Klasik örnekte en soldaki orijinal resim Inception v3'e göre %97 olasılıkla "papağan"dır. Bu resmin üzerine özel olarak hazırlanmış bir gürültü eklenerek ortadaki resim oluşturulmuştur. Sağdaki gürültü görüntüsü, görünür olsun diye değerleri çok büyütülerek gösterilmiştir; resme eklenen hâli çok daha küçüktür. Aynı Inception mimarisi ortadaki resme %99 olasılıkla "kitaplık" der. İnsanlar bu resme asla kitaplık demez.

**Soru (hoca):** Bu neden çok kötü bir şey? **Cevap (öğrenci):** Model tamamen yanlış tahmin ediyor. Örneğin yapay zekâyla bir güvenlik sistemi kurulmuşsa, saldırgan erişimi olmadığı hâlde sistemi kandırarak erişim sağlayabilir.

Hoca sorunun eğitim kümesinin küçük olmasıyla ya da test kümesinin çok zor veya çok kolay seçilmesiyle ilgili olmadığını vurguladı. Eğitim kümesi büyütülse, hatta bu şekilde üretilmiş düşmanca örnekler (adversarial samples) eğitime katılsa bile sisteme karşı yeni adversarial örnekler üretilebildiği görülmüştür. İşin çok kötü olmayan tarafı, böyle bir resmin normal bir kameranın çekebileceği bir resim olmamasıdır. Gürültü rastgele değildir; resme "kitaplık" dedirtmek için özenle üretilmiştir.

### 11.2 Adversarial örnekler nasıl oluşuyor?

**Soru:** Bu gürültü resmi nasıl üretiliyor? **Cevap:** Hoca en kaba hâliyle şöyle açıkladı: yapay sinir ağlarının karar sınırları düzgün (smooth) değildir. Doğrusal olmayan yapılar, verilerin içinde boşluklar oluşturur. Eğitim kümesinde kitaplığa dair hiçbir örneğin bulunmadığı, hiç ilgisiz bir yerde de ağ bir bölgeyi "kitaplık" olarak işaretleyebilir. Resim bu bölgeye doğru ilerletilirse ağ ona kitaplık der.

**Soru:** Saldırının nasıl oluşturulduğunu tam olarak bilirsek ona bir çözüm üretebilir miyiz? **Cevap:** O manada bir çözüm yok. Mevcut saldırı yöntemlerine karşı bir şey yapılsa da başka bir saldırı yöntemi geliştirilip savunma kolaylıkla aşılabiliyor.

> **Hocanın vurgusu:** Makine öğrenmesi algoritmalarını kandırmak, insanları kandırmaktan daha kolaydır.

Slayta göre daha önce görülen GAN'lar bu tür ataklara karşı dayanıklı mimariler üretmek için geliştirilmiştir. Sadece derin öğrenme mimarileri tehdit altında değildir; doğrusal olmayan birçok yapı bu problemden muzdariptir. Bir Kaggle yarışmasında üç görev vardı: hedefi belli atak (bir resme belirli bir sınıfı dedirtmek), hedefi belirsiz atak (sadece yanlış bir şey dedirtmek) ve savunma. Hoca savunma tarafında maalesef çok fazla bir şey olmadığını söyledi. Sadece tek bir pikselin değiştirilmesiyle bile kandırmak mümkün olabiliyor; ama bu değişimler rastgele değildir ve her resim için ayrı uğraşmak gerekir. Yine de birinin yüzünün başka biri olarak tanınması için uğraşmaya değer görülebileceğinden, bu güvenlik açısından büyük bir açıktır.

Doğal resimlerde, yani eğitim kümesinin bulunduğu bölgelerin etrafında böyle bir sorun yoktur. Sorun, örneklerin hiç bulunmadığı bölgelere doğru gidildiğinde ortaya çıkar.

## 12. Planlı Öğrenme

### 12.1 Fikir

Planlı öğrenme (curriculum learning), yeni örnekler geldiğinde eğitime baştan başlaması gerekmeyen öğreniciler, yani online algoritmalar için bir problemdir. "Curriculum" müfredat demektir. Bir dersin müfredatında konular haftalara dağıtılır ve adım adım ilerlenir; konuların hepsi tek seferde verilmez. Slayttaki sorular şunlardı: örneklerin öğrenciye (burada makineye) veriliş sırası önemli mi; bir müfredat oluşturulmalı mı; evetse nasıl; eldeki tüm veriler müfredata dahil edilmeli mi?

İnsanlar anaokulu, ilköğretim, lise ve üniversite sırasıyla yetiştirilir. Hoca bunun tartışılabileceğini, ama kavramlar açısından kabaca kolaydan zora gidildiğini varsayabileceğimizi söyledi (ekrandan, 01:45:00). İnsanlara kavramları bir sırayla veriyoruz; acaba makineyi de böyle eğitmek iyi olur mu? Online öğrenmede örnekleri rastgele sırayla vermek yerine bir sıraya dizip vermek, rastgele vermeye göre daha başarılı bir öğrenme sağlar mı?

İlk geniş ilgi gören planlı öğrenme makalesi 2009 civarında yayınlanmıştır ve çalışmalar hâlâ sürmektedir. Yaklaşım özellikle pekiştirmeli öğrenmede ve oyunlarda çok kullanılır. Hoca, elindeki Rubik küpünü çözen robot elini örnek verdi. Gerçek dünyada çok fazla deneme gerekir; bu denemelerin çok büyük kısmı simülasyon ortamında yaptırılır. Simülasyon daha kısıtlı ve belirli bir ortamdır, yani kolaydır. Sistem orada iyice öğrendikten sonra öğrendiklerini daha karmaşık ve kısıtları tam bilinmeyen gerçek dünyaya aktarır. Sınıflandırma, regresyon ve nesne tanıma gibi geleneksel problemlerde ise daha kısıtlı kullanılır, ama orada da belli başarılar elde edilmiştir.

### 12.2 Örneklerin zorluğu

Slayta göre örneklerin kolaylık ölçütü iki biçimde belirlenebilir (ekrandan, 01:45:00):

- Önceden belirlenip sabit kalsın:
  - İnsan belirler.
  - Bir algoritmanın sınıflara atama olasılıkları kullanılır.
  - Geometrik yaklaşımlar (Ho ve arkadaşlarının 2002 tarihli sınıflandırma problemlerinin karmaşıklık ölçüleri çalışmasına atıfla).
- Öğrenme sırasında değişsin (self-paced learning).

Şekil sınıflandırma örneğinde birinci satırdaki şekiller basit, ikinci satırdakiler zordu. Zor satırda üçgenler daha farklı çeşitkenar üçgenlere, daireler elipslere, kareler dikdörtgenlere dönüşmüştü. Örneklerin zorluğunu insanlar belirleyebileceği gibi makinenin kendisinin belirlediği yaklaşımlar da vardır.

Deney sonuçlarında örnekler sıralandığında belli başarılar elde edilebildiği görüldü. Klasik müfredatın (kolaydan zora) yanında anti-müfredatın, yani örnekleri zordan kolaya sıralamanın da başarılı sonuçlar verdiği görülmüştür.

## 13. Hayat Boyu Öğrenme

Dersin son konusu hayat boyu öğrenmedir (lifelong learning), yani öğrenme sürecinin hiç bitmediği durum (ekrandan, 01:50:00). Normalde bir problem için veri kümesi hazırlanır, model eğitilir ve kullanıma alınır. Sistem, kurulduğu an için çalışır. Dünya değişmiyorsa, yani inputların yapısı ve sınıfların dağılımları hiç değişmiyorsa bu bir sorun oluşturmaz.

Ama gerçek dünyadaki problemler genelde böyle değildir. Örneğin dil durmadan değişir: yeni kavramlar eklenir, kavramlar bölünür ya da birleşir, anlamlar başka anlamlara kayar. Yeni markalar ve trendler çıkar; beş yıl önce adı bile duyulmayan şeyler hayatın önemli parçaları olabilir. Böyle durumlarda bir kere eğitip sonsuza kadar kullanmak olmaz.

Slayttaki özellikler şunlardır:

- Öğrenme süreci bitmez.
- Tüm eğitim verileri elde değildir, zaman içinde erişilir.
- Test örnekleri sadece eğitim örneklerinin sınıflarından gelmez (open world).
- Önceki öğrenilenler, nelerin ve nasıl öğrenileceğine etki eder.
- Endüstride daha yaygındır.

Örnek olarak başta bütün verileri almayan, etrafta gezindikçe öğrenen bir robot verildi.

## 14. Proje Soru-Cevaplarından Akademik Noktalar

Dersin sonunda öğrenciler dönem projeleriyle ilgili sorular sordu. Akademik noktalar aşağıdadır.

### 14.1 Dengesiz veride örnek üretimi ve azaltımı

**Soru:** Dengesiz veri kümelerinde yapay örnek üretiminin yanında çoğunluk sınıfından örnek azaltımı da yapılabilir mi? Örneğin 900'e 100 örnekli bir veri kümesinde azınlık sınıfına 100 yapay örnek ekleyip çoğunluk sınıfından 700 örnek silerek 200'e 200 dengeli bir küme elde etmek gibi. **Cevap:** Olabilir. Projenin temel beklentisi SMOTE, SMOTE-IPF ve benzeri yöntemlerle yapay veri üretmek, üretilen yapay veri sayısının ve üretim türünün etkilerini görmektir. Ek analizler yapılabilir, ama önce temel istenenleri gerçekleştirip sonra ek denemelere geçmek daha iyidir.

### 14.2 Yapay sinir ağı çözümleri arasındaki yollardan ensemble

**Soru:** Farklı başlangıç değerleriyle ulaşılan YSA çözümleri ($Q_1$, $Q_2$) arasında test başarısını düşürmeden bir yol bulunduğunda, bu yol üzerindeki noktalarla ensemble nasıl kurulur? **Cevap:** Her veri kümesi için (ör. CIFAR-10 için ayrı, CIFAR-100 için ayrı) iki uç nokta bulunur. Yol üzerindeki her nokta bir ağırlık takımıdır, yani tam bir modeldir ve tahmin üretebilir. Soru, bu ara noktalardan 3-5 tanesiyle (gerekirse $Q_1$ ve $Q_2$ de katılarak) kurulan ensemble'ın uç noktaları geçip geçemeyeceğidir. Örneğin $Q_1$ %80, $Q_2$ %82 başarı veriyorsa, ensemble %83 gibi bir başarıya ulaşabiliyor mu?

### 14.3 Ağırlık uzayında MCMC benzeri gezinme

Bir öğrenci, eğittiği ağın son ağırlıklarına $[-0.5, 0.5]$ aralığından rastgele değerler ekleyip yeni noktanın başarısı bir öncekinden belirli bir eşikten az farklıysa noktayı kabul ettiği, sonra aynı işlemi yeni noktadan tekrarladığı bir yöntem gösterdi. Gezilen noktaları PCA ve t-SNE ile iki boyuta indirip çizmişti; başarı adım adım düşüyordu.

Hocanın değerlendirmesi:

- Başarının sürekli düşmesi istenmez; amaç başarının hemen hemen aynı kaldığı noktaları bulmaktır. Kabul ölçütü çok daha sıkı olmalı, ağırlıklara eklenen adımlar çok daha küçük olmalıdır.
- Noktalar bir sırayla üretildiği için çizimde tek bir uç olması beklenir; iki ayrı kol görünmesi açıklanması gereken bir durumdur.
- Başarının hep düşmesinin bir nedeni, eğitimin çok sivri (sharp) bir minimumda bitmiş olması olabilir. Farklı başlangıç değerleriyle bazı çözümler geniş yüzeylerde, bazıları sivri uçlarda bitebilir. Örneğin önceki haftanın slaytlarındaki Digit veri kümesinde farklı son noktalar oldukça düzgün (smooth) bölgelerdeydi. Bu tür değerlendirmeler de projeye katılabilir.
- Öğrencinin, son 10 ağırlığın standart sapmasını kullanarak rastgele adımı ölçekleme fikri makul bulundu; hoca, örnek kodunun kabul/ret adımını ve dağılımı daha iyi kontrol ettiğini, incelenmesi gerektiğini söyledi.

### 14.4 Ensemble yörüngelerinde kappa-hata diyagramı

**Soru:** Ensemble'ı bir boyutta kappa, diğer boyutta tekil öğrenici hatasıyla göstermek için ikili kappaların ortalaması mı alınmalı? **Cevap:** 10 öğrenicili bir ensemble'da $\binom{10}{2} = \frac{10 \cdot 9}{2} = 45$ ikili kappa vardır. Bunların ortalaması alınıp ensemble tek bir noktayla gösterilebilir ya da 45 noktanın hepsi bir bulut olarak çizilebilir. Rotation Forest slaytlarındaki kırmızı-siyah bulutlar böyle oluşturulmuştu: bir eksende her ikilinin kappası, diğer eksende o ikilinin tekil başarılarının ortalaması vardı. Hocaya göre bulutlar, ensemble boyutu arttıkça dağılımın nasıl değiştiğini de gösterdiği için ortalamadan çok daha fazla bilgi verir.

> **Ek bilgi (derste anlatılmadı):** İki sınıflandırıcı arasındaki kappa istatistiği $\kappa = \frac{p_o - p_e}{1 - p_e}$ biçimindedir; $p_o$ iki sınıflandırıcının aynı kararı verdiği örneklerin oranı, $p_e$ bu uyuşmanın şans eseri beklenen değeridir. Kappa 1'e yaklaştıkça sınıflandırıcılar birbirine benzer, yani çeşitlilik azalır.

### 14.5 Eğitim yörüngesinin iki boyuta indirgenmesi

Bir öğrencinin 22 katmanlı bir ağın CIFAR-10 üzerindeki 200 epokluk ağırlık yörüngesini gösterdiği grafikte noktalar soldan sağa tek bir sinyal gibi diziliyordu. Hoca, x ekseninin epokları gösteriyormuş gibi durduğunu, yani verilerin aslında tek boyuta indirgendiğini söyledi. İstenen, ağırlıkların iki ayrı boyuta indirgenip yörüngenin bu iki boyutlu düzlemde çizilmesidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:55): İki sınıflı bir problemde aktif öğrenme modelimiz bir örnek için "%90 A, %10 B", başka bir örnek için "%51 A, %49 B" tahmini veriyor. Modeli iyileştirmek için hangi örneğin etiketini istemek daha yararlıdır?

> **Çözüm (derste verildi):** İkinci örneğin. Birinci örnekte model kararından emindir; etiketini öğrenmek modeli pek değiştirmez. İkinci örnekte sınıf olasılıkları birbirine çok yakındır, yani örnek modelin karar sınırına yakındır. Bu örneğin etiketi sınırı belirginleştirir ve modeli iyileştirmeye yönelik değiştirir. Deneylerde de önce bu tür zor örnekleri eklemenin rastgele eklemeyi geçebildiği, önce kolay örnekleri eklemenin ise rastgele eklemekten kötü olduğu görüldü.

**Soru 2** (ekrandan, 00:25:00): Aktif öğrenmede ilk eğitim seti nasıl seçilebilir, önemi var mı? B ve C adımlarının tekrarı ne zaman durmalıdır?

> **Çözüm (derste verildi):** İlk eğitim setinin önemi vardır; problem global bir optimizasyon olmadığı için başlangıç varılan yeri etkiler. Rastgele seçilebilir ya da kümeleme yapılıp her kümeden bir örnek alınabilir. Durma için bir etiketleme bütçesi kullanılabilir: her etiket 1 dolar ve bütçe 100.000 dolarsa 100.000 etikete ulaşınca durulur. Her adımda eklenecek örnek sayısı gibi bu seçimler de aktif öğrenmenin hiperparametreleridir.

**Soru 3** (ekrandan, 00:25:00): Sınıflandırma problemlerinde etiketsiz bir örneğin tahmin varyasyonu nasıl hesaplanır? Üç sınıflı bir problemde %34, %33, %33 tahmini ne anlama gelir?

> **Çözüm (derste verildi):** Modelin verdiği sınıf olasılıkları (confidence değerleri) kullanılır; olasılıklar birbirine ne kadar yakınsa tahmin o kadar kararsızdır. %34, %33, %33 diyen model karar verememiştir; örnek mevcut modelin sınırlarına yakındır ve o bölgeden alınan bir etiket sınırı değiştirecektir. Regresyon için ölçünün nasıl olacağı derste açık bırakıldı.

**Soru 4** (ekrandan, 00:50:00): `multi_task_learning.m` deneyinde 3. veri kümesinin test başarıları tek başına eğitimde 0.6923, 0.7063, 0.6783; çok görevli eğitimde 0.7343, 0.7413, 0.7203'tür. Çok görevli eğitim bu veri kümesinde ortalama ne kadar kazanç sağlamıştır? Bu veri kümeleri birbiriyle ilgisiz olduğu hâlde sonuç neden ilginçtir?

> **Çözüm (derste verilmedi):** Ortalama tek başına başarı $(0.6923 + 0.7063 + 0.6783)/3 = 0.6923$, ortalama çok görevli başarı $(0.7343 + 0.7413 + 0.7203)/3 = 0.7320$'dir (python ile doğrulandı). Kazanç yaklaşık $0.0397$, yani yaklaşık 4 puandır ve üç denemenin üçünde de iyileşme vardır. Derste vurgulandığı gibi beş UCI veri kümesi birbirinden tamamen ilgisizdir; yine de tek bir 10 gizli nöronlu ağın beşini birlikte öğrenmesi bazı veri kümelerinde test başarısını artırmıştır. Ancak 1. veri kümesinde iki denemede belirgin düşüş olduğu ve deneme sayısının az olduğu unutulmamalıdır.

**Soru 5** (derste sözlü, 01:37:29): Inception v3'ün %97 olasılıkla "papağan" dediği resme özel bir gürültü eklenince model %99 olasılıkla "kitaplık" diyor. Bu neden kötüdür ve eğitim kümesini büyütmek bu sorunu çözer mi?

> **Çözüm (derste verildi):** Model tamamen yanlış bir sınıfı çok yüksek güvenle veriyor; yapay zekâya dayanan bir güvenlik sistemi bu yolla kandırılabilir. Eğitim kümesini büyütmek, hatta adversarial örnekleri eğitime katmak bile yeni saldırı örneklerinin üretilmesini engellemiyor. Sorun doğrusal olmayan karar sınırlarının, eğitim verisi olmayan bölgelerde de sınıf bölgeleri oluşturmasından kaynaklanır ve doğrusal olmayan birçok yapıda görülür.

**Soru 6** (derste sözlü, 02:10:07): 10 öğrenicili bir ensemble'ı kappa-hata diyagramında ikili kappalarla göstermek istiyoruz. Kaç nokta elde edilir?

> **Çözüm (derste verildi):** Her öğrenici çifti için bir kappa hesaplanır: $\binom{10}{2} = 45$. Bu 45 değerin ortalaması alınıp ensemble tek noktayla gösterilebilir ya da 45 nokta bir bulut olarak çizilebilir; bulut daha çok bilgi verir.

## Dersin Toparlaması

Bu derste klasik gözetimli öğrenme kalıbının dışına çıkan güncel problemler tanıtıldı. Etiketleme maliyetini azaltmaya yönelik yaklaşımlar (aktif öğrenme, yarı eğiticili öğrenme, insan-makine işbirliği, weak supervision), veri toplama ve hiperparametre seçimini akıllıca yönlendiren yöntemler (aktif örnekleme, Bayesçi optimizasyon), bilgiyi görevler arasında paylaşan yaklaşımlar (transfer öğrenme, çok görevli eğitim, zero-shot çeviri), veriyi çoğaltan teknikler (veri zenginleştirme, SMOTE), modellerin güvenilirliğini tehdit eden adversarial örnekler ve öğrenme sürecinin zaman boyutunu ele alan planlı öğrenme ile hayat boyu öğrenme incelendi. Aktif öğrenme deneylerinin ortak dersi, örnek seçiminin önemli olduğu ve önce zor örnekleri seçmenin bazı veri kümelerinde daha az etiketle aynı başarıya ulaştırdığıdır. İteratif yöntemlerde ise nerede durulacağı belirleyicidir.

Ders sonundaki proje tartışmaları, dönemin kollektif öğrenme konularını (SMOTE ile dengesiz veri, YSA çözümleri arasındaki yollardan ensemble, kappa-hata diyagramları, Rotation Forest çeşitlilik bulutları) bu yeni problemlerle birleştirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
