import { useState, useEffect } from 'react';
import { useDebounce } from '@/hooks/use-debounce';
import api from '@/lib/api';
import type { User } from '@/types';
import { Input } from '@/components/ui/input';
import { ScrollArea } from '@/components/ui/scroll-area';
import { Avatar, AvatarFallback, AvatarImage } from '@/components/ui/avatar';
import { Check, Loader2 } from 'lucide-react';

interface UserSearchProps {
  onSelect: (user: User) => void;
  selectedUserIds?: string[];
  className?: string;
  placeholder?: string;
}

export function UserSearch({ onSelect, selectedUserIds = [], className, placeholder = "Search users..." }: UserSearchProps) {
  const [query, setQuery] = useState('');
  const debouncedQuery = useDebounce(query, 300);
  const [results, setResults] = useState<User[]>([]);
  const [isLoading, setIsLoading] = useState(false);
  const [showResults, setShowResults] = useState(false);

  useEffect(() => {
    const searchUsers = async () => {
      if (!debouncedQuery.trim()) {
        setResults([]);
        return;
      }

      setIsLoading(true);
      try {
        const response = await api.get(`/users/search?q=${encodeURIComponent(debouncedQuery)}`);
        // Handle both possible response formats
        const data = response.data.data || response.data || [];
        setResults(Array.isArray(data) ? data : []);
        setShowResults(true);
      } catch (error) {
        console.error('Failed to search users:', error);
        setResults([]);
      } finally {
        setIsLoading(false);
      }
    };

    searchUsers();
  }, [debouncedQuery]);

  const handleSelect = (user: User) => {
    onSelect(user);
    setQuery('');
    setResults([]);
    setShowResults(false);
  };

  return (
    <div className={`relative ${className}`}>
      <div className="relative">
        <Input
          placeholder={placeholder}
          value={query}
          onChange={(e) => setQuery(e.target.value)}
          onFocus={() => {
              if (results.length > 0) setShowResults(true);
          }}
        />
        {isLoading && (
          <div className="absolute right-3 top-2.5">
            <Loader2 className="h-4 w-4 animate-spin text-muted-foreground" />
          </div>
        )}
      </div>

      {showResults && results.length > 0 && (
        <div className="absolute z-50 mt-1 w-full rounded-md border bg-popover text-popover-foreground shadow-md outline-none animate-in fade-in-0 zoom-in-95">
          <ScrollArea className="h-[200px]">
            <div className="p-1">
              {results.map((user) => {
                const isSelected = selectedUserIds.includes(user.id);
                return (
                  <div
                    key={user.id}
                    className={`flex items-center gap-2 rounded-sm px-2 py-1.5 text-sm outline-none cursor-pointer hover:bg-accent hover:text-accent-foreground ${
                        isSelected ? 'opacity-50 pointer-events-none' : ''
                    }`}
                    onClick={() => handleSelect(user)}
                  >
                    <Avatar className="h-6 w-6">
                      <AvatarImage src={user.profile_picture} />
                      <AvatarFallback>{user.username[0].toUpperCase()}</AvatarFallback>
                    </Avatar>
                    <div className="flex flex-col flex-1">
                        <span className="font-medium">{user.username}</span>
                        <span className="text-xs text-muted-foreground">{user.first_name} {user.last_name}</span>
                    </div>
                    {isSelected && <Check className="h-4 w-4" />}
                  </div>
                );
              })}
            </div>
          </ScrollArea>
        </div>
      )}
      {showResults && query && !isLoading && results.length === 0 && (
          <div className="absolute z-50 mt-1 w-full p-2 text-sm text-center text-muted-foreground border bg-popover rounded-md shadow-md">
              No users found.
          </div>
      )}
    </div>
  );
}

