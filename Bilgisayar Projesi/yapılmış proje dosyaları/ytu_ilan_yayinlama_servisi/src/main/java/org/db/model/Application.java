package org.db.model;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.Table;

import org.db.compositePK.ApplicationPK;
import org.hibernate.annotations.Generated;
import org.hibernate.annotations.GenerationTime;

@Entity
@Table(name = "application")
public class Application implements Serializable {

	private static final long serialVersionUID = 1L;

	@EmbeddedId
	private ApplicationPK pk;

	@Column(name="application_no", columnDefinition="serial")
	@Generated(GenerationTime.INSERT)
	private int applicationNo;

	@Column(name = "time_to_application", nullable = false)
	private Date timeToApplication;

	@Column(name = "ip_address")
	private String ipAddress;

	public ApplicationPK getPk() {
	return pk;
	}

	public void setPk(ApplicationPK pk) {
	this.pk = pk;
	}

	public int getApplicationNo() {
	return applicationNo;
	}

	public void setApplicationNo(int applicationNo) {
	this.applicationNo = applicationNo;
	}

	public Date getTimeToApplication() {
	return timeToApplication;
	}

	public void setTimeToApplication(Date timeToApplication) {
	this.timeToApplication = timeToApplication;
	}

	public String getIpAddress() {
	return ipAddress;
	}

	public void setIpAddress(String ipAddress) {
		this.ipAddress = ipAddress;
	}
}
