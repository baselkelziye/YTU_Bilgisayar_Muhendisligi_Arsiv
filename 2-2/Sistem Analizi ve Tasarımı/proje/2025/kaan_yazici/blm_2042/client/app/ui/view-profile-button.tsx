import { User } from "lucide-react";
import { useRouter } from 'next/navigation';

export default function ViewProfile() {
  const router = useRouter();

  const handleClick = () => {
    fetch('/api/user/profile', {
      method: 'POST',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();
      const username = data.username;
      if (res.ok) {
        router.push(`/user/${username}`);
      }
    });
  }

  return (
    <button onClick={handleClick} className="w-full px-4 py-2 hover:bg-gray-100 flex items-center">
      <User className="w-4 h-4 mr-2" />View Profile
    </button>
  );
}

