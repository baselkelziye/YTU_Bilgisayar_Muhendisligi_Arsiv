package com.burak.project.service;

import com.burak.project.model.Course;
import com.burak.project.model.Week;
import com.burak.project.repository.IWeekRepository;
import com.burak.project.request.WeekRequest;
import jakarta.persistence.EntityNotFoundException;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class WeekService {
    private final IWeekRepository weekRepository;

    public WeekService(IWeekRepository weekRepository){
        this.weekRepository = weekRepository;
    }

    public List<Week> createWeeks(Course course, List<WeekRequest> weekRequests){
        List<Week> weeks = weekRequests.stream()
                .map(weekRequest -> Week.builder()
                        .course(course)
                        .reading(weekRequest.getReading())
                        .build())
                .collect(Collectors.toList());
        return weekRepository.saveAll(weeks);
    }

    @Transactional
    public void updateWeeks(List<WeekRequest> weekRequests) {
        if (weekRequests != null) {
            for (WeekRequest weekRequest : weekRequests) {
                if (weekRequest.getId() != null) {
                    Week week = weekRepository.findById(weekRequest.getId())
                            .orElseThrow(() -> new EntityNotFoundException("Week not found with ID: " + weekRequest.getId()));
                    week.setReading(weekRequest.getReading());
                    weekRepository.save(week);
                }
            }
        }
    }

    public Week updateWeek(Long weekId, WeekRequest weekRequest) {
        Week week = weekRepository.findById(weekId)
                .orElseThrow(() -> new EntityNotFoundException("Week not found with ID: " + weekRequest.getId()));
        week.setReading(weekRequest.getReading());
        return weekRepository.save(week);
    }
}
