import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QComboBox, QPushButton, QTableWidget, QTableWidgetItem, QTextBrowser

class MainWindow(QWidget):
    def __init__(self):
        super(MainWindow, self).__init__()

        self.setWindowTitle("Product Recommendation System Based on Users with Similar Choices")
        self.setGeometry(100, 100, 1267, 665)

        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        # ComboBox
        self.algorithm_combobox = QComboBox(self)
        self.algorithm_combobox.addItems(['SVD', 'k-NN', 'naive Bayesian'])
        layout.addWidget(self.algorithm_combobox)

        # Apply Button
        apply_button = QPushButton('Apply', self)
        apply_button.clicked.connect(self.apply_algorithm)
        layout.addWidget(apply_button)

        # Table Widget
        self.table_widget = QTableWidget(self)
        self.table_widget.setColumnCount(2)
        self.table_widget.setHorizontalHeaderLabels(['Parameter', 'Value'])
        layout.addWidget(self.table_widget)

        # Text Browser
        self.text_browser = QTextBrowser(self)
        layout.addWidget(self.text_browser)

        self.setLayout(layout)

    def apply_algorithm(self):
        selected_algorithm = self.algorithm_combobox.currentText()

        # Clear existing items in the table
        self.table_widget.setRowCount(0)

        # Add information to the table based on the selected algorithm
        if selected_algorithm == 'SVD':
            self.add_table_row('Parameter 1', 'Value 1')
            self.add_table_row('Parameter 2', 'Value 2')
            self.text_browser.setPlainText('Additional information about SVD...')
        elif selected_algorithm == 'k-NN':
            self.add_table_row('Parameter A', 'Value A')
            self.add_table_row('Parameter B', 'Value B')
            self.text_browser.setPlainText('Additional information about k-NN...')
        elif selected_algorithm == 'naive Bayesian':
            self.add_table_row('Parameter X', 'Value X')
            self.add_table_row('Parameter Y', 'Value Y')
            self.text_browser.setPlainText('Additional information about naive Bayesian...')

    def add_table_row(self, param, value):
        current_row = self.table_widget.rowCount()
        self.table_widget.insertRow(current_row)
        self.table_widget.setItem(current_row, 0, QTableWidgetItem(param))
        self.table_widget.setItem(current_row, 1, QTableWidgetItem(value))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = MainWindow()
    main_window.show()
    sys.exit(app.exec_())
