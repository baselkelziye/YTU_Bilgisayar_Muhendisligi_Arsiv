"use client";
import React, { useState, useEffect, useRef } from "react";
import { Button } from "@/components/ui/button";
import Link from "next/link";
import { toast } from "sonner";
import { useRouter } from 'next/navigation';
import { Eye, EyeOff } from 'lucide-react';

export default function SignInPage() {
  const router = useRouter();

  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [showPassword, setShowPassword] = useState(false);

  const usernameRef = useRef<HTMLInputElement>(null);
  const passwordRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    if (usernameRef.current?.value) {
      setUsername(usernameRef.current.value);
    }
    if (passwordRef.current?.value) {
      setPassword(passwordRef.current.value);
    }
  }, []);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();

    if (!username || !password) {
      toast.error("Please fill in both username and password.");
      return;
    }

    fetch('/api/signin', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded',
      },
      credentials: 'include',
      body: new URLSearchParams({ username, password }).toString(),
    }).then( async res => {
      const data = await res.json();
      const status = res.status;
      console.log(status, data);
      if (res.ok) {
        toast.success("Login successful! Welcome back.");
        setTimeout(() => {
          router.push('/');
          }, 500);
      } else {
        toast.error('Login failed.');
      }
    })
  };

  return (
    <div className="min-h-screen flex items-center justify-center bg-gradient-to-r from-blue-500 via-purple-500 to-pink-500">
      <div className="bg-white p-8 shadow-lg rounded-xl w-full max-w-sm">
        <h2 className="text-2xl font-semibold text-blue-600 mb-6 text-center">Sign In</h2>

        <form className="space-y-6" autoCorrect="off" onSubmit={handleSubmit}>
          <div>
            <input
              type="text"
              placeholder="Username"
              value={username}
              ref={usernameRef}
              onChange={(e) => setUsername(e.target.value)}
              className="w-full border border-gray-300 p-4 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500 transition-all"
            />
          </div>

          <div className="relative">
            <input
              type={showPassword ? "text" : "password"}
              placeholder="Password"
              value={password}
              ref={passwordRef}
              onChange={(e) => setPassword(e.target.value)}
              className="w-full border border-gray-300 p-4 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500 transition-all"
            />
            {password && (
              <button
                type="button"
                title={showPassword ? "Hide password" : "Show password"}
                onClick={() => setShowPassword(prev => !prev)}
                className="absolute top-1/2 right-4 transform -translate-y-1/2 text-gray-600 hover:text-gray-900 focus:outline-none"
              >
                {showPassword ? <EyeOff size={20}/> : <Eye size={20}/>}
              </button>
            )}
          </div>

          <Button type="submit" className="w-full py-3 bg-blue-600 text-white hover:bg-blue-700 rounded-lg transition-colors">
            Sign In
          </Button>
        </form>

        <p className="text-sm text-center mt-4 text-gray-600">
          Don’t have an account?
          <Link href="/signup" className="text-blue-600 underline hover:text-blue-800 transition-colors mx-2">
            Sign up
          </Link>
        </p>
      </div>
    </div>
  );
}
