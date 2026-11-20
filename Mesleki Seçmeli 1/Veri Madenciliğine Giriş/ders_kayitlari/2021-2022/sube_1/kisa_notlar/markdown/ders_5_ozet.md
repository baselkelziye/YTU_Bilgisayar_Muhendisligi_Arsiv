# Ders 5 Çalışma Özeti

## Genel Konular

- Bir süreç olarak veri temizleme (ekrandan, 00:05:00)
  - Veride uyumsuzluk (discrepancy) olabilir: kullanıcı bir yerde doğum tarihini, başka yerde yaşını girmiş ve ikisi tutmuyor; adresteki şehir ile posta kodu uyuşmuyor. Bu tür tutarsızlıklardan çıkarım yapılabilir.
  - Elde metadata varsa kullanılır. Örneğin bir fotoğrafın içinde nerede, ne zaman çekildiği gibi gizli bilgiler bulunur; web sayfalarında ve loglarda da metadata olabilir.
  - Slaytta: metadata (alan, aralık, bağımlılık, dağılım) kullanmak; uniqueness, consecutive ve null kurallarını denetlemek; ortalamadan iki standart sapmadan fazla uzaktaki değerleri olası aykırı değer olarak işaretlemek.
  - Ticari araçlar da vardır: data scrubbing (posta kodu, yazım denetimi gibi basit alan bilgisiyle hata bulma) ve data auditing (veriden kural ve ilişki çıkarıp bunlara uymayanları bulma; korelasyon ve kümeleme ile aykırı değer bulma).
- Veri bütünleştirme (data integration)
  - Farklı kaynaklardaki veriyi birleştirmektir: bir firmanın farklı şubeleri, başka veri tabanları, yazılan bir crawler ile başka sitelerden çekilen veri (örneğin hava durumu).
  - Birleştirirken ön işlem gerekir, çünkü kaynakların formatları ve tutuluş biçimleri farklıdır. Tekrarlayan kayıt (duplicate record) olup olmadığı denetlenir; birimlerin çevrilmesi gerekebilir.
  - Hocanın örneği: bir havayolu şirketinin düzenlediği veri madenciliği yarışmasında birinci olan takım, uçuş verisine o günlerin hava durumu verisini ekleyerek daha çok özniteliğe sahip olmuş ve daha iyi tahmin yapmıştır.
- Bütünleştirmede gereksizlik (redundancy) (ekrandan, 00:10:00)
  - Bir öznitelik başka bir öznitelikten ya da öznitelik kümesinden türetilebiliyorsa gereksizdir. Örnek: yaş ile doğum tarihi, posta kodu ile ilçe/mahalle. İkisini birden tutmak veriyi büyütür ve boşuna işlem yaptırır.
  - Aynı öznitelik ya da nesne farklı veri tabanlarında farklı adlarla geçebilir (object identification); bir öznitelik başka tablodan türetilmiş olabilir (derivable data, örneğin yıllık gelir).
  - Gereksiz öznitelikler korelasyon analiziyle bulunur: sayısal öznitelikler için korelasyon katsayısı ve kovaryans, nominal öznitelikler için $\chi^2$ (ki-kare) testi.
- Sayısal veride korelasyon ve kovaryans (ekrandan, 00:15:00)
  - Ortalamalar beklenen değer olarak da adlandırılır: $E(A)=\bar{A}=\frac{\sum_{i=1}^{n} a_i}{n}$, $E(B)=\bar{B}=\frac{\sum_{i=1}^{n} b_i}{n}$.
  - Kovaryans: $Cov(A,B)=E((A-\bar{A})(B-\bar{B}))=\frac{\sum_{i=1}^{n}(a_i-\bar{A})(b_i-\bar{B})}{n}$.
  - Korelasyon katsayısı: $r_{A,B}=\frac{Cov(A,B)}{\sigma_A\sigma_B}$.
  - Hesabı kolaylaştıran eşitlik: $Cov(A,B)=E(A\cdot B)-\bar{A}\bar{B}$. İki sütunun eleman eleman çarpımı aslında bir iç çarpımdır (dot product).
  - $r$ değeri $-1$'e yakınsa biri artarken öteki azalır (negatif korelasyon); $1$'e yakınsa birlikte artarlar (pozitif korelasyon); $0$ civarındaysa aralarında doğrusal ilişki yoktur ve ikisi de tutulur.
  - Araçlardaki scatter plot (saçılım grafiği) matrisi bütün öznitelik çiftlerinin ilişkisini birlikte gösterir; ikili ilişkiler bir korelasyon matrisi olarak da gösterilebilir.
- Nominal veride korelasyon: $\chi^2$ testi (ekrandan, 00:20:00)
  - $A$'nın $c$ farklı değeri, $B$'nin $r$ farklı değeri olsun; bu sayıların eşit olması gerekmez.
  - $\chi^2=\sum_{i=1}^{c}\sum_{j=1}^{r}\frac{(o_{ij}-e_{ij})^2}{e_{ij}}$. Burada $o_{ij}$ gözlenen frekans, yani $(A_i,B_j)$ ikilisinin veride gerçekten kaç kez geçtiği; $e_{ij}$ beklenen frekanstır.
  - $e_{ij}=\frac{count(A=a_i)\times count(B=b_j)}{n}$, $n$ toplam kayıt sayısıdır.
  - $e_{ij}$'ye bölmek, büyük veri ve çok farklı sayılar olduğunda terimleri normalize etmek içindir.
  - $\chi^2$ ne kadar büyükse değişkenlerin ilişkili olma olasılığı o kadar yüksektir. $\chi^2$ negatif olamaz.
- Veri dönüştürme (data transformation) ve ayrıklaştırma (discretization)
  - Dönüştürme çoğu zaman bütünleştirme sırasında gerekir: örneğin bir şube satışları dolar, öteki Türk lirası cinsinden tutmuştur.
  - Normalizasyon: çok geniş aralıklı değerler (örneğin birkaç çok pahalı evin bulunduğu ev fiyatı verisi) bazı yöntemlerde küçük değerlerin etkisini yok edebilir; bazı yöntemler yalnız $[0,1]$ aralığında girdi alır. Etkisi yönteme göre değişir: yapay sinir ağlarında çok fark eder, Bayes ağlarında çok fark etmeyebilir.
- Min-max normalizasyonu (ekrandan, 00:35:00)
  - $v_i'=\frac{v_i-min_A}{max_A-min_A}(new\_max_A-new\_min_A)+new\_min_A$.
  - Minimum çıkarılınca başlangıç sıfıra gelir, aralığa bölününce $[0,1]$'e ölçeklenir; sonra yeni aralıkla çarpılıp yeni minimum eklenir. Hedef aralık $[-1,1]$ de olabilir.
  - Doğrusal bir dönüşümdür, değerler arasındaki ilişkiyi korur; en çok kullanılan yöntemdir. Farklı aletlerle toplanmış benzer ölçümler ayrı ayrı $[0,1]$'e çekilip birleştirilebilir.
- Z-skor normalizasyonu (ekrandan, 00:40:00)
  - $v_i'=\frac{v_i-\bar{A}}{\sigma_A}$ (zero-mean normalization). Ortalama sıfıra taşınır, standart sapmaya bölünür.
  - Gerçek minimum ve maksimum bilinmediğinde kullanışlıdır: test aşamasında eğitim verisindeki minimumdan küçük bir değer gelebilir.
  - Slayt örneği: gelir ortalaması 54.000, standart sapması 16.000 ise 73.600 değeri $\frac{73600-54000}{16000}=1.225$ olur.
- Ondalık ölçekleme (decimal scaling)
  - Değerler 10'un bir kuvvetine bölünür. Derste sözlü verilen örnek: $A$ sütunu $-986$ ile $917$ arasında, en büyük mutlak değer $986$; her değer $1000$'e bölünerek $-0.986$ ile $0.917$ arasına gelir.
  - Hep milyonlarca liralık ev fiyatlarında son basamaklar önemsizse bine bölmek bellekten tasarruf sağlar ve çok büyük sayı türlerine gerek bırakmaz.
- Ayrıklaştırma (discretization)
  - Sürekli bir özniteliği (yaş, kilo) kategorik değere çevirmektir. Aralıkları genelde insan belirler; eşit aralık ya da verinin dağılımı dikkate alınabilir, bu probleme bağlıdır. Örnek: vücut kitle indeksine göre eşiklerle zayıf, normal, obez sınıfları.
  - Denetimli ve denetimsiz ayrıklaştırma (ekrandan, 00:45:00): sınıf bilgisi kullanılıyorsa denetimli (karar ağacı, $\chi^2$ analizi), kullanılmıyorsa denetimsizdir (binning, kümeleme).
  - Kümeleme ile ayrıklaştırmada sürekli değerler örneğin 3 kümeye ayrılır ve her kümenin minimum-maksimum aralığı bir kategori olur. Müdahale imkânı az olduğu ve gürültüde garip sonuçlar verebildiği için pek kullanılmaz.
  - Binning: eşit frekanslı (equal frequency; 12 sıralı eleman 3 kutuya 4, 4, 4) ve eşit genişlikli (equal width; 0-30 aralığı 0-10, 10-20, 20-30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ön işlemler asla verinin aslı üzerinde yapılmaz
  - Verinin orijinali mutlaka ayrı saklanmalıdır. Bir örnekte eksik değerler ortalamayla doldurulmuş, sonradan hangi değerlerin değiştiği ve ortalamanın kaç olduğu bilinemediği için yöntemin eksik değerlerden ne kadar etkilendiği hesaplanamamıştır.
  - Ön işlemede birden çok adım olduğu için adım adım, kayıt tutarak çalışmak gerekir.
- $\chi^2$'nin yorumu
  - Hoca önce küçük $\chi^2$'nin ilişki gösterdiğini söyledi, sonra düzeltti: $\chi^2$ ne kadar büyükse ilişki o kadar güçlüdür. Örnekteki $507.93$ değeri iki özniteliğin ilişkili olduğunu gösterir.
- Bir öznitelik başka bir öznitelikten türetilebiliyorsa ikisini birden tutmaya gerek yoktur
  - Gereksiz öznitelik veriyi büyütür ve hesaplama gücünü boşa harcar.
- Z-skorun min-max'a üstünlüğü
  - Test aşamasında gelecek minimum ve maksimumdan emin değilseniz, verinin dağılımına güveniyorsanız z-skor kullanılır. Örnek: yetişkin verisinde 18 yaşı 0'a eşlediyseniz çocuklara uygulamada 18'in altındaki bütün yaşlar 0 olur.

## Kısa Tekrar Notları

- Gereksiz öznitelik: başka özniteliklerden türetilebilen özniteliktir; korelasyon analiziyle bulunur.
- Sayısal: $r_{A,B}=\frac{Cov(A,B)}{\sigma_A\sigma_B}$, $Cov(A,B)=E(A\cdot B)-\bar{A}\bar{B}$.
- $r\approx 1$ pozitif, $r\approx -1$ negatif ilişki, $r\approx 0$ doğrusal ilişki yok.
- Nominal: $\chi^2=\sum\sum\frac{(o_{ij}-e_{ij})^2}{e_{ij}}$, $e_{ij}=\frac{count(A=a_i)\,count(B=b_j)}{n}$; büyük $\chi^2$ daha güçlü ilişki demektir.
- Min-max: $v'=\frac{v-min}{max-min}(new\_max-new\_min)+new\_min$.
- Z-skor: $v'=\frac{v-\bar{A}}{\sigma_A}$; min-max bilinmiyorsa kullanılır.
- Ondalık ölçekleme: 10'un kuvvetine bölme ($-986\dots 917 \to -0.986\dots 0.917$).
- Ayrıklaştırma: sürekli değeri kategoriye çevirme; denetimli (karar ağacı, $\chi^2$) ve denetimsiz (binning, kümeleme).
- Eşit frekans: her kutuda aynı sayıda eleman. Eşit genişlik: her kutunun aralığı eşit.
- Verinin aslı her zaman saklanır; ön işleme bir kopya üzerinde yapılır.

## Detaylı Açıklamalar

- Kovaryans örneği (derste sözlü, 00:16:04)
  - İki hisse senedinin ($A$ ve $B$) beş zamandaki değerleri verilmiştir; soru, aynı sektör eğiliminden etkilenip etkilenmedikleri, yani birlikte artıp azalmadıklarıdır.
  - Altyazıda $B$ değerleri $5, 8, 10, 11, 14$; $A$ değerleri $2, 3, 5, 4$ ve beşinci değer olarak duyulur. Ardından $E(A\cdot B)$ hesaplanıp ortalamaların çarpımı çıkarılır ve sonuç pozitif çıkar: iki hisse birlikte artma eğilimindedir.
  <!-- BELİRSİZ: Kovaryans slaytı karelerde yok. Hoca sonucu 4.88 olarak okudu. A'nın beşinci değeri 7 ise sonuç tam 4.88 olur; değer 6 ise sonuç 4 olur (python ile hesaplandı). Slayttaki değer doğrulanamadı. -->
- $\chi^2$ örneği (ekrandan, 00:25:00)
  - Olumsallık tablosu (contingency table), "bilim kurgu sever mi" (LikeScienceFiction) ve "satranç oynar mı" (PlayChess) özniteliklerini içerir. Toplam $1500$ kayıt vardır.

```text
                          Play chess   Not play chess   Sum (row)
Like science fiction      250 (90)     200 (360)        450
Not like science fiction  50 (210)     1000 (840)       1050
Sum (col.)                300          1200             1500
```

  - Parantez içindeki sayılar beklenen frekanslardır. Örneğin $e_{LSF,PC}=\frac{450\times 300}{1500}=90$, $e_{\neg LSF,PC}=\frac{1050\times 300}{1500}=210$.
  - $\chi^2=\frac{(250-90)^2}{90}+\frac{(50-210)^2}{210}+\frac{(200-360)^2}{360}+\frac{(1000-840)^2}{840}=284.44+121.90+71.11+30.48=507.93$ (python ile doğrulandı).
  - Sonuç büyük olduğu için iki öznitelik ilişkilidir.
- Ön işleme sırası
  - Bu bölüme kadar veri temizleme ve düzleştirme (smoothing, kutulara ayırma), sonra bütünleştirme, sonra dönüştürme ve ayrıklaştırma görüldü. Slaytlardaki özet, sırada veri indirgeme (boyut ve sayı indirgeme) olduğunu gösteriyor (ekrandan, 00:50:00).
- Eşit genişlik örneği
  - Yaşın $0$-$18$, $18$-$25$, $25$-$35$, $35$-$50$ diye bölünmesi tam olarak eşit genişlikte değildir, ama sınırlar insan tarafından konduğu ve kayıt sayısına bakılmadığı için hoca bunu eşit genişlik yaklaşımına daha yakın saydı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
