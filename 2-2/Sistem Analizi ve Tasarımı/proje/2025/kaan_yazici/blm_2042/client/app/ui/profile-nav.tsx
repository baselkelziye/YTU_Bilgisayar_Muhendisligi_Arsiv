'use client'

import Link from "next/link"
import { useState, useEffect, useRef } from "react"
import { UserCircle, PlusCircle, Settings, Users } from "lucide-react"
import LogoutButton from '@/app/ui/logout-button';
import ViewProfileButton from '@/app/ui/view-profile-button';

export default function ProfileNav() {
    const [dropdownOpen, setDropdownOpen] = useState(false)
    const dropdownRef = useRef<HTMLDivElement>(null)
  
    useEffect(() => {
      const handleClickOutside = (event: MouseEvent) => {
        if (dropdownRef.current && !dropdownRef.current.contains(event.target as Node)) {
          setDropdownOpen(false)
        }
      }
      document.addEventListener("mousedown", handleClickOutside)
      return () => {
        document.removeEventListener("mousedown", handleClickOutside)
      }
    }, [])

  return (
    <div className="relative" ref={dropdownRef}>
        <button onClick={() => setDropdownOpen(!dropdownOpen)}>
            <UserCircle className="hover:w-7 hover:h-7 w-6 h-6 text-gray-700 hover:text-blue-600 transition-all duration-300" />
        </button>   

    {dropdownOpen && (
        <div className="absolute right-0 mt-2 w-50 bg-white border border-gray-200 shadow-md rounded-md z-50">
            <ViewProfileButton />

            <Link href="/add-post" className="px-4 py-2 hover:bg-gray-100 flex items-center">
                <PlusCircle className="w-4 h-4 mr-2" />Add Post
            </Link>

            <Link href="/settings" className="px-4 py-2 hover:bg-gray-100 flex items-center">
                <Settings className="w-4 h-4 mr-2" />Settings
            </Link>

            <Link href="/create-community" className="px-4 py-2 hover:bg-gray-100 flex items-center">
                <Users className="w-4 h-4 mr-2" />Create Community
            </Link>

            <LogoutButton />
        </div>
    )}
    </div>
  )
}
