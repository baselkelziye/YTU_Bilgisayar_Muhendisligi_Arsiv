import os
import glob
from datetime import datetime
import customtkinter as ctk
from PIL import Image

class ResultsAnalysisScreen(ctk.CTkFrame):
    def __init__(self, parent_frame, controller):
        super().__init__(parent_frame, corner_radius=0, fg_color="transparent")
        self.controller = controller

        self._build_layout()
        self._load_results()

    def _build_layout(self):
        header_frame = ctk.CTkFrame(self, fg_color="transparent")
        header_frame.pack(side="top", fill="x", padx=40, pady=(20, 10))

        ctk.CTkLabel(header_frame, text="List of Prior Results", font=("Arial", 24, "bold")).pack(side="left")

        refresh_button = ctk.CTkButton(header_frame, text="Refresh Page", width=120, command=self._load_results,
                                       fg_color="gray", hover_color="gray16")
        refresh_button.pack(side="right", pady=5)

        self.result_list_frame = ctk.CTkScrollableFrame(self, corner_radius=10, fg_color=("gray", "gray16"))
        self.result_list_frame.pack(side="top", fill="both", expand=True, padx=40, pady=(0, 20))

    def _clear_list(self):
        for widget in self.result_list_frame.winfo_children():
            widget.destroy()

    def _load_results(self):
        self._clear_list()

        log_dir = "results/logs"
        if not os.path.exists(log_dir):
            ctk.CTkLabel(self.result_list_frame, text="The \"results/logs\" folders do not exist.",
                         font=("Arial", 16, "bold"), text_color="red").pack(pady=40)
            return

        log_files = glob.glob(os.path.join(log_dir, "*_Log.txt"))
        log_files.sort(reverse=True, key=os.path.getmtime)

        if not log_files:
            ctk.CTkLabel(self.result_list_frame, text="No result logs found in the results directory.",
                         font=("Arial", 16, "bold"), text_color="red").pack(pady=40)
            return

        for file_path in log_files:
            log_filename = os.path.basename(file_path)
            log_prefix = log_filename.replace("_log.txt", "")

            log_parts = log_prefix.split('_')
            if len(log_parts) >= 3:
                test_mode = log_parts[-1]
                log_timestamp = "_".join(log_parts[:-1])
                try:
                    date_timestamp = datetime.strptime(log_timestamp, "%Y%m%d_%H%M%S")
                    formatted_datetime = date_timestamp.strftime("%B %d, %Y - %H:%M:%S")
                except ValueError:
                    formatted_datetime = log_timestamp
            else:
                test_mode = "Unknown"
                formatted_datetime = log_prefix

            self._create_result_row(formatted_datetime, test_mode, log_timestamp, file_path)

    def _create_result_row(self, test_date, test_mode, raw_timestamp, log_path):
        result_row = ctk.CTkFrame(self.result_list_frame, fg_color=("gray", "gray16"), corner_radius=8)
        result_row.pack(fill="x", pady=5, padx=10)

        badge_color = "blue"
        if test_mode == "Base":
            badge_color = "green"
        elif test_mode == "Performance":
            badge_color = "red"

        badge = ctk.CTkLabel(result_row, text=test_mode.upper(), font=("Arial", 12, "bold"),
                             fg_color=badge_color, text_color="white", corner_radius=4, width=100)
        badge.pack(side="left", padx=10, pady=10)

        ctk.CTkLabel(result_row, text=test_date, font=("Arial", 16)).pack(side="left", padx=15)

        view_button = ctk.CTkButton(result_row, text="View Report", width=100,
                                 command=lambda t=raw_timestamp, m=test_mode,
                                                p=log_path: self._open_logged_result(t, m, p))
        view_button.pack(side="right", padx=10, pady=10)

    def _open_logged_result(self, timestamp, test_mode, log_path):
        result_page = ctk.CTkToplevel(self)
        result_page.title(f"Result of Test: {test_mode} Mode")
        result_page.geometry("1100x750")
        result_page.grab_set()

        ctk.CTkLabel(result_page, text=f"Archived Result: {test_mode} Mode", font=("Arial", 24, "bold")).pack(pady=(20, 5))

        try:
            date_timestamp = datetime.strptime(timestamp, "%Y%m%d_%H%M%S")
            ctk.CTkLabel(result_page, text=date_timestamp.strftime("%B %d, %Y at %H:%M:%S"), font=("Arial", 14, "bold"),
                         text_color="gray").pack(pady=(0, 15))
        except ValueError:
            pass
        except TypeError:
            pass

        result_frame = ctk.CTkFrame(result_page, fg_color="transparent")
        result_frame.pack(fill="both", expand=True, padx=20, pady=10)

        result_left_frame = ctk.CTkFrame(result_frame, width=350, height=700)
        result_left_frame.pack(side="left", fill="y", padx=(0, 10))
        result_left_frame.pack_propagate(False)

        ctk.CTkLabel(result_left_frame, text="Test Result Log", font=("Arial", 16, "bold")).pack(pady=10)

        log_textbox = ctk.CTkTextbox(result_left_frame, font=("Arial", 13), wrap="word")
        log_textbox.pack(fill="both", expand=True, padx=10, pady=(0, 10))

        try:
            with open(log_path, 'r', encoding='utf-8') as bfr:
                log_content = bfr.read()
                log_textbox.insert("0.0", log_content)
        except Exception as ex:
            log_textbox.insert("0.0", f"Error reading log file: {str(ex)}")

        log_textbox.configure(state="disabled")

        result_right_frame = ctk.CTkFrame(result_frame, fg_color="transparent")
        result_right_frame.pack(side="right", fill="both", expand=True)

        result_tabview = ctk.CTkTabview(result_right_frame)
        result_tabview.pack(fill="both", expand=True)

        plots_dir = "results/plots_and_graphs"
        plot_prefix = f"{timestamp}_{test_mode}"

        comparison_chart_path = os.path.join(plots_dir, f"{plot_prefix}_comparison_chart.png")
        if os.path.exists(comparison_chart_path):
            result_tabview.add("Comparison Chart")
            self._embed_plot(result_tabview.tab("Comparison Chart"), comparison_chart_path, size=(700, 450))

        conf_matrix_search_pattern = os.path.join(plots_dir, f"{plot_prefix}_*_conf_matrix.png")
        conf_matrix_files = glob.glob(conf_matrix_search_pattern)
        for conf_matrix_path in conf_matrix_files:
            filename = os.path.basename(conf_matrix_path)
            raw_model_name = filename.replace(f"{plot_prefix}_", "").replace("_conf_matrix.png", "")
            model_name = raw_model_name.replace("_", " ")
            result_tabview.add(model_name)
            self._embed_plot(result_tabview.tab(model_name), conf_matrix_path, size=(500, 450))

    def _embed_plot(self, parent_frame, plot_path, size):
        try:
            plot = Image.open(plot_path)
            ctk_plot = ctk.CTkImage(light_image=plot, dark_image=plot, size=size)
            ctk.CTkLabel(parent_frame, text="", image=ctk_plot).pack(expand=True, pady=10)
        except Exception as ex:
            ctk.CTkLabel(parent_frame, text=f"Error loading image: {str(ex)}", text_color="red").pack(expand=True)