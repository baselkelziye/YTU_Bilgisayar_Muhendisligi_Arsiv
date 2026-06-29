# Biyoenformatiğe Giriş Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

## Genel Bilgiler

- **Ders Adı:** Biyoenformatiğe Giriş
- **Dersi Veren Akademisyen:** Prof. Dr. Nizamettin Aydın
- **Akademik Yıl:** 2020-2021
- **Dönem:** Bahar
- **İlk Ders Tarihi:** 2 Nisan 2021

## Müfredat ve Belge Dizini

| Ders | Ders İçeriği / Konu Başlığı | Markdown Kaynak Notu | PDF İndirme |
| --- | --- | --- | --- |
| Ders 1 | Biyoenformatiğe giriş, biyolojik veri ve disiplinler arası kapsam | [ders_1.md](altyazi_ozetleri/ders_1.md) | [ders_1.pdf](ders_1.pdf) |
| Ders 2 | Biyoenformatik yazılımları, web araçları, komut satırı ve Linux | [ders_2.md](altyazi_ozetleri/ders_2.md) | [ders_2.pdf](ders_2.pdf) |
| Ders 3 | Moleküler biyoloji temelleri, hücre, DNA, RNA, protein ve omics kavramları | [ders_3.md](altyazi_ozetleri/ders_3.md) | [ders_3.pdf](ders_3.pdf) |
| Ders 4 | Programlama temelleri, algoritmik düşünme, Perl ve Python bağlamı | [ders_4.md](altyazi_ozetleri/ders_4.md) | [ders_4.pdf](ders_4.pdf) |
| Ders 5 | Perl'de örüntü eşleme, bağlama işleci ve değiştirme işlemleri | [ders_5.md](altyazi_ozetleri/ders_5.md) | [ders_5.pdf](ders_5.pdf) |
| Ders 6 | İkili dizi hizalama, DNA/protein karşılaştırması ve homoloji-benzerlik ayrımı | [ders_6.md](altyazi_ozetleri/ders_6.md) | [ders_6.pdf](ders_6.pdf) |
| Ders 9 | Dinamik programlama ile dizi hizalama, matris doldurma ve traceback | [ders_9.md](altyazi_ozetleri/ders_9.md) | [ders_9.pdf](ders_9.pdf) |
| Ders 11 | Çoklu dizi hizalama, korunmuş bölgeler, evrimsel ve işlevsel çıkarım | [ders_11.md](altyazi_ozetleri/ders_11.md) | [ders_11.pdf](ders_11.pdf) |
| Ders 12 | Akademik içerik bulunmayan kayıt | [ders_12.md](altyazi_ozetleri/ders_12.md) | [ders_12.pdf](ders_12.pdf) |
| Ders 13 | Veri analizi, örneklem, popülasyon, betimsel ve çıkarımsal istatistik | [ders_13.md](altyazi_ozetleri/ders_13.md) | [ders_13.pdf](ders_13.pdf) |
| Ders 14 | Görselleştirme, algı, veri sunumu ve etkileşimli arayüzler | [ders_14.md](altyazi_ozetleri/ders_14.md) | [ders_14.pdf](ders_14.pdf) |

## Detaylı Özetler

### Ders 1: Biyoenformatiğe Giriş

- **Genel konular**
  - Biyoenformatik, biyolojik verilerin bilgisayar destekli yöntemlerle saklanması, işlenmesi, analiz edilmesi ve yorumlanması üzerine kuruludur.
  - Dersin kapsamı; DNA, RNA, protein dizileri, genomik veri, veri tabanı kullanımı, dizi analizi ve hesaplamalı yöntemleri içerir.
  - Biyolojik diziler bilgisayar ortamında çoğu zaman karakter dizileri olarak temsil edilir; bu nedenle algoritma, veri yapısı ve metin işleme becerileri temel öneme sahiptir.
- **Hocanın özellikle vurguladığı kısımlar**
  - Biyoenformatik disiplinler arasıdır; biyoloji, bilgisayar bilimi, istatistik ve veri analizi birlikte düşünülmelidir.
  - Bilgisayar mühendisliği bakış açısı yalnızca hazır araç kullanmayı değil, araçların çalışma mantığını ve geliştirilebilirliğini anlamayı gerektirir.
- **Detaylı açıklamalar**
  - Modern biyolojide deneysel yöntemlerle çok büyük veri üretilir. Biyoenformatik, bu verinin elle incelenemeyecek kadar büyük olduğu durumlarda anlamlı bilgi üretmeye yarayan hesaplamalı yaklaşımları sağlar.
  - Ders, önce biyolojik kavramların veri olarak ne ifade ettiğini tanıtır; sonra bu veriler üzerinde arama, hizalama, karşılaştırma ve yorumlama gibi hesaplamalı işlemleri ele alır.

### Ders 2: Biyoenformatik Araçları ve Çalışma Ortamları

- **Genel konular**
  - Biyoenformatik yazılımları web tabanlı/grafik arayüzlü araçlar ve komut satırı araçları olarak iki ana kültürde incelenir.
  - Web araçları veri tabanlarına erişim, genom tarayıcıları ve temel analizler için erişilebilir çözümler sağlar.
  - Komut satırı araçları tekrarlanabilir, otomatikleştirilebilir ve büyük ölçekli analizler için daha güçlüdür.
- **Hocanın özellikle vurguladığı kısımlar**
  - Linux/Unix ortamları biyoenformatik yazılımlarında yaygındır; komut satırı becerisi ileri analizler için önemlidir.
  - Bilgisayar mühendisleri araç kullanıcısı olmanın ötesinde araç geliştirici rolü de üstlenebilir.
- **Detaylı açıklamalar**
  - Web tabanlı sistemler programlama bilmeyen kullanıcıların biyolojik veriyle çalışmasını kolaylaştırır. Buna karşılık komut satırı, çok sayıda dosya üzerinde aynı işlemi yürütme ve analiz akışlarını betiklerle kurma avantajı sağlar.
  - Genom tarayıcıları biyolojik dizilerin ve anotasyonların görsel olarak incelenmesini sağlar; veri tabanları ise genetik bilginin saklanması ve erişimi için temel altyapıdır.

### Ders 3: Moleküler Biyoloji Temelleri

- **Genel konular**
  - Moleküler biyoloji, biyolojik olayları moleküler düzeyde inceler.
  - Hücre canlı organizmaların yapısal ve işlevsel temel birimidir.
  - DNA genetik bilgiyi taşır, RNA bilgi aktarımında rol alır, proteinler hücresel işlevleri yerine getirir.
  - Genom, transkriptom ve proteom kavramları farklı biyolojik veri düzeylerini ifade eder.
- **Hocanın özellikle vurguladığı kısımlar**
  - Biyoenformatik analizlerin doğru yorumlanması için verinin biyolojik kaynağı bilinmelidir.
  - Amaç ayrıntılı moleküler biyoloji öğretmek değil, hesaplamalı analizleri anlayacak temel kavram altyapısını kurmaktır.
- **Detaylı açıklamalar**
  - Genom bir organizmanın tüm genetik bilgisini, transkriptom belirli koşullarda üretilen RNA moleküllerini, proteom ise proteinlerin bütününü temsil eder.
  - Bu ayrım veri analizinde önemlidir; çünkü genom nispeten kalıcı bilgi sunarken transkriptom ve proteom hücre tipi, çevresel koşul ve hastalık durumuna göre değişebilir.

### Ders 4: Programlama ve Biyoenformatikte Dil Seçimi

- **Genel konular**
  - Programlama, problemi algoritmaya dönüştürme ve bilgisayarın yürüteceği adımları tanımlama sürecidir.
  - Temel programlama yapıları sıralı yürütme, koşullu dallanma ve yinelemedir.
  - Perl, metin işleme ve düzenli ifade desteği nedeniyle biyoenformatikte tarihsel olarak yaygın kullanılmıştır.
  - Python, veri bilimi, yapay zeka ve genel amaçlı programlama bağlamında önemlidir.
- **Hocanın özellikle vurguladığı kısımlar**
  - Kod yazmak, problemi küçük alt görevlere ayırarak algoritmik düşünmeyi gerektirir.
  - Biyolojik dizilerin metin gibi işlenmesi Perl'i biyoenformatikte güçlü hale getirir.
- **Detaylı açıklamalar**
  - Biyoenformatik problemleri çoğu zaman dosya okuma, dizileri ayırma, motif arama, sayma ve raporlama gibi adımlardan oluşur.
  - Adım adım iyileştirme yaklaşımı karmaşık analizleri yönetilebilir parçalara böler ve hata ayıklamayı kolaylaştırır.

### Ders 5: Perl'de Örüntü Eşleme

- **Genel konular**
  - Perl'de örüntü eşleme, metin içinde belirli kalıpları arama ve gerektiğinde değiştirme işlemlerini kapsar.
  - Eşleme işlemi için arama yapılacak metin, aranan örüntü ve bunları bağlayan işlem gerekir.
  - `=~` işleci, bir değişkenin belirli örüntüyle eşleşip eşleşmediğini test eder.
- **Hocanın özellikle vurguladığı kısımlar**
  - Örüntü eşleme biyoenformatiğin merkezindedir; DNA veya protein dizilerinde motif arama string arama problemidir.
  - Perl betiklerinde arama, eşleme veya değiştirme işlemleri çok sık kullanılır.
- **Detaylı açıklamalar**
  - Biyolojik diziler çoğu zaman karakter dizisi olarak tutulduğu için düzenli ifadeler ve örüntü eşleme teknikleri motif bulma, veri temizleme ve format dönüştürme için kullanılır.
  - Yer değiştirme işlemleri, dosyalardaki gereksiz karakterleri temizleme veya sonuçları rapor formatına dönüştürme gibi pratik görevlerde kullanılır.

### Ders 6: İkili Dizi Hizalama

- **Genel konular**
  - İkili dizi hizalama, iki DNA, RNA veya protein dizisinin benzerlik derecesini değerlendirmek için kullanılır.
  - Protein dizileri bazı durumlarda DNA dizilerinden daha bilgilendirici olabilir; DNA dizileri ise polimorfizm ve düzenleyici bölge analizlerinde doğrudan önemlidir.
  - Dizi benzerliği ölçülebilir bir durumdur; homoloji ortak atadan gelme ilişkisidir.
- **Hocanın özellikle vurguladığı kısımlar**
  - Benzerlik ve homoloji aynı şey değildir; yüksek benzerlik doğrudan homoloji ifadesi olarak kullanılmamalıdır.
  - Hangi dizi türünün kullanılacağı analiz amacına bağlıdır.
- **Detaylı açıklamalar**
  - Hizalama işlemi eşleşme, uyuşmazlık ve boşlukları değerlendirerek dizilerin hangi bölgelerde korunduğunu veya farklılaştığını gösterir.
  - BLAST gibi veritabanı arama araçları ikili hizalama düşüncesine dayanır ve biyolojik işlev ya da evrimsel ilişki çıkarımı için kullanılır.

### Ders 9: Dinamik Programlama ile Hizalama

- **Genel konular**
  - Dinamik programlama, dizi hizalama problemlerinde optimal hizalamayı bulmak için kullanılan temel yöntemdir.
  - İşlem matris kurma, matrisi başlatma, puanlama şemasına göre doldurma ve geriye izleme adımlarından oluşur.
  - Global, lokal ve örtüşme hizalamaları farklı biyolojik sorulara yanıt verir.
- **Hocanın özellikle vurguladığı kısımlar**
  - Dinamik programlama bir matris doldurma problemidir.
  - Geriye izleme, yalnız skoru değil hizalamanın nasıl oluştuğunu gösterir.
  - Match, mismatch ve gap puanları sonucu etkiler.
- **Detaylı açıklamalar**
  - Her matris hücresi, o noktaya kadar olan en iyi ara çözümü temsil eder. Bu sayede tüm hizalamaları tek tek denemek yerine sistematik bir hesaplama yapılır.
  - Matris doldurulduktan sonra en iyi skora götüren yol takip edilerek karakter eşleşmeleri, boşluklar ve uyuşmazlıklar içeren hizalama üretilir.

### Ders 11: Çoklu Dizi Hizalama

- **Genel konular**
  - Çoklu dizi hizalama, üç veya daha fazla dizinin aynı anda hizalanmasıdır.
  - Korunmuş sütunlar, işlevsel veya yapısal açıdan önemli bölgeleri gösterebilir.
  - Dizi sayısı arttıkça olası hizalama kombinasyonları hızla büyür.
- **Hocanın özellikle vurguladığı kısımlar**
  - Çoklu hizalama ikili hizalamanın basit bir uzantısı değildir; hesaplama karmaşıklığı çok daha yüksektir.
  - Pratikte optimal sonucu garanti etmeyen fakat hızlı ve bellek açısından uygun yaklaşık yöntemler kullanılır.
- **Detaylı açıklamalar**
  - Çoklu hizalama gen ve protein ailelerinde korunmuş motifleri, domainleri ve evrimsel ilişkileri belirlemek için kullanılır.
  - Evrimsel süreçte korunan bölgeler, molekülün işlevi için kritik olabilir; değişen bölgeler ise işlev farklılaşmasıyla ilişkilendirilebilir.

### Ders 12: Akademik İçerik Bulunmayan Kayıt

- **Genel konular**
  - Bu kayıtta akademik/teorik ders içeriği işlenmemiştir.
- **Hocanın özellikle vurguladığı kısımlar**
  - Akademik kavram, yöntem veya teknik açıklama bulunmamaktadır.
- **Detaylı açıklamalar**
  - Kayıt organizasyonel nitelikte olduğu için çalışma özeti akademik içerik içermemektedir.

### Ders 13: İstatistik ve Veri Analizi

- **Genel konular**
  - İstatistik, veriyi anlamlı niceliklerle özetleme ve örneklemden popülasyon hakkında çıkarım yapma yöntemidir.
  - Popülasyon incelenmek istenen tüm kümedir; örneklem bu kümeden seçilen temsil edici alt kümedir.
  - Betimsel istatistik veriyi açıklar; çıkarımsal istatistik genelleme yapar.
  - Makine öğrenmesi, yapay zeka ve veri bilimi istatistiksel temellere dayanır.
- **Hocanın özellikle vurguladığı kısımlar**
  - Örneklemin popülasyonu temsil etmesi, çıkarımların güvenilirliği için kritiktir.
  - İstatistiksel düşünce, modern veri analizi ve modelleme süreçlerinden ayrı düşünülemez.
- **Detaylı açıklamalar**
  - Popülasyonun tamamını ölçmek çoğu zaman mümkün değildir. Bu yüzden örneklem kullanılır; fakat örneklem yanlış seçilirse sonuçlar hatalı genellemelere yol açar.
  - Biyoenformatikte istatistik gen ifadesi, varyasyon, sınıflandırma ve biyolojik hipotez testleri gibi alanlarda kullanılır.

### Ders 14: Görselleştirme ve Algı

- **Genel konular**
  - Görselleştirme, veri veya kavramların insanların anlayabileceği grafik temsillere dönüştürülmesidir.
  - Büyük ve karmaşık biyoenformatik verilerinin kullanıcıya anlaşılır aktarılması etkili arayüzler gerektirir.
  - Algı, görselleştirme tasarımında temel kavramdır; insan duyuları bilgiyi yorumlama biçimini etkiler.
  - Etkileşimli sistemler filtreleme, yakınlaştırma ve seçme gibi işlemlerle veri keşfini kolaylaştırır.
- **Hocanın özellikle vurguladığı kısımlar**
  - Görselleştirme yalnızca resim üretmek değildir; veri içindeki ilişkileri ve örüntüleri anlaşılır hale getirmektir.
  - Veri miktarı arttıkça iyi insan-veri arayüzlerine duyulan ihtiyaç artar.
- **Detaylı açıklamalar**
  - Genom konumları, hizalama sonuçları, gen ifade matrisleri, protein yapıları ve biyolojik ağlar farklı görselleştirme teknikleri gerektirir.
  - Görsel temsil, eğilimleri, aykırı değerleri, kümelenmeleri ve ilişkileri hızlı fark etmeyi sağlar. Bu nedenle biyoenformatikte analiz kadar sunum ve keşif arayüzü de önemlidir.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
