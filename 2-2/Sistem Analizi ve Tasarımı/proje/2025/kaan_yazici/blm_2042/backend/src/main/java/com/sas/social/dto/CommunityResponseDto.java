package com.sas.social.dto;

public record CommunityResponseDto(
		String communityName,
		String communityDescription,
		Integer mediaId,
		Boolean isJoined) {

}
