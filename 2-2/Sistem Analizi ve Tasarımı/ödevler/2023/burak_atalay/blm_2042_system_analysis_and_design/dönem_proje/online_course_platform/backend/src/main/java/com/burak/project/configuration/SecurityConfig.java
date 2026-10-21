package com.burak.project.configuration;


import com.burak.project.enumeration.Role;
import com.burak.project.security.JwtAuthenticationFilter;
import com.burak.project.service.UserDetailsServiceImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.authentication.ProviderManager;
import org.springframework.security.authentication.dao.DaoAuthenticationProvider;
import org.springframework.security.config.annotation.method.configuration.EnableMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configurers.AbstractAuthenticationFilterConfigurer;
import org.springframework.security.config.annotation.web.configurers.AbstractHttpConfigurer;
import org.springframework.security.config.http.SessionCreationPolicy;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;
import org.springframework.web.filter.CorsFilter;

@Configuration
@EnableWebSecurity
@EnableMethodSecurity
public class SecurityConfig {
    private final JwtAuthenticationFilter jwtAuthenticationFilter;
    private final UserDetailsServiceImpl userDetailsService;

    public SecurityConfig(JwtAuthenticationFilter jwtAuthenticationFilter,
                          UserDetailsServiceImpl userDetailsService) {
        this.jwtAuthenticationFilter = jwtAuthenticationFilter;
        this.userDetailsService = userDetailsService;
    }

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity httpSecurity) throws Exception {
        return httpSecurity
                .csrf(AbstractHttpConfigurer::disable)
                .authorizeHttpRequests(req ->
                        req.requestMatchers("/auth/**")
                                .permitAll()
                                .requestMatchers(HttpMethod.GET, "/courses")
                                .permitAll()
                                .requestMatchers(HttpMethod.GET, "/instructors")
                                .permitAll()
                                .requestMatchers(HttpMethod.DELETE, "/instructors/{instructorId}")
                                .hasAnyRole(Role.ADMIN.name(), Role.INSTRUCTOR.name())
                                .requestMatchers(HttpMethod.POST, "/courses")
                                .hasAnyRole(Role.INSTRUCTOR.name())
                                .requestMatchers(HttpMethod.PUT, "/courses")
                                .hasAnyRole(Role.INSTRUCTOR.name(), Role.ADMIN.name())
                                .requestMatchers(HttpMethod.DELETE, "/courses/{courseId}")
                                .hasAnyRole(Role.INSTRUCTOR.name(), Role.ADMIN.name())
                                .requestMatchers(HttpMethod.GET, "/students/{id}")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.GET, "/students")
                                .hasAnyRole(Role.ADMIN.name())
                                .requestMatchers(HttpMethod.DELETE, "/students/{studentId}")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.GET, "/enrollments")
                                .hasAnyRole(Role.ADMIN.name())
                                .requestMatchers(HttpMethod.GET, "/enrollments/{id}")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.GET, "/enrollments/student/{studentId}")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.DELETE, "/enrollments/{enrollmentId}")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.POST, "/enrollments")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .requestMatchers(HttpMethod.PUT, "/enrollments")
                                .hasAnyRole(Role.ADMIN.name(), Role.STUDENT.name())
                                .anyRequest()
                                .authenticated()
                )
                .sessionManagement(session -> session.sessionCreationPolicy(SessionCreationPolicy.STATELESS))
                .formLogin(AbstractAuthenticationFilterConfigurer::disable)
                .addFilterBefore(corsFilter(), UsernamePasswordAuthenticationFilter.class)
                .addFilterBefore(jwtAuthenticationFilter, UsernamePasswordAuthenticationFilter.class)
                .build();
    }

    @Bean
    public AuthenticationProvider authenticationProvider() {
        DaoAuthenticationProvider authenticationProvider = new DaoAuthenticationProvider();
        authenticationProvider.setUserDetailsService(userDetailsService);
        authenticationProvider.setPasswordEncoder(passwordEncoder());
        return authenticationProvider;
    }

    @Bean
    public AuthenticationManager authenticationManager(){
        return new ProviderManager(authenticationProvider());
    }

    @Bean
    public BCryptPasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    @Bean
    public CorsFilter corsFilter() {
        org.springframework.web.cors.CorsConfiguration corsConfiguration = new org.springframework.web.cors.CorsConfiguration();
        corsConfiguration.setAllowCredentials(true);
        corsConfiguration.addAllowedOriginPattern("*");
        corsConfiguration.addAllowedHeader("*");
        corsConfiguration.addAllowedMethod("*");

        UrlBasedCorsConfigurationSource source = new UrlBasedCorsConfigurationSource();
        source.registerCorsConfiguration("/**", corsConfiguration);

        return new CorsFilter(source);
    }
}
