# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 9 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:02'de başlar. İlk yarım saat tanışma ve dersin işleyişidir.
  - Ders iki grupta verilir. Diğer grubu Ahmet Hoca yürütür. Slaytlara bu dönem yeni bölümler eklendi.
- Dersin işleyişi ve değerlendirme
  - İki vize ve bir final var. Vize iki kısım olabilir: çoktan seçmeli test ve yazılı kısım. Yazılı cevaplar Drive'a yüklenir.
  - Ödev yok. Bazı konularda algoritma soruları verilecek. Doğru çalışan kodu ilk gönderen 10 kişi bonus alır. Dil C.
  - Bonus, harf notu sınırında (ör. 67-69) notu bir üst harfe çıkarır.
  - Pandemi döneminde değerlendirme: yıl içi %60, final %40. Final notu 40'ın altındaysa öğrenci başarısız olur.
  - Slaytlar hocanın AVESİS sayfasında. Eylül 2020'den sonra yüklenenler güncel olanlardır; topluca indirmeyin.
  - Duyurular AVESİS ve USİS üzerinden yapılır. E-posta için hocanın Gmail adresi önerildi.
- Dönemin konu başlıkları
  - Ayrık matematiğe giriş.
  - Mantık ve ispatlar: önermeler, niceleyiciler, ispat yöntemleri.
  - Boole cebri ve kombinasyonel (combinatorial) devreler, Karnaugh diyagramları.
  - Matematiğin dili: matrisler, kümeler, diziler, sayı sistemleri, bağıntılar. Sayı teorisi.
  - Algoritmalar, karmaşıklık ve asimptotik gösterim.
  - Graf teorisi, ağaçlar, kromatik polinomlar.
  - Otomatlar, gramerler ve diller.
- Ders kitabı
  - Ana kaynak: Rosen, *Discrete Mathematics and Its Applications*. Slaytların yaklaşık %95'i bu kitaptan hazırlandı.
  - Ek kaynak olarak bir "Ayrık İşlemsel Yapılar" ders notu da anıldı.
- Ayrık matematik nedir?
  - Bilgisayar sürekli verilerle çalışamaz. Sürekli bir sinyalden belirli aralıklarla örnek (sample) alınır. İşlem bu ayrık örnekler üzerinde yapılır.
  - Ayrık matematik, süreklilik içermeyen ayrık yapılarla ilgilenen matematik dalıdır.
  - Ayrık nesne örnekleri: tam sayılar, bir programın işlem adımları, haritada bir yolun durakları.
- Ayrık matematikle çözülen problem örnekleri
  - Belirli kurallara uyan kaç şifre yazılabilir?
  - İki bilgisayar arasında bağlantı var mı, kaç farklı bağlantı var?
  - E-posta spam mı? Mesajdan özellikler çıkarılır ve bu ayrık verilerle karar verilir.
  - İki şehir arasındaki en kısa yol. Her şehri bir kez gezip başlangıca dönen en kısa tur.
  - Bir listenin sıralanması, gereken adım sayısı ve algoritmanın doğruluğunun ispatı.
- Kombinatoryal problem türleri
  - Varlık problemi: tenis fikstürü örneği.
  - Sayma problemi: yatırım kulübünde başkan-sayman dönüşümü örneği.
  - Optimizasyon problemi: işçilere iş atama, ders programı, pilot-uçuş eşleştirme.
- PERT örneği: 30 günde bitmesi gereken 11 iş (A-K) ve öncelik grafiği.
- Mantık ve önermeler (proposition)
  - Önerme: doğru ya da yanlış değeri olan ifade. Önermeler $p, q, r, s, t$ ile gösterilir.
  - Bağlaçlar: AND (conjunction, $\land$), OR (inclusive disjunction, $\lor$), XOR (exclusive disjunction, $\oplus$), NOT (negation, $\lnot p$ veya $p'$), ise ($\rightarrow$), ancak ve ancak ($\leftrightarrow$).
  - AND, OR, XOR, NOT ve $p \rightarrow q$ doğruluk tabloları.
  - Birleştirilmiş önermeler ve $(p \lor q) \land r$ doğruluk tablosu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritma bu bölümde her şeyin temelidir.
  - Veri Yapıları ve Algoritma Analizi derslerinde kalmanın asıl sebebi algoritma mantığının oturmamasıdır.
  - Algoritma ancak çalışarak gelişir: akış çiz, kod yaz, çalıştır, hatayı bul, düzelt.
- Koda hemen başlamayın.
  - Terzi gibi önce ölçü alın: blok şeması çizin, modülleri belirleyin, sonra kodlayın.
  - Uç durumları (edge case) mutlaka önceden düşünün.
- Aynı işi yapan iki programdan karmaşıklığı düşük ve hızlı olan tercih edilir.
- Graf ve ağaçlar sonraki birçok dersin temelidir. Bu konuları çok dikkatli dinleyin.
- Terimlerin hem İngilizcesini hem Türkçesini öğrenin. Kaynakların çoğu İngilizcedir.
- Ayrık düşünmek, bir problemi parçalarına ayırabilmektir. Metin olarak verilen problem önce bir modele (ör. graf) çevrilir, sonra kodlanır.
- Doğruluk tablosu satırları rastgele yazılmaz.
  - $n$ değişken için $2^n$ satır vardır.
  - Sağdaki sütun birer birer, sonraki ikişer ikişer, sonraki dörder dörder değişir. Her satır $0$'dan $2^n-1$'e kadar bir ikilik sayıdır.
- Kısa hatırlama yolları:
  - AND çarpmadır: iki giriş de 1 ise 1.
  - OR toplamadır: iki giriş de 0 ise 0.
  - XOR çıkarmadır: girişler aynıysa 0, farklıysa 1.
  - $p \rightarrow q$ yalnız $p=1$, $q=0$ iken 0'dır.
- Önermeleri olumlu biçimde tanımlayın. Olumsuzluk, NOT bağlacıyla sonradan eklenir.

## Kısa Tekrar Notları

- Ayrık matematik: süreklilik içermeyen, tek tek ayrılabilen yapıları inceler.
- Değerlendirme: 2 vize + final; yıl içi %60, final %40. Ödev yok, bonus algoritma soruları var.
- Önerme: doğru (T, 1) ya da yanlış (F, 0) değeri olan ifade.
- $n$ önerme için doğruluk tablosunda $2^n$ satır olur.
- AND: $p \land q = 1$ yalnız $p=q=1$ iken.
- OR: $p \lor q = 0$ yalnız $p=q=0$ iken.
- XOR: $p \oplus q = 1$ yalnız $p \neq q$ iken.
- NOT: $\lnot p$, $p$'nin tersidir.
- Koşullu önerme: $p \rightarrow q = 0$ yalnız $p=1, q=0$ iken. $p$ hipotez (hypothesis), $q$ sonuç (conclusion).
- PERT: her iş, kendinden önceki işlerin en geç bitiş zamanına kendi süresi eklenerek biter. En uzun yol kritik yoldur.

## Detaylı Açıklamalar

Bu ders tanışma, dersin işleyişi ve mantık konusuna girişle geçti. Aşağıda dersin sayısal örnekleri ve doğruluk tabloları toplu olarak verilmiştir.

### Ayrık ve sürekli

Bir ses kaydı sürekli bir dalgadır. Bilgisayar bu dalgayı belirli zaman aralıklarında örnekler. Örnekler saklanır ve işlenir. Gerekirse bu örneklerden orijinal sinyal yeniden elde edilir. Matematiğin "ayrık" sıfatı buradan gelir: bilgisayar yalnız tek tek ayrılmış verilerle çalışabilir.

### PERT örneği

Bir mağaza bayram ilanı için 11 iş yapacak. İşler sırayla yapılırsa toplam süre 37 gündür. Sürenin 30 günü geçmemesi gerekiyor. Bazı işler aynı anda yapılabilir. Her iş bir düğüm, öncelik ilişkisi bir kenardır.

| İş | Süre (gün) | Önce bitmesi gereken | En erken bitiş |
| :---: | :---: | :---: | :---: |
| A | 3 | - | 3 |
| B | 2 | - | 2 |
| C | 2 | A, B | 5 |
| D | 4 | C | 9 |
| E | 3 | C | 8 |
| G | 3 | C | 8 |
| H | 1 | G | 9 |
| F | 2 | D, E | 11 |
| I | 5 | F | 16 |
| J | 2 | H, I | 18 |
| K | 10 | J | 28 |

- Bir işin bitişi, önceki işlerin en geç bitişi artı kendi süresidir.
- Bütün işler 28 günde biter. 37 günlük sıralı plandan çok daha kısadır.
- Kritik yol: A, C, D, F, I, J, K. Bu yoldaki bir gecikme bütün projeyi geciktirir.
- Bu yöntem PERT (Program Evaluation and Review Technique) olarak bilinir.

### Pilot-uçuş eşleştirmesi

Pazartesi sabahı Ankara'dan 7 ülkeye uçuş var. 7 pilotun her biri yalnız bazı ülkelere uçmak istiyor. Ülkeler bir kümede, pilotlar başka bir kümede gösterilir. Bir pilot bir ülkeye uçmak istiyorsa arada kenar çizilir. Aynı kümenin elemanları arasında kenar yoktur. Bu yapı iki parçalı graftır (bipartite graph). Amaç, isteklere en çok uyan eşleştirmeyi bulmaktır.

### Doğruluk tabloları

İki önerme için 4, üç önerme için 8 satır vardır.

| $p$ | $q$ | $p \land q$ | $p \lor q$ | $p \oplus q$ | $p \rightarrow q$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 0 | 0 | 1 |

- NOT için $p=1$ ise $\lnot p = 0$, $p=0$ ise $\lnot p = 1$.
- Örnek: "Cüneyt programcıdır ($p$)" ve "Zeynep avukattır ($q$)" doğru olsun.
  - $p \lor q$ doğrudur.
  - "Ne Cüneyt programcıdır ne de Zeynep avukattır" ifadesinde iki önerme de olumsuzdur. XOR sonucu 0 olur.
  - "Cüneyt programcıdır ama Zeynep avukat değildir" ifadesinde XOR sonucu 1 olur.
  - $p \rightarrow q$ doğrudur. "Cüneyt programcı ise Zeynep avukat değildir" ifadesi yanlıştır, çünkü $1 \rightarrow 0 = 0$.

### $(p \lor q) \land r$ doğruluk tablosu

| $p$ | $q$ | $r$ | $(p \lor q) \land r$ |
| :---: | :---: | :---: | :---: |
| T | T | T | T |
| T | T | F | F |
| T | F | T | T |
| T | F | F | F |
| F | T | T | T |
| F | T | F | F |
| F | F | T | F |
| F | F | F | F |

Önce parantez içindeki OR hesaplanır, sonra sonuç $r$ ile AND'lenir.

### XOR ve Assembly

Assembly dilinde bir yazmacı sıfırlamanın iki yolu vardır: `SUB A, A` ve `XOR A, A`. İkisi de aynı değeri kendisinden "çıkarır" ve sonucu 0 yapar. Hoca XOR tablosunu bu yüzden çıkarma ile ilişkilendiriyor: aynı iki bit için sonuç 0'dır.

### Ders sonrası notlar

- **Soru cümleleri önerme değildir.** Derste "Saatin var mı?" sorusunun cevabı evet/hayır olduğu için önerme sayıldı. Rosen'in tanımına göre önerme bildirme (declarative) cümlesidir. Soru, emir ve dilek cümleleri önerme değildir. "Benim saatim var" bir önermedir; "Saatin var mı?" değildir.
- **"Önerme olumsuz olamaz" bir kitap kuralı değildir.** "Cüneyt programcı değildir" de geçerli bir önermedir. Derste kastedilen bir yazım alışkanlığıdır: değişkenler olumlu cümlelerle tanımlanır, olumsuzluk $\lnot$ ile gösterilir.
- **1 ile 2 arasında tam sayı yoktur.** Derste "1 ile 2 arasında tam sayı olarak sonsuz sayıda sayı var" dendi. 1 ile 2 arasında sonsuz sayıda reel sayı vardır, ama hiç tam sayı yoktur. Bilgisayar bu reel sayıların ancak sonlu sayıda ayrık yaklaşığını tutabilir.
- **PERT örneğinde süre birimi gündür.** Derste bazen "saat" dendi; tablo gün cinsindendir. Ayrıca "B işi A'dan uzun sürüyor" dendi. Doğrusu: A 3 gün, B 2 gün sürer, C'nin başlaması için A'nın bitmesi (3 gün) beklenir.
- **PERT sonuçları Python ile doğrulandı.** Bütün işler 28 günde biter, sıralı toplam 37 gündür.
- **Fortran'da örtük tip.** Derste "I, J, K, L otomatik integer" dendi. Fortran'da adı I, J, K, L, M, N harfleriyle başlayan değişkenler tanımlanmasa da `INTEGER` kabul edilir. Diğer harflerle başlayanlar `REAL` olur.
- **Fulye serisi = Fourier serisi.** Altyazıda "Fulye" diye geçiyor.
- **XOR aslında mod 2 toplamadır.** Mod 2'de toplama ile çıkarma aynı sonucu verir. Bu yüzden "XOR çıkarmadır" hatırlatması tabloyu doğru verir.
- **AND ve OR sembolleri.** AND $\land$ (ters V), OR $\lor$ (V) ile gösterilir. Slaytta AND için `^` işareti kullanılmıştır.
- **Altyazı hataları:** "Rose'nin kitabı" Rosen'dir. "AVSİZ" AVESİS'tir. "Nifton" Newton'dur; bir öğrenci slayttaki resmin aslında George Washington olduğunu söyledi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
