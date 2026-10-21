package com.sas.social.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sas.social.entity.Category;
import com.sas.social.entity.User;
import com.sas.social.service.CategoryService;


@RestController
@RequestMapping("/category")
public class CategoryController {

	private CategoryService categoryService;
	
	@Autowired
	public CategoryController(CategoryService categoryService) {
		this.categoryService = categoryService;
	}
	
	@GetMapping("/all")
	public List<Category> getAll() {
		return categoryService.getAllCategories();
	}
	
	@GetMapping("/{id}")
    public Category getById(@PathVariable Integer id) {
        return categoryService.getCategory(id).orElse(new Category());
    } 

}