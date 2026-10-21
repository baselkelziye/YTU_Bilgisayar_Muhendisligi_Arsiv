package com.burak.project.repository;

import com.burak.project.model.Enrollment;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface IEnrollmentRepository extends JpaRepository<Enrollment, Long> {
    List<Enrollment> findByStudentId(Long studentId);

    List<Enrollment> findByCourseId(Long courseId);

    @Query("SELECT e FROM Enrollment e WHERE " +
            "(:studentId = e.student.id) AND" +
            " (e.course.id = :courseId)")
    Enrollment findByForeignKeys(Long studentId, Long courseId);
}
