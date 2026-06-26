# Ders 5 Çalışma Özeti

## Genel Konular

- Activity kavramı
  - Android tarafında en önemli bileşen olan Activity; uygulamaya giriş noktası.
  - Bir activity'ye farklı noktalardan ulaşılabilmesi; sadece uygulamaya girip değil, uygulamanın içindeki farklı activity'lere başka activity'ler üzerinden de erişim sağlanabilmesi.
  - Her activity'nin kendi içerisinde belli yetenekleri barındıran, en küçük parça (atom parçası) olarak düşünülebilecek bir bileşen olması.
  - Örnek: bir uygulamadan mail gönderilmek istendiğinde, mail gönderme işini yapabilen başka bir uygulamanın activity'sine yönlendirme yapılması.

- Activity'lerin non-deterministic (belirsiz) yapısı
  - Telefondaki activity'ler arasındaki gezinmenin belli bir yolu olmaması; desktop tarafında genelde belli rotalar üzerinden ilerlenirken ve aynı uygulama içinde kalınırken, mobilde uygulamalar arası geçiş yapılabilir.
  - Bir uygulamadan başka bir uygulamaya iş paslanıp, o iş yapıldıktan sonra kaldığınız uygulamaya geri dönülebilmesi.
  - Bu nedenle activity'lerin yaşam döngüsünün (lifecycle) yönetiminin önemli olduğu.

- Fragment kavramı
  - Bir activity'nin ikiye bölünüp birbirinden bağımsız iki işin aynı aktivite içinde yönetilmesi ihtiyacından doğan yapı.
  - Örnek: bir fragment'ta e-postaların listelendiği, diğer fragment'ta seçilen e-postanın görüntülendiği senaryo.
  - Activity bir process olarak düşünülürse, fragment bir thread olarak düşünülebilir.
  - Her uygulamanın bir main activity'si vardır; C'deki main fonksiyonu gibi düşünülebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayar mühendisliğinde farklı alanlarda uzmanlaşmanın önemi
  - 2000'li yıllarda sadece kod yazarak (PHP, HTML) başarı elde edilebilirken, 2010'larda basit bir mobil uygulama ile ciddi gelir elde edilebileceği.
  - Günümüzde makine öğrenmesi, veri madenciliği, yapay zeka konularında bilgi sahibi olmanın fark yarattığı.
  - Yeni dönemin şartlarına uygun bilgisayar mühendisliği alt dallarında kariyer planlamasının önerilmesi.

- Hobi ve aktivitenin sağlık üzerindeki etkisi
  - Uzun süre bilgisayar başında kalmanın sağlık açısından sorunlu olduğu; hareket etmenin önemli olduğu.
  - Bilgisayar mühendislerinin genel hayatlarının bilgisayar başında geçtiği gerçeği; bunu telafi etmek için aktivite eklenmesi gerektiği.

- Online çalışmanın olumlu ve olumsuz yanları
  - Yolda zaman kaybetmemenin büyük avantaj olduğu.
  - Günde 10 saat bilgisayar başında olmanın verimi azalttığı; ortam değişikliğinin olmamasının motivasyonu düşürdüğü.
  - Online iş yapmanın güvenilirliğinin artması (pandemi sonrası).
  - Gece/gündüz kavramının kalkması, yükün artması.

- Modüler kod geliştirmenin dersin temel felsefesi olması
  - Her hafta bir özellik eklenecek, bir yapı kurulacak, üzerine başka şeyler eklenerek ilerlenecek.
  - Login mekanizmasıyla başlanıp, login ekranı tasarlandıktan sonra başka ekranlara geçileceği.
  - Ders sırasında gerçekleştirilen faaliyetlerin zamandan tasarruf ve öğrenme kolaylığı sağlayacağı.

- Hocaların "kötü polis" rolü
  - Pandemide otokontrol mekanizmasının herkeste iyi çalışmadığı için hocaların bu rolü üstlendiği.
  - Öğrencilere kulak verildiği, iletişim kurmaktan çekinmemeleri gerektiği.

## Kısa Tekrar Notları

- Activity: Android'in en önemli bileşeni, uygulamaya giriş noktası, en küçük atom parçası.
- Activity'ler arası geçiş non-deterministic; bir uygulamadan diğerine geçilebilir.
- Fragment: bir activity'yi bölmek için kullanılır; activity process, fragment thread benzeri.
- Her uygulamada bir main activity vardır (C'deki main gibi).
- Activity'ler farklı noktalardan erişilebilir (intent, başka uygulamalar).
- Dersin kod felsefesi: modüler geliştirme, her hafta üstüne koyarak ilerleme.

## Detaylı Açıklamalar

Dersin ilk büyük bölümü pandemi sürecinin öğrenciler üzerindeki psikolojik etkisi, uzaktan eğitim deneyimleri ve online çalışmanın getirdiği zorluklar üzerine bir sohbet şeklinde geçmiştir. Öğrenciler, online eğitimin yolda zaman kaybetmeme gibi avantajları olduğunu, ancak günde neredeyse 10 saat bilgisayar başında kalmak zorunda kaldıklarını, bu durumun verimi azalttığını, ortam değişikliğinin olmamasının motivasyon ve performans düşüklüğüne yol açtığını paylaşmışlardır. Hoca, bu durumun uzun vadede sağlık açısından sıkıntılara yol açabileceğini, özellikle bilgisayar mühendislerinin zaten genel hayatlarının bilgisayar başında geçtiğini, her koşulda hayata bir hareket katmanın faydalı olduğunu vurgulamıştır. Açık havada vakit geçirmek, iki-üç arkadaşla uzaktan ve gerekli önlemler alınmış açık hava buluşmaları düzenlemenin iyi geldiği belirtilmiştir. Online iş yapmanın güvenilirliğinin pandemi sonrasında arttığı, birçok şirketin tamamen online çalıştığı, fiziksel mekana gitmeden de işlerin yürütülebildiği, ancak bunun yükü artırdığı, gece-gündüz kavramının kalktığı, sekizde toplantı yapabilme gibi durumların oluştuğu paylaşılmıştır. Hoca, bu konuda bir paradoks yaşandığını (çok ödev verilmeyen derslerde ödev vermeye başlayınca öğrencilerin isyan etmesi) belirtmiş, vites düşürmeye çalıştıklarını, orta yolu bulmaya çalıştıklarını söylemiştir. "Kayıp nesil olmamanız için" ifadesini kullanarak, bilgisayar başında sizi sıkıntıya sokan durumların sizin iyiliğinize uzun vadede olduğunu vurgulamıştır. Otokontrol mekanizmasının herkeste iyi çalışmadığını, bu yüzden hocaların "kötü polis" rolünü üstlendiğini, ancak her zaman kulak verdiklerini ve iletişim kurmaktan çekinmemeleri gerektiğini belirtmiştir.

Dersin akademik içeriğe geçtiği bölümde, hoca ilk dört haftadaki mobil dünya konularının detayına merak eden öğrenciler için araştırma konuları bulmalarını önermiştir. Bilgisayar mühendisliğinin farklı ihtiyaçlara cevap vermesi gerektiği, 2000'li yıllarda kod yazarak başarı elde edilirken, 2010'larda basit mobil uygulamalarla ciddi gelir sağlandığı, günümüzde makine öğrenmesi, veri madenciliği, yapay zeka konularında bilgi sahibi olmanın fark yarattığı vurgulanmıştır. Yeni dönemin şartlarına uygun bilgisayar mühendisliği alt dallarında kariyer planlaması yapmanın uzun vadede yüksek ücretler ve pozisyonlar anlamına geleceği söylenmiştir.

Bu haftadan itibaren kodlamaya geçileceği belirtilmiştir. Önce slide'larla başlanacağı, arkasından Android Studio'nun açılacağı, bir telefon bağlantısının USB üzerinden ekrana yansıtılacağı, hangi uygulamanın kullanılabileceğinin anlatılacağı, Android Studio içindeki yeteneklerin tanıtılacağı belirtilmiştir. Dersin ilk bölümünde konu anlatımı, ikinci bölümünde o konuyla ilgili küçük bir uygulama parçası geliştirileceği açıklanmıştır.

Android bileşenlerinden en önemlisinin Activity olduğu, bunun uygulamaya giriş noktası olduğu belirtilmiştir. Bir activity'ye farklı noktalardan ulaşılabileceği, sadece uygulamaya girip değil, uygulamanın içindeki farklı activity'lere başka activity'ler üzerinden de erişim sağlanabileceği açıklanmıştır. Örnek olarak, bir uygulamadan mail gönderilmek istendiğinde, mail gönderme işini yapabilen başka bir uygulamanın activity'sine yönlendirme yapılması verilmiştir. Her activity'nin kendi içerisinde belli yetenekleri barındıran, uygulamadaki en küçük parça (atom parçası) olarak düşünülebilecek bir bileşen olduğu vurgulanmıştır.

Activity'lerin non-deterministic yapısı detaylı olarak açıklanmıştır. Telefondaki activity'ler arasındaki gezinmenin belli bir yolu olmaması, desktop tarafında genelde belli rotalar üzerinden ilerlenip aynı uygulama içinde kalınırken, mobilde uygulamalar arası geçiş yapılabilmesi, hatta bir uygulamadan başka bir uygulamaya iş paslanıp o iş yapıldıktan sonra kaldığınız uygulamaya geri dönülebilmesi örnekleri verilmiştir. Bu nedenle non-deterministic bir hikayeden bahsedildiği, her uygulamanın birden fazla ekran içerebileceği belirtilmiştir.

Aynı anda bir activity'nin yetmediği durumlarda, activity'nin ikiye bölünüp Fragment kavramının kullanıldığı açıklanmıştır. Birbirinden bağımsız iki işin aynı aktivite içinde yönetilebildiği Fragment yapısı, e-postaları listeleme ve seçilen e-postayı görüntüleme örneğiyle somutlaştırılmıştır. Activity process, fragment thread benzeri yapılar olarak kavramsallaştırılmıştır. Her uygulamanın bir main activity'si olduğu, C'deki main fonksiyonu gibi düşünülmesi gerektiği vurgulanmıştır.

Dersin kod felsefesi açıklanmıştır: Ders sırasında gerçekleştirilecek faaliyetler, bir hafta bir özellik ekleyip bir yapı kurup, arkasından onun üzerine başka şeyler ekleyerek ilerleme şeklinde olacaktır. Örneğin login mekanizmasıyla başlanacak, login giriş ekranı tasarlanacak, sonra başka bir ekrana geçilecektir. Bunlar daha sonra ödev olarak alınma potansiyeli taşımaktadır. Bu yüzden ders sırasında gerçekleştirilen faaliyetlerin zamandan tasarruf ve öğrenme kolaylığı sağlayacağı belirtilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
