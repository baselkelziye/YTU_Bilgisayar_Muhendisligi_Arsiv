# Mikroişlemci Sistemleri ve Assembly Dili Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Mikroişlemci Sistemleri ve Assembly Dili (BLM3061)
* **Hoca:** Prof. Dr. Songül Varlı
* **Dönem:** Güz
* **Akademik Yıl:** 2025-2026
* **Şube:** BLM3061 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 3** | Dizi Komutları, BCD Düzenleme, EXE/COM Program Yapısı ve DEBUG Uygulaması | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |

> [!NOTE]
> Dersler yüz yüze yapıldığından kayıt arşivinde yalnızca 23 Ekim 2025 online ek dersi bulunmaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 3: Dizi Komutları, BCD Düzenleme, EXE/COM Program Yapısı ve DEBUG Uygulaması
* **Genel Konular:**
  - Dizi (string) komutları: `MOVSB/MOVSW`, `CMPSB/CMPSW`, `SCASB/SCASW`, `LODSB/LODSW`, `STOSB/STOSW`.
  - Tekrar önekleri (repeat prefix): `REP`, `REPE/REPZ`, `REPNE/REPNZ`.
  - Yön bayrağı (direction flag, DF) ile `CLD`/`STD`.
  - İşaret genişletme (sign extension) komutları: `CBW` ve `CWD`.
  - Giriş/çıkış komutları `IN` ve `OUT`. İşlemci denetim komutları `HLT`, `NOP`, `WAIT`.
  - BCD düzenleme komutları: `AAA`, `AAS`, `AAM`, `AAD`, `DAA`, `DAS`.
  - EXE ve COM tipi program yapısı.
* **Hocanın Vurgusu:**
  - Dizi komutlarında tekrar sayısı `CX`'te tutulur.
    - Her adımda `CX` bir azalır.
  - DF = 0 ise adresler artar (ileri).
    - DF = 1 ise adresler azalır (geri).
  - Byte komutlarında `SI`/`DI` 1, word komutlarında 2 değişir.
  - `CBW` ve `CWD` işaret bitini dikkate alarak genişletir.
    - Bölme işlemlerinde bu genişletme gerekir.
  - EXE programlarda en az bir `FAR` prosedür olmalı.
    - Prosedürün başındaki 5 satır her programda aynıdır.
* **Detaylı Açıklamalar:** Dizi kopyalama (slayt):

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
