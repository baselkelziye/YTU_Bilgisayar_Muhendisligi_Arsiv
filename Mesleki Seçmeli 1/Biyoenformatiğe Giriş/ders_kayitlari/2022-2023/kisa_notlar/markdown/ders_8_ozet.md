# Ders 8 Çalışma Özeti

## Genel Konular

- Blok analizi (lokal çoklu dizi hizalama)
  - Bloklar, profiller gibi çoklu hizalamadaki lokal korunmuş bölgeleri temsil eder. Farkları: bloklarda boşluk (gap, indel) yoktur; her sütunda yalnız eşleşme ve uyuşmazlık bulunur.
  - Bloklar ya önce çoklu hizalama yapılıp boşluksuz bölgeler ayrılarak ya da veri tabanında aynı uzunlukta benzer diziler aranarak bulunur.
  - Blok arayan algoritmalar sezgiseldir (heuristic), optimal değildir. En benzer dizileri bulmak için istatistiksel yaklaşımlar kullanılır: Beklenti-Maksimizasyon (EM) ve Gibbs örneklemesi (ekrandan, 00:10:00).
  - Yaygın paketler: BLOCKS ve eMOTIF <!-- BELİRSİZ: ikinci paket adı altyazıda "emotive" diye geçiyor, karede görülmedi -->. Örnek olarak 10 kesilmiş protein kinaz dizisinde BLOCKS sunucusunun bulduğu iki blok gösterildi (ekrandan, 00:15:00).
- Beklenti-Maksimizasyon (EM) algoritması
  - Başlangıçta motif uzunluğu verilir ve her dizide motifin yeri rastgele seçilir.
  - Beklenti adımı: motif dışındaki kalıntılardan arka plan frekansları, motifin her sütunu için sütun frekansları hesaplanır (ekrandan, 00:20:00).
  - Maksimizasyon adımı: bu frekanslarla her dizide motife en iyi uyan konum bulunur; yeni konumlarla beklenti adımı tekrarlanır, çözüm yakınsayana kadar devam edilir (ekrandan, 00:25:00).
  - Sıfır sayımları önlemek için yalancı sayım (pseudocount) eklenir: $P_{ca} = (n_{ca} + b_{ca}) / (N_c + B_c)$ (ekrandan, 00:40:00).
- EM için çalışılmış DNA örneği
  - 29 dizi, 6 baz genişliğinde motif: $29 \times 6$ blok. Yedi frekans kümesi hesaplanır: biri arka plan, altısı motif sütunları (ekrandan, 00:30:00).
  - Birinci dizi 41 bazdır; $41 - 6 + 1 = 36$ aday konum vardır (ekrandan, 00:45:00).
  - Her aday 6'lı için motif olasılığı (sütun olasılıklarının çarpımı), arka plan olasılığı (RANDOM) ve oranları (ODDS) hesaplanır; en yüksek oranlı `CAGTTA` (1.23) yeni konum seçilir (ekrandan, 00:50:00).
- EM programları
  - MEME (Multiple EM for Motif Elicitation), EM'i kullanan programdır (ekrandan, 01:05:00). Türevleri: blok arayan ParaMEME, profilleri gizli Markov modelleriyle arayan Meta-MEME.
  - MEME en olası motif genişliğini log-olabilirlik skoruna göre belirler. OOPS, ZOOPS (dizi başına 0 ya da 1 motif) ve TCM (iki bileşenli karışım) modelleri anıldı.
- Gibbs örneklemesi
  - EM'e benzer; EM ile benzetimli tavlamayı (simulated annealing) birleştirir. Amaç, motif olasılıklarından örnekleyerek model/arka plan olasılık oranını en büyütmektir (ekrandan, 01:10:00).
  - EM'den farkı: motif başlangıç konumu, normalize edilmiş oranlarla ağırlıklandırılmış rastgele örneklemeyle seçilir.
- Markov zincirleri ve gizli Markov modelleri (HMM)
  - HMM'ler sembol dizilerini modelleyen olasılıksal modellerdir; kökü konuşma tanımadır. Eşleşme, uyuşmazlık, ekleme ve silmeyi modelleyebilir.
  - Markov zincirinde bir sembolün olasılığı yalnız bir önceki sembole bağlıdır (ekrandan, 01:20:00). DNA için A, C, G, T dört durumdur; başlangıç ve bitiş hariç 16 geçiş vardır.
  - CpG adaları: metilasyon yüzünden genomda CG dinükleotidi azdır; bazı bölgelerde (genlerin başlangıç bölgeleri gibi) metilasyon bastırılır ve CG fazla bulunur. CpG ve CpG olmayan bölgeler için iki ayrı geçiş tablosu kurulur (ekrandan, 01:25:00).
  - Bir dizinin olasılığı geçiş olasılıklarının çarpımıdır; iki modelin verdiği olasılıklar karşılaştırılarak dizinin hangi modelden geldiğine karar verilir (ekrandan, 01:30:00).
- PSSM, entropi ve dizi logoları
  - Konuma özgü skorlama matrisindeki (PSSM) bilgi, frekansların logaritmik dönüşümüdür. Eğitim verisine yanlılık sorunu vardır (ekrandan, 01:35:00).
  - Belirsizliğin ölçüsü entropidir. Dizi logoları her sütundaki bilgiyi harf yüksekliğiyle gösterir (ekrandan, 01:40:00).
- Dizi dosya biçimleri (hatırlatma)
  - FASTA: `>` ile başlayan açıklama satırı ve ardından dizi satırları (ekrandan, 01:45:00). GenBank: alanlara ayrılmış kayıt, dizi `ORIGIN` ile `//` arasında. ASN.1 diğer biçimlerdeki bilgilerin hepsini içerir.
- Filogenetiğe giriş
  - Filogenetik, organizmalar arasındaki evrimsel ilişkilerin incelenmesidir; sistematiğin parçasıdır. Taksonomi adlandırma ve sınıflandırmadır.
  - Moleküler filogenetiğin kısa tarihi (ekrandan, 02:00:00) ve moleküler verinin morfolojik/fizyolojik veriye üstünlükleri.
  - Ağaç terimleri: düğüm, yaprak (OTU, takson), iç düğüm, kök, dendrogram, kladogram, topoloji, monofiletik ve parafiletik gruplar, gen ağacı ve tür ağacı.
  - Köklü ve köksüz ağaç sayısı formülleri (ekrandan, 02:15:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bloklarla profiller arasındaki tek fark boşluktur
  - Bloklar boşluksuzdur; her sütunda yalnız eşleşme ve uyuşmazlık vardır. Profiller ise boşluk içerebilir.
- Çoklu hizalama algoritmaları sezgiseldir
  - Hoca blok bulma dahil çoklu hizalama algoritmalarının optimal olmadığını yineledi.
- Kategorik veriyi sayısal veriye çevirmek
  - Dizi verisi nominal (kategorik) veridir. EM'in ilk adımında frekans hesabıyla sayısal veriye çevrilir; olasılıklar frekans oranlarıdır.
- Uzun dizide olasılık çarpımı çok küçülür
  - 1'den küçük sayılar çarpıldığı için uzun dizilerde olasılık sıfıra çok yaklaşır.
- Ağaçta yalnız topoloji anlamlıdır
  - Dallar düğümler etrafında döndürülebilir; yapraklar yer değiştirse de aynı topolojiyse aynı bilgi verilir.

## Kısa Tekrar Notları

- Blok = boşluksuz lokal korunmuş bölge; profil boşluk içerebilir.
- Blok bulma: EM ve Gibbs örneklemesi; paketler BLOCKS, eMOTIF.
- EM: rastgele başlangıç → beklenti (arka plan ve sütun frekansları) → maksimizasyon (her dizide en iyi konum) → yakınsayana kadar tekrar.
- $L$ uzunluklu dizide $w$ genişlikli motif için $L - w + 1$ aday konum vardır ($41 - 6 + 1 = 36$).
- Aday skoru: motif olasılıklarının çarpımı / arka plan olasılıklarının çarpımı (odds).
- Yalancı sayım: $P_{ca} = (n_{ca} + b_{ca}) / (N_c + B_c)$; toplam yalancı sayım 1 ve dört nükleotit eşit olasılıklıysa her biri $1/4$.
- MEME: Multiple EM for Motif Elicitation; ParaMEME bloklar, Meta-MEME HMM ile profiller.
- Gibbs: EM + benzetimli tavlama; başlangıç konumu ağırlıklı rastgele örnekleme ile seçilir.
- Markov zinciri: $p(S_p)$ yalnız $S_{p-1}$'e bağlı. DNA'da 16 geçiş.
- CpG adası tespiti: CpG ve CpG olmayan geçiş tabloları, dizi olasılıklarının karşılaştırılması.
- PSSM bilgisi frekansların logaritmik dönüşümüdür; belirsizlik ölçüsü entropidir; dizi logosu görselleştirmedir.
- FASTA: `>` açıklama satırı + dizi.
- Kladogram yalnız topolojiyi gösterir; zaman ve genetik uzaklık bilgisi yoktur.
- Köklü ağaç sayısı $\frac{(2n-3)!}{2^{n-2}(n-2)!}$, köksüz ağaç sayısı $\frac{(2n-5)!}{2^{n-3}(n-3)!}$.

## Detaylı Açıklamalar

- **Blok analizi.** Önceki derste profiller anlatılmıştı. Bloklar da çoklu hizalamadaki lokal korunmuş bölgelerdir, ama boşluk içermez. Ekrandaki örnekte 10 protein kinaz dizisinin yaklaşık 75 kalıntılık kesilmiş bölümleri hizalanmış ve BLOCKS sunucusu iki boşluksuz blok bulmuştur; altta korunmuş kalıntılar `cons` satırında gösterilir (ekrandan, 00:15:00). Protein kinazlar diğer proteinlere fosfat grubu ekleyen (fosforilasyon) enzimlerdir; hoca insan genomunda yaklaşık 500 protein kinaz geni bulunduğunu, bunların insan genlerinin yaklaşık %2'si olduğunu söyledi.
- **EM'in beklenti adımı.** Rastgele seçilen bloklardan iki tür frekans hesaplanır. Arka plan frekansı, blok dışında kalan bütün kalıntılardaki her nükleotidin sayısıdır. Sütun frekansı, bloğun her sütunundaki nükleotit sayısıdır. Örnekte 29 dizi ve 6 sütun olduğundan 7 sayım kümesi oluşur. Hoca arka plandaki A oranını $279 / 1046 \approx 0.267$ olarak hesapladı. Gözlenen frekans tablosu (ekrandan, 00:35:00):

  | Nükleotit | 0 (arka plan) | 1 | 2 | 3 | 4 | 5 | 6 |
  |---|---|---|---|---|---|---|---|
  | A | 0.267 | 0.209 | 0.414 | 0.209 | 0.209 | 0.379 | 0.241 |
  | C | 0.267 | 0.276 | 0.103 | 0.172 | 0.241 | 0.241 | 0.241 |
  | G | 0.216 | 0.310 | 0.276 | 0.345 | 0.241 | 0.172 | 0.276 |
  | T | 0.250 | 0.209 | 0.209 | 0.276 | 0.310 | 0.209 | 0.241 |

- **Yalancı sayım.** Bir sütunda bir nükleotit hiç görülmezse olasılığı sıfır olur ve çarpım sıfırlanır. Bunu ve aşırı öğrenmeyi önlemek için $P_{ca} = (n_{ca} + b_{ca}) / (N_c + B_c)$ kullanılır. $n_{ca}$: $c$ sütunundaki $a$ sayısı, $b_{ca}$: onun yalancı sayımı, $N_c$: sütundaki toplam sayım, $B_c$: sütunun toplam yalancı sayımı. Yalancı sayımın seçimi keyfidir.
- **EM'in maksimizasyon adımı.** Birinci dizi `TCAGAACCAGTTATAAATTTATCATTTCCTTCTCCACTCCT` 41 bazdır ve başlangıç bloğu `ATTTAT`'tır (ekrandan, 00:45:00). 36 adayın her biri için altı konum olasılığının çarpımı (motif olasılığı) ve arka plan olasılıklarının çarpımı (RANDOM) bulunur, oranı alınır. `CAGTTA` için çarpım $0.263 \cdot 0.296 \cdot 0.246 \cdot 0.261 \cdot 0.241 \cdot 0.263 = 0.000317$, arka plan $0.000257$, oran $1.23$ ile en büyüktür; bu dizi için yeni motif konumu budur (ekrandan, 00:50:00). Aynı işlem bütün dizilere yapılır, yeni blokla frekanslar yeniden hesaplanır ve bloklar değişmeyene kadar döngü sürer.
- **Markov zinciri ile ayırt etme.** CpG adası tablosunda örneğin $a_{AG} = 0.426$, $a_{CG} = 0.274$ (ekrandan, 01:25:00). Bir dizinin olasılığı ilk sembolün olasılığı ile ardışık geçiş olasılıklarının çarpımıdır. Aynı dizi iki modelde hesaplanır; hangi modelde olasılık büyükse dizi o modelden gelmiş sayılır. İki model birbirinden yeterince farklı değilse ayırt etmek için yeterli bilgi yoktur (ekrandan, 01:30:00). <!-- BELİRSİZ: Hocanın olasılığını hesapladığı örnek dizi ve sonuç değerleri altyazıdan ve karelerden okunamadı. -->
- **Filogenetik ağaçlar.** Ağaçta yapraklar operasyonel taksonomik birimlerdir (OTU, takson); veri madenciliğinde uç düğüm ya da yaprak denir. Ağaç genelde soldan sağa çizilir ve sol taraf geçmişi gösterir. Dallar düğüm etrafında döndürülebilir, bu yüzden yalnız topoloji anlamlıdır. Dendrogram hiyerarşik kümelemenin sonucunu gösteren ağaçtır. Kladogram yalnız topolojiyi gösterir (ekrandan, 02:10:00). Olası ağaç sayısı tür sayısıyla çok hızlı büyür: 4 türde 15 köklü ve 3 köksüz, 10 türde 34,459,425 köklü ağaç vardır (ekrandan, 02:15:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
