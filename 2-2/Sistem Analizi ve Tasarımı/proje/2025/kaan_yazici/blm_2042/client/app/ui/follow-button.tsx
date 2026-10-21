'use client'

import { CheckCircleIcon } from "@heroicons/react/24/outline";
import { Button } from "@/components/ui/button";
import { useState } from "react";

export default function FollowButton({ username, isFollow }: { username: string, isFollow: boolean }) {
  const [isFollowing, setIsFollowing] = useState(isFollow);

  async function handleClick() {
    const newState = !isFollowing;
    setIsFollowing(newState);

    const endpoint = newState ? 'follow' : 'unfollow';

    await fetch(`/api/user/${username}/${endpoint}`, {
      method: 'POST',
      credentials: 'include',
      body: JSON.stringify({ owner_username: username }),
    });
  }

  return (
    <Button
      variant="outline"
      onClick={handleClick}
      className={`flex items-center gap-2 text-sm rounded-lg p-2 transition-colors duration-200 
        ${isFollowing ? 'text-blue-600 border-blue-600' : 'text-gray-700 border-gray-400'} 
        hover:border-blue-600 hover:text-blue-600`}
    >
      {isFollowing ? (
        <>
          <CheckCircleIcon className="w-4" /> Following
        </>
      ) : (
        <>Follow</>
      )}
    </Button>
  );
}
