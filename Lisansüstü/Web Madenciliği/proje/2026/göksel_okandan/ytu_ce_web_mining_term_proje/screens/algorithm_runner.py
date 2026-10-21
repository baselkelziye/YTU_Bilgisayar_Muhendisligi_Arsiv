import customtkinter as ctk
import queue
import pandas as pd
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import seaborn as sns
from ml_engine import MLEngineViaThreading

class AlgorithmRunnerScreen(ctk.CTkFrame):
    def __init__(self, parent_frame, controller):
        super().__init__(parent_frame, corner_radius=0, fg_color="transparent")
        self.controller = controller

        self.run_nb = ctk.BooleanVar(value=True)
        self.run_knn_10k = ctk.BooleanVar(value=True)
        self.run_knn_100 = ctk.BooleanVar(value=True)
        self.run_lstm = ctk.BooleanVar(value=True)

        self._build_layout()
        self._render_base_mode()

    def _build_layout(self):
        sub_navbar_frame = ctk.CTkFrame(self, fg_color="transparent")
        sub_navbar_frame.pack(side="top", fill="x", pady=(20, 0))

        center_sub_frame = ctk.CTkFrame(sub_navbar_frame, fg_color="transparent")
        center_sub_frame.pack(expand=True)

        button_base = ctk.CTkButton(center_sub_frame, text="Base Mode", font=("Arial", 14), command=self._render_base_mode)
        button_base.pack(side="left", padx=10)

        button_perf = ctk.CTkButton(center_sub_frame, text="Performance Mode", font=("Arial", 14),
                                    command=self._render_performance_mode)
        button_perf.pack(side="left", padx=10)

        self.algorithm_content_frame = ctk.CTkFrame(self, corner_radius=10, fg_color=("gray", "gray16"))
        self.algorithm_content_frame.pack(side="top", fill="both", expand=True, padx=40, pady=20)

    def _clear_algo_content(self):
        for widget in self.algorithm_content_frame.winfo_children():
            widget.destroy()
    
    def _render_base_mode(self):
        self._clear_algo_content()
        label_title = ctk.CTkLabel(self.algorithm_content_frame, text="Base Mode Testing", font=("Arial", 24, "bold"))
        label_title.pack(pady=(20, 10))

        control_frame = ctk.CTkFrame(self.algorithm_content_frame, fg_color="transparent")
        control_frame.pack(fill="x", padx=20, pady=10)

        ctk.CTkLabel(control_frame, text="Select Models:", font=("Arial", 14, "bold")).pack(side="left", padx=(0, 15))
        ctk.CTkCheckBox(control_frame, text="Naive-Bayes", variable=self.run_nb).pack(side="left", padx=10)
        ctk.CTkCheckBox(control_frame, text="k-NN (10k Feat.s)", variable=self.run_knn_10k).pack(side="left", padx=10)
        ctk.CTkCheckBox(control_frame, text="k-NN (100 Feat.s)", variable=self.run_knn_100).pack(side="left", padx=10)
        ctk.CTkCheckBox(control_frame, text="Bidirectional LSTM", variable=self.run_lstm).pack(side="left", padx=10)
        self.start_button_base = ctk.CTkButton(control_frame, text="Start Base Test", fg_color="green", hover_color="darkgreen",
                                               font=("Arial", 14, "bold"), command=self._start_base_mode)
        self.start_button_base.pack(side="right", padx=10)

        self.base_progress_frame = ctk.CTkFrame(self.algorithm_content_frame, fg_color="transparent")
        self.base_progress_frame.pack(fill="both", expand=True, padx=20, pady=(10, 20))

    def _start_base_mode(self):
        if not hasattr(self.controller, 'clean_dataset') or self.controller.clean_dataset is None:
            ctk.CTkLabel(self.base_progress_frame, text="Error: Dataset not available.", text_color="red").pack()
            return

        selected_models = []
        if self.run_nb.get(): selected_models.append("Naive-Bayes")
        if self.run_knn_10k.get(): selected_models.append("k-NN (10k Feat.s)")
        if self.run_knn_100.get(): selected_models.append("k-NN (100 Feat.s)")
        if self.run_lstm.get(): selected_models.append("Bidirectional LSTM")

        if not selected_models:
            ctk.CTkLabel(self.base_progress_frame, text="No models selected. Please select at least one model to run the tests.",
                         text_color="red").pack()
            return

        self.start_button_base.configure(state="disabled", text="Running Tests...")

        for widget in self.base_progress_frame.winfo_children():
            widget.destroy()

        self.base_widgets = {}

        for model in selected_models:
            column_frame = ctk.CTkFrame(self.base_progress_frame)
            column_frame.pack(side="left", fill="both", expand=True, padx=5)

            ctk.CTkLabel(column_frame, text=model, font=("Arial", 16, "bold")).pack(pady=(10, 5))

            progress_bar = ctk.CTkProgressBar(column_frame)
            progress_bar.pack(fill="x", padx=10, pady=5)
            progress_bar.set(0)

            label_status = ctk.CTkLabel(column_frame, text="Status: Waiting...", font=("Arial", 12, "bold"))
            label_status.pack(pady=5)

            label_metrics = ctk.CTkLabel(column_frame, text="Accuracy: \n"
                                                            "Precision: \n"
                                                            "Recall: \n"
                                                            "F1-Score: \n"
                                                            "Runtime: s",
                                         justify="left", font=("Arial", 13, "bold"))
            label_metrics.pack(pady=10)

            self.base_widgets[model] = {"progress": progress_bar, "status": label_status, "metrics": label_metrics}

        self.update_queue = queue.Queue()
        self.ml_engine = MLEngineViaThreading(
            dataframe=self.controller.clean_dataset,
            raw_dataframe=self.controller.raw_dataset,
            models_selected=selected_models,
            update_queue=self.update_queue,
            mode="Base",
            split_ratio=1.0
        )
        self.ml_engine.start()
        self._check_base_queue()

    def _check_base_queue(self):
        try:
            while True:
                message = self.update_queue.get_nowait()

                if message.get("status") == "ALL_COMPLETE":
                    self.start_button_base.configure(state="normal", text="Start Base Test")
                    self._show_report_window(message["final_results"], "Base Mode Test")
                    return

                model = message["model"]
                if model in self.base_widgets:
                    self.base_widgets[model]["status"].configure(text=f"Status: {message['status']}")
                    self.base_widgets[model]["progress"].set(message["progress"])

                    if message.get("metrics"):
                        metrics = message["metrics"]
                        metrics_text = (f"Accuracy: {metrics['accuracy']:.4f}\n"
                                       f"Precision: {metrics['precision']:.4f}\n"
                                       f"Recall: {metrics['recall']:.4f}\n"
                                       f"F1: {metrics['f1']:.4f}\n"
                                       f"Runtime: {metrics['runtime']:.3f}s")
                        self.base_widgets[model]["metrics"].configure(text=metrics_text)
                        self.base_widgets[model]["status"].configure(text="Complete.", text_color="green")

        except queue.Empty:
            pass

        self.after(100, self._check_base_queue)

    def _render_performance_mode(self):
        self._clear_algo_content()
        label_title = ctk.CTkLabel(self.algorithm_content_frame, text="Performance Mode Testing", font=("Arial", 24, "bold"))
        label_title.pack(pady=(20, 10))

        description_text = ("his mode tests all algorithms sequentially across 25%, 50%, and 100% test data splits to evaluate \n"
                            "scalability and memory usage along with other metrics.\n"
                            "Press \"Start Performance Test\" to start the performance test.")
        ctk.CTkLabel(self.algorithm_content_frame, text=description_text, font=("Arial", 14)).pack(pady=(0, 20))

        self.start_button_perf = ctk.CTkButton(self.algorithm_content_frame, text="Start Performance Test", fg_color="green",
                                               hover_color="darkgreen", font=("Arial", 14, "bold"),
                                               command=self._start_performance_mode)
        self.start_button_perf.pack(pady=5)

        self.perf_progress_frame = ctk.CTkFrame(self.algorithm_content_frame, fg_color="transparent")
        self.perf_progress_frame.pack(fill="both", expand=True, padx=20, pady=20)

    def _start_performance_mode(self):
        self.start_button_perf.configure(state="disabled", text="Testing...")

        for widget in self.perf_progress_frame.winfo_children():
            widget.destroy()

        self.perf_mode_splits = [0.25, 0.50, 1.0]
        self.perf_mode_models = ["Naive-Bayes", "k-NN (10k Feat.s)", "k-NN (100 Feat.s)", "Bidirectional LSTM"]
        self.perf_mode_widgets = {}
        self.perf_mode_final_results = {}

        for split in self.perf_mode_splits:
            row_frame = ctk.CTkFrame(self.perf_progress_frame)
            row_frame.pack(fill="x", pady=5)

            label_name = ctk.CTkLabel(row_frame, text=f"{int(split * 100)}% Test Data Split",
                                      font=("Arial", 14, "bold"), width=150, anchor="w")
            label_name.pack(side="left", padx=10, pady=10)

            progress_bar = ctk.CTkProgressBar(row_frame, width=300)
            progress_bar.pack(side="left", padx=10)
            progress_bar.set(0)

            label_ram = ctk.CTkLabel(row_frame, text="Memory: ??? MB", font=("Arial", 13), width=150, anchor="e")
            label_ram.pack(side="right", padx=10)

            self.perf_mode_widgets[split] = {"progress": progress_bar, "ram": label_ram, "row_frame": row_frame}

        self.current_split_index = 0
        self.update_queue = queue.Queue()
        self._run_next_perf_split()

    def _run_next_perf_split(self):
        if self.current_split_index >= len(self.perf_mode_splits):
            self.start_button_perf.configure(state="normal", text="Start Performance Test")
            self._show_report_window(self.perf_mode_final_results, "Performance Mode Test", is_perf_mode=True)
            return

        current_split = self.perf_mode_splits[self.current_split_index]
        self.perf_mode_widgets[current_split]["row_frame"].configure(fg_color=("gray", "gray16"))

        self.ml_engine = MLEngineViaThreading(
            dataframe=self.controller.clean_dataset,
            raw_dataframe=self.controller.raw_dataset,
            models_selected=self.perf_mode_models,
            update_queue=self.update_queue,
            mode="Performance",
            split_ratio=current_split
        )
        self.ml_engine.start()
        self._check_perf_queue(current_split)

    def _check_perf_queue(self, active_split):
        try:
            while True:
                message = self.update_queue.get_nowait()

                if message.get("status") == "ALL_COMPLETE":
                    self.perf_mode_widgets[active_split]["progress"].set(1.0)
                    self.perf_mode_widgets[active_split]["row_frame"].configure(fg_color="transparent")

                    split_key = f"{int(active_split * 100)}% Test Data Split"
                    self.perf_mode_final_results[split_key] = message["final_results"]

                    self.current_split_index += 1
                    self._run_next_perf_split()
                    return

                self.perf_mode_widgets[active_split]["ram"].configure(text=f"Memory Used: {message['memory']:.2f} MB")

                if "model" in message and message["model"] in self.perf_mode_models:
                    model_index = self.perf_mode_models.index(message["model"])
                    unified_progress_bar = (model_index + message["progress"]) / len(self.perf_mode_models)
                    self.perf_mode_widgets[active_split]["progress"].set(unified_progress_bar)

        except queue.Empty:
            pass

        self.after(100, lambda: self._check_perf_queue(active_split))

    def _show_report_window(self, results_dictionary, title, is_perf_mode=False):
        report_frame = ctk.CTkToplevel(self)
        report_frame.title(title)
        report_frame.geometry("1200x800")
        report_frame.grab_set()

        ctk.CTkLabel(report_frame, text=f"Results: {title}", font=("Arial", 24, "bold")).pack(pady=20)

        report_tabview = ctk.CTkTabview(report_frame, width=950, height=600)
        report_tabview.pack(padx=20, pady=10, fill="both", expand=True)

        if is_perf_mode:
            for split_key, models_data in results_dictionary.items():
                report_tabview.add(split_key)
                report_tab_frame = report_tabview.tab(split_key)

                report_sub_tabs = ctk.CTkTabview(report_tab_frame)
                report_sub_tabs.pack(fill="both", expand=True)

                report_sub_tabs.add("Performance Comparison Chart")
                self._build_comparison_chart_tab(report_sub_tabs.tab("Performance Comparison Chart"), models_data)

                ranked_models = sorted(models_data.items(), key=lambda x: x[1]['f1'], reverse=True)
                for rank_index, (model_name, metrics) in enumerate(ranked_models):
                    rank_number = rank_index + 1
                    tab_name = f"#{rank_number} {model_name}"
                    report_sub_tabs.add(tab_name)
                    self._build_report_tab(report_sub_tabs.tab(tab_name), model_name, metrics, rank_number)

                report_sub_tabs.set("Performance Comparison Chart")
        else:
            report_tabview.add("Performance Comparison Chart")
            self._build_comparison_chart_tab(report_tabview.tab("Performance Comparison Chart"), results_dictionary)

            ranked_models = sorted(results_dictionary.items(), key=lambda x: x[1]['f1'], reverse=True)
            for rank_index, (model_name, metrics) in enumerate(ranked_models):
                rank_number = rank_index + 1
                tab_name = f"#{rank_number} {model_name}"
                report_tabview.add(tab_name)
                self._build_report_tab(report_tabview.tab(tab_name), model_name, metrics, rank_number)

            report_tabview.set("Performance Comparison Chart")

    def _build_comparison_chart_tab(self, parent_frame, models_data):
        model_metrics_data = []
        for model_name, metrics in models_data.items():
            model_metrics_data.append({'Base Algorithm': model_name, 'Metric': 'Accuracy', 'Score': metrics['accuracy']})
            model_metrics_data.append({'Base Algorithm': model_name, 'Metric': 'Precision', 'Score': metrics['precision']})
            model_metrics_data.append({'Base Algorithm': model_name, 'Metric': 'Recall', 'Score': metrics['recall']})
            model_metrics_data.append({'Base Algorithm': model_name, 'Metric': 'F1-Score', 'Score': metrics['f1']})
        metrics_dataframe = pd.DataFrame(model_metrics_data)

        comp_figure = Figure(figsize=(10, 5), dpi=100)
        comp_figure.patch.set_facecolor('#2b2b2b')
        comp_ax = comp_figure.add_subplot(111)
        comp_ax.set_facecolor('#2b2b2b')
        sns.barplot(x='Metric', y='Score', hue='Base Algorithm', palette='crest', data=metrics_dataframe, ax=comp_ax)
        comp_ax.set_ylabel('Score', color='white', fontsize=12)
        comp_ax.set_xlabel('', color='white')
        comp_ax.set_title('Performance Comparison Across All Models', color='white', fontsize=16, fontweight='bold')
        comp_ax.tick_params(colors='white', labelsize=12)
        comp_ax.set_ylim(0, 1.1)
        comp_ax.spines['bottom'].set_color('gray')
        comp_ax.spines['left'].set_color('gray')
        comp_ax.spines['top'].set_visible(False)
        comp_ax.spines['right'].set_visible(False)
        comp_ax.yaxis.grid(True, linestyle='--', alpha=0.3, color='gray')
        comp_ax.set_axisbelow(True)
        comp_ax.legend(bbox_to_anchor=(1.02, 1), loc='upper left', facecolor='#2b2b2b', edgecolor='gray', labelcolor='white')
        comp_figure.subplots_adjust(right=0.75)

        comp_canvas = FigureCanvasTkAgg(comp_figure, master=parent_frame)
        comp_canvas.draw()
        comp_canvas.get_tk_widget().pack(fill="both", expand=True, padx=20, pady=20)

    def _build_report_tab(self, parent_frame, model_name, model_metrics, rank_number):
        report_left_frame = ctk.CTkFrame(parent_frame, width=400, fg_color="transparent")
        report_left_frame.pack(side="left", fill="y", padx=10)

        metrics_text = (
            f"OVERALL RANK: #{rank_number}\n"
            f"-------------------------------------------------\n"
            f"F1-Score: {model_metrics['f1']:.4f}\n"
            f"Accuracy: {model_metrics['accuracy']:.4f}\n"
            f"Precision: {model_metrics['precision']:.4f}\n"
            f"Recall: {model_metrics['recall']:.4f}\n"
            f"Runtime: {model_metrics['runtime']:.2f} seconds\n"
        )
        ctk.CTkLabel(report_left_frame, text=metrics_text, font=("Arial", 15, "bold"), justify="left").pack(pady=10, anchor="w")

        ctk.CTkLabel(report_left_frame, text="Flagging Examples:", font=("Arial", 14, "bold")).pack(anchor="w", pady=(10, 0))
        example_box = ctk.CTkTextbox(report_left_frame, wrap="word", width=400, height=550)
        example_box.pack(pady=5)

        example_box.insert("end", "[TRUE POSITIVE EXAMPLE - Correctly Flagged Fake]\n")
        example_box.insert("end", f"{model_metrics['tp_example']}\n\n")
        example_box.insert("end", "[FALSE POSITIVE EXAMPLE - Wrongly Flagged Fake]\n")
        example_box.insert("end", f"{model_metrics['fp_example']}\n")
        example_box.configure(state="disabled")

        report_right_frame = ctk.CTkFrame(parent_frame, fg_color="transparent")
        report_right_frame.pack(side="right", fill="both", expand=True, padx=10)

        conf_figure = Figure(figsize=(5, 4), dpi=100)
        conf_figure.patch.set_facecolor('#2b2b2b')
        conf_ax = conf_figure.add_subplot(111)
        sns.heatmap(model_metrics["confusion_matrix"], annot=True, fmt='d', cmap='Blues',
                    xticklabels=['Original', 'Computer Generated'], yticklabels=['Original', 'Computer Generated'], ax=conf_ax)
        conf_ax.set_title(f"Confusion Matrix: {model_name}", color='white')
        conf_ax.set_xlabel('Predicted Label', color='white')
        conf_ax.set_ylabel('True Label', color='white')
        conf_ax.tick_params(colors='white')

        conf_canvas = FigureCanvasTkAgg(conf_figure, master=report_right_frame)
        conf_canvas.draw()
        conf_canvas.get_tk_widget().pack(fill="both", expand=True)