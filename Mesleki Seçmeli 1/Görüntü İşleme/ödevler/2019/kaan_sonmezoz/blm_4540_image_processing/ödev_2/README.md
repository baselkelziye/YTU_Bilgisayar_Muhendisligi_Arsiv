Konu : İçerik Tabanlı Görüntü Erişimi (Content Based Image Retrieval) Uygulaması : Bir resmin renk ve doku bilgisine göre benzerlerinin bulunması

Açıklama : Bu ödevde resimlerin renk ve doku benzerliklerini değerlendirerek bir resme en çok benzeyen 5 adet resmi bulan bir sistem tasarlanacak ve gerçeklenecektir.

İşlem Adımları : Ödev 2 aşamadan oluşmaktadır.

1.       Veritabanındaki resimlerin hazırlanması : Aşağıdaki işlemleri eğitim veritabanındaki bütün resimler için sadece 1 defa yapınız. Elde ettiğiniz sonuçları kullanmak için saklayınız.
Renk histogramlarının hesaplanması  :  Renk benzerliklerinin ölçülmesi için resimlerin renk histogramları kullanılacaktır. Resim veritabanındaki bütün resimlerin (R,G,B) histogramlarını(elinizde R,G ve B için toplam 3 histogram dizisi olacak) sadece bir kere hesaplayınız. Sonuçları mutlaka [0,1] aralığına normalize ediniz.
Yerel İkili Örüntü (Local Binary Pattern - LBP) kodlarının histogramlarının hesaplanması : LBP kodlarının histogramı için önce resimdeki her pikselin LBP değerini hesaplayınız. Daha sonra bunları kullanarak resmin LBP histogramını hesaplayınız. Sonuçları mutlaka [0,1] aralığına normalize ediniz.
 

2.       Örnek Test Resimleri İle Sistem Başarısının Ölçülmesi:Test aşamasında aşağıdaki işlemleri yapınız.
Her test resmi için test resminin önce renk histogramını sonra LBP histogramını eğitim örnekleri için yaptığınız gibi hesaplayınız.
Resimlerin benzerliklerini ölçerken verilen test resminin eğitim resimlerinin hepine mesafesini aşağıdaki gibi bulun:
                                                               i.      Sadece renk benzerliklerini ölçmek için Manhattan City Block (L1 norm) yöntemi ile R,G ve B histogramları arasındaki toplam mesafeyi bulun. Mesafenin en az olduğu 5 eğitim resminin isimlerini ekrana yazdırın.

                                                             ii.      Sadece doku benzerliklerini ölçmek için Manhattan City Block (L1 norm) yöntemi ile R,G ve B histogramları arasındaki toplam mesafeyi bulun. Mesafenin en az olduğu 5 eğitim resminin isimlerini ekrana yazdırın.

 

Test İşlemleri  :  Programın çalışma başarısını http://www.vision.caltech.edu/Image_Datasets/Caltech101/ linki altındaki accordion, dalmatian, water_lilly, dolphin, wild_cat, leopards, schooner başlığı altında bulunan resimleri kullanılarak değerlendiriniz. Her resim türü için(örneğin accordion altındaki resimler) ilk 10 resmi eğitim için kullanın, sonraki 10 resmi test için kullanın. Bu durumda toplam 70 adet resim için test yapmış olacaksınız.
