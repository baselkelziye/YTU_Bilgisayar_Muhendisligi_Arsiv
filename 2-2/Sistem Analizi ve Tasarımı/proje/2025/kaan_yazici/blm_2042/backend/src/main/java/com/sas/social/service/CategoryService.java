package com.sas.social.service;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sas.social.entity.Category;
import com.sas.social.repository.CategoryRepository;

@Service
public class CategoryService {

	private CategoryRepository categoryRepository;

	@Autowired
	public CategoryService(CategoryRepository categoryRepository) {
		this.categoryRepository = categoryRepository;
	}
	
	public Optional<Category> getCategory(Integer id) {
		return categoryRepository.findById(id);
	}
	
	public List<Category> getAllCategories() {
		return categoryRepository.findAll();
	}
}
