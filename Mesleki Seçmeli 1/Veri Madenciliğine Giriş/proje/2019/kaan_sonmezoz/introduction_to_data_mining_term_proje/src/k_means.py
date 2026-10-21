import pandas as pd

DATASET_PATH = "../data/with-headers/dataset.csv"
MAX_ITERATION = 5

class_to_int = { 'team_1': 1, 'team_2': -1}


def read_dataset(file_path = DATASET_PATH):
    return pd.read_csv(file_path)

def remove_columns(dataset, columns = ["cluster_id"]):    
    return dataset.drop(columns=columns)

def get_feature_column_names(samples):
    column_names = samples.columns.values.tolist()    
    column_names.remove('class') 
    
    return column_names

def calculate_jaccard_similarity(sample_1, sample_2):   ## min hashing falan yapmak lazimdi aslında jaccard cok yavas olmasına neden oluyor
    common_count = 0
    
    feature_count = len(feature_columns)
    
    for i in range(feature_count):
        feature_name = feature_columns[i]
        
        if sample_1[feature_name] == sample_2[feature_name]:
            common_count += 1
    
    return (common_count / feature_count)

def find_cluster(center_1, center_2, sample):
    similarity_1 = calculate_jaccard_similarity(center_1, sample)
    similarity_2 = calculate_jaccard_similarity(center_2, sample)
    
    if similarity_1 > similarity_2:
        return "cluster_1"
    else:
        return "cluster_2"

def find_representative_sample(elements):   
    print("Finding representative element")
    total_similarities = []
    elements_length = len(elements)
    
    for i in range(elements_length):
        print("Calculating total similarity for element: " + str(i + 1))
        total_similarity = 0
        sample = elements[i]
        
        for j in range(elements_length):
            total_similarity += calculate_jaccard_similarity(sample, elements[j])
        
        total_similarities.append(total_similarity)
    
    max_similarity = max(total_similarities)
    max_value_index = total_similarities.index(max_similarity)
    
    return elements[max_value_index]

def assign_new_centers(clusters):
    new_center_1 = find_representative_sample(clusters['cluster_1']['elements'])
    new_center_2 = find_representative_sample(clusters['cluster_2']['elements'])
    
    clusters['cluster_1']['center'] = new_center_1
    clusters['cluster_2']['center'] = new_center_2
    

def assign_samples_to_clusters(dataset, clusters):
    center_1 = clusters['cluster_1']['center']
    center_2 = clusters['cluster_2']['center']
    
    for i in range(dataset.shape[0]):
        print("Sample " + str(i + 1))
        sample = dataset.iloc[i]
        cluster_name = find_cluster(center_1, center_2, sample)    
        clusters[cluster_name]['elements'].append(sample)
            
def find_cluster_class(elements):
    class_count = {'-1': 0, '1': 0}
    
    for i in range(len(elements)):
        class_value_str = str(elements[i]["class"])
        class_count[class_value_str] += 1
    
    if class_count['1'] > class_count['-1']:
        return "team_1", class_count['1'], class_count['-1'] ## returns class_label, true_predictions, wrong_predictions
    else:
        return "team_2", class_count['-1'], class_count['1']
    
def clear_cluster_elements(clusters):
    clusters['cluster_1']['elements'].clear()
    clusters['cluster_2']['elements'].clear()
    
def init_clusters(dataset):
    center_1 = dataset.iloc[0]
    center_2 = dataset.iloc[dataset.shape[0] - 1]
    
    clusters = {
        'cluster_1': {
                'center': center_1,
                'elements': []
        },        
            'cluster_2': {
                'center': center_2,
                'elements': []
        }
    }
            
    return clusters

dataset = read_dataset()
dataset = remove_columns(dataset, ["cluster_id"])

feature_columns = get_feature_column_names(dataset)

clusters = init_clusters(dataset)
        
for i in range(MAX_ITERATION):
    print("Iteration: " + str(i + 1))
    clear_cluster_elements(clusters)
    
    assign_samples_to_clusters(dataset, clusters)
    assign_new_centers(clusters)
    

predictions = {'team_1': {'true': 0, 'false': 0},
               'team_2': {'true': 0, 'false': 0}
              }

class_name, true_predictions, false_predictions = find_cluster_class(clusters['cluster_1']['elements'])
    
predictions[class_name]['true'] += true_predictions
predictions[class_name]['false'] += false_predictions    

class_name, true_predictions, false_predictions = find_cluster_class(clusters['cluster_2']['elements'])
    
predictions[class_name]['true'] += true_predictions
predictions[class_name]['false'] += false_predictions    


## bundan sonra listeyi bosaltmak lazim listeyi her bir assigment'tan önce bosaltalım
## en son for'dan cikinca da cluster'in label'ini bulmak gerekecek dogru etiket sayisini da donebiliriz



"""
x = dataset.iloc[0]

index = dataset == x
"""
