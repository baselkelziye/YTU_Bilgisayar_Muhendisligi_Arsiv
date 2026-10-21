package org.db.model;

import java.io.Serializable;

import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

import org.db.compositePK.CommunicationWayPK;

@Entity
@Table(name = "communication_way")

public class CommunicationWay implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;

	@EmbeddedId
	private CommunicationWayPK pk;

	@ManyToOne
	@JoinColumn(name = "user_name", nullable = false)
	private User user;

	public CommunicationWay() {
		super();
	}

	public CommunicationWay(CommunicationWayPK pk) {
		this.pk = pk;
	}

	public CommunicationWayPK getPk() {
		return pk;
	}

	public User getUser() {
		return user;
	}

	public void setPk(CommunicationWayPK pk) {
		this.pk = pk;
	}

	public void setUser(User user) {
		this.user = user;
	}

}
