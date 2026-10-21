package com.burak.project.repository;

import com.burak.project.model.Course;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface ICourseRepository extends JpaRepository<Course, Long> {
    List<Course> findByInstructorId(Long InstructorId);
}
