package com.airline.model;

import com.airline.model.enums.UserRole;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Admin extends Staff {
	private static final long serialVersionUID = 1L;

	private int adminLevel;

	public Admin(String username, String password, String email) {
		super(username, password, email, "Yönetim", "Sistem Yöneticisi");
		this.setRole(UserRole.ADMIN);
		this.adminLevel = 1;
	}

	public Admin(String username, String password, String email, int adminLevel) {
		super(username, password, email, "Yönetim", "Sistem Yöneticisi");
		this.setRole(UserRole.ADMIN);
		this.adminLevel = adminLevel;
	}

	public Admin(String userId, String username, String password, String email,
				 String staffId, int adminLevel) {
		super(userId, username, password, email, staffId, "Yönetim", "Sistem Yöneticisi");
		this.setRole(UserRole.ADMIN);
		this.adminLevel = adminLevel;
	}

	@Override
	public List<String> getPermissions() {
		List<String> permissions = new ArrayList<>(super.getPermissions());
		permissions.addAll(Arrays.asList(
			"MANAGE_USERS",
			"CREATE_USER",
			"DELETE_USER",
			"MANAGE_STAFF",
			"CREATE_STAFF",
			"DELETE_STAFF",
			"SYSTEM_SETTINGS",
			"VIEW_ALL_REPORTS",
			"DELETE_FLIGHT",
			"CANCEL_ANY_RESERVATION",
			"VIEW_SYSTEM_LOGS",
			"MANAGE_ROUTES",
			"MANAGE_PLANES"
		));
		if (adminLevel >= 2) {
			permissions.addAll(Arrays.asList(
				"MANAGE_ADMINS",
				"SYSTEM_BACKUP",
				"SYSTEM_RESTORE"
			));
		}
		return permissions;
	}

	/**
	 * Personel yönetimi.
	 */
	public void manageStaff() {
		// Personel ekleme, silme, düzenleme
	}

	/**
	 * Kullanıcı yönetimi.
	 */
	public void manageUsers() {
		// Kullanıcı ekleme, silme, düzenleme
	}

	/**
	 * Sistem ayarları.
	 */
	public void systemSettings() {
		// Sistem konfigürasyonu
	}

	/**
	 * Super Admin mi kontrol eder.
	 */
	public boolean isSuperAdmin() {
		return adminLevel >= 2;
	}

	// Getter ve Setter metodları
	public int getAdminLevel() {
		return adminLevel;
	}

	public void setAdminLevel(int adminLevel) {
		this.adminLevel = adminLevel;
	}

	@Override
	public String toString() {
		return String.format("Admin{id='%s', username='%s', level=%d, super=%s}",
				getUserId(), getUsername(), adminLevel, isSuperAdmin());
	}
}
