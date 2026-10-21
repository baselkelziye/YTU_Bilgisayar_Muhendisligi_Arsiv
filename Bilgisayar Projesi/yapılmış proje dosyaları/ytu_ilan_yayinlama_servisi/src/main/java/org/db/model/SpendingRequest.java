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
@Table(name = "spending_request")
public class SpendingRequest implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	@Column(name = "id")
	private int id;
	
	@Column(name = "title")
	private String title;
	
	@Column(name = "content")
	private String content;
	
	@Column(name = "amount")
	private int amount;
	
	@Column(name = "sent_date_time")
	private Date sentDateTime;
	
	@Column(name = "updated_date_time")
	private Date updatedDateTime;
	
	@ManyToOne
	@JoinColumn(name = "dau")
	private DonationAcceptUnit dau;
	
	@ManyToOne
	@JoinColumn(name = "state")
	private SpendingRequestState state;
	
	@ManyToOne
	@JoinColumn(name = "updater")
	private DauUser dauUser;
	
	@Column(name = "answer_from_updater")
	private String answerFromUpdater;

	@Column(name = "pdf_path")
	private String pdfPath;

	@Column(name = "image_path")
	private String imagePath;

	public SpendingRequest() {
		super();
	}
	
	//getter-setter
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
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public Date getSentDateTime() {
		return sentDateTime;
	}
	public DonationAcceptUnit getDau() {
		return dau;
	}
	public void setDau(DonationAcceptUnit dau) {
		this.dau = dau;
	}
	public SpendingRequestState getState() {
		return state;
	}
	public void setState(SpendingRequestState state) {
		this.state = state;
	}
	public DauUser getDauUser() {
		return dauUser;
	}
	public void setDauUser(DauUser dauUser) {
		this.dauUser = dauUser;
	}
	public void setAmount(int amount) {
		this.amount = amount;
	}
	public int getAmount() {
		return amount;
	}
	public Date getUpdatedDateTime() {
		return updatedDateTime;
	}
	public void setUpdatedDateTime(Date updatedDateTime) {
		this.updatedDateTime = updatedDateTime;
	}
	public void setSentDateTime(Date sentDateTime) {
		this.sentDateTime = sentDateTime;
	}
	public String getAnswerFromUpdater() {
		return answerFromUpdater;
	}
	public void setAnswerFromUpdater(String answerFromUpdater) {
		this.answerFromUpdater = answerFromUpdater;
	}
	public String getPdfPath() {
		return pdfPath;
	}
	public void setPdfPath(String pdfPath) {
		this.pdfPath = pdfPath;
	}
	public String getImagePath() {
		return imagePath;
	}
	public void setImagePath(String imagePath) {
		this.imagePath = imagePath;
	}
}
