package com.airline.gui;

import com.airline.MainApp;
import com.airline.model.*;
import com.airline.model.enums.FlightStatus;
import com.airline.service.ReportGenerator;

import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Cursor;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;

/**
 * Admin/Personel dashboard ekranı.
 * Uçuş yönetimi, rezervasyon görüntüleme ve rapor oluşturma işlemleri.
 */
public class AdminDashboard {

    private Stage stage;
    private User user;
    private TableView<Flight> flightTable;
    private TableView<Reservation> reservationTable;
    private TextArea reportArea;
    private Label statusLabel;
    private ProgressBar progressBar;

    public AdminDashboard(Stage stage, User user) {
        this.stage = stage;
        this.user = user;
    }

    public void show() {
        stage.setTitle("Yönetim Paneli - " + user.getUsername());

        BorderPane mainLayout = new BorderPane();
        mainLayout.setStyle("-fx-background-color: #f5f5f5;");

        // Üst menü
        mainLayout.setTop(createHeader());

        // İçerik paneli
        StackPane contentPane = new StackPane();
        VBox flightsPane = createFlightsPane();
        VBox reservationsPane = createReservationsPane();
        VBox reportsPane = createReportsPane();
        VBox simulationPane = createSimulationPane();

        reservationsPane.setVisible(false);
        reportsPane.setVisible(false);
        simulationPane.setVisible(false);
        contentPane.getChildren().addAll(flightsPane, reservationsPane, reportsPane, simulationPane);

        // Modern Pill Style Tab Bar
        HBox tabBar = new HBox(10);
        tabBar.setAlignment(Pos.CENTER);
        tabBar.setPadding(new Insets(15, 20, 15, 20));
        tabBar.setStyle("-fx-background-color: #f0f0f0;");

        Button flightsTabBtn = createPillTab("✈ Uçuş Yönetimi", true);
        Button reservationsTabBtn = createPillTab("📋 Rezervasyonlar", false);
        Button reportsTabBtn = createPillTab("📊 Raporlar", false);
        Button simulationTabBtn = createPillTab("🔄 Simülasyon", false);

        Button[] allTabs = { flightsTabBtn, reservationsTabBtn, reportsTabBtn, simulationTabBtn };
        VBox[] allPanes = { flightsPane, reservationsPane, reportsPane, simulationPane };

        int i = 0;
        while (i < allTabs.length) {
            final int index = i;
            allTabs[i].setOnAction(e -> {
                int j = 0;
                while (j < allPanes.length) {
                    allPanes[j].setVisible(j == index);
                    updatePillTabStyle(allTabs[j], j == index);
                    j++;
                }
            });
            i++;
        }

        tabBar.getChildren().addAll(flightsTabBtn, reservationsTabBtn, reportsTabBtn, simulationTabBtn);

        VBox centerContent = new VBox();
        centerContent.getChildren().addAll(tabBar, contentPane);
        VBox.setVgrow(contentPane, Priority.ALWAYS);
        mainLayout.setCenter(centerContent);

        // Ekran boyutuna göre pencere boyutu ayarla
        javafx.stage.Screen screen = javafx.stage.Screen.getPrimary();
        double screenWidth = screen.getVisualBounds().getWidth();
        double screenHeight = screen.getVisualBounds().getHeight();

        // Pencere boyutunu ekranın %85'i olarak ayarla, maksimum 1200x800
        double windowWidth = Math.min(1200, screenWidth * 0.85);
        double windowHeight = Math.min(800, screenHeight * 0.85);

        Scene scene = new Scene(mainLayout, windowWidth, windowHeight);
        stage.setScene(scene);
        stage.setMinWidth(900);
        stage.setMinHeight(600);
        stage.centerOnScreen();
        stage.show();
    }

    private Button createPillTab(String text, boolean isActive) {
        Button btn = new Button(text);
        btn.setCursor(Cursor.HAND);
        updatePillTabStyle(btn, isActive);
        return btn;
    }

    private void updatePillTabStyle(Button btn, boolean isActive) {
        if (isActive) {
            btn.setStyle(
                    "-fx-background-color: #ffc107; " +
                            "-fx-text-fill: #333333; " +
                            "-fx-font-size: 14px; " +
                            "-fx-font-weight: bold; " +
                            "-fx-background-radius: 25; " +
                            "-fx-padding: 10 25; " +
                            "-fx-cursor: hand;");
        } else {
            btn.setStyle(
                    "-fx-background-color: white; " +
                            "-fx-text-fill: #666666; " +
                            "-fx-font-size: 14px; " +
                            "-fx-font-weight: normal; " +
                            "-fx-background-radius: 25; " +
                            "-fx-padding: 10 25; " +
                            "-fx-border-color: #e0e0e0; " +
                            "-fx-border-radius: 25; " +
                            "-fx-cursor: hand;");
        }
        btn.setOnMouseEntered(e -> {
            if (!btn.getStyle().contains("#ffc107")) {
                btn.setStyle(
                        "-fx-background-color: #fff8e1; " +
                                "-fx-text-fill: #333333; " +
                                "-fx-font-size: 14px; " +
                                "-fx-font-weight: normal; " +
                                "-fx-background-radius: 25; " +
                                "-fx-padding: 10 25; " +
                                "-fx-border-color: #ffc107; " +
                                "-fx-border-radius: 25; " +
                                "-fx-cursor: hand;");
            }
        });
        btn.setOnMouseExited(e -> {
            if (!btn.getStyle().contains("#fff8e1"))
                return;
            btn.setStyle(
                    "-fx-background-color: white; " +
                            "-fx-text-fill: #666666; " +
                            "-fx-font-size: 14px; " +
                            "-fx-font-weight: normal; " +
                            "-fx-background-radius: 25; " +
                            "-fx-padding: 10 25; " +
                            "-fx-border-color: #e0e0e0; " +
                            "-fx-border-radius: 25; " +
                            "-fx-cursor: hand;");
        });
    }

    private void applyOutlineStyle(Button btn, String color) {
        btn.setCursor(Cursor.HAND);
        btn.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-text-fill: " + color + "; " +
                        "-fx-font-size: 13px; " +
                        "-fx-font-weight: bold; " +
                        "-fx-background-radius: 8; " +
                        "-fx-border-radius: 8; " +
                        "-fx-border-color: " + color + "; " +
                        "-fx-border-width: 2; " +
                        "-fx-padding: 8 16; " +
                        "-fx-cursor: hand;");
        btn.setOnMouseEntered(e -> {
            btn.setStyle(
                    "-fx-background-color: " + color + "; " +
                            "-fx-text-fill: white; " +
                            "-fx-font-size: 13px; " +
                            "-fx-font-weight: bold; " +
                            "-fx-background-radius: 8; " +
                            "-fx-border-radius: 8; " +
                            "-fx-border-color: " + color + "; " +
                            "-fx-border-width: 2; " +
                            "-fx-padding: 8 16; " +
                            "-fx-cursor: hand;");
        });
        btn.setOnMouseExited(e -> {
            btn.setStyle(
                    "-fx-background-color: transparent; " +
                            "-fx-text-fill: " + color + "; " +
                            "-fx-font-size: 13px; " +
                            "-fx-font-weight: bold; " +
                            "-fx-background-radius: 8; " +
                            "-fx-border-radius: 8; " +
                            "-fx-border-color: " + color + "; " +
                            "-fx-border-width: 2; " +
                            "-fx-padding: 8 16; " +
                            "-fx-cursor: hand;");
        });
    }

    private HBox createHeader() {
        HBox header = new HBox();
        header.setPadding(new Insets(15, 20, 15, 20));
        header.setAlignment(Pos.CENTER_LEFT);
        header.setStyle("-fx-background-color: #f9a825;");

        Label titleLabel = new Label("✈ Havayolu Yönetim Paneli");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 20));
        titleLabel.setTextFill(Color.WHITE);

        Region spacer = new Region();
        HBox.setHgrow(spacer, Priority.ALWAYS);

        Label userLabel = new Label("👤 " + user.getUsername() + " (" + user.getRole().getDescription() + ")");
        userLabel.setFont(Font.font("Arial", 14));
        userLabel.setTextFill(Color.WHITE);

        Button logoutButton = new Button("Çıkış");
        logoutButton.setStyle("-fx-background-color: #c62828; -fx-text-fill: white;");
        logoutButton.setOnAction(e -> {
            MainApp.getUserManager().logout();
            new LoginScreen(stage).show();
        });

        header.getChildren().addAll(titleLabel, spacer, userLabel, new Label("  "), logoutButton);
        return header;
    }

    private VBox createFlightsPane() {
        VBox pane = new VBox(15);
        pane.setPadding(new Insets(20));

        Label titleLabel = new Label("Uçuş Yönetimi");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));

        // Butonlar
        HBox buttonBox = new HBox(10);
        Button addButton = new Button("➕ Yeni Uçuş Ekle");
        applyOutlineStyle(addButton, "#4caf50");
        addButton.setOnAction(e -> showAddFlightDialog());

        Button editButton = new Button("✏ Düzenle");
        applyOutlineStyle(editButton, "#FF9800");
        editButton.setOnAction(e -> showEditFlightDialog());

        Button deleteButton = new Button("🗑 Sil");
        applyOutlineStyle(deleteButton, "#c62828");
        deleteButton.setOnAction(e -> deleteFlight());

        Button refreshButton = new Button("🔄 Yenile");
        applyOutlineStyle(refreshButton, "#FF9800");
        refreshButton.setOnAction(e -> loadFlights());

        buttonBox.getChildren().addAll(addButton, editButton, deleteButton, refreshButton);

        flightTable = createFlightTable();

        pane.getChildren().addAll(titleLabel, buttonBox, flightTable);
        VBox.setVgrow(flightTable, Priority.ALWAYS);

        loadFlights();

        return pane;
    }

    @SuppressWarnings("unchecked")
    private TableView<Flight> createFlightTable() {
        TableView<Flight> table = new TableView<>();
        table.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY_FLEX_LAST_COLUMN);

        TableColumn<Flight, String> numCol = new TableColumn<>("Uçuş No");
        numCol.setCellValueFactory(new PropertyValueFactory<>("flightNum"));
        numCol.setMinWidth(70);

        TableColumn<Flight, String> depCol = new TableColumn<>("Kalkış");
        depCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getDepartureWithAirport()));
        depCol.setMinWidth(120);

        TableColumn<Flight, String> arrCol = new TableColumn<>("Varış");
        arrCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getArrivalWithAirport()));
        arrCol.setMinWidth(120);

        TableColumn<Flight, LocalDate> dateCol = new TableColumn<>("Tarih");
        dateCol.setCellValueFactory(new PropertyValueFactory<>("date"));
        dateCol.setMinWidth(85);

        TableColumn<Flight, String> timeCol = new TableColumn<>("Saat");
        timeCol.setCellValueFactory(new PropertyValueFactory<>("hour"));
        timeCol.setMinWidth(55);

        TableColumn<Flight, Integer> durationCol = new TableColumn<>("Süre(dk)");
        durationCol.setCellValueFactory(new PropertyValueFactory<>("duration"));
        durationCol.setMinWidth(60);

        TableColumn<Flight, String> planeCol = new TableColumn<>("Uçak");
        planeCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getPlane().getPlaneModel()));
        planeCol.setMinWidth(90);

        TableColumn<Flight, Integer> capacityCol = new TableColumn<>("Kapasite");
        capacityCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleIntegerProperty(
                cellData.getValue().getPlane().getCapacity()).asObject());
        capacityCol.setMinWidth(60);

        TableColumn<Flight, Integer> availableCol = new TableColumn<>("Boş");
        availableCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleIntegerProperty(
                cellData.getValue().getAvailableSeatCount()).asObject());
        availableCol.setMinWidth(45);

        TableColumn<Flight, String> statusCol = new TableColumn<>("Durum");
        statusCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getStatus().getDescription()));
        statusCol.setMinWidth(75);

        table.getColumns().addAll(numCol, depCol, arrCol, dateCol, timeCol,
                durationCol, planeCol, capacityCol, availableCol, statusCol);

        return table;
    }

    private void loadFlights() {
        List<Flight> flights = MainApp.getFlightManager().getAllFlights();
        flightTable.setItems(FXCollections.observableArrayList(flights));
    }

    private void showAddFlightDialog() {
        Dialog<Flight> dialog = new Dialog<>();
        dialog.setTitle("Yeni Uçuş Ekle");
        dialog.setHeaderText("Uçuş bilgilerini girin");

        ButtonType addButtonType = new ButtonType("Ekle", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(addButtonType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        TextField flightNumField = new TextField();
        flightNumField.setPromptText("TK001");
        TextField departureField = new TextField();
        departureField.setPromptText("İstanbul");
        TextField arrivalField = new TextField();
        arrivalField.setPromptText("Ankara");
        DatePicker datePicker = new DatePicker(LocalDate.now().plusDays(1));
        TextField hourField = new TextField();
        hourField.setPromptText("10:30");
        TextField durationField = new TextField();
        durationField.setPromptText("60");
        TextField planeIdField = new TextField();
        planeIdField.setPromptText("TC-001");
        TextField planeModelField = new TextField();
        planeModelField.setPromptText("Boeing 737");

        grid.add(new Label("Uçuş No:"), 0, 0);
        grid.add(flightNumField, 1, 0);
        grid.add(new Label("Kalkış:"), 0, 1);
        grid.add(departureField, 1, 1);
        grid.add(new Label("Varış:"), 0, 2);
        grid.add(arrivalField, 1, 2);
        grid.add(new Label("Tarih:"), 0, 3);
        grid.add(datePicker, 1, 3);
        grid.add(new Label("Saat (HH:mm):"), 0, 4);
        grid.add(hourField, 1, 4);
        grid.add(new Label("Süre (dk):"), 0, 5);
        grid.add(durationField, 1, 5);
        grid.add(new Label("Uçak ID:"), 0, 6);
        grid.add(planeIdField, 1, 6);
        grid.add(new Label("Uçak Model:"), 0, 7);
        grid.add(planeModelField, 1, 7);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == addButtonType) {
                try {
                    String[] timeParts = hourField.getText().split(":");
                    LocalTime time = LocalTime.of(
                            Integer.parseInt(timeParts[0]),
                            Integer.parseInt(timeParts[1]));

                    Plane plane = new Plane(planeIdField.getText(), planeModelField.getText(), 500);

                    return MainApp.getFlightManager().createFlight(
                            flightNumField.getText(),
                            departureField.getText(),
                            arrivalField.getText(),
                            datePicker.getValue(),
                            time,
                            Integer.parseInt(durationField.getText()),
                            plane);
                } catch (Exception e) {
                    showAlert("Hata", "Geçersiz bilgi: " + e.getMessage());
                    return null;
                }
            }
            return null;
        });

        dialog.showAndWait().ifPresent(flight -> {
            if (flight != null) {
                showAlert("Başarılı", "Uçuş eklendi: " + flight.getFlightNum());
                loadFlights();
            }
        });
    }

    private void showEditFlightDialog() {
        Flight selected = flightTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Uyarı", "Lütfen düzenlemek istediğiniz uçuşu seçin!");
            return;
        }

        Dialog<Flight> dialog = new Dialog<>();
        dialog.setTitle("Uçuş Düzenle");
        dialog.setHeaderText("Uçuş: " + selected.getFlightNum());

        ButtonType saveButtonType = new ButtonType("Kaydet", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(saveButtonType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        DatePicker datePicker = new DatePicker(selected.getDate());
        TextField hourField = new TextField(selected.getHour().toString());
        TextField durationField = new TextField(String.valueOf(selected.getDuration()));
        ComboBox<FlightStatus> statusCombo = new ComboBox<>();
        statusCombo.setItems(FXCollections.observableArrayList(FlightStatus.values()));
        statusCombo.setValue(selected.getStatus());

        grid.add(new Label("Tarih:"), 0, 0);
        grid.add(datePicker, 1, 0);
        grid.add(new Label("Saat:"), 0, 1);
        grid.add(hourField, 1, 1);
        grid.add(new Label("Süre (dk):"), 0, 2);
        grid.add(durationField, 1, 2);
        grid.add(new Label("Durum:"), 0, 3);
        grid.add(statusCombo, 1, 3);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == saveButtonType) {
                try {
                    String[] timeParts = hourField.getText().split(":");
                    selected.setDate(datePicker.getValue());
                    selected.setHour(LocalTime.of(
                            Integer.parseInt(timeParts[0]),
                            Integer.parseInt(timeParts[1])));
                    selected.setDuration(Integer.parseInt(durationField.getText()));
                    selected.setStatus(statusCombo.getValue());
                    MainApp.getFlightManager().updateFlight(selected);
                    return selected;
                } catch (Exception e) {
                    showAlert("Hata", "Geçersiz bilgi: " + e.getMessage());
                    return null;
                }
            }
            return null;
        });

        dialog.showAndWait().ifPresent(flight -> {
            if (flight != null) {
                showAlert("Başarılı", "Uçuş güncellendi!");
                loadFlights();
            }
        });
    }

    private void deleteFlight() {
        Flight selected = flightTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Uyarı", "Lütfen silmek istediğiniz uçuşu seçin!");
            return;
        }

        Alert confirm = new Alert(Alert.AlertType.CONFIRMATION);
        confirm.setTitle("Onay");
        confirm.setHeaderText("Uçuş Silme");
        confirm.setContentText("Bu uçuşu silmek istediğinizden emin misiniz?\n" + selected.getFlightNum());

        confirm.showAndWait().ifPresent(response -> {
            if (response == ButtonType.OK) {
                MainApp.getFlightManager().deleteFlight(selected.getFlightNum());
                showAlert("Başarılı", "Uçuş silindi.");
                loadFlights();
            }
        });
    }

    private VBox createReservationsPane() {
        VBox pane = new VBox(15);
        pane.setPadding(new Insets(20));

        Label titleLabel = new Label("Tüm Rezervasyonlar");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));

        Button refreshButton = new Button("🔄 Yenile");
        applyOutlineStyle(refreshButton, "#FF9800");
        refreshButton.setOnAction(e -> loadReservations());

        reservationTable = createReservationTable();

        pane.getChildren().addAll(titleLabel, refreshButton, reservationTable);
        VBox.setVgrow(reservationTable, Priority.ALWAYS);

        loadReservations();

        return pane;
    }

    @SuppressWarnings("unchecked")
    private TableView<Reservation> createReservationTable() {
        TableView<Reservation> table = new TableView<>();
        table.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY_FLEX_LAST_COLUMN);

        TableColumn<Reservation, String> codeCol = new TableColumn<>("Kod");
        codeCol.setCellValueFactory(new PropertyValueFactory<>("reservationCode"));
        codeCol.setMinWidth(80);

        TableColumn<Reservation, String> passengerCol = new TableColumn<>("Yolcu");
        passengerCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getPassenger().getFullName()));
        passengerCol.setMinWidth(120);

        TableColumn<Reservation, String> flightCol = new TableColumn<>("Uçuş");
        flightCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getFlight().getFlightNum()));
        flightCol.setMinWidth(70);

        TableColumn<Reservation, String> routeCol = new TableColumn<>("Rota");
        routeCol.setCellValueFactory(cellData -> {
            Flight f = cellData.getValue().getFlight();
            return new javafx.beans.property.SimpleStringProperty(
                    f.getDepartureWithAirport() + " → " + f.getArrivalWithAirport());
        });
        routeCol.setMinWidth(200);

        TableColumn<Reservation, String> seatCol = new TableColumn<>("Koltuk");
        seatCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getSeat().getSeatNum() + " (" +
                        cellData.getValue().getSeat().getClass_() + ")"));
        seatCol.setMinWidth(85);

        TableColumn<Reservation, String> dateCol = new TableColumn<>("Rez. Tarihi");
        dateCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getFormattedDate()));
        dateCol.setMinWidth(100);

        TableColumn<Reservation, String> statusCol = new TableColumn<>("Durum");
        statusCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getStatus().getDescription()));
        statusCol.setMinWidth(75);

        table.getColumns().addAll(codeCol, passengerCol, flightCol, routeCol, seatCol, dateCol, statusCol);

        return table;
    }

    private void loadReservations() {
        List<Reservation> reservations = MainApp.getReservationManager().getAllReservations();
        reservationTable.setItems(FXCollections.observableArrayList(reservations));
    }

    private VBox createReportsPane() {
        VBox pane = new VBox(15);
        pane.setPadding(new Insets(20));

        Label titleLabel = new Label("Raporlar (Asenkron)");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));

        // Rapor butonları
        HBox buttonBox = new HBox(10);

        Button occupancyButton = new Button("📊 Doluluk Raporu");
        applyOutlineStyle(occupancyButton, "#FF9800");
        occupancyButton.setOnAction(e -> generateReport(ReportGenerator.ReportType.OCCUPANCY));

        Button revenueButton = new Button("💰 Gelir Raporu");
        applyOutlineStyle(revenueButton, "#4caf50");
        revenueButton.setOnAction(e -> generateReport(ReportGenerator.ReportType.REVENUE));

        Button reservationButton = new Button("📋 Rezervasyon Raporu");
        applyOutlineStyle(reservationButton, "#FF9800");
        reservationButton.setOnAction(e -> generateReport(ReportGenerator.ReportType.RESERVATION));

        Button fullButton = new Button("📑 Tam Rapor");
        applyOutlineStyle(fullButton, "#4caf50");
        fullButton.setOnAction(e -> generateReport(ReportGenerator.ReportType.FULL));

        buttonBox.getChildren().addAll(occupancyButton, revenueButton, reservationButton, fullButton);

        // Durum göstergesi
        HBox statusBox = new HBox(10);
        statusBox.setAlignment(Pos.CENTER_LEFT);

        statusLabel = new Label("Hazır");
        statusLabel.setFont(Font.font("Arial", 12));

        progressBar = new ProgressBar(0);
        progressBar.setPrefWidth(200);
        progressBar.setVisible(false);

        statusBox.getChildren().addAll(statusLabel, progressBar);

        // Rapor alanı
        reportArea = new TextArea();
        reportArea.setEditable(false);
        reportArea.setFont(Font.font("Consolas", 12));
        reportArea.setStyle("-fx-control-inner-background: #ffffff; -fx-text-fill: #333333; " +
                "-fx-border-color: #e0e0e0; -fx-border-radius: 8; -fx-background-radius: 8;");

        pane.getChildren().addAll(titleLabel, buttonBox, statusBox, reportArea);
        VBox.setVgrow(reportArea, Priority.ALWAYS);

        return pane;
    }

    private void generateReport(ReportGenerator.ReportType type) {
        statusLabel.setText("Rapor hazırlanıyor...");
        progressBar.setVisible(true);
        progressBar.setProgress(ProgressIndicator.INDETERMINATE_PROGRESS);
        reportArea.setText("Lütfen bekleyin...\n\nRapor oluşturuluyor...");

        // Ayrı thread'de rapor oluştur (Senaryo 2)
        ReportGenerator generator = new ReportGenerator(
                MainApp.getFlightManager(),
                MainApp.getReservationManager(),
                type);

        generator.onReportComplete(result -> {
            // GUI thread'inde güncelle
            Platform.runLater(() -> {
                reportArea.setText(result);
                statusLabel.setText("Rapor hazır!");
                progressBar.setVisible(false);
            });
        });

        // Thread başlat
        Thread reportThread = new Thread(generator);
        reportThread.setDaemon(true);
        reportThread.start();
    }

    private VBox createSimulationPane() {
        VBox pane = new VBox(15);
        pane.setPadding(new Insets(20));

        Label titleLabel = new Label("Eşzamanlı Koltuk Rezervasyonu Simülasyonu");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));

        Label descLabel = new Label("Bu simülasyon, 90 yolcunun aynı anda 180 koltuğa\n" +
                "rezervasyon yapmaya çalıştığı senaryoyu gösterir.");

        // Simülasyon kontrolleri
        HBox controlBox = new HBox(15);
        controlBox.setAlignment(Pos.CENTER_LEFT);

        CheckBox syncCheckBox = new CheckBox("Synchronized (Thread-Safe)");
        syncCheckBox.setSelected(true);

        Button startButton = new Button("▶ Simülasyonu Başlat");
        applyOutlineStyle(startButton, "#4caf50");

        controlBox.getChildren().addAll(syncCheckBox, startButton);

        // Simülasyon paneli
        SeatSimulationPanel simulationPanel = new SeatSimulationPanel();

        startButton.setOnAction(e -> {
            simulationPanel.runSimulation(syncCheckBox.isSelected());
        });

        pane.getChildren().addAll(titleLabel, descLabel, controlBox, simulationPanel);
        VBox.setVgrow(simulationPanel, Priority.ALWAYS);

        return pane;
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
