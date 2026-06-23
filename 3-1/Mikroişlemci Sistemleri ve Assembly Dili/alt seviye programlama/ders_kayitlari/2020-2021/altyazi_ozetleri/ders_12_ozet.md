# Ders 12 Çalışma Özeti

## Genel Konular

- Kesmeler (Interrupts) ve Kesme Vektör Tablosu (IVT)
  - Kesme kavramı, IVT'nin bellekteki konumu (ilk 1 KB) ve yapısı anlatılır.
- Yazılımsal kesmeler (INT komutu)
  - BIOS ve DOS servislerini çağıran INT 21h, INT 10h gibi sistem kesmeleri ele alınır.
- Kesmelerin çalışma mantığı
  - Kesme tetiklendiğinde Flags, CS ve IP registerlarının otomatik olarak stack'e atılması ve Kesme Servis Yordamına (ISR) dallanma süreci açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- IVT'nin 00000h - 003FFh arasındaki sabit adresi
  - Her bir kesme için 4 byte'lık (2 byte Segment, 2 byte Offset) adres vektörü tuttuğu bilgisi.
- ISR sonundaki IRET komutunun rolü
  - Stack'e atılan Flags, CS ve IP değerlerini geri yükleyerek kesme öncesindeki ana program akışına güvenli dönüş sağladığı.

## Kısa Tekrar Notları

- Kesme, program akışını geçici olarak durduran olaydır.
- IVT 256 adet kesme vektörü içerir. Her vektör 4 byte uzunluğundadır (2 byte Segment, 2 byte Offset).
- INT 21h DOS servislerini çağırarak ekrana yazı yazma, girdi alma gibi işlemleri yapar.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Kesmeler (Interrupts), işlemcinin normal akışını keserek öncelikli bir görevi (Kesme Servis Yordamı - ISR) yürütmesini sağlayan mekanizmalardır. 8086 mimarisinde belleğin ilk 1 KB'lık kısmı (00000h - 003FFh) Kesme Vektör Tablosu (Interrupt Vector Table - IVT) olarak ayrılmıştır. IVT, 256 adet kesmenin her biri için 4 byte'lık CS:IP adres bilgisini tutar. Yazılımsal kesmeler INT N komutuyla tetiklenir. Örneğin INT 21h, DOS işletim sistemi servislerini (ekrana karakter yazma, klavyeden okuma, dosya işlemleri) çağırmak için kullanılır. Kesme tetiklendiğinde işlemci sırasıyla Flags register'ını, CS ve IP değerlerini stack'e push eder, kesme koduna karşılık gelen adresi IVT'den okuyarak oraya dallanır. ISR sonundaki IRET komutu stack'teki değerleri geri yükleyerek ana programa dönüş sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
