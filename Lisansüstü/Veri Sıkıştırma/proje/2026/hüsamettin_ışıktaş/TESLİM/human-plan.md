Proje: Auto-encoder based content aware profile based text compression
Bu proje hangi sorunu çözüyor? Çözmeyi amaçladığı yöntem nedir nasıl çalışıyor vs onu anlatacağız önce. Kabaca bir küçük bir auto-encoder eğiteceğiz. Bu auto-encoder profilleme yapacak. İlgili profili en iyi sıkıştıran algoritmayı seçeceğiz.

Faz 1:
Veriseti indirme ve data explarotry aşaması: (indirecğeimiz kitapları ya da bütün chunk'ları karıştırıp direkt train-test-val bölümü kesinlikle yapmalıyız. Test verisetindeki bir kitap'ın bölümü hiç train vala girmese daha iyi olabilir belki emin değilim. Sen onu halledersin hangisi doğruysa)Chunk size'ı ve profil sayısını belirlemek için veriyi incelememiz gerek. Farklı plot'lar çeşitleri vs dahil edilmeli. Data explaroty aşamasında hem hangi özellikleri kullanacağımıza karar vereceğiz. Hem de hangi chunk size'ı seçecğeimize karar vereceğiz. O yüzden farklı parametrelerle verisetinde nasıl dağılımlar gösterdiğni farklı tablolar üzerinde görebilmemiz gerek. Buradan toplam profil sayısına vs karar vereceğiz. Clustering vs kullanarak belirlediğimiz sayıda profile bölebilriz direkt. Ve cluster'ları direkt class olarak atayalım. Arada kalan cluster'ları vs kaldırabilriz. Yalnızca kesin ve net bir şekilde o cluster'da olduğunu bildiğimiz metinleri o profile atayabiliriz.

Faz 2:
Belirttiğimiz profilleri en iyi sıkıştıran algoritmalar hangileri bunun için her profildeki metinler için ortalamada en iyi sonuç veren algoritmayı seçeceğiz

Faz 3:
Auto-encoder eğitim aşaması. Elimizde clustering'den profil'leri belirlenmiş, etiketlenmiş veriler var. Artık auto-encoder ile text to class bir pipeline yazacağız. Auto-encoder eğiteceğiz. Niye eğitiyoruz. auto-encoder'ın ürettiği vektör daha anlamlı olacak. ve cluster'a göre daha mantıklı bir sınıflandırma ypaacka. Clustering arada kalanlar konsunda yanlış sınıflandırmaya daha meyilli olabilir.

Faz 4:
Test verisetindeki metinleri auto-encoder'a verip profillerini çıkarıp o profile uygun şekilde metni şifreleyeceğiz. İdeal chunk-size'ı faz 1'de halledeceğimiz için header'ın varlığı sorun olmayacaktır.