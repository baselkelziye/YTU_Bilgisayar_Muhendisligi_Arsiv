Ödev için kullanacağınız verisetine ve veriseti ile alakalı açıklayıcı bilgilere https://www.robots.ox.ac.uk/~vgg/data/oxbuildings/ adresinden ulaşabilirsiniz.

Veriseti içerisinde 17 farklı yapıya ait resimler bulunmaktadır.  Herbir yapı için train / test / validation setlerini oluşturunuz.

1) Train ve Validation seti kullanarak, derste de anlatıldığı üzere, 3 tane convolutional hidden layer ve bunların ardından gelen 2 tane fully-connected (keras için ismi Dense() fonksiyonu) bulunan bir network tasarlayıp sınıflandırma işlemini gerçekleştiriniz.

Bu aşamada ekte paylaşılan Fashion-Mnist kodundaki CNN_Model kısmını inceleyebilir, oradan destek alabilirsiniz.

Eğtimi tamamlanan convolutional neural network konfigürasyonunuzu test set üzerindeki sonuçlarını accuracy ve loss olarak paylaşınız.

 

2) Eğitimi tamamlanan network'ünüzü kullanarak;

a) Verisetindeki her bir imgenin fully-connected katmanındaki (isterseniz ilki, isterseniz ikincisi olabilir) çıktılarını o resim için karşılık gelen bir öznitelik olarak kaydediniz.

b) Daha önce ayırmış olduğunuz test setindeki imgeler için en yakın resimleri bu öznitelik vektörü üzerinden hesaplayınız. Bu aşamada mesafe hesabı için Euclidean Mesafesi  kullanabilirsiniz.

 

* Fully-connected katmanındaki özniteliklerin elde edilmesi için https://androidkt.com/get-output-of-intermediate-layers-keras/ adresinde ki yapıyı inceleyebilirsiniz.

3) İlk iki soruda, yeni bir network tasarlamanız, eğitmeniz ve eğitilmiş network ün ağırlıkları üzerinden her bir imge için öznitelik vektörü elde etmeniz beklenmişti. Bu soruda ise Imagenet yarışmasında eğitilmiş VGG-16 network ünün ağırlıklarını Keras’ın kendi built-in fonksiyonları ile indirmeniz beklenmekte (https://keras.io/applications/) ve VGG-16 networkünün ilk fully-connected katmanındaki ağırlıkları kullanarak test setinizdeki imgeler için en yakın imgeleri elde etmeniz beklenmektedir.

* Üç numaralı soruda herhangi bir eğitim yapmayacak, zaten eğitilmiş olan network ün ağırlıklarını kullanarak en benzer imgeleri elde etmeniz beklenmektedir.

 

 

Önemli Not: Ödev içerisinde Keras üzerinden örnekler verilmiş olmasına rağmen, diğer popüler derin öğrenme frameworkleri de bu özellikleri sunmaktadır. Dilerseniz diğer frameworkleri de kullanabilirsiniz. 

Başarılar


https://sebastianraschka.com/pdf/lecture-notes/stat479ss19/L03_perceptron_slides.pdf 

 

https://sebastianraschka.com/pdf/lecture-notes/stat479ss19/L05_gradient-descent_slides.pdf 

 

https://sebastianraschka.com/pdf/lecture-notes/stat479ss19/L09_mlp_slides.pdf  

http://cs231n.stanford.edu/slides/2019/cs231n_2019_lecture05.pdf 

 

http://cs231n.stanford.edu/slides/2017/cs231n_2017_lecture4.pdf

 

https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/ 
