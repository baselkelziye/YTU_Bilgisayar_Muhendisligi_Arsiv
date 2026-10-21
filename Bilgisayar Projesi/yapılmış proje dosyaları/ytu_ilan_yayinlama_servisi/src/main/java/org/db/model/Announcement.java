package org.db.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.annotations.Fetch;
import org.hibernate.annotations.FetchMode;

@Entity
@Table(name="announcement")
public class Announcement implements Serializable, Comparable<Announcement> {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
    @Column(name="id")
    @GeneratedValue(strategy=GenerationType.AUTO)
    private int id;
    
    @Column(name="title")
    private String title;
    
    @Column(name="brief", nullable=false)
    private String brief;
    
    @Column(name="content", nullable=false)
    private String content;
    
    @Column(name="number_of_page_views")
    private int numberOfPageViews;
    
    @ManyToOne
    @JoinColumn(name="state")
    private AnnouncementState state; // ilan durumu oluşturulunca pasif, şikayette beklenen, aktif vs
    
    @ManyToOne  
    @JoinColumn(name = "owner_company", nullable=false)
    private Company ownerCompany; 
    
    @ManyToOne
    @JoinColumn(name="owner_packet")
    private CompanyOwnPacket ownerPacket;
    
    @ManyToOne
    @JoinColumn(name="announcement_type", nullable=false)
    private AnnouncementType announcementType; //staj, freelance, part time, full time
    
    @OneToMany(mappedBy="pk.announcement", targetEntity=Application.class, 
    		fetch = FetchType.EAGER, cascade=CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    private List<Application> appStudentList = new ArrayList<Application>();

    @OneToMany(mappedBy="announcement", targetEntity=ComplaintReport.class,
            fetch = FetchType.EAGER, cascade=CascadeType.ALL)
    @Fetch(value = FetchMode.SUBSELECT)
    private List<ComplaintReport> reports = new ArrayList<ComplaintReport>();

    @OneToMany(mappedBy = "announcement", targetEntity = Complaint.class,
            fetch = FetchType.EAGER, cascade=CascadeType.ALL)
    private List<Complaint> complaintList = new ArrayList<Complaint>();
    
    @Column(name = "announcement_language")
    private String announcementLanguage;
    
    @ManyToOne
    @JoinColumn(name = "announcement_category")
    private AnnouncementCategory category;
    
    @Column(name = "publish_date")
    private Date publishDate;

    @Column(name = "expired_date")
    private Date expiredDate;

    @Column(name = "proper_complaint")
    private boolean properComplaint;

    @Column(name = "visibility")
    private boolean visibility;

	public Announcement(){
    	super();
    }

    public Announcement(int id) {
        super();
        this.id = id;
    }

    public int compareTo(Announcement a) {
        if(getPublishDate() == null)
            return -1;
        else if(a.getPublishDate() == null)
            return 1;
        else
            return getPublishDate().compareTo(a.getPublishDate());
    }

    public AnnouncementType getAnnouncementType() {
        return announcementType;
    }

    public void setAnnouncementType(AnnouncementType announcementType) {
        this.announcementType = announcementType;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getBrief() {
        return brief;
    }

    public void setBrief(String brief) {
        this.brief = brief;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public int getNumberOfPageViews() {
        return numberOfPageViews;
    }

    public void setNumberOfPageViews(int numberOfPageViews) {
        this.numberOfPageViews = numberOfPageViews;
    }

    public AnnouncementState getState() {
        return state;
    }

    public void setState(AnnouncementState state) {
        this.state = state;
    }

    public Company getOwnerCompany() {
        return ownerCompany;
    }

    public void setOwnerCompany(Company ownerCompany) {
        this.ownerCompany = ownerCompany;
    }

    public CompanyOwnPacket getOwnerPacket() {
        return ownerPacket;
    }

    public void setOwnerPacket(CompanyOwnPacket ownerPacket) {
        this.ownerPacket = ownerPacket;
    }
    
    public List<Application> getAppStudentList() {
		return appStudentList;
	}

	public void setAppStudentList(List<Application> appStudentList) {
		this.appStudentList = appStudentList;
	}
	
	public String getAnnouncementLanguage() {
		return announcementLanguage;
	}

	public void setAnnouncementLanguage(String announcementLanguage) {
		this.announcementLanguage = announcementLanguage;
	}

	public AnnouncementCategory getCategory() {
		return category;
	}

	public void setCategory(AnnouncementCategory category) {
		this.category = category;
	}
	
	public Date getPublishDate() {
		return publishDate;
	}

	public void setPublishDate(Date publishDate) {
		this.publishDate = publishDate;
	}

    public List<Complaint> getComplaintList() {
        return complaintList;
    }

    public void setComplaintList(List<Complaint> complaintList) {
        this.complaintList = complaintList;
    }

    public boolean isProperComplaint() {
        return properComplaint;
    }

    public void setProperComplaint(boolean properComplaint) {
        this.properComplaint = properComplaint;
    }

    public Date getExpiredDate() {
        return expiredDate;
    }

    public void setExpiredDate(Date expiredDate) {
        this.expiredDate = expiredDate;
    }

    public List<ComplaintReport> getReports() {
        return reports;
    }

    public void setReports(List<ComplaintReport> reports) {
        this.reports = reports;
    }

    public boolean isVisibility() {
        return visibility;
    }

    public void setVisibility(boolean visibility) {
        this.visibility = visibility;
    }
}
