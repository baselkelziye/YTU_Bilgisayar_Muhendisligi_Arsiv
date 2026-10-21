package org.db.model;

import javax.persistence.*;

@Entity
@Table(name="dau_user")
@PrimaryKeyJoinColumn(name="user_name")

public class DauUser  extends User {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@ManyToOne
	@JoinColumn(name = "unit_name")
	private DonationAcceptUnit dau;

	@Column(name = "name")
	private String name;

	@Column(name = "surname")
	private String surname;

	@Column(name = "contact_mail")
	private String contactMail;

	@Column(name = "contact_tel")
	private String contactTel;

	public DauUser() {
		super();
	}
	
	public DonationAcceptUnit getDau() {
		return dau;
	}

	public void setDau(DonationAcceptUnit dau) {
		this.dau = dau;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSurname() {
		return surname;
	}

	public void setSurname(String surname) {
		this.surname = surname;
	}

	public void setContactMail(String contactMail) {
		this.contactMail = contactMail;
	}

	public String getContactTel() {
		return contactTel;
	}

	public void setContactTel(String contactTel) {
		this.contactTel = contactTel;
	}

	public String getContactMail() {
		return contactMail;
	}

}
