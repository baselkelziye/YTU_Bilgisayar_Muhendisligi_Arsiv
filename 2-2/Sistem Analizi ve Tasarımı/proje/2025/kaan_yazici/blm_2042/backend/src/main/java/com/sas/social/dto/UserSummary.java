package com.sas.social.dto;

// No explicit mapper for this DTO
public record UserSummary(
		Integer userId,
		String visibleName,
		String username,
		Integer profilePhotoId) {

}
