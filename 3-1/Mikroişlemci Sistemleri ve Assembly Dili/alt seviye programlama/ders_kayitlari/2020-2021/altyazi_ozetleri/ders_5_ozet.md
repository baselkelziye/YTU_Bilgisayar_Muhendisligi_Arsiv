# Ders 5 Çalışma Özeti

## Genel Konular

- Öteleme (Shift) ve döndürme (Rotate) komutları (SHL, SHR, SAR, SAL, ROL, ROR, RCL, RCR)
- Mantıksal ve aritmetik öteleme farkları
- Öteleme komutlarının hızlı çarpma ve bölme işlemlerinde kullanımı

## Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik ötelemede (SAR) işaret bitinin (MSB) korunması, mantıksal ötelemede ise sıfır doldurulması.
- Döndürme komutlarında elde (carry) bitinin rolü.
- Performans kritik uygulamalarda çarpma/bölme yerine öteleme komutlarının kullanılması.

## Kısa Tekrar Notları

- SHL/SHR mantıksal, SAL/SAR aritmetik ötelemedir.
- SAR işaret bitini korur, dolayısıyla işaretli sayılarda bölme için kullanılır.
- Öteleme komutları 2'nin kuvvetleriyle çarpmayı/bölmeyi hızlandırır. ROL/ROR döndürme, RCL/RCR carry ile döndürmedir.
