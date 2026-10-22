# Devre Teorisi ve Elektronik Devreler Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Devre Teorisi ve Elektronik Devreler (BLM1033)
* **Hoca:** Doç. Dr. Hamza Osman İlhan
* **Dönem:** Bahar
* **Akademik Yıl:** 2023-2024
* **Şube:** BLM1033 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 3** | İkinci Dereceden Devreler: Sınır Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC, Aşırı/Kritik/Az Sönüm | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |

> [!NOTE]
> Bu şubenin kayıt arşivinde yalnızca 3 numaralı ders kaydı bulunmaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 3: İkinci Dereceden Devreler: Sınır Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC, Aşırı/Kritik/Az Sönüm
* **Genel Konular:**
  - Duyurular
    - Hoca o hafta Ankara'da olduğu için ders online yapıldı. Hoca dersi ilk kez tablet üzerinden anlattı. Bulunduğu ortam nedeniyle kısık sesle konuştu; bazı öğrenciler sesi düşük duyduğunu yazdı.
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

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
