package com.burak.project.service;

import com.burak.project.model.Course;
import com.burak.project.model.Enrollment;
import com.burak.project.model.Student;
import com.burak.project.model.UserProgress;
import com.burak.project.repository.IEnrollmentRepository;
import com.burak.project.request.EnrollmentRequest;
import com.burak.project.request.StudentRequest;
import com.burak.project.request.UserProgressRequest;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

@Service
public class EnrollmentService {
    private final IEnrollmentRepository enrollmentRepository;
    private final UserProgressService userProgressService;
    private final StudentService studentService;
    private final CourseService courseService;

    public EnrollmentService(IEnrollmentRepository enrollmentRepository,
                             UserProgressService userProgressService,
                             StudentService studentService, CourseService courseService) {
        this.enrollmentRepository = enrollmentRepository;
        this.userProgressService = userProgressService;
        this.studentService = studentService;
        this.courseService = courseService;
    }

    public List<Enrollment> getAllEnrollments(){
        return enrollmentRepository.findAll();
    }

    public List<Enrollment> getEnrollmentsByStudentId(Long studentId){
        return (studentId != null) ? enrollmentRepository.findByStudentId(studentId) : null;
    }

    public List<Enrollment> getEnrollmentsByCourseId(Long courseId) {
        return (courseId != null) ? enrollmentRepository.findByCourseId(courseId) : null;
    }

    public Enrollment getEnrollmentById(Long enrollmentId) {
        return enrollmentRepository.findById(enrollmentId).orElseThrow(() -> new EntityNotFoundException(
                "Invalid enrollmentId"));
    }

    public Enrollment createEnrollment(EnrollmentRequest enrollmentRequest) {
        Student student = studentService.getStudentById(enrollmentRequest.getStudentId());
        Course course = courseService.getCourseById(enrollmentRequest.getCourseId());

        StudentRequest studentRequest = StudentRequest.builder().
                username(student.getUsername()).
                password(student.getPassword()).
                balance(student.getBalance() - course.getPrice()).
                build();
        studentService.updateStudent(student.getId(), studentRequest);

        Enrollment enrollment = Enrollment.builder().
                student(student).
                course(course).
                enrollmentDate(LocalDate.now()).
                build();
        enrollment = enrollmentRepository.save(enrollment);

        List<UserProgress> userProgresses = userProgressService.createUserProgresses(enrollment, course.getWeeks());
        enrollment.setUserProgresses(userProgresses);
        return enrollment;
    }

    public Enrollment updateEnrollment(EnrollmentRequest enrollmentRequest, Long enrollmentId) {
        Optional<Enrollment> temp = enrollmentRepository.findById(enrollmentId);
        if(temp.isEmpty()) throw new EntityNotFoundException("Invalid enrollmentId");

        Enrollment enrollment = temp.get();
        userProgressService.updateUserProgresses(enrollmentRequest.getUserProgresses());
        return enrollmentRepository.save(enrollment);
    }

    public UserProgress updateUserProgress(Long userProgressId, UserProgressRequest userProgressRequest) {
        return userProgressService.updateUserProgress(userProgressId, userProgressRequest);
    }

    public void deleteEnrollment(Long enrollmentId) {
        Optional<Enrollment> temp = enrollmentRepository.findById(enrollmentId);
        if(temp.isPresent()){
            Student student = temp.get().getStudent();
            Course course = temp.get().getCourse();
            StudentRequest studentRequest = StudentRequest.builder().
                    username(student.getUsername()).
                    balance(student.getBalance() + course.getPrice()).
                    build();
            studentService.updateStudent(student.getId(), studentRequest);
            enrollmentRepository.deleteById(enrollmentId);
        }
    }

    public void deleteEnrollmentWithForeignKeys(Long studentId, Long courseId) {
        Student student = studentService.getStudentById(studentId);
        Course course = courseService.getCourseById(courseId);
        Enrollment enrollment = enrollmentRepository.findByForeignKeys(studentId, courseId);
        StudentRequest studentRequest = StudentRequest.builder().
                username(student.getUsername()).
                balance(student.getBalance() + course.getPrice()).
                build();
        studentService.updateStudent(studentId, studentRequest);
        enrollmentRepository.deleteById(enrollment.getId());
    }
}
