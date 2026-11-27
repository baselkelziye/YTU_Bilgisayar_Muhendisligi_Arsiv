# Ders 13 Çalışma Özeti

## Genel Konular

- Ders büyük ölçüde İngilizce anlatıldı, bazı yerler Türkçe açıklandı.
  - Anlatım hazır slaytlar üzerinden ilerledi ("Turing Variations", "Decidable", "Time Complexity" slayt dosyaları). Kayıtta iki ara var (yaklaşık 00:38-00:52 ve 01:30-01:38).
  - Altyazının birçok yerinde Whisper bozmaları var. Slaytlarda kalan ama altyazıda anlaşılmayan ayrıntılar BELİRSİZ olarak işaretlendi.
- Turing makinesi çeşitleri: yerinde kalma seçenekli makine (stay-option)
  - Kafa sola (L) ve sağa (R) gitmenin yanında yerinde de kalabilir (S).
  - Teorem: stay-option makineleri standart Turing makineleriyle aynı güce sahiptir (ekrandan, 00:05:00).
  - İspat iki yönlüdür: (1) stay-option makine standart makineyi taklit eder (her standart makine zaten bir stay-option makinedir), (2) standart makine stay-option makineyi taklit eder.
  - $q_1 \xrightarrow{a \to b,\,S} q_2$ geçişi standart makinede iki geçişle yapılır: önce $a \to b, L$ ile geçici bir duruma, sonra $x \to x, R$ ile $q_2$'ye. Burada $x$ her olası şerit simgesidir. L ya da R içeren geçişler değişmez.
- Çok izli şerit (multiple track tape)
  - Tek şerit, tek kafa; her hücrede izler üst üste durur. Kafa altındaki sütun tek bir simge sayılır, örneğin $(a,b)$ (ekrandan, 00:15:00).
  - İki iz ikili (double), üç iz üçlü (triple) bir simge gibi düşünülür. Bu yüzden çok izli şerit standart makineyle aynı güçtedir.
- Yarı sonsuz şerit (semi-infinite tape)
  - Şerit yalnız sağa doğru sonsuzdur; solda bir başlangıç noktası vardır. Kafa sol sınırdan sola gitmek isterse yerinde kalır.
  - Teorem: yarı sonsuz şeritli makineler standart makinelerle aynı güçtedir.
  - Standart makine yarı sonsuz makineyi taklit eder: giriş dizgisinin soluna özel simge $\#$ konur ve her duruma $\# \to \#, R$ öz döngüsü eklenir (çıkışı olmayan durumlar hariç) (ekrandan, 00:20:00).
  - Yarı sonsuz makine standart makineyi taklit eder: iki yöndeki sonsuzluk tek yöne "sıkıştırılır". Şerit iki izli düşünülür: üst iz sağ yarı (right part), alt iz sol yarı (left part). Her standart durumun $q^L$ ve $q^R$ diye iki kopyası olur (ekrandan, 00:25:00).
  - Sınırda $\#$ simgeleri birlikte okunup birlikte yazılır, kafa sağa döner ve durum sol kopyadan sağ kopyaya geçer.
- Çok şeritli Turing makineleri (multi-tape)
  - Birden çok şerit ve her şeritte ayrı bir kafa vardır. Bir geçişte her şeritten bir simge okunur, her şeride bir simge yazılır ve her kafa ayrı hareket eder.
  - Teorem: çok şeritli makineler standart makinelerle aynı güçtedir.
  - Standart makinede taklit: her şerit bir iz, her şeridin kafa konumu ayrı bir iz olur (dört izli şerit, kafa konumu 0/1 ile işaretlenir). Sol uçta $\#$ referans noktası bulunur (ekrandan, 00:30:00).
  - Her çok şeritli geçiş için: referans noktasına dön, iz 1'deki güncel simgeyi bul ve güncelle; referans noktasına dön, şerit 2'nin güncel simgesini bul ve güncelle.
  - Aynı güç aynı hız demek değildir: $\{a^nb^n\}$ standart makinede ileri geri giderek yaklaşık $n^2$ adımda tanınır; iki şeritli makinede $b^n$ ikinci şeride kopyalanıp $a^n$ ile karşılaştırılır. <!-- BELİRSİZ: iki şeritli sürenin hocanın söylediği değeri altyazıda kesik (00:32:30) -->
- Çok boyutlu şerit
  - İki boyutlu şeritte kafa sola, sağa, yukarı ve aşağı gider. Hücre konumu koordinatlarla verilir, örneğin $b$ simgesi $(+2,-1)$ konumundadır (ekrandan, 00:35:00).
  - Standart makinede taklit: her simgenin yanına koordinatları yazılır (iki izli şerit, koordinatlar $\#$ ile ayrılır).
- Belirlenimci olmayan (non-deterministic) Turing makineleri
  - Aynı durum ve okunan simge için birden çok seçenek olabilir (örneğin $a \to b, L$ ve $a \to c, R$).
  - Belirlenimci makine bunu her seçenek için şeridin bir kopyasını çıkararak taklit eder. En kötü durumda taklit, kabul eden en kısa yolun uzunluğuna göre üstel zaman alır.
  - Sonuç: belirlenimcilik olmayan makineler standart makinelerden daha güçlü değildir.
- Karar verilebilir diller (decidable languages)
  - Turing'le kabul edilebilir (Turing-acceptable, recognizable, recursively enumerable) dil: $L$'yi kabul eden bir $M$ makinesi vardır. $w \in L$ ise makine kabul durumunda durur; $w \notin L$ ise kabul olmayan bir durumda durur ya da sonsuza dek döner.
  - Karar verilebilir dil: $L$'yi kabul eden ve her giriş dizgisinde duran (hiç döngüye girmeyen) bir Turing makinesi vardır. Bu makineye karar verici (decider) denir.
  - Her karar verilebilir dil Turing'le kabul edilebilirdir; tersi doğru değildir.
  - Tek kabul ve tek ret durumlu makine: birden çok son durum tek $q_{accept}$ durumuna, tanımsız geçişler tek $q_{reject}$ durumuna yönlendirilerek her makine bu biçime getirilebilir (ekrandan, 00:55:00).
  - Bir hesaplama problemi, karşılık gelen dili karar verilebilirse karar verilebilirdir. Böyle problemlere çözülebilir (solvable) de denir (ekrandan, 01:00:00).
- Karar verilebilir problem örnekleri
  - "$x$ asal mı?": $x$, 2 ile $\sqrt{x}$ arasındaki tüm sayılara bölünmeye çalışılır; biri bölerse ret, hiçbiri bölmezse kabul. Döngü yoktur.
  - "DFA $M$ boş dili mi kabul ediyor?": $EMPTY_{DFA} = \{\langle M \rangle : M$ boş dili kabul eden bir DFA$\}$. Başlangıç durumundan bir kabul durumuna yol varsa dil boş değildir (ekrandan, 01:05:00).
  - "DFA $M$ sonlu bir dil mi kabul ediyor?": başlangıçtan kabul durumuna giden ve döngü (cycle) içeren bir yol varsa dil sonsuzdur, makine reddedilir.
  - "DFA $M$, $w$ dizgisini kabul ediyor mu?": $A_{DFA} = \{\langle M, w \rangle : M$, $w$'yu kabul eden bir DFA$\}$. Karar verici $M$'yi $w$ üzerinde çalıştırır; DFA her zaman durur (ekrandan, 01:10:00).
  - "$M_1$ ve $M_2$ aynı dili mi kabul ediyor?": $L(M) = (L_1 \cap \overline{L_2}) \cup (\overline{L_1} \cap L_2)$ olan bir DFA $M$ kurulur. $L(M) = \emptyset$ ise iki dil eşittir; bu da boşluk problemine indirgenir.
- Tümleme teoremi
  - $L$ karar verilebilirse $\overline{L}$ de karar verilebilirdir.
  - İspat: $L$'nin karar vericisi $M$'de kabul ve ret durumları yer değiştirilir; elde edilen $M'$, $\overline{L}$'nin karar vericisidir (ekrandan, 01:15:00).
- Karar verilemeyen bir dil (köşegen yöntemi)
  - $\Sigma = \{a\}$ üzerindeki dizgiler $a, a^2, a^3, \dots$ ve bu alfabe üzerindeki Turing makineleri $M_1, M_2, \dots$ sayılabilir.
  - Her dil, $a^i$'nin dilde olup olmadığını gösteren bir ikili satırla gösterilir. Örneğin $L(M_i) = \{a^2, a^4, a^6\}$ için satır $0\,1\,0\,1\,0\,1\,0 \dots$ olur (ekrandan, 01:20:00).
  - $L = \{a^i : a^i \in L(M_i)\}$ (köşegendeki 1'ler) ve $\overline{L} = \{a^i : a^i \notin L(M_i)\}$ (köşegendeki 0'lar) tanımlanır.
  - Teorem: $\overline{L}$ Turing'le kabul edilebilir değildir. Kabul eden bir $M_k$ olsaydı, her $i$ için $a^i$ $L(M_k)$ ile $L(M_i)$'den yalnız birinde bulunurdu; yani $M_k$ hiçbir $M_i$'ye eşit olamazdı (ekrandan, 01:25:00).
  - $L$ ise Turing'le kabul edilebilirdir: $a^i$ için $i$ bulunur, $M_i$ sayımlayıcıyla (enumerator) elde edilip $a^i$ üzerinde taklit edilir.
  - $L$ karar verilebilir olsaydı $\overline{L}$ de karar verilebilir (dolayısıyla Turing'le kabul edilebilir) olurdu. Çelişki: $L$ Turing'le kabul edilebilir ama karar verilemezdir (ekrandan, 01:30:00).
- Zaman karmaşıklığı
  - Bir dile karar veren belirlenimci makinenin $w$ için karar süresi, başlangıçtan kabul ya da ret durumuna kadarki geçiş sayısıdır.
  - $T_M(n)$: $n$ uzunluğundaki herhangi bir dizgiye karar vermek için gereken en uzun süre (ekrandan, 01:40:00).
  - $TIME(T(n))$: $T(n)$ sürede belirlenimci bir makineyle karar verilebilen dillerin sınıfı.
  - Örnekler: $\{a^nb\}$ doğrusal sürede; $\{a^nb^n\}$ ve $\{ww\}$ $n^2$ sürede; matris çarpımı ve CYK algoritması $n^3$ sürede.
  - Polinom zaman: $TIME(n^k)$. Küçük $k$ için algoritmalar uygulanabilir (tractable). $P = \bigcup_k TIME(n^k)$ (ekrandan, 01:45:00).
  - Üstel zaman algoritmaları ($2^{n^k}$) uygulanamaz (intractable) sayılır. Örnekler: Hamilton yolu (tüm yolların denenmesi, $n!$), $k$ boyutlu klik var mı, SAT (birleşik normal biçimdeki Boole ifadesinin sağlanabilirliği).
  - Belirlenimci olmayan zaman: $NTIME(T(n))$, $NP = \bigcup_k NTIME(n^k)$ (ekrandan, 01:50:00). $P \subseteq NP$; $P = NP$ olup olmadığı açık problemdir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yarı sonsuz şeritli makinenin standart makineyi taklit ettiği örnek "çok iyi bir örnek" olarak gösterildi; nasıl kullanıldığının anlaşılması istendi.
- Karar verilebilir dilin anahtarı "döngü yok" koşuludur: karar verici her girişte kabul ya da ret durumunda durur.
- "Karar verilebilir dilin tümleyeni karar verilebilirdir" teoremi "çok önemli bir teorem" olarak vurgulandı.
- Karar verilebilir diller ve köşegen ispatıyla ilgili konulardan final sınavında soru sorulacağı söylendi.
- $P = NP$ sorusunun cevabını bilmiyoruz; açık problemdir.

## Kısa Tekrar Notları

- Stay-option, çok izli, yarı sonsuz, çok şeritli, çok boyutlu ve belirlenimci olmayan Turing makinelerinin hepsi standart makineyle aynı güçtedir.
- "Aynı güç" ispatı iki yönlüdür: A, B'yi taklit eder ve B, A'yı taklit eder.
- Stay hareketi = $a \to b, L$ + $x \to x, R$ (geçici durum üzerinden).
- Yarı sonsuz şerit: $\#$ sınır simgesi, $\# \to \#, R$ öz döngüleri; iki yönlü şerit iki izle tek yöne katlanır, durumlar $q^L$/$q^R$.
- Çok şeritli makine: her şerit için bir iz ve bir kafa konumu izi; $\#$ referans noktası.
- Turing'le kabul edilebilir: $w \notin L$ iken döngü olabilir. Karar verilebilir: her girişte durur.
- $A_{DFA}$, $EMPTY_{DFA}$, sonluluk ve DFA eşitliği karar verilebilirdir.
- $L$ karar verilebilir $\Rightarrow$ $\overline{L}$ karar verilebilir.
- Köşegen dili $L = \{a^i : a^i \in L(M_i)\}$ Turing'le kabul edilebilir ama karar verilemezdir; $\overline{L}$ Turing'le kabul edilebilir değildir.
- $P = \bigcup_k TIME(n^k)$, $NP = \bigcup_k NTIME(n^k)$, $P \subseteq NP$, $P \stackrel{?}{=} NP$ açık.

## Detaylı Açıklamalar

- **Stay-option makinesinin taklidi.** Slayttaki örnekte şerit $\Diamond a a b a \Diamond$ ve makine $q_1$ durumunda ilk $a$ üzerindedir. $q_1 \xrightarrow{a \to b,\,S} q_2$ geçişinden sonra şerit $\Diamond b a b a \Diamond$ olur, kafa yerinde kalır ve durum $q_2$'dir. Standart makinede aynı sonuç iki adımda elde edilir: $a$ yerine $b$ yazılıp kafa sola gider (geçici duruma geçilir), sonra okunan simge değiştirilmeden kafa sağa döner ve $q_2$'ye geçilir (ekrandan, 00:10:00).
  - Ders sonrası not: Slaytta adım 2'nin durumu $q_2$, adım 3'ün durumu $q_3$ yazılıydı; hoca bunu düzeltti: ara durum geçici bir durumdur, son durum $q_2$ olmalıdır.
- **Çok izli şerit.** İzler aynı sütunda üst üste durduğu için kafa tek bir sütunu okur. Örneğin kafanın altında üstte $b$, altta $a$ varsa ve geçiş bunları $c$, $d$ yapıp sola gidiyorsa, tek simgeli bir geçiş gibi $(b,a) \to (c,d), L$ yazılır. Bu yüzden çok izli şerit yeni bir güç getirmez, yalnız karmaşık taklitleri kolaylaştıran bir hiledir.
- **Yarı sonsuz şerit.** Yarı sonsuz makinede iki yönlü şerit sağ ve sol yarılara bölünür. Sağ yarı üst ize, sol yarı alt ize yazılır; sol yarı ters sırayla durur. Makine sol yarıda çalışırken $q^L$ durumlarını, sağ yarıda çalışırken $q^R$ durumlarını kullanır ve sol yarıdaki hareket yönleri tersine çevrilir. Slayttaki örnekte "Time 1" anında kafa $\#$ sınırında ve durum $q_1^L$'dir; sınırda $\#$ simgeleri birlikte okunup yazılır, kafa sağa gider ve "Time 2" anında aynı durumun sağ kopyası $q_1^R$ ile birinci sütundadır (ekrandan, 00:25:00).
- **Karar verilebilirlik ve problem dili.** Bir problemi dil olarak görmek için girdisi (örneğin bir DFA) ikili dizgi olarak kodlanır, tıpkı bir Java ya da C kodunun sonunda ikili dizgiye dönüşmesi gibi. "Boş dili kabul eden tüm DFA'ların kodları" bir dizgi kümesi, yani bir dildir. Bu dile karar veren ve her girişte duran bir makine varsa problem çözülebilirdir.
- **DFA eşitliği.** İki DFA'nın dilleri eşitse simetrik fark $(L_1 \cap \overline{L_2}) \cup (\overline{L_1} \cap L_2)$ boştur. Düzenli diller kesişim, birleşim ve tümleme altında kapalı olduğu için bu dili tanıyan bir DFA kurulabilir; sonra $EMPTY_{DFA}$ karar vericisi kullanılır.
  - Ders sonrası not: Hoca bir yerde bu dilin "boş dizgi" (empty string) olması gerektiğini söyledi; doğrusu boş dil ($\emptyset$) olmasıdır.
- **Köşegen ispatı.** Slayttaki tabloda $L(M_1)$ satırı $0\,1\,0\,1$, $L(M_2)$ satırı $1\,0\,0\,1$, $L(M_3)$ satırı $0\,1\,1\,1$, $L(M_4)$ satırı $0\,0\,0\,1$ ile başlar. Köşegen $0, 0, 1, 1$ olduğundan $L = \{a^3, a^4, \dots\}$ ve $\overline{L}$'nin satırı $1\,1\,0\,0 \dots$ olur, yani $\overline{L} = \{a, a^2, \dots\}$. $M_k = M_1$ olamaz çünkü $a \in L(M_k)$ ama $a \notin L(M_1)$; benzer şekilde $a^2$ tanığıyla $M_k \ne M_2$ olur. Her $i$ için $a^i$ ayırt edici tanık olduğundan $M_k$ var olamaz (ekrandan, 01:25:00; python ile kontrol edildi).
- **Karmaşıklık sınıfları.** Polinom zamanlı algoritmalar uygulanabilir sayılır ve $P$ sınıfını oluşturur. Üstel zamanlı algoritmalarda girdi büyüdükçe süre o kadar hızlı artar ki çözüm yüzyıllar alabilir; hoca anahtarı bilinmeyen şifreli bir metni çözmeyi örnek verdi. Belirlenimci olmayan makinede hesaplamalar bir ağaç olarak düşünülür ve kabul eden bir dalın uzunluğu süreyi belirler. SAT için polinom zamanlı belirlenimci bir algoritma olup olmadığı bilinmiyor.
  - Ders sonrası not: Hoca üstel ifadede $k < 1$ ise problemin uygulanabilir sayılabileceğini söyledi. $0 < k < 1$ için bile $2^{n^k}$ her polinomdan hızlı büyür; bu yüzden böyle bir algoritma büyük olasılıkla polinom zamanlı sayılmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
