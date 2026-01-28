from PyQt6.QtWidgets import QHBoxLayout, QVBoxLayout, QPushButton, QSizePolicy
from degiskenler import YUKARI_BUTON_STILI, ASAGI_BUTON_STILI
from typing import Callable


class YukariAsagiDugmeDizilimi(QHBoxLayout):
    def __init__(
        self,
        anaFonksiyon: Callable,
        yukariFonksiyonu: Callable,
        asagiFonksiyonu: Callable,
        anaDugmeAciklama: str = "",
        aciklamaMetni: str = "",
        yukariButonBasligi: str = "Yukarı Çıkar",
        asagiButonBasligi: str = "Aşağı İndir",
        yukariButonStili: str = YUKARI_BUTON_STILI,
        asagiButonStili: str = ASAGI_BUTON_STILI,
    ):
        super().__init__()
        yukariAsagiDugmeDizilimi = QVBoxLayout()

        anaDugme = QPushButton(anaDugmeAciklama)
        anaDugme.setToolTip(aciklamaMetni)  # Tam metni araç ipucu olarak ekle
        anaDugme.clicked.connect(anaFonksiyon)

        boyutPolitikasi = QSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Preferred
        )
        anaDugme.setSizePolicy(boyutPolitikasi)
        self.addWidget(anaDugme)

        # Yukarı Taşı butonu
        yukariDugmesi = QPushButton(yukariButonBasligi)
        yukariDugmesi.setStyleSheet(yukariButonStili)
        yukariDugmesi.clicked.connect(yukariFonksiyonu)
        yukariAsagiDugmeDizilimi.addWidget(yukariDugmesi)

        # Aşağı Taşı butonu
        asagiDugmesi = QPushButton(asagiButonBasligi)
        asagiDugmesi.setStyleSheet(asagiButonStili)
        asagiDugmesi.clicked.connect(asagiFonksiyonu)
        yukariAsagiDugmeDizilimi.addWidget(asagiDugmesi)

        self.addLayout(yukariAsagiDugmeDizilimi)
