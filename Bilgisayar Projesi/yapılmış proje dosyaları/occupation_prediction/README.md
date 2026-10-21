# Occupation Prediction from Twitter Data

## Overview
This project aims to predict the occupation of Twitter, now known as X, users based on their Turkish tweets. The study utilizes machine learning and deep learning techniques to analyze two datasets comprising 10,000 , 15,000 , 20,000 , 25,000 and 30,000 tweets, respectively. Various models, including Logistic Regression, Naive Bayes, Random Forest, Support Vector Machine, Multi-Layer Perceptron, Convolutional Neural Network, Recurrent Neural Network, BERT and COSMOS are evaluated to determine the best performance.

## Datasets
Five datasets are used in this project:
1. **Dataset 1:** 25,000 tweets from 10 different occupations (2,500 tweets per occupation).
2. **Dataset 2:** 30,000 tweets, an extended version of Dataset 1 with additional 5,000 tweets.

Other 3 datasets are a randomized reduction of the second dataset to 10,000, 15,000 and 20,000 tweets.

### Occupations Covered:
- Lawyer
- Dietitian
- Doctor
- Economist
- Teacher
- Psychologist
- Sports Commentator
- Historian
- Software Developer
- Agricultural Engineer

### Preprocessing Steps:
- Removal of punctuation
- Conversion to lowercase
- Removal of links
- Root extraction using Zeyrek and Zemberek libraries

## Feature Extraction
- **TF-IDF (Term Frequency-Inverse Document Frequency)**
- **Bag-of-Words Vectors**

## Models Used
### Machine Learning Models:
- Logistic Regression
- Naive Bayes
- Random Forest
- Support Vector Machine

### Deep Learning Models:
- Multi-Layer Perceptron (MLP)
- Convolutional Neural Network (CNN)
- Recurrent Neural Network (RNN)
  - Variants: GRU, LSTM, bi-LSTM

### Pre-trained Model:
- BERT (Bidirectional Encoder Representations from Transformers)
- COSMOS

## Results for Singular Data

| **Method Type**    | **Method**            |     **10K**    |   **15K** |     **20K** | **25K** |  **30K** |
|--------------------|-----------------------|------------|------------|--------------|--------------|--------------|
| **Machine Learning** | Support Vector Machine |  **0.71**    | 0.70     |    0.69       |  **0.71**      |  0.69
| **Machine Learning** | Logistic Regression   |   0.71   | 0.71     |    0.72       | **0.74**       |  0.73
| **Machine Learning** | Random Forest         |   0.59  | 0.58     |    0.59       |  **0.60**        |  0.59
| **Machine Learning** | Naive Bayes           |   0.70   | 0.72     |    0.71       |  **0.73**      |  0.72
| **Deep Learning**  | MLP                   |   0.70   | 0.71     |    0.72       |  **0.74**        |  0.73
| **Deep Learning**  | CNN                   |   0.68   | 0.69     |    0.70       |  **0.72**        | **0.72**
| **Deep Learning**  | LSTM                  |   0.62   | 0.63     |    0.65       |  0.66        |  **0.67**
| **Deep Learning**  | Bi-LSTM               |   0.65   | 0.64     |    0.68       |  **0.71**        |  0.69  
| **Deep Learning**  | GRU                   |   0.62   | 0.64     |    0.64       |  **0.68**        |  0.65
| **Pre-Trained**    | BERT                  |   0.75   | 0.75     |    0.76       |  0.76        |  **0.78**
| **Pre-Trained**    | COSMOS                  |   0.76   | 0.75     |    0.74       |  0.77      |  **0.78**

## Results for Pairwise Data

| **Method Type**    | **Method**            |     **10K**    |   **15K** |     **20K** | **25K** |  **30K** |
|--------------------|-----------------------|------------|------------|--------------|--------------|--------------|
| **Machine Learning** | Support Vector Machine |  0.85    | 0.85     |    **0.87**       |  0.85      |  0.83
| **Machine Learning** | Logistic Regression   |   0.85   | 0.85     |    **0.88**       | 0.85       |  0.85
| **Machine Learning** | Random Forest         |   0.75  | **0.76**     |    **0.76**       |  0.74        |  0.73
| **Machine Learning** | Naive Bayes           |   0.82   | 0.85     |    **0.86**       |  0.84      |  0.82
| **Deep Learning**  | MLP                   |   0.83   | 0.85     |    **0.88**       |  0.84        |  0.85
| **Deep Learning**  | CNN                   |   0.79   | 0.81     |    **0.84**       |  0.83        | 0.82
| **Deep Learning**  | LSTM                  |   0.71   | 0.74    |   **0.79**       |  0.77        |  0.75
| **Deep Learning**  | Bi-LSTM               |   0.72   | 0.76     |    **0.79**       |  0.78        |  **0.79**  
| **Deep Learning**  | GRU                   |   0.71   | 0.76     |    **0.77**       |  0.74        |  0.74
| **Pre-Trained**    | BERT                  |   0.86   | 0.88     |    **0.89**       |  0.88        |  0.87
| **Pre-Trained**    | COSMOS                  |   0.86   | **0.89**     |    **0.89**       |  0.88      |  0.87


## Results
- Highest accuracy rates are obtained when the data are grouped in pairs.
- The highest accuracy in the study is the 89% accuracy rate of the BERT and COSMOS models tested using pairwise data on the dataset containing 20,000 data. The same 89% accuracy rate was also obtained from COSMOS on a dataset of 15,000.
- It is also observed that the increase in the number of data generally increases the performance, especially in deep learning and pre-trained models.


## Future Work
- Exploring more sophisticated preprocessing techniques
- Testing additional machine learning and deep learning models
- Expanding the dataset to include more occupations and larger tweet samples
- Integrating other social media platforms for a broader analysis

## Datasets
The dataset of size 25.000 can be found [here](https://github.com/imayda/occupation-dataset-in-turkish).


## Contact
For any inquiries, please contact:
- Tolga İzdaş: [tolgaizdas@gmail.com](mailto:tolgaizdas@gmail.com)
- Hikmet İskifoğlu: [hikmet.iskifoglu@std.yildiz.edu.tr](mailto:hikmet.iskifoglu@std.yildiz.edu.tr)

