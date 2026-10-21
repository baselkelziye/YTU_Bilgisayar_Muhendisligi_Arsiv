'use client'

import { Button } from "@/components/ui/button";
import { MinusCircle } from "lucide-react";
import { useState } from "react";

export default function BlockButton({ username, isBlock }: { username: string; isBlock: boolean }) {
  const [isBlocked, setIsBlocked] = useState(isBlock);

  async function handleClick() {
    const newState = !isBlocked;
    setIsBlocked(newState);

    const endpoint = newState ? 'block' : 'unblock';

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
      className="ml-1 p-2 border-2 rounded-md text-red-600 border-red-600 hover:bg-red-100 hover:text-red-700 transition-all duration-200 ease-in-out"
    >
      <MinusCircle className="w-5 text-red-600 hover:text-red-700" />
    </Button>
  );
}
