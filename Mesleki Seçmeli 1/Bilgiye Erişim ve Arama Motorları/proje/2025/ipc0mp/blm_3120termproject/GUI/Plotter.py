from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt
import numpy as np

import common.Logger as CommonLogger
from GUI.GUI import ForwardArgs

class Plotter:
    def __init__(self, evaluators):
        self.evaluators = evaluators

    def setup_args(self, args):
        self.args = {}

        for alg in self.evaluators.keys():
            tmp = {}

            tmp["testset_infile"] = args.testset_infile
            tmp["pickle_path"]    = getattr(args, f"pickle_path_{alg}")

            self.args[alg] = ForwardArgs("Plotter.setup_args", tmp)

    def plot_performances(self, args):
        self.setup_args(args)

        failure = [None] * 6

        self.performances = {}

        # fetch evaluation metrics for every model
        for alg in self.args.keys():
            CommonLogger.logger.log(alg)
            gen = self.evaluators[alg](self.args[alg])

            try:
                i = 0
                while True and i < 1000:
                    i += 1
                    next(gen)

                if i >= 10000:
                    raise Exception("[ERROR] plot_performances(): Infinite loop while trying to consume evaluator")
            except StopIteration as e:
                tmp = e.value

                if not tmp or len(tmp) != 7:
                    CommonLogger.logger.log(f"[ERROR] plot_performances(): unexpected evaluator return value for {alg}")
                    return failure
                else:
                    accuracy, precision, recall, f1_score, roc_auc, y_probs, y_labels = tmp

                    self.performances[alg] = {
                        "accuracy":  accuracy,
                        "precision": precision,
                        "recall":    recall,
                        "f1_score":  f1_score,
                        "roc_auc":   roc_auc,
                        "y_probs":   y_probs,
                        "y_labels":  y_labels
                    }


        metrics = ['accuracy', 'precision', 'recall', 'f1_score', 'roc_auc']
        self.model_names = list(self.performances.keys())

        # different colors for different models
        self.colors = ['#e07272', '#368dd9', '#3eb53e']

        figs = []

        # plotting all metrics except the roc curve
        for metric in metrics:
            fig, ax = plt.subplots(figsize=(5, 4))

            scores = [self.performances[model][metric] for model in self.model_names]

            bars = ax.bar(self.model_names, scores, color=self.colors)

            # style
            ax.set_title(metric.replace('_', ' ').title() if 'roc' not in metric else metric.replace('_', ' ').upper(), fontsize=12, fontweight='bold')
            ax.set_ylim(0, 1.1)
            ax.set_yticks(np.arange(0, 1.1, 0.1))
            ax.set_ylabel('Score')

            # bar labels
            for bar in bars:
                height = bar.get_height()
                ax.text(bar.get_x() + bar.get_width()/2., height + 0.01,
                        f'{height:.4f}', ha='center', va='bottom', fontsize=9)

            plt.tight_layout()

            figs.append(fig)

        figs.append(self.plot_roc_curve())

        return figs

    def plot_roc_curve(self):
        fig_roc, ax_roc = plt.subplots(figsize=(6, 5))

        for i, alg in enumerate(self.model_names):
            y_true = self.performances[alg]["y_labels"]
            y_score = self.performances[alg]["y_probs"]

            # get roc-curve points
            fpr, tpr, _ = roc_curve(y_true, y_score)
            roc_auc_val = self.performances[alg]["roc_auc"]

            ax_roc.plot(fpr, tpr, color=self.colors[i], lw=2,
                        label=f'{alg} (AUC = {roc_auc_val:.4f})')

        # style
        ax_roc.plot([0, 1], [0, 1], color='navy', lw=1, linestyle='--') # Diagonal baseline
        ax_roc.set_xlim([0.0, 1.0])
        ax_roc.set_ylim([0.0, 1.05])
        ax_roc.set_xticks(np.arange(0, 1.1, 0.1))
        ax_roc.set_yticks(np.arange(0, 1.1, 0.1))
        ax_roc.set_xlabel('False Positive Rate', fontsize=10)
        ax_roc.set_ylabel('True Positive Rate', fontsize=10)
        ax_roc.set_title('ROC Curve', fontsize=12, fontweight='bold')
        ax_roc.legend(loc="lower right")
        ax_roc.grid(alpha=0.3)

        plt.tight_layout()

        return fig_roc
