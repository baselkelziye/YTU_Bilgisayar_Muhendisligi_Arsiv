package com.burak.project.response;

import com.burak.project.model.Enrollment;
import lombok.Data;

import java.time.LocalDate;
import java.util.List;

@Data
public class EnrollmentResponse {
    private Long id;
    private Long studentId;
    private Long courseId;
    private LocalDate enrollmentDate;
    private List<UserProgressResponse> userProgresses;

    public EnrollmentResponse(Enrollment enrollment){
        id = enrollment.getId();
        studentId = enrollment.getStudent().getId();
        courseId = enrollment.getCourse().getId();
        enrollmentDate = enrollment.getEnrollmentDate();
        userProgresses = enrollment.getUserProgresses().stream().map(UserProgressResponse::new).
                toList();
    }
}
