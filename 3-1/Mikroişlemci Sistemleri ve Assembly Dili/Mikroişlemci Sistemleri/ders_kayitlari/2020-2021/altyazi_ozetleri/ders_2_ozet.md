# Ders 2 Çalışma Özeti

## Genel Konular

- 8086 Bacak (Pin) Bağlantıları ve Tanımları
  - 8086 mikro işlemcisi 40 pin'e sahip bir entegredir. Bu pinler adres, veri ve kontrol sinyallerini taşır. Bacak tanımlarının öğrenilmesi, çevre birimleriyle programlama yapabilmek için temel zorunluluktur çünkü tüm entegre bağlantıları bu pinler üzerinden gerçekleştirilir.
- Adres ve Veri Yollarının Çoklanmış (Multiplexed) Yapısı
  - 8086'da 20 adres ucu ve 16 veri ucu ayrı ayrı ayrılmamıştır; bunun yerine AD0-AD15 pinleri adres ve veri için ortak kullanılır (multiplexed/multishare yapı). A16-A19 pinleri ise sadece adres için ayrılmıştır. Bu yapı 40 pin sınırından kaynaklanmaktadır. Ortak kullanım nedeniyle adres bilgisi önce gönderilip latch'lenmeli, ardından veri gönderilmelidir.
- ALE (Address Latch Enable) Bacagı
  - ALE pini, ortak kullanılan AD0-AD15 hatlarının o an adres mi yoksa veri mi taşıdığını karşı tarafa bildiren kontrol sinyalidir. ALE = 1 olduğunda hat üzerinde adres bilgisi vardır; ALE = 0 olduğunda veri bilgisi vardır. Karşı taraftaki latch devreleri (74273 gibi) ALE'nin düşen kenarında adresi yakalayıp tutar. Bu sayede adres sabit kalırken veri yolundan veri aktarımı yapılabilir.
- READ ve WRITE Kontrol Bacakları
  - READ (okuma) ve WRITE (yazma) bacaları, mikroişlemcinin bir bellek veya I/O birimine veri yazıp yazmayacağını veya oradan veri okuyup okumayacağını belirler. Bu sinyaller hedef birimin enable ucunu tetikler. WRITE = 0 (aktif düşük) olduğunda yazma, READ = 0 olduğunda okuma işlemi gerçekleşir.
- MN/MX (Mode Selection) Bacagı
  - MN/MX pini mikroişlemcinin çalışma modunu belirler. Minimum mode'da (MN/MX = 1) 8086 tek başına kontrol sinyallerini üretir ve ders kapsamında genelde bu mod kullanılır. Maximum mode'da ise bazı kontrol sinyalleri harici bir denetleyici (8288) üzerinden sağlanır.
- INTR ve NMI (Interrupt) Bacakları
  - INTR (Interrupt Request): Programlanabilir kesme isteği girişidir. Interrupt Enable Flag (IF) açık olduğunda dışarıdan gelen kesme isteklerini kabul eder. NMI (Non-Maskable Interrupt): Maskelenemez kesme girişidir; IF durumuna bakılmaksızın her zaman kabul edilir. Kritik durumlarda (örneğin acil durdurma) kullanılır.
- BHE (Bus High Enable) Bacagı
  - BHE pini, 16 bitlik veri yolunun üst 8 bitinin (D8-D15) aktif olup olmadığını kontrol eder. BHE = 0 olduğunda üst 8 bitlik veri yolu aktiftir. Bu pin, 8 bitlik çevre birimlerinin 16 bitlik veri yoluna bağlanmasında kritik rol oynar: İlk cycle'da BHE=0 ile üst 8 bit, ikinci cycle'da BHE=1 ile alt 8 bit aktarılır.
- DT/R (Data Transmit/Receive) ve IO/M Bacakları
  - DT/R: Veri yönünü belirler. DT/R = 1 ise veri gönderme (transmit), DT/R = 0 ise veri alma (receive) anlamına gelir. IO/M: İşlemin I/O mu yoksa bellek (memory) mi olduğunu belirtir. IO/M = 0 ise I/O, IO/M = 1 ise bellek erişimi yapılır.
- Input-Output ve Memory Arasındaki Fark (Isolated vs Mapped)
  - Mikroişlemci dış dünyayla iletişim kurarken iki yöntem kullanır: Memory mapped (bellek haritalı) ve I/O isolated (ayık I/O). IO/M sinyali ile hangi tür erişim yapılacağı belirlenir. Aynı adres uzayında hem bellek hem I/O birimi bulunabilir; ancak IO/M ve A0 sinyalleri farklı kombinasyonlarla enable sinyalleri üretilerek çakışma önlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- ALE sinyalinin çoklanmış (multiplexed) yapılarda adres ve verinin ayrıştırılması için hayati öneme sahip olduğu vurgulanmıştır. ALE olmadan karşı taraf hat üzerindeki bilginin adres mi veri mi olduğunu bilemez.
- BHE pininin 8 bitlik çevre birimlerini 16 bitlik veri yoluna bağlamak için nasıl kullanıldığı özellikle açıklanmıştır. İki ayrı cycle ile üst ve alt 8 bitlik veriler birleştirilerek 16 bitlik veri yolu elde edilir.
- SMD dersinin önemi bir kez daha vurgulanmış: Mikroişlemci Assembly dilinde programlanacağı için SMD altyapısının sağlam olması gerektiği belirtilmiştir.
- Bacak tanımlarının doğrudan programlamayla ilişkili olduğu; çevre birimi entegrelerinin (8255, 8254, interrupt kontrolcü vb.) kodlanmasının bu bacak bağlantılarını bilmekle mümkün olduğu vurgulanmıştır.

## Kısa Tekrar Notları

- 8086: 40 pin, 20 adres ucu, 16 veri ucu (AD0-AD15 çoklanmış), A16-A19 sadece adres
- ALE = 1 → adres gönderiliyor; ALE = 0 → veri gönderiliyor
- AD0-AD15: Adres ve veri ortak hat (multiplexed); A16-A19: Sadece adres
- READ = 0 → okuma, WRITE = 0 → yazma (aktif düşük mantık)
- BHE = 0 → üst 8 bit (D8-D15) aktif; BHE ile A0 kombinasyonu tek/çift adres belirler
- MN/MX = 1 → Minimum mode (ders boyunca kullanılacak)
- NMI: Maskelenemez kesme; INTR: IF bayrağına bağlı kesme
- IO/M: I/O erişimi mi bellek erişimi mi olduğunu belirtir
- DT/R: Veri yönü (1 = gönder, 0 = al)
- Latch devreleri (74273) adres bilgisini tutar, böylece aynı hat üzerinden veri aktarımı yapılabilir

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Multiplexed (Çoklanmış) Adres/Veri Yapısı:**
8086'da 40 pin sınuru bulunduğundan 20 ayrı adres ve 16 ayrı veri ucu kullanılamaz. Bunun yerine AD0-AD15 pinleri hem adres hem veri için ortak kullanılır. İşlem sırası şöyledir: İlk olarak mikroişlemci adres bilgisini AD0-AD15 hatlarına koyar ve ALE sinyalini 1 yapar. Karşı taraftaki latch devresi (örneğin 74273) ALE'nin 1→0 geçişinde (düşen kenar) adres bilgisini yakalar ve kendi çıkışlarında sabit tutar. Böylece adres hat üzerından çekildikten sonra aynı hat üzerinden veri aktarımı yapılabilir. A16-A19 pinleri ise sadece adres için kullanıldığından latch'lenmelerine gerek yoktur. Bu yapı sayesinde 40 pin ile hem 20 bit adresleme hem 16 bit veri yolu sağlanabilir.

**BHE ve 8 Bitlik Çevre Birimlerinin Bağlanması:**
8086'nın veri yolu 16 bit (D0-D15) olmasına rağmen çevre birimleri genelde 8 bitlik veri yollarına sahiptir. BHE (Bus High Enable) pini bu uyumsuzluğu çözer. BHE = 0 ve A0 = 0 olduğunda alt 8 bit (D0-D7) çift adresli bir bellek/I/O bloğuna yazılır. BHE = 0 ve A0 = 1 olduğunda üst 8 bit (D8-D15) tek adresli bloğa yazılır. Bu sayede iki ayrı 8 bitlik çevre birimi, birinin çift adreslere diğerinin tek adreslere yerleştirilmesi koşuluyla, 16 bitlik veri yoluna BHE pin'i ile anahtarlanarak bağlanabilir. İlk cycle'da BHE=0 ile üst 8 bit, ikinci cycle'da alt 8 bit gönderilerek 16 bitlik veri birimi oluşturulur.

**Latch Devrelerinin Rolü:**
Çoklanmış adres/veri hatlarında adres bilgisinin bir yerde tutulması gerekir çünkü adres seçimi yapıldıktan sonra aynı hat üzerinden veri aktarımı yapılacaktır. 74273 gibi latch devreleri bu amaçla kullanılır. Latch'in clock girişine ALE bağlanır. ALE 1 iken latch adresi geçirir, ALE 0'a düştüğünde adres latch içinde kilitlenir ve çıkışlarda sabit kalır. Bu sayede mikroişlemci aynı hat üzerinden veri göndermeye başladığında bile adres bilgisi dış dünyada mevcut kalır ve hedef bellek/I/O birimi doğru şekilde seçili kalır.

**Kesme (Interrupt) Sistemi:**
8086'da iki tür kesme giriş pin'i bulunur. INTR pini programlanabilir kesme girişidir; Interrupt Enable Flag (IF) bayrağı 1 olduğunda bu pin üzerinden gelen kesme istekleri kabul edilir, 0 olduğunda göz ardı edilir. NMI (Non-Maskable Interrupt) pini ise maskelenemez kesme girişidir; IF durumuna bakılmaksızın her zaman etkindir ve kritik sistem olaylarında (güç kesintisi, donanım hatası gibi) kullanılır. Bir kesme oluştuğunda mikroişlemci mevcut işlemi durdurur, kesme vektör tablosundan ilgili kesme hizmet rutininin adresini alır ve o adrese dallanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
