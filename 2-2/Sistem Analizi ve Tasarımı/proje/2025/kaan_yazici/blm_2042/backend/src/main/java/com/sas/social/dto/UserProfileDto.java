package com.sas.social.dto;

public record UserProfileDto (
		Integer userId,
		String visibleName,
		String username,
		String bio,
		
		Integer profilePhotoId,
		Integer bannerPhotoId,
		
		Integer postNumber,
		Integer followerNumber,
		Integer followingNumber
		
	) {

	
}
