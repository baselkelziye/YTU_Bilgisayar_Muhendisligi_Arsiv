package com.sas.social.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sas.social.dto.UserProfileDto;
import com.sas.social.entity.UserPrincipal;
import com.sas.social.service.SearchService;

@RestController
@RequestMapping("/search")
public class SearchController {

	@Autowired
	private SearchService searchService;
	
	@GetMapping("{searchTerm}")
	public List<UserProfileDto> getSearchResults(@PathVariable String searchTerm,
			@AuthenticationPrincipal UserPrincipal userDetails) {
		
		return searchService.getSearchResults(searchTerm, userDetails.getUsername(), 6);
	}
}
