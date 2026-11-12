# Ders 8 Genişletilmiş Notu: Üçüncü Ödev Sunumları: SFT, Multi-SFT ve GRPO ile Doğruluk-Farklılık Dengesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi ve Ödevin Konusu
- 2. Deney Düzeni
- 3. Doğruluğun Ölçülmesi: Cevaptan Sayıyı Çıkarmak
- 4. Farklılığın Ölçülmesi
- 5. SFT ve Multi-SFT Verisinin Üretilmesi
- 6. GRPO: Algoritma ve Ödül Tasarımları
- 7. Sonuçlar ve Ortak Bulgular
- 8. Grafiklerin Kurulması ve Okunması
- 9. Nitel Örnek: Hiçbir Modelin Çözemediği Soru
- 10. Hocanın Yöntem Uyarıları ve Yapay Zekâ Kullanımı
- Örnek Sorular

## 1. Dersin Çerçevesi ve Ödevin Konusu

Bu dersin tamamı üçüncü ve son ödevin sunumlarına ayrıldı. Önceki sunum dersinde (Ders 5) ikinci ödev, yani dil modellerinde gizli durum yörüngelerinin analizi sunulmuştu. Bu kez konu, bir dil modelinin sonradan eğitilmesinin (post-training) ürettiği cevaplara etkisiydi. Hoca yeni konu anlatmadı; her sunumda ölçütlerin nasıl hesaplandığını, grafiklerin neyi gösterdiğini ve kodun ne kadarının öğrenciye ait olduğunu sordu.

Hoca dersin başında ödevin herkesçe bilindiğini, bu yüzden sunumlarda ödevin tanıtımına zaman harcanmamasını istedi. Asıl beklentisi şuydu: öğrencinin temel olarak ne yaptığı, yapay zekâlı ve yapay zekâsız çözümleri arasında hangi farkların olduğu ve sonuçların nasıl yorumlandığı.

Ödevin sorusu sunumlarda şöyle tekrarlandı (00:21:03): bir model sonradan eğitildikçe ürettiği cevapların **doğruluğu** (accuracy) ve aynı soruya verdiği cevapların birbirinden **farklılığı** (diversity, çeşitlilik) nasıl değişir? İdeal olan, hem doğru hem birbirinden farklı cevaplar üreten bir modeldir. Sunumlarda tekrar eden gözlem ise bu ikisinin çoğu zaman birbirine karşı hareket ettiğiydi: doğruluk arttıkça model hep aynı doğru yolu kullanmaya başlıyor ve cevaplar birbirine benziyordu (00:40:21).

## 2. Deney Düzeni

### 2.1 Veri ve modeller

Sunumlarda ortak olan düzen şuydu:

- **Veri kümesi:** Türkçe matematik problemleri, `ytu-ce-cosmos/gsm8k_tr` (ekrandan, 01:45:00). Bu, GSM8K veri kümesinin Türkçe sürümüdür.
- **Bölme:** 1000 eğitim ve 500 test sorusu. Bir öğrenci bölmeyi sabit bir rastgele tohumla (seed 42) yaptı (00:09:34).
- **Taban model:** `Qwen/Qwen3.5-4B` (ekrandan, 01:45:00); derste "3.5-4 milyar" diye geçti.
- **Öğretmen model:** SFT ve Multi-SFT çözümlerini üretmek için büyük bir model; çoğunlukla `gpt-oss-120b`. Öğrenciler bu modele bir API sağlayıcısı üzerinden eriştiler, çünkü 120 milyar parametreli bir modeli yerelde çalıştırmak mümkün değildi.
- **Karşılaştırılan modeller:** Base, SFT, Multi-SFT, GRPO, SFT+GRPO, Multi-SFT+GRPO.

Bazı öğrenciler taban modeli değiştirdi. Gerekçeler farklıydı: bir öğrenci Qwen3.5-4B'nin tabanda %75 gibi yüksek bir başarı verdiğini, bunun üstüne %20 eklemenin mümkün görünmediğini söyleyip Qwen2.5-3B'ye geçti (02:55:48); başkaları bellek, süre ya da kütüphane uyumsuzluğu yüzünden Qwen2.5'in 1.5B, 3B ya da 14B sürümlerine ya da Qwen3-4B'ye geçti. Bir grup, eğitimi hızlandıran Unsloth ve çıkarımı hızlandıran vLLM kütüphanelerini birlikte kullanabilmek için Qwen3-4B'yi seçti (02:39:56).

### 2.2 Cevap üretimi ve çiftler

Her test (ve eğitim) sorusu için her modelden 10 cevap üretildi. Aynı isteme farklı cevaplar alabilmek için örnekleme açık olmalıdır. Bir öğrenci bunu şöyle anlattı (02:07:50): üretim fonksiyonunda örnekleme kapatılırsa (`do_sample=False`) model her adımda en olası token'ı seçer ve aynı isteme hep aynı cevabı verir. Örnekleme açılıp sıcaklık (temperature) yükseltildikçe cevaplar birbirinden daha çok ayrışır.

10 cevaptan ikişerli $\binom{10}{2}=45$ çift çıkar. Her çift grafikte bir noktadır. 500 test sorusu için bu $500\times45=22.500$ çift eder (00:57:23).

Bir öğrencinin sunumunda iş yükü şöyle özetlendi (ekrandan, 00:30:00): her model için 1000 eğitim ve 500 test sorusunda 10'ar cevap, yani model başına 15.000 cevap; 6 model için yaklaşık 90.000 cevap üretimi; bunlardan 405.000 çift noktası. Hesap: $6\times1500\times45=405.000$. Öğrenci bunun A100 üzerinde yaklaşık 40 saat sürdüğünü belirtti.

### 2.3 Hedefler

Ödevde iki hedef vardı (00:45:35): SFT ile taban modele göre yaklaşık %10, SFT+GRPO ile yaklaşık %20 doğruluk artışı. Bir öğrenci bu hedefleri grafikte iki yatay çizgi olarak gösterdi; SFT'lerin %10 çizgisini, GRPO'lu modellerin %20 çizgisini geçtiğini söyledi.

### 2.4 Bir çiftin iki koordinatı

Her cevap çifti iki sayıyla grafiğe yerleştirilir:

- **Y, çift doğruluğu:** İki cevap da doğruysa 1, biri doğruysa 0.5, ikisi de yanlışsa 0 (00:56:22). Bu, çiftteki iki cevabın doğruluk değerlerinin ortalamasıdır.
- **X, farklılık:** İki cevap metninin ne kadar farklı olduğu. En yaygın ölçüt iki cevabın embedding'leri arasındaki kosinüs benzerliğinin birden çıkarılmasıdır:

$$\text{farklılık}(i,j) = 1-\cos(\mathbf{e}_i,\mathbf{e}_j)$$

İdeal bölge grafiğin sağ üst köşesidir: yüksek doğruluk ve yüksek farklılık (ekrandan, 00:15:00).

## 3. Doğruluğun Ölçülmesi: Cevaptan Sayıyı Çıkarmak

Doğruluk, modelin cevabından çıkarılan sayının referans cevapla karşılaştırılmasıyla ölçüldü. Asıl zorluk sayıyı güvenilir biçimde çıkarmaktı.

### 3.1 Düzenli ifade ile çıkarma

Bir öğrencinin kodunda yöntem şöyleydi (ekrandan, 02:30:00):

```python
def extract_last_number(text):
    if not text:
        return None
    match = re.search(r"####\s*\[?(-?[\d.,]+)\]?", str(text))
    if match:
        raw = match.group(1)
    else:
        numbers = re.findall(r"-?\d+(?:[.,]\d+)?", text)
        if not numbers:
            return None
        raw = numbers[-1]
    ...
    raw = raw.replace(",", ".")
    # Sadece nokta veya boş string döndürme
    if raw in (".", "", "-"):
        return None
    try:
        float(raw)
        return raw
    except ValueError:
        return None
```

Önce GSM8K'nin `#### <sayı>` kalıbı aranır; bulunamazsa metindeki **son sayı** alınır. Öğrenci binlik ayracı olarak kullanılan noktayı silmek ve ondalık virgülü noktaya çevirmek zorunda kaldığını anlattı (02:30:00). Kodun 96-97. satırları ekranda kısmen kapalıydı.

<!-- BELİRSİZ: 96-97. satırların tam içeriği ekranda bir ipucu kutusunun altında kaldı; noktadan sonra üç hane varsa noktayı silen bir kontrol olduğu anlaşılıyor. -->

### 3.2 Karşılaşılan sorunlar

Sunumlarda dile getirilen sorunlar:

- **Biçim eşleşmemesi:** `42.0` ile `42` metin olarak eşit görünmez (00:42:27).
- **Modelin formatı bozması:** Model bazen cevap etiketini koymuyor, "eşittir, eşittir, eşittir" gibi anlamsız tekrarlara girebiliyor ya da cevabı sonda değil ortada yazıyordu (00:55:07, 02:13:15).
- **Dil ve stil:** Öğretmen çözümleriyle eğitilen modelin cevaplarında İngilizce ve LaTeX parçaları vardı. Bir öğrenci kirli çıktılardan sonucu bulmak için uzun bir "sonuçları çıkar" fonksiyonu yazmak zorunda kaldı (02:13:15).
- **Kopan ya da eksik üretimler:** Ücretsiz API kullanımında bağlantı kopmaları ya da atlanan sorular oldu; bir grup başarısız istekleri en çok 3 kez yeniden denedi (00:49:06).
- **Değerlendirme fonksiyonunun hatası:** Bir öğrencinin ilk düzenli ifadesi cevapları yanlış okuduğu için doğruluk %7-%10 çıktı; cevaptaki son sayılara bakan ek kodla %40'lara yükseldi. Yani modeller aslında çözebiliyordu; düşük skor ölçüm hatasıydı (00:05:26).

### 3.3 Referans cevaplardaki hatalar

Bir öğrenci veri kümesindeki bazı referans cevapların yanlış olduğunu fark etti (01:44:35). Referans yanlışsa model doğru çözse bile yanlış sayılır. Öğrenci öğretmen modelin cevabıyla referansın uyuşmadığı soruları ayırdı, bunları başka araçlarla da kontrol etti ve referansları düzeltti (ekrandan, 01:45:00: "Cevaplarda yanlışlar olduğu tespit edildiği için gpt-oss-120b yardımıyla düzenleme yapıldı"). Aynı öğrencinin gözlemine göre, yapay zekâya baştan sona yaptırılan çözüm bu sorunu fark etmedi ve kontrol mekanizması yanlış olduğu için doğruluk çok düştü (01:53:18).

Başka bir öğrenci referans cevapların veri kümesinde bazen başta, bazen sonda olduğunu görünce, her referans çözümdeki sonucu ayrıca `gpt-oss-120b`'ye çıkarttı (02:56:22).

### 3.4 Farklı doğruluk ölçütleri

Bazı sunumlar ikili doğruluğun yanına başka ölçütler ekledi:

- **Soft doğruluk:** Tahminin referansa ne kadar yakın olduğuna göre kısmi puan (02:55:21).
- **Pass@1, Pass@10, çoğunluk oylaması:** Bir öğrenci üç ölçüt kullandı (02:21:57): Pass@1, 10 cevabın ortalama doğruluğu; Pass@10, 10 cevaptan en az biri doğruysa soruyu doğru sayan ölçüt; çoğunluk oylaması (majority voting, self-consistency), en sık tekrar eden cevabın doğru olup olmadığı.
- **Açgözlü çözümle doğruluk:** Bir öğrenci sıcaklığı sıfırlayıp (greedy decoding) tek cevapla da ölçtü. Bu ölçümde Multi-SFT, SFT'den yüksek çıktı; sıcaklıklı ölçümde tersiydi (02:36:38).

Pass@10 ölçütüyle ilgili bir sunumda eğitim kümesi sonuçları şöyleydi (ekrandan, 02:22:20):

| Model | Pass@1 | Çoğunluk oylaması | Pass@10 |
|---|---|---|---|
| Multi-SFT+GRPO | 65.3 | 69.5 | 84.5 |
| Multi-SFT | 65.0 | 69.2 | 84.8 |
| GRPO | 7.9 | 3.4 | 41.6 |
| SFT+GRPO | 2.4 | 2.3 | 6.6 |
| SFT | 2.2 | 2.2 | 5.7 |
| Base | 8.8 | 1.6 | 45.3 |

<!-- BELİRSİZ: Hocanın sorusu altyazıda "PES bana göre niye düşük kalıyor" diye geçiyor; hangi ölçüte işaret ettiği net değil. Öğrencinin cevabı çoğunluk oylamasıyla ilgili. -->

**Soru:** Çoğunluk oylaması neden bazı modellerde ortalama doğruluktan bile düşük? **Cevap:** Öğrenciye göre modeller sık sık döngüye girip cevabı tamamlayamıyordu; bir soruda en çok tekrar eden "cevap" boş (None) olunca çoğunluk oylaması yanlış sayılıyordu (02:23:19). Hoca sonucu garip bulduğunu söyledi.

Aynı sunumun test sonuçlarında tabanın %1, Multi-SFT'nin 56 civarı çıkması hocaya göre tuhaftı; öğrenci de nedenini açıklayamadı. Hoca "anlayamadıysan sıkıntı bu" dedi (02:24:39).

> **Ders sonrası not:** Bu sunumda Multi-SFT verisi aynı sorunun farklı çözümleri yerine farklı alanlardan farklı sorulardan oluşturulmuştu (bkz. 5.3). Test değerlendirmesinde de modellere farklı sistem istemleri verilmişti. Sonuçların bu yüzden karşılaştırılabilir olmaması büyük olasılıkla tuhaflığın kaynaklarından biridir.

## 4. Farklılığın Ölçülmesi

### 4.1 Embedding tabanlı ölçütler

Çoğu sunum iki cevabı bir cümle embedding modeline verip $1-\cos$ hesapladı. Kullanılan modeller:

- Türkçe E5 Large (Cosmos ekibinin modeli) (01:16:50, 01:46:06, 03:04:01).
- `paraphrase-multilingual-mpnet-base-v2` (ekrandan, 00:56:15).
- Bir MiniLM modeli (02:10:11).

Bir öğrencinin koddaki hesabı (ekrandan, 02:11:10):

```python
for idx1, idx2 in indeks_ciftleri:
    # 3. Adım: 1 - Cosine Similarity (Uzaklık) Hesaplama
    vec1 = embeddings[idx1].reshape(1, -1)
    vec2 = embeddings[idx2].reshape(1, -1)
    sim = cosine_similarity(vec1, vec2)[0][0]
    uzaklik = 1.0 - sim
    x_koordinatlari.append(uzaklik)

    # 4. Adım: Sayısal Ortalama ve Başarı Hesaplama
    sayi1 = cevap_sayilari[idx1]
    sayi2 = cevap_sayilari[idx2]
    hata = np.abs(gercek_sonuc - (sayi1 + sayi2)/2) / 5
    basari = np.pow(1/(hata+1), 1/5)
    y_koordinatlari.append(basari)
```

Bu öğrenci Y eksenini ikili doğruluk yerine sürekli bir "başarı skoru" olarak kurdu: çiftin iki sayısal cevabının ortalaması alınır, referanstan farkının mutlak değeri 5'e bölünür ve $\left(\frac{1}{\text{hata}+1}\right)^{1/5}$ hesaplanır. Öğrencinin açıklamasıyla, hata 0 ise $1/1=1$; hata 1 ise $1/2=0.5$ olur. Beşinci kök, küçük hatalarda skorun 0.85'in üzerinde kalması içindi (02:10:39 - 02:11:31).

> **Ders sonrası not:** Öğrenci "hata 1 olduğunda 0.5" dedi; bu, kök alınmadan önceki değerdir. Koddaki beşinci kökle birlikte hata 1 için skor $0.5^{1/5}\approx0.871$ olur (python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Bu formülde iki cevabın önce ortalaması alındığı için, referansı 5 olan bir soruda 4 ve 6 cevaplarından oluşan çiftin hatası sıfır çıkar; iki yanlış cevap tam puan alır. Ödevde istenen çift doğruluğu ise her cevabı ayrı ayrı doğru/yanlış sayar.

### 4.2 Embedding'siz ölçütler

- **TF-IDF + kosinüs:** Bir öğrenci cevapları TF-IDF ile vektörleştirip kosinüs benzerliğini kullandı (02:33:38; ekrandan, 02:00:00: "Çeşitlilik (1 - cosine TF-IDF)").
- **Jaccard:** Noktalama işaretleri ve satır sonları atıldıktan sonra kalan kelime kümelerinin örtüşmesi (01:33:50). Öğrenci bunun anlamsal bir benzerlik olmadığını, anlamsal bir ölçütle sonucun farklı çıkabileceğini kendisi not etti.
- **SequenceMatcher:** Karakterlerin aynı olup olmadığına bakan bir benzerlik; "cevap 40" ile "cevap 40'tır" arasında yüksek benzerlik yakalar. Farklılık, benzerliğin birden çıkarılmasıyla elde edildi (00:10:50).
- **ROUGE-L:** İki metindeki en uzun ortak alt diziyi (longest common subsequence) bulup benzerliği buna göre hesaplar (01:40:02). Öğrenci n-gram'larla çalışan bu yöntemi embedding'ler yerine denemek istediğini söyledi.
- **n-gram ve Jaccard:** Bir öğrenci metni küçük harfe çevirip noktalamayı atarak n-gram'lar oluşturdu; Jaccard'ın iki metnin 2-gram kümelerini yakalayamadığını söyledi (00:42:07).

### 4.3 Farklılık ölçütünün sonuca etkisi

Karakter ve kelime örtüşmesine dayanan ölçütler yüzeysel farkı ölçer. Bir öğrencinin gözlemi bunu iyi gösteriyor: SFT'den sonra cevaplardaki ortak İngilizce kalıp cümleler ("Perform calculation" gibi) yüzünden farklılık yapay olarak düştü (02:15:05). Öğrenci bu ortak kısımların bir bölümünü sildiğini, ama bütün örnekleri tek tek kontrol etmenin imkânsız olduğunu söyledi.

Bir sunumda farklılık değerleri çok dar bir aralıkta kaldı. Taban modelde cevaplar arası kosinüs benzerliğinin ortalaması 0.909'du (ekrandan, 02:40:30); yani farklılık yaklaşık 0.09'du. Grup, farklılık aralığı bu kadar dar olduğu için grafikte büyük görünen farkların aslında çok küçük olduğunu, modelleri asıl ayıranın doğruluk olduğunu söyledi (02:43:21).

## 5. SFT ve Multi-SFT Verisinin Üretilmesi

### 5.1 SFT

SFT (supervised fine-tuning, gözetimli ince ayar) için her eğitim sorusuna öğretmen modelden bir çözüm alındı ve taban model bu soru-çözüm çiftleriyle eğitildi. Sunumlarda LoRA ile parametre verimli ince ayar yapıldı; bazıları belleği korumak için 4 ya da 8 bit nicemleme (quantization) de kullandı.

Bir sunumda SFT hiperparametreleri şöyleydi (ekrandan, 01:04:00):

| Hiperparametre | Değer |
|---|---|
| Yöntem | LoRA ($r=64$, $\alpha=128$) |
| Hedef katmanlar | q, k, v, o, gate, up, down |
| Dropout | 0.1 |
| Öğrenme oranı | 5e-5 |
| Batch size | $8\times2=16$ (gradyan biriktirme) |
| Epoch | 2 |
| Warmup oranı | 0.05 |

Öğrenme oranında kosinüs zamanlayıcı kullanıldı (01:04:29).

Bazı öğrenciler öğretmen çözümlerinden yalnız **doğru** olanları tuttu; böylece model yanlış çözümlerden öğrenmedi. Bir öğrenci öğretmen olarak kullandığı modelin eğitim sorularından 686'sını doğru çözdüğünü ve yalnız bunlarla devam ettiğini söyledi (02:09:18).

Bir öğrencinin önerilen bir ayarı ilginçti (01:27:24): yapay zekâ aracı, SFT eğitiminde kaybın yalnız cevap token'ları üzerinden hesaplanmasını sağlayan bir eğitici parametresini eklemesini önerdi. Bu ayar olmadan model soruyu da öğrenmeye çalışır; amaç ise yalnız cevabı öğrenmesidir. Aynı araç bir doğrulama kümesi ve erken durdurma da ekledi; en iyi kontrol noktası seçildi (01:31:57).

### 5.2 Öğretmen stilinin ezberlenmesi

Bir öğrencinin deneyi bu dersin en öğretici sonuçlarından biriydi (01:03:34; ekrandan, 01:04:00). İlk SFT denemesinde `gpt-oss-120b`'nin sentetik çözümleri kullanıldı. Bu çözümler LaTeX biçimindeydi ve model bu stili ezberledi; testteki artış yalnız %1.7 oldu. Öğrenci slaytta bunu "mode collapse, LaTeX stil ezberi" diye adlandırdı. Ardından veri kümesinin kendi Türkçe çözümlerine geçti; test doğruluğu 0.421'den 0.581'e çıktı (+0.160). Öğrenci bunu dağılım kayması (distribution shift) sorununun çözülmesi olarak yorumladı.

Hoca bu sonucu "enteresan" buldu (01:04:15).

Bir başka öğrenci de benzer bir sorunu dil açısından yaşadı: öğretmen soruları Türkçe çözse bile modelin cevapları İngilizce çıktı. Farklılığı ölçmek için Türkçeye ince ayar yapılmış bir embedding modeli kullandığı için İngilizce cevaplarda farklılık ölçümü bozuldu; İngilizce odaklı bir model seçseydi daha iyi sonuç alabileceğini söyledi (00:06:48).

Bir grup öğretmenden çözümleri ayrı alanlar hâlinde JSON olarak istedi: açıklama ve sayısal cevap ayrı ayrı. Böylece sayıyı ayıklama sorunu baştan ortadan kalktı (02:39:30). Aynı grup bu üretimin (1500 soru) yaklaşık 1 dolara mal olduğunu belirtti.

### 5.3 Multi-SFT

Multi-SFT'de **aynı soru** için öğretmenden birden çok (3 ya da 5) farklı çözüm alınır ve model hepsiyle eğitilir. Bazı öğrenciler bu çözümlerin gerçekten farklı olması için öğretmene farklı tarzlar istedi: kısa işlemli, ayrıntılı adımlı, alternatif denklemli çözüm (01:50:10). Bir öğrenci ise aynı istemi 5 kez tekrar ederek üretti ve sonradan, "5 farklı çözüm üret" deseydi Multi-SFT'deki çeşitliliğin daha yüksek olabileceğini söyledi (03:01:38).

Bir öğrenci Multi-SFT verisini farklı alanlardan (matematik dışı) farklı sorularla oluşturmuştu. Hoca bunu düzeltti (02:19:09):

> **Hocanın vurgusu:** Multi-SFT'de aynı soru için birden fazla cevap alınır. Farklı alanlardan farklı sorular toplamak başka bir fikirdir; çeşitliliği artırabileceğini düşünmek doğru bir bakış açısı olabilir, ama ödevde istenen o değildir.

**Soru (hoca):** SFT'de kaç örnekle, Multi-SFT'de kaç örnekle eğitim yaptın? **Cevap:** SFT'de her soruya bir çözüm, Multi-SFT'de üç çözüm vardı. Hoca bunun Multi-SFT'de aslında üç kat eğitim verisi demek olduğunu vurguladı (01:50:48). O sunumda Multi-SFT doğruluğu düz SFT kadar artırmadı ama farklılığı biraz artırdı.

Kaynak sıkıntısı yaşayan bir öğrenci eğitimi yaklaşık 400 örnekle yaptı. Hoca bu kadar az örnekle anlamlı bir sonradan eğitim beklenemeyeceğini söyledi (01:38:26).

## 6. GRPO: Algoritma ve Ödül Tasarımları

### 6.1 Algoritma

Bir öğrencinin slaytında GRPO (Group Relative Policy Optimization; DeepSeekMath, Shao ve diğ. 2024) şöyle özetlendi (ekrandan, 01:07:00):

```text
1. Aynı prompt için K cevap üret
2. Her cevap için reward hesapla
3. Grup içi ortalama -> advantage (göreceli)
4. Policy update + KL penalty
```

GRPO'da ayrı bir değer (critic) modeli yoktur. Bir cevabın ne kadar iyi olduğu, aynı soruya üretilen gruptaki öteki cevaplarla karşılaştırılarak belirlenir:

$$A_k = r_k - \bar r, \qquad \bar r = \frac{1}{K}\sum_{k=1}^{K} r_k$$

> **Ek bilgi (derste anlatılmadı):** DeepSeekMath makalesindeki GRPO, avantajı ayrıca grubun standart sapmasına böler: $A_k=(r_k-\bar r)/\sigma_r$. Derste gösterilen slayt yalnız ortalamanın çıkarıldığı sade hâli verdi; her iki biçimde de bütün ödüller eşitse avantaj sıfırdır.

Sunumlarda grup büyüklüğü (`num_generations`) çoğunlukla 4 ya da 8 idi. 8 çok uzun sürdüğü için birçok öğrenci 4'e indi (00:52:53). Hoca, GRPO'nun hiçbir şey değiştirmediğini söyleyen bir öğrenciye bu sayıyı artırmanın işe yarayabileceğini önerdi (01:49:32).

### 6.2 Öğrenme sinyalinin kaybolması

Aynı öğrenci GRPO'nun tabana doğrudan uygulandığında neden az katkı verdiğini iki senaryoyla açıkladı (ekrandan, 01:07:00):

- Taban model %42.1 doğru; bir grupta 8 cevaptan ortalama 3.4'ü doğru ($8\times0.421\approx3.37$).
- **Senaryo A:** 8 cevabın hepsi doğru → grup ortalaması 1.0 → her cevap için avantaj $1.0-1.0=0$ → öğrenme sinyali sıfır.
- **Senaryo B:** 8 cevabın hepsi yanlış → grup ortalaması 0.0 → avantaj $0.0-0.0=0$ → öğrenme sinyali sıfır.
- Önerilen çözüm: warm-start RL, yani önce SFT, sonra GRPO.

Bu sunumda GRPO tabana göre yalnız +0.032 getirdi (test doğruluğu 0.453).

Hoca bu açıklamanın yarım kaldığını söyledi (01:07:16 - 01:09:22):

> **Hocanın vurgusu:** Senaryo A ve B'yi yazdıysan, bu senaryoların oluşma olasılığının ne olduğunu da hesaplayıp "bu yüzden buradan doğru düzgün öğrenemiyor" diye bağlaman gerekir. Başını verip sonunu vermezsen bunu yazmanın bir anlamı kalmaz.

Öğrenci ayrıca "advantage parametresi de kullandım" deyince hoca, avantajın GRPO'nun kendisinin bir parçası olduğunu, kullanmamanın söz konusu olmadığını hatırlattı (01:08:09). Bu olasılığın kaba bir hesabı Örnek Sorular bölümündedir.

### 6.3 Ödül tasarımları

Ödüller bütün sunumlarda kural tabanlıydı. Ekranda görülen tasarımlar:

| Sunum | Doğruluk ödülü | Format ödülü | Diğer |
|---|---|---|---|
| (ekrandan, 00:53:25) | doğru 1.0, yanlış 0.0 | `</cozum>` ve `Cevap:` şablonu 0.5 | — |
| (ekrandan, 01:07:00) | doğru +1.0, yanlış 0.0 | "Buna göre, doğru cevap N" +0.2 | — |
| (ekrandan, 01:30:00) | doğru +2.0, yanlış −1.0 | `Final: <sayı>` varsa +0.2, yoksa −0.2 | 8 < kelime < 90 ise +0.1; kelime > 140 ise −0.2 |
| (ekrandan, 01:40:10) | tam eşleşme 1.0; yakınlığa göre 0.5'e kadar kısmi | `#### <sayı>` varsa 0.3 | — |
| (ekrandan, 02:35:17) | doğruysa 2.0, değilse 0.0 | `####` varsa 0.5 | — |

İkinci satırdaki öğrenci, doğruluk ve format ödülleriyle bir cevabın en çok 1.2 puan alabildiğini söyledi (01:07:41). Bir başkası ilk denemede yalnız doğruluk (0.8) ve biçim (0.2) kullandı; model çok kısa cevaplar üretip adım atladığı için yanlış yapınca bir uzunluk ödülü ekledi ve sonuç biraz iyileşti (02:56:48).

Sorulan ödüllerden birinde hoca format ödülünün doğruluktan bağımsız olup olmadığını sordu. **Soru:** Cevap doğru değilse ama format doğruysa yine formattan 0.5 puan alıyor mu? **Cevap:** Evet, iki ödül ayrı fonksiyonlardır (02:35:26 - 02:35:38).

### 6.4 Ödül sömürüsü

Bir öğrencinin GRPO deneyi bu bağımsızlığın sonucunu gösterdi (01:40:37; ekrandan, 01:40:10). Format çoğunlukla tutturulunca model bir süre sonra mantık yürütmeyi ve doğruluğu bırakıp puanı formattan almaya yöneldi. Öğrencinin slaytındaki ifade: formata ödül vermek, modelin mantık yürütmekten çok formatı doğru vermesine odaklanmasını sağlamış olabilir (kısa yoldan ödül kazanma problemi). SFT ile %22-23'e çıkan doğruluk SFT+GRPO'da geriledi. Öğrenci ayrıca KL katsayısını (beta) güncellemenin çok hızlı olacağı biçimde seçtiğini, modelin SFT'de öğrendiğini kaçırdığını düşündü (01:40:51).

> **Ek bilgi (derste anlatılmadı):** Bu olgu literatürde "reward hacking" diye bilinir: politika, ödül fonksiyonunun amaçlanan davranışı değil, ölçülen yüzeysel özelliği en büyükleyen bir yol bulur. Format ödülünü yalnız cevap doğruyken vermek ya da format ödülünü doğruluk ödülüne göre çok küçük tutmak yaygın önlemlerdir.

### 6.5 Hiperparametreler

Bir öğrenci SFT+GRPO'nun ilk sürümüyle %20 hedefine ulaşamayınca ikinci bir sürümde adım sayısını artırdı, öğrenme oranını değiştirdi ve beta'yı düşürdü, yani KL kısıtını gevşetti; böylece model SFT'den daha uzaklaşabildi ve test doğruluğu tabanın 20 puan üzerine çıktı (01:10:18).

Thinking (düşünme) modunu açık kullanan bir öğrenci, düşünen modellerin döngüye girebildiğini, bunu önlemek için tekrar cezasını (repetition penalty) 1.1, sıcaklığı 0.7 verdiğini anlattı. En fazla 1536 yeni token'a izin verdi; düşünme çok token harcadığı için birçok cevap bu sınıra takıldı ve taban doğruluğu düşük çıktı (02:32:24 - 02:33:20). Başka bir öğrenci de GRPO'daki 256 token sınırının final cevabı kestiğini görüp 384'e çıkardı (01:53:43).

## 7. Sonuçlar ve Ortak Bulgular

### 7.1 Bir sunumun tam tablosu

Bir öğrencinin test sonuçları (ekrandan, 02:57:25; 500 soru):

| Model | binary | soft | farklılık | base'e göre |
|---|---|---|---|---|
| base | %42.4 | %61.2 | 0.139 | — |
| grpo | %51.7 | %68.1 | 0.116 | +%9.3 |
| sft | %58.2 | %71.1 | 0.099 | +%15.8 |
| multisft | %59.0 | %71.9 | 0.096 | +%16.6 |
| sft_grpo | %59.9 | %72.9 | 0.096 | +%17.5 |
| multisft_grpo | %61.0 | %74.2 | 0.094 | +%18.6 |

"Base'e göre" sütunu yüzde puan farkıdır (ör. $58.2-42.4=15.8$; python ile doğrulandı). Öğrencinin slayttaki iki çıkarımı: doğruluk arttıkça farklılık sistematik olarak azalıyor; en doğru model (Multi-SFT+GRPO) aynı zamanda en az çeşitli olan.

Öğrencinin yorumu (02:58:44 - 02:59:45): asıl kazancı SFT sağladı (+15.8). GRPO tabana +9.3 getirdi, ama SFT'nin üstüne yalnız +1.7, Multi-SFT'nin üstüne +2.0 ekledi. Model ne kadar temel ise GRPO o kadar çok iyileştirme yapıyor; eğitilmiş bir modeli çok az geliştiriyor.

### 7.2 Aşırı uyum

Aynı öğrencinin eğitim-test karşılaştırması (ekrandan, 03:00:00):

| Model | train | test | fark |
|---|---|---|---|
| grpo | %51.5 | %51.7 | −0.2 |
| sft | %67.9 | %58.2 | %9.7 |
| multisft | %70.5 | %59.0 | %11.5 |
| sft_grpo | %69.8 | %59.9 | %9.9 |
| multisft_grpo | %72.8 | %61.0 | %11.8 |

Yalnız GRPO'da eğitim ile test neredeyse aynıdır: model ezberlemeden genelliyor ama tavanı düşük. SFT ailesinde %10-12'lik bir fark var: doğru çözüm tarzını öğrenirken eğitim kümesine bir miktar uyuyor. Öğrenci GRPO'nun SFT üzerine eklenince bu farkı çok az artırırken test doğruluğunu yükselttiğini söyledi.

Başka sunumlarda da eğitim-test farkının küçük olması aşırı uyum ya da ödül sömürüsü olmadığına kanıt olarak gösterildi (00:44:20, 01:14:04). Tersine, bir öğrencinin ikinci düzeninde eğitim doğruluğu artarken test doğruluğu düştü; hoca "burada bir overfit mevzusu var" dedi (01:31:55).

### 7.3 Doğruluk-farklılık korelasyonu

Bir öğrenci yedi modelin (Base, SFT, Multi-SFT, GRPO, iki SFT+GRPO sürümü, Multi-SFT+GRPO) test ortalamalarını aynı düzleme koydu (ekrandan, 01:12:55). X ekseni anlamsal farklılık (0.02-0.05 arası), Y ekseni test doğruluğu (0.42-0.63 arası). Noktalar neredeyse tek bir doğru üzerindeydi: doğrusal regresyon $y=-9.32x+0.84$, Pearson $r=-0.994$. Öğrenci bunu "doğruluk artıyor ama anlamsal fark hızla düşüyor" diye yorumladı. İstenen durum ikisinin birlikte artmasıydı.

> **Ders sonrası not:** Aynı slaytta grafik başlığı $r=-0.98$, kutu içindeki değer $r=-0.994$ yazıyordu; iki değer birbirini tutmuyor. Ayrıca yalnız 7 noktalık bir korelasyon, nedensel bir ilişkiden çok bu deneylerdeki eğilimi gösterir.

Bu öğrencinin yorumu: SFT öğretmeni taklit ettiği için farklılık sıfıra yaklaştı; GRPO'daki ödülde farklılığı ödüllendiren bir terim olmadığı için GRPO da bunu kıramadı. Çözüm önerisi, GRPO ödülüne cevap çiftleri ne kadar farklıysa o kadar puan veren bir çarpan eklemekti; ancak bunun doğruluğu düşürebileceğini de ekledi (01:06:24, 01:11:08). Aynı öneriyi başka öğrenciler de yaptı (03:01:56).

### 7.4 Taban modelin konumu

Sunumlarda taban modelin yeri farklı çıktı ve bu, farklılık ölçütüne bağlıydı. Bir sunumda taban model yüksek farklılık (yaklaşık 0.75) ve orta doğrulukta (0.62) duruyordu; SFT ve Multi-SFT ortada, GRPO'lu modeller sol üstteydi: doğruluk arttı, farklılık düştü (ekrandan, 00:45:00). Öğrenci "her nokta bir cevap çiftini temsil ediyor" diyerek grafiği anlattı (00:44:37).

Bir başka sunumda ise model arttıkça doğruluk düştü ve en iyi sonucu taban model verdi (02:03:44). O öğrenci veri ve eğitimi on kat küçültmüştü (100 eğitim, 50 test) ve öğretmen olarak taban modelin kendisini kullanmıştı.

**Soru (hoca):** SFT ve Multi-SFT çözümlerini de taban modelden mi ürettin? **Cevap:** Evet (02:02:31).

### 7.5 Zorluk düzeylerine göre analiz

Bir öğrenci test sorularını taban modelin başarısına göre ayırdı (00:10:01): taban modelin %40'tan az başardığı zor sorular (yaklaşık %30), %40-%79 arası orta sorular (yaklaşık %20), %80 ve üstü kolay sorular (yaklaşık %50). Başarı, 10 cevaptan oluşan çiftlerin ortalama doğruluğu üzerinden hesaplandı.

**Soru (hoca):** Başarının %40 ile %79 arasında kalması ne demek? **Cevap:** Bir soru için 10 cevap alınıyor; ikili kombinasyonların ortalama başarısına göre soru zor, orta ya da kolay sayılıyor (00:14:06 - 00:15:17).

Eğitimler zor sorularda belirgin artış verdi; orta ve kolay sorularda başarı düştü. Öğrenci bunu kolay sorulardaki aşırı uyum ya da halüsinasyona bağladı. Hoca iki öneri yaptı (00:18:21, 00:19:49): bütün soruları gösteren dağınık grafik yerine yalnız zor soruların grafiği çizilmeli; zorluk tablosu yalnız doğruluk için değil farklılık için de çıkarılmalı.

## 8. Grafiklerin Kurulması ve Okunması

### 8.1 Her nokta neyi temsil etmeli?

Hoca birçok sunumda "buradaki bir yuvarlak neyi temsil ediyor?" diye sordu. Ödevde her noktanın **bir cevap çifti** olması isteniyordu. Bir grup her soru için 45 çiftin ortalamasını alıp 500 nokta çizmişti (02:44:18 - 02:45:26):

> **Hocanın vurgusu:** İstediğim bu değildi. Cevap ikililerine bakmanızı istiyorum. Bir yuvarlak bir cevap çiftini temsil etmeli.

Başka bir öğrencinin grafiğinde de her nokta bir sorunun bütün cevap çiftlerinin ortalamasıydı; o öğrenci ikinci bir grafikte beş sorunun cevap çiftlerini ayrıca gösterdi (02:57:55 - 02:58:15).

Soru başına ortalama alındığında Y değeri 0, 0.5, 1 dışında da değer alır. Bir sunumda Y ekseni 0.1 adımlarla ilerliyordu (ekrandan, 02:45:00); bu, noktaların çift değil soru ortalaması olduğunu ele verir.

### 8.2 Çift grafiklerinin örnekleri

Bir sunumda tek bir zor soru için altı modelin çift grafiği yan yana konmuştu (ekrandan, 00:16:20). Soru: "John bir kutu inşa eder. Kutu 26 inç × 26 inç × 14 inç boyutlarındadır. Duvarlar her iki tarafta 1 inç kalınlığındadır..." Grafiklerdeki özetler:

| Model | Ort. doğruluk | Ort. farklılık |
|---|---|---|
| Base | 0.10 | 0.87 |
| SFT | 0.70 | 0.76 |
| Multi-SFT | 0.90 | 0.77 |
| GRPO | 0.70 | 0.85 |
| SFT + GRPO | 0.90 | 0.90 |
| Multi-SFT + GRPO | 0.90 | 0.70 |

Burada taban modelde ikisi de doğru olan bir çift yokken, SFT ile birlikte üstte yeşil noktalar oluşmaya başladı. Öğrenci bu soruyu özellikle seçtiğini, kolay sorularda çoğu zaman tersinin olduğunu açıkça söyledi (00:16:52 - 00:17:20).

Aynı sunumdaki başka bir soruda (ekrandan, 00:15:00) taban modelin ortalama doğruluğu 0.10, farklılığı 0.79; Multi-SFT'de doğruluk 0.80, farklılık 0.50 idi: doğruluk arttı, farklılık düştü.

### 8.3 Sunumlarda görülen grafik hataları

- Bir grubun tablosunda GRPO doğruluğu 56 civarındayken grafikte 50'nin altında görünüyordu; hoca sorunca grup grafiğe yanlış değer koyduğunu fark etti (02:42:15 - 02:43:10).
- Bir öğrencinin tablosunda bir farklılık değeri 0.999 yazılmıştı; doğrusu 0.099 idi. Öğrenci bunu sonradan fark ettiğini söyledi (02:07:08).
- Bir grafikte açıklama kutusu taban modelin noktalarını kapatıyordu; hoca konumunun kötü olduğunu söyledi (00:58:01).
- Bir sunumda parametre sayısı "3000" yazılmıştı. **Hoca:** "3 bin parametre ile bunları başarabilseler mükemmel olurdu" (02:04:17). Doğrusu 3 milyardı.
- Yapay zekâya hazırlatılan bir slaytta taban modelin değerleri hiç farklı değildi; öğrenci bunu fark etmemişti (03:09:23).

### 8.4 t-SNE ile cevapların dağılımı

Bir grup bütün cevapların embedding'lerini t-SNE ile iki boyuta indirip doğru/yanlış diye renklendirdi (ekrandan, 01:00:00). Her nokta bir cevaptı (soru dahil değil). Hoca GRPO grafiğinde daha çok nokta var gibi göründüğünü söyledi. **Soru:** GRPO'da daha mı çok nokta var, yoksa ötekilerde noktalar üst üste mi binmiş? **Cevap:** Öğrenci, aynı konuma farklı soruların cevaplarının da düşmüş olabileceğini, hocanın haklı olabileceğini söyledi (01:00:11 - 01:00:38).

### 8.5 Sayıları oransal vermek

Bir öğrenci "10 cevaptan 10'u doğru" olan soru sayısını mutlak sayı olarak verdi: tabanda 181, SFT'de 284 (01:48:19). Hoca bu sayıların oran olarak verilmesi gerektiğini söyledi (01:47:15):

> **Hocanın vurgusu:** Mutlak sayılarla yazınca oranlar sanki farklıymış gibi görünüyor; oransal yazsan daha iyi olur.

## 9. Nitel Örnek: Hiçbir Modelin Çözemediği Soru

Bir öğrenci altı modelin hiçbirinin çözemediği bir soruyu inceledi (ekrandan, 01:51:55). Soru özeti: Bir kasada 42 elma var. Fabrikaya 12 kasa geldi. 4 elma çürük çıktı. Kalan elmalar her kutuya 10 elma gelecek şekilde paketlendi. Kaç kutu gerekir? Referans cevap: 50.

| Model | 10 cevaptan doğru | Örnek final cevap |
|---|---|---|
| Base | 0 | 2 |
| SFT | 0 | 3 |
| GRPO | 0 | 15 |
| SFT+GRPO | 0 | 2 |
| multiSFT | 0 | 37 |
| multiSFT+GRPO | 0 | 37 |

SFT modelinin çözümü: toplam elma 42; çürük elma atıldı: $42-4=38$; kalan elmalar 10'lu kutulara bölünür: $38/10 = 3$ kutu. Öğrencinin yorumu: modeller "kasa" ile "elma" arasındaki ilişkiyi kuramadı; önce toplam elmayı ($12\times42$) bulma adımını atladı. Öğrenci bunu küçük bir modelin bağlamsal ve anlamsal ilişki kurmadaki zayıflığına bağladı (01:52:06 - 01:52:32).

Hoca böyle bir örnek koymayı beğendi ve bir tamamlayıcı önerdi (01:52:40 - 01:53:03):

> **Hocanın vurgusu:** Hiçbir modelin yapamadığı soru güzel bir örnek. Yanına tabanın çözemediği ama SFT'nin çözebildiği bir örnek de koymalısın; yapılan eğitimin işe yaradığını gösteren bir örnek.

## 10. Hocanın Yöntem Uyarıları ve Yapay Zekâ Kullanımı

### 10.1 Yöntemi bilmek

Hoca birçok sunumda bir sayının nasıl hesaplandığını sordu. "Kodda hesaplattım" cevabını yeterli bulmadı (00:36:49): farklılığın nasıl ölçüldüğü sorulduğunda ölçütün kendisi (ör. hangi embedding, hangi uzaklık) söylenmelidir. Bir sunumda öğrenci 138 sorunun "eksik" çıktığını ve eşleşene kadar kodu tekrar tekrar çalıştırdığını anlattı; hoca bunun ne demek olduğunu anlayamadığını, "missing data"nın ne anlama geldiğinin açıklanması gerektiğini söyledi (00:22:26 - 00:28:45). Bir başka sunumda öğrenci ödül listesindeki bir terimin ne demek olduğunu bilmiyordu; listeyi yapay zekâya çıkarttığını söyledi (01:28:22 - 01:29:24).

Bir öğrenci test verisini her model için ayrı dosyalara bölmüştü. **Soru (hoca):** Test soruları herkes için aynı değil mi; neden ayrı ayrı yazıyorsun? **Cevap:** Öğrenci her modele farklı sistem istemi verdiğini, ama testteki bütün sorular matematik olduğu için bu ayrımın gereksiz olduğunu kabul etti (02:27:21 - 02:28:39).

### 10.2 Yapay zekâ kullanımı

Ödevde öğrencinin kendi çözümü ile bir yapay zekâ aracına yaptırılan çözümün karşılaştırılması isteniyordu. Sunumların çoğunda bu karşılaştırma eksikti; bazı öğrenciler kodun tamamını ya da büyük kısmını yapay zekâya yazdırdığını söyledi. Hoca "istediğim bu değildi" dedi (00:46:13).

Yapay zekâ ile iyileştirme örnekleri de vardı: bir öğrencinin aracı öğretmen istemine "ara çözümleri atlama" gibi cümleler ekledi, üç öğretmen çözümü arasından cevabın metin içinde ara adımlarda da tutarlı geçtiği çözümü seçen bir kontrol yazdı, SFT'de yalnız cevabın öğrenilmesi için bir parametre ve doğrulama kümesi ekledi (01:26:07 - 01:27:51). Bir başka öğrencide ise yapay zekânın yazdığı ince ayar istemleri cevaplara İngilizce kalıplar soktu ve doğruluğu düşürdü (02:12:41 - 02:14:07).

Dersin sonunda bir öğrencinin, konuları anladığı hâlde ödevlere nasıl başlayacağını bilemediğini söylemesi üzerine hoca genel bir uyarı yaptı (03:10:31 - 03:12:43):

> **Hocanın vurgusu:** Yapay zekâyı çok fazla kullandıkça çözüm bulma, çözüm üretme ve düşünme kabiliyeti yavaş yavaş körelir. Yapay zekânın hızı çok çekicidir, ama onunla yapılan işin kişiye ne kattığı belirsizdir. Herkes yapay zekâya yaptırabildiğine göre fark yaratmak için başka bir şey yapabilmek gerekir. Hatayı çözmek için de yine yapay zekâya gidince hiç problem çözülmemiş olur. "Yapay zekâ diyeti" yapmak gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Bir voleybol maçı için satılacak yüz bilet vardır. Andrea, Jude'un iki katı kadar bilet satarken Sandra, Jude'un sattığı bilet sayısının yarısından 4 fazla bilet satmıştır. Jude 16 bilet sattıysa, kaç bilet satılması gerekir?

> **Çözüm (derste verilmedi):** Ekranda referans cevap 40 olarak görünüyordu; adımlar derste anlatılmadı. Andrea $2\times16=32$, Sandra $16/2+4=12$ bilet sattı. Satılan toplam $16+32+12=60$. Satılması gereken $100-60=40$ bilet (python ile doğrulandı).

**Soru 2** (ekrandan, 01:51:55): Bir kasada 42 elma var. Fabrikaya 12 kasa geldi. 4 elma çürük çıktı. Kalan elmalar her kutuya 10 elma gelecek şekilde paketlendi. Kaç kutu gerekir?

> **Çözüm (derste verilmedi):** Ekranda referans cevap 50 olarak görünüyordu; doğru çözümün adımları derste yazılmadı. Toplam elma $12\times42=504$. Çürükler atılınca $504-4=500$. Kutu sayısı $500/10=50$ (python ile doğrulandı). Modellerin hatası ilk adımı atlayıp $42-4=38$ ile devam etmesiydi (bkz. Bölüm 9).

**Soru 3** (derste sözlü, 00:57:23): Bir soru için 10 cevap üretiliyor ve 500 test sorusu var. Grafikte kaç cevap çifti noktası olur?

- Derste verilen cevap: Bir soru için $\binom{10}{2}=45$ çift; 500 soru için $500\times45=22.500$ çift.

**Soru 4** (derste sözlü, 01:08:40): GRPO'da 8 cevaplık bir grubun tamamen doğru (Senaryo A) ya da tamamen yanlış (Senaryo B) olma olasılığı nedir? Taban modelin doğruluğu 0.421'dir (ekrandan, 01:07:00).

> **Çözüm (derste verilmedi):** Her cevabın birbirinden bağımsız ve her soruda aynı $p=0.421$ olasılıkla doğru olduğu varsayılırsa: $P(A)=0.421^8\approx0.00099$, $P(B)=0.579^8\approx0.0126$; toplam $\approx0.0136$, yani grupların yaklaşık %1.4'ü (python ile doğrulandı). Gerçekte soruların zorluğu farklıdır: kolay sorularda $p$ 1'e, zor sorularda 0'a yakındır. Bu yüzden sinyalsiz grupların oranı bu varsayımla bulunandan büyük olasılıkla çok daha yüksektir; asıl değer her soru için 8 cevabın doğruluk sayısı sayılarak ölçülmelidir.

**Soru 5** (derste sözlü, 01:50:48): Bir soruya SFT'de bir, Multi-SFT'de üç öğretmen çözümü veriliyorsa, Multi-SFT'nin eğitim verisi SFT'ye göre ne kadar büyüktür ve karşılaştırmada bu neden önemlidir?

- Derste verilen cevap: Multi-SFT'de 3 kat eğitim örneği vardır. Multi-SFT'nin sonucu yorumlanırken bu fark hesaba katılmalıdır; daha iyi sonuç yalnız çözüm çeşitliliğinden değil, daha çok veriden de gelebilir.

**Soru 6** (derste sözlü, 02:35:32): GRPO'da doğruluk ödülü doğruysa 2.0, format ödülü `####` varsa 0.5 ve ikisi bağımsızsa, yanlış ama doğru formatta bir cevap kaç puan alır?

- Derste verilen cevap: 0.5 puan; cevap yanlış olsa da formattan puan alır (ekrandan, 02:35:17).

## Dersin Toparlaması

Bu derste üçüncü ödevin sunumları yapıldı. Ödev, bir dil modelinin SFT, Multi-SFT ve GRPO ile sonradan eğitilmesinin aynı soruya verdiği cevapların doğruluğunu ve birbirinden farklılığını nasıl değiştirdiğini ölçüyordu. Sunumların ortak sonucu, doğruluk ile farklılığın çoğu zaman ters yönde hareket ettiğiydi. SFT doğruluğu en çok artıran adımdı, ama model öğretmenin stilini taklit edip benzer cevaplar üretmeye başladı. GRPO tabana doğrudan uygulandığında sınırlı, SFT'nin üstüne eklendiğinde çok küçük bir katkı verdi. Bunun nedenleri olarak gruptaki cevapların hepsi doğru ya da hepsi yanlış olduğunda öğrenme sinyalinin kaybolması, küçük grup büyüklüğü ve doğruluktan bağımsız format ödüllerinin sömürülmesi tartışıldı. Birçok öğrenci çeşitliliği korumak için ödüle bir farklılık terimi eklemeyi önerdi.

Hocanın müdahaleleri yöntemle ilgiliydi: her nokta bir cevap çifti olmalı, her ölçütün nasıl hesaplandığı bilinmeli, Multi-SFT aynı soruya birden çok çözüm demektir, sayılar oranla verilmeli ve analiz eğitimin etkisinin görüldüğü zor sorularda yapılmalıdır. Hoca dersi, yapay zekâya fazla yaslanmanın problem çözme becerisini zayıflattığı uyarısıyla kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
