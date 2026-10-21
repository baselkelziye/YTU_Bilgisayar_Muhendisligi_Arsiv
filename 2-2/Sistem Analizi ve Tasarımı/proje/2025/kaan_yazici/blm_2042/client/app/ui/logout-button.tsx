import { toast } from 'sonner';
import { useRouter } from 'next/navigation';
import { LogOut } from "lucide-react";

export default function LogoutButton() {
  const router = useRouter();

  const handleLogout = () => {
    fetch('/api/logout', {
      method: 'POST',
      credentials: 'include',
    }).then(async res => {
      if (res.ok) {
        toast.success('Logged out.');
        setTimeout(() => {
          router.push('/signin');
        }, 500);
      } else {
        toast.error('Logout failed.');
      }
    });
  }

  return (
    <button onClick={handleLogout} className="w-full px-4 py-2 hover:bg-red-100 text-red-600 flex items-center">
      <LogOut className="w-4 h-4 mr-2" />Log Out
    </button>
  );
}