package com.burak.project.request;

import lombok.Data;

import java.util.List;

@Data
public class CourseRequest {
    private String title;
    private String description;
    private Long instructorId;
    private Double price;
    private List<WeekRequest> weeks;

}
