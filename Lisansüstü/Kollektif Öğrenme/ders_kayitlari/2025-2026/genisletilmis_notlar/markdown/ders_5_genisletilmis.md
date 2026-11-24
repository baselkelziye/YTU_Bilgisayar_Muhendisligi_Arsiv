# Ders 5 Genişletilmiş Notu: Ödev Sunumları: GRPO ile Ödül Fonksiyonu Tasarımı ve Model Birleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödevin Çerçevesi ve Ortak Kurulum
- 2. Veri Alt Kümesinin Seçimi
- 3. Prompt ve Çıktı Formatı
- 4. Ödül Fonksiyonu Tasarımları
- 5. Ödül Hilesi ve Modelin Davranışı
- 6. GRPO'nun Ayarları: Cevap Sayısı, KL Katsayısı, SFT
- 7. Model Birleştirme
- 8. Değerlendirme ve Ölçüm Hataları
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödevin Çerçevesi ve Ortak Kurulum

Bu ders bütünüyle ödev sunumlarına ayrıldı. Konu anlatımı yapılmadı; öğrenciler tek başına ya da iki kişilik gruplar halinde çalışmalarını yaklaşık beşer-altışar dakikada sundu, hoca da her sunumdan sonra sorular sorup teknik yorumlar yaptı. Bu notta sunumların ortak teknik içeriği ve hocanın yorumları konu konu toplanmıştır; sunanların kimliği yer almaz.

Hoca derse ödevi kısaca hatırlatarak başladı. Standart GRPO (Group Relative Policy Optimization) kurulumunda ödül fonksiyonu doğruluk ve format bileşenlerinden oluşur. Ödevde bunun yanına dört yeni ödül bileşeni tasarlanacak, böylece farklı ödül fonksiyonlarına sahip beş model eğitilecekti. Eğitilecek model, kullanılacak veri kümesi ve eğitim/test büyüklükleri önceden verilmişti. Son adımda iyi çıkan modeller birleştirilerek (merge) bir model daha denenecekti. Topluluk öğrenmesi açısından ödevin fikri şudur: farklı ödüllerle farklı davranışlar kazanmış modeller birleşince her birinin iyi yanını taşıyan bir model elde edilebilir mi?

Sunumlarda görülen ortak kurulum şöyledir:

- **Temel model:** `ytu-ce-cosmos/turkish-gpt2-large-750m-instruct-v0.1`. Türkçe talimat takibi için hazırlanmış, GPT-2 mimarili, 750 milyon parametreli bir dil modelidir (ekrandan, 00:10:00).
- **Veri seti:** `alibayram/turkish_mmlu`. Türkçe çoktan seçmeli sınav sorularından oluşan geniş bir akademik soru kümesidir (ekrandan, 00:45:00).
- **Bölme:** 1000 eğitim ve 500 test sorusu.
- **Eğitim:** Bütün ağırlıkları güncellemek yerine LoRA (Low-Rank Adaptation) ile parametre verimli ince ayar. Bir raporda ana ağırlıkların dondurulduğu, yalnız $r=16$ ranklı adaptör katmanlarının eğitildiği yazıyordu. Böylece GRPO'nun yüksek bellek ihtiyacı GPU belleği sınırında karşılanmış ve modelin var olan Türkçe bilgisi korunmuştu (ekrandan, 00:10:00).

> **Ek bilgi (derste anlatılmadı):** GRPO'da her soru için modelden bir grup cevap örneklenir ve her cevap ödül fonksiyonlarıyla puanlanır. Bir cevabın avantajı, ödülünün grubun ortalamasından ne kadar yukarıda ya da aşağıda olduğuna göre hesaplanır; ayrı bir değer (critic) ağı gerekmez. Model, grup ortalamasının üstünde kalan cevapların olasılığını artıracak biçimde güncellenir.

## 2. Veri Alt Kümesinin Seçimi

Ödevin bir koşulu, veri kümesinden bilgi ağırlıklı değil çıkarım ağırlıklı bir alt küme seçmekti. Grupların kullandığı yollar şunlardı:

- **Konu/bölüm sütununa göre seçim:** Matematik, mantık, fizik, istatistik, Türkçe paragraf, sözel ve sayısal mantık gibi konular seçildi.
- **Anahtar kelime filtresi:** Soru metninde "çünkü", "dolayısıyla", "oranı", "ortalaması", "en az", "en çok" gibi ifadeler arandı. Bir grup tersine "kaçtır", "eşittir" gibi işlem gerektiren soruları çıkarıp yalnız paragraf ve çıkarım sorularını aldı.
- **Puanlama:** Bir öğrenci her soruya puan verdi: mantıksal bağlaç eşleşmesi başına $+2$, matematiksel ifade başına $+1.5$, her 100 karakter için $+1$ (en fazla $+3$), ezber göstergesi olan her ifade için $-3$. Bir eşik değerini 3'ten 7'ye kadar artırarak alt kümeyi yaklaşık 1900 soruya indirdi.
- **Uzunluk ve görsel kontrolü:** Bilgi soruları genelde kısa olduğu için uzunluk filtresi kullanıldı; resim içeren sorular çıkarıldı.
- **Dengeli şık dağılımı:** Bazı gruplar eğitim ve test kümelerini doğru şıkların dağılımı korunacak biçimde (tabakalı, stratified) böldü. Amaç, bir şıkkın baskın olup modelin o şıkka yönelerek kolay puan almasını önlemekti. Bir rapordaki veri temizleme adımlarında cevap alanı A-E harfine çevrilmiş; geçersiz cevaplı, eksik seçenekli ve prompt üretilemeyen örnekler çıkarılmıştı (ekrandan, 02:00:00).

Bir öğrenci veri setinde konu etiketiyle soru içeriğinin uyuşmadığı örnekler bulduğunu, örneğin bir dil dersi başlığı altında vergiyle ilgili soru olduğunu anlattı; hoca böyle bir problemin olduğunu doğruladı. Bu yüzden öğrenci konu filtresini bırakıp soru içeriğine göre puanlamaya geçmişti.

Bir grup, geometri sorularını da almıştı. Hoca bu soruların görsel içerip içermediğini sordu; öğrenci çoğunun sözel olduğunu, görselli olanların da bulunduğunu söyledi.

> **Hocanın vurgusu:** Modelin bilgisi zaten çok sınırlıdır. Ona bilgi tabanlı şeyler sormak makul değildir; GRPO modelin bilmediği bir şeyi keşfettiremez. Soruların filtrelenmesinin istenmesinin sebebi budur.

## 3. Prompt ve Çıktı Formatı

### 3.1 Talimat mı, örnek mi?

Birçok grup, düşünce ve cevap etiketleri isteyen uzun talimatlarla başladı. Küçük temel model bu talimatları çoğu zaman izleyemedi: etiketleri tekrar etti, formatı kopyaladı, cevaptan sonra yeni sorular üretmeye devam etti. Bir öğrenci talimatları bırakıp promptun başına çözülmüş bir örnek soru koydu ve asıl soruyu açık bir düşünce etiketiyle bıraktı (ekrandan, 01:10:00):

```text
Soru: Türkiye'nin başkenti neresidir?
Seçenekler:
A) İstanbul
B) Ankara
C) İzmir
D) Bursa
E) Adana

Analiz:
<düşünce>
Soru başkenti soruyor. İstanbul en büyük şehir olsa da başkent değildir. Doğru cevap Ankara'dır.
</düşünce>
Cevap:
<cevap>B</cevap>

###

Soru: {soru}
Seçenekler:
{seçenekler}
Analiz:
<düşünce>        (model buradan itibaren yazmaya başlar)
```

Hoca burada tek örnek yerine birkaç örnek verilmesini önerdi. Soru, düşünce ve cevap kalıbı cevabın sonuna kadar gidip ardından yeni bir soruyla birkaç kez tekrar edilirse model yapıyı, yani kalıbı olduğu gibi görebilir.

Bir başka grup, prompta örnek soru koymanın cevapları biraz iyileştirdiğini ama soruyu ve promptu tekrar etme davranışının sürdüğünü gözlemledi.

### 3.2 Önce gerekçe, sonra cevap

Birkaç grup modelden önce cevabı (ya da şık numarasını), sonra gerekçeyi istedi. Hoca bunun ters olduğunu söyledi:

> **Hocanın vurgusu:** Önce düşünmeden nasıl cevap verilir? O zaman cevap uydurulur, gerekçe de cevaba göre üretilir. Model bir sonraki token'ı tahmin ederek (next token prediction) eğitilmiştir. Sorudan hemen sonra doğru şıkkı tahmin etmenin olasılığı çok düşüktür. Onun yerine "şu şöyledir, bu böyledir, dolayısıyla doğru cevap şudur" biçiminde ilerlemek, böyle eğitilmiş bir model için çok daha kolay bir davranıştır.

Sunumların sonuna doğru başka gruplar da kendi promptlarında aynı hatayı yaptıklarını fark ettiklerini söyledi.

### 3.3 Format neden istenir?

Hoca, format istenmesinin bir sebebinin kullanıcıya düzgün çıktı vermenin ötesinde doğruluğu çok basit bir kuralla ölçebilmek olduğunu belirtti. Çıktı belli bir kalıpta (örneğin "Cevap: X" ya da `<cevap>X</cevap>`) olursa doğru şık regex ile çekilip gerçek cevapla karşılaştırılabilir.

## 4. Ödül Fonksiyonu Tasarımları

Sunumlarda çok çeşitli ödül bileşenleri görüldü. Aşağıda ortak türler, ekranda okunabilen örnek puanlarla birlikte verilmiştir.

### 4.1 Format ve doğruluk

Bütün gruplar temel ödül olarak doğruluk ve formatı kullandı. Bir raporda doğruluk ödülü doğru cevaba $+2.0$, yanlış cevaba $-1.0$ veriyor; cevap etiketi hiç yoksa $-0.5$ ceza uyguluyordu. Format dışı üretimlere uygulanan $-0.5$ cezanın, modelin önce iletişim kalıbını öğrenmesini zorunlu kıldığı yazıyordu (ekrandan, 00:05:00).

Başka bir raporda senaryolar şöyle tanımlanmıştı (ekrandan, 00:15:00):

- **Yalnız format:** format doğruysa $+1.0$, "Cevap: X" ifadesi yoksa $-1.0$. Cevabın doğru ya da yanlış olması fark etmez.
- **Doğruluk ağırlıklı:** $R = 2.0 \cdot Acc + 0.2 \cdot Fmt$; hem yanlış hem formatsız ise $-0.5$. Amaç doğru cevabı formatın çok önünde tutmaktır.

Bir öğrenci hiçbir ödülde negatif puan vermediğini, negatif puanla modelin çöktüğünü anlattı. Bu öğrenci iki ayrıştırıcı kullandı: "cevap A", "doğru şık B", "yanıt C" gibi biçimleri ve metnin sonunda tek başına duran harfi de kabul eden gevşek bir ayrıştırıcı, yalnız net formatı kabul eden katı bir ayrıştırıcı.

### 4.2 Cevap temizliği ve tek şık

Bir grup, cevap etiketinin içinde yalnız tek bir harf (A-E) bulunmasını ödüllendirdi. Hoca bunun format kontrolünden farkını sordu: format zaten düşünce ve cevap etiketlerinin varlığına bakıyordu, cevap temizliği ise etiketin içinin gürültüsüz olmasına bakıyordu. Hoca format ile çok benzer şeyler ölçen bileşenlerin ayrı birer davranış eklemediğine dikkat çekti. Başka bir grup "birden fazla şık yazma" durumunu cezalandırdı; çünkü model "ABCDE" yazarak doğruluk kontrolünü atlatabilirdi. Bir grubun "tek seçim" ödülünün gerekçesi de regex'in ilk gördüğü sayıyı cevap olarak almasıydı.

### 4.3 Uzunluk ve kısalık

Uzunluk ödülleri iki yönde tasarlandı. Bazı gruplar düşünce kısmının uzun olmasını (örneğin 200 ya da 400 karakterin üstü) ödüllendirdi; bazıları kısa ve öz cevabı ödüllendirdi. Ekranda okunan bir kısa cevap ödülü şöyleydi (ekrandan, 01:20:00):

- Açıklama 7 ile 30 kelime arasındaysa $+1.0$.
- 7 kelimeden az: her eksik kelime için $-0.2$ (örneğin 4 kelime $= -0.6$).
- 30 kelimeden fazla: her fazla kelime için $-0.1$ (örneğin 40 kelime $= -1.0$).

Cezanın sabit değil kelime başına (kademeli) verilmesi, modelin ideal aralığa doğru bir "eğim" görmesini sağlar. Aynı grubun bütün ödüllerde ortak kullandığı kontroller şunlardı (ekrandan, 01:20:00):

| Durum | Puan | Amaç |
|---|---|---|
| Doğru sıralama (açıklama önce, cevap sonra) | $+0.5$ | Mantıksal akış |
| Doğru cevap harfi | $+2.0$ | Ana ödül |
| Regex ile cevap çıkarımı başarılı | $+0.2$ | Format hassasiyeti |
| Spam (tekrar eden başlık) | $-3.0$ | Hile önleme |
| Birden fazla farklı şık | $-5.0$ | Hile önleme |
| Çok kısa açıklama (5 kelimeden az) | $-1.0$ | Kalite kontrolü |

Bir öğrencinin kısalık ödülünü anlattığı sırada hoca bunun "tek seferde cevabı söyle" demekle aynı şey olup olmadığını sordu; öğrenci farkın cezanın kademeli olması olduğunu söyledi.

### 4.4 Mantıksal bağlaç ve akıl yürütme

Birçok grup "çünkü", "bu nedenle", "dolayısıyla", "sonuç olarak" gibi bağlaçları sayan ödüller yazdı. Örneğin bir tasarımda bir bağlaç $+0.2$, en az iki bağlaç $+0.5$ veriyordu (ekrandan, 00:05:00). Bir başka grup "giriş, analiz, sonuç" akışını arıyordu. Bağlaç ödüllerine genelde bir üst sınır kondu; çünkü sınırsız bağlaç ödülü hileye açıktır (bkz. Bölüm 5).

### 4.5 Belirsizlik ve dürüstlük

Bazı gruplar "bilmiyorum", "emin değilim", "sanırım", "tahminen" gibi ifadeleri cezalandırdı (ekrandan, 00:35:00). Bir grup tersini denedi: uydurmaktansa "bilmiyorum" demesini ve yanlış şıkların neden yanlış olduğunu açıklamasını ödüllendirdi. Bu grup, hem doğru cevabı tutturup hem bilmediği soruda çekimser kalmanın küçük bir model için zor olduğunu gözlemledi.

### 4.6 Tekrar, entropi ve çeşitlilik

- **Tekrar/spam cezası:** "açıklama açıklama açıklama" ya da "çünkü çünkü çünkü" gibi tekrarlar n-gram ve benzersiz kelime oranıyla yakalanıp cezalandırıldı.
- **Entropi ödülü:** Bir öğrenci cevaptaki kelime dağılımının entropisini hesaplayıp belli bir eşiğin üstünde olmasını istedi; amaç aynı kelimelerin tekrarını engellemekti. Sonradan entropinin aşırı yüksek olmasının da sınırlanabileceğini önerdi.
- **Cevap çeşitliliği:** Bir soru için üretilen cevapların hepsi aynı şık olmasın diye çeşitliliği ödüllendiren, ya da modelin bütün sorulara aynı cevabı vermesini cezalandıran tasarımlar denendi.

### 4.7 Diğer bileşenler

- **Türkçe karakter ödülü:** Model "düşündüğüm" yerine "dusundugum" yazabildiği için Türkçe karakter oranına göre ödül, "q", "w", "x" gibi harfler belli bir oranı aşınca ceza.
- **Dilsel kalite:** Cümlelerin uygun noktalama işaretiyle bitmesi.
- **Anlamsal benzerlik:** Açıklama ile cevap arasındaki vektörel (embedding) benzerliğe göre puan. Başka bir öğrenci benzer bir fikri çalışma süresi açısından ağır bulduğu için regex tabanlı ödüllere döndü.
- **Prompt kopyalama cezası:** Çıktının prompttaki kelimelerle örtüşme oranına göre ceza.
- **Kalibrasyon ödülü:** Model doğruysa emin, yanlışsa emin değilmiş gibi davransın.

### 4.8 Ödül bileşenleri nasıl kullanılır?

Bir öğrenci her LoRA adaptörünü tek bir yeni ödülle eğittiğini söyleyince hoca bunu sordu. Öğrenci yeni ödüllerin doğruluk ve format ödülünün üstüne eklendiğini açıkladı. Hoca bunu onayladı: yeni bileşenler temel ödülün üstüne eklenir; tek başına bir bileşen (örneğin yalnız uzunluk) anlamlı bir eğitim sağlamaz.

Bir öğrenci ödül fonksiyonlarını türetirken bir yapay zekâ aracından destek aldığını, aracın birbirine çok benzeyen öneriler verdiğini anlattı. Hoca, bu önerilerin değerlendirilmesi gerektiğini, yapay zekânın yetmediği yerde "doğal zekânın" kullanılması gerektiğini söyledi.

## 5. Ödül Hilesi ve Modelin Davranışı

### 5.1 Reward hacking

Bağlaç ödülüyle eğitilen bir modelin çıktısında beş bağlaç bulunuyor, model $1.5$ gibi yüksek bir puan alıyor, ama cümlelerin hiçbir mantığı yoktu. Hoca bu durumu adlandırdı:

> **Hocanın vurgusu:** Buna "reward hacking" denir: ödülü memnun etmek, ama ürettiği şeyin temelde istediğimiz şey olmaması.

Bir öğrencinin eğitim grafiklerinde ödülün çok kısa sürede ani artışı, kayıp ile ödül arasında aşırı hızlı bir ilişki görülüyordu. Öğrenci bunu modelin erken aşamada "kolay çözüme kaçması", görevin özünü değil ödül fonksiyonunun açıklarını optimize etmesi olarak yorumladı. Tekrar cezası eklenen modelde ise ödül artışı kademeli ve kararlıydı. Öğrencinin vardığı sonuç "yüksek ödül değil, davranış önemlidir" oldu (ekrandan, 02:35:00).

### 5.2 Gözlenen davranışlar

Sunumlarda görülen tipik davranışlar şunlardır:

- **Bütün şıkları saymak:** Ceza olmayan bir tasarımda model, bütün seçenekleri tekrar ederse her durumda bir miktar ödül aldığını "fark etti" ve neredeyse bütün modeller şıkları papağan gibi tekrar etmeye başladı.
- **Susmak:** Cezanın abartıldığı tasarımda model "ödül alamıyorsam ceza da almayayım" mantığıyla hiç cevap vermemeye başladı.
- **Tek şıkka yönelmek:** Bir raporda model belirsiz durumlarda sistematik olarak C şıkkını seçiyordu; soruyu çözmek yerine "C cevabını vererek ödülü en yükseğe çıkarma" stratejisini benimsemişti (ekrandan, 00:25:00). Rastgele seçilen beş sorudan oluşan bir niteliksel analiz tablosunda modelin tahmini beş soruda da "C" idi; doğru cevaplar C, D, C, A, C idi (ekrandan, 00:20:00).
- **Soruyu kopyalamak:** Benzerlik ödülüyle eğitilen model soruyu kopyalamayı, ardından benzer yeni sorular üretmeyi öğrendi. Bir rapordaki örnek tabloda temel model "Doğru şık A şıkkıdır, doğru şık B şıkkıdır, ..." diye bütün şıkları sayıyor, bias modeli "Doğru" kelimesini art arda tekrarlıyor, benzerlik modeli ise soruyu ve şıkları tekrar edip yeni bir soruya geçiyordu (ekrandan, 01:00:00).

Bir öğrencinin aynı soruya verdiği cevapta hoca şunu sordu: benzerlik modeli soruyu kopyalamayı öğrendiyse niye puan alamamış? Öğrenci, benzerlik ödülünün format ödülüyle aynı büyüklükte verildiğini, modelin benzerliği takip etmeyi seçip doğru cevap vermenin ödülünü hiç "tadamadığını" düşündüğünü söyledi.

### 5.3 Dengeli tasarım

Bir grubun vardığı sonuç: yalnız ödül verildiğinde model tekrara düşüyor ve ödül almak için her şeyi yapabiliyor; fazla ceza verildiğinde ise sessizliğe bürünüyor. Ödül ve ceza arasında denge kurmak gerekir.

## 6. GRPO'nun Ayarları: Cevap Sayısı, KL Katsayısı, SFT

### 6.1 Soru başına cevap sayısı (num_generations)

Sunumlarda soru başına 4, 6, 8 ve 16 cevap üretildiği görüldü. Bir öğrencinin bu değeri 2 seçtiğini görünce hoca şöyle açıkladı: GRPO bir "grup politikası" yöntemidir; bir soru için üretilen cevaplar birbirine göre değerlendirilir. Model zaten çok bir şey yapamıyorken yalnız iki cevap üretilirse bu iki cevaptan birinin doğru olma olasılığı düşüktür ve karşılaştırma anlamlı olmaz.

> **Hocanın vurgusu:** İki gibi bir değer kullanmak iyi değildir. En azından 8 civarında bir değer daha makuldür.

### 6.2 KL ıraksaması

Bir grubun modeli anlamsız çıktılar üretince hoca şunu hatırlattı: GRPO'nun içinde modelin bozulmasını engelleyen bir referans noktası vardır; bu, KL ıraksaması (KL divergence) terimidir. Modelin kendi ürettiği metni çok bozmasını engellemek için bu terimin katsayısı artırılır. Bu kısım modeli bozmadan ürettiği metnin hâlâ anlamlı olmasını sağlar. Başka bir grup ise tersini yaptığını anlattı: modelin istenen formata daha çok uyması için beta katsayısını küçültüp referans modelden biraz uzaklaşmasına izin vermişti.

> **Ek bilgi (derste anlatılmadı):** GRPO'nun amacında, güncellenen politika ile referans politika (genellikle başlangıç modeli) arasındaki KL ıraksaması $\beta$ katsayısıyla cezalandırılır. $\beta$ büyüdükçe model referansa yakın kalır ve dil yeteneği korunur, ama ödüle uyum yavaşlar; $\beta$ küçüldükçe model ödüle daha hızlı uyar, ama bozulma riski artar.

### 6.3 Diğer hiperparametreler

Sunumlarda öğrenme oranı olarak $5 \times 10^{-6}$ ve $2 \times 10^{-6}$ gibi küçük değerler, 300-700 adım, 512 token en uzun prompt, 0.8 sıcaklık (temperature) görüldü. Bir grup sıcaklığı modelin farklı cevaplar deneyip entropisinin artması için yüksek tuttuğunu söyledi. Bir grup LoRA parametrelerini, modelin kartındaki önerilen değerlerin yarısı olarak seçtiğini; LoRA parametrelerini artırmanın arama uzayını da büyüttüğünü anlattı. Bir öğrenci epoch sayısını 3 yapınca modelin aşırı öğrenip yalnız ödüllendirilen davranışa odaklandığını gözlemledi.

Bir grubun en fazla 6 token çıktı üretme ayarına hoca neden böyle seçildiğini sordu. Grup, çoktan seçmeli sorular için kısa çıktının yeterli olacağını düşündüklerini söyledi.

### 6.4 GRPO'dan önce SFT

Bir öğrenci, modelin soru-cevap bağlamını ve cevap formatını öğrenmesi için GRPO'dan önce denetimli ince ayar (SFT) uyguladı. Model formatı başarıyla öğrendi, ama cevaplar tek bir şıkka çöktü. Doğru cevaba $0.9$, doğru formata $0.1$ veren temel ödül de, çeşitliliği ödüllendiren dört alternatif ödül de bunu düzeltemedi; doğruluk tek şıkka çökmüş bir modelden beklenen düzeyde kaldı.

> **Hocanın vurgusu:** SFT'de model muhtemelen aşırı öğrendi (overfit) ve yerel bir minimuma çöktü. GRPO onu oradan hareket ettiremez. SFT ya çok daha az yapılmalı ya da hiç yapılmadan doğrudan GRPO denenmeliydi. Çökmeyi başta fark ettiğinde buna göre davranmak gerekirdi.

## 7. Model Birleştirme

### 7.1 Birleştirme yöntemleri

Gruplar şu yolları kullandı:

- **MergeKit:** Modellerin ağırlıklarını birleştirme kütüphanesi.
- **PEFT ile adaptör birleştirme:** MergeKit sorun çıkardığında kullanıldı.
- **LoRA adaptör ağırlıklarının ortalaması:** Bir raporda formül açıkça yazılmıştı (ekrandan, 01:25:00):

$$W_{merged} = 0.5 \times W_{simple} + 0.5 \times W_{long}$$

Burada $W$ LoRA adaptör ağırlık matrislerini gösterir; her adaptör %50 oranında birleştirilmiş, böylece iki model eşit katkıda bulunmuştur.

- **Ağırlıklı ortalama:** Bir öğrenci en iyi modele biraz daha fazla ağırlık vermek için $\alpha = 0.6$, $\beta = 0.4$ katsayılarını kullandı.

Elinde modelin tamamı olmadığı için yalnız adaptör ağırlıklarının ortalamasını alan bir öğrenciye hoca şunu hatırlattı: LoRA ile eğitimden sonra ortaya çıkan matrislerin tekrar modele eklenmesi gerekir. Nihai model ancak böyle elde edilir ve başka bir yerde kullanılabilir.

### 7.2 Birleştirmenin sonuçları

Sonuçlar gruptan gruba değişti:

- Bir grupta birleştirme en iyi sonucu verdi: temel modelin doğruluğu %0.4 iken birleştirilmiş model %24.2'ye çıktı. Grubun raporuna göre başarının arkasında modelin belirsizlikte C şıkkına yönelmesi de vardı (ekrandan, 00:25:00).
- Bir grupta en iyi iki tekil model %6.8 ve %4.4 doğruluk verdi; ortalama olarak %5.6 beklenirken birleştirilmiş model %4'e düştü (ekrandan, 01:25:00). Öğrenciler bunu "yaklaşık %30 daha düşük" diye özetledi.

$$\frac{0.5 \cdot 6.8 + 0.5 \cdot 4.4 - 4}{0.5 \cdot 6.8 + 0.5 \cdot 4.4} = \frac{5.6 - 4}{5.6} \approx 0.286$$

(ara adım eklendi; yani beklenen değerden yaklaşık %29 düşük.)

- Bir grubun tablosunda tekil modeller %31.0 ile %37.6 arasında, birleştirilmiş model %45.4 görünüyordu (ekrandan, 01:40:00). Ancak grup sonradan bu doğrulukların ölçüm hatasından şişkin olduğunu fark etti (bkz. Bölüm 8); ölçüt düzeltilince değerler %10'lara düştü, yine de birleştirilmiş model iki tekil modelden yüksek kaldı.
- Bir grupta birleştirilmiş modelin token yapısı bozuldu; model var olmayan etiketler açıp şıklarda olmayan cevaplar uydurdu.

Bir öğrenci birleştirmenin "neredeyse sıfır eğitim süresiyle" en yüksek doğruluğa ulaştığını söyleyince hoca, birleştirilecek modellerin önce eğitilmesi gerektiğini, bunun da bir maliyeti olduğunu hatırlattı.

### 7.3 Ödül birleştirme model birleştirme değildir

Bir öğrenci birleştirme adımında ödül fonksiyonlarının bileşenlerini ağırlıklandırıp (örneğin 0.3, 0.3, 0.2, 0.2) tek bir ödülle yeni bir model eğitmişti. Hoca ödevin böyle olmadığını, eğitilmiş modellerin birleştirilmesinin istendiğini belirtti.

### 7.4 Karar düzeyinde topluluk

Bir öğrenci dört modelin "cevaplarını birleştirerek" bir topluluk (ensemble) kurduğunu söyledi. Hoca, her modelin bir metin (string) ürettiğini hatırlatıp topluluğun cevabının bu metinlerden nasıl belirlendiğini sordu; öğrencinin "ödül skorlarını ağırlıklandırarak birleştirdim" açıklaması hocanın sorusunu karşılamadı.

> **Ek bilgi (derste anlatılmadı):** Her modelin çıktısından bir şık çekilebiliyorsa, karar düzeyinde birleştirme için en basit yol çoğunluk oylamasıdır: her model bir şık "oylar", en çok oy alan şık topluluğun cevabı olur. Modellerin doğrulukları farklıysa oylar ağırlıklandırılabilir. Ağırlık birleştirmede ise tek bir model elde edilir ve çıkarım bir kez yapılır.

## 8. Değerlendirme ve Ölçüm Hataları

### 8.1 Çıktıya bakmak

Hoca neredeyse her sunumda iki şey sordu: modelin bir soruya verdiği gerçek çıktı nedir ve doğruluk nasıl hesaplanmıştır? Çıktılarını hiç incelemeden yalnız tablolara odaklanan bir öğrenciye bunun iyi bir bakış açısı olup olmadığını sordu. Bir grubun kodları kaybolduğu için çıktı gösterilemedi; hoca bu durumda da modelin bir çıktısının nasıl değerlendirildiğini, doğru cevabın nasıl ölçüldüğünü anlamak istedi.

### 8.2 Şişkin doğruluk

Bir grup doğruluğu, doğru şıkkın modelin cevabının içinde geçip geçmediğine bakarak ölçmüştü. Model bütün şıkları tekrar edince her soru doğru sayıldı ve doğruluk %30'ların üstünde göründü. Grup örneklere tek tek bakınca hatayı fark etti; ölçütü düzeltince doğruluk %10'lara düştü. Hoca, hatayı görmelerine rağmen doğruluk ölçütünü neden değiştirmediklerini sordu.

Bir başka grup, doğruluğu hem doğru cevap hem doğru format şartıyla ölçtüğü için düşük gördüğünü; açıklamada doğru şıkkı söyleyip "Cevap: X" kalıbına koymayan çıktıların sayılmadığını anlattı.

### 8.3 Rastgele tahminle karşılaştırma

Bir öğrencinin temel modeli %10 doğruluk verdi. Hoca bu değerin iyi olup olmadığını sordu. Öğrenci bunun iyi olmadığını, beş şıklı sorularda rastgele cevap vermenin %20 doğruluk getireceğini, sürekli cezalandırıldığı için modelin bunun altına düştüğünü söyledi. Benzer biçimde hoca, formatı öğrenen ama cevapları hâlâ rastgele düzeyde kalan bir model için "formatı öğreniyor ama cevaplar rastgele düzeyinde" yorumunu yaptı.

### 8.4 Göreli artış hesabı

Bir grup temel modelden birleştirilmiş modele göreli artışı şu formülle hesapladı:

$$\text{Artış} = \frac{\text{yeni} - \text{eski}}{\text{eski}} \times 100 = \frac{24.2 - 0.4}{0.4} \times 100$$

> **Ders sonrası not:** Sunumda sonuç "%59.5" diye söylendi. Doğrusu $\frac{23.8}{0.4} \times 100 = 5950$, yani yaklaşık %5950'lik bir göreli artıştır (python ile kontrol edildi).

### 8.5 Ek ölçütler

- **Etkin skor:** Bir öğrenci doğruluk ile format uyum oranının çarpımını etkin skor olarak kullandı ve birleştirilmiş modelin doğruluğunu Wilson %95 güven aralığıyla kontrol etti. Bu öğrenci format uyumu %100'e çıkınca doğruluğun da yükseldiğini gözlemledi.
- **Güven, marj ve entropi:** Bir öğrenci modelin şıklara verdiği olasılıkları kullandı (ekrandan, 02:50:00). Güven olasılığı modelin seçtiği şıkka verdiği olasılıktır. Marj, doğru şıkkın olasılığı ile en yüksek yanlış şıkkın olasılığı arasındaki farktır; örneğin doğru şık $0.6$, en yüksek yanlış $0.3$ ise marj $0.3$'tür, negatif marj modelin yanlışa yöneldiğini gösterir. Entropi cezası olasılık dağılımının belirsizliğini ölçer: dört şıkka eşit $0.25$ olasılık verilirse entropi en büyük değerine, $\ln 4 \approx 1.386$'ya ulaşır; tek şıkka $1$ olasılık verilirse $0$ olur.

| Ölçüt | Eğitim | Test |
|---|---|---|
| accuracy | 0.2170 | 0.2260 |
| soft_accuracy | 0.3344 | 0.3472 |
| confidence_prob | 0.8011 | 0.2260 |
| margin | -0.1370 | -0.3560 |
| entropy_penalty | -0.9589 | -0.6460 |
| ensemble_result | - | 0.2220 |

(ekrandan, 02:50:00)

- **Kalibrasyon ve istatistiksel testler:** Bir grup beklenen kalibrasyon hatası (ECE), McNemar testi ve bootstrap güven aralıkları kullandı. Raporlarında kalibrasyon temelli ödülün %52.0 doğruluk ve en düşük ECE ($0.11$) verdiği, topluluk yaklaşımının doğruluğu %52.8'e çıkardığı yazıyordu (ekrandan, 03:20:00). Grafikte ise en yüksek doğruluk çeşitlilik ödülünde görünüyordu; sunumda da çeşitlilik modeli %56.4 ile en iyi diye anlatıldı. Hoca doğruluğun nasıl hesaplandığını sorduğunda grup, modelin tek bir şık ürettiğini, A-E dışındaki ya da bozuk formatlı çıktıların yanlış sayıldığını söyledi. <!-- BELİRSİZ: Raporun metni ile grafik ve sözlü anlatım arasında en iyi model konusunda tutarsızlık var; kare yalnız bir anı gösteriyor. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:31:59): Beş şıklı çoktan seçmeli sorularda bir model %10 doğruluk veriyor. Bu iyi bir değer midir?

> **Cevap (derste verildi):** Değildir. Beş şıklı bir soruda rastgele cevap vermek bile beklenen değer olarak $1/5 = $ %20 doğruluk verir. %10, rastgele tahminin de altındadır; model büyük olasılıkla cezalar yüzünden formatı ya da cevabı bozuyordur.

**Soru 2** (derste sözlü, 02:06:14): Modelden önce cevabı (şıkkı), sonra gerekçeyi istemek mi daha doğaldır, önce gerekçeyi sonra cevabı istemek mi? Neden?

> **Cevap (derste verildi):** Önce gerekçe, sonra cevap. Model bir sonraki token'ı tahmin edecek biçimde eğitilmiştir. Sorudan hemen sonra doğru şıkkı tahmin etme olasılığı düşüktür; adım adım ilerleyip "dolayısıyla cevap şudur" demek böyle bir model için çok daha kolaydır. Önce cevap istenirse cevap uydurulur ve gerekçe ona göre üretilir.

**Soru 3** (derste sözlü, 03:10:11): GRPO'da soru başına üretilen cevap sayısı (num_generations) 2 seçilirse ne olur?

> **Cevap (derste verildi):** GRPO cevapları grup içinde birbirine göre değerlendirir. İki cevapla bu karşılaştırma anlamlı olmaz; zayıf bir modelde iki cevaptan birinin doğru olma olasılığı da düşüktür. En az 8 civarında bir değer daha makuldür.

**Soru 4** (derste sözlü, 02:02:51): GRPO'dan önce yapılan SFT sonrasında model bütün sorulara aynı şıkkı vermeye başladı ve farklı ödüller bunu düzeltmedi. Sorun nedir, ne yapılmalıydı?

> **Cevap (derste verildi):** SFT'de model muhtemelen aşırı öğrendi ve yerel bir minimuma çöktü; GRPO onu oradan hareket ettiremez. SFT çok daha az yapılmalı ya da hiç yapılmadan doğrudan GRPO ile eğitim denenmeliydi.

**Soru 5** (derste sözlü, 01:28:01): GRPO ile eğitilen model anlamsız, bozuk metinler üretmeye başladı. GRPO'nun hangi bileşeni bunu engellemek içindir ve nasıl ayarlanır?

> **Cevap (derste verildi):** Referans modele göre hesaplanan KL ıraksaması terimi. Modelin kendi ürettiği metni bozmasını engellemek için bu terimin katsayısı artırılır.

**Soru 6** (derste sözlü, 01:29:29): Ödevde neden veri setinin bilgi değil çıkarım gerektiren sorulara filtrelenmesi istendi?

> **Cevap (derste verildi):** Modelin bilgisi çok sınırlıdır. GRPO modelin bilmediği bir bilgiyi keşfettiremez; yalnız var olan yeteneği (akıl yürütme, format) ödülle yönlendirebilir.

**Soru 7** (derste sözlü, 00:39:33): LoRA adaptörleriyle eğitilen modeller adaptör ağırlıklarının ortalaması alınarak birleştirildi. Nihai, başka yerde kullanılabilir bir model elde etmek için ne gerekir?

> **Cevap (derste verildi):** Eğitimden sonra ortaya çıkan LoRA matrislerinin temel modele geri eklenmesi gerekir; nihai model ancak böyle elde edilir.

**Soru 8** (derste sözlü, 01:55:14): Dört modelin her biri metin (string) üretiyor. Topluluğun (ensemble) cevabı bu metinlerden nasıl belirlenir?

> **Çözüm (derste verilmedi):** Her modelin çıktısından regex gibi bir kuralla bir şık çekilir. Topluluk cevabı bu şıklar üzerinde çoğunluk oylamasıyla belirlenir: en çok oy alan şık seçilir. Modellerin doğrulukları farklıysa her oy modelin doğruluğuyla ağırlıklandırılabilir; eşitlikte en güvenilir modelin şıkkı seçilebilir. Hoca soruyu sordu, ama öğrencinin açıklaması soruyu karşılamadı.

**Soru 9** (derste sözlü, 00:23:15): Temel modelin doğruluğu 0.4, birleştirilmiş modelin doğruluğu 24.2 ise göreli artış yüzde kaçtır?

> **Çözüm (derste verilmedi):** $\frac{24.2 - 0.4}{0.4} \times 100 = \frac{23.8}{0.4} \times 100 = 5950$. Göreli artış yaklaşık %5950'dir. Sunumda sonuç "%59.5" diye söylenmişti (bkz. Bölüm 8.4).

## Dersin Toparlaması

Bu derste konu anlatımı yerine GRPO ödevinin sunumları yapıldı. Sunumlardan çıkan ortak ders şudur: küçük bir dil modelini ödülle eğitirken ödül fonksiyonu modelin davranışını doğrudan biçimlendirir ve model ödülün her açığını kullanır. Bağlaç sayan ödül anlamsız bağlaç dizileri, cezasız tasarım bütün şıkları sayan cevaplar, aşırı ceza ise susan bir model üretti. Prompt formatı (önce gerekçe, sonra cevap), soru başına üretilen cevap sayısı, KL katsayısı ve GRPO'dan önceki SFT miktarı sonucu belirleyen önemli kararlardır. Veri setinin bilgi değil çıkarım gerektiren sorulardan seçilmesi de önemlidir, çünkü GRPO modelin bilmediği bilgiyi ona öğretemez.

Topluluk öğrenmesi açısından, farklı ödüllerle eğitilmiş modellerin ağırlık birleştirmesi bazı gruplarda tekil modellerden iyi, bazılarında kötü sonuç verdi. Bu, birleştirmenin kendiliğinden iyileşme getirmediğini gösterir. Hocanın her sunumda tekrarladığı uyarı da değerlendirmeyle ilgiliydi: modelin gerçek çıktısına bakmadan ve doğruluğun nasıl ölçüldüğünü denetlemeden verilen tablolar yanıltıcı olabilir. Hoca kapanışta ödevin zor olduğunu, ama zorlandıkça herkesin bir şeyler öğrendiğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
