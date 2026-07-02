önce cub'da denedim hepsini, oradaki sonuçlar iyileştiğini gösteriyordu.
sonra inat üzerinde denedim. concat'ta hepsini dahil edemedim orda.
o yüzden concat'ta en başarılı ikisini dinov3 ve dinov2 olanlarını uç uca ekleyip eğittim. NOTE 0.75

dino'lar aynı mimari o yüzden dinov3 + başka bir mimari olan bir modelle uç uca eklemece yapacağım.
dino + başka model yapacağım. 

convnext için boyut indirgeme yaptım.

DONE conv + dinov3 toplayıp eğitiyorum. muhtemelen kötü çıkacak  NOTE 0.69

DONE dino'ları toplayıp eğiteceğim NOTE 0.72 falan olcak

DONE dino + conv uç uca ekleme eğiteceğim. 

DONE farklı embeddinglerle eğtiilmiş mlp'leri birleştircem.


NOTE modeller birbiri ile ne kadar aynı sonuçları veriyorlar ne kadar bilebiliyorlar bunu ölçtüm. ona göre farklı modellerin ensemble edilip edilmemesi ile ilgili daha farklı sonuçlar elde edebileceğim

DONE farklı prensiplerde birleştirdiğim modellerin ve farklı şekilde birleştirdiğim modellerin birbiriyle ne kadar benzer kararlar verdiğini ölçtüm. birbiriyle farklı kararlar vermeleri ensemble açısından önemli.

3 farklı ensemble stratejisi yaptık aslında
embed concat
embed sum
mlp ensemble, kararların ortalamasını alıyoruz
mlp ensemble, modelleri birleştiriyoruz? birleştiremedik çünkü modeller farklı embeddinglerle eğitiliyor


