package com.sas.social.dto;

import java.util.Set;

import org.springframework.web.multipart.MultipartFile;

public record PostCreateDto(
		String username,
		String title,
		MultipartFile postImage,
		Boolean homepageVisible,
		Set<String> postCategories) {
}
