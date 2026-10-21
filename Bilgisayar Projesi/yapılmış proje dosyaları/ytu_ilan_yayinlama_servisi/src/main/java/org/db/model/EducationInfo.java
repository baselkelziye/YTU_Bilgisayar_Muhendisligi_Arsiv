package org.db.model;

import javax.persistence.*;
import java.io.Serializable;

/**
 * Created by mgunes on 27.01.2017.
 */
@Entity
@Table(name = "education_info")
public class EducationInfo implements Serializable {
    @Id
    @Column(name = "id")
    @GeneratedValue(strategy=GenerationType.AUTO)
    private int id;

    @ManyToOne
    @JoinColumn(name = "student")
    private Student student;

    @Column(name = "school", nullable = false)
    private String school;

    @Column(name = "department")
    private String department;

    @Column(name = "start_date", nullable = false)
    private int startDate;

    @Column(name = "end_date")
    private int endDate;

    @Column(name = "degree")
    private String degree;

    public EducationInfo() {
        super();
    }

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

    public String getSchool() {
        return school;
    }

    public void setSchool(String school) {
        this.school = school;
    }

    public int getStartDate() {
        return startDate;
    }

    public void setStartDate(int startDate) {
        this.startDate = startDate;
    }

    public int getEndDate() {
        return endDate;
    }

    public void setEndDate(int endDate) {
        this.endDate = endDate;
    }

    public String getDegree() {
        return degree;
    }

    public void setDegree(String degree) {
        this.degree = degree;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }
}
