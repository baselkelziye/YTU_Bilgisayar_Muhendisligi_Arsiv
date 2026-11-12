# Ders 13 Çalışma Özeti

Bu ders öğrenci proje sunumlarına ayrılmıştır. On iki sunum yapıldı; konular dört başlıkta toplanıyordu: hash fonksiyonlarının saldırılara karşı dayanıklılığı, çakışmaya dayanıklı (collision resistant) hash fonksiyonları ve evrensel (universal) hash, algısal hash (perceptual hashing) ve blokzincirde hash fonksiyonları. Aşağıda yalnız sunumların akademik içeriği ve hocanın akademik yorumları yer alır.

## Genel Konular

- Kriptografik hash fonksiyonunun güvenlik ölçütleri (birçok sunumda ortak)
  - Hash fonksiyonu, herhangi uzunluktaki girdiyi sabit uzunlukta bir çıktıya (özet, digest) eşleyen tek yönlü bir fonksiyondur. Kullanım alanları: parola saklama, dosya bütünlüğü (checksum), dijital imza, mesaj doğrulama, blokzincir.
  - Çakışma direnci (collision resistance): $x \neq x'$ olup $H(x) = H(x')$ olan bir çift bulmak zor olmalıdır. Girdi uzayı sonsuz, çıktı uzayı sonlu olduğu için çakışma teoride mutlaka vardır; amaç bulunmasını zorlaştırmaktır.
  - Ön görüntü direnci (preimage resistance): verilen $H(M)$ değerinden $M$ bulunamamalıdır.
  - İkinci ön görüntü direnci (second preimage resistance): verilen bir $x_1$ için $H(x_1) = H(x_2)$ olan başka bir $x_2$ bulunamamalıdır. Çakışmadan farkı, girdilerden birinin önceden verilmiş olmasıdır.
  - Basit örnek (derste sözlü, 00:06:39): $H(x) = x \bmod 3$ için $H(5) = H(8) = 2$ bir çakışmadır; 2 çıktısı için 5 bir ön görüntüdür; 8 verildiğinde 5 bir ikinci ön görüntüdür.
  - Doğum günü saldırısı: $n$ bitlik çıktıda çakışma bulmak için yaklaşık $2^{n/2}$ işlem yeter. 23 kişilik bir grupta iki kişinin doğum gününün aynı olma olasılığı yaklaşık %50'dir.
- Standart hash fonksiyonları ve saldırılar
  - MD5: 512 bit blok, 128 bit çıktı, Merkle-Damgård yapısı (ekrandan, 00:10:00). Dört adet 32 bitlik kelime (A, B, C, D) üzerinde çalışır; her turda farklı bir doğrusal olmayan fonksiyon ($F, G, H, I$), modüler toplama ve sola döndürme kullanılır (ekrandan, 01:40:00). Çakışma ve hızlı çakışma saldırılarına açıktır.
  - RIPEMD-160: iki paralel MD4 benzeri hattın birleştirilmesiyle elde edilir; 512 bit blok, 160 bit çıktı.
  - SHA-1: 512 bit blok, 160 bit çıktı (40 onaltılık hane), 80 tur, Merkle-Damgård (ekrandan, 01:30:00). Freestart çakışma: saldırganın başlangıç vektörünü (IV) kendisinin seçtiği çakışma türü. 2017'de iki farklı PDF dosyasının aynı SHA-1 özetini verdiği gösterildi.
  - SHA-2: 224, 256, 384, 512 ve 512/224, 512/256 sürümleri olan bir ailedir. SHA-256 sekiz adet 32 bitlik, SHA-512 sekiz adet 64 bitlik kelime üzerinde çalışır. Bilinen pratik bir çakışma yoktur.
  - SHA-3 (Keccak): bir yarışmayla seçildi; Merkle-Damgård yerine sünger (sponge) yapısını kullanır, iç durum 1600 bittir, 24 tur vardır (ekrandan, 01:45:40). Veri önce "emilir" (absorb), sonra "sıkılarak" (squeeze) çıktı alınır.
  - Teorik güvenlik bitleri tablosu (ekrandan, 01:45:40): çakışma güvenliği SHA-1 için $<80$, SHA-256 için 128, SHA-512 için 256, SHA3-256 için 128 bittir.
- Yeni önerilen hash yöntemleri (literatür)
  - Hücresel otomat tabanlı, değişken çıktı uzunluklu, kaotik harita tabanlı ve sinir ağı tabanlı hash fonksiyonları önerilmiştir. Ortak zayıflıklar: pratikte yeterince test edilmemiş olmak, MD5'in sorunlarını taşımak, çakışmaya zayıflık ya da 128 bit gibi kısa çıktı.
  - Bir karşılaştırma tablosunda (ekrandan, 02:50:00) 2015-2017 arası yedi çalışma, avantaj ve sınırlılıklarıyla listelendi; sınırlılıkların çoğu "kriptografik saldırılara karşı test edilmedi" ya da "128 bit çıktı, kapsamlı çakışma aramasına açık" idi.
  - Önerilen güvenli sürümler (ekrandan, 01:50:00): geliştirilmiş MD5, SHA-1 için paralel algoritma, SHA-256, SHA-3, RIPEMD ve Whirlpool.
- Evrensel (universal) hash fonksiyonları
  - Bir hash ailesi $H$ için, ailedeki fonksiyon rastgele seçildiğinde her $x \neq y$ çifti için $\Pr[h(x) = h(y)] \le 1/m$ ise $H$ evrenseldir ($m$: tablo boyutu, slot sayısı) (ekrandan, 01:06:40).
  - Amaç: algoritmanın hangi girdiyle karşılaşacağı bilinmediği için en kötü girdi karşısında bile beklenen çakışmayı düşük tutmak.
  - $n$ anahtar hash'lendiğinde bir $x$ anahtarının beklenen çakışma sayısı $E[C_x] = (n-1)/m$'dir (ekrandan, 01:10:00).
  - Asal sayı (prime) yöntemi: $h_{a,b}(x) = ((ax + b) \bmod p) \bmod m$, $a \in \{1,\dots,p-1\}$, $b \in \{0,\dots,p-1\}$; ailede $p(p-1)$ fonksiyon vardır (ekrandan, 01:11:50).
  - Matris yöntemi: $u$ bitlik anahtar, $M = 2^b$ boyutlu tablo, rastgele $b \times u$ ikili matris $h$; $h(x) = hx \pmod 2$ ve çakışma olasılığı $1/2^b$ (ekrandan, 01:16:10).
  - Polinom yöntemi: $H(x) = (x_0 + x_1 b + x_2 b^2 + \dots + x_{n-1} b^{n-1}) \bmod M$ (ekrandan, 01:18:45).
- Algısal hash (perceptual hashing)
  - Amaç kriptografik hash'in tersidir: içerik olarak benzer görüntüler benzer hash vermelidir. Çığ etkisi (avalanche) istenmez; iki hash arasındaki benzerlik Hamming uzaklığı gibi bir metrikle ölçülür.
  - Aranan özellikler: ayırt edicilik (distinct), dayanıklılık (resilient/robust), deterministik olma, verimlilik, geri döndürülemezlik, sabit uzunluk (kompaktlık).
  - Genel akış (ekrandan, 02:00:00): ön işleme (yeniden boyutlandırma, filtreleme, renk uzayı dönüşümü) → özellik çıkarma → hash üretme → referans hash'lerle uzaklık tabanlı karar (Öklid, Hamming, L1, korelasyon).
  - aHash (ortalama): gri seviye, 8×8'e küçültme, her hücreyi ortalamayla karşılaştırıp 1/0 yazma, 64 bit. dHash: komşu pikseller arasındaki farka bakar. pHash: 32×32, ayrık kosinüs dönüşümü (DCT), sol üstteki 8×8 düşük frekans katsayılarını ortalamayla karşılaştırır. wHash: ayrık dalgacık dönüşümü (DWT) kullanır (ekrandan, 02:10:00).
  - Uygulamalar: zararlı içerik moderasyonu, yinelenen görüntü ayıklama, telif ve intihal tespiti, adli analiz, ters görsel arama, nesne ve yüz takibi.
  - Nesne takibi çalışmaları (ekrandan, 00:40:00): geliştirilmiş üç kare farkı (three-frame differencing) ile aHash, pHash, dHash birlikte kullanıldı; aynı ekibin sonraki çalışması Laplace tabanlı LHash ve LDHash'i önerdi.
- Blokzincirde hash fonksiyonları
  - Blokzincir, herkesin kopyasını tuttuğu merkeziyetsiz, açık bir defterdir (public ledger). Her blok, önceki bloğun hash'ini tutar; aradaki bir işlem değişirse sonraki bütün blokların hash'i değişir ve değişiklik fark edilir.
  - Bir blok veri, kendi hash'i, önceki bloğun hash'i, zaman damgası ve nonce içerir. Blokzincir türleri: açık, özel, hibrit, konsorsiyum (ekrandan, 02:20:00).
  - Proof of Work: madenci, blok hash'i belirli sayıda sıfırla başlayana kadar nonce'u değiştirir. Bulmak zor, doğrulamak kolaydır. Düğümler her zaman en uzun doğrulanmış zinciri kabul eder.
  - Dijital imza: işlem özel anahtarla imzalanır, açık anahtarla doğrulanır (ekrandan, 01:00:00).
  - Kullanılan hash'ler: Bitcoin'de SHA-256, Ethereum'da Keccak-256, BLAKE2/BLAKE3, Bitcoin adreslerinde RIPEMD-160.
  - SHA-256 ön işlemesi: mesaj, uzunluğu 512'nin katından 64 eksik olacak şekilde doldurulur (önce bir adet 1, sonra 0'lar), sonra 64 bitlik uzunluk alanı eklenir: $L + P + 64 = n \cdot 512$. Her 512 bitlik blok 16 adet 32 bitlik kelimeye bölünür ve 64 turda işlenir (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Algısal hash'te dayanıklılık (resilient) özelliği
  - Hoca, bu özelliğin hangi uygulamalar için önemli olduğunu sordu. Cevap: nesne takibi; nesne hareket ettiğinde yalnız konumu değişir, hash'lerin birbirine yakın kalması beklenir. Hoca bu özelliğin klasik hash'ten farklı olduğu için açıklanmasının önemli olduğunu söyledi.
- Güncel çalışmalar
  - Hoca, sunumlarda güncel makalelere değinilmesini istediğini hatırlattı. Literatür özetlenirken çalışma adlarının slayta yazılmasını önerdi. Evrensel hash sunumunu teorik anlatımı için beğendi, ama güncel çalışmalara da yer verilmesini beklediğini söyledi.

## Kısa Tekrar Notları

- Üç güvenlik özelliği: çakışma, ön görüntü, ikinci ön görüntü direnci.
- Jenerik çakışma saldırısı $2^{n/2}$; 256 bit için $2^{128}$.
- MD5 128 bit, SHA-1 160 bit, SHA-2 224-512 bit; MD5 ve SHA-1 artık güvenli sayılmaz.
- Merkle-Damgård: dolgu + bloklara bölme + sıkıştırma fonksiyonunun ardışık uygulanması. Sünger: emme ve sıkma (SHA-3).
- Evrensel hash: $\Pr[h(x)=h(y)] \le 1/m$; beklenen çakışma $(n-1)/m$; $h_{a,b}(x) = ((ax+b) \bmod p) \bmod m$.
- Algısal hash: benzer içerik → benzer hash, Hamming uzaklığıyla karşılaştırma. aHash < dHash < pHash sırasıyla dayanıklılık ve maliyet artar.
- Blokzincir: önceki bloğun hash'i ile zincirleme, nonce ile Proof of Work, imza ile işlem doğrulama.

## Detaylı Açıklamalar

- Kaba kuvvetle ön görüntü bulmanın maliyeti (ekrandan, 00:28:45)
  - Slayttaki örnekte "Hello1!", "Hello2!", ..., "Hello10000!" ve başka girdiler denenmiş, hiçbiri hedef hash'i vermemiştir. Saniyede yaklaşık 60 milyon hash hesaplayan normal bir bilgisayar için beklenen deneme sayısı $2^{255}$ alınınca süre $2^{255} / (60 \cdot 10^6)$ saniye, yani yaklaşık $3 \cdot 10^{61}$ yıldır.
  - Altyazıda "2 üzeri 55" geçiyor; slaytta $2^{255}$ yazıyor. Hesap $2^{255}$ ile tutar (python ile doğrulandı); $2^{55}$ deneme yaklaşık 19 yıl sürerdi.
- Evrensel hash'te beklenen çakışma sayısının türetilmesi (ekrandan, 01:10:00)
  - $C_x$, $x$ ile çakışan anahtar sayısı olsun. $h(x) = h(y)$ ise $c_{xy} = 1$, değilse $0$. Böylece $C_x = \sum_{y \neq x} c_{xy}$.
  - Beklenen değerin doğrusallığından $E[C_x] = \sum_{y \neq x} E[c_{xy}] \le \sum_{y \neq x} \frac{1}{m} = \frac{n-1}{m}$. Tabloya $m$'den az anahtar konduğunda beklenen çakışma 1'den küçük kalır.
- Asal sayı yönteminde $a \neq 0$ olmasının nedeni (ekrandan, 01:11:50)
  - $a = 0$ olursa $h(x) = b \bmod m$ olur; hangi anahtar verilirse verilsin aynı sonuç çıkar ve her çift çakışır. Bu yüzden $a \in \{1, \dots, p-1\}$ seçilir.
  - $a$ için $p-1$, $b$ için $p$ seçenek vardır; aile $|H| = p(p-1)$ fonksiyondan oluşur. Evrensellik için bir $x_i \neq x_j$ çiftini çakıştıran fonksiyon sayısı en fazla $p(p-1)/m$ olmalıdır; bu sayı $|H|$'ye bölününce $1/m$ elde edilir.
  - > **Ders sonrası not:** Slaytta en büyük değerler "$a = p-1$, $b = p$" diye yazılmış. $b$'nin en büyük değeri $p-1$'dir; $|H| = p(p-1)$ sonucu $b$ için $p$ farklı seçenek olmasından gelir.
- Matris yönteminin sezgisi (01:16:00 civarı)
  - $x \neq y$ ise iki anahtar en az bir bitte ayrılır. Sunumdaki gösterimde $x$'in o biti 0, $y$'nin o biti 1 seçildi. $x$ için o bite karşılık gelen matris sütunu sonuca etki etmez, $y$ için eder. O sütun rastgele seçildiğinden $h(x) = h(y)$ olma olasılığı $1/2^b$ olur.
- Algısal hash yöntemlerinin karşılaştırılması
  - aHash yalnız ortalamaya göre karşılaştırma yaptığı için pikseller arası ilişkiyi göremez. Bir örnekte aynı renk tonlarına sahip ama bambaşka iki görüntüyü dHash az benzer, aHash daha benzer buldu; yani aHash'in ayırt etme gücü daha düşüktür.
  - 800 görüntüye 10 farklı manipülasyon uygulanan bir çalışmada çakışma olasılıklarının dağılımı incelendi; pHash ve dHash beklenen dağılıma daha yakın, aHash ve wHash daha uzak çıktı.
  - Sunumdaki yorum: içerik tabanlı görüntü aramada pHash yaygındır ama DCT yüzünden daha maliyetlidir; pHash ve wHash maliyetli, dHash hızlıdır. Çok hassas işlerde (adli analiz) daha hassas yöntem, hız gereken yerde dHash seçilebilir.
- Çığ etkisi örnekleri
  - Kriptografik hash'te tek bir harfin büyük yazılması ("hello" ve "hellO") ya da bir pikselde tek bir renk değerinin değişmesi, çıktı bitlerinin yaklaşık yarısını değiştirir. Algısal hash'te ise üzerine yazı eklenmiş bir fotoğrafın hash'i asıl hash'ten yalnız 3 bitte ayrıldı (Hamming uzaklığı 3).
- Düzeltmeler
  - > **Ders sonrası not:** Bir sunumda MD5'in "döngü sayısı 18" olduğu söylendi (ekrandan, 00:10:00); başka bir sunumda "toplamda 16 tur" dendi. MD5'te 4 tur ve her turda 16 adım, toplam 64 işlem vardır; aynı karşılaştırma tablosu da 64 yazıyor (ekrandan, 02:40:00).
  - > **Ders sonrası not:** RIPEMD-160'ın çıktısının MD5'ten "128 bit daha fazla" olduğu söylendi; fark $160 - 128 = 32$ bittir.
  - > **Ders sonrası not:** SHA-3 için "çıktıları 1600 bit" dendi; 1600 bit iç durum boyutudur, çıktı 224/256/384/512 bittir (ekrandan, 01:45:40).
  - > **Ders sonrası not:** Evrensel hash'i ortaya atanlar "Beckman ve Carter, 1978" diye anıldı; büyük olasılıkla Carter ve Wegman'dır (1977 konferans, 1979 dergi makalesi).
  - > **Ders sonrası not:** SHA-256 slaytında uzunluk alanı "$L \bmod 2^{32}$" yazıyor (ekrandan, 03:00:00); uzunluk alanı 64 bit olduğu için doğrusu büyük olasılıkla $L \bmod 2^{64}$'tür.
  - > **Ders sonrası not:** Bir sunumda dijital imzada "herkesin iki özel anahtarı var" dendi; her kullanıcının bir özel ve bir açık anahtarı vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
