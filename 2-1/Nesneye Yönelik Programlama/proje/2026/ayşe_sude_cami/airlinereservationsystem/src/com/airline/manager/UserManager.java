package com.airline.manager;

import com.airline.model.*;
import com.airline.model.enums.UserRole;
import com.airline.util.FileManager;
import com.airline.exception.DuplicateEntryException;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Kullanıcı yönetimi işlemlerini gerçekleştirir.
 * Giriş, kayıt ve kullanıcı CRUD işlemleri yapar.
 */
public class UserManager {

    private static final String USERS_FILE = "users.dat";
    private static final String PASSENGERS_FILE = "passengers.dat";

    private List<User> users;
    private List<Passenger> passengers;
    private User currentUser; // Şu an giriş yapmış kullanıcı

    /**
     * UserManager oluşturur ve verileri yükler.
     */
    public UserManager() {
        this.users = new ArrayList<>();
        this.passengers = new ArrayList<>();
        loadFromFile();
        createDefaultAdmin();
    }

    /**
     * Varsayılan admin hesabını oluşturur (yoksa).
     */
    private void createDefaultAdmin() {
        boolean adminExists = users.stream()
                .anyMatch(u -> u.getRole() == UserRole.ADMIN);

        if (!adminExists) {
            Admin admin = new Admin("admin", "admin123", "admin@airline.com", 2);
            users.add(admin);
            saveToFile();
        }
    }

    /**
     * Kullanıcı girişi yapar.
     * @param username Kullanıcı adı
     * @param password Şifre
     * @return Giriş başarılı ise kullanıcı, değilse null
     */
    public User login(String username, String password) {
        java.util.Iterator<User> iterator = users.iterator();
        while (iterator.hasNext()) {
            User user = iterator.next();
            if (user.login(username, password)) {
                currentUser = user;
                return user;
            }
        }
        return null;
    }

    /**
     * Kullanıcı çıkışı yapar.
     */
    public void logout() {
        if (currentUser != null) {
            currentUser.logout();
            currentUser = null;
        }
    }

    /**
     * Yeni müşteri kaydı yapar.
     * @param username Kullanıcı adı
     * @param password Şifre
     * @param email E-posta
     * @param name Ad
     * @param surname Soyad
     * @param phone Telefon
     * @return Oluşturulan müşteri
     */
    public Customer registerCustomer(String username, String password, String email,
                                      String name, String surname, String phone) {
        // Kullanıcı adı kontrolü
        if (isUsernameTaken(username)) {
            throw new DuplicateEntryException("Kullanıcı adı", username);
        }

        // Yolcu oluştur
        Passenger passenger = new Passenger(name, surname, email, phone);
        passengers.add(passenger);

        // Müşteri oluştur
        Customer customer = new Customer(username, password, email, passenger);
        users.add(customer);

        saveToFile();
        return customer;
    }

    /**
     * Yeni personel kaydı yapar (sadece admin yapabilir).
     */
    public Staff registerStaff(String username, String password, String email,
                               String department, String position) {
        if (currentUser == null || currentUser.getRole() != UserRole.ADMIN) {
            throw new SecurityException("Bu işlem için admin yetkisi gerekli!");
        }

        if (isUsernameTaken(username)) {
            throw new DuplicateEntryException("Kullanıcı adı", username);
        }

        Staff staff = new Staff(username, password, email, department, position);
        users.add(staff);
        saveToFile();
        return staff;
    }

    /**
     * Kullanıcı adının kullanılıp kullanılmadığını kontrol eder.
     */
    public boolean isUsernameTaken(String username) {
        return users.stream()
                .anyMatch(u -> u.getUsername().equalsIgnoreCase(username));
    }

    /**
     * Kullanıcı adına göre kullanıcı arar.
     */
    public User getUserByUsername(String username) {
        java.util.Iterator<User> iterator = users.iterator();
        while (iterator.hasNext()) {
            User user = iterator.next();
            if (user.getUsername().equalsIgnoreCase(username)) {
                return user;
            }
        }
        return null;
    }

    /**
     * ID'ye göre kullanıcı arar.
     */
    public User getUserById(String userId) {
        java.util.Iterator<User> iterator = users.iterator();
        while (iterator.hasNext()) {
            User user = iterator.next();
            if (user.getUserId().equals(userId)) {
                return user;
            }
        }
        return null;
    }

    /**
     * Kullanıcıyı siler (sadece admin yapabilir).
     */
    public boolean deleteUser(String userId) {
        if (currentUser == null || currentUser.getRole() != UserRole.ADMIN) {
            throw new SecurityException("Bu işlem için admin yetkisi gerekli!");
        }

        boolean removed = users.removeIf(u -> u.getUserId().equals(userId) &&
                                              u.getRole() != UserRole.ADMIN);
        if (removed) {
            saveToFile();
        }
        return removed;
    }

    /**
     * Kullanıcı bilgilerini günceller.
     */
    public boolean updateUser(User user) {
        int i = 0;
        while (i < users.size()) {
            if (users.get(i).getUserId().equals(user.getUserId())) {
                users.set(i, user);
                saveToFile();
                return true;
            }
            i++;
        }
        return false;
    }

    /**
     * Tüm kullanıcıları döndürür.
     */
    public List<User> getAllUsers() {
        return new ArrayList<>(users);
    }

    /**
     * Role göre kullanıcıları filtreler.
     */
    public List<User> getUsersByRole(UserRole role) {
        return users.stream()
                .filter(u -> u.getRole() == role)
                .collect(Collectors.toList());
    }

    /**
     * Tüm müşterileri döndürür.
     */
    public List<Customer> getAllCustomers() {
        return users.stream()
                .filter(u -> u instanceof Customer)
                .map(u -> (Customer) u)
                .collect(Collectors.toList());
    }

    /**
     * Tüm personeli döndürür.
     */
    public List<Staff> getAllStaff() {
        return users.stream()
                .filter(u -> u instanceof Staff)
                .map(u -> (Staff) u)
                .collect(Collectors.toList());
    }

    /**
     * Yolcu ekler.
     */
    public void addPassenger(Passenger passenger) {
        if (!passengers.contains(passenger)) {
            passengers.add(passenger);
            saveToFile();
        }
    }

    /**
     * Tüm yolcuları döndürür.
     */
    public List<Passenger> getAllPassengers() {
        return new ArrayList<>(passengers);
    }

    /**
     * ID'ye göre yolcu arar.
     */
    public Passenger getPassengerById(String passengerId) {
        java.util.Iterator<Passenger> iterator = passengers.iterator();
        while (iterator.hasNext()) {
            Passenger p = iterator.next();
            if (p.getPassengerId().equals(passengerId)) {
                return p;
            }
        }
        return null;
    }

    /**
     * Şu an giriş yapmış kullanıcıyı döndürür.
     */
    public User getCurrentUser() {
        return currentUser;
    }

    /**
     * Kullanıcı giriş yapmış mı kontrol eder.
     */
    public boolean isLoggedIn() {
        return currentUser != null;
    }

    /**
     * Şu anki kullanıcının admin olup olmadığını kontrol eder.
     */
    public boolean isCurrentUserAdmin() {
        return currentUser != null && currentUser.getRole() == UserRole.ADMIN;
    }

    /**
     * Şu anki kullanıcının personel olup olmadığını kontrol eder.
     */
    public boolean isCurrentUserStaff() {
        return currentUser != null &&
               (currentUser.getRole() == UserRole.STAFF || currentUser.getRole() == UserRole.ADMIN);
    }

    /**
     * Verileri dosyaya kaydeder.
     */
    public void saveToFile() {
        FileManager.saveList(users, USERS_FILE);
        FileManager.saveList(passengers, PASSENGERS_FILE);
    }

    /**
     * Verileri dosyadan yükler.
     */
    public void loadFromFile() {
        List<User> loadedUsers = FileManager.loadList(USERS_FILE);
        List<Passenger> loadedPassengers = FileManager.loadList(PASSENGERS_FILE);

        if (loadedUsers != null && !loadedUsers.isEmpty()) {
            this.users = loadedUsers;
        }
        if (loadedPassengers != null && !loadedPassengers.isEmpty()) {
            this.passengers = loadedPassengers;
        }
    }

    /**
     * Kullanıcı sayısını döndürür.
     */
    public int getUserCount() {
        return users.size();
    }
}
