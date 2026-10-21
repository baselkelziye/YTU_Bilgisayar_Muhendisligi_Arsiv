package com.burak.project.service;

import com.burak.project.model.Enrollment;
import com.burak.project.model.UserProgress;
import com.burak.project.model.Week;
import com.burak.project.repository.IUserProgressRepository;
import com.burak.project.request.UserProgressRequest;
import jakarta.persistence.EntityNotFoundException;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserProgressService {
    private final IUserProgressRepository userProgressRepository;

    public UserProgressService(IUserProgressRepository userProgressRepository){
        this.userProgressRepository = userProgressRepository;
    }

    public List<UserProgress> createUserProgresses(Enrollment enrollment, List<Week> weeks){
        if(weeks == null) throw new EntityNotFoundException("weeks of a course cannot be null");
        List<UserProgress> userProgresses =  weeks.stream()
                .map(week -> UserProgress.builder()
                        .status(false)
                        .enrollment(enrollment)
                        .week(week)
                        .build())
                .collect(Collectors.toList());
        return userProgressRepository.saveAll(userProgresses);
    }

    @Transactional
    public void updateUserProgresses(List<UserProgressRequest> userProgressRequests) {
        if (userProgressRequests != null) {
            for (UserProgressRequest userProgressRequest : userProgressRequests) {
                if (userProgressRequest.getId() != null) {
                    UserProgress userProgress = userProgressRepository.findById(userProgressRequest.getId())
                            .orElseThrow(() -> new EntityNotFoundException(
                                    "UserProgress not found with ID: " + userProgressRequest.getId()));
                    userProgress.setStatus(userProgressRequest.getStatus());
                    userProgressRepository.save(userProgress);
                }
            }
        }
    }

    public UserProgress updateUserProgress(Long userProgressId, UserProgressRequest userProgressRequest) {
        UserProgress userProgress = userProgressRepository.findById(userProgressId)
                .orElseThrow(() -> new EntityNotFoundException(
                        "UserProgress not found with ID: " + userProgressRequest.getId()));
        userProgress.setStatus(userProgressRequest.getStatus());
        return userProgressRepository.save(userProgress);
    }
}
