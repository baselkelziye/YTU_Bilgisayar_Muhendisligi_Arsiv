package com.sas.social.controller;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sas.social.entity.Media;
import com.sas.social.repository.MediaRepository;

@RestController
@RequestMapping("/media")
public class MediaController {

	@Autowired
	private MediaRepository mediaRepository;
	
	@GetMapping("/{id}")
	public ResponseEntity<byte[]> getImage(@PathVariable Integer id) {
	    Optional<Media> mediaOptional = mediaRepository.findById(id);
	    if (mediaOptional.isEmpty()) {
	        return ResponseEntity.notFound().build();
	    }

	    Media media = mediaOptional.get();
	    return ResponseEntity.ok()
	            .contentType(MediaType.parseMediaType(media.getImageType()))
	            .header( "inline; filename=\"" + media.getImageName() + "\"")
	            .body(media.getImageByte());
	}

}
