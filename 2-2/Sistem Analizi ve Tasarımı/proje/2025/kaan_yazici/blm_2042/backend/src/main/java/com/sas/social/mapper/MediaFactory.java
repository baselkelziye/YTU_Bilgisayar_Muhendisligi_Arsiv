package com.sas.social.mapper;

import java.io.IOException;

import org.springframework.web.multipart.MultipartFile;

import com.sas.social.entity.Media;

public class MediaFactory {

    public static Media fromMultipartFile(MultipartFile file) throws IOException {
    	if(file == null)
    		return null;
    	
        Media media = new Media();
        media.setImageName(file.getOriginalFilename());
        media.setImageType(file.getContentType());
        media.setImageByte(file.getBytes());
        return media;
    }
    
}


