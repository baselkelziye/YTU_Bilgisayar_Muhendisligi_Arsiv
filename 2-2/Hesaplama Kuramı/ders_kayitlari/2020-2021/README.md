# Hesaplama Kuramı Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Hesaplama Kuramı (BLM2502)
* **Hoca:** Dr. Oğuz Altun
* **Dönem:** Bahar
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM2502 - 2

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Dersin Tanıtımı, Hesaplama Kuramına Genel Bakış, Küme Kuramı, Boole Mantığı ve Doğrudan ve Yapıcı İspat | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Olmayana Ergi, Tümevarım, Güvercin Yuvası İlkesi; Alfabe, Dizgi, Dil ve Düzenli Dillere Giriş | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Sonlu Otomatlara Giriş, DFA'nın Biçimsel Tanımı, Dil Bulma ve DFA Tasarımı | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Deterministik Olmayan Sonlu Otomatlar, Hesaplama Ağaçları ve NFA-DFA Denkliği | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | NFA'dan DFA'ya Dönüşümün Tamamlanması, Pompalama Önsavı ve Düzenli Olmayan Dillerin İspatı | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Bağlamdan Bağımsız Gramerler, Türetme, Türetme Ağaçları ve Belirsizlik | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Düzenli İfadeler, Düzenli İfade ile NFA Arası Dönüşümler ve GNFA | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Bağlamdan Bağımsız Diller İçin Pompalama Önsavı, Gramerlerin Sadeleştirilmesi, Chomsky ve Greibach Normal Biçimleri | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Aşağı İtmeli Otomatlar: Yığın, Geçişler, Anlık Betimleme, Örnekler ve Biçimsel Tanım | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | CFG'den PDA'ya Dönüştürme, Dil Hiyerarşisi ve Turing Makinelerine Giriş | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Turing Makinesi Örnekleri, Biçimsel Tanım, Turing ile Tanınabilir Diller ve Fonksiyon Hesaplama | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Turing Makinelerini Birleştirme, Turing Tezi, Turing Makinesi Çeşitleri ve Final Bilgilendirmesi | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> Bu şubede ders İngilizce anlatılmıştır. 27 Nisan (vize haftası) ve 11 Mayıs 2021 (Ramazan Bayramı) haftalarına ait kayıt yoktur. Kaynaklar: Sipser ve Linz.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Dersin Tanıtımı, Hesaplama Kuramına Genel Bakış, Küme Kuramı, Boole Mantığı ve Doğrudan ve Yapıcı İspat
* **Genel Konular:**
  - Dersin tarihi 9 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 00:04'te başlar. Hoca tahta olarak bir tablet uygulaması kullanıyor.
  - Dersin tanıtımı
    - Dersin kodu BLM2502, adı Hesaplama Kuramı (Theory of Computation).
  - Değerlendirme
    - 2 ödev, her biri 15 puan.
  - Kaynak kitap
    - Michael Sipser, *Introduction to the Theory of Computation*, 3. baskı. Tek kaynak budur.
  - Dönemin konuları (geçici liste)
    - İspat türleri.
  - Hesaplama kuramının üç alanı
    - Karmaşıklık kuramı (complexity theory): Bazı problemler neden zor, bazıları neden kolay?
  - Küme kuramı tekrarı
    - Bilinen kümeler, alt küme, kuvvet kümesi, birleşim, kesişim, fark, Kartezyen çarpım, tümleyen.
* **Hocanın Vurgusu:**
  - Ders İngilizce yapılacak.
    - Yabancı öğrenci olsun olmasın dil değişmez. Hoca gerekirse ara sıra Türkçe açıklama yapabilir.
  - Kitaptaki bütün alıştırma ve problemleri çözün.
    - Ödev sayısı az. Dersi gerçekten öğrenmek için kitaptaki işlenen konuların bütün alıştırmalarını yapın.
  - Not ve slayt verilmeyecek.
    - Kendi notunuzu tutun.
  - Bir problemi "kolay" ya da "zor" diye sınıflandırabilmek çok önemli.
    - Problem kolaysa onu hızlı çözen bir algoritma yazarsınız.
  - Turing makineleri en önemli hesaplama modelidir.
    - Turing makinesinin çözemediği bir problemi gerçek bir bilgisayar da çözemez.
* **Detaylı Açıklamalar:** Dersin ilk kısmı tanıtım ve dönem planıyla geçer. Hoca, hesaplama kuramının temel sorusunu şöyle koyar: Bilgisayar donanımı ve yazılımının matematiksel özellikleri nelerdir? Hesaplama nedir, algoritma nedir, bilgisayarların sınırları nelerdir? Amaç, gerçek bilgisayarları yansıtan biçimsel matematiksel modeller kurmaktır. Böylece gerçek bilgisayar kullanmadan bilgisayarlar hakkında matematiksel olarak düşünebiliriz.

### 🔹 Ders 2: Olmayana Ergi, Tümevarım, Güvercin Yuvası İlkesi; Alfabe, Dizgi, Dil ve Düzenli Dillere Giriş
* **Genel Konular:**
  - Dersin tarihi 16 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 00:02'de başlar.
  - Değerlendirme sistemi değişti
    - 3 quiz, her biri 10 puan, toplam 30 puan.
  - İspat teknikleri (devam)
    - Yapıcı ispat örneğinin tekrarı.
  - Düzenli diller (regular languages) ve temel tanımlar
    - Alfabe (alphabet), sembol (symbol), dizgi (string), dizgi uzunluğu, boş dizgi, ters dizgi, alt dizgi.
  - Karışık örnekler ve tanımlar
    - Ondalık, ikili ve birli (unary) sayıların dizgi olarak gösterimi.
* **Hocanın Vurgusu:**
  - Quizler sürpriz olmayacak.
    - Quiz zamanı bir hafta önceden duyurulacak.
  - Olmayana ergi ispatında başta "çelişki elde etmek için varsayalım" diye yazın.
  - Tümevarımda iki adım vardır.
    - Taban adımı (basis) sayısal olarak gösterilir.
  - Dil yalnızca bir dizgi kümesidir.
    - Diller küme olduğu için bütün küme işlemleri dillere uygulanabilir.
  - Bu derste $0^2$ gibi gösterimler sayısal işlem değildir.
    - $0^2 = 00$ demektir, yani birleştirmedir.
* **Detaylı Açıklamalar:** Bir öğrenci, rasyonel sayıların tanımının ispat gerektirip gerektirmediğini sordu. Hoca Türkçe yanıtladı: Bu bir aksiyom da değildir, bir tanımdır. Rasyonel sayılar bir kümedir. İspatta $\sqrt{2}$'nin bu kümenin içinde olmadığını gösterdik.

### 🔹 Ders 3: Sonlu Otomatlara Giriş, DFA'nın Biçimsel Tanımı, Dil Bulma ve DFA Tasarımı
* **Genel Konular:**
  - Dersin tarihi 23 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:08:50'de başlar. Kaydın başı bekleme kısmıdır.
  - Sonlu otomatlara giriş (finite automata)
    - Otomat, giriş şeridindeki (input tape) dizgiyi soldan sağa, her adımda bir sembol okuyarak işler.
  - Durum diyagramı
    - Durumlar (state) çemberle, geçişler (transition) okla gösterilir.
  - Örnek bir makinenin `abbaaabb` dizgisi üzerinde adım adım çalıştırılması
  - Sonlu otomatın biçimsel tanımı: 5'li $(Q, \Sigma, \delta, q_0, F)$
  - Geçiş fonksiyonu $\delta: Q \times \Sigma \to Q$ ve geçiş tablosu
  - Tasarım örneği: tek sayıda 1 içeren ikili dizgiler
* **Hocanın Vurgusu:**
  - Makine, kabul durumuna erken ulaşsa bile durmaz.
    - Bütün giriş okunana kadar devam eder. Karar, son okunan sembolden sonraki duruma göre verilir.
  - Bir makinenin 5'li tanımı sorulduğunda bunu yazabilmelisiniz.
    - Diyagram insan için kolaydır. Bilgisayara verilecek gösterim biçimsel tanımdır.
  - Geçiş fonksiyonu makinenin programıdır.
    - Geçişleri değiştirmek, makinenin programını değiştirmektir.
  - DFA'da hiçbir geçiş atlanamaz.
    - Her durum için her sembolün ne yaptığı yazılmalıdır. Gerekirse tuzak durum (trap / dead state) eklenir.
  - Tasarımda yöntem: önce dilden örnek dizgiler yazın, deseni anlayın.
    - Sonra her durum için her sembolü tek tek ele alın.
* **Detaylı Açıklamalar:** Sonlu otomat, giriş şeridindeki dizgiyi okuyan mantıksal bir makinedir. Okuma kafası (read-write head) şeridin başından başlar. Her adımda bir sembol okur ve sağa kayar. Makine o anki durumuna ve okunan sembole bakarak yeni duruma geçer. Bütün semboller okununca son duruma bakılır.

### 🔹 Ders 4: Deterministik Olmayan Sonlu Otomatlar, Hesaplama Ağaçları ve NFA-DFA Denkliği
* **Genel Konular:**
  - Dersin tarihi 30 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:04:30'da başlar.
  - Deterministik olmayan sonlu otomat (NFA, nondeterministic finite automaton)
    - DFA'dan üç farkı: aynı sembolle birden çok geçiş, boş geçiş (null / $\varepsilon$ transition), bazı geçişlerin hiç yazılmaması.
  - NFA'nın biçimsel tanımı ve geçiş fonksiyonu $\delta: Q \times \Sigma \to 2^Q$
  - NFA nasıl çalışır: paralel hesaplama dalları (computation)
  - NFA'nın kabul ve ret koşulları
  - Hesaplama ağacı (computation tree)
  - NFA dil bulma örnekleri: $\{aa\}$, $(ab)^+$, $(10)^*$, $(ab)^*(aa \cup \varepsilon)$
* **Hocanın Vurgusu:**
  - NFA'da bir dalın kabul etmesi yeterlidir.
    - En az bir hesaplama dalı bütün girişi okuyup kabul durumunda biterse NFA dizgiyi kabul eder.
  - $\varepsilon$ hiçbir zaman alfabede değildir.
    - Bu ders boyunca $\varepsilon$ (bazı kaynaklarda $\lambda$) "girdi okumadan geçiş" anlamına gelen özel bir semboldür.
  - NFA'da bir sembol için geçiş yazılmamışsa o dal, o sembol gelince reddeder.
  - Karmaşık NFA'larda hesaplama ağacı çizin.
    - Hoca bu yöntemi çok faydalı bulduğunu söyledi.
  - NFA tasarlamak daha kolaydır ama NFA daha güçlü değildir.
    - NFA ve DFA aynı dil sınıfını, yani düzenli dilleri, kabul eder.
* **Detaylı Açıklamalar:** 1. **Aynı sembolle birden çok geçiş:** $q_1$'de `a` okununca hem $q_2$'ye hem $q_3$'e gidilebilir. 2. **Boş geçiş:** $q_1 \xrightarrow{\varepsilon} q_2$ ise makine $q_1$'e geldiği anda, girdi okumadan $q_2$'de de olur. İki dal paralel çalışmaya devam eder. 3. **Eksik geçiş:** $\Sigma = \{a, b\}$ iken bir durumdan yalnızca `a` geçişi yazılabilir. O dala `b` gelirse dal reddeder.

### 🔹 Ders 5: NFA'dan DFA'ya Dönüşümün Tamamlanması, Pompalama Önsavı ve Düzenli Olmayan Dillerin İspatı
* **Genel Konular:**
  - Dersin tarihi 6 Nisan 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:03:00'te başlar. Kayıtta iki ara var (yaklaşık 01:01-01:17 ve 02:04-02:14).
  - NFA'dan DFA'ya dönüşüm örneğinin tamamlanması (alt küme yapısı, subset construction)
    - Geçen haftaki örnekte $q_1$'in kabul durumu olduğu düzeltildi.
  - Dönüşümün genel yöntemi
  - Düzenli olmayan diller (non-regular / irregular languages): $a^n b^n$, $w w^R$
  - Güvercin yuvası ilkesi (pigeonhole principle) ve sonlu otomatta tekrar eden durum
  - Pompalama önsavı (pumping lemma) ve üç koşulu
  - Pompalama önsavıyla bir dilin düzenli olmadığını ispatlama yöntemi (çelişkiyle ispat)
* **Hocanın Vurgusu:**
  - Dönüşümde yeni DFA durumu oluştukça her durum için her sembolü sorun.
    - "Bu durum $a$ alınca nereye gider, $b$ alınca nereye gider?" sorusu, yeni durum çıkmayana kadar tekrarlanır.
  - DFA'da her sembolün bir geçişi olmalıdır.
    - NFA'da geçiş yoksa DFA'da $\emptyset$ adlı reddeden bir tuzak durum açılır. Bu durumdan çıkış yoktur.
  - Kabul durumlarını yazmayı unutmayın.
    - NFA'nın bir kabul durumunu içeren her DFA durumu kabul durumudur.
  - Pompalama önsavı yalnızca bir dilin düzenli olmadığını göstermek için kullanılır.
    - Sonlu dil her zaman düzenlidir. Bu yüzden düzenli olmayan her dil sonsuzdur.
  - İspat her zaman çelişkiyle yapılır.
    - Önce dilin düzenli olduğu varsayılır, sonra pompalama önsavından bir çelişki çıkarılır.
* **Detaylı Açıklamalar:** NFA (ders 4'teki örnek): $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_1$, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$. Başlangıç $q_0$. Bu derste $q_1$'in kabul durumu olduğu söylendi; notlarınıza ekleyin.

### 🔹 Ders 6: Bağlamdan Bağımsız Gramerler, Türetme, Türetme Ağaçları ve Belirsizlik
* **Genel Konular:**
  - Dersin tarihi 13 Nisan 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:04:30'da başlar. Kayıtta iki ara var (yaklaşık 00:49-01:02 ve 02:02-02:13).
  - Bağlamdan bağımsız dillere giriş (context-free languages, CFL)
    - $a^n b^n$ ve $w w^R$ düzenli değildir ama bağlamdan bağımsızdır.
  - İngilizce gramer benzetmesiyle gramer kavramı
  - Değişkenler (variables), uç simgeler (terminals), kurallar (rules / productions), başlangıç değişkeni
  - Türetme (derivation) ve gramerin dili
  - Kısa gösterimler: $\Rightarrow^*$ ve $|$
  - CFG'nin biçimsel tanımı (dörtlü)
* **Hocanın Vurgusu:**
  - Her türetme başlangıç değişkeniyle başlar.
    - Başlangıç değişkeni genellikle en üstte ve en solda yazılır, çoğunlukla $S$'dir.
  - Kuralda tek ok ($\to$), türetme adımında kalın ok ($\Rightarrow$) kullanılır.
  - Bir gramerin dilini görmek için önce birkaç dizgi türetin.
    - Sonra deseni küme gösterimiyle yazın.
  - Belirsiz gramer derleyicide sorun çıkarır.
    - Bir kodun tek bir anlamı olmalıdır. Ayrıştırma ağacı kodun anlamıdır.
  - Belirsizlik tanımında dikkat:
    - Ağaçlarla bakıyorsanız: iki farklı türetme ağacı olması yeterlidir, en soldan olmaları gerekmez.
* **Detaylı Açıklamalar:** Küçük bir gramer:

### 🔹 Ders 7: Düzenli İfadeler, Düzenli İfade ile NFA Arası Dönüşümler ve GNFA
* **Genel Konular:**
  - Dersin tarihi 20 Nisan 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:08:00'de başlar. Başta quiz saatinin sistemde yanlış tanımlandığı fark edilip düzeltildi.
  - Düzenli ifadeler (regular expressions)
    - Hoca daha önce kendiniz okuyun dediği bu konuya, vakit olduğu için geri döndü. Bağlamdan bağımsız gramerlere sonra devam edilecek.
  - Düzenli ifadenin anlamı: birleşim, birleştirme (concatenation), Kleene yıldızı
  - $\Sigma$ kullanımı, işlem önceliği, $R^+$ ve $R^k$ gösterimleri
  - $\emptyset$ ve $\varepsilon$ ile ilgili özdeşlikler
  - Dil bulma örnekleri
  - Düzenli ifadeler ile sonlu otomatların denkliği
* **Hocanın Vurgusu:**
  - Aritmetik ifade bir sayı verir, düzenli ifade bir dil verir.
  - $\varepsilon$ (null, boş dizgi) ile $\emptyset$ (boş küme) farklıdır.
    - $\varepsilon$, sembolü olmayan bir dizgidir. Programlamadaki `""` gibidir.
  - İşlem önceliği: önce yıldız, sonra birleştirme, en son birleşim.
  - Bir dilin düzenli olduğunu göstermek için onu tanımlayan bir düzenli ifade yazmak da yeterlidir.
  - Yöntemli dönüşüm (bilgisayarın yapacağı gibi) gereğinden çok durum üretir.
    - İnsan aynı dili çok daha az durumla yazabilir. Elde edilen otomatı sadeleştirebilirsiniz.
* **Detaylı Açıklamalar:** Kareden alınan yöntemli yapı:

### 🔹 Ders 9: Bağlamdan Bağımsız Diller İçin Pompalama Önsavı, Gramerlerin Sadeleştirilmesi, Chomsky ve Greibach Normal Biçimleri
* **Genel Konular:**
  - Dersin tarihi 4 Mayıs 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:06:40'ta başlar. Ders vize haftasından sonraki ilk derstir.
  - Bağlamdan bağımsız diller için pompalama önsavı (pumping lemma for context-free languages)
    - Önsavın ifadesi: $z = uvwxy$ bölünmesi ve üç koşul.
  - Bağlamdan bağımsız gramerlerin sadeleştirilmesi (simplification of CFGs)
    - Yerine koyma (substitution) kuralı.
  - Normal biçimler (normal forms)
    - Chomsky normal biçimi (CNF, Chomsky normal form) ve dönüştürme adımları.
  - Araya giren duyurular: vize ve Quiz 2 sonuçları ders duvarına yüklendi. Vize ortalaması yaklaşık 50-55.
* **Hocanın Vurgusu:**
  - Pompalama önsavının ifadesini yazın ve ezberleyin.
    - Önsavın ispatı derste yapılmadı. Hoca ispatı kitaptan okumanızı istedi.
  - Bağlamdan bağımsız diller en fazla iki sayımı eşleştirebilir.
    - Bir desende üç sayının eşit olması gerekiyorsa ($0^n 1 0^n 1 0^n$ gibi), dil büyük olasılıkla bağlamdan bağımsız değildir. Bunu ispatlamak için pompalama önsavı kullanılır.
  - Pompalama önsavı yalnızca bir dilin bağlamdan bağımsız **olmadığını** ispatlamak için kullanılır.
    - Bir dizginin pompalanabildiğini göstermek, dilin bağlamdan bağımsız olduğunun ispatı değildir. Bağlamdan bağımsız olduğunu ispatlamak için o dili üreten bir gramer vermelisiniz.
  - İki sayı eşleşiyor diye dili hemen bağlamdan bağımsız saymayın.
    - $\{ww\}$ ilk bakışta iki şeyi eşleştiriyor gibi görünür, ama bağlamdan bağımsız değildir.
  - İspatın sonunda çelişkiyi açıkça yazın.
    - "Hiçbir $uvwxy$ bölünmesi pompalanamıyor. Bu bir çelişki. O hâlde $L$'nin bağlamdan bağımsız olduğu varsayımı yanlış."
* **Detaylı Açıklamalar:** Hoca önce düzenli diller için pompalama önsavını hatırlattı. Ardından bağlamdan bağımsız diller için yeni sürümü yazdı. Tahtadaki ifade şöyledir:

### 🔹 Ders 10: Aşağı İtmeli Otomatlar: Yığın, Geçişler, Anlık Betimleme, Örnekler ve Biçimsel Tanım
* **Genel Konular:**
  - Dersin tarihi 18 Mayıs 2021 Salı. Ders Zoom üzerinden yapıldı.
    - Açılış konuşmaları Türkçe, ders anlatımı İngilizce. Asıl anlatım yaklaşık 00:05:30'da başlar.
  - Dönemin kalan planı: 11-14. haftalar, bir quiz ve final.
  - Aşağı itmeli otomat (PDA, pushdown automaton)
    - Durumlar, giriş şeridi ve yeni olarak bir yığın (stack).
  - Anlık betimleme (ID, instantaneous description): $(q, \text{kalan giriş}, \text{yığın})$.
  - Örnek PDA'lar:
    - $M_1$: $\{a^nb^n \mid n \ge 0\}$.
  - Hesaplama ağacı ile $aaabbb$ ve $abba$ girişlerinin adım adım işlenmesi.
  - Kabul koşulu: bütün girişin tüketilmesi ve kabul durumunda bitirmek. Yığının içeriği önemli değil.
* **Hocanın Vurgusu:**
  - Bu derste yığının dibinde başlangıçta özel bir sembol vardır: $\$$.
    - PDA'lar, $\$$ yığının tepesine geldiğinde yığının sonuna ulaşıldığını anlayacak biçimde tasarlanır.
  - Boş yığından çekme yapmaya çalışan PDA durur ve girişi reddeder.
    - PDA'larınızı bu durum hiç oluşmayacak biçimde tasarlayın.
  - PDA'lar deterministik değildir.
    - Aynı (giriş, çekilen) çifti için birden fazla geçiş olabilir. Giriş okumadan ($\varepsilon$ ile) geçiş yapılabilir.
  - Bu dersin kabul kuralı: Giriş tamamen tüketilmeli ve son durum bir kabul durumu olmalı.
    - Yığında ne kaldığı önemli değil.
  - PDA'lar iki değeri eşleştirebilir (ör. $a$ ve $b$ sayısı).
    - Hoca "üç ya da daha fazla değeri eşleştiremez" cümlesini yazdı, sonra emin olmadığı için sildi.
* **Detaylı Açıklamalar:** PDA, daha önce görülen otomatlara benzer: durumlar, geçişler, bir başlangıç durumu, kabul ve ret durumları ve giriş dizgisi vardır. Yeni olan parça **yığındır**. Yığın son giren ilk çıkar (LIFO, last in first out) yapısındadır. Yığın kafası her zaman en son eklenen sembolü gösterir.

### 🔹 Ders 11: CFG'den PDA'ya Dönüştürme, Dil Hiyerarşisi ve Turing Makinelerine Giriş
* **Genel Konular:**
  - Dersin tarihi 25 Mayıs 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:09:00'da başlar.
  - PDA tekrarı: anlık betimleme, hesaplama ağacı, dizgi çekme/itme kısaltması, 7'li tanım, PDA'nın dili.
  - CFG'den PDA'ya dönüştürme (CFL ⊆ PDA dilleri)
    - Üç durumlu genel yapı ve döngüdeki geçişler.
  - PDA'dan CFG'ye dönüştürme (ters yön): derste yapılmadı, kitaptan okunacak.
  - Sipser 2. bölüm bitti. Deterministik bağlamdan bağımsız diller atlandı ve sınava dahil değil.
  - 3. bölüm: Church-Turing tezi ve Turing makinelerine giriş
    - Dil hiyerarşisi: düzenli ⊆ bağlamdan bağımsız ⊆ Turing-tanınabilir.
  - Gelecek hafta quiz var.
* **Hocanın Vurgusu:**
  - Eşdeğerlik ispatlarında iki yön gösterilir: her iki kümenin de diğerinin alt kümesi olduğu.
  - CFG'den PDA'ya dönüştürme kolaydır.
    - PDA'nın yalnız üç durumu vardır ve iki geçiş her zaman aynıdır.
  - Hesaplama ağacını her zaman yazmak zorunda değilsiniz.
    - Çalışacak dalı görebiliyorsanız doğrudan onu yazın.
  - PDA'dan CFG'ye dönüştürme karmaşıktır ve çok büyük bir gramer üretir.
    - Derste yapılmadı. İlgilenen kitaptan okusun.
  - Deterministik bağlamdan bağımsız diller sınavda yok.
* **Detaylı Açıklamalar:** Bir $G$ grameri için $L(G) = L(M)$ olan $M$ şöyle kurulur:

### 🔹 Ders 12: Turing Makinesi Örnekleri, Biçimsel Tanım, Turing ile Tanınabilir Diller ve Fonksiyon Hesaplama
* **Genel Konular:**
  - Dersin tarihi 1 Haziran 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl anlatım yaklaşık 00:06:30'da başlar. Kaydın başı bekleme kısmıdır.
  - Turing makinesi (Turing machine) tekrarı
    - Giriş şeridi iki yönde sonsuzdur. Giriş dışındaki bütün hücrelerde boş sembol (blank, $\square$) vardır.
  - Durma (halt), kabul ve ret kuralları
    - Uygun geçiş yoksa makine o durumda durur.
  - Örnek: $L = \{a^n b^n : n \ge 1\}$ dilini tanıyan Turing makinesi
    - Fikir: her $a$'yı bir $b$ ile eşleştirmek. $a$ yerine $x$, $b$ yerine $y$ yazılır.
  - Ev çalışması: makineyi $\{a^n b^n c^n : n \ge 1\}$ dilini tanıyacak biçimde değiştirmek
  - Turing makinesinin biçimsel tanımı: 7'li $M = (Q, \Sigma, \Gamma, \delta, q_0, \square, F)$
  - Anlık tanım, hesaplama (computation) ve $\vdash^*$ kısaltması
* **Hocanın Vurgusu:**
  - Turing makinesi, bağlamdan bağımsız dillerin (context-free languages) tanıyamadığı dilleri de tanır.
    - Örnek: $a^n b^n c^n$.
  - Bu derste görülen Turing makineleri deterministiktir ve boş geçiş (null / $\lambda$ transition) yoktur.
    - Deterministik olmayan Turing makineleri ileride ayrıca görülecek.
  - Deterministik olsa da Turing makinesi diyagramında her sembol için geçiş çizilmez.
    - Yalnız geçişi olan semboller gösterilir. Bu, DFA diyagramından farklıdır.
  - Giriş tamamen okunmak zorunda değildir.
    - Kafa sola da gidebildiği için makine girişin bir kısmına hiç dokunmadan kabul edip durabilir.
  - Anlık tanımları yazarken çok dikkatli olun.
    - Hoca `aabb` örneğinde bir adımda yön karıştırdı ve hesaplamayı baştan yazdı.
* **Detaylı Açıklamalar:** Turing makinesi, şimdiye kadar görülen otomatlara çok benzer: durumları, geçişleri, kabul ve ret durumları vardır. Fark, şeridin iki yönde sonsuz olması ve kafanın şeride yazıp her iki yöne gidebilmesidir.

### 🔹 Ders 13: Turing Makinelerini Birleştirme, Turing Tezi, Turing Makinesi Çeşitleri ve Final Bilgilendirmesi
* **Genel Konular:**
  - Dersin tarihi 8 Haziran 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı. Dönemin son dersidir.
    - Asıl anlatım yaklaşık 00:05:00'te başlar. Ders iki arayla üç bölümden oluşuyor.
  - Tekrar: $x + y$ ve $2x$ fonksiyonlarını hesaplayan Turing makineleri
    - Bundan sonra makineler büyüdüğü için durum diyagramı yerine yalnız sözde kod (pseudocode) verilecek.
  - Örnek: karşılaştırma fonksiyonu
    - $f(x, y) = 1$ eğer $x > y$; $f(x, y) = 0$ eğer $x \le y$.
  - Turing makinelerini birleştirme (combining Turing machines) ve blok diyagramları
    - Örnek: $f(x, y) = x + y$ eğer $x > y$; $0$ eğer $x \le y$.
  - Turing tezi (Turing's thesis, Church-Turing tezi)
  - Algoritmanın Turing makinesiyle tanımı
  - Turing makinesi çeşitleri (variations)
    - Standart Turing makinesi modeli
* **Hocanın Vurgusu:**
  - Turing tezi önemlidir.
    - Mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir.
  - "Algoritma nedir?" diye sorulursa iki cevap verebilmelisiniz.
    - Problemi çözen adımlar dizisi.
  - Bu derste "Turing makinesi" denince standart model kastedilir.
    - İki yönde sonsuz şerit, tek okuma-yazma kafası, her adımda L ya da R hareketi, deterministik kontrol birimi.
  - Bu derste "güç", bir makine sınıfının tanıyabildiği diller kümesidir.
  - Bütün Turing makinesi çeşitleri standart Turing makinesiyle aynı güçtedir.
    - Daha güçlü görünseler de yeni bir dil tanıyamazlar.
* **Detaylı Açıklamalar:** Örnek fonksiyon:

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
