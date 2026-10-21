package com.airline.gui;

import com.airline.MainApp;
import com.airline.model.User;
import com.airline.model.Customer;
import com.airline.model.enums.UserRole;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

/**
 * Kullanıcı giriş ekranı.
 * Kullanıcı girişi ve yeni kayıt işlemlerini yönetir.
 */
public class LoginScreen {

    private Stage stage;
    private TextField usernameField;
    private PasswordField passwordField;
    private Label messageLabel;

    public LoginScreen(Stage stage) {
        this.stage = stage;
    }

    public void show() {
        stage.setTitle("Havayolu Rezervasyon Sistemi - Giriş");

        // Ana layout - Sol: Resim, Sağ: Form
        HBox mainLayout = new HBox();
        mainLayout.setStyle("-fx-background-color: linear-gradient(to bottom, #f9a825, #ff8f00);");

        // ===== SOL TARAF: Resim =====
        VBox leftPane = new VBox();
        leftPane.setAlignment(Pos.CENTER);
        leftPane.setPrefWidth(400);
        leftPane.setPadding(new Insets(20));

        try {
            // Önce classpath'ten yüklemeyi dene (Eclipse ve JAR için)
            java.io.InputStream is = getClass().getResourceAsStream("/resources/ytu_airline.png");
            if (is == null) {
                // Alternatif yol dene
                is = getClass().getClassLoader().getResourceAsStream("resources/ytu_airline.png");
            }
            if (is == null) {
                // Dosya sisteminden yüklemeyi dene
                java.io.File imageFile = new java.io.File("resources/ytu_airline.png");
                if (!imageFile.exists()) {
                    imageFile = new java.io.File("src/resources/ytu_airline.png");
                }
                if (!imageFile.exists()) {
                    imageFile = new java.io.File("../resources/ytu_airline.png");
                }
                if (imageFile.exists()) {
                    is = new java.io.FileInputStream(imageFile);
                }
            }
            if (is != null) {
                Image airlineImage = new Image(is);
                ImageView imageView = new ImageView(airlineImage);
                imageView.setFitWidth(350);
                imageView.setPreserveRatio(true);
                imageView.setSmooth(true);
                leftPane.getChildren().add(imageView);
            } else {
                throw new Exception("Image not found");
            }
        } catch (Exception e) {
            // Resim bulunamazsa placeholder göster
            Label placeholderLabel = new Label("✈");
            placeholderLabel.setFont(Font.font("Arial", FontWeight.BOLD, 120));
            placeholderLabel.setTextFill(Color.WHITE);
            leftPane.getChildren().add(placeholderLabel);
        }

        // ===== SAĞ TARAF: Form =====
        VBox rightPane = new VBox(20);
        rightPane.setAlignment(Pos.CENTER);
        rightPane.setPadding(new Insets(40));
        HBox.setHgrow(rightPane, Priority.ALWAYS);

        // Başlık
        Label titleLabel = new Label("✈ Havayolu Rezervasyon Sistemi");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 28));
        titleLabel.setTextFill(Color.WHITE);

        Label subtitleLabel = new Label("Hoş Geldiniz");
        subtitleLabel.setFont(Font.font("Arial", 16));
        subtitleLabel.setTextFill(Color.WHITE);

        // Form container
        VBox formBox = new VBox(15);
        formBox.setAlignment(Pos.CENTER);
        formBox.setPadding(new Insets(30));
        formBox.setMaxWidth(350);
        formBox.setStyle("-fx-background-color: white; -fx-background-radius: 10;");

        // Kullanıcı adı
        Label usernameLabel = new Label("Kullanıcı Adı");
        usernameLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
        usernameField = new TextField();
        usernameField.setPromptText("Kullanıcı adınızı girin");
        usernameField.setPrefHeight(40);
        usernameField.setStyle("-fx-font-size: 14px; -fx-background-radius: 5;");

        // Şifre
        Label passwordLabel = new Label("Şifre");
        passwordLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
        passwordField = new PasswordField();
        passwordField.setPromptText("Şifrenizi girin");
        passwordField.setPrefHeight(40);
        passwordField.setStyle("-fx-font-size: 14px; -fx-background-radius: 5;");

        // Mesaj etiketi
        messageLabel = new Label();
        messageLabel.setFont(Font.font("Arial", 12));

        // Giriş butonu
        Button loginButton = new Button("Giriş Yap");
        loginButton.setPrefWidth(200);
        loginButton.setPrefHeight(40);
        loginButton.setStyle("-fx-background-color: #f9a825; -fx-text-fill: white; " +
                "-fx-font-size: 14px; -fx-font-weight: bold; -fx-cursor: hand; -fx-background-radius: 5;");
        loginButton.setOnAction(e -> handleLogin());

        // Kayıt ol butonu
        Button registerButton = new Button("Yeni Hesap Oluştur");
        registerButton.setPrefWidth(200);
        registerButton.setPrefHeight(35);
        registerButton.setStyle("-fx-background-color: transparent; -fx-text-fill: #f9a825; " +
                "-fx-font-size: 12px; -fx-cursor: hand; -fx-border-color: #f9a825; -fx-border-radius: 5;");
        registerButton.setOnAction(e -> showRegisterDialog());

        // Enter tuşu ile giriş
        passwordField.setOnAction(e -> handleLogin());

        formBox.getChildren().addAll(
                usernameLabel, usernameField,
                passwordLabel, passwordField,
                messageLabel,
                loginButton, registerButton);

        rightPane.getChildren().addAll(titleLabel, subtitleLabel, formBox);

        // Ana layout'a ekle
        mainLayout.getChildren().addAll(leftPane, rightPane);

        // Ekran boyutuna göre pencere boyutu ayarla
        javafx.stage.Screen screen = javafx.stage.Screen.getPrimary();
        double screenWidth = screen.getVisualBounds().getWidth();
        double screenHeight = screen.getVisualBounds().getHeight();

        // Pencere boyutunu ayarla
        double windowWidth = Math.max(900, Math.min(1000, screenWidth * 0.7));
        double windowHeight = Math.max(550, Math.min(650, screenHeight * 0.7));

        Scene scene = new Scene(mainLayout, windowWidth, windowHeight);
        stage.setScene(scene);
        stage.setMinWidth(800);
        stage.setMinHeight(500);
        stage.setResizable(true);
        stage.centerOnScreen();
        stage.show();
    }

    private void handleLogin() {
        String username = usernameField.getText().trim();
        String password = passwordField.getText();

        if (username.isEmpty() || password.isEmpty()) {
            showMessage("Kullanıcı adı ve şifre gerekli!", Color.RED);
            return;
        }

        User user = MainApp.getUserManager().login(username, password);

        if (user != null) {
            showMessage("Giriş başarılı!", Color.GREEN);

            // Kullanıcı rolüne göre ekran aç
            if (user.getRole() == UserRole.ADMIN || user.getRole() == UserRole.STAFF) {
                new AdminDashboard(stage, user).show();
            } else {
                new CustomerDashboard(stage, (Customer) user).show();
            }
        } else {
            showMessage("Geçersiz kullanıcı adı veya şifre!", Color.RED);
        }
    }

    private void showRegisterDialog() {
        Dialog<Customer> dialog = new Dialog<>();
        dialog.setTitle("Yeni Hesap Oluştur");
        dialog.setHeaderText("Bilgilerinizi girin");

        // Butonlar
        ButtonType registerButtonType = new ButtonType("Kayıt Ol", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(registerButtonType, ButtonType.CANCEL);

        // Form alanları
        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        TextField firstNameField = new TextField();
        firstNameField.setPromptText("Ad");
        TextField lastNameField = new TextField();
        lastNameField.setPromptText("Soyad");
        TextField emailField = new TextField();
        emailField.setPromptText("E-posta");
        TextField phoneField = new TextField();
        phoneField.setPromptText("Telefon");
        TextField newUsernameField = new TextField();
        newUsernameField.setPromptText("Kullanıcı adı");
        PasswordField newPasswordField = new PasswordField();
        newPasswordField.setPromptText("Şifre");

        grid.add(new Label("Ad:"), 0, 0);
        grid.add(firstNameField, 1, 0);
        grid.add(new Label("Soyad:"), 0, 1);
        grid.add(lastNameField, 1, 1);
        grid.add(new Label("E-posta:"), 0, 2);
        grid.add(emailField, 1, 2);
        grid.add(new Label("Telefon:"), 0, 3);
        grid.add(phoneField, 1, 3);
        grid.add(new Label("Kullanıcı Adı:"), 0, 4);
        grid.add(newUsernameField, 1, 4);
        grid.add(new Label("Şifre:"), 0, 5);
        grid.add(newPasswordField, 1, 5);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == registerButtonType) {
                try {
                    Customer customer = MainApp.getUserManager().registerCustomer(
                            newUsernameField.getText().trim(),
                            newPasswordField.getText(),
                            emailField.getText().trim(),
                            firstNameField.getText().trim(),
                            lastNameField.getText().trim(),
                            phoneField.getText().trim());
                    return customer;
                } catch (IllegalArgumentException e) {
                    showAlert("Hata", e.getMessage());
                    return null;
                }
            }
            return null;
        });

        dialog.showAndWait().ifPresent(customer -> {
            if (customer != null) {
                showMessage("Kayıt başarılı! Giriş yapabilirsiniz.", Color.GREEN);
                usernameField.setText(customer.getUsername());
            }
        });
    }

    private void showMessage(String message, Color color) {
        messageLabel.setText(message);
        messageLabel.setTextFill(color);
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
