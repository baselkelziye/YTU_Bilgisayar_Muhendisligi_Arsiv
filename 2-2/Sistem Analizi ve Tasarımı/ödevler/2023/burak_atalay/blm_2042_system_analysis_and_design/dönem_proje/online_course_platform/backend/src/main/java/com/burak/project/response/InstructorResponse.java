package com.burak.project.response;

import com.burak.project.model.Instructor;
import lombok.Data;

@Data
public class InstructorResponse {
    private Long id;
    private String username;
    private String biography;
    private Integer courseCount;

    public InstructorResponse(Instructor instructor){
        id = instructor.getId();
        username = instructor.getUsername();
        biography = instructor.getBiography();
        courseCount = instructor.getCourses().size();
    }
}
