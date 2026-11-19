# Ders 6 Çalışma Özeti

## Genel Konular

- Öğrenci sunumları ve sunum sonrası tartışma
  - Bu derste altı öğrenci kısa sunumlarını yaptı. Her sunumdan sonra soru-cevap ve tartışma açıldı; soru gelmediğinde hoca soru sordu ya da konuyla ilgili kendi bilgisini paylaştı.
  - Sunumlar hocanın bilgisayarından paylaşıldı ve sunan öğrenci "geçebiliriz" diyerek yansıları ilerletti.
- Sunum 1: Yeşil Sahra (ekrandan, 00:05:00)
  - Bugün kurak bir çöl olan Sahra, yaklaşık 10 bin yıl önce yeşil ve ılıman bir bölgeydi.
  - 1800'lerde Afrika'yı gezen Avrupalı araştırmacı Heinrich Barth, Sahra'daki mağara resimlerinde bugünkü Orta ve Güney Afrika savanlarına benzeyen bir yaşam betimlendiğini gördü; bölgenin eskiden daha ılıman olduğunu düşündü ama bunu kanıtlayacak verisi yoktu.
  - Açıklama: Dünya'nın ekseni ve yörüngesi periyodik olarak değişir (Milankoviç döngüleri). Bugün Dünya Güneş'e en yakın konumdayken güney yarımkürede yaz yaşanır; 10 bin yıl önce bu durum tersti ve kuzey yarımkürede yaz yaşanıyordu. Bu, Sahra'yı daha da ısıttı ve bugün Hindistan'da görülen muson yağmurlarına benzer yağışlar oluştu.
  - Yağışları Alize rüzgârları taşıdı: yüksek basınç farkı nedeniyle Atlas Okyanusu üzerinde oluşan yağmuru Sahra'ya taşıyorlardı. Bugün yeterli basınç farkı oluşmadığı için bu rüzgârlar Afrika'nın batı kıyısından güneye doğru ilerler.
  - Pozitif geri bildirim: yağmurla bitki örtüsü oluşur, yeraltı suyu artar, bitkiler terlemeyle atmosfere su buharı verir, buhar yeniden yağmur olarak düşer. Yeşil alan yüzyıllar içinde kenarlardan iç bölgelere yayıldı.
  - Döngünün yaklaşık 20 bin yılda bir tekrarlandığı, son yeşil dönemin yaklaşık 7 bin yıl önce (MÖ 5000 civarı) bittiği söylendi. Soru-cevapta sunan öğrenci, çölleşmenin Sahra'daki insanları Nil'e göç ettirerek Mısır uygarlığının kuruluşuna katkıda bulunduğunu ekledi.
- Sunum 2: Albert Camus'ya göre absürdizm ve varoluşçuluk (ekrandan, 00:15:00 ve 00:20:00)
  - Camus, 1913'te doğmuş, Cezayir asıllı Fransız yazardır. İkinci Dünya Savaşı'nda Fransız direniş hareketinde bir dergide yazarak görev aldı, bu sırada Jean-Paul Sartre ile tanıştı. Siyasi olarak solda durdu ama komünizme karşı çıktı. 1957'de Nobel Edebiyat Ödülü'nü aldı.
  - Absürdizm, kelime anlamıyla saçma ya da uyumsuzluk felsefesidir. Camus bu akımın kurucusu değildir ama felsefeye en büyük katkısı absürtlük konusu olmuştur. Fikirlerini "Sisifos Söyleni"nde açıklamış, "Yabancı" ve "Veba" romanlarında işlemiştir.
  - Düalizm: birbirine karşı çıkan iki kavramın bir arada var olması (yaşam ve ölüm, gece ve gündüz). İnsan yaşayarak kendine değer verir ama öleceğini bilir; bu çelişkiyle yaşamak absürdün kendisidir.
  - Bilinçli insan: yaşamın anlamsızlığının ve boşluğunun farkında olan insandır. Camus kendini bilinçli insan sayar, ama hiçbir zaman intiharı savunmamıştır.
  - Varoluşçuluk: köklerinden kopmuş, geçmişe ve geleceğe güvenini yitirmiş, topluma ve kendine yabancılaşmış, mutsuz ama ileri derecede düşünebilen insanın kendini oluşturma çabası. Bu birey toplumdan ve gelenekten soyutlanarak başkaldırır. "Yabancı" romanındaki Meursault bu insanın örneğidir.
- Sunum 3: Makine öğrenmesine genel bakış (ekrandan, 00:30:00)
  - Makine öğrenmesi, algoritmayı çok sayıda örnekle (veriyle) besleyerek bir şeyi tanımasını öğretmektir. Örnekler: farklı şişe görüntüleriyle "şişe" kavramının öğretilmesi, telefonun yüz tanımayla kilit açması.
  - Sunan öğrenci bunu çocukların tanıdık yüzleri tekrar tekrar görerek öğrenmesine benzetti.
  - Riskler: IBM'in Deep Blue programının satranç ustası Kasparov'u yenmesi, yapay zekânın insan zekâsına yaklaştığı korkusunu başlattı. Bazı uzmanlar 20-30 yıl içinde insan benzeri zekâ beklerken bazıları bunun hiç olmayacağını söyler.
- Sunum 4: RTX ve oyunlarda ışın izleme (ray tracing) (ekrandan, 00:40:00, 00:45:00 ve 01:20:00)
  - Rasterleştirme (rasterization): oyunda gerçek bir ışık takibi yoktur; yansımalar ve gölgeler çoğunlukla önceden hazırlanmış iki boyutlu görüntülerdir ve bakılan yöne göre anlık yerleştirilir. Hareketli nesnelerin (oyuncu karakteri, ateş) yansıması bu yüzden çoğu zaman görülmez.
  - Işın izleme: üç boyutlu sahnede ışık isabet eden her nesnenin ışınları takip edilir; takip ışığın çıktığı yerden nesneye, oradan diğer nesnelere ve en son ekrana kadar sürer. Birden fazla ışık varsa hepsinin dağılımı ve yansıması hesaba katılır.
  - Ekran kartındaki ışın izleme çekirdekleri BVH adlı bir algoritmaya göre çalışır; ışık kaynağının türü, yüzeyin türü, çarpma açısı ve nesneler arası uzaklıklar hesaplanır.
  - Örnekler: RTX kapalı ve açık karşılaştırmaları (Spider-Man, Watch Dogs Legion, Quake 2).
  - Soru-cevapta Unreal Engine 5'in Lumen aydınlatma teknolojisi soruldu.
- Sunum 5: Oyun bağımlılığı (ekrandan, 00:50:00, 00:55:00 ve 01:05:00)
  - Belirtiler: oynamadığında kötü hissetme ya da yoksunluk, giderek artan sürelerde oynama isteği, azaltamama, önceden sevilen işlere ilgisizlik, okul/iş/ev sorunları, başkalarına yalan söyleme, kötü duyguyu oyunla bastırma, ilişki ve kariyer fırsatlarını kaçırma.
  - Fiziksel etkiler: baş ağrısı, yorgunluk, göz sorunları, karpal tünel sendromu.
  - Sıklık (ekrandan, 00:55:00): yedi Avrupa ülkesinde 14-17 yaş arası 12.938 ergenle yapılan bir ankette %1,6'sının bütün kriterleri karşıladığı, %5,1'inin risk altında olduğu; İstanbul'da 95 gençle yapılan bir çalışmada yaygınlığın %9,4 olabileceği belirtildi.
  - Önleme ve bırakma: önceden anlaşılmış zaman limiti, cihazların yatak odası dışında tutulması, sanatsal, kültürel ve fiziksel etkinliklere yönlendirme; işe yaramazsa uzman desteği. Tedavide amaç altta yatan psikolojik etkenlerin bulunup tedavi edilmesidir.
- Sunum 6: Mısır piramitleri (ekrandan, 01:10:00)
  - Piramitler firavunlar için mezar olarak yapıldı. En eski piramit olarak Zoser (Djoser) piramidi anıldı. Gize'deki Keops piramidi en büyüğüdür, sunumda 138 metre yüksekliğinde olduğu söylendi ve antik dünyanın yedi harikasından ayakta kalan tek yapıdır.
  - Sunumda "ilginç özellikler" başlığı altında bazı iddialar aktarıldı (piramit yüksekliği ile Dünya-Güneş uzaklığı ilişkisi, içeride radar ve sonar çalışmaması gibi). Hoca bu iddiaları "eski uzaylılar" teorileri bağlamında tartışmaya açtı.
  - Mısır'ın 2017 turizm geliri sunumda 25 milyar dolar olarak verildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Turing testi ve Alan Turing
  - Turing testi, bir yapay zekânın yeterince olgun olup olmadığını ölçen bir testtir. Üç katılımcı birbirini görmeden terminal üzerinden haberleşir: bir yapay zekâ, bir insan ve sınamayı yapan kişi. Sınayan kişi hangisinin yapay zekâ olduğunu ayırt edemiyorsa yapay zekâ testi geçmiş sayılır.
  - Alan Turing, hesaplama kavramının teorik temellerini atan ve modern bilgisayarların babası sayılabilecek kişidir; İkinci Dünya Savaşı'nda Alman şifrelerini kıran ekipte çalışmıştır.
  - Hoca: "Bilgisayar mühendisliği okuyorsanız Alan Turing'in adını bilmeniz gerekiyor."
- Mühendislikte ödünleşim (trade-off)
  - Geniş bir donanım yelpazesini hedefleyen yazılım (örneğin oyun), düşük donanımda bazı özellikleri kapatarak ya da alternatif yöntemlerle çalışmalıdır. Örneğin yansımayı kapatarak saniyedeki kare sayısında (FPS) kazanç sağlanabilir.
  - Mühendislik, neyi nereden kazanıp karşılığında neyi kaybetmeyi göze aldığınızı tartarak dengeli tasarım yapmaktır.
- Bağımlılığın ölçütü
  - Bir hobinin bağımlılığa dönüşüp dönüşmediğini gösteren sihirli bir saat sınırı yoktur. En büyük ölçüt, diğer sorumlulukları yerine getirmeyi engelleyip engellemediğidir.
  - Sanal ortamdaki etkileşim yüz yüze etkileşimin yerini tutmaz; insanlar araya bir ekran girdiğinde farklı davranır. Karantina dönemlerinde bağımlılık riski artar.
- Sunum hazırlamada teknik ve tasarım ipuçları
  - Çok yüksek çözünürlüklü görseller dosyayı büyütür; çevrim içi paylaşımda ağ gecikmesi nedeniyle yansılar geç görünür.
  - Öncesi/sonrası karşılaştırmasını iki ayrı yansıda değil, ekranı ikiye bölerek tek yansıda göstermek daha anlaşılır ve akılda kalıcıdır.
  - İnsan aynı anda sınırlı sayıda bilgi birimini verimli biçimde işleyebilir; hoca bunu "5 artı eksi 2" (en az 3, en fazla 7) olarak verdi. Sunumda da kodlamada da problemi bu sayıda parçaya bölmek gerekir.
- Kodek kavramı
  - Kodek, kodlayıcı-kod çözücünün (coder-decoder) kısaltmasıdır. Kodlama, görüntüyü ikili veriye çevirerek saklanabilir ya da ağda iletilebilir hale getirmektir; kod çözme, gelen ikili veriyi açıp göstermektir.
  - Bant genişliği daraldığında veriyi daha düşük kaliteyle aktaran yöntemlere uyarlamalı (adaptif) denir.

## Kısa Tekrar Notları

- Sahra'nın yeşil dönemleri Milankoviç döngülerine bağlıdır; Alize rüzgârları ve bitki örtüsünün pozitif geri bildirimi yağışı yüzyıllarca sürdürür.
- Camus: absürt, yaşama değer vermek ile öleceğini bilmek arasındaki çelişkidir; bilinçli insan bu anlamsızlığın farkındadır ama intihar çözüm değildir.
- Makine öğrenmesi: algoritmayı örneklerle besleyerek öğretmek; Deep Blue-Kasparov maçı yapay zekâ korkularının sembolü oldu.
- Turing testi: sınayan kişi yapay zekâyı insandan ayırt edemiyorsa test geçilmiş sayılır.
- Rasterleştirme önceden hazırlanmış yansıma ve gölgeler kullanır; ışın izleme ışığı kaynaktan ekrana kadar takip eder, ekran kartında BVH tabanlı çekirdeklerle çalışır.
- Mühendislik = ödünleşim: kalite ile performans (FPS) arasında denge.
- Bağımlılığın ölçütü süre değil, sorumlulukların aksamasıdır.
- Kodek = kodlayıcı + kod çözücü; adaptif aktarım bant genişliğine göre kaliteyi düşürür.
- Sunum ipuçları: dosya boyutunu makul tut, karşılaştırmaları yan yana göster, bir anda sınırlı sayıda (yaklaşık 3-7) bilgi birimi ver.

## Detaylı Açıklamalar

- Yeşil Sahra sunumunda iklim değişiminin tek bir nedene değil, birbirini besleyen bir zincire bağlı olduğu anlatıldı. Eksen ve yörünge değişimi kuzey yarımküredeki yazları ısıtınca kara ile okyanus arasındaki basınç farkı arttı; Alize rüzgârları Atlas Okyanusu'nun nemini Sahra'ya taşıdı. Bitki örtüsü oluşunca terleme yoluyla atmosfere su buharı geri döndü ve yağış kendini sürdürdü. Bu süreç bir anda değil, yüzyıllar içinde kademeli olarak gerçekleşti. Hoca soru-cevapta konuyu genişleterek Dünya'nın manyetik kutuplarının da sabit olmadığını, çekirdekteki eriyik metal tabakanın hareketleri nedeniyle sürekli oynadığını ve bunun navigasyonda sorunlara yol açtığını belirtti.
- Camus sunumundan sonra hoca, düalizm konusunu genişletti. İnsan zihni birçok kavramı karşıtıyla öğrenir: iyiyi kötünün karşılığı olarak tanımlarız. Ama yalnız karşıtlıklarla yetinmek yetmez; iki uç arasındaki gri bölgeleri ve geçiş noktalarını da bilmek gerekir. Hoca bu bağlamda yaşamın değerinin ölümle bilindiği temasını işleyen bir bilim kurgu dizisini (Battlestar Galactica, yeniden yorumlanan sürüm) örnek verdi; dizide bilinci yeni bir bedene aktarılan yapay zekâlı varlıklar vardır.
- Makine öğrenmesi sunumundan sonra hoca Turing testini ayrıntılı anlattı ve yapay zekânın edebiyat ve sinemada sıkça işlendiğini, Terminatör ve Ex Machina gibi örneklerle hatırlattı.
- Işın izleme sunumunda rasterleştirme ile ışın izleme arasındaki temel fark, gölge ve yansımanın önceden hazırlanmış mı yoksa anlık mı hesaplandığıdır. Rasterleştirmede sahnedeki cisimler geometrik nesneler olarak hesaplanır ve etraflarına iki boyutlu gölge ve yansıma görüntüleri konur; bu yüzden örneğin bir çaydanlıkta yanındaki bardağın yansıması görünmez. Işın izlemede optik kurallarına göre ışığın çarpma açısı, cismin şekli ve ışığın nereye kadar gidebileceği hesaplanır; bir cam kapatıldığında ondan gelen yansıma da anında kaybolur. Lumen sorusu üzerine hoca, yazılımın hedeflediği donanım yelpazesi genişledikçe özelliklerin kademeli olarak kapatılabilmesi gerektiğini ve bunun bir mühendislik ödünleşimi olduğunu vurguladı.
- Ders sonunda hoca, sunum dosyalarının boyutu üzerine teknik bir değerlendirme yaptı. Ekran paylaşımında görüntü, bağlantının bir ucundan diğerine ağ üzerinden gider ve bu sırada bir iletişim gecikmesi oluşur. İletilecek veri ne kadar ayrıntılıysa gecikme o kadar hissedilir. Video uygulamaları kodek kullanır ve büyük olasılıkla bant genişliği daraldığında kaliteyi düşüren adaptif yöntemlerle çalışır. Hoca bunu bir eleştiri olarak değil, teknik bir konuşma vesilesi olarak andı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
