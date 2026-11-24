# Ders 5 Çalışma Özeti

## Genel Konular

- Kullanım şemaları (use case diagrams)
  - Kullanım senaryosu metinleri sistemin davranışını ayrıntılı anlatır; kullanım şeması ise senaryoların birbiriyle ilişkisi üzerinden sisteme genel bir bakış sağlar.
  - Her kullanım senaryosu bir elipsle gösterilir. Senaryonun yalnız birinci aktörü elipse düz bir çizgiyle bağlanır; bütün aktörler bağlanırsa şema okunamaz hale gelir (ekrandan, 00:15:00).
  - İnsan aktör çöp adamla, insan olmayan aktör (başka bir yazılım ya da donanım bileşeni) `<<actor>>` stereotipli bir dikdörtgenle çizilir.
  - Senaryolar arasında iki ilişki vardır: `<<include>>` (içerme, ön koşul gibi de düşünülebilir) ve `<<extend>>` (alternatif senaryo olma). Her ikisinin oku kesikli çizgiyle çizilir.
  - Okun yönü İngilizce okunarak belirlenir: "Sales includes Login" olduğu için ok satıştan login'e; "Cancellation extends Sales" olduğu için ok iptalden satışa doğrudur.
  - Kullanım senaryoları arasında genelleme (kalıtım) ilişkisi de kurulabilir, ama include ve extend çoğu durumu karşıladığı için derste kullanılmayacağı belirtildi.
- Örnek: satış senaryosunun kullanım şeması (ekrandan, 00:25:00)
  - Kasiyer (birinci aktör) Satış senaryosuna düz çizgiyle bağlanır.
  - Satış `<<include>>` Kimlik Doğrulama, Yeni Satış Başlat ve Ödeme.
  - Geçersiz Barkod ve Ürün İptal, Satış'ı `<<extend>>` eder; Provizyon, Ödeme'yi `<<extend>>` eder (her ödeme kartla yapılmadığı için).
  - Barkod girme, toplam hesaplama gibi basit adımlar ayrı senaryo yapılmaz.
  - Ödeme türleri (nakit, kredi/banka kartı, yemek kartı) kalıtımla gösterilirse Provizyon ilişkisi nakit ödemeye de kalıtılmış gibi görünür; hoca bu yüzden bu çözümü beğenmedi (ekrandan, 00:45:00).
- Nesneye yönelik çözümleme: sınıfların belirlenmesi (ekrandan, 00:25:00)
  - Kullanıcı gereksinimleri belgesindeki ve kullanım senaryolarındaki bütün isimler taranır, aday sınıf olarak yazılır.
  - Aday şu üç kuraldan en az birini sağlamalıdır: saklanan bilgi (sistemin çalışması süresince durumu saklanmalı), gereksinim duyulan hizmetler (hizmetlerine ihtiyaç duyan başka varlıklar var), gerekli varlıklar (problemin çözümü için bilgi üreten ya da tüketen varlıklar).
  - Kuralların hiçbirini sağlamayan aday, başka bir sınıfın üye alanı olarak değerlendirilebilir.
  - Çözümlemede "ne?" sorulur: nesneler, üye alanlar ve ilişkiler belirlenir, metotlar düşünülmez. Üye alanlar sıfatlardan, metotlar (tasarımda) eylemlerden çıkarılır.
  - Bir bilgiyle ilgili davranış, o bilgiyle aynı sınıfta yer almalıdır.
- Örnek aday eleme: NextGenPOS perakende satış programı (ekrandan, 00:55:00)
  - Kasa (+), Satış (+), Şube (+), Kasiyer (+), Ödeme (+), Ürün (+).
  - Alış-veriş (-): satışla eş anlamlı.
  - Rapor (-): aslında gerekir, ama çözümü sade tutmak için "üretilebilir bilgi" gerekçesiyle alınmadı.
  - Fiş (-): tamamen üretilebilir bilgidir; tek tip olduğu kabul edildi.
  - Müşteri (-): sadakat/müşteri kartı gereksinimlerde yok.
  - KDV (-): ürüne bağlıdır, Ürün'ün üye alanıdır. Barkod (-): Ürün'ün üye alanıdır.
- Alan modeli (sınıf şeması) (ekrandan, 01:35:00 ve 01:40:00)
  - Şube ile Kasa arasında bütün-parça ilişkisi (Şube 1, Kasa 1..*): şubede en az bir kasa vardır.
  - Kasa → Satış (1 - *): bir kasada hiç satış yapılmamış olabilir.
  - Kasa → Kasiyer (1 - 0..1): kasada oturum açmış kasiyer olabilir ya da olmayabilir.
  - Satış → Kasiyer (1 - 1), Satış → Ödeme (1 - 1), Satış → SatışKalemi (1 - 1..*), SatışKalemi → Ürün (1 - 1).
  - Şube ile Ürün arasında bütün-parça ilişkisi (1 - *): ürün bilgisi her kasaya ayrı ayrı değil, şubeye girilir.
  - Üye alanlar: Ürün (barkod, tanim: String; fiyat, KDV: float), Şube (ad, adres, vergiNo: String), Satış (tarih: Date), Ödeme (miktar: double), SatışKalemi (adet: int).
- Satış kalemi: ilişki nesnesi
  - Bir üründen kaç adet alındığı ne Ürün'e (her satışta üzerine yazılır) ne de Satış'a paralel bir "adetler" dizisi olarak konmalıdır; ikisi de kod kokusudur.
  - Araya yalnız bu bilgiyi tutan bir ara sınıf (SatışKalemi) konur. "Kalem" terimi konu alanından gelir (satış kalemi, bütçe kalemi).
- Çözümlemede yapılabilecek ek çalışmalar
  - CRC kartları, ER şeması, prototip ve taslak ekranlar (örneğin rapor ve veri giriş ekranları).
- Nesneye yönelik tasarım süreci (ekrandan, 02:00:00)
  - "Nasıl?" sorusuna yanıt aranır. Problem alanı nesnelerinden oluşan model yardımcı nesnelerle zenginleştirilir, metotlar eklenir.
  - Nesne tasarımı (problem alanı nesneleri) ve sistem tasarımı (altyapı ve gereçler: yazılım mimarisi, kullanıcı arayüzü, veri yönetimi, ağ programlama).
  - Sistem katmanı çoğunlukla sıfırdan yazılmaz, hazır altyapı programları (framework) kullanılır.
  - Artifakt: kod dışında üretilen her şey (teknik ve son kullanıcı belgeleri, kurulum için yapılandırma dosyaları vb.).
- Tasarım ölçütleri (ekrandan, 02:05:00)
  - Ayrılabilirlik, birleştirilebilirlik, anlaşılabilirlik, süreklilik, koruma. Bunlar öznel ölçütlerdir.
- Bağlaşım (coupling): düşük olmalı
  - Bir parçanın diğer parçalara bağımlılık oranıdır. Sınıf şemasında bir sınıftan başka bir sınıfa giden her ok (ilişki, bütün-parça, kalıtım) 1 bağlaşım sayılır; ilişkinin niceliği (1 ya da *) değil varlığı önemlidir (ekrandan, 02:15:00).
  - Düşük bağlaşım değişikliklerin ve hataların yayılmasını azaltır, yeniden kullanılabilirliği artırır.
  - Toplam bağlaşım, en büyük bağlaşım ve dolaylı bağlaşım (genelde yarım sayılır) ölçülerine göre iki tasarım karşılaştırıldı (ekrandan, 02:30:00).
- Uyum (cohesion): yüksek olmalı
  - Bir sınıfın sorumluluklarının birbiriyle ilişkili olma derecesidir.
  - Ölçüm: metot ile üye alan arasındaki erişim eşleşmelerinin, olası en çok eşleşmeye oranı (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım şemasında include/extend oklarının adı yetmez
  - Okun gövdesi kesikli, yönü doğru olmalıdır; hepsine tek tek bakılır. Yönü bulmak için ilişki İngilizce cümle gibi okunur.
- Extend yalnız alternatif senaryoda geçen durumlar için kullanılır
  - "Kasiyer zaten giriş yapmışsa?" durumu alternatif senaryodadır; ana akışta her satış kimlik doğrulamayı içerdiği için ilişki include'dur.
- Kalıtım ağır sıklet bir ilişkidir
  - Tam bir "is-a" ilişkisi yoksa deneyimli tasarımcılar kalıtım dışındaki çözümleri tercih eder; kullanım şemasında da kalıtıma gerek görülmedi.
- KDV başlı başına bir sınıf değildir
  - Ürünlere göre farklı değer alır, ürüne bağlıdır, Ürün'ün üye alanıdır.
- Çift yönlü ilişkiden kaçının
  - Çift yönlü ilişkilerde tutarlılık denetimi ek iş getirir; KISS (Keep It Simple) ilkesine uyulur.
- Paralel diziler ve "adetler" alanı kod kokusudur
  - Değişen başka bir şey vardır; onu bir ilişki nesnesi (SatışKalemi) olarak keşfetmek gerekir.
- Bağlaşım bir gösterge olarak kullanılmalı, amaç olarak değil
  - Olması gereken bir bağlaşım düzeyi vardır; gerekenden az bağlaşım da ilişkili olması gereken sınıfların ilişkilendirilmediğini gösterebilir.
- Veritabanı sorumluluğu ayrı bir sınıfa verilmelidir
  - Problem alanı sınıflarına hem iş mantığı hem kendini saklama görevi vermek uyumu düşürür ve veritabanı değişince bütün sınıfları etkiler.

## Kısa Tekrar Notları

- Kullanım şeması: elips = senaryo, çöp adam = insan aktör, `<<actor>>` dikdörtgen = insan olmayan aktör, düz çizgi = birinci aktörle etkileşim.
- `<<include>>`: içerme/ön koşul, ok içerenden içerilene. `<<extend>>`: alternatif senaryo, ok alternatiften ana senaryoya. İkisi de kesikli ok.
- Aday sınıf kuralları: saklanan bilgi, gereksinim duyulan hizmetler, gerekli varlıklar. Hiçbiri yoksa üye alan olur.
- Üretilebilir bilgi (rapor, fiş) ve eş anlamlı kelimeler (alış-veriş = satış) sınıf yapılmaz.
- Çözümleme = ne? (nesne, üye alan, ilişki). Tasarım = nasıl? (metotlar, yardımcı nesneler).
- Satış ile ürün arasındaki adet bilgisi için SatışKalemi ilişki nesnesi kullanılır.
- Barkod `String` tutulur (13 haneli barkodlar int'e sığmaz, ISBN'de X harfi olabilir).
- Tasarım ölçütleri: ayrılabilirlik, birleştirilebilirlik, anlaşılabilirlik, süreklilik, koruma.
- Bağlaşım: dışarı giden ok sayısı; düşük olmalı. Uyum: mevcut metot-alan eşleşmesi / olası eşleşme; yüksek olmalı.
- Uyumu düşük bir sınıf ikiye bölünerek (refactoring) uyum artırılabilir.
- Veritabanı işlemleri için ayrı bir sınıf, katmanlı mimari sağlar.

## Detaylı Açıklamalar

- **Kullanım şeması çizim kuralları.** Slayttaki genel şemada (ekrandan, 00:15:00) kişi türü adı verilen bir aktör Use Case A'ya düz çizgiyle bağlıdır. Use Case A'nın içinde "Extension Points: Adım K, Adım L" bölümü vardır; Use Case B, A'ya `<<extends>>` ile, A da Use Case C'ye `<<includes>>` ile bağlıdır. C'ye bağlı insan olmayan aktör `<<actor>> HW/SW Element` kutusuyla gösterilir. Gösterim sözlüğü: use case = işlev, insan aktör = kullanıcılar, etkileşim = kullanım (düz çizgi), ilişki = benzeşim (kesikli ok). Hoca örnek olarak satışın login'i içermesini (ok satıştan login'e) ve ürün iptalin satışı genişletmesini (ok iptalden satışa) çizdi. Satışın ödemeyi içerdiğini, provizyonun ise ödemeyi genişlettiğini söyledi: provizyon, kartla ödemede kartın bakiyesinin yeterli olup olmadığı, bilgilerinin doğru girilip girilmediği, süresinin geçip geçmediği, çalıntı ya da iptal olarak işaretlenip işaretlenmediği gibi denetimlerdir; nakit ödemede gerekmediği için alternatif senaryodur.
- **Ödeme türleri için iki çözüm.** Hoca bir düşünce alıştırması olarak Ödeme'den Nakit, Kredi/Banka Kartı ve Yemek Kartı senaryolarını kalıtımla türetti (ekrandan, 00:45:00). Kalıtımda üstteki her şey alta geçtiği için Provizyon'un extend ilişkisi nakit ödemeye de geçmiş gibi görünür; bu yüzden bu çözümü beğenmedi. Ardından kalıtımsız, fiş basma ve fatura basma senaryolarıyla bir alternatif kurdu ve kalıtım kullanmadan da ayrıntılı bir çözüm elde edilebildiğini gösterdi. <!-- BELİRSİZ: Fiş basma/fatura basma senaryolarının şemadaki ilişkileri karede görünmüyor; altyazıdan tam çıkarılamadı. --> Bunların gereksinimlerde geçmediğini, yalnız tartışma için yapıldığını belirtti.
- **Sınıfların belirlenmesi.** Örnek gereksinim belgesi NextGenPOS perakende satış programıdır (ekrandan, 00:35:00): program kasada yapılan alış-veriş işlemlerine yardımcı olur, her işlemi saklar, mali bilgileri harici bütçe sistemine, mal çıkış bilgilerini harici envanter sistemine iletir, saklanan işlemler üzerinde rapor ve analiz yapılır, müşteriye fiş verilir, her satış için KDV hesaplanır, şirketin birden fazla şubesi vardır ve işlemler merkezi sunucuya iletilir. Hoca bu metinden ve satış kullanım öyküsünden isimleri topladı; problem alanına odaklanmak için harici sistemleri ve "program", "sistem", "işlem", "mali bilgi" gibi çok genel kelimeleri dışarıda bıraktı. Kasa, çalışma süresince durumu saklandığı için alındı. Satış, hem kayıtları saklandığı hem de satış sırasında ürün ekleme, çıkarma gibi hizmetler gerektiği için alındı. Şube, fişteki şube adı ve adresi gibi bilgiler problemin çözümünde kullanıldığı için alındı. Kasiyer, giriş yapacağı için kullanıcı hesabı bilgisi saklanmalıdır. Ödeme, kartlı ödemelerde onay kodu, kartın son dört hanesi ve miktar gibi bilgilerin kasada saklanması gerektiği için alındı.
- **Alan modelinin kurulması.** Hoca bir sınıfı şemaya koyduğunda önceki sınıflarla ilişkisini hemen çizdi. Şube ile satış arasına ilişki koymadı, çünkü bir şubenin satışları kasalar üzerinden toplanabilir. Satıştan kasaya ters yönlü bir ilişki de koymadı. Barkod için 13 haneli bir ürün barkodunu örnek gösterdi ve barkodun uzunluğu ve kitaplardaki ISBN'de X harfi bulunabilmesi nedeniyle `String` tutulmasını önerdi. KDV ve fiyat ondalıklıdır; çok hassasiyet gerekmediği için `float` yeterlidir. Barkodu okutulan ürünün bilgisi her kasaya ayrı ayrı yüklenmez; şubeye girilir ve kasa ürün bilgisini şubeden ister. Hoca şube ile ürün arasında bir map kullanmanın (anahtar = barkod) ardışıl aramadan daha iyi olacağını, bunun ise bir tasarım kararı olduğunu söyledi.
- **Ders notundaki alan modeliyle karşılaştırma** (ekrandan, 01:35:00). Ders notundaki modelde SatışKalemi (miktar: int) "içerir" ilişkisiyle Ürün'e (tanim: String; fiyat, kdv: double; barkod: String) bağlıdır; Satış (tarih: Date) ile SatışKalemi arasında dolu elmaslı bütün-parça ilişkisi (1 - 1..*), Satış ile Ödeme (miktar: double) arasında "içerir" ilişkisi (1 - 1) vardır; Şube (ad, adres: String) ürünleri "stoklar" (1 - *), Şube ile Kasa arasında dolu elmaslı ilişki, Kasa ile Satış arasında "kaydeder" ilişkisi bulunur. Derste çizilen modelde ayrıca Kasiyer sınıfı vardır. İlişki adları isteğe bağlıdır.
- **Bağlaşımın sayılması.** Hoca A sınıfının B'ye 1, C'ye * ilişkisi, X'ten kalıtımı ve D ile bütün-parça ilişkisi olan bir şema çizdi ve bağ(A) = 4 yazdı (ekrandan, 02:15:00). A'yı başka bir projede kullanmak için B, C, X ve D'nin kodu da alınmak zorundadır; bu yüzden her ilişki tek bağlaşım sayılır. İki tasarım karşılaştırıldı (ekrandan, 02:30:00): Tasarım I'de A → B ve A → C (bağ(A) = 2, bağ(B) = bağ(C) = 0, topBağ = 2, maxBağ = 2); Tasarım II'de A → B → C (bağ(A) = 1, bağ(B) = 1, bağ(C) = 0, topBağ = 2, maxBağ = 1). En büyük bağlaşıma bakılırsa II, dolaylı A → C ilişkisi yarım sayılırsa (II'de bağ(A) = 1,5, topBağ = 2,5) I tercih edilir. Hoca sonuçta asıl ölçütün problem alanındaki gerçek ilişkiler olduğunu söyledi.
- **Uyumun ölçülmesi.** 4 üye alanı ve 5 metodu olan bir sınıfta en çok 4 × 5 = 20 eşleşme olabilir; şekilde 7 eşleşme vardır, uyum = 7/20 = %35 (ekrandan, 02:40:00). Sınıf ikiye bölündüğünde (refactoring) birinci sınıfta 2 alan × 2 metot = 4 olası eşleşmenin 3'ü (%75), ikinci sınıfta 2 alan × 3 metot = 6 olası eşleşmenin 4'ü (yaklaşık %67) vardır. Çevik süreçlerde bu tür düzeltmeler için bir refactoring koşusu planlanabilir.
- **Veritabanı sorumluluğu.** İki tasarım gösterildi (ekrandan, 02:45:00): Tasarım I'de A, B ve C kendilerini veritabanına kendileri kaydeder (üçünden de veritabanına ok); Tasarım II'de A, B ve C'ye sahip olan bir D sınıfı veritabanıyla tek başına konuşur. Ok sayısı II'de daha fazla olsa da doğru cevap II'dir: veritabanı değişirse (örneğin ilişkisel bir veritabanından ilişkisel olmayan bir veritabanına geçilirse) yalnız D değişir; ayrıca A, B ve C yalnız problem alanı görevlerini taşır, uyumları yüksek kalır ve katmanlı bir mimari elde edilir. Veritabanı kodu A, B ve C'de tekrar edeceği için kalıtımla ortak bir üst sınıfa taşımak da düşünülebilir, ama çoklu kalıtımı desteklemeyen dillerde (Java, .NET) bu sınıfların başka bir üst sınıftan türemesi gerekirse sorun çıkar (ekrandan, 02:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
