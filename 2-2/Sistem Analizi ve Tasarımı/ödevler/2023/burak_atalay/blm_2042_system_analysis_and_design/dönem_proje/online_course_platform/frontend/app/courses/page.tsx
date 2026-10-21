"use client";
import React, { useEffect, useState } from 'react';
import { useRouter } from 'next/navigation';
import CourseCard from '@/app/components/courseCard';
import useAuthActions from "@/app/services/AuthService";
import { CourseResponse } from '@/app/interfaces/course'; 

const MainPage: React.FC = () => {
    const [courses, setCourses] = useState<CourseResponse[]>([]);
    const [userRole, setUserRole] = useState<string>(''); 
    const [userId, setUserId] = useState<number>();
    const { GetWithAuth } = useAuthActions();
    const router = useRouter();

    useEffect(() => {
        const storedUserId = localStorage.getItem('currentUserId');
        const storedUserRole = localStorage.getItem('userRole');

        if (storedUserId) {
            setUserId(parseInt(storedUserId));
            console.log("User ID set:", storedUserId);
        } else {
            console.log("No User ID found in localStorage");
        }

        if (storedUserRole) {
            setUserRole(storedUserRole);
            console.log("User Role set:", storedUserRole);
        } else {
            console.log("No User Role found in localStorage");
        }

        fetchCourses();
    }, []);
    
    const fetchCourses = async () => {
        const courseResponse = await GetWithAuth('/courses');
        console.log("Courses fetched");
        if (courseResponse.ok) {
            const coursesData = await courseResponse.json() as CourseResponse[];
            setCourses(coursesData);
        } else {
            console.error('Failed to load courses');
        }
    };

    const goToProfile = () => {
        if(userId && userRole){
            if (userRole === 'STUDENT') {
            router.push('/student-profile');
        } else if (userRole === 'INSTRUCTOR') {
            router.push('/instructor-profile/');
        }
        } else {
            router.push('/login');
        }
    };

    const logout = () => {
        localStorage.removeItem('username');
        localStorage.removeItem('currentUserId');
        localStorage.removeItem('userRole');
        localStorage.removeItem('accessToken');
        localStorage.removeItem('refreshToken');
        router.push('/');
    };

    return (
        <div className="bg-gray-100 min-h-screen"> {/* Setting a light gray background and minimum height to full screen */}
            <div className="main-container mx-auto max-w-7xl px-4 sm:px-6 lg:px-8">
                <div className="flex justify-between items-center mb-8">
                    <h1 className="text-3xl font-bold text-gray-900">Courses</h1>
                    <button 
                        onClick={goToProfile}
                        className="px-6 py-3 bg-green-500 text-white font-semibold rounded-lg shadow hover:bg-green-600 focus:outline-none focus:ring-2 focus:ring-green-700 focus:ring-opacity-50 transition ease-in-out duration-150 cursor-pointer"
                    >
                        Go to Your Profile
                    </button>
                    <button 
                            onClick={logout}
                            className="px-6 py-3 bg-red-500 text-white font-semibold rounded-lg shadow hover:bg-red-600 focus:outline-none focus:ring-2 focus:ring-red-700 focus:ring-opacity-50 transition ease-in-out duration-150 cursor-pointer"
                        >
                            Logout
                        </button>
                </div>
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

export default MainPage;