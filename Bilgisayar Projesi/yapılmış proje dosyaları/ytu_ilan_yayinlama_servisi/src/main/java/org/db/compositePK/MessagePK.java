package org.db.compositePK;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import javax.persistence.JoinColumn;

@Embeddable
public class MessagePK implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@JoinColumn
	@Column(name="sender_email_address", nullable=false)
    private String mailAddress;
    
	@Column(name="date_time", nullable=false)
    private Date dateTime;
    
    public String getMailAddress() {
        return mailAddress;
    }

    public void setMailAddress(String emailAddress) {
        this.mailAddress = emailAddress;
    }
    
    public Date getDateTime() {
        return dateTime;
    }

    public void setDateTime(Date dateTime) {
        this.dateTime = dateTime;
    }

}
