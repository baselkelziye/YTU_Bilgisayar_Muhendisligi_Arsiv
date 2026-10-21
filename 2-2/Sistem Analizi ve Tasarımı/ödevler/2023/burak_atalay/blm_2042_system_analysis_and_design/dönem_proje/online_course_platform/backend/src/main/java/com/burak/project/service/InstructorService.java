package com.burak.project.service;

import com.burak.project.model.Instructor;
import com.burak.project.model.Student;
import com.burak.project.repository.IInstructorRepository;
import com.burak.project.repository.IStudentRepository;
import com.burak.project.request.InstructorRequest;
import jakarta.persistence.EntityExistsException;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class InstructorService {
    private final IInstructorRepository instructorRepository;
    private final IStudentRepository studentRepository;
    private final BCryptPasswordEncoder passwordEncoder;

    public InstructorService(IInstructorRepository instructorRepository,
                             IStudentRepository studentRepository,
                             BCryptPasswordEncoder passwordEncoder) {
        this.studentRepository = studentRepository;
        this.instructorRepository = instructorRepository;
        this.passwordEncoder = passwordEncoder;
    }

    public Instructor getInstructorById(Long instructorId) {
        return instructorRepository.findById(instructorId).orElseThrow(() -> new EntityNotFoundException("Invalid instructorId"));
    }

    public Instructor getInstructorByUsername(String username) {
        return instructorRepository.findByUsername(username);
    }

    public List<Instructor> getAllInstructors() {
        return instructorRepository.findAll();
    }

    public Instructor createInstructor(InstructorRequest instructorRequest) {
        if(instructorRequest.getUsername() == null) throw new IllegalArgumentException("username cannot be null");
        Instructor instructor = instructorRepository.findByUsername(instructorRequest.getUsername());
        Student student = studentRepository.findByUsername(instructorRequest.getUsername());
        if(instructor != null || student != null) throw new EntityExistsException(
                "There is already a user with this username.");
        instructor = Instructor.builder().
                biography(instructorRequest.getBiography()).
                username(instructorRequest.getUsername()).
                password(passwordEncoder.encode(instructorRequest.getPassword())).
                build();
        return instructorRepository.save(instructor);
    }

    public Instructor updateInstructor(Long instructorId, InstructorRequest instructorRequest) {
        if(instructorRequest.getUsername() == null || instructorRequest.getPassword() == null) throw
            new EntityNotFoundException("username or password cannot be null");
        Optional<Instructor> temp = instructorRepository.findById(instructorId);
        if(temp.isPresent()){
            Instructor foundInstructor = temp.get();
            Instructor instructor = instructorRepository.findByUsername(instructorRequest.getUsername());
            if(instructor != null && !instructorId.equals(instructor.getId())) throw
                    new EntityExistsException("There is already an instructor with this username.");

            foundInstructor.setUsername(instructorRequest.getUsername());
            foundInstructor.setPassword(instructorRequest.getPassword());
            foundInstructor.setBiography(instructorRequest.getBiography());
            return instructorRepository.save(foundInstructor);
        }
        else throw new EntityNotFoundException("Invalid instructorId");
    }

    public void deleteInstructor(Long instructorId) {
        instructorRepository.deleteById(instructorId);
    }
}
