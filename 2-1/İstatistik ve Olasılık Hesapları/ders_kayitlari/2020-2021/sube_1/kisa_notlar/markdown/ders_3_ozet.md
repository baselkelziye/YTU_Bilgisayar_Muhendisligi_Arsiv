# Ders 3 Çalışma Özeti

## Genel Konular

- Olasılığın aksiyomatik tanımı
  - Olasılık, örnek uzay $\Omega$ üzerinde tanımlanan bir fonksiyondur: her olaya ($A \in \mathcal{P}(\Omega)$, yani örnek uzayın kuvvet kümesinin bir elemanına) bir sayı $\Pr(A)$ atar.
  - Üç aksiyom (ekrandan, 00:10:00):
    - $\Pr(A) \ge 0$, her $A \in \mathcal{P}(\Omega)$ için.
    - $\Pr(\Omega) = 1$.
    - $A \cap B = \emptyset$ ise $\Pr(A \cup B) = \Pr(A) + \Pr(B)$.
  - $\Pr: \mathcal{P}(\Omega) \to [0,1]$ fonksiyonuna **olasılık ölçüsü** (probability measure), $(\Omega, \Pr)$ ikilisine **olasılık uzayı** (probability space) denir (ekrandan, 00:15:00).
  - Fonksiyon kavramı tekrar edildi: tanım kümesi (domain), değer kümesi (range); $\mathbb{R}$ tüm reel sayılar, $\mathbb{R}_+$ pozitif reel sayılar; hoca $[0,1]$ aralığını $\mathbb{R}_+^1$ diye gösterdi.
- Temel olasılık kuralları (ekrandan, 00:20:00 ve 00:25:00)
  - $\Pr(\emptyset) = 0$ (imkânsız olay).
  - $A = \{\omega_1, \dots, \omega_k\}$ ise $\Pr(A) = \sum_{i=1}^{k} \Pr(\{\omega_i\})$; $\{\omega_i\}$ temel (elementary) olaylardır ve ayrık oldukları varsayılır: $i \ne j$ için $\{\omega_i\} \cap \{\omega_j\} = \emptyset$.
  - Tümleyen: $\Pr(\bar{A}) = 1 - \Pr(A)$.
  - İkişer ayrık $A_1, \dots, A_n$ için $\Pr\left(\bigcup_{k=1}^{n} A_k\right) = \sum_{k=1}^{n} \Pr(A_k)$.
  - Her $A, B$ için $\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B)$; bu formül $n$ olaya genelleştirilir (içerme-dışarma).
- Eşitsizlikler
  - Monotonluk: $A \subset B$ ise $\Pr(A) \le \Pr(B)$.
  - $\Pr\left(\bigcup_{i=1}^{n} A_i\right) \le \sum_{i=1}^{n} \Pr(A_i)$; olaylar ikişer ayrıksa eşitlik olur.
  - $\Pr\left(\bigcap_{i=1}^{n} A_i\right) \ge 1 - \sum_{i=1}^{n} \Pr(\bar{A}_i)$, $n \in \mathbb{N}$.
- Bağımsız olaylar
  - $E_1, \dots, E_n$ olaylarından birinin gerçekleşmesi diğerlerinin olasılığını etkilemiyorsa bu olaylar bağımsızdır (ekrandan, 00:35:00).
  - Bağımsız olaylar için $\Pr(A_1 \cap \dots \cap A_n) = \Pr(A_1)\Pr(A_2)\cdots\Pr(A_n)$.
  - $A$ ve $B$ bağımsızsa $A$ ile $\bar{B}$, $\bar{A}$ ile $B$ de bağımsızdır.
- Koşullu olasılık
  - Tanım: $\Pr(A \mid B) = \dfrac{\Pr(A \cap B)}{\Pr(B)}$, $\Pr(B) \ne 0$; yani $B$ imkânsız olay olamaz (ekrandan, 00:45:00).
  - Özellikler (ekrandan, 00:50:00): $0 \le \Pr(A \mid B) \le 1$; $\Pr(\Omega \mid B) = 1$ çünkü $B \subset \Omega$; $A_1, A_2$ ayrık (incompatible) ise $\Pr(A_1 \cup A_2 \mid B) = \Pr(A_1 \mid B) + \Pr(A_2 \mid B)$; $A, B$ bağımsızsa $\Pr(A \mid B) = \Pr(A)$ ve $\Pr(B \mid A) = \Pr(B)$.
  - Kesişimin olasılığı (çarpma kuralı): $\Pr(A_1 \cap \dots \cap A_n) = \Pr(A_1)\Pr(A_2 \mid A_1)\Pr(A_3 \mid A_1 \cap A_2)\cdots\Pr(A_n \mid A_1 \cap \dots \cap A_{n-1})$.
- Toplam olasılık yasası
  - $B_1, \dots, B_k$ örnek uzayın bir parçalanışıdır (partition): ikişer ayrık, birleşimleri $\Omega$ ve her biri için $\Pr(B_i) > 0$.
  - $\Pr(A) = \sum_{i=1}^{k} \Pr(B_i)\Pr(A \mid B_i)$ (ekrandan, 01:30:00).
  - $B$ ve $\bar{B}$ ile kurulan parçalanışta: $\Pr(A) = \Pr(A \mid B)\Pr(B) + \Pr(A \mid \bar{B})\Pr(\bar{B})$ (ekrandan, 01:35:00).
- Bayes kuralı ve Bayes teoremi
  - Bayes kuralı: $\Pr(A \mid B)\Pr(B) = \Pr(B \mid A)\Pr(A)$, $\Pr(A) \ne 0$, $\Pr(B) \ne 0$.
  - Bayes teoremi (ekrandan, 01:45:00): $\Pr(B_j \mid A) = \dfrac{\Pr(B_j)\Pr(A \mid B_j)}{\sum_{i=1}^{k} \Pr(B_i)\Pr(A \mid B_i)}$.
  - Bayes teoremi, Bayes kuralı ile toplam olasılık yasasının birleşimidir.
  - $\Pr(B_i)$: önsel (prior) olasılıklar; $\Pr(B_i \mid A)$: sonsal (posterior) olasılıklar; $A$: kanıt (evidence).
- Rastgele değişken ve kesikli dağılımlar
  - Rastgele değişken, bir deneyin her sonucuna sayısal bir değer atanarak elde edilir; sonuçların bir fonksiyonudur.
  - Atamanın tanım kümesi örnek uzay $\Omega$, değer kümesi $\mathbb{R}$'nin bir alt kümesidir.
  - Sayılabilir değerler alan rastgele değişkene **kesikli rastgele değişken** denir (ekrandan, 02:25:00).
  - Rastgele değişkenle ilgili bütün olasılıkların topluluğu **dağılım**dır; çoğu zaman tablo ile verilir: $0 \le p_i \le 1$ ve $\sum_i p_i = 1$ (ekrandan, 02:35:00).
  - Olasılık kütle fonksiyonu (PMF): $p(x) = \Pr(X = x)$. Değer sayısı çoksa tablo yerine PMF çizimi önerilir.
  - Birikimli dağılım fonksiyonu (CDF): $F_X(x) = \Pr(X \le x) = \sum_{x_k \le x} \Pr(X = x_k)$ (ekrandan, 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- İçerme-dışarma formülünün $n=5$ için yazılması
  - Hoca, $n=4$ için formülü yazdıktan sonra $\Pr(A \cup B \cup C \cup D \cup E)$ ifadesinin çok iyi bir sınav sorusu olduğunu söyledi.
- Toplam olasılık yasasının önemi
  - Hoca bu yasanın "çok önemli" olduğunu söyledi; Bayes teoremi bu yasa üzerine kuruludur.
- Bayes kuralı ile Bayes teoremi farklıdır
  - Kural iki olay için iki koşullu olasılığı ilişkilendirir; teorem bir parçalanış üzerinden sonsal olasılığı verir.
- Rastgele değişkenin tanımı
  - Rastgele değişken, her sonuca sayısal bir değer atamaktır. Hoca bu tanımı bilmenin olasılık, istatistik ve makine öğrenmesi için temel olduğunu vurguladı.
- Rastgele değişken gösterimi
  - Derste rastgele değişkenler "kancalı" büyük harfle yazılır (hocanın el yazısında $X$'in üstünde bir kanca vardır). Kancasız $x$ bir sabittir. $\Pr(X = x)$ ifadesinde ilki rastgele değişken, ikincisi sabit değerdir.
  - PMF için $p(x)$ ve $p_X(x)$ gösterimleri kullanılabilir; tercih edilen $\Pr(X = x)$ yazımıdır.

## Kısa Tekrar Notları

- Aksiyomlar: $\Pr(A) \ge 0$, $\Pr(\Omega) = 1$, ayrık olaylarda toplanabilirlik.
- $\Pr(\bar{A}) = 1 - \Pr(A)$, $\Pr(\emptyset) = 0$.
- $\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B)$; üç olayda üçlü kesişim işareti artıdır, dört olayda dörtlü kesişim eksidir.
- Bağımsızlık: $\Pr(A \cap B) = \Pr(A)\Pr(B)$. Ayrıklık: $A \cap B = \emptyset$. Bu iki kavram aynı şey değildir.
- $\Pr(A \mid B) = \Pr(A \cap B)/\Pr(B)$, $\Pr(B) > 0$.
- Toplam olasılık: $\Pr(A) = \sum_i \Pr(B_i)\Pr(A \mid B_i)$.
- Bayes: $\Pr(B_j \mid A) = \Pr(B_j)\Pr(A \mid B_j) / \sum_i \Pr(B_i)\Pr(A \mid B_i)$.
- Hilesiz zar: $\Pr(X = k) = 1/6$, $k = 1, \dots, 6$; CDF basamaklıdır, her tam sayıda $1/6$ sıçrar, $F_X(3.5) = 1/2$, $F_X(x) = 1$ ($x \ge 6$).
- İki para örneği: $\Pr(C_1 \mid H) = 3/5$.

## Detaylı Açıklamalar

- **Aksiyomatik olasılık.** Önceki derslerde göreli frekans ve eşit olasılıklı sonuçlar üzerinden olasılık tanımlanmıştı. Bu derste olasılık, kuvvet kümesinden $[0,1]$ aralığına giden bir fonksiyon olarak tanımlandı. Üç aksiyomdan temel kurallar türetilir: imkânsız olayın olasılığı sıfırdır, tümleyenin olasılığı $1 - \Pr(A)$'dır, bir olayın olasılığı onu oluşturan temel olayların olasılıklarının toplamıdır. Hoca olasılık uzayı kavramının ileride kuantum hesaplama ve kuantum algoritmaları gibi alanlarda da gerektiğini söyledi.

- **İçerme-dışarma.** Üç olay için:
  $\Pr(A \cup B \cup C) = \Pr(A) + \Pr(B) + \Pr(C) - \Pr(A \cap B) - \Pr(A \cap C) - \Pr(B \cap C) + \Pr(A \cap B \cap C)$.
  Dört olay için tekli olasılıklar toplanır, altı ikili kesişim çıkarılır, dört üçlü kesişim eklenir, dörtlü kesişim çıkarılır. Genel kural: tekliler artı, ikililer eksi, üçlüler artı, dörtlüler eksi diye işaret değişir.

- **Bağımsızlık ve koşullu olasılık.** Bir para ve bir zar birlikte atıldığında "para H (head) gelir" ile "zar 6 gelir" bağımsızdır: $\Pr = \frac{1}{2} \cdot \frac{1}{6} = \frac{1}{12}$ (ekrandan, 00:40:00). Buna karşılık bir zarda "tek sayı gelmesi" ($\{1,3,5\}$) ile "asal sayı gelmesi" ($\{2,3,5\}$) bağımlıdır, çünkü 3 ve 5 ortaktır. Bağımlı olaylarda kesişimin olasılığı koşullu olasılıkla hesaplanır.

- **İki para örneği (Bayes).** Biri hileli ($\Pr(H) = 3/4$, $\Pr(T) = 1/4$), biri hilesiz ($\Pr(H) = \Pr(T) = 1/2$) iki para var, hangisinin hangisi olduğu bilinmiyor. Rastgele bir para seçilip atılıyor ve H (head) geliyor. Ağaç diyagramından $\Pr(C_1 \cap H) = \frac12 \cdot \frac34 = \frac38$, $\Pr(C_2 \cap H) = \frac12 \cdot \frac12 = \frac14$. Toplam olasılıkla $\Pr(H) = \frac38 + \frac14 = \frac58$. Sonuç: $\Pr(C_1 \mid H) = \frac{3/8}{5/8} = \frac35$ (ekrandan, 01:25:00).

- **Toplam olasılık ve Bayes teoremi.** Örnek uzay $B_1, \dots, B_6$ gibi parçalara bölünür ve $A$ olayı bu parçalarla kesişir. $A$'nın olasılığı, her parçanın olasılığı ile o parça bilindiğinde $A$'nın koşullu olasılığının çarpımlarının toplamıdır. Bayes teoreminin ispatı: $\Pr(B_j \mid A) = \Pr(B_j \cap A)/\Pr(A)$; pay $\Pr(B_j)\Pr(A \mid B_j)$ diye, payda toplam olasılık yasasıyla yazılır. Hoca örnek olarak iki fabrikanın elektronik çip ürettiği bir durumu anlattı: bozuk bir çip gözlendiğinde (kanıt), onun hangi fabrikadan geldiğinin olasılığı (sonsal) önsel olasılıklardan ve koşullu olasılıklardan bulunur.

- **Rastgele değişken.** Para atmada H (head) sonucuna 0, T (tail) sonucuna 1 atanırsa $X$ rastgele değişkeni elde edilir; beş atışın sonucu $1, 0, 0, 1, 1$ gibi bir diziyle gösterilir. Zarda her yüze 1'den 6'ya kadar sayı atanır; rastgele değişkenin örnek uzayının boyutu 6'dır, yani sayılabilirdir ve $X$ kesiklidir.

- **Dağılım tabloları.** Hilesiz zar: her değer için $1/6$. Hileli para: hoca $\Pr(H) = 1/4$, $\Pr(T) = 3/4$ seçip H sonucuna 0, T sonucuna 1 atadı; tablo $X = 0 \to 1/4$, $X = 1 \to 3/4$ (ekrandan, 02:40:00).

- **PMF ve CDF.** Hilesiz zarın PMF'i 1'den 6'ya kadar her noktada $1/6$ yüksekliğinde çubuklardan oluşur (ekrandan, 02:50:00). CDF basamaklı bir fonksiyondur: $F_X(0.5) = 0$, $F_X(1) = F_X(1.5) = 1/6$, $F_X(3.5) = 3/6 = 1/2$, $F_X(8) = 1$ (ekrandan, 03:05:00 ve 03:10:00). Grafikte her basamağın sol ucu dolu, sağ ucu boş noktayla gösterilir; dikey çizgiler sıçramayı anlatır, kesikli çizilip çizilmemesi önemli değildir.

- **Ders sonrası notlar.**
  - Hoca $\Pr(B) = 0$ olunca oranın sonsuza gittiğini söyledi. Doğrusu: $\Pr(B) = 0$ ise $\Pr(A \cap B) = 0$ olur ve oran $0/0$ biçiminde tanımsızdır; koşul bu yüzden konur.
  - Derste bir öğrenci bağımsız olayların aynı zamanda ayrık (mutually exclusive) sayılıp sayılamayacağını sordu, hoca son kısımda "evet" dedi. Doğrusu: olasılıkları sıfırdan büyük iki olay hem bağımsız hem ayrık olamaz; ayrıklıkta $\Pr(A \cap B) = 0$, bağımsızlıkta $\Pr(A \cap B) = \Pr(A)\Pr(B) > 0$ olur.
  - Hoca örnek uzayın boyutu sonsuz olursa sayılamaz olacağını söyledi. Doğrusu: sayılabilir küme sonsuz da olabilir (örneğin $\{0, 1, 2, \dots\}$); böyle değerler alan rastgele değişken de kesiklidir.
  - İki para örneğinde hoca önce $\Pr(H) = 1/2$ dedi, sonra $5/8$ olarak düzeltti; doğru değer $5/8$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
