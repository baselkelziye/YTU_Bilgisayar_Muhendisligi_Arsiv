package com.burak.project.repository;

import com.burak.project.model.Instructor;
import org.springframework.data.jpa.repository.JpaRepository;

public interface IInstructorRepository extends JpaRepository<Instructor, Long> {
    Instructor findByUsername(String username);
}
