from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split

from ai.utils import load_data, convert_labels_to_numerical, get_prediction_results

if __name__ == '__main__':
    # Load data
    data, labels = load_data("data", group=True, group_size=2, unique=True)

    # Split data into train and test sets
    train_data, test_data, train_labels, test_labels = train_test_split(data, labels, test_size=0.3, random_state=42)

    # Convert labels to numerical form
    labels_dict = sorted(list(dict.fromkeys(train_labels)))
    label_mapping = {label: i for i, label in enumerate(labels_dict)}
    train_labels = convert_labels_to_numerical(train_labels, label_mapping)
    test_labels = convert_labels_to_numerical(test_labels, label_mapping)

    # Create TF-IDF vectorizer
    n = 1
    vectorizer = TfidfVectorizer(ngram_range=(n, n))
    vectorizer.fit(train_data)

    train_vectors, test_vectors = vectorizer.transform(train_data).toarray(), vectorizer.transform(test_data).toarray()

    print('train vectors shape:', train_vectors.shape)
    print('train vectors:', train_vectors)

    # Create and train Random Forest model
    rf = RandomForestClassifier(random_state=42)
    rf.fit(train_vectors, train_labels)

    # Make predictions and print results
    accuracy, report, cm = get_prediction_results(rf, test_vectors, test_labels, label_mapping, is_deep=False)

    print("\nConfusion Matrix:\n", cm)
    print("\nClassification Report:\n", report)
    print(f"Accuracy: {accuracy}")
