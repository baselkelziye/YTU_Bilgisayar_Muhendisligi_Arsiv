package org.db.model;

import javax.persistence.*;
import java.io.Serializable;
import java.util.Date;

/**
 * Created by mgunes on 21.01.2017.
 */
@Entity
@Table(name = "complaint_report")
public class ComplaintReport implements Serializable {
    @Id
    @GeneratedValue(strategy=GenerationType.AUTO)
    @Column(name = "id")
    private int id;

    @ManyToOne
    @JoinColumn(name = "announcement")
    private Announcement announcement;

    @Column(name = "operation_date", nullable = false)
    private Date operationDate;

    @Column(name = "description", nullable = false)
    private String description;

    @Column(name = "current_state")
    private String currentState;

    public ComplaintReport() {
        super();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Announcement getAnnouncement() {
        return announcement;
    }

    public void setAnnouncement(Announcement announcement) {
        this.announcement = announcement;
    }

    public Date getOperationDate() {
        return operationDate;
    }

    public void setOperationDate(Date operationDate) {
        this.operationDate = operationDate;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getCurrentState() {
        return currentState;
    }

    public void setCurrentState(String currentState) {
        this.currentState = currentState;
    }
}
