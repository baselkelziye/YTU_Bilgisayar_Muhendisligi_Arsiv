# Paper Presentation

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

[Proje Avesis Doküman Linki](https://avesis.yildiz.edu.tr/resume/downloadfile/svarli?key=499737ad-8826-47cb-92b4-319b7ee32352)  
Scien Dedirect Makale Linki: [A Methodology Based on Trace-based​ Clustering for Patient Phenotyping](https://www.sciencedirect.com/science/article/pii/S0950705121007310)  
[YouTube Sunum Linki: Önder Görmez](https://www.youtube.com/watch?v=9nWkNp0wrH8)

# A Methodology Based on Trace-based​ Clustering for Patient Phenotyping

Yazarlar;
* a: Antonio Lopez-Martinez-Carrasco, 
* a: Jose M. Juarez,
* a, b: Manuel Campos
* a: Bernardo Canovas-Segura

Yayında Emeği Geçen Kurumlar;
* a: AIKE Research Group (INTICO), University of Murcia, Spain
* b: Murcian Bio-Health Institute (IMIB-Arrixaca), Spain

0950-7051/© 2021 The Author(s). Published by Elsevier B.V.
* Accepted 7 September 2021

# Keywords
* Clustering
* Patient phenotype
* Methodology
* Subgroup discovery

# Teknik Terimler
**Phenotype (Fenotip)**: Klinik tıpta bir hastalığın ortaya çıkışı hakkında konuşmak için kullanılan terimdir.

# Hangi konu ile alakalı?

Antimicrobial resistance use case;​
* by employing the MIMIC-III open-access database​
* This is a public database that contains the health-related data of more than 45,000 patients treated in intensive care units and around 60,000 admissions between 2001 and 2012​

for patients infected with the​
* Methicillin-resistant Staphylococcus Aereus​
* and Enterococcus Faecium treated with Vancomycin

# Amacı nedir?

* Bakterilerin antibiyotiklere direncini belirlemek için makine öğrenmesinin **conventional clustering** veya **subgroup algorithms** yöntemlerinden yararlanmaktır.

* Yeni önerdikleri yöntem **trace-based clustering** yöntemidir.
* Adımları;
  1) Extraction and transformation of data and analysis of clustering tendency
  2) Selection of clustering algorithm and parameters
  3) Automatic generation of candidate clusters,
  4) Visual support for selection of candidate clusters, and
  5) Evaluation by clinical experts.

# Kapsam ve çalışma nerelere dokunmuş?

* Hopkins statistic in order to evaluate the clustering tendency of the data​
* K-Means algorithm for clustering​
* Dice coefficient to measure the similarity of the clusters​

​
* 370 potential patient sets (clusters) so as to obtain 19 candidate clusters​
* reduced set of consistent candidate clusters with a common phenotype (resistance and death)​
* An expert in the domain could add labels with clinical meaning to the reduced number of clusters

# Deneysel çalışmalarda ne elde edilmiş?

* Our experiments confirm that quality measures, and the visual analysis could help expert clinicians to control the knowledge discovery process and obtain interpretable results​

* (experiment 1, k = 150), we had to compute 1,676,100 comparisons among clusters.​
* (experiment 2, k = 105), we had to compute 573,195 2 comparisons among clusters.​
* (experiment 3, k = 115), we had to compute 753,710 comparisons among clusters.

# Neyi, ne kadar çözmüş?

* Supervised learning yöntemleri ile uygulanan çalışmalarda dataların etiketlenmesi (labeling) gerektiği için klinik uzmanların çok büyük bir ön çalışma ile örnekleri etiketlemesi gerekmektedir.
* Bu çok uzun bir süreçtir ve klinik uzmanların bu süreçteki yükü çok fazladır. İşlerinden arta kalan zamanlarda bu işlemi yapmaları yıllar alabilir.
* Bu çalışmada ise etiketleme işlemi yapılmadan (unsupervised learning) cluster lar elde edilmiştir.
* Elde edilen çıktılar klinik uzmanların analizine sunularak sonuçların yorumlanması istenmiştir.

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Makalede herhangi bir feature work e değinilmemiş.

# Conclusion

* Görsel analizin klinik uzmanlara yardımcı olabileceğini ve bilgi keşfi sürecinde yorumlanabilir sonuçlar ortaya çıkarabileceğini söylemişler.
* Kullandıkları yöntemin genel ve başka problemlere kolayca addapte edilebilir bir yöntem olduğunu söylüyorlar.
