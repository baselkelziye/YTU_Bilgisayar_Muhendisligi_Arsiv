package com.burak.project.controller;

import com.burak.project.model.Course;
import com.burak.project.request.CourseRequest;
import com.burak.project.request.WeekRequest;
import com.burak.project.response.CourseResponse;
import com.burak.project.service.CourseService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/courses")

public class CourseController {
    private final CourseService courseService;

    public CourseController(CourseService courseService){
        this.courseService = courseService;
    }

    @GetMapping
    public List<CourseResponse> getAllCourses(@RequestParam(required = false) Long instructorId){
        List<Course> courses = courseService.getAllCourses(instructorId);
        return (courses == null) ? null : courses.stream().map(CourseResponse::new).toList();
    }

    @GetMapping("/{courseId}")
    public CourseResponse getCourseById(@PathVariable Long courseId){
        return new CourseResponse(courseService.getCourseById(courseId));
    }

    @PostMapping
    public ResponseEntity<Void> createCourse(@RequestBody CourseRequest courseRequest){
        System.out.println(courseRequest.toString());
        return (courseService.createCourse(courseRequest) != null) ? new ResponseEntity<>(HttpStatus.CREATED) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/{courseId}")
    public ResponseEntity<Void> updateCourse(@RequestBody CourseRequest courseRequest,
                                             @PathVariable Long courseId){
        return (courseService.updateCourse(courseRequest, courseId) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/weeks/{weekId}")
    public ResponseEntity<Void> updateWeek(@PathVariable Long weekId, @RequestBody WeekRequest weekRequest){
        return (courseService.updateWeek(weekId, weekRequest) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @DeleteMapping("/{courseId}")
    public void deleteCourse(@PathVariable Long courseId){
        courseService.deleteCourse(courseId);
    }
}
