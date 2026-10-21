package org.db.model;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.*;

@Entity
@Table(name="announcement_packet")
public class AnnouncementPacket implements Serializable {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
    @Column(name="packet_id")
    @GeneratedValue(strategy= GenerationType.AUTO)
    private int packetId;
    
	@Column(name="title")
    private String title;
   
	@Column(name="announcement_count", nullable=false)
    private int announcementCount;
   
	@Column(name="price", nullable=false)
    private int price;
   
	@Column(name="last_date_used", nullable=false)
    private Date lastDateUsed;
   
	@Column(name="active_time", nullable=false)
    private int activeTime;
   
	@ManyToOne
	@JoinColumn(name="currency", nullable=false)
    private Currency currency;

	@Column(name="condition", nullable=false)
    private String condition;
   
	@ManyToOne
	@JoinColumn(name="bank_account_info", nullable=false)
    private BankAccountInfo accountInfo;

    @Column(name = "visible")
    private boolean visible;

	public AnnouncementPacket(){
        super();
    }
    
    public int getPacketId() {
        return packetId;
    }

    public void setPacketId(int packetId) {
        this.packetId = packetId;
    }

    public int getAnnouncementCount() {
        return announcementCount;
    }

    public void setAnnouncementCount(int announcementCount) {
        this.announcementCount = announcementCount;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public Date getLastDateUsed() {
        return lastDateUsed;
    }

    public void setLastDateUsed(Date lastDateUsed) {
        this.lastDateUsed = lastDateUsed;
    }

    public int getActiveTime() {
        return activeTime;
    }

    public void setActiveTime(int activeTime) {
        this.activeTime = activeTime;
    }

    public Currency getCurrency() {
        return currency;
    }

    public void setCurrency(Currency currency) {
        this.currency = currency;
    }

    public String getCondition() {
        return condition;
    }

    public void setCondition(String condition) {
        this.condition = condition;
    }

    public BankAccountInfo getDonateAcceptUnit() {
        return accountInfo;
    }

    public void setDonateAcceptUnit(BankAccountInfo donateAcceptUnit) {
        this.accountInfo = donateAcceptUnit;
    }
    
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    
    public BankAccountInfo getAccountInfo() {
		return accountInfo;
	}

	public void setAccountInfo(BankAccountInfo accountInfo) {
		this.accountInfo = accountInfo;
	}

    public boolean isVisible() {
        return visible;
    }

    public void setVisible(boolean visible) {
        this.visible = visible;
    }
}
