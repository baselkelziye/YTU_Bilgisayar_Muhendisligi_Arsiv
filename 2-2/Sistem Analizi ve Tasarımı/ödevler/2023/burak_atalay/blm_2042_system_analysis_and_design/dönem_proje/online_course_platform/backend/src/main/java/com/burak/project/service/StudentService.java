package com.burak.project.service;

import com.burak.project.model.Instructor;
import com.burak.project.model.Student;
import com.burak.project.repository.IInstructorRepository;
import com.burak.project.repository.IStudentRepository;
import com.burak.project.request.StudentRequest;
import jakarta.persistence.EntityExistsException;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class StudentService {
    private final IStudentRepository studentRepository;
    private final IInstructorRepository instructorRepository;
    private final BCryptPasswordEncoder passwordEncoder;

    public StudentService(IStudentRepository studentRepository,
                          IInstructorRepository instructorRepository,
                          BCryptPasswordEncoder passwordEncoder) {
        this.studentRepository = studentRepository;
        this.instructorRepository = instructorRepository;
        this.passwordEncoder = passwordEncoder;
    }

    public List<Student> getAllStudents() {
        return studentRepository.findAll();
    }

    public Student getStudentById(Long studentId) {
        return studentRepository.findById(studentId).orElseThrow(
                () -> new EntityNotFoundException("Invalid studentId"));
    }

    public Student getStudentByUsername(String username) {
        return studentRepository.findByUsername(username);
    }

    public Student createStudent(StudentRequest studentRequest) {
        if(studentRequest.getUsername() == null) throw new IllegalArgumentException("username cannot be null");
        Student student = studentRepository.findByUsername(studentRequest.getUsername());
        Instructor instructor = instructorRepository.findByUsername(studentRequest.getUsername());
        if(student != null || instructor != null) throw new EntityExistsException(
                "There is already a user with this username.");
        if(studentRequest.getBalance() < 0.0) throw new EntityNotFoundException("Balance cannot be less than 0");
        student = Student.builder().
                username(studentRequest.getUsername()).
                password(passwordEncoder.encode(studentRequest.getPassword())).
                balance(studentRequest.getBalance()).
                build();
        return studentRepository.save(student);
    }

    public Student updateStudent(Long studentId, StudentRequest studentRequest) {
        if(studentRequest.getUsername() == null) throw
                new EntityNotFoundException("username or password cannot be null");
        Optional<Student> temp = studentRepository.findById(studentId);
        if(temp.isPresent()){
            Student foundStudent = temp.get();
            Student student = studentRepository.findByUsername(studentRequest.getUsername());
            if(student != null && !studentId.equals(student.getId())) throw
                    new EntityExistsException("There is already a student with this username.");

            foundStudent.setUsername(studentRequest.getUsername());
            foundStudent.setBalance(studentRequest.getBalance());
            return studentRepository.save(foundStudent);
        }
        else throw new EntityNotFoundException("Invalid studentId");
    }

    public void deleteStudent(Long studentId) {
        studentRepository.deleteById(studentId);
    }
}
