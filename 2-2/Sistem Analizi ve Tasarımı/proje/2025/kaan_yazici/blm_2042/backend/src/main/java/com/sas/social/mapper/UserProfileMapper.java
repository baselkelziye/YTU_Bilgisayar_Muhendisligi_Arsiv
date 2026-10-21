package com.sas.social.mapper;

import java.util.function.Function;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.sas.social.dto.UserProfileDto;
import com.sas.social.entity.User;
import com.sas.social.repository.UserRepository;

@Component
public class UserProfileMapper 
	implements Function<User, UserProfileDto> {
	
	@Autowired 
	private UserRepository userRepository;
	
	@Override
	public UserProfileDto apply(User u) {
		Integer postNumber = userRepository.getPostNumber( u.getUserId() );
		Integer followerNumber = userRepository.getNumberOfFollowers( u.getUserId() );
		Integer followingNumber = userRepository.getNumberOfFollowing( u.getUserId() ); 
		
		Integer profilePhotoId =  null; 
		Integer bannerPhotoId = null;
		
		if( u.getProfilePhoto() != null ) 
			profilePhotoId = u.getProfilePhoto().getMediaId();
		if( u.getBannerPhoto() != null )
			bannerPhotoId = u.getBannerPhoto().getMediaId();
		
		return new UserProfileDto(
				u.getUserId(),
				u.getVisibleName(),
				u.getUsername(),
				u.getBio(),
				
				profilePhotoId,
				bannerPhotoId,		
				
				postNumber,
				followerNumber,
				followingNumber
				);
	}
	
//	public User toEntity(UserProfileDto userDto) {
//		return new User(
//				userDto.userId(),
//				userDto.visibleName(),
//				userDto.username(),
//				userDto.profilePhoto(),
//				userDto.bannerPhoto()
//	); }

}
