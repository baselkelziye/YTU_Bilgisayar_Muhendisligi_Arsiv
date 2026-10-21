package com.sas.social.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.sas.social.entity.UserCommunity;
import com.sas.social.entity.UserCommunity.UserCommunityId;

public interface UserCommunityRepository 
	extends JpaRepository<UserCommunity, UserCommunityId>{

}
