package org.db.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.annotations.Fetch;
import org.hibernate.annotations.FetchMode;


@Entity
@Table(name = "donation_accept_unit")
public class DonationAcceptUnit implements Serializable {
	private static final long serialVersionUID = 1L;
	
	@Id
	@Column(name="unit_name", nullable=false)
    private String unitName;
	
    @Column(name="balance")
    private int balance;

    @Column(name="created_date")
    private Date createdDate;
    
    @OneToMany(mappedBy="dau",  
            targetEntity=DauUser.class, fetch = FetchType.EAGER, cascade = CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    List<DauUser> dauUser = new ArrayList<DauUser>();
    
    @OneToMany(mappedBy="ownerUnit", fetch = FetchType.EAGER, 
    	    targetEntity=BankAccountInfo.class, cascade = CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    List<BankAccountInfo> account = new ArrayList<BankAccountInfo>();

    public List<DauUser> getDauUser() {
		return dauUser;
	}

	public void setDauUser(List<DauUser> dauUser) {
		this.dauUser = dauUser;
	}

	public List<BankAccountInfo> getAccount() {
		return account;
	}

	public void setAccount(List<BankAccountInfo> account) {
		this.account = account;
	}

	public DonationAcceptUnit(){
        super();
    }
    
    public String getUnitName() {
        return unitName;
    }

    public void setUnitName(String unitName) {
        this.unitName = unitName;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public Date getCreatedDate() {
        return createdDate;
    }

    public void setCreatedDate(Date createdDate) {
        this.createdDate = createdDate;
    }
}
