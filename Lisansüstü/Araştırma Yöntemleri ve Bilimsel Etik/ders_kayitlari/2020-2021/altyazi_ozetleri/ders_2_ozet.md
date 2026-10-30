# Ders 2 Çalışma Özeti

## Genel Konular

- Bilimsel veriye erişim: literatür taraması (literature review) için kaynak.
- Üniversite kütüphanesinin imkanları ve elektronik abonelikler (subscription).
- Kampüs dışından erişim: ters vekil sunucu (reverse proxy) ve üniversitenin yeni uzaktan erişim sistemi.
- İndeks (index) kavramı ve indekslerin işlevi.
- Mühendislik için önemli indeksler: Science Citation Index (SCI), Science Citation Index Expanded (SCIE), Scopus.
- Uygun dergiyi (journal) bulma: araçlar ve "amaç ve kapsam" (aims and scope) incelemesi.
- Sahte dergiler, sahte indeksler ve yağmacı (predatory) konferanslar.
- Açık erişim (open access) dergiler.
- Dergi ve yazar ölçütleri: etki faktörü (impact factor), Journal Citation Reports, h-indeksi.
- Konferans bildirisi ile dergi makalesi farkı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Herhangi bir araştırmadan önce literatür taraması gerekir. Bunun için kaynağa erişim şarttır; öğrenci için bu çoğunlukla üniversite üzerinden olur.
- Üniversitenin elektronik aboneliklerini kampüs dışından da test edin. Tez ve projeler için kritik.
- Son dönemde Google Scholar üzerinden bulunan PDF'lerin birçoğu indirilemiyor. Üniversitenin aboneliğini kullanmak işi çok kolaylaştırır.
- SCI ile SCIE arasında kalite farkı aramanın anlamı yok. Scopus'ta da çok değerli dergiler var. Önemli olan indeks değil, gönderilen derginin kendisi.
- Dergi bulma araçları yalnızca yardımcıdır. Asıl iş:
  - Literatür taramasında bulduğunuz makalelerin nerede yayınlandığına bakmak.
  - Derginin amaç ve kapsam kısmını dikkatle okumak.
  - Dergide benzer konuda kaç yayın olduğuna ve ne kadar yeni olduklarına bakmak.
- Makalenin dergiye uygunluğuna son noktada editör karar verir. Kapsam dışı bir makale dakikalar içinde reddedilebilir (desk reject).
- Yayıncılık ticarileşti. Sahte dergi, sahte indeks ve "parayı ver, yayınla" düzenine karşı dikkatli olun.
- Etki faktörü hâlâ kullanılıyor ama manipüle edilmesi kolay. Tek ölçüt olarak görülmemeli.
- h-indeksi de manipüle edilebilir. En basit yol, yazarın kendi eski yayınlarına sürekli atıf yapmasıdır.

## Kısa Tekrar Notları

- Kütüphane (2015 faaliyet raporu): 130 binden fazla farklı kitap. Raporda 9754 olan yüksek lisans ve doktora tezi sayısı bugün 15 bine yaklaşmış.
- Türkiye'de tezlerin çevrimiçi ortama aktarılması geç başladı. Bazı eski tezlere çevrimiçi erişilemiyor.
- Elektronik abonelikler IP adresine göre çalışır: kampüs içinden bağlananlara açıktır.
- İndeks: dergileri bir araya toplayıp okura ulaştıran ve atıf istatistiği çıkaran yapı. Bir dergi birden fazla indekste olabilir.
- Dergi bulma araçları: Master Journal List (Clarivate), IEEE Xplore, Elsevier Journal Finder, ACM Digital Library, ScienceDirect, Springer Journal Suggester.
- Etki faktörü: son iki yılın yayınlarına bir sonraki yıl yapılan atıfların, o iki yıldaki yayın sayısına oranı. Beş yıllık sürümü de var.
- Konferansa gönderilen metin "bildiri" (conference paper), dergiye gönderilen metin "makale" (article).

## Detaylı Açıklamalar

### Kütüphane ve elektronik erişim

- Üniversite kütüphanesi basılı kitap, tez ve dergi sunuyor. Ayrıca birçok elektronik veri tabanına üye.
  - Örnek: IEEE Xplore üyeliği. Buradan istenen yayın doğrudan indirilebiliyor.
  - Üyelikler yalnızca bilgisayar mühendisliğiyle sınırlı değil: kimya, mimarlık, tıp gibi alanların veri tabanları da var.
- Eskiden ACM, IEEE gibi sitelerdeki yayınların PDF'leri Google Scholar üzerinden de bulunabiliyordu. Telif hakkı düzenlemeleri nedeniyle artık çoğu bulunamıyor.
- Başka üniversitelerin dijital kütüphanelerindeki kaynaklara da erişmek mümkün olabilir. Ama halk kütüphanesi üyelikleri mühendislik için yeterli değil.

### Kampüs dışından erişim

- Abonelikler IP adresine göre denetlenir. Kampüs dışından erişim için iki yol var:
  - Ters vekil sunucu (reverse proxy) ayarı: kütüphanenin sayfasındaki PDF'te ekran görüntüleriyle anlatılıyor.
  - Üniversitenin yeni uzaktan erişim sistemi (altyazıda "VETIS" diye geçiyor). Vekil sunucu ayarıyla uğraşmayı gerektirmiyor.
- Vekil sunucu (proxy) nedir:
  - Normalde internet çıkışına konan bir cihazdır.
  - Amacı internet erişimini denetlemek, yönetmek ve iyileştirmek (optimize).
  - İyileştirme: bir kullanıcının açtığı sayfayı yerelde önbelleğe alır (caching), aynı sayfayı isteyen başkasına yerelden verir.
  - Yönetme: belirli kişilerin ya da IP'lerin belirli sayfalara erişimini saat, gün ya da tamamen kısıtlar.
- "Ters" denmesinin nedeni: burada vekil sunucu dışarıdan kampüse girmek için kullanılır. Bağlandıktan sonra sanki kampüs içindeki bir bilgisayarmışsınız gibi dışarı çıkarsınız.
- Yan etki: tarayıcıda sistem geneli (system-wide) ayar yapılırsa bütün trafik üniversite ağı üzerinden geçer. Bu, bazı erişim sorunlarına yol açabilir.

### İndeks kavramı

- Kitap indeksine benzer. Hoca örnek olarak bir bilgisayar ağları kitabını veriyor: fiziksel katmanın kaçıncı sayfada olduğunu indeksten bulursunuz, sayfa sayfa çevirmezsiniz.
- Bir alanda (ör. bilgisayar mühendisliği, onun altında yapay zeka, ağlar, onların da altında mobil ağlar, araçlar arası iletişim) çok sayıda dergi var. Bunları tek tek takip etmek zor.
- İndeks iki taraflı çalışır:
  - Okur, tek tek dergilerle uğraşmak yerine indekse üye olur ve bilgiye oradan erişir.
  - Dergi de indeks sayesinde daha çok okura ulaşır.
- Bir öğrencinin sorusu: indeks bir yayıncı kuruluş mu?
  - Hayır. Yayıncı (dergi) makaleyi yayınlar. İndeks, yayınları bir araya toplayıp bugün internet üzerinden erişime açar.
  - Eskiden yayıncılar ve indeksleyenler ayrıydı. Bugün Springer ve Elsevier gibi büyük yayıncıların kendi indeksleri de var.
  - Hocanın benzetmesi: indeks bir kulüp. Hem dergiler hem son kullanıcılar üye olur.
- Bir dergi birden fazla indekste yer alabilir (Google Scholar, Scopus vb.). IEEE Xplore'da arama yapınca IEEE'nin kendi indeksinde, Google Scholar'da arama yapınca onun kapsadığı birçok indekste aranmış olur.

### İndekslerin tarihi ve alan farkları

- İlk indeksler daha çok biyomedikal alanda kuruldu: Embase, PubMed, BIOSIS gibi.
- Neden: II. Dünya Savaşı sonrasında sağlık alanında çok sayıda yayın çıktı. Bu yayınları belirli bir sistematikle yazmak ve araştırmacıların birbirinden haberdar olması gerekti.
- Mühendislikte önemli üç indeks: SCI, SCIE ve Scopus.
  - Akademik atama ve yükseltmelerde ölçüt olarak kullanılıyorlar.
  - Bu yüzden tez danışmanınız makaleyi bu indekslerdeki bir dergiye göndermenizi isteyecektir.

### SCI, SCIE ve Scopus karşılaştırması

- Yaygın bir kanı var: SCI dergileri SCIE dergilerinden daha değerli. Hocaya göre bunun bir mantığı yok.
- Tarihsel neden: önce SCI vardı ve kağıt üzerinde yürüyordu. Makale basılı gönderiliyor, üç kopya hakemlere gidiyordu. Yönetimi zor olduğu için SCIE sonradan elektronik ortamda ortaya çıktı.
- Thomson Reuters'tan bir yöneticinin bir e-postaya verdiği cevaba göre fark yalnızca depolama ortamıydı: biri çevrimiçi, diğeri yalnızca CD/DVD üzerinden. Artık ikisi de çevrimiçi.
- Scopus Türkiye'deki ölçütlerde SCI/SCIE'nin bir adım gerisinde sayılıyordu. Hocanın benzetmesi: köklü bir kulüp olmak, sonradan gelen bir kulübün sizi geçmesine engel değildir.
- Hocanın deneyimi:
  - SCI'da bir dergi, İngilizcesi anlaşılmayacak kadar kötü bir makaleyi hocanın "major revision" önerisine rağmen iki hafta sonra yayınlamış.
  - Öte yandan SCIE'de Springer'in çok iyi bir ağ dergisi var.
- Sonuç: indeksleri çarpıştırmak yerine indekslerin sağladığı özelliklere ve derginin kendisine bakın.

### İndeksin yazar ve dergi açısından faydası

- Yazar açısından:
  - Yayınlar daha çok kişiye ulaşır.
  - Kimin, hangi çalışmada size atıf yaptığını görürsünüz. Bu çalışmalar büyük ihtimalle sizin işinizle ilgilidir; okuyup üstüne bir şey koyabilirsiniz.
  - Araştırırken iyi bir yayın bulunca, ona atıf yapan diğer yayınları indeksten bulabilirsiniz. Hocaya göre bunu en iyi yapan Google Scholar.
  - Örnek: 1996'da yapılmış ve 2021'e kadar hiç atıf almamış bir yayının işe yarar olduğunu düşünmek için sebep yok.
- Dergi açısından: kaliteli yayınları belirli bir kitleye tek tek e-posta göndermeden ulaştırmak. Her iki taraf da kazançlı (win-win).

### Uygun dergiyi bulma

- Araçlar:
  - Master Journal List: eskiden Thomson Reuters'ın, şimdi Clarivate altında.
  - IEEE Xplore: bilgisayar, elektrik ve haberleşme alanlarında güvenilir. Konferans da aranabilir.
  - Elsevier Journal Finder: ana ve alt başlıklarla listeyi daraltır.
  - ACM Digital Library, ScienceDirect.
  - Springer Journal Suggester: makalenin başlığını ve özetini (abstract) girersiniz, uygun dergileri önerir. Her zaman başarılı değil.
- Asıl yöntem:
  1. Literatür taramasında bulduğunuz ve ilgili çalışmalar (related work) kısmına koyduğunuz makalelerin dergileri, sizin için de potansiyel dergilerdir.
  2. Derginin amaç ve kapsam kısmını okuyun. Elsevier Journal Finder bile son kararın bu inceleme olduğunu söylüyor.
  3. Dergide benzer başlıkta ya da alanda kaç yayın olduğunu ve ne kadar yeni olduklarını aratın.
- Uyarı: daha önce benzer bir yayın o dergide çıkmış olabilir ama derginin kapsamı sonradan değişmiş olabilir.

### Sahte dergiler, sahte indeksler ve yağmacı konferanslar

- Ticarileşen her alanda hile görülür. Kimliğe bürünen (phishing) e-postalardan ve sahte dergilerden uzak durun.
- Örnek hile: kısaltması aynı kalsın diye "Science Citation List" gibi var olmayan bir indeks uydurmak ve "bugün gönder, iki haftada kabul" vaadiyle e-posta atmak.
- Bazıları gerçek bir derginin adıyla sayfa açıp bilgileri birebir kopyalamış ve yayın vaadiyle para toplamış.
- Hocaya göre bu tuzaklara düşenlerin bir kısmı bilinçsizlikten değil, atama-yükseltme için kestirme yol aramaktan düşüyor.
- Örnek: WASET (World Academy of Science, Engineering and Technology).
  - Her ay farklı bir ülkede, farklı bir şehirde aynı adlı konferanslar düzenliyor.
  - Sayfalardaki yazılar birebir aynı, yalnızca arka plan resmi değişiyor.
  - Yüksek kayıt ücreti alınıyor, gönderilen her şey yayınlanıyor.

### Açık erişim dergiler

- Örnek: IEEE dergilerine akademik gönderim normalde ücretsiz. Proje bütçeniz varsa ödeme yapmanız istenir; zorunlu değil. Dergiler yalnızca üyelerine açık, kazanç üyelikten gelir.
- Açık erişim (open access): içerik üyelik gerektirmeden herkese açık. Daha çok okur ve daha çok atıf anlamına gelebilir.
- Bunun kötüye kullanımı: "açık erişim istiyorsan öde" ya da "biz yalnızca açık erişimliyiz, ücret öde" diyen dergiler.
- Bir test: teknik, yapısal ve dil bilgisi açısından berbat bir makale 304 dergiye gönderilmiş. Yarısından fazlası kabul etmiş.

### Etki faktörü (impact factor)

- Thomson'daki SCI/SCIE dergilerini karşılaştırmak için önerilmiş.
- Hesap mantığı (1992 örneği): 1992'de yayınlanan yayınların, 1990 ve 1991 yayınlarına yaptığı atıflar sayılır.

$$IF_{1992} = \frac{\text{1992'de, 1990 ve 1991 yayınlarına yapılan atıf sayısı}}{\text{1990 ve 1991'de yayınlanan atıf alabilir yayın sayısı}}$$

- Aynı mantık beş yıl için uygulanırsa beş yıllık etki faktörü bulunur. Sonuç yalnızca bir sayıdır (3,5; 1,2; 0,6 gibi).
- Manipüle etme yolları:
  - Editörün ya da yardımcı editörün yazara "dergimizdeki ilgili makaleleri de kaynak gösterin" baskısı (zorlamalı atıf, coercive citation).
  - Popüler konulardaki (hot topic) makalelerin sayısını artırmak.
  - Çok tanınmış yazarları davet edip makalelerini değerlendirmeden yayınlamak.
  - Yüzlerce kaynak içeren derleme (review/survey) makaleleri yayınlamak. Normalde bir makale bir sorunu tespit edip katkı sunar; derleme ise alanın genel bir fotoğrafını çeker.
  - Editörün ön söz gibi yazılarda derginin önceki makalelerine toplu atıf yapması.
- Journal Citation Reports (Clarivate): hangi derginin kaç makale yayınladığı, kaç atıf aldığı gibi ayrıntılı rapor. Okumak için ayrı üyelik gerekiyor.

### h-indeksi

- Yazarın performansını ölçmek için kullanılan bir ölçüt. Hoca formülü ve mantığı sıkıntılı buluyor.
- Değer, bakılan indekse göre değişir: Google Scholar kendi indekslediği tüm yayınlara bakar, başka indeks başka değer verir.
- Hoca kendi değerini örnek veriyor: tüm zamanlar için 7, 2016'dan sonrası için 6.
- i10-indeksi gibi başka ölçütler de var.
- Genel kural: ne kadar yüksekse o kadar iyi.
- Manipülasyon: yazar her yeni yayınında eski yayınlarına atıf yaparak h-indeksini şişirebilir (self-citation).

### Geç fark edilen yayınlar

- Bir öğrencinin sorusu: 2005'te yayınlanan derin öğrenme makaleleri, GPU gücü artınca yıllar sonra çok atıf aldı. 2006'da bakan biri bunları kalitesiz mi sayardı?
- Hocanın cevabı: önemli olan makalenin 2005'te düzgün, prestijli bir yerde yayınlanıp yayınlanmadığı. Öyleyse o gün için de değerlidir. Bir çalışma o gün yalnızca büyük bir hesaplama merkezinde çalıştırılabilirken yıllar sonra ev bilgisayarında çalışır hale gelebilir; bu ayrı bir durumdur.

### Konferans bildirisi ve dergi makalesi

- Konferansa gönderilen metin bildiridir. Bildiriler konferansın bildiri kitabında (proceedings) art arda basılır.
- Bildirinin genişletilmiş hali sonradan dergiye makale olarak gönderilebilir.
- Bazı konferanslar en iyi bildirilerin bir kısmını ödül gibi ilgili bir dergide makale olarak yayınlar.
- Bazı yayıncılar konferans bildirilerini kitap dizisi olarak yayınlıyor (ör. Lecture Notes in Computer Science).

### Duyurular

- Ders, hocanın bölümdeki proje değerlendirme toplantısı nedeniyle kısa tutuldu.
- Değerlendirme: final sınavı ve proje önerisi yazımı ile sunumu. Sunumlar son haftalarda yapılacak.
- Hoca, Zoom'da konuşanın adını göremediği için soru soranların önce adını söylemesini istedi.

### Ders sonrası notlar

- Lecture Notes in Computer Science (LNCS) Elsevier'in değil, Springer'in dizisidir.
- Etki faktörünü Thomson'ın sıradan bir çalışanı değil, ISI'nin (Institute for Scientific Information) kurucusu Eugene Garfield ortaya attı. ISI sonradan Thomson'a geçti. Thomson Reuters bu bilimsel bilgi işini 2016'da bütünüyle Clarivate'e devretti.
- SCI ile SCIE arasındaki fark yalnızca depolama ortamı değildi. SCI, seçilmiş çekirdek dergilerden oluşan daha küçük bir alt kümeydi; SCIE daha çok dergiyi kapsıyordu. Bugün Clarivate yalnızca SCIE'yi listeliyor. Hocanın asıl vurgusu doğru: bir dergiyi değerlendirirken SCI/SCIE etiketinden çok derginin kendisine bakmak gerekir.
- 304 dergiye gönderilen sahte makale deneyi: John Bohannon, Science, 2013 ("Who's Afraid of Peer Review?"). Dergilerin yaklaşık 157'si makaleyi kabul etmişti.
- h-indeksinin doğru tanımı: bir yazarın en az $h$ atıf almış $h$ yayını varsa h-indeksi $h$'dir. Örnek: 10 atıflı 3, 2 atıflı 5 yayını olan yazarın h-indeksi 3'tür. Google Scholar'daki "2016'dan beri" değeri aynı hesabın yalnızca son yıllardaki atıflarla yapılmış halidir.
- i10-indeksi: en az 10 atıf almış yayın sayısı.
- Q1-Q4 sorusunu hoca cevaplamadı. Q1-Q4, bir dergi kategorisindeki dergilerin etki faktörüne (ya da Scopus'ta SJR değerine) göre sıralanıp dörde bölünmesidir. Q1 en üst %25'tir.
- Altyazıda geçen "Elseverin Journal Finder'ı" doğru; hoca öncesinde "LCR" diyor, bu da Elsevier olmalı.

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
