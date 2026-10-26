# Ders 7 Çalışma Özeti

## Genel Konular

- Dersin tarihi 20 Nisan 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl anlatım yaklaşık 00:08:00'de başlar. Başta quiz saatinin sistemde yanlış tanımlandığı fark edilip düzeltildi.
  - Kayıtta iki ara var (yaklaşık 00:43-00:57 ve 01:39-01:59).
  - Dersin hemen ardından 11:35-11:50 arasında Quiz 2 yapıldı.
- Düzenli ifadeler (regular expressions)
  - Hoca daha önce kendiniz okuyun dediği bu konuya, vakit olduğu için geri döndü. Bağlamdan bağımsız gramerlere sonra devam edilecek.
- Düzenli ifadenin anlamı: birleşim, birleştirme (concatenation), Kleene yıldızı
- $\Sigma$ kullanımı, işlem önceliği, $R^+$ ve $R^k$ gösterimleri
- $\emptyset$ ve $\varepsilon$ ile ilgili özdeşlikler
- Dil bulma örnekleri
- Düzenli ifadeler ile sonlu otomatların denkliği
- Düzenli ifadeden NFA'ya dönüşüm: $(ab \cup a)^*$ ve $(a \cup b)^*aba$
- NFA'dan düzenli ifadeye dönüşüm: sezgisel yol ve yöntemli yol (GNFA, durum söküp atma)
- Not dağılımındaki değişiklik

## Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik ifade bir sayı verir, düzenli ifade bir dil verir.
- $\varepsilon$ (null, boş dizgi) ile $\emptyset$ (boş küme) farklıdır.
  - $\varepsilon$, sembolü olmayan bir dizgidir. Programlamadaki `""` gibidir.
  - $(0 \cup \varepsilon)1^*$ ifadesinden $\varepsilon$'u atıp $01^*$ yazmak yanlıştır.
- İşlem önceliği: önce yıldız, sonra birleştirme, en son birleşim.
- Bir dilin düzenli olduğunu göstermek için onu tanımlayan bir düzenli ifade yazmak da yeterlidir.
- Yöntemli dönüşüm (bilgisayarın yapacağı gibi) gereğinden çok durum üretir.
  - İnsan aynı dili çok daha az durumla yazabilir. Elde edilen otomatı sadeleştirebilirsiniz.
- Karmaşık NFA'larda sezgisel yol hızla büyür ve hata yapmaya açıktır. O zaman yöntemli yolu (GNFA) kullanın.
- Bu konuyu daha önce kitaptan okumuş olmanız bekleniyordu.

## Kısa Tekrar Notları

- Düzenli işlemler: birleşim $R_1 \cup R_2$ (bazen $R_1 + R_2$), birleştirme $R_1 R_2$, yıldız $R^*$.
- $0$ gibi tek sembol aslında $\{0\}$ kümesinin kısa yazımıdır.
- Kümelerde birleştirme: $\{a, b\}\{c\} = \{ac, bc\}$. "$+$" yazımıyla çarpma gibi dağılır: $(a + b)c = ac + bc$.
- $0^* = \{\varepsilon, 0, 00, 000, \dots\}$.
- $R^+ = RR^*$: en az bir tekrar. $R^k$: $R$'nin $k$ kez birleştirilmesi.
- $\Sigma = \{0, 1\}$ ise $\Sigma$, $(0 \cup 1)$ demektir. $\Sigma^*$ bütün dizgilerdir.
- Özdeşlikler:
  - $R \cup \emptyset = R$
  - $R \varepsilon = R$
  - $R \emptyset = \emptyset$
  - $R \cup \varepsilon$, $R$'ye eşit olabilir de olmayabilir de.
  - $\emptyset^* = \{\varepsilon\}$
- Teorem: Bir dil düzenlidir $\iff$ onu tanımlayan bir düzenli ifade vardır.
  - Her sonlu otomat düzenli ifadeye, her düzenli ifade sonlu otomata dönüştürülebilir.
- Düzenli ifadeden NFA'ya yapı taşları:
  - Tek sembol: iki durum, bir geçiş.
  - Birleştirme: birinci makinenin kabul durumları kabul olmaktan çıkar, ikinci makinenin başlangıcına $\varepsilon$ ile bağlanır.
  - Birleşim: yeni başlangıç durumundan iki makineye $\varepsilon$ geçişi.
  - Yıldız: kabul durumlarından başlangıca $\varepsilon$ ile dönüş, ayrıca $\varepsilon$'u kabul eden yeni bir başlangıç durumu.
- Durum söküp atma kuralı: $q_i \xrightarrow{R_1} q_{rip}$, $q_{rip}$'te döngü $R_2$, $q_{rip} \xrightarrow{R_3} q_j$, $q_i \xrightarrow{R_4} q_j$ ise $q_{rip}$ atılınca $q_i \to q_j$ etiketi $(R_1 R_2^* R_3) \cup R_4$ olur.

## Detaylı Açıklamalar

### Düzenli ifade bir dil tanımlar

- $(0 \cup 1)0^*$: $0$ ya da $1$ ile başlayıp ardından istenen sayıda $0$ gelen dizgiler. Örnekler: $0, 1, 00, 10, 000, 100, \dots$
- Parantez açılabilir: $(0 \cup 1)0^* = 00^* \cup 10^*$.
- Yıldızlı bir ifadenin içine dağıtım yapılamaz. Örneğin $0\Sigma^*$ "0 ile başlayan bütün dizgiler"dir; daha fazla açılamaz.
- $01^+ = 011^*$.

### Dil bulma örnekleri ($\Sigma = \{0, 1\}$)

| Düzenli ifade | Dil |
| :--- | :--- |
| $0^* 1 0^*$ | Tam olarak bir tane $1$ içeren dizgiler |
| $(\Sigma\Sigma)^*$ | Uzunluğu çift olan dizgiler ($0$ uzunluk da çifttir) |
| $(0 \cup \varepsilon)1^*$ | $01^* \cup 1^*$ |
| $\emptyset^*$ | $\{\varepsilon\}$ |

- $(0 \cup \varepsilon)1^*$ açılırken $\varepsilon 1^* = 1^*$ olur. $\varepsilon$ birleştirmede etkisizdir.
- $1^* \emptyset = \emptyset$: Birleştirmede ikinci parça boş kümeden gelmek zorunda. Boş kümede eleman olmadığı için sonuçta da eleman yoktur.
- $\emptyset^* = \{\varepsilon\}$: Yıldız işlemi dilden sıfır tane dizgi alıp birleştirebilir. Bu, boş dizgiyi verir. Dil boş olsa bile sıfır dizgi seçmek her zaman mümkündür.

### Düzenli ifadeden NFA'ya: $(ab \cup a)^*$

Kareden alınan yöntemli yapı:

1. $a$ ve $b$ için birer küçük makine kurulur.
2. $ab$: $a$ makinesinin kabul durumu kabul olmaktan çıkar, $\varepsilon$ ile $b$ makinesine bağlanır.
3. $ab \cup a$: yeni bir başlangıç durumundan iki $\varepsilon$ geçişiyle $ab$ ve $a$ makinelerine paralel gidilir.
4. $(ab \cup a)^*$: kabul durumlarından başlangıca $\varepsilon$ ile dönülür. $\varepsilon$ de kabul edilmeli; bu yüzden en başa kabul durumu olan yeni bir başlangıç durumu eklenir ve $\varepsilon$ ile eski başlangıca bağlanır.

Derste bir öğrenci, $a$ ile $b$ arasındaki $\varepsilon$ geçişinin neden gerektiğini sordu. Hoca Türkçe cevap verdi:
- Bu geçişi koymamak hata olmaz.
- Yöntem, bir bilgisayar programının dönüşümü nasıl yapacağını gösterir.
- İnsan daha basit makineler yazabilir.

Sadeleştirme (kitap iki durumlu bir sürüm olduğunu söylüyor). Doğrulanmış iki durumlu bir NFA:

- $q_0$: başlangıç ve kabul durumu. $q_0 \xrightarrow{a} q_0$, $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{b} q_0$.
- Bu makine $(ab \cup a)^*$'ı kabul eder. 12 sembole kadar bütün dizgilerde Python ile denendi.
- Hoca derste benzer bir iki durumlu makineye ulaştı ama sonucu evde çalışmaya bıraktı.

### Düzenli ifadeden NFA'ya: $(a \cup b)^* aba$

Kareden alınan adımlar:

1. $a$, $b$ ve $a \cup b$ makineleri kurulur.
2. $(a \cup b)^*$: yeni kabul eden başlangıç durumu, kabul durumlarından başlangıca $\varepsilon$ dönüşleri.
3. $aba$: $a$, $b$, $a$ makineleri $\varepsilon$ ile ard arda bağlanır. Bu $\varepsilon$'lar atlanıp doğrudan $a, b, a$ zinciri de yazılabilir.
4. Birleştirme: $(a \cup b)^*$ makinesindeki üç kabul durumu kabul olmaktan çıkar. Hepsinden $aba$ makinesinin başına $\varepsilon$ geçişi çizilir.

### NFA'dan düzenli ifadeye: sezgisel yol

- Örnek 1: başlangıçta $a$ döngüsü, $b$ ile kabul durumuna geçiş. İfade: $a^* b$.
- Örnek 2 (kareden): iki durumun ikisi de kabul durumu. $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{b} q_0$.
  - Doğru ifade $(ab)^*(a \cup \varepsilon)$'dur.
  - Hoca arada kaybolduğunu söyleyip ara verdi. Aradan sonra $(ab + ba)^* + a(ba + ab)^*$ yazdı. Bu ifade yanlış; açıklama "Ders sonrası notlar"da.
- Bu örnek, sezgisel yolun karmaşık makinelerde ne kadar hızlı zorlaştığını gösterir.

### NFA'dan düzenli ifadeye: yöntemli yol (GNFA)

GNFA (generalized NFA, genelleştirilmiş NFA): geçiş etiketleri tek sembol değil, düzenli ifadelerdir. Makine bir geçişte o ifadeye uyan bir parça okur.

Dönüşüm için özel biçimdeki GNFA şu koşulları sağlar:

- Başlangıç durumundan diğer bütün durumlara ok vardır. Başlangıç durumuna hiç ok gelmez.
- Tek bir kabul durumu vardır ve başlangıç durumundan farklıdır.
  - Diğer bütün durumlardan kabul durumuna ok gelir. Kabul durumundan hiç ok çıkmaz.
- Başlangıç ve kabul dışındaki her durumdan diğer her duruma ve kendisine birer ok vardır.

NFA'yı özel GNFA'ya çevirme:

1. Yeni bir başlangıç durumu ekle, eski başlangıca $\varepsilon$ ile bağla.
2. Yeni tek bir kabul durumu ekle. Eski kabul durumlarını kabul olmaktan çıkar, yenisine $\varepsilon$ ile bağla.
3. Aynı iki durum arasındaki birden çok etiketi birleşimle tek oka indir (ör. $a, b$ yerine $a \cup b$).
4. Ok olmayan yerlere $\emptyset$ etiketli ok ekle. Bu oklar hiçbir zaman kullanılamaz, dili değiştirmez. Elle çözerken çizilmeyebilir.

Sonra başlangıç ve kabul dışındaki durumlar tek tek atılır ve etiketler birleştirilir. Sona yalnız başlangıç ve kabul durumu kalır. Aradaki okun etiketi aranan düzenli ifadedir.

Örnek (kareden): $1$ başlangıç, $1 \xrightarrow{a} 1$, $1 \xrightarrow{b} 2$, $2 \xrightarrow{a, b} 2$, $2$ kabul.

1. GNFA: $s \xrightarrow{\varepsilon} 1$, $2 \xrightarrow{\varepsilon} acc$, $2$'deki döngü $a \cup b$.
2. $2$ atılır: $1 \xrightarrow{b(a \cup b)^*} acc$.
3. $1$ atılır: $s \xrightarrow{a^* b (a \cup b)^*} acc$.

Sonuç $a^* b (a \cup b)^*$. Bu ifade 10 sembole kadar bütün dizgilerde makineyle karşılaştırıldı, aynı dili verdi.

### Duyurular

- Quiz 2: aynı gün 11:35-11:50, Online YıldızEdu'da. Sistemde önce 11:30-12:26 görünüyordu, ders başında düzeltildi. Soru sayısı 5'ten fazla.
- Not dağılımı: 3 quiz × 10 puan = 30, vize 30, final 40. Bir quiz daha yapılacak.

### Ders sonrası notlar

- Sezgisel örnek 2'de hocanın yazdığı $(ab + ba)^* + a(ba + ab)^*$ yanlıştır.
  - Makine $b$ ile başlayan hiçbir dizgiyi kabul etmez. $q_0$'dan $b$ geçişi yoktur.
  - Hocanın ifadesi $ba$, $baba$, $abba$ gibi dizgileri de üretir.
  - Doğru ifade $(ab)^*(a \cup \varepsilon)$'dur. Python ile 10 sembole kadar bütün dizgilerde denendi: hocanın ifadesi 83 dizgide makineden farklı sonuç verdi (ör. $bababababa$), doğru ifade hiçbirinde farklı değildi.
- Hoca bir yerde "$a \cup \emptyset$ boş küme verir" dedi. Doğrusu $a \cup \emptyset = a$'dır. Boş kümeyle birleşim etkisizdir; boş kümeyle **birleştirme** boş küme verir.
- Hoca özetlerken "düzenli ifadenin boş dizgiyle birleşimi kendisini verir" dedi. Doğru özdeşlik $R \cup \emptyset = R$'dir. Boş dizgiyle birleşim ($R \cup \varepsilon$) $R$'ye eşit olmayabilir. Boş dizgiyle birleştirme $R\varepsilon = R$'dir.
- Hoca $\emptyset^* = \{\varepsilon\}$ sonucunu kendisinin de tam anlamadığını söyledi. Açıklaması: yıldız işlemi sıfır dizgiyi birleştirmeye de izin verir. Sıfır dizginin birleştirmesi boş dizgidir. Bu yüzden her dil için $\varepsilon \in L^*$, $L = \emptyset$ için bile.
- Küme birleştirme örneğinde hoca "$ac$ artı $ab$" dedi. Doğrusu $\{a, b\}\{c\} = \{ac, bc\}$.
- GNFA'da başlangıç durumu için hoca "kendisine ok yok" dedi. Sipser'daki koşul daha geniştir: başlangıç durumuna **hiçbir** durumdan ok gelmez.
- GNFA örneğinin sonunda altyazıda "$a^* b (a \cup b) b^*$" gibi bir ifade geçiyor. Kareye ve hesaba göre doğru sonuç $a^* b (a \cup b)^*$'dır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
