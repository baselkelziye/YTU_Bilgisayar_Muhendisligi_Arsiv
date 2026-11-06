# Devre Teorisi ve Elektronik Devreler Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Devre Teorisi ve Elektronik Devreler (BLM1033)
* **Hoca:** Doç. Dr. Hamza Osman İlhan
* **Dönem:** Bahar
* **Akademik Yıl:** 2023-2024
* **Şube:** BLM1033 - 1

Bu dizin, ilgili ders kayıtlarının altyazılarını, kısa notlarını ve genişletilmiş notlarını içermektedir.

* **Kısa not:** Tekrar için. Dersin konuları, hocanın vurguları ve kısa tekrar maddeleri.
* **Genişletilmiş not:** Dersi izlemeden öğrenmek için. Dersin anlatım akışını baştan sona, örnekleri ve soru-cevaplarıyla anlatır.
* `altyazilar/`: ders kayıtlarının altyazıları (.srt). Notların PDF'leri `kisa_notlar/` ve `genisletilmis_notlar/` klasörlerinde, markdown kaynakları bu klasörlerin içindeki `markdown/` klasöründedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu ile kısa ve genişletilmiş notlarının markdown ve PDF halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kısa Not | Genişletilmiş Not |
| :---: | :--- | :---: | :---: |
| **Ders 3** | İkinci Dereceden Devreler: Sınır Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC, Aşırı/Kritik/Az Sönüm | [Markdown](kisa_notlar/markdown/ders_3_ozet.md) · [PDF](kisa_notlar/ders_3_ozet.pdf) | [Markdown](genisletilmis_notlar/markdown/ders_3_genisletilmis.md) · [PDF](genisletilmis_notlar/ders_3_genisletilmis.pdf) |

> [!NOTE]
> Bu şubenin kayıt arşivinde yalnızca 3 numaralı ders kaydı bulunmaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 3: İkinci Dereceden Devreler: Sınır Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC, Aşırı/Kritik/Az Sönüm
* **Genel Konular:**
  - Dualite konusu işlenmeyecek, sorumlu değilsiniz.
  - Birinci ve ikinci dereceden devreler
    - RC ve RL devrelerinde tek bir enerji depolayan eleman (bir kondansatör veya bir bobin) vardı. Kondansatörde $i_C = C\frac{dv_C}{dt}$, bobinde $v_L = L\frac{di_L}{dt}$ ilişkisinden birinci dereceden diferansiyel denklem çıkıyordu.
  - Sınır koşulları (boundary conditions)
    - Önce geçiş anından ($t_0$) çok önceki (initial) ve çok sonraki (final) durumlar bulunur. Bu, grafiğin nereden başlayıp nereye gittiğini gösterir. Aradaki geçişin (transient) şekli ayrıca incelenir.
  - Geçişin üç biçimi
    - İki enerji depolayan eleman enerjiyi birbirine aktarır: kondansatör boşalırken bobini, bobin boşalırken kondansatörü besler. Bu yüzden sistem salınım yapabilir.
  - Kaynaksız seri RLC (source-free series RLC)
    - Kondansatör $V_s$'ye şarjlı, kaynak $t_0$'da çıkarılıyor. Başlangıç: $v_C = V_s$, akım 0. Son: her şey 0.
  - Kaynaksız paralel RLC
    - Akım kaynağı $I_s$ çıkarılıyor. Başlangıçta bobin kısa devre olduğu için $i_L = I_s$, sonra 0'a iner.
  - Basamak cevabı (step response)
    - Devrede kaynak yokken $t = 0$'da kaynak bağlanıyor.
* **Hocanın Vurgusu:**
  - Sınır koşullarında kondansatör açık devre, bobin kısa devre.
  - Kaynak çıkınca her şey sıfıra gitmeyebilir.
    - Başka kaynak varsa son değeri o belirler.
  - Hangi durumun oluşacağına $\alpha$ ile $\omega_0$ karşılaştırılarak karar verilir.
  - Seri ve paralel devrede yalnızca $\alpha$ değişir.
  - Formüllerin nasıl çıktığını evde kendiniz türetin.
    - Gelecek haftaki soru çözümüne mutlaka katılın.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
