import customtkinter as ctk

class CreditsScreen(ctk.CTkFrame):
    def __init__(self, parent_frame, controller):
        super().__init__(parent_frame, corner_radius=0, fg_color="transparent")
        self.controller = controller

        self._build_layout()

    def _build_layout(self):
        credits_frame = ctk.CTkFrame(self, corner_radius=15, fg_color=("gray85", "gray16"))
        credits_frame.pack(expand=True, fill="both", padx=60, pady=60)

        credits_inner_frame = ctk.CTkFrame(credits_frame, fg_color="transparent")
        credits_inner_frame.pack(expand=True)

        credits_title_label = ctk.CTkLabel(credits_inner_frame, text="Credits", font=("Arial", 32, "bold"))
        credits_title_label.pack(pady=(0, 30))

        credits_text = (
            "This project was created by Yıldız Technical University MSc student Göksel Okandan "
            "for the Web Mining course of the 2025/2026 spring curriculum."
        )
        ctk.CTkLabel(credits_inner_frame, text=credits_text, font=("Arial", 18, "bold"),
                     wraplength=700, justify="center").pack(pady=(0, 30))

        thanks_text = (
            "The project creator would like to extend his thanks to www.flaticon.com for providing, "
            "and to users Artifex, Becris, muh zakaria, Shashank Zingh, Freepik, gravisio, Pixel perfect "
            "and iconixar for creating the icons used in this project."
        )
        ctk.CTkLabel(credits_inner_frame, text=thanks_text, font=("Arial", 16, "bold"),
                     wraplength=700, justify="center").pack(pady=(0, 30))

        disclaimer_text = (
            "Disclaimer: LLM assistance (Gemini 3.1 Pro) was used during the development process of this project, "
            "primarily for guidance and coding during the desktop application coding process.")
        ctk.CTkLabel(credits_inner_frame, text=disclaimer_text, font=("Arial", 16, "bold"),
                     wraplength=700, justify="center").pack(pady=(0, 30))