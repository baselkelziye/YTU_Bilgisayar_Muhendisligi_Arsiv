# Ders 11 Çalışma Özeti

## Genel Konular

- ADC0804 A/D Dönüştürücü
  - 8-bit çözünürlüklü analogdan sayısala dönüştürücü
  - 0-255 arası dijital çıkış (8-bit)
  - 0-5V analog giriş aralığı
  - 32 pin'lik DIP kasa
  - CLK girişi için dahili osilatör (RC devresi ile)
  - WR (Write) pini ile dönüşüm başlatılır
  - RD (Read) pini ile sonuç okunur
  - EOC (End of Conversion) pini ile dönüşüm tamamlanma sinyali

- 8086 ile ADC0804 Arayüzleme
  - Chip Select (CS) pini ile adresleme
  - WR sinyali ile ADC'ye yazma (dönüşüm başlatma)
  - RD sinyali ile ADC'den okuma (sonuç alma)
  - Veri bus'ına doğrudan bağlantı (D0-D7)
  - Vref ayarı ile ölçüm aralığının belirlenmesi

- EOC El Sıkışma (Handshake)
  - EOC pini HIGH olduğunda dönüşüm tamamlanmıştır
  - EOC pini LOW olduğunda dönüşüm devam eder
  - Yazılımsal bekleme (polling) veya kesme (interrupt) ile kontrol

- Kesme Driven Dönüşüm
  - EOC pininin INTR pini ile kesme üretmesi
  - Kesme servo rutini ile dönüşüm sonuçlarının okunması
  - Yoğun işlemci kullanımı önler

## Hocanın Özellikle Vurguladığı Kısımlar

- ADC0804'ün 8-bit çözünürlüğünün 256 farklı seviyeyi temsil ettiğini
- Vref ayarının ölçüm hassasiyetini doğrudan etkilediğini
- WR/RD zamanlamalarının datasheet'teki değerlerine dikkat edilmesi gerektiğini
- EOC el sıkışma yönteminin güvenilirliğini
- Kesme driven dönüşümün gerçek zamanlı uygulamalarda tercih edildiğini

## Kısa Tekrar Notları

- ADC0804 = 8-bit A/D dönüştürücü (0-255 çıkış)
- Vref = Ölçüm aralığı referans voltajı
- WR pini HIGH→LOW: Dönüşüm başlatır
- RD pini LOW→HIGH: Sonucu okur
- EOC pini: Dönüşüm tamamlanma sinyali
- CS pini: Chip seçimi (adresleme)
- Kesme driven: EOC → INTR → Kesme servo rutini

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

ADC0804, analog sinyalleri sayısala dönüştüren temel bir A/D dönüştürücüdür. 8-bit çözünürlüğe sahiptir ve 0-255 arası dijital değer üretir. 0-5V'luk analog giriş aralığını 256 farklı seviyeye böler.

8086 ile arayüzleme işleminde, ADC0804 veri bus'ına doğrudan bağlanır. Chip Select (CS) pini ile adresleme yapılır. WR pini HIGH→LOW geçtiğinde dönüşüm başlatılır. RD pini LOW→HIGH geçtiğinde ise sonuç dijital çıkış pinlerinden okunur.

EOC (End of Conversion) el sıkışma yöntemi, dönüşümün tamamlanmasını bekler. EOC pini HIGH olduğunda sonuç hazır demektir. Bu yöntemde ya yazılımsal polling kullanılır ya da kesme (interrupt) ile dönüşüm tetiklenir.

Kesme driven dönüşüm, EOC pininin INTR pini ile kesme üretmesini sağlar. Bu sayede işlemci sürekli beklemez ve dönüşüm tamamlandığında kesme servo rutini devreye girer. Gerçek zamanlı uygulamalarda bu yöntem tercih edilir.