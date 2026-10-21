package com.airline.model.enums;

/**
 * Kullanıcı rollerini tanımlar.
 */
public enum UserRole {
    CUSTOMER("Müşteri"),
    STAFF("Personel"),
    ADMIN("Yönetici");

    private final String description;

    UserRole(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}
