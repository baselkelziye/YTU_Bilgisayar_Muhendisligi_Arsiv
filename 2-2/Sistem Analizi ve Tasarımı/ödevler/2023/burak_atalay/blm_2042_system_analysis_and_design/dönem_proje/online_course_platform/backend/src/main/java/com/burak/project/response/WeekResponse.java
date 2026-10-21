package com.burak.project.response;

import com.burak.project.model.Week;
import lombok.Data;

@Data
public class WeekResponse {
    private Long id;
    private String reading;

    public WeekResponse(Week week){
        id = week.getId();
        reading = week.getReading();
    }
}
