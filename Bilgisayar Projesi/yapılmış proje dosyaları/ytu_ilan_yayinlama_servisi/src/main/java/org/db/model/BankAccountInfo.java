package org.db.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name="bank_account_info")
public class BankAccountInfo implements Serializable {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
	@Column(name="iban")
    private String iban;

	@ManyToOne
    @JoinColumn(name="owner_unit_name")
    private DonationAcceptUnit ownerUnit;
    
    @Column(name="bank_name", nullable = false)
    private String bankName;
    
    @Column(name="branch_bank_name", nullable = false)
    private String branchBankName;
    
    @Column(name="bank_account_number", nullable = false)
    private int bankAccountNumber;
    
    @Column(name="currency", nullable = false)
    private int currency;
    
    @OneToMany(mappedBy="accountInfo",  
            targetEntity=AnnouncementPacket.class, fetch = FetchType.EAGER, cascade = CascadeType.ALL)
    List<AnnouncementPacket> packetList = new ArrayList<AnnouncementPacket>();

	public List<AnnouncementPacket> getPacketList() {
		return packetList;
	}

	public void setPacketList(List<AnnouncementPacket> packetList) {
		this.packetList = packetList;
	}

	public int getCurrency() {
        return currency;
    }

    public void setCurrency(int currency) {
        this.currency = currency;
    }

    public DonationAcceptUnit getOwnerUnit() {
        return ownerUnit;
    }

    public void setOwnerUnit(DonationAcceptUnit ownerUnitName) {
        this.ownerUnit = ownerUnitName;
    }

    public String getBankName() {
        return bankName;
    }

    public void setBankName(String bankName) {
        this.bankName = bankName;
    }

    public String getBranchBankName() {
        return branchBankName;
    }

    public void setBranchBankName(String branchBankName) {
        this.branchBankName = branchBankName;
    }

    public int getBankAccountNumber() {
        return bankAccountNumber;
    }

    public void setBankAccountNumber(int bankAccountNumber) {
        this.bankAccountNumber = bankAccountNumber;
    }

    public String getIban() {
        return iban;
    }

    public void setIban(String iban) {
        this.iban = iban;
    }
    
}
