# Ders 12 Çalışma Özeti

## Genel Konular

- Kesmeler (Interrupts) ve Kesme Vektör Tablosu (Interrupt Vector Table - IVT)
- Yazılımsal kesmeler (INT komutu) ve BIOS/DOS servisleri (örn. INT 21h fonksiyonları)
- Kesmelerin çalışma mantığı ve kesme servis yordamları (ISR)

## Hocanın Özellikle Vurguladığı Kısımlar

- **IVT'nin bellekteki ilk 1 KB'lık alanda (00000h - 003FFh) yer alması ve her kesme için 4 byte'lık CS:** IP adres bilgisi tutması.
- Kesme tetiklendiğinde Flags, CS ve IP registerlarının otomatik olarak stack'e atılması.

## Kısa Tekrar Notları

- Kesme, program akışını geçici olarak durduran olaydır.
- IVT 256 adet kesme vektörü içerir. Her vektör 4 byte uzunluğundadır (2 byte Segment, 2 byte Offset).
- INT 21h DOS servislerini çağırarak ekrana yazı yazma, girdi alma gibi işlemleri yapar.
