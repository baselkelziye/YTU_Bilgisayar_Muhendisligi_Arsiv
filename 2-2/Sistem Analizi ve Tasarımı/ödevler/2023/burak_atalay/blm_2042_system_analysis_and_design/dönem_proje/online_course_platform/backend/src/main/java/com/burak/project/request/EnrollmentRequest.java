package com.burak.project.request;

import lombok.Data;

import java.util.List;

@Data
public class EnrollmentRequest {
    private Long studentId;
    private Long courseId;
    private List<UserProgressRequest> userProgresses;
}
