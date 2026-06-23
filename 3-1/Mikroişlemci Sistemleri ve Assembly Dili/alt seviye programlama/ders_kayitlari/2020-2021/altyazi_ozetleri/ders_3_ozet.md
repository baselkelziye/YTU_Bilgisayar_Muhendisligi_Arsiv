# Ders 3 Çalışma Özeti

## Genel Konular

- Dallanma ve Karşılaştırma komutları: Koşulsuz dallanma (JMP) ve koşullu dallanma (JE, JNE, JZ, JNZ, JG, JL vb.)
- Matematiksel ve mantıksal işlemler (ADD, SUB, MUL, DIV, AND, OR, XOR, NOT)
- Karşılaştırma (CMP) komutu ve Flags register'ının rolü

## Hocanın Özellikle Vurguladığı Kısımlar

- Koşullu dallanmaların Flags register'ı üzerindeki bit durumlarına göre çalıştığı.
- Çarpma (MUL) ve bölme (DIV) işlemlerinde örtük (implicit) register kullanımı ve taşma durumları.
- Kod okunabilirliği ve akışı için dallanma bloklarının düzenli yapılandırılması.

## Kısa Tekrar Notları

- JMP koşulsuz, JE/JZ vb. koşullu dallanmadır.
- Çarpma ve bölmede AX (veya DX:AX) varsayılan olarak kullanılır.
- Karşılaştırma için CMP komutu kullanılır, bu komut arka planda çıkarma yapar ancak sonucu kaydetmez, sadece Flags register'ı etkiler.
