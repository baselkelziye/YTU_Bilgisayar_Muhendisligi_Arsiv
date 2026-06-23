# Ders 11 Çalışma Özeti

## Genel Konular

- Alt programlara parametre aktarma yöntemleri
  - Registerlar aracılığıyla, ortak bellek alanları (global değişkenler) veya yığın (stack) yardımıyla parametre geçişi anlatılır.
- Stack frame oluşturma
  - BP (Base Pointer) register'ı kullanılarak stack üzerinde her fonksiyon çağrısı için oluşturulan yerel çalışma alanı açıklanır.
- Yığındaki parametrelere erişim
  - Parametrelere göreli adresleme ile ([BP+4], [BP+6] vb.) erişim mantığı ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Stack üzerinden parametre aktarımının avantajları
  - Rekürsif (öz yinelemeli) ve çoklu yordam çağrılarında register çakışmasını önleyen en güvenli yöntem olması.
- Stack temizleme sorumluluğu
  - Yordam çağrısından sonra stack'in temizlenmesinin çağıran (caller - ADD SP, X) veya çağrılan (callee - RET X) tarafından yapılması kuralı.
- BP register'ının stack frame taban noktası rolü
  - MOV BP, SP ile frame sınırının belirlenmesi ve SP değişse bile parametrelere sabit mesafeyle erişim kolaylığı.

## Kısa Tekrar Notları

- Parametre aktarımında en esnek yöntem stack kullanımıdır.
- BP register'ı yığındaki parametrelere göreli erişim sağlar ([BP+4] vb.).
- Lokal değişkenler için stack'te yer açılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Alt programlara parametre aktarımı üç temel yöntemle yapılır: registerlar üzerinden (hızlı ama sınırlı sayıda), ortak bellek alanları (global değişkenler) üzerinden (modülerliği azaltır) ve stack (yığın) üzerinden (güvenli ve sınırsız). Stack üzerinden parametre aktarımında, çağıran program parametreleri sırayla stack'e push eder ve ardından CALL komutunu çalıştırır. Yordam içinde, parametrelere ve lokal değişkenlere erişmek için BP (Base Pointer) register'ı kullanılır. BP değeri stack frame'in taban noktası olarak belirlenir (MOV BP, SP ile). Yordam sonlandığında stack'in temizlenmesi gerekir. Bu temizlik, çağıran program tarafından (ADD SP, X ile) veya yordamın kendisi tarafından (RET X komutuyla) gerçekleştirilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
