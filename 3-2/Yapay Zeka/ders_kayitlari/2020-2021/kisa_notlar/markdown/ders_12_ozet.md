# Ders 12 Çalışma Özeti

## Genel Konular

- Pekiştirmeli öğrenme (reinforcement learning)
  - Türkçede destekleyici ya da takviyeli öğrenme diye de geçer. Sistem yine bir girdiye (durum, $S$) karşılık bir çıktı (hareket, $A$) üretmeyi öğrenir.
  - Sınıflandırma ve regresyondan farkı: sisteme doğru çıktı söylenmez. Yalnız ödül (artı) ya da ceza (eksi) verilir. Doğru hareketi sistem deneme yanılmayla keşfeder.
  - Ajan bir ortamda (environment) hareket eder. Her hareket (action) bir ödül (reward) ve yeni bir durum (state) üretir. Ajan, hareketleri boyunca topladığı toplam ödülü en büyük yapmaya çalışır (ekrandan, 00:05:00).
  - Ajanın hareketleri hangi verilere erişeceğini belirler. Ortamın bütün verisi en başta verilmez.
  - Olası bütün durumların erişilebilir olduğu simülasyon dünyalarında, yani oyunlarda iyi çalışır. Ajan kendi kendine oynayarak da eğitilebilir (ekrandan, 00:10:00).
- Temel kavramlar
  - Ortam (environment), durum (state), ödül (reward: ortamdan gelen geri besleme, ödül ya da ceza).
  - Politika (policy): ajanın durumlarını hareketlerine eşleyen tablo.
  - Değer (value): bir durumda bir hareket yapınca alınacak gelecek ödül.
- Örnek: "Eve gidelim" ortamı (ekrandan, 00:15:00)
  - 0 (başlangıç) ile 8 (ev) arasında 9 durum, her durumda 4 olası hareket (sağ, sol, yukarı, aşağı). 4 ve 5 çukurdur; oraya giren bölüm başarısız biter.
  - Ödüller yalnız 8'e giden hareketlerdedir (10 puan): 6'dan aşağı ve 3'ten sola.
  - $Q$ tablosu: satırları durumlar, sütunları hareketler olan matris. Başlangıçta bütün değerleri 0'dır, eğitimle değişir.
- Q-learning algoritması (ekrandan, 00:25:00)
  - Bölüm (episode): başlangıçtan başlayıp hedefle ya da başarısızlıkla biten hareket dizisi. Bölümlerin uzunluğu farklı olabilir.
  - Her bölümde: başlangıç durumuna git; bölüm bitmediği sürece politikaya göre hareket seç, hareketi yap, ödülü $R$ ve sonraki durumu $s'$ belirle, $Q$'yu güncelle, $s=s'$ yap.
  - Güncelleme kuralı: $Q[s,a] = Q[s,a] + \alpha\,(R + \gamma \max_{A} Q(s',A) - Q[s,a])$.
  - $\alpha$ öğrenme katsayısı, $\gamma \in (0,1)$ indirim katsayısıdır.
- Keşfetme ve kullanma ikilemi (exploration / exploitation)
  - Kullanmak: o ana kadar en iyi görünen hareketi seçmek ($Q[s,:]$ satırının en büyüğü).
  - Keşfetmek: en iyi görünmeyen bir hareketi de denemek (örneğin rastgele seçmek). Yeni durumlara erişir, uzun vadede iyileşme sağlayabilir.
  - Decay $\varepsilon$-greedy: rastgele hareket seçme olasılığı eğitim boyunca giderek azalır; benzetimli tavlamadaki sıcaklık gibi.
- Labirentten çıkış (ekrandan, 00:40:00)
  - Her beyaz kare bir durumdur, hareketler 4 yöndür. Her adıma $-1$ ödül verilirse ajan en kısa yolu öğrenir.
  - Öğrenilen tabloda her durumdaki en iyi hareket, çıkışa en kısa yoldan götüren harekettir.
- Yeni durumlar ve derin Q ağı (ekrandan, 01:05:00 ve 00:55:00)
  - Durum sayısı başta biliniyorsa $Q$ sabit boyutludur; yeni durumlar çıktıkça tabloya satır eklenebilir.
  - Q-learning daha önce görmediği bir durumun değerini bilemez. Olası çözüm: yeni durumu eldeki durumlardan en benzerine benzetmek.
  - Oyun ekranını durum olarak almak durum sayısını patlatır. Çözüm: ekranı (ve son birkaç kareyi) CNN ile işleyip $Q(s,a)$ değerlerini ya da hareketi doğrudan üretmek (Atari oyunları, deep Q-network).
- Yapay zeka, etik ve hukuk
  - Tanımlar: etik iyi ve kötüyü sorgular; hukuk devlet yaptırımıyla güçlendirilmiş kurallar bütünüdür; yapay zeka karar veren bir sistemdir (ekrandan, 01:10:00).
  - Verilerdeki önyargı, sorumluluk, yapay zekanın işler üzerindeki etkisi, manipülasyon ve kişisel veriler tartışıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ödüller birbirinden çok uzaksa öğrenme zorlaşır
  - Ödül genelde uzaktadır ama çok uzakta olmamalıdır. Seyrek ödüllü ortamlarda pekiştirmeli öğrenme algoritmaları başarısız olabilir.
- Ödül geriye doğru yayılır
  - Ortamdan hiç ödül gelmeyen bir hareketin değeri bile, vardığı durumdan ileride ödül toplanabiliyorsa artar. Böylece hedefe giden yolun bütün durumları ödüllendirilir.
- $\alpha$ ve $\gamma$ parametrelerinin anlamı
  - $\alpha$ küçükse geçmişte biriken değerlerin etkisi büyük kalır; büyükse son hareketlerin etkisi baskın olur. Eğitimin başında büyük, sonunda küçük tutulabilir.
  - $\gamma$ 0'a yakınsa yakın ödüllere, 1'e yakınsa gelecek ödüllere odaklanılır.
- Konfor alanı benzetmesi
  - Hep bildiğini yapan (yalnız kullanan) ajan daha iyi bir politikayı hiç keşfedemez. Tepe tırmanma yalnız kullanır; benzetimli tavlama keşfe şans tanır.
- En kısa yol için RL makul bir seçim değildir
  - Labirent örneği yalnız bir kullanım senaryosudur. Başlangıçla hedef arasındaki en kısa yol için A* gibi klasik algoritmalar çok daha etkilidir. RL algoritmaları yavaş yakınsar, analitik ve deterministik değildir.
- Anlık ekran görüntüsü durumu belirlemeye yetmeyebilir
  - Tek karede düşmanın yaklaştığı mı uzaklaştığı mı anlaşılmaz; son 3-5 kare kullanılmalıdır.
- Veride önyargı varsa model de onu öğrenir
  - Modelin verilerden başka bilgi kaynağı yoktur; verideki ayrımcılığı aynen yansıtır.

## Kısa Tekrar Notları

- Pekiştirmeli öğrenme = ödül/ceza ile eğitim; doğru cevap söylenmez.
- Ajan, ortam, durum, hareket, ödül, politika, değer.
- $Q$ tablosu: satır = durum, sütun = hareket, başlangıçta sıfır.
- $Q[s,a] \leftarrow Q[s,a] + \alpha(R + \gamma \max_A Q(s',A) - Q[s,a])$.
- Örnekte $\alpha=0{,}5$, $\gamma=0{,}9$: $Q[3,L]=5$, $Q[6,D]=5$, sonra $Q[2,L]=Q[2,D]=2{,}25$.
- Keşfet (rastgele) / kullan (en büyük $Q$); decay $\varepsilon$-greedy keşfi giderek azaltır.
- Her adıma $-1$ ödül vermek en kısa yolu öğretir.
- Görülmemiş durum: en benzer bilinen duruma benzet. Büyük durum uzayı: CNN ile deep Q-network.
- Oyunlar kapalı dünya (closed world) sistemleridir; RL orada çok iyi çalışır.
- Korelasyon nedensellik değildir; yüz tanıma gibi sistemlerin başarımı her alt grup için ayrı raporlanmalıdır.
- Ham veri ile işlenmiş veri farklıdır: tıklanan haberler siyasi tercihi, konum verisi rakip şirketle görüşmeyi ele verebilir.

## Detaylı Açıklamalar

- Pekiştirmeli öğrenmenin farkı
  - Sınıflandırma ve regresyonda her girdi için çıktının ne olması gerektiği (bir sayı ya da kategori) söylenir. Pekiştirmeli öğrenmede ise sisteme yalnız yaptığı hareketin sonucu olarak ödül ya da ceza verilir. Sistem rastgele ararken iyi bir şeye rastlarsa o hareketin iyi olduğunu kendisi anlar. Öğrenilmesi gereken şey hangi durumda ($S$) hangi hareketin ($A$) yapılacağıdır. Oyun örneğinde karakterin dört tuşla yapabileceği hareketler ve "hiçbir şey yapmamak" vardır; hiçbir şey yapmamak bile durumu değiştirebilir (rakip yaklaşıyorsa beklemek kötüdür). Simülasyon dünyası sisteme "kazandın, kaybettin, şu kadar puan aldın" der.
- Eve gidelim örneği ve Q tablosu
  - Ortamda 9 durum vardır: 0 başlangıç, 8 ev, 4 ve 5 çukur. Eğitim ilerledikçe $Q$ tablosu şöyle yorumlanır: örneğin 2 durumunda yukarı ve sağ 0, aşağı ve sol 2,25 değerindeyse 2'de aşağı ya da sola gitmek iyidir. 6'da aşağı gitmek 5 değerindedir. 4, 5 ve 8 durumlarının satırları sıfırdır, çünkü çukurlardan çıkış yoktur, 8 ise hedeftir.
  - Eğitim bitince tablo şöyle kullanılır: 0'da en büyük değer sola gitmektir (altyazıda 0,45 diye geçer), 1'e varılır. 1'de aşağı gidilir, 2'ye varılır. 2'de aşağı ve sol eşit değerdedir; aşağı seçilirse 3'e varılır. 3'te sola gidilir ve 8'e varılır. Birden fazla yol çıkabilir; puanı en yüksek olan (örneğin en kısa) yol seçilir.
- Güncelleme kuralının yorumu
  - $R$ şu anki hareketin anlık ödülüdür. $\max_A Q(s',A)$ ise hareket sonucu varılan $s'$ durumunda yapılabilecek bütün hareketlerin en büyük değeridir, yani o yoldan ileride toplanabilecek ödülün göstergesidir. Parantez içindeki fark artı da eksi de olabilir; $R$ eksi ise ya da $s'$'deki değer $Q[s,a]$'dan küçükse $Q[s,a]$ azalır.
  - Sayısal örnek ($\alpha=0{,}5$, $\gamma=0{,}9$, tablo başta sıfır): 3'te sola gidilirse $R=10$, $s'=8$ ve 8'in satırı sıfırdır. $Q[3,L] = 0 + 0{,}5\,(10 + 0{,}9 \cdot 0 - 0) = 5$. Aynı şekilde $Q[6,D] = 5$. Daha sonra 2'de sola gidilirse $R=0$, $s'=6$ ve $\max Q(6,\cdot)=5$ olduğundan $Q[2,L] = 0 + 0{,}5\,(0 + 0{,}9 \cdot 5 - 0) = 2{,}25$. Ödülün geriye yayılması böyle olur. (Python ile doğrulandı.)
  - Başta bütün değerler sıfır olduğundan ajan ilk ödüle rastlayana kadar rastgele dolaşır; tablo o ana kadar hiç değişmez.
- Labirent ve en kısa yol
  - Her durumda (son adım dahil) ödül $-1$ ise toplam ödülü en büyük yapmak, toplam cezayı en küçük yapmak demektir; ajan en kısa yolu bulur. Öğrenilen gelecek ödül tablosunda bitiş karesi $-1$, ona komşu kare $-2$ olur ve değerler başlangıca doğru azalır; başlangıç karesinin değeri $-16$'dır (ekrandan, 00:40:00). Tabloda yalnız başlangıçtan değil, her kareden çıkışa en kısa yol okunur.
- Büyük durum uzayları
  - $100 \times 100$ siyah-beyaz bir ekranda 10.000 piksel vardır, olası durum sayısı $2^{10000}$'dir; böyle bir $Q$ tablosu kurulamaz. Durum, ekrandan çıkarılan birkaç değişkenle (örneğin ajanın topa uzaklığı ve açısı) kodlanabilir ama bunu her oyuna elle uyarlamak verimli değildir. Derin öğrenmenin felsefesi, özellik çıkarıcıları insanın değil makinenin öğrenmesidir. Deep Q-network'te girdi son birkaç ekran karesi, çıktı her hareketin $Q$ değeridir. Yeni durumu benzerine benzetme işi de CNN'lerle kolaylaşır.
- Etik ve hukuk tartışması
  - Hukuk da etik de zamandan ve kültürden bağımsız değildir: kölelik bir zamanlar hukukiydi; İnsan Hakları Evrensel Beyannamesi 1948'de kabul edildi. Karar vermek hukukta sorumluluk almak demektir.
  - Verilerdeki önyargı: insan kaynakları cinsiyete ya da yaşa göre ayrımcılık yaptıysa o verilerle eğitilen model de yapar. Arama sonuçlarında "yemek yedi" ifadesi "öldürdü" ifadesinden çok daha az geçer, çünkü olağan şeyler yazılmaz; yazılı metinlerdeki sıklıklar gerçek dünyadakinden farklıdır. "Ameliyatı yapamam, bu benim oğlum" bilmecesinde cevap (doktor annedir) önyargı yüzünden geç bulunur. Önyargılar sezgisel kestirmelerdir ve onlarsız yaşanamaz; ama zararlı olanları vardır.
  - Korelasyon nedensellik değildir: çekilen kedi resmi sayısıyla trafik kazalarının birlikte artması gibi.
  - Sorumluluk: otonom araçlar da hata yapacaktır; bugünkü uygulamada otopilotu kullanma kararını veren araç sahibi sorumludur. Yeni durumlar için hukukta ya benzetme (içtihat) ya da yeni kanun gerekir.
  - İşler: ya küresel işsizlik ya da sanayi devrimindeki gibi bazı mesleklerin azalıp yenilerinin doğması (ya da arası). Tekrarlı işler makineye uygundur; zeka, yaratıcılık ve inisiyatif isteyen meslekler önem kazanır.
  - Manipülasyon: reklamcılığın tamamı bir kişinin fikrini video ve haberle değiştirmeye dayanır; bir ürünü aldırmakla bir partiye oy verdirmek dinamik olarak çok farklı değildir. Tıklama akışını optimize etmek, insanları anlamak yerine onları daha kolay tahmin edilebilir (refleksif) hale getirmeye dönüşebilir.
  - Kişisel veriler: hangi verinin ne amaçla, kimlerle paylaşıldığı açıklanmalıdır. İnsanlar veri paylaşmayı karşılığında aldıkları faydaya göre kabul eder (konum verisi ile yol tarifi, biyosensörler ile sağlık takibi gibi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
