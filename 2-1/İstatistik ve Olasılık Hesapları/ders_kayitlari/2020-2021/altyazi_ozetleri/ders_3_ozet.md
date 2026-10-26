# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 22 Ekim 2020 Perşembe. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 05:00'te başlar.
  - Dersin ilk 10 dakikası önceki dersin Türkçe tekrarıdır. Hoca yaklaşık 14:50'den sonra İngilizceye geçti.
- Önceki dersin tekrarı (Türkçe)
  - Üç aksiyom, eşit olasılıklı çıktılar, tümleyen ve boş küme kuralları.
  - Fark kuralı $P(A \setminus B) = P(A) - P(A \cap B)$ Venn diyagramıyla kısaca gösterildi.
- Yeni olasılık kuralları
  - Birleşim kuralı (kesişen olaylar için).
  - Alt küme kuralı.
- Sürekli olasılık uzayları (continuous probability spaces) üzerine kısa giriş
- Şartlı olasılık (conditional probability)
  - Tanım, sezgisel anlamı ve zar örneği.
  - Şartlı olasılık da bir olasılık ölçüsüdür.
  - Uçuş örneği.
- Bağımsızlık (independence)
  - Tanım, uçuş örneğiyle test.
  - Ayrık (disjoint) ile bağımsız (independent) kavramlarının farkı.
  - Bağımsızlık kuralları ve üç olayın bağımsızlığı.
- Toplam olasılık kuralı (law of total probability)
  - Ev ödevi: üç hileli bozuk para örneği.

## Hocanın Özellikle Vurguladığı Kısımlar

- Şartlı olasılık formülü önemlidir, mutlaka bilin: $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$, $P(B) > 0$.
- Şartlı olasılık aksiyomlara uyar. Bu yüzden şartlı olasılık bir olasılık ölçüsüdür.
  - Öğrendiğiniz her kuralın şartlı versiyonu vardır. Örnek: $P(A^c \mid B) = 1 - P(A \mid B)$.
  - Dikkat: koşullar aynı olmalıdır. $P(A \mid B^c) = 1 - P(A \mid B)$ **yanlıştır**.
- Problem çözerken önce modelleyin.
  - Olaylara büyük harfle ad verin. Verilen olasılıkları bu harflerle yazın. Sorulan şeyi bu harflerle yazın.
  - "ve" (and) kelimesi genellikle kesişim demektir.
  - Model kurulduktan sonra geriye yalnızca kuralları uygulamak kalır.
- Ayrık (mutually exclusive) ile bağımsız (independent) aynı şey değildir.
  - Ayrık: kesişim boş kümedir. Bu, kümelerle ilgili bir özelliktir.
  - Bağımsız: $P(A \cap B) = P(A)P(B)$. Bu, olasılıklarla ilgili bir özelliktir.
  - Ayrık olaylar bağımsız değildir: biri olursa öbürü olamaz. Yani biri, öbürü hakkında bilgi verir.
- Bağımsızlığı test ederken çoğu zaman çarpım kuralı daha kolaydır.
- Sürekli uzaylarda tek bir noktanın olasılığı sıfırdır. Bu yüzden aralıkların olasılığıyla çalışılır.
- Aksiyomlar ve onlardan türetilen bütün kurallar hem kesikli (discrete) hem sürekli uzaylarda geçerlidir.

## Kısa Tekrar Notları

- Birleşim: $P(A \cup B) = P(A) + P(B) - P(A \cap B)$. Ayrık olaylarda son terim sıfırdır.
- Alt küme: $A \subseteq B \Rightarrow P(A) \le P(B)$.
- Sürekli uzay, $[0,1]$ aralığında düzgün (uniform) seçim:
  - Tek noktanın olasılığı $0$'dır.
  - $P(0.5 \le a \le 0.75) = \dfrac{0.75 - 0.5}{1 - 0} = 0.25$.
  - İki boyutta uzunluk yerine alan kullanılır.
- Gösterim: $P(0.5 \le a \le 0.75)$ (Baron) ile $P([0.5, 0.75])$ (Pishro-Nik) aynı anlamdadır.
- Şartlı olasılık: $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$. "$B$ verildiğinde $A$'nın olasılığı" (probability of $A$ given $B$) diye okunur.
- Şartlı aksiyomlar:
  - $P(A \mid B) \ge 0$.
  - $P(\Omega \mid B) = 1$.
  - Ayrık $A_1, A_2, \dots$ için $P(A_1 \cup A_2 \cup \dots \mid B) = P(A_1 \mid B) + P(A_2 \mid B) + \dots$
- Bağımsızlık: $P(A \mid B) = P(A)$ ya da eşdeğer olarak $P(A \cap B) = P(A)P(B)$.
- $A$ ve $B$ bağımsızsa: $P(B \mid A) = P(B)$. Ayrıca $A^c$ ile $B$, $A$ ile $B^c$, $A^c$ ile $B^c$ de bağımsızdır.
- Üç olayın bağımsızlığı: bütün ikili kesişimler ve üçlü kesişim çarpıma eşit olmalıdır.
  - $P(A \cap B) = P(A)P(B)$, $P(A \cap C) = P(A)P(C)$, $P(B \cap C) = P(B)P(C)$.
  - $P(A \cap B \cap C) = P(A)P(B)P(C)$.
- Toplam olasılık: $B_1, B_2, \dots$ örneklem uzayının bir bölüntüsü ve $P(B_i) > 0$ ise
  - $P(A) = \sum_i P(A \cap B_i) = \sum_i P(A \mid B_i) P(B_i)$.

## Detaylı Açıklamalar

- Birleşim kuralının mantığı
  - $P(A)$ ve $P(B)$ toplanınca kesişimdeki elemanlar iki kez sayılır.
  - Bir kez sayılmaları için $P(A \cap B)$ bir kez çıkarılır.
- Alt küme kuralının ispatı
  - $A \subseteq B$ ise $P(B) = P(A) + P(B \setminus A)$.
  - Aksiyom 1'den $P(B \setminus A) \ge 0$. Bu yüzden $P(A) \le P(B)$.
- Sürekli uzay: tek noktanın olasılığı neden sıfır?
  - 0 ile 1 arasında sonsuz sayıda nokta var. Hepsi eşit olasılıklıysa her birinin olasılığı "1 bölü sonsuz", yani 0'dır.
  - Bu sezgiye aykırı görünebilir, çünkü sonunda bir nokta seçiyoruz.
  - Bu yüzden "seçilen nokta 0.5 ile 0.75 arasında mı?" gibi aralık soruları sorulur. Bu olasılık sıfır olmak zorunda değildir.
  - İki boyutlu sorularda bütün bölge alanı 1 kabul edilir. Bir alt bölgenin olasılığı, alanının oranıdır. Hoca bunun Venn diyagramı olmadığını, gerçek bir geometrik bölge olduğunu vurguladı.
  - Soru okurken bir doğru üzerinde mi yoksa bir alan üzerinde mi çalıştığınızı anlayın.
- Şartlı olasılığın sezgisel anlamı
  - Herhangi bir gün yağmur yağma olasılığı 0.3 olsun.
  - Pencereden baktınız ve gökte bulut gördünüz. Artık yağmur olasılığı daha büyüktür, ör. 0.5. Bu, $P(\text{yağmur} \mid \text{bulut})$'tur.
  - Yeni bilgi olasılığı değiştirir. Hoca Türkçe örnek de verdi: dersi kitaba çalışarak, çalışmadan veya dersleri dinleyerek geçme olasılıkları birbirinden farklıdır.
- Zar örneği
  - Hilesiz zar atılıyor. Sonucun 3 veya daha küçük olduğu biliniyor. Çift olma olasılığı nedir?
  - $B = \{1,2,3\}$, $A = \{2,4,6\}$, $A \cap B = \{2\}$.
  - $B$ yeni örneklem uzayı gibi davranır. $P(A \mid B) = |A \cap B| / |B| = 1/3$.
  - Pay ve payda $|\Omega|$'ya bölünürse genel formül çıkar: $P(A \mid B) = P(A \cap B) / P(B)$. Bu formül eşit olasılıklı olmayan durumlarda da geçerlidir.
- Şartlı aksiyom 2'nin mantığı
  - $B$ olduysa çıktı $B$'nin içindedir. $B \subseteq \Omega$ olduğu için çıktı kesinlikle $\Omega$'dadır. Bu yüzden $P(\Omega \mid B) = 1$.
  - Hoca önce bunu $P(B \mid B) = 1$ diye yazdı, sonra aksiyomun doğru biçiminin $P(\Omega \mid B) = 1$ olduğunu söyledi. İkisi de doğru bir eşitliktir.
- Uçuş örneği (Adana'dan İstanbul'a gelen arkadaşınız)
  - Uçuşların %90'ı zamanında kalkıyor, %80'i zamanında iniyor, %75'i hem zamanında kalkıp hem zamanında iniyor.
  - Model: $D$ = zamanında kalkış, $A$ = zamanında varış. $P(D) = 0.90$, $P(A) = 0.80$, $P(A \cap D) = 0.75$.
  - (a) Uçak zamanında kalktı. Zamanında varma olasılığı: $P(A \mid D) = 0.75 / 0.90 \approx 0.833$.
  - (b) Uçak zamanında indi. Zamanında kalkmış olma olasılığı: $P(D \mid A) = 0.75 / 0.80 = 0.9375$. Hoca bunu evde yapmanızı istedi.
  - Zamanında kalktığını bilmek, zamanında varış olasılığını 0.80'den 0.833'e çıkarır. Bu mantıklıdır.
- Bağımsızlık örnekleri
  - Uçuş örneği: $P(A)P(D) = 0.80 \times 0.90 = 0.72 \neq 0.75 = P(A \cap D)$. Kalkış ve varış bağımlıdır (dependent).
  - Yağmur ve yazı tura: para atmak yağmur olasılığını değiştirmez. "Yağmur" ve "yazı (tails)" olayları bağımsızdır.
- Yağmur ve para örneğinde örneklem uzayı (öğrenci sorusu, Türkçe)
  - Öğrenci, iki olayın farklı örneklem uzaylarında olup olmadığını sordu.
  - Hoca iki deneyi birlikte düşünmek gerektiğini söyledi: örneklem uzayı ikililerden oluşur. $\Omega = \{(R,T), (S,T), (R,H), (S,H)\}$. Burada R yağmur, S güneş, T yazı, H turadır.
  - $A$ = yağmur = $\{(R,T), (R,H)\}$, $B$ = yazı = $\{(R,T), (S,T)\}$.
  - Hepsi eşit olasılıklıysa $P(A) = P(B) = 1/2$ ve $P(A \cap B) = P(\{(R,T)\}) = 1/4 = P(A)P(B)$. Olaylar bağımsızdır.
- Toplam olasılık kuralının mantığı
  - Örneklem uzayı $B_1, \dots, B_4$ parçalarına bölünmüş olsun. $A$ olayı bu parçaların bazılarıyla kesişir.
  - $A$'nın parçalarla kesişimlerinin olasılıkları toplanınca $P(A)$ bulunur.
  - Her kesişim, şartlı olasılık tanımından $P(A \cap B_i) = P(A \mid B_i) P(B_i)$ diye yazılır.
- Ev ödevi: hileli paralar
  - Torbada 3 hileli para var. Tura (heads) gelme olasılıkları sırasıyla 0.9, 0.6 ve 0.3.
  - Torbadan rastgele bir para çekilip atılıyor. Tura gelme olasılığı nedir?
  - Her paranın çekilme olasılığı eşittir. Toplam olasılık kuralıyla çözülür.

### Ders sonrası notlar

- Alt küme ispatında hoca "olasılıklar sıfırdan büyüktür" bilgisini Aksiyom 2 olarak andı. Doğrusu **Aksiyom 1**'dir ($P(A) \ge 0$). Aksiyom 2, $P(\Omega) = 1$'dir.
- "Ayrık olaylar bağımsız değildir" sonucu yalnızca $P(A) > 0$ ve $P(B) > 0$ ise geçerlidir. Olaylardan birinin olasılığı 0 ise $P(A \cap B) = 0 = P(A)P(B)$ olur ve olaylar hem ayrık hem bağımsızdır.
- Ödevin cevabı: $P(\text{tura}) = \frac{1}{3}(0.9) + \frac{1}{3}(0.6) + \frac{1}{3}(0.3) = 0.6$.
- Uçuş örneğinin (b) şıkkı: $P(D \mid A) = 0.75 / 0.80 = 0.9375$.
- Sürekli uzayda "1 bölü sonsuz = 0" bir sezgidir, kesin bir hesap değildir. Kesin açıklama, sürekli dağılımlar konusunda yoğunluk fonksiyonu (density function) ile yapılır.
- Kayıtta yaklaşık 06:30-11:20, 52:00-01:00:00 ve 01:29-01:31 arası Türkçe tekrar kısımları büyük ölçüde anlaşılmıyor. Bu kısımlarda altyazı bozuk. Anlaşılan kısımlar yukarıda özetlendi.

**Not:** Bu ders İngilizce anlatılmıştır. İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
