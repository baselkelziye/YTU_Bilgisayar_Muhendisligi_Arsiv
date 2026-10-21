package com.burak.project.request;

import lombok.Builder;
import lombok.Data;

@Data
public class InstructorRequest {
    private String username;
    private String password;
    private String biography;
}
