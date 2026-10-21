package org.db.compositePK;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import javax.persistence.JoinColumn;

@Embeddable
public class CommunicationWayPK implements Serializable {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@JoinColumn
    @Column(name="comm_type")
	private String commType;
	
	@Column(name="comm_value")
	private String commValue;

	public String getCommType() {
		return commType;
	}

	public void setCommType(String commType) {
		this.commType = commType;
	}

	public String getCommValue() {
		return commValue;
	}

	public void setCommValue(String commValue) {
		this.commValue = commValue;
	}

}
