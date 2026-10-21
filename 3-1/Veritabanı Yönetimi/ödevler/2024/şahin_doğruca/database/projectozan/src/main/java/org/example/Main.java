package com.mynamespace.movienight;

import java.util.Scanner;
//import java.util.Date;
import java.sql.Date;
import java.time.LocalDate;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("\n--- Movie Night Yönetim Sistemi ---");
            System.out.println("1. Admin Ekle");
            System.out.println("2. Admin Sil");
            System.out.println("3. Admin Email Güncelle");
            System.out.println("4. Film Ekle");
            System.out.println("5. Film Sil");
            System.out.println("6. Film Türü Güncelle");
            System.out.println("7. Film Vizyon Tarihi Güncelle");
            System.out.println("8. Kullanıcı Ekle");
            System.out.println("9. Kullanıcı Sil");
            System.out.println("10. Kullanıcı Giriş Yap ve Davet Gönder");
            System.out.println("11. Çıkış");
            System.out.println("12. Etkinlik Oluştur");
            System.out.print("Lütfen bir seçenek girin: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Buffer temizleme

            switch (choice) {
                case 1 -> addAdmin(scanner);
                case 2 -> deleteAdmin(scanner);
                case 3 -> updateAdminEmail(scanner);
                case 4 -> addMovie(scanner);
                case 5 -> deleteMovie(scanner);
                case 6 -> updateMovieGenre(scanner);
                case 7 -> updateMovieReleaseDate(scanner);
                case 8 -> addUser(scanner);
                case 9 -> deleteUser(scanner);
                case 10 -> authenticateAndInvite(scanner);
                case 11 -> {
                    exit = true;
                    System.out.println("Çıkış yapılıyor. Görüşmek üzere!");
                }
                case 12 -> authenticateAndCreateEvent(scanner); // Yeni seçenek
                default -> System.out.println("Hatalı seçim. Lütfen tekrar deneyin.");
            }
        }

        scanner.close();
    }

    private static void addAdmin(Scanner scanner) {
        System.out.print("Admin Adı: ");
        String name = scanner.nextLine();
        System.out.print("Admin E-mail: ");
        String email = scanner.nextLine();
        System.out.print("Admin Şifre: ");
        String password = scanner.nextLine();

        Admin admin = new Admin(0, name, email, password);
        AdminDAO adminDAO = new AdminDAO();

        if (adminDAO.addAdmin(admin)) {
            System.out.println("Admin başarıyla eklendi.");
        } else {
            System.out.println("Admin ekleme başarısız.");
        }
    }

    private static void deleteAdmin(Scanner scanner) {
        System.out.print("Silmek istediğiniz adminin adı: ");
        String name = scanner.nextLine();
        System.out.print("Adminin şifresi: ");
        String password = scanner.nextLine();

        AdminDAO adminDAO = new AdminDAO();
        if (adminDAO.deleteAdminByNameAndPassword(name, password)) {
            System.out.println("Admin başarıyla silindi.");
        } else {
            System.out.println("Admin silinemedi.");
        }
    }

    private static void updateAdminEmail(Scanner scanner) {
        System.out.print("Email güncellemek istediğiniz adminin adı: ");
        String name = scanner.nextLine();
        System.out.print("Mevcut şifre: ");
        String currentPassword = scanner.nextLine();
        System.out.print("Yeni email: ");
        String newEmail = scanner.nextLine();

        AdminDAO adminDAO = new AdminDAO();
        if (adminDAO.updateAdminEmail(name, currentPassword, newEmail)) {
            System.out.println("Email başarıyla güncellendi.");
        } else {
            System.out.println("Email güncellenemedi.");
        }
    }

    private static void addMovie(Scanner scanner) {
        System.out.print("Film Adı: ");
        String title = scanner.nextLine();
        System.out.print("Film Türü: ");
        String genre = scanner.nextLine();
        System.out.print("Vizyon Tarihi (YYYY-MM-DD): ");
        String releaseDateInput = scanner.nextLine();
        Date releaseDate = Date.valueOf(releaseDateInput);
        System.out.print("Film Puanı (0-10): ");
        double rating = scanner.nextDouble();
        scanner.nextLine(); // Buffer temizleme

        Movies movie = new Movies(0, title, genre, releaseDate.toLocalDate(), rating);
        MoviesDAO movieDAO = new MoviesDAO();

        if (movieDAO.addMovie(movie)) {
            System.out.println("Film başarıyla eklendi.");
        } else {
            System.out.println("Film eklenemedi.");
        }
    }

    private static void deleteMovie(Scanner scanner) {
        System.out.print("Silmek istediğiniz film adı: ");
        String title = scanner.nextLine();

        MoviesDAO movieDAO = new MoviesDAO();
        if (movieDAO.deleteMovie(title)) {
            System.out.println("Film başarıyla silindi.");
        } else {
            System.out.println("Film silinemedi.");
        }
    }

    private static void updateMovieGenre(Scanner scanner) {
        System.out.print("Türünü güncellemek istediğiniz film adı: ");
        String title = scanner.nextLine();
        System.out.print("Yeni tür: ");
        String newGenre = scanner.nextLine();

        MoviesDAO movieDAO = new MoviesDAO();
        if (movieDAO.updateMovieGenre(title, newGenre)) {
            System.out.println("Film türü başarıyla güncellendi.");
        } else {
            System.out.println("Film türü güncellenemedi.");
        }
    }

    private static void updateMovieReleaseDate(Scanner scanner) {
        System.out.print("Vizyon tarihini güncellemek istediğiniz film adı: ");
        String title = scanner.nextLine();
        System.out.print("Yeni vizyon tarihi (YYYY-MM-DD): ");
        String releaseDateInput = scanner.nextLine();
        Date releaseDate = Date.valueOf(releaseDateInput);

        MoviesDAO movieDAO = new MoviesDAO();
        if (movieDAO.updateMovieReleaseDate(title, releaseDate.toLocalDate())) {
            System.out.println("Vizyon tarihi başarıyla güncellendi.");
        } else {
            System.out.println("Vizyon tarihi güncellenemedi.");
        }
    }

    private static void addUser(Scanner scanner) {
        System.out.print("Kullanıcı adı: ");
        String username = scanner.nextLine();
        System.out.print("Email: ");
        String email = scanner.nextLine();
        System.out.print("Şifre: ");
        String password = scanner.nextLine();

        Users user = new Users(0, username, email, password);
        UsersDAO userDAO = new UsersDAO();

        if (userDAO.addUser(user)) {
            System.out.println("Kullanıcı başarıyla eklendi.");
        } else {
            System.out.println("Kullanıcı eklenemedi.");
        }
    }

    private static void deleteUser(Scanner scanner) {
        System.out.print("Kullanıcı adı: ");
        String username = scanner.nextLine();
        System.out.print("Şifre: ");
        String password = scanner.nextLine();

        UsersDAO userDAO = new UsersDAO();
        if (userDAO.deleteUser(username, password)) {
            System.out.println("Kullanıcı başarıyla silindi.");
        } else {
            System.out.println("Kullanıcı silinemedi.");
        }
    }

    private static void authenticateAndInvite(Scanner scanner) {
        System.out.print("Kullanıcı adı: ");
        String username = scanner.nextLine();
        System.out.print("Şifre: ");
        String password = scanner.nextLine();

        UsersDAO usersDAO = new UsersDAO();
        if (usersDAO.authenticateUser(username, password)) {
            System.out.println("Başarıyla giriş yaptınız!");
            UserSession.setUserID(usersDAO.getUserIDByUsername(username));
            UserSession.setUserName(username);

            System.out.print("Davetiye göndermek istediğiniz etkinlik adı: ");
            String eventName = scanner.nextLine();
            System.out.print("Davet gönderilecek kullanıcı adı: ");
            String invitedUsername = scanner.nextLine();

            InvitationDAO invitationDAO = new InvitationDAO();
            if (invitationDAO.addInvitation(eventName, invitedUsername)) {
                System.out.println("Davet başarıyla gönderildi.");
            } else {
                System.out.println("Davet gönderilemedi.");
            }
        } else {
            System.out.println("Giriş başarısız.");
        }
    }
    private static void authenticateAndCreateEvent(Scanner scanner) {
        System.out.print("Kullanıcı adı: ");
        String username = scanner.nextLine();
        System.out.print("Şifre: ");
        String password = scanner.nextLine();

        UsersDAO usersDAO = new UsersDAO();
        if (usersDAO.authenticateUser(username, password)) {
            System.out.println("Başarıyla giriş yaptınız!");
            UserSession.setUserID(usersDAO.getUserIDByUsername(username));
            UserSession.setUserName(username);

            System.out.print("Etkinlik adı: ");
            String eventName = scanner.nextLine();
            System.out.print("Etkinlik tarihi (YYYY-MM-DD): ");
            String eventDateInput = scanner.nextLine();
            LocalDate eventDate = LocalDate.parse(eventDateInput); // LocalDate'e dönüştür

            Events event = new Events(0, 0, eventName, eventDate);
            EventsDAO eventsDAO = new EventsDAO();
            if (eventsDAO.addEvent(event)) {
                System.out.println("Etkinlik başarıyla oluşturuldu.");
            } else {
                System.out.println("Etkinlik oluşturulamadı.");
            }
        } else {
            System.out.println("Giriş başarısız.");
        }
    }
}
