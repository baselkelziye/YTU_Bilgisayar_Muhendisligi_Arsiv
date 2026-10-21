package com.sas.social.dto;

import org.springframework.web.multipart.MultipartFile;

public record UserUpdateDto(
		String visibleName,
		String bio,
		MultipartFile profilePhoto,
		MultipartFile bannerPhoto) {

}
