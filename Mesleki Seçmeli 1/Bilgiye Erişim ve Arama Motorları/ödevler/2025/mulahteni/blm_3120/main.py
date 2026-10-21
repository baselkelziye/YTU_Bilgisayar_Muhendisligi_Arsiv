import argparse
from datasets import load_dataset
import pandas as pd
import joblib
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from xgboost import XGBClassifier
from sklearn.naive_bayes import MultinomialNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix, roc_curve, auc
import matplotlib.pyplot as plt
import seaborn as sns
import os
import numpy as np
import logging
import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

logging.basicConfig(level=logging.INFO, filename='model_training.log', filemode='w',
                    format='%(asctime)s - %(levelname)s - %(message)s')

nltk.download('stopwords')
nltk.download('wordnet')

stop_words = set(stopwords.words('english'))
lemmatizer = WordNetLemmatizer()

def preprocess_text(text):
    """Preprocess the input text by removing special characters and stop words, converting to lowercase, and applying lemmatization."""
    text = re.sub(r'[^a-zA-Z\s]', '', text)
    text = text.lower()
    text = ' '.join(word for word in text.split() if word not in stop_words)
    text = ' '.join(lemmatizer.lemmatize(word) for word in text.split())
    return text

def training(model, model_name, X_train_tfidf, y_train, weights_dir):
    logging.info(f"Training {model_name}...")
    print(f"Training {model_name}...")
    model.fit(X_train_tfidf, y_train)
    os.makedirs(weights_dir, exist_ok=True)
    model_path = os.path.join(weights_dir, f"{model_name.replace(' ', '_').lower()}_model.pkl")
    joblib.dump(model, model_path)
    logging.info(f"{model_name} trained and saved successfully at {model_path}.")
    return model

def evaluate(model_name, y_pred, y_test, plots_dir, label_names):
    os.makedirs(plots_dir, exist_ok=True)
    accuracy = accuracy_score(y_test, y_pred)
    report = classification_report(y_test, y_pred, output_dict=True, target_names=label_names)
    logging.info(f"Accuracy for {model_name}: {accuracy:.4f}")
    logging.info(f"Classification Report for {model_name}:\n{classification_report(y_test, y_pred, target_names=label_names)}\n")
    print(f"Accuracy for {model_name}: {accuracy:.4f}")
    print(f"Classification Report for {model_name}:\n{classification_report(y_test, y_pred, target_names=label_names)}\n")
    cm = confusion_matrix(y_test, y_pred)

    # Confusion Matrix
    try:
        plt.figure(figsize=(10, 7))
        sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=label_names,
                    yticklabels=label_names)
        plt.title(f"Confusion Matrix for {model_name}")
        plt.xlabel("Predicted Labels")
        plt.ylabel("True Labels")
        confusion_path = os.path.join(plots_dir, f"{model_name.replace(' ', '_').lower()}_confusion_matrix.png")
        plt.savefig(confusion_path)
        plt.close()
        logging.info(f"Confusion matrix for {model_name} saved at {confusion_path}.")
    except Exception as e:
        logging.error(f"Error saving confusion matrix for {model_name}: {e}")

    # Precision, Recall, and F1-Score Bar Plot
    try:
        precisions = [report[label]['precision'] for label in label_names]
        recalls = [report[label]['recall'] for label in label_names]
        f1_scores = [report[label]['f1-score'] for label in label_names]
        x = np.arange(len(label_names))

        plt.figure(figsize=(12, 8))
        bar_width = 0.25

        plt.bar(x - bar_width, precisions, width=bar_width, label='Precision', color='blue')
        plt.bar(x, recalls, width=bar_width, label='Recall', color='purple')
        plt.bar(x + bar_width, f1_scores, width=bar_width, label='F1-Score', color='cyan')

        plt.xlabel('Classes')
        plt.ylabel('Score')
        plt.title(f'Precision, Recall, and F1-Score for each class in {model_name}')
        plt.xticks(x, label_names, rotation=45, ha="right")
        plt.legend()

        metrics_path = os.path.join(plots_dir, f"{model_name.replace(' ', '_').lower()}_metrics_bar_chart.png")
        plt.savefig(metrics_path)
        plt.close()
        logging.info(f"Precision, Recall, and F1-Score bar chart for {model_name} saved at {metrics_path}.")
    except Exception as e:
        logging.error(f"Error saving Precision, Recall, and F1-Score bar chart for {model_name}: {e}")

    # ROC Curve and AUC
    try:
        plt.figure(figsize=(10, 8))
        for i, label in enumerate(label_names):
            y_test_bin = np.array([1 if label_idx == i else 0 for label_idx in y_test])  # Fix
            y_pred_prob = [1 if pred == i else 0 for pred in y_pred]
            fpr, tpr, _ = roc_curve(y_test_bin, y_pred_prob)
            roc_auc = auc(fpr, tpr)
            plt.plot(fpr, tpr, label=f'{label} (AUC = {roc_auc:.2f})')

        plt.plot([0, 1], [0, 1], 'k--', label='Random Guess')
        plt.xlabel('False Positive Rate')
        plt.ylabel('True Positive Rate')
        plt.title(f'ROC Curve for {model_name}')
        plt.legend(loc='lower right')

        roc_path = os.path.join(plots_dir, f"{model_name.replace(' ', '_').lower()}_roc_curve.png")
        plt.savefig(roc_path)
        plt.close()
        logging.info(f"ROC curve for {model_name} saved at {roc_path}.")
    except Exception as e:
        logging.error(f"Error saving ROC curve for {model_name}: {e}")

def main(args):
    try:
        ds = load_dataset("dair-ai/emotion", "split")
        print("Dataset loaded successfully.")
        logging.info("Dataset loaded successfully.")
    except Exception as e:
        print(f"Error loading dataset: {e}")
        logging.error(f"Error loading dataset: {e}")
        return

    label_names = ds['train'].features['label'].names
    
    train_df = pd.DataFrame(ds['train'])
    val_df = pd.DataFrame(ds['validation'])
    test_df = pd.DataFrame(ds['test'])

    texts = [preprocess_text(text) for text in train_df['text'].tolist()] + [preprocess_text(text) for text in val_df['text'].tolist()]
    labels = train_df['label'].tolist() + val_df['label'].tolist()
    test_texts = [preprocess_text(text) for text in test_df['text'].tolist()]
    test_labels = test_df['label'].tolist()
    
    logging.info(f"All text preprocessed.")
    print(f"All text preprocessed.")
    
    try:
        if args.vec and os.path.exists(args.vec):
            vectorizer = joblib.load(args.vec)
            X_train_tfidf = vectorizer.transform(texts)
            X_test_tfidf = vectorizer.transform(test_texts)
        else:
            vectorizer = TfidfVectorizer(max_features=3000)
            X_train_tfidf = vectorizer.fit_transform(texts)
            X_test_tfidf = vectorizer.transform(test_texts)
            print("Vectorizer saved.")
            logging.info("Vectorizer saved.")
            joblib.dump(vectorizer, "tfidf_vectorizer.pkl")
    except Exception as e:
        print(f"Error during vectorization: {e}")
        logging.error(f"Error during vectorization: {e}")
        return

    rf_clf = RandomForestClassifier(random_state=args.rs)
    lr_clf = LogisticRegression(max_iter=1000, random_state=args.rs)
    xgb_clf = XGBClassifier(eval_metric='logloss', random_state=args.rs)
    nb_clf = MultinomialNB()
    knn_clf = KNeighborsClassifier()
    dt_clf = DecisionTreeClassifier(random_state=args.rs)

    weights_dir = "model_weights"
    plots_dir = "model_plots"

    model_map = {
        1: ("Random Forest", rf_clf, os.path.join(weights_dir, "random_forest_model.pkl")), 
        2: ("Logistic Regression", lr_clf, os.path.join(weights_dir, "logistic_regression_model.pkl")), 
        3: ("XGBoost", xgb_clf, os.path.join(weights_dir, "xgboost_model.pkl")),
        4: ("Naive Bayes", nb_clf, os.path.join(weights_dir, "naive_bayes_model.pkl")),
        5: ("K-Nearest Neighbors", knn_clf, os.path.join(weights_dir, "k-nearest_neighbors_model.pkl")),
        6: ("Decision Tree", dt_clf, os.path.join(weights_dir, "decision_tree_model.pkl"))
    }

    models_to_train = model_map if args.ch2 == 0 else {args.ch2: model_map[args.ch2]}
    for _, (model_name, model, _) in models_to_train.items():
        try:
            trained_model = training(model, model_name, X_train_tfidf, labels, weights_dir)
            y_pred = trained_model.predict(X_test_tfidf)
            evaluate(model_name, y_pred, test_labels, plots_dir, label_names)
        except Exception as e:
            print(f"Error during training or evaluating {model_name}: {e}")
            logging.error(f"Error during training or evaluating {model_name}: {e}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Train emotion classification models')
    parser.add_argument('-ch2', '--ch2', type=int, default=0, help='0: All, 1: RF, 2: LR, 3: XGB, 4: NB, 5: KNN, 6: DT')
    parser.add_argument('-vec', '--vec', type=str, default='tfidf_vectorizer.pkl', help='Vectorizer path (optional)')
    parser.add_argument('-rs', '--rs', type=int, default=42, help='Random state for reproducibility (default: 42)')
    args = parser.parse_args()
    main(args)
