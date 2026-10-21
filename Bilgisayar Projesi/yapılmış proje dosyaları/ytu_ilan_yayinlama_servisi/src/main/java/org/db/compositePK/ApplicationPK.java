package org.db.compositePK;

import java.io.Serializable;

import javax.persistence.Embeddable;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;

import org.db.model.Announcement;
import org.db.model.User;

@Embeddable
public class ApplicationPK implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@ManyToOne
	@JoinColumn(name = "username")
	private User user;
	
	@ManyToOne
	@JoinColumn(name = "announcement_id")
	private Announcement announcement;
	
	public ApplicationPK() {
		super();
	}

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public Announcement getAnnouncement() {
		return announcement;
	}

	public void setAnnouncement(Announcement announcement) {
		this.announcement = announcement;
	}
	
	
}
