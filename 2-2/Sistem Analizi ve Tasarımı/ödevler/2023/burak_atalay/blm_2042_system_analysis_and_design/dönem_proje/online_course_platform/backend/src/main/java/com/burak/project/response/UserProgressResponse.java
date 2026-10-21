package com.burak.project.response;

import com.burak.project.model.UserProgress;
import lombok.Data;

@Data
public class UserProgressResponse {
    private Long id;
    private Long enrollmentId;
    private WeekResponse week;
    private Boolean status;

    public UserProgressResponse(UserProgress userProgress){
        id = userProgress.getId();
        enrollmentId = userProgress.getEnrollment().getId();
        week = new WeekResponse(userProgress.getWeek());
        status = userProgress.getStatus();
    }
}
