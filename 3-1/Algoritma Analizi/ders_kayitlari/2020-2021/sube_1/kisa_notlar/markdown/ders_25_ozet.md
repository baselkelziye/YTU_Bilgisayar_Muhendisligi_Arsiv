# Ders 25 Çalışma Özeti

## Genel Konular

- P ve NP kavramlarına giriş
  - P "polynomial", NP ise "non-deterministic polynomial" kısaltmasıdır (ekrandan, 00:05:00). NP sık sık yanlışlıkla "non-polynomial" diye açılır; doğrusu deterministik olmayan polinomsal algoritmadır.
  - Bu ders bir algoritma anlatmaz; algoritma analizi yaparken bilinmesi gereken kavramları tanıtır.
- Efektif (tractable) ve efektif olmayan (intractable) algoritmalar
  - Çalışma zamanı polinomsal olan algoritmalar ($n$, $n^2$, $n^3$, $n \log n$ gibi) efektif kabul edilir. Örnekler: merge sort, Huffman kodlama, ikili arama.
  - Çalışma zamanı $n!$, $2^n$, $3^n$ gibi üstel olan algoritmalar efektif değildir. Örnekler: gezgin satıcı (traveling salesman) problemi, Hamilton devresi (Hamiltonian circuit).
  - Polinomsal zamanda çözülebilen problemlere tractable, çözülemeyenlere intractable denir (ekrandan, 00:15:00: "Intractable problems: NP").
  - Gezgin satıcı probleminin karmaşıklığı derste $O(n^2 \cdot 2^n)$ olarak verildi.
  - $n^{100000}$ gibi bir karmaşıklık teknik olarak polinomsaldır ama pratikte çözülebilir sayılmaz.
- Çalışma süresi tablosu (ekrandan, 00:10:00)
  - Her temel işlemin 1 mikrosaniye sürdüğü varsayımıyla $n$, $n^2$, $n^3$ ve $2^n$ algoritmalarının $n = 10, 20, 50$ için süreleri karşılaştırıldı.
  - Polinomsal satırlar küçük kalırken $2^n$ satırı $n=20$'de yaklaşık 1 saniyeye, $n=50$'de yaklaşık 35,7 yıla çıkar; $n=60$'ta yüzyıllar sürer.
- Deterministik ve deterministik olmayan algoritmalar
  - Deterministik algoritma aynı giriş için her zaman aynı sonucu üretir (merge sort, ikili arama).
  - Deterministik olmayan (non-deterministic) algoritma aynı giriş için farklı çalıştırmalarda farklı sonuç verebilir. Rastgele bir seçim yapar, sonra seçimin doğru olup olmadığını kontrol eder.
- Deterministik olmayan arama
  - $j = \text{choice}(1..n)$ ile rastgele bir indis seçilir; $A[j] = x$ ise indis yazdırılır ve başarı, değilse başarısızlık (failure) döner.
  - Döngü yoktur, karmaşıklığı $O(1)$'dir.
- Deterministik olmayan sıralama: NSORT (ekrandan, 00:20:00 ve 00:25:00)
  - $B$ dizisi sıfırlanır; her $A[i]$ için rastgele bir $j$ seçilir, $B[j]$ doluysa failure, boşsa $B[j] = A[i]$ yapılır.
  - Sonra $B$'nin sıralı olup olmadığı tek bir taramayla kontrol edilir; sıralıysa $B$ yazdırılır ve başarı döner.
  - Karmaşıklık $O(n)$'dir (ekrandan, 00:25:00). Algoritma her zaman çalışmaz, ama şanslı bir çalıştırmada diziyi $O(n)$ sürede sıralamış olur.
- Deterministik olmayan algoritmanın yapı taşları
  - $\text{choice}$: bir seçim yapar ve değer döndürür; $\text{success}$: başarılı bitiş; $\text{failure}$: başarısız bitiş.
  - İki aşama vardır: tahmin aşaması (guessing stage, deterministik değildir) ve doğrulama aşaması (verification stage, deterministiktir).
  - NP algoritma: doğrulama aşaması polinomsal zamanda yapılabilen algoritmadır.
- Optimizasyon ve karar problemleri (ekrandan, 00:30:00)
  - Optimizasyon problemi en iyi sonucu ister ("bu çizge en az kaç renge boyanır?"). Karar problemi evet/hayır sorusudur ("bu çizge iki renge boyanabilir mi?").
  - Karar sorusu polinomsal zamanda cevaplanabilir; en iyi sonucu bulmak ise olasılıkları tek tek denemeyi gerektirebilir.
- P ve NP sınıfları (ekrandan, 00:35:00 ve 00:40:00)
  - Çözümü polinomsal zamanda bulunabiliyorsa problem P'dedir; çözümü polinomsal zamanda doğrulanabiliyorsa NP'dedir.
  - P, NP'nin alt kümesidir. P = NP olup olmadığı kanıtlanmamıştır; Clay vakfı bu problem için 1 milyon dolar ödül koymuştur.
- NP-tam (NP-complete) ve NP-zor (NP-hard) (ekrandan, 00:45:00)
  - Tahtadaki şema: "All problems" kümesi içinde NP, NP'nin içinde P; NP ile kesişen ayrı bir NP-hard kümesi; kesişim bölgesi NP-complete.
  - Tahtadaki tanımlar: NP-complete "solution NP, verification P"; NP-hard "solution NP, can not verified in P".
  - Hamilton devresi derste NP-tam örneği, gezgin satıcı problemi (en kısa tur) NP-zor örneği olarak verildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- NP'nin açılımı
  - Hoca NP'nin "non-polynomial" değil "non-deterministic polynomial" olduğunu özellikle düzeltti.
- Üstel algoritmalar neden efektif değil
  - Küçük $n$ için bütün olasılıkları denemek sorun değildir; ama $n$ büyüdükçe süre katlanarak artar, problem makul sürede çözülemez.
- Doğrulama ile çözme arasındaki fark
  - NP algoritmada asıl iş çözmek değil, tahmin edilen sonucu doğrulamaktır. Doğrulama polinomsalsa algoritma, şans yaver giderse polinomsal zamanda sonuç vermiş olur.
- Ders kapsamı
  - Hoca P, NP ve indirgeme (reduction) konularının bundan çok daha derin olduğunu, ama bu ders için bu temel tanımların yeterli olduğunu söyledi.

## Kısa Tekrar Notları

- P: polinomsal zamanda çözülebilen problemler. NP: çözümü polinomsal zamanda doğrulanabilen problemler. $P \subseteq NP$.
- Tractable: polinomsal zamanda çözülebilir. Intractable: polinomsal zamanda çözülemez.
- $2^n$ algoritma, işlem başına 1 μs ile $n=50$'de yaklaşık 35,7 yıl sürer.
- Deterministik olmayan algoritma = tahmin (non-deterministic) + doğrulama (deterministic).
- Deterministik olmayan arama $O(1)$, deterministik olmayan sıralama NSORT $O(n)$.
- Optimizasyon problemi: "en az kaç?"; karar problemi: "şu kadarla olur mu?".
- NP-tam: doğrulama polinomsal (örnek: Hamilton devresi). NP-zor (derste verilen tanım): doğrulama bile polinomsal değil (örnek: gezgin satıcının en kısa turu).
- P = NP açık bir problemdir.
- Ders sonrası not: Derste minimum kapsayan ağaç (minimum spanning tree) NP bir problem olarak anıldı; doğrusu, Prim ve Kruskal algoritmalarıyla polinomsal zamanda çözüldüğü için P sınıfındadır.

## Detaylı Açıklamalar

- Polinomsal ve üstel büyüme
  - Tahtadaki tabloda (ekrandan, 00:10:00) $n=10$ için $n$: 0,00001 s, $n^2$: 0,0001 s, $n^3$: 0,001 s, $2^n$: 0,001 s; $n=20$ için $n$: 0,00002 s, $n^2$: 0,0004 s, $n^3$: 0,008 s, $2^n$: 1,0 s; $n=50$ için $n$: 0,00005 s yazılıdır. Bu değerler her işlemin 1 μs sürdüğü varsayımıyla tutarlıdır (python ile kontrol edildi).
  - $n=50$ için $2^n$ değeri altyazıda "35,7" olarak geçer; $2^{50}$ μs ≈ 35,7 yıldır. $n=60$ için hoca "yüzyıl" dedi; $2^{60}$ μs büyük olasılıkla yaklaşık 365 yüzyıldır (ara adım eklendi). <!-- BELİRSİZ: n=50 sütununun n^2 ve n^3 değerleri ile n=60 satırı mevcut karelerde görünmüyor -->
- Deterministik olmayan sıralama örneği (ekrandan, 00:25:00)
  - $A = [2, 3, 1, 4]$, $B = [0, 0, 0, 0]$. Seçilen indisler sırasıyla $j = 2, 1, 4, 3$ olursa $B[2]=2$, $B[1]=3$, $B[4]=1$, $B[3]=4$ olur ve $B = [3, 2, 4, 1]$ çıkar. Doğrulama ilk karşılaştırmada ($3 > 2$) başarısız olur.
  - İkinci senaryoda ilk seçim $j=3$ ile $B[3]=2$ yazılır, ikinci seçim yine $j=3$ gelir; $B[3]$ dolu olduğu için algoritma failure ile biter, yeniden denemez.
  - Üçüncü senaryoda şans yaver gider, her eleman doğru yere düşer ve $B$ sıralı çıkar.
  - Ders sonrası not: Tahtada doğrulama satırı "if B[i] < B[i+1] then failure" diye yazıldı. Hocanın anlatımı (her $i$ için $B[i] < B[i+1]$ ise dizi sıralıdır) ve örnekteki sonuç, başarısızlık koşulunun $B[i] > B[i+1]$ olması gerektiğini gösterir.
- Graf boyama örneği
  - Komşu düğümlerin aynı renge boyanmadığı boyamada hoca bir çizgeyi önce iki renkle boyamaya çalıştı; bir öğrencinin uyarısıyla bir düğümün iki farklı renkli komşusu olduğu görüldü ve en az üç renk gerektiği bulundu. <!-- BELİRSİZ: çizgenin yapısı karelerde görünmüyor -->
- Gezgin satıcı ve Hamilton devresi
  - Gezgin satıcıda "önerilen tur en kısa tur mu?" sorusunu doğrulamak için de polinomsal yöntem yoktur; bu yüzden derste NP-zor diye sınıflandırıldı.
  - Hamilton devresinde "verilen yol her düğümden bir kez geçip başa dönüyor mu?" sorusu yalnızca yolu izleyerek polinomsal zamanda doğrulanır; bu yüzden derste NP-tam diye sınıflandırıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
