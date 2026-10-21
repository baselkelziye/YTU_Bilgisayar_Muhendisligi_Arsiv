package com.airline;

import com.airline.manager.FlightManager;
import com.airline.manager.ReservationManager;
import com.airline.manager.UserManager;
import com.airline.model.*;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.List;
import java.util.Scanner;

/**
 * Terminal tabanlı kullanıcı arayüzü.
 * JavaFX olmadan çalışabilir.
 */
public class CliApp {
    private static FlightManager flightManager;
    private static ReservationManager reservationManager;
    private static UserManager userManager;
    private static Scanner scanner;
    private static User currentUser;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        initializeManagers();

        System.out.println("╔════════════════════════════════════════════════════════════╗");
        System.out.println("║     HAVAYOLU REZERVASYON SİSTEMİ - Terminal Modu           ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝");
        System.out.println();

        // Giriş veya Kayıt Ekranı
        if (!authenticationScreen()) {
            System.out.println("Giriş başarısız. Program sonlandırılıyor.");
            return;
        }

        // Ana menü
        mainMenu();

        scanner.close();
        System.out.println("\nProgram sonlandırıldı. İyi günler!");
    }

    private static void initializeManagers() {
        flightManager = new FlightManager();
        reservationManager = new ReservationManager();
        userManager = new UserManager();

        if (flightManager.getAllFlights().isEmpty()) {
            flightManager.createSampleData();
        }
        syncReservationsWithFlights();
    }

    private static void syncReservationsWithFlights() {
        java.util.Iterator<Flight> flightIterator = flightManager.getAllFlights().iterator();
        while (flightIterator.hasNext()) {
            Flight flight = flightIterator.next();
            if (flight.getPlane() != null) {
                flight.getPlane().resetAllSeats();
            }
        }

        java.util.Iterator<Reservation> reservationIterator = reservationManager.getAllReservations().iterator();
        while (reservationIterator.hasNext()) {
            Reservation reservation = reservationIterator.next();
            if (reservation.isActive() && reservation.getFlight() != null && reservation.getSeat() != null) {
                String flightNum = reservation.getFlight().getFlightNum();
                Flight flight = flightManager.getFlightByNumber(flightNum);
                if (flight != null && flight.getPlane() != null) {
                    String seatNum = reservation.getSeat().getSeatNum();
                    Seat seat = flight.getPlane().getSeat(seatNum);
                    if (seat != null) {
                        seat.reserve();
                    }
                }
            }
        }
        flightManager.saveToFile();
    }

    private static boolean login() {
        System.out.println("═══════════════ GİRİŞ ═══════════════");
        System.out.print("Kullanıcı adı: ");
        String username = scanner.nextLine().trim();
        System.out.print("Şifre: ");
        String password = scanner.nextLine().trim();

        currentUser = userManager.login(username, password);
        if (currentUser != null) {
            System.out.println("\n✓ Hoş geldiniz, " + currentUser.getUsername() + "!");
            return true;
        } else {
            System.out.println("\n✗ Kullanıcı adı veya şifre hatalı!");
            return false;
        }
    }

    private static boolean authenticationScreen() {
        while (true) {
            System.out.println("╔════════════════════════════════════════════════════════════╗");
            System.out.println("║           KİMLİK DOĞRULAMA EKRANI                         ║");
            System.out.println("╚════════════════════════════════════════════════════════════╝");
            System.out.println("1. Giriş Yap");
            System.out.println("2. Yeni Hesap Oluştur");
            System.out.println("0. Çıkış");
            System.out.print("\nSeçiminiz: ");

            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1" -> {
                    if (login()) {
                        return true;
                    }
                }
                case "2" -> register();
                case "0" -> {
                    return false;
                }
                default -> System.out.println("✗ Geçersiz seçim!");
            }
            System.out.println();
        }
    }

    private static void register() {
        System.out.println("\n═══════════════ YENİ HESAP OLUŞTUR ═══════════════");

        System.out.print("Kullanıcı Adı: ");
        String username = scanner.nextLine().trim();

        if (username.isEmpty()) {
            System.out.println("✗ Kullanıcı adı boş olamaz!");
            return;
        }

        // Kullanıcı adı zaten var mı kontrol et
        if (userManager.getUserByUsername(username) != null) {
            System.out.println("✗ Bu kullanıcı adı zaten kullanımda!");
            return;
        }

        System.out.print("Şifre: ");
        String password = scanner.nextLine().trim();

        if (password.isEmpty()) {
            System.out.println("✗ Şifre boş olamaz!");
            return;
        }

        System.out.print("Ad: ");
        String firstName = scanner.nextLine().trim();

        System.out.print("Soyad: ");
        String lastName = scanner.nextLine().trim();

        System.out.print("E-posta: ");
        String email = scanner.nextLine().trim();

        System.out.print("Telefon: ");
        String phone = scanner.nextLine().trim();

        try {
            Customer customer = userManager.registerCustomer(username, password, email, firstName, lastName, phone);
            System.out.println("\n✓ Hesap başarıyla oluşturuldu!");
            System.out.println("✓ Şimdi giriş yapabilirsiniz.");
            System.out.println();
        } catch (IllegalArgumentException e) {
            System.out.println("✗ Kayıt başarısız: " + e.getMessage());
        }
    }

    private static void mainMenu() {
        while (true) {
            System.out.println("\n═══════════════ ANA MENÜ ═══════════════");
            System.out.println("1. Uçuş Ara");
            System.out.println("2. Tüm Uçuşları Listele");
            System.out.println("3. Rezervasyon Yap");
            System.out.println("4. Rezervasyonlarımı Görüntüle");
            System.out.println("5. Rezervasyon İptal Et");
            System.out.println("6. Uçuş Detayı Görüntüle");
            if (currentUser instanceof Admin) {
                System.out.println("7. [Admin] Tüm Kullanıcıları Listele");
                System.out.println("8. [Admin] Tüm Rezervasyonları Listele");
            }
            System.out.println("0. Çıkış");
            System.out.print("\nSeçiminiz: ");

            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1" -> searchFlights();
                case "2" -> listAllFlights();
                case "3" -> makeReservation();
                case "4" -> viewMyReservations();
                case "5" -> cancelReservation();
                case "6" -> viewFlightDetails();
                case "7" -> {
                    if (currentUser instanceof Admin)
                        listAllUsers();
                    else
                        System.out.println("Yetkisiz işlem!");
                }
                case "8" -> {
                    if (currentUser instanceof Admin)
                        listAllReservations();
                    else
                        System.out.println("Yetkisiz işlem!");
                }
                case "0" -> {
                    return;
                }
                default -> System.out.println("Geçersiz seçim!");
            }
        }
    }

    private static void searchFlights() {
        System.out.println("\n═══════════════ UÇUŞ ARA ═══════════════");
        System.out.print("Kalkış şehri (boş bırakılabilir): ");
        String departure = scanner.nextLine().trim();
        System.out.print("Varış şehri (boş bırakılabilir): ");
        String arrival = scanner.nextLine().trim();
        System.out.print("Tarih (YYYY-MM-DD, boş bırakılabilir): ");
        String dateStr = scanner.nextLine().trim();

        LocalDate date = null;
        if (!dateStr.isEmpty()) {
            try {
                date = LocalDate.parse(dateStr);
            } catch (DateTimeParseException e) {
                System.out.println("Geçersiz tarih formatı!");
                return;
            }
        }

        final LocalDate searchDate = date;
        List<Flight> results = flightManager.getAllFlights().stream()
                .filter(f -> departure.isEmpty()
                        || f.getRoute().getDepartureAirport().toLowerCase().contains(departure.toLowerCase()))
                .filter(f -> arrival.isEmpty()
                        || f.getRoute().getArrivalAirport().toLowerCase().contains(arrival.toLowerCase()))
                .filter(f -> searchDate == null || f.getDate().equals(searchDate))
                .toList();

        if (results.isEmpty()) {
            System.out.println("\nUygun uçuş bulunamadı.");
        } else {
            System.out.println("\n" + results.size() + " uçuş bulundu:\n");
            printFlightTable(results);
        }
    }

    private static void listAllFlights() {
        System.out.println("\n═══════════════ TÜM UÇUŞLAR ═══════════════");
        List<Flight> flights = flightManager.getAllFlights();
        if (flights.isEmpty()) {
            System.out.println("Kayıtlı uçuş bulunmamaktadır.");
        } else {
            printFlightTable(flights);
        }
    }

    private static void printFlightTable(List<Flight> flights) {
        System.out.println(
                "┌──────────┬────────────────────┬────────────────────┬─────────────────────┬───────────┬──────────┐");
        System.out.println(
                "│ Uçuş No  │ Kalkış             │ Varış              │ Tarih/Saat          │ Fiyat     │ Boş Kol. │");
        System.out.println(
                "├──────────┼────────────────────┼────────────────────┼─────────────────────┼───────────┼──────────┤");

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy HH:mm");
        int flightIndex = 0;
        while (flightIndex < flights.size()) {
            Flight f = flights.get(flightIndex);
            int availableSeats = f.getPlane() != null ? f.getPlane().getAvailableSeatCount() : 0;
            LocalDateTime departureDateTime = LocalDateTime.of(f.getDate(), f.getHour());
            // Fiyatı ilk müsait koltuktan al
            double price = 0;
            if (f.getPlane() != null && !f.getPlane().getAvailableSeats().isEmpty()) {
                price = f.getPlane().getAvailableSeats().get(0).getPrice();
            }
            System.out.printf("│ %-8s │ %-18s │ %-18s │ %-19s │ %9.2f │ %8d │%n",
                    f.getFlightNum(),
                    truncate(f.getRoute().getDepartureAirport(), 18),
                    truncate(f.getRoute().getArrivalAirport(), 18),
                    departureDateTime.format(formatter),
                    price,
                    availableSeats);
            flightIndex++;
        }
        System.out.println(
                "└──────────┴────────────────────┴────────────────────┴─────────────────────┴───────────┴──────────┘");
    }

    private static void makeReservation() {
        System.out.println("\n═══════════════ REZERVASYON YAP ═══════════════");
        System.out.print("Uçuş numarası: ");
        String flightNum = scanner.nextLine().trim();

        Flight flight = flightManager.getFlightByNumber(flightNum);
        if (flight == null) {
            System.out.println("Uçuş bulunamadı!");
            return;
        }

        // Müsait koltukları göster
        System.out.println("\nMüsait koltuklar:");
        List<Seat> availableSeats = flight.getPlane().getAvailableSeats();
        if (availableSeats.isEmpty()) {
            System.out.println("Bu uçuşta müsait koltuk bulunmamaktadır.");
            return;
        }

        int seatIndex = 0;
        while (seatIndex < availableSeats.size()) {
            Seat s = availableSeats.get(seatIndex);
            System.out.printf("%s (%s)  ", s.getSeatNum(), s.getClass_().getDisplayName());
            if ((seatIndex + 1) % 8 == 0)
                System.out.println();
            seatIndex++;
        }
        System.out.println();

        System.out.print("\nKoltuk numarası: ");
        String seatNum = scanner.nextLine().trim().toUpperCase();

        Seat seat = flight.getPlane().getSeat(seatNum);
        if (seat == null) {
            System.out.println("Geçersiz koltuk numarası!");
            return;
        }
        if (seat.isReserveStatus()) {
            System.out.println("Bu koltuk zaten dolu!");
            return;
        }

        // Yolcu bilgileri
        System.out.print("Yolcu adı: ");
        String passengerName = scanner.nextLine().trim();
        System.out.print("Yolcu soyadı: ");
        String passengerSurname = scanner.nextLine().trim();
        System.out.print("Email: ");
        String email = scanner.nextLine().trim();
        System.out.print("Telefon: ");
        String phone = scanner.nextLine().trim();

        Passenger passenger = new Passenger(passengerName, passengerSurname, email, phone);

        // Rezervasyon oluştur
        try {
            Reservation reservation = reservationManager.makeReservation(flight, passenger, seat);
            flightManager.saveToFile();
            System.out.println("\n✓ Rezervasyon başarıyla oluşturuldu!");
            System.out.println("  Rezervasyon Kodu: " + reservation.getReservationCode());
            System.out.println("  Uçuş: " + flight.getFlightNum());
            System.out.println("  Koltuk: " + seat.getSeatNum());
            System.out.println("  Yolcu: " + passenger.getFullName());
        } catch (Exception e) {
            System.out.println("\n✗ Rezervasyon oluşturulamadı: " + e.getMessage());
        }
    }

    private static void viewMyReservations() {
        System.out.println("\n═══════════════ REZERVASYONLARIM ═══════════════");

        List<Reservation> myReservations = reservationManager.getAllReservations().stream()
                .filter(r -> r.getPassenger() != null)
                .toList();

        if (myReservations.isEmpty()) {
            System.out.println("Henüz rezervasyonunuz bulunmamaktadır.");
            return;
        }

        printReservationTable(myReservations);
    }

    private static void printReservationTable(List<Reservation> reservations) {
        System.out.println("┌────────────┬──────────┬────────────────────┬────────────────────┬────────┬────────────┐");
        System.out.println("│ Rez. Kodu  │ Uçuş No  │ Kalkış             │ Varış              │ Koltuk │ Durum      │");
        System.out.println("├────────────┼──────────┼────────────────────┼────────────────────┼────────┼────────────┤");

        int reservationIndex = 0;
        while (reservationIndex < reservations.size()) {
            Reservation r = reservations.get(reservationIndex);
            Flight f = r.getFlight();
            System.out.printf("│ %-10s │ %-8s │ %-18s │ %-18s │ %-6s │ %-10s │%n",
                    r.getReservationCode(),
                    f != null ? f.getFlightNum() : "-",
                    f != null ? truncate(f.getRoute().getDepartureAirport(), 18) : "-",
                    f != null ? truncate(f.getRoute().getArrivalAirport(), 18) : "-",
                    r.getSeat() != null ? r.getSeat().getSeatNum() : "-",
                    r.getStatus().toString());
            reservationIndex++;
        }
        System.out.println("└────────────┴──────────┴────────────────────┴────────────────────┴────────┴────────────┘");
    }

    private static void cancelReservation() {
        System.out.println("\n═══════════════ REZERVASYON İPTAL ═══════════════");
        System.out.print("Rezervasyon kodu: ");
        String code = scanner.nextLine().trim().toUpperCase();

        Reservation reservation = reservationManager.getReservation(code);
        if (reservation == null) {
            System.out.println("Rezervasyon bulunamadı!");
            return;
        }

        System.out.print("İptal etmek istediğinizden emin misiniz? (E/H): ");
        String confirm = scanner.nextLine().trim();
        if (confirm.equalsIgnoreCase("E")) {
            boolean success = reservationManager.cancelReservation(code);
            if (success) {
                // Koltuğu serbest bırak
                if (reservation.getSeat() != null && reservation.getFlight() != null) {
                    Flight flight = flightManager.getFlightByNumber(reservation.getFlight().getFlightNum());
                    if (flight != null && flight.getPlane() != null) {
                        Seat seat = flight.getPlane().getSeat(reservation.getSeat().getSeatNum());
                        if (seat != null) {
                            seat.release();
                            flightManager.saveToFile();
                        }
                    }
                }
                System.out.println("✓ Rezervasyon başarıyla iptal edildi.");
            } else {
                System.out.println("✗ Rezervasyon iptal edilemedi!");
            }
        } else {
            System.out.println("İşlem iptal edildi.");
        }
    }

    private static void viewFlightDetails() {
        System.out.println("\n═══════════════ UÇUŞ DETAYI ═══════════════");
        System.out.print("Uçuş numarası: ");
        String flightNum = scanner.nextLine().trim();

        Flight flight = flightManager.getFlightByNumber(flightNum);
        if (flight == null) {
            System.out.println("Uçuş bulunamadı!");
            return;
        }

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy HH:mm");
        LocalDateTime departureDateTime = LocalDateTime.of(flight.getDate(), flight.getHour());
        System.out.println("\n┌─────────────────────────────────────────┐");
        System.out.println("│            UÇUŞ BİLGİLERİ               │");
        System.out.println("├─────────────────────────────────────────┤");
        System.out.printf("│ Uçuş No    : %-26s │%n", flight.getFlightNum());
        System.out.printf("│ Kalkış     : %-26s │%n", flight.getRoute().getDepartureAirport());
        System.out.printf("│ Varış      : %-26s │%n", flight.getRoute().getArrivalAirport());
        System.out.printf("│ Tarih      : %-26s │%n", departureDateTime.format(formatter));
        System.out.printf("│ Uçak       : %-26s │%n", flight.getPlane().getPlaneModel());
        System.out.printf("│ Kapasite   : %-26d │%n", flight.getPlane().getCapacity());
        System.out.printf("│ Boş Koltuk : %-26d │%n", flight.getPlane().getAvailableSeatCount());
        // Ekonomi sınıfı fiyatı
        double basePrice = flight.getPlane().getAvailableSeats().isEmpty() ? 0
                : flight.getPlane().getAllSeats().get(0).getPrice();
        System.out.printf("│ Fiyat      : %-26.2f │%n", basePrice);
        System.out.printf("│ Durum      : %-26s │%n", flight.getStatus());
        System.out.println("└─────────────────────────────────────────┘");

    }

    private static void listAllUsers() {
        System.out.println("\n═══════════════ TÜM KULLANICILAR ═══════════════");
        List<User> users = userManager.getAllUsers();

        System.out.println("┌────────────────────┬────────────────────┬────────────────┐");
        System.out.println("│ Kullanıcı Adı      │ Email              │ Rol            │");
        System.out.println("├────────────────────┼────────────────────┼────────────────┤");

        int userIndex = 0;
        while (userIndex < users.size()) {
            User u = users.get(userIndex);
            System.out.printf("│ %-18s │ %-18s │ %-14s │%n",
                    truncate(u.getUsername(), 18),
                    truncate(u.getEmail(), 18),
                    u.getRole().toString());
            userIndex++;
        }
        System.out.println("└────────────────────┴────────────────────┴────────────────┘");
    }

    private static void listAllReservations() {
        System.out.println("\n═══════════════ TÜM REZERVASYONLAR ═══════════════");
        List<Reservation> reservations = reservationManager.getAllReservations();

        if (reservations.isEmpty()) {
            System.out.println("Henüz rezervasyon bulunmamaktadır.");
            return;
        }

        printReservationTable(reservations);
    }

    private static String truncate(String str, int maxLen) {
        if (str == null)
            return "";
        return str.length() > maxLen ? str.substring(0, maxLen - 2) + ".." : str;
    }
}
