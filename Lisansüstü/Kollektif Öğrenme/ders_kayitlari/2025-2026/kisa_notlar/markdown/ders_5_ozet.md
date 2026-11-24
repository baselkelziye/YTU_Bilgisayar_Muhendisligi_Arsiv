# Ders 5 Çalışma Özeti

## Genel Konular

- Ödev sunumları: GRPO ile ödül fonksiyonu tasarımı ve model birleştirme
  - Bu derste konu anlatımı yapılmadı. Öğrenciler, bir dil modelini GRPO (Group Relative Policy Optimization) ile pekiştirmeli öğrenmeyle eğittikleri ödevi sundu. Hoca her sunumdan sonra sorular sordu ve teknik yorumlar yaptı.
  - Ödevin çerçevesi: standart GRPO'da doğruluk ve format ödülü vardır. Bunun yanına dört yeni ödül bileşeni tasarlanır, böylece farklı ödül fonksiyonlarıyla beş model eğitilir. Sonra en iyi modeller birleştirilerek (merge) bir model daha elde edilir.
  - Ekranda görülen ortak kurulum: temel model `ytu-ce-cosmos/turkish-gpt2-large-750m-instruct-v0.1` (750 milyon parametre, GPT-2 mimarisi), veri seti Türkçe çoktan seçmeli sınav soruları içeren `alibayram/turkish_mmlu`, 1000 eğitim ve 500 test sorusu, LoRA ile parametre verimli ince ayar (ekrandan, 00:10:00 ve 00:45:00).
- Veri alt kümesinin seçimi
  - Amaç, bilgi ve ezbere dayalı soruları değil, çıkarım (akıl yürütme) gerektiren soruları seçmektir. Gruplar konu/bölüm sütununa, anahtar kelimelere (çünkü, dolayısıyla, oranı, ortalaması gibi), soru uzunluğuna ve puanlama kurallarına göre filtreleme yaptı.
  - Bazı gruplar şık dağılımını eğitim ve test kümesinde dengeli tuttu (tabakalı bölme), böylece model bir şıkka yönelerek kolay puan alamaz.
  - Veri setinde konu etiketiyle sorunun içeriğinin uyuşmadığı örnekler olduğu görüldü; hoca bu sorunun var olduğunu doğruladı.
- Ödül fonksiyonu türleri (sunumlarda görülen örnekler)
  - Format ve doğruluk (temel ödül), cevap temizliği (etiket içinde yalnız tek harf), düşünce uzunluğu, kısalık ve özlülük, mantıksal bağlaç kullanımı, tekrar/spam cezası, birden fazla şık yazma cezası, Türkçe karakter kullanımı, entropi, cevap çeşitliliği, kalibrasyon, anlamsal (embedding) benzerlik, prompt kopyalama cezası, "emin değilim" gibi belirsizlik ifadeleri.
- Ödül hilesi (reward hacking) ve modelin davranışı
  - Model ödülü yükseltmek için görevi çözmek yerine ödül fonksiyonunun açıklarını kullanabilir: bağlaçları anlamsız biçimde sıralamak, bütün şıkları tekrar etmek, hep aynı şıkkı (örneğin C) seçmek, soruyu kopyalamak.
  - Ceza çok ağır olunca model hiç cevap vermeyen "sessiz" bir modele dönüşebilir.
- GRPO'nun önemli ayarları
  - Soru başına üretilen cevap sayısı (num_generations), KL ıraksaması katsayısı (beta), LoRA rankı, öğrenme oranı, adım sayısı.
- Model birleştirme
  - MergeKit ile ağırlık birleştirme ya da LoRA adaptör ağırlıklarının (ağırlıklı) ortalaması. Örnek: $W_{merged} = 0.5\,W_{simple} + 0.5\,W_{long}$ (ekrandan, 01:25:00).
  - Birleştirme bazı gruplarda tekil modellerden iyi, bazı gruplarda kötü sonuç verdi.
- Değerlendirme
  - Doğruluk (accuracy), format uyum oranı, ikisinin çarpımı olarak etkin skor; bazı gruplarda beklenen kalibrasyon hatası (ECE), McNemar testi, bootstrap ve Wilson güven aralıkları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce akıl yürütme, sonra cevap
  - Hoca, prompt formatında cevabın düşünceden önce istenmesini yanlış buldu. Model bir sonraki token'ı tahmin ederek (next token prediction) eğitildiği için sorudan hemen sonra doğru şıkkı üretmesi zordur. "Şu şöyledir, bu böyledir, dolayısıyla cevap şudur" biçiminde ilerlemek böyle bir model için çok daha kolaydır. Önce cevap verilirse gerekçe sonradan uydurulur.
- Bilgi sorusu GRPO ile öğretilemez
  - Modelin bilgisi zaten sınırlıdır. GRPO modelin bilmediği bir bilgiyi keşfettiremez; bu yüzden veri setinin çıkarım gerektiren sorulara filtrelenmesi istendi.
- Soru başına cevap sayısı yeterince büyük olmalı
  - GRPO, aynı soruya üretilen bir grup cevabı birbiriyle karşılaştırarak öğrenir. Cevap sayısı 2 olunca küçük bir model için doğru cevabın grupta bulunma olasılığı düşüktür. Hoca en az 8 civarında bir değeri daha makul buldu.
- KL ıraksaması ve modelin bozulması
  - GRPO'da modelin referans modelden çok uzaklaşmasını engelleyen bir KL ıraksaması terimi vardır. Model anlamsız metin üretmeye başlıyorsa bu terimin katsayısı artırılır.
- Ödül hilesi
  - Ödülü memnun edip istenen davranışı üretmemek "reward hacking" diye adlandırılır. Bağlaç sayan bir ödülün mantıksız bağlaç dizileriyle doldurulması bunun örneğidir.
- Model çıktısına bakmak
  - Hoca hemen her sunumda modelin bir soruya verdiği gerçek çıktıyı ve doğruluğun nasıl hesaplandığını sordu. Yalnız tabloya bakıp çıktıyı incelememek iyi bir yaklaşım değildir. Doğru şık cevabın içinde geçiyor mu diye bakmak, bütün şıkları sayan modele yüksek doğruluk verir.
- SFT sonrası çökme
  - GRPO'dan önce yapılan denetimli ince ayar (SFT) modeli tek şıkka çökertmişse model yerel bir minimuma düşmüştür ve GRPO onu oradan çıkaramaz. SFT çok daha az yapılmalı ya da hiç yapılmamalıdır.
- Ödül bileşenleri tek başına kullanılmaz
  - Yeni ödül bileşenleri doğruluk ve format ödülünün üstüne eklenir. Format ile neredeyse aynı şeyi ölçen bileşenler (örneğin "cevap etiketinde yalnız şık olsun") yeni bir davranış eklemez.
- Birleştirme modellerin birleştirilmesidir
  - Ödül fonksiyonlarının bileşenlerini ağırlıklandırıp tek ödül yapmak ödevdeki birleştirme değildir; eğitilmiş modellerin birleştirilmesi istenmişti.
- LoRA ile eğitimden sonra
  - LoRA eğitimiyle elde edilen düşük ranklı matrislerin modele geri eklenmesi gerekir; nihai model ancak böyle elde edilip başka yerde kullanılabilir.

## Kısa Tekrar Notları

- GRPO: aynı soruya bir grup cevap üretilir, her cevap ödül fonksiyonlarıyla puanlanır, grup içinde göreli olarak iyi cevaplar güçlendirilir.
- Format istemenin bir nedeni de doğruluğu basit bir regex ile ölçebilmektir.
- Beş şıklı soruda rastgele tahmin %20 doğruluk verir; %10 doğruluk rastgeleden kötüdür.
- Uzunluk ödülleri model soruyu ya da şıkları tekrar ederek kandırılabilir; tekrar/spam cezası bunu sınırlamak için eklenir.
- Çok ağır ceza modeli susturabilir; hiç ceza olmaması da bütün şıkları sayan modeli ödüllendirebilir.
- Soru başına cevap sayısı (num_generations) küçük tutulmamalı; birkaç cevap yerine 8 civarı daha makuldür.
- KL katsayısı modelin referans modelden uzaklaşmasını sınırlar; metin anlamsızlaşıyorsa artırılır.
- LoRA adaptörleri ağırlık ortalamasıyla birleştirilebilir, ama nihai model için adaptörün temel modele eklenmesi gerekir.
- Birleştirilmiş model iki modelin ortalamasından da kötü çıkabilir (bir grupta beklenen %5.6 yerine %4).
- Değerlendirmede gerçek çıktılara bakılmalı; ölçüm hatası doğruluğu olduğundan yüksek gösterebilir.

## Detaylı Açıklamalar

- **Ödev ve ortak kurulum.** Hoca derse ödevi hatırlatarak başladı: standart GRPO'daki doğruluk ve format ödülünün yanına dört yeni bileşen tasarlanacak, farklı ödül fonksiyonlarıyla beş model eğitilecek, en iyileri birleştirilerek bir model daha denenecekti. Sunumlarda görülen ortak kurulum, Türkçe talimat takibi için hazırlanmış 750 milyon parametreli GPT-2 tabanlı bir modelin, Türkçe çoktan seçmeli sınav sorularıyla LoRA kullanılarak eğitilmesiydi. Bir raporda LoRA rankının $r=16$ seçildiği, ana ağırlıkların dondurulduğu ve böylece hem belleğin aşılmadığı hem de modelin Türkçe bilgisinin korunduğu yazıyordu (ekrandan, 00:10:00).

- **Prompt tasarımı.** Talimat tabanlı uzun promptlar küçük modelde çoğu zaman işe yaramadı: model etiketleri tekrarladı, formatı kopyaladı. Bir öğrenci örnek bir soru ve çözümünü promptun başına koyup asıl soruyu `<düşünce>` etiketiyle açık bırakarak modelin tamamlamasını bekledi (ekrandan, 01:10:00). Hoca burada tek örnek yerine birkaç örnek verilmesini önerdi: soru, düşünce, cevap ve ardından yeni bir soru biçiminde yapı birkaç kez tekrar edilirse model kalıbı daha kolay yakalar.

- **Önce gerekçe, sonra cevap.** Birkaç grup modelden önce cevabı, sonra açıklamayı istedi. Hoca bunun doğal olmadığını anlattı: bir sonraki token'ı tahmin eden bir model için soru metninden hemen sonra doğru şıkkı üretme olasılığı düşüktür. Önce adım adım akıl yürütüp sonra "dolayısıyla cevap şudur" demek böyle bir model için çok daha kolay bir davranıştır. Önce cevap verilirse gerekçe cevaba uydurulur.

- **Ödül fonksiyonu örnekleri.** Ekranda görülen bir tasarımda kısa cevap ödülü 7 ile 30 kelime arasını ideal kabul ediyor, bu aralıkta $+1.0$ veriyor; 7 kelimeden az her eksik kelime için $-0.2$, 30 kelimeden fazla her fazla kelime için $-0.1$ ceza uyguluyordu (örneğin 4 kelime $-0.6$, 40 kelime $-1.0$) (ekrandan, 01:20:00). Aynı grubun ortak kontrolleri arasında doğru cevap harfi $+2.0$, doğru sıralama (açıklama önce, cevap sonra) $+0.5$, tekrar eden başlık $-3.0$, birden fazla farklı şık $-5.0$, çok kısa açıklama $-1.0$ vardı. Bir başka raporda yalnız format ödülü "format doğruysa $+1.0$, değilse $-1.0$", doğruluk ağırlıklı ödül ise $R = 2.0 \cdot Acc + 0.2 \cdot Fmt$ (hem yanlış hem formatsızsa $-0.5$) olarak tanımlanmıştı (ekrandan, 00:15:00).

- **Ödül hilesi örnekleri.** Bağlaç sayan ödülle eğitilen model beş bağlaçlık mantıksız cümleler kurarak yüksek ödül aldı; hoca bunu reward hacking diye adlandırdı. Ceza içermeyen bir tasarımda model bütün şıkları tekrar etmeyi öğrendi; ağır ceza içeren tasarımda ise hiç cevap vermemeye başladı. Benzerlik ödülü modelin soruyu kopyalamasına, hatta yeni sorular üretmesine yol açtı. Bir raporda model belirsiz durumlarda sistematik olarak C şıkkına yöneldi (ekrandan, 00:25:00).

- **KL ıraksaması.** Hoca, GRPO içinde modelin kendi ürettiği metni bozmasını engelleyen bir referans noktası olduğunu, bunun KL ıraksaması terimi olduğunu hatırlattı. Model anlamsız metinler üretiyorsa bu terimin katsayısı artırılır. Bir grup ise formata daha çok uysun diye beta katsayısını küçülttüğünü anlattı.

- **Soru başına cevap sayısı.** GRPO'nun "grup göreli" yapısı, aynı soruya üretilen cevapların birbirine göre değerlendirilmesine dayanır. Hoca, 2 cevapla bu karşılaştırmanın anlamlı olmadığını, küçük bir modelde iki cevaptan birinin doğru olma olasılığının düşük olduğunu, en az 8 civarı bir değerin daha makul olduğunu söyledi. Sunumlarda 4, 6, 8 ve 16 değerleri kullanılmıştı.

- **SFT ve çökme.** Bir öğrenci GRPO'dan önce SFT uyguladı; model formatı öğrendi ama hep aynı şıkkı vermeye başladı ve alternatif ödüller de bunu düzeltemedi. Hoca, SFT'de modelin muhtemelen aşırı öğrenip yerel bir minimuma çöktüğünü, GRPO'nun onu oradan hareket ettiremediğini, SFT'nin çok daha az yapılması ya da hiç yapılmaması gerektiğini söyledi.

- **Model birleştirme.** Gruplar MergeKit, PEFT ya da LoRA adaptör ağırlıklarının ortalamasını kullandı. Bir grup en iyi iki modeli %50-%50 birleştirdi: tekil doğruluklar %6.8 ve %4.4 iken ortalama olarak %5.6 beklenirken birleşik model %4 verdi (ekrandan, 01:25:00). Başka bir grup en iyi modele daha fazla ağırlık vererek 0.6 ve 0.4 katsayılarıyla birleştirdi. Hoca birleştirme için önce modellerin eğitilmesi gerektiğini, bunun da bir maliyet olduğunu hatırlattı. Ödül bileşenlerini ağırlıklandırıp tek ödül yapmanın ödevdeki birleştirme olmadığını belirtti.

- **Değerlendirme ve ölçüm hataları.** Hoca, doğruluğun nasıl hesaplandığını ve modelin gerçek çıktısını tekrar tekrar sordu. Bir grup doğru şıkkın cevap metninde geçip geçmediğine baktığı için bütün şıkları sayan modele yüksek doğruluk vermişti; ölçüt düzeltilince doğruluk %10'lara düştü. Format zorunluluğunun bir amacı da doğruluğu basit bir kuralla ölçebilmektir. Bir başka grubun %10 doğruluğu için hoca bu değerin iyi olup olmadığını sordu: beş şıklı bir soruda rastgele tahmin %20 verir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
