# Ders 4 Çalışma Özeti

## Genel Konular

- NFA'nın DFA'dan farklarının kısa tekrarı
  - NFA'da bir durum aynı sembolle birden fazla duruma geçebilir; otomat kendini çoğaltır ve paralel hesaplama dalları oluşur. Dallardan birinin kabul etmesi yeterlidir.
  - $\varepsilon$ (null) geçişi hiçbir sembol okumadan durumu değiştirir; kaynak durum da etkin kalır.
  - NFA'da her durum için her sembolün geçişini çizmek gerekmez. Çizilmeyen sembol gelirse o dal durur (ölür). DFA'da ise her durum için her sembolün geçişi gösterilmelidir.
  - NFA'nın geçiş fonksiyonunun sonucu bir durum kümesidir.
- Makinelerin denkliği (equivalence)
  - $M_1$ ile $M_2$ denktir ancak ve ancak $L(M_1) = L(M_2)$. Örnekte bir NFA ile bir DFA aynı $\{10\}^*$ dilini kabul ettiği için denktir.
- Teorem: NFA'ların kabul ettiği diller kümesi = düzenli diller kümesi (DFA'ların kabul ettiği diller) (ekrandan, 00:25:00)
  - NFA ve DFA aynı hesaplama gücüne sahiptir. NFA çizimi kolaylaştırır ama ek güç vermez; DFA için bir tür kısayoldur (syntactic sugar).
  - İspat iki kapsama ile yapılır. Adım 1 (düzenli diller ⊆ NFA dilleri) önemsizdir: her DFA zaten bir NFA'dır. Adım 2 (NFA dilleri ⊆ düzenli diller) için her NFA'nın denk bir DFA'ya çevrilebildiği gösterilir (ekrandan, 00:30:00).
- NFA'dan DFA'ya dönüşüm (alt küme yapısı)
  - DFA durumlarının etiketleri NFA durumlarının kümeleridir (kuvvet kümesinden). Başlangıç durumu $q_0$'ı içeren kümedir.
  - Her DFA durumu $\{q_i, q_j, \dots, q_m\}$ ve her sembol $a$ için NFA'da $\delta^*(q_i,a) \cup \delta^*(q_j,a) \cup \dots \cup \delta^*(q_m,a)$ hesaplanır ve $\delta(\{q_i,\dots,q_m\}, a)$ bu birleşim olur (ekrandan, 00:50:00). Etiket grafikte yoksa yeni durum eklenir.
  - Hiçbir yere gidilmiyorsa sonuç $\varnothing$ etiketli tuzak durumdur; her sembolde kendine döner ve kabul etmez.
  - Yeni durum çıkmayana kadar tekrarlanır. Sonunda NFA'nın bir kabul durumunu içeren her DFA durumu kabul durumu yapılır.
- Dönüşümün doğruluğunun ispatı
  - $L(M) \subseteq L(M')$ dizgi uzunluğu $|v|$ üzerinde tümevarımla gösterilir: NFA'da $v$ ile $q_0$'dan $q_d$'ye gidilebiliyorsa, DFA'da $v$ ile $q_d$'yi içeren bir duruma gidilir. Taban ($|v|=1$) ve adım ($|v|=k+1$, $v = v' a_{k+1}$) DFA'nın kuruluşu gereği doğrudur (ekrandan, 01:15:00 ve 01:20:00).
  - NFA yolundaki kesikli oklar, sembolden önce ve sonra $\varepsilon$ geçişleri olabileceğini gösterir (ekrandan, 01:10:00).
  - Ters kapsama ($L(M') \subseteq L(M)$) aynı yolla yapılır, derste atlandı.
- Düzenli dillerin kapalılık özellikleri
  - $L_1$ ve $L_2$ düzenliyse birleşim $L_1 \cup L_2$, birleştirme $L_1 L_2$, yıldız $L_1^*$, ters $L_1^R$, tümleyen $\overline{L_1}$ ve kesişim $L_1 \cap L_2$ de düzenlidir. Düzenli diller bu işlemler altında kapalıdır.
  - İspat yöntemi kuruluşla ispattır: sonuç dilini kabul eden bir NFA kurulur; NFA varsa dil düzenlidir.
- Yararlı dönüşüm: tek kabul durumu
  - Birden fazla kabul durumu olan NFA'da eski kabul durumları kabul olmayan yapılır, yeni tek bir kabul durumu eklenir ve eski kabul durumlarından ona $\varepsilon$ geçişleri çizilir (ekrandan, 01:35:00). Hiç kabul durumu yoksa yeni kabul durumu eklenir ama ona geçiş çizilmez.
- Kapalılık kuruluşları
  - Birleşim: yeni başlangıç durumundan $M_1$ ve $M_2$'nin başlangıçlarına $\varepsilon$ geçişi (ekrandan, 01:40:00).
  - Birleştirme: $M_1$'in kabul durumu sıradan duruma çevrilir, ondan $M_2$'nin başlangıcına $\varepsilon$ geçişi eklenir (ekrandan, 01:50:00).
  - Yıldız: yeni bir durum hem başlangıç hem kabul durumu olur, ondan eski başlangıca $\varepsilon$, eski kabul durumundan (artık kabul değil) yeni duruma $\varepsilon$ geçişi eklenir (ekrandan, 02:10:00).
  - Ters: bütün geçişlerin yönü ters çevrilir, başlangıç durumu kabul, kabul durumu başlangıç yapılır (ekrandan, 02:15:00).
  - Tümleyen: bir **DFA**'da kabul durumları kabul olmayan, kabul olmayanlar kabul yapılır. $\overline{L} = \Sigma^* - L$ (ekrandan, 02:20:00).
  - Kesişim: De Morgan kuralı $L_1 \cap L_2 = \overline{\overline{L_1} \cup \overline{L_2}}$ ile önceki özelliklerden çıkar (ekrandan, 02:25:00). İkinci yol: iki DFA'yı paralel çalıştıran çarpım DFA'sı.
- Kesişim için çarpım DFA'sı
  - Her $q_i \in M_1$ ve $p_j \in M_2$ için $(q_i, p_j)$ durumu; $q_1 \xrightarrow{a} q_2$ ve $p_1 \xrightarrow{a} p_2$ ise $(q_1,p_1) \xrightarrow{a} (q_2,p_2)$. Başlangıç $(q_0, p_0)$. Kabul durumları her iki bileşeni de kabul olan çiftlerdir.
  - Kuruluş: başlangıç durumunu kur; her yeni durum ve her sembol için var olan bir duruma ya da yeni bir duruma geçiş ekle; yeni durum kalmayana kadar tekrarla; kabul durumlarını belirle (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- NFA'yı DFA'ya çevirme prosedürü önemlidir
  - Sınavlarda bir NFA'yı DFA'ya çevirme ya da bir DFA'nın bir NFA'ya denk olup olmadığı sorulur. Sipser'in kitabındaki ve paylaşılan alıştırmalar çalışılmalıdır.
- Tümleyen yalnız DFA ile alınır
  - Kabul ve kabul olmayan durumları yer değiştirme yöntemi NFA'da yanlış sonuç verir. Örnek: tek, kabul olmayan durumlu ve hiç geçişi olmayan NFA'nın dili $\{\}$, tümleyeni $\{a,b\}^*$'dır; ama durumu kabul yapınca elde edilen NFA yalnız $\{\varepsilon\}$'u kabul eder. Önce DFA'ya çevirmek gerekir.
- Kesişim DFA'sında kabul durumları
  - Yalnız her iki bileşeni de kabul olan çiftler kabul durumudur; içinde yalnız birinin kabul durumu geçen çiftler kabul değildir.
- İki otomatın kesişimini (ya da iki dilin kesişimini kabul eden otomatı) bulma sorusu gelebilir; basit örneklerde DFA doğrudan yazılabilir ama genel durumda prosedür gerekir.

## Kısa Tekrar Notları

- Denk makineler: aynı dili kabul eden makineler.
- NFA dilleri = DFA dilleri = düzenli diller.
- Alt küme yapısı: DFA durumu = NFA durum kümesi; geçiş = üyelerin $\delta^*$ sonuçlarının birleşimi; $\varnothing$ = tuzak; NFA kabul durumu içeren küme = kabul.
- Örnek dönüşüm sonucu: $\{q_0\} \xrightarrow{a} \{q_1,q_2\}$, $\{q_0\} \xrightarrow{b} \varnothing$, $\{q_1,q_2\} \xrightarrow{a} \{q_1,q_2\}$, $\{q_1,q_2\} \xrightarrow{b} \{q_0\}$; kabul durumu $\{q_1,q_2\}$.
- Dönüşümün doğruluğu $|v|$ üzerinde tümevarımla ispatlanır.
- Kapalılık: birleşim, birleştirme, yıldız, ters, tümleyen, kesişim.
- Birleşim paralel bağlama, birleştirme seri bağlama ($\varepsilon$ ile).
- Tümleyen için DFA şart.
- Kesişim: De Morgan ya da çarpım DFA'sı; $\{a^n b\} \cap \{ab^m\} = \{ab\}$.

## Detaylı Açıklamalar

- NFA–DFA denkliği. Düzenli diller önceki derste DFA'ların kabul ettiği diller olarak tanımlanmıştı. Bu derste NFA'ların kabul ettiği dillerin kümesinin de tam olarak düzenli diller olduğu ispatlandı. Kümelerin eşitliği için iki yönlü kapsama gerekir. Her DFA, NFA gösteriminin bir alt kümesini kullandığından zaten bir NFA'dır; bu yüzden her düzenli dil bir NFA tarafından da kabul edilir. Diğer yön için bir dönüşüm prosedürü verilir ve dönüşümün dili koruduğu gösterilir. Sonuç: NFA'lar hesaplama gücü katmaz, yalnız çizimi kolaylaştırır. Problemler küme üyeliği olarak (örneğin toplama işleminin geçerliliği, "toplama dili"ne üyelik olarak) ifade edildiği için, bu iki modelin çözebildiği problemler aynıdır.
- Dönüşüm örneği (ekrandan, 00:35:00 ve 00:40:00). NFA $M$: $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_1$, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$; kabul durumu $q_1$. $q_0$'ın $b$ geçişi yoktur ve bir $\varepsilon$ geçişi vardır, bu yüzden NFA'dır. DFA'nın başlangıcı $\{q_0\}$'dır. $q_0$ $a$ okuyunca $q_1$'e gider; $\varepsilon$ geçişi yüzünden $q_2$ de etkin olur, yani $\{q_1,q_2\}$. $q_0$ $b$ okuyamaz, bu yüzden $b$ tuzak durum $\varnothing$'ye gider. $\{q_1,q_2\}$ için $a$: $\delta^*(q_1,a) = \{q_1,q_2\}$, $\delta^*(q_2,a) = \varnothing$, birleşim $\{q_1,q_2\}$ (kendine döngü). $b$: $\delta^*(q_2,b) = \{q_0\}$, birleşim $\{q_0\}$. Tuzak durum her iki sembolde kendine döner. $q_1$'i içerdiği için $\{q_1,q_2\}$ kabul durumudur. Python ile 8 uzunluğa kadar bütün dizgilerde iki otomatın aynı kararı verdiği kontrol edildi.
- Hoca bu adımda slayttaki hesabın hatalı olduğunu düşünerek slayta $\delta^*(q_1,b) = \varnothing$ satırını ekledi <!-- BELİRSİZ: slaytın düzeltmeden önceki satırı karede görünmüyor -->. Hocanın bakışı, $\varepsilon$ geçişinden sonra $q_1$ ve $q_2$'yi ayrılmış iki makine gibi düşünmektir: $q_1$ $b$ okuyamaz, $q_2$ okur. Bir öğrenci $q_1$'deyken $b$ gelince $q_0$'a geçilmez mi diye sordu; hoca bu bakışın da mümkün olduğunu söyledi. Birleşim sonucu iki yaklaşımda da $\{q_0\}$'dır.
  - Ders sonrası not: Slaytlardaki $\delta^*$ tanımı yoldaki $\varepsilon$ geçişlerini de içerir (01:10:00 karesindeki kesikli ok açıklaması). Bu tanımla $q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{b} q_0$ yolu olduğundan $\delta^*(q_1,b) = \{q_0\}$'dır; öğrencinin bakışı büyük olasılıkla slayt tanımına daha uygundur. Sonuç DFA değişmez.
- Kapalılık kuruluşları. Örneklerde $L_1 = \{a^n b : n \ge 0\}$ (başlangıçta $a$ döngüsü, $b$ ile kabul durumuna) ve $L_2 = \{ba\}$ kullanıldı. Birleşim NFA'sı $aab$'yi kabul eder: başta $\varepsilon$ geçişleriyle iki dal etkinleşir, alt dal ilk $a$'da ölür, üst dal $a, a$ ile döngüde kalıp $b$ ile kabul durumuna varır. Birleştirme NFA'sı $aabba$'yı kabul eder: $aab$ $M_1$'in eski kabul durumuna getirir, $\varepsilon$ ile $M_2$'nin başına geçilir, $ba$ ile kabul durumuna varılır. Yıldız NFA'sı $abaab = ab \cdot aab$'yi kabul eder: her $b$'den sonra $\varepsilon$ geçişleriyle üç durum birden etkin olur ve girdi bittiğinde etkin durumlardan biri kabul durumudur. Ters için $L_1^R = \{b a^n\}$ elde edilir.
- Tümleyen örneği (ekrandan, 02:20:00). $L_1 = \{a^n b\}$ için DFA: başlangıç ($a$ döngüsü), $b$ ile kabul durumu, oradan $a,b$ ile tuzak durum. Tümleyen DFA'sında başlangıç ve tuzak durum kabul, ortadaki durum kabul olmayan olur. Dil $\overline{L_1} = \{a,b\}^* - \{a^n b\}$'dir.
- Kesişim örneği (ekrandan, 02:30:00 ve 02:35:00). $L_1 = \{a^n b\}$ için $M_1$: $q_0 \xrightarrow{a} q_0$, $q_0 \xrightarrow{b} q_1$ (kabul), $q_1 \xrightarrow{a,b} q_2$, $q_2$ tuzak. $L_2 = \{ab^m : m \ge 0\}$ için $M_2$: $p_0 \xrightarrow{a} p_1$ (kabul), $p_0 \xrightarrow{b} p_2$, $p_1 \xrightarrow{b} p_1$, $p_1 \xrightarrow{a} p_2$, $p_2$ tuzak. Çarpım DFA'sının geçişleri:

  | Durum | $a$ | $b$ |
  |---|---|---|
  | $\to (q_0,p_0)$ | $(q_0,p_1)$ | $(q_1,p_2)$ |
  | $(q_0,p_1)$ | $(q_0,p_2)$ | $(q_1,p_1)$ |
  | $(q_1,p_1)$ (kabul) | $(q_2,p_2)$ | $(q_2,p_1)$ |
  | $(q_1,p_2)$ | $(q_2,p_2)$ | $(q_2,p_2)$ |
  | $(q_0,p_2)$ | $(q_0,p_2)$ | $(q_1,p_2)$ |
  | $(q_2,p_1)$ | $(q_2,p_2)$ | $(q_2,p_1)$ |
  | $(q_2,p_2)$ | $(q_2,p_2)$ | $(q_2,p_2)$ |

  Tek kabul durumu $(q_1,p_1)$'dir ve dil $\{ab\}$'dir. Tablo python ile kuruldu ve 6 uzunluğa kadar yalnız $ab$'nin kabul edildiği doğrulandı. Hoca, bu basit örnekte $\{ab\}$ için DFA'nın doğrudan da yazılabileceğini belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
