# Ders 2 Çalışma Özeti

## Genel Konular

- Turing testi
  - Turing 1950'de yazdığı "Makineler düşünebilir mi?" makalesinde bir sisteme ne zaman "zeki" diyebileceğimize dair bir test önerir.
  - Bir duvarla ayrılmış iki oda vardır. Bir tarafta insan sorgulayıcı, diğer tarafta ya bir insan ya da bir yapay zeka sistemi bulunur. İletişim yalnızca yazışarak yapılır (ekrandan, 00:10:00).
  - Sorgulayıcı karşı taraftakinin insan mı makine mi olduğuna doğru karar veremiyorsa ve karşıda gerçekten bir makine varsa, Turing'e göre bu makineye zeki demeliyiz.
  - Turing'in dayanağı: Diğer insanlara da "zeki" sıfatını yalnızca dışarıdan ölçebildiğimiz davranışlarına bakarak veririz; davranışın içeride nasıl üretildiğini bilmeyiz.
  - Testi geçecek sistemler için yarışmalar düzenlenmiştir (Loebner Yarışması). Hocanın bildiği kadarıyla testi gerçekten geçmiş bir makine yoktur.
- ELIZA
  - 1965, Joseph Weizenbaum; bir terapisti simüle eden ilk sohbet robotlarından biri (ekrandan, 00:15:00).
  - Şablon tabanlı çalışır: Kullanıcının cümlesi hangi şablona uyuyorsa o şablonun karşılığı olan kalıpla cümleyi dönüştürüp kullanıcıya soru olarak geri verir. Uygun şablon yoksa genel amaçlı bir cevap verir.
  - Taklit ettiği yöntem Rogers tipi (danışan merkezli) psikoterapidir: danışanın söylediklerini ona ayna gibi geri yansıtmak. Programlanması çok kolay olduğu için bu teknik seçilmiştir.
  - Turing testini geçemez, ama 1965'te az da olsa kandırabildiği insanlar olmuştur.
- Searle'ün Çin Odası
  - Odada Çince bilmeyen bir insan, bir kural kitabı, veri çekmeceleri, bir giriş ekranı ve bir çıkış vardır. Kural: "Şöyle bir şekil geldiyse çıkışa x. çekmecedeki şekli koy." (ekrandan, 00:20:00)
  - Benzetme: insan işlemciyi, kural kitabı programı (kodu), çekmeceler veriyi temsil eder.
  - Oda bir Çinli ile sorunsuz konuşabiliyorsa Turing testini geçer. Turing'e göre oda Çince biliyordur.
  - Searle'e göre dümdüz bir programı izleyen bu kadar basit bir yapıya zeki denemez; yoksa hesap makinesine ya da termostata da zeki dememiz gerekirdi.
- İki öğrenci örneği (süreç mi, sonuç mu?)
  - $1+2+\dots+100$ toplamını bir öğrenci çok hızlı ve hatasız toplayarak bulur; Gauss ise $(N/2)(N+1)$ kısayolunu keşfeder ama daha yavaştır ve çarpmada hata yapabilir (ekrandan, 00:35:00).
  - Yalnız sonuca bakan bir değerlendirme (Turing'in bakışı) hızlı toplayan öğrenciyi, yani makineyi, daha zeki sayar. Yeni bir yöntem keşfetmek gözden kaçar.
- Ned Block'un soru-cevap ağacı
  - İki insan arasında geçebilecek bütün olası diyalogları içeren dev bir diyalog ağacı Turing testini geçer, ama yalnızca bir "if" yapısıdır.
  - Block: Bir davranışa zeki demek, o davranışın nasıl üretildiği hakkında bir önermede bulunmaktır.
- Rudolf Arnheim: Yöntem sorunu (ekrandan, 00:45:00)
  - Zekanın çözebildiği her problemin yalnızca zeka ile çözüleceğini söyleyemeyiz.
  - Zihinsel süreçler çıktıları aracılığıyla tanımlanmadıkça ya da zekanın işleyişine dair görüşümüz mekanist bir niteliğe kavuşmadıkça bilgisayarların kullandığı yönteme zekice denemez.
- Yapay zekayı gerçekleştirmede iki yaklaşım
  - Aşağıdan yukarıcılar: İnsanı zeki yapan beyindir; beynin donanımı, yani sinir ağları model alınmalıdır.
  - Yukarıdan aşağıcılar: Uçaklar kanat çırparak uçmaz; doğanın çözümünü kopyalamak şart değildir, işin kendisine odaklanılmalıdır.
- YZ karşıtları (ekrandan, 00:50:00)
  - John Searle: Tek başına sentaks, ne miktarda olursa olsun, semantiği ortaya çıkarmaz. Anlam yoksa zeka da yoktur.
  - Gödel teoremi: İnsanların doğruluğunu bildiği ama makinelerin ispatlayamadığı doğrular vardır.
  - John Lucas: Böyle doğrular olduğuna göre insan zihni makinelerin kapasitesinin üzerindedir.
  - Turing ile Searle: Turing soruyu deneysel olarak ele almak ister; Searle'e göre program izleyen bir şey asla düşünemez. Açık soru: İnsanlar da bir program izliyor olabilir mi? (ekrandan, 00:55:00)
- Yapay zekanın kısa tarihi (ekrandan, 01:10:00)
  - 1943 McCulloch ve Pitts: ilk yapay nöron; nöronların AND, OR gibi mantık kapılarını gerçekleyebildiği gösterildi.
  - 1949 Hebbian öğrenme kuralı: İki nöron aynı anda aktif olursa aralarındaki bağ güçlenir. Öğrenme, bağlantı ağırlıklarının güncellenmesidir.
  - 1950 Turing'in makalesi; 1951 ilk yapay sinir ağı bilgisayarı (Minsky ve Edmonds).
  - Büyük beklentiler dönemi: Turing testinin 50 yılda geçileceği, 10 yılda dünya satranç şampiyonu bir bilgisayar olacağı (Newell ve Simon, 1957), otomatik çevirinin yakın olduğu öngörüldü. Satranç hedefi 40 yıl sonra, 1997'de gerçekleşti.
  - Neden gerçekleşmediler: dünya/sağduyu bilgisinin büyük etkisi, problemlerin karmaşıklığının üstel olması, kısıtlı dünyaların (microworlds) gerçek dünyaya model olamaması (ekrandan, 01:15:00).
  - 1966-1973 zor dönem: fonların durması; 1969'da çok katmanlı (derin) ağların bu problemleri çözebildiği gösterildi ama ağırlıkları eğitecek algoritma (geri yayılım) 80'lere kadar yoktu.
  - 1979-1990 güzel zamanlar: kural tabanlı uzman sistemler (örnek: MYCIN), Japonya'nın Prolog temelli Fifth Generation projesi, "now with AI!" klişesi (ekrandan, 01:20:00). Ardından daha mütevazı hedeflere dönüş.
  - Günümüz: Deep Blue 1997'de Kasparov'u yendi; 2018'de Go ve StarCraft; sürücüsüz arabalar; Mars'ta otonom robot; konuşmayı yazıya çeviren programlar; daha ayrıntılı hava tahmini; ChatGPT (ekrandan, 01:25:00).
- Kimine kolay, kimine zor (ekrandan, 01:40:00)
  - Satranç, planlama, büyük sayıları çarpmak insan için zor, makine için kolaydır; bunlar formal tanımlı, bütün durumları erişilebilir dünyalardır.
  - İnsan için kolay, makine için zor: "1 4 9 61 ?" dizisi, Bongard problemleri, dil anlama, resim anlama, dünya bilgisi; değişkenliğin yüksek olduğu, olası tüm durumların kapsanamadığı problemler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zeki sıfatı neye verilir: çıktıya mı, sürece mi?
  - Turing yalnız dışarıdan ölçülebilen davranışa bakar. Searle, Block ve Arnheim davranışın nasıl üretildiğinin de önemli olduğunu savunur.
  - Bu tartışma önemlidir; çünkü yakın gelecekte kendisinin zeki olduğunu iddia eden makinelerle karşılaşılacak ve onlara hangi hakların verileceği gündeme gelecektir.
- Çin odası itirazı "kural kitabında eksik olur, yeni çıktı üretemez" itirazı değildir.
  - Varsayım gereği oda dışarıdan bakıldığında insandan ayırt edilemez. Searle'ün itirazı "ne yapabildiği" değil, "nasıl yaptığı"dır.
- Süreç ile sonuç ikisi de önemlidir.
  - Süreci objektif olarak ölçmek zordur; bu yüzden pratikte sonuca bakılır. Ama yalnız sonuca odaklanmak bakış açısını daraltır.
- "Organik olmayan süreçle üretilen yanıt zeki değildir" ölçütü işe yaramaz.
  - Yalnız yazıştığımız birinin organik bir süreçle mi cevap verdiğini dışarıdan bilemeyiz.
- Bu konulardaki görüşlerin hiçbiri kesin doğru değildir; hepsi spekülatif tartışmalardır.
- Açıklanabilirlik
  - Kural tabanlı sistemlerin yapay sinir ağlarına göre üstünlüğü kararlarını açıklayabilmeleridir. Ama tek ölçüt değildir: %90 başarılı ama açıklayamayan sistemle %70 başarılı ama açıklayabilen sistem arasında seçim yapmak gerekebilir.
- Makineler benzer örnekleri çok görülen problemlerde iyidir.
  - İyi bir zeka problemi öncekilere en az benzeyendir. İnternette cevabı olmayan yepyeni bir problemde makine zorlanır.
- ChatGPT mantıksal çıkarım yapmaz.
  - İnternette en sık görülen cevabı verir; herkesin yanlış bildiği bir şeyin doğrusunu söyleme ihtimali yoktur.

## Kısa Tekrar Notları

- Turing testi: yalnız yazışma; sorgulayıcı insan ile makineyi ayırt edemezse makine zekidir.
- ELIZA (1965, Weizenbaum): şablon tabanlı, Rogers tipi terapist taklidi, Turing testini geçemez.
- Çin odası: insan = işlemci, kural kitabı = program, çekmeceler = veri. Sentaks semantik üretmez.
- Gauss örneği: $\sum_{i=1}^{100} i = \frac{100}{2}\cdot 101 = 5050$. Yalnız sonuca bakmak yöntemi göremez.
- Ned Block: zeki demek, davranışın nasıl üretildiği hakkında bir önermedir.
- Arnheim: zekanın çözdüğü her problem yalnız zeka ile çözülmez.
- Aşağıdan yukarı (beyni/sinir ağlarını taklit et) ve yukarıdan aşağı (işin kendisine odaklan) yaklaşımları.
- Gödel ve Lucas: insanın bildiği ama makinenin ispatlayamadığı doğrular.
- 1943 McCulloch-Pitts nöronu, 1949 Hebb kuralı, 1950 Turing makalesi, 1951 ilk YSA bilgisayarı, 1997 Deep Blue, 2018 Go ve StarCraft.
- Beklentilerin tutmama nedenleri: sağduyu bilgisi, üstel karmaşıklık, microworld'lerin gerçek dünyaya genellenememesi.
- Uzman sistemler: kural tabanlı, kısıtlı alanda uzman, açıklanabilir (MYCIN).
- İnsana kolay makineye zor: Bongard problemleri, dizi tamamlama, dil ve resim anlama, dünya bilgisi.

## Detaylı Açıklamalar

- Turing testi ve dayanağı
  - Turing'in fikrine göre bir sistemin zeki olup olmadığına karar verirken yalnız dışarıdan ölçülebilen davranışlara bakılır. Bunun gerekçesi, diğer insanların zihnine de erişemememiz ve onlara verdiğimiz "zeki" sıfatını da davranışlarına bakarak vermemizdir. Testi bir sistem geçerse, yani sorgulayıcıyı yanlış karara ya da kararsızlığa sürüklerse ve karşıda gerçekten bir makine varsa, ona zeki ya da düşünce sahibi demek gerekir.
  - Hoca derste ELIZA diyaloğunu gösterip hangi tarafın makine olduğunu sordu. Sınıf siyah yazılı (büyük harfli) satırların makine olduğunu doğru tahmin etti. İpuçları: makinenin terapist rolü, karşıdakinin son cümlesini soruya çevirmesi, bağlamı tutamayıp yalnız bir önceki cümleye bağlı kalması ("My father." - "YOUR FATHER"). Hocaya göre sınıf karar verebildiği için ELIZA bu küçük testi de geçememiş oldu.
  - 1965'te bazı insanların ELIZA'nın makine olduğuna ikna edilmesi zor oldu. Sınıfta öne sürülen nedenler: konuşan kişinin desteğe çok ihtiyaç duyması ve 1965 insanının bilgisayarla ilk kez karşılaşıyor olması.
- Çin odası ve Turing'in olası cevabı
  - Oda Çince biliyor mu sorusuna Turing'in cevabı "evet" olur: Dışarıdan bakıldığında Çinli bir insandan farkı yoksa ona da Çince biliyor demeliyiz. Searle'ün itirazı ise içeride olan işin dümdüz bir program izleme olduğudur. Bu kadar basit bir mekanizmaya zeki demek, hesap makinesine ya da termostata da zeki dememizi gerektirir.
- İki öğrenci ve süreç-sonuç tartışması
  - Gauss'un hikayesinde öğretmen öğrencileri oyalamak için 1'den 100'e kadar sayıları toplatır. Gauss baştaki ve sondaki sayıların toplamının hep 101 olduğunu, böyle 50 çift bulunduğunu fark eder ve $50 \times 101$ ile sonuca ulaşır. Hikayenin değiştirilmiş versiyonunda sınıfta çok hızlı ve hatasız toplayan ikinci bir öğrenci vardır. Bu öğrenci Gauss'tan çok önce doğru cevabı verir, Gauss ise yavaştır ve çarpmada hata bile yapabilir (slaytta bilerek $50 \times 101 = 5005$ yazıldı; ekrandan, 00:35:00). Yalnız sonuca bakan bir değerlendirme hızlı öğrenciyi, yani makineyi temsil eden öğrenciyi seçer, yeni yöntemi bulan Gauss'u göremez.
  - Hoca bunu insan değerlendirmelerine de bağladı: Süreci objektif ölçmek çok zor olduğu için sonuca bakılır, ama yalnız sonuca bakmak sıralamayı istenmeyen biçimde değiştirebilir.
- Tarihçe ayrıntıları
  - Hebb kuralı Pavlov'un köpekleri üzerinden anlatıldı: Zil sesiyle uyarılan nöronlar ile salya akıtmayı tetikleyen nöronlar defalarca art arda aktif olunca aralarındaki bağ güçlenir; artık zil tek başına salya akıtır. Yapay sinir ağlarının diliyle öğrenme ağırlık güncellemesidir.
  - Satranç hedefinin 10 yıl yerine 40 yılda gerçekleşmesinin nedeni algoritmik bir sıçrama değil, hesaplama gücündeki büyük artıştır.
  - Çok katmanlı ağlar 1969'da bu problemleri çözebiliyordu ama ağırlıkları insanlar elle ayarlıyordu. Geri yayılım 80'lerin başında ortaya çıktı. Yapay sinir ağlarına ilgi 2012'deki başarılara kadar diğer makine öğrenmesi yöntemlerine göre daha azdı.
  - Uzman sistemler belirli bir dar alanda uzmandır (genel doktor değil, belirli bir hastalık). Hukuk örneğinde bir kararın gerekçesinin istenmesi açıklanabilirliğin neden önemli olduğunu gösterir.
- Günümüz uygulamaları
  - Mars'taki robotun otonom olması gerekir; uzaktan kumandada gecikme vardır. Ekranda robotun kratere yaklaştığını gördüğünüz anda robot aslında çoktan düşmüş olabilir.
  - Sürücüsüz araçlar koordineli hareket edebilseler trafik çok daha verimli olabilir; insan faktörü tahmin edilemezlik getirir.
  - ChatGPT'nin halka açılması çok büyük bir veri toplanmasını sağladı. Hocaya göre rutin, standart süreçleri izleyen işlerin önemli bir kısmı makinelere devredilebilir görünüyor.
- Dünya bilgisi
  - Slayttaki fotoğrafta tartılan bir kişinin arkasından biri ayağıyla tartıya basıp ağırlığını artırıyor (ekrandan, 01:50:00). Esprinin anlaşılması için tartının nasıl çalıştığını bilmek gerekir. Gelişmiş görüntü işleme araçları kişileri, konumları ve nesneleri tanıyabilir, ama resmin bütününün anlattığı şey parçaların toplamından fazladır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
