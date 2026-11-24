# Ders 4 Çalışma Özeti

## Genel Konular

- Benzer kümelerin bulunması problemi ve uygulamaları
  - Amaç, tek bir bilgisayarın belleğine ya da diskine sığmayan, dağıtık olarak (örneğin HDFS'te) saklanan büyük veride birbirine benzeyen ikilileri bulmaktır.
  - Uygulamalar (ekrandan, 00:15:00 ve 00:20:00): benzer kelimeler içeren sayfaları konuya göre sınıflandırmak; filmlere benzer puan veren kullanıcıları bulmak (öneri sistemleri); bunun ikizi (dual) olarak benzer izleyici kitlesine sahip filmleri bulmak; varlık çözümleme (entity resolution), yani farklı sosyal medya sitelerindeki profillerin aynı kişiye ait olduğunu bulmak.
  - Benzer doküman uygulamaları: ayna (mirror) siteler, intihal (uzun alıntılar dahil) ve farklı haber sitelerinde aynı haberin kümelenmesi.
- Üç adımlı iş akışı ("The Big Picture", ekrandan, 00:25:00)
  - Doküman → **Shingling** → dokümanda geçen $k$ uzunluklu dizgilerin kümesi.
  - Küme → **Minhashing** → kümeleri temsil eden ve benzerliklerini yansıtan kısa tamsayı vektörleri (imzalar, signatures).
  - İmzalar → **Locality-Sensitive Hashing (LSH)** → benzerliği gerçekten test edilmesi gereken aday ikililer (candidate pairs).
- Shingling
  - $k$-shingle, dokümanda art arda geçen $k$ karakterlik dizidir. Doküman, $k$-shingle'larının kümesiyle temsil edilir; kümede her eleman bir kez yer alır.
  - Örnek: beş harflik `abcab` dokümanı, $k=2$ için $\{ab, bc, ca\}$ kümesine dönüşür (dördüncü ikili `ab` zaten kümede vardır).
  - Benzer dokümanların ortak shingle sayısı yüksektir; bir kelimeyi değiştirmek ya da paragrafların yerini değiştirmek yalnız az sayıda shingle'ı etkiler.
  - Uzun shingle'lar 4 baytlık tamsayılara hash'lenerek sıkıştırılabilir; bunlara **token** denir.
- Dokümanların Boolean matrisle gösterimi ve Jaccard benzerliği
  - Satırlar evrensel kümenin elemanları (bütün olası $k$-shingle'lar), sütunlar kümeler (dokümanlar) olur. Eleman kümedeyse hücre 1, değilse 0'dır. Matris tipik olarak seyrektir.
  - Jaccard benzerliği: $\text{Sim}(C_1, C_2) = |C_1 \cap C_2| / |C_1 \cup C_2|$.
  - Satır tipleri a (1,1), b (1,0), c (0,1), d (0,0) ile: $\text{Sim}(C_1, C_2) = a/(a+b+c)$ (ekrandan, 00:50:00).
- Minhashing
  - Satırlar rastgele permüte edilmiş gibi düşünülür. Minhash fonksiyonu $h(C)$, permüte sırada $C$ sütununun 1 içerdiği ilk satırın numarasıdır (ekrandan, 01:05:00).
  - Birçok (örneğin 100) bağımsız hash fonksiyonuyla her sütun için bir imza oluşturulur. İmzalar yan yana konunca **imza matrisi** (signature matrix) elde edilir: sütunlar kümeler, satırlar minhash değerleridir.
  - Sütun sayısı değişmez; satır sayısı hash fonksiyonu sayısına iner.
- Şaşırtıcı özellik
  - Rastgele permütasyonda $P[h(C_1) = h(C_2)] = \text{Sim}(C_1, C_2)$; ikisi de $a/(a+b+c)$'dir (ekrandan, 01:25:00).
  - İki imzanın benzerliği, aynı değeri aldıkları satırların oranıdır ve Jaccard benzerliğine yaklaşır.
- Minhashing'in pratik gerçeklenmesi
  - Milyar satırlık bir matriste permütasyon üretmek çok bellek ve zaman ister. Bunun yerine satır numarasını karıştıran basit hash fonksiyonları kullanılır.
  - İmza değerleri başta sonsuz yapılır; dış döngü satırlar, iç döngü sütunlar üzerinde çalışır; sütunda 1 varsa her hash fonksiyonu için küçük olan değer tutulur.
- Locality-Sensitive Hashing
  - Milyonlarca dokümanın bütün ikililerini karşılaştırmak çok pahalıdır; LSH hiç karşılaştırma yapmadan benzer olma olasılığı yüksek ikilileri bulur.
  - İmza matrisi her biri $r$ satırlık $b$ banda bölünür. Her bantta her sütunun o banttaki parçası bir hash fonksiyonuyla bir kovaya (bucket) atanır.
  - En az bir bantta aynı kovaya düşen ikililer aday ikilidir; yalnız bunların benzerliği hesaplanır.
  - Yanlış pozitif (benzer olmadığı halde aday olan) ve yanlış negatif (benzer olduğu halde aday olmayan) oranlarını en aza indirecek $b$ ve $r$ seçilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Minhash fonksiyonunun çalışması
  - Hoca bu kısmın çok önemli olduğunu söyleyip örneği Türkçe olarak da adım adım anlattı: permütasyonda 1, 2, 3, ... numaralı satırlara sırayla bakılır ve sütunda ilk 1 görülen satırın numarası imzaya yazılır.
- İmza benzerliği ile Jaccard benzerliğinin yakınlığı
  - Örnekte 1-3 sütunları için Jaccard 0,75, imza benzerliği 0,67; 2-4 için 0,75 ve 1,00; 1-2 için ikisi de 0'dır (ekrandan, 01:20:00). Yaklaşım tam eşit değildir ama gerçeğe yakındır.
- Neden aday ikili gerekir?
  - 100.000 doküman için $\binom{100000}{2} \approx 5$ milyar ikili vardır; hepsinin Jaccard benzerliğini hesaplamak çok zaman alır.
  - İmza matrisinin kendisi küçüktür: $4 \times 100 \times 100.000$ bayt = 40 MB, belleğe sığar. Darboğaz karşılaştırma sayısıdır.
- $k$ değerinin seçimi
  - $k$ küçük seçilirse (örneğin 2) neredeyse her doküman aynı shingle'ları içerir. Bu yüzden $k$ yeterince büyük (örneğin 10) seçilir; bu durumda shingle'lar token'lara hash'lenerek bellekten kazanılır.

## Kısa Tekrar Notları

- İş akışı: Shingling → Minhashing → LSH → aday ikililer → yalnız adaylar için gerçek benzerlik.
- $k$-shingle: dokümanda art arda geçen $k$ karakter. Doküman = shingle kümesi.
- Token: shingle'ın 4 baytlık hash değeri ($2^{32}$ farklı değer). Nadiren iki farklı shingle aynı token'a düşebilir.
- Jaccard: kesişim / birleşim. Satır tipleriyle $a/(a+b+c)$; d tipi (0,0) satırlar sayılmaz.
- Minhash: permüte sırada sütunun ilk 1'inin satır numarası. $P[h(C_1)=h(C_2)] = \text{Sim}(C_1,C_2)$.
- İmza matrisi: satır sayısı = hash fonksiyonu sayısı, sütun sayısı = doküman sayısı. Hücrelerde 0-1 değil, satır numaraları bulunur.
- Gerçekleme: başlangıçta $\infty$; her satır $r$ için $h_i(r)$ hesaplanır; sütunda $r$ satırında 1 varsa $\text{SIG}(i,c) = \min(\text{SIG}(i,c), h_i(r))$.
- LSH: $b$ bant × $r$ satır. En az bir bantta aynı kovaya düşen sütunlar aday ikilidir.
- $b=20$, $r=5$, benzerlik 0,8 için: bir bantta aynı olma olasılığı $0{,}8^5 = 0{,}328$; hiçbir bantta aynı olmama olasılığı $(1-0{,}328)^{20} \approx 0{,}00035$, yani yaklaşık 3000'de 1 yanlış negatif.
- Ders sonrası not: Hoca bu değeri sözlü olarak 0,0035 diye okudu; slayttaki ve hesaplanan değer 0,00035'tir (3000'de 1 ile tutarlı olan budur). Hoca ayrıca imza matrisinin "R tane banda" bölündüğünü söyledi; slayttaki gösterimde bant sayısı $b$, bant başına satır sayısı $r$'dir.

## Detaylı Açıklamalar

- **Uygulamalar.** Bir ay boyunca web taranıp bir milyon sayfa toplandığını düşünelim; aynı konudaki sayfaları bulmak bir benzer küme problemidir. Netflix ya da Amazon Prime Video gibi bir sitede satırları filmler, sütunları kullanıcılar olan bir puan matrisi kurulursa, sütun vektörlerini karşılaştırarak benzer zevkteki kullanıcılar bulunur; satırlar karşılaştırılırsa aynı türdeki (aksiyon, tarihî vb.) filmler bulunur. Varlık çözümlemede milyonlarca kişinin Facebook, Instagram, LinkedIn gibi sitelerdeki profillerinden aynı kişiye ait olanlar bulunur. Arama motoru, aynı içeriğin başka sunucuda kopyası olan ayna siteleri önceden tespit ederek sonuçlarda yalnız birini gösterir. Bir ajansın yayımladığı haberi başka sitelerin hemen kendi sitelerinde yayımlaması da benzer haberlerin kümelenmesi problemini doğurur.
- **Shingle'lar ve benzerlik sezgisi.** "The dog which chased the cat" cümlesi $k=3$ ile `The`, `he_`, `e_d`, ... `cat` gibi üçlülere ayrılır. "which" yerine "that" yazılınca yalnız `g_w`, `_wh`, `whi`, `hic`, `ich`, `ch_`, `h_c` olmak üzere 7 shingle değişir (ekrandan, 00:30:00). Slayttaki genel kural: bir kelimeyi değiştirmek yalnız o kelimeye $k$ uzaklıktaki shingle'ları etkiler; paragrafların yerini değiştirmek yalnız paragraf sınırlarını geçen $2k$ shingle'ı etkiler. Değişen shingle sayısı toplama göre küçük kaldığı için benzerlik yine yakalanır.
- **Sıkıştırma ve yanlış sonuçlar.** Shingle 4 baytlık bir tamsayıya hash'lenince her biri 4 bayt yer kaplar. $2^{32}$ yeterli değilse `long` kullanılabilir. Hash çakışması yüzünden iki doküman ortak shingle'ı varmış gibi görünebilir (slayt: "rarely"). Yöntem benzer olmayan ikiliyi benzer sayarsa yanlış pozitif, benzer ikiliyi kaçırırsa yanlış negatif oluşur; parametreler ikisini de azaltacak biçimde seçilir.
- **Boolean matris.** Bütün olası shingle'lar satırlara, dokümanlar sütunlara yazılır. $k$ büyük seçildiğinde olası shingle'ların çoğu bir dokümanda bulunmaz, bu yüzden matris seyrektir. İki sütunun benzerliği, 1 içeren satır kümelerinin Jaccard benzerliğidir. Hocanın gösterdiği iki sütunlu örnekte kesişimde 2, birleşimde 5 satır vardı ve benzerlik $2/5 = 0{,}4$ çıktı. <!-- BELİRSİZ: Bu örneğin sütun değerleri ekrandaki karelerde görünmüyor; yalnız sonuç altyazıdan alındı. -->
- **Minhashing örneği (ekrandan, 01:10:00).** Girdi matrisi 7 satır, 4 sütundur; üç permütasyon (mor, sarı, kahverengi) verilmiştir. Mor permütasyon için 1. sütunda permütasyon numarası 1 olan satırda 0 vardır, numarası 2 olan satırda 1 vardır; bu yüzden imza değeri 2'dir. Bu yolla imza matrisi şöyle bulunur:

  | Permütasyon | Sütun 1 | Sütun 2 | Sütun 3 | Sütun 4 |
  |---|---|---|---|---|
  | Mor (3,4,7,6,1,2,5) | 2 | 1 | 2 | 1 |
  | Sarı (4,2,1,3,6,7,5) | 2 | 1 | 4 | 1 |
  | Kahverengi (1,3,7,6,2,5,4) | 1 | 2 | 1 | 2 |

- **Hash fonksiyonlu gerçekleme örneği (ekrandan, 01:30:00).** Beş satırlı iki sütun $C_1 = (1,0,1,1,0)$, $C_2 = (0,1,1,0,1)$ ve $h(x) = x \bmod 5$, $g(x) = (2x+1) \bmod 5$ verilir. Satır satır güncellenen imzalar sonunda $C_1$ için $(1, 2)$, $C_2$ için $(0, 0)$ olur. Dördüncü satırda hash değerleri (4, 4) mevcut değerlerden büyük olduğu için hiçbir güncelleme yapılmaz.
- **LSH'de bantlar ve kovalar (ekrandan, 01:45:00).** Slayttaki şekilde bir banttaki 7 sütun parçası kovalara hash'lenir. 2. ve 6. sütunlar aynı kovaya düştüğü için bu bantta büyük olasılıkla aynıdır; 6. ve 7. sütunlar farklı kovalara düştüğü için bu bantta kesinlikle farklıdır. Benzerlik eşiği $t$ (1'den küçük bir oran) seçilir. İmza matrisinin $c$ ve $d$ sütunları, imzaları satırların en az $t$ oranında aynıysa aday ikili olmalıdır (ekrandan, 01:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
