# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 15 Ekim 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 05:20'de başlar. İlk dakikalar görüntü ayarı ve bekleme kısmıdır.
  - Hoca tahtayı bir tablet üzerinden yazıyor.
- Dersin işleyişi (tekrar)
  - Ofis saati Çarşamba 15:00-17:00. Uymazsa yarım saatlik Calendly görüşme talebi gönderebilirsiniz.
  - İzlence, notlandırma ve haftalar Bologna sisteminde (bologna.yildiz.edu.tr) bulunur.
  - Dosyalar Dropbox'tan paylaşılacak. Duyurular USİS e-postasıyla yapılacak.
  - Hoca derste bütün şubeye USİS'ten deneme e-postası ("Hello from P and S") gönderdi.
- Kümeler konusunun tekrarı
- Kümelerde yeni kavramlar
  - Fark için $A \setminus B = A \cap B^c$ kuralı.
  - Sayılabilir (countable) ve sayılamaz (uncountable) kümeler.
  - Sayılabilir sonsuz (countably infinite) kümeler.
  - Kapsayan (exhaustive) kümeler ve bölüntü (partition) ile farkı.
  - Kuvvet kümesi (power set).
- Olasılık teorisine giriş
  - Rastgele deney (random experiment), çıktı (outcome), olay (event), örneklem uzayı (sample space).
  - Olasılığın frekans ve inanç (Bayesçi) yorumları.
  - Olasılık aksiyomları (axioms of probability).
- Olasılık hesaplama kuralları
  - Eşit olasılıklı çıktılar.
  - Tümleyen, boş küme, üst sınır ve fark kuralları.

## Hocanın Özellikle Vurguladığı Kısımlar

- USİS e-postasını alamıyorsanız aynı gün YTÜ bilgi işlem birimiyle görüşün.
  - Duyurular bu sistemden yapılacak.
- Olaylar (events) birer kümedir.
  - Kümelerde öğrendiğimiz her şey (birleşim, kesişim, bölüntü, kapsayan kümeler) olaylar için de geçerlidir.
- Aksiyomlar çok önemlidir. Bunun iki nedeni var:
  - Olasılıkla ilgili diğer bütün kurallar bu üç aksiyomdan türetilir.
  - Aksiyomlara uyan her fonksiyon bir olasılık ölçüsüdür (probability measure). Bu yüzden öğreneceğimiz bütün kurallar o fonksiyon için de geçerlidir.
- Şartlı olasılık (conditional probability) da aksiyomlara uyar.
  - Bu yüzden $P(A^c) = 1 - P(A)$ kuralından doğrudan $P(A^c \mid B) = 1 - P(A \mid B)$ yazılabilir. Ayrıca ispat gerekmez.
- Matematikte ispatlamadığınız bir kuralı kullanamazsınız.
  - Bir kuralı bir kez ispatladıktan sonra o kural "alet çantanıza" girer. Sonraki ispatlarda kullanabilirsiniz.
- Kitaplar arasındaki notasyon farkları:
  - Fark: Pishro-Nik'te $A - B$, Baron'da $A \setminus B$.
  - Tümleyen: Baron'da $\bar{A}$, Pishro-Nik'te $A^c$.
  - Örneklem uzayı: Baron'da $\Omega$, Pishro-Nik'te $S$.
- Pishro-Nik'in kitabı ilk bölümlerde biraz daha ayrıntılıdır.
- Ev ödevi: $P(A \setminus B) = P(A) - P(A \cap B)$ kuralını ispatlayın.
  - İpucu: $A \setminus B = A \cap B^c$.

## Kısa Tekrar Notları

- Fark: $A \setminus B = A \cap B^c$.
- Sayılabilir küme: sonludur ya da elemanları bir dizi hâlinde numaralandırılabilir (enumerate).
  - $\mathbb{N}$, $\mathbb{Z}$ ve $\mathbb{Q}$ sayılabilirdir. $\mathbb{R}$ sayılamaz.
- Sayılabilir sonsuz küme: hem sayılabilir hem sonsuz olan küme. Örnek: $\mathbb{N}$.
- Kapsayan (exhaustive) kümeler: birleşimleri örneklem uzayıdır. Kesişebilirler.
- Bölüntü: birleşimi örneklem uzayıdır **ve** kümeler kesişmez.
- Kuvvet kümesi $\mathcal{P}(A)$: $A$'nın bütün alt kümelerinin kümesidir. $|\mathcal{P}(A)| = 2^{|A|}$. Boş kümeyi ve $A$'nın kendisini içerir.
- Rastgele deney: sonucu kesin olarak tahmin edilemeyen olay. Örnek: zar atmak, para atmak.
- Çıktı (outcome): deneyin bir sonucu. Olay (event): çıktılardan oluşan bir küme. Örneklem uzayı: bütün olası çıktıların kümesi.
- Bir olay, deneyin çıktısı o olayın içindeyse gerçekleşir (occurs).
- Olasılık aksiyomları ($P$, olayları reel sayılara götüren fonksiyon):
  - Aksiyom 1: Her $A$ olayı için $P(A) \ge 0$.
  - Aksiyom 2: $P(\Omega) = 1$.
  - Aksiyom 3: Ayrık $A_1, A_2, \dots$ olayları için $P(A_1 \cup A_2 \cup \dots) = P(A_1) + P(A_2) + \dots$
- Eşit olasılıklı çıktılarda: $P(E) = \dfrac{|E|}{|\Omega|}$.
- Tümleyen: $P(A^c) = 1 - P(A)$.
- Boş küme: $P(\emptyset) = 0$.
- Üst sınır: $P(A) \le 1$. Aksiyom 1 ile birlikte $0 \le P(A) \le 1$.
- Fark: $P(A \setminus B) = P(A) - P(A \cap B)$.

## Detaylı Açıklamalar

- $A \setminus B = A \cap B^c$ kuralı
  - Venn diyagramında $B^c$, $B$'nin dışındaki bölgedir.
  - $A$ ile $B^c$'nin ortak bölgesi, $A$'nın $B$'ye girmeyen kısmıdır. Bu da $A \setminus B$'dir.
- Sayılabilirlik
  - $A = \{2, 3, 4\}$ sonlu olduğu için sayılabilirdir.
  - $\mathbb{N} = \{1, 2, 3, \dots\}$: birinci, ikinci, üçüncü eleman diye numaralandırılabilir.
  - $\mathbb{R}$: "1.0'dan sonraki reel sayı" bulunamaz. 1 ile 1.1 arasında 1.05, onunla 1 arasında da başka bir sayı vardır. Bu yüzden numaralandırılamaz.
- Tam sayılar sayılabilir (bir öğrencinin chat sorusu üzerine)
  - Sayılabilir olmak için doğal sayılarla birebir eşleme kurabilmek gerekir.
  - Sıralı sayarsak ($0, 1, 2, 3, \dots$) negatiflere hiç sıra gelmez.
  - Sırayı değiştiririz: $0, 1, -1, 2, -2, \dots$ Bu sayımda hiçbir eleman atlanmaz.
- Rasyonel sayılar sayılabilir
  - Satırlara pay, sütunlara payda yazılan bir tablo kurulur. Kesişimlere $a/b$ yazılır.
  - İlk satırı bitirmeye çalışırsak satır sonsuz olduğu için hiç bitmez.
  - Bunun yerine tablo köşegenler boyunca gezilir: $1/1, 2/1, 1/2, 1/3, 2/2, 3/1, \dots$
  - Negatifler için her pozitif sayının hemen ardından negatifi yazılır.
- Kapsayan kümeler ile bölüntünün farkı
  - İkisinde de birleşim örneklem uzayıdır.
  - Kapsayan kümelerde kesişime izin verilir. Bölüntüde verilmez.
  - Her bölüntü kapsayandır, ama her kapsayan küme ailesi bölüntü değildir.
- Kuvvet kümesi örneği
  - $A = \{1, 2\}$ için $\mathcal{P}(A) = \{\emptyset, \{1\}, \{2\}, \{1,2\}\}$. Eleman sayısı $2^2 = 4$.
- Örneklem uzayı örnekleri
  - Altı yüzlü zar: $\Omega = \{1,2,3,4,5,6\}$.
  - Zar üç kez atılıyor: çıktılar sıralı üçlülerdir, ör. $(1,3,4)$ ve $(1,3,5)$. Örneklem uzayı bütün olası üçlülerdir.
  - "Sonuç tek sayı" olayı: $E = \{1, 3, 5\}$.
  - "Sonuç 1" olayı da bir kümedir: $\{1\}$.
- Bölüntü olarak olaylar
  - $E_1, \dots, E_4$ olaylarının birleşimi $\Omega$ ise ve her $i \neq j$ için $E_i \cap E_j = \emptyset$ ise, bu olaylar örneklem uzayının bir bölüntüsüdür.
- İnanç yorumu örneği
  - Ayşe'nin üniversite sınavını kazanma olasılığı. Ayşe bu sınava hayatında büyük olasılıkla bir kez girecek. Bu durumda olasılığı bir inanç olarak düşünmek daha uygundur.
  - Bu derste çoğunlukla frekans yorumu kullanılacak.
- Her fonksiyon olasılık olamaz
  - $P(A) = 3/2$ veren bir fonksiyon olasılık ölçüsü değildir. Olasılık ölçüsü aksiyomlara uymalıdır.
- Eşit olasılıklı çıktılar kuralının çıkarımı
  - Hilesiz zarda $P(1) = P(2) = \dots = P(6)$.
  - Çıktılar ayrıktır ve birleşimleri $\Omega$'dır. Aksiyom 2 ve 3'ten her çıktının olasılığı $1/6$ çıkar.
  - $E = \{1,3,5\}$ olsun. $E$ tek elemanlı kümelerin birleşimidir. Aksiyom 3'ten $P(E) = 1/6 + 1/6 + 1/6 = 3/6$.
  - 3 sayısı $|E|$, 6 sayısı $|\Omega|$'dır. Buradan $P(E) = |E| / |\Omega|$ kuralı çıkar.
  - Bu kural yalnızca çıktılar eşit olasılıklıysa geçerlidir. Hileli zarda kullanılamaz.
- Tümleyen kuralının ispatı
  - $A \cup A^c = \Omega$ ve $A \cap A^c = \emptyset$.
  - Aksiyom 3'ten $P(A) + P(A^c) = P(\Omega)$. Aksiyom 2'den $P(\Omega) = 1$.
  - Buradan $P(A^c) = 1 - P(A)$.
- Boş küme kuralının ispatı
  - $\emptyset \cup \Omega = \Omega$ ve $\emptyset \cap \Omega = \emptyset$. Yani ikisi ayrıktır.
  - Aksiyom 3 ve 2'den $P(\emptyset) + 1 = 1$. Buradan $P(\emptyset) = 0$.
- $P(A) \le 1$ ispatı
  - Tümleyen kuralından $P(A) = 1 - P(A^c)$.
  - Aksiyom 1'den $P(A^c) \ge 0$. Bu yüzden $P(A) \le 1$.
- Ders sonunda Türkçe tekrar
  - Bir öğrencinin isteği üzerine hoca aksiyomları ve kuralları Türkçe olarak özetledi.
  - Hoca, bu kuralların bir kısmının sezgisel olarak çok basit olduğunu söyledi. Ama derste amaç bunları aksiyomlardan yola çıkarak ispatlamak ve mantığı oturtmak.

### Ders sonrası notlar

- Derste rastgele deney için önce "sonucu belirsizlikle tahmin edilemeyen" dendi. Doğrusu: sonucu **kesin olarak** (with certainty) tahmin edilemeyen. Hoca tahtaya doğrusunu yazdı.
- Aksiyom 3 derste "$A_1$'den $A_n$'ye kadar sayılabilir ayrık olaylar" diye yazıldı. Bu aksiyom sonsuz dizi $A_1, A_2, A_3, \dots$ için de geçerlidir (sayılabilir toplamsallık, countable additivity). Sonlu sayıda olay bunun özel durumudur.
- Rasyonel sayıları köşegen boyunca sayarken $2/2$ gibi tekrarlar çıkar ($2/2 = 1/1$). Tekrar eden değerler atlanarak sayım yapılır. Bu sayılabilirlik sonucunu değiştirmez.
- Derste $x^2$'nin görüntü kümesi yine "pozitif sayılar" diye geçti. Doğrusu $[0, \infty)$'dur, çünkü $0^2 = 0$.
- Fark kuralı ödevinin bir çözümü
  - $A = (A \cap B) \cup (A \cap B^c)$ ve bu iki küme ayrıktır.
  - Aksiyom 3'ten $P(A) = P(A \cap B) + P(A \cap B^c)$.
  - $A \cap B^c = A \setminus B$ olduğu için $P(A \setminus B) = P(A) - P(A \cap B)$.
- Kayıtta 01:16-01:17, 01:47 ve yaklaşık 02:27-02:50 arası büyük ölçüde anlaşılmıyor. Bu kısımlarda Türkçe konuşma var ve altyazı bozuk. Türkçe tekrarın anlaşılan kısımları yukarıda özetlendi.

**Not:** Bu ders İngilizce anlatılmıştır. İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
