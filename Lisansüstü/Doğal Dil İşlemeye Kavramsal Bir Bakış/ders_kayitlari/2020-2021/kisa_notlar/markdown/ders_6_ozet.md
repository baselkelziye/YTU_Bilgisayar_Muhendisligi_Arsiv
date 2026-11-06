# Ders 6 Çalışma Özeti

## Genel Konular

- Dil modellerinin tekrarı ve n-gram modelinin pratikte kullanımı.
- Bigram ile cümle olasılığı: "I want to eat Chinese food" örneği.
- Seyrek (sparse) matrisler ve yumuşatma (smoothing) teknikleri:
  - Add-one smoothing.
  - Good-Turing.
  - Back-off yöntemi.
- N-gram modelinin biçimbirimsel belirsizliği gidermede kullanımı ("koyun" örneği).
- Kelime anlamları, anlam (sense) kavramı ve kelime anlam belirsizliği giderme (word sense disambiguation, WSD).
- Seçilmiş sözcük ve tüm sözcük yaklaşımları.
- Bilgi tabanlı, derlem tabanlı ve makine öğrenmesi yöntemleri.
- Lesk algoritması ve geliştirilmiş biçimleri.
- WordNet (kelime ağı): yapısı, ilişkileri, Türkçe çalışmalar.
- WordNet üzerinden kelime benzerliği ölçütleri: Leacock & Chodorow, Wu & Palmer, Jiang-Conrath, Lin.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kelimeler doğal dilde birbirinden bağımsız durmaz. Bu yüzden kelime olasılıklarını bağımsız çarpmak gerçekçi sonuç vermez.
- Tüm geçmişi kullanan n-gram pratikte uygulanamaz. Çalışmalarda $n$ en fazla 5'e kadar çıkar. Genelde 2 ve 3 yeterlidir.
- Hiçbir derlem ne kadar büyük olursa olsun bütün kelime ikililerini içermez. Zipf yasası gereği seyrek veri her zaman olacaktır.
- Sıfır olasılık, olasılık çarpan yöntemlerde (örneğin Naive Bayes) bütün sonucu sıfır yapar. Bu yüzden yumuşatma gerekir.
- Sıfırlara rastgele değer atanamaz. Mantıklı bir yumuşatma tekniği kullanılmalıdır.
- Add-one örneği daha önce bir sınav sorusuydu ve öğrenciler hata yapmıştı. Hoca o yüzden bu örneği derste ayrıntılı anlatıyor.
- Kelime anlam belirsizliğinde çalışmaların çoğu seçilmiş sözcük yaklaşımıyla yapılır. Tüm sözcük yaklaşımı çok zordur ve başarısı düşüktür.
- WordNet'te en sık kullanılan ilişkiler üst kavram (hypernym) ve alt kavram (hyponym) ilişkileridir.
- Seminerde makaleyle ilgili uygulama geliştirilmeyecek. Sunum en fazla 15 dakika olacak.

## Kısa Tekrar Notları

- N-gram yaklaşımı: $P(w_n|w_1^{n-1}) \approx P(w_n|w_{n-N+1}^{n-1})$.
- Bigram ile cümle olasılığı: $P(w_1^n) \approx \prod_{k=1}^{n} P(w_k|w_{k-1})$.
- Bigram olasılığı: $P(w_n|w_{n-1}) = \frac{C(w_{n-1}w_n)}{C(w_{n-1})}$.
- Unigram: $n=1$. Bigram: $n=2$. Trigram: $n=3$. Quadgram: $n=4$.
- Bigram grameri $V \times V$ boyutunda bir olasılık matrisidir. $V$ sözlük boyutudur.
- Add-one: her sayıma 1 eklenir ve normalize edilir. $P'(w_i) = \frac{c_i + 1}{N_T + V}$.
- Good-Turing: hiç görülmemiş bir olayın olasılığı = bir kez görülen tür sayısı / toplam gözlem sayısı.
- Back-off: önce $n$-gram'a bakılır. Sayım sıfırsa $(n-1)$-gram'a, o da sıfırsa daha küçük $n$ değerine inilir.
- Sense: bağlamdaki kullanım ile kelimenin gerçek anlamı arasındaki bağlantıyı belirleyen kavram.
- Lesk: kelimenin sözlükteki hangi anlam açıklaması bağlamla en çok örtüşüyorsa o anlam seçilir.
- WordNet: bir dilin kelimelerini, tanımlarını ve kelimeler arası anlamsal ilişkileri içeren veri tabanı.
- Synset (eşküme): bir kelime, onun bir anlamı ve o anlamın ilişkileri.
- Benzerlik ölçütleri iki gruptadır: bağ sayma (edge counting) ve bilgi içeriği (information content).

## Detaylı Açıklamalar

### Ders başı duyuruları

- Hoca öğrencilerin seminer bilgilerini topladı. Seminer takvimini hafta sonu hazırlayacak.
- Ocak ayının ilk haftası da eğitim var. Dönem 9 Ocak'ta kapanıyor.
- Plan: Aralık'ın son haftası ile Ocak'ın ilk haftası seminer haftaları olacak.
- Seminerlerden önceki hafta kısa bir değerlendirme sınavı (vize gibi) yapılacak.
  - Çoktan seçmeli ya da kısa sorular olacak.
  - Çok temel ve bariz şeyler sorulacak. Hocanın derste çok üzerinde durduğu, birkaç slaytta tekrar ettiği yerler önemlidir.
  - Amaç, anlatılanların ne kadarının alındığını görmek. Projeler bunu tam yansıtmıyor.
- Ekran paylaşımı gibi sorunlarda öğrencilerin sohbete (chat) yazmak yerine sesli haber vermesi istendi.

### Dil modellerinin tekrarı

- Dil modeline ihtiyaç duyulan uygulamalar: konuşmadan metne (speech to text), OCR, yazar tanıma (özellik çıkarma), kelime belirsizliği giderme.
- Dil modeli istatistik tabanlıdır. Kelimelerin, kalıpların ya da karakter dizilerinin olasılıkları kullanılır.
- En kaba hâli: sözlükte $V$ kelime varsa her kelimenin olasılığı $1/V$ alınır. Cümle olasılığı bu değerlerin çarpımıdır.
- Daha iyisi: kelimeler bağımsız kabul edilip her kelimenin kendi olasılığı çarpılır. Bu da yeterince gerçekçi değildir.
- Sebep: kelimeler bağımsız değildir. İngilizcede "I am", "he is", "she is", "he did" gibi zamirden sonra genelde yardımcı fiil gelir. "he" ve "did" ayrı ayrı değil, birlikte geçme olasılığıyla ele alınırsa daha gerçekçi sonuç çıkar.

### N-gram modeli

- Dört kelimelik (ya da karakterlik) bir dizi düşünelim: A, B, C, D.
  - A'nın geçmişi yoktur. Kendi olasılığı alınır.
  - B için A ile birlikte gelme olasılığına bakılır.
  - C için C'nin metinde kaç kez geçtiğine değil, A ve B'den sonra kaç kez geçtiğine bakılır.
  - D için A, B ve C ile birlikte kullanımına bakılır.
- Formülde bu çarpımlar $\prod$ ile gösterilir.
- Pratik sorun: 10 bin kelimelik bir dokümanda son kelimenin olasılığı için önceki 9999 kelimeyle birlikte olasılık hesaplanmalıdır.
  - Bu hesap çok maliyetlidir.
  - Bu dizinin derlemde tekrar geçmesi için çok büyük bir derlem gerekir.
- Bu yüzden $n$ sınırlanır. Hoca 5'i bile çok az gördüğünü söyledi. $n = 4$ ya da 5 alınınca yalnızca olasılık değerleri küçülür, başarı ondalık noktadan sonra değişir.
- "chasing the big dog" örneğinde "dog" kelimesinin olasılığı:
  - Unigram: yalnızca "dog".
  - Bigram: "big dog".
  - Trigram: "the big dog".
  - Quadgram: "chasing the big dog".

### Bigram ile cümle olasılığı

- Örnek ($n = 2$):

$$P(\text{I want to eat Chinese food}) = P(\text{I}|\langle start\rangle) \, P(\text{want}|\text{I}) \, P(\text{to}|\text{want}) \, P(\text{eat}|\text{to}) \, P(\text{Chinese}|\text{eat}) \, P(\text{food}|\text{Chinese})$$

- Bu ikililerin olasılıkları derlemden çıkarılır ve çarpılır. Sonuç, bu cümlenin bu sırayla, araya kelime girmeden derlemde görülme olasılığıdır.
- Popülerlik örneği:
  - Soru: Çin mutfağı mı daha popüler, İngiliz mutfağı mı?
  - İnsan bunu deneyimiyle bilir. Hemen her ülkede Çin restoranı vardır ama İngiliz restoranına pek rastlanmaz.
  - Bilgisayar bunu dil modeliyle çıkarabilir. Aynı cümlede "Chinese food" yerine "British food" yazılır ve iki olasılık karşılaştırılır.
  - "Chinese food" olasılığı çok daha büyük çıkar. Demek ki bu konuda çok daha fazla yayın ve haber vardır.
  - Sonuç: dil modeli beklenmedik bir soruya cevap verebilir.

### Sıfır olasılık ve seyrek veri

- Bazı cümlelerin olasılığı sıfıra çok yakın ya da sıfır çıkar. Sebepler:
  - Yazım hatası: yanlış yazılan bir kelimeyi başkası aynı şekilde yanlış yazmayacağı için derlemde geçmez.
  - Çok nadir konular.
- Sözlük boyutu $V$ (örneğin 300 bin) ise bigram sayım matrisi $V \times V$ boyutundadır. Örneğin "aba aba" ya da "aba abla" ikilileri hiç geçmez.
- Bu matris çoğunlukla sıfırlardan oluşur. Buna seyrek (sparse) matris denir.
- Sıfırlardan kurtulmak için yapılan işleme yumuşatma (smoothing) denir. Amaç: sıfır yerine sıfıra yakın ama sıfır olmayan bir değer vermek.
- Naive Bayes gibi yöntemler olasılıkları çarpar. 0,5 × 0 × 0,9 = 0 olur. Sıfır yutan eleman olduğu için örnek hiçbir sınıfa yerleşemez ya da yanlış sınıfa yerleşir.

### Sayım ve olasılık matrisi örneği

- Sözlük: I, want, to, eat, Chinese, food, lunch. $n = 2$.
- Bigram sayımları (satır: önceki kelime, sütun: sonraki kelime):

|  | I | want | to | eat | Chinese | food | lunch |
|---|---|---|---|---|---|---|---|
| I | 8 | 1087 | 0 | 13 | 0 | 0 | 0 |
| want | 3 | 0 | 786 | 0 | 6 | 8 | 6 |
| to | 3 | 0 | 10 | 860 | 3 | 0 | 12 |
| eat | 0 | 0 | 2 | 0 | 19 | 2 | 52 |
| Chinese | 2 | 0 | 0 | 0 | 0 | 120 | 1 |
| food | 19 | 0 | 17 | 0 | 0 | 0 | 0 |
| lunch | 4 | 0 | 0 | 0 | 0 | 1 | 0 |

- Unigram sayımları: I 3437, want 1215, to 3256, eat 938, Chinese 213, food 1506, lunch 459.
- Sıralama önemlidir: "want I" 3 kez, "I want" 1087 kez geçer. Değişme özelliği yoktur.
- "I I" ikilisi İngilizcede anlamsızdır ama 8 kez geçmiş. Hocaya göre bu, dokümanlarda Romen rakamıyla yazılmış maddelerden ("I", "II") kaynaklanır.
- Hesaplar:
  - $P(\text{I}|\text{I}) = \frac{C(\text{I I})}{C(\text{I})} = \frac{8}{3437} \approx 0{,}0023$
  - $P(\text{want}|\text{I}) = \frac{1087}{3437} \approx 0{,}32$
- Olasılık matrisi de sayım matrisi gibi seyrektir.

### Yumuşatma için parametreler

- $V$: sözlük boyutu (vocabulary size), yani farklı kelime sayısı.
- $N_T$: derlemdeki toplam kelime sayısı. Farklı kelime sayısı değildir.
- $T$: o ana kadar görülmüş ayrık kelime sayısı. $V$ ve $N_T$ değerinden küçüktür.
- Onlarca yumuşatma tekniği vardır. Derste akademik çalışmalarda en çok kullanılan ve daha iyi sonuç veren üçü anlatıldı.

### Add-one smoothing

- Her n-gram sayımına 1 eklenir. Yalnızca sıfırlara değil, bütün sayımlara eklenir: 0 olan 1, 5 olan 6 olur.
- Sonra bir normalizasyon katsayısıyla çarpılır. Normalizasyon, değerleri belirli bir aralığa sıkıştırır (örneğin 1-10.000 arasını 1-100 arasına).
- Yumuşatılmış sayım (smoothed count):

$$c_i' = (c_i + 1)\frac{N_T}{N_T + V}$$

- Yumuşatılmış olasılık (smoothed probability):

$$P'(w_i) = \frac{c_i'}{N_T} = \frac{c_i + 1}{N_T + V}$$

- Normalizasyon katsayısı illa bu olmak zorunda değildir. Min-max ya da z-score normalizasyonu gibi başka katsayılar da kullanılabilir.
- Add-one sonrası matris artık seyrek değildir. Örneğin "lunch want" ikilisi için sıfır yerine küçük pozitif bir değer kullanılır. Olasılık çarpımı sıfır çıkmaz.

### Add-one örneği (eski sınav sorusu)

- Sözlük 7 kelime: Bugün, de, her, zamanki, gibi, eve, gidiyorum.
- 7 kelimeyle yazılabilecek bütün ikililerin sayısı $7 \times 7 = 49$ olur. Örnekte $V$ yerine bu 49 kullanılır.
- Hesaplanan cümle: "Bugün de her zamanki gibi gidiyorum". Bu cümlede 5 ikili vardır.
- Yumuşatmasız olasılıklar slaytta $\frac{1}{5}$ olarak verildi: $P_{\text{Bugün de}} = \frac{1}{5}$, $P_{\text{de her}} = \frac{1}{5}$ vb.
- Add-one için slayttaki formül: $P_i^* = \frac{C_i + 1}{N + V}$.
  - $N$: o ana kadar karşılaşılan ikili sayısı (5).
  - $V$: yazılabilecek bütün ikililer (49).
  - $P_{\text{Bugün de}} = \frac{1 + 1}{5 + 49} = \frac{2}{54}$
- Cümlenin olasılığı bu değerlerin çarpımıdır.
- Bir öğrenci, tabloda "eve" kelimesinin de bulunduğunu, cümleye eklenirse ikili sayısının 6 olacağını sordu. Hoca, tablodaki kelimelerin sözlük olduğunu, cümlenin sözlükteki her kelimeyi içermek zorunda olmadığını açıkladı (örneğin "Bugün eve gidiyorum" da yazılabilir). Sınavda yaşanan karışıklık da buydu.

### Good-Turing

- Balık tutma örneği: 10 aynalı sazan (carp), 3 morina (cod), 2 tuna, 1 alabalık (trout), 1 som balığı (salmon), 1 yılan balığı (eel) yakalanmış. Toplam 18 balık.
- Soru: bir sonraki balığın yeni bir tür olma olasılığı nedir? Örneğin gölde hiç görülmemiş bir tür.
- Normalde bu olasılık sıfırdır. Good-Turing buna sıfır yerine anlamlı bir değer verir:

$$P(\text{yeni tür}) = \frac{\text{bir kez görülen tür sayısı}}{\text{toplam gözlem sayısı}} = \frac{3}{18}$$

- Mantık: yeni bir tür gelirse en az bir kez görülmüş olacaktır. Bu yüzden bir kez görülenlerin oranı kullanılır.
- Metin karşılığı: dokümanda 10 "medeniyet", 3 "hukuk", 2 "cumhuriyet", 1 "anayasa", 1 "yargıç" vb. varsa, gelecek kelimenin yeni bir kelime olma olasılığı aynı şekilde hesaplanır.

### Back-off yöntemi

- N-gram modeline dayanır.
- Trigram ($n = 3$) için $w_i$ olasılığı $w_{i-2}$ ve $w_{i-1}$ ile birlikte hesaplanır. Bu üçlü derlemde hiç geçmemişse $n$ bir azaltılır.

$$\hat{P}(w_i|w_{i-2}w_{i-1}) = \begin{cases} \tilde{P}(w_i|w_{i-2}w_{i-1}), & C(w_{i-2}w_{i-1}w_i) > 0 \\ \alpha_1 \tilde{P}(w_i|w_{i-1}), & C(w_{i-2}w_{i-1}w_i) = 0 \text{ ve } C(w_{i-1}w_i) > 0 \\ \alpha_2 \tilde{P}(w_i), & \text{diğer durumlarda} \end{cases}$$

- $n$ illa 3 olmak zorunda değildir. 4 ya da 5 de olabilir.
- $\alpha_1$ ve $\alpha_2$ katsayılarının görevi:
  - Asıl istenen olasılık üçlünün olasılığıdır. İkilinin ve tek kelimenin olasılığı daha büyüktür.
  - Katsayılar bu daha büyük değerleri küçültüp üçlünün olasılığına yaklaştırır. Tek kelimenin olasılığı daha da büyük olduğu için daha küçük bir katsayıyla çarpılır.
  - Katsayılar büyük bir derlemden deneysel olarak çıkarılır. Uğraşmak istemeyen, literatürde bu değerleri veren çalışmaları bulup kullanır.
- Özet: add-one sayıma 1 ekleyip normalize eder. Good-Turing bir kez görülenlerin oranını kullanır. Back-off sayım bulunana kadar $n$ değerini azaltır.

### N-gram ile biçimbirimsel belirsizlik giderme

- Morfolojik analiz araçları: Türkçe için Zemberek, Porter Stemmer, NLTK. Bu araçlar bir kelimenin olası bütün çözümlemelerini verir. Hangisinin doğru olduğunu söylemez.
- Örnek: "yüz" kelimesi fiil ("yüzmek"), isim ya da sayı olabilir.
- Daha önce bu, sentaktik analizle çözülüyordu: cümle hangi ağaca oturuyorsa kelimenin türü oradan alınıyordu. Parser yoksa n-gram kullanılabilir.
- Slayttaki örnek cümleler:
  - "Çoban bizim için sürüden bir koyun seçti": "koyun" hayvandır, isimdir.
  - "Oyuna devam etmek istiyorsanız beşer lira koyun": "koyun" fiildir ("koymak").
- Yöntem:
  - $n = 2$ alınır. $n$ büyüdükçe sonuç daha kesin olur.
  - Belirsizliği giderilecek kelime $w_t$ olsun.
  - Derlemde $w_{t-1}$ ve $w_t$ ikilisinin peş peşe gelme olasılıkları çıkarılır (örneğin "bir koyun", "lira koyun").
- İki derlemden çıkarılmış tablolar:

| Nitelik | Hayvan anlamlı "koyun" derlemi | Fiil anlamlı "koyun" derlemi |
|---|---|---|
| Fiil | 0,01 | 0,8 |
| İsim | 0,5 | 0,01 |
| Zamir | 0,01 | 0,01 |
| Sayı | 0 | 0 |
| Ünlem | 0,007 | 0,007 |
| Edat | 0,001 | 0,002 |

- Yeni bir doküman gelince aynı olasılıklar çıkarılır ve hangi tabloya benzediğine bakılır.
  - Kurban Bayramı ile ilgili bir dokümandaki olasılıklar ilk tabloya benzer. "Koyun" isim anlamındadır.
  - Kumarla ilgili ("bir koydun beş aldık") bir doküman ikinci tabloya benzer. "Koyun" fiil anlamındadır.

### Kelime anlamları ve anlam (sense)

- Şimdiye kadar kelimelere sayısal varlık olarak bakıldı: sıklıklar, birlikte kullanımlar. Kelimelerin anlamları bazı problemlerin çözümüne yardım edebilir.
- Sözlük bir veri tabanıdır: kelime, kelimenin anlamı, o anlamın geçtiği örnek cümle.
- "Kalem" deyince hepimizin aklına ilk anlamı gelir. Çünkü ilk anlam en çok kullanılan ve ilk öğrendiğimiz anlamdır.
- "Kalem" kelimesinin 6 anlamı:
  - Yazma, çizme vb. işlerde kullanılan araç ("Kalem masanın üstünde.").
  - Resmî kuruluşlarda yazı işlerinin görüldüğü yer ("Kalemimiz bugün hizmet vermeyecektir.").
  - Yontma işlerinde kullanılan ucu sivri araç ("oymacı kalemi").
  - Çeşit, tür ("beş kalem ilaç", "beş kalemlik fatura").
  - Bazı birleşik ifadelerde yazı anlamı ("kaleme almak").
  - Yazar ("Peyami Safa edebiyatımızın usta kalemlerindendir.").
- Bir kelimenin hangi anlamda kullanıldığı bağlamdan (context) anlaşılır.
- Sense (anlam): bağlamdaki kullanım ile kelimenin gerçek anlamı arasındaki bağlantıyı belirleyen kavram.
- Uygulamaya göre değişir: metindeki "kalem" sayısını bulmak için anlamlara bakmak gerekmez. Dokümanları içeriğe göre ayırmak için gerekebilir.
- Kelime anlam belirsizliği için her yıl Senseval / SemEval yarışmaları düzenlenir. Düzenleyen kurum veri setini hazırlar. Önce İngilizce için başlamış, sonra başka dillere de açılmıştır. Başarılı algoritmalar literatüre girebilir.

### Kelime anlam belirsizliği giderme yaklaşımları

- Sözcük seçimine göre iki yaklaşım vardır:
  - Seçilmiş sözcük yaklaşımı (lexical sample): araştırmacı birden fazla anlamı olan belirli kelimeleri seçer ("kalem", "yüz", "koyun" gibi). Örneğin yalnızca belirli isimler ya da fiiller.
  - Tüm sözcük yaklaşımı (all-words): dildeki bütün kelimeler ve bütün anlamları ele alınır.
- Çalışmaların büyük çoğunluğu seçilmiş sözcük yaklaşımıyla yapılır. Başarı daha yüksektir.
- Yöntemler kullandıkları kaynağa göre:
  - Bilgi tabanlı yöntemler (sözlük, WordNet).
  - Derlem tabanlı yöntemler.
  - Bilgi ve derlemi birlikte kullanan melez yöntemler.
  - Makine öğrenmesi yöntemleri (denetimli ve denetimsiz). Özellikler: kelimenin cümledeki yeri, birlikte geçtiği kelimeler vb.

### Seçilmiş sözcük yaklaşımı

- Küçük bir kelime grubu sözlükteki anlamlarıyla birlikte alınır.
- Derlemde bu kelimelerin geçtiği cümleler insan tarafından anlamlarına göre etiketlenir.
- Avantaj: anlam listesi etiketleyicinin önündedir. Az bilinen anlamlar da karıştırılmadan etiketlenir. Kolayca etiketli derlem elde edilir.

### Tüm sözcük yaklaşımı

- Bütün kelimeler sisteme yüklenir. Etiketleyiciler hepsini anlamlarına göre işaretler. Örneğin 300 bin kelime için büyük bir grup çalışması gerekir.
- Başarı düşük olduğu için ek bilgilere ihtiyaç vardır:
  - Türkçe gibi sondan eklemeli dillerde kelimenin kökü.
  - Büyük harfle yazılıp yazılmadığı.
  - Kelimenin cümledeki öğesi.
- Bu özellikler bir sınıflandırma yöntemine verilip model kurulur.
- Hoca tüm sözcük yaklaşımıyla yapılmış akademik çalışmaya rastlamadığını söyledi. Derin öğrenmeden sonra yapılmış olabilir.

### Lesk algoritması

- Bilgi tabanlı bir yöntemdir. Sözlük anlamının bağlamla örtüşmesine dayanır.
- Oxford sözlüğüyle İngilizcede başarısı %50-70 arasındadır. Anlam sayısı az olan kelimelerde %70'e yaklaşır. 6-10 anlamı olan kelimelerde %50'ye düşer.
- Adımlar:
  1. Tümcedeki belirsizliği giderilecek sözcük seçilir.
  2. Sözcüğün sözlükteki açıklamaları ve örnek tümceleri incelenir.
  3. Eşleşen sözcükler tespit edilir.
  4. En çok örtüşme hangi anlamdaysa sözcüğe o anlam atanır.
  5. Tümcedeki anlam taşıyan kelimeler kullanılır, işlevsel kelimeler (stop words: "ve", "veya", "için", "çünkü", "gibi") çıkarılır.
  6. Türkçe için kelimelerin kök ya da gövde biçimleri kullanılır.
- Örnek: "Eren'in konak gibi büyük evi var."
  - "Konak" kelimesinin sözlükte 7 anlamı var:
    1. Büyük ve gösterişli ev.
    2. Vali, kaymakam gibi yüksek dereceli devlet görevlilerinin resmî konutu.
    3. Konakçı.
    4. Araba veya hayvanla bir günde alınan yol.
    5. Yolculukta geceyi geçirmek için inilen, konaklanılan yer.
    6. Kundak çocuklarının başlarında görülen kepek tabakası.
    7. Gözde oluşan ince tabaka.
  - 1. anlamla çakışan sözcükler: "büyük", "ev" ve "konak" (3 sözcük).
  - 2. anlamla çakışan sözcükler: "gibi" ve "konak" (2 sözcük).
  - Diğer anlamlarda çakışma 1'e iner. En çok çakışma 1. anlamdadır. "Konak" burada "büyük ve gösterişli ev" anlamındadır.
  - Örnekte 5. ve 6. adımlar uygulanmadı. Uygulansaydı "gibi" çıkarılırdı.
  - Ek sorun: 2. anlamdaki "konut" kelimesi "ev" ile eş anlamlıdır. Eş anlamlılar da hesaba katılırsa çakışma 3 olur.
- Hocanın yorumu: "konak" kelimesinin 7 anlamından yalnızca 3'ünü bildiğini söyledi. Bilinmeyen anlamlar varken bütün kelimeleri etiketlemek zordur. Bu, tüm sözcük yaklaşımının zorluğunu gösterir.
- Zayıf yönler:
  - Sözlük açıklamalarında örnek tümcedeki sözcükler geçmeyebilir.
  - Birden fazla anlamda aynı sayıda örtüşme çıkabilir.
- Geliştirilmiş sürümler:
  - Corpus Lesk: örtüşmelere ağırlık verir. Çakışan kelime hedef kelimenin hemen sağında ya da solundaysa 3, iki kelime uzaklıktaysa 2, daha uzaktaysa 1 ile çarpılır.
  - Uyarlanmış Lesk (Adapted Lesk): yalnızca hedef kelimenin değil, cümledeki diğer kelimelerin ("Eren", "büyük", "ev") sözlük tanımlarını da karşılaştırmaya katar.

### Benzerlik ve ilişki

- Bir başka bilgi tabanlı kaynak WordNet'tir. İki sözcüğün anlamca ne kadar benzediğini ve aralarındaki ilişkiyi çıkarmaya dayanır.
- Örnek: su ile bardak arasındaki ilişkiye 1-5 arası puan verin. Çoğu kişi 4 ya da 5 der. Bardak ile şemsiye için çoğu kişi 1 der.
- İnsan bunu deneyimiyle yapar. Bilgisayara bu bilgiyi vermek için WordNet ortaya atılmıştır.
- İlişki ile benzerlik farklıdır:
  - "Akıllı" ile "aptal" arasında güçlü bir zıtlık ilişkisi vardır ama benzer değildirler.
  - "Benzin" ile "araba" ilişkilidir ama benzer değildir.

### Derlem tabanlı yöntemler

- Denetimli (supervised): kelimelerin hangi anlamda kullanıldığını gösteren etiketli veri gerekir. Özellikler (birlikte geçtiği kelimeler, cümledeki yeri) etiketle birlikte verilir, model kurulur. En büyük sorun yeterli etiketli verinin olmamasıdır.
- Yarı denetimli (semi-supervised): az miktardaki etiketli veri boşa harcanmaz. Sistem azar azar öğretilir. Başarısı denetimli yöntem kadar yüksek olmaz.
- Denetimsiz (unsupervised): hiç etiketli veri yoktur. Bu problemde en düşük başarıyı verir.
- Denetimsiz yöntem örneği:
  - Etiketsiz dokümanlarda birden fazla anlamı olan kelimeler geçiyor.
  - Terim-doküman matrisi çıkarılır: her kelimenin her dokümanda kaç kez geçtiği.
  - Her kelime, doküman sayısı uzunluğunda bir vektörle temsil edilir.
  - Kelime vektörlerinin benzerlikleri ölçülür. Benzer vektörler aynı konudaki dokümanlarda geçiyor demektir.
  - Örnek: bir dokümanda hem "koyun" hem "yüz" geçiyorsa "koyun" hayvan, "yüz" deri yüzmek anlamındadır. Aynı konu aynı anlam ailesindeki kelimeleri içerir. "Koyunumla denize girdim" gibi bir şey olmaz.
  - Zahmetlidir ve her zaman iyi sonuç vermez. Bu yüzden denetimsiz çalışmalar azdır.

### Yöntemlerin karşılaştırılması

| Yöntem | Güçlü yan | Zayıf yan |
|---|---|---|
| Bilgi tabanlı | Doğruluk yüksektir, etiket bilgisi hazırdır. | Örtüşme bulunamayabilir. |
| Denetimli | Gerçekleştirme açısından diğerlerinden üstündür. | Büyük etiketli veri gerekir, kaynaklar kısıtlıdır. |
| Denetimsiz | Etiketli veri gerekmez. | Zordur ve başarısı düşüktür. |

### WordNet

- Bir dilin bütün kelimelerini, tanımlarını ve kelimeler arasındaki anlamsal ilişkileri içeren veri tabanıdır.
- İngilizce için ilk olarak Princeton Üniversitesi tarafından elle oluşturulmuştur. Bu çok meşakkatli bir süreçtir.
- Bugün 200'den fazla dili kapsar. İngilizce dışındaki diller için henüz tamamlanmamıştır.
- İlişkiler synset'ler (eşkümeler) arasında tanımlanır. Synset: bir kelime, o kelimenin bir anlamı ve o anlamın ilişkileri.
- Kullanım alanları: metin analizi, makine çevirisi, anlam belirsizliği giderme.
- Sözlükten farkı:
  - Sözlükte yalnızca kelimeler, anlamları ve örnek cümleler vardır.
  - WordNet'te isimler, fiiller ve sıfat-zarflar için ayrı ağlar vardır. Hiyerarşik bir yapıdadır.
  - İngilizce WordNet yaklaşık 117 bin synset üzerinde kurulmuştur.

### Üst kavram ve alt kavram

- Üst kavram: hypernym. Alt kavram: hyponym.
- Hiyerarşi örneği:

```
canlı
  hayvan
    memeli
      koyun
        karaman, merinos ...
      inek
      balina
      kedi
    memeli olmayan
  insan
  bitki
```

- "Hayvan", "canlı" teriminin altındadır. Kendi altında "kedi" vardır. "Kedi", "hayvan" kelimesinin hyponym'idir. "Canlı", "hayvan" kelimesinin hypernym'idir.
- Bir kelimenin üst kavramları, alt kavramları, eş anlamlıları, zıt anlamlıları ve parça-bütün ilişkileri birlikte tutulur.
- Mobilya örneği: furniture (mobilya) altında bed (yatak), onun altında bunk bed (ranza) gibi daha özel kavramlar vardır. Yatak da çocuk yatağı, hasta yatağı vb. diye ayrılabilir. Buradan mobilyanın ranza ve yatak içerdiği anlaşılır.

### Türkçe WordNet çalışmaları

- KeNet: en büyük Türkçe çalışmalardan biridir. Işık Üniversitesi'nde bir hoca ve ekibinin kurduğu Starlang Yazılım tarafından geliştirilmiştir (hoca şu an Özyeğin Üniversitesi'ndedir).
  - Açık kaynak ve ücretsizdir.
  - Yaklaşık 80 bin synset içerir. Hâlâ geliştirilmektedir.
- BalkaNet: Sabancı Üniversitesi'nin yürüttüğü bir projeydi. Şu an erişim yok gibi görünüyor. Önceden indirenler kullanıyor.

### WordNet'teki kelime ilişkileri

- Alt kavram (hyponymy): sözcükler aynı cins ve türden olma açısından benzerdir.
  - "Kuş", "hayvan" ve "canlı" üst kavramlarının alt kavramıdır.
  - "Bülbül", "serçe", "güvercin", "çalıkuşu" da "kuş" kelimesinin alt kavramlarıdır.
- Parça-bütün (meronymy) ve bütün-parça (holonymy):
  - Egzoz, motor, dişli, direksiyon, cam, benzin deposu, radyatör: hepsi arabanın parçasıdır. WordNet parçalardan bütünü (araba) ya da bütünden parçaları verir.
  - Üye-bütün: profesör ve doçent, fakültenin üyeleridir. WordNet bu ilişkiyi iki yönde de verir.
- Eş anlamlılık (synonymy): yazılışı ve okunuşu farklı, kavramsal içeriği aynı iki sözcük. Örnek: "yürek" ve "kalp", "ak" ve "beyaz".
- Eş dizimlilik (collocation): eş anlamlı kelimelerin birbirinin yerine kullanılmasını engeller.
  - "Anamın ak sütünü emdim" denir, "anamın beyaz sütünü" denmez.
  - "Kalpsiz adam" denir, "yüreksiz adam" aynı anlamda kullanılmaz.
  - "Beyaz tenli" denir, "ak tenli" denmez. "Alnım ak" denir, "alnım beyaz" denmez.
- Eş anlamlılığın dereceleri:
  - Tam eş anlamlılık: "üzüntü", "elem", "keder", "dert". Rahatça birbirinin yerine kullanılır.
  - Önermesel eş anlamlılık: bazen uyar bazen uymaz. "Ali kaplumbağayı gördü" ile "Ali tosbağayı gördü" aynıdır. Ama teknik bir yazıda ("araştırmacılar kaplumbağaları incelerken") "kaplumbağa" kullanılmalıdır.
  - Yarı eş anlamlılık: tamamen aynı değildir. "Sebebiyle" yerine "nedeniyle" koymadan önce düşünmek gerekir.
- Eş anlamlılığı etkileyen diğer durumlar:
  - Farklı lehçe ve ağızlar: Trakya'da "ayçiçeği", Ege'de "günebakan".
  - Olumsuz çağrışım: "adam" yerine "herif" daha argo ve olumsuzdur.
  - Duygusal yük: "devlet adamı" oturaklı ve ehil birini, "politikacı" bugün başka yarın başka konuşan birini çağrıştırır.
  - Belirli bağlamlar.
- WordNet yalnızca tam eş anlamlılık varsa bu bilgiyi verir.
- Zıt anlamlılık (antonymy): iki sözcüğün birbirine karşıt olması ("kısa-uzun", "güzel-çirkin"). Türleri:
  - Derecelendirilebilen: "uzun-kısa", "genç-yaşlı". Bir eşik vardır (örneğin 1,50 m altı kısa). Olumsuzu karşıtı vermez: "kısa değil" demek "uzun" demek değildir.
  - Derecelendirilemeyen: "ölü-canlı", "evli-bekâr". "Yüzde 70 yaşıyor" denemez. Olumsuz karşıtı verir: ölü değilse canlıdır, bekâr değilse evlidir.
  - Ters (yönsel) karşıtlık: "sağ-sol", "itmek-çekmek".
  - Bakışımlı karşıtlık: kişiden kişiye değişir. "Doktor-hasta". "Ahmet Ali'ye borç verdi" ile "Ali Ahmet'ten borç aldı" aynı olayı farklı bakış açılarından anlatır.
- Eş seslilik (hocanın kullandığı terim: homofoni): yazılışı ve okunuşu aynı, anlamı farklı kelimeler. Örnek: "yüz". WordNet hangi anlamın hangi türde olduğunu da verir (fiil ağı, isim ağı).
- Çok anlamlılık (polysemy): bir kelimenin temel anlamını genişleterek yeni kavramlar anlatması.
  - "Yüz" (insan yüzü) kelimesinden "yorgan yüzü".
  - "Baş": devletin başı (yönetici), satır başı (başlangıç), "Her şeyin başı sağlıktır" (temel), yokuşun başı (tepe), "üç baş soğan" (tane).
  - "Burun": yüzdeki organ ve coğrafyada denize doğru çıkıntı yapan kara parçası.
- Metafor (eğretileme): bir kavramı başka bir kavram üzerinden anlatmak.
  - "Borç içinde yüzmek": borç denize, miktarı denizin derinliğine benzetilir.
  - Öfke örnekleri: "kan beynine sıçramak", "içinde öfke biriktirmek", "öfke kusmak", "burnundan ateşler saçmak", "tepesinin tası atmak", "öfkeyle donmak".
  - Türkçeyi sonradan öğrenen biri bunları ancak toplumda yaşayarak anlar. Kelime kelime çevrilemez. Hocaya göre dildeki en zor çözümlenen yapılar metaforlardır.

### İngilizce WordNet sayıları ve ilişki türleri

- İsimler için, fiiller için ve sıfat-zarflar için ayrı WordNet'ler vardır.
- Hocanın verdiği sayılar: 117.097 isim ve toplam 145.104 anlam, 11.488 fiil ve yaklaşık 24 bin anlam. Sıfat ve zarfların sayıları da tabloda verildi.

| Tür | İlişki | Örnek |
|---|---|---|
| İsim | Hypernym (üst kavram) | breakfast → meal |
| İsim | Hyponym (alt kavram) | meal → lunch, breakfast, dinner |
| İsim | Has-member / Member-of | crew (ekip) ↔ copilot |
| İsim | Has-part / Part-of | table → leg (masa ayağı), drawer (çekmece) |
| İsim | Antonym | leader ↔ follower |
| Fiil | Troponym | walk → uygun adım yürümek, sekerek yürümek, koşar adım yürümek |
| Fiil | Entails | snore (horlamak) → sleep (uyumak) |
| Sıfat, zarf | Antonym | yalnızca zıtlık ilişkisi |

- Troponym bir eylemin nasıl yapıldığını gösteren çeşitleri verir.

### WordNet üzerinden anlamsal benzerlik

- Amaç: insanın deneyimle verdiği benzerlik puanını bilgisayara verdirmek.
- İki yaklaşım vardır:
  - Bağ sayma (edge counting): ağ bir ağaç gibi düşünülür. İki kelime arasında kaç bağdan geçildiği sayılır. Taksonomi derinliği de kullanılır (kökten en alttaki yaprağa kadar olan mesafe).
  - Bilgi içeriği (information content): taksonomi bilgisinin yanında derlemi de kullanır, örneğin kelimenin derlemdeki olasılığını. Hoca bunu "müşterek bilgi" olarak adlandırdı.

#### Leacock & Chodorow (1998)

$$sim_{LC}(c_1, c_2) = -\log \frac{len(c_1, c_2)}{2L}$$

- $len(c_1, c_2)$: iki synset arasındaki en kısa yolun uzunluğu. Benzerlikle ters orantılıdır.
- $L$: bütün taksonominin derinliği.
- WordNet bir graf olduğu için iki düğüm arasında birden fazla yol olabilir. En kısa yol alınır.

#### Wu & Palmer (1994)

$$sim_{WP}(c_1, c_2) = \frac{2 \times N_3}{N_1 + N_2 + 2 \times N_3}$$

- $N_1$, $N_2$: $c_1$ ve $c_2$ synset'lerinin en yakın ortak üst synset'e IS-A bağlarıyla uzaklıkları. Benzerlikle ters orantılıdır.
- $N_3$: en yakın ortak üst synset'in kök synset'e uzaklığı. Büyüklüğü, ortak synset'in ne kadar özel olduğunu gösterir.
- Derste çizilen iki örnek:
  - $c_1$ ve $c_2$ aynı ebeveynin çocukları: $N_1 = 1$, $N_2 = 1$, $N_3 = 1$. $sim = \frac{2}{1 + 1 + 2} = 0{,}5$.
  - Ortak üst synset kökün kendisi: $N_1 = 2$, $N_2 = 1$, $N_3 = 0$. $sim = \frac{0}{3} = 0$.

#### Jiang-Conrath (1997) ve Lin (1998)

$$sim_{JC}(c_1, c_2) = 2\log(p(lcs(c_1, c_2))) - (\log(p(c_1)) + \log(p(c_2)))$$

$$sim_{L}(c_1, c_2) = \frac{2 \log(p(lcs(c_1, c_2)))}{\log(p(c_1)) + \log(p(c_2))}$$

- $lcs(c_1, c_2)$: en yakın ortak üst synset.
- A kısmı ($2\log p(lcs)$): her iki kavramı da içeren en özel kavramı kullanır. İki kavramın birlikte geçtiği doküman sayısına benzer.
- B kısmı: iki kavramdan herhangi birini içeren doküman sayısına benzer.
- İki formül aynı parçaları kullanır. Jiang-Conrath farkı, Lin oranı alır.

#### Ölçütlerin karşılaştırılması

- Bütün yöntemler 38 İngilizce kelime çiftine uygulanmış. İnsanlara bu çiftler için 1-10 arası benzerlik puanı verdirilmiş. Yöntemlerin sonuçlarının insan yargılarıyla korelasyonu ölçülmüş.

| Yöntem | Tür | Korelasyon |
|---|---|---|
| Wu & Palmer 1994 | Edge Counting | 0,74 |
| Li 2003 | Edge Counting | 0,82 |
| Leacock & Chodorow 1998 | Edge Counting | 0,82 |
| Resnik 1999 | Info. Content | 0,79 |
| Lin 1998 | Info. Content | 0,82 |
| Lord 2003 | Info. Content | 0,79 |
| Jiang & Conrath 1998 | Info. Content | 0,83 |
| Tversky 1977 | Feature Based | 0,73 |
| Adapted Lesk 2002 | Feature Based | 0,37 |
| Rodriguez 2003 | Hybrid | 0,71 |

- En yüksek korelasyonlar Li, Leacock & Chodorow, Lin ve Jiang & Conrath ölçütlerindedir (0,80'in üzeri).
- Uygulama: "kitap", "defter", "kalem", "okul" kelimeleri birbirine çok yakınsa bunların birlikte geçtiği dokümanlar aynı konudan bahsediyor demektir. Dokümanlar bu bilgiyle sınıflandırılabilir.

### Ders sonu duyuruları

- Haftaya vize haftası. Hoca lisans derslerine vize yapacak, bu derse vize yapmayacak.
- Vize tarihi ve seminer takvimi hafta sonuna kadar mail ile bildirilecek.
- Vize haftasında da ders yapılacak. Zoom'da sorun çıkarsa hoca kendi hesabından Zoom açacak. Ders grubu üzerinden haberleşilecek.
- Proje teslimi:
  - Final tarihine kadar süre var.
  - Final haftasında projeler gösterilecek. Final saati yetmezse akşam saatlerinde devam edilecek.
  - Final sınavı yerine proje gösterilecek ve projeyi anlatan bir doküman sınav evrakı olarak teslim edilecek.
- Seminer:
  - Seçilen makaleyle ilgili uygulama geliştirilmeyecek.
  - PowerPoint sunumu en fazla 15 dakika olacak. Süre kesinlikle aşılmamalı.
  - Anlatılacaklar: makalenin amacı, yazarların ne yaptığı, ne kullandığı, nasıl sonuç aldığı.
  - Bunu anlatan bir Word dokümanı seminer evrakı olarak teslim edilecek. Hoca dokümanı okuyunca makalenin ne yaptığını anlayabilmeli.
  - Proje konusuyla ilgili makale seçmek işi kolaylaştırır. Uygun makale yoksa başka konu seçilebilir.
- Regex ödevleri henüz değerlendirilmedi. Hoca en kısa zamanda sonuçları göndereceğini söyledi.

### Ders sonrası notlar

- Slayttaki $sim_{JC}$ formülü adına rağmen bir uzaklık verir. Aynı kavram için 0 çıkar, kavramlar uzaklaştıkça büyür. Jiang-Conrath benzerliği genelde bu değerin tersi ($1/dist_{JC}$) olarak kullanılır.
- Add-one örneğindeki tutarsızlık: slayttaki sayım tablosunda "gibi eve" ve "eve gidiyorum" ikilileri 1, "gibi gidiyorum" ikilisi 0 görünüyor. Yani tablo "Bugün de her zamanki gibi eve gidiyorum" cümlesinden (6 ikili) çıkarılmış gibi duruyor. Bu tabloya göre $P_{\text{gibi gidiyorum}}$ yumuşatmasız 0, add-one ile $\frac{0+1}{N+49}$ olmalıdır. Slayttaki $\frac{1}{5}$ ve $\frac{2}{54}$ değerleri ise "gibi gidiyorum" ikilisi 1 kez geçmiş gibi hesaplanmış. Öğrencinin "eve" itirazı bu yüzden yerindeydi. Sınavda bu tür bir soruda sayım tablosu ile hesaplanan cümlenin tutarlı olup olmadığına dikkat edin.
- Hoca üniversite hiyerarşisini önce doğru anlattı: fakültenin üst kavramı rektörlük, bölümün üst kavramı fakültedir. Sonra "fakültenin hypernym'i bölümdür" dedi. Doğrusu: bölüm, fakültenin hyponym'idir. Ayrıca rektörlük-fakülte-bölüm ilişkisi WordNet açısından aslında bir parça-bütün (meronymy) ilişkisine daha yakındır.
- Hoca "Hypername tam tersi olabilir. Meal'ın altları..." derken hyponym ilişkisini kastediyor.
- Altyazıda çok anlamlılık için "eş anlamlılık" kelimesi geçiyor. Polysemy'nin Türkçesi "çok anlamlılık"tır.
- Altyazıda eş anlamlılık tanımında "halponim" geçiyor. Doğru terim synonym'dir.
- Hoca entailment ilişkisini troponym'in "tam tersi" olarak anlattı. WordNet'te entailment, bir eylemin başka bir eylemi gerektirmesidir: horlamak (snore) uyumayı (sleep) gerektirir.
- Hoca NLTK için "Stanford Üniversitesi'nin hazırladığı" dedi. NLTK, Pennsylvania Üniversitesi'nde geliştirilmiştir. Stanford'un ayrı araç seti Stanford CoreNLP'dir.
- Hoca korelasyon tablosunu "100 çiftin 80'ine yakınında bilgisayar ile insan aynı benzerliği vermiş" diye yorumladı. 0,82 bir korelasyon katsayısıdır, doğru tahmin edilen çiftlerin oranı değildir. Yöntemin puanlarının insan puanlarıyla güçlü biçimde birlikte değiştiğini gösterir.
- Altyazıda "Advanced smoothing" ve "Erdogan smoothing" geçen yerler "add-one smoothing", "good touring" geçen yerler "Good-Turing", "KeyNet" geçen yer "KeNet", "Lee Kock ve Shadorov" geçen yer "Leacock & Chodorow", "Hu Palmer" geçen yer "Wu & Palmer", "Jean-Condrat" geçen yer "Jiang-Conrath" olmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
