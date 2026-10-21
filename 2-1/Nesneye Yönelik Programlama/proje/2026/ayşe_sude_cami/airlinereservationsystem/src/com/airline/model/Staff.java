package com.airline.model;

import com.airline.model.enums.UserRole;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Personel kullanıcı sınıfı.
 * Uçuş yönetimi ve tüm rezervasyonları görüntüleme yetkilerine sahiptir.
 */
public class Staff extends User {
    private static final long serialVersionUID = 1L;

    private String staffId;
    private String department;
    private String position;

    /**
     * Yeni bir personel oluşturur.
     */
    public Staff(String username, String password, String email, 
                 String department, String position) {
        super(username, password, email, UserRole.STAFF);
        this.staffId = generateStaffId();
        this.department = department;
        this.position = position;
    }

    /**
     * ID ile birlikte personel oluşturur.
     */
    public Staff(String userId, String username, String password, String email,
                 String staffId, String department, String position) {
        super(userId, username, password, email, UserRole.STAFF);
        this.staffId = staffId;
        this.department = department;
        this.position = position;
    }

    private String generateStaffId() {
        return "STF-" + System.currentTimeMillis() % 100000;
    }

    @Override
    public List<String> getPermissions() {
        return Arrays.asList(
            // Müşteri yetkileri
            "SEARCH_FLIGHTS",
            "VIEW_FLIGHT_DETAILS",
            "MAKE_RESERVATION",
            "VIEW_OWN_RESERVATIONS",
            "CANCEL_OWN_RESERVATION",
            "VIEW_TICKET",
            "UPDATE_PROFILE",
            // Personel yetkileri
            "VIEW_ALL_RESERVATIONS",
            "MANAGE_FLIGHTS",
            "ADD_FLIGHT",
            "EDIT_FLIGHT",
            "VIEW_REPORTS",
            "CHECK_IN_PASSENGER"
        );
    }

    /**
     * Uçuş yönetimi işlemi.
     */
    public void manageFlights() {
        // FlightManager ile entegre çalışır
    }

    /**
     * Tüm rezervasyonları görüntüler.
     */
    public List<Reservation> viewAllReservations() {
        // ReservationManager ile entegre çalışır
        return new ArrayList<>();
    }

    /**
     * Rapor oluşturur.
     */
    public void generateReports() {
        // ReportGenerator ile entegre çalışır
    }

    // Getter ve Setter metodları
    public String getStaffId() {
        return staffId;
    }

    public void setStaffId(String staffId) {
        this.staffId = staffId;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    @Override
    public String toString() {
        return String.format("Staff{id='%s', staffId='%s', username='%s', department='%s', position='%s'}",
                getUserId(), staffId, getUsername(), department, position);
    }
}
