# Ders 13 Çalışma Özeti

## Genel Konular

- Kayıt 24 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 1 saat 38 dakika sürüyor.
- Ders, dönem projesi sunumlarının ilk günü. Konu anlatımı yok. Bu hafta gönüllü dört grup sundu.
- Sunulan projeler, dönem başında verilen üç vaka üzerine kurulu:
  - Bir medya takip şirketi için bilgi sistemi: medya organlarını izleme, müşteriye günlük/haftalık/aylık ve özel rapor, anket hizmeti.
  - Bir yazılım evinin insan kaynakları sistemi: çalışanları projelere atama, maaş ve tazminat hesabı, işten çıkarma.
  - Bir seyahat acentesi için bilet ve tatil sistemi: ulaşım bileti, otel rezervasyonu, puan kazanma, farklı ödeme yöntemleri.
- Her sunumda proje planı (alan tanımı, kabuller ve kısıtlar, Gantt diyagramı, ekip organizasyonu, risk tablosu), gereksinim modelleme, nesneye dayalı modelleme ve tasarım diyagramları ile birim testleri anlatıldı.
- Hoca sunumlar sırasında sorular sordu ve geri bildirim verdi. Bu özet, projelerin ortak içeriğini ve hocanın geri bildirimlerini adsız olarak toplar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Grubun **bütün üyeleri** sunumda bulunmalı. Hoca her sunumdan önce üyeleri tek tek yokladı ve herkesin hangi işi yaptığını sordu.
- **Kabuller ve kısıtlar ayrı ayrı** yazılmalı. Kabuller genellikle olumlu varsayımlardır. Kısıtlar problemdeki, sistemdeki veya projedeki sınırlamalardır.
- Kısıt yazarken gerekçe verilmeli. Örneğin "proje Java ile yazılmalıdır" yerine "grup üyelerinin en iyi bildiği dil Java'dır" ya da "bu sisteme en uygun dil Java'dır" gibi bir ifade daha doğru.
- Risk tablosunda hangi risklerin takip edileceği belirlenmeli: etkisi büyük ve olasılığı yüksek (veya orta-yüksek) riskler takip edilir, düşük olanlar ihmal edilebilir. Bunun için bir eşik konabilir.
- Her geliştirici yazdığı birimin **birim testini** kendisi yazmalı.
- Rapor diyagram yığını olarak değil, aşamalara göre düzenlenmeli:
  - Gereksinim analizi bölümü: kullanım durumu (use case) diyagramı, kullanım senaryosu belgesi, varsa kavramsal sınıf diyagramı.
  - Tasarım bölümü: sıralama, durum ve etkinlik diyagramları ile tamamlanmış UML sınıf diyagramı.
- Sıralama (ardışıl) diyagramında nesneler genellikle aynı hizada, üstte yatay olarak dizilir.
- Not sunum, rapor ve demo notlarının birleşiminden oluşur.

## Kısa Tekrar Notları

- **Proje planında beklenenler:** alan (kapsam) tanımı, kabuller, kısıtlar, iş-zaman çizelgesi (Gantt), süreç modeli, ekip organizasyon şeması ve görev dağılımı, risk tablosu (olasılık, etki, düzey, önlem).
- **Gereksinim modelleme:** use case diyagramı, her işlev için kullanım senaryosu metni (ilgililer ve beklentileri, ön koşul, son koşul, ana senaryo, alternatif akış), izlenebilirlik tablosu (traceability matrix).
- **Use case ilişkileri:** `include` her seferinde çalışan zorunlu alt işlev (ör. sisteme giriş), `extend` koşula bağlı ek işlev (ör. özel ücretlendirme).
- **İzlenebilirlik tablosu:** satırlarda gereksinimler, sütunlarda bunları gerçekleyen sınıflar, modüller veya menüler.
- **Tasarım:** tasarım sınıf diyagramı (metotlarla), sıralama, etkinlik ve durum diyagramları.
- **Sınıf diyagramında kesikli ok:** bağımlılık (dependency). Bir sınıf diğerini nitelik olarak tutmuyor, yalnızca bir metodunda kullanıyor veya örneğini oluşturuyorsa kullanılır.
- **Birim testi örnekleri:** veritabanı bağlantısının kurulması, kayıt ekleme ve silme, eksik veya hatalı girişte uyarı verilmesi, cüzdan bakiyesi yetersizse ödemenin reddedilmesi, puan hesabının doğruluğu.

## Detaylı Açıklamalar

### Sunum düzeni ve işleyiş

- Bu hafta gönüllü gruplar sundu. Kalan gruplar gelecek hafta sunacak.
- Programın çalıştırılması (demo) ve kodla ilgili sorular bu sunumların parçası değil. Bunlar için asistan pazartesi öğleden sonra ayrı bir online oturum açacak. Oturum adresi asistanın AVESİS sayfasında paylaşılacak; gerekirse hoca OBS'den de gönderecek.
- Demo oturumu sunum yapan ve yapmayan bütün gruplar için. "Sunum yapmadık, bize ayrı gün verilecek" diye düşünülmemeli.
- Kodlar için sistemde ayrı bir ödev açılacak. Gruptan bir kişi kodu oraya yükleyecek; e-postayla göndermede sorun yaşandığı için bu yol seçildi. Süre pazartesiye kadar.
- Ödev dokümanına göre rapor ve kod ayrı ayrı yükleniyor.

### Proje planı bölümünde görülenler

- Gantt diyagramları Google Sheets şablonu, Excel veya online Gantt araçlarıyla çizildi. Hoca her grupta Gantt'ın nerede çizildiğini ve hangi süreç modelinin seçildiğini sordu.
- Gruplar çoğunlukla şelale (waterfall) modelini kullandı. Bir grubun iş akışı: alan tanımı, kabul ve kısıtlar, risk tablosu; use case diyagramı ve senaryoları; sınıf diyagramları; sıralama, etkinlik ve durum diyagramları; arayüz tasarımı ve kodlama; birim testleri; rapor.
- Ekip organizasyonunda proje yöneticisi, analist, yardımcı analist, geliştirici ve test eden rolleri dağıtıldı.
- Risk tablosu örnekleri: veri kaybı (olasılık düşük, etki çok yüksek), zaman baskısı, bütçe kısıtları, personel eksikliği, kullanılan kütüphanelerin güncel olmaması.

### Gereksinim analizi bölümünde görülenler

- Use case diyagramlarında genellikle tek bir ana aktör (müşteri veya kullanıcı) ve onun işlevleri vardı. Seyahat acentesi projesinde müşteri, acente görevlisi ve dış sistemler (otel sistemi, seyahat firması sistemi) aktör olarak alındı.
- Kullanım senaryosu metinlerinde ilgililer ve beklentiler, ön ve son koşullar, ana senaryo ve alternatif akış yazıldı.
- Bir grup UML diyagramları için Violet UML Editor kullandı. Hoca diğer gruplara da bu aracı kullanan olup olmadığını sordu.

### Tasarım bölümünde görülenler

- Medya takip projesinde ana menü (main GUI), anket arayüzü, kaynak ekleme arayüzü, rapor ve medya türleri için enum tipleri ve veritabanı işlemleri sınıfı vardı.
- Hoca bir sınıf diyagramındaki kesikli bağlantıların anlamını sordu. Cevap: bağlantılı sınıf nitelik olarak tutulmuyor, metot içinde örneği oluşturuluyor; bu bir bağımlılık ilişkisidir.
- İK projesinde arayüz sınıfları dışarıda bırakılıp yalnızca alan sınıfları (yönetici, çalışan, takım, proje) çizildi.
- Seyahat acentesi projesinde cüzdan bakiyesi, kredi kartı, çek ve nakit ödeme, bilet ve rezervasyon akışları etkinlik diyagramıyla gösterildi.

### Test bölümünde görülenler

- Birim testleri kişi başına bölüştürüldü ve herkes kendi biriminin testini yazdı.
- Hoca bu durumu olumlu buldu. Testlerin derste gösterilmeyen bir araçla yapıldığını, grupların bu konuda kendi araştırmasını yaptığını belirtti.
- Hoca kullanıcı testi yapılıp yapılmadığını da sordu. Grup kullanıcı testinin derste işlenmediğini, bu yüzden uygulamadığını söyledi.

### Duyurular

- Gelecek hafta saat 09:00'dan itibaren kalan bütün gruplar sunacak.
- Sınavların online yapılacağı kesinleşti; sınav programındaki tarihler değişmiyor. (Ders 11'de finalin yüz yüze olacağı söylenmişti.)
- Ders sonunda hoca bir mazeret işlemiyle ilgili gelecek hafta ders saatinde (10:30 civarı, sorun olursa 12:00) başlatılacak online bir uygulamadan söz etti. Altyazıda bu kısım net değil.
- Uygulama dersi (ders 12) aslında proje tesliminden önce planlanmıştı ama programdaki değişiklik yüzünden teslimden sonraya kaldı.

### Ders sonrası notlar

- Altyazıdaki "100 kez diagramı" use case diyagramı, "artificial diagram" ardışıl (sıralama) diyagramı, "Violet Yönertis/biyolet" ise Violet UML Editor demektir.
- Sıralama diyagramında nesneler genellikle üstte aynı hizada başlar. Ancak bir nesne etkileşim sırasında yaratılıyorsa (`create` mesajı) kutusu yaratıldığı noktada çizilebilir; bu durumda farklı hiza UML'ye uygundur.
- Bağımlılık (dependency), ilişki (association), toplama (aggregation) ve bileşim (composition) farklı çizgilerle gösterilir. Bağımlılık kesikli ok ile çizilir ve en zayıf ilişkidir.
- Kabul ile kısıt arasındaki ayrım: kabul, doğruluğu kanıtlanmadan varsayılan koşuldur (ör. "fiyatlar süreç boyunca değişmez"). Kısıt, çözümü sınırlayan koşuldur (ör. "yalnızca kredi kartıyla ödeme").

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
