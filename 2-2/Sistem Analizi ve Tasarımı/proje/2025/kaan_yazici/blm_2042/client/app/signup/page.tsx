"use client";

import React, { useState } from "react";
import { Button } from "@/components/ui/button";
import Link from "next/link";
import { ToggleGroup, ToggleGroupItem } from "@/components/ui/toggle-group";
import { tags } from "@/app/lib/definitions";
import { toast }from "sonner";
import { useRouter } from "next/navigation";
import { Eye, EyeOff } from 'lucide-react';

export default function SignUpPage() {
  const router = useRouter();

  const [username, setUsername] = useState("");
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [interests, setInterests] = useState<string[]>([]);
  const [showPassword, setShowPassword] = useState(false);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();

    if (!username || !name || !email || !password) {
      toast.error("Please fill in all the fields.");
      return;
    }
    if (interests.length === 0) {
      toast.error("Please select at least one interest.");
      return;
    }

    fetch('/api/user/signup', {
      method: 'POST',
      credentials: 'include',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        username,
        email,
        password,
        visibleName: name,
        userCategories: interests
      }),
    }).then(async res => {
      if (res.ok) {
        toast.success("Sign up is successfully completed.")
        router.push('/signin');
      } else {
        toast.error('Signup failed.');
      }
    })
  };

  return (
    <div className="min-h-screen flex items-center justify-center bg-gradient-to-r from-blue-500 via-purple-500 to-pink-500 py-3">
      <div className="bg-white p-8 shadow-lg rounded-xl w-full max-w-md">
        <h2 className="text-2xl font-semibold text-blue-600 mb-8 text-center">Create Account</h2>
        <form className="space-y-6" autoComplete="off" autoCorrect="off" onSubmit={handleSubmit}>
          <input
            type="text"
            placeholder="Username"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
            className="w-full border border-gray-300 p-3 rounded-lg focus:outline-none focus:border-blue-600 transition-colors"
          />
          <input
            type="text"
            placeholder="Name"
            value={name}
            onChange={(e) => setName(e.target.value)}
            className="w-full border border-gray-300 p-3 rounded-lg focus:outline-none focus:border-blue-600 transition-colors"
          />
          <input
            type="email"
            placeholder="Email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            className="w-full border border-gray-300 p-3 rounded-lg focus:outline-none focus:border-blue-600 transition-colors"
          />
          <div className="relative">
            <input
              type={showPassword ? "text" : "password"}
              placeholder="Password"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              className="w-full border border-gray-300 p-3 rounded-lg focus:outline-none focus:border-blue-600 transition-colors"
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
          {/* Interest Section */}
          <div className="mt-6">
            <p className="text-lg font-semibold text-gray-700 mb-4">What are you interested in?</p>
            <ToggleGroup
              type="multiple"
              className="flex flex-wrap gap-4"
              value={interests}
              onValueChange={setInterests}
            >
              {tags.map(tag => (
                <ToggleGroupItem
                  key={tag}
                  value={tag}
                  className="flex items-center justify-center px-10 py-4 text-sm text-gray-700 rounded-full border border-gray-300 transition-all hover:bg-blue-100 focus:outline-none focus:ring-2 focus:ring-blue-600 data-[state=on]:bg-blue-600 data-[state=on]:text-white"
                >
                  {tag}
                </ToggleGroupItem>
              ))}
            </ToggleGroup>
          </div>

          <Button type="submit" className="w-full py-3 bg-blue-600 text-white hover:bg-blue-700 transition-colors">
            Sign Up
          </Button>
        </form>
        <p className="text-sm text-center mt-4">
          Already have an account?
          <Link href="/signin" className="text-blue-600 underline hover:text-blue-800 mx-1">
            Sign in
          </Link>
        </p>
      </div>
    </div>
  );
}
