# Ders 9 Çalışma Özeti

## Genel Konular

- Ara sınavın değerlendirilmesi ve yol haritası (roadmap) sorusunun doğru cevabı.
- 1. makale sunumu: çevik (agile) yazılım projelerinde proje yöneticisinin hâlâ var olup olmadığı üzerine bir anket çalışması.
- 2. makale sunumu: Monte Carlo simülasyonuna dayalı yazılım projesi zaman yönetimi.
- 11 Mayıs 2021 haftası için idari izin duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınav notları genel olarak 70 ile 100 arasında. Liste henüz yayınlanmadı.
- Öğrencilerin çoğu "proje yönetiminde hangi adımlar vardır" (roadmap) sorusunda takıldı. Birçoğu bu soruya proje planının maddelerini yazdı. Oysa soru proje yönetiminin aşamalarını soruyordu.
- Hoca iki sunumu da iyi buldu ve sonraki hafta sunacaklara örnek olduğunu söyledi.

## Kısa Tekrar Notları

- Proje yönetimi yol haritası (sınavdaki doğru cevap):
  1. Hazırlık: projenin anlaşılması (understanding) ve tanımlanması (defining).
  2. Planlama.
  3. Yürütme ve izleme: kilometre taşlarında planla uyumlu gidilip gidilmediği kontrol edilir, plan revize edilir.
  4. Kapanış: projeyle ilgili büyük olasılıkla know-how (altyazıda "navha") oluşturulur.
- Scrum'da proje yöneticisi unvanı yoktur. Yerine ürün sahibi (Product Owner) ve Scrum Master rolleri vardır.
- XP'de koç (coach) rolü, geleneksel proje yöneticisine en çok benzeyen roldür.
- PERT beklenen süresi: $t_e = \dfrac{t_o + 4t_m + t_p}{6}$, standart sapma: $\sigma = \dfrac{t_p - t_o}{6}$.
- Monte Carlo simülasyonu: olasılık dağılımlarından rastgele sayılarla çok sayıda tekrarlı hesap yaparak sonucun dağılımını bulur.
- Simülasyon sayısı arttıkça sonuçlar kararlı bir değere yaklaşır.

## Detaylı Açıklamalar

### Ara sınav değerlendirmesi

- Hoca sınav kâğıtlarını okudu ve genel olarak iyi buldu.
- Literatürle ilgili sorular da vardı.
- Asıl sorun yol haritası sorusundaydı. Bir öğrenci de bu sorunun cevabını e-postayla sordu. Hoca cevabı herkese derste verdi:
  - Önce projeye hazırlık: anlama ve tanımlama aşamaları.
  - Sonra projenin planlanması.
  - Sonra projenin yürütülmesi ve izlenmesi. Örneğin yazılım geliştirirken belli aşamalarda, genelde kilometre taşlarında, "planla eş güdümlü gidiyor muyuz?" diye sorulur. Plan revize edilir veya plana uygun gidilmeye çalışılır.
  - En sonda projenin kapatılması ve projeyle ilgili büyük olasılıkla know-how'ın (altyazıda "navha") oluşturulması.
- Diğer sorularda bazı öğrencilerin kişisel eksik veya hataları oldu.

### 1. sunum: Çevik projelerde proje yöneticisi hâlâ var mı?

- **Makale:** "Does the Project Manager Still Exist in Agile Software Development Projects?" Yeni Zelanda'daki bir üniversiteden (altyazıda "Otland", büyük olasılıkla Auckland) üç araştırmacı. 2016, 23. Asya-Pasifik Yazılım Mühendisliği Konferansı (APSEC).
- **Arka plan:**
  - Çevik proje yönetimi değişime açık, artımlı ve yinelemeli bir yaklaşımdır. Temeli 2001'deki Çevik Yazılım Geliştirme Manifestosu ile atıldı.
  - Kendi kendini örgütleyen takımlar ve müşteri iş birliği gibi ilkelerle değişen gereksinimlere hızlı yanıt vermeyi hedefler.
  - Çevik yöntemler: DSDM (dinamik sistem geliştirme), özellik güdümlü geliştirme (Feature Driven Development), Extreme Programming (XP), Scrum.
  - Sektör araştırmalarına göre katılımcıların %75'i Scrum veya Scrum hibriti kullanıyor.
  - Scrum etkinlikleri: kullanıcı öyküleri, ürün biriktirme listesi (product backlog), günlük Scrum, sprint inceleme ve sprint planlama toplantıları.
- **Proje yöneticisinin rolü:**
  - Geleneksel (örneğin şelale) takımlarda proje yöneticisi merkezîdir ve yapı hiyerarşiktir.
  - Beklenen özellikler: liderlik, ekip oluşturma, motivasyon, iletişim, etkileme, karar verme, planlama, koçluk.
  - Çevik takımlarda karar yetkisi ekip ile yönetici arasında dengeli dağılır. Takımlar görevlerini kendileri seçer.
  - Scrum ve XP'de proje yöneticisi unvanı teoride kaldırılmıştır.
  - Scrum: ürün sahibi müşteriyi temsil eder ve ürün özelliklerini önceliklendirir. Scrum Master ekibin işleyişini kolaylaştırır ve önündeki engelleri kaldırır.
  - XP rolleri: koç, danışman, izci (tracker), programcı, müşteri, test eden, büyük patron. Koç sürecin sahipliğini ve takıma rehberliği üstlenir.
- **Araştırma sorusu:** Proje yöneticisi unvanı teoride kalktı. Pratikte sektörde de durum böyle mi?
- **Yöntem:** 31 ülkeden 97 katılımcıyla Google Forms üzerinden çevrim içi anket.
  - Demografik sorular: ülke, sektör, yaş grubu, toplam iş deneyimi, çevik ve geleneksel projelerdeki deneyim.
  - Asıl sorular: iş unvanı, kullanılan yöntem, ekip büyüklüğü, proje yöneticisi var mı, yoksa ekibi kim yönetiyor, ekip aynı yerde mi yoksa dağıtık mı çalışıyor.
- **Bulgular:**

| Konu | Sonuç |
|---|---|
| Ülkeler | ABD %29, Hindistan %13, Hollanda %5, Kanada/Almanya/Birleşik Krallık %4'er, diğer 25 ülke |
| Sektörler | Finans ve bankacılık %17, bilgi teknolojileri %15, sağlık %13, telekomünikasyon %7, yazılım %6, diğer %37 |
| Toplam deneyim | 10-20 yıl %44, 20 yıl üstü %33, 5-10 yıl %12, 0-5 yıl %10 |
| Çevik deneyim | 0-5 yıl %65, 6-10 yıl %29 |
| Ekip büyüklüğü | 5-10 kişi %39, 10-15 kişi %23, 25 üstü %15, 0-5 kişi %13 |
| İş unvanı | Proje yöneticisi %24, Scrum Master %11, çevik koç %4, diğer (CEO, ürün sahibi, kalite güvence vb.) |
| Projede proje yöneticisi var mı | Evet %67, Hayır %33 |
| Çalışma şekli | Dağıtık %55, aynı yerde %45 |
| Yöntem | Yalnız çevik %58 (Scrum %49, Kanban %2), çevik + bir yöntem hibrit %19 (en çok Scrum + Kanban %8), ikiden fazla yöntem hibrit %23 (en çok Scrum + Kanban + XP) |

- **Sonuçlar:**
  - Ekip büyüklüğü ile proje yöneticisi varlığı arasında ilişki var. 5-10 kişilik ekiplerde proje yöneticisi bulunma olasılığı 5'ten küçük ekiplerden çok daha yüksek. 25 ve üstü ekiplerde de olasılık yüksek.
  - Bu bulgu, Scrum için literatürde önerilen 3-9 kişilik ideal takım büyüklüğüyle büyük olasılıkla çelişiyor (altyazıda "gelişmekte").
  - Olası neden: birçok kurum ekip düzeyinde çevik yöntem kullanırken ekip üstünde geleneksel proje yönetimini sürdürüyor.
  - 20 kişilik bir ekip üzerine yapılan bir çalışmada proje yöneticisi, uzmanların katılımını teşvik ederek ekibin işleyişini kolaylaştırmış.
  - Dağıtık ekiplerde proje yöneticisi daha sık bulunuyor. Bunun nedeni koordinasyon ihtiyacı olabilir.
- Sunuma soru gelmedi.

### 2. sunum: Monte Carlo simülasyonuna dayalı yazılım projesi zaman yönetimi

- Sunan öğrenci bir referans makaleye ek olarak birkaç kaynak daha inceledi. Sektörde 3,5 yıllık deneyimi var: 2 yıl test uzmanı, 1,5 yıl yazılım geliştirici.
- **Motivasyon:**
  - Yazılım sektörü büyüdükçe rekabet artıyor. Kötü planlanan projelerin başarı oranı düşük. Bu durum şirketler üzerinde ekonomik baskı yaratıyor.
  - Yazılım projelerinde her aşamanın süresi belirsizdir. Örneğin ekibin deneyimine ve kurumda o yazılım türüyle ilgili birikim (know-how) veya kayıtlı metrik olup olmamasına bağlıdır.
  - Sistem karmaşık ve süreç doğrusal olmadığı için süre tahmini için doğru bir matematiksel model kurmak zordur.
- **Monte Carlo yöntemi:**
  - 1940'larda Stanisław Ulam tarafından geliştirildi.
  - Stokastik problemleri tekrarlanan istatistiksel deneylerle çözer. Bir tür sayısal simülasyondur.
  - Bir olayın olasılığı veya rastgele bir değişkenin beklenen değeri, deneysel sıklık veya ortalamayla yaklaşık bulunur.
  - Risklerin zaman ve maliyet üzerindeki etkisini analiz etmek için kullanılabilir.
  - Proje yöneticisinin deneyimi ve tercihi gibi öznel faktörlere bağımlılığı azaltır. Projenin belirli bir sürede tamamlanma olasılığını verir.
- **PERT ile ilişkisi:**
  - PERT, geçmiş veri yokken büyük ve karmaşık projelerde süre tahmini için kullanılan istatistiksel bir yöntemdir. Zaman faktörü maliyetten önemliyse tercih edilir.
  - Elverişli, elverişsiz ve olağan koşullar için üç süre tahmini ağırlıklı ortalamayla birleştirilir.
- **Önerilen adımlar:**
  1. Proje görevlere ayrılır. Her görev için iyimser, kötümser ve en olası süre tahmin edilir.
  2. Her görev için $t_e$ ve standart sapma hesaplanır, uygun bir olasılık dağılımı seçilir.
  3. Olasılık dağılımına göre rastgele sayılarla çok sayıda tekrarlı hesap yapılır. Makalede sözde rastgele (pseudo-random) sayılar Python ile üretildi.
  4. Sonuçlardan en küçük ve en büyük süre, beklenen değer, standart sapma, her günün olasılığı ve kritik yol olasılığı elde edilir.
- **Örnek durum: küçük bir insan kaynakları yönetim sistemi**
  - Proje 6 adıma ayrıldı: proje planlama, gereksinim analizi, tasarım, kodlama, test, kabul.
  - Her adım için iyimser, kötümser ve en olası süre tablosu çıkarıldı. PERT ağından iki aday kritik yol bulundu:

| Yol | İyimser | Kötümser | Ortalama |
|---|---|---|---|
| Yol 1: A-B-C-D-F | 112 gün | 176 gün | yaklaşık 144-146 gün |
| Yol 2: büyük olasılıkla A-B-C-E-F (altyazıda A-B-C-F) | 92 gün | 142 gün | yaklaşık 117 gün |

  - Gerekli simülasyon sayısı, projenin standart sapması ve izin verilen hataya bağlı bir formülle bulunur. Öğrenci değerleri Excel'de hesaplayınca $n \approx 12.845$ çıktı. Makalede 25.000 simülasyon koşuldu. Önemli olan hesaplanan $n$'den fazla simülasyon yapmaktır.
  - Simülasyon sonucunda beklenen proje süresi 174 gün olarak verildi. Kritik yol %97,71 olasılıkla Yol 1 (A-B-C-D-F) çıktı.
  - Kritik yolda olmayan E aktivitesi (test) de göz ardı edilmemeli. Proje yürürken bilinmeyen durumlar ve riskler ortaya çıkabilir.
  - Simülasyon sayısı arttıkça sonuç grafiği düzgünleşiyor ve sabit bir değere yaklaşıyor.
- **Dikkat edilecekler:**
  - Simülasyon için yine başlangıç değerleri, yani üç süre tahmini gerekir. Tahminlerin kalitesi sonucu belirler. Sözde rastgele sayıların referans değerleri proje ekibinin tahminleridir.
  - Hesap tek bir aktivite için değil, tüm aktiviteler için yapılmalı.
  - Risk değerlendirmeleri eksiksiz tamamlanmış olmalı.
- **Faydalar:**
  - Zaman açısından proje risklerini değerlendirmeye yardım eder.
  - Zaman ve maliyet aşımlarını önceden görmeyi sağlar.
  - Gerçekçi bütçe ve zaman çizelgesi hazırlanmasını sağlar.
  - Risk yönetimi için yönetim desteği almayı kolaylaştırır.
  - Gerçekçi verilerle karar vermeyi destekler, kilometre taşlarına ulaşma olasılığını artırır.
- **Öğrencinin sektör gözlemi:**
  - Gereksinim analizi ve geliştirmedeki gecikmeler birbirinin üstüne biner. Teslim günü değişmediği için gecikme hep teste itilir.
  - Test geç başlar ama süresi sabit kalır. Hatalar gözden kaçar, metriklere ulaşılamaz ve kalite düşer.
  - Bu yüzden zaman yönetiminin iyileştirilmesi çok önemlidir. Öğrenci Monte Carlo yöntemini bunun için umut verici buluyor ama tahmin kalitesi konusunda daha fazla çalışma gerektiğini düşünüyor.

### Duyurular

- Bir öğrenci sonraki hafta sunum yapmak istedi. Hoca listeye ekledi.
- Bir öğrenci sonraki hafta için çıkan idari izin kararını sordu. Başka bölümden bir öğrenci, kendi bölüm hocasının pazartesi-salı idari izin nedeniyle dersi iptal ettiğini söyledi.
- Hoca durumu bölüme sorup herkese toplu e-posta atacağını söyledi. Bu nedenle 11 Mayıs 2021 dersinin yapılmamış olması muhtemel (o haftanın kaydı arşivde yok).

### Ders sonrası notlar

- Altyazıdaki "Otland Üniversitesi" büyük olasılıkla Auckland Üniversitesi, "Ecail/Ejail/Eceal" çevik (agile), "Montecorji/mantıkarlı/muantekar" Monte Carlo, "Stanislav Yulam" Stanisław Ulam olmalı. Altyazıda "hüküter bilim insanı" diye geçen ifade anlaşılmıyor. Ulam Polonya asıllı ABD'li bir matematikçidir.
- 1. sunumda "%55 uzaktan çalışmıyor" ifadesi geçiyor. Sunumun devamına göre doğrusu: %55'i dağıtık (bir arada çalışmayan) ekip, %45'i aynı yerde çalışan ekip.
- 2. sunumda Yol 1'in ortalaması yaklaşık 144-146 gün olarak verildi. Simülasyonun beklenen süresi ise 174 gün olarak söylendi. Bu iki değer altyazıdaki hâliyle tutarlı görünmüyor; 174 gün kötümser değere (176) çok yakın. Kesin değerler makaledeki tablodan kontrol edilmeli.
- Sunumda "rastgele sayılar yerine yüksek benzerliğe sahip sözde rastgele sayılar" deniyor. Bilgisayarda üretilen rastgele sayılar zaten sözde rastgeledir; bu bir seçenek değil, olağan durumdur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
