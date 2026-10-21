package com.burak.project.repository;

import com.burak.project.model.UserProgress;
import org.springframework.data.jpa.repository.JpaRepository;

public interface IUserProgressRepository extends JpaRepository<UserProgress, Long> {
}
