package com.burak.project.repository;

import com.burak.project.model.Week;
import org.springframework.data.jpa.repository.JpaRepository;

public interface IWeekRepository extends JpaRepository<Week, Long> {
}
