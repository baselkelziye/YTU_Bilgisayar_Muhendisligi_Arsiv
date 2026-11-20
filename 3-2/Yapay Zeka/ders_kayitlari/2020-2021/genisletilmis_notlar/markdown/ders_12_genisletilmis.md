# Ders 12 Genişletilmiş Notu: Pekiştirmeli Öğrenme (Q-Learning) ve Yapay Zekanın Etik-Hukuki Boyutu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Pekiştirmeli Öğrenmeye Giriş
- 2. Temel Kavramlar
- 3. Eve Gidelim Örneği ve Q Tablosu
- 4. Bölüm ve Politika
- 5. Keşfetmek ve Kullanmak İkilemi
- 6. Q-Learning Algoritması
- 7. Sayısal Örnek: Q Güncellemeleri
- 8. Labirentten Çıkış ve En Kısa Yol
- 9. Yeni Durumlar ve Büyük Durum Uzayları
- 10. Atari Oyunları ve Deep Q-Network
- 11. Yapay Zeka, Etik ve Hukuk
- Örnek Sorular

## 1. Pekiştirmeli Öğrenmeye Giriş

Bu ders, makine öğrenmesi bölümünün üçüncü kısmıdır ve dönemin son dersidir. Önceki iki haftada sınıflandırma ve kümeleme yöntemleri tamamlanmıştı. Bu derste önce pekiştirmeli öğrenme (reinforcement learning), sonra yapay zekanın etik ve hukukla ilişkisi işlenir.

Reinforcement learning Türkçeye farklı kişilerce farklı çevrilmiştir: pekiştirmeli, destekleyici ya da takviyeli öğrenme. Hepsi aynı şeydir (ekrandan, 00:05:00).

### 1.1 Önceki problemlerden farkı

Şimdiye kadar gördüğümüz sistemlerde bir girdi vardı ve bu girdiye karşılık bir çıktı üretmeye çalışıyorduk. Pekiştirmeli öğrenmede de aynı şey yapılır: bir girdiye karşılık bir çıktı üretilir. Fark, eğitimde kullanılan verinin niteliğindedir.

Sınıflandırma ve regresyonda sisteme bir girdi verilir ve o girdi gelince çıktının ne olması gerektiği söylenir: "böyle bir şey gelirse şu çıkışı ver". Bu çıktı regresyonda bir sayı, sınıflandırmada bir kategoridir. Pekiştirmeli öğrenmede ise sistemin ne yapması gerektiği doğrudan söylenmez. Onun yerine ödül ya da ceza verilir. Doğru hareketin ne olduğunu sistemin kendisi keşfetmelidir: rastgele ararken bir şeye rastlarsa onun iyi bir hareket olduğunu anlaması beklenir.

Slayttaki maddeler şöyledir (ekrandan, 00:05:00):

- Ödül/ceza ile eğitim.
- Ödül genelde uzakta.
- Hangi durumda ($S$) hangi hareketin ($A$) yapılacağı öğrenilir.
- Ne yapması gerektiğini söylemeyiz. Ödül/ceza veririz sadece.
- Ajan, toplam ödülü maksimize etmeye çalışır.
- Ajanın hareketleri hangi verilere erişeceğini belirler.

Ödül genelde uzaktadır ama çok çok uzakta olmamalıdır. Ödüller birbirinden ne kadar uzaksa sistem o kadar zor öğrenir; çok uzak olursa pekiştirmeli öğrenme algoritmaları başarılı olamaz. Ödüllerin sıklığı, ortamın öğrenilebilirliğini doğrudan etkiler.

Ajanın hareketlerinin hangi verilere erişeceğini belirlemesi şu demektir: ortama dair bütün veriler en başta ajana verilmez. Ajanın erişebildiği veriler, yaptığı hareketlere bağlı olarak ortaya çıkar.

### 1.2 Ajan-ortam döngüsü

Slayttaki şemada bir ajan (agent) ve bir ortam (environment) vardır (ekrandan, 00:05:00). Ajan $t$ anında $S_t$ durumundadır ve bir $A_t$ hareketi (action) yapar. Ortam buna karşılık bir ödül $R_{t+1}$ ve yeni bir durum $S_{t+1}$ döndürür. Ödül artı ise ödül, eksi ise ceza anlamındadır.

Hoca bunu oyunlarla örnekledi. Pekiştirmeli öğrenme genelde oyunlarda kullanılır. Tuşlarla oynanan bir oyunda karakterin o an yapabileceği dört hareket (dört tuş) ve bir de "hiçbir şey yapmamak" olabilir. Hiçbir şey yapmamak her oyunda durumu değiştirmez anlamına gelmez: bir rakip size doğru yaklaşıyorsa olduğunuz yerde beklemek kötü olabilir, başka bir yöne gitmek gerekebilir. Yani yapılan her hareket hem bir sonraki durumu hem de ortamdan alınan ödülü üretir. Ajanın öğrenmesi gereken şey şudur: hangi durumda ($S$) hangi hareketi ($A$) yapmalıyım?

### 1.3 Nerede iyi çalışır

Slayta göre pekiştirmeli öğrenme, olası tüm durumların erişilebilir olduğu simülasyon dünyalarında (oyunlarda) iyi çalışır (ekrandan, 00:10:00). Oyunlarda sonlu sayıda durum vardır ve ajan kendi kendine ya da bir insana karşı oynayabilir. Kendi kendine eğitim de mümkündür: ajan kendisine karşı oynatılarak iyi sonuçlar elde etmesi sağlanabilir. Simülasyon dünyası öğrenen sisteme "oyunu kazandın", "kaybettin" ya da "şu kadar puan aldın" gibi geri bildirim verir. Sistem bunları kullanarak hangi durumda ne yapması gerektiğini öğrenir.

## 2. Temel Kavramlar

Slayttaki temel kavramlar şunlardır:

- **Ortam (environment):** ajanın içinde bulunduğu ortam.
- **Durum (state):** mevcut durum.
- **Ödül (reward):** ortamdan gelen geri besleme. Ödül de ceza da olabilir; illa pozitif diye düşünülmemelidir.
- **Politika (policy):** ajanın durumlarını hareketlerine eşleyen tablo. "Şöyle bir durumda şunu yapmalısın" bilgisini gösterir. Öğrenmeye çalıştığımız şey aslında budur.
- **Değer (value):** bir durumda bir hareket yapınca alınacak gelecek ödül. Şu andaki bir şey değil, geleceğe dair bir şeydir.

## 3. Eve Gidelim Örneği ve Q Tablosu

### 3.1 Ortam

Slaytın başlığı "Eve gidelim, ama nasıl"dır (ekrandan, 00:15:00). Ortam $3 \times 3$ bir ızgarada 9 durumdan oluşur. Şekildeki yerleşim şöyledir:

```text
5   1   0      (0: başlangıç, araba)
6   2   4      (4: çukur)
8   3   7      (8: ev)
```

Slayttaki bilgiler:

- 0 (başlangıç) ile 8 (ev) arasında toplam 9 durum vardır.
- Her durumda yapılabilecek 4 olası hareket vardır: sağ, sol, yukarı, aşağı.
- Ödüller yalnız 8'e giden yerlerdedir ve değeri 10'dur.

4 ve 5 durumları çukurdur; oralara gidilmemelidir. Bazı durumlardan çıkış yoktur: 4'e ya da 5'e giren ajan oradan çıkamaz ve deneme başarısız (fail) biter. Hedef 8'e, yani eve varmaktır. Ajan 0 numaralı yerden başlar.

8'e götüren hareketler 6'dan aşağı inmek ve 3'ten sola gitmektir. Bu iki hareketin 10 puanlık ödülü vardır.

### 3.2 Q tablosu

$Q$ tablosu satırlarında durumlar, sütunlarında hareketler olan bir matristir. Bu ortamda 9 satır ve 4 sütun olur; her hücre "şu durumda şu hareketi yapmanın" değerini tutar. Başlangıçta bütün değerleri 0'dır, hiçbir şey bilinmez; zaman içinde değişir (ekrandan, 00:15:00). Ajan hareket ettikçe ortamdan ödüller gelir ve tablo bu ödüllere göre güncellenir.

<!-- BELİRSİZ: Hocanın 00:12:01-00:13:09 arasında gösterdiği t=0, t=k, t=∞ tablolarının (slayt 7) değerleri karede okunamadı; aşağıdaki değerler altyazıdan alınmıştır. -->

Hoca eğitimin bir ara aşamasındaki tabloyu şöyle okudu:

- 2 durumunda yukarı (up) ya da sağ (right) yapılırsa 0 puan alınır; aşağı (down) ya da sol (left) yapılırsa 2,25 alınır.
- 5 durumunda ne yapılırsa yapılsın puan yoktur. 4 ve 5 çukurdur, oradan çıkış yoktur.
- 6 durumunda aşağı yapılırsa 5 puan alınır, diğer hareketlerin puanı yoktur.
- 8 durumunun satırında da bir şey yoktur, çünkü 8 hedeftir; vardıktan sonra yapılacak bir şey kalmaz.

### 3.3 Ödülün yol boyunca yayılması gerekir

8'e vardığımızda bizi 8'e götüren hareketlerin değerinin en yüksek olmasını isteriz: 6'da aşağı gitmek ve 3'te sola gitmek iyi hareketler olmalıdır. Ama 0'dan 6'ya tek adımda varılamaz. O zaman 6'ya giden yolu da öğrenmek, yani ödüllendirmek gerekir. Yalnız hedefe giden son hareket değil, hedefe giden yola götüren bütün durumlar ödüllendirilmelidir. Algoritma tabloyu sıfırla başlatır ve tablo zaman içinde bir değere yakınsar (converge).

### 3.4 Öğrenilen tablonun kullanımı

Eğitim bittikten sonra ajan 0 durumundadır. 0'da en mantıklı hareket sola gitmektir (altyazıda bu değer "0-45" diye geçer, büyük olasılıkla 0,45). 0'dan sola gidilince 1'e varılır. 1'de tablo aşağı gitmeyi söyler; 1'den aşağı gidilince 2'ye varılır. 2'de aşağı ve sol eşit puanlıdır; aşağı seçilirse 3'e varılır. 3'te yapılacak hareket doğrudan soldur (değeri 5) ve 8'e varılır. İş biter.

Burada tek bir yol bulunmaz; birden fazla yol çıkabilir ve puanları farklı olabilir. Puanı en yüksek olan yol, örneğin en kısa yol, ortaya çıkarılmak istenir.

> **Ders sonrası not:** 7. bölümdeki güncelleme kuralı $\alpha=0{,}5$, $\gamma=0{,}9$ ile 3 ← 2 ← 1 ← 0 zincirinde birer kez uygulanırsa $Q[3,L]=5$, $Q[2,D]=2{,}25$, $Q[1,D]=1{,}0125$, $Q[0,L]=0{,}455625$ çıkar (python ile hesaplandı). Bu, hocanın okuduğu 2,25 ve "0-45" değerleriyle tutarlıdır; altyazıdaki "0-45" büyük olasılıkla 0,45'tir.

## 4. Bölüm ve Politika

### 4.1 Bölüm (episode)

Pekiştirmeli öğrenmenin en temel algoritması Q-learning'dir. Adı, öğrenilen matrisin adından ($Q$) gelir: Q-learning, $Q$'yu öğrenmek demektir.

Bölüm (episode), başlangıçtan başlayıp başarısızlıkla ya da hedefle biten hareket dizisidir. Örneğin 0'dan iki kez sola gitmek (0 → 1 → 5) 5 çukuruna düşer ve bölüm biter; bu bir bölümdür. Ardına bir sol daha eklemek bölüm oluşturmaz, çünkü bölüm çukurda bitmiştir. Her bölüm ya 8'e vararak ya da 4 veya 5'te başarısız olarak biter. Bölümlerin hepsinin uzunluğu aynı olmak zorunda değildir. Eğitim bu bölümler kullanılarak yapılır.

<!-- BELİRSİZ: Hoca bu örnekte (00:15:53) "altıdan sonra tekrar sola gidemiyoruz" dedi; şekle göre iki sol hareketi 0 → 1 → 5 yoluyla 5 çukuruna varır. Not şekle göre yazıldı. -->

### 4.2 Politika (policy)

Politika, mevcut $s$ durumunda yapılacak hareketi $Q$'ya göre seçer. Hoca bunu eğitim sürecinden bir anla açıkladı: diyelim ki eğitim sırasında 3 durumundasınız; 3'ün satırında bir 5 var, diğerleri 0. Eğitim sürecinde (oyun bittikten sonra kullanılırken değil) politika şunlardan biri olabilir:

- Var olan hareketlerin içinden en yüksek değerliyi seç.
- Hareketlerden birini rastgele seç.
- En yüksek üç hareketten birini seç.

Ajan deneme yanılmayla iyi bir politika arar: bir politikayla başlar ve onu iyileştirir. Bu iyileştirmede bir ikilem vardır.

## 5. Keşfetmek ve Kullanmak İkilemi

### 5.1 Tanım

İkilem keşfetmek (exploration) ile kullanmak (exploitation) arasındadır (ekrandan, 00:20:00, slayt listesi):

- **Kullanmak (exploitation):** o ana kadar öğrenilenler içinden en iyisini seçmek, yani şu anda en iyi görünen hareketi denemek. Hedefe daha az maliyetle, daha çok puanla ulaşmayı sağlamaya çalışır.
- **Keşfetmek (exploration):** şu anda en iyi olmayan bir hareketi denemek, yani o ana kadar kullanılmamış şeylere de şans tanımak. Ortamı daha iyi keşfetmeyi sağlar, yeni durumlara erişir, uzun vadede iyileşme sağlayabilir.

3 durumu örneğinde kullanma seçilirse 5 değerli sol hareketi yapılır. Keşif seçilirse örneğin rastgele aşağı (down) seçilebilir. Oradan şimdiye kadar hiçbir şey alınmamıştır, orası hiç görülmemiştir; belki 5'i yapmaktan daha iyi bir yere götürür.

### 5.2 Günlük hayattan örnekler

Slayttaki örnekler şunlardır (ekrandan, 00:20:00):

- **Acıktınız:** yeni bir yeri denemek (keşfetmek) ya da iyi bildiğiniz bir yere gitmek (kullanmak). Bildiğiniz yere gitmenin iyi tarafı, kalitesini ve fiyatlarını bilmeniz, sürpriz olmamasıdır. Yeni bir yer daha risklidir: bildiğinizden daha iyi bir yer de bulabilirsiniz, daha kötüsünü de.
- **Petrol arıyorsunuz:** daha önce petrol çıkmış bölgede çalışmak ya da yeni bir bölgede çalışmak.
- **Benzetimli tavlamayı (simulated annealing) hatırlayın:** rastgele bir hareket seç, iyiyse uygula, değilse azalan bir olasılıkla uygula.

Hoca bu ikilemin hayatta da olduğunu söyledi: konfor alanı dediğimiz şey kullanma kısmıdır. Konfor alanı hiç bozulmazsa insan kendini geliştiremez ve mevcut duruma takılı kalır; sürekli bildiğinizi yaparsanız on yıl sonra da aynı yerde kalırsınız.

Arama algoritmalarıyla bağlantı da kuruldu. Tepe tırmanma (hill climbing) yalnız kullanır: mevcutların içinden en iyisine gider. Benzetimli tavlama keşfe biraz daha şans tanır: rastgele üretilen bir hareket kötü olsa bile bir olasılıkla uygulanır; böylece yerel bir minimum ya da maksimum aşılıp daha iyi bir yere gidilebilir.

Aynı şey oyun ajanları için de geçerlidir. Eğitimde hep kullanma seçilirse ajan o ana kadar bulduğu yoldan daha iyi bir yolu, daha iyi bir oynama stratejisini, daha iyi bir politikayı keşfedemez. Birçok hareket hiç denenmeden eğitim tamamlanabilir; belki bulunandan daha iyi bir $Q$ tablosu vardır ama ona hiç dokunulmamıştır.

## 6. Q-Learning Algoritması

### 6.1 Algoritma

Slayttaki algoritma şöyledir (ekrandan, 00:25:00):

```text
Her bölüm için tekrar et
    Başlangıç durumuna git (s = s0)
    s bölüm sonu olmadığı sürece
        politikaya göre hareket (a) seç
        hareketi yap, ödülü (R) ve sonraki durumu (s') belirle
        Q[s, a] = Q[s, a] + α*(R + γ*max[Q(s', A)] - Q[s, a])
        s = s'
```

Güncelleme kuralı matematik gösterimiyle:

$$Q[s,a] \leftarrow Q[s,a] + \alpha \left( R + \gamma \max_{A} Q(s', A) - Q[s,a] \right)$$

Slayttaki açıklamalar:

- $\max[Q(s', A)]$: $s'$ durumunda yapılabilecek tüm hareketlerin ödüllerinin maksimumu.
- Politikaya göre hareket seçimi keşfet/kullan ikilemidir: $Q[s,:]$'lerin en yükseğini seçmek → kullan; rastgele birini seçmek → keşfet.
- Decay $\varepsilon$-greedy: rastgele hareket seçme olasılığı giderek azalır, benzetimli tavlamadaki sıcaklık gibi.
- $\alpha$: öğrenme katsayısı.
- $\gamma$: $(0,1)$ arası; 0'a yakın olursa yakın ödüllere, 1'e yakın olursa gelecek ödüllere odaklanılır.

### 6.2 Hareket seçimi

Örneğin 0 durumundayken satırdaki dört değer de sıfırdır. Bunlardan biri rastgele seçilebilir ya da en büyüğü seçilebilir; ikisi de birer karar yöntemidir. Nasıl seçileceği bize kalmıştır. Decay $\varepsilon$-greedy yöntemlerinde eğitimin başında rastgele seçim olasılığı yüksektir, eğitimin sonlarına doğru bu olasılık azaltılır.

Hareket seçilince yapılır; ortamdan ödül $R$ ve sonraki durum $s'$ belirlenir. Sonra $Q$ tablosu bu seçime ve ortamdan gelen $R$'ye göre güncellenir: $s$ durumunda $a$ hareketini yapmanın değeri $Q[s,a]$ güncellenir.

### 6.3 Öğrenme katsayısı $\alpha$

$Q[s,a]$ o ana kadar biriken değeri, parantez içindeki ifade ise son yapılan hareketle gelen güncellemeyi gösterir. $\alpha$ çok küçükse son hareketin $Q$ üzerindeki etkisi küçük olur; o ana kadar biriktirilmiş değerlerin etkisi daha fazla kalır. $\alpha$ büyükse sistem son yaptığı hareketlere çok bağımlı olur. Yani $\alpha$ geçmişin etkisini ayarlayan bir katsayıdır.

$\alpha$ eğitim boyunca değiştirilebilir. Başlarda çok birikim olmadığından $\alpha$'yı büyük tutmak değerlerin hızlı değişmesini sağlar. Sonlara doğru, örneğin bir milyon oyun oynandıktan sonra 1,2 milyona kadarki süreçte $\alpha$ küçük tutularak yalnız küçük değişikliklere izin verilebilir.

> **Ders sonrası not:** Hoca bu kısımda (00:25:37) bir yerde "Q'yu küçük tutarsanız" dedi; bağlamdan kastedilen öğrenme katsayısı $\alpha$'dır.

### 6.4 İndirim katsayısı $\gamma$ ve gelecek ödül

$R$, $s$ durumundayken $a$ hareketini yapınca elde edilen anlık ödüldür. $\gamma$ 0 ile 1 arasında bir değerdir ve $\max_A Q(s',A)$ ile çarpılır.

$s'$, $s$ durumunda $a$ hareketi yapılınca geçilen sonraki durumdur. Örneğin 2'deyken aşağı yapılırsa $s'=3$ olur. $\max_A Q(s',A)$, o yeni durumda yapılabilecek bütün hareketlerin en büyük değeridir; yani o hareketi yaparsam oradan nerelere varabileceğimi, ne kadar ödül toplayabileceğimi gösterir. Bu gelecek ödüldür.

Parantez içindeki ifade, gelecek ödül ile anlık ödülün toplamından mevcut değerin çıkarılmasıdır. Bu fark eksi de olabilir: $R$ eksi olabilir ya da $s'$'den elde edilen değer $Q[s,a]$'dan küçük olabilir. Yani $Q[s,a]$ illa artacak diye bir şey yoktur. Gelecek ödül yüksekse $Q[s,a]$ artar; böylece ödüle giden yoldaki hareketler de ödüllendirilir.

Önemli sonuç: bir hareket yapıldığında ortamdan hiçbir şey gelmese bile (ortam ne "aferin" der ne ödül verir) o hareketin değeri değişebilir. Yeter ki varılan durumdan sonra bir ödül gelecek olsun. $R$ şimdiki ödülü, $\max_A Q(s',A)$ gelecekteki ödülü gösterir; $\gamma$ ikisi arasındaki dengeyi kurar.

> **Ders sonrası not:** Hoca 00:27:42'de "A durumundayken S hareketini yaptım" dedi; doğrusu "$s$ durumundayken $a$ hareketini yaptım"dır.

## 7. Sayısal Örnek: Q Güncellemeleri

Bu örnekte $\alpha = 0{,}5$ ve $\gamma = 0{,}9$ alınır. Başlangıçta $Q$ tablosu tamamen sıfırdır. Gösterimde $Q[3,L]$, 3 durumunda sol (left) hareketinin değeridir.

<!-- BELİRSİZ: "Örnek Q güncellemeleri" slaytı (slayt 12) hiçbir karede açık görünmedi; değerler altyazıdan alındı ve python ile doğrulandı. -->

### 7.1 İlk ödüle rastlanana kadar

Başta her şey sıfır olduğundan ajan rastgele hareket eder. Ödül yalnız 8'e giden oklardadır. Örneğin ajan 0'da sola gider, sonra aşağı iner, sonra sağa gider ve çukura düşer; tablo değişmez. Başka bir bölümde 3'e kadar gelir, sağa gidip 7'ye, oradan yukarı çıkıp 4'e düşer; yine değişmez. Ajan ödüle rastlayana kadar tablo sıfırlarla dolu kalır.

### 7.2 Birinci güncelleme: $Q[3,L]$

Verilen: $s=3$, $a=L$, $R=10$ (3'ten sola giden kırmızı oktaki ödül), $s'=8$, $Q[3,L]=0$. 8'den yapılabilecek bütün hareketlerin değeri sıfırdır, çünkü 8'deyken yapılan hiçbir hareket bir şey kazandırmaz.

$$Q[3,L] = 0 + 0{,}5\,(10 + 0{,}9 \cdot \max Q(8,\cdot) - 0) = 0 + 0{,}5\,(10 + 0{,}9 \cdot 0 - 0) = 5$$

Sıfır olan değer 5'e çıkar. Aynı şekilde 6'da aşağı gitmek de 10 ödül verir ve $Q[6,D] = 5$ olur.

### 7.3 Ödülün geriye yayılması: $Q[2,L]$

Değerler 5'e çıktıktan sonra 3 ve 6 durumları değerli durumlar haline gelir. Oyunun başında 2'den aşağı ya da sola gitmenin hiçbir anlamı yokken artık anlamı vardır.

Verilen: $s=2$, $a=L$, $R=0$ (ödül gelmez), $s'=6$, $Q[2,L]=0$. 6'nın satırındaki değerlerin en büyüğü 5'tir.

$$Q[2,L] = 0 + 0{,}5\,(0 + 0{,}9 \cdot 5 - 0) = 0{,}5 \cdot 4{,}5 = 2{,}25$$

Ortamdan hiçbir şey gelmediği halde, 6'da alınacak 5 puan yüzünden değer geriye yansır. Aynı şekilde 2'den aşağı gitmenin ($s'=3$) değeri de 2,25 olur. Sonra aynı etki 2'ye götüren yollara geçer: 1'den aşağı gitmenin değeri de artar. Bu, bir yerde bir ödül bulup oraya götüren yolları sürekli güncellemek şeklinde bir süreçtir. Python ile kontrol edildiğinde 5, 5, 2,25 ve 2,25 değerleri doğrulanır.

### 7.4 Çukurlardan uzak durmak

Slayt 13'te "Çukurlardan uzak durmak istersek?" sorusu vardır (ekrandan, 00:40:00 karesindeki slayt listesinde görünür). Hoca bunun için çukurların ödüllerinin değiştirilebileceğini söyledi.

> **Ders sonrası not:** Hoca 00:36:13'te çukurların ödüllerini "sıfır yapmak" dedi. Bu örnekte ödüller zaten sıfırdır; ajanı çukurlardan uzak tutmak için büyük olasılıkla çukura giden hareketlere negatif ödül (ceza) vermek kastedilmiştir.

## 8. Labirentten Çıkış ve En Kısa Yol

### 8.1 Problemin Q-learning'e dökülmesi

Q-learning bir labirentten çıkış için de uygulanabilir. Önce $Q$ tablosunun yapısı canlandırılır:

- Hareketler: dört yöne hareket; tablonun 4 sütunu olur.
- Durumlar: labirentteki her beyaz kare bir durumdur; tablonun satır sayısı beyaz kare sayısıdır.

Eğitim yine rastgele hareketlerle başlar; ajan boşu boşuna bir sürü hareket yapar. Sonunda bir yerde, örneğin bitiş noktasında sağa gitmek bir ödül verirse, bu ödül önce bitişe komşu kareye, ondan bir öncekine ve böyle geriye doğru yayılır.

### 8.2 Hızlı varmak için her adıma $-1$

Ajanın yalnız çıkışa varmasını değil, oraya hızlı varmasını da istiyorsak her adımda $-1$ ödül verilir. Yani ajan ne yaparsa yapsın, bütün durumlarda ödül $-1$'dir; bitişteki de $-1$'dir. Hiç pozitif ödül yoktur.

Algoritma toplam ödülü en büyük yapmaya çalışır. Bütün ödüller eksi olunca toplam cezayı en küçük yapmaya çalışır; bunun yolu en kısa yoldan gitmektir. Birden fazla yol varsa en kısa yolu bulmak için bu oldukça şık bir hiledir.

### 8.3 Öğrenilen tablo

"Öğrenmemiz gereken" slaytında iki şekil vardır (ekrandan, 00:40:00). Üstteki şekilde oklar, her $s$ durumunda en iyi değere (gelecek ödüle) sahip hareketi gösterir. Alttaki şekil ise her karenin gelecek ödülünü gösterir. Karedeki değerler şöyledir (siyah hücreler duvardır, "." ile gösterildi):

```text
  .   -14  -13  -12  -11  -10   -9    .
-16   -15    .    .  -12    .   -8    .
  .   -16  -17    .    .   -6   -7    .
  .     .  -18  -19    .   -5    .    .
  .   -24    .  -20    .   -4   -3    .
  .   -23  -22  -21  -22    .   -2   -1
```

Başlangıç karesi soldaki $-16$'dır (ikinci satır), bitiş karesi sağ alttaki $-1$'dir. Bitiş karesinin değeri $-1$'dir (oradan çıkmak bir adımdır), ona komşu kare $-2$, böyle devam eder; her karenin değeri, o kareden çıkışa en kısa yoldaki adım sayısının eksisidir (python ile kareden alınan tablo üzerinde genişlik öncelikli arama yapılarak doğrulandı). Herhangi bir durumdayken en büyük (en az eksi) değerli komşuya gitmek, ajanı bitişe en kısa yoldan götürür. Yani yalnız başlangıçtan bitişe değil, her noktadan bitişe giden yol tabloda vardır.

### 8.4 Uyarı

> **Hocanın vurgusu:** Bir başlangıçla bir hedef arasındaki en kısa yolu bulmak için pekiştirmeli öğrenmeyi kullanmak çok makul değildir. Bu yalnız bir kullanım senaryosudur. Böyle yerlerde A* gibi klasik bir algoritma çok daha etkili çözüm sağlar. Pekiştirmeli öğrenme algoritmaları hızlı değildir, yavaş yavaş yakınsar; arama algoritmaları gibi analitik ve deterministik değildir.

## 9. Yeni Durumlar ve Büyük Durum Uzayları

### 9.1 Durum sayısı

Şimdiye kadarki örneklerde durum sayısı sabitti ve azdı. Slayta göre iki seçenek vardır (ekrandan, 01:05:00):

- Durum sayısı en başta bilinebilir (sabit boyutlu $Q$ matrisi). Örneğin "bu problemde 100 durum var" denir ve Q-learning ona göre çalıştırılır.
- Zaman içinde yeni durumlar ($Q$'ya yeni satırlar) eklenebilir. Tablo önce erişilebilen durumlara göre küçük kurulur, yeni durumlar çıktıkça satır eklenir.

### 9.2 Görülmemiş durum sorunu

Q-learning daha önce görmediği bir durumun değerini (value) bilemez, dolayısıyla yeni durumlara adapte olamaz. Eğitim bitip algoritma çalışırken tabloda olmayan bir durum ortaya çıkarsa ne yapacağını bilemez. Eğitim sürecinde görülmeyen durum sayısı oyunlarda ve gerçek hayatta çok fazladır; birebir aynı durum pek tekrar etmez.

Olası çözüm, yeni durumu eldekilerden birine benzetmektir: yeni bir durum gelince bilinen durumlardan en çok benzeyeni o durum sayılır ve onun için en iyi hareket yapılır. Eğitim ne kadar uzun yapılır, ortam ne kadar iyi keşfedilirse ve ortamın tamamını temsil eden durumlar tabloda bulunursa bu oldukça iyi bir çözüm olur.

### 9.3 Ekranın durum olarak alınması

Oyunlarda durum, o anki ekran görüntüsüyle ilgilidir: top üstünüze geliyor, düşman yaklaşıyor, bir kapıdan geçeceksiniz; ne yapmalısınız? Hoca, $100 \times 100$'lük bir ekran düşünmeyi ve her pikseli yalnız siyah ya da beyaz almayı önerdi. 10.000 piksel ve piksel başına 2 durum varsa olası durum sayısı $2^{10000}$'dir (bkz. Örnek Sorular). Böyle bir $Q$ tablosunu kurmak ve öğrenmek mümkün değildir. Gerçek ekranda renk sayısı çok daha fazladır, yani taban 2'den de büyük olur.

Durum, onu en iyi belirleyen bazı değişkenlerle de ifade edilebilir; ekranın piksel piksel görüntüsünü durum saymak gerekmez. Örneğin bazı oyunlarda görüntüden ajanın topa uzaklığı ve topla yaptığı açı hesaplanıp durum olarak kullanılabilir. Olası durum sayısı çok azalır. Ama bunun oyunu kazanmaya yetip yetmeyeceği, yani durumun nasıl kodlanacağı ayrı bir konudur. Ekran ön işlenip oradan bazı bilgiler çekilerek durum oluşturulabilir.

### 9.4 Anlık görüntü yetmeyebilir

Hoca bunu tahtada bir çizimle anlattı (ekrandan, 01:00:00): bir çizgi üzerinde ajan (yuvarlak) ve bir düşman (çarpı) vardır; düşmanın üzerinde iki yönlü ok çizilidir. Anlık görüntüden düşmanın ajana uzaklığı çıkarılabilir. Ama düşman ajana doğru da gidiyor olabilir, ajandan uzaklaşıyor da; mesafe ikisinde de aynıdır. Anlık görüntü düşmanın ne tarafa gittiği bilgisini taşıyamaz. Bu yüzden anlık ekran görüntüsü en iyi hareketi seçmeye yetmez; durumu belirlemek için son 3-5 kare kullanılmalıdır. Bu da olası durum sayısını daha da katlar.

Oyunun hangi dinamiklerinin (hangi şeklin hangi şekle uzaklığı, neyin hızı) kullanılacağını her oyun için ayrı ayrı belirlemek de çok etkili bir yol değildir. Burada derin öğrenme devreye girer.

## 10. Atari Oyunları ve Deep Q-Network

Slaytın başlığı "Atari oyunları / deep Q-network"tür (ekrandan, 00:55:00). Maddeler:

- Renkli bir ekranda olası durum sayısı ???
- Resmi (durumu) CNN'lerle işle, $Q(s,a)$'ları / hareketi belirle.

Slayttaki şemada girdi bir oyun ekranıdır; ardından iki evrişim (convolution) katmanı ve iki tam bağlantılı (fully connected) katman gelir. Çıktı katmanında her joystick hareketi (yönler, ateş, yön + ateş, hareketsizlik) için bir çıkış vardır. Kaynak olarak Nature'daki makale verilmiştir (ekrandan, 00:55:00).

Derin öğrenmeden önce görüntü işlemede insan eliyle tasarlanmış filtreler kullanılırdı: "bu problemde verinin şuraları önemli, şu işlemleri yapıp şu bilgileri çıkaralım". Bunların her probleme özgü olarak tekrar tekrar tasarlanması gerekirdi. Derin öğrenmenin temel felsefesi şudur: özellik çıkarıcılarla, tanımlayıcılarla (descriptor) insanlar uğraşmasın; resmi temsil etmek için nerelere odaklanılacağını makine kendisi öğrensin. Görüntü için kabaca CNN'ler kullanılır. Hoca, son zamanlarda CNN'lerin yerine geçmeye başlayan Transformer'ların da bu alanda kullanılmaya başlanmış olabileceğini, ama kontrol etmediğini söyledi.

Derin öğrenmenin Q-learning'e eklenmesi, bir sürü farklı oyunu aynı yapıyla eğitebilmeyi sağlamıştır. Oyunda neyin önemli olduğunu insanların çıkarıp uygun $Q$ tabloları tasarlamasına gerek kalmaz. Sisteme mevcut ekran ve gerekirse ondan önceki 3-5 kare girdi olarak verilir; çıktı hangi hareketin yapılacağı, yani $Q(s,a)$ değerleridir. Ağ bunları içeride hesaplar ve çok büyük durum uzaylarını tutmaya gerek kalmaz. Yeni bir durumu eldekilere benzetme işi de CNN'lerle kolayca gerçekleşir.

Bu başarılar oyun dünyalarındadır. Gerçek hayattaki problemlerde durumun tanımı bambaşkadır; o durumdan gidilebilecek seçenekler size söylenmeyebilir, onları sizin oluşturmanız gerekir. Oyunlar ise kapalı dünya (closed world) sistemleridir. Arama uzayları gerçekten büyüktür ama sonuçta kapalıdırlar ve büyük bilgisayar gücüyle bütün dinamikleri ortaya çıkarılabilir. İnsan oyuncuların bir bir yenildiği haberleri bu yüzdendir; her birini eğitmek için çok büyük enerji harcanır.

## 11. Yapay Zeka, Etik ve Hukuk

Dersin son konusu yapay zekanın etik ve hukukla ilişkisidir. Bu teknik değil, sosyal bir alandır. Giderek ilgi çekmekte ve üzerinde düşünülmesi gereken bir konu olarak öne çıkmaktadır; bu slaytlar derse önceki yıllarda yoktu, sonradan eklendi. İçerik: tanımlar, verilerdeki önyargı, sorumlu kim, iş sonrası dünya ve manipülasyon.

### 11.1 Tanımlar

Slayttaki tanımlar (ekrandan, 01:10:00):

- **Etik / ahlak:** İyi/kötü nedir? Hangi durumda ne yapılmalıdır? Hoca, $Q$ tablosunun da aslında bir tür etik olduğunu söyledi: hangi durumda ne yapılacağını söyler.
- **Hukuk:** Toplumu düzenleyen ve devlet yaptırımıyla güçlendirilmiş bulunan kuralların, yasaların bütünü. Devlet hangi durumda ne yapılması ve ne yapılmaması gerektiğini söyler; hukuk, devletin iyi-kötü tanımı sayılabilir.
- **Yapay zeka:** karar veren bir sistem.

Slayttaki sorular: hukuki olan her zaman etik midir? Hukuk da etik de zamandan ve kültürden bağımsız değildir; kölelik bir zamanlar hukukiydi. Bugün bankadan döviz ya da altın almak ne kadar hukukiyse, bir zamanlar insanların alınıp satılması da öyle hukukiydi. Etik için de aynısı geçerlidir: insanların ortak olarak kabul ettiği haklar ancak 1948'de İnsan Hakları Evrensel Beyannamesi ile evrensel hale geldi; öncesinde böyle ortak kurallar çok azdı. Bunlar doğadan gelmez; zaman, mekan ve kültürle iç içe geçmiş kurgulardır ve ileride değişebilirler.

Yapay zeka sistemi karar verir. Karar vermek hukukta sorumluluk almak demektir; bir kişinin sorumluluğu verdiği kararlarla ve yaptığı işlerle ölçülür.

### 11.2 Verilerdeki önyargı

Yapay zeka algoritmaları verilerden öğrenir: verilen verilerden bir kural sistemi, kabaca bir girdi-çıktı eşlemesi çıkarırlar. Eğitim verisinde önyargı varsa onu da öğrenirler. Örneğin insan kaynakları bölümündeki kişiler bazı gruplara cinsiyet ya da yaşa göre ayrımcılık yaptıysa, bu verilerle eğitilen model de aynı ayrımcılığı yapar. Modelin verilerden başka kaynağı olmadığı için verilerde ne varsa onu aynen yansıtır.

**Arama sonucu örneği.** Hoca internette bazı ifadeleri aratıp sonuç sayılarını gösterdi (altyazıdan):

- "kırmızı muz" → 13.400 sonuç, "sarı muz" → 30.400 sonuç, "yeşil muz" → 33.600 sonuç.
- "yemek yediği" → 714 bin sonuç, "öldürdüğü" → yaklaşık 26 milyon sonuç.

Yorum: normal olmayan şeyleri yazmaya çok daha meraklıyız. "Birisi yemek yedi" haber olmaz, "birisi birini öldürdü" haberdir. Yazılı kaynaklardan toplanan veride olağan şeylerin sayısı çok daha azdır. Bütün metinlere bakan bir program "insanlar en çok ne yapar" sorusuna "birbirlerini öldürürler" diyebilir; gerçek bu değildir. Olağan olan söylenmez, yazılmaz. Gerçek dünyadaki olayların sıklığıyla yazılı metinlerdeki ya da haberlerdeki sıklıkları çok farklıdır.

**Doktor bilmecesi** (ekrandan, 01:15:00): "Bir adam ve oğlu ciddi bir trafik kazası geçirmişler ve acildeler. Çocuğun ameliyat olması gerekiyor. Ameliyatı yapacak doktor çocuğa bakıyor ve «bu ameliyatı yapamam, bu benim oğlum» diyor. Bu mümkün mü?" Cevap: doktor çocuğun annesidir. Bu cevabı bulmak bazılarına zaman alır, çünkü zihinde ameliyat yapacak doktorun erkek olacağı varsayılır ve bu varsayım yüzünden bir çelişki varmış gibi görünür. Önyargı ne kadar güçlüyse cevap o kadar geç bulunur.

Hoca önyargıların tamamen kötü olduğunu söylemenin de saçma olduğunu ekledi: önyargısız yaşanamaz. Her şeyi derinlemesine analiz edip hiç kanıtsız bilgi kullanmamaya çalışan biri karar veremez, fikir beyan edemez. Önyargı kabaca sezgisel bir yaklaşım kullanmaktır. A* algoritması da en iyi çözümü değil daha hızlı bir çözümü sezgiyle bulur. Önyargılar da toplumdan, çevreden, deneyimlerden ve okuduklarımızdan öğrendiğimiz sezgilerdir. Zararlı olanları ve işe yarayanları vardır.

**Korelasyon ve nedensellik.** Benzer zamanda olan şeyler her zaman sebep-sonuç ilişkisine sahip değildir. Makine öğrenmesi algoritmaları genelde böyle varsayımlarda bulunur ama bu her zaman geçerli değildir. Örnekler: çekilen kedi resmi sayısı arttıkça trafik kazalarında artış; kadınlara oy hakkı verilmesi ile dünya savaşlarının başlaması (slaytta 1900'ler). Aralarında zamanda ya da mekanda korelasyon vardır ama sebep-sonuç ilişkisi yoktur. Slaytta ayrıca internetin yaygınlaşması ile dünyadaki ağaç sayısının azalması örneği de görünmektedir (ekrandan, 01:25:00, slayt listesi).

**Önyargıyı ortaya çıkarmak.** Yüz tanıma sistemlerinin başarımı artık her alt grup için ayrı raporlanmaya çalışılmaktadır: farklı etnik gruplar, kadın/erkek. Veri kümesinde grupların temsil oranları farklı olsa bile (bu iyi bir şey değildir), her grup için ayrı test yapılırsa önyargı görünür hale gelir.

### 11.3 Bir yapay zeka sistemi hata yaptı: sorumlu kim?

Yapay zekalar da hata yapacaktır. Ne kadar iyi olursa olsun, saatte yüz kilometreyle giden bir araç önüne atlayan bir yayaya çarpabilir; bunlar yaşandı. Sorumluluğun kime ait olduğu sorusu ortaya çıkar. Hocanın bildiği kadarıyla otopilotu ya da otomatik park sistemini kullanma kararını aracın sahibi verdiği için sorumluluk sahibine aittir; bunun ne kadar değişeceğini zaman gösterecek.

Hukuk yaşayan bir şeydir. Daha önce olmayan bir durum ortaya çıkınca ona nasıl karar verileceğine dair kurallar yazılması gerekir. Q-learning'deki yeni durum sorununa benzer şekilde iki yol vardır: yeni durumu bilinen bir duruma benzetmek (buna içtihat denir) ya da yeni bir kanun çıkarmak.

### 11.4 Yapay zeka işlerimizi elimizden alacak mı?

Slayttaki iki uç olasılık (ekrandan, 01:25:00):

- **Küresel işsizlik:** insanların çok büyük çoğunluğunun emeğine ihtiyaç duymayan bir sistem. Herkese temel geçim desteği verilir, çok az insanın çalışması gerekir.
- **Önceki işgücü devirlerinde olduğu gibi (insan → makine):** sanayi devrimi de işçilerden tepki almıştı (İngiltere'de işçiler makineleri yakmıştı), sonunda yalnız bazı mesleklerin sıklığı azaldı ve yeni meslekler ortaya çıktı.

Arada senaryolar da olabilir: insanlar yine çalışır ama günde 8 yerine 4 saat yeterli olur; ya da çalışma süresi değişmez, yalnız meslekler değişir. Bu noktada zeka, yaratıcılık ve inisiyatif alma gibi insani özelliklerin çok kullanıldığı meslekleri seçmek önem kazanır. Sürekli aynı şeyi tekrar eden işlerde iş güvencesi uzun vadede sürmeyebilir, çünkü tekrarlı işler makinelere daha uygundur. Henüz hiç el değmeden üretilen ürün pek yoktur ama büyük kısmı insan eli değmeden üretilen ürünlerin sayısı giderek artacaktır. Kendinden bir şey katmayı gerektirmeyen işler belki zaten insanlar için uygun işler değildir.

### 11.5 Manipülasyon

Soru: birinin bir konu hakkındaki fikrini ona video izleterek, haber okutarak değiştirmek mümkün müdür? Cevap büyük oranda evettir; bütün reklam sektörü bunun üzerine kuruludur. Reklam, bir kişinin fikri yoksa oluşturmaya, varsa kendi tarafına çekmeye çalışmaktır.

Sosyal medyada karşınıza çıkan içerikler neye göre seçiliyor? Bir kişiye X ürününü satın aldırmaya çalışmakla X partisine oy verdirmeye çalışmak dinamik bakımından çok farklı değildir; ikisinin yapmaya çalıştığı şey aynıdır. Hoca, önceki bir ABD seçiminde Facebook'la çalışan bir firmanın böyle şeyler yaptığına dair iddialar olduğunu andı. Bu alanlar oldukça bulanıktır.

"Sosyal Medya" slaytında tıklama akışının (clickthrough) optimize edilmesi ele alınır (ekrandan, 01:30:00, slayt listesi): amaç insanların ne istediğini öğrenmekti (learning what people want), sonuç insanları daha tahmin edilebilir hale getirmek oldu (modifying people to be more predictable). Yani insanları daha iyi tahmin etmek için algoritma geliştirmek yerine insanlar daha kolay tahmin edilebilir, daha refleksif hale getirilir. Refleksif olmak düşünmeden hareket etmektir; insanlar uçlara itildikçe bu olur.

### 11.6 Kişisel verilerin sahibi

Slayttaki maddeler (ekrandan, 01:30:00):

- Ne amaçla, hangi verilerinizi kullandığını, kimlere vereceğini açıklamalı, size ait verileri göstermeli.
- Ham veriler bir şey, işlenmiş veriler başka bir şey: tıkladığınız haberler → siyasi tercihiniz; koordinatlarınız → rakip şirketle görüşmeye gittiniz.
- "Reklam amaçlı kullanacağım" = ???

Firmalar genelde ham verilerinize eriştiklerini söyler ama bu verileri işleyip hangi hale getirdiklerini ve nereye gönderdiklerini pek paylaşmaz; buna erişmek pek mümkün olmaz.

Kişisel veriler kimlerle paylaşılmalı: işvereniniz, eşiniz, ebeveynleriniz, sigorta şirketleri, devlet, sağlık kuruluşları? Sağlık bu listeye yeni girmiştir. Hoca, pandeminin biyosensörlerin sağlık sistemine giderek daha fazla entegre olmasını tetikleyeceğini düşündüğünü söyledi. Bugün kalp atış sayısı gibi birkaç basit şey ölçülebilirken bu sistemler arttıkça vücutta olup bitenin gerçek zamanlı ve uzaktan izlenmesi mümkün olacaktır; buna izin verilip verilmeyeceği ayrı bir konudur.

Veri paylaşma isteği, karşılığında ne sağlandığıyla çok ilgilidir. Eskiden "herkesin cebine bütün gün nereye gittiğini bilen bir cihaz koyacağız" denseydi kabul görmezdi; bugün herkes kabul ediyor, çünkü bu veriyle en yakın yerler, yol tarifi, en hızlı güzergah gibi faydalar sağlanıyor. Sağlıkta, gelecekteki ya da yeni baş gösteren hastalıkları bilmek için normalde paylaşmam diyenler de verilerini paylaşmayı kabul edebilir. Vazgeçilemeyecek ya da çok istenen bir şey sağlanıyorsa veriler isteyerek paylaşılır.

Hoca son olarak sosyal medyadan ve telefondan neler öğrenilebileceği sorusunu sordu: ne zaman, kiminle, nerede, ne yaptığınız, özel hayatınız; ya da tersine, ne öğrenilemez? Bu konuların önümüzdeki en az on yıl boyunca gündemde kalacağını söyledi.

## Örnek Sorular

**Soru 1** (ekrandan ve derste sözlü, 00:30:26): $\alpha = 0{,}5$, $\gamma = 0{,}9$ ve başlangıçta tamamen sıfır olan $Q$ tablosuyla "eve gidelim" ortamında ajan 3 durumunda sola gidiyor ($R = 10$, $s' = 8$). Sonra başka bir bölümde 2 durumunda sola gidiyor ($R = 0$, $s' = 6$; bu sırada $Q[6,D] = 5$ olmuştur). $Q[3,L]$ ve $Q[2,L]$ ne olur?

> **Çözüm (derste verildi):** $Q[3,L] = 0 + 0{,}5\,(10 + 0{,}9 \cdot 0 - 0) = 5$. $Q[2,L] = 0 + 0{,}5\,(0 + 0{,}9 \cdot \max Q(6,\cdot) - 0) = 0{,}5 \cdot 0{,}9 \cdot 5 = 2{,}25$. Python ile doğrulandı.

**Soru 2** (derste sözlü, 00:15:53): "Eve gidelim" ortamında hangi hareket dizileri bir bölüm (episode) oluşturur?

> **Çözüm (derste verildi):** Başlangıçtan (0) başlayıp ya 8'e varan ya da 4 veya 5 çukurunda biten dizi bir bölümdür; örneğin iki kez sola gitmek ajanı 5 çukuruna götürür ve bölüm biter. Bölümlerin uzunluğu farklı olabilir.

**Soru 3** (ekrandan, 00:40:00 karesindeki slayt 13 başlığı): Ajanın çukurlardan uzak durmasını istersek ne yapabiliriz?

> **Çözüm (derste verilmedi, kısmen):** Hoca çukurların ödüllerini değiştirmekten söz etti. Büyük olasılıkla çukura giren hareketlere negatif ödül (ceza) vermek gerekir; güncelleme kuralındaki $R$ eksi olunca o hareketlerin $Q$ değeri düşer ve politika onları seçmez.

**Soru 4** (derste sözlü, 00:36:45): Bir labirentten çıkış problemine Q-learning uygulanırsa $Q$ tablosunun kaç satırı ve kaç sütunu olur?

> **Çözüm (derste verildi):** Sütun sayısı hareket sayısıdır (dört yön → 4). Satır sayısı durum sayısıdır, yani labirentteki beyaz kare sayısıdır.

**Soru 5** (derste sözlü, 00:38:13): Labirentte ajanın yalnız çıkışa değil en kısa yoldan çıkışa varmasını nasıl sağlarız?

> **Çözüm (derste verildi):** Her adımda (bitiş dahil) ödülü $-1$ yaparız. Toplam ödülü en büyük yapmak, toplam cezayı en küçük yapmak, yani en az adımla çıkmak demektir.

**Soru 6** (ekrandan ve derste sözlü, 00:55:22): $100 \times 100$'lük ve her pikseli yalnız siyah ya da beyaz olabilen bir ekranda olası durum sayısı kaçtır? Böyle bir $Q$ tablosu kurulabilir mi?

> **Çözüm (derste verildi):** 10.000 piksel, piksel başına 2 değer: $2^{10000}$ durum. Bu sayı 3011 basamaklıdır (python ile hesaplandı). Böyle bir tabloyu kurmak ve öğrenmek mümkün değildir; renkli ekranda taban daha da büyür.

**Soru 7** (derste sözlü, 01:00:00 civarı tahta çizimi): Durumu tek bir ekran karesiyle tanımlamak neden yetersiz olabilir?

> **Çözüm (derste verildi):** Tek karede düşmanın ajana uzaklığı görülür ama yönü görülmez: yaklaşan ve uzaklaşan düşman aynı mesafede aynı görünür. En iyi hareketi seçmek için son 3-5 kare birlikte durum olarak verilmelidir.

**Soru 8** (ekrandan, 01:15:00): "Bir adam ve oğlu ciddi bir trafik kazası geçirmişler ve acildeler. Çocuğun ameliyat olması gerekiyor. Ameliyatı yapacak doktor çocuğa bakıyor ve «bu ameliyatı yapamam, bu benim oğlum» diyor. Bu mümkün mü?"

> **Çözüm (derste verildi):** Mümkün; doktor çocuğun annesidir. Cevabın geç bulunmasının nedeni, doktorun erkek olacağı önyargısıdır.

**Soru 9** (derste sözlü, 01:12:18): "yemek yediği" araması 714 bin, "öldürdüğü" araması yaklaşık 26 milyon sonuç veriyor. Bu rakamları nasıl yorumlarsınız?

> **Çözüm (derste verildi):** Olağan olaylar yazılmaz, olağan dışı olanlar yazılır. Yazılı metinlerdeki sıklıklar gerçek dünyadaki sıklıkları yansıtmaz; böyle metinlerle eğitilen bir model insanlar hakkında çarpık sonuçlar çıkarabilir.

## Dersin Toparlaması

Bu derste pekiştirmeli öğrenme, doğru cevabın verilmediği, yalnız ödül ve cezayla öğrenilen bir problem türü olarak tanıtıldı. Ajan ortamda hareket ederek durum-hareket çiftlerinin değerini $Q$ tablosunda öğrenir. Q-learning güncelleme kuralı $Q[s,a] \leftarrow Q[s,a] + \alpha(R + \gamma \max_A Q(s',A) - Q[s,a])$, ödülü hedefe giden yol boyunca geriye yayar. Bu, "eve gidelim" örneğinde 5 ve 2,25 değerleriyle izlendi. Hareket seçiminde keşfetmek ile kullanmak arasındaki denge, benzetimli tavlamadaki gibi giderek azalan rastgelelikle (decay $\varepsilon$-greedy) kurulur. Her adıma $-1$ ödül vermek en kısa yolu öğretir, ama en kısa yol için A* gibi klasik algoritmalar daha uygundur. Durum uzayı büyüdüğünde tablo yaklaşımı çöker; ekranı ve son birkaç kareyi CNN ile işleyip $Q(s,a)$ üreten deep Q-network, oyunlar gibi kapalı dünyalarda bu sorunu çözer.

Dersin ikinci yarısında yapay zekanın etik ve hukukla ilişkisi tartışıldı: etik ve hukukun zamana ve kültüre bağlılığı, verideki önyargının modele geçmesi, korelasyonun nedensellik olmadığı, hata durumunda sorumluluk, yapay zekanın meslekler üzerindeki olası etkileri, sosyal medya ve reklam yoluyla manipülasyon ve kişisel verilerin sahipliği. Bu ders dönemin son dersidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
