import { useState } from 'react';
import { Button } from '@/components/ui/button';
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogTrigger,
} from '@/components/ui/dialog';
import { Avatar, AvatarFallback, AvatarImage } from '@/components/ui/avatar';
import { ScrollArea } from '@/components/ui/scroll-area';
import { UserSearch } from './UserSearch';
import type { Chat, User } from '@/types';
import { useAuth } from '@/hooks/use-auth';
import api from '@/lib/api';
import { Loader2, Trash2, Shield, Settings } from 'lucide-react';

interface ChatDetailsDialogProps {
  chat: Chat;
  onUpdate: () => void;
  onDelete?: () => void;
  trigger?: React.ReactNode;
}

export function ChatDetailsDialog({ chat, onUpdate, onDelete, trigger }: ChatDetailsDialogProps) {
  const { user: currentUser } = useAuth();
  const [open, setOpen] = useState(false);
  const [isLoading, setIsLoading] = useState(false);
  const [isAdding, setIsAdding] = useState(false);
  const [isDeleting, setIsDeleting] = useState(false);
  const [isLeaving, setIsLeaving] = useState(false);

  const isAdmin = chat.participants.some(
    (p) => String(p.userId) === String(currentUser?.id) && p.role === 'ADMIN'
  );
  const isCreator = String(chat.createdBy) === String(currentUser?.id);
  const canDelete = chat.type === 'DIRECT' || isAdmin || isCreator;

  const handleLeaveGroup = async () => {
    if (!confirm('Are you sure you want to leave this group?')) return;
    setIsLeaving(true);
    try {
      await api.post(`/chats/${chat._id}/leave`);
      setOpen(false);
      onDelete?.();
    } catch (error: any) {
      console.error('Failed to leave group', error);
      alert(error.response?.data?.message || 'Failed to leave group');
    } finally {
      setIsLeaving(false);
    }
  };

  const handleAddParticipant = async (user: User) => {
    setIsLoading(true);
    try {
      await api.post(`/chats/${chat._id}/participants`, { userId: user.id });
      onUpdate();
      setIsAdding(false);
    } catch (error) {
      console.error('Failed to add participant', error);
      alert('Failed to add participant');
    } finally {
      setIsLoading(false);
    }
  };

  const handleRemoveParticipant = async (userId: string) => {
    if (!confirm('Are you sure you want to remove this user?')) return;
    setIsLoading(true);
    try {
      await api.delete(`/chats/${chat._id}/participants/${userId}`);
      onUpdate();
    } catch (error) {
      console.error('Failed to remove participant', error);
      alert('Failed to remove participant');
    } finally {
      setIsLoading(false);
    }
  };

  const handleDeleteChat = async () => {
    const confirmMessage = chat.type === 'DIRECT' 
      ? 'Are you sure you want to leave this chat?'
      : 'Are you sure you want to delete this chat? This action cannot be undone.';
    
    if (!confirm(confirmMessage)) return;
    
    setIsDeleting(true);
    try {
      await api.delete(`/chats/${chat._id}`);
      setOpen(false);
      if (onDelete) {
        onDelete();
      }
    } catch (error: any) {
      console.error('Failed to delete chat', error);
      alert(error.response?.data?.message || 'Failed to delete chat');
    } finally {
      setIsDeleting(false);
    }
  };

  return (
    <Dialog open={open} onOpenChange={setOpen}>
      <DialogTrigger asChild>
        {trigger || (
          <Button variant="ghost" size="icon">
            <Settings className="h-5 w-5" />
          </Button>
        )}
      </DialogTrigger>
      <DialogContent className="sm:max-w-[500px]">
        <DialogHeader>
          <DialogTitle>Chat Details</DialogTitle>
        </DialogHeader>
        
        <div className="space-y-6">
            <div className="flex items-center gap-4">
                <Avatar className="h-16 w-16">
                    <AvatarImage src={chat.avatar} />
                    <AvatarFallback>{chat.name?.[0]?.toUpperCase() || 'C'}</AvatarFallback>
                </Avatar>
                <div>
                    <h2 className="text-xl font-semibold">{chat.name}</h2>
                    <p className="text-sm text-muted-foreground">{chat.participants.length} participants</p>
                </div>
            </div>

            <div className="space-y-4">
                <div className="flex items-center justify-between">
                    <h3 className="font-medium">Participants</h3>
                    {isAdmin && chat.type === 'GROUP' && (
                        <Button variant="outline" size="sm" onClick={() => setIsAdding(!isAdding)}>
                            {isAdding ? 'Cancel' : 'Add Participant'}
                        </Button>
                    )}
                </div>

                {isAdding && (
                    <div className="p-4 border rounded-md bg-muted/50">
                        <UserSearch 
                            onSelect={handleAddParticipant}
                            selectedUserIds={chat.participants.map(p => p.userId)}
                            placeholder="Search user to add..." 
                        />
                    </div>
                )}

                <ScrollArea className="h-[300px] pr-4">
                    <div className="space-y-2">
                        {chat.participants.map((p) => (
                            <div key={p.userId} className="flex items-center justify-between p-2 rounded-lg hover:bg-muted/50">
                                <div className="flex items-center gap-3">
                                    <Avatar>
                                        <AvatarImage src={p.user?.profile_picture} />
                                        <AvatarFallback>{p.user?.username?.[0]?.toUpperCase() || 'U'}</AvatarFallback>
                                    </Avatar>
                                    <div>
                                        <div className="flex items-center gap-2">
                                            <span className="font-medium">{p.user?.username || 'Unknown User'}</span>
                                            {p.role === 'ADMIN' && <Shield className="h-3 w-3 text-yellow-500" />}
                                        </div>
                                        <p className="text-xs text-muted-foreground">{p.user?.email}</p>
                                    </div>
                                </div>
                                {isAdmin && String(currentUser?.id) !== String(p.userId) && (
                                    <Button 
                                        variant="ghost" 
                                        size="icon" 
                                        className="text-destructive hover:text-destructive hover:bg-destructive/10"
                                        onClick={() => handleRemoveParticipant(p.userId)}
                                        disabled={isLoading}
                                    >
                                        {isLoading ? <Loader2 className="h-4 w-4 animate-spin" /> : <Trash2 className="h-4 w-4" />}
                                    </Button>
                                )}
                            </div>
                        ))}
                    </div>
                </ScrollArea>
            </div>

            <div className="pt-4 border-t space-y-2">
              {chat.type === 'GROUP' && (
                <Button
                  variant="destructive"
                  className="w-full"
                  onClick={handleLeaveGroup}
                  disabled={isLeaving}
                >
                  {isLeaving ? (
                    <>
                      <Loader2 className="mr-2 h-4 w-4 animate-spin" />
                      Leaving...
                    </>
                  ) : (
                    <>
                      <Trash2 className="mr-2 h-4 w-4" />
                      Leave Group
                    </>
                  )}
                </Button>
              )}

              {canDelete && (
                <Button
                  variant="destructive"
                  className="w-full"
                  onClick={handleDeleteChat}
                  disabled={isDeleting}
                >
                  {isDeleting ? (
                    <>
                      <Loader2 className="mr-2 h-4 w-4 animate-spin" />
                      Deleting...
                    </>
                  ) : (
                    <>
                      <Trash2 className="mr-2 h-4 w-4" />
                      {chat.type === 'DIRECT' ? 'Leave Chat' : 'Delete Chat'}
                    </>
                  )}
                </Button>
              )}
            </div>
        </div>
      </DialogContent>
    </Dialog>
  );
}

