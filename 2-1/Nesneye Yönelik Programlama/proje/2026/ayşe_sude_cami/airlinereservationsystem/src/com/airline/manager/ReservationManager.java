package com.airline.manager;

import com.airline.model.*;
import com.airline.model.enums.ReservationStatus;
import com.airline.util.FileManager;
import com.airline.exception.SeatNotAvailableException;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.ReentrantLock;
import java.util.stream.Collectors;

/**
 * Rezervasyon yönetimi işlemlerini gerçekleştirir.
 * Multithreading (eşzamanlılık) kontrolü içerir.
 * ReentrantLock kullanarak thread-safe rezervasyon yapar.
 */
public class ReservationManager {

    private static final String RESERVATIONS_FILE = "reservations.dat";
    private static final String TICKETS_FILE = "tickets.dat";

    private List<Reservation> reservations;
    private List<Ticket> tickets;
    private final ReentrantLock lock;

    /**
     * ReservationManager oluşturur.
     */
    public ReservationManager() {
        this.reservations = new ArrayList<>();
        this.tickets = new ArrayList<>();
        this.lock = new ReentrantLock();
        loadFromFile();
    }

    /**
     * Yeni rezervasyon yapar (thread-safe).
     * @param flight Uçuş
     * @param passenger Yolcu
     * @param seat Koltuk
     * @return Oluşturulan rezervasyon
     */
    public Reservation makeReservation(Flight flight, Passenger passenger, Seat seat) {
        lock.lock();
        try {
            // Koltuk zaten rezerve mi kontrol et
            if (seat.isReserveStatus()) {
                throw new SeatNotAvailableException(seat.getSeatNum(), "Koltuk zaten rezerve edilmiş");
            }

            // Rezervasyon oluştur
            Reservation reservation = new Reservation(flight, passenger, seat);
            reservation.confirm(); // Koltuğu da rezerve eder
            reservations.add(reservation);

            saveToFile();
            return reservation;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Synchronized koltuk rezervasyonu (Senaryo 1 için).
     * @param seat Rezerve edilecek koltuk
     * @return Başarılı ise true
     */
    public boolean synchronizedReserve(Seat seat) {
        lock.lock();
        try {
            if (seat.isReserveStatus()) {
                return false;
            }
            seat.reserve();
            return true;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Synchronized olmadan koltuk rezervasyonu (race condition gösterimi için).
     * @param seat Rezerve edilecek koltuk
     * @return Başarılı ise true
     */
    public boolean unsynchronizedReserve(Seat seat) {
        // Bu metod synchronized DEĞİL - race condition olabilir
        // Önce durumu kontrol et
        boolean wasAvailable = !seat.isReserveStatus();

        // Yapay gecikme ekle - race condition'ı daha görünür yapmak için
        try {
            Thread.sleep(2);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        // Gecikme sonrası tekrar kontrol et - bu arada başkası almış olabilir
        if (seat.isReserveStatus()) {
            // Koltuk zaten alınmış - çakışma!
            return false;
        }

        // Koltuğu rezerve et (ama başka thread de aynı anda yapıyor olabilir)
        seat.setReserveStatus(true);
        return wasAvailable;
    }

    /**
     * Rezervasyonu iptal eder.
     * @param reservationCode Rezervasyon kodu
     * @return İptal başarılı ise true
     */
    public boolean cancelReservation(String reservationCode) {
        lock.lock();
        try {
            Reservation reservation = getReservation(reservationCode);
            if (reservation != null && reservation.isActive()) {
                reservation.cancel();
                saveToFile();
                return true;
            }
            return false;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Rezervasyon koduna göre rezervasyon arar.
     * @param reservationCode Rezervasyon kodu
     * @return Bulunan rezervasyon veya null
     */
    public Reservation getReservation(String reservationCode) {
        java.util.Iterator<Reservation> iterator = reservations.iterator();
        while (iterator.hasNext()) {
            Reservation r = iterator.next();
            if (r.getReservationCode().equalsIgnoreCase(reservationCode)) {
                return r;
            }
        }
        return null;
    }

    /**
     * Yolcu ID'sine göre rezervasyonları döndürür.
     * @param passengerId Yolcu ID
     * @return Rezervasyon listesi
     */
    public List<Reservation> getReservationsByPassenger(String passengerId) {
        return reservations.stream()
                .filter(r -> r.getPassenger().getPassengerId().equals(passengerId))
                .collect(Collectors.toList());
    }

    /**
     * Uçuşa göre rezervasyonları döndürür.
     * @param flightNum Uçuş numarası
     * @return Rezervasyon listesi
     */
    public List<Reservation> getReservationsByFlight(String flightNum) {
        return reservations.stream()
                .filter(r -> r.getFlight().getFlightNum().equals(flightNum))
                .collect(Collectors.toList());
    }

    /**
     * Tüm rezervasyonları döndürür.
     */
    public List<Reservation> getAllReservations() {
        return new ArrayList<>(reservations);
    }

    /**
     * Aktif rezervasyonları döndürür.
     */
    public List<Reservation> getActiveReservations() {
        return reservations.stream()
                .filter(Reservation::isActive)
                .collect(Collectors.toList());
    }

    /**
     * Duruma göre rezervasyonları filtreler.
     */
    public List<Reservation> getReservationsByStatus(ReservationStatus status) {
        return reservations.stream()
                .filter(r -> r.getStatus() == status)
                .collect(Collectors.toList());
    }

    /**
     * Rezervasyon için bilet oluşturur.
     * @param reservation Rezervasyon
     * @param price Fiyat
     * @return Oluşturulan bilet
     */
    public Ticket createTicket(Reservation reservation, double price) {
        lock.lock();
        try {
            Ticket ticket = new Ticket(reservation, price);
            tickets.add(ticket);
            saveToFile();
            return ticket;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Bilet ID'sine göre bilet arar.
     */
    public Ticket getTicketById(String ticketId) {
        java.util.Iterator<Ticket> iterator = tickets.iterator();
        while (iterator.hasNext()) {
            Ticket t = iterator.next();
            if (t.getTicketId().equals(ticketId)) {
                return t;
            }
        }
        return null;
    }

    /**
     * Tüm biletleri döndürür.
     */
    public List<Ticket> getAllTickets() {
        return new ArrayList<>(tickets);
    }

    /**
     * Verileri dosyaya kaydeder.
     */
    public void saveToFile() {
        FileManager.saveList(reservations, RESERVATIONS_FILE);
        FileManager.saveList(tickets, TICKETS_FILE);
    }

    /**
     * Verileri dosyadan yükler.
     */
    public void loadFromFile() {
        List<Reservation> loadedReservations = FileManager.loadList(RESERVATIONS_FILE);
        List<Ticket> loadedTickets = FileManager.loadList(TICKETS_FILE);

        if (loadedReservations != null && !loadedReservations.isEmpty()) {
            this.reservations = loadedReservations;
        }
        if (loadedTickets != null && !loadedTickets.isEmpty()) {
            this.tickets = loadedTickets;
        }
    }

    /**
     * Rezervasyon sayısını döndürür.
     */
    public int getReservationCount() {
        return reservations.size();
    }

    /**
     * Aktif rezervasyon sayısını döndürür.
     */
    public int getActiveReservationCount() {
        return (int) reservations.stream().filter(Reservation::isActive).count();
    }

    /**
     * Tüm verileri temizler.
     */
    public void clearAllData() {
        lock.lock();
        try {
            reservations.clear();
            tickets.clear();
            saveToFile();
        } finally {
            lock.unlock();
        }
    }

    /**
     * Lock nesnesini döndürür (test için).
     */
    public ReentrantLock getLock() {
        return lock;
    }
}
