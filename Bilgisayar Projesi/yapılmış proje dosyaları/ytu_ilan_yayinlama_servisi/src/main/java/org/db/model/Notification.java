package org.db.model;

import javax.persistence.*;
import java.io.Serializable;
import java.util.Date;

/**
 * Created by mgunes on 29.01.2017.
 */
@Entity
@Table(name = "notification")
public class Notification implements Serializable {
    @Id
    @GeneratedValue(strategy=GenerationType.AUTO)
    @Column(name = "id")
    private int id;

    @Column(name = "trigger_factor", nullable = false)
    private String triggerFactor;

    @ManyToOne
    @JoinColumn(name = "trigger_target", nullable = false)
    private User triggerTarget;

    @Column(name = "description", nullable = false)
    private String description;

    @Column(name = "trigger_date", nullable = false)
    private Date triggerDate;

    @Column(name = "state", nullable = false)
    private String state;

    public Notification() {
        super();
    }

    public Notification(String triggerFactor, User triggerTarget, String description, Date triggerDate, String state) {
        this.triggerFactor = triggerFactor;
        this.triggerTarget = triggerTarget;
        this.description = description;
        this.triggerDate = triggerDate;
        this.state = state;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTriggerFactor() {
        return triggerFactor;
    }

    public void setTriggerFactor(String triggerFactor) {
        this.triggerFactor = triggerFactor;
    }

    public User getTriggerTarget() {
        return triggerTarget;
    }

    public void setTriggerTarget(User triggerTarget) {
        this.triggerTarget = triggerTarget;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Date getTriggerDate() {
        return triggerDate;
    }

    public void setTriggerDate(Date triggerDate) {
        this.triggerDate = triggerDate;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}
