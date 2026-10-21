package com.burak.project.repository;

import com.burak.project.model.Student;
import com.burak.project.model.Token;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ITokenRepository extends JpaRepository<Token, Long> {

    Token findByUserId(Long userId);
}
