# Ders 10 Çalışma Özeti

## Genel Konular

- Makine öğrenmesinin tanımı ve temel süreci
  - Çok büyük miktardaki verinin elle işlenmesi ve analizi artık mümkün değildir; makine öğrenmesi metotları bu tür problemler için geliştirilmiştir (ekrandan, 00:10:00).
  - Bu metotlar geçmişteki verileri kullanarak veriye en uygun modeli bulmaya çalışır, yeni gelen verileri de bu modele göre analiz edip sonuç üretir.
  - Algoritma seçmek aslında bir model ailesi seçmektir; bu seçim "bu veriyi bu aile ile iyi modellerim" şeklinde bir varsayımdır.
  - Seçilen ailenin parametrelerini eldeki veriye uyumlu hale getirme süreci, yani ailenin veriye en uygun üyesini arama süreci, eğitim sürecidir.
  - Eğitimden sonra eğitim kümesine ihtiyaç kalmaz; model, eğitim örneklerini bir formüle (karar sınırına) sıkıştırmıştır ve yeni örneğin çıkışını tek başına tahmin eder.
- Sınıflandırma
  - Çıkış kategorik bir değişkendir. Örnek tabloda $x_1 \dots x_5$ özellikleri ve A/B sınıf etiketi vardır; her satır bir örnektir (ekrandan, 00:15:00).
  - Doğrusal model ailesi: $w_1 x_1 + w_2 x_2 + w_3 = 0$. $w_1, w_2, w_3$ değiştikçe ailenin farklı üyeleri (farklı doğrular) elde edilir.
  - Eğitim kümesini hatasız ayıran birden fazla doğru olabilir ve bunlar yeni bir test örneğine farklı sınıflar atayabilir.
- Kümeleme (öbekleme, demetleme, clustering)
  - Örneklerin çıkışı yoktur (gözetimsiz öğrenme); örnekler genellikle önceden belirlenmiş sayıda kümeye atanır.
  - Kümeleme, farklı değer sayısını azaltır (kuantizasyon). Örnek: 256 rengin 16 renge indirilmesi (ekrandan, 00:25:00).
  - Başka örnek: bir GSM operatörünün milyonlarca müşterisini birkaç segmente ayırması.
- Regresyon (eğri uydurma)
  - Gözetimli öğrenmedir, ama çıkış sayısaldır. Örnek: motor gücünden maksimum hızın tahmini (ekrandan, 00:35:00).
  - Doğrusal model bu veriye tam uyamaz; tüm noktalardan geçen eğri ancak daha karmaşık bir model ailesiyle elde edilir (ekrandan, 00:40:00).
- Model esnekliği
  - Parametre sayısı arttıkça model ailesi esnekleşir ve eğitim kümesine uyma ihtimali artar.
  - Eğitim kümesindeki başarı, görülmemiş örneklerdeki başarı hakkında tek başına pek bir şey söylemez; basit bir model test kümesinde daha başarılı olabilir.
- Pekiştirmeli öğrenme
  - Modele çıkışın ne olması gerektiği söylenmez, yalnızca doğru ya da yanlış yaptığı (ya da ne kadar iyi/kötü yaptığı) söylenir (ekrandan, 00:45:00).
  - Ödül/ceza fonksiyonu tanımlanır; genelde birbirini etkileyen ardışık kararlar içeren problemlerde (oyunlar gibi) kullanılır.
- Birliktelik kurallarının keşfi
  - Sepet analizi (hangi ürünler birlikte satılıyor), raf düzenlemesi, promosyonlar (ekrandan, 00:50:00). Apriori gibi algoritmalar bu dersin kapsamı dışındadır.
- Uygulamalar
  - Dolar kuru tahmini (zaman serisi, regresyon), el yazısı/kitap yazısı tanıma (HCR/OCR), gen mikrodizilimleri, iris, yüz, parmak izi, ses, imza, spam, güvenlik kamerası ve işaret dili, otonom sürüş (ALVINN), yargı kararları, beyin aktiviteleri, öğrenmenin geleceği.
  - Basit bir OCR uygulamasında veri hazırlama, eğitim/test ayrımı ve başarı ölçümü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Modelin başarısı, eğitimde kullanılmayan örnekler üzerindeki performansıdır.
  - Eğitim ve test kümesinin ayrılmasının amacı, modelin gerçek dünyadaki (müşteri verisindeki) performansını doğru tahmin etmektir. Öğretmen sınıfta çözdüğü soruların aynılarını sınavda sorarsa öğrencilerin öğrenip öğrenmediğini mi yoksa ezberleyip ezberlemediğini mi bilemez.
- Zaman serisi problemlerinde eğitim ve test kümesi zamansal olarak ayrılmalıdır.
  - Bir yıllık veride örneğin ilk 8 ay eğitim, son 4 ay test olabilir. Veriyi karıştırıp rastgele bölmek modelin "kopya çekmesine" yol açar ve ölçülen performans gerçeği yansıtmaz. Hoca bunun çok yapılan bir hata olduğunu belirtti.
- 256 rengi 16 renge indirmek boyutu 16'da birine değil yarıya indirir.
  - Piksel sayısı değişmez; piksel başına 8 bit yerine 4 bit gerekir.
- Sınıflandırma probleminin zorluğu sınıf içi ve sınıflar arası benzerlikle değerlendirilir.
  - Sınıf içi benzerlik yüksek, sınıflar arası benzerlik düşükse problem kolaydır.
- Hata türlerinin maliyeti farklı olabilir (tip 1 ve tip 2 hata).
  - Hasta birine "sağlıklı" demek ile sağlıklı birine "hasta" demek aynı maliyette değildir; bu fark eğitime ceza olarak katılabilir.
- Makineye ne yapması gerektiğini söyleyebiliriz, nasıl yapması gerektiğini söyleyemeyiz.
  - Tank hikayesi: model tankları değil havanın güneşli ya da bulutlu olmasını ayırt etmeyi öğrenmişti.

## Kısa Tekrar Notları

- Makine öğrenmesi: model ailesi seç (varsayım), parametreleri veriye uydur (eğitim), yeni örnekte tahmin et.
- Sınıflandırma: çıkış kategorik. Regresyon: çıkış sayısal. İkisi de gözetimli.
- Kümeleme: çıkış yok, gözetimsiz; farklı değer sayısını azaltır (kuantizasyon).
- Pekiştirmeli öğrenme: yalnız doğru/yanlış ya da ödül/ceza geri bildirimi; ardışık kararlar, oyunlar.
- Birliktelik kuralları: sepet analizi, raf düzeni, promosyon.
- $n$ bit ile $2^n$ farklı değer tutulur; 256 renk 8 bit, 16 renk 4 bit.
- Esneklik parametre sayısıyla artar; eğitimde tam uyum test başarısını garanti etmez.
- Zaman serilerinde eğitim geçmişten, test gelecekten seçilir.
- Sınıf içi benzerlik yüksek ve sınıflar arası benzerlik düşükse sınıflandırma kolaydır.
- Tip 1 ve tip 2 hataların maliyetleri farklı olabilir.
- Adversarial örnekler makine öğrenmesi modellerini yanıltabilir.

## Detaylı Açıklamalar

- **Model ailesi ve eğitim.** Bir algoritma seçmek, eldeki veri için bir model ailesi seçmek demektir. Örneğin iki boyutlu bir sınıflandırma probleminde doğrusal model seçilirse aile $w_1 x_1 + w_2 x_2 + w_3 = 0$ biçimindeki bütün doğrulardan oluşur ve bu ailenin sonsuz üyesi vardır. Üyeleri birbirinden ayıran şey parametrelerdir. Eğitim, eldeki veriye en iyi uyan üyeyi (parametre değerlerini) aramaktır. Aynı uyuma sahip birden fazla üye bulunabilir; örneğin eğitim kümesini hatasız ayıran iki farklı doğru, yeni bir test örneğini farklı sınıflara atayabilir. Hoca bunun bir varyans oluşturduğunu söyledi, ama ayrıntısına girmedi.
- **Sınıflandırma örneği.** Slayttaki iki boyutlu şekilde mor (mavi) ve siyah noktalar iki sınıfı, kırmızı nokta sınıfı bilinmeyen test örneğini gösterir. Tablodaki her satır bir örnek, her sütun bir özelliktir (ekrandan, 00:15:00):

| x1 | x2 | x3 | x4 | x5 | Sınıf |
|---|---|---|---|---|---|
| 1.2 | 3.4 | 2.3 | 6.7 | 7.8 | A |
| 1 | 2 | 2 | 4 | 5 | A |
| 9 | 8 | 6 | 5 | 3 | B |
| 6 | 7 | 8 | 9 | 1 | B |
| 8 | 8 | 9 | 9 | 9 | B |

- **Kümeleme ve kuantizasyon.** Kümelemede çıkış bilgisi yoktur; amaç örnekleri benzerliklerine göre gruplamaktır. Bir resimdeki 256 farklı renk değerini 16 renge indirmek bir kümeleme problemidir: pikseller renklerine göre kümelenir ve her piksel kümesinin temsil değeriyle gösterilir. Resmin kalitesi biraz bozulur ama yer kazanılır. $n$ bitle $2^n$ farklı değer tutulabildiği için 256 renk 8 bit, 16 renk 4 bit gerektirir; piksel sayısı değişmediğinden boyut yarıya iner. Hoca, kuantum fiziğindeki "kuantum" sözcüğüyle aynı kökten gelen bu işleme kuantizasyon dendiğini belirtti. GSM operatörü örneğinde müşteriler; internet kullanımı, konuşma süresi, SMS sayısı, geçmiş faturalar, konum, yaş gibi özelliklere göre birkaç segmente ayrılabilir.
- **Regresyon ve esneklik.** Motor gücüne karşılık maksimum hız verisinde çıkış sayısaldır. Doğrusal bir model her noktaya tam uyamaz; her örnek için gerçek değer ile modelin tahmini arasındaki fark o örnekteki hatadır. Bütün noktalardan geçen bir eğri çizmek mümkündür ama bu doğrusal ailenin üyesi değildir; daha karmaşık (daha çok parametreli) bir aile gerekir. Bazı model aileleri her eğitim kümesine tam uyum sağlayabilir, bazıları sağlayamaz. Yine de basit modeller kullanılır, çünkü eğitimdeki başarı test başarısını garanti etmez. Hangi model ailesinin veriye en uygun olduğunu seçmek kolay değildir.
- **Geri bildirim türleri ve pekiştirmeli öğrenme.** Model 3 ürettiğinde "doğrusu 5'ti" demek doğrudan (gözetimli) geri bildirimdir. "Yanlış yaptın" demek daha az bilgi verir: model 3'ten uzaklaşması gerektiğini bilir ama hangi yöne gideceğini bilmez. "Doğruya 2 uzaksın" demek de başka bir geri bildirim türüdür (doğru 1 ya da 5 olabilir). Bu tür geri bildirimin kullanılma nedenleri: doğru cevabı biz de bilmiyor olabiliriz ve modelin keşfetmesini isteriz; biliyor olsak da etiketleme için zaman ve bütçe olmayabilir; birden fazla doğru hamle olabilir. Hoca, ChatGPT gibi sistemlerin eğitim sürecinde de pekiştirmeli öğrenme kullanıldığını ve toplanan etiketlerle bir ödül fonksiyonu oluşturulduğunu anlattı.
- **Dolar kuru tahmini.** Doların bugünkü değerinin yalnız önceki 3 günün değerine bağlı olduğu varsayılır (gerçekte doğru bir varsayım değildir). Seri kaydırılan bir pencereyle tabloya dönüştürülür (ekrandan, 01:05:00). Seri: 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1, ...

| D-3 | D-2 | D-1 | D |
|---|---|---|---|
| 6.1 | 6.2 | 6.3 | 6.3 |
| 6.2 | 6.3 | 6.3 | 6.3 |
| 6.3 | 6.3 | 6.3 | 6.2 |
| 6.3 | 6.3 | 6.2 | 6.4 |
| 6.3 | 6.2 | 6.4 | 6.1 |

  - Çıkış sayısal olduğu için bu bir regresyon problemidir.
- **El yazısı ve kitap yazısı.** Kitap yazısında küçük "a" sınıfının örnekleri birbirine çok benzer; el yazısında farklı kişilerin, hatta aynı kişinin yazdığı "a"lar bile birbirinden farklıdır. Bu yüzden kitap yazısı tanıma daha kolaydır. "O" ile "0" ya da "9" ile "g" gibi sınıflar arası benzerliğin yüksek olduğu durumlar zordur; "1" ile "8" ise kolay ayrılır.
- **Gen mikrodizilimleri.** 100 kişinin (hasta/sağlam) gen dizilimleriyle yeni bir kişinin hasta olup olmadığını ya da hastalık türünü öğrenmek sınıflandırmadır. İlaç dozunu tahmin etmek regresyon, farklı tedavi türlerinden birini önermek sınıflandırmadır (ekrandan, 01:15:00).
- **Tank hikayesi ve kara kutu.** Doğruluğundan emin olunmayan bir hikayede, tank kameralarından düşman tankını tanıyan bir yapay sinir ağı testlerde yaklaşık %100 başarı verir ama sahada şans düzeyinde kalır. Neden, dost tanklarının güneşli, düşman tanklarının bulutlu havada fotoğraflanmış olmasıdır: model havayı sınıflandırmayı öğrenmiştir. Hoca bu hikayeden şunu çıkardı: algoritmalar çıkışı optimize eder; makineye ne yapacağını söyleriz ama nasıl yapacağını söyleyemeyiz. Zaten nasıl çözüleceğini bilseydik (örneğin sıralama) algoritmasını doğrudan yazardık.
- **Biyometri ve adversarial örnekler.** İris deseni kişiye özeldir ve iki irisin aynı olma olasılığı hocanın hatırladığına göre milyarda birdir; ancak yakın mesafeden ve pahalı donanımla alınabilir. Hoca, iris tanımanın basit bir veritabanı eşleştirmesi olmadığını, ışık ve açı gibi değişimler yüzünden aynı irisin görüntülerinin de birebir aynı olmadığını açıkladı. Yüz tanımada doğruluk daha düşük ama erişim daha kolaydır. Tanıma algoritmalarını yanıltmak için tasarlanan desenler (adversarial örnekler) ayrı bir araştırma konusudur. Parmak izinde aynı olma oranını hoca milyonda bir olarak hatırladığını söyledi.
- **Otonom sürüş ve etik.** 1988 tarihli ALVINN çalışması (slaytta "ALVIN"), otobanda sürücüsüz gidebilen bir otomobildir ve yapay sinir ağı kullanır: 30x32 sensör girdisi, 4 gizli birim, 30 çıkış birimi (ekrandan, 01:45:00). Direksiyon açısı ve pedal konumları sayısal olduğu için bu bir regresyon problemidir. Hoca, makine hata yaptığında suçlunun kim olacağı gibi etik soruların öne çıkacağını vurguladı.
- **Basit bir OCR uygulaması.** Resimde önce satırlar, sonra harfler bulunur. Bütün karakterler 10x6'lık bir yapıya getirildiğinde her örnek 60 boyutlu uzayda bir nokta olur. Veri eğitim ve test kümesine bölünür, eğitim kümesi bir sınıflandırıcıya verilir, test örneklerinde modelin tahmini gerçek sınıfla karşılaştırılarak başarı ölçülür. <!-- BELİRSİZ: Bu slaytın karesi yok; altyazıda rakamlar için "her birinden 16 tane örnek" ve "100 tane örnek" birlikte geçiyor (10 rakam x 10 örnek = 100 olmalı). Örnek sayısı doğrulanamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
