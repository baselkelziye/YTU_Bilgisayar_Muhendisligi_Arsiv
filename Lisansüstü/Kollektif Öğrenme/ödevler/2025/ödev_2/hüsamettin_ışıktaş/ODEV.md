Kolektif Öğrenme, 2025-2026 Güz
Ödev No: 2
Ödev Konusu: Tez Yılı Tahmininde Kolektif Öğrenme

Yapılacaklar:

[https://huggingface.co/datasets/umutertugrul/turkish-academic-theses-dataset](https://huggingface.co/datasets/umutertugrul/turkish-academic-theses-dataset) adresinde yer alan Türkçe tez özetleri, Türkçe tez başlıkları ve yılları bilgilerini alınız.

2001-2025 yıllarının her biri için **500'er tezi** seçiniz. Üniversiteler ya da tez konuları arasında **rastgele seçim** yapınız. Toplamda $500 \times 25 = 12500$ tez bilgisi olacaktır.

Her yıl için **250 tezi eğitim**, **250 tezi test** için ayırınız.

[https://huggingface.co/ytu-ce-cosmos/turkish-e5-large](https://huggingface.co/ytu-ce-cosmos/turkish-e5-large) ile tez başlık ve özetlerinin **temsillerini** elde ediniz.

Temsilleri ayrı ayrı ve yan yana birleştirerek **2 veri kümesi** (başlıktan yıl tahmini, özetten yıl tahmini) için **3 farklı temsil** elde ediniz (başlık, özet, başlık özet). Toplamda **6 veri kümesi** olacaktır.

Bu 6 veri kümesini **Bagging, Random Subspace, Random Forest** algoritmaları ile modelleyip **performans karşılaştırması** yapınız.

Algoritmaların **hiper parametre optimizasyonlarını** en az 2 hiper parametre için yapınız.

Sonuçlarınızın anlaşılabilirliğini artırmak için **tablo, grafik, şekil vb.** kullanmanız önerilir. Sonuçlarınıza dair yaptığınız **yorumlar** önemlidir.

---

Notlandırma: Sınıfta sunum yapmayanlar en fazla 30/100 not alabilirler.

Ödevin Son Teslim Tarihi: **2 Aralık 2025 saat 08:59**

Ödevin Teslim Şekli: online.yildiz.edu.tr

Bu ödevde en çok **2 kişilik gruplar** halinde çalışabilirsiniz. Grup çalışmalarında, sadece 1 kişinin ödevi yüklemesi yeterlidir. Grup çalışmalarında, 2 kişinin isimleri teslim edilen raporun ilk sayfasında yer almalıdır.

2 Aralık'taki derste ödev, raporunuz üzerinden sunulacaktır.

---

Ödevde Teslim Edilecekler:

1- Açıklama içeren **kodlarınız** (değişkenlerin ne için kullanıldıkları, algoritmanın adımları)
2- **pdf formatında ödev raporu**

Not 1: Ödevde dil kısıtlaması yoktur.

Not 2: Ödev yapımında ticari dil modellerinden yardım alabilirsiniz, ancak raporunuz tamamen size ait olmalıdır.