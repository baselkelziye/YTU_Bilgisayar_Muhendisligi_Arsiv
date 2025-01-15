# Project Proposal - Credit Card Fraud Detection

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Aims of the Project
* Bu projede, veri setinde nadir olarak karşılaşılan ama aslında tespit etmeye çalıştığımız bir durum olan kredi kartı dolandırıcılığının tespiti üzerine yapılmış geçmiş çalışmalar incelenecektir.  
* Dersin ana konusu olan **klasik makine öğrenmesi** konularına odaklanılmakla birlikte **derin öğrenme** algoritmaları da incelenecektir.

# Some of the Publicly Available Datasets
* Kaggle Dataset - [IEEE-CIS Fraud Detection](https://www.kaggle.com/competitions/ieee-fraud-detection/overview)
* Kaggle Dataset - [Credit Card Fraud Detection](https://www.kaggle.com/datasets/mlg-ulb/creditcardfraud/data)
* Kaggle Dataset - [Fraud ecommerce](https://www.kaggle.com/datasets/vbinh002/fraud-ecommerce)
* Kaggle Dataset - [Credit Card Transactions Fraud Detection Dataset](https://www.kaggle.com/datasets/kartik2112/fraud-detection)

Yukarıdaki datasetler incelendiğinde IEEE'nin düzenlediği yarışma için hazırlanan [IEEE-CIS Fraud Detection](https://www.kaggle.com/competitions/ieee-fraud-detection/overview) verisetinin daha geniş olduğu görülmüştür. Bu nedenle bu veriseti üzerinde çalışılması planlanmaktadır.

Veri setinin temel özellikleri;
* **Size:** 1.35 GB
* **Transaction Table:** Yapılan İşlemlerin tutulduğu tablo. Bazı öne çıkan özellikler;
  * Müşterinin kart sayısı
  * Yapılan işlemin tutarı
  * İşlem tarihi
  * ...
* **Identity Table:** Kimlik bilgisi, cihaz bilgisi ve IP gibi kişiye özel bilgilerin tutulduğu tablo. Bazı öne çıkan özellikler;
  * Device Info
  * IP Address
  * ISP
  * ...

Dataset üzerinde aşağıdaki klasik makine öğrenmesi algoritmalarının en az 3 tanesinin uygulanması hedeflenmektedir.
* Naive Bayes
* Linear Regression
* Logistic Regression
* Decision Trees
* K-Nearest Neighbors
* K-Means
* Support Vector Machines (SVM)

# Articles to Benefit From

Aşağıdaki makalelerden en az 5 tanesinden yaralanılmak istenmektedir.

## Paper 1

[Credit Card Fraud Detection Using Lightgbm Model](https://ieeexplore.ieee.org/document/9134072)
* Authors: Dingling Ge; Jianyang Gu; Shunyu Chang; JingHui Cai
* Publisher: IEEE
* Published in: 2020 International Conference on E-Commerce and Internet Technology (ECIT)
* Date of Conference: 22-24 April 2020
* Conference Location: Zhangjiajie, China

## Paper 2
[CatBoost for Fraud Detection in Financial Transactions](https://ieeexplore.ieee.org/document/9342475)
* Authors: Yeming Chen; Xinyuan Han
* Publisher: IEEE
* Published in: 2021 IEEE International Conference on Consumer Electronics and Computer Engineering (ICCECE)
* Date of Conference: 15-17 January 2021
* Conference Location: Guangzhou, China

## Paper 3

[A Data Mining Based Fraud Detection Hybrid Algorithm in E-bank](https://ieeexplore.ieee.org/document/9196322)
* Authors: Zijian Song
* Published in: 2020 International Conference on Big Data, Artificial Intelligence and Internet of Things Engineering (ICBAIE)
* Publisher: IEEE
* Published in: 2020 International Conference on Big Data, Artificial Intelligence and Internet of Things Engineering (ICBAIE)
* Date of Conference: 12-14 June 2020
* Conference Location: Fuzhou, China

## Paper 4
[Credit Card Fraud Detection Using State-of-the-Art Machine Learning and Deep Learning Algorithms](https://ieeexplore.ieee.org/document/9755930)
  * Authors: Fawaz Khaled Alarfaj; Iqra Malik; Hikmat Ullah Khan; Naif Almusallam; Muhammad Ramzan; Muzamil Ahmed
  * Publisher: IEEE
  * Published in: IEEE Access (Volume: 10)
  * Date of Publication: 12 April 2022

## Paper 5

[Identifying Fraudulent Credit Card Transactions Using Ensemble Learning](https://ieeexplore.ieee.org/document/10477993)
  * Authors: Jaber Jemai; Anis Zarrad; Ali Daud
  * Publisher: IEEE
  * Published in: IEEE Access (Volume: 12)
  * Date of Publication: 22 March 2024

## Paper 6

[Credit Card Fraud Detection Based on Machine and Deep Learning](https://ieeexplore.ieee.org/document/9078935)
  * Authors: Hassan Najadat; Ola Altiti; Ayah Abu Aqouleh; Mutaz Younes
  * Publisher: IEEE
  * Published in: 2020 11th International Conference on Information and Communication Systems (ICICS)
  * Date of Conference: 07-09 April 2020
  * Conference Location: Irbid, Jordan

## Paper 7

[Anomaly Detection via Online Oversampling Principal Component Analysis](https://ieeexplore.ieee.org/document/6200273)
* Authors: Yuh-Jye Lee; Yi-Ren Yeh; Yu-Chiang Frank Wang
* Publisher: IEEE
* Published in: IEEE Transactions on Knowledge and Data Engineering (Volume: 25, Issue: 7, July 2013)
* Date of Publication: 15 May 2012
