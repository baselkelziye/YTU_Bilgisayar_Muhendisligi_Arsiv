"use client"
import React, { useEffect, useState } from 'react';
import CourseCard from '@/app/components/courseCard';
import { CourseResponse } from '@/app/interfaces/course';
import {Instructor} from '@/app/interfaces/user';
import Link from 'next/link';
import useAuthActions from "@/app/services/AuthService";
import { useRouter } from 'next/navigation';

const InstructorProfile: React.FC = () => {
    const [instructor, setInstructor] = useState<Instructor | null>(null);
    const [courses, setCourses] = useState<CourseResponse[]>([]);
    const router = useRouter();
    const [userRole, setUserRole] = useState<string>('');
    const { GetWithAuth } = useAuthActions();
    const [instructorId, setInstructorId] = useState<number>();

    useEffect(() => {
        const storedUserRole = localStorage.getItem('userRole');
        const storedUserId = localStorage.getItem('currentUserId');
        if(storedUserRole){
            setUserRole(storedUserRole);
        }
        if(storedUserId){
            setInstructorId(parseInt(storedUserId));
        }
    }, [router]);

    useEffect(() => {
        if (instructorId) {
            const fetchInstructor = async () => {
                const res = await GetWithAuth(`/instructors/${instructorId}`);
                if (res.ok) {
                    const data = await res.json();
                    setInstructor(data);
                } else {
                    console.error('Failed to fetch instructor');
                }
            };

            const fetchCourses = async () => {
                const res = await GetWithAuth(`/courses?instructorId=${instructorId}`);
                if (res.ok) {
                    const data = await res.json();
                    setCourses(data);
                } else {
                    console.error('Failed to fetch courses');
                }
            };

            fetchInstructor();
            fetchCourses();
        }
    }, [instructorId]);

    const logout = () => {
        localStorage.removeItem('username');
        localStorage.removeItem('currentUserId');
        localStorage.removeItem('userRole');
        localStorage.removeItem('accessToken');
        localStorage.removeItem('refreshToken');
        router.push('/');
    };

    return (
        <div className="container mx-auto p-4">
            <div className="flex justify-between items-center">
                <Link href="/courses" passHref>
                    <button className="mt-4 mb-4 px-4 py-2 bg-blue-500 text-white font-semibold rounded-lg hover:bg-blue-600 focus:outline-none transition ease-in-out duration-150">
                        Go Back to Courses
                    </button>
                </Link>
                <button 
                    onClick={logout}
                    className="px-6 py-3 bg-red-500 text-white font-semibold rounded-lg shadow hover:bg-red-600 focus:outline-none focus:ring-2 focus:ring-red-700 focus:ring-opacity-50 transition ease-in-out duration-150 cursor-pointer"
                >
                    Logout
                </button>
            </div>
            <h1 className="text-xl font-bold">Instructor Profile</h1>
            {instructor && (
                <>
                    <div>
                        <p>Username: {instructor.username}</p>
                        <p>Biography: {instructor.biography}</p>
                        <p>Total Courses: {instructor.courseCount}</p>
                    </div>
                    {userRole === 'INSTRUCTOR' && (
                        <Link href="/create-course" passHref>
                            <button className="mt-4 mb-4 px-4 py-2 bg-blue-500 text-white font-semibold rounded-lg hover:bg-blue-600 focus:outline-none transition ease-in-out duration-150">
                                Create Course
                            </button>
                        </Link>
                    )}
                </>
            )}
            <h2 className="mt-4 font-bold">Courses by {instructor?.username}</h2>
            <div>
                {courses.map(course => (
                    <React.Fragment key={course.id}>
                    <CourseCard
                        courseId={course.id}
                        course={course}
                    />
                </React.Fragment>
                ))}
            </div>
        </div>
    );
};

export default InstructorProfile;
