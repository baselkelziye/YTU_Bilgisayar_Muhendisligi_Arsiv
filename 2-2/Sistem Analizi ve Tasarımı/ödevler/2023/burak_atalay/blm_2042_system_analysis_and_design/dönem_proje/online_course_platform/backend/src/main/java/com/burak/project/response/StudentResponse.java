package com.burak.project.response;

import com.burak.project.model.Student;
import lombok.Data;

@Data
public class StudentResponse {
    private Long id;
    private String username;
    private Double balance;
    private Integer enrollmentCount;

    public StudentResponse(Student student){
        id = student.getId();
        username = student.getUsername();
        balance = student.getBalance();
        enrollmentCount = student.getEnrollments().size();
    }
}
