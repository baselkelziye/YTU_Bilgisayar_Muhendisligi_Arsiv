package org.db.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="membership_status")
public class MembershipStatus {
	@Id //sıralı artan generated eklenecek
	@Column(name="id")
	private int id;
	
	@Column(name="status", nullable=false)
	private String status;
	
	public MembershipStatus() {
		super();
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getStatus() {
		return status;
	}
	public void setStatus(String status) {
		this.status = status;
	}
}
