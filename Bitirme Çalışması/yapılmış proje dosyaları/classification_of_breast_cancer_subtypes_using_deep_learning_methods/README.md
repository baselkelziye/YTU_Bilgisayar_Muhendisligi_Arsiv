This study was presented at the SIU2024 conference and shared on the IEEE Explore website (https://ieeexplore.ieee.org/abstract/document/10600977).


The dataset used in this project is the open source BRACS which divides breast cancer into 3 categories: benign, malignant and unusual. The dataset is divided into test, training and validation parts and contains hematoxylin and eosin stained RoI images for each category. 

The project aims to achieve high accuracy rates by enabling automatic feature extraction and sectioning of breast cancer images through deep learning methods. 

In the data preprocessing stage, a new dataset was extracted from the BRACS dataset with the K-Means Clustering method to obtain higher accuracy by taking the pixels with the majority of cancer cells (128x128, 256x256, 512x512).

In the classification phase, various deep learning classification models of the Keras library were used to obtain high accuracy rates for 3 and 7 subtypes by finding the parameters that would provide maximum performance. The recorded models were subjected to F1, Overall Accuracy (OA) and Kappa tests to show the accuracy rates.
