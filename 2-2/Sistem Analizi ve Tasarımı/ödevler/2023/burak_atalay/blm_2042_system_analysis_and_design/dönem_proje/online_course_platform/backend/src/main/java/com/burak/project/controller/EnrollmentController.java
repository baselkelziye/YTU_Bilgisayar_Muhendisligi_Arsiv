package com.burak.project.controller;

import com.burak.project.model.Enrollment;
import com.burak.project.request.EnrollmentRequest;
import com.burak.project.request.UserProgressRequest;
import com.burak.project.response.EnrollmentResponse;
import com.burak.project.service.EnrollmentService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/enrollments")

public class EnrollmentController {
    private final EnrollmentService enrollmentService;

    public EnrollmentController(EnrollmentService enrollmentService) {
        this.enrollmentService = enrollmentService;
    }

    @GetMapping
    public List<EnrollmentResponse> getAllEnrollments(){
        List<Enrollment> enrollments = enrollmentService.getAllEnrollments();
        return (enrollments == null) ? null : enrollments.stream().map(EnrollmentResponse::new).toList();
    }

    @GetMapping("/student/{studentId}")
    public List<EnrollmentResponse> getEnrollmentsByStudentId(@PathVariable Long studentId){
        List<Enrollment> enrollments = enrollmentService.getEnrollmentsByStudentId(studentId);
        return (enrollments == null) ? null : enrollments.stream().map(EnrollmentResponse::new).toList();
    }

    @GetMapping("/course/{courseId}")
    public List<EnrollmentResponse> getEnrollmentsByCourseId(@PathVariable Long courseId){
        List<Enrollment> enrollments = enrollmentService.getEnrollmentsByCourseId(courseId);
        return (enrollments == null) ? null : enrollments.stream().map(EnrollmentResponse::new).toList();
    }

    @GetMapping("/{enrollmentId}")
    public EnrollmentResponse getEnrollmentById(@PathVariable Long enrollmentId){
        return new EnrollmentResponse(enrollmentService.getEnrollmentById(enrollmentId));
    }

    @PostMapping
    public ResponseEntity<Void> createEnrollment(@RequestBody EnrollmentRequest enrollmentRequest){
        return (enrollmentService.createEnrollment(enrollmentRequest) != null) ? new ResponseEntity<>(HttpStatus.CREATED) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/{enrollmentId}")
    public ResponseEntity<Void> updateCourse(@RequestBody EnrollmentRequest enrollmentRequest,
                                             @PathVariable Long enrollmentId){
        return (enrollmentService.updateEnrollment(enrollmentRequest, enrollmentId) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/userProgresses/{userProgressId}")
    public ResponseEntity<Void> updateUserProgress(@PathVariable Long userProgressId, @RequestBody UserProgressRequest userProgressRequest){
        return (enrollmentService.updateUserProgress(userProgressId, userProgressRequest) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @DeleteMapping("/{enrollmentId}")
    public void deleteEnrollment(@PathVariable Long enrollmentId){
        enrollmentService.deleteEnrollment(enrollmentId);
    }

    @DeleteMapping
    public void deleteEnrollmentWithForeignKeys(@RequestParam Long studentId, @RequestParam Long courseId){
        enrollmentService.deleteEnrollmentWithForeignKeys(studentId, courseId);
    }
}
