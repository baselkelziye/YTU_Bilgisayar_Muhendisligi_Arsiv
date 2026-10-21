package com.sas.social.service;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;

import com.sas.social.dto.UserProfileDto;
import com.sas.social.entity.User;
import com.sas.social.mapper.UserProfileMapper;
import com.sas.social.repository.UserRepository;

@Service
public class SearchService {

	@Autowired
	private UserRepository userRepository;
	
	@Autowired
	private UserProfileMapper userMapper;
	
	public List<UserProfileDto> getSearchResults(String searchTerm, String viewerUsername, int totalLimit) {
		
		User currentUser = userRepository.findByUsername(viewerUsername).get();
		
	    Set<User> followedUsers = currentUser.getFollows();
	    Set<User> blockedUsers = currentUser.getBlockedUsers();
	    
	    // Search from followed users (max 3)
	    List<User> followedResults = userRepository.profileSearchFollowedUsers(
	        searchTerm,
	        followedUsers,
	        PageRequest.of(0, 3)
	    );

	    // Search others
	    Set<User> excluded = new HashSet<>(followedResults);
	    excluded.addAll(blockedUsers);
	    excluded.add(currentUser);

	    int remainingLimit = totalLimit - followedResults.size();
	    List<User> otherResults = remainingLimit > 0
	        ? userRepository.profileSearchOtherUsers(searchTerm, excluded, PageRequest.of(0, remainingLimit))
	        : Collections.emptyList();

	    // Merge and return
	    List<User> combined = new ArrayList<>(followedResults);
	    combined.addAll(otherResults);
	    
	    return combined.stream().map(userMapper).toList();
	}
}
