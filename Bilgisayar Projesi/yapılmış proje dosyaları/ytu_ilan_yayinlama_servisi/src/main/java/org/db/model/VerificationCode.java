package org.db.model;

import javax.persistence.*;
import java.io.Serializable;
import java.util.Date;

/**
 * Created by mgunes on 25.01.2017.
 */
@Entity
@Table(name = "verification_code")
public class VerificationCode implements Serializable {
    @Id
    @Column(name = "code")
    private String code;

    @ManyToOne
    @JoinColumn(name = "user_name")
    private User username;

    @Column(name = "sending_time", nullable = false)
    private Date sendingTime;

    @Column(name = "operation_time")
    private Date operationTime;

    @Column(name = "state")
    private String state;

    public VerificationCode() {
        super();
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public User getUsername() {
        return username;
    }

    public void setUsername(User username) {
        this.username = username;
    }

    public Date getSendingTime() {
        return sendingTime;
    }

    public void setSendingTime(Date sendingTime) {
        this.sendingTime = sendingTime;
    }

    public Date getOperationTime() {
        return operationTime;
    }

    public void setOperationTime(Date operationTime) {
        this.operationTime = operationTime;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}
