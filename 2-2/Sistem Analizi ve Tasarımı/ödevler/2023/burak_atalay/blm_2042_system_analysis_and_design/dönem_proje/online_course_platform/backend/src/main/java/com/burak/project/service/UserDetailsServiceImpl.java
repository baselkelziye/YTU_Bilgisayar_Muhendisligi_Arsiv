package com.burak.project.service;

import com.burak.project.enumeration.Role;
import com.burak.project.model.Instructor;
import com.burak.project.model.Student;
import com.burak.project.repository.IInstructorRepository;
import com.burak.project.repository.IStudentRepository;
import com.burak.project.security.JwtUserDetails;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Component;

import java.util.Optional;

@Component
public class UserDetailsServiceImpl implements UserDetailsService {
    private final IStudentRepository studentRepository;
    private final IInstructorRepository instructorRepository;

    public UserDetailsServiceImpl(IStudentRepository studentRepository,
                                  IInstructorRepository instructorRepository) {
        this.studentRepository = studentRepository;
        this.instructorRepository = instructorRepository;
    }

    @Override
    public JwtUserDetails loadUserByUsername(String username) throws UsernameNotFoundException {

        Student student = studentRepository.findByUsername(username);
        if(student != null){
            return new JwtUserDetails(student.getId(), student.getUsername(),
                    student.getPassword(), Role.STUDENT);
        }

        Instructor instructor = instructorRepository.findByUsername(username);
        if(instructor != null){
            return new JwtUserDetails(instructor.getId(), instructor.getUsername(),
                instructor.getPassword(), Role.INSTRUCTOR);
        }

        throw new UsernameNotFoundException("Invalid username");
    }

    public JwtUserDetails loadUserByUserId(Long userId) throws UsernameNotFoundException {

        Optional<Student> found = studentRepository.findById(userId);
        if(found.isPresent()){
            Student student = found.get();
            return new JwtUserDetails(student.getId(), student.getUsername(),
                    student.getPassword(), Role.STUDENT);
        }

        Optional<Instructor> found2 = instructorRepository.findById(userId);
        if(found2.isPresent()){
            Instructor instructor = found2.get();
            return new JwtUserDetails(instructor.getId(), instructor.getUsername(),
                    instructor.getPassword(), Role.INSTRUCTOR);
        }

        throw new BadCredentialsException("Invalid userId");
    }
}
