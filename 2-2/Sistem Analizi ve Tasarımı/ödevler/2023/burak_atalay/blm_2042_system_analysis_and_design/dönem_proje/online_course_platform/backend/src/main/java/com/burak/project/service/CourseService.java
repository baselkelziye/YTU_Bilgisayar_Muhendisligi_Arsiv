package com.burak.project.service;

import com.burak.project.model.Course;
import com.burak.project.model.Instructor;
import com.burak.project.model.Week;
import com.burak.project.repository.ICourseRepository;
import com.burak.project.request.CourseRequest;
import com.burak.project.request.WeekRequest;
import jakarta.persistence.EntityNotFoundException;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class CourseService {
    private final ICourseRepository courseRepository;
    private final InstructorService instructorService;
    private final WeekService weekService;

    public CourseService(ICourseRepository courseRepository, InstructorService instructorService,
                         WeekService weekService) {
        this.courseRepository = courseRepository;
        this.instructorService = instructorService;
        this.weekService = weekService;
    }

    public List<Course> getAllCourses(Long instructorId){
        return (instructorId != null) ? courseRepository.findByInstructorId(instructorId) :
                courseRepository.findAll();
    }

    public Course getCourseById(Long courseId) {
        return courseRepository.findById(courseId).orElseThrow(() -> new EntityNotFoundException("Invalid courseId"));
    }

    @Transactional
    public Course createCourse(CourseRequest courseRequest) {
        Instructor instructor = instructorService.getInstructorById(
                courseRequest.getInstructorId());
        if(courseRequest.getPrice() < 0.0) throw new EntityNotFoundException(
                "Course price cannot be less than 0");
        Course course = Course.builder().
                title(courseRequest.getTitle()).
                description(courseRequest.getDescription()).
                duration(courseRequest.getWeeks().size()).
                price(courseRequest.getPrice()).
                instructor(instructor).
                build();
        course = courseRepository.save(course);
        List<Week> weeks = weekService.createWeeks(course, courseRequest.getWeeks());
        course.setWeeks(weeks);
        return course;
    }

    @Transactional
    public Course updateCourse(CourseRequest courseRequest, Long courseId) {
        Optional<Course> temp = courseRepository.findById(courseId);
        if(temp.isEmpty()) throw new EntityNotFoundException("Invalid courseId");
        Course foundCourse = temp.get();
        foundCourse.setTitle(courseRequest.getTitle());
        foundCourse.setDescription(courseRequest.getDescription());
        foundCourse.setPrice(courseRequest.getPrice());
        weekService.updateWeeks(courseRequest.getWeeks());
        return courseRepository.save(foundCourse);
    }

    public Week updateWeek(Long weekId, WeekRequest weekRequest){
        return weekService.updateWeek(weekId, weekRequest);
    }

    public void deleteCourse(Long courseId) {
        courseRepository.deleteById(courseId);
    }
}
