# Ders 4 Çalışma Özeti

## Genel Konular

- Ders anlatımı ağırlıkla İngilizce yapıldı, bazı açıklamalar Türkçe tekrar edildi.
  - Asıl anlatım yaklaşık 00:07:50'de başlar.
  - Araya iki ara verildi (yaklaşık 00:50:30-01:02:30 ve 02:04:45-02:15:55).
- NFA ile DFA arasındaki fark (tekrar)
  - DFA'da her durumdan çıkan geçiş sayısı alfabenin büyüklüğüne eşittir. NFA'da bu koşul aranmaz.
  - Tek durumlu basit otomatlar: $L(M_1)=\{\}$ ve $L(M_2)=\{\varepsilon\}$. Alfabe boşsa bunlar DFA, boş değilse NFA sayılır.
  - DFA'ların kümesi NFA'ların kümesinin alt kümesidir.
- NFA'nın genişletilmiş geçiş fonksiyonu $\delta^*$
  - Çıktısı tek bir durum değil, bir durum kümesidir. $\varepsilon$ geçişleri de hesaba katılır.
- NFA'nın dili ve kabul koşulu
  - $w \in L(M)$ olması için $\delta^*(q_0,w)$ kümesinde en az bir kabul durumu bulunmalıdır.
- Makinelerin denkliği
  - İki makine aynı dili tanıyorsa denktir. Durum ve geçiş sayısına bakılmaz.
- Teorem: NFA'ların kabul ettiği diller = düzenli diller (DFA'ların kabul ettiği diller).
  - İspatın iki yönü ve NFA'dan DFA'ya dönüşüm fikri.
- NFA'dan DFA'ya dönüşüm (alt küme yapısı)
  - DFA'daki her durumun adı, NFA'nın o anda bulunabileceği durumların kümesidir.
- Düzenli dillerin kapanma özellikleri
  - Birleşim, birleştirme (concatenation), Kleene yıldızı, ters çevirme, tümleme, kesişim.
  - Tek kabul durumuna dönüştürme, her işlem için NFA kurma yöntemleri.
  - Kesişim için Kartezyen çarpım yapısı.
- Düzenli ifadelere giriş: özyinelemeli tanım ve düzenli ifadenin dili.

## Hocanın Özellikle Vurguladığı Kısımlar

- NFA ile DFA'yı ayırt etmek için her durumun çıkış geçişlerini sayıp alfabenin büyüklüğüyle karşılaştırın.
  - Bir oktaki iki sembol ($0,1$ gibi) iki ayrı geçiş sayılır.
  - $\varepsilon$ geçişi çıkış geçişi sayılmaz, yalnızca bir bağlantıdır.
- NFA ve DFA'nın hesaplama gücü aynıdır, aynı dil kümesini tanırlar.
  - NFA tasarlamak daha kolaydır ve daha az durum/geçiş kullanır. DFA daha karmaşıktır.
- Dönüşümde DFA durumlarının üzerindeki küme işaretleri durumların adıdır.
  - Hoca, bunları ad olarak görmezseniz kafanızın karışacağını söyledi. Durumlara istediğiniz adı verebilirsiniz.
- Bu konu, hocaya göre bilgisayar mühendisliğinin kalbidir.
  - Örnek kullanım alanları: işlemci içindeki donanım otomatları, dosya aramada joker karakterler, içecek otomatları, derleyicilerde sözcük ayırma (tokenizer).
- Sınavlarda sık sorulan soru tipi: verilen bir NFA'nın tümleyenini ya da birkaç dilin birleşim/kesişim/birleştirme gibi işlemlerle elde edilen dilini tanıyan bir otomat tasarlamak.
- Tümleme için önce NFA mutlaka DFA'ya dönüştürülür. Sonra yalnızca durum türleri değiştirilir.

## Kısa Tekrar Notları

- DFA: her durumda çıkış geçişi sayısı $= |\Sigma|$. NFA: bu koşul yok, $\varepsilon$ geçişi olabilir.
- $\delta^*(q,w)$ bir durum kümesidir.
- $L(M)=\{w : \delta^*(q_0,w)\cap F \neq \emptyset\}$.
- Başlangıç durumu kabul durumuysa $\varepsilon \in L(M)$ olur.
- Denk makineler: $L(M_1)=L(M_2)$.
- NFA'dan DFA'ya: başlangıç durumu $\{q_0\}$ (ve $\varepsilon$ kapanışı); her yeni küme için her sembolün gittiği küme hesaplanır; boş küme tuzak durumdur; içinde NFA kabul durumu olan her küme DFA'da kabul durumudur.
- DFA'nın durumları NFA durumlarının kuvvet kümesinden seçilir.
- Birleşim: yeni başlangıç durumundan iki makinenin başlangıcına $\varepsilon$ geçişi.
- Birleştirme: $M_1$'in kabul durumu normal duruma çevrilir, $M_2$'nin başlangıcına $\varepsilon$ ile bağlanır.
- Yıldız: yeni başlangıç ve yeni kabul durumu, $\varepsilon$ geçişleri ve geri dönüş döngüsü.
- Ters çevirme: bütün geçişler ters çevrilir, başlangıç ve kabul durumlarının rolleri değiştirilir.
- Tümleme: DFA'da kabul durumları normal, normal durumlar kabul durumu yapılır.
- Kesişim: $M_1$ ve $M_2$ DFA'larının durumlarının Kartezyen çarpımı; durumlar $(q_i,p_j)$ çiftleridir.
- Düzenli ifade: ilkel ifadeler $\varepsilon$ ve $\alpha$; $r_1+r_2$, $r_1\cdot r_2$, $r_1^*$, $(r_1)$ de düzenli ifadedir.

## Detaylı Açıklamalar

- **NFA mı DFA mı?** Alfabesi $\{0,1\}$ olan ve $q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$, $q_0 \xrightarrow{\varepsilon} q_2$ geçişlerine sahip makinede (ekrandan, 00:10:00) $q_0$'dan yalnızca bir sembollü geçiş çıkar. Bu yüzden makine NFA'dır. Dili $\{\varepsilon, 10, 1010, 101010, \dots\} = \{10\}^*$'dır. $q_2$ gereksiz bir durumdur (redundant state). Başlangıç durumu aynı zamanda kabul durumu olduğundan boş dizgi dile aittir.
- **Tek durumlu makineler** (ekrandan, 00:15:00): $\varepsilon$ sembolü giriş şeridinde hiçbir zaman görünmez. Tek, kabul etmeyen durumlu $M_1$'in dili boş kümedir; tek, kabul eden durumlu $M_2$'nin dili $\{\varepsilon\}$'dur. Hiç çıkış geçişi olmadığı için alfabe boş kümeyse bu makineler DFA, değilse NFA'dır.
- **NFA daha kolay ifade eder** (ekrandan, 00:25:00): $\Sigma=\{a\}$ için $\{a\}$ dilini NFA iki durumla ($q_0 \xrightarrow{a} q_1$) tanır. DFA ise üç durum ister: $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_2$ ve $q_2$'de $a$ döngüsü. İki makine denktir.
- **Genişletilmiş geçiş örnekleri.** Makine: $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_4$, $q_1 \xrightarrow{a} q_5$, $q_1 \xrightarrow{b} q_2$, $q_2 \xrightarrow{\varepsilon} q_3$, $q_3 \xrightarrow{\varepsilon} q_0$; $F=\{q_0,q_5\}$ (ekrandan, 00:30:00 ve 00:40:00).
  - $\delta^*(q_0,a)=\{q_1\}$, $\delta^*(q_0,aa)=\{q_4,q_5\}$, $\delta^*(q_0,ab)=\{q_2,q_3,q_0\}$.
  - $\delta^*(q_0,aba)=\{q_1\}$: $q_2$ ve $q_3$'ten $a$ ile geçiş yoktur, bu yollar ölür.
  - $aa$, $ab$ ve $abaa$ kabul edilir; $aba$ reddedilir. Sonuçlar python ile doğrulandı.
  - Makinenin dili $L(M)=\{ab\}^* \cup \{ab\}^*\{aa\}$'dır (ekrandan, 00:45:00).
- **Bir dizginin kabulü** (ekrandan, 00:35:00): $L(M)=\{w_1,\dots,w_n\}$ ise her $w_m$ için $\delta^*(q_0,w_m)=\{q_i,\dots,q_k,\dots,q_j\}$ kümesinde en az bir $q_k \in F$ bulunur. Kümede hiç kabul durumu yoksa $w_m$ dile ait değildir.
- **Denk makineler** (ekrandan, 00:50:00): NFA $M_1$ ($q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$) ile DFA $M_2$ (aynı geçişler, ek olarak $q_1 \xrightarrow{1} q_2$, $q_0 \xrightarrow{0} q_2$ ve $q_2$'de $0,1$ döngüsü) aynı dili, $\{10\}^*$'ı tanır. Bu yüzden denktir. Python ile 8 uzunluğa kadar bütün dizgilerde doğrulandı.
- **Teorem ve ispat fikri** (ekrandan, 00:55:00 ve 01:05:00): Eşitliği göstermek için iki kapsama gösterilir.
  - Düzenli diller $\subseteq$ NFA dilleri: her DFA zaten bir NFA'dır.
  - NFA dilleri $\subseteq$ düzenli diller: her NFA denk bir DFA'ya dönüştürülebilir.
  - Lemma: NFA $M$, DFA $M'$'ye dönüştürülürse $L(M)=L(M')$ olur. $w=\sigma_1\sigma_2\cdots\sigma_k \in L(M)$ ise $M'$ $\{q_0\}$ etiketli durumdan başlar ve $k$ adım sonra $\{q_f,\dots\}$ etiketli bir kabul durumuna ulaşır. Bu yüzden $w \in L(M')$ olur (ekrandan, 01:10:00). Uzunluk üzerinden tümevarımla gösterilir. Ters yön de benzer biçimde gösterilir.
- **Dönüşüm örneği** (ekrandan, 01:20:00 ve 01:25:00): NFA $M$: $q_0 \xrightarrow{a} q_1$, $q_1$'de $a$ döngüsü, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$; kabul durumu $q_1$.
  - $\delta(\{q_0\},a)=\{q_1,q_2\}$, $\delta(\{q_0\},b)=\emptyset$ (tuzak durum).
  - $\delta(\{q_1,q_2\},a)=\{q_1,q_2\}$ (döngü), $\delta(\{q_1,q_2\},b)=\{q_0\}$.
  - İçinde $q_1$ bulunan $\{q_1,q_2\}$ durumu DFA'nın kabul durumudur. Geçiş tablosu python ile doğrulandı.
- **Tek kabul durumu** (ekrandan, 01:35:00): Birden çok kabul durumu olan bir NFA'nın kabul durumları normal duruma çevrilir. Bunlar $\varepsilon$ geçişleriyle yeni ve tek bir kabul durumuna bağlanır. Elde edilen NFA denktir. Hoca bazı kitapların boş dizgi için $\lambda$, bazılarının $\varepsilon$ kullandığını söyledi.
- **İşlem örnekleri** ($L_1=\{a^nb\}$, $n\ge 0$; $L_2=\{ba\}$):
  - Birleşim: yeni başlangıç durumundan $M_1$ ve $M_2$'nin başlangıçlarına $\varepsilon$ geçişi (ekrandan, 01:40:00).
  - Birleştirme: $L_1L_2=\{a^nbba\}$.
  - Yıldız: $L_1^*=\{a^nb\}^*$.
  - Ters çevirme: $L_1^R=\{ba^n\}$; geçişler ters çevrilir, başlangıç ve kabul durumu yer değiştirir (ekrandan, 01:45:00).
- **Tümleme** (ekrandan, 01:55:00): $L_1=\{a^nb\}$ için DFA: başlangıç durumunda $a$ döngüsü, $b$ ile kabul durumuna, oradan $a,b$ ile tuzak duruma (tuzakta $a,b$ döngüsü). Tümleyen $\overline{L_1}=\{a,b\}^*-\{a^nb\}$: başlangıç ve tuzak durumu kabul durumu, eski kabul durumu normal durum olur. Python ile doğrulandı.
- **Kesişim:** Hoca önce tümleme ve birleşim üzerinden giden bir yolu kısaca andı (büyük olasılıkla De Morgan: $L_1\cap L_2=\overline{\overline{L_1}\cup\overline{L_2}}$), sonra doğrudan yapıya geçti. $M$, $M_1$ ve $M_2$'yi paralel çalıştırır; durumları $(q_i,p_j)$ çiftleridir (ekrandan, 02:20:00). Kabul durumları her iki bileşeni de kabul durumu olan çiftlerdir. Üçer durumlu iki DFA için en çok $3\times 3=9$ durum oluşur.
  <!-- BELİRSİZ: Kesişim örneğindeki L1 ve L2 dilleri ile 9 durumlu DFA'nın geçişleri karelerde görünmüyor; hoca kesişimin {ab} olduğunu söyledi. -->
- **Düzenli ifadeler** (ekrandan, 02:25:00): İlkel düzenli ifadeler $\varepsilon$ ve $\alpha$'dır ($\alpha$ alfabeden bir sembol). $r_1$, $r_2$ düzenli ifadeyse $r_1+r_2$ (birleşim), $r_1\cdot r_2$ (birleştirme), $r_1^*$ (yıldız) ve $(r_1)$ de düzenli ifadedir. Örneğin $\{a,bc\}^*$ dili $(a+bc)^*$ ile ifade edilir.
  <!-- BELİRSİZ: Düzenli olan ve olmayan ifade örnekleri ile L(r) tanım slaytları karelerde görünmüyor. -->
- **Ders sonrası not:** Hoca slayttaki $L(M)=\{ab\}^*\cup\{ab\}^*\{aa\}$ ifadesini $\{ab\}^*\cup\{aa\}$ olarak sadeleştirmeyi önerdi ve ikisinin aynı olduğunu söyledi. Bu doğru değildir: $abaa$ makine tarafından kabul edilir (derste de gösterildi) ama $\{ab\}^*\cup\{aa\}$ kümesinde yoktur. Doğru sadeleştirme $\{ab\}^*\{\varepsilon, aa\}$'dır.
- **Ders sonrası not:** Slaytta $\delta^*(q_0,abaa)=\{q_4,q_5\}$ satırının sonunda "$aaba \in L(M)$" yazıyor. Doğrusu $abaa \in L(M)$'dir; $aaba$ makinece reddedilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
