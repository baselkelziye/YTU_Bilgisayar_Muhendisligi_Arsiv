package com.sas.social.repository;

import java.util.Set;

import org.springframework.data.jpa.repository.JpaRepository;

import com.sas.social.entity.Category;

public interface CategoryRepository extends JpaRepository<Category, Integer>{
	
	Set<Category> findAllByCategoryNameIn(Set<String> categoryNames);
}
