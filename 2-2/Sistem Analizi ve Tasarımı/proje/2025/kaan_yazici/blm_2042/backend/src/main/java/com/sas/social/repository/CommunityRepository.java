package com.sas.social.repository;

import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;

import com.sas.social.entity.Community;

public interface CommunityRepository extends JpaRepository<Community, Integer>{

	boolean existsByCommunityName(String communityName);

	Optional<Community> findByCommunityName(String str);
}
