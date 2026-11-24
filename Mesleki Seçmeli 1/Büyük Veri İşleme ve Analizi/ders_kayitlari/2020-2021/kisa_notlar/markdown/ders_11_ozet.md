# Ders 11 Çalışma Özeti

## Genel Konular

- Kaynak ve konu
  - Ders, MMDS kitabının (Mining of Massive Datasets, Leskovec, Rajaraman ve Ullman) 7. bölümü olan kümeleme (clustering) konusunu işler. Slaytlar dört parçadır: genel bakış, hiyerarşik kümeleme, k-means ve BFR algoritması (ekrandan, 00:05:00).
- Kümeleme problemi
  - Elimizde $n$ tane veri noktası (data point) vardır. Noktalar iki boyutlu ya da çok boyutlu olabilir. Amaç bu noktaları gruplara (kümelere) ayırmaktır.
  - İki hedef vardır: aynı kümedeki noktalar birbirine yakın olmalı, farklı kümeler birbirinden olabildiğince uzak olmalıdır.
  - İki boyutta kümeleri görerek bile bulmak kolaydır. Boyut 100, 200 gibi büyüdüğünde görselleştirme işe yaramaz. Çok yüksek boyutta neredeyse bütün nokta çiftleri arasındaki uzaklık birbirine yaklaşır.
  - Gerçek verilerde kümeler genellikle iç içe geçmiştir. Bu yüzden kümeleme zor bir problemdir (ekrandan, 00:20:00).
- Uygulama örnekleri
  - Gökyüzü nesneleri (SkyCat): her nesne 7 frekans bandıyla, yani 7 boyutlu bir vektörle ifade edilir. Kümeleme galaksileri, yıldızları vb. ayrı gruplara toplar.
  - Müzik CD'leri: her CD, müşteri sayısı kadar boyutlu bir 0/1 vektörüdür (CD'yi alan müşteri 1, almayan 0). Benzer CD'ler kümelenir. Tersi de yapılabilir: müşteriler CD uzayında vektör olur, benzer beğenili müşteriler bulunur.
  - Belgeler: her belge kelime uzayında bir 0/1 vektörüdür; benzer konudaki belgeler kümelenir. İkili (dual) formülasyonda kelimeler belge uzayında vektör olur; birlikte geçen kelime grupları bir konuyu (topic) verir (ekrandan, 00:25:00).
- Uzaklık ölçüleri
  - Daha önceki derslerde görülen Öklid (Euclidean), kosinüs (cosine), Jaccard ve düzenleme (edit) uzaklıkları kümelemede kullanılabilir.
- Kümeleme yöntemlerinin sınıflandırması (ekrandan, 00:30:00)
  - Hiyerarşik kümeleme
    - Birleştirici (agglomerative, aşağıdan yukarı): başta her nokta ayrı bir kümedir; en yakın iki küme sürekli birleştirilir. Derste bu yaklaşım işlenir.
    - Bölücü (divisive, yukarıdan aşağı): bütün veri tek küme olarak başlar ve yinelemeli olarak ikiye bölünür.
  - Nokta atama (point assignment): küme sayısı baştan verilir; her nokta en yakın kümeye atanır.
- Birleştirici hiyerarşik kümeleme
  - Temel işlem: en yakın iki kümeyi tekrar tekrar birleştirmek. Birleşmeler dendrogram adlı bir ağaçta tutulur; dikey eksen zaman (birleşme sırası) gibi düşünülebilir.
  - Üç önemli soru (ekrandan, 00:35:00): (1) Birden çok noktalı bir küme nasıl temsil edilir? (2) Kümelerin "yakınlığı" nasıl ölçülür? (3) Birleştirme ne zaman durur?
  - Öklid uzayında: küme, noktaların boyut boyut ortalaması olan merkezle (centroid) temsil edilir; kümeler arası uzaklık merkezler arası uzaklıktır. En yakın noktalar ya da en uzak noktalar arası uzaklık da kullanılabilir.
  - Öklid dışı (non-Euclidean) uzayda: "ortalama" tanımsızdır. Küme, diğer noktalara "en yakın" gerçek bir veri noktası olan clustroid ile temsil edilir; kümeler arası uzaklıkta clustroid merkez gibi kullanılır (ekrandan, 00:45:00).
  - Durma: küme sayısı $k$ biliniyorsa $k$ kümede durulur; bilinmiyorsa her adımda bir uyum (cohesion) ölçüsü hesaplanır ve ölçü bir eşiği aşınca durulur.
  - Karmaşıklık: saf uygulama $O(N^3)$, öncelik kuyruğuyla $O(N^2 \log N)$; bellekte sığmayan büyük veriler için yine pahalıdır (ekrandan, 00:55:00).
- k-means algoritması
  - Varsayımlar: Öklid uzayı, baştan verilen $k$, başlangıç için seçilmiş $k$ nokta.
  - Adımlar: her noktayı en yakın merkeze ata; bütün atamalar bitince merkezleri güncelle; noktaları yeniden ata; 2. ve 3. adımları yakınsamaya kadar tekrarla (ekrandan, 01:10:00).
  - $k$ seçimi (dirsek, elbow yöntemi): $k$ arttıkça merkeze ortalama uzaklık doğru $k$'ya kadar hızlı, sonra çok yavaş düşer (ekrandan, 01:20:00).
  - Başlangıç noktaları: örnekleme (sampling) ile hiyerarşik kümeleme ya da birbirinden olabildiğince uzak noktaları seçme.
  - Karmaşıklık: her tur $O(kN)$, ama tur sayısı çok büyük olabilir (ekrandan, 01:25:00).
- BFR (Bradley-Fayyad-Reina) algoritması
  - Diskte duran çok büyük veriler için k-means'in bir türevidir; veriyi tek geçişte kümeler (ekrandan, 01:30:00).
  - Varsayım: her küme Öklid uzayında bir merkez etrafında normal dağılır; bu yüzden kümeler elips biçimindedir.
  - Veri belleğe sığacak parçalar (segment/chunk) hâlinde okunur; bellekte yalnız küme üst verisi (metadata) tutulur (ekrandan, 01:35:00).
  - Üç küme türü (ekrandan, 01:40:00): atılan küme (discard set, DS), sıkıştırılmış küme (compression set, CS), alıkonan küme (retained set, RS).
  - Her DS ve CS kümesi $N$, $SUM$ ve $SUMSQ$ ile özetlenir (ekrandan, 01:45:00); bu $2d+1$ değer eder.
  - Yakınlık ölçüsü Mahalanobis uzaklığıdır; kabul eşiği örneğin $3\sqrt{d}$ (ekrandan, 01:55:00 ve 02:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Boyut sorunu
  - İki boyutta kümeleme kolaydır; boyut sayısı arttıkça problem zorlaşır ve noktalar arası uzaklıklar birbirine benzer hâle gelir.
- Centroid ile clustroid farkı
  - Centroid sanal bir noktadır (ortalamadır) ve yalnız nümerik (Öklid) verilerde hesaplanabilir. Clustroid ise kümedeki gerçek bir veri noktasıdır; kategorik veride kullanılır.
- Hiyerarşik kümeleme büyük veri için uygun değildir
  - $O(N^3)$ ya da en iyi $O(N^2 \log N)$ karmaşıklığı yüzünden yalnız fiziksel belleğe sığan veri kümelerinde kullanılabilir. Örneğin milyarlarca 7 boyutlu noktadan oluşan SkyCat verisi için çok pahalıdır.
- k-means'in zayıf yanı
  - Her turda bütün veri yeniden okunur ve tur sayısı önceden bilinmez. BFR bu sorunu veriyi tek kez okuyarak çözer.
- BFR'de veri noktaları bellekte tutulmaz
  - Yalnız istatistikler ($N$, $SUM$, $SUMSQ$) güncellenir; yalnız yalıtılmış noktalar (RS) bellekte kalır.

## Kısa Tekrar Notları

- Kümeleme: aynı kümede yakın, farklı kümelerde uzak noktalar.
- Hiyerarşik: birleştirici (aşağıdan yukarı) ve bölücü (yukarıdan aşağı). Nokta atama: $k$ baştan verilir.
- Üç soru: temsil, yakınlık, durma.
- Öklid: centroid = boyut boyut ortalama. Öklid dışı: clustroid = diğerlerine "en yakın" gerçek nokta.
- Clustroid ölçütleri: en büyük uzaklığı en küçük, ortalama uzaklığı en küçük ya da uzaklık kareleri toplamı en küçük olan nokta.
- Durma: $k$ bilinirse $k$ kümede; bilinmezse cohesion ölçüsü (çap, yarıçap, yoğunluk) bir eşiği aşınca.
- Hiyerarşik karmaşıklık: $O(N^3)$, en iyi $O(N^2\log N)$.
- k-means: ata, merkezleri güncelle, yeniden ata; yakınsama = noktalar küme değiştirmez. Tur başına $O(kN)$.
- Dirsek yöntemi: ortalama uzaklığın düşüşünün birden yavaşladığı $k$ seçilir.
- Başlangıç: örnek + hiyerarşik kümeleme ya da birbirinden en uzak $k$ nokta.
- BFR: tek geçiş; DS (kümeye atanıp özetlenen), CS (birbirine yakın ama kümeye girmeyen, özetlenen), RS (yalıtılmış, bellekte tutulan).
- Özet: $N$, $SUM$, $SUMSQ$ → $2d+1$ sayı. Merkez $= SUM/N$; varyans $= SUMSQ/N - (SUM/N)^2$.
- Mahalanobis: $y_i = (x_i - c_i)/\sigma_i$, $MD = \sqrt{\sum y_i^2}$; eşik örneğin $3\sqrt{d}$.

## Detaylı Açıklamalar

- Birleştirici hiyerarşik kümeleme örneği (ekrandan, 00:40:00)
  - Altı iki boyutlu nokta: $(0,0)$, $(1,2)$, $(2,1)$, $(4,1)$, $(5,0)$, $(5,3)$. Başta altı küme vardır; $\binom{6}{2}=15$ ikilinin uzaklığı hesaplanır.
  - 1. birleşme: $(1,2)$ ile $(2,1)$ (uzaklık $\sqrt2 \approx 1{,}414$); merkez $(1{,}5;\ 1{,}5)$. Beş küme kalır.
  - 2. birleşme: $(4,1)$ ile $(5,0)$ (uzaklık yine $\sqrt2$); merkez $(4{,}5;\ 0{,}5)$. Dört küme kalır.
  - 3. birleşme: $(0,0)$ ile mavi küme (merkezler arası $\approx 2{,}121$); yeni merkez $(1,1)$. Üç küme kalır.
  - 4. birleşme: $(5,3)$ ile yeşil küme (merkezler arası $\approx 2{,}550$); yeni merkez $(4{,}7;\ 1{,}3)$ (tam değeri $(14/3,\ 4/3)$).
  - 5. birleşme: kalan iki küme birleşir. Bu sıra python ile doğrulanmıştır.
- Clustroid seçimi
  - Öklid dışı uzayda ortalama alınamaz. Kümedeki noktalardan biri seçilir. "En yakın" şu ölçütlerden biriyle tanımlanır: diğer noktalara en büyük uzaklığı en küçük olan, diğer noktalara ortalama uzaklığı en küçük olan ya da diğer noktalara uzaklıklarının kareleri toplamı en küçük olan nokta.
  - Kategorik değerli noktalar arasındaki uzaklık düzenleme uzaklığı ya da Jaccard uzaklığı gibi ölçülerle hesaplanabilir.
  <!-- BELİRSİZ: Hoca birinci ölçütü "maksimum uzaklıkları toplamının minimum olması" diye söyledi; MMDS'deki karşılığı büyük olasılıkla "en büyük uzaklığı en küçük olan nokta"dır. İlgili slayt karelerde yok. -->
- Cohesion (uyum) ölçüsü ile durma
  - Çap (diameter): kümede birbirinden en uzak iki nokta arasındaki uzaklık.
  - Yarıçap (radius): merkez ile kümedeki en uzak nokta arasındaki uzaklık.
  - Yoğunluk (density): kümedeki nokta sayısının çapa ya da yarıçapa (veya bunların karesine) bölümü.
  - Her birleşmeden sonra bu ölçü hesaplanır; ölçü önceden belirlenmiş eşiği aşınca birleştirme durdurulur.
  <!-- BELİRSİZ: Hoca yoğunluğun "yarıçapın karesine bölünmesiyle" de bulunabileceğini söyledi; slayt karelerde yok. Ayrıca hoca eşik yönünü bir yerde "eşiğin altına düşerse dururum" diye söyledi; kullanılan ölçüye göre (çap/yarıçap büyür, yoğunluk düşer) yön değişir. -->
- k-means çalışma örneği (ekrandan, 01:15:00)
  - $k=2$ ve iki başlangıç noktası verilir. 1. turda noktalar iki başlangıç noktasına atanır, merkezler güncellenir. 2. turda bazı noktalar diğer kümeye geçer. 3. turdan sonra yeniden atama hiçbir noktayı yer değiştirmez; algoritma yakınsar.
- Dirsek yöntemi
  - $k=2$'den başlanır; her $k$ için kümeleme yapılır ve noktaların kendi merkezlerine ortalama uzaklığı hesaplanır. $k$ arttıkça bu değer düşer. Düşüşün birden yavaşladığı (eğrinin dirsek yaptığı) $k$ en iyi değerdir.
- BFR adımları
  - Veri belleğe sığan parçalara bölünür (ör. 8 GB bellek için 6 GB'lık parçalar).
  - İlk parça: dirsek yöntemiyle $k$ bulunur, başlangıç noktaları seçilir, noktalar kümelere atanır. Kümeye yeterince yakın noktalar DS'ye girer ve atılır; yalnız istatistik güncellenir. Kalan noktalar bellek içi (hiyerarşik) kümelemeyle gruplanır: gruplar CS, tek kalanlar RS olur.
  - Sonraki parçalar: noktalar önce DS kümelerine, sonra CS'lere yerleştirilmeye çalışılır; yerleşmeyenler eski RS ile birlikte yeniden hiyerarşik kümelenir. Birbirine yakın CS'ler birleştirilebilir.
  - Son parça: kalan CS ve RS'ler en yakın kümeye atanır.
  - DS/CS özetinin $2d+1$ değeri: $N$ (1 sayı), $SUM$ ($d$ sayı), $SUMSQ$ ($d$ sayı). Merkez $c_i = SUM_i/N$, varyans $\sigma_i^2 = SUMSQ_i/N - (SUM_i/N)^2$, standart sapma bunun karekökü.
  <!-- BELİRSİZ: Hoca varyans formülünü ekranda gösterdi ama o slayt karelerde yok; yazılan formül MMDS'deki standart biçimdir. -->
  - İki CS'nin birleştirilmesi: $N$, $SUM$ ve $SUMSQ$ toplanarak birleşik kümenin varyansı hesaplanır; varyans eşiğin altındaysa birleştirilir.
- Mahalanobis uzaklığı (ekrandan, 01:55:00)
  - Küme merkezi $(c_1,\dots,c_d)$, standart sapmalar $(\sigma_1,\dots,\sigma_d)$, nokta $P=(x_1,\dots,x_d)$.
  - $y_i = (x_i - c_i)/\sigma_i$ ve $MD(P, C) = \sqrt{\sum_{i=1}^{d} y_i^2}$.
  - Nokta her boyutta merkezden 1 standart sapma uzaksa $MD=\sqrt d$; 2 sapma uzaksa $2\sqrt d$; 3 sapma uzaksa $3\sqrt d$.
  - Normal dağılımda noktaların %68'i $MD \le \sqrt d$, %95'i $MD \le 2\sqrt d$, %99'u $MD \le 3\sqrt d$ aralığındadır (ekrandan, 02:00:00). Nokta, MD'si eşikten (ör. $3\sqrt d$) küçük olan kümeye kabul edilir.
  - Ders sonrası not: Hoca 1 standart sapma için "%67" dedi; slaytta ve doğrusu %68'dir (tam değeri %68,27).
- Ders sonrası not (Jaccard)
  - Hoca iki belgenin kesişimindeki kelime sayısının birleşimindeki kelime sayısına bölümünü "Jaccard distance" diye andı. Bu oran Jaccard benzerliğidir; Jaccard uzaklığı $1 -$ bu orandır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
