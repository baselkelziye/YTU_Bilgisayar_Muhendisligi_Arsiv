"use client";
import React, { useState } from 'react';
import { useRouter } from 'next/navigation';
import useAuthActions from "@/app/services/AuthService";

interface UserLoginInfo {
    username: string;
    password: string;
}

function LoginPage() {
    const [username, setUsername] = useState<string>('');
    const [password, setPassword] = useState<string>('');
    const [error, setError] = useState<string>('');
    const { PostWithoutAuth } = useAuthActions();
    const router = useRouter();

    const tryLogin = async (url: string, userInfo: UserLoginInfo): Promise<boolean> => {
        const response = await PostWithoutAuth(url, userInfo)
        if (response.ok) {
            const data = await response.json();
            localStorage.setItem('username', username);
            localStorage.setItem('currentUserId', data.userId);
            localStorage.setItem('userRole', data.role);
            localStorage.setItem('accessToken', data.accessToken);
            localStorage.setItem('refreshToken', data.refreshToken);
            router.push('/courses');
            return true;
        } else {
            const errorText = await response.text(); 
            console.error('Login failed:', errorText);
            setError('Login failed: ' + errorText);
            return false;
        }
    };

    const handleLogin = async () => {
        setError('');
        if (!(await tryLogin('/auth/login', { username, password }))) {
            setError('Login failed: Invalid credentials or server error');
        }
    };

    return (
        <div className="flex justify-center items-center h-screen">
            <div className="w-full max-w-xs">
                <form className="bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4" onSubmit={e => e.preventDefault()}>
                    <div className="mb-4">
                        <label className="block text-gray-700 text-sm font-bold mb-2" htmlFor="username">
                            Username
                        </label>
                        <input
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                            id="username"
                            type="text"
                            placeholder="Username"
                            value={username}
                            onChange={e => setUsername(e.target.value)}
                        />
                    </div>
                    <div className="mb-6">
                        <label className="block text-gray-700 text-sm font-bold mb-2" htmlFor="password">
                            Password
                        </label>
                        <input
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 mb-3 leading-tight focus:outline-none focus:shadow-outline"
                            id="password"
                            type="password"
                            placeholder="**********"
                            value={password}
                            onChange={e => setPassword(e.target.value)}
                        />
                    </div>
                    <div className="flex items-center justify-between">
                        <button
                            className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline"
                            type="button"
                            onClick={handleLogin}
                        >
                            Sign In
                        </button>
                    </div>
                    {error && <p className="text-red-500 text-xs italic">{error}</p>}
                </form>
            </div>
        </div>
    );
}

export default LoginPage;