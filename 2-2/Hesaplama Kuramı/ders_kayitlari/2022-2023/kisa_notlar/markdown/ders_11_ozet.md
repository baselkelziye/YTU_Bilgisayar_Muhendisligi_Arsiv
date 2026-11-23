# Ders 11 Çalışma Özeti

## Genel Konular

- Bağlamdan bağımsız diller için pompalama önsavının tekrarı
  - Sonsuz bir bağlamdan bağımsız dil $L$ için bir kritik uzunluk $m$ vardır (kitapta $p$ diye de geçer). $|w| \ge m$ olan her $w \in L$ dizgesi $w = uvxyz$ biçiminde yazılabilir; $|vxy| \le m$, $|vy| \ge 1$ ve her $i \ge 0$ için $uv^ixy^iz \in L$ olur (ekrandan, 00:10:00).
  - Önsav bir dilin bağlamdan bağımsız **olmadığını** ispatlamak için kullanılır. Örnek diller: $\{a^nb^nc^n\}$ ve $\{vv : v \in \{a,b\}^*\}$.
  - $L = \{vv : v \in \{a,b\}^*\}$ için seçilen dizge $a^mb^ma^mb^m$'dir (ekrandan, 00:15:00). $a^{2m}$ gibi bir dizge de dilde olsa da pompalanabildiği için işe yaramaz; pompalanamadığı gösterilebilecek bir dizge seçilmelidir.
  - Durum 1: $vxy$ ilk $a^m$ bloğunun içindedir; $v = a^{k_1}$, $y = a^{k_2}$, $k_1 + k_2 \ge 1$ (ekrandan, 00:20:00). Yukarı pompalayınca ilk blokta fazla $a$ olur, dizge $vv$ biçiminden çıkar. $vxy$ öteki blokların birinin içindeyse durum aynıdır.
  - Durum 2: $v$ hem $a$ hem $b$ içerir ($v$ ilk iki bloğun sınırında), $y$ $b$'lerin içindedir ve boş olabilir. Pompalanınca $a$ ve $b$ iç içe geçer, dizge iki eş yarıya bölünemez. Öteki "sınırda" durumlar buna benzer.
  - $vxy$ üç bloğa birden yayılamaz, çünkü $|vxy| \le m$'dir.
  - Bütün durumlarda çelişki çıkar; $L$ bağlamdan bağımsız değildir (ekrandan, 00:25:00).
- Bağlamdan bağımsız dillerin kapalılık özellikleri (properties of context-free languages)
  - Birleşim (union): yeni başlangıç değişkeni $S$ ve $S \to S_1 \mid S_2$ kuralı eklenir (ekrandan, 00:30:00).
  - Birleştirme (concatenation): $S \to S_1 S_2$.
  - Yıldız işlemi (star): yeni başlangıç değişkeni $S$ ile özgün değişken arka arkaya yazılır ve bitirmek için $\lambda$ eklenir; böylece istenen sayıda $S_1$ üretilir. <!-- BELİRSİZ: kuralın tam yazımı karede görülmedi; Busch slaytlarında büyük olasılıkla $S \to SS_1 \mid \lambda$ -->
  - Kesişim (intersection) altında kapalı **değildir**: $L_1 \cap L_2$ bağlamdan bağımsız olmak zorunda değildir (olabilir de, olmayabilir de) (ekrandan, 00:35:00).
  - Örnek: $L_1 = \{a^nb^nc^m\}$ ($S \to AC$, $A \to aAb \mid \lambda$, $C \to cC \mid \lambda$) ve $L_2 = \{a^nb^mc^m\}$ ($S \to AB$, $A \to aA \mid \lambda$, $B \to bBc \mid \lambda$) bağlamdan bağımsızdır; $L_1 \cap L_2 = \{a^nb^nc^n\}$ değildir (ekrandan, 00:40:00).
  - Tümleme (complement) altında kapalı değildir. İspat olmayana ergiyle: tümleme kapalı olsaydı De Morgan kuralıyla $\overline{\overline{L_1} \cup \overline{L_2}} = L_1 \cap L_2$ de bağlamdan bağımsız olurdu; ama yukarıdaki örnekte kesişim $\{a^nb^nc^n\}$'dir (ekrandan, 00:40:00).
  - Düzenli dillerle karşılaştırma: düzenli diller birleşim, birleştirme, yıldız, tümleme ve kesişim altında kapalıdır; bağlamdan bağımsız diller ilk üçünde kapalı, son ikisinde kapalı değildir.
- Bağlamdan bağımsız dil ile düzenli dilin kesişimi (regular closure)
  - $L_1$ bağlamdan bağımsız, $L_2$ düzenliyse $L_1 \cap L_2$ bağlamdan bağımsızdır.
  - İspat inşa yoluyla: $L_1$ için NPDA $M_1$, $L_2$ için DFA $M_2$ alınır; ikisini paralel benzeten yeni bir NPDA $M$ kurulur (ekrandan, 00:50:00).
  - NPDA (nondeterministic PDA) derste öğrenilen PDA'nın kendisidir; "N" yalnız deterministik PDA'dan (DPDA) ayırmak için yazılır.
  - $M$'nin durumları $(q, p)$ çiftleridir. $q_1 \xrightarrow{a,\, b \to c} q_2$ ve $p_1 \xrightarrow{a} p_2$ geçişleri $(q_1,p_1) \xrightarrow{a,\, b \to c} (q_2,p_2)$ geçişini verir. $\lambda$ geçişlerinde DFA bileşeni yerinde kalır. Başlangıç durumu $(q_0,p_0)$; kabul durumları her iki bileşeni de kabul durumu olan çiftlerdir.
  - Örnek: $L_1 = \{w_1w_2 : |w_1| = |w_2|,\ w_1 \in \{a,b\}^*,\ w_2 \in \{c,d\}^*\}$, $L_2 = \{a,c\}^*$; kesişim $\{a^nc^n : n \ge 0\}$ (ekrandan, 00:55:00 ve 01:25:00).
  - Slayttaki NPDA'da $q_2 \to q_3$ geçişi yığıtın boşaldığını denetlemiyordu; tek bir $a$ girdisi de kabul ediliyordu. Derste bu geçiş yığıt sonu sembolü $\$$ okunacak biçimde düzeltildi (ekrandan, 01:20:00).
- Kesişim özelliğinin uygulamaları
  - Bağlamdan bağımsızlığı ispat: $L = \{a^nb^n : n \ne 100,\ n \ge 0\}$. $L_1 = \{a^{100}b^{100}\}$ düzenlidir, $\overline{L_1} = \{(a+b)^*\} - \{a^{100}b^{100}\}$ de düzenlidir; $L = \{a^nb^n\} \cap \overline{L_1}$ bağlamdan bağımsızdır (ekrandan, 01:30:00).
  - Bağlamdan bağımsız olmadığını ispat: $L = \{w : n_a = n_b = n_c\}$. $L$ bağlamdan bağımsız olsaydı $L \cap L(a^*b^*c^*) = \{a^nb^nc^n\}$ de olurdu; çelişki.
- Doğrusal ve düzenli gramerler
  - Doğrusal gramer (linear grammar): her kuralın sağ tarafında en çok bir değişken vardır.
  - Sağ doğrusal (right-linear): kurallar $A \to xB$ ya da $A \to x$ biçimindedir ($x$ bitiş sembolleri dizgesi). Sol doğrusal (left-linear): $A \to Bx$ ya da $A \to x$ (ekrandan, 01:50:00).
  - Düzenli gramer: sağ doğrusal ya da sol doğrusal gramer.
  - Örnek sol doğrusal gramer: $S \to Aab$, $A \to Aab \mid B$, $B \to a$ (ekrandan, 01:50:00); dili $aab(ab)^*$.
  - Teorem: düzenli gramerlerin ürettiği diller kümesi, düzenli diller kümesine eşittir. İki yönlü ispat edilir.
- Sağ doğrusal gramerden NFA
  - Her değişken için bir durum ve ek bir kabul durumu $V_F$ yazılır. $V_i \to a_1 \dots a_k V_j$ için $V_i$'den $V_j$'ye ara durumlarla bir zincir, $V_i \to a_1 \dots a_k$ için $V_F$'ye giden zincir eklenir.
  - Örnek: $S \to aA \mid B$, $A \to aaB$, $B \to bB \mid a$ (ekrandan, 01:55:00); dili $aaab^*a + b^*a$. NFA: $S \xrightarrow{a} A$, $S \xrightarrow{\lambda} B$, $A \xrightarrow{a} q \xrightarrow{a} B$, $B \xrightarrow{b} B$, $B \xrightarrow{a} V_F$ (ekrandan, 02:00:00).
- Sol doğrusal gramerler
  - Her kuralın sağ tarafı ters çevrilerek ($A \to Bv$ yerine $A \to v^RB$) sağ doğrusal $G'$ elde edilir; $L(G) = L(G')^R$ (ekrandan, 02:05:00).
  - $L(G')$ düzenlidir ve düzenli diller ters çevirme altında kapalıdır; dolayısıyla $L(G)$ düzenlidir.
- NFA'dan sağ doğrusal gramer
  - Her durum bir değişken olur; $q_i \xrightarrow{a} q_j$ geçişi $q_i \to aq_j$ kuralını, her kabul durumu $q_f \to \lambda$ kuralını verir (ekrandan, 02:10:00).
  - Örnek: $q_0 \to aq_1$, $q_1 \to bq_1$, $q_1 \to aq_2$, $q_2 \to bq_3$, $q_3 \to q_1$, $q_3 \to \lambda$ (ekrandan, 02:15:00). Birim ve $\lambda$ kuralları atılınca $q_0 \to aq_1$, $q_1 \to bq_1 \mid aq_2$, $q_2 \to bq_1 \mid b$ kalır.
- Deterministik yığıtlı otomatlar (DPDA)
  - DPDA'da $\lambda$ geçişlerine izin vardır (DFA'dan farkı budur), ama aynı durumda aynı (girdi, yığıt üstü) çifti için iki seçenek olamaz.
  - İzin verilmeyenler: aynı durumdan $a, b \to w_1$ ve $a, b \to w_2$ ile iki ayrı duruma gitmek; aynı yığıt sembolü $b$ ile hem $\lambda, b \to w_1$ hem $a, b \to w_2$ geçişi (ekrandan, 02:40:00).
  - İzin verilenler: yığıt üstü farklı olan geçişler; girdi sembolü farklı olan geçişler.
  - Bir dili kabul eden bir DPDA varsa dil deterministik bağlamdan bağımsızdır. Her DPDA bir PDA olduğu için deterministik bağlamdan bağımsız diller $\subseteq$ bağlamdan bağımsız diller (ekrandan, 02:45:00). Kapsamanın kesin olduğunu göstermek için $\{a^nb^n\} \cup \{a^nb^{2n}\}$ ($n > 0$) dili ele alınacaktır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pompalama önsavında dizge seçimi
  - Dilde olan ve $m$'den uzun her dizge işe yaramaz. Pompalanamadığı gösterilebilecek bir kalıp seçilmelidir; $a^{2m}$ yerine $a^mb^ma^mb^m$ seçilmesinin nedeni budur.
- "Kapalı değil" ne demek?
  - Kesişim ya da tümleme sonucunun bağlamdan bağımsız olmadığı anlamına gelmez; bağlamdan bağımsız olması garanti değildir.
- Bağlamdan bağımsız ile düzenli arasındaki fark
  - Kesişim ve tümleme düzenli dillerde kapalı, bağlamdan bağımsız dillerde kapalı değildir. Bağlamdan bağımsız dilin düzenli bir dille kesişimi ise yine bağlamdan bağımsızdır.
- Kesişim özelliği iki yönde kullanılır
  - Bir dilin bağlamdan bağımsız olduğunu da, olmadığını da ispatlamaya yarar.
- NPDA aslında PDA'dır
  - Derste öğrenilen PDA'lar zaten deterministik değildir; "N" yalnız DPDA'dan ayırmak içindir.
- DPDA ve DFA farkı
  - NFA/DFA ayrımında DFA'da $\lambda$ geçişi yoktur; NPDA/DPDA ayrımında DPDA'da $\lambda$ geçişi olabilir.

## Kısa Tekrar Notları

- CFL pompalama önsavı: $w = uvxyz$, $|vxy| \le m$, $|vy| \ge 1$, $uv^ixy^iz \in L$.
- $\{vv\}$ için dizge $a^mb^ma^mb^m$; $vxy$'nin her konumunda çelişki.
- CFL'ler birleşim ($S \to S_1 \mid S_2$), birleştirme ($S \to S_1S_2$) ve yıldız altında kapalıdır.
- CFL'ler kesişim ve tümleme altında kapalı değildir; örnek $\{a^nb^nc^m\} \cap \{a^nb^mc^m\} = \{a^nb^nc^n\}$.
- Tümleme ispatı De Morgan ile kesişime indirgenir.
- CFL $\cap$ düzenli = CFL; NPDA ile DFA'nın çarpım otomatı kurulur.
- $\{a^nb^n : n \ne 100\}$ CFL'dir; $\{w : n_a = n_b = n_c\}$ CFL değildir (ikisi de kesişim özelliğiyle).
- Doğrusal gramer: sağ tarafta en çok bir değişken. Sağ doğrusal: $A \to xB \mid x$; sol doğrusal: $A \to Bx \mid x$.
- Düzenli gramerler = düzenli diller. Sağ doğrusal → NFA; sol doğrusal → ters çevirip sağ doğrusal; NFA → sağ doğrusal ($q_i \to aq_j$, $q_f \to \lambda$).
- DPDA: aynı durum ve aynı yığıt üstü için tek seçenek; $\lambda$ geçişi yalnız aynı yığıt üstüyle okuma geçişi yoksa serbest.
- DCFL $\subseteq$ CFL.

## Detaylı Açıklamalar

- $\{vv\}$ ispatının mantığı
  - Olmayana ergi ile $L$'nin bağlamdan bağımsız olduğu varsayılır. Önsavın verdiği $m$ için $a^mb^ma^mb^m$ seçilir; bu dizgenin uzunluğu $4m$'dir ve dildedir. Önsav "her bölünme için pompalanabilir" dediğinden, $vxy$'nin olabileceği bütün konumlar incelenir. $vxy$ tek bir bloğun içindeyse pompalama yalnız o bloğu büyütür ve iki yarı eşitliği bozulur. $v$ ya da $y$ iki bloğun sınırındaysa pompalama $a$ ile $b$'yi iç içe sokar ve dizge kendini tekrar eden iki yarıya ayrılamaz. $vxy$ en çok $m$ uzunluğunda olduğu için üç bloğa birden dokunamaz. Her durum çelişki verdiği için varsayım yanlıştır.
- Kapalılık inşaları
  - Birleşimde yeni başlangıç değişkeni iki gramerden birini seçer; bu, birleşimin "veya" olmasına karşılık gelir. Birleştirmede iki başlangıç değişkeni yan yana yazılır. Yıldızda yeni değişken kendini ve özgün başlangıç değişkenini tekrar tekrar üretir, sonunda $\lambda$ ile sonlanır.
- Kesişim inşası ve slayttaki hata
  - Çarpım otomatında okuma geçişleri iki makinede aynı anda yapılır, $\lambda$ geçişlerinde yalnız NPDA ilerler. $M$, bir dizgeyi ancak $M_1$ ve $M_2$ ikisi de kabul ediyorsa kabul eder; bu yüzden $L(M) = L(M_1) \cap L(M_2)$.
  - Örnekteki $M_1$: $q_0 \xrightarrow{\lambda,\lambda \to \lambda} q_1$; $q_1$ döngüsü $a,\lambda \to 1$ ve $b,\lambda \to 1$; $q_1 \xrightarrow{\lambda,\lambda \to \lambda} q_2$; $q_2$ döngüsü $c,1 \to \lambda$ ve $d,1 \to \lambda$; $q_2 \xrightarrow{\lambda,\lambda \to \lambda} q_3$ (ekrandan, 00:55:00). Bir öğrencinin sorusu üzerine hoca, son geçişin yığıtta $\$$ görmesi gerektiğini doğruladı: yalnız $a$ girildiğinde yığıtta bir $1$ kalsa da $q_3$'e ulaşılıyordu. <!-- BELİRSİZ: düzeltilmiş geçişin tam yazımı karede tamamlanmamış ($\lambda, \$ \to$ ...) -->
  - Kesişim için kurulan $M$: $(q_0,p_0) \to (q_1,p_0)$ ($\lambda,\lambda \to \lambda$), $(q_1,p_0)$ döngüsü $a,\lambda \to 1$, $(q_1,p_0) \to (q_2,p_0)$, $(q_2,p_0)$ döngüsü $c,1 \to \lambda$, $(q_2,p_0) \to (q_3,p_0)$ (ekrandan, 01:25:00). $b$ ve $d$ geçişleri DFA'da karşılığı olmadığı için düşer.
- Düzenli gramer ile NFA dönüşümleri
  - Sağ doğrusal gramerde değişken "o anki durum" gibi çalışır: üretilen bitiş sembolleri okunan girdiye, sağdaki değişken bir sonraki duruma karşılık gelir. $aaaba$ için türetim $S \Rightarrow aA \Rightarrow aaaB \Rightarrow aaabB \Rightarrow aaaba$'dır; NFA'da etkin durumlar sırasıyla $\{S,B\}$, $\{A,V_F\}$, $\{q\}$, $\{B\}$, $\{B\}$, $\{V_F\}$ olur ve dizge kabul edilir.
  - Ters yönde NFA'nın her geçişi bir kural olur. Örnekteki $q_3 \to q_1$ birim kuralı ve $q_3 \to \lambda$ kuralı, önceki derslerin sadeleştirme adımlarıyla atılabilir; sonuç gramer aynı dili ($a(b^*ab)^+$) üretir (ajan tarafından python ile kontrol edildi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
