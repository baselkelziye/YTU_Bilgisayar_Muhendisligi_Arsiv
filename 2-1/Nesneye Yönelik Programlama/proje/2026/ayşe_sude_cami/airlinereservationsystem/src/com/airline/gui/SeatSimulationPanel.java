package com.airline.gui;

import com.airline.manager.ReservationManager;
import com.airline.model.Plane;
import com.airline.model.Seat;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Eşzamanlı Koltuk Rezervasyonu Simülasyon Paneli.
 * Senaryo 1: 90 yolcu 180 koltuğa aynı anda rezervasyon yapmaya çalışır.
 * Synchronized ve unsynchronized modları gösterir.
 */
public class SeatSimulationPanel extends VBox {

    private static final int ROWS = 30;
    private static final int SEATS_PER_ROW = 6;
    private static final int PASSENGER_COUNT = 90;

    private GridPane seatGrid;
    private Rectangle[][] seatRectangles;
    private Label statusLabel;
    private Label occupiedLabel;
    private Label emptyLabel;
    private Plane simulationPlane;
    private ReservationManager reservationManager;

    public SeatSimulationPanel() {
        setSpacing(15);
        setPadding(new Insets(10));
        setAlignment(Pos.CENTER);

        reservationManager = new ReservationManager();

        createSeatGrid();
        createStatusPanel();
    }

    private void createSeatGrid() {
        seatGrid = new GridPane();
        seatGrid.setHgap(3);
        seatGrid.setVgap(3);
        seatGrid.setAlignment(Pos.CENTER);
        seatGrid.setStyle("-fx-background-color: #37474f; -fx-padding: 15; -fx-background-radius: 10;");

        seatRectangles = new Rectangle[ROWS][SEATS_PER_ROW];

        // Sütun başlıkları (A-F)
        char[] columns = {'A', 'B', 'C', ' ', 'D', 'E', 'F'};
        int c = 0;
        while (c < columns.length) {
            if (columns[c] != ' ') {
                Label label = new Label(String.valueOf(columns[c]));
                label.setFont(Font.font("Arial", FontWeight.BOLD, 10));
                label.setTextFill(Color.WHITE);
                label.setMinWidth(25);
                label.setAlignment(Pos.CENTER);
                seatGrid.add(label, c + 1, 0);
            }
            c++;
        }

        // Koltukları oluştur
        int row = 0;
        while (row < ROWS) {
            // Sıra numarası
            Label rowLabel = new Label(String.valueOf(row + 1));
            rowLabel.setFont(Font.font("Arial", 9));
            rowLabel.setTextFill(Color.WHITE);
            rowLabel.setMinWidth(20);
            seatGrid.add(rowLabel, 0, row + 1);

            int colIndex = 0;
            int col = 0;
            while (col < 7) {
                if (col == 3) {
                    // Koridor
                    Region corridor = new Region();
                    corridor.setMinWidth(15);
                    seatGrid.add(corridor, col + 1, row + 1);
                } else {
                    int actualCol = colIndex;
                    Rectangle rect = new Rectangle(22, 22);
                    rect.setFill(Color.LIGHTGREEN); // Boş = yeşil
                    rect.setStroke(Color.DARKGREEN);
                    rect.setStrokeWidth(1);
                    rect.setArcWidth(5);
                    rect.setArcHeight(5);

                    // İlk 5 sıra business (farklı renk)
                    if (row < 5) {
                        rect.setFill(Color.LIGHTBLUE);
                        rect.setStroke(Color.DARKBLUE);
                    }

                    seatRectangles[row][actualCol] = rect;
                    seatGrid.add(rect, col + 1, row + 1);
                    colIndex++;
                }
                col++;
            }
            row++;
        }

        // Lejant
        HBox legend = new HBox(20);
        legend.setAlignment(Pos.CENTER);
        legend.setPadding(new Insets(10, 0, 0, 0));

        legend.getChildren().addAll(
                createLegendItem(Color.LIGHTGREEN, "Boş (Economy)"),
                createLegendItem(Color.LIGHTBLUE, "Boş (Business)"),
                createLegendItem(Color.ORANGERED, "Dolu"),
                createLegendItem(Color.DARKRED, "Çakışma (Race Condition)")
        );

        VBox gridContainer = new VBox(10);
        gridContainer.setAlignment(Pos.CENTER);
        gridContainer.getChildren().addAll(seatGrid, legend);

        // ScrollPane ile kaydırılabilir yap
        ScrollPane scrollPane = new ScrollPane(gridContainer);
        scrollPane.setFitToWidth(true);
        scrollPane.setStyle("-fx-background: transparent; -fx-background-color: transparent;");
        scrollPane.setPrefViewportHeight(500);
        VBox.setVgrow(scrollPane, Priority.ALWAYS);

        getChildren().add(scrollPane);
    }

    private HBox createLegendItem(Color color, String text) {
        Rectangle rect = new Rectangle(15, 15);
        rect.setFill(color);
        rect.setStroke(Color.BLACK);
        rect.setArcWidth(3);
        rect.setArcHeight(3);

        Label label = new Label(text);
        label.setFont(Font.font("Arial", 11));
        label.setTextFill(Color.BLACK);
        label.setStyle("-fx-text-fill: black;");

        HBox box = new HBox(5);
        box.setAlignment(Pos.CENTER_LEFT);
        box.getChildren().addAll(rect, label);

        return box;
    }

    private void createStatusPanel() {
        HBox statusPanel = new HBox(30);
        statusPanel.setAlignment(Pos.CENTER);
        statusPanel.setPadding(new Insets(10));
        statusPanel.setStyle("-fx-background-color: #eceff1; -fx-background-radius: 10;");

        statusLabel = new Label("Hazır");
        statusLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));

        occupiedLabel = new Label("Dolu: 0");
        occupiedLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
        occupiedLabel.setTextFill(Color.ORANGERED);

        emptyLabel = new Label("Boş: 180");
        emptyLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
        emptyLabel.setTextFill(Color.GREEN);

        statusPanel.getChildren().addAll(statusLabel, occupiedLabel, emptyLabel);
        getChildren().add(statusPanel);
    }

    public void runSimulation(boolean synchronized_) {
        // Önce tüm koltukları sıfırla
        resetSeats();

        // Yeni uçak oluştur
        simulationPlane = new Plane("SIM-001", "Simulation Plane", ROWS, SEATS_PER_ROW, 5, 500);

        statusLabel.setText("Simülasyon çalışıyor...");

        // Thread'leri başlat
        Thread simulationThread = new Thread(() -> {
            AtomicInteger successCount = new AtomicInteger(0);
            AtomicInteger failCount = new AtomicInteger(0);
            AtomicInteger conflictCount = new AtomicInteger(0);

            List<Thread> passengerThreads = new ArrayList<>();
            CountDownLatch startLatch = new CountDownLatch(1);
            CountDownLatch endLatch = new CountDownLatch(PASSENGER_COUNT);

            Random random = new Random();

            // 90 yolcu thread'i oluştur
            int i = 0;
            while (i < PASSENGER_COUNT) {
                final int passengerId = i;

                Thread passengerThread = new Thread(() -> {
                    try {
                        // Tüm thread'lerin aynı anda başlamasını bekle
                        startLatch.await();

                        // Rastgele bir boş koltuk seç
                        List<Seat> availableSeats = simulationPlane.getAvailableSeats();
                        if (availableSeats.isEmpty()) {
                            endLatch.countDown();
                            return;
                        }

                        Seat selectedSeat = availableSeats.get(random.nextInt(availableSeats.size()));
                        int row = selectedSeat.getRow() - 1;
                        int col = getColumnIndex(selectedSeat.getColumn());

                        boolean reserved;
                        if (synchronized_) {
                            // Thread-safe rezervasyon
                            reserved = reservationManager.synchronizedReserve(selectedSeat);
                        } else {
                            // Thread-safe OLMAYAN rezervasyon (race condition olabilir)
                            reserved = reservationManager.unsynchronizedReserve(selectedSeat);
                        }

                        // GUI'yi güncelle
                        final boolean wasReserved = reserved;

                        Platform.runLater(() -> {
                            if (row >= 0 && row < ROWS && col >= 0 && col < SEATS_PER_ROW) {
                                if (wasReserved) {
                                    // Başarılı rezervasyon - turuncu
                                    seatRectangles[row][col].setFill(Color.ORANGERED);
                                    successCount.incrementAndGet();
                                } else if (!synchronized_) {
                                    // Unsynchronized modda başarısız = çakışma (race condition)
                                    // Koltuk zaten dolu olarak işaretlenmiş ama biz de seçmiştik
                                    seatRectangles[row][col].setFill(Color.DARKRED);
                                    conflictCount.incrementAndGet();
                                }
                                updateStatus(successCount.get(), conflictCount.get());
                            }
                        });

                    } catch (Exception e) {
                        failCount.incrementAndGet();
                    } finally {
                        endLatch.countDown();
                    }
                });

                passengerThread.setName("Passenger-" + passengerId);
                passengerThreads.add(passengerThread);
                i++;
            }

            // Tüm thread'leri başlat
            java.util.Iterator<Thread> threadIterator = passengerThreads.iterator();
            while (threadIterator.hasNext()) {
                Thread t = threadIterator.next();
                t.start();
            }

            // Hepsini aynı anda serbest bırak
            startLatch.countDown();

            // Tamamlanmasını bekle
            try {
                endLatch.await();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            // Sonuçları göster
            int occupied = simulationPlane.getReservedSeatCount();

            Platform.runLater(() -> {
                if (synchronized_) {
                    statusLabel.setText("Tamamlandı (Synchronized) - Doğru sonuç!");
                    statusLabel.setTextFill(Color.GREEN);
                } else {
                    if (occupied != PASSENGER_COUNT) {
                        statusLabel.setText("Tamamlandı (Unsynchronized) - HATALI! Race condition tespit edildi!");
                        statusLabel.setTextFill(Color.RED);
                    } else {
                        statusLabel.setText("Tamamlandı (Unsynchronized) - Şanslı, hata yok");
                        statusLabel.setTextFill(Color.ORANGE);
                    }
                }
                updateStatus(occupied, conflictCount.get());
            });
        });

        simulationThread.setDaemon(true);
        simulationThread.start();
    }

    private int getColumnIndex(char column) {
        switch (column) {
            case 'A': return 0;
            case 'B': return 1;
            case 'C': return 2;
            case 'D': return 3;
            case 'E': return 4;
            case 'F': return 5;
            default: return -1;
        }
    }

    private void resetSeats() {
        statusLabel.setText("Hazır");
        statusLabel.setTextFill(Color.BLACK);

        int row = 0;
        while (row < ROWS) {
            int col = 0;
            while (col < SEATS_PER_ROW) {
                if (row < 5) {
                    seatRectangles[row][col].setFill(Color.LIGHTBLUE);
                } else {
                    seatRectangles[row][col].setFill(Color.LIGHTGREEN);
                }
                col++;
            }
            row++;
        }
        updateStatus(0, 0);
    }

    private void updateStatus(int occupied, int conflicts) {
        int empty = (ROWS * SEATS_PER_ROW) - occupied;
        occupiedLabel.setText("Dolu: " + occupied + (conflicts > 0 ? " (Çakışma: " + conflicts + ")" : ""));
        emptyLabel.setText("Boş: " + empty);
    }
}
