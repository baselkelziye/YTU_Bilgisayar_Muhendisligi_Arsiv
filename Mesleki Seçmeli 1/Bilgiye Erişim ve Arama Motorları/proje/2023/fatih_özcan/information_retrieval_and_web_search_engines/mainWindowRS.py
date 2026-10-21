import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QComboBox, QPushButton, QTableWidget, \
    QTableWidgetItem, QTextBrowser, QMainWindow, QAction, QMenu, QLabel
from PyQt5.QtCore import Qt
import pandas as pd
from Data_Preprocessing import *
from SVD_Algo import *
import pandas as pd
import time
from Data_Preparation import *
from SVD import *
from NBC import *
from KNN import K_Nearest_Neighbors
from AboutPage import About_Window
from sklearn.neighbors import KNeighborsClassifier
from naive_bayes_classifier import NBC
from NaiveBayes import *
from AboutPage import About_Window
from PyQt5.QtWidgets import QDialog
from PyQt5.QtGui import QFont
from PyQt5.QtGui import QDesktopServices
from PyQt5.QtCore import QUrl
from PyQt5.QtGui import QPixmap, QPainter, QCursor, QIcon, QPalette, QColor

class MainWindow(QWidget):
    def __init__(self):
        super(MainWindow, self).__init__()

        self.setWindowTitle("Product Recommendation System Based on Users with Similar Choices")
        self.setGeometry(100, 100, 600, 400)
        """
        menubar = self.menuBar()
        about_menu = menubar.addMenu('About')
        about_action = QAction('About', self)
        about_menu.addAction(about_action)
        about_action.triggered.connect(self.show_about_window)

        self.central_widget = MainWindow()
        self.setCentralWidget(self.central_widget)
        """
        self.init_ui()  
    def show_about_window(self):
        about_window = About_Window()
        about_window.show()

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
            # SVD Algorithm
            timeout = 10  # Set the timeout value in seconds
            start_time = time.time()
            self.text_browser.setPlainText('SVD is working...')
            temp_head, num_recommendations = SVD_RS()
            # Bekleme döngüsü ekleyerek işlemin tamamlanmasını bekleyin
            while time.time() - start_time < timeout:
                app.processEvents()

            header_labels = ['Recommended Items', 'user_ratings','user_predictions']
            self.table_widget.setColumnCount(len(header_labels))
            self.table_widget.setHorizontalHeaderLabels(header_labels)
            
            self.add_table_row('Parameter 1', 'Value 1')
            self.add_table_row('Parameter 2', 'Value 2')
            self.text_browser.setPlainText("SVD time : %s seconds" % (time.time() - start_time))
        elif selected_algorithm == 'k-NN':
            self.text_browser.setPlainText('k-NN is working...')
            
            start_time = time.time()
            for_tsne_df, knn = K_Nearest_Neighbors()
            end_time = time.time()
            elapsed_time = end_time - start_time
            self.text_browser.setPlainText("k-NN time : %s seconds" % (elapsed_time))

            # Step 1: Select a random user
            random_user_index = np.random.randint(0, len(for_tsne_df))
            selected_user = for_tsne_df.iloc[random_user_index]

            # Step 2: Get t-SNE representation of the selected user
            selected_user_embedding = np.array([[selected_user['Dim_X'], selected_user['Dim_Y']]])
            # Step 3: Use k-NN to find nearest neighbors
            neighbors_indices = knn.kneighbors(selected_user_embedding, n_neighbors=5, return_distance=False)[0]

            # Step 4: Recommend a product from the nearest neighbors
            recommended_product_indices = []
            for neighbor_index in neighbors_indices:
                if neighbor_index != random_user_index:  # Exclude the selected user
                    recommended_product_indices.append(neighbor_index)

            # Print the details of the selected user and the recommended products
            print("Selected User:")
            print(for_tsne_df.iloc[random_user_index])

            print("\nRecommended Products:")
            for product_index in recommended_product_indices:
                print(for_tsne_df.iloc[product_index])
            
            header_labels = ['Selected User', 'Dim_X', 'Dim_Y', 'Score']
            self.table_widget.setColumnCount(len(header_labels))
            self.table_widget.setHorizontalHeaderLabels(header_labels)
            
            # Print the details of the selected user and the recommended products
            selected_user_details = f"Selected User:\n{for_tsne_df.iloc[random_user_index]}\n\n"
            recommended_products_details = "Recommended Products:\n"

            for product_index in recommended_product_indices:
                recommended_products_details += f"{for_tsne_df.iloc[product_index]}\n"

            # Append the details to text_browser
            self.text_browser.append(selected_user_details)
            self.text_browser.append(recommended_products_details)

            # Add the details to the table
            #self.add_table_row("Selected User", for_tsne_df.iloc[random_user_index].to_string())
            user_info = for_tsne_df.iloc[random_user_index].to_string()
            split_values = [value.strip() for value in user_info.split()]
            self.add_table_row4("Selected User", split_values[1], split_values[3], split_values[5])

            for product_index in recommended_product_indices:
                user_info = for_tsne_df.iloc[product_index].to_string()
                split_values = [value.strip() for value in user_info.split()]
                self.add_table_row4("Recommended Product", split_values[1], split_values[3], split_values[5])
            #self.add_table_row('Parameter A', 'Value A')
            #self.add_table_row('Parameter B', 'Value B')
            self.text_browser.setPlainText('Additional information about k-NN...')
            
        elif selected_algorithm == 'naive Bayesian':
            self.text_browser.setPlainText('Naive Bayesian is working...')

            # header labels for the table 
            header_labels = ['User', 'ProductId', 'Actual', 'Predicted']
            self.table_widget.setColumnCount(len(header_labels))
            self.table_widget.setHorizontalHeaderLabels(header_labels)
            start_time = time.time()
            # Naive Bayesian Algorithm
            X_test, y_test, y_pred = Naive_Bayes()
            end_time = time.time()
            elapsed_time = end_time - start_time
            self.text_browser.setPlainText("Naive Bayesian time : %s seconds" % (elapsed_time))

            for user, product_id, actual, predicted in zip(X_test['Id'].head(5), X_test['ProductId'].head(5), y_test[:5], y_pred[:5]):
                print(f"User: {user}, ProductId: {product_id}, Actual: {actual}, Predicted: {predicted}")
                self.add_table_row5(str(user), str(product_id), str(actual), str(predicted), "", "")
                
            

    def add_table_row(self, param, value):
        current_row = self.table_widget.rowCount()
        self.table_widget.insertRow(current_row)
        self.table_widget.setItem(current_row, 0, QTableWidgetItem(param))
        self.table_widget.setItem(current_row, 1, QTableWidgetItem(value))

    def add_table_row3(self, param1, param2, value):
        current_row = self.table_widget.rowCount()
        self.table_widget.insertRow(current_row)
        self.table_widget.setItem(current_row, 0, QTableWidgetItem(param1))
        self.table_widget.setItem(current_row, 1, QTableWidgetItem(param2))
        self.table_widget.setItem(current_row, 2, QTableWidgetItem(value))

    def add_table_row4(self, param1, param2, param3, param4):
        current_row = self.table_widget.rowCount()
        self.table_widget.insertRow(current_row)
        self.table_widget.setItem(current_row, 0, QTableWidgetItem(param1))
        self.table_widget.setItem(current_row, 1, QTableWidgetItem(param2))
        self.table_widget.setItem(current_row, 2, QTableWidgetItem(param3))
        self.table_widget.setItem(current_row, 3, QTableWidgetItem(param4))

    def add_table_row5(self, param1, param2, param3, param4, param5, value):
        current_row = self.table_widget.rowCount()
        self.table_widget.insertRow(current_row)
        self.table_widget.setItem(current_row, 0, QTableWidgetItem(param1))
        self.table_widget.setItem(current_row, 1, QTableWidgetItem(param2))
        self.table_widget.setItem(current_row, 2, QTableWidgetItem(param3))
        self.table_widget.setItem(current_row, 3, QTableWidgetItem(param4))
        self.table_widget.setItem(current_row, 4, QTableWidgetItem(param5))
        self.table_widget.setItem(current_row, 5, QTableWidgetItem(value))


"""
class AboutWindow(QWidget):
    def __init__(self):
        super(AboutWindow, self).__init__()

        self.setWindowTitle("About")
        self.setGeometry(200, 200, 400, 200)

        layout = QVBoxLayout()

        about_label = QLabel("Created by: Your Name\nProject Description: Your project description here.")
        about_label.setAlignment(Qt.AlignCenter)

        layout.addWidget(about_label)
        self.setLayout(layout)
"""

class DatasetWindow(QWidget):
    def __init__(self, dataset_df):
        super(DatasetWindow, self).__init__()

        self.setWindowTitle("Dataset Information")
        self.setGeometry(200, 200, 600, 400)

        layout = QVBoxLayout()

        # Display the head of the dataset in a QTextBrowser
        text_browser = QTextBrowser(self)
        text_browser.setPlainText(dataset_df.head().to_string())

        layout.addWidget(text_browser)
        self.setLayout(layout)


class OptionsWindow(QWidget):
    def __init__(self):
        super(OptionsWindow, self).__init__()

        self.setWindowTitle("Options")
        self.setGeometry(200, 200, 400, 200)

        layout = QVBoxLayout()

        theme_label = QLabel("Select Theme:")
        theme_combobox = QComboBox(self)
        theme_combobox.addItems(['Light', 'Dark'])

        layout.addWidget(theme_label)
        layout.addWidget(theme_combobox)
        self.setLayout(layout)


class MainApplication(QMainWindow):
    def __init__(self):
        super(MainApplication, self).__init__()

        self.setWindowTitle("Product Recommendation System Based on Users with Similar Choices")
        self.setGeometry(100, 100, 1267, 665)

        menubar = self.menuBar()

        # Option Menu
        option_menu = menubar.addMenu('Option')
        """
        theme_action = QAction('Theme', self)
        option_menu.addAction(theme_action)
        theme_action.triggered.connect(self.show_options_window)
        option_menu.aboutToShow.connect(self.show_options_window)
        """

        # Create a "Theme" submenu in the "Options" menu
        theme_menu = QMenu("Theme", self)
        option_menu.addMenu(theme_menu)

        # Create a "Light" action in the "Theme" submenu
        light_theme_action = QAction("Light", self)
        light_theme_action.triggered.connect(self.light_theme)
        theme_menu.addAction(light_theme_action)

        # Create a "Dark" action in the "Theme" submenu
        dark_theme_action = QAction("Dark", self)
        dark_theme_action.triggered.connect(self.dark_theme)
        theme_menu.addAction(dark_theme_action)

        # Dataset Menu
        dataset_menu = menubar.addMenu('Dataset')
        dataset_action = QAction('View Dataset', self)
        dataset_menu.addAction(dataset_action)
        dataset_action.triggered.connect(self.show_dataset_window)

        # Dataset Menu
        help_menu = menubar.addMenu('Help')
        help_menu.aboutToShow.connect(self.show_help_window)

        # About Menu
        about_menu = menubar.addMenu('About')
        about_menu.aboutToShow.connect(self.show_about_window)

        """
        about_menu = menubar.addMenu('About')
        about_action = QAction('About', self)
        about_menu.addAction(about_menu)
        about_action.triggered.connect(self.show_about_window)
        """

        self.central_widget = MainWindow()
        self.setCentralWidget(self.central_widget)

    def show_options_window(self):
        options_window = OptionsWindow()
        options_window.exec_()

    def show_dataset_window(self):
        dataset_df = pd.DataFrame({'Column1': [1, 2, 3], 'Column2': ['A', 'B', 'C']})
        dataset_window = DatasetWindow(dataset_df)
        dataset_window.exec_()

    # Change the theme to light
    def light_theme(self):
        app.setPalette(light_palette)

    # Change the theme to dark
    def dark_theme(self):
        app.setPalette(dark_palette)

    def show_about_window(self):
        w = QDialog(self)
        w.resize(343, 435)
        w.setWindowTitle("About")

        label_2 = QLabel(w)
        label_2.setText("Recommendation System")
        label_2.setGeometry(50, 20, 231, 71)
        font_2 = QFont("MS Shell Dlg 2", 12)
        label_2.setFont(font_2)

        label_2_5 = QLabel(w)
        label_2_5.setText("Created by:")
        label_2_5.setGeometry(30, 180, 111, 61)
        font_2_5 = QFont("MS Shell Dlg 2", 10)
        label_2_5.setFont(font_2_5)

        label_3 = QLabel(w)
        label_3.setText("Fatih Özcan")
        label_3.setGeometry(140, 190, 111, 41)
        font_3 = QFont("MS Shell Dlg 2", 10)
        label_3.setFont(font_3)

        label_4 = QLabel(w)
        label_4.setText("Version 1.0")
        label_4.setGeometry(30, 130, 131, 21)
        font_4 = QFont("MS Shell Dlg 2", 10)
        label_4.setFont(font_4)

        label_5 = QLabel(w)
        label_5.setText("<a href='https://github.com/faozdev'>GitHub</a><br><br>")
        label_5.setGeometry(30, 260, 71, 41)
        font_5 = QFont("MS Shell Dlg 2", 10)
        label_5.setFont(font_5)

        label_5.setOpenExternalLinks(True)
        label_5.linkActivated.connect(self.linkiAc)

        w.exec_()
    def linkiAc(self, link):
        QDesktopServices.openUrl(QUrl(link))

    def show_help_window(self):
        q = QDialog(self)
        q.resize(343, 435)
        q.setWindowTitle("About")

        label_2 = QLabel(q)
        label_2.setText("Recommendation System")
        label_2.setGeometry(50, 20, 231, 71)
        font_2 = QFont("MS Shell Dlg 2", 12)
        label_2.setFont(font_2)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_app = MainApplication()

    # Set the dark theme
    dark_palette = QPalette()
    dark_palette.setColor(QPalette.Window, QColor(53, 53, 53))
    dark_palette.setColor(QPalette.WindowText, QColor(115, 114, 114))
    dark_palette.setColor(QPalette.Base, QColor(25, 25, 25))
    dark_palette.setColor(QPalette.AlternateBase, QColor(53, 53, 53))
    dark_palette.setColor(QPalette.ToolTipBase, QColor(115, 114, 114))
    dark_palette.setColor(QPalette.ToolTipText, QColor(115, 114, 114))
    dark_palette.setColor(QPalette.Text, QColor(115, 114, 114))
    dark_palette.setColor(QPalette.Button, QColor(53, 53, 53))
    dark_palette.setColor(QPalette.ButtonText, QColor(77, 77, 77))
    dark_palette.setColor(QPalette.BrightText, Qt.red)
    dark_palette.setColor(QPalette.Link, QColor(42, 130, 218))
    dark_palette.setColor(QPalette.Highlight, QColor(42, 130, 218))
    dark_palette.setColor(QPalette.HighlightedText, QColor(115, 114, 114))

    # Set the light theme
    light_palette = QPalette()
    light_palette.setColor(QPalette.Window, QColor(255, 255, 255))
    light_palette.setColor(QPalette.WindowText, Qt.black)
    light_palette.setColor(QPalette.Base, QColor(240, 240, 240))
    light_palette.setColor(QPalette.AlternateBase, QColor(255, 255, 255))
    light_palette.setColor(QPalette.ToolTipBase, Qt.black)
    light_palette.setColor(QPalette.ToolTipText, Qt.black)
    light_palette.setColor(QPalette.Text, Qt.black)
    light_palette.setColor(QPalette.Button, QColor(255, 255, 255))
    light_palette.setColor(QPalette.ButtonText, Qt.black)
    light_palette.setColor(QPalette.BrightText, Qt.red)
    light_palette.setColor(QPalette.Link, QColor(42, 130, 218))
    light_palette.setColor(QPalette.Highlight, QColor(42, 130, 218))
    light_palette.setColor(QPalette.HighlightedText, Qt.white)

    # Initialize in light mode
    app.setPalette(light_palette)
    
    main_app.show()
    sys.exit(app.exec_())
