# ARA-PROJE
YTU CE ARA PROJE- TWİTTER'DA DUYGUDURUM ANALİZİ

Projenin konusu ’Twitter’da duygudurum analizi’ dir.Twitter metinleri olumlu,
olumsuz veya nötr sınıflarından biriyle doğru bir ¸sekilde etiketlemektir.

Duygudurum analizi projesinde öncelikle veri setimizi analize hazır hale getirmek
için ön işlem aşamasından geçirdikten sonra ,python dilinde jupyterde ski-learn
kütüphanesi kullanılarak klasik makine öğrenmesi algoritmaları kelime ve karakter
seviyeli farklı n gramlar ile çalıştırılmıştır , en iyi sonuçlar kelime seviyeli 2 gramlardan
alınmıştır.Python’da keras kütüphanesi kullanılarak google colaboratary’nin sağladığı
GPU ile derin öğrenme algoritmaları farklı kelime vektörleri ve kernal_size’lar için
çalıştırılmıştır en iyi sonuçlar CNN modelinden kernal_size 3 iken alınmıştır.
