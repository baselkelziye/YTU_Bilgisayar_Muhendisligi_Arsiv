package org.db.model;

import java.io.Serializable;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.OneToMany;
import javax.persistence.PrimaryKeyJoinColumn;
import javax.persistence.Table;

import org.hibernate.annotations.Fetch;
import org.hibernate.annotations.FetchMode;

@Entity
@Table(name="company")
@PrimaryKeyJoinColumn(name="user_name")
public class Company extends User implements Serializable {
	private static final long serialVersionUID = 1L;
    
    @Column(name="company_name", nullable=false)
    private String companyName;
    
    @Column(name="location", nullable=true)
    private String location;
    
    @OneToMany(mappedBy="ownerCompany", targetEntity=Announcement.class, 
    		fetch = FetchType.EAGER, cascade=CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    private List<Announcement> announcements;
    
    @OneToMany(mappedBy="ownerCompany", targetEntity=CompanyOwnPacket.class, 
    		fetch = FetchType.EAGER, cascade=CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    private List<CompanyOwnPacket> packets;

    @Column(name = "name")
	private String name;

	@Column(name = "surname")
	private String surname;

    @Column(name = "contact_mail")
    private String contactMail;

    public String getContactMail() {
        return contactMail;
    }

    @Column(name = "contact_tel")
    private String contactTel;

    @Column(name = "kep")
    private String kep;

    @Column(name = "mersis")
    private String mersis;

    public Company(){
    	super();
    }
    
    public String getCompanyName() {
        return companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }
    
    public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public List<Announcement> getAnnouncements() {
		return announcements;
	}

	public void setAnnouncements(List<Announcement> announcements) {
		this.announcements = announcements;
	}
	
	public List<CompanyOwnPacket> getPackets() {
		return packets;
	}

	public void setPackets(List<CompanyOwnPacket> packets) {
		this.packets = packets;
	}

	public void setName(String name) {
		this.name = name;
	}

    public String getName() {
        return name;
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

    public String getKep() {
        return kep;
    }

    public void setKep(String kep) {
        this.kep = kep;
    }

    public String getMersis() {
        return mersis;
    }

    public void setMersis(String mersis) {
        this.mersis = mersis;
    }
}
