import pandas as pd
from sklearn.model_selection import KFold ## kendi metodunu yaz sonra vakit kalirsa

DATASET_PATH = "../data/with-headers/dataset.csv"

classes = {'team_1': 1, 'team_2': -1}


def read_dataset(file_path = DATASET_PATH):
    return pd.read_csv(file_path)

def remove_columns(dataset, columns = ["cluster_id"]):    
    return dataset.drop(columns=columns)

def get_class_samples(dataset):
    team_1 = filter_samples_by(dataset, "class", classes['team_1'])
    team_2 = filter_samples_by(dataset, "class", classes['team_2'])
    return team_1, team_2

def filter_samples_by(samples, column_name, column_value):
    sample_indexes = samples[column_name] == column_value
    return samples[sample_indexes]

def get_feature_column_names(samples):
    column_names = samples.columns.values.tolist()    
    column_names.remove('class') 
    
    return column_names

def calculate_probability_for(class_samples, feature_name, feature_value, occurences, class_name):
    sample_count = class_samples.shape[0]
    
    feature_occurences = occurences[class_name]
    
    if feature_name in feature_occurences:
        feature_occurences = feature_occurences[feature_name]
        feature_value_string = str(feature_value)
        if feature_value_string in feature_occurences:
            filtered_sample_count = feature_occurences[feature_value_string]
        else:
            filtered_sample_count = filter_samples_by(class_samples, feature_name, feature_value).shape[0]
            feature_occurences[feature_value_string] = filtered_sample_count
    else:
        filtered_sample_count = filter_samples_by(class_samples, feature_name, feature_value).shape[0]
        occurence = {str(feature_value): filtered_sample_count}
        feature_occurences[feature_name] = occurence
        
    
    #filtered_sample_count = filter_samples_by(class_samples, feature_name, feature_value).shape[0]
        
    return filtered_sample_count / sample_count
    
def calculate_probability_for_all_features(class_samples, test_sample, occurences, class_name):
    feature_columns = get_feature_column_names(class_samples)
    probability = 1.0
    
    for i in range(len(feature_columns)):
        feature = feature_columns[i]
        value = test_sample[feature]
        feature_probability = calculate_probability_for(class_samples, feature, value, occurences, class_name)  
        probability = probability * feature_probability
        
    return probability

def predict_sample(class_1_samples, class_2_samples, test_sample, occurences):
    
    team_1_probability = calculate_probability_for_all_features(class_1_samples, test_sample, occurences, "team_1")
    team_2_probability = calculate_probability_for_all_features(class_2_samples, test_sample, occurences, "team_2")
    
    if team_1_probability > team_2_probability:
        return classes['team_1']
    else:
        return classes['team_2']

def init_prediction_counts():
    return {
            '1': {'true': 0, 'false': 0},   ## 1 tahmin edildi, dogru tahmin edilenler true (yani gercekten de bir onlar) yanlis tahminler edilenler wrong (actual degeri 1 değil -1 yani)
            '-1': {'true': 0, 'false': 0}
           }

def predict_all_samples(train_dataset, test_dataset):
    predictions = init_prediction_counts()
    
    occurences = {
        'team_1': {}, ## 'team_1': { 'feature': {'-1': .., '0': ..., '1': ...} }
        'team_2': {}
    }

    team_1_samples, team_2_samples = get_class_samples(train_dataset)
    test_size = test_dataset.shape[0]
    
    for i in range(test_size):
        test_sample = test_dataset.iloc[i]
        actual_class = test_sample['class']
        predicted_class = predict_sample(team_1_samples, team_2_samples, test_sample, occurences)
        
        print("Prediction: " + str(i+1) + " actual: " + str(actual_class) + " predicted: " + str(predicted_class))
        
        if actual_class == predicted_class:
            predictions[str(predicted_class)]['true'] += 1
        else:
            predictions[str(predicted_class)]['false'] += 1
    
    return predictions


## daha sonra buradaki dataset ikiye ayrılmalı cross fold ile ...
## ve bu değerler kaydedilmeli ki bunları kullanarak aynı şekilde naive bayes ile karsilastirma yapalim
## train test diye ayrılmalı ...


## k-fold cross validation ile anladıgım kadariyla once bol sonra o parcayı test yap
## geri kalan parcalarla ile modeli egit ardından test et sonuc al sonra tekrar yap iteratif olarak
## gidiyor böyle



dataset = read_dataset()
dataset = remove_columns(dataset, ["cluster_id"])

kFold = KFold(n_splits = 5, shuffle = False, random_state = None)

results = []



count = 1

for train_indices, test_indices in kFold.split(dataset):    
    print("Validation: " + str(count))
    train_dataset = dataset.iloc[train_indices]
    test_dataset = dataset.iloc[test_indices]
    
    results.append(predict_all_samples(train_dataset, test_dataset))
    count = count + 1


predictions = {'-1': {'total_true': 0, 'total_false': 0},
               '1': {'total_true': 0, 'total_false': 0},
              }

for i in range(len(results)):
    predictions['-1']['total_true'] += results[i]['-1']['true']
    predictions['-1']['total_false'] += results[i]['-1']['false']
    
    predictions['1']['total_true'] += results[i]['1']['true']
    predictions['1']['total_false'] += results[i]['1']['false']

accuracy = (predictions['-1']['total_true'] + predictions['1']['total_true']) / (dataset.shape[0])

