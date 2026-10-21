"use client"
import React, { useEffect, useState } from 'react';
import { CourseResponse } from '@/app/interfaces/course';
import { Enrollment, UserProgress } from '@/app/interfaces/enrollment';
import useAuthActions from "@/app/services/AuthService";
import { useRouter } from 'next/navigation';

export default function CoursePage({ params }: { params: { enrollmentId: string } }) {
    const { enrollmentId } = params;
    const router = useRouter();
    const [course, setCourse] = useState<CourseResponse | null>(null);
    const [enrollment, setEnrollment] = useState<Enrollment | null>(null);
    const { GetWithAuth, PutWithAuth } = useAuthActions();

    useEffect(() => {
        const fetchEnrollmentDetails = async () => {    
            const response = await GetWithAuth(`/enrollments/${enrollmentId}`);
            if (response.ok) {
                const data: Enrollment = await response.json();
                setEnrollment(data);
            }
            else{
                console.error('Failed to fetch enrollment details');
            }
        };

        fetchEnrollmentDetails();
    }, [enrollmentId]);

    useEffect(() => {
        if (enrollment) {
            const fetchCourseDetails = async () => {
                const response = await GetWithAuth(`/courses/${enrollment.courseId}`);
                if (response.ok) {
                    const data: CourseResponse = await response.json();
                    setCourse(data);
                }
                else{
                    console.error('Failed to fetch course details');
                }
            };

            fetchCourseDetails();
        }
    }, [enrollment]);

    const handleWeekCompletion = async (userProgressId: number, currentStatus: boolean) => {
        if (!enrollment) {
            console.error('Enrollment data is not available.');
            return;
        }
        const newStatus = !currentStatus;
        const response = await PutWithAuth(`/enrollments/userProgresses/${userProgressId}`,
            { status: newStatus }
        );

        if (response.ok) {
            alert('Week status updated successfully!');
            const updatedUserProgresses = enrollment.userProgresses?.map(userProgress => {
                if (userProgress.id === userProgressId) {
                    return { ...userProgress, status: newStatus };
                }
                return userProgress;
            });
    
            setEnrollment(previousEnrollment => {
                if (!previousEnrollment) return null;
            
                return {
                    ...previousEnrollment,
                    userProgresses: updatedUserProgresses
                } as Enrollment;  
            });
        } else {
            alert('Failed to update week status.');
        }
    };

    if (!course || !enrollment) return <p className="text-center text-gray-600 mt-10">Loading...</p>;

    return (
        <div className="container mx-auto p-6">
            <div className="bg-white shadow-lg rounded-lg overflow-hidden">
                <div className="p-6 bg-gradient-to-r from-teal-500 to-blue-500 text-white">
                    <button 
                        onClick={() => router.push('/student-profile')}
                        className="mb-4 px-6 py-3 bg-white text-teal-700 font-semibold rounded-lg shadow hover:bg-gray-200 focus:outline-none focus:ring-2 focus:ring-white focus:ring-opacity-50 transition ease-in-out duration-150 cursor-pointer"
                    >
                        Go to Your Profile
                    </button>
                    <h2 className="text-2xl font-bold mb-2">{course.title}</h2>
                    <p className="text-lg">{course.description}</p>
                    <div className="mt-4">
                        <p className="font-semibold">Instructor: {course.instructorName}</p>
                        <p className="font-semibold">Duration: {course.duration} weeks</p>
                    </div>
                </div>
                <div className="p-6">
                    <h3 className="text-xl font-semibold text-gray-800 mb-4">Course Progress</h3>
                    <ul className="space-y-4">
                        {enrollment.userProgresses && enrollment.userProgresses.length > 0 ? (
                            enrollment.userProgresses.map((userProgress: UserProgress, index: number) => (
                                <li key={userProgress.id} className="flex justify-between items-center bg-gray-100 p-4 rounded-lg shadow-sm">
                                    <span className="text-gray-800 font-medium">Week {index + 1}: {userProgress.week.reading}</span>
                                    <button
                                        className={`px-4 py-2 rounded-lg shadow ${
                                            userProgress.status ? 'bg-red-500 hover:bg-red-600' : 'bg-green-500 hover:bg-green-600'
                                        } text-white transition ease-in-out duration-150`}
                                        onClick={() => handleWeekCompletion(userProgress.id, userProgress.status)}
                                    >
                                        {userProgress.status ? 'Mark Incomplete' : 'Mark Complete'}
                                    </button>
                                </li>
                            ))
                        ) : (
                            <p className="text-gray-600">No weeks available.</p>
                        )}
                    </ul>
                </div>
            </div>
        </div>
    );
};
