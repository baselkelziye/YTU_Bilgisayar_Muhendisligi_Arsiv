# Proje İlerleme Raporu

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035  
Konu: Credit Card Fraud Detection

# Okunan Makaleler

* Proje önerisinde verilen **makale 1 okunmuş** ve önemli görülen kısımlar çalışmada kullanılmak üzere **not alınmıştır**.
* Proje önerisinde verilen **makale 4 okunmaya başlanmış**, fakat çalışma detaylı olduğu için daha tamamlanmamıştır. Özellikle bu makale kullanmayı hedeflediğimiz **veri setinin detaylarına dair bilgiler ve deneysel sonuçlar** içermektedir. Bu nedenle bu makaleye öncelik verilmiştir.

## Paper 1

- [x] [Credit Card Fraud Detection Using Lightgbm Model](https://ieeexplore.ieee.org/document/9134072)
* Authors: Dingling Ge; Jianyang Gu; Shunyu Chang; JingHui Cai
* Publisher: IEEE
* Published in: 2020 International Conference on E-Commerce and Internet Technology (ECIT)
* Date of Conference: 22-24 April 2020
* Conference Location: Zhangjiajie, China

## Paper 4
- [x] [Credit Card Fraud Detection Using State-of-the-Art Machine Learning and Deep Learning Algorithms](https://ieeexplore.ieee.org/document/9755930)
  * Authors: Fawaz Khaled Alarfaj; Iqra Malik; Hikmat Ullah Khan; Naif Almusallam; Muhammad Ramzan; Muzamil Ahmed
  * Publisher: IEEE
  * Published in: IEEE Access (Volume: 10)
  * Date of Publication: 12 April 2022


# Veri Seti Değişimi
* Proje önerisinde belirtilen 1. veriseti (Kaggle Dataset - [IEEE-CIS Fraud Detection](https://www.kaggle.com/competitions/ieee-fraud-detection/overview)) incelenmiş ve özellikleri ve **boyutunun çok büyük (1.35 GB) olması nedeniyle** ön işlemesi ve kullanımının çok uzun süreler alacağına karar verilmiştir.
* Ve ayrıca yukarıda okunmaya başlayan **makale 4 te ve diğer makalelerde** de yine proje önerisinde belirtilen **2. verisetinin daha detaylı incelendiği** görülmüştir.

Yukarıda belirtilen nedenlerle ve 2. veriseti (Kaggle Dataset - [Credit Card Fraud Detection](https://www.kaggle.com/datasets/mlg-ulb/creditcardfraud/data)) üzerinde yapılan incelemeler neticesinde, **projenin çalışmalarına 2. veriseti ile devam edilmesine karar verilmiştir**. Veri setinin özelliklerine dair bilgiler aşağıdaki gibidir.

## 2. Veri Seti Özellikleri
* Yukarıdaki nedenle [Credit Card Fraud Detection](https://www.kaggle.com/datasets/mlg-ulb/creditcardfraud/data) dataseti üzerinde çalışılmaya başlanmıştır.

Veri setinin temel özellikleri;
* **Size:** 150.83 MB
* creditcard.csv
* Avrupa'da 2013 yılında yapılan işlemleri içerir
* 2 gün içinde gerçekleşen işlemler
* 284315 transfer içinde 492 fraud transfer
* Yüksek dengesizlik oranı (highly unbalanced)
* Yüzde 0.172 fraud transfer

Dataset üzerinde aşağıdaki klasik makine öğrenmesi algoritmalarının en az 3 tanesinin uygulanması hedeflenmektedir.
* Decision Trees
* Naive Bayes
* K-Nearest Neighbors
* K-Means
* Linear Regression
* Logistic Regression
* Support Vector Machines (SVM)
