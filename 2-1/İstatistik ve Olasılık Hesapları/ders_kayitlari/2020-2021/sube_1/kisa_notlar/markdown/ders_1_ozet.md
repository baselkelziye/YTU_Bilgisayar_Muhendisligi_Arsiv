# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve öğrenme çıktıları
  - Ders, bilgisayar mühendisliği öğrencilerine olasılık ve istatistiği tanıtır. Konular: kombinatorik ve küme teorisi, olasılık aksiyomları, koşullu olasılık, kesikli ve sürekli rastgele değişkenler (dağılımlar), beklenen değer operatörü ile varyans, kovaryans, çarpıklık (skewness), basıklık (kurtosis) ve momentler, parametre kestirimi (momentler yöntemi ve en çok olabilirlik yöntemi), güven aralıkları, ortalama ve varyans üzerine hipotez testleri (z, t ve ki-kare istatistikleri).
  - Çıktılar: belirsizliği olasılıkla modellemek, sayma ve olasılık kurallarıyla olasılık hesaplamak, merkezi limit teoremini (CLT) uygulamak, çeşitli rastgele modeller için ortalama, varyans, kovaryans ve korelasyon hesaplamak ve parametreleri örnek veriden kestirmek, veriyi histogram ve ampirik yoğunluk fonksiyonuyla göstermek, güven aralıklarını anlamak, ortalama ve varyans için hipotez testi yapmak.
- Olasılık ve istatistiğin tanımı
  - Olasılık teorisi ve istatistik, belirsizlikle (öngörülemezlikle) başa çıkmak için geliştirilmiş matematik dallarıdır.
  - Olasılık teorisi, deney ve veri analizi yoluyla yapılan istatistiksel çıkarımın temel araçlarını sağlar.
  - Olasılık teorisinin merkezi nesneleri rastgele değişkenler ve olaylardır.
- Rastgelelik kavramı ve yazı-tura örneği
  - Paranın hangi yüzünün geleceği; atış kuvveti, paranın başlangıç yönü, parmak ile para arasındaki etki, havadaki türbülans, masa yüzeyinin pürüzsüzlüğü ve havanın yoğunluğu gibi çok sayıda etkene bağlıdır.
  - Bütün etkenler bilinseydi sonuç kesin olarak söylenebilirdi; etkenlerin hepsi ölçülemediği için sonuç öngörülemez. Rastgelelik, bilginin sınırlı olmasından doğar.
  - Tek tek deneyler öngörülemese de çok sayıda tekrarda belirli örüntüler ortaya çıkar. Bu örüntüleri anlatan iki temel sonuç büyük sayılar yasası ve merkezi limit teoremidir.
- Olasılık teorisinin bilgisayar bilimi ve mühendislikteki uygulamaları (ekrandan, 01:25:00)
  - Sistem güvenilirliğinin ve kalitesinin değerlendirilmesi.
  - Ölçüm doğruluğunun yorumlanması.
  - Uygun kalite kontrollerinin sürdürülmesi.
- Tarihsel not: el-Kindî ve frekans analizi (ekrandan, 01:20:00)
  - Hoca, olasılık ve istatistiğin öncüsü olarak el-Kindî'yi (yaklaşık 801-873) tanıttı ve şifreli metinleri çözmek için harf sıklıklarını kullandığını anlattı.
  - Ekranda el-Kindî'nin *On Deciphering Cryptographic Messages* el yazmasının ilk sayfası, kriptanalizde frekans analizinin bilinen en eski tarifi olarak gösterildi.
- Deney, sonuç ve örnek uzay
  - Deney: bir sonuç ya da gözlem veren, tekrarlanabilir bir süreçtir (ekrandan, 01:35:00).
  - Sonuç (outcome): bir deneyin temel (elementer) sonucudur.
  - Örnek uzay: bir deneyin bütün olası sonuçlarının kümesidir; $\Omega$ ya da $S$ ile gösterilir, derste $\Omega$ tercih edilir.
  - Örnek uzayın elemanlarına örnek noktaları ya da temel olaylar (elementary events) denir.
- Olay ve kuvvet kümesi
  - Olay: sonuçların kümesi, yani örnek uzayın bir alt kümesi, yani temel olayların bir kümesidir.
  - Bir A kümesinin kuvvet kümesi $\mathcal{P}(A)$, A'nın bütün alt kümelerinin kümesidir. $n$ sonuçlu bir örnek uzay $2^n$ olası olay verir.
- Kesin olay ve imkânsız olay
  - Kesin olay, deneyin her tekrarında kesinlikle gerçekleşen olaydır; bu olay örnek uzay $\Omega$'nın kendisidir.
  - İmkânsız olay, deneyde hiçbir zaman gerçekleşmeyen olaydır; boş küme $\emptyset$ ile gösterilir.
- Olaylar üzerinde işlemler
  - Olaylar sonuç kümeleri olduğu için olay işlemleri küme teorisine dayanır: birleşim, kesişim, tümleme ve fark.
- Ayrık (bağdaşmaz) ve bütüncül (exhaustive) olaylar
  - Olaylar, bütün ikili (ve daha çoklu) kesişimleri boşsa ayrıktır.
  - Olayların birleşimi örnek uzayın tamamını veriyorsa olaylar bütüncüldür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Olasılık ve istatistiğin önemi
  - Hoca olasılığı "bilim ve teknolojinin motoru" olarak niteledi; yapay zekânın arkasındaki mantığın ve kuantum programlamanın olasılık bilinmeden anlaşılamayacağını, salgın döneminde politikaların istatistiklere göre belirlendiğini söyledi.
  - Program yazmanın tek başına mühendislik olmadığını, mühendislik problemlerini çözmek için olasılık ve istatistiğin iyi bilinmesi gerektiğini vurguladı.
- Ders yazarak takip edilmeli
  - Hoca dersi sunum yerine tablete yazarak anlatıyor ve öğrencilerin de not tutarak izlemesini istiyor.
- Olay bir kümedir, cümle değildir
  - Örnek uzayı $\Omega=\{\text{full, empty, bus, taxi, arrive(s), depart(s)}\}$ olan örnekte, $E_1=\{\text{empty, bus, departs}\}$ olayı "boş otobüs kalktı" cümlesi gibi okunmamalıdır. Deneyin her denemesi tek bir sonuç üretir; sonuç hangi olayların elemanıysa o olaylar gerçekleşmiş olur.
- Gösterim kitaba göre değişir
  - Tümleyen için $\bar{A}$, $A'$, $A^c$ gibi farklı gösterimler vardır. Derste izlenen kitapta (Michael Baron) $\bar{A}$ ve $A^c$ geçer, hoca $\bar{A}$ gösterimini tercih ediyor. Bir kitaba başlarken önce gösterimini öğrenmek gerekir.
- Ayrıklık için bütün kesişimler kontrol edilmeli
  - Bütün olayların ortak kesişimi boş olsa bile ikili kesişimlerden biri boş değilse olaylar ayrık değildir.
- $\mathcal{P}(A)$ olasılık değildir
  - Kuvvet kümesi italik (el yazısı) $\mathcal{P}$ ile gösterilir; olasılık fonksiyonuyla karıştırılmamalıdır.

## Kısa Tekrar Notları

- Deney: sonuç ya da gözlem veren tekrarlanabilir süreç. Deneyin sonucu rastgeledir.
- Örnek uzay $\Omega$: bütün olası sonuçlar. Elemanları temel olaylardır.
- Örnek uzaylar (ekrandan, 01:40:00 ve 01:45:00):
  - Yazı-tura: $\Omega_1=\{T, H\}=\{0,1\}$.
  - Zar: $\Omega_2=\{1,2,3,4,5,6\}$.
  - Bankadaki müşteri sayısı: $\Omega_3=\{0,1,2,3,\dots\}$.
  - Bankaya gelen iki müşteri arasındaki süre: $\Omega_4=\{x \mid x\in[0,\infty)\}$.
- Olay = $\Omega$'nın alt kümesi. $|\mathcal{P}(\Omega)|=2^{|\Omega|}$.
- Kesin olay $\Omega$, imkânsız olay $\emptyset$.
- Birleşim $A\cup B$ ("cup"): A ya da B'den en az biri gerçekleşir. $|A\cup B|\le |A|+|B|$.
- Kesişim $A\cap B$ ("cap"): A ve B aynı anda gerçekleşir. $|A\cap B|\le \min(|A|,|B|)$.
- Tümleyen $\bar{A}$: $A\cup\bar{A}=\Omega$, $A\cap\bar{A}=\emptyset$, $|\bar{A}|=|\Omega|-|A|$.
- Fark $A\setminus B=A\cap\bar{B}$, $B\setminus A=B\cap\bar{A}$.
- Ayrık = bağdaşmaz (incompatible) = karşılıklı dışlayan (mutually exclusive): bütün kesişimler boş.
- Bütüncül (exhaustive): $A\cup B\cup C\cup\dots=\Omega$. $A$ ile $\bar{A}$ hem ayrık hem bütüncüldür.

## Detaylı Açıklamalar

- **Rastgele deney ve örnek uzay.** Bir deney tekrarlandığında her seferinde $a, b, c, d$ gibi olası sonuçlardan biri ortaya çıkar; hangisinin çıkacağı önceden bilinemez, bu yüzden deneyin sonucu rastgeledir (ekrandan, 01:30:00). Örneğin beş denemede sonuçlar $a, d, b, c, d$ olabilir; sonuçların sırayla gelmesi gerekmez ve bir sonuç birden çok kez çıkabilir. Bütün olası sonuçların kümesine örnek uzay denir. Yazı-tura deneyinde örnek uzay $\{T,H\}$'dir ve yazı/tura 0 ve 1 ile de kodlanabilir. Zar atışında örnek uzay $\{1,\dots,6\}$'dır. Bankadaki müşteri sayısını saymak, sıfır dahil negatif olmayan tamsayıları verir (kişi kendini saymazsa banka boş olabilir). İki müşterinin geliş zamanları arasındaki farkı ölçmek ise $[0,\infty)$ aralığında sürekli değerler verir.
- **Olay ve kuvvet kümesi örneği.** $\Omega=\{a,b,1\}$ örnek uzayı liste biçiminde ya da Venn şemasıyla gösterilebilir (ekrandan, 01:50:00). Kuvvet kümesi:
  $$\mathcal{P}(\Omega)=\{\emptyset,\{a\},\{b\},\{1\},\{a,b\},\{a,1\},\{b,1\},\{a,b,1\}\}$$
  Burada $|\Omega|=3$ ve $|\mathcal{P}(\Omega)|=2^3=8$'dir. Bu alt kümelerin her biri bir olaydır. Boş küme de örnek uzayın bir alt kümesidir. Genel sonuç: $n$ sonuçlu bir örnek uzay $2^n$ olası olay verir.
- **Bir olayın gerçekleşmesi.** $\Omega=\{a,b,c,d\}$ ve $E=\{a,b\}$ olsun. Deneyin sonucu $a$ ya da $b$ ise $E$ olayı gerçekleşmiş olur; yani $a,b\in E\subset\Omega$ ve bunlardan biri ortaya çıkarsa $E$ gerçekleşir (ekrandan, 02:20:00). Otobüs/taksi örneğinde (ekrandan, 02:10:00) $E_1=\{\text{empty, bus, departs}\}$, $E_2=\{\text{full, taxi}\}$, $E_3=\{\text{bus, taxi}\}$ ve hepsi $\Omega$'nın alt kümesidir. Sonuç "taxi" ise taxi hem $E_2$'nin hem $E_3$'ün elemanı olduğu için $E_2$ ve $E_3$ aynı anda gerçekleşir, $E_1$ gerçekleşmez.
  - Ders sonrası not: Hoca sonuç "bus" iken $E_1$ olayının gerçekleştiğini söyledi. Bus, $E_3$'ün de elemanı olduğundan bu durumda $E_3$ de gerçekleşir.
- **Kesin ve imkânsız olay.** Para atıldığında sonuç her zaman yazı ya da turadır; zar atıldığında sonuç her zaman 1-6'dan biridir. Bu yüzden deneyin sonucu her zaman örnek uzayın bir elemanıdır ve $\Omega$ kesin olaydır. Örnek uzayda olmayan bir sonuç hiç gelemez; hiçbir sonucu içermeyen olay boş kümedir ve imkânsız olaydır (ekrandan, 02:25:00).
- **Olay işlemleri** (ekrandan, 02:30:00 ve 02:35:00). Birleşim $A\cup B$, iki olayın bütün sonuçlarından oluşur ve olaylardan en az biri gerçekleştiğinde gerçekleşir. Kesişim $A\cap B$ de bir olaydır ve iki olay aynı anda gerçekleştiğinde gerçekleşir; otobüs/taksi örneğinde taxi sonucu $E_2\cap E_3$ içindedir. Tümleyen $\bar{A}$, örnek uzayda A'da olmayan sonuçlardır; $A\cup\bar{A}=\Omega$, $A\cap\bar{A}=\emptyset$ ve $|\bar{A}|=|\Omega|-|A|$ (ekrandan, 02:40:00). Fark $A\setminus B$, A'da olup B'de olmayan sonuçlardır.
- **Fark ve kesişim ilişkisi** (ekrandan, 02:45:00). Venn şemasında iki olayın ortak bölgesi $A\cap B$, yalnız A'ya ait bölge $A\setminus B$, yalnız B'ye ait bölge $B\setminus A$'dır:
  $$B\setminus A=B\cap\bar{A},\qquad A\setminus B=A\cap\bar{B}$$
  Hoca $(A\setminus B)\cup(B\setminus A)$ bölgesini dağılma özelliğiyle açtı:
  $$(A\cap\bar{B})\cup(B\cap\bar{A})=(B\cup A)\cap(B\cup\bar{B})\cap(A\cup\bar{A})\cap(\bar{A}\cup\bar{B})$$
  Burada $B\cup\bar{B}=\Omega$ ve $A\cup\bar{A}=\Omega$'dır; bir olayın $\Omega$ ile kesişimi kendisidir ($\Omega\cap A=A$). Böylece ifade $(A\cup B)\cap(\bar{A}\cup\bar{B})$ olur.
- **Ayrık olaylar** (ekrandan, 02:50:00 ve 02:55:00). $A, B, C, D, \dots$ olayları, bütün olası kesişimleri boşsa ayrıktır: $A\cap B=\emptyset$, $A\cap C=\emptyset$, $B\cap C=\emptyset$, ... ve $A\cap B\cap C=\emptyset$ gibi bütün kombinasyonlar. Dört olaylı Venn örneğinde $A\cap C=\emptyset$ olduğundan A ve C ayrıktır; $A\cap B\neq\emptyset$ olduğundan A ve B ayrık değildir; $C\cap D=\emptyset$ olduğundan C ve D bağdaşmazdır; $C\cap B\neq\emptyset$ olduğundan C ve B ayrık değildir. $A\cap B\cap C\cap D=\emptyset$ olsa da $C\cap B\neq\emptyset$ olduğu için A, B, C, D ayrık değildir.
- **Bütüncül olaylar ve zar örneği** (ekrandan, 03:00:00). Olaylar örnek uzayın tamamını kaplıyorsa bütüncüldür. Zar deneyinde $\Omega=\{1,\dots,6\}$, çift sayılar $A=\{2,4,6\}$, tek sayılar $B=\{1,3,5\}$, asal sayılar $C=\{2,3,5\}$ olsun:
  - $A\cup B\cup C=\Omega$ olduğundan A, B, C bütüncüldür.
  - $A\cap B\cap C=\emptyset$'dir; ama örneğin $A\cap C=\{2\}\neq\emptyset$ olduğundan A, B, C ayrık değildir (ara adım eklendi).
  - $A\cup B=\Omega$ ve $A\cap B=\emptyset$ olduğundan A ve B ayrıktır (ve bütüncüldür).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
