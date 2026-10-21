package com.sas.social.mapper;

import java.util.function.Function;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

import com.sas.social.dto.UserRegisterDto;
import com.sas.social.entity.User;
import com.sas.social.repository.CategoryRepository;

@Component
public class UserRegisterMapper 
	implements Function<User, UserRegisterDto>{

	@Autowired
    CategoryRepository categoryRepository;

	@Autowired
	private PasswordEncoder encoder;
	
	@Override
	public UserRegisterDto apply(User user) {
		return new UserRegisterDto(
				user.getVisibleName(),
				user.getUsername(),
				user.getEmail(),
				encoder.encode( user.getPassword() ),
				user.getUserCategories()
						.stream()
						.map(c -> c.getCategoryName() )
						.collect( Collectors.toSet() ) 
				);
	}

	public User ToEntity(UserRegisterDto registerDto) {

		return new User(
				registerDto.visibleName(),
				registerDto.username(),
				registerDto.email(),
				encoder.encode( registerDto.password() ),
				categoryRepository.findAllByCategoryNameIn(
						registerDto.userCategories())
		);
	}
	
}
