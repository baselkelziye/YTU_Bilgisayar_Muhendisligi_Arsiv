package com.sas.social.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.authentication.dao.DaoAuthenticationProvider;
import org.springframework.security.config.Customizer;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.authentication.AuthenticationFailureHandler;
import org.springframework.security.web.authentication.AuthenticationSuccessHandler;

import jakarta.servlet.http.HttpServletResponse;

@Configuration
@EnableWebSecurity
public class SecurityConfig {

	@Autowired
	UserDetailsService userDetailsService;
	
//	@Bean
//	public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
//	    return http
//	            .csrf(csrf -> csrf.disable())
//	            .authorizeHttpRequests(auth -> auth
//	                    .requestMatchers("/signup", "/login").permitAll()
//	                    .anyRequest().authenticated()
//	            )
//	            .formLogin(form -> form
//	                    .loginPage("/login")            // custom login page
//	                    .defaultSuccessUrl("/home", true) // redirect after successful login
//	                    .permitAll()
//	            )
//	            .logout(logout -> logout
//	                    .logoutUrl("/logout")            // logout URL
//	                    .logoutSuccessUrl("/login")      // redirect after logout
//	                    .permitAll()
//	            )
//	            .build();
//	}
    
    
//	@Bean
//	public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
//	    http
//	        .csrf(csrf -> csrf.disable())
//	        .cors(Customizer.withDefaults())
//	        .authorizeHttpRequests(auth -> auth
//	                .requestMatchers("/signin", "/signup").permitAll()
//	                .anyRequest().authenticated()
//	        )
//	        .formLogin(form -> form
//	        .loginProcessingUrl("/signin")
//	        .successHandler(successHandler())
//	        .failureHandler(failureHandler())
//	        .permitAll()
//	        )
//	            .logout(logout -> logout
//	                    .logoutUrl("/logout")
//	                    .logoutSuccessHandler((request, response, authentication) -> {
//	                        response.setStatus(HttpServletResponse.SC_OK);
//	                        response.setContentType("application/json");
//	                        response.setHeader("Set-Cookie", "JSESSIONID=; HttpOnly; Path=/ Max-Age=0");
//	                        response.getWriter().write("{\"message\":\"Logged out successfully\"}");
//	                    })
//	                    .deleteCookies("JSESSIONID")
//	                    .invalidateHttpSession(true)
//	                    .permitAll()
//	            );
//	
//	    return http.build();
//	}

	@Bean
	public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
	    http
	        .csrf(csrf -> csrf.disable())
	        .cors(Customizer.withDefaults())
				.authorizeHttpRequests(auth -> auth
						.requestMatchers(HttpMethod.POST, "/signup", "/user/signup").permitAll()
						.requestMatchers("/signin").permitAll()
						.anyRequest().authenticated()
				)
	        .formLogin(form -> form
	            .loginProcessingUrl("/signin")
	            .successHandler(successHandler())
	            .failureHandler(failureHandler())
	            .permitAll()
	        )
//			.formLogin(Customizer.withDefaults())
//			.httpBasic(Customizer.withDefaults())
	        .logout(logout -> logout
	                .logoutUrl("/logout")
	                .logoutSuccessHandler((request, response, authentication) -> {
	                    response.setStatus(HttpServletResponse.SC_OK);
	                    response.setContentType("application/json");
	                    response.setHeader("Set-Cookie", "JSESSIONID=; HttpOnly; Path=/; Max-Age=0");
	                    response.getWriter().write("{\"message\":\"Logged out successfully\"}");
	                })
	                .deleteCookies("JSESSIONID")
	                .invalidateHttpSession(true)
	                .permitAll()
	        );

	    return http.build();
	}

	@Bean
	public DaoAuthenticationProvider authenticationProvider() {
	    var provider = new DaoAuthenticationProvider();
	    provider.setUserDetailsService(userDetailsService);
	    provider.setPasswordEncoder(passwordEncoder());
	    return provider;
	}
	
	@Bean
	public AuthenticationSuccessHandler successHandler() {
	    return (request, response, authentication) -> {
	        response.setStatus(HttpServletResponse.SC_OK);
	        response.setContentType("application/json");
	        response.getWriter().write("{\"message\":\"Login successful\"}");
	    };
	}
	
	@Bean
	public AuthenticationFailureHandler failureHandler() {
	    return (request, response, exception) -> {
	        response.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
	        response.setContentType("application/json");
	        response.getWriter().write("{\"error\":\"Login failed\"}");
	    };
	}
	
	@Bean
	public PasswordEncoder passwordEncoder() {
	    return new BCryptPasswordEncoder(12);
	}

}
