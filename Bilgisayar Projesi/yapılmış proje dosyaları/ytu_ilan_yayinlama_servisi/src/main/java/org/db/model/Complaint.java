package org.db.model;

import javax.persistence.*;
import java.io.Serializable;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 11.12.2016.
 */

@Entity
@Table(name = "complaint")
public class Complaint implements Serializable {
    @Id
    @GeneratedValue(strategy=GenerationType.AUTO)
    @Column(name = "id")
    private int id;

    @ManyToOne
    @JoinColumn(name = "student")
    private Student student;

    @ManyToOne
    @JoinColumn(name = "announcement")
    private Announcement announcement;

    @Column(name = "description")
    private String description;

    @Column(name = "complaint_time")
    private Date complaintTime;

    @Column(name = "result")
    private String result;

    @Column(name = "result_time")
    private Date resultTime;

    @Column(name = "result_reply")
    private String resultReply;

    public Complaint() {
        super();
    }

    //getter-setter
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }

    public Announcement getAnnouncement() {
        return announcement;
    }

    public void setAnnouncement(Announcement announcement) {
        this.announcement = announcement;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Date getComplaintTime() {
        return complaintTime;
    }

    public void setComplaintTime(Date complaintTime) {
        this.complaintTime = complaintTime;
    }

    public String getResult() {
        return result;
    }

    public void setResult(String result) {
        this.result = result;
    }

    public Date getResultTime() {
        return resultTime;
    }

    public void setResultTime(Date resultTime) {
        this.resultTime = resultTime;
    }

    public String getResultReply() {
        return resultReply;
    }

    public void setResultReply(String resultReply) {
        this.resultReply = resultReply;
    }
}
