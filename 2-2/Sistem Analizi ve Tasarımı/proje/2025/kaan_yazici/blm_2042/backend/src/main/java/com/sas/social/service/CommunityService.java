package com.sas.social.service;

import java.io.IOException;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import com.sas.social.dto.CommunityCreateDto;
import com.sas.social.dto.CommunityResponseDto;
import com.sas.social.dto.PostCreateDto;
import com.sas.social.dto.PostResponseDto;
import com.sas.social.entity.Community;
import com.sas.social.entity.CommunityPost;
import com.sas.social.entity.Post;
import com.sas.social.entity.User;
import com.sas.social.entity.UserCommunity;
import com.sas.social.mapper.MediaFactory;
import com.sas.social.mapper.PostMapper;
import com.sas.social.repository.CommunityPostRepository;
import com.sas.social.repository.CommunityRepository;
import com.sas.social.repository.MediaRepository;
import com.sas.social.repository.PostRepository;
import com.sas.social.repository.UserCommunityRepository;
import com.sas.social.repository.UserRepository;

import jakarta.transaction.Transactional;

@Service
public class CommunityService {
	
	private CommunityRepository communityRepository;
	private CommunityPostRepository communityPostRepository;
	private PostRepository postRepository;
	private MediaRepository mediaRepository;
	private UserRepository userRepository;
	private UserCommunityRepository userCommunityRepo;
	private PostMapper postMapper;
	
	@Autowired
	public CommunityService(CommunityRepository communityRepository,
				CommunityPostRepository communityPostRepository,
				MediaRepository mediaRepository,
				PostRepository postRepository,
				UserRepository userRepository,
				UserCommunityRepository userCommunityRepo,
				PostMapper postMapper) {
		
		this.communityRepository = communityRepository;
		this.communityPostRepository = communityPostRepository;
		this.postRepository = postRepository;
		this.mediaRepository = mediaRepository;
		this.userRepository = userRepository;
		this.userCommunityRepo = userCommunityRepo;
		this.postMapper = postMapper;
	}

	@Transactional
	public ResponseEntity<?> createCommunity(CommunityCreateDto dto, String username) throws IOException {
		
		boolean nameTaken = communityRepository.existsByCommunityName(dto.communityName());
		
	    if (nameTaken) {
	        return ResponseEntity
	            .status(HttpStatus.CONFLICT)
	            .body("Community name is already taken.");
	    }
	    
	    User user = userRepository.findByUsername(username).get();
	    
	    Community community = new Community(
			dto.communityName(),
			dto.communityDescription(),
			MediaFactory.fromMultipartFile( dto.communityPhoto() )
			);

	    mediaRepository.save( community.getMedia() );
		communityRepository.save(community);
		
		UserCommunity userCommunity = new UserCommunity(user, community, "ADMIN");
		userCommunityRepo.save( userCommunity );
		
		return ResponseEntity.ok().build();
	}
	
	public List<CommunityResponseDto> getAllCommunities(String username) {
		User user = userRepository.findByUsername(username).get();
		
		Set<Integer> communities = user.getParticipatedCommunities()
									.stream()
									.map(u -> u.getId().getCommunityId())
									.collect( Collectors.toSet() );
		
		return communityRepository.findAll()
				.stream()
				.map(u -> new CommunityResponseDto(
							u.getCommunityName(),
							u.getCommunityDescription(),
							u.getMedia() != null ? u.getMedia().getMediaId() : null,
							communities.contains( u.getCommunityId() )
						)
					)
				.toList();
	}
	
	public void joinCommunity(String username, String communityName) {
		
		User user = userRepository.findByUsername(username).get();
		
		Community community = communityRepository
					.findByCommunityName(communityName).get();
		
		UserCommunity userCommunity = new UserCommunity(user, community, "MEMBER");
		
		userCommunityRepo.save( userCommunity );
	}
	
	@Transactional
	public void createCommunityPost(PostCreateDto postDto,
			String communityName) {
		Community community = communityRepository
				.findByCommunityName( communityName ).get();
		
		Post post = postMapper.map( postDto );
		CommunityPost communityPost = new CommunityPost(post, community);
		
		// persist order is important!
		if( post.getPostImage() != null)
			mediaRepository.save( post.getPostImage() );
		postRepository.save(post);
		communityPostRepository.save( communityPost );
	}
 
	public Page<PostResponseDto> getCommunityPosts(Integer viewerId, 
				String communityName, Pageable pageable) {
		Community community = communityRepository
				.findByCommunityName( communityName ).get();
		
		Page<Post> posts = postRepository
					.getCommunityPosts(community.getCommunityId(), pageable);
		
		User user = userRepository.findById( viewerId ).get();
		Set<User> blockedUsers = user.getBlockedUsers(); 
		
		posts.stream().filter( post -> !blockedUsers.contains( post.getUser() ));
		return posts.map(p -> postMapper.map(p, viewerId));
	}
}
