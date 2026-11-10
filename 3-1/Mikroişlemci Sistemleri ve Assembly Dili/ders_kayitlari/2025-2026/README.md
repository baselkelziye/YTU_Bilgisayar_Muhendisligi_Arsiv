# Mikroişlemci Sistemleri ve Assembly Dili Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Mikroişlemci Sistemleri ve Assembly Dili (BLM3061)
* **Hoca:** Prof. Dr. Songül Varlı
* **Dönem:** Güz
* **Akademik Yıl:** 2025-2026
* **Şube:** BLM3061 - 1

Bu dizin, ilgili ders kayıtlarının altyazılarını, kısa notlarını ve genişletilmiş notlarını içermektedir.

* **Kısa not:** Tekrar için. Dersin konuları, hocanın vurguları ve kısa tekrar maddeleri.
* **Genişletilmiş not:** Dersi izlemeden öğrenmek için. Dersin anlatım akışını baştan sona, örnekleri ve soru-cevaplarıyla anlatır.
* `altyazilar/`: ders kayıtlarının altyazıları (.srt). Notların PDF'leri `kisa_notlar/` ve `genisletilmis_notlar/` klasörlerinde, markdown kaynakları bu klasörlerin içindeki `markdown/` klasöründedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu ile kısa ve genişletilmiş notlarının markdown ve PDF halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kısa Not | Genişletilmiş Not |
| :---: | :--- | :---: | :---: |
| **Ders 3** | Dizi Komutları, BCD Düzenleme, EXE/COM Program Yapısı ve DEBUG Uygulaması | [Markdown](kisa_notlar/markdown/ders_3_ozet.md) · [PDF](kisa_notlar/ders_3_ozet.pdf) | [Markdown](genisletilmis_notlar/markdown/ders_3_genisletilmis.md) · [PDF](genisletilmis_notlar/ders_3_genisletilmis.pdf) |

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

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
