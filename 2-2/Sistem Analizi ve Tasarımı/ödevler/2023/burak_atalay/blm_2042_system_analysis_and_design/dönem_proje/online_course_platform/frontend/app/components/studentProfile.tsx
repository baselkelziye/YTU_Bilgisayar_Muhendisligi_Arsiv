"use client"
import React, { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';
import EnrollmentCard from '@/app/components/enrollmentCard';
import { Enrollment } from '@/app/interfaces/enrollment';
import { Student } from '@/app/interfaces/user';
import useAuthActions from "@/app/services/AuthService";
import Link from 'next/link';

const StudentProfile: React.FC = () => {
    const [enrollments, setEnrollments] = useState<Enrollment[]>([]);
    const [student, setStudent] = useState<Student | null>(null);
    const [isUpdating, setIsUpdating] = useState<boolean>(false);
    const [amountToAdd, setAmountToAdd] = useState<string>('');
    const [studentId, setStudentId] = useState<number>();
    const [errorMessage, setErrorMessage] = useState<string>('');
    const { GetWithAuth, PutWithAuth } = useAuthActions();
    const router = useRouter();

    useEffect(() => {
        const userRole = localStorage.getItem('userRole');
        const userId = localStorage.getItem('currentUserId');
        
        if (userRole === 'INSTRUCTOR') {
            router.push('/instructor-profile/');
        }
        if(userId){
            setStudentId(parseInt(userId))
        }
    
    }, []);

    const fetchStudentDetails = async () => {
        const response = await GetWithAuth(`/students/${studentId}`);
        if (response.ok) {
            const data: Student = await response.json();
            setStudent(data);
            console.log(data);
        }
    };

    const fetchEnrollments = async () => {
        const response = await GetWithAuth(`/enrollments/student/${studentId}`);
        if (response.ok) {
            const data: Enrollment[] = await response.json();
            setEnrollments(data);
        }
    };

    useEffect(() => {
        if (studentId) {
            fetchStudentDetails();
            fetchEnrollments();
        }
    }, [studentId]);

    const updateStudent = async () => {
        if (!student || !studentId) return;

        const amount = parseFloat(amountToAdd);
        if (isNaN(amount) || amount <= 0) {
            setErrorMessage('You cannot add a negative amount or zero.');
            return;
        }

        const updatedStudent: Student = {
            ...student,
            balance: student.balance + amount,
        };

        const response = await PutWithAuth(`/students/${studentId}`,
            updatedStudent);

        if (response.ok) {
            alert('Balance updated successfully!');
            setStudent(updatedStudent);
            setIsUpdating(false);
            setAmountToAdd(''); 
            setErrorMessage('');
        } else {
            alert('Failed to update balance.');
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

    const updateBalance = async () => {
        if (!studentId) return;
        const response = await GetWithAuth(`/students/${studentId}`);
        if (response.ok) {
            const updatedData = await response.json() as { balance: number };
            setStudent(prevStudent => {
                if (!prevStudent) return null;
                return {
                    ...prevStudent,
                    balance: updatedData.balance
                };
            });
        }
    };

    const handleDeleteEnrollment = async (id: number) => {
        setEnrollments(prevEnrollments => prevEnrollments.filter(enrollment => enrollment.id !== id));
        await updateBalance();
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
            <h1 className="text-xl font-bold">Student Profile</h1>
            {student && (
                <>
                    <div>
                        <p>Username: {student.username}</p>
                        <p>Balance: ${student.balance.toFixed(2)}</p>
                        <p>Enrollments: {student.enrollmentCount}</p>
                    </div>
                    <div className="space-y-4 mt-4">
                        {enrollments.map(enrollment => (
                            <EnrollmentCard key={enrollment.id} enrollment={enrollment} onDelete={handleDeleteEnrollment} />
                        ))}
                    </div>
                </>
            )}
            {isUpdating ? (
                <div className="space-y-2">
                    <input
                        type="number"
                        value={amountToAdd}
                        onChange={(e) => setAmountToAdd(e.target.value)}
                        placeholder="Amount to Add"
                        required className="w-full p-2 border border-gray-300 rounded bg-gray-100 text-gray-900 focus:bg-white focus:text-gray-900 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    />
                    {errorMessage && <p className="text-red-500">{errorMessage}</p>}
                    <button onClick={updateStudent} className="btn btn-primary">Update Balance</button>
                </div>
            ) : (
                <button onClick={() => setIsUpdating(true)} className="btn btn-secondary">
                    Update Balance
                </button>
            )}
        </div>
    );
};

export default StudentProfile;

