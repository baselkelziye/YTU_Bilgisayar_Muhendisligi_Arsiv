package com.airline;

import com.airline.gui.LoginScreen;
import com.airline.manager.FlightManager;
import com.airline.manager.ReservationManager;
import com.airline.manager.UserManager;

import javafx.application.Application;
import javafx.stage.Stage;

/**
 * Havayolu Rezervasyon Sistemi ana uygulama sınıfı.
 * JavaFX Application'dan türetilir ve uygulamayı başlatır.
 */
public class MainApp extends Application {

    // Singleton manager instances
    private static FlightManager flightManager;
    private static ReservationManager reservationManager;
    private static UserManager userManager;

    @Override
    public void start(Stage primaryStage) {
        // Manager'ları başlat
        initializeManagers();

        // Login ekranını göster
        LoginScreen loginScreen = new LoginScreen(primaryStage);
        loginScreen.show();
    }

    /**
     * Tüm manager sınıflarını başlatır.
     */
    private void initializeManagers() {
        flightManager = new FlightManager();
        reservationManager = new ReservationManager();
        userManager = new UserManager();

        // Eğer hiç uçuş yoksa örnek veriler oluştur
        if (flightManager.getAllFlights().isEmpty()) {
            flightManager.createSampleData();
        }

        // Rezervasyonları uçuşlarla senkronize et
        syncReservationsWithFlights();
    }

    /**
     * Rezervasyonlardaki koltuk durumlarını uçuşlarla senkronize eder.
     * Bu, uygulama yeniden başlatıldığında doluluk oranlarının doğru gösterilmesi için gereklidir.
     */
    private void syncReservationsWithFlights() {
        // Önce tüm uçuşlardaki koltukları sıfırla
        java.util.Iterator<com.airline.model.Flight> flightIterator = flightManager.getAllFlights().iterator();
        while (flightIterator.hasNext()) {
            com.airline.model.Flight flight = flightIterator.next();
            if (flight.getPlane() != null) {
                flight.getPlane().resetAllSeats();
            }
        }

        // sadece aktif rezervasyonlardaki koltukları rezerve et
        java.util.Iterator<com.airline.model.Reservation> reservationIterator = reservationManager.getAllReservations().iterator();
        while (reservationIterator.hasNext()) {
            com.airline.model.Reservation reservation = reservationIterator.next();
            System.out.println("DEBUG: Rezervasyon " + reservation.getReservationCode() +
                " - Status: " + reservation.getStatus() +
                " - isActive: " + reservation.isActive() +
                " - Flight: " + (reservation.getFlight() != null ? reservation.getFlight().getFlightNum() : "null"));

            if (reservation.isActive() && reservation.getFlight() != null && reservation.getSeat() != null) {
                // Uçuşu FlightManager'dan bul
                String flightNum = reservation.getFlight().getFlightNum();
                com.airline.model.Flight flight = flightManager.getFlightByNumber(flightNum);

                System.out.println("DEBUG: Aranan uçuş: " + flightNum + " - Bulunan: " + (flight != null ? flight.getFlightNum() : "null"));

                if (flight != null && flight.getPlane() != null) {
                    // Koltuğu uçağın içinden bul ve rezerve et
                    String seatNum = reservation.getSeat().getSeatNum();
                    com.airline.model.Seat seat = flight.getPlane().getSeat(seatNum);
                    if (seat != null) {
                        seat.reserve();
                        System.out.println("DEBUG: Koltuk rezerve edildi: " + seatNum + " uçuş: " + flightNum);
                    }
                }
            }
        }
        // Güncellenmiş uçuşları kaydet
        flightManager.saveToFile();
    }

    /**
     * FlightManager singleton instance'ını döndürür.
     */
    public static FlightManager getFlightManager() {
        if (flightManager == null) {
            flightManager = new FlightManager();
        }
        return flightManager;
    }

    /**
     * ReservationManager singleton instance'ını döndürür.
     */
    public static ReservationManager getReservationManager() {
        if (reservationManager == null) {
            reservationManager = new ReservationManager();
        }
        return reservationManager;
    }

    /**
     * UserManager singleton instance'ını döndürür.
     */
    public static UserManager getUserManager() {
        if (userManager == null) {
            userManager = new UserManager();
        }
        return userManager;
    }

    /**
     * Uygulamayı başlatır.
     */
    public static void main(String[] args) {
        launch(args);
    }
}
