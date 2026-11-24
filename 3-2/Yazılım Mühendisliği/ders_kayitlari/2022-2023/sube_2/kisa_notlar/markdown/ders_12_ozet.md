# Ders 12 Çalışma Özeti

## Genel Konular

- Uygulama senaryosu: otobüs bileti rezervasyon ve satış sistemi
  - Bir yolcunun gitmek istediği sefere ait otobüsü ve bu otobüsteki koltuğu seçtiği, seçimlerin rezervasyon bilgisi olarak kaydedildiği bir sistem tasarlanır (ekrandan, 00:15:00).
  - Kullanım senaryosu "Otobüs Bileti Alımı": birincil aktör Yolcu, diğer ilgili Bilet Satış Sistemi. Ön koşul: sisteme tüm sefer bilgileri girilmiştir. Son koşul: yolcu biletini satın almıştır.
  - Ana senaryo beş adımdır: sefer bilgisi girilir ve seferler gösterilir, otobüs seçilir, koltuk seçilir ve uygunluğu kontrol edilir, rezervasyon bilgileri girilir ve koltuk rezerve işlenir, ödeme yapılır ve bilet sisteme işlenir.
  - Alternatifler: seçilen koltuk doluysa sistem yeni koltuk seçilmesini ister; rezervasyon yapılıp ödeme 12 saatlik süre içinde yapılmazsa rezervasyon iptal edilir ve koltuk yeniden boş işaretlenir.
  - Aynı senaryo için dört UML şeması çizildi: sınıf, sıralama (sequence), etkinlik (activity) ve durum (state) şeması. Araç Violet UML Editor'dür.
- Tasarım sınıf şeması
  - Analiz aşamasındaki sınıf şemasında sınıf adı, nitelikler ve ilişkiler yeterliydi. Tasarım aşamasında metotlar da (nesnenin yapabildiği işler) parametre ve dönüş tipleriyle yazılır.
  - Sınıflar: Yolcu, RezervasyonEkranı, Sefer, Otobüs, Koltuk, Rezervasyon, Ödeme.
  - Üye alanlar private (`-`), metotlar public (`+`) gösterilir.
  - Otobüs ile Koltuk arasında bileşim (composition) ilişkisi vardır; dolu elmas Otobüs tarafındadır.
- Sıralama şeması
  - Rezervasyon yapma işlemi için nesnelerin hangi metotları hangi sırayla çağırdığı gösterildi.
  - Nesne yaşam çizgileri (object lifeline), etkinlik çubukları (activation bar), çağrı mesajları ve kesikli dönüş mesajları kullanıldı.
- Etkinlik şeması
  - Rezervasyon yapma işleminin eylemleri, karar düğümü (sefer var mı?) ve eş zamanlama çubukları (çatallanma ve birleşme) ile gösterildi.
- Durum şeması
  - Bir Koltuk nesnesinin durumları (Boş, Rezerve, Biletlendi) ve aralarındaki geçişler gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Analiz ve tasarım sınıf şeması farkı
  - Analizde metot ayrıntısı gerekmez; tasarım bir sonraki ve daha ayrıntılı aşamadır, metotlar parametre ve dönüş tipleriyle yazılır.
- Tip seçimi anlamlı olmalı
  - T.C. kimlik numarası sayısal işlem yapılmayacağı için String tutulur. Koltuk numarası "1A", "1B" gibi harf içerebildiği için String olur. Rezervasyon numarası da harf içerebileceği için String verilir.
- Bileşim ilişkisi
  - Koltuk tek başına var olamaz, otobüsün parçasıdır; bu yüzden en kuvvetli ilişki olan bileşim kullanılır. Dolu elmas "bir" tarafında (Otobüs), çok tarafı düz çizgidir.
- Sıralama şemasında sıra
  - Mesajların sırası şaşmamalıdır; örneğin otobüs seçimi sefer aramasından önce yazılamaz. Okunabilirlik için mesajları 1, 2, 3, ... diye numaralamak iyi bir alışkanlıktır.
- İsimsiz nesne gösterimi
  - Nesnenin adı akışta kullanılmayacaksa yalnız `:SınıfAdı` yazılır; bu, o sınıftan adı belirtilmemiş bir nesne anlamına gelir.
- Etkinlik şemasında eş zamanlama
  - İkisi de tamamlanmadan sonraki adıma geçilmeyecek işler çatallanma ve birleşme çubuklarıyla gösterilir.

## Kısa Tekrar Notları

- Tasarım sınıf şeması = nitelikler + metotlar (parametre ve dönüş tipleriyle) + ilişkiler ve çokluklar.
- Getter/setter metotları üye alanlardan türetilir; örnekte yalnız bir kısmı yazıldı.
- Sefer → Otobüs: 1'e 1. Otobüs ◆— Koltuk: 1'e çok, bileşim.
- Yolcu → RezervasyonEkranı: 1'e çok. RezervasyonEkranı → Sefer: 1'e çok. RezervasyonEkranı → Rezervasyon: 1'e 0..1. Rezervasyon → Ödeme: 1'e 1.
- Ödeme yapılmadıysa Rezervasyon içindeki ödeme alanı null'dır.
- Kendi sınıfının metodunu çağıran nesne, sıralama şemasında kendine dönen bir çağrı oku ile gösterilir (`gosterSeferBilgileri(sefer)`).
- Sıralama şeması tek bir işlemi gösterir; ödeme gibi başka işlem ya aynı şemada devam ettirilir ya da ayrı şemayla çizilir.
- Etkinlik şeması: başlangıç noktası, eylemler, karar elması (koşul etiketiyle), eş zamanlama çubukları, bitiş noktası.
- Durum şeması: bir sınıfın nesnesinin bulunabileceği durumlar ve geçiş olayları.
- Koltuk durumları: Boş → Rezerve → Biletlendi; ödeme yapılmazsa Rezerve → Boş.

## Detaylı Açıklamalar

Bu derste bir uygulama sorusu üzerinden dört UML şeması çizildi. Senaryo bir otobüs bileti rezervasyon ve satış sistemidir. Yolcu gitmek istediği yeri ve tarihi girer, sistem uygun seferleri listeler, yolcu otobüsü ve boş koltuklardan birini seçer, iletişim bilgilerini girerek rezervasyon yapar ve ödeme yaptığında bilet kesinleşir. Ödeme belirlenen 12 saatlik süre içinde yapılmazsa rezervasyon iptal edilir ve koltuk yeniden boşa çıkar. <!-- BELİRSİZ: 12 saatlik sürenin sefere 12 saat kalana kadar mı yoksa rezervasyondan sonraki 12 saat mi olduğu altyazıda net değil; alternatif senaryo metni karede görünmüyor. -->

Tasarım sınıf şemasında (ekrandan, 00:40:00) sınıflar şöyledir:

- Yolcu: `ad`, `soyad`, `tcNo`, `iletisimBilgileri` (String); `getAd()`, `getSoyad()`, `getTcNo()`, `getIletisimBilgileri()`.
- RezervasyonEkranı: `seferler: Sefer[]`; `seferAra(gidis, varış: String, gun: Date): boolean`, `gosterSeferBilgileri(sefer: Sefer): void`, `otobusSec(busX: Otobus): void`, `koltukSec(koltukY: Koltuk): void`.
- Sefer: `çıkışYeri`, `varışYeri` (String), `tarih: Date`, `otobüs: Otobüs`; kurucu `Sefer(çıkış, varış, tarih, otobüs)` ve `seferBilgileriniAl(): Sefer`.
- Otobüs: `plaka`, `sofor` (String), `koltuklar: Koltuk[]`; `getPlaka()`, `getSofor()`. Sıralama şeması çizilirken buna `bosKoltuklariListele()` metodunun da eklenmesi gerektiği fark edildi.
- Koltuk: `koltukNo`, `koltukTipi` (String), `boslukDurumu: boolean`; getter'lar ve `setBoslukDurumu(boolean): void`.
- Rezervasyon: `rezervasyonNo: String`, `odeme: Odeme`; `rezervasyonYap(yolcu, sefer, koltuk)`, `odemeYap(rezervasyonNo: String): void`.
- Ödeme: `odemeTarihi: Date`, `odemeTutari: double`; `odemeAl(): void`.

Sıralama şemasında (ekrandan, 00:55:00) akış şöyledir: yolcu `:RezervasyonEkranı` üzerinde `seferAra(parametreler)` çağırır ve `true` döner. Ekran `sefer` nesnesinden `seferBilgileriniAl()` ile seferi alır ve kendi `gosterSeferBilgileri(sefer)` metodunu çağırır. Yolcu `otobusSec(busX)` ile otobüsü seçer; ekran `busX` üzerinde `bosKoltuklariListele()` çağırır, otobüs her koltuğa `getBoslukDurumu()` sorar ve boşluk bilgisi gelir, ekrana koltuk bilgileri döner. Yolcu `koltukSec(koltukY)` ile koltuğu seçer; ekran `:Rezervasyon` üzerinde `rezervasyonYap(yolcu, sefer, koltukY)` çağırır ve rezervasyon onayı döner.

Etkinlik şemasında (ekrandan, 01:05:00) akış: Yolcu Sisteme Girer → Yolcu Sefer Bilgilerini Girer → Sistem Seferleri Kontrol Eder → karar "Sefer var mı?" (Yok ise sefer bilgisi girişine geri dönülür, Var ise devam) → Yolcu Otobüs Seçer → Boş Koltuk Bilgileri Yolcuya Verilir → çatallanma: Yolcu Koltuk Seçer ve Yolcu İletişim Bilgilerini Girer → birleşme → Rezervasyon Yapılır → Yolcu Rezervasyonu Onaylar → bitiş.

Durum şemasında (ekrandan, 01:10:00) Koltuk nesnesi başlangıçtan "Yolcu otobüs seçer ve boş koltukları görüntüler" geçişiyle Boş durumuna gelir. "Yolcu koltuk seçti ve iletişim bilgisini girdi" ile Rezerve olur. "Yolcu ödeme yaptı" ile Biletlendi durumuna geçer ve "Koltuk başkasına verilemez" ile senaryo biter. Rezerve durumundayken "Yolcu 12 saate kadar ödeme yapmaz" olursa koltuk Boş durumuna döner.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
