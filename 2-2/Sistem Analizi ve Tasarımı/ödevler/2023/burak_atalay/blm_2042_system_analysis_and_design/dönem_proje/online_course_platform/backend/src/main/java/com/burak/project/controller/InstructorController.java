package com.burak.project.controller;

import com.burak.project.model.Instructor;
import com.burak.project.request.InstructorRequest;
import com.burak.project.response.InstructorResponse;
import com.burak.project.service.InstructorService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/instructors")

public class InstructorController {
    private final InstructorService instructorService;

    public InstructorController(InstructorService instructorService) {
        this.instructorService = instructorService;
    }

    @GetMapping
    public List<InstructorResponse> getAllInstructors(){
        List<Instructor> instructors =  instructorService.getAllInstructors();
        return (instructors == null) ? null : instructors.stream().map(InstructorResponse::new).
                toList();
    }

    @GetMapping("/{instructorId}")
    public InstructorResponse getInstructorById(@PathVariable Long instructorId){
        return new InstructorResponse(instructorService.getInstructorById(instructorId));
    }

    @PostMapping
    public ResponseEntity<Void> createInstructor(@RequestBody InstructorRequest instructorRequest){
        return (instructorService.createInstructor(instructorRequest) != null) ? new ResponseEntity<>(HttpStatus.CREATED) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @PutMapping("/{instructorId}")
    public ResponseEntity<Void> updateInstructor(@PathVariable Long instructorId,
                                           @RequestBody InstructorRequest instructorRequest){
        return (instructorService.updateInstructor(instructorId, instructorRequest) != null) ? new ResponseEntity<>(HttpStatus.OK) :
                new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @DeleteMapping("/{instructorId}")
    public void deleteInstructor(@PathVariable Long instructorId){
        instructorService.deleteInstructor(instructorId);
    }
}
