package org.db.model;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="donation")
public class Donation implements Serializable {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
    @Column(name="donation_id")
    @GeneratedValue(strategy=GenerationType.AUTO)
    private int donationId;
    
    @Column(name="company_username", nullable=false)
    private String companyUsername;
    
    @Column(name="donation_accept_unit_username")
    private String donationAcceptUnitUsername;
    
    @Column(name="packet_id", nullable=false)
    private int packetId;
    
    @Column(name="iban")
    private String iban;
    
    @Column(name="amount")
    private int amount;
    
    @Column(name="approved", columnDefinition = "boolean default false")
    private boolean approved;
    
    public Donation(){
        
    }
    
    public int getDonationId() {
        return donationId;
    }

    public void setDonationId(int donationId) {
        this.donationId = donationId;
    }

    public String getCompanyUsername() {
        return companyUsername;
    }

    public void setCompanyUsername(String companyUsername) {
        this.companyUsername = companyUsername;
    }

    public String getDonationAcceptUnitUsername() {
        return donationAcceptUnitUsername;
    }

    public void setDonationAcceptUnitUsername(String donationAcceptUnitUsername) {
        this.donationAcceptUnitUsername = donationAcceptUnitUsername;
    }

    public int getPacketId() {
        return packetId;
    }

    public void setPacketId(int packetId) {
        this.packetId = packetId;
    }

    public String getIban() {
        return iban;
    }

    public void setIban(String iban) {
        this.iban = iban;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
    
    public boolean isApproved() {
        return approved;
    }

    public void setApproved(boolean approved) {
        this.approved = approved;
    }
}
