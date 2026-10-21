package org.db.compositePK;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;

import org.db.model.DonationAcceptUnit;

public class AccountingPK implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@ManyToOne
	@JoinColumn(name="unit_name")
	private DonationAcceptUnit unit;

	@Column(name="date_time")
	private Date dateTime;
	
	public AccountingPK() {
		super();
	}

	public DonationAcceptUnit getUnit() {
		return unit;
	}

	public void setUnit(DonationAcceptUnit unit) {
		this.unit = unit;
	}

	public Date getDateTime() {
		return dateTime;
	}

	public void setDateTime(Date dateTime) {
		this.dateTime = dateTime;
	}
	
	
}
