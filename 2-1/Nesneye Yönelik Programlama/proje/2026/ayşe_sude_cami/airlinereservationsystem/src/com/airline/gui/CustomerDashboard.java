package com.airline.gui;

import com.airline.MainApp;
import com.airline.model.*;
import com.airline.model.enums.AdditionalService;
import com.airline.model.enums.SeatClass;
import com.airline.service.FlightSearchEngine;
import com.airline.service.PriceCalculator;

import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.shape.SVGPath;
import javafx.stage.Stage;
import javafx.scene.Cursor;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Müşteri dashboard ekranı.
 * Uçuş arama, rezervasyon yapma ve rezervasyon yönetimi işlemleri.
 */
public class CustomerDashboard {

    private Stage stage;
    private Customer customer;
    private FlightSearchEngine searchEngine;
    private PriceCalculator priceCalculator;
    private TableView<Flight> flightTable;
    private TableView<Reservation> reservationTable;
    private ComboBox<String> departureCombo;
    private ComboBox<String> arrivalCombo;
    private DatePicker datePicker;
    private DatePicker returnDatePicker;
    private ComboBox<String> tripTypeCombo;
    private ComboBox<String> passengerCombo;
    private ComboBox<SeatClass> cabinClassCombo;

    public CustomerDashboard(Stage stage, Customer customer) {
        this.stage = stage;
        this.customer = customer;
        this.searchEngine = new FlightSearchEngine(MainApp.getFlightManager());
        this.priceCalculator = new PriceCalculator();
    }

    public void show() {
        stage.setTitle("Havayolu Rezervasyon - " + customer.getUsername());

        BorderPane mainLayout = new BorderPane();
        mainLayout.setStyle("-fx-background-color: #f5f5f5;");

        // Üst menü
        mainLayout.setTop(createHeader());

        // İçerik paneli
        StackPane contentPane = new StackPane();
        VBox searchPane = createSearchPane();
        VBox reservationsPane = createReservationsPane();
        reservationsPane.setVisible(false);
        contentPane.getChildren().addAll(searchPane, reservationsPane);

        // Modern Pill Style Tab Bar
        HBox tabBar = new HBox(10);
        tabBar.setAlignment(Pos.CENTER);
        tabBar.setPadding(new Insets(15, 20, 15, 20));
        tabBar.setStyle("-fx-background-color: #f0f0f0;");

        Button searchTabBtn = createPillTab("🔍 Uçuş Ara", true);
        Button reservationsTabBtn = createPillTab("📋 Rezervasyonlarım", false);

        searchTabBtn.setOnAction(e -> {
            searchPane.setVisible(true);
            reservationsPane.setVisible(false);
            updatePillTabStyle(searchTabBtn, true);
            updatePillTabStyle(reservationsTabBtn, false);
        });

        reservationsTabBtn.setOnAction(e -> {
            searchPane.setVisible(false);
            reservationsPane.setVisible(true);
            loadReservations();
            updatePillTabStyle(searchTabBtn, false);
            updatePillTabStyle(reservationsTabBtn, true);
        });

        tabBar.getChildren().addAll(searchTabBtn, reservationsTabBtn);

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
        header.setStyle("-fx-background-color: #ffc107;");

        Label titleLabel = new Label("✈ Havayolu Rezervasyon Sistemi");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 20));
        titleLabel.setTextFill(Color.WHITE);

        Region spacer = new Region();
        HBox.setHgrow(spacer, Priority.ALWAYS);

        Label userLabel = new Label("Hoş geldiniz, " +
                (customer.getPassenger() != null ? customer.getPassenger().getFullName() : customer.getUsername()));
        userLabel.setFont(Font.font("Arial", 14));
        userLabel.setTextFill(Color.WHITE);

        Button logoutButton = new Button("Çıkış");
        applyOutlineStyle(logoutButton, "#c62828");
        logoutButton.setOnAction(e -> {
            MainApp.getUserManager().logout();
            new LoginScreen(stage).show();
        });

        header.getChildren().addAll(titleLabel, spacer, userLabel, new Label("  "), logoutButton);
        return header;
    }

    private VBox createSearchPane() {
        VBox pane = new VBox(20);
        pane.setPadding(new Insets(0));
        pane.setStyle("-fx-background-color: #f5f5f5;");

        // Ana arama bölümü - koyu sarı arka plan
        VBox searchSection = new VBox(15);
        searchSection.setPadding(new Insets(20, 30, 25, 30));
        searchSection.setStyle("-fx-background-color: #ffc107;");

        // Üst kısım: Trip Type Chip
        HBox topRow = new HBox(10);
        topRow.setAlignment(Pos.CENTER_LEFT);

        tripTypeCombo = new ComboBox<>();
        tripTypeCombo.getItems().addAll("Gidiş Dönüş", "Tek Yön");
        tripTypeCombo.setValue("Gidiş Dönüş");
        tripTypeCombo.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-border-color: rgba(255,255,255,0.5); " +
                        "-fx-border-radius: 20; " +
                        "-fx-background-radius: 20; " +
                        "-fx-text-fill: white; " +
                        "-fx-font-size: 13px; " +
                        "-fx-padding: 6 12;");

        topRow.getChildren().add(tripTypeCombo);

        // Ana arama kutusu - beyaz arka plan
        HBox searchBox = new HBox(0);
        searchBox.setAlignment(Pos.CENTER);
        searchBox.setStyle(
                "-fx-background-color: white; " +
                        "-fx-background-radius: 10; " +
                        "-fx-border-radius: 10;");
        searchBox.setPadding(new Insets(5));

        // Kalkış Bölümü
        VBox departureBox = createSearchField("Kalkış:", "Ülke, şehir veya havaalanı", true);
        departureBox.setPrefWidth(200);

        // Swap Button - Skyscanner tarzı yukarı-aşağı oklar
        StackPane swapButtonPane = new StackPane();
        swapButtonPane.setStyle(
                "-fx-background-color: white; " +
                        "-fx-border-color: #ffc107; " +
                        "-fx-border-width: 3; " +
                        "-fx-border-radius: 50; " +
                        "-fx-background-radius: 50; " +
                        "-fx-min-width: 40; " +
                        "-fx-min-height: 40; " +
                        "-fx-max-width: 40; " +
                        "-fx-max-height: 40; " +
                        "-fx-cursor: hand;");
        swapButtonPane.setCursor(Cursor.HAND);

        // SVGPath ile yukarı-aşağı ok ikonu
        SVGPath swapIcon = new SVGPath();
        swapIcon.setContent("M2 4 L6 0 L10 4 M6 0 L6 14 M14 10 L18 14 L22 10 M18 14 L18 0");
        swapIcon.setStyle("-fx-fill: transparent; -fx-stroke: #ffc107; -fx-stroke-width: 2;");
        swapIcon.setScaleX(0.6);
        swapIcon.setScaleY(0.6);
        swapIcon.setRotate(90); // 90 derece çevir - yatay yap

        swapButtonPane.getChildren().add(swapIcon);
        swapButtonPane.setOnMouseClicked(e -> swapLocations());
        swapButtonPane.setOnMouseEntered(e -> swapButtonPane.setStyle(
                "-fx-background-color: #f0f0f0; " +
                        "-fx-border-color: #ffc107; " +
                        "-fx-border-width: 3; " +
                        "-fx-border-radius: 50; " +
                        "-fx-background-radius: 50; " +
                        "-fx-min-width: 40; " +
                        "-fx-min-height: 40; " +
                        "-fx-max-width: 40; " +
                        "-fx-max-height: 40; " +
                        "-fx-cursor: hand;"));
        swapButtonPane.setOnMouseExited(e -> swapButtonPane.setStyle(
                "-fx-background-color: white; " +
                        "-fx-border-color: #ffc107; " +
                        "-fx-border-width: 3; " +
                        "-fx-border-radius: 50; " +
                        "-fx-background-radius: 50; " +
                        "-fx-min-width: 40; " +
                        "-fx-min-height: 40; " +
                        "-fx-max-width: 40; " +
                        "-fx-max-height: 40; " +
                        "-fx-cursor: hand;"));

        StackPane swapPane = new StackPane(swapButtonPane);
        swapPane.setPadding(new Insets(10, 5, 0, 5));

        // Varış Bölümü
        VBox arrivalBox = createSearchField("Nereye", "Ülke, şehir veya havaalanı", false);
        arrivalBox.setPrefWidth(200);

        // Ayırıcı
        Region separator1 = createSeparator();

        // Kalkış Tarihi
        VBox departureDateBox = createDateField("Kalkış", "Tarih ekleyin", true);
        departureDateBox.setPrefWidth(140);

        // Ayırıcı
        Region separator2 = createSeparator();

        // Dönüş Tarihi
        VBox returnDateBox = createDateField("Dönüş", "Tarih ekleyin", false);
        returnDateBox.setPrefWidth(140);

        // Ayırıcı
        Region separator3 = createSeparator();

        // Trip Type değişikliğinde dönüş tarihini gizle/göster
        tripTypeCombo.setOnAction(e -> {
            boolean isRoundTrip = "Gidiş Dönüş".equals(tripTypeCombo.getValue());
            returnDateBox.setVisible(isRoundTrip);
            returnDateBox.setManaged(isRoundTrip);
            separator2.setVisible(isRoundTrip);
            separator2.setManaged(isRoundTrip);
        });

        // Yolcular ve Kabin Sınıfı
        VBox passengerBox = createPassengerField();
        passengerBox.setPrefWidth(280);
        passengerBox.setMinWidth(280);

        // Ara butonu öncesi boşluk
        Region spacer = new Region();
        spacer.setPrefWidth(15);

        // Ara Butonu
        Button searchButton = new Button("Ara");
        searchButton.setMinWidth(80);
        searchButton.setPrefWidth(80);
        searchButton.setStyle(
                "-fx-background-color: #ffc107; " +
                        "-fx-text-fill: #333; " +
                        "-fx-font-size: 16px; " +
                        "-fx-font-weight: bold; " +
                        "-fx-background-radius: 8; " +
                        "-fx-padding: 15 20; " +
                        "-fx-cursor: hand;");
        searchButton.setCursor(Cursor.HAND);
        searchButton.setOnAction(e -> searchFlights());

        searchBox.getChildren().addAll(
                departureBox, swapPane, arrivalBox, separator1,
                departureDateBox, separator2, returnDateBox, separator3,
                passengerBox, spacer, searchButton);

        // Tüm uçuşları göster butonu
        Button showAllButton = new Button("Tüm Uçuşları Göster");
        showAllButton.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-text-fill: rgba(255,255,255,0.8); " +
                        "-fx-font-size: 13px; " +
                        "-fx-underline: true; " +
                        "-fx-cursor: hand;");
        showAllButton.setCursor(Cursor.HAND);
        showAllButton.setOnAction(e -> showAllFlights());

        HBox bottomRow = new HBox(showAllButton);
        bottomRow.setAlignment(Pos.CENTER_RIGHT);
        bottomRow.setPadding(new Insets(10, 0, 0, 0));

        searchSection.getChildren().addAll(topRow, searchBox, bottomRow);

        // Sonuçlar bölümü
        VBox resultsSection = new VBox(15);
        resultsSection.setPadding(new Insets(20));
        resultsSection.setStyle("-fx-background-color: #f5f5f5;");

        Label resultsLabel = new Label("Uçuş Sonuçları");
        resultsLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));
        resultsLabel.setTextFill(Color.web("#ffc107"));

        // Uçuş tablosu
        flightTable = createFlightTable();

        // Rezervasyon butonu
        Button reserveButton = new Button("✈ Seçili Uçuşu Rezerve Et");
        reserveButton.setStyle(
                "-fx-background-color: #ffc107; " +
                        "-fx-text-fill: #333; " +
                        "-fx-font-size: 14px; " +
                        "-fx-font-weight: bold; " +
                        "-fx-padding: 12 30; " +
                        "-fx-background-radius: 8;");
        reserveButton.setCursor(Cursor.HAND);
        reserveButton.setOnAction(e -> makeReservation());

        HBox buttonBox = new HBox(reserveButton);
        buttonBox.setAlignment(Pos.CENTER);
        buttonBox.setPadding(new Insets(10, 0, 0, 0));

        resultsSection.getChildren().addAll(resultsLabel, flightTable, buttonBox);
        VBox.setVgrow(flightTable, Priority.ALWAYS);

        pane.getChildren().addAll(searchSection, resultsSection);
        VBox.setVgrow(resultsSection, Priority.ALWAYS);

        // Şehirleri yükle
        loadCities();

        // Başlangıçta tüm uçuşları göster
        showAllFlights();

        return pane;
    }

    private VBox createSearchField(String label, String placeholder, boolean isDeparture) {
        VBox box = new VBox(2);
        box.setPadding(new Insets(10, 15, 10, 15));

        Label fieldLabel = new Label(label);
        fieldLabel.setStyle("-fx-text-fill: #68697f; -fx-font-size: 12px;");

        ComboBox<String> combo;
        if (isDeparture) {
            departureCombo = new ComboBox<>();
            combo = departureCombo;
        } else {
            arrivalCombo = new ComboBox<>();
            combo = arrivalCombo;
        }

        combo.setPromptText(placeholder);
        combo.setEditable(true);
        combo.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-border-color: transparent; " +
                        "-fx-font-size: 14px; " +
                        "-fx-font-weight: bold; " +
                        "-fx-padding: 0;");
        combo.setPrefWidth(170);

        box.getChildren().addAll(fieldLabel, combo);
        return box;
    }

    private VBox createDateField(String label, String placeholder, boolean isDeparture) {
        VBox box = new VBox(2);
        box.setPadding(new Insets(10, 15, 10, 15));

        Label fieldLabel = new Label(label);
        fieldLabel.setStyle("-fx-text-fill: #68697f; -fx-font-size: 12px;");

        DatePicker picker;
        if (isDeparture) {
            datePicker = new DatePicker();
            picker = datePicker;
        } else {
            returnDatePicker = new DatePicker();
            picker = returnDatePicker;
        }

        picker.setPromptText(placeholder);
        picker.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-border-color: transparent; " +
                        "-fx-font-size: 13px;");
        picker.setPrefWidth(120);

        box.getChildren().addAll(fieldLabel, picker);
        return box;
    }

    private VBox createPassengerField() {
        VBox box = new VBox(2);
        box.setPadding(new Insets(10, 10, 10, 10));

        Label fieldLabel = new Label("Yolcular ve kabin sınıfı");
        fieldLabel.setStyle("-fx-text-fill: #68697f; -fx-font-size: 12px;");

        HBox valueBox = new HBox(0);
        valueBox.setAlignment(Pos.CENTER_LEFT);

        passengerCombo = new ComboBox<>();
        passengerCombo.getItems().addAll("1 yetişkin", "2 yetişkin", "3 yetişkin", "4 yetişkin");
        passengerCombo.setValue("1 yetişkin");
        passengerCombo.setMinWidth(120);
        passengerCombo.setPrefWidth(120);
        passengerCombo.setButtonCell(new javafx.scene.control.ListCell<>() {
            @Override
            protected void updateItem(String item, boolean empty) {
                super.updateItem(item, empty);
                setText(empty ? "" : item);
            }
        });
        passengerCombo.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-border-color: transparent; " +
                        "-fx-font-size: 13px; " +
                        "-fx-font-weight: bold;");

        cabinClassCombo = new ComboBox<>();
        cabinClassCombo.getItems().addAll(SeatClass.values());
        cabinClassCombo.setValue(SeatClass.ECONOMY);
        cabinClassCombo.setMinWidth(120);
        cabinClassCombo.setPrefWidth(120);
        cabinClassCombo.setButtonCell(new javafx.scene.control.ListCell<>() {
            @Override
            protected void updateItem(SeatClass item, boolean empty) {
                super.updateItem(item, empty);
                setText(empty ? "" : item.getDisplayName());
            }
        });
        cabinClassCombo.setStyle(
                "-fx-background-color: transparent; " +
                        "-fx-border-color: transparent; " +
                        "-fx-font-size: 13px; " +
                        "-fx-font-weight: bold;");

        valueBox.getChildren().addAll(passengerCombo, cabinClassCombo);
        box.getChildren().addAll(fieldLabel, valueBox);
        return box;
    }

    private Region createSeparator() {
        Region separator = new Region();
        separator.setStyle("-fx-background-color: #e0e0e0;");
        separator.setPrefWidth(1);
        separator.setPrefHeight(50);
        return separator;
    }

    private void swapLocations() {
        String departure = departureCombo.getValue();
        String arrival = arrivalCombo.getValue();
        departureCombo.setValue(arrival);
        arrivalCombo.setValue(departure);
    }

    private void loadCities() {
        List<String> departures = searchEngine.getAllDepartureCities();
        List<String> arrivals = searchEngine.getAllArrivalCities();

        departureCombo.setItems(FXCollections.observableArrayList(departures));
        arrivalCombo.setItems(FXCollections.observableArrayList(arrivals));
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
        depCol.setMinWidth(130);

        TableColumn<Flight, String> arrCol = new TableColumn<>("Varış");
        arrCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getArrivalWithAirport()));
        arrCol.setMinWidth(130);

        TableColumn<Flight, LocalDate> dateCol = new TableColumn<>("Tarih");
        dateCol.setCellValueFactory(new PropertyValueFactory<>("date"));
        dateCol.setMinWidth(85);

        TableColumn<Flight, String> timeCol = new TableColumn<>("Saat");
        timeCol.setCellValueFactory(new PropertyValueFactory<>("hour"));
        timeCol.setMinWidth(60);

        TableColumn<Flight, String> durationCol = new TableColumn<>("Süre");
        durationCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getFormattedDuration()));
        durationCol.setMinWidth(70);

        TableColumn<Flight, Integer> seatsCol = new TableColumn<>("Boş Koltuk");
        seatsCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleIntegerProperty(
                cellData.getValue().getAvailableSeatCount()).asObject());
        seatsCol.setMinWidth(75);

        TableColumn<Flight, String> statusCol = new TableColumn<>("Durum");
        statusCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getStatus().getDescription()));
        statusCol.setMinWidth(80);

        table.getColumns().addAll(numCol, depCol, arrCol, dateCol, timeCol, durationCol, seatsCol, statusCol);
        table.setPlaceholder(new Label("Uçuş bulunamadı"));

        return table;
    }

    private void searchFlights() {
        String departure = departureCombo.getValue();
        String arrival = arrivalCombo.getValue();
        LocalDate date = datePicker.getValue();
        boolean isRoundTrip = "Gidiş Dönüş".equals(tripTypeCombo.getValue());
        LocalDate returnDate = returnDatePicker.getValue();

        if (departure == null || arrival == null) {
            showAlert("Uyarı", "Lütfen kalkış ve varış şehirlerini seçin!");
            return;
        }

        // Gidiş-dönüş seçiliyse dönüş tarihini kontrol et
        if (isRoundTrip && returnDate == null) {
            showAlert("Uyarı", "Gidiş-dönüş için lütfen dönüş tarihini de seçin!");
            return;
        }

        // Dönüş tarihi kalkış tarihinden önce olamaz
        if (isRoundTrip && date != null && returnDate != null && returnDate.isBefore(date)) {
            showAlert("Uyarı", "Dönüş tarihi kalkış tarihinden önce olamaz!");
            return;
        }

        // Gidiş uçuşlarını ara
        List<Flight> outboundResults = searchEngine.searchFlights(departure, arrival, date);

        if (isRoundTrip) {
            // Dönüş uçuşlarını da ara (varış -> kalkış)
            List<Flight> returnResults = searchEngine.searchFlights(arrival, departure, returnDate);

            // Her iki yönde de uçuş varsa göster
            if (outboundResults.isEmpty() && returnResults.isEmpty()) {
                flightTable.setItems(FXCollections.observableArrayList());
                showAlert("Bilgi", "Gidiş ve dönüş için uygun uçuş bulunamadı.");
            } else if (outboundResults.isEmpty()) {
                flightTable.setItems(FXCollections.observableArrayList(returnResults));
                showAlert("Bilgi", "Gidiş için uygun uçuş bulunamadı. Sadece dönüş uçuşları gösteriliyor.");
            } else if (returnResults.isEmpty()) {
                flightTable.setItems(FXCollections.observableArrayList(outboundResults));
                showAlert("Bilgi", "Dönüş için uygun uçuş bulunamadı. Sadece gidiş uçuşları gösteriliyor.");
            } else {
                // Her iki yönün uçuşlarını birleştir
                List<Flight> allResults = new ArrayList<>();
                allResults.addAll(outboundResults);
                allResults.addAll(returnResults);
                flightTable.setItems(FXCollections.observableArrayList(allResults));
                showAlert("Bilgi", String.format("Gidiş: %d uçuş, Dönüş: %d uçuş bulundu.",
                        outboundResults.size(), returnResults.size()));
            }
        } else {
            // Tek yön - sadece gidiş uçuşlarını göster
            flightTable.setItems(FXCollections.observableArrayList(outboundResults));
            if (outboundResults.isEmpty()) {
                showAlert("Bilgi", "Arama kriterlerine uygun uçuş bulunamadı.");
            }
        }
    }

    private void showAllFlights() {
        List<Flight> flights = searchEngine.getAvailableFlights();
        flightTable.setItems(FXCollections.observableArrayList(flights));
    }

    private void makeReservation() {
        Flight selectedFlight = flightTable.getSelectionModel().getSelectedItem();
        if (selectedFlight == null) {
            showAlert("Uyarı", "Lütfen bir uçuş seçin!");
            return;
        }

        if (selectedFlight.getAvailableSeatCount() == 0) {
            showAlert("Hata", "Bu uçuşta boş koltuk bulunmamaktadır!");
            return;
        }

        // Koltuk seçim dialogu
        showSeatSelectionDialog(selectedFlight);
    }

    private void showSeatSelectionDialog(Flight flight) {
        Dialog<Seat> dialog = new Dialog<>();
        dialog.setTitle("Koltuk Seçimi");
        dialog.setHeaderText(flight.getFlightSummary());

        ButtonType reserveButtonType = new ButtonType("Rezerve Et", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(reserveButtonType, ButtonType.CANCEL);

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        // Sınıf seçimi
        Label classLabel = new Label("Sınıf Seçin:");
        ComboBox<SeatClass> classCombo = new ComboBox<>();
        classCombo.setItems(FXCollections.observableArrayList(SeatClass.values()));
        classCombo.setValue(SeatClass.ECONOMY);

        // Koltuk listesi
        Label seatLabel = new Label("Koltuk Seçin:");
        ListView<Seat> seatList = new ListView<>();
        seatList.setPrefHeight(200);

        // Fiyat gösterimi
        Label priceLabel = new Label("Fiyat: -");
        priceLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));

        // Sınıf değiştiğinde koltukları güncelle
        classCombo.setOnAction(e -> {
            SeatClass selected = classCombo.getValue();
            List<Seat> seats = flight.getPlane().getAvailableSeatsByClass(selected);
            seatList.setItems(FXCollections.observableArrayList(seats));
        });

        // Koltuk seçildiğinde fiyatı göster
        seatList.getSelectionModel().selectedItemProperty().addListener((obs, oldVal, newVal) -> {
            if (newVal != null) {
                double price = priceCalculator.calculatePrice(newVal, flight);
                priceLabel.setText(String.format("Fiyat: %.2f TL", price));
            }
        });

        // Başlangıçta economy koltukları göster
        List<Seat> economySeats = flight.getPlane().getAvailableSeatsByClass(SeatClass.ECONOMY);
        seatList.setItems(FXCollections.observableArrayList(economySeats));

        content.getChildren().addAll(classLabel, classCombo, seatLabel, seatList, priceLabel);
        dialog.getDialogPane().setContent(content);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == reserveButtonType) {
                return seatList.getSelectionModel().getSelectedItem();
            }
            return null;
        });

        dialog.showAndWait().ifPresent(seat -> {
            if (seat != null) {
                // Koltuk seçildikten sonra ek hizmetler ekranını göster
                showAdditionalServicesDialog(flight, seat);
            }
        });
    }

    /**
     * Ek hizmetler seçim ekranını gösterir.
     */
    private void showAdditionalServicesDialog(Flight flight, Seat seat) {
        Dialog<Set<AdditionalService>> dialog = new Dialog<>();
        dialog.setTitle("Ek Hizmetler");
        dialog.setHeaderText("UÇUŞUNA EK HİZMET EKLE");

        ButtonType continueButtonType = new ButtonType("Devam Et", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(continueButtonType, ButtonType.CANCEL);

        VBox content = new VBox(20);
        content.setPadding(new Insets(20));
        content.setAlignment(Pos.CENTER);
        content.setStyle("-fx-background-color: #f5f5f5;");

        // Hizmet kartları için grid
        HBox cardsContainer = new HBox(15);
        cardsContainer.setAlignment(Pos.CENTER);

        // Seçilen hizmetleri tutacak set
        Set<AdditionalService> selectedServices = new HashSet<>();

        // Baz fiyat
        double basePrice = priceCalculator.calculatePrice(seat, flight);

        // Toplam fiyat label
        Label totalLabel = new Label(String.format("Toplam: %.2f TL", basePrice));
        totalLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));
        totalLabel.setTextFill(Color.web("#333333"));

        // Her hizmet için kart oluştur
        AdditionalService[] services = AdditionalService.values();
        int serviceIndex = 0;
        while (serviceIndex < services.length) {
            AdditionalService service = services[serviceIndex];
            VBox card = createServiceCard(service, selectedServices, basePrice, totalLabel);
            cardsContainer.getChildren().add(card);
            serviceIndex++;
        }

        // Fiyat bilgisi
        VBox priceSection = new VBox(5);
        priceSection.setAlignment(Pos.CENTER);
        priceSection.setPadding(new Insets(15, 0, 0, 0));

        Label basePriceLabel = new Label(String.format("Bilet Fiyatı: %.2f TL", basePrice));
        basePriceLabel.setFont(Font.font("Arial", 14));
        basePriceLabel.setTextFill(Color.web("#666666"));

        priceSection.getChildren().addAll(basePriceLabel, totalLabel);

        content.getChildren().addAll(cardsContainer, priceSection);
        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().setPrefWidth(700);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == continueButtonType) {
                return selectedServices;
            }
            return null;
        });

        dialog.showAndWait().ifPresent(services2 -> {
            // Rezervasyonu tamamla
            completeReservation(flight, seat, services2);
        });
    }

    /**
     * Hizmet kartı oluşturur.
     */
    private VBox createServiceCard(AdditionalService service, Set<AdditionalService> selectedServices,
            double basePrice, Label totalLabel) {
        VBox card = new VBox(10);
        card.setAlignment(Pos.CENTER);
        card.setPadding(new Insets(15));
        card.setPrefWidth(140);
        card.setPrefHeight(140);
        card.setStyle(
                "-fx-background-color: white; " +
                        "-fx-background-radius: 12; " +
                        "-fx-border-color: #e0e0e0; " +
                        "-fx-border-radius: 12; " +
                        "-fx-cursor: hand;");

        // İkon
        Label iconLabel = new Label(service.getIcon());
        iconLabel.setFont(Font.font(32));
        iconLabel.setTextFill(Color.web("#ffc107"));

        // İsim
        Label nameLabel = new Label(service.getDisplayName());
        nameLabel.setFont(Font.font("Arial", FontWeight.BOLD, 11));
        nameLabel.setTextFill(Color.web("#333333"));
        nameLabel.setWrapText(true);
        nameLabel.setAlignment(Pos.CENTER);

        // Fiyat
        Label priceLabel = new Label(String.format("+%.0f TL", service.getPrice()));
        priceLabel.setFont(Font.font("Arial", 12));
        priceLabel.setTextFill(Color.web("#666666"));

        // Seçim checkbox
        CheckBox checkBox = new CheckBox();
        checkBox.setStyle("-fx-cursor: hand;");

        checkBox.setOnAction(e -> {
            if (checkBox.isSelected()) {
                selectedServices.add(service);
                card.setStyle(
                        "-fx-background-color: #fff8e1; " +
                                "-fx-background-radius: 12; " +
                                "-fx-border-color: #ffc107; " +
                                "-fx-border-width: 2; " +
                                "-fx-border-radius: 12; " +
                                "-fx-cursor: hand;");
            } else {
                selectedServices.remove(service);
                card.setStyle(
                        "-fx-background-color: white; " +
                                "-fx-background-radius: 12; " +
                                "-fx-border-color: #e0e0e0; " +
                                "-fx-border-radius: 12; " +
                                "-fx-cursor: hand;");
            }
            // Toplam fiyatı güncelle
            double total = basePrice + priceCalculator.calculateServicesTotal(selectedServices);
            totalLabel.setText(String.format("Toplam: %.2f TL", total));
        });

        // Karta tıklandığında checkbox'ı toggle et
        card.setOnMouseClicked(e -> {
            checkBox.setSelected(!checkBox.isSelected());
            checkBox.getOnAction().handle(null);
        });

        card.getChildren().addAll(iconLabel, nameLabel, priceLabel, checkBox);
        return card;
    }

    /**
     * Rezervasyonu tamamlar.
     */
    private void completeReservation(Flight flight, Seat seat, Set<AdditionalService> services) {
        try {
            Passenger passenger = customer.getPassenger();
            if (passenger == null) {
                passenger = new Passenger(customer.getUsername(), "",
                        customer.getEmail(), "");
                customer.setPassenger(passenger);
            }

            Reservation reservation = MainApp.getReservationManager()
                    .makeReservation(flight, passenger, seat);
            customer.addReservation(reservation);

            double price = priceCalculator.calculatePriceWithServices(seat, flight, services);
            MainApp.getReservationManager().createTicket(reservation, price);

            // Seçilen hizmetleri bildir
            StringBuilder message = new StringBuilder();
            message.append("Rezervasyon tamamlandı!\n");
            message.append("Rezervasyon Kodu: ").append(reservation.getReservationCode()).append("\n");
            message.append(String.format("Toplam Fiyat: %.2f TL", price));

            if (services != null && !services.isEmpty()) {
                message.append("\n\nSeçilen Ek Hizmetler:");
                java.util.Iterator<AdditionalService> iterator = services.iterator();
                while (iterator.hasNext()) {
                    AdditionalService service = iterator.next();
                    message.append("\n• ").append(service.getFullLabel());
                }
            }

            showAlert("Başarılı", message.toString());

            // Tabloyu güncelle
            showAllFlights();

        } catch (Exception e) {
            showAlert("Hata", "Rezervasyon yapılamadı: " + e.getMessage());
        }
    }

    private VBox createReservationsPane() {
        VBox pane = new VBox(15);
        pane.setPadding(new Insets(20));

        Label titleLabel = new Label("Rezervasyonlarım");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 18));

        reservationTable = createReservationTable();

        // Yenile butonu
        Button refreshButton = new Button("🔄 Yenile");
        applyOutlineStyle(refreshButton, "#FF9800");
        refreshButton.setOnAction(e -> loadReservations());

        // İptal butonu
        Button cancelButton = new Button("❌ Seçili Rezervasyonu İptal Et");
        applyOutlineStyle(cancelButton, "#c62828");
        cancelButton.setOnAction(e -> cancelReservation());

        HBox buttonBox = new HBox(15, refreshButton, cancelButton);
        buttonBox.setAlignment(Pos.CENTER);

        pane.getChildren().addAll(titleLabel, reservationTable, buttonBox);
        VBox.setVgrow(reservationTable, Priority.ALWAYS);

        loadReservations();

        return pane;
    }

    @SuppressWarnings("unchecked")
    private TableView<Reservation> createReservationTable() {
        TableView<Reservation> table = new TableView<>();
        table.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY_FLEX_LAST_COLUMN);

        TableColumn<Reservation, String> codeCol = new TableColumn<>("Rezervasyon Kodu");
        codeCol.setCellValueFactory(new PropertyValueFactory<>("reservationCode"));
        codeCol.setMinWidth(110);

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

        TableColumn<Reservation, String> dateCol = new TableColumn<>("Tarih");
        dateCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getFlight().getDate().toString()));
        dateCol.setMinWidth(85);

        TableColumn<Reservation, String> seatCol = new TableColumn<>("Koltuk");
        seatCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getSeat().getSeatNum()));
        seatCol.setMinWidth(60);

        TableColumn<Reservation, String> statusCol = new TableColumn<>("Durum");
        statusCol.setCellValueFactory(cellData -> new javafx.beans.property.SimpleStringProperty(
                cellData.getValue().getStatus().getDescription()));
        statusCol.setMinWidth(80);

        table.getColumns().addAll(codeCol, flightCol, routeCol, dateCol, seatCol, statusCol);
        table.setPlaceholder(new Label("Henüz rezervasyonunuz bulunmamaktadır"));

        return table;
    }

    private void loadReservations() {
        List<Reservation> reservations;
        if (customer.getPassenger() != null) {
            reservations = MainApp.getReservationManager()
                    .getReservationsByPassenger(customer.getPassenger().getPassengerId());
        } else {
            reservations = customer.getReservationHistory();
        }
        // Sadece aktif rezervasyonları göster (iptal edilmişleri filtrele)
        List<Reservation> activeReservations = reservations.stream()
                .filter(Reservation::isActive)
                .collect(java.util.stream.Collectors.toList());
        reservationTable.setItems(FXCollections.observableArrayList(activeReservations));
    }

    private void cancelReservation() {
        Reservation selected = reservationTable.getSelectionModel().getSelectedItem();
        if (selected == null) {
            showAlert("Uyarı", "Lütfen iptal etmek istediğiniz rezervasyonu seçin!");
            return;
        }

        if (!selected.isActive()) {
            showAlert("Bilgi", "Bu rezervasyon zaten iptal edilmiş veya tamamlanmış.");
            return;
        }

        Alert confirm = new Alert(Alert.AlertType.CONFIRMATION);
        confirm.setTitle("Onay");
        confirm.setHeaderText("Rezervasyon İptali");
        confirm.setContentText("Bu rezervasyonu iptal etmek istediğinizden emin misiniz?\n" +
                "Rezervasyon Kodu: " + selected.getReservationCode());

        confirm.showAndWait().ifPresent(response -> {
            if (response == ButtonType.OK) {
                boolean cancelled = MainApp.getReservationManager()
                        .cancelReservation(selected.getReservationCode());
                if (cancelled) {
                    showAlert("Başarılı", "Rezervasyon iptal edildi.");
                    loadReservations();
                    showAllFlights();
                } else {
                    showAlert("Hata", "Rezervasyon iptal edilemedi.");
                }
            }
        });
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
