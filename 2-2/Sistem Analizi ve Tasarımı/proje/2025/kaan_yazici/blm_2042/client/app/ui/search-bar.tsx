'use client'

import React, { useState } from "react"
import { Search } from "lucide-react"
import Link from "next/link"
import { useDebouncedCallback } from 'use-debounce';
import { useSearchParams, usePathname, useRouter } from 'next/navigation';

type searchedUser = {
    username: string,
    profilePicId: string,
};

export default function SearchBar() {
    const [searchTerm, setSearchTerm] = useState("");
    const [searchResults, setSearchResults] = useState<searchedUser[]>([]);
    const [showSearchResults, setShowSearchResults] = useState(false);
    const [profilePics, setProfilePics] = useState<Record<string, string>>({});

    const searchParams = useSearchParams();
    const pathName = usePathname();
    const router = useRouter();

    const handleSearch = useDebouncedCallback((term: string): void => {
        const params = new URLSearchParams(searchParams);
        if (term) {
            params.set('search', term);
        } else {
            params.delete('search');
        }
        router.replace(`${pathName}?${String(params)}`);

        if (term.trim()) {
            fetch(`/api/search/${term}`, {
                credentials: 'include',
            }).then(async res => {
                const users = await res.json();
                if (users.length) {
                    const parsedUsers = users.map((user: any) => ({
                        username: user.username,
                        profilePicId: user.profilePhotoId,
                    })) as searchedUser[];
                    setSearchResults(parsedUsers);

                    parsedUsers.forEach(async (user) => {
                        if (!user.profilePicId) {
                            return;
                        }
                        const res = await fetch(`/api/media/${user.profilePicId}`);
                        const blob = await res.blob();
                        const imageUrl = URL.createObjectURL(blob);
                        setProfilePics(prev => ({ ...prev, [user.profilePicId]: imageUrl }));
                        console.log('profile pics: ', profilePics);
                    })
                }
            });
        }
    }, 300);
    return (
      <div className="flex-1 flex justify-center mx-2">
          <div className="relative w-full max-w-md">
              <div className="flex items-center bg-gray-100 border border-gray-300 rounded-md px-3 py-2">
                  <Search className="w-4 h-4 text-gray-500 mr-2" />
                  <input
                    type="text"
                    placeholder="Search..."
                    value={searchTerm}
                    onChange={(e) => {
                        const term = e.target.value
                        setSearchTerm(term)
                        handleSearch(term)
                        setShowSearchResults(!!term.trim())
                    }}
                    className="w-full bg-transparent focus:text-black text-muted-foreground focus:outline-none text-sm"
                  />
              </div>

              {showSearchResults && (
                <div className="absolute top-full mt-1 w-full bg-white border border-gray-200 rounded-md shadow z-50">
                    {searchResults.length > 0 ? (
                      searchResults.map((user) => {
                          const imageSrc = user.profilePicId && profilePics[user.profilePicId]
                            ? profilePics[user.profilePicId]
                            : '/user-circle-svgrepo-com.svg'

                          return (
                            <Link
                              key={user.username}
                              href={`/user/${user.username}`}
                              className="block px-4 py-2 hover:bg-gray-100 text-sm"
                              onClick={() => {
                                  setSearchTerm("")
                                  setShowSearchResults(false)
                              }}
                            >
                                <div className="flex items-center gap-2">
                                    <img
                                      src={imageSrc}
                                      alt={user.username}
                                      className="w-8 h-8 rounded-full object-cover"
                                    />
                                    <span>{user.username}</span>
                                </div>
                            </Link>
                          )
                      })
                    ) : (
                      <div className="px-4 py-2 text-sm text-gray-500">No users found</div>
                    )}
                </div>
              )}
          </div>
      </div>
    )
}
