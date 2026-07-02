import { useState } from 'react';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogTrigger,
  DialogFooter,
} from '@/components/ui/dialog';
import { Tabs, TabsContent, TabsList, TabsTrigger } from '@/components/ui/tabs';
import { UserSearch } from './UserSearch';
import { Badge } from '@/components/ui/badge';
import { X } from 'lucide-react';
import api from '@/lib/api';
import type { User } from '@/types';

interface NewChatDialogProps {
  onChatCreated: () => void;
  trigger?: React.ReactNode;
}

export function NewChatDialog({ onChatCreated, trigger }: NewChatDialogProps) {
  const [open, setOpen] = useState(false);
  const [isLoading, setIsLoading] = useState(false);

  // Direct Chat State
  const [selectedDirectUser, setSelectedDirectUser] = useState<User | null>(null);

  // Group Chat State
  const [groupName, setGroupName] = useState('');
  const [selectedGroupUsers, setSelectedGroupUsers] = useState<User[]>([]);

  const handleCreateDirect = async () => {
    if (!selectedDirectUser) return;
    setIsLoading(true);
    try {
      await api.post('/chats/direct', { targetUserId: selectedDirectUser.id });
      setOpen(false);
      onChatCreated();
      setSelectedDirectUser(null);
    } catch (error) {
      console.error(error);
      alert('Failed to create direct chat');
    } finally {
      setIsLoading(false);
    }
  };

  const handleCreateGroup = async () => {
    if (!groupName || selectedGroupUsers.length === 0) return;
    setIsLoading(true);
    try {
      const ids = selectedGroupUsers.map(u => u.id);
      await api.post('/chats/group', { name: groupName, participantIds: ids });
      setOpen(false);
      onChatCreated();
      setGroupName('');
      setSelectedGroupUsers([]);
    } catch (error) {
      console.error(error);
      alert('Failed to create group chat');
    } finally {
      setIsLoading(false);
    }
  };

  const handleGroupUserSelect = (user: User) => {
      if (!selectedGroupUsers.find(u => u.id === user.id)) {
          setSelectedGroupUsers([...selectedGroupUsers, user]);
      }
  };

  const removeGroupUser = (userId: string) => {
      setSelectedGroupUsers(selectedGroupUsers.filter(u => u.id !== userId));
  };

  return (
    <Dialog open={open} onOpenChange={setOpen}>
      <DialogTrigger asChild>
        {trigger || <Button variant="outline">New Chat</Button>}
      </DialogTrigger>
      <DialogContent className="sm:max-w-[425px]">
        <DialogHeader>
          <DialogTitle>Start a new chat</DialogTitle>
        </DialogHeader>
        <Tabs defaultValue="direct" className="w-full">
          <TabsList className="grid w-full grid-cols-2">
            <TabsTrigger value="direct">Direct Message</TabsTrigger>
            <TabsTrigger value="group">Group Chat</TabsTrigger>
          </TabsList>
          
          <TabsContent value="direct">
            <div className="grid gap-4 py-4">
              <div className="grid gap-2">
                <Label>Search User</Label>
                {selectedDirectUser ? (
                    <div className="flex items-center justify-between p-2 border rounded-md">
                        <span className="font-medium">{selectedDirectUser.username}</span>
                        <Button variant="ghost" size="sm" onClick={() => setSelectedDirectUser(null)}>
                            <X className="h-4 w-4" />
                        </Button>
                    </div>
                ) : (
                    <UserSearch onSelect={setSelectedDirectUser} />
                )}
              </div>
            </div>
            <DialogFooter>
              <Button onClick={handleCreateDirect} disabled={isLoading || !selectedDirectUser}>
                {isLoading ? 'Creating...' : 'Start Chat'}
              </Button>
            </DialogFooter>
          </TabsContent>

          <TabsContent value="group">
            <div className="grid gap-4 py-4">
              <div className="grid gap-2">
                <Label htmlFor="name">Group Name</Label>
                <Input
                  id="name"
                  value={groupName}
                  onChange={(e) => setGroupName(e.target.value)}
                  placeholder="My Group"
                />
              </div>
              <div className="grid gap-2">
                <Label>Add Participants</Label>
                <UserSearch 
                    onSelect={handleGroupUserSelect} 
                    selectedUserIds={selectedGroupUsers.map(u => u.id)}
                    placeholder="Search to add..."
                />
                <div className="flex flex-wrap gap-2 mt-2">
                    {selectedGroupUsers.map(user => (
                        <Badge key={user.id} variant="secondary" className="flex items-center gap-1">
                            {user.username}
                            <X 
                                className="h-3 w-3 cursor-pointer" 
                                onClick={() => removeGroupUser(user.id)}
                            />
                        </Badge>
                    ))}
                </div>
              </div>
            </div>
            <DialogFooter>
              <Button onClick={handleCreateGroup} disabled={isLoading || !groupName || selectedGroupUsers.length === 0}>
                {isLoading ? 'Creating...' : 'Create Group'}
              </Button>
            </DialogFooter>
          </TabsContent>
        </Tabs>
      </DialogContent>
    </Dialog>
  );
}
