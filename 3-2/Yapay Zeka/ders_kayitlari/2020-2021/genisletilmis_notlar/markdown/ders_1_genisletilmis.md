# Ders 1 Genişletilmiş Notu: Yapay Zekaya Giriş: Zeka Tanımları, Turing Testi ve Tarihçe

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konu Akışı ve Kaynaklar
- 2. Zeka Nedir?
- 3. Yapay Zeka Tanımları
- 4. Yapay Zekaya Nasıl Ulaşmalıyız? Dört Yaklaşım
- 5. Yapay Zekayla Neden Uğraşıyoruz?
- 6. Akıllı ve Zeki Davranışın İpuçları
- 7. Düşünce Deneyi: Ne Zaman Zeki Deriz?
- 8. Turing Testi
- 9. ELIZA
- 10. Searle'ün Çin Odası
- 11. Süreç mi Sonuç mu? Gauss, Ned Block ve Arnheim
- 12. Yapay Zeka Savunucuları ve Karşıtları
- 13. Yapay Zekanın Kısa Tarihi
- 14. Kimine Kolay, Kimine Zor
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Konu Akışı ve Kaynaklar

Hoca ilk derste dönemin konu akışını tanıttı. Ders, yapay zekanın tanımları ve tarihçesiyle başlıyor. Ardından yaklaşık beş haftalık bir blok halinde arama algoritmaları geliyor: kör arama, sezgisel arama, yerel arama, genetik algoritmalar ve oyunlar (ekrandan, 00:15:00). Hoca arama algoritmalarını "yapay zekanın en temel konusu" diye tanımladı. Sonra bilgi gösterimi ve çıkarım mekanizmaları, ardından makine öğrenmesi (yapay öğrenme), en sonda da yapay zekada etik ve hukuk konuları işlenecek.

Hoca etik ve hukuk konusunu neden derse koyduğunu şöyle açıkladı: yapay zekanın uygulama alanları ve toplumsal hayattaki yeri arttıkça bu uygulamaların etik ve hukuki sorunları da ortaya çıkmaya başladı ve önümüzdeki yıllarda artarak sürecek gibi görünüyor. Bu yüzden yapay zeka derslerinin içine artık bu konunun da girmesi gerekiyor.

Kaynak olarak hocanın slaytları yeterli. Daha fazlasını isteyenler için yapay zekanın klasik ders kitabı Russell ve Norvig'in kitabı öneriliyor: hacimli ama kapsamlı ve iyi bir kitap.

## 2. Zeka Nedir?

Yapay zekayı tanımlamadan önce zekanın ne olduğunu konuşmak gerekir: bir sisteme hangi kabiliyetlere sahip olduğunda zeki deriz? Slaytta iki soru vardı: "İnsanları diğer canlılardan ayıran özellik?" ve "Hayvanlar zeki olamaz mı?" (ekrandan, 00:25:00).

### 2.1 Hayvanlarda zekice davranış

Zekayı insanı diğer canlılardan ayıran özellik olarak tanımlamak doğru olmayabilir, çünkü hayvanların da zekice davranışları vardır. Hoca kendi gözlemini anlattı: Üniversitenin eski binasının yakınında ceviz ağaçları vardı. Kargalar cevizleri alıp yukarıdan otobana atıyor, arabalar cevizlerin üzerinden geçip onları kırıyor, sonra kargalar inip kırılmış cevizleri yiyordu.

Öğrenciler de örnekler verdi: Suya ulaşamayan bir karganın kaba taş atarak su seviyesini yükseltip suyu içmesi; bir kavanoza konan ahtapotun kapağı döndüre döndüre açıp kendini dışarı çıkarması; ayağı kırık bir sokak kedisinin yardım için tekrar tekrar aynı eve gelmesi.

### 2.2 Ayna testi

Ahtapot örneğinden sonra hoca ayna testini anlattı. Bu test, hayvanlarda benlik bilinci olup olmadığını ölçmek için kullanılır. Hocanın aktardığı biçimiyle:

1. Hayvana ayna gösterilir, kendini aynada görür.
2. Hayvan uyurken, haberi olmadan yüzüne boya sürülür.
3. Hayvan uyanınca ona tekrar ayna gösterilir.
4. Aynadakinin kendisi olduğunu anlıyorsa yüzündeki boyayı çıkarmaya çalışır. Anlamıyorsa aynadakine başka bir hayvan görmüş gibi tepki verir (kızar, alanını korumaya çalışır).

Hoca kedilerin bildiği kadarıyla bu testi geçemediğini, ahtapotun ise beklenmedik biçimde geçtiğini söyledi. Bu da ahtapotun oldukça farklı bir canlı olduğunu düşündürüyor. Hoca ayrıca böyle bir testi tasarlayabilmenin de büyük bir başarı olduğunu ekledi.

> **Ders sonrası not:** Hoca ayna testini ahtapotların da geçtiğini söyledi ama ahtapota testin nasıl uygulandığını bilmediğini belirtti. Ayna testini geçtiği yaygın kabul gören hayvanlar büyük olasılıkla büyük maymunlar, yunuslar, filler ve saksağanlardır; ahtapotlarla ilgili sonuçlar tartışmalıdır.

### 2.3 Sözlük tanımı ve Hawking'in sözü

Sonuç olarak hayvanlar da zeki olabilir; zekayı yalnız insana özgü saymak pek doğru değildir. Webster sözlüğüne göre zeka **öğrenme ve problem çözme kapasitesidir** (ekrandan, 00:25:00).

Slaytta ayrıca bazı harfleri rakamlarla değiştirilmiş şu yazı vardı (ekrandan, 00:25:00):

```text
1N73LL1G3NC3 15 7H3
4B1L17Y 70 4D4P7 70
CH4NG3.
573PH3N H4WK1NG
```

Bir öğrenci yazıyı "değişikliğe ayak uydurma yeteneği" diye okudu: "Intelligence is the ability to adapt to change. Stephen Hawking", yani "Zeka, değişime uyum sağlama yeteneğidir." Hoca yazının neden böyle yazıldığını sordu. Cevap: bunu okuyabiliyorsanız değişikliğe uyum sağlayabiliyorsunuz, yani zekisiniz. Hocaya göre sözün içeriğini sözün görüntüsüne yansıtmak başlı başına iyi bir zeka ürünü. Sözün sahibi Stephen Hawking, görseli yapan ise başkaları.

## 3. Yapay Zeka Tanımları

Zekanın da yapay zekanın da çok sayıda tanımı var, ama herkesin kabul ettiği açık ve net bir tanım yok. Hoca iki tanım verdi:

- **Marvin Minsky:** "İnsanlar tarafından yapıldığında zeka gerektiren şeyleri makinelere yaptırma arayışıdır."
- **Chris Riesbeck:** "Şu temel soruya cevap aramaktır: Bilgisayarlar neden bu kadar aptal?"

Hoca ikinci tanımı daha çok sevdiğini söyledi. Buradaki "aptal" ne demek? Bir öğrencinin cevabı: "Her şeyi anlatmak gerekiyor." Hoca da bunu onayladı: Bilgisayarlar biz söylemeden bir şey yapamaz. Bunun nedenini bulmaya ve çözmeye yönelik çalışmalar yapay zeka çalışmalarıdır.

Hoca, Minsky'nin tanımının zekayı tanımlamadığını, bu tanıma ileride (Arnheim'ın yöntem sorununda) yeniden döneceklerini söyledi.

> **Ders sonrası not:** Altyazıda ikinci tanımın sahibi "Chris Rasmick" diye geçiyor; slayttaki ad Chris Riesbeck'tir (ekrandan, 00:30:00 küçük resmi).

## 4. Yapay Zekaya Nasıl Ulaşmalıyız? Dört Yaklaşım

Tarihte yapay zekaya nasıl ulaşılacağı konusunda dört fikir ortaya çıkmıştır (ekrandan, 00:30:00):

| | İnsan gibi | Rasyonel |
|---|---|---|
| Düşünmek | İnsan gibi düşünmek | Rasyonel düşünmek |
| Hareket etmek | İnsan gibi hareket etmek | **Rasyonel hareket etmek** |

Tabloda iki boyut vardır: biri düşünmek / hareket etmek, diğeri insan gibi / rasyonel. Slaytta "Rasyonel hareket etmek" kırmızıyla vurgulanmıştı; bugün izlenen temel yaklaşım budur.

### 4.1 İnsan gibi mi, rasyonel mi?

**Rasyonel (doğru) davranış:** Eldeki verilere göre hedefe ulaşmada maksimum fayda sağlayan davranıştır (ekrandan, 00:30:00).

İnsan ile rasyonel aynı şey midir? Hoca sordu: İnsanlar her zaman mantıklı mı davranır, zararını bile bile bir şey yapar mıyız? Öğrenciler "yaparız" dedi. Herkesin rasyonel olmayan davranışları olabilir; belki insanı insan yapan da biraz budur. Tamamen rasyonel bir varlık, duygularına hiç kapılmaması gerektiği için bildiğimiz insan tanımına pek uymaz, daha çok bir robota benzer. Slaytta bu, "Duyguların düşünce üzerindeki etkileri" diye geçiyordu.

Slayttaki "Uçmayı kuşlardan öğrenmedik" ifadesini hoca şöyle açıkladı: Aslında uçmayı bir anlamda kuşlardan öğrendik, çünkü uçma araçlarının kanatları kuş kanatlarından esinlenmiştir. Ama sonunda bir fark oluştu: uçaklar kanat çırpmaz, yine de kuşlardan çok daha hızlı gider. Buradan çıkan sonuç: **Zeki davranışı gerçekleştirmek için insanı birebir taklit etmek zorunda değiliz.** İnsanda zekayı üreten şey beyin yapısıysa, o yapıyı (nöron bağlantılarını) aynen modellememiz şart değildir. Aynı problemi bambaşka bir yolla, belki daha iyi ve daha hızlı çözen sistemler kurabiliriz; tıpkı kanat çırpmadan, jet motoruyla çok daha yüksek hızlara ulaşmak gibi. Önemli olan insan gibi olmak değil, mantıklı kararlar verebilmek ve problemleri iyi çözebilmektir.

Slayttaki karşı ifade ise "Hedef insansa, onu modellemeliyiz." idi (ekrandan, 00:30:00).

### 4.2 Düşünmek mi, hareket etmek mi?

Yapay zeka çalışmaları başlangıçta "insan gibi düşünen sistemler" fikriyle başladı. Fakat bir sorun ortaya çıktı: İnsan gibi düşünen bir sistem yaptığınızı iddia ediyorsanız bunu nasıl test edeceksiniz? Bunun için insanın nasıl düşündüğünü bilmeniz, elinizde "bu sistem insan gibi düşünüyor / düşünmüyor" diyebileceğiniz bir ölçüt olması gerekir. İnsanın nasıl düşündüğünü tam bilmediğimiz için bu ölçülemez.

Bu yüzden "hareket etmeye" geçildi. Buradaki hareket fiziksel hareket değildir; **dışarıdan ölçülebilen şeyler, yani çıktılar üzerinden değerlendirme** demektir. Artık "bu sistem insan gibi düşünüyor mu?" diye sorulmaz; "bu problemi insan kadar ya da insandan daha iyi çözebiliyor mu?" diye sorulur. Düşünmekten hareket etmeye ve insandan rasyonele geçiş birlikte tablodaki kırmızı hücreyi verir: rasyonel hareket etmek.

Bir sonraki slaytta yapay zekanın geleceğine dair bazı ünlü kişilerin farklı görüşleri vardı. Hoca bu slaytın çok kritik olmadığını, bakılabileceğini söyledi ve bu kişilerden birinin (Roger Penrose) 2020'de Nobel aldığını hatırlattı.

## 5. Yapay Zekayla Neden Uğraşıyoruz?

Slayttaki iki temel hedef (ekrandan, 00:35:00):

- **Makineleri daha akıllı / yararlı hale getirmek.** Bu pragmatik hedeftir: işimizi daha çok gören, daha büyük problemlerimizi çözen, zaten faydalı olan bir şeyi daha faydalı yapan makineler.
- **İnsan zekasını daha iyi anlamak için onu simüle eden programlar yazmak.** Bu, kendimizi anlama hedefidir.

İkinci hedefi hoca bir bilardo örneğiyle açıkladı. Bilgisayarda bir bilardo oyunu yazacağınızı düşünün: istaka topa vuracak, top banda çarpacak, diğer toplara çarpacak, toplar dağılacak. Bunu gerçeğine benzetebilmek için bir şey bir şeye çarptığında, banda çarptığında, açıyla çarptığında ne olduğunu, yani bütün fizik kurallarını programa koymanız gerekir. **Bir şeyin simülasyonunu yapabilmek için onu anlamak gerekir.** Dolayısıyla insan zekasını simüle eden bir program yazabilirsek, insan zekasını da anlamış oluruz.

## 6. Akıllı ve Zeki Davranışın İpuçları

Zekayı tanımlamak zordur, ama zeki bir davranışı gördüğümüzde tanımak oldukça kolaydır. Peki neye bakarak "bu zekice bir şey" deriz? Slayttaki ipuçları (ekrandan, 00:40:00):

- Tecrübelerden öğrenme (sürekli öğrenme kabiliyeti)
- Yeni bir duruma başarılı ve çabuk adaptasyon
- Problem çözebilme
- Bilgiyi bulma ve kullanma
- Muhakeme edebilme
- Rastlantılardan yararlanabilme
- Farklılar arasındaki benzerlikleri görebilme
- Benzerler arasındaki farkları görebilme
- Yeni fikirler / kavramlar üretebilme
- Çok anlamlı / çelişki içeren bilgileri kullanabilme

### 6.1 Yeni duruma çabuk adaptasyon

Hoca bu maddeyi Hawking slaytıyla açıkladı. O yazıyı daha önce hiç görmemiş, İngilizce bilen biri ne yapar? Önce bazı karakterlerin başka karakterlerle değiştiğini algılaması, sonra neyin neyle değiştiğini çözmesi gerekir. Bunu ilk kez görüp okuyabilen birine zeki deriz. Ama birine önce "bu karakter şudur" diye öğretip sonra benzer bir yazıyı okutursak, onu okuyabilmek o kadar zekice sayılmaz. **İlk kez karşılaşılan bir durumu çözebilmek önemli bir kabiliyettir.**

### 6.2 Rastlantılardan yararlanabilme

Hoca bu maddeyi House M.D. dizisiyle anlattı. Dizide bir teşhis uzmanı ve ekibi garip hastalıklarla uğraşır, önce bir sürü yanlış tahmin yapar. Sonra House konuyla hiç ilgisiz birinden, bir olaydan ya da sohbette geçen bir sözden bir şey yakalar ve onu problemle ilişkilendirip çözüme ulaşır.

Rastlantılardan yararlanmak, **çözeceğiniz problemi sürekli ön planda tutmadan da onu çözebilmek** demektir. Problem kafanızda vardır ama siz başka bir şeyle uğraşırsınız; uğraştığınız şey arka plandaki problem için bir çözüm ipucu verir. Bu, arka planda problemi çözmeye devam ettiğinizi gösterir. Aralarında ilişki yokmuş gibi görünen şeyler arasında bağlantı kurabilmek önemli bir zeka ipucudur.

## 7. Düşünce Deneyi: Ne Zaman Zeki Deriz?

Aradan sonra hoca üç aşamalı bir düşünce deneyi yaptırdı ve öğrencilerin görüşlerini aldı.

### 7.1 Birinci aşama: 1000 yıl öncesi

Slayttaki soru: "1000 yıl öncesinde yaşayan birisinin eline bir bilgisayar versek ve yapabildiklerini göstersek (hesaplama, oyunlar, filmler, yüz tanıma vs.), ona zeki der mi?" (ekrandan, 00:50:00)

Bir zaman makinesiyle bin yıl öncesine bir dizüstü bilgisayar götürdüğümüzü düşünelim: çok hızlı hesap yapıyor, satranç oynuyor, film gösteriyor, yüz tanıyor, konuşuyor. Öğrenci görüşleri:

- Gösteren kişiyi cadı sanıp yakmaya çalışabilirler.
- Bin yıl geriye gitmeye bile gerek yok; bugün de telefonun yaptıklarına şaşıranlar var, bilgisayara büyük olasılıkla zeki derler.

Hoca soruyu genişletti: Diyelim ki o kişiye, belki yıllar sürecek biçimde, bilgisayarın nasıl çalıştığını (programlar, algoritmalar, donanım) anlattık. O zaman hâlâ zeki der mi? Öğrenciler büyük olasılıkla demeyeceğini söyledi. Hoca "Siz kendi bilgisayarınıza ya da telefonunuza zeki diyor musunuz?" diye sordu. Cevap "hayır" oldu; bir öğrenci onları "iyi programlanmış araçlar" olarak gördüğünü söyledi. Bir başka öğrenci, o durumda kişinin belki "onu yapan zeki" diyeceğini ekledi.

### 7.2 İkinci aşama: Android

Slayttaki ikinci soru: "Size dersin sonunda yüzümü sıyırıp bir android olduğumu gösterirsem bana zeki der misiniz?" (ekrandan, 00:55:00)

Dersin başından beri karşınızda insandan ayırt edemediğiniz, soru soran, cevap bekleyen, cevap gelmeyince üzülen bir varlık var. Ona bir insan olduğu için zeki diyordunuz. Android olduğunu öğrenince ne olur? Öğrenci görüşleri:

- İnsani özelliklerin hepsini gösteriyorsa yine zeki derim; yalnız üretilmiş olduğu için zeki dememek bir tür ayrımcılık olur.
- Aldatıldığımı düşünür, zeki değil derdim.
- Nasıl programlandığına bağlı: İnternetteki her şeyi okuyup insanların tepkilerinden öğrenen bir sistemse zeki derdim; her soruya cevabı önceden yazılmışsa demezdim.

Hoca son görüşe şöyle karşılık verdi: İnternetten öğrenen o sistem de bir program değil mi? Analiz yapan kısım da bir kod. Bilgisayarı en alt seviyede düşünürsek her şey toplama, çıkarma, atama gibi temel işlemlere, en altta da AND ve NAND kapılarına iner. Üstte makine öğrenmesi gibi bir şey çalışsa bile altta hepsi temel kodlardır.

Diğer görüşler:

- Bir androidin zekasını yalnız insana benzemesiyle ölçseydik, dersin başındaki ahtapot ya da kargaya da zeki demezdik; benzemese de zeka olabilir.
- İnsanlar açıklayamadıkları ve kendilerinden üst seviyede problem çözen şeylere zeki der. Açıklandığı anda "işin büyüsü gider", artık zeki görülmez.
- Tam tersine, biz anladığımız şeylere zeki deriz: Arıların kendi aralarında bir iletişim dili olduğunu anlayınca onların zeki olduğunu düşünmeye başladık. Hoca bunu "en azından bir iletişim seviyesi kurmuş olmak gerekir" diye özetledi.
- Herkesi kandırabilecek kadar insan gibi davranabiliyorsa hem android hem onu programlayan çok zekidir.
- Zeka aklı kullanabilme yeteneğidir; bilgi birikimini işleyip cevap verebiliyorsa zekidir. Bir insanın beynini açıp algoritmasını görebilseydik de aynı şey çıkardı.

Hoca bu aşamada şunu da sordu: Kaynak kodu açıp algoritmayı gösterseydik, "bütün hikaye buymuş" diye gördükten sonra hâlâ zeki der miydiniz?

### 7.3 Üçüncü aşama: Beynin yerinde bir devre

Üçüncü aşamada hoca şu senaryoyu verdi: İki gündür geçmeyen bir baş ağrısı yüzünden doktora gidiyorsunuz, beyin görüntülemesi yapılıyor. Doktor sizi acilen çağırıyor ve görüntüde beyin sandığınız yerde bir elektronik sistem olduğunu görüyorsunuz. Yani android olan siz imişsiniz. Bugüne kadar sevindiniz, üzüldünüz, bir sürü şey yaşadınız. Kendinizi hâlâ zeki bir varlık olarak görür müsünüz?

Öğrenci görüşleri:

- Hayır; her şey kafamda kodlanmışmış, bir "ben" bile yokmuş diye hissederdim.
- İnsanın kendi bilincinin farkında olması zekanın göstergelerinden biridir; "zeki değilim" diye düşünebilmek bile zeka belirtisidir.
- Zeka üst düzeyde örgütlenmiş bir yansıtma yeteneğidir. Sınırları önceden belli bir kod zeka belirtisi olamaz; ama birbirinden kopuk şeyleri birleştirip yeni bir şey tasarlayabiliyorsak, beynimizin içinde ne olursa olsun bu zekadır.
- Zeka arkadaki algoritmadan bağımsızdır. Bir satranç robotu o dalda zekidir; ben de yaşadıklarımı bir çip sayesinde yaptıysam yine zekiyim. Programlanmış olmak zekayı etkilemez.
- Duygular daha yavan, sahte gelirdi; bir olaya verdiğim tepkinin programlanmış mı yoksa kendi düşüncem mi olduğu konusunda ikileme düşerdim.

Hoca tasarım görüşüne şöyle karşılık verdi: Siz de hayatta birbiriyle ilgisiz görünen iki şeyi birleştirip sürekli yeni çözümler buluyorsunuz; ama senaryoya göre bunu yapan şey bir program. Öğrenci, bu varoluş sorgusunu yapabildiği sürece yine kendine zeki diyeceğini söyledi. Hoca ikilem görüşüne de şöyle cevap verdi: "Kendin" diye ayrı bir şey yok, ortada bir program var; o program kendi hakkında düşünebilecek, yorum yapabilecek biçimde yazılmış.

Hoca bu tartışmalarda kesin bir cevap vermedi; amaç, zekayı neye göre tanımladığımızı sorgulatmaktı. Tartışmanın ardından hoca yapay zekayla ilgili disiplinleri gösterdi: bilgisayar bilimleri, psikoloji, felsefe, dilbilim ve nöroloji (ekrandan, 00:55:00 küçük resmi).

## 8. Turing Testi

Turing 1950'de "Bilgisayarlar düşünebilir mi?" sorusunu ele alan bir makale yazdı. Testin modernleştirilmiş bir çizimi slaytta vardı (ekrandan, 01:15:00): solda "HUMAN INTERROGATOR", duvarın ardında ya "HUMAN" ya da "AI SYSTEM".

Kurgu şöyledir: Duvarla ayrılmış iki oda vardır. Sol odada bir insan sorgulayıcı oturur. Sağ odada ya bir insan ya da bir yapay zeka sistemi vardır. Sorgulayıcı belirli bir süre (örneğin 5 ya da 10 dakika) karşı tarafla yalnız yazışır, sorular sorar, cevaplar alır. Sürenin sonunda karşısındakinin insan mı makine mi olduğuna karar vermesi istenir. **Sorgulayıcı karar veremiyorsa ve karşıdaki bir yapay zeka sistemiyse, bu sisteme zeki demeliyiz.**

Bu testte sorgulayıcının elinde yalnız yazışma vardır; sistemin içinde nasıl çalıştığı hiç ilgilendirmez. Turing, **bir sistemin zeki olup olmadığına yalnız çıktıları üzerinden karar verilmesini** önerir.

Turing testinden sonra bu fikre dayanan yarışmalar düzenlendi (Loebner yarışması, ekrandan 01:15:00). Bu yarışmalarda bir jüri sistemlerle diyalog kurup puan verir ve her yıl en yüksek puanı alan sohbet programı seçilir. Hocaya göre bugüne kadar 10 dakikalık bir diyalogda Turing testini geçebilen bir sistem yoktur.

### 8.1 Süre neden önemli?

Hoca sordu: Bir sistemin bir dakika boyunca insan gibi davranabilmesiyle on dakika boyunca davranabilmesi arasında fark var mı? Bir öğrenci, uzun sürede sistemin kendini tekrar etmeye başlayabileceğini söyledi. Hocanın açıklaması: Kısa sürede sorulabilecek soruların ve olabilecek durumların sayısı azdır; uzun sürede bu sayı çok çok daha fazladır. Bu yüzden insan taklidini uzun süre sürdürmek çok daha zordur.

Turing 1950'de, 50 yıl içinde (yani 2000'lere kadar) makinelerin böyle bir diyaloğu geçebileceğini tahmin etmişti. Hocaya göre bu henüz gerçekleşmedi ve yakın zamanda gerçekleşecek gibi de görünmüyor.

## 9. ELIZA

ELIZA, 1965'te Joseph Weizenbaum tarafından yazılmış ilk sohbet programıdır ve bir terapisti simüle eder (ekrandan, 01:20:00). Slayttaki diyalog (kırmızılar kullanıcı, büyük harfli siyahlar ELIZA):

```text
Men are all alike.
IN WHAT WAY?
They're always bugging us about something or other.
CAN YOU THINK OF A SPECIFIC EXAMPLE?
Well, my boyfriend made me come here.
YOUR BOYFRIEND MADE YOU COME HERE?
He says I'm depressed much of the time.
I AM SORRY TO HEAR THAT YOU ARE DEPRESSED.
It's true that I am unhappy.
DO YOU THINK COMING HERE WILL HELP YOU NOT TO BE UNHAPPY?
I need some help, that much seems certain.
TELL ME MORE ABOUT YOUR FAMILY.
My mother takes care of me.
WHO ELSE IN YOUR FAMILY TAKES CARE OF YOU?
My father.
YOUR FATHER
```

Hoca derste hangi rengin kime ait olduğunu sordu (bkz. Örnek Sorular).

### 9.1 ELIZA nasıl çalışır?

ELIZA'nın elinde şablonlar vardır. Şablonlarda X, Y gibi değişken kısımlar bulunur. Kural kabaca "girdide şu kalıbı görürsen şöyle cevap ver" biçimindedir; ELIZA değişken kısımları aynen kopyalar ya da yerlerini değiştirir. Uyan bir şablon yoksa genel amaçlı cevaplarından birini verir. Birkaç yüz kadar böyle kural vardır.

Örneğin kullanıcı "My boyfriend made me come here" dediğinde ELIZA "me"yi "you"ya çevirip cümleyi soruya dönüştürür: "YOUR BOYFRIEND MADE YOU COME HERE?" Yani söyleneni gerekli değişikliklerle tekrar eder.

Bu yaklaşım Rogerian psikoterapi tekniğine dayanır: Bir insanın kendi ağzından çıkanları başka birinin ağzından duymasının ona yeni bir farkındalık kazandırabileceği düşüncesi. ELIZA da çoğunlukla kullanıcının girdisini dönüştürüp ona geri söyler.

ELIZA'nın zeki olmadığı açıktır; ama 1965'in insanlarından bazılarını etkilemiş, "içeride biri var" hissi uyandırmıştır. Arkasında ise oldukça basit bir şablon mekanizması vardır.

## 10. Searle'ün Çin Odası

Hoca John Searle'ün düşünce deneyini anlattı. Bir oda düşünün. Odanın bir girdi penceresi (bir ekran gibi) vardır; orada bazı şekiller belirir. İçerideki kişi şekillere bakar, sonra bir kural kitabına bakar. Kural kitabına göre veri çekmecelerinden bazı şeyleri alır, gerekirse keser, birleştirir ya da kendisi yazar ve belirli bir sırayla çıktı penceresinden dışarı atar.

Şimdi bu düzenin bir Çinliyle konuşabildiğini, yani Çinlinin yazdıklarına anlamlı Çince cevaplar üretebildiğini düşünelim. Soru: **İçerideki insan Çince biliyor mu?**

Bir öğrenci, kişinin yıllar içinde Çince öğrenebileceğini söyledi. Hoca bunun ayrı bir mesele olduğunu belirtti: Üç yıl sonra içerideki kişiyi değiştirirseniz sistemin çalışmasında bir değişiklik olmaz. Yani içerideki kişinin Çince bilmesine gerek yoktur; bilmeden de bu işi rahatlıkla yapabilir. Peki oda bir bütün olarak Çince biliyor mu? Biliyor görünmesi yeter mi?

Hoca bu düzenin neyi temsil ettiğini sordu ve sınıfla birlikte şu eşleşmeyi kurdu:

| Çin odası | Bilgisayar |
|---|---|
| Odanın tamamı | Bilgisayar |
| İçerideki kişi | İşlemci |
| Kural kitabı | Program |
| Veri çekmeceleri | RAM ve sabit disk |

Bir bilgisayar tam olarak böyle çalışır: Bir program vardır, işlemci bu programı verilere bakarak yürütür. Başka türlü bir bilgisayar mimarimiz yoktur. Searle'e göre böyle çalışan bir sistem, dışarıdan ne yapabilirse yapsın, **hiçbir şekilde zeki olarak değerlendirilemez.**

## 11. Süreç mi Sonuç mu? Gauss, Ned Block ve Arnheim

### 11.1 İki öğrenci: Gauss hikayesi

Hoca önce bilinen hikayeyi anlattı. Gauss'un ilkokul öğretmeni sınıfı oyalamak için 1'den 100'e kadar olan sayıları toplamalarını ister. Gauss sayıları yazar ve şunu fark eder: ilk ile son sayının toplamı 101, ikinci ile sondan ikincinin toplamı da 101, üçüncü ile sondan üçüncününki de 101. Böyle 50 tane 101 vardır; cevap 50 tane 101'in çarpımıdır.

$$1+2+\dots+100 = 50 \times 101 = 5050$$

(Sonuç derste söylenmedi; çarpım python ile doğrulandı.)

Slayttaki genel hali (ekrandan, 01:25:00):

$$1+2+3+\dots+N = \frac{N}{2}\,(N+1)$$

Sonra hoca hikayeyi değiştirdi: Sınıfta bir çocuk daha var ve tek özelliği **inanılmaz hızlı ve doğru toplama yapabilmesi**. Gauss'un formülü bulup cevaplaması örneğin 10 dakika sürdüyse, bu çocuk 1'den N'e kadar olan sayıları tek tek toplayarak 1 dakikada bitirebiliyor. Slayttaki soru: "İlki çook hızlı olsa daha zeki mi olur?"

Öğretmen yalnız çıktıya, yani doğru toplamı ne kadar hızlı verdiklerine bakarsa hızlı çocuğu daha değerli bulabilir. Gauss hatta 101 ile 50'yi çarparken küçük bir hata bile yapabilir. Ama sürece bakılırsa Gauss'un yaklaşımı çok daha zekicedir: Sayıları tek tek toplamak yerine bir tasarım kurgulayıp problemi dönüştürmüştür. Yalnız sonuca odaklanırsak bu değeri yakalayamayız, çünkü sıradan ama hızlı yöntem daha iyi görünür.

Hızlı toplayan öğrenci **bilgisayarı** temsil eder: Bilgisayar 1'den N'e kadar olan sayıları, bizim bir bölme ve bir çarpma yapmamızdan çok daha hızlı toplar. Hikayenin dersi: **Yalnız sonuca değil sürece odaklanmak da zekanın bir ipucudur.**

### 11.2 Ned Block'un soru-cevap ağacı

Slayttaki ifade (ekrandan, 01:30:00):

- X saatten az her mümkün söyleşinin içinde yer aldığı bir ağaç yapısı.
- Belki de depolayamayacağımız kadar büyük ama varsayalım ki elimizde.
- Zeka yalnızca soruları zeki bir insandan ayırt edilemeyen bir yolla yanıtlama yeteneği değildir.
- Bir davranışı zeki diye adlandırmak bu davranışın nasıl üretildiği hakkında bir önermede bulunmaktır.

Hocanın açıklaması: Örneğin 5 dakikalık iki insan arasında geçebilecek bütün olası diyalogları topladığımızı düşünelim. Böyle bir sistem tamamen eğer-ise kurallarıyla çalışır, ama Turing testini geçer. Block'a göre Turing testini geçmek bir sistemin zeki olduğunu göstermez. Block da çıktıya değil sürece odaklanılması gerektiğini savunur.

### 11.3 Rudolf Arnheim: Yöntem sorunu

Arnheim'a göre (ekrandan, 01:30:00 küçük resmi): Zekanın çözebildiği her problemin yalnız zeka ile çözüleceğini söyleyemeyiz. Zihinsel süreçler çıktıları aracılığıyla tanımlanmadıkça ya da zekanın işleyişine dair mekanizma netlik kazanmadıkça bilgisayarların kullandığı yönteme zekice denemez.

Hoca bunu Minsky'nin tanımıyla bağladı: Minsky "insanlar yaptığında zeka gerektiren şeyleri makinelere yaptırma" diyordu. Arnheim'a göre bir iş insan yaptığında zeka gerektiriyor olabilir, ama makine yaptığında makinenin zeki olduğu anlamına gelmez.

Arnheim'ın koyduğu iki koşulu hoca şöyle açtı:

- **Zihinsel süreçlerin çıktılarla tanımlanması:** Bu, fonksiyonelist bakış açısıdır, yani Turing'in bakışı. Fonksiyonel açıdan dışarıdan bakıldığında bir insandan farkı görülmüyorsa, içeride nasıl yapıldığı önemsizdir; insan zekiyse bu sistem de zekidir.
- **Zekanın mekanizmasının ortaya çıkması:** Birileri insan zekasının "kodunu" bulursa, yani insanın da arka planda bir programı izlediği ortaya çıkarsa, o zaman ne yapay zeka ne de zeka diye bir ayrım kalır; hepsi programlanmış bir şey olur.

Bu ikisi gerçekleşmedikçe bilgisayarların yöntemine zekice diyemeyiz, çünkü bilgisayarlar yalnızca hızlıdır.

<!-- BELİRSİZ: Bir sonraki slaytta ("Rudolf Arnheim - Yöntem sorunu", slayt 21) Thorndike'ın 1890'larda hayvanlara atfettiği deneme-yanılma yöntemiyle bir karşılaştırma var gibi görünüyor; yalnız küçük resimde göründüğü ve derste okunmadığı için nota alınmadı. -->

### 11.4 Hocanın değerlendirmesi

Hoca iki tarafın karıştırılmaması gerektiğini vurguladı. Bir sistemin zeki olup olmadığını süreçlere bakarak, yani "insan bunu nasıl yapıyor, sistem de öyle mi yapıyor" diye ölçmeye kalkarsak elimizde nesnel bir şey yoktur, çünkü insanların nasıl düşündüğünü çok az biliyoruz. Turing bu yüzden süreçlere değil çıktılara odaklanmayı önerir. Öte yandan karşı tarafın itirazları da haklıdır: Turing testini geçen şey arkada çok basit eğer-ise kurallarıyla çalışıyorsa ona da mı zeki diyeceğiz? O zaman hesap makinesine neden zeki demeyelim?

> **Hocanın vurgusu:** Bu hâlâ tartışmalı bir konudur; hangi tarafın kesin haklı olduğunu söyleyebileceğimiz bir noktada değiliz. Hoca öğrencilerin bu süregelen tartışmalardan haberdar olmasını istedi.

## 12. Yapay Zeka Savunucuları ve Karşıtları

### 12.1 Savunucular: iki grup

Yapay zeka savunucuları kabaca iki gruba ayrılır (ekrandan, 01:45:00). Burada "aşağısı" donanımı, "yukarısı" yazılımı temsil eder.

- **Aşağıdan yukarıyacılar:** Beynin fiziksel yapısı bilişsel yapımızda önemli bir yere sahiptir.
  - Yapay sinir ağları: Bu dünyanın bir kuramına sahip olmadan da zeki bir şekilde davranmanın mümkünlüğü. Hoca bunu örnek tabanlı öğrenme diye açıkladı.
- **Yukarıdan aşağıyacılar:** Simgesel temsil şemalarına ve düşünme kurallarına odaklan, beynin fiziksel yapısına takılma.
  - Arama
  - Mikro dünyalar
  - Marvin Minsky'nin frame'leri, Roger Schank'ın senaryoları
  - Sağduyu bilgisi

Yukarıdan aşağıyacılara göre bu bilgiler mantıksal olarak kodlanıp makinelere verilmelidir. Aşağıdan yukarıyacılar ise yapay sinir ağlarıyla örnek tabanlı öğrenmeyi savunur.

Hoca şu anda slaytta üstte yazılı grubun (aşağıdan yukarıyacılar, yani yapay sinir ağları) önde olduğunu söyledi. Ama bu denge geçmişte değişti, ileride de değişecektir; bir tarafın kesin kazanacağı söylenemez.

### 12.2 Karşıtlar

- **John Searle:** Tek başına sentaks (sözdizimi), ne miktarda olursa olsun, semantiği (anlamı) ortaya çıkarmaz. Bilgisayarlar işledikleri simgelerin anlamına dair hiçbir anlayışa sahip değildir. Anlam yoksa zeka da yoktur.
- **Gödel Teoremi:** Kurt Gödel, en azından aritmetik (çarpma işlemi) içeren her biçimsel sistemde insanların doğruluğunu bildiği ama makinelerin (sistemin) ispatlayamadığı doğrular olduğunu ortaya koymuştur.
- **John Lucas:** Böyle doğrular olduğuna göre insan zihni makinelerin kapasitesinin her zaman üstünde kalacaktır.

> **Ek bilgi (derste anlatılmadı):** Gödel'in eksiklik teoremi kabaca şunu söyler: Temel aritmetiği ifade edebilen ve çelişkisiz olan her biçimsel sistemde, sistemin içinde ne ispatlanabilen ne de çürütülebilen doğru önermeler vardır. Lucas'ın (ve sonra Penrose'un) bu teoremden insan zihninin makinelerden üstün olduğu sonucunu çıkarması felsefede çok tartışılan bir argümandır.

### 12.3 Turing ve Searle

- **Turing:** "Makineler düşünebilir mi?" sorusu felsefi bir yaklaşımdan çok deneysel bir yaklaşımla ele alınmalıdır, çünkü felsefi yaklaşım sonuç vermiyor.
- **Searle:** Deneysel bir yaklaşım olamaz, çünkü bir programı takip eden şey asla düşünemez.

Buradan akla gelen soru: İnsanlar da bir programı takip ediyor olabilir mi? Bunu henüz bilmiyoruz. İnsanların belli düşünce kalıpları elbette vardır, ama burada sözü edilen, bütün sistemin işleyişini kontrol eden bir programdır. Böyle bir şey varsa, hocaya göre bu tartışmaların belki hiçbir önemi kalmaz.

## 13. Yapay Zekanın Kısa Tarihi

Hoca tarihçede yapay zekanın inişlerini ve çıkışlarını gösterdi.

### 13.1 Başlangıç

- **1943:** McCulloch ve Pitts ilk yapay nöron tasarımını yaptı. O dönemin terimiyle "otomatlar" üzerine çok fikir birikmişti; yeni elektronik teknolojilerle bunları hızla uygulamak ve denemek imkanı doğdu.
- **1949:** Hebb öğrenme kuralı: İki nöron aynı anda aktif olursa aralarındaki bağ güçlenir.
- **1950:** Turing'in makalesi.
- **1951:** Minsky ve Edmonds ilk yapay sinir ağı bilgisayarını geliştirdi.

Hoca Hebb kuralını Pavlov'un köpek, mama ve zil deneyiyle ilişkilendirdi: Hebb kuralı o deneydeki koşullanmayı biyolojik açıdan açıklayan bir yaklaşımdır.

> **Ders sonrası not:** Hoca McCulloch ve Pitts'in çalışmasını "transistörlerin ilk ortaya çıkışının hemen ardından" diye anlattı; transistör 1947'de icat edildiği için 1943 ondan öncedir. Hoca büyük olasılıkla ilk elektronik hesaplama makinelerinin ortaya çıktığı dönemi kastetti. Ayrıca Donald Hebb biyolog değil, büyük olasılıkla bir psikolog (nöropsikolog) olarak bilinir.

> **Ders sonrası not:** Altyazıda tarihler "1449" ve "1905" diye geçiyor; slayta göre doğrusu 1949 (Hebb) ve 1950'dir (Turing'in makalesi) (ekrandan, 01:45:00 küçük resmi).

### 13.2 1950-1966: Büyük beklentiler dönemi

Slayttaki tahminler (ekrandan, 01:50:00):

- **1950, Turing:** 50 yıl içinde sıradan sorgulayıcıların en az yüzde 30'u 5 dakikalık bir diyalogdan sonra doğru kararı veremeyecek. Bu gerçekleşmedi.
- **1957, Newell ve Simon:** On yıl içinde dünya satranç şampiyonu bir bilgisayar olacak. 1967'de değil, 1997'de gerçekleşti.
- **1950-60 arası:** Otomatik dil çevirisi çok yakınımızda. Otomatik çeviride büyük aşamalar kaydedildi, ama uzman bir insan kadar iyi çeviri yapan bir sistem hocaya göre henüz yok.

### 13.3 Neden gerçekleşmediler?

Slayttaki üç neden (ekrandan, 01:50:00 küçük resmi):

- **Dünya / sağduyu (commonsense) bilgisinin büyük etkisi:** Dünyanın nasıl işlediğine dair bilginin bilgisayarlarda olmaması, bu bilginin bilgisayara nasıl aktarılacağı ve problem çözmede nasıl kullanılacağına dair büyük ölçekli bir mekanizma kurulamaması.
- **Problemlerin karmaşıklığının üstel olması:** Satranç tahmini 10 yılda değil 40 yılda gerçekleşti. 8×8 tahtada çok sayıda hamleyi ileriye doğru tahmin etmek gerekir ve hesaplama maliyeti üstel artar. Bilgisayarlar hızlandıkça aynı problemlere çözüm üretilebildi: Eskiden çok uzun düşünmeleri gerekirken artık makul sürede dünya şampiyonlarını yenebiliyorlar. Ama örneğin 24×24'lük yeni bir satranç tahtasında arama uzayı korkunç büyüyeceği için bilgisayarlar üstünlüklerini koruyamayabilir. Hoca bu konuya dersin arama ve oyunlar bölümünde döneceklerini söyledi.
- **Kısıtlı dünyaların (mikro dünyalar) gerçek dünyayı modelleyememesi:** Örneğin yalnız 3-5 iş yapabilen bir makineye doğal dille komut vermek mümkündür; ama yapılabilecek şeylerin sayısı çok artınca küçük bir dünyadan gerçek dünyaya geçmek kolay olmaz.

### 13.4 1966-1973: Biraz da gerçekler

Slayttaki maddeler (ekrandan, 01:55:00):

- **1969:** Minsky ve Papert'in yapay sinir ağlarının birçok problem türünde başarısızlığını kanıtlaması, yapay sinir ağları çalışmalarına ayrılan fonların durdurulması. Hoca kitabın adını "Perceptron" olarak hatırladı: Kitapta tek katmanlı ağların çok basit problemler dışında karmaşık problemleri çözemediği gösterildi.
- **1969:** Bryson ve Ho çok katmanlı yapay sinir ağlarını keşfetti, ama bir eğitim algoritması olmadığı için 1980'lere kadar ilgi görmedi.
- **Otomatik çeviri sistemlerinde hüsran:** Slayttaki örnek: "the spirit is willing, but the flesh is weak" cümlesi İngilizceden Rusçaya çevrilip geri alındığında "the vodka is good but the meat is rotten" olmuştur. Sorunlar dünya bilgisi ve eş anlamlılık gibi konulardan kaynaklanır.

Hoca sinir ağlarının seyrini şöyle özetledi: 1969'dan sonra durgunluk, 1980'lerde geri yayılım (backpropagation) algoritmasıyla (hoca Hinton'u andı) yeniden ilgi, 2012'den sonra ise asıl yapay sinir ağları dönemi. Hocaya göre 2012'den bugüne yapay sinir ağlarının diğer modellere karşı belirgin bir üstünlüğü var. Çeviri sistemleri de zamanla çok iyileşti, ama henüz insan düzeyinde değil.

> **Ders sonrası not:** Altyazıda "Minsk-Glap-Report" ve "Bryanson" diye geçen adlar slayta göre Minsky ve Papert ile Bryson ve Ho'dur. Hoca bir yerde "Yapay Zeka'nın karmaşık problemleri çözemediğini" dedi; kastedilen yapay sinir ağlarıdır (perseptron). Kitabın adı büyük olasılıkla "Perceptrons" (1969)'tur.

### 13.5 1979-1990: Güzel zamanlar

- Uzman sistemler ortaya çıktı.
- **1981-1991:** Japonya, Prolog tabanlı çalışan zeki makineler üretmek için "Fifth Generation" adlı projesini duyurdu. Amaç, Prolog'u donanım seviyesinde çok hızlı çalıştırabilen makineler yapmaktı.
- Amerika ve Avrupa, Japonya'nın gerisinde kalmamak için yapay zeka projelerine büyük paralar yatırdı. Hoca arka planı şöyle anlattı: Japonya elektronikte minyatürleştirme alanında çok hızlı ilerlemişti; küçülttükçe daha karmaşık sistemleri daha küçük yerlere sığdırabiliyordu. Bu alanda geride kalan ABD ve Avrupa, yapay zekada geride kalmak istemedi.
- Yazılımda yeni klişe: "Now with AI". Hoca bunun günümüzde de benzer şekilde yaşandığını, her ürünün içinde bir "yapay zeka" lafı geçtiğini söyledi. Bir öğrenci de telefon alırken satıcının "bunda yapay zeka var" dediğini, ama ne yaptığını açıklayamadığını anlattı.
- Yapay zeka firmalarının sayısında büyük artış oldu.

### 13.6 ~1991-~1995: YZ kışı

- Fifth Generation durduruldu; büyük umut ve beklentiler boşa çıktı.
- Yapay zeka endüstrisinde yeni odak: İnsanların yerini tamamen alabilecek programlar üretmeye çalışmak yerine uygun problemlere yapay zeka tekniklerini uygulamak ve insanları destekleyen programlar üretmek. Hocaya göre bugün de genelde bu yaklaşım izleniyor.

### 13.7 Günümüz

Slayttaki maddeler (ekrandan, 02:00:00):

- **Deep Blue, Garry Kasparov'u 1997'de yendi.**
- **2018: Go ve StarCraft ile yenilgilerimiz devam ediyor.** Go satrançtan çok daha karmaşık bir oyundur: tahtası 19×19, taş sayısı daha fazla, dolayısıyla arama uzayı çok daha büyük. Satranç 1997'de yenildikten sonra Go'ya yönelindi. StarCraft bir strateji oyunudur; orada da insanlar üstünlüklerini kaybetti.
- **Sürücüsüz arabalar (DARPA yarışması, 132 mil):** Araçlar çölde bir noktaya bırakılır ve 132 mil uzaktaki bir varış noktasına sürücüsüz, uzaktan kumandasız gitmeleri istenir; GPS gibi her şey serbesttir. Hocanın hatırladığına göre ilk yıl önemli üniversiteler katıldığı halde hiçbir araç çok uzağa gidemedi. Yarışma kapatılmadı; ertesi yıl beş takım 132 mil uzaktaki hedefe ulaştı.
- **Mars'ta otonom bir robot.** Hoca Mars'tan gelen ve gökyüzünde iki ay görünen fotoğraflardan söz etti.
- **Konuşmayı yazıya çeviren programlar (Google Speech to text):** Başarısız oldukları yerler olsa da iş görür haldeler.
- **Hava tahmin sistemleri** artık daha ilerideki tarihlerde ve daha küçük zaman aralıklarında çalışabiliyor. Mevsim geçişlerinde yanılabilirler; bu doğaldır, çünkü mevsim geçişleri tahminin en zor olduğu zamanlardır.

Hoca otonom sürüş hakkında kişisel görüşünü de paylaştı: Araba firmaları bu konuya çok yatırım yaptı. Otobanlardaki bütün araçların otonom olması insanların sürmesinden çok daha iyi olabilir, çünkü makineler birbiriyle çok daha iyi iletişim kurup daha düzenli hareket edebilir. Ama işin içine insanlar ve insanların kullandığı araçlar girince işler karışıyor; bunun etik ve hukuki boyutları da var.

> **Ders sonrası not:** Hoca DARPA yarışmasının ilk yılında en uzağa giden aracın "bir kilometre bile gidemediğini" söyledi ve yanlış hatırlıyor olabileceğini belirtti. 2004'teki ilk DARPA Grand Challenge'da en uzağa giden araç büyük olasılıkla yaklaşık 7,4 mil (yaklaşık 12 km) gidebildi; 2005'te beş araç parkuru tamamladı. Ayrıca Go'da insan dünya şampiyonu düzeyindeki bir oyuncunun yenilmesi büyük olasılıkla 2016'dadır (AlphaGo); slayttaki 2018 tarihi daha çok StarCraft (AlphaStar) dönemine denk düşer.

## 14. Kimine Kolay, Kimine Zor

### 14.1 İnsanlar için zor, makineler için kolay görevler

Slayttaki maddeler (ekrandan, 02:05:00 küçük resmi): Çok fazla veriye göre işlem yapmayı gerektiren görevler.

- **Planlama:** Bir lojistik firmasında hangi aracın hangi ürünü alıp nereye gideceğini planlamak, taşımacılık, uçuş saatlerini ayarlamak. Bunlar korkunç miktarda veri gerektirir ama makineler için oldukça kolaydır.
- **Bilgisayar oyunları (satranç vb.):** Zaten bilgisayarda oynanırlar, makine her duruma erişebilir.

Ortak özellik: **Formal tanımlarla tüm durumlarına makinelerin erişebildiği problemler.** Değişken sayısının fazla olması da insanı zorlar: Satrançta 10-15 hamle ilerisini hesaba katmak insan için kolay değildir, bilgisayar için ise yalnız zaman meselesidir; yeterli zamanı varsa istediği kadar derine bakabilir. Ama hoca bu sürenin derinlikle üstel arttığını hatırlattı.

### 14.2 İnsanlar için kolay, makineler için zor görevler

Slayttaki maddeler (ekrandan, 02:05:00):

- `1 4 9 61 ?` (bir sayı dizisindeki sonraki sayıyı tahmin etmek)
- Bongard problemleri
- Dil anlama
- Resim anlama
- Dünya bilgisi (Ör: Balıkların kaç ayağı var?)
- Değişkenliğin yüksek olduğu, olası tüm durumların kapsanamadığı problemler

**Sayı dizisi:** Dizinin çözümü Örnek Sorular bölümündedir. Hoca burada da asıl kritik olanın böyle bir problemi ilk kez gördüğünde çözebilmek olduğunu vurguladı; benzerini ya da aynısını gördükten sonra çözebilmek çok şey ifade etmez.

**Bongard problemleri:** Solda bir grup şekil, sağda bir grup şekil vardır. Soru: Soldaki şekilleri sağdakilerden ayıran şey nedir? Slayttaki örnek "BP#62. Designer: M. M. Bongard" idi (ekrandan, 02:05:00). Bu problemler insan zekasını ölçmek için kullanılır. Makineler için çok zordur, çünkü her problem diğerlerinden çok farklıdır; bir problemi başka bir probleme benzeterek çözmek kolay değildir, bir problemden diğerine geçmek bir adım atlamayı gerektirir.

**Resim anlama:** Slayttaki fotoğrafta bir koridorda tartıya çıkmış bir adam ve arkasında gülen insanlar vardı (ekrandan, 02:05:00). Bugünkü sistemler bu resimde bir insan, kapı, belki ayna, tavan ve eski model bir tartı olduğunu söyleyebilir; insanların duruş pozisyonlarını (biri dik duruyor, biri sağ ayağını kaldırıp uzatmış) ve kimin gülüp kimin gülmediğini çıkarabilir. Ama resimde **ne olduğunu** anlatamaz: Arkadaki kişi (Obama) ayağıyla tartıya bastırarak tartılan adamın kilosunu olduğundan fazla gösteriyor ve diğerleri buna gülüyor. Nesneleri saymak başka, olayı anlamak başka bir şeydir. Hocaya göre bugünkü sistemler bunu yapamıyor.

> **Hocanın vurgusu:** Değişkenliği yüksek olan ve olası tüm durumların kapsanamadığı problemler bilgisayarlar için oldukça güçtür; insanlar bu konuda bilgisayarlardan epey ileridedir.

## Örnek Sorular

**Soru 1** (ekrandan, 02:05:00): `1 4 9 61 ?` dizisinde soru işaretinin yerine hangi sayı gelir?

> **Çözüm (derste verildi):** 52. Dizi 1, 2, 3, 4, 5... sayılarının karelerinin rakamları ters çevrilerek yazılmasıyla oluşur: $1^2=1$, $2^2=4$, $3^2=9$, $4^2=16 \to 61$, $5^2=25 \to 52$. (Python ile doğrulandı; bir sonraki terim $6^2=36 \to 63$ olur.)

**Soru 2** (ekrandan, 00:25:00): Slayttaki "1N73LL1G3NC3 15 7H3 4B1L17Y 70 4D4P7 70 CH4NG3. 573PH3N H4WK1NG" yazısı ne diyor ve neden böyle yazılmış?

> **Çözüm (derste verildi):** "Intelligence is the ability to adapt to change. Stephen Hawking", yani "Zeka, değişime uyum sağlama yeteneğidir." Bazı harfler benzer rakamlarla değiştirilmiştir (I→1, T→7, E→3, A→4, S→5). Yazıyı okuyabilmek değişikliğe uyum sağlayabilmek demektir; görsel, sözün içeriğini kendisi gösterir.

**Soru 3** (ekrandan, 01:20:00): ELIZA diyaloğunda kırmızı ve siyah satırlar kime ait?

> **Çözüm (derste verildi):** Siyah (büyük harfli) satırlar ELIZA'nın, kırmızı satırlar insanındır. Bir öğrencinin belirttiği gibi ELIZA bir terapisti simüle ettiği için soruları soran taraf siyahlardır. Hocanın sonradan gösterdiği dönüşüm de bunu doğrular: kullanıcının "my boyfriend made me come here" cümlesi ELIZA'da "YOUR BOYFRIEND MADE YOU COME HERE?" olur.

**Soru 4** (derste sözlü, 01:14:31): Bir sistemin Turing testini bir dakikada geçebilmesiyle on dakikada geçebilmesi arasında fark var mı?

> **Çözüm (derste verildi):** Vardır. Kısa sürede sorulabilecek soruların ve olabilecek durumların sayısı azdır, uzun sürede çok daha fazladır. Sistem uzun sürede kendini tekrar etmeye de başlayabilir. Bu yüzden insan taklidini uzun süre sürdürmek çok daha zordur.

**Soru 5** (derste sözlü, 01:23:09): Searle'ün Çin odasındaki kişi, kural kitabı ve veri çekmeceleri bir bilgisayarın neyini temsil eder? İçerideki kişinin Çince bilmesi gerekir mi?

> **Çözüm (derste verildi):** Kişi işlemciyi, kural kitabı programı, veri çekmeceleri RAM ve sabit diski temsil eder; odanın tamamı bir bilgisayardır. İçerideki kişinin Çince bilmesine gerek yoktur: Kişiyi değiştirseniz de sistem aynı çalışır.

**Soru 6** (derste sözlü, 01:25:38; ekrandan, 01:25:00): 1'den 100'e kadar olan sayıların toplamı nedir? Bu toplamı tek tek çok hızlı toplayan bir öğrenci, formülü bulan öğrenciden daha mı zekidir?

> **Çözüm (derste verildi, sayısal sonuç python ile doğrulandı):** Baştan ve sondan eşlenen her çiftin toplamı 101'dir ve 50 çift vardır: $50 \times 101 = 5050$. Genel formül $\frac{N}{2}(N+1)$. Yalnız sonuca bakılırsa hızlı öğrenci daha değerli görünebilir; ama süreç açısından formülü bulan öğrencinin yaklaşımı çok daha zekicedir. Hızlı öğrenci bilgisayarı temsil eder.

**Soru 7** (ekrandan, 02:05:00): Slayttaki Bongard probleminde (BP#62) soldaki şekilleri sağdakilerden ayıran özellik nedir?

> **Çözüm (derste verildi):** Bir öğrencinin önerisi ve hocanın onayıyla: Sağdaki şekillerin uçları (başlangıç ve bitiş noktaları) birbirine yakındır, soldaki şekillerin uçları birbirinden uzaktır.

<!-- BELİRSİZ: Bongard probleminin cevabı derste sözlü verildi; slayttaki şekiller kare çözünürlüğünde bu kuralı kesin doğrulayacak kadar net okunmuyor. -->

**Soru 8** (ekrandan, 00:50:00 ve 00:55:00): Düşünce deneyi: (a) 1000 yıl önce yaşayan birine bir bilgisayarın yapabildiklerini göstersek ona zeki der mi? Nasıl çalıştığını anlatsak? (b) Hoca dersin sonunda yüzünü sıyırıp bir android olduğunu gösterse ona zeki der misiniz? (c) Beyninizin yerinde elektronik bir devre olduğunu öğrenseniz kendinize hâlâ zeki der misiniz?

> **Çözüm (derste tek bir cevap verilmedi):** Bunlar tartışma sorularıdır; öğrenci görüşleri 7. bölümde özetlendi. Hocanın vurguladığı nokta, bir şeyin nasıl çalıştığı açıklandığında ona zeki demekte zorlandığımız ve "zekiliği" çıktıya mı sürece mi göre tanımladığımız sorusudur.

## Dersin Toparlaması

Bu derste yapay zekaya giriş yapıldı. Önce zekanın tanımı tartışıldı: Hayvanlarda da zekice davranışlar olduğu, zekanın öğrenme, problem çözme ve değişime uyum sağlama kapasitesi olarak tanımlanabileceği görüldü. Yapay zekaya ulaşmak için dört yaklaşımdan bugün benimsenenin "rasyonel hareket etmek", yani insanı birebir taklit etmeden çıktılarla ölçülebilen en faydalı davranışı üretmek olduğu anlatıldı. Turing testi, ELIZA, Searle'ün Çin odası, Gauss örneği, Ned Block'un ağacı ve Arnheim'ın yöntem sorunu üzerinden zekanın çıktıyla mı süreçle mi ölçülmesi gerektiği tartışıldı; hoca bu tartışmanın hâlâ açık olduğunu vurguladı. Ardından yapay zekanın 1943'ten bugüne inişli çıkışlı tarihi, büyük beklentilerin neden gerçekleşmediği (sağduyu bilgisi, üstel karmaşıklık, mikro dünyalar) ve günümüzün başarıları gözden geçirildi. Son olarak formal ve bütün durumları erişilebilir problemlerin makineler için, değişkenliği yüksek problemlerin ise insanlar için kolay olduğu gösterildi.

Hoca bir sonraki dersten itibaren yapay zekanın en temel problemi olan arama problemlerine başlanacağını, bir noktadan diğerine en hızlı gitmekten bilgisayara problem çözdürmeye kadar arama algoritmalarının işleneceğini, ardından bilgisayarların insanlara karşı nasıl oyun oynadığına (oyun algoritmalarına) geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
