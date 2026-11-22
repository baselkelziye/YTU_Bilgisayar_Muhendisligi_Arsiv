# Ders 3 Çalışma Özeti

## Genel Konular

- Bilgi sistemi geliştirme aşamaları
  - Bir bilgi sistemi projesi sırasıyla proje planlama, analiz, tasarım, gerçekleştirme (implementasyon) ve destek aşamalarından geçer.
  - Bir projenin belgelerinden plan, fizibilite, analiz, sistem tasarımı ve kodlama aşamaları izlenebilmelidir.
  - Proje yapısal ya da nesneye yönelik yaklaşımla geliştirilebilir. Seçilen yaklaşıma göre kullanılan diyagramlar değişir.
- Proje ekibi (ekrandan, 00:20:00)
  - Ekip, her üyenin bütün için kritik, uzmanlaşmış bir görev yaptığı bir "cerrahi ekip" gibidir.
  - Ekip projenin süresi boyunca değişir:
    - Planlama: az sayıda kişi (proje yöneticisi ve birkaç analist).
    - Analiz: iş analistleri ve sistem analistleri eklenir.
    - Tasarım: teknik uzmanlar (veri tabanı, ağ tasarımcısı) gelebilir.
    - Gerçekleştirme: programcılar ve kalite kontrol çalışanları eklenir.
  - En kalabalık ekip genellikle gerçekleştirme aşamasındadır.
- Proje yönetimi ve roller (ekrandan, 00:35:00)
  - Proje yöneticisi: ekibin işleyişinden birinci derecede sorumlu kişi.
  - Proje yönetimi: önceden belirlenmiş iş listesi (takvim) ve bütçe içinde planlanan sonuca ulaşmak için çalışanları ve organizasyonu yönlendirme.
  - İyi yönetici plan yapmayı, planı uygulamayı, sorunları önceden görmeyi ve sapmalara göre ayar yapmayı bilir.
  - Müşteri (client): projeyi finanse eden ve sonuçlarını isteyen kişi ya da grup.
  - Kullanıcı (user): sistemi doğrudan kullanacak kişi ya da grup.
- Proje yöneticisinin görevleri
  - Organizasyon ve planlama: proje kapsamını tanımlama, ayrıntılı iş listesi ve takvimle plan geliştirme.
  - Yönlendirme: çalışanları yönlendirme, kilometre taşlarını (milestone) belirleme ve bunlarda değerlendirme yapma.
  - Kontrol: ilerlemeyi izleme, metodolojileri tanımlama, sorunları öngörme.
- Projenin başlatılması (ekrandan, 00:40:00)
  - Uzun dönemli stratejik planın parçası olarak (yukarıdan aşağı).
  - Ortaya çıkan acil bir ihtiyacı karşılamak için (aşağıdan yukarı).
  - Dış bir etken nedeniyle (örneğin vergi yapısındaki değişikliğin faturalama sistemini etkilemesi).
- Proje planlama aşamasının adımları
  - Problemi tanımlama, fizibiliteyi doğrulama, proje iş listesini (takvimini) üretme, ekibi oluşturma (görevlere kişi atama), projeyi başlatma.
- Problemi tanımlama: Rocky Mountain Outfitters (RMO) örneği (ekrandan, 00:45:00 ve 01:00:00)
  - İhtiyaç ve işletme faydaları ifadesi: elle sipariş işlemeden kaynaklanan hataları azaltmak, sipariş işlemeyi hızlandırmak, posta ve telefon siparişindeki personel düzeyini korumak ya da azaltmak, İnternet üzerinden yeni satış kanalı açmak, popüler ve yavaş satan ürünleri izleyerek ciroyu artırmak, kapsamlı müşteri desteğiyle müşteri bağlılığını artırmak.
  - Sistem yetenekleri listesi: çevrim içi müşteri, sipariş, bekleyen sipariş ve iade bilgisi; telefon ve posta kataloğu satışı için hızlı veri giriş ekranları; İnternet üzerinden katalog satışı ve sipariş takibi; pazar analizi için yeterli veri tabanı ve geçmiş bilgisi; müşteri sorguları için işlem geçmişi; hacimde büyük artışı (yüzde 300 ya da daha fazla) performans kaybı olmadan karşılama; yeni siparişleri 24 saatte gönderme; birden çok depodan gönderimi koordine etme; satış analizi ve talep tahmini için geçmiş tutma.
  - Sistemin dış birimlerle (pazarlama, müşteri, banka, ürün gönderme, yönetim, satış) ilişkisi taslak (özet) veri akış diyagramı ile gösterilir.
- Fizibilite (olurluluk) türleri
  - Ekonomik fizibilite: maliyet-fayda analizi.
  - Kurumsal ve kültürel fizibilite: sistemin kurum kültürüne uygunluğu.
  - Teknik fizibilite: önerilen teknolojinin gereksinimleri ve eldeki uzmanlık.
  - Zaman çizelgesi (takvim) fizibilitesi: iş listesinin belirlenen süreye sığması.
  - Kaynak fizibilitesi: ekip, bilgisayar kaynakları ve destek personelinin bulunabilirliği.
- Maliyetler (ekrandan, 01:05:00)
  - Geliştirme maliyetleri: maaş ve ücretler, donanım ve kurulumu, yazılım ve lisanslar, danışmanlık ve üçüncü taraf ödemeleri, eğitim, tesisler, araçlar, destek personeli, seyahat ve diğer.
  - Süregelen işletim maliyetleri: bağlantı, donanım bakımı, bilgisayar işletimi, program desteği, donanım amortismanı, eğitim ve sürekli destek (yardım masası), sarf malzemeleri.
- Faydalar
  - Somut (tangible) faydalar: paraya çevrilebilir. Örnekler: otomasyonla personel azalması, işletim giderlerinin azalması, hata oranının düşmesi, envanter ve satış kayıplarının azalması, kâğıt ve iletişim maliyetlerinin düşmesi.
  - Somut olmayan (intangible) faydalar: doğrudan paraya dökülemez. Örnek: müşteri memnuniyeti, hastane bilgi sisteminde hasta güveni.
- Fizibilite çalışmasının yürütülmesi (ekrandan, 01:10:00)
  - Her maliyet kategorisi tahmin edilir, maaşlar personel ihtiyacından hesaplanır, diğer maliyetler (donanım, lisans, eğitim) tahmin edilir.
  - Geliştirme ve yıllık işletim maliyetleri ile faydaların özeti çıkarılır.
  - Net bugünkü değer (NPV) örneğin 5 yıllık dönem için hesaplanır ve projeye devam edilip edilmeyeceğine karar verilir.
- Ekonomik ölçütler
  - Net bugünkü değer (NPV): gelecekteki fayda ve maliyetlerin bugünkü değeri.
  - Geri ödeme süresi (payback period): birikimli faydanın maliyeti karşıladığı an.
  - Yatırım getirisi (ROI): yatırımdan elde edilen kazanç oranı.
- Proje takvimi geliştirme (ekrandan, 01:20:00)
  - Her etkinlik için görevleri belirle (yukarıdan aşağı ya da aşağıdan yukarı), her görevin süre ve kaynağını tahmin et (iyimser, kötümser, beklenen süre), görev sırasını belirle, görevleri takvime yerleştir.
  - Gösterim yöntemleri: PERT/CPM ağı ve Gantt şeması.
- PERT ve Gantt şemaları (ekrandan, 01:25:00 ve 01:30:00)
  - PERT: görevler dikdörtgenlerle gösterilir; paralel yollardaki görevler eş zamanlı yapılabilir; kritik yol bağımlı görevlerin en uzun yoludur ve üzerinde bolluk (slack) süresi yoktur.
  - Gantt: görevler yatay çubuklarla, zaman ekseni gün ve haftalarla gösterilir; takvimi iyi gösterir, bağımlılıkları daha zayıf gösterir; tamamlanan görevler renklendirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanıcı ile müşteri aynı kişi olmayabilir
  - Bir şirketin muhasebe biriminde bordro yazılımı yenilenecekse isteği muhasebe müdürü yapar, parayı üst yönetim verir, sistemi bordro işlemlerini yapan memurlar kullanır. Bu durumda müşteri ile kullanıcı farklıdır.
- Proje yöneticisi "yetkisiz sorumluluk" taşır
  - Projeden sorumludur ama çalışanların işe ya da projeye alınması çoğu zaman şirketin üst yönetiminin işidir.
- Ekonomik fizibilite yalnız maliyet değildir
  - Genellikle yalnız maliyet hesabı gibi anlaşılır. Asıl iş maliyet ile faydanın kıyaslanmasıdır: yapılan yatırım elde edilecek faydaya değecek mi?
- Maliyet yalnız kurulumda oluşmaz
  - Geliştirme maliyetine ek olarak sistemin çalışır kalması için bakım, destek ve eğitim gibi süregelen maliyetler vardır.
- Bütün alternatif çözümler için fizibilite yapılır
  - Teknik, ekonomik ve kullanılabilirlik açısından her alternatif değerlendirilir.
- Kritik yol
  - PERT'te önemli olan kritik yolu bulmaktır. Bu yoldaki görevlerde gecikmeye izin yoktur.

## Kısa Tekrar Notları

- Aşamalar: planlama, analiz, tasarım, gerçekleştirme, destek.
- Ekip aşamaya göre büyür; en kalabalık hali gerçekleştirmededir.
- Müşteri parayı verir ve ister; kullanıcı sistemi doğrudan kullanır.
- Proje başlatma: yukarıdan aşağı (stratejik plan), aşağıdan yukarı (acil ihtiyaç), dış etken.
- Planlama adımları: problemi tanımla, fizibiliteyi doğrula, takvim üret, ekibi kur, projeyi başlat.
- Fizibilite: ekonomik, kurumsal-kültürel, teknik, takvim, kaynak.
- Maliyet: geliştirme + süregelen işletim.
- Fayda: somut (paraya çevrilir) ve somut olmayan.
- NPV: gelecekteki tutarların indirim faktörüyle bugüne çekilmesi; %10 için 1. yıl faktörü 0,9091.
- Geri ödeme süresi: birikimli NPV'nin sıfırı geçtiği an.
- ROI: kazancın maliyete oranı.
- PERT: bağımlılık ve kritik yol; Gantt: takvim ve süre.

## Detaylı Açıklamalar

- Bilgi sistemi geliştirme projesinde planlama aşaması, problemin tanımıyla başlar: bizden ne isteniyor, ne yapılacak? Ardından problemi çözecek teknik yapı düşünülür ve fizibilitesi yapılır. Teknik çözümün maliyeti ve getirisi kıyaslanarak ekonomik fizibilite, kullanıcılar açısından kullanılabilirlik durumu değerlendirilerek bir başka fizibilite yapılır. Bütün alternatif çözümler için bu değerlendirmeler tablolarla hazırlanır. Sonra proje iş listesi (analiz, tasarım, gerçekleştirme, test, destek) çıkarılır, görevler belirlenir ve görevlere kişi atanır.

- RMO örneğinde şirket, satış, müşteri desteği ve envanter için uzun dönemli bir stratejik plan yapmıştır. Yeni müşteri destek sistemi bu planın ilk kritik sistemidir. Önce işletme faydaları (neden yenilemeye ihtiyaç var), sonra bu faydaları sağlayacak sistem yetenekleri yazılır. Son olarak sistemin çevresindeki birimlerle hangi bilgiler üzerinden iletişim kurduğu taslak veri akış diyagramıyla gösterilir.

- RMO personel maliyeti hesabı (yıllık maaş, çalışma süresi ve kişi sayısından). Proje yöneticisi ve sistem analisti satırları altyazıyla doğrulandı, ağ tasarımcısı satırı slaytın küçük önizlemesinden okundu (ekrandan, 01:15:00):

| Görev | Süre | Yıllık maaş | Toplam |
|---|---|---|---|
| Proje yöneticisi | 12 ay | 90.000 | 90.000 |
| Sistem analisti (3 kişi) | 9 ay | 75.000 | 168.750 |
| Programcı (6 kişi) | 7 ay | 50.000 | 175.000 |
| Ağ tasarımcısı | 5 ay | 70.000 | 29.166 |
| Toplam | | | 462.916 |

  - Örnek: $75.000 \times \frac{9}{12} \times 3 = 168.750$. Toplam python ile doğrulandı.

- RMO maliyet-fayda analizi, indirim oranı %10 (ekrandan, 01:15:00). İndirim faktörü $\frac{1}{(1+0{,}10)^n}$ ile bulunur:

| Satır | Yıl 0 | Yıl 1 | Yıl 2 | Yıl 3 | Yıl 4 | Yıl 5 |
|---|---|---|---|---|---|---|
| Fayda değeri | 0 | 889.000 | 1.139.000 | 1.514.000 | 2.077.000 | 2.927.000 |
| İndirim faktörü | 1,000 | 0,9091 | 0,8264 | 0,7513 | 0,6830 | 0,6209 |
| Faydaların bugünkü değeri | 0 | 808.190 | 941.270 | 1.137.468 | 1.418.591 | 1.817.374 |
| Geliştirme maliyeti | 1.336.000 | | | | | |
| Süregelen maliyet | | 241.000 | 241.000 | 241.000 | 241.000 | 241.000 |
| Maliyetlerin bugünkü değeri | 1.336.000 | 219.093 | 199.162 | 181.063 | 164.603 | 149.637 |
| Net bugünkü değer | -1.336.000 | 589.097 | 742.107 | 956.405 | 1.253.988 | 1.667.737 |
| Birikimli NPV | -1.336.000 | -746.903 | -4.796 | 951.609 | 2.205.597 | 3.873.334 |

  - Geri ödeme süresi: birikimli NPV 2. yıl sonunda -4.796, 3. yıl sonunda +951.609. $2 + \frac{4.796}{4.796 + 951.609} \approx 2{,}005$ yıl, yani yaklaşık 2 yıl 2 gün.
  - Ders sonrası not: Slayttaki 2. yıl birikimli NPV "(4,769)" yazıyor, ama tablodaki değerlerden -4.796 çıkıyor ve slayttaki geri ödeme formülü de 4.796'yı kullanıyor. Slayttaki 4. yıl maliyet bugünkü değeri "164,6037" diye yazılmış, doğrusu 164.603'tür (python ile doğrulandı).
  - Ders sonrası not: Slayttaki 5 yıllık ROI satırı "22.23%" ve formül olarak $\frac{1.817.374 - (1.336.000 + 149.637)}{1.336.000 + 149.637}$ veriyor. Bu formülün sonucu %22,33'tür. Ayrıca bu formül yalnız 5. yılın değerlerini kullanıyor; 5 yılın toplam bugünkü değerleriyle $\frac{\text{toplam fayda} - \text{toplam maliyet}}{\text{toplam maliyet}}$ hesaplanırsa yaklaşık %172 çıkar. Slayttaki satır büyük olasılıkla hatalıdır. Derste ROI sayısı üzerinde durulmadı.

- PERT/CPM şemasında görevler kutularla, bağımlılıklar oklarla gösterilir. Bir görev bitmeden ona bağlı görev başlayamaz. Paralel yollardaki görevler aynı anda yürütülebilir. Kritik yol, bağımlı görevlerden oluşan en uzun yoldur ve projenin toplam süresini belirler; bu yoldaki bir gecikme bütün projeyi geciktirir. Diğer yollarda takvimi etkilemeden kayabilen bolluk süresi olabilir. Gantt şemasında her görev bir yatay çubuktur, çubuğun uzunluğu süresini gösterir; tamamlanan görevler farklı renkle, bugünün tarihi dikey bir çizgiyle gösterilir. Bu şemalar MS Project gibi araçlarla çizilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
