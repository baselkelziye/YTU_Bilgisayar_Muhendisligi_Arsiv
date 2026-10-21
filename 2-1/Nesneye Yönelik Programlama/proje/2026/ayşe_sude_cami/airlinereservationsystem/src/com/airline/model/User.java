package com.airline.model;

import com.airline.model.enums.UserRole;
import java.io.Serializable;
import java.util.List;
import java.util.UUID;

public abstract class User implements Serializable {
	private static final long serialVersionUID = 1L;

	protected String userId;
	protected String username;
	protected String password;
	protected String email;
	protected UserRole role;
	protected boolean active;

	public User(String username, String password, String email, UserRole role) {
		this.userId = generateUserId();
		this.username = username;
		this.password = password;
		this.email = email;
		this.role = role;
		this.active = true;
	}

	public User(String userId, String username, String password, String email, UserRole role) {
		this.userId = userId;
		this.username = username;
		this.password = password;
		this.email = email;
		this.role = role;
		this.active = true;
	}

	private String generateUserId() {
		return "USR-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase();
	}

	/**
	 * Kullanıcı girişi yapar.
	 * @param username Kullanıcı adı
	 * @param password Şifre
	 * @return Giriş başarılı ise true
	 */
	public boolean login(String username, String password) {
		return this.username.equals(username) && this.password.equals(password) && this.active;
	}

	/**
	 * Kullanıcı çıkışı yapar.
	 */
	public void logout() {
		// Oturum kapatma işlemleri
	}

	public abstract List<String> getPermissions();

	public boolean hasPermission(String permission) {
		return getPermissions().contains(permission);
	}

	/**
	 * Şifre doğrulama.
	 */
	public boolean checkPassword(String password) {
		return this.password.equals(password);
	}

	/**
	 * Şifre değiştirme.
	 */
	public void changePassword(String oldPassword, String newPassword) {
		if (checkPassword(oldPassword)) {
			this.password = newPassword;
		}
	}

	// Getter ve Setter metodları
	public String getUserId() {
		return userId;
	}

	public void setUserId(String userId) {
		this.userId = userId;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public UserRole getRole() {
		return role;
	}

	public void setRole(UserRole role) {
		this.role = role;
	}

	public boolean isActive() {
		return active;
	}

	public void setActive(boolean active) {
		this.active = active;
	}

	@Override
	public String toString() {
		return String.format("User{id='%s', username='%s', role=%s, active=%s}",
				userId, username, role, active);
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		User user = (User) o;
		return userId != null && userId.equals(user.userId);
	}

	@Override
	public int hashCode() {
		return userId != null ? userId.hashCode() : 0;
	}
}
