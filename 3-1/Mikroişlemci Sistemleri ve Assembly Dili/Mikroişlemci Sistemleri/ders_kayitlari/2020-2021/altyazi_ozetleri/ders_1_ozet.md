# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin Yapısı ve Notlandırma
  - Toplam 2 saat teorik + 2 saat laboratuvar dersi
  - Vize %30, Final %40, Laboratuvar %30 ağırlığa sahip
  - 8086 mikro işlemcisi üzerine odaklanılacak
  - Lab dersleri programlamaya yakın, SM dilinde kodlama gerektirir

- Bilgisayar Mimarilerinin Tarihçesi
  - **Mekanik Çağ:** Abaküs ile başlar, Pascal makinelerine kadar uzanır. Hesaplama işlemleri mekanik çarklarla gerçekleştirilirdi. 1800'lü yıllara kadar使用 edildi.
  - **Elektriksel Çağ:** Vakum tüpleri ile başladı. IBM firması bu dönemde önemli yenilikler getirdi. Z3 makinesi modern bilgisayarların atası sayılır (5 Hz çalışan).
  - **Sayısal Çağ:** Transistör tabanlı sistemlerle başladı (1947). Entegre devreler (IC) geliştirildi. 1971'de Intel ilk mikro işlemciyi (4004) tanıttı.

- Mikro İşlemci Değerlendirme Kriterleri
  - İşlemci kaç bitlik olduğu (4-bit, 8-bit, 16-bit)
  - Adresleme kapasitesi (kaç farklı bellek hücresine erişebildiği)
  - İçerisindeki yazmaç (register) sayısı
  - Komut seti (instruction set) zenginliği
  - İşlem frekansı

- İşlemci Gelişimi
  - **Intel 4004 (1971):** İlk mikro işlemci, 4-bit, 4096 adresleme, 45 komut
  - **Intel 8008 (1972):** 8-bit, 16KB adresleme, 48 komut
  - **Intel 8080 (1973):** 8-bit, 64KB adresleme, TTL mimarisi, 10 kat daha hızlı
  - **Intel 8085 (1977):** 8-bit, 769 kHz çalışma frekansı
  - **Intel 8086 (1978):** İlk 16-bit işlemci, 1MB adresleme, 20 adres ucu, 2.5 milyon işlem/saniye

- RISC ve CISC Mimarileri
  - **RISC (Reduced Instruction Set Computer):** Az komut seti, hafıza açısından verimli, ancak karmaşık işlemler için daha fazla komut gerekir
  - **CISC (Complex Instruction Set Computer):** Zengin komut seti, tek satırda karmaşık işlemler yapılabilir, ancak daha fazla hafıza alanı gerektirir

## Hocanın Özellikle Vurguladığı Kısımlar

- Lab derslerinin önemi çok büyüktür; lab notunun yüksek olması Final'e hazırlık açısından kritiktir
- 8086'nın 16-bit olması demek, register'larının 16 bit veri saklayabilmesi anlamına gelir (0-65535 arası sayılar tek seferde işlenebilir)
- 20 adres ucu = 2^20 = 1MB adresleme kapasitesi
- SMD (Sayısal Mantık Tasarımı) bilgisi bu dersin temelini oluşturur
- Komut setinin zenginliği bir işlemcinin gücünü belirler (4004'te çarpma komutu yoktu, toplama ile yapılması gerekiyordu)

## Kısa Tekrar Notları

- Mikro işlemci = CPU'nun tek bir çip üzerine sığdırılmış halidir
- Bit sayısı = Register'da tek seferde saklanabilen veri miktarı
- Adresleme kapasitesi = 2^(adres ucu sayısı) × bellek hücresi boyutu
- 8086: 16-bit, 20 adres ucu (1MB), 16 veri ucu, CISC mimarisi
- Transistör sayısı ile işlemci hızı doğrudan ilişkilidir
- Günümüzde transistör yoğunluğu fiziksel sınırlara ulaşmıştır (çekirdek sayısı artırılarak devam edilmektedir)

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8086 mikro işlemcisi, bilgisayar mimarisi tarihinde dönüm noktası niteliğindedir. 16-bit mimarisi sayesinde önceki 8-bit işlemcilere göre çok daha geniş bir veriye aynı anda erişebilir. Örneğin 8-bit bir işlemci 0-256 arasındaki bir sayıyı tek seferde işlerken, 16-bit 8086 0-65535 arasındaki bir sayıyı tek döngüde işleyebilir.

İşlemci seçerken en önemli kriterlerden biri adresleme kapasitesidir. 8086'nın 20 adres ucu vardır ve 2^20 = 1.048.576 (1MB) farklı bellek adresine erişebilir. Bu, o dönemde büyük bir avantaj sağlamıştır. Her bir adres bir byte veri tutabilir.

Komut seti (instruction set) zenginliği de hayati önem taşır. 4004'te sadece 45 komut vardı ve çarpma işlemi doğrudan desteklenmiyordu. 8086'da ise yaklaşık 20.000 farklı komut varyasyonu mevcuttur. Bu zenginlik, programcıya daha az komut ile daha karmaşık işlemler yapma imkanı tanır.

RISC ve CISC mimarileri arasındaki temel fark şudur: RISC az sayıda basit komutla çalışır, bu yüzden hafızada az yer kaplar ama karmaşık bir işlem için birçok komutun art arda çalıştırılması gerekir. CISC ise çok sayıda karmaşık komut barındırır, tek bir komutla bileşik işlemler yapılabilir ancak her komutun hafızada kapladığı yer fazladır. 8086 bir CISC mimarisidir.
