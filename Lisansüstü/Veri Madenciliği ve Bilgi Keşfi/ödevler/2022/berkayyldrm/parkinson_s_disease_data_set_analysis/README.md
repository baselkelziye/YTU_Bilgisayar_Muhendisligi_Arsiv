# Parkinson-s-Disease-Data-Set-Analysis
YTU MSc Data Mining Course

## Data Set Information

Data set link : https://archive.ics.uci.edu/ml/datasets/Early+biomarkers+of+Parkinson%E2%80%99s+disease+based+on+natural+connected+speech

**Abstract**: Predict a pattern of neurodegeneration in the dataset of speech features obtained from patients with early untreated Parkinson's disease and patients at high risk developing Parkinson's disease.

**Data Set Characteristics** : *Multivariate*

**Number of Instances** : *130*

**Area** : *Life*

**Attribute Characteristics** : *Integer, Real*

**Number of Attributes** : *65*

**Date Donated** : *2017-02-15*

**Associated Tasks** : *Classification, Regression*

**Missing Values?** : *Yes*

**Number of Web Hits** : *5719*


### Source:

The dataset was collected at Charles University in Prague, First Faculty of Medicine, Department of Neurology and Centre of Clinical Neuroscience, Prague, Czech Republic. Speech features were automatically analysed by HlavniÄka et al. (2017).


### Data Set Information:

The dataset include 30 patients with early untreated Parkinson's disease (PD), 50 patients with REM sleep behaviour disorder (RBD), which are at high risk developing Parkinson's disease or other synucleinopathies; and 50 healthy controls (HC). All patients were scored clinically by a well-trained professional neurologist with experience in movement disorders. All subjects were examined during a single session with a speech specialist. All subjects performed reading of standardized, phonetically-balanced text of 80 words and monologue about their interests, job, family or current activities for approximately 90 seconds. Speech features were automatically analyzed by HlavniÄka et al. (2017).

The dataset is provided in xls and csv format. The table is organized as follows:

* First two rows include header
* First row denote sections (Demographic information, Clinical information, etc.)
* Second row denote attribute
* Each row in range from 3 to 132 corresponds to one particular subject identified by a unique code (first column). The code indicate also clinical diagnosis of the subject (PD, RBD, or HC)

For further details about the computational procedures, please see HlavniÄka (2017), or contact rusz.mz (at) gmail.com.


### Attribute Information:

* Participant code = unique code for identification of a subject and diagnosis (PD = Parkinsonâ€™s disease, RBD = rapid eye movement sleep behaviour disorder, HC = Healthy control)
* UPDRS III = Unified Parkinson's Disease Rating Scale III, accordingly to: Stebbins, G. T. & Goetz, C. G. Factor structure of the Unified Parkinson's Disease Rating Scale: motor examination section. Mov. Disord 13, 633â€“636 (1998).
* Gender 'F' = female
* Gender 'M' = male
* Speech examination: speaking task of reading passage = speech features analyzed on reading passage
* Speech examination: speaking task of monologue = speech features analyzed on monologue

### Citation
HlavniÄka, J., ÄŒmejla, R., TykalovÃ¡, T., Å onka, K., RÅ¯Å¾iÄka, E., and Rusz, J. (2017). Automated analysis of connected speech reveals early biomarkers of Parkinsonâ€™s disease in patients with rapid eye movement sleep behaviour disorder. Scientific Reports, 7(1), 12.

## Study

1. Data Analysis: Extracting information such as the content of the data set, the meaning of the features used, the number and names of classes, the number of samples per class. Sorting the features in the dataset according to their distinctiveness in classification and removing any missing data. Also performing Outlier Analysis.

2. Classification: Researching the most successful classification methods and selecting and examining 3 of them in detail, comparing classification performances and class confusion matrices.

3. Clustering: Researching the most successful clustering methods and selecting 3 of them and examining them in detail. Labeling the clusters by using the class labels of the samples in the evaluation phase at the end of the clustering and comparing the clustering successes.
