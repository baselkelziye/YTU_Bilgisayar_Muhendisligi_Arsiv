# Ders 1 Çalışma Özeti

## Genel Konular

- Hesaplama kuramının amacı
  - Ders, bilgisayar donanımı ve yazılımının matematiksel özelliklerini inceler: hesaplama nedir, algoritma nedir, bilgisayarların sınırları nelerdir.
  - Diğer derslerde algoritmalar genellikle sezgisel (gayriresmî) tanımlanır; bu derste algoritma biçimsel, matematiksel olarak tanımlanacaktır.
  - Bilgisayarlar her problemi çözemez; bu kuramsal bir sonuçtur. Ders, hesaplamanın biçimsel matematiksel modellerini geliştirmeyi amaçlar.
  - Ders sayılardan çok semboller ve ispatlarla ilgilenen bir matematik dersidir.
- Karmaşıklık kuramı (Complexity Theory)
  - Soru: Bazı problemleri hesaplama açısından zor, bazılarını kolay yapan nedir? "Kolay" ve "zor" matematiksel olarak tanımlanacaktır.
  - Kolay problemler verimli çözülür; girdi çok büyüse bile makul sürede çözülebilir: sayıları sıralama, bir listede ad arama, İstanbul'da iki semt arasındaki en hızlı yolu bulma.
  - Zor problemler verimli çözülemeyen ya da verimli çözülüp çözülemediği bilinmeyen problemlerdir (ekrandan, 00:25:00): bütün dersler için ders programı çizelgeleme, 300 basamaklı bir tamsayıyı asal çarpanlarına ayırma, VLSI'da yonga yerleşimi hesaplama.
  - Merkezi soru (ekrandan, 00:25:00): problemleri "zorluk" derecelerine göre sınıflandırmak ve zor görünen problemlerin gerçekten zor olduğunu titizlikle ispatlamak.
- Hesaplanabilirlik kuramı (Computability Theory)
  - Bilgisayar, algoritma ve hesaplamanın biçimsel tanımları burada yapılır.
  - Bazı problemler yalnız zor değil, çözülemezdir; kuramsal olarak hiçbir bilgisayar onları çözemez.
- Otomata kuramı (Automata Theory)
  - Farklı "hesaplama modellerinin" tanımları ve özellikleriyle ilgilenir; dersin başında işlenecektir (ekrandan, 00:30:00).
  - Sonlu otomatlar: metin işleme, derleyiciler ve donanım tasarımında kullanılır; yetenekleri en düşüktür.
  - Bağlamdan bağımsız gramerler: programlama dillerini tanımlamakta ve yapay zekâda kullanılır; daha yeteneklidir.
  - Turing makineleri: evdeki bilgisayar gibi "gerçek" bir bilgisayarın basit soyut modelidir; gerçek bir bilgisayarın yapabildiği her şeyi yapabilir.
  - Merkezi soru (ekrandan, 00:30:00): Bu modeller aynı güçte mi, yoksa biri ötekinden daha fazla problem çözebilir mi?
- Küme kuramı temelleri (ekrandan, 00:35:00 ve 00:45:00)
  - Küme, iyi tanımlanmış nesnelerin topluluğudur.
  - Doğal sayılar $\mathbb{N} = \{1, 2, 3, \dots\}$ (bu derste 0 doğal sayı değildir), tamsayılar $\mathbb{Z} = \{\dots, -3, -2, -1, 0, 1, 2, 3, \dots\}$, rasyonel sayılar $\mathbb{Q} = \{m/n : m \in \mathbb{Z}, n \in \mathbb{Z}, n \neq 0\}$, gerçel sayılar $\mathbb{R}$.
  - Alt küme, kuvvet kümesi, birleşim, kesişim, fark, Kartezyen çarpım ve tümleyen tanımları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu derste doğal sayılar 1'den başlar
  - Bazı kitaplar ve matematikçiler 0'ı doğal sayı kabul eder; bu derste kabul edilmez.
- Problemin sınıfını bilmenin pratik değeri
  - Bir problemin çok zor olduğunu kuramsal olarak bilirsek büyük girdide çok zaman alacağını önceden biliriz; problemi başka biçimde koymayı ya da başka yoldan çözmeyi seçebiliriz.
  - Bir problemin çözülemez olduğunu bilirsek onun için program yazmaya zaman harcamayız; asıl problemi farklı bir yoldan ele alırız.
  - Bir problem sonlu otomatla çözülebiliyorsa (örneğin buzdolabı ya da çamaşır makinesi denetimi) cihaza çok daha ucuz bir "zekâ" konabilir; yalnız Turing makinesiyle çözülebiliyorsa gerçek bir bilgisayar ya da yonga gerekir.
- Kartezyen çarpım bu derste çok önemlidir
  - Ders kitabında bu gösterim sık geçer; çarpımda sıra önemlidir: ilk eleman $A$'dan, ikinci eleman $B$'den gelir.
- Küme kuramı dersin temelidir
  - Matematiğin bir kısmı gibi bu ders de küme kuramına dayanır.

## Kısa Tekrar Notları

- Dersin üç ana bölümü: otomata kuramı, hesaplanabilirlik kuramı, karmaşıklık kuramı.
- Kolay problem: büyük girdide bile makul sürede çözülür. Zor problem: verimli çözülemez ya da verimli çözülüp çözülemediği bilinmez.
- Çözülemez problem: kuramsal olarak hiçbir bilgisayar çözemez.
- Modellerin gücü: sonlu otomat < bağlamdan bağımsız gramer < Turing makinesi (dersin ilerleyen bölümlerinde biçimsel olarak incelenecek).
- $\mathbb{N}$ 1'den başlar; $\mathbb{Q}$ iki tamsayının bölümü olarak yazılabilen sayılardır; irrasyonel sayılar rasyonel olmayan sayılardır ($\pi$ gibi); $\mathbb{R}$ sayılamaz bir kümedir ve rasyonelleri ve irrasyonelleri içerir.
- $A \subseteq B$: $A$'nın her elemanı $B$'nin de elemanıdır. $\mathcal{P}(B) = \{A : A \subseteq B\}$; $\emptyset \in \mathcal{P}(B)$ ve $B \in \mathcal{P}(B)$.
- $A \cup B$ (veya), $A \cap B$ (ve), $A \setminus B$ ($A$'da olup $B$'de olmayan), $A \times B$ (sıralı ikililer), $\bar{A}$ ($A$'da olmayanlar).
- Örnek: $A = \{1,2\}$, $B = \{3,4\}$ ise $A \times B = \{(1,3), (1,4), (2,3), (2,4)\}$.

## Detaylı Açıklamalar

- **Dersin genel çerçevesi.** Hesaplama kuramı "hesaplama nedir, algoritma nedir, bilgisayarlar neyi hesaplayabilir" sorularına matematiksel cevap arar. Ders boyunca hesaplamanın biçimsel modelleri kurulur ve bu modellerin gücü karşılaştırılır. Şaşırtıcı bir sonuç olarak bilgisayarların her problemi çözemediği kuramsal olarak gösterilecektir.
- **Karmaşıklık kuramı.** Kolay problemler, girdi bir milyon ya da bir milyar eleman olsa bile makul sürede çözülebilir; sıralama, listede arama ve en kısa yol bulma bunlara örnektir. Zor problemlerde ise girdi büyüdükçe çözüm süresi makul olmaktan çıkar. Hoca bunu ders programı örneğiyle açıkladı: tek bir üniversitenin birkaç bin dersi bugünün hızlı bilgisayarlarıyla makul sürede çizelgelenebilir, ama dünyadaki bütün derslerin (milyonlarca ders) çizelgelenmesi makul sürede yapılamaz. Asal çarpanlara ayırma ve VLSI yerleşimi de zor problem örnekleridir. Bazı problemler zor, bazıları "gerçekten çok zor"dur; bu farkın nasıl tanımlanacağı kuramın konusudur.
- **Hesaplanabilirlik kuramı.** Burada bilgisayar, algoritma ve hesaplama biçimsel olarak tanımlanır. Zor problemler bir şekilde (uzun sürede) çözülebilir; çözülemez problemler ise kuramsal olarak hiç çözülemez. Bunu bilmek, olmayacak bir program için emek harcanmasını önler.
- **Otomata kuramı.** Dersin ilk bölümüdür. Hesaplama modelleri basitten güçlüye doğru incelenir: önce sonlu otomatlar, sonra bağlamdan bağımsız gramerler, sonra Turing makineleri. Turing makinesi gerçek bilgisayarların kuramsal modelidir. Bir problemin hangi modelle çözülebildiğini bilmek mühendislikte de işe yarar: sonlu otomatla çözülebilen bir denetim problemi için ucuz bir devre yeter, Turing makinesi gerektiren bir problem için gerçek bir işlemci gerekir.
- **Küme kuramı.** Küme iyi tanımlanmış nesnelerin topluluğudur. Küme gösteriminde iki nokta üst üste (":") "öyle ki" diye, virgül "ve" diye okunur. Buna göre $\mathbb{Q} = \{m/n : m \in \mathbb{Z}, n \in \mathbb{Z}, n \neq 0\}$ ifadesi "$m/n$ biçiminde yazılabilen, $m$ ve $n$ tamsayı ve $n$ sıfırdan farklı olan sayılar kümesi" diye okunur. Örneğin $3 = 3/1$ ve $2/3$ rasyoneldir. $\pi$ iki tamsayının bölümü olarak yazılamadığı için irrasyoneldir. Gerçel sayılar kümesi $\mathbb{R}$ sayılamazdır ve rasyonel ile irrasyonel sayıların hepsini içerir. $\mathbb{N} \subseteq \mathbb{Z}$'dir, çünkü her doğal sayı bir tamsayıdır. Bir $B$ kümesinin kuvvet kümesi bütün alt kümelerinden oluşur; boş küme ve $B$'nin kendisi de birer alt kümedir.
- **Küme işlemleri (ekrandan, 00:45:00).**
  - $A \cup B = \{x : x \in A \text{ veya } x \in B\}$
  - $A \cap B = \{x : x \in A \text{ ve } x \in B\}$
  - $A \setminus B = \{x : x \in A \text{ ve } x \notin B\}$
  - $A \times B = \{(x, y) : x \in A \text{ ve } y \in B\}$; elemanlar sıralı ikililerdir (pair), ilk bileşen $A$'dan, ikinci bileşen $B$'den gelir.
  - $\bar{A} = \{x : x \notin A\}$
  - Hocanın örneği: $A = \{1, 2\}$, $B = \{3, 4\}$ için $A \times B = \{(1,3), (1,4), (2,3), (2,4)\}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
