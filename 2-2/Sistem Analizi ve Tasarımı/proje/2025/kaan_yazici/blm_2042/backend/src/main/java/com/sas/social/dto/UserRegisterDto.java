package com.sas.social.dto;

import java.util.Set;

public record UserRegisterDto (
		String visibleName,
		String username,
		String email,
		String password,
		Set<String> userCategories
		) {

}
