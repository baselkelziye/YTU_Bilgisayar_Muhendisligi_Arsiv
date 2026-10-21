import os
import customtkinter as ctk
from PIL import Image
import pandas as pd
from screens.dataset_manager import DatasetManagerScreen
from screens.algorithm_runner import AlgorithmRunnerScreen
from screens.results_analysis import ResultsAnalysisScreen
from screens.credits import CreditsScreen

class FraudDetectionApplication(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("Fraudulent Review Detection System")
        self.minsize(1050, 700)

        appear_mode = "dark"
        accent_color = "blue"
        ctk.set_appearance_mode(appear_mode)
        ctk.set_default_color_theme(accent_color)

        self.icons = {}
        self._load_all_icons()

        self.clean_dataset = None
        self.raw_dataset = None
        self._load_dataset()

        self.nav_frame = ctk.CTkFrame(self, height=50, corner_radius=0, fg_color=("gray", "gray16"))
        self.nav_frame.pack(side="top", fill="x")
        self.main_content_frame = ctk.CTkFrame(self, corner_radius=0, fg_color="transparent")
        self.main_content_frame.pack(side="top", fill="both", expand=True)
        self.screens = {}

        self._build_navigation_bar()
        self._build_screens()
        self.show_screen("Credits")

    def _load_all_icons(self):
        self.icons["Dataset Manager"] = self._load_icon("dataset_manager_dark_mode.png")
        self.icons["Dataset Statistics"] = self._load_icon("dataset_statistics_dark_mode.png")
        self.icons["Dataset Examples"] = self._load_icon("dataset_examples_dark_mode.png")
        self.icons["Algorithm Runner"] = self._load_icon("algorithm_runner_dark_mode.png")
        self.icons["Results & Analysis"] = self._load_icon("results_analysis_dark_mode.png")
        self.icons["Logs"] = self._load_icon("logs_dark_mode.png")
        self.icons["Credits"] = self._load_icon("references_dark_mode.png")
        self.icons["Settings"] = self._load_icon("settings_dark_mode.png")
        self.icons["Exit"] = self._load_icon("exit_dark_mode.png")

    def _load_icon(self, filename, size=(20, 20)):
        icon_path = os.path.join("resources", "icons", filename)
        if os.path.exists(icon_path):
            return ctk.CTkImage(dark_image=Image.open(icon_path), size=size)
        else:
            print(f"Icon not found: {icon_path}")
        return None

    def _load_dataset(self):
        clean_dataset_path = os.path.join("datasets", "cleaned_fake_reviews.csv")
        raw_dataset_path = os.path.join("datasets", "raw_fake_reviews.csv")

        try:
            self.clean_dataset = pd.read_csv(clean_dataset_path)
            print("Clean dataset loaded successfully.")
        except FileNotFoundError:
            print(f"{clean_dataset_path} not found.")
            self.clean_dataset = None

        try:
            self.raw_dataset = pd.read_csv(raw_dataset_path)
            print("Raw dataset loaded successfully.")
        except FileNotFoundError:
            print(f"{raw_dataset_path} not found.")
            self.raw_dataset = None

    def _build_navigation_bar(self):
        navbar_options = ["Dataset Manager", "Algorithm Runner", "Results & Analysis", "Credits", "Exit"]

        navbar_container = ctk.CTkFrame(self.nav_frame, fg_color="transparent")
        navbar_container.pack(expand=True)

        for option in navbar_options:
            icon = self.icons.get(option)

            if option == "Exit":
                btn = ctk.CTkButton(navbar_container, text=option, image=icon, compound="left",
                    fg_color="transparent", hover_color="red",
                    font=("Arial", 14, "bold"), command=self.quit)
            else:
                btn = ctk.CTkButton(navbar_container, text=option, image=icon, compound="left",
                    fg_color="transparent", font=("Arial", 14, "bold"),
                    command=lambda name=option: self.show_screen(name))

            btn.pack(side="left", padx=15, pady=10)

    def _build_screens(self):
        self.screens["Dataset Manager"] = DatasetManagerScreen(parent_frame=self.main_content_frame, controller=self)
        self.screens["Algorithm Runner"] = AlgorithmRunnerScreen(parent_frame=self.main_content_frame, controller=self)
        self.screens["Results & Analysis"] = ResultsAnalysisScreen(parent_frame=self.main_content_frame, controller=self)
        self.screens["Credits"] = CreditsScreen(parent_frame=self.main_content_frame, controller=self)

    def show_screen(self, screen_name):
        for frame in self.screens.values():
            frame.pack_forget()
        if screen_name in self.screens:
            self.screens[screen_name].pack(fill="both", expand=True)