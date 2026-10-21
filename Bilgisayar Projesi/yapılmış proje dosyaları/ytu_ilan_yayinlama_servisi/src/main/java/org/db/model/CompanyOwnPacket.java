package org.db.model;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@Entity
@Table(name = "company_own_packet")
public class CompanyOwnPacket implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
	@Column(name="id")
    @GeneratedValue(strategy=GenerationType.AUTO)
	private int id;
	
	@ManyToOne
	@JoinColumn(name = "owner_company", nullable = false)
	private Company ownerCompany;

	@ManyToOne
	@JoinColumn(name = "packet", nullable = false)
	private AnnouncementPacket packet;
	
	@ManyToOne
	@JoinColumn(name = "announcement_packet_state")
	private AnnouncementPacketState state;
	
	@Column(name = "used_announcements")
	private int usedAnnouncements;
	
	@Column(name = "approved")
	private boolean approved;
	
	//isteği onaylayan/reddeden vakıf kullanıcısının kullanıcı adı
	@Column(name = "user_for_approved")
	private String usernameForApproved;
	
	@Column(name = "time_to_request", nullable = false)
	private Date timeToRequest;
	
	@Column(name = "time_to_approved")
	private Date timeToApproved;

	@Column(name = "time_to_expired")
	private Date timeToExpired;

	@Column(name = "file_path")
	private String filePath;

	@Column(name = "second_file_path")
	private String secondFilePath;

    @Column(name = "company_description")
    private String companyDescription;

    @Column(name = "second_company_description")
    private String secondCompanyDescription;

    @Column(name = "dau_description")
    private String dauDescription;

    @Column(name = "second_dau_description")
    private String secondDauDescription;

	public CompanyOwnPacket() {
		super();
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public Company getOwnerCompany() {
		return ownerCompany;
	}

	public void setOwnerCompany(Company ownerCompany) {
		this.ownerCompany = ownerCompany;
	}

	public AnnouncementPacket getPacket() {
		return packet;
	}

	public void setPacket(AnnouncementPacket packet) {
		this.packet = packet;
	}

	public int getUsedAnnouncements() {
		return usedAnnouncements;
	}

	public void setUsedAnnouncements(int usedAnnouncements) {
		this.usedAnnouncements = usedAnnouncements;
	}

	public boolean isApproved() {
		return approved;
	}

	public void setApproved(boolean approved) {
		this.approved = approved;
	}

	public String getUsernameForApproved() {
		return usernameForApproved;
	}

	public void setUsernameForApproved(String usernameForApproed) {
		this.usernameForApproved = usernameForApproed;
	}

	public Date getTimeToRequest() {
		return timeToRequest;
	}

	public void setTimeToRequest(Date timeToRequest) {
		this.timeToRequest = timeToRequest;
	}

	public Date getTimeToApproved() {
		return timeToApproved;
	}

	public void setTimeToApproved(Date timeToApproved) {
		this.timeToApproved = timeToApproved;
	}
	
	public AnnouncementPacketState getState() {
		return state;
	}

	public void setState(AnnouncementPacketState state) {
		this.state = state;
	}

    public Date getTimeToExpired() {
        return timeToExpired;
    }

    public void setTimeToExpired(Date timeToExpired) {
        this.timeToExpired = timeToExpired;
    }

    public String getFilePath() {
        return filePath;
    }

    public void setFilePath(String filePath) {
        this.filePath = filePath;
    }

    public String getCompanyDescription() {
        return companyDescription;
    }

    public void setCompanyDescription(String companyDescription) {
        this.companyDescription = companyDescription;
    }

    public String getSecondFilePath() {
        return secondFilePath;
    }

    public void setSecondFilePath(String secondFilePath) {
        this.secondFilePath = secondFilePath;
    }

    public String getDauDescription() {
        return dauDescription;
    }

    public String getSecondDauDescription() {
        return secondDauDescription;
    }

    public void setSecondDauDescription(String secondDauDescription) {
        this.secondDauDescription = secondDauDescription;
    }

    public void setDauDescription(String dauDescription) {
        this.dauDescription = dauDescription;
    }

    public String getSecondCompanyDescription() {
        return secondCompanyDescription;
    }

    public void setSecondCompanyDescription(String secondCompanyDescription) {
        this.secondCompanyDescription = secondCompanyDescription;
    }
}
