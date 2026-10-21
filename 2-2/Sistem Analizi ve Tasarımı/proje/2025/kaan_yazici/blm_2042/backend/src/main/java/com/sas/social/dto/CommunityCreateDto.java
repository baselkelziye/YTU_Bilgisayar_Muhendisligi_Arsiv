package com.sas.social.dto;

import org.springframework.web.multipart.MultipartFile;

public record CommunityCreateDto(		
		String communityName,
		String communityDescription,
		MultipartFile communityPhoto) {

}
