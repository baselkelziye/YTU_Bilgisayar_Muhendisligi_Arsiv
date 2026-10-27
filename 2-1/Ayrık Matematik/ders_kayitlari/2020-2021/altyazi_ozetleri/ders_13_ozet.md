# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 8 Ocak 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin son kaydıdır.
  - Aynı gün 10.30'da vize sınavı vardı. 1 Ocak tatili yüzünden yetişmeyen konu sınavdan önce kısaca anlatıldı.
  - Kayıt yaklaşık 55 dakikadır.
- Sonlu durum makineleri (finite-state machines)
  - Günlük hayattan örnekler: turnike, asansör.
  - Bilgisayar bilimindeki kullanım alanları: doğal dil işleme, ses tanıma, görüntü işleme.
- Çıktılı sonlu durum makinesinin biçimsel tanımı: $M = (S, I, O, f, g, s_0)$.
- Durum tablosu ile durum diyagramı arasında geçiş.
- Verilen bir girdi dizisi için çıktıyı bulma.
- Başlangıç ve bitiş (final) durumları.
- Tasarım örnekleri
  - Sağa kaydırma (ikiye bölme) yapan makine.
  - Bir bitlik iki sayıyı toplayan seri toplayıcı.
  - Art arda üç 1 gelince hata veren makine.
  - 4 karakterlik değişken adı denetleyicisi.
- Dersin sonunda bir öğrenci, Ayrık Matematik dersinden ne beklendiğini sordu. Hoca cevap verdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir olayı modellerken önce kaç durum (state) gerektiğine karar verin. Olay bunun üzerine kurulur.
  - Toplamada iki durum vardır: elde var, elde yok.
  - Çıkarmada iki durum vardır: borç alındı, borç alınmadı.
- Durum tablosu verilirse diyagramı çizebilmeli, diyagram verilirse tabloyu yazabilmelisiniz.
  - Problem karmaşıksa hata yapmamak için tablo çizin. Basitse doğrudan diyagram yeterli.
- Girdinin soldan mı sağdan mı okunduğu sonucu değiştirir. Tasarımda bunu belirtmek gerekir.
- Akan bir veri (sürekli giriş) varsa bitiş durumu yoktur.
  - Durma noktası belliyse (ör. ilk hatada çık, şifre uzunluğu) bitiş durumu konur.
  - Başlangıç durumu tektir. Bitiş durumu birden fazla olabilir.
- Kendinize alıştırma yapın: sola kaydırma, iki bitlik sayıları toplama, çıkarma makineleri.
- Ayrık Matematik, bilgisayar biliminin terminolojisini ve bakış açısını veren bir derstir.
  - Lojik, veri yapıları, algoritmalar, hesaplama kuramı gibi derslere ön bilgi verir.
  - Örnek: Ağacı dizi ile tutmak. Sol çocuk $2i$, sağ çocuk $2i+1$.
  - Örnek: Alt kümeleri bulmak için ikili sayıları kullanmak, uzun bir kodu tek satıra indirir.

## Kısa Tekrar Notları

- Çıktılı sonlu durum makinesi $M = (S, I, O, f, g, s_0)$:
  - $S$: sonlu durum kümesi
  - $I$: girdi alfabesi
  - $O$: çıktı alfabesi
  - $f: S \times I \to S$: geçiş fonksiyonu (sonraki durum)
  - $g: S \times I \to O$: çıktı fonksiyonu
  - $s_0$: başlangıç durumu
- Diyagramda bir kenar "girdi/çıktı" ($a/0$ veya $a,0$) diye etiketlenir.
- Bitiş durumu iç içe iki halka ile gösterilir.
- Seri toplayıcı: $s_0$ = elde yok, $s_1$ = elde var.
  - Girdi iki bitin ikilisi, çıktı toplam biti.
  - Bitler en sağdan (en düşük basamaktan) başlanarak verilir.
- Art arda üç 1 makinesi: üç durum yeterlidir ($s_0, s_1, s_2$).
  - Her 0 başa döndürür.
  - $s_2$'de 1 gelince çıktı 1 olur ve $s_2$'de kalınır.

## Detaylı Açıklamalar

### Turnike ve asansör

- Turnikenin iki durumu vardır: kapalı ve açık.
  - Kart basılınca kapalıdan açığa geçer.
  - Yolcu geçince yeniden kapalıya döner.
- Asansörde de "içeride" ve "dışarıda" gibi durumlar ve kat düğmesi gibi geçiş olayları vardır.
- Doğal dil işlemede, bir kelimenin kökü ve ekleri Türkçe kurallarına uyuyor mu diye durumlar arasında ilerlenir.
  - Son duruma gelinip kelime bittiyse kelime kurallara uyuyordur.

### İki durumlu tablo örneği

- $I=\{a,b\}$, $O=\{0,1\}$, $S=\{s_0,s_1\}$, başlangıç $s_0$.

| Durum | $a$ | $b$ |
| :---: | :---: | :---: |
| $s_0$ | $s_0$, 0 | $s_1$, 1 |
| $s_1$ | $s_1$, 1 | $s_1$, 0 |

- Diyagramda:
  - $s_0$'da $a/0$ ile kendine döner, $b/1$ ile $s_1$'e geçer.
  - $s_1$'de $a/1$ ve $b/0$ ile kendine döner.

### Beş durumlu makinede çıktı bulma

- Başlangıç $s_0$, girdi `101011`.
- İzleme:
  - $s_0 \xrightarrow{1/0} s_3$
  - $s_3 \xrightarrow{0/0} s_1$
  - $s_1 \xrightarrow{1/1} s_2$
  - $s_2 \xrightarrow{0/0} s_3$
  - $s_3 \xrightarrow{1/0} s_0$
  - $s_0 \xrightarrow{1/0} s_3$
- Çıktı: `001000`.

### Sağa kaydırma makinesi

- Üç durumlu makineye $12 = 1100_2$ verildi.
- Girdi soldaki (en anlamlı) bitten başlanarak verilince çıktı $0110_2 = 6$ olur.
  - Tekrar verilince $3$, bir kez daha verilince $1$ çıkar.
  - Makine sayıyı ikiye böler, yani bir bit sağa kaydırır. Tam sayı işlem yaptığı için $1{,}5$ yerine $1$ verir.
- Aynı girdi sağdan verilince farklı bir sonuç ($8$) çıktı.
  - Bu yüzden girdinin hangi uçtan okunacağı tasarımın parçasıdır.

### Seri toplayıcı (bir bitlik iki sayı)

| Durum | 00 | 01 | 10 | 11 |
| :---: | :---: | :---: | :---: | :---: |
| $s_0$ (elde yok) | $s_0$, 0 | $s_0$, 1 | $s_0$, 1 | $s_1$, 0 |
| $s_1$ (elde var) | $s_0$, 1 | $s_1$, 0 | $s_1$, 0 | $s_1$, 1 |

- Örnek: $s_1$'de $11$ gelirse $1+1+1 = 3$ olur. Çıktı 1, elde yine 1. Bu yüzden $s_1$'de kalınır.
- Örnek: $s_1$'de $00$ gelirse $0+0+1 = 1$ olur. Çıktı 1, elde kalmaz. $s_0$'a dönülür.

### Art arda üç 1 gelince hata

- $s_0$: hiç 1 sayılmadı. $s_1$: bir 1 sayıldı. $s_2$: iki veya daha fazla art arda 1 sayıldı.
- Geçişler:
  - Her durumda 0 gelirse çıktı 0 olur ve $s_0$'a dönülür.
  - $s_0 \xrightarrow{1/0} s_1$, $s_1 \xrightarrow{1/0} s_2$.
  - $s_2 \xrightarrow{1/1} s_2$: üçüncü ve sonraki her art arda 1 için hata çıktısı verilir.
- `0111110` gibi bir girdide, üst üste binen her üçlü için ayrı hata verilir.
- "İlk hatada dur" denirse $s_2$'den çıkan $1/1$ kenarı bir bitiş durumuna gider.

### 4 karakterlik değişken adı

- Kurallar:
  - Ad tam 4 karakterdir.
  - İlk karakter harf olmalıdır (A-Z, a-z).
  - 2., 3. ve 4. karakterler harf veya rakam (0-9) olabilir.
  - Ü, Ç, J gibi bunların dışındaki karakterler $\Sigma$ ile gösterilir ve kabul edilmez.
- Durumlar: $S_0 \to S_1 \to S_2 \to S_3 \to S_4$ (bitiş).
  - $S_0$'da rakam veya $\Sigma$ gelirse $S_0$'da beklenir.
  - Her geçerli karakter bir sonraki duruma geçirir.
  - $S_4$ bitiş durumudur, başka girdi kabul edilmez.
- "Yanlış karakterde baştan başla" denirse $\Sigma$ kenarları $S_0$'a bağlanır.

### Sınav bilgisi

- Ders, aynı gün saat 10.30'da yapılacak vize sınavından hemen önce işlendi.
  - Ders 12'de bu vizenin test olacağı, finalin klasik olacağı söylenmişti.
- Hoca, sonlu durum makinelerinin vizeden sonraki zamanda anlatılmasını planlamıştı. Sonra sınavdan önce anlatmaya karar verdi.
- Kayıtta final sınavının tarihi ve kapsamı hakkında ayrıntı yok.

### Ders sonrası notlar

- **$f$ ve $g$ fonksiyonları:** Hoca $f$'yi "durumdan çıkış", $g$'yi "dönüş fonksiyonu" diye anlattı. Rosen'daki tanımda $f$ geçiş fonksiyonudur. $f$, durum ve girdiden sonraki durumu verir. $g$ çıktı fonksiyonudur. $g$, durum ve girdiden üretilecek çıktıyı verir.
- **Bitiş durumu:** Rosen'da çıktılı sonlu durum makinelerinin (Mealy makinesi) bitiş durumu yoktur. Bitiş (kabul) durumları, dil tanıyan sonlu durum otomatlarına aittir. Hocanın şifre ve değişken adı örnekleri bu ikinci türe girer. Bu yüzden orada çıktı yerine kabul/ret konuşulur.
- **"Epsilon":** Değişken adı örneğinde hoca birkaç kez "epsilon" dedi, sonra düzeltti. Kastedilen geçersiz karakterler kümesi $\Sigma$'dır. $\varepsilon$ otomatlarda boş dizgi için kullanılır, karıştırılmamalıdır.
- **Kaydırma makinesinin "sağdan" sonucu:** Altyazıda sağdan okumanın sonucu 8 diye geçiyor. Makinenin tam tablosu kayıtta okunmadığı için bu sonuç doğrulanamadı. Soldan okumanın ikiye böldüğü ($12 \to 6 \to 3 \to 1$) izlemeyle tutarlı.
- **Doğrulama:** Beş durumlu makinenin `101011` için `001000` çıktısı ve seri toplayıcı tablosu Python ile kontrol edildi. Toplayıcı, en düşük bitten başlayarak bütün 4 bitlik sayı çiftleri için doğru toplamı verdi.
- Altyazıdaki "row 0/row 1" $s_0/s_1$, "stake/X-Tate" state, "sonu durum makineleri" sonlu durum makineleri, "A putu/ağa kut" output demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
