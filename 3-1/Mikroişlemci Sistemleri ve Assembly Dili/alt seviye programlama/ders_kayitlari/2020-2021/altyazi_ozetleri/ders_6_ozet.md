# Ders 6 Çalışma Özeti

## Genel Konular

- 8086 Adresleme Kipleri (Addressing Modes)
  - Immediate, Register, Direct, Register Indirect, Based, Indexed ve Based Indexed adresleme yöntemleri açıklanır.
- OFFSET direktifi ve işaretçiler (pointers)
  - Bir değişkenin başlangıç adresini (segment içindeki offsetini) alma ve bellek adreslerini işaretçilerle yönetme yolları ele alınır.
- Bellekteki verilere esnek erişim yöntemleri
  - Diziler veya yapılar gibi veri kümelerine indeks yazmaçları (SI, DI) kullanarak erişim anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adresleme kiplerinin esnekliği
  - Diziler ve tablolara erişimde indexed veya based-indexed adreslemenin sunduğu büyük pratiklik.
- Pointer aritmetiği ve veri boyutu belirteçleri
  - Bellek adresindeki verinin boyutunu derleyiciye bildirmek için kullanılan BYTE PTR veya WORD PTR belirteçlerinin önemi.
- Performans farkları
  - Hangi adresleme kipinin hangi bellek erişim süresi (saat çevrimi) maliyetini getirdiği.

## Kısa Tekrar Notları

- Adresleme kipleri veriye nasıl erişileceğini belirler.
- [BX], [SI], [DI] dolaylı adreslemede kullanılabilir.
- OFFSET bir değişkenin başlangıç adresini (segment içindeki konumunu) verir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Adresleme kipleri, işlemcinin bellekteki operandlara nasıl erişeceğini belirler. En temel kipler immediate (doğrudan sabit değer), register (yazmaçtaki değer) ve direct (doğrudan adres) adreslemedir. Daha karmaşık veri yapıları için dolaylı adresleme yöntemleri kullanılır: register indirect (BX, BP, SI, DI registerları ile adresleme), based (BX veya BP ile bir taban adrese göre adresleme), indexed (SI veya DI ile dizin adresleme) ve based-indexed (taban ve dizin yazmaçlarının toplamıyla adresleme). Offset direktifi, bir değişkenin tanımlandığı veri segmentindeki başlangıç adresini (offset değerini) almak için kullanılır. İşaretçiler (pointers) tanımlanırken verinin boyutu BYTE PTR veya WORD PTR belirteçleriyle derleyiciye bildirilmelidir. Bu belirteçler, bellek adresindeki verinin kaç byte olarak okunacağını veya yazılacağını netleştirir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
