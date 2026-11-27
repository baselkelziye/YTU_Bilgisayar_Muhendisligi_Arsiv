# Ders 9 Çalışma Özeti

## Genel Konular

- Ders büyük ölçüde İngilizce anlatıldı; bazı açıklamalar ve problem çözümleri Türkçe yapıldı.
  - Anlatım slaytlar üzerinde ve el yazısıyla yapılan çözümlerle ilerledi.
- Bağlamdan bağımsız diller için pompalama önsavı (pumping lemma for context-free languages)
  - Önsavın ifadesi: $z = uvwxy$ bölünmesi, $v$ ve $x$ parçalarının birlikte pompalanması.
  - "Kaç ilişki (sayım eşleşmesi) var?" sezgisi: $a^m b^n$ düzenli, $a^m b^m$ bağlamdan bağımsız, $a^m b^m c^m$ bağlamdan bağımsız değil.
  - İspat fikri: Chomsky normal biçimindeki (CNF) bir gramerin ayrıştırma ağacı, $n = 2^m$ seçimi ve ağaçta tekrar eden değişken.
  - Örnekler: $\{ww^R\}$, $\{ww\}$, $\{0^i 1 0^i\}$, $\{0^i 1 0^i 1 0^i\}$, $\{a^n b a^n\}$.
- Bağlamdan bağımsız gramerlerin sadeleştirilmesi (simplification of CFGs)
  - Yerine koyma (substitution) kuralı.
  - $\varepsilon$-üretimlerinin (boşa giden değişkenlerin, nullable variables) kaldırılması.
  - Birim üretimlerin (unit productions) kaldırılması.
  - Yararsız (useless) değişken ve üretimlerin kaldırılması: terminal dizgiye ulaşamayan ve başlangıçtan ulaşılamayan değişkenler.
  - El yazısıyla çözülen gramer sadeleştirme örnekleri (bir kısmı geçmiş sınav sorularından).
- Normal biçimler
  - Chomsky normal biçimi: $A \to BC$ ya da $A \to a$.
  - Greibach normal biçimi (GNF): $A \to a V_1 V_2 \cdots V_k$.
- Yığıtlı otomatlara (pushdown automata, PDA) giriş
  - Geçiş gösterimi $a, b \to c$: girdi $a$ okunur, yığıttan $b$ çekilir (pop), yığıta $c$ itilir (push).
  - $\{a^n b^n : n \ge 0\}$, $\{vv^R\}$ ve "$a$ sayısı = $b$ sayısı" dilleri için PDA'lar ve çalıştırma izleri.
  - PDA'ların belirlenimsizliği (non-determinism) ve dizginin ortasının "tahmin edilmesi".

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlamdan bağımsız olmayan diller genelde iki sayım çiftini ya da iki dizgiyi eşleştirmeye çalışır.
  - Tek bir ilişki ($a$ sayısı = $b$ sayısı gibi) bağlamdan bağımsız dille kurulabilir; üç sayının birbirine eşit olması gerekiyorsa dil bağlamdan bağımsız değildir.
- Sadeleştirme sırası önemlidir.
  - Önce $\varepsilon$-üretimleri, sonra birim üretimler, en son yararsız değişkenler kaldırılır. Bu sıra istenmeyen değişken ve üretimlerin gerçekten temizlenmesini garanti eder.
- Bir üretim kaldırılırken önce var olan üretimler aynen yazılır, sonra kaldırılan üretimden kaynaklanan yeni seçenekler eklenir.
- Kendine dönen üretimler ($A \to aA$, $B \to BB$ gibi) terminale ulaşabiliyorsa yararlıdır ve kaldırılamaz.
  - Bunları yerine koyarak gidermeye çalışmak grameri sadeleştirmez, üretim sayısını artırır.
- CNF, gramerin yazılımda kolayca gerçeklenmesini sağlar; ayrıştırma ve teorem ispatlarında kullanılır.
- PDA'da çok sembollü pop/push sırasına dikkat edilmelidir.
  - $a, eb \to cdf$: önce $e$, sonra $b$ çekilir; önce $f$, sonra $d$, en son $c$ itilir ($c$ yığıtın tepesinde kalır).

## Kısa Tekrar Notları

- **CFL pompalama önsavı (slayttaki biçim):** Her bağlamdan bağımsız $L$ için bir $n$ vardır; $|z| > n$ olan her $z \in L$, $z = uvwxy$ biçiminde yazılabilir ve $|vwx| < n$, $|vx| > 0$, her $i$ için $uv^iwx^iy \in L$ (ekrandan, 00:15:00).
  - Standart biçim: $|z| \ge n$, $|vwx| \le n$, $|vx| \ge 1$ ve her $i \ge 0$ için $uv^iwx^iy \in L$.
- Önsav yalnız bir dilin bağlamdan bağımsız **olmadığını** göstermek için kullanılır (çelişkiyle ispat; bütün bölünmeler denenmelidir).
- $\{ww^R\}$ ve $\{0^i 1 0^i\}$ bağlamdan bağımsızdır; $\{ww\}$ ve $\{0^i 1 0^i 1 0^i\}$ değildir.
- **Yerine koyma:** $B \to b$ üretimini kaldırmak için $B$ geçen her sağ tarafa $b$'li bir kopya eklenir.
- **$\varepsilon$ kaldırma:** $M \to \varepsilon$ ise $M$ geçen her sağ tarafa $M$'siz bir kopya eklenir.
- **Birim üretim:** $A \to B$ kaldırılırken $B$'nin sağ tarafları $A$'ya eklenir; $B \to B$ doğrudan silinir.
- **Yararsız değişken:** terminal dizgi üretemeyen ya da başlangıç değişkeninden ulaşılamayan değişken.
- **CNF dönüşümü:** her terminal için $T_a \to a$ eklenir; uzunluğu $n$ olan sağ taraf $n-2$ yeni değişkenle ikili parçalara bölünür.
- **GNF:** her üretim bir terminalle başlar, ardından yalnız değişkenler gelir.
- **PDA:** yığıt başta $\$$ içerir; $\varepsilon, \$ \to \$$ geçişi "yığıt boş" sınamasıdır.
- $\{a^n b^n\}$ PDA'sı: her $a$ için $a$ itilir, her $b$ için $a$ çekilir; sonunda yalnız $\$$ kalırsa kabul.
- $\{vv^R\}$ PDA'sı: önce okunan semboller itilir, $\varepsilon$ geçişiyle orta tahmin edilir, sonra eşleşen semboller çekilir.

## Detaylı Açıklamalar

- **Kaç ilişki var?** Hoca dilleri sembol sayıları arasındaki ilişki sayısına göre sınıflandırdı.
  - $L_1 = \{a^m b^n \mid m, n \ge 0\}$: $a$ ve $b$ sayıları arasında ilişki yoktur; dil düzenlidir (dolayısıyla bağlamdan bağımsızdır).
  - $L_2 = \{a^m b^m \mid m \ge 0\}$: tek ilişki vardır ($a$ sayısı = $b$ sayısı); dil bağlamdan bağımsızdır.
  - $\{a^m b^m c^m \mid m \ge 0\}$: $a$-$b$, $b$-$c$ ve $a$-$c$ arasında ilişki vardır; dil bağlamdan bağımsız değildir.
  - Ekranda önceki sayfalarda şu örnekler de görünür: $\{a^n b^m c^k \mid n > k, m > k\}$ bağlamdan bağımsız değil; $\{a^n b^n c^n \mid n \le 5\}$ sonlu olduğu için bağlamdan bağımsız (ekrandan, 00:10:00).
- **İspat fikri.** $m$ değişkenli bir CNF gramer alınır ve $n = 2^m$ seçilir. CNF ağacında her iç düğümün iki çocuğu olduğundan $|z| > n$ olan bir dizginin ağacında $m+1$'den fazla değişken içeren bir yol bulunur; güvercin yuvası ilkesiyle bir değişken tekrar eder. Tekrar eden değişkenin alt ağacı çıkarılırsa $uv^0wx^0y = uwy$, iki kez yerleştirilirse $uv^2wx^2y$ elde edilir (ekrandan, 00:20:00).
  - Slaytta Lemma 1: $|z| > n$ ise ayrıştırma ağacında uzunluğu $m+2$ ya da daha fazla bir yol vardır.
- **$L = \{0^i 1 0^i 1 0^i \mid i \ge 1\}$ bağlamdan bağımsız değildir.** $z = 0^n 1 0^n 1 0^n$, $|z| = 3n+2 > n$ seçilir. Hoca $n = 3$ ile $z = 000\,1\,000\,1\,000$ üzerinde bir bölünme denedi ve $uwy$'nin dile ait olmadığını gösterdi (ekrandan, 00:35:00).
  - Slayttaki durum 1: $vx$ hiç 0 içermiyorsa en az biri 1'dir ve $uwy$ en çok bir tane 1 içerir; dildeki hiçbir dizgi böyle değildir.
- **Önsavı sağlayan dil: $\{a^n b a^n\}$.** $n = 3$, $z = aaabaaa$, $u = aa$, $v = a$, $w = b$, $x = a$, $y = aa$ bölünmesiyle $uv^iwx^iy = a^{i+2} b a^{i+2}$ her $i$ için dildedir (ekrandan, 00:40:00).
  - Önsavı sağlamak dilin bağlamdan bağımsız olduğunu ispatlamaz; bunun için bir gramer (örneğin $S \to aSa \mid b$) verilmelidir.
- **Sadeleştirme örnekleri (slaytlardan).**
  - Yerine koyma: $S \to aB$, $A \to aaA \mid abBc$, $B \to aA \mid b$ grameri, $B \to b$ kaldırılınca $S \to aB \mid ab$, $A \to aaA \mid abBc \mid abbc$, $B \to aA$ olur (ekrandan, 00:45:00).
  - $\varepsilon$ kaldırma: $S \to aMb$, $M \to aMb \mid \varepsilon$ grameri $S \to aMb \mid ab$, $M \to aMb \mid ab$ olur (ekrandan, 00:50:00).
  - Birim üretim örneğinin son grameri: $S \to aA \mid aB$, $A \to a$, $B \to bb$; tekrarlanan $aA$ seçeneği silinir (ekrandan, 00:55:00).
- **Yararsız üretim örneği (slayt):** $S \to aS \mid A \mid C$, $A \to a$, $B \to aa$, $C \to aCb$. $C$ hiçbir zaman terminal dizgiye ulaşmaz (kendine kilitlenir), $B$ başlangıçtan ulaşılamaz; ikisi de silinir (ekrandan, 01:15:00).
- **Derste çözülen sadeleştirme örnekleri.**
  - $S \to aSS \mid AB \mid B$, $A \to aA \mid S$: $B$'nin üretimi yoktur, $AB$ ve $B$ silinir; geriye kalan $S \to aSS$ hiç sonlanmaz. Gramer hiçbir dizgi üretmez (ekrandan, 01:25:00).
  - $S \to aS \mid aB \mid b$, $B \to BB \mid a$, $C \to B$: $C$ ulaşılamaz ve silinir; $B \to BB$ terminale ulaşabildiği için kalır (ekrandan, 01:40:00). <!-- BELİRSİZ: karede ikinci satır "S → b" olarak okunuyor ve yanında kırmızı bir işaret var; satırın anlamı altyazıdan net çıkmıyor. -->
    - Hoca önce $B \to BB$ üretimini de kaldırmayı denedi; bir öğrencinin uyarısıyla $B \to BB$'nin kendine döndüğü ve kaldırılamayacağı kabul edildi.
  - $S \to 0S0 \mid 1A1$, $A \to 0A \mid b$: $A \to 0A$ kendine döndüğü için giderilemez; gramer daha fazla sadeleşmez (ekrandan, 01:35:00).
  - $S \to X \mid Xb \mid Xbb$, $X \to Xa \mid cX \mid cXa \mid \varepsilon$: $\varepsilon$ kaldırılınca $S \to X \mid Xb \mid Xbb \mid bb \mid b \mid \varepsilon$, $X \to cXa \mid cX \mid Xa \mid ca \mid c \mid a$ elde edilir (ekrandan, 01:55:00).
- **CNF dönüşümü (slayt).** Sonuç gramer: $S \to AV_1$, $V_1 \to BT_a$, $A \to T_aV_2$, $V_2 \to T_aT_b$, $B \to AT_c$, $T_a \to a$, $T_b \to b$, $T_c \to c$ (ekrandan, 02:10:00). Bu, $S \to ABa$, $A \to aab$, $B \to Ac$ gramerinin CNF karşılığıdır.
- **GNF (slayt).** $S \to cAB$, $A \to aA \mid bB \mid b$, $B \to b$ GNF'dir; $S \to abSb \mid aa$ değildir. Hoca bunu $S \to aBSB \mid aA$, $A \to a$, $B \to b$ biçimine çevirdi (ekrandan, 02:15:00).
- **PDA örnekleri.**
  - $\{a^n b^n : n \ge 0\}$: $q_0 \xrightarrow{\varepsilon,\varepsilon\to\varepsilon} q_1$, $q_1$'de döngü $a,\varepsilon \to a$, $q_1 \xrightarrow{b,a\to\varepsilon} q_2$, $q_2$'de döngü $b,a \to \varepsilon$, $q_2 \xrightarrow{\varepsilon,\$\to\$} q_3$; $q_0$ ve $q_3$ kabul durumudur (ekrandan, 02:25:00). $aaabbb$ kabul, $aab$ ret edilir.
  - $\{vv^R : v \in \{a,b\}^*\}$: $q_0$'da $a,\varepsilon \to a$ ve $b,\varepsilon \to b$; $q_0 \xrightarrow{\varepsilon,\varepsilon\to\varepsilon} q_1$; $q_1$'de $a,a \to \varepsilon$ ve $b,b \to \varepsilon$; $q_1 \xrightarrow{\varepsilon,\$\to\$} q_2$ (ekrandan, 02:35:00).
  - $a$ sayısı = $b$ sayısı: tek durumda $a,\$ \to 0\$$, $a,0 \to 00$, $a,1 \to \varepsilon$, $b,\$ \to 1\$$, $b,1 \to 11$, $b,0 \to \varepsilon$; $q_1 \xrightarrow{\varepsilon,\$\to\$} q_2$ (ekrandan, 02:50:00). Yığıtta fazla gelen sembolün sayısı tutulur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
