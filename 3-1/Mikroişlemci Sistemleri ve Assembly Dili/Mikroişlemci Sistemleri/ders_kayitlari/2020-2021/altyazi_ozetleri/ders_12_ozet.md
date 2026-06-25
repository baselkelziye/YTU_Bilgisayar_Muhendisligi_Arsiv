# Ders 12 Çalışma Özeti

## Genel Konular

- **Kesmeler (Interrupts) - Detaylı İnceleme**
  - Kesme kavramı: Mikro işlemcinin normal yürütmesini durdurarak harici veya dahili bir olaya müdahale etmesi; olay çözümlendikten sonra kaldığı yere geri dönmesi.
  - Yazılımsal kesmeler: INT komutu ile tetiklenen kesmeler (INT 0, INT 3 gibi).
  - Donanımsal kesmeler: INTR (maskelenebilir) ve NMI (maskelenemez) pinlerinden gelen sinyallerle oluşan kesmeler.

- **Kesme Vektör Tablosu**
  - 8086'da 00000H-003FFH adres aralığında bulunan 1024 byte'lık tablo.
  - 256 farklı kesme tipi; her biri 4 byte (2 byte IP/offset + 2 byte CS/segment).
  - Rezerve kesme tipleri: Tip 0 (sıfıra bölme), Tip 1 (single step/debug), Tip 2 (NMI), Tip 3 (breakpoint), Tip 4 (overflow).
  - Kullanıcı tanımlı kesmeler: Tip 32-255 arası (80H-3FFH adres aralığı).

- **Kesme İşleminin Gerçekleştirilmesi (Adım Adım)**
  1. Kesme türü belirlenir (öncelik sırası: Single Step > NMI > INTR > INT).
  2. Flags register stack'e push edilir.
  3. IF=0 ve TF=0 yapılır (iç içe kesmeleri engellemek için).
  4. CS ve IP stack'e push edilir (geri dönüş adresi).
  5. Kesme vektör tablosundan yeni CS ve IP değerleri okunur.
  6. Kesme alt programı (subroutine) yürütülür.
  7. IRET ile IP, CS ve Flags register stack'ten pop edilir; ana programa dönülür.

- **8259A Programlanabilir Kesme Kontrol Entegresi**
  - 8 adet kesme girişini (IR0-IR7) yöneten; önceliklendirme, maskeleme ve vektör numarası üretimi yapan entegre.
  - Master-slave yapılandırma ile 64 kesmeye kadar genişletilebilir.
  - INT ucu → mikro işlemcinin INTR pinine; INTA ucu ← mikro işlemcinin INTA pinine bağlanır.

- **8259A Komut Kelimeleri (ICW - Initialization Command Words)**
  - ICW1 (A0=0): 8086 modu, single/cascade seçimi, kenar/seviye tetikleme, ICW4 gerekliliği.
  - ICW2 (A0=1): Kesme vektör numarasının üst 5 bitini tanımlama (IR0-IR7 için başlangıç tipi).
  - ICW3 (cascade modda): Master için hangi portlarda slave olduğu; slave için kendi ID'si.
  - ICW4: Otomatik EOI (End of Interrupt), 8086 modu (PM=1).

- **8259A Kesme İşlem Akışı**
  1. IR pinlerinden biri 1 olunca 8259, CPU'ya INTR gönderir.
  2. CPU ilk INTA gönderir → 8259 IRR/ISR register'larını günceller.
  3. CPU ikinci INTA gönderir → 8259 kesme tipini (vektör numarasını) veri yoluna koyar.
  4. CPU bu tip numarasını 4 ile çarparak kesme vektör tablosundaki adresi hesaplar.
  5. Kesme alt programı yürütülür.
  6. EOI gönderilerek işlem sonlandırılır (otomatik veya manuel).

- **Assembly Kodu: Kesme Programlama Örneği**
  - 8259'un ICW1, ICW2, ICW4 kelimelerinin sıralı gönderimi.
  - STI komutu ile kesmelerin aktif edilmesi.
  - Kesme vektör tablosuna subroutine adresinin (offset ve segment) yazılması.
  - Kesme alt programında BP push, SP→BP, AX increment, BP pop, IRET adımları.

## Hocanın Özellikle Vurguladığı Kısımlar

- **ICW gönderim sırası kritiktir**: ICW1 → ICW2 → (varsa ICW3) → (varsa ICW4) sıralaması kesinlikle değiştirilemez; akışın ortasından başlanamaz.
- **Kesme vektör tablosu adres hesabı**: Tip numarası × 4 = efektif adres. Örneğin tip 40 (40H) → 40H × 4 = 100H.
- **INTA iki kez gönderilir**: İlk INTA'da anlamlı veri okunamaz; ikinci INTA'da 8259 kesme tipini veri yoluna koyar.
- **Kesme routinesinde stack kullanımı**: Flags → CS → IP sırasıyla push edilir; IRET ile ters sırada pop edilir.
- **Daisy chain yöntemi**: Birden fazla 8255 entegresinin OR kapısı ile tek INTR hattına bağlanması; ancak kesme tipini doğrudan bildirmediği için yazılımsal kontrol (C portu okuma) gerekir.

## Kısa Tekrar Notları

- Kesme vektör tablosu: 00000H-003FFH, 256 kesme, her biri 4 byte.
- Tip 0: DIV 0 (sıfıra bölme), Tip 2: NMI, Tip 3: Breakpoint, Tip 4: Overflow.
- IF=1 → INTR aktif; IF=0 → INTR pasif. NMI her zaman aktiftir.
- 8259A: 8 kesme girişi, master-slave ile 64'e kadar genişletilebilir.
- ICW1: A0=0 adresine yazılır; ICW2-4: A0=1 adresine sırayla yazılır.
- ICW1'de D4=1 olmalı; D0-D2=0 (8086 için); D3: tetikleme tipi (1=kenar); D1: ICW4 gerekli mi.
- ICW2: Kesme vektörünün üst 5 bitini belirler (IR0 için başlangıç tipi).
- ICW4: D0=1 ise otomatik EOI; D4=1 ise 8086 modu (PM).
- Kesme routinesinde: PUSH BP → MOV BP,SP → işlem → POP BP → IRET.
- LEA komutu ile efektif adres hesaplanarak vektör tablosuna offset/segment yazılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Kesme Vektör Tablosu Yapısı:**
8086'da belleğin ilk 1024 byte'ı kesme vektör tablosuna ayrılmıştır. Her kesme tipi 4 byte'lık bir girişe sahiptir: ilk 2 byte kesme alt programının offset (IP) değerini, sonraki 2 byte ise segment (CS) değerini içerir. Örneğin tip 0 (sıfıra bölme) kesmesi 0000H-0003H adreslerinde, NMI (tip 2) 0008H-000BH adreslerinde yer alır. Kullanıcı tanımlı kesmeler 80H'dan (tip 32) 3FFH'ye kadar olan bölgede tanımlanabilir. Bir kesmenin efektif adresini bulmak için tip numarası 4 ile çarpılır.

**8259A ICW Programlama Sırası:**
8259'u programlamak için komut kelimeleri belirli bir sırayla gönderilmelidir:
1. ICW1 (CS=0, A0=0 adresine): 8086 modu, single/cascade, kenar/seviye tetikleme ve ICW4 gerekliliği belirlenir. D4=1 olmalıdır.
2. ICW2 (CS=0, A0=1 adresine): IR0-IR7 pinlerine karşılık gelen kesme vektör numarasının üst 5 biti tanımlanır. Örneğin IR0'a tip 40 atamak istenirse ICW2=40H yazılır.
3. ICW3 (sadece cascade modda, A0=1): Master modda hangi IR portlarında slave olduğu; slave modda entegrenin ID numarası belirlenir.
4. ICW4 (ICW1'de D0=1 ise, A0=1): Otomatik EOI (D0=1), 8086 modu (D4=1) ayarlanır.

**8259A ile Kesme Oluşum Süreci:**
Bir IR pinine kesme geldiğinde: (1) 8259 IRR (Interrupt Request Register) register'ında ilgili biti set eder, (2) INT pinini 1 yaparak CPU'ya kesme isteği gönderir, (3) CPU INTA sinyalinin ilk darbesini gönderir → 8259 IRR'yi ISR'ye (In-Service Register) aktarır ve yeni kesmeleri engeller, (4) CPU INTA'nın ikinci darbesini gönderir → 8259 kesme tipini (vektör numarasını) veri yoluna yerleştirir, (5) CPU bu tip numarasını 4 ile çarparak kesme vektör tablosundaki CS:IP adresini okur ve kesme alt programına dallanır.

**Assembly'de Kesme Vektör Tablosuna Subroutine Yazma:**
Kullanıcı tanımlı bir kesmenin (örneğin tip 40) vektör tablosundaki adresi hesaplanır: 40H × 4 = 100H. LEA komutu ile subroutine'in efektif adresi alınır. Extra segment (ES) 0 olarak ayarlanır (vektör tablosu 0. segmentte). Offset değeri [100H] adresine, CS değeri [102H] adresine yazılır. Böylece tip 40 kesmesi oluştuğunda CPU bu adresteki subroutine'e dallanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
