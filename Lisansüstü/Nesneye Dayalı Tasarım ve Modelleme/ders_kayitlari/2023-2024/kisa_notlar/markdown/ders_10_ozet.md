# Ders 10 Çalışma Özeti

## Genel Konular

- Bu kayıtta yeni konu işlenmedi
  - Hoca bu hafta ders anlatmadı (ekrandan, 00:07:40), oturumu soru yanıtlamak için açık tuttu. Akademik içerik, birinci ara sınavın ikinci sorusu üzerine yapılan kısa bir tartışmadan ibarettir (00:21:40 - 00:25:55).
  - Kayıtta ekranda yalnız duyuru slaydı ve dosya gezgini görünür; sınav sorusunun metni ekranda gösterilmedi. Hoca soruyu tümüyle paylaşmak istemediğini söyledi.
- Sınav sorusu: çok sayıda benzer nesneyi az bellekle oluşturmak
  - Soruda çok sayıda ders vardır. Bu derslerin birbirine çok benzeyen ortak özellikleri vardır, aralarında yalnız ufak tefek farklar bulunur.
  - Ders sayısı çok olduğu için birçok yerde yüksek bellek kullanımı ortaya çıkabilir. Soru, bellek kullanımının mümkün olduğunca az tutulmasını açıkça ister.
  - Hocaya göre bu net gereksinim yüzünden sorunun tek doğru yanıtı Prototype kalıbıdır.
- Factory tabanlı yanıtlar neden uymuyor
  - Bir öğrenci, nesneleri bir factory ile hem oluşturup hem de bir depoda (store) biriktirmeyi önerdi. Hoca factory tabanlı çözümlerin hepsinin çeşitli bellek sıkıntılarına yol açtığını söyledi.
  - Abstract Factory belki düşünülebilir, ama onda da kalıtım ilişkisinin kırılımı (hangi ürün ailesine göre ayrılacağı) açısından önemli sorunlar vardır.
- Abstract Factory'nin bu bağlamda nasıl kurulacağı (hocanın örneği)
  - Abstract Factory'de bir programa göre ürün aileleri oluşur. Örnek: %100 Türkçe, %30 İngilizce ve %100 İngilizce programlar.
  - Aynı ders (örneğin Nesneye Yönelik Programlama) %100 Türkçe programda Türkçe, %100 İngilizce programda İngilizce verilir. %30 İngilizce programda duruma göre Türkçe ya da İngilizce açılabilir.
  - Bunun yanında zorunlu ve seçimlik ders ayrımı da vardır.
  - Asıl soru, hangi aileye göre ürün ailesini ve bu ailenin bireylerini yazacağınızdır. Bu kırılım doğru yapılmazsa çözüm kalıba uymaz.
  - Abstract Factory kalıbının yapısında iki düzey kalıtım vardır. Tek düzeyli bir kalıtım ağacıyla kurulan çözüm kalıbın UML gösterimine uymaz. <!-- BELİRSİZ: "iki düzey kalıtım" ifadesinin soyut fabrika ve soyut ürün hiyerarşilerini mi, yoksa başka bir yapıyı mı kastettiği altyazıdan net değil. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Gereksinim kalıbı belirler
  - Soruda "bellek kullanımını mümkün olduğunca az tut" gibi net bir gereksinim varsa, çözüm o gereksinimi karşılayan kalıp olmalıdır. Bu soruda bu kalıp Prototype'tır.
- Abstract Factory'de kırılım ve iki düzey kalıtım
  - Ürün ailelerinin hangi ölçüte göre ayrılacağı (program dili, zorunlu/seçimlik) doğru kurulmalıdır.
  - Kalıbın yapısındaki iki düzey kalıtım tek düzeyli bir ağaçla gösterilemez.

## Kısa Tekrar Notları

- Çok sayıda, birbirine çok benzeyen nesne ve az bellek gereksinimi: Prototype.
- Factory tabanlı çözümler bu soruda bellek sorunlarına yol açar.
- Abstract Factory: programa göre ürün aileleri (%100 Türkçe, %30 İngilizce, %100 İngilizce); her ailenin bireyleri (dersler).
- Abstract Factory'nin yapısında iki düzey kalıtım vardır; tek düzeyli kalıtım ağacı kalıba uymaz.

## Detaylı Açıklamalar

- Bu kayıtta ders anlatılmadı. Kaydın akademik kısmı, birinci ara sınavın ikinci sorusu üzerine birkaç dakikalık bir soru-cevaptır.
- Sorudaki durum şudur: bir dolu ders vardır ve bu derslerin pek çok ortak, birbirine çok benzeyen özelliği vardır; aralarında yalnız küçük farklar bulunur. Ders sayısı fazla olduğu için her dersi ayrı ayrı sıfırdan oluşturmak çok bellek harcar. Soru bu yüzden bellek kullanımının mümkün olduğunca az tutulmasını ister. Hoca bu açık gereksinim nedeniyle tek doğru yanıtın Prototype olduğunu söyledi.
- Bir öğrenci, factory ile nesneleri hem oluşturup hem bir depoda biriktirmenin olup olmayacağını sordu. Hoca factory tabanlı yanıtların çeşitli bellek sıkıntılarına yol açtığını belirtti. Abstract Factory'nin belki düşünülebileceğini, ama onda da kalıtım kırılımı açısından önemli sorunlar olduğunu söyledi.
- Hoca Abstract Factory'nin nasıl kurulması gerektiğini bir örnekle açıkladı. Programlar ürün ailelerini oluşturur: %100 Türkçe, %30 İngilizce, %100 İngilizce. Nesneye Yönelik Programlama gibi bir ders %100 Türkçe programda Türkçe, %100 İngilizce programda İngilizce verilir; %30 İngilizce programda duruma göre Türkçe ya da İngilizce açılabilir. Zorunlu ve seçimlik dersler de ayrıca vardır. Bu durumda hangi aileye göre ürün ailesinin ve bu ailenin bireylerinin yazılacağı kararı önemlidir. Kalıbın yapısında iki düzey kalıtım vardır; tek düzeyli kalıtım ağacıyla yapılan çözüm kalıbın UML gösterimine uymaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
