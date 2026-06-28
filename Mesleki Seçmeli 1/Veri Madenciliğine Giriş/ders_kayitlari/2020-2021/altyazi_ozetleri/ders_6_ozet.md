# Ders 6 Çalışma Özeti

## Genel Konular

- Naive Bayes sınıflayıcı
  - Naive Bayes, Bayes teoremine dayalı olasılıksal bir sınıflama yöntemidir.
  - Öz niteliklerin sınıf koşulu altında birbirinden bağımsız olduğu varsayımıyla hesaplamayı basitleştirir.
- Posterior olasılık ve karar verme
  - Her sınıf için gözlenen öz nitelikler altında olasılık hesaplanır.
  - En yüksek posterior olasılığa sahip sınıf tahmin sonucu olarak seçilir.
- K-en yakın komşu yöntemine giriş
  - KNN, yeni örneği eğitim verisindeki en yakın komşuların sınıfına göre etiketleyen örnek tabanlı bir yöntemdir.
  - K değeri ve uzaklık ölçüsü yöntemin davranışını belirler.
- Dengesiz veri problemi
  - Sınıflar arasında büyük oran farkı varsa model başarısı yalnızca doğruluk oranıyla değerlendirilemez.

## Hocanın Özellikle Vurguladığı Kısımlar

- Naive Bayes'teki bağımsızlık varsayımı
  - Bu varsayım gerçek hayatta her zaman tam sağlanmasa da yöntemi pratik ve hızlı hale getirir.
- KNN'de K seçimi
  - Çok küçük K gürültüye duyarlı, çok büyük K ise sınıf sınırlarını fazla yumuşatan sonuçlar üretebilir.

## Kısa Tekrar Notları

- Naive Bayes olasılıksal sınıflayıcıdır.
- En yüksek posterior olasılık sınıf tahminini verir.
- KNN komşuluk ve uzaklık ölçüsüne dayanır.
- Dengesiz veri accuracy ile tek başına değerlendirilemez.

## Detaylı Açıklamalar

- Derste Naive Bayes sınıflayıcının temel mantığı, sınıf olasılıkları ile öz nitelik olasılıklarının birlikte kullanılması olarak açıklanır. Her sınıf için verinin o sınıfa ait olma olasılığı hesaplanır ve karşılaştırılır.
- Yöntemin naive olarak adlandırılmasının nedeni, öz nitelikler arasında koşullu bağımsızlık varsayımı yapmasıdır. Bu varsayım hesaplamayı kolaylaştırır ve özellikle metin sınıflama gibi yüksek boyutlu problemlerde pratik avantaj sağlar.
- KNN tarafında model açık biçimde parametre öğrenmez; eğitim örneklerini saklar ve yeni örnek geldiğinde yakınlık hesabı yapar. Bu nedenle ölçekleme, uzaklık metriği ve K değeri kritik hale gelir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
