import React, { useEffect, useState } from 'react';
import { CourseResponse } from '@/app/interfaces/course';
import { Student } from '@/app/interfaces/user';
import { Enrollment } from '@/app/interfaces/enrollment';
import useAuthActions from "@/app/services/AuthService";
import Link from 'next/link';
import { useRouter } from 'next/navigation';

interface CourseCardProps {
    courseId: number;
    course: CourseResponse;
}

const CourseCard: React.FC<CourseCardProps> = ({ courseId, course }) => {
    const [isEnrolled, setIsEnrolled] = useState(false);
    const [enrollments, setEnrollments] = useState<Enrollment[]>([]);
    const [enrollmentCount, setEnrollmentCount] = useState(course.enrollmentCount);
    const [userRole, setUserRole] = useState<string>('');
    const [userId, setUserId] = useState<number>();
    const [student, setStudent] = useState<Student | null>(null);
    const [loading, setLoading] = useState(true);
    const { GetWithAuth, PostWithAuth, DeleteWithAuth } = useAuthActions();
    const router = useRouter();

    useEffect(() => {
        const storedUserId = localStorage.getItem('currentUserId');
        const storedUserRole = localStorage.getItem('userRole');

        if (storedUserId) {
            setUserId(parseInt(storedUserId));
        }
        if (storedUserRole) {
            setUserRole(storedUserRole);
        }

        setLoading(false);
    }, []);

    const fetchStudent = async () => {
        const res = await GetWithAuth(`/students/${userId}`);
        if (res.ok) {
            const data = await res.json();
            setStudent(data);
        } else {
            console.error('Failed to fetch student');
        }
    };

    useEffect(() => {
    
        if (userId && userRole == 'STUDENT') {
            fetchStudent();
        }
    }, [userId, userRole]);

    useEffect(() => {
        const fetchEnrollments = async () => {
            const enrollment = await GetWithAuth(`/enrollments/course/${course.id}`);
            if (enrollment.ok) {
                const enrollmentData = await enrollment.json() as Enrollment[];
                setEnrollments(enrollmentData);
            } else {
                console.error('Failed to load enrollments');
            }
        };
    
        fetchEnrollments();
    }, [course.id, userRole]);

    const checkEnrollments = async () => {
        if (userRole == 'INSTRUCTOR') return;
        if (student) {
            const enrollmentControl = enrollments.find(enrollment => enrollment.studentId === student.id);
            if (enrollmentControl != null) {
                setIsEnrolled(true);
            }
        }
    };

    useEffect(() => {
        checkEnrollments();
    }, [student, enrollments]);

    const handleEnrollment = async () => {
        if (userRole == 'INSTRUCTOR') return;

        if (!isEnrolled) {
            const success = await saveEnrollment();
            if (success) {
                setIsEnrolled(true);
                setEnrollmentCount(enrollmentCount + 1);
            }
        } else {
            const success = await deleteEnrollment();
            if (success) {
                setIsEnrolled(false);
                alert('Enrollment deleted successfully!');
                setEnrollmentCount(enrollmentCount - 1);
            }
        }
    };

    const saveEnrollment = async () => {
        console.log("balance:", student?.balance);
        if (student && student.balance < course.price) {
            alert("You do not have enough balance to enroll in this course.");
            return false;
        }

        try {
            const response = await PostWithAuth(`/enrollments`,
                { studentId: userId, courseId: course.id });
            if (response.ok) {
                alert('Enrollment successful!');
                return true;
            } else {
                const errorData = await response.text();
                alert(errorData || 'Failed to enroll in the course');
                return false;
            }
        } catch (error) {
            console.error('Failed to save enrollment:', error);
            return false;
        }
    };

    const deleteEnrollment = async () => {
        try {
            const studentId = userId?.toString();
            const courseId = course.id.toString();

            const url = `/enrollments?studentId=${studentId}&courseId=${courseId}`;

            await DeleteWithAuth(url);
            return true;

        } catch (error) {
            console.error('Failed to delete enrollment:', error);
            return false;
        }
    };

    const deleteCourse = async () => {
        try {
            await DeleteWithAuth('/courses/' + courseId);
            alert('Course deleted successfully!');
            return true;
        } catch (error) {
            console.error('Failed to delete course:', error);
            return false;
        }
    };

    if (loading) {
        return <div>Loading...</div>;
    }

    return (
        <div className="bg-white shadow-md rounded-lg p-4 mb-6 relative">
            <h2 className="text-xl font-bold mb-2 text-gray-800">{course.title}</h2>
            <p className="text-gray-700 mb-4">{course.description}</p>
            <Link href={`/instructor-profile/`} passHref>
                <span className="text-gray-600 mb-1 cursor-pointer underline hover:text-blue-500">
                    Instructor: {course.instructorName}
                </span>
            </Link>
            <p className="text-gray-600 mb-1">Duration: {course.duration} weeks</p>
            <p className="text-gray-600 mb-3">Price: {course.price.toFixed(2)} TL</p>
            <div className="flex justify-between items-center">
                <p className="text-green-500">Enrollments: {enrollmentCount}</p>
                {userRole === 'STUDENT' && !isEnrolled && (
                    <button className="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600" onClick={() => handleEnrollment()}>
                        Enroll
                    </button>
                )}
                {userRole === 'STUDENT' && isEnrolled && (
                    <button className="px-4 py-2 bg-red-500 text-white rounded hover:bg-red-600" onClick={() => handleEnrollment()}>
                        Unenroll
                    </button>
                )}
                {!userId && !userRole && (
                    <button 
                        className="text-red-500 underline hover:text-red-600 focus:outline-none"
                        onClick={() => router.push('/login')}
                    >
                        Log in to enroll in this course
                    </button>
                )}
            </div>
        </div>
    );
};

export default CourseCard;

