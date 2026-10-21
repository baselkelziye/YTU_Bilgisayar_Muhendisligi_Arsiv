"use client";

import React, { useState } from 'react';
import { useRouter } from 'next/navigation';
import useAuthActions from "@/app/services/AuthService";

export interface UserLoginInfo {
    username: string;
    password: string;
}

export interface StudentRequest extends UserLoginInfo {
    balance: number;
}

export interface InstructorRequest extends UserLoginInfo {
    biography: string;
}

const RegistrationForm: React.FC = () => {
    const [userType, setUserType] = useState<string>('');
    const [username, setUsername] = useState<string>('');
    const [password, setPassword] = useState<string>('');
    const [balance, setBalance] = useState<string>('');
    const [biography, setBiography] = useState<string>('');
    const [error, setError] = useState<string>('');
    const { PostWithoutAuth } = useAuthActions();

    const router = useRouter();

    const handleRegister = async (e: React.FormEvent<HTMLFormElement>) => {
        e.preventDefault();
        let payload: StudentRequest | InstructorRequest;

        if (userType === 'student') {
            payload = {
                username,
                password,
                balance: parseFloat(balance)
            };
        } else {
            payload = {
                username,
                password,
                biography
            };
        }

        try {
            const response = await PostWithoutAuth('/auth/register/' + userType, payload); 

            if (!response.ok) {
                const errorData = await response.text(); 
                throw new Error(errorData || 'Failed to register.');
            }

            alert('Registration successful!');
            router.push('/login');
        } catch (err: unknown) {
            let message = 'An error occurred during registration.';
            if (err instanceof Error) {
                message = err.message;
            }
            setError(message);
        }
    };

    return (
        <div className="p-6 max-w-md mx-auto text-center">
            <h1 className="text-2xl font-bold mb-6">Register as a Student or Instructor</h1>
            <form onSubmit={handleRegister} className="space-y-4">
                <div className="space-y-2">
                    <label className="block font-bold">
                        User Type:
                        <select
                            className="w-full p-2 border border-gray-300 rounded bg-gray-100 focus:bg-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                            value={userType}
                            onChange={e => setUserType(e.target.value)}
                            required
                        >
                            <option value="">Select User Type</option>
                            <option value="student">Student</option>
                            <option value="instructor">Instructor</option>
                        </select>
                    </label>
                </div>
                <div className="space-y-2">
                    <label className="block font-bold">Username:</label>
                    <input
                        className="w-full p-2 border border-gray-300 rounded bg-gray-100 focus:bg-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                        type="text"
                        value={username}
                        onChange={e => setUsername(e.target.value)}
                        required
                    />
                </div>
                <div className="space-y-2">
                    <label className="block font-bold">Password:</label>
                    <input
                        className="w-full p-2 border border-gray-300 rounded bg-gray-100 focus:bg-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                        type="password"
                        value={password}
                        onChange={e => setPassword(e.target.value)}
                        required
                    />
                </div>
                {userType === 'student' && (
                    <div className="space-y-2">
                        <label className="block font-bold">Balance:</label>
                        <input
                            className="w-full p-2 border border-gray-300 rounded bg-gray-100 focus:bg-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                            type="number"
                            value={balance}
                            onChange={e => setBalance(e.target.value)}
                            required
                        />
                    </div>
                )}
                {userType === 'instructor' && (
                    <div className="space-y-2">
                        <label className="block font-bold">Biography:</label>
                        <textarea
                            className="w-full p-2 border border-gray-300 rounded bg-gray-100 focus:bg-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                            value={biography}
                            onChange={e => setBiography(e.target.value)}
                            required
                        />
                    </div>
                )}
                <button
                    className="w-full py-3 text-white bg-blue-500 rounded hover:bg-blue-600 transition ease-in-out duration-150"
                    type="submit"
                >
                    Register
                </button>
                {error && <p className="text-red-500 mt-4 text-sm">{error}</p>}
            </form>
        </div>
    );
}

export default RegistrationForm;
