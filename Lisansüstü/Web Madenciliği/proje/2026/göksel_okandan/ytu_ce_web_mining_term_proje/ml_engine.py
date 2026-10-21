import os
import time
import threading
import datetime
import psutil
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import joblib
import pickle
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.sequence import pad_sequences

class MLEngineViaThreading(threading.Thread):
    def __init__(self, dataframe, raw_dataframe, models_selected, update_queue, mode="Base", split_ratio=1.0):
        super().__init__()
        self.full_dataframe = dataframe
        self.raw_dataframe = raw_dataframe
        self.models_selected = models_selected
        self.update_queue = update_queue
        self.mode = mode
        self.split_ratio = split_ratio

        os.makedirs("results/logs", exist_ok=True)
        os.makedirs("results/plots_and_graphs", exist_ok=True)

        self.artifacts = {}

    def _get_memory_usage(self):
        process = psutil.Process(os.getpid())
        return process.memory_info().rss / (1024 * 1024)

    def _send_update(self, model_name, status, progress, metrics=None):
        self.update_queue.put({
            "model": model_name,
            "status": status,
            "progress": progress,
            "memory": self._get_memory_usage(),
            "metrics": metrics
        })

    def _load_artifacts(self):
        try:
            if any(m in self.models_selected for m in ["Naive-Bayes", "k-NN (10k)", "k-NN (100 SVD)"]):
                self.artifacts['tfidf'] = joblib.load(os.path.join("models", "tfidf_vectorizer.pkl"))
            if "k-NN (100 Feat.s)" in self.models_selected:
                self.artifacts['svd'] = joblib.load(os.path.join("models", "knn_svd_transformer.pkl"))
            if "Naive-Bayes" in self.models_selected:
                self.artifacts['nb_model'] = joblib.load(os.path.join("models", "naive_bayes_model.pkl"))
            if "k-NN (10k Feat.s)" in self.models_selected:
                self.artifacts['knn_10k'] = joblib.load(os.path.join("models", "knn_model_10000_features.pkl"))
            if "k-NN (100 Feat.s)" in self.models_selected:
                self.artifacts['knn_100'] = joblib.load(os.path.join("models", "knn_model_100_features.pkl"))
            if "Bidirectional LSTM" in self.models_selected:
                with open(os.path.join("models", "lstm_tokenizer.pkl"), 'rb') as handle:
                    self.artifacts['tokenizer'] = pickle.load(handle)
                self.artifacts['lstm_model'] = load_model(os.path.join("models", "lstm_model.keras"))
            return True

        except FileNotFoundError as ex:
            print(f"Missing artifact: {ex}")
            return False

    def run(self):
        self._send_update("SYSTEM", "Loading Pre-trained Models...", 0.0)

        if not self._load_artifacts():
            self.update_queue.put({"status": "ERROR", "message": "Failed to load files from models/ directory."})
            return

        if self.split_ratio < 1.0:
            active_dataframe = self.full_dataframe.sample(frac=self.split_ratio, random_state=59)
        else:
            active_dataframe = self.full_dataframe

        texts = active_dataframe['clean_text'].astype(str).values
        labels = active_dataframe['binary_label'].values
        raw_texts = self.raw_dataframe.loc[active_dataframe.index, 'text_'].astype(str).values \
            if self.raw_dataframe is not None else texts

        x_train_raw, x_test_raw, y_train, y_test, indices_train, indices_test = train_test_split(texts, labels,
                                                                                                 np.arange(len(texts)),
                                                                                                 test_size=0.2,
                                                                                                 random_state=59)

        results_dictionary = {}
        timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")

        tfidf_is_needed = any(m in self.models_selected for m in ["Naive-Bayes", "k-NN (10k Feat.s)", "k-NN (100 Feat.s)"])
        if tfidf_is_needed:
            x_tfidf = self.artifacts['tfidf'].transform(x_test_raw)

        if "Naive-Bayes" in self.models_selected:
            self._send_update("Naive-Bayes", "Running Inference Tests...", 0.50)
            start_time = time.time()
            y_prediction_nb = self.artifacts['nb_model'].predict(x_tfidf)
            runtime_nb = time.time() - start_time
            results_dictionary["Naive-Bayes"] = self._evaluate(y_test, y_prediction_nb, runtime_nb,
                                                               raw_texts)
            self._send_update("Naive-Bayes", "Inference Tests Completed.",
                              1.00, results_dictionary["Naive-Bayes"])

        if "k-NN (10k Feat.s)" in self.models_selected:
            self._send_update("k-NN (10k Feat.s)", "Running Inference Tests...", 0.50)
            start_time = time.time()
            y_prediction_knn_10k = self.artifacts['knn_10k'].predict(x_tfidf)
            runtime_knn_10k = time.time() - start_time
            results_dictionary["k-NN (10k Feat.s)"] = self._evaluate(y_test,
                                                                     y_prediction_knn_10k, runtime_knn_10k, raw_texts)
            self._send_update("k-NN (10k Feat.s)", "Inference Tests Completed.",
                              1.0, results_dictionary["k-NN (10k Feat.s)"])

        if "k-NN (100 Feat.s)" in self.models_selected:
            self._send_update("k-NN (100 Feat.s)", "Applying TruncatedSVD to Reduce Dimensions...", 
                              0.33)
            start_time = time.time()
            x_svd = self.artifacts['svd'].transform(x_tfidf)
            self._send_update("k-NN (100 Feat.s)", "Running Inference Tests...", 0.66)
            y_prediction = self.artifacts['knn_100'].predict(x_svd)
            runtime = time.time() - start_time
            results_dictionary["k-NN (100 Feat.s)"] = self._evaluate(y_test, y_prediction,
                                                                     runtime, raw_texts)
            self._send_update("k-NN (100 Feat.s)", "Complete",
                              1.0, results_dictionary["k-NN (100 Feat.s)"])

        if "Bidirectional LSTM" in self.models_selected:
            self._send_update("Bidirectional LSTM", "Tokenizing Texts...", 0.33)
            start_time = time.time()
            x_padded = pad_sequences(self.artifacts['tokenizer'].texts_to_sequences(x_test_raw), maxlen=200)
            self._send_update("Bidirectional LSTM", "Running Inference Tests...", 0.66)
            y_prediction_probs = self.artifacts['lstm_model'].predict(x_padded, verbose=0)
            y_prediction = (y_prediction_probs > 0.5).astype(int).flatten()
            runtime = time.time() - start_time
            results_dictionary["Bidirectional LSTM"] = self._evaluate(y_test, y_prediction,
                                                                      runtime, raw_texts)
            self._send_update("Bidirectional LSTM", "Complete",
                              1.0, results_dictionary["Bidirectional LSTM"])

        self._export_logs(results_dictionary, timestamp)
        self._export_plots(results_dictionary, timestamp)
        self.update_queue.put({"status": "ALL_COMPLETE", "final_results": results_dictionary, "split": self.split_ratio})

    def _evaluate(self, y_true, y_prediction, runtime, raw_strings):
        accuracy = accuracy_score(y_true, y_prediction)
        precision = precision_score(y_true, y_prediction, zero_division=0)
        recall = recall_score(y_true, y_prediction, zero_division=0)
        f1 = f1_score(y_true, y_prediction, zero_division=0)
        conf_matrix = confusion_matrix(y_true, y_prediction)

        true_positives = np.where((y_true == 1) & (y_prediction == 1))[0]
        false_positives = np.where((y_true == 0) & (y_prediction == 1))[0]
        tp_example = raw_strings[true_positives[0]] if len(true_positives) > 0 else "No True Positives Found."
        fp_example = raw_strings[false_positives[0]] if len(false_positives) > 0 else "No False Positives Found."

        return {
            "accuracy": accuracy, "precision": precision, "recall": recall, "f1": f1,
            "runtime": runtime, "confusion_matrix": conf_matrix,
            "tp_example": tp_example, "fp_example": fp_example
        }

    def _export_logs(self, results_dictionary, timestamp):
        filename = f"results/logs/{timestamp}_{self.mode.replace(' ', '_')}_log.txt"
        with open(filename, 'w', encoding='utf-8') as file:
            file.write(f"RESULTS OF TEST: {self.mode}\n")
            file.write(f"Timestamp: {timestamp}\n")
            file.write(f"Test Data Split Used: {self.split_ratio * 100}%\n\n")

            for model, metrics in results_dictionary.items():
                file.write(f"[{model}]\n")
                file.write(f"Accuracy:  {metrics['accuracy']:.4f}\n")
                file.write(f"Precision: {metrics['precision']:.4f}\n")
                file.write(f"Recall:    {metrics['recall']:.4f}\n")
                file.write(f"F1-Score:  {metrics['f1']:.4f}\n")
                file.write(f"Runtime:   {metrics['runtime']:.3f} seconds\n")
                file.write("-" * 39 + "\n")

    def _export_plots(self, results_dictionary, timestamp):
        for model, metrics in results_dictionary.items():
            safe_model_name = model.replace(' ', '_').replace('(', '').replace(')', '')

            plt.figure(figsize=(6, 5))
            sns.heatmap(metrics["confusion_matrix"], annot=True, fmt='d', cmap='Blues',
                        xticklabels=['Original', 'Computer Generated'], yticklabels=['Original', 'Computer Generated'])
            plt.title(f"Confusion Matrix: {model}", font='Arial', fontweight='bold')
            plt.ylabel('True Label', font='Arial')
            plt.xlabel('Predicted Label', font='Arial')
            plt.tight_layout()
            plot_filename = (f"results/plots_and_graphs/{timestamp}_{self.mode.replace(' ', '_')}_{safe_model_name}"
                             f"_conf_matrix.png")
            plt.savefig(plot_filename, dpi=300)
            plt.close()

        model_metrics_data_for_comp = []
        for model_name, metrics in results_dictionary.items():
            model_metrics_data_for_comp.append({'Base Algorithm': model_name, 'Metric': 'Accuracy', 'Score': metrics['accuracy']})
            model_metrics_data_for_comp.append({'Base Algorithm': model_name, 'Metric': 'Precision', 'Score': metrics['precision']})
            model_metrics_data_for_comp.append({'Base Algorithm': model_name, 'Metric': 'Recall', 'Score': metrics['recall']})
            model_metrics_data_for_comp.append({'Base Algorithm': model_name, 'Metric': 'F1-Score', 'Score': metrics['f1']})
        metrics_dataframe = pd.DataFrame(model_metrics_data_for_comp)

        plt.figure(figsize=(10, 6))
        sns.barplot(x='Metric', y='Score', hue='Base Algorithm', palette='crest', data=metrics_dataframe)
        plt.title(f'Performance Comparison in {self.mode} Mode', font='Arial', fontsize=16, fontweight='bold')
        plt.ylim(0, 1.1)
        plt.ylabel('Score', font='Arial', fontsize=12)
        plt.xlabel('')
        plt.legend(bbox_to_anchor=(1.02, 1), loc='upper left')
        plt.tight_layout()

        export_filename = f"results/plots_and_graphs/{timestamp}_{self.mode.replace(' ', '_')}_comparison_chart.png"
        plt.savefig(export_filename, dpi=300, bbox_inches='tight')
        plt.close()