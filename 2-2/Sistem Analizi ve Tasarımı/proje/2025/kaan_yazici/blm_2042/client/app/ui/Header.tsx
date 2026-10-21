'use client'

import Link from "next/link"
import { Star, Users } from "lucide-react"
import ProfileNav from "@/app/ui/profile-nav"
import SearchBar from "@/app/ui/search-bar"
import { Suspense } from 'react';

export default function Header() {
    
    return (
        <header className="transition-shadow duration-300 hover:shadow-gray-300 w-full flex items-center justify-between px-6 py-4 bg-white/90 backdrop-blur-md shadow-lg border-b border-gray-200 sticky top-0 z-50">
            <Link href="/" className="flex items-center space-x-2 text-xl hover:text-2xl transition-all duration-300">
                <Star className="text-blue-600 w-6 h-6" />
                <h1 className=" font-bold text-blue-700 hidden sm:block">YildizNet</h1>
            </Link>
          <Suspense fallback={<div>Loading search...</div>}>
            <SearchBar />
          </Suspense>
            <nav className="flex items-center space-x-6 ml-auto">
              <div className="flex items-center space-x-4">
                <Link href="/community">
                    <Users className="hover:w-7 hover:h-7 w-6 h-6 text-gray-700 hover:text-blue-600 transition-all duration-300" />
                </Link>
                <ProfileNav />
              </div>
            </nav>
        </header>
    )
}
