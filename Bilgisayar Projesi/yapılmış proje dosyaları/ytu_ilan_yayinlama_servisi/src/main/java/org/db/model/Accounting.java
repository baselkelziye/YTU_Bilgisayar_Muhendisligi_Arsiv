package org.db.model;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

import org.db.compositePK.AccountingPK;

@Entity
@Table(name="accounting")
public class Accounting implements Serializable {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@EmbeddedId
	private AccountingPK accountingPK;
	
	@ManyToOne
	@JoinColumn(name="user_name", nullable=false)
	private DauUser dauUser;
	
	@Column(name="amount", nullable=false)
	private int amount;

	@Column(name = "description")
	private String description;
	
	public Accounting() {
		super();
	}

	//getter-setter
	public AccountingPK getAccountingPK() {
		return accountingPK;
	}

	public void setAccountingPK(AccountingPK accountingPK) {
		this.accountingPK = accountingPK;
	}

	public DauUser getDauUser() {
		return dauUser;
	}

	public void setDauUser(DauUser dauUser) {
		this.dauUser = dauUser;
	}

	public int getAmount() {
		return amount;
	}

	public void setAmount(int amount) {
		this.amount = amount;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}
}
