# Ders 7 Çalışma Özeti

## Genel Konular

- Doğrultucuların kısa tekrarı
  - Yarım dalga doğrultucu sinüsün yalnız pozitif yarı periyodunu geçirir. Çıkışın ortalama (DC) değeri tepe geriliminin yaklaşık 0,318 katıdır ($V_{dc} = 0{,}318\,V_m$).
  - Köprü tipi ve transformatörlü tam dalga doğrultucuda negatif yarı periyot da ters çevrilir; DC değer $0{,}636\,V_m$ olur.
  - Bu değerler ideal diyot içindir. Silisyum diyotun 0,7 V'luk iletim gerilimi hesaba katılırsa yarım dalgada bir kez 0,7 V, köprüde akım iki diyottan geçtiği için $2 \times 0{,}7$ V düşülür.
- Seri diyot kırpıcı (series clipper)
  - Diyot kaynağa seri, çıkış ise diyottan sonraki dirençten alınır (ekrandan, 00:10:00). Slayttaki tanım: seri kırpıcı, diyotu ileri kutuplamayan her gerilimi keser; yani ters kutuplayan gerilimi ve silisyum diyot için 0,7 V'tan küçük ileri gerilimi.
  - Giriş yalnız sinüs olmak zorunda değildir; kare dalga ve üçgen dalga da AC giriş sayılır (ekrandan, 00:10:00).
  - İdeal diyotla pozitif yarı periyotta diyot kısa devre olur, $v_o = v_i$; negatif yarı periyotta açık devre olur, $v_o = 0$. Davranış yarım dalga doğrultucuyla aynıdır.
  - "$\pm v_i$" ile gösterilen giriş, aslında bir ucu toprağa bağlı bir kaynaktır; $v_o$ da çıkış düğümünün toprağa göre gerilimidir.
- DC kaynaklı (biased) seri kırpıcı
  - Diyota seri bir DC kaynak eklenince diyotun etkin ileri kutuplaması değişir (ekrandan, 00:15:00). Örnekte $V = 5$ V'luk kaynak girişe eklenir, giriş 20 V tepe değerli sinüstür.
  - Diyot iletimdeyken $v_o = v_i + 5$ V olur: $v_i = 0$ iken 5 V, $v_i = 20$ V iken 25 V, $v_i = -1$ V iken 4 V.
  - Geçiş gerilimi $v_i = -5$ V'tur; burada $v_o = -5 + 5 = 0$ V. Girişin −5 V'un altında kaldığı aralıkta diyot açık devredir, $v_o = 0$ (ekrandan, 00:30:00).
  - Sonuç: seri DC kaynak çıkışı yukarı doğru öteliyormuş gibi davranır.
- Paralel kırpıcı (parallel clipper)
  - Direnç kaynağa seri, diyot çıkışa paralel bağlıdır. Paralel kırpıcı, diyotu ileri kutuplayan gerilimi keser (ekrandan, 00:40:00).
  - Diyot iletimdeyken uçları kısa devre olur: $V_D = V_B - V_T = 0$, dolayısıyla $v_o = 0$.
  - Diyot kesimdeyken dirençten akım akmaz. Akım $I = (V_A - V_B)/R = V_R/R$ olduğundan $I = 0$ ise $V_B = V_A$, yani $v_o = v_i$ olur.
  - Seriye eklenen DC kaynak kırpma seviyesini değiştirir.
- Kırpıcı özet tabloları
  - Slaytlarda basit ve DC kaynaklı seri kırpıcılar (pozitif, negatif) ile basit ve DC kaynaklı paralel kırpıcılar, giriş ve çıkış dalga şekilleriyle listelenir (ekrandan, 00:45:00 ve 01:30:00). Örnek çıkışlar: $-(V_m+V)$, $(V_m-V)$, $(V_m+V)$ tepeli dalgalar, $V$ ya da $-V$ seviyesinde kırpılmış sinüsler, iki diyot ve iki kaynakla iki seviyede ($V_1$, $-V_2$) kırpma.
- Derste çözülen örnekler
  - Seri kırpıcı, ters bağlı −5 V'luk kaynak ve ters bağlı diyot, giriş ±10 V sinüs (ekrandan, 00:55:00 ve 01:15:00): $v_o = v_i - 5$ V (girişin 5 V'tan küçük olduğu yerlerde), girişin 5 V'u aştığı aralıkta $v_o = 0$. En alt değer $-15$ V.
  - Paralel kırpıcı, katodu çıkışa bakan diyot ve ters bağlı 3 V'luk kaynak, giriş ±10 V sinüs (ekrandan, 01:25:00): $v_o$ girişi takip eder, girişin −3 V'un altına indiği yerlerde −3 V'ta sabit kalır.
- Kenetleyici (clamper) devreler
  - Clamp, masaya bir parçayı sıkıştıran kıskaç anlamındadır. Kenetleyicide kapasitör kullanılır; kapasitör diyot iletirken dolar, iletmezken yükünü korur ya da yavaşça boşaltır.
  - Kare dalga ($\pm V$) girişli temel örnekte pozitif yarıda diyot iletir, $v_o = 0$; negatif yarıda çıkış $-2V$ olur (ekrandan, 01:35:00). Kapasitör yeterince büyükse çıkış düz görünür; gerçekte yavaşça azalır.
  - Özet slaytında diyot yönü ve seri DC kaynakla ($V_1$) çıkışın $2V$ genlikli kare dalga olarak farklı seviyelere kenetlendiği altı devre vardır (ekrandan, 01:35:00).
- Zener diyot devreleri
  - Zener diyot devreye ters bağlanır. Uçlarındaki gerilim $V_Z$'den küçükse "off" durumundadır ve açık devre gibi davranır. $V_Z$'ye ulaşınca "on" olur ve uçlarında $V_Z$ değerinde bir gerilim kaynağı gibi sabit gerilim tutar (ekrandan, 01:45:00).
  - Slayttaki bağıntılar: on durumunda $V_L = V_Z$, $I_Z = I_R - I_{R_L}$, Zener gücü $P_Z = V_Z I_Z$; $P_{ZM}$ en büyük güç sınırıdır (ekrandan, 01:45:00).
  - Örnek: $V_Z = 5$ V. Girişe 1 V uygulanırsa Zener off olur ve yüke en fazla 1 V gelir. Girişe 10, 20 ya da 30 V uygulanırsa yükte yine 5 V kalır; 30 V'ta seri dirence 25 V düşer. Zener, paralel bağlı yükü aşırı gerilime karşı korur.
- Gerilim çoklayıcılar
  - Gerilim ikileyici, üçleyici ve dörtleyici devreler slaytlarda vardır, ancak derste ayrıntısına girilmedi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kırpıcı çıkışını adım adım çizmek
  - Hoca çıkış dalga şeklini nokta nokta kurdu: önce $v_i = 0$ anı, sonra tepe (ekstremum) noktaları, sonra diyotun iletimden kesime geçtiği geçiş gerilimi. Her aralıkta diyot kısa devre ya da açık devre olarak yerine konur.
  - Bu tür "giriş verilir, çıkışı çizin" sorularının sınavlarda geleceğini birkaç kez söyledi; ödevde verilen ±10 V, −5 V'luk örneğin daha önce sınavda sorulduğunu belirtti.
- Diyotun hangi durumda ilettiği
  - Diyot, anot ucunun gerilimi katot ucundan yüksekse iletir. Hoca bunu "diyotun eksi ucu artı ucuna göre daha düşük potansiyelde ise iletimdedir" diye ifade etti. Ters bağlı pil ve ters bağlı diyotta da aynı karşılaştırma yapılır.
- Akım akmayan dirençte gerilim düşmez
  - Paralel kırpıcıda diyot kesimdeyken çıkışın neden girişi takip ettiği bir öğrenci sorusuyla açıklandı: ucu boşta olan bir dirençten akım akmaz, uçları arasında gerilim farkı olmaz, çıkış girişe eşittir.
- Zener koruma elemanıdır
  - Giriş ne kadar artarsa artsın Zener'e paralel yüke en fazla $V_Z$ gelir; fazlası seri dirence düşer.
- Simülasyonla doğrulama
  - Kırpıcı ve kenetleyici devreleri simülasyon programında sinüs ve kare dalga girişle kurup osiloskopla giriş ve çıkışı birlikte göstermek, sonucu mantıkla açıklamak istendi.

## Kısa Tekrar Notları

- Yarım dalga: $V_{dc} = 0{,}318\,V_m$; tam dalga ve köprü: $V_{dc} = 0{,}636\,V_m$. Gerçek diyotta Si için 0,7 V, köprüde 1,4 V düşülür.
- Seri kırpıcı: diyot ileri kutuplanmayan gerilimi keser. İdeal diyotta çıkış yarım dalga doğrultucu gibidir.
- Seri kırpıcıya DC kaynak eklenirse çıkış ötelenir: $V = 5$ V, $V_m = 20$ V örneğinde iletimde $v_o = v_i + 5$ V, tepe 25 V, $v_i < -5$ V iken $v_o = 0$.
- Paralel kırpıcı: diyot ileri kutuplanınca $v_o = 0$ (ya da seri kaynağın değeri); kesimde $v_o = v_i$.
- Diyot kesimde ise dirençten akım akmaz, $V_A = V_B$.
- Geçiş gerilimi: diyotun iletim ile kesim arasında geçtiği giriş değeri. Çizimde bu nokta mutlaka bulunur.
- Kenetleyici: kapasitör + diyot. Kare dalga girişte çıkış şekli korunur, seviye kayar ($0$ ile $-2V$ arası gibi).
- Zener: $V < V_Z$ off (açık devre), $V \ge V_Z$ on; on durumunda $V_L = V_Z$, $I_Z = I_R - I_{R_L}$, $P_Z = V_Z I_Z$.

## Detaylı Açıklamalar

- Ders, yarım dalga ve tam dalga doğrultucuların hatırlatılmasıyla başladı. Doğrultulmuş işaretin DC seviyesi, dalga altında kalan alanın periyoda bölünmesiyle bulunur. İdeal diyotla yarım dalgada $0{,}318\,V_m$, tam dalgada $0{,}636\,V_m$ çıkar. Silisyum diyotun 0,7 V'luk iletim gerilimi hesaba katılınca köprü doğrultucuda akımın iki diyottan geçtiği unutulmamalıdır.
- Seri kırpıcıda diyot ideal kabul edildi: sıfırın altında iletmez, sıfırı epsilon kadar geçince kısa devre olur. Pozitif yarı periyotta (0 ile $T/2$ arası) diyot kısa devre olduğu için giriş aynen çıkışta görünür. Negatif yarı periyotta diyot açık devredir, dirençten akım akmaz ve çıkış 0'dır. Kare dalga girişte çıkış yalnız pozitif kısımdan, üçgen dalga girişte yalnız pozitif üçgenden oluşur (ekrandan, 00:10:00).
- DC kaynaklı seri kırpıcı örneğinde giriş ile diyot arasına artı ucu diyota bakan 5 V'luk bir pil eklenmiştir (ekrandan, 00:15:00). Hoca A (giriş), B (pil ile diyot arası) ve C (çıkış) noktalarını tanımladı. $t = 0$'da A noktası 0 V, B noktası 5 V'tur; diyot iletir ve çıkış 5 V olur. Giriş 20 V'a çıkarken çıkış her an 5 V fazlasıdır, tepe 25 V'tur. Giriş negatife geçtiğinde de diyot bir süre iletmeye devam eder: −1 V girişte çıkış 4 V'tur. Giriş −5 V'a geldiğinde B noktası 0 V olur, çıkış 0'a iner. Girişin −5 V'un altında kaldığı aralıkta (−6 V'tan −20 V'a kadar) diyot açık devredir, çıkış 0'dır. Giriş tekrar −5 V'u geçince diyot iletir ve çıkış girişi 5 V fazlasıyla izler (ekrandan, 00:30:00). Slayttaki ifadeler: $v_o = v_i + 5 = 25$ V, $v_o = 0 + 5 = 5$ V, $v_o = -5 + 5 = 0$ V.
- Paralel kırpıcıda giriş A noktasından uygulanır, direnç A ile B arasındadır, diyot B ile toprak (T) arasındadır. Pozitif yarıda diyot iletir; uçları kısa devre olduğu için $V_D = V_B - V_T = 0$ ve çıkış sıfırdır. Negatif yarıda B noktası topraktan düşük kalır, diyot açık devredir, dirençten akım akmaz ve çıkış girişi aynen izler. Kare dalga ve üçgen dalga için çıkış yalnız negatif kısımdır (ekrandan, 00:40:00).
- Hocanın tahtada çözdüğü ilk örnek (sınavda daha önce sorulduğunu söyledi) bir seri kırpıcıdır: girişte ±10 V sinüs, ardından ters bağlı −5 V'luk kaynak ve katodu girişe bakan bir diyot, çıkış direnç üzerinden alınır (ekrandan, 00:55:00). $v_i = 0$ iken diyotun giriş tarafı −5 V'tadır, diyot iletir ve çıkış −5 V olur. Giriş 1, 2, 3 V oldukça çıkış −4, −3, −2 V olur; giriş 5 V'a ulaşınca çıkış 0'a gelir. Giriş 5 V'un üzerindeyken diyot kesimdedir, çıkış 0'dır. Giriş tekrar 5 V'un altına inince diyot iletir ve çıkış $v_i - 5$ olarak azalır; $v_i = -10$ V iken çıkış −15 V olur (ekrandan, 01:15:00). Bu sonuç özet slaytındaki DC kaynaklı seri kırpıcının $-(V_m + V)$ tepeli çıkışıyla aynıdır (ekrandan, 00:45:00).
- İkinci örnek DC kaynaklı bir paralel kırpıcıdır: diyotun katodu çıkışa, anodu ters bağlı (kısa ucu yukarıda) $V = 3$ V'luk kaynağa bağlıdır, giriş ±10 V sinüstür (ekrandan, 01:25:00). Anot −3 V'ta kaldığından çıkış −3 V'un üzerindeyken diyot kesimdedir ve çıkış girişi izler. Giriş −3 V'un biraz altına (örneğin −3,001 V) inince diyot iletir ve çıkış −3 V'ta sabit kalır. Hoca çizimin ilk hâlinde pozitif yarı periyotta çıkışı yanlışlıkla 0 çizdi, sonra düzeltti (01:29:58).
- Kenetleyicilerde kapasitör, diyot iletimdeyken dolar ve diyot kesimdeyken yükünü tutar. Kare dalga girişli temel devrede pozitif yarıda diyot kısa devre olduğu için çıkış 0'dır; negatif yarıda kapasitördeki gerilim girişle toplanır ve çıkış $-2V$ olur. Bu ideal bir gösterimdir; gerçekte kapasitör yavaşça boşaldığı için çıkış düz kalmaz, kapasitör çok büyükse düz kabul edilir (ekrandan, 01:35:00).
- Zener diyotlarda katkı malzemeleriyle kırılma gerilimi $V_Z$ istenen değere kaydırılır ve diyot ters bağlanarak kullanılır. $V_Z = 5$ V'luk bir Zener 5 V'tan küçük gerilimde açık devredir. Gerilim 5 V'u aşınca Zener iletir ve uçlarında 5 V'luk bir kaynak gibi davranır. Yük direnci ($R_L$) Zener'e paralel olduğu için yükün gerilimi de 5 V'ta kalır; giriş 30 V olsa bile 25 V seri dirence düşer (ekrandan, 01:45:00).
  <!-- BELİRSİZ: 01:45:18 civarında altyazıda "transistörün iki tane durumu" geçiyor; bağlamdan Zener'in iki durumu (on/off) kastedildiği anlaşılıyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
