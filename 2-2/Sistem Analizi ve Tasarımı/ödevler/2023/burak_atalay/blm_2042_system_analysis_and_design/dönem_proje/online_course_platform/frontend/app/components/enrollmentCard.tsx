import React, { useEffect, useState } from 'react';
import { Enrollment } from '@/app/interfaces/enrollment';
import { CourseResponse } from '@/app/interfaces/course';
import useAuthActions from "@/app/services/AuthService";
import Link from 'next/link';

interface EnrollmentCardProps {
    enrollment: Enrollment;
    onDelete: (id: number) => void;
}

const EnrollmentCard: React.FC<EnrollmentCardProps> = ({ enrollment, onDelete }) => {
    const [course, setCourse] = useState<CourseResponse | null>(null);
    const { GetWithAuth, DeleteWithAuth } = useAuthActions();

    useEffect(() => {
        const fetchCourse = async () => {
            const response = await GetWithAuth(`/courses/${enrollment.courseId}`);
            if (response.ok) {
                const data: CourseResponse = await response.json();
                setCourse(data);
            }
        };

        fetchCourse();
    }, [enrollment.courseId]);

    const deleteEnrollment = async () => {
        try {
            await DeleteWithAuth(`/enrollments/${enrollment.id}`);
            alert('Enrollment deleted successfully!');
            onDelete(enrollment.id);
        } catch (error) {
            console.error('Failed to delete enrollment:', error);
            alert('Failed to delete enrollment.');
        }
    };

    return (
        <div className="bg-white shadow-md rounded-lg p-4 mb-6">
            {course && (
                <>
                    <h2 className="text-xl font-bold mb-2 text-gray-800">{course.title}</h2>
                    <p className="text-gray-700 mb-4">{course.description}</p>
                    <p className="text-gray-600 mb-1">Instructor: {course.instructorName}</p>
                    <p className="text-gray-600 mb-1">Duration: {course.duration} weeks</p>
                    <p className="text-gray-600 mb-3">Price: {course.price.toFixed(2)} TL</p>
                </>
            )}
            <p className="text-gray-600 mb-1">Enrollment Date: {new Date(enrollment.date).toLocaleDateString()}</p>
            <p className="text-gray-600 mb-1">Progress: {enrollment.userProgresses?.filter(progress => progress.status).length} / {enrollment.userProgresses?.length}</p>
            <div className="flex justify-between items-center">
                <Link href={`/course/${enrollment.id}`} passHref>
                    <button className="px-4 py-2 bg-blue-500 text-white font-semibold rounded-lg hover:bg-blue-600 focus:outline-none transition ease-in-out duration-150">
                        Go to Course
                    </button>
                </Link>
                <button onClick={deleteEnrollment} className="px-4 py-2 bg-red-500 text-white font-semibold rounded-lg hover:bg-red-600 focus:outline-none transition ease-in-out duration-150">
                    Unenroll
                </button>
            </div>
        </div>
    );
};

export default EnrollmentCard;