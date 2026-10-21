import customtkinter as ctk

class DatasetManagerScreen(ctk.CTkFrame):
    def __init__(self, parent_frame, controller):
        super().__init__(parent_frame, corner_radius=0, fg_color="transparent")
        self.controller = controller

        self._build_layout()
        self._render_dataset_statistics()

    def _build_layout(self):
        sub_navbar_frame = ctk.CTkFrame(self, fg_color="transparent")
        sub_navbar_frame.pack(side="top", fill="x", pady=(20, 0))

        center_sub_frame = ctk.CTkFrame(sub_navbar_frame, fg_color="transparent")
        center_sub_frame.pack(expand=True)

        button_dataset_stats = ctk.CTkButton(center_sub_frame, text="Statistics", image=self.controller.icons.get("Dataset Statistics"),
                                          compound="left", font=("Arial", 14), command=self._render_dataset_statistics)
        button_dataset_stats.pack(side="left", padx=10)

        button_dataset_examples = ctk.CTkButton(center_sub_frame, text="Examples", image=self.controller.icons.get("Dataset Examples"),
                                     compound="left", font=("Arial", 14), command=self._render_dataset_examples)
        button_dataset_examples.pack(side="left", padx=10)

        self.dataset_content_frame = ctk.CTkFrame(self, corner_radius=10, fg_color=("gray", "gray16"))
        self.dataset_content_frame.pack(side="top", fill="both", expand=True, padx=40, pady=20)

    def _clear_dataset_content(self):
        for widget in self.dataset_content_frame.winfo_children():
            widget.destroy()

    def _render_dataset_statistics(self):
        self._clear_dataset_content()

        label_title = ctk.CTkLabel(self.dataset_content_frame, text="Dataset Statistics", font=("Arial", 24, "bold"))
        label_title.pack(pady=(20, 10))

        if not hasattr(self.controller, 'clean_dataset') or self.controller.clean_dataset is None:
            error_label = ctk.CTkLabel(self.dataset_content_frame, text="No dataset available.", text_color="red")
            error_label.pack(pady=20)
            return

        try:
            clean_dataframe = self.controller.clean_dataset
            total_review_count = len(clean_dataframe)
            original_review_count = len(clean_dataframe[clean_dataframe['binary_label'] == 0])
            fake_review_count = len(clean_dataframe[clean_dataframe['binary_label'] == 1])

            dataset_stats_text = (
                f"Total Reviews Loaded: {total_review_count:,}\n"
                f"Original Reviews (0): {original_review_count:,} ({(original_review_count/total_review_count):.2%})\n"
                f"Computer Generated (1): {fake_review_count:,} ({(fake_review_count/total_review_count):.2%})\n\n"
                f"Dataset Shape: {self.controller.clean_dataset.shape}\n\n"
            )

            dataset_stats_display = ctk.CTkLabel(self.dataset_content_frame, text=dataset_stats_text, font=("Arial", 16),
                                                 justify="left")
            dataset_stats_display.pack(pady=20)

        except Exception as ex:
            exception_display = ctk.CTkLabel(self.dataset_content_frame, text=f"Error: {str(ex)}.", font=("Arial", 16),
                                             justify="left")
            exception_display.pack(pady=20)

    def _render_dataset_examples(self):
        self._clear_dataset_content()
        label_title = ctk.CTkLabel(self.dataset_content_frame, text="Dataset Examples", font=("Arial", 24, "bold"))
        label_title.pack(pady=(20, 10))

        if not hasattr(self.controller, 'raw_dataset') or self.controller.raw_dataset is None:
            ctk.CTkLabel(self.dataset_content_frame, text="No dataset available.", text_color="red").pack(pady=20)
            return

        raw_dataframe = self.controller.raw_dataset

        filter_frame = ctk.CTkFrame(self.dataset_content_frame, fg_color="transparent")
        filter_frame.pack(fill="x", padx=20, pady=(0, 10))

        ctk.CTkLabel(filter_frame, text="Label:", font=("Arial", 14, "bold")).pack(side="left", padx=(0, 5))
        self.filter_label_var = ctk.StringVar(value="All")
        filter_label_menu = ctk.CTkOptionMenu(filter_frame, variable=self.filter_label_var, width=170,
                                              values=["All", "Original (OR)", "Computer Generated (CG)"],
                                              command=self._update_example_view)
        filter_label_menu.pack(side="left", padx=(0, 20))

        ctk.CTkLabel(filter_frame, text="Rating:", font=("Arial", 14, "bold")).pack(side="left", padx=(0, 5))
        self.filter_rating_var = ctk.StringVar(value="All")
        filter_rating_menu = ctk.CTkOptionMenu(filter_frame, variable=self.filter_rating_var, width=80,
                                               values=["All", "5.0", "4.0", "3.0", "2.0", "1.0"],
                                               command=self._update_example_view)
        filter_rating_menu.pack(side="left", padx=(0, 20))

        ctk.CTkLabel(filter_frame, text="Category:", font=("Arial", 14, "bold")).pack(side="left", padx=(0, 5))
        self.filter_category_var = ctk.StringVar(value="All")

        if 'category' in raw_dataframe.columns:
            unique_categories = sorted([str(category) for category in raw_dataframe['category'].dropna().unique()])
            review_cats = ["All"] + unique_categories
        else:
            review_cats = ["All"]

        filter_category_menu = ctk.CTkOptionMenu(filter_frame, variable=self.filter_category_var, width=200,
                                                 values=review_cats, command=self._update_example_view)
        filter_category_menu.pack(side="left")

        self.scroll_text = ctk.CTkTextbox(self.dataset_content_frame, wrap="word", font=("Arial", 14))
        self.scroll_text.pack(fill="both", expand=True, padx=20, pady=(0, 20))

        self._update_example_view()

    def _update_example_view(self, choice=None):
        if not hasattr(self, 'scroll_text'):
            return

        self.scroll_text.configure(state="normal")
        self.scroll_text.delete("1.0", "end")

        raw_dataframe = self.controller.raw_dataset

        label_value = self.filter_label_var.get()
        if label_value == "Original (OR)":
            raw_dataframe = raw_dataframe[raw_dataframe['label'] == 'OR']
        elif label_value == "Computer Generated (CG)":
            raw_dataframe = raw_dataframe[raw_dataframe['label'] == 'CG']

        rating_value = self.filter_rating_var.get()
        if rating_value != "All":
            raw_dataframe = raw_dataframe[raw_dataframe['rating'] == float(rating_value)]

        category_value = self.filter_category_var.get()
        if category_value != "All":
            raw_dataframe = raw_dataframe[raw_dataframe['category'] == category_value]

        if raw_dataframe.empty:
            self.scroll_text.insert("end", "No reviews match the selected filter combination. "
                                      "Please try another combination.")
        else:
            sample_dataframe = raw_dataframe.sample(min(100, len(raw_dataframe)))
            for index, row in sample_dataframe.iterrows():
                raw_text = row.get('text_', 'No text found.')
                self.scroll_text.insert("end", f"{raw_text}\n")
                self.scroll_text.insert("end", "-" * 200 + "\n")

        self.scroll_text.configure(state="disabled")