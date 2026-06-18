# Yapay Zeka Ders Kayıtları & Çalışma Özetleri

### 📋 Genel Bilgiler
* **Ders:** Yapay Zeka
* **Dönem:** Bahar
* **Akademik Yıl:** 2022 - 2023


> [!TIP]
> **NotebookLM vb. Araçlarla İnteraktif Çalışma:**
> **[altyazılar](./altyazilar/)** dizinindeki ham altyazı dosyalarını **NotebookLM** ya da benzeri yapay zeka tabanlı araçlara yükleyerek çalışma verimliliğinizi artırabilirsiniz.


Bu dizin, **Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü 3. Sınıf 2. Dönem Yapay Zeka** dersine ait ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

Derslerin temel amacı; yapay zekayı tek bir algoritma veya yöntem ailesi olarak görmek yerine, problemleri doğru modelleme, arama uzaylarını yönetme, bilgi gösterimi ve makine öğrenmesi yaklaşımları arasındaki bağlantıları kurarak **akıllı davranış üreten sistemler** tasarlamaktır.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Yapay Zekaya Giriş: Kapsam, Zeka Yaklaşımları, Problem Temsili | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Yapay Zekanın Tarihsel Gelişimi ve Etmen (Agent) Mantığı | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Arama Problemlerine Giriş, Durum Uzayı ve Kör Arama (BFS, DFS) | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Sezgisel (Informed) Arama: Maliyet Tabanlı Arama, Sezgisel Fonksiyonlar ve A* Algoritması | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Lokal Arama Yöntemleri: Tepe Tırmanma (Hill Climbing) ve Lokal/Global Optimum Sınırları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Genetik Algoritmalar: Evrimsel Arama, Kromozom Temsili ve Uygunluk Fonksiyonu | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Oyun Teorisi ve Karar Verme: İki Oyunculu Sıfır Toplamlı Oyunlar ve Minimax | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Bilgi Gösterimi ve Akıl Yürütme: Veri-Bilgi Ayrımı ve Bilgi İşleme Modelleri | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 10** | Makine Öğrenmesine Giriş: Veriden Örüntü Öğrenme, Sınıflandırma vs. Regresyon | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Sınıflandırma Karar Yapıları: Çıktı Değişkeni Analizi ve Karar Ağaçları | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Sınıflandırma Sınırları: Doğrusal/Doğrusal Olmayan Karar Sınırları, YSA ve Kümeleme | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Pekiştirmeli Öğrenme (Reinforcement Learning): Ajan-Çevre Etkileşimi ve Ödül/Ceza | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 9* resmi tatil veya ara sınav haftası nedeniyle işlenmemiş ya da kayıt altına alınmamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Yapay Zekaya Giriş
* **Genel Konular:** Zeka ve yapay zeka tanımları, dersin kapsamı (arama, oyunlar, bilgi gösterimi, makine öğrenmesi, YSA, derin öğrenme), rasyonel düşünme/davranma ve problem çözme fikri.
* **Hocanın Vurgusu:** Yapay zeka tek bir algoritma değildir. Ders boyunca farklı problem aileleri birbirine bağlanarak öğrenilecektir. Problemin doğru temsil edilmesi, başarının anahtarıdır.

### 🔹 Ders 2: Tarihsel Gelişim ve Etmenler
* **Genel Konular:** Sembolik yapay zeka, bağlantıcı (connectionist) yaklaşımlar, makine öğrenmesi ayrımı ve etmen (agent) yapısı.
* **Hocanın Vurgusu:** Etmen kavramı, yapay zeka problemlerini çözümlemek için en temel çerçevedir. Ortamın yapısı (çevre), kullanılacak yapay zeka yöntemini doğrudan belirler.

### 🔹 Ders 3: Arama Problemleri ve Kör Arama
* **Genel Konular:** Başlangıç durumu, hedef durumu, durum uzayı ve operatörler ile problem modelleme; Kör arama yöntemleri (BFS - Enlemesine Arama, DFS - Derinlemesine Arama).
* **Hocanın Vurgusu:** Problemi matematiksel/mantıksal olarak kurmadan arama algoritması seçmek anlamsızdır. Durum uzayı büyüdükçe arama maliyeti katlanarak artar.

### 🔹 Ders 4: Sezgisel Arama ve A* Algoritması
* **Genel Konular:** Maliyet tabanlı arama, sezgisel (heuristic) bilgi kullanımı ve A* algoritmasının çalışma prensibi.
* **Hocanın Vurgusu:** Sezgisel fonksiyonlar hedefe olan kalan maliyeti yaklaşık olarak tahmin eder. Doğru sezgisel fonksiyon tasarımı algoritmanın başarısını belirler; hatalı fonksiyonlar arama sürecini yanlış yönlendirebilir.

### 🔹 Ders 5: Lokal Arama Yöntemleri
* **Genel Konular:** Bellek tasarrufu sağlayan lokal arama modelleri, Tepe Tırmanma (Hill Climbing) algoritması, lokal optimum ve global optimum çıkmazları.
* **Hocanın Vurgusu:** Lokal arama, tüm durum uzayını bellekte tutmak zorunda olmadığından büyük problemlerde son derece avantajlıdır. Ancak lokal optimumlara takılma riski yüksektir.

### 🔹 Ders 6: Genetik Algoritmalar
* **Genel Konular:** Doğal seçilim ve evrimsel süreç tabanlı optimizasyon, popülasyon, kromozom kodlaması ve uygunluk (fitness) fonksiyonu.
* **Hocanın Vurgusu:** Genetik algoritmalarda en kritik kısım çözümün kromozom üzerinde nasıl temsil edildiğidir. Kötü bir temsil, algoritmayı işlevsiz kılacaktır.

### 🔹 Ders 7: Oyun Teorisi ve Minimax
* **Genel Konular:** İki oyunculu sıfır toplamlı (zero-sum) oyunlar, minimax karar verme mekanizması ve oyun ağaçları.
* **Hocanın Vurgusu:** Oyun yapay zekasında rakibin de her zaman en iyi/rasyonel hamleyi yapacağı varsayımıyla hareket edilmelidir.

### 🔹 Ders 8: Bilgi Gösterimi ve Akıl Yürütme
* **Genel Konular:** Veri, bilgi (knowledge) ayrımı, bilginin bilgisayar ortamında mantıksal/sembolik olarak gösterilmesi ve işlenmesi.
* **Hocanın Vurgusu:** Veri ham girdidir; bilgi ise bir bağlam içinde karar verme süreçlerinde kullanılabilen anlamlı çıktıdır.

### 🔹 Ders 10 & 11: Makine Öğrenmesi ve Karar Ağaçları
* **Genel Konular:** Örüntü tanıma, denetimli öğrenme alt dalları (Sınıflandırma vs. Regresyon) ve karar ağaçları.
* **Hocanın Vurgusu:** Problemin türünü belirleyen şey çıktı (etiket) değişkeninin sürekli mi yoksa kategorik mi olduğudur. Karar ağaçları anlaşılması kolay, açıklanabilir güçlü modellerdir.

### 🔹 Ders 12: Sınıflandırma Sınırları ve Yapay Sinir Ağları
* **Genel Konular:** Doğrusal (linear) ve doğrusal olmayan (non-linear) karar sınırları, Yapay Sinir Ağlarının doğrusal olmayan verilerdeki gücü ve denetimsiz öğrenmede Kümeleme (Clustering).
* **Hocanın Vurgusu:** Her problem doğrusal karar sınırıyla çözülemez. Ancak her problem için de doğrudan en karmaşık model (YSA vb.) seçilmemelidir; ihtiyaç ve veri yapısı analizi yapılmalıdır.

### 🔹 Ders 13: Pekiştirmeli Öğrenme (Reinforcement Learning)
* **Genel Konular:** Ajan ve ortam etkileşimi, durum, eylem, ödül/ceza mekanizması, politika (policy) ve değer fonksiyonu.
* **Hocanın Vurgusu:** Pekiştirmeli öğrenme, etiketli verilerle çalışan denetimli öğrenmeden farklıdır. Amaç anlık ödülü değil, uzun vadeli toplam getiriyi maksimize etmektir.
