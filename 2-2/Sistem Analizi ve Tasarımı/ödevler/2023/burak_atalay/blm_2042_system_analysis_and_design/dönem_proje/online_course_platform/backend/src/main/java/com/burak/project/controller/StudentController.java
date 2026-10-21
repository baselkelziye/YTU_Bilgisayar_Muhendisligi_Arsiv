package com.burak.project.controller;

import com.burak.project.model.Student;
import com.burak.project.request.StudentRequest;
import com.burak.project.response.StudentResponse;
import com.burak.project.service.StudentService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/students")

public class StudentController {
    private final StudentService studentService;

    public StudentController(StudentService studentService) {
        this.studentService = studentService;
    }

    @GetMapping
    public List<StudentResponse> getAllInstructors(){
        List<Student> students =  studentService.getAllStudents();
        return (students == null) ? null : students.stream().map(StudentResponse::new).
                toList();
    }

    @GetMapping("/{studentId}")
    public StudentResponse getStudentById(@PathVariable Long studentId){
        return new StudentResponse(studentService.getStudentById(studentId));
    }

    @PostMapping
    public ResponseEntity<Void> createStudent(@RequestBody StudentRequest studentRequest){
        return (studentService.createStudent(studentRequest) != null) ? new ResponseEntity<>(HttpStatus.CREATED) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/{studentId}")
    public ResponseEntity<Void> updateStudent(@PathVariable Long studentId,
                                                 @RequestBody StudentRequest studentRequest){
        return (studentService.updateStudent(studentId, studentRequest) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @DeleteMapping("/{studentId}")
    public void deleteStudent(@PathVariable Long studentId){
        studentService.deleteStudent(studentId);
    }
}
