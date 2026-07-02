import { useEffect, useRef, useState } from 'react';
import type { Message, User } from '@/types';
import { ScrollArea } from '@/components/ui/scroll-area';
import { Avatar, AvatarFallback, AvatarImage } from '@/components/ui/avatar';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { format } from 'date-fns';
import { Pencil, Trash2, X, Check, Loader2 } from 'lucide-react';

interface MessageListProps {
  messages: Message[];
  currentUser: User | null;
  chat?: { participants: { userId: string; user?: User }[] } | null;
  hasMore?: boolean;
  isLoadingMore?: boolean;
  onLoadMore?: () => void;
  onEditMessage?: (messageId: string, newContent: string) => Promise<void>;
  onDeleteMessage?: (messageId: string) => Promise<void>;
}

export function MessageList({ 
    messages, 
    currentUser, 
    chat,
    hasMore, 
    isLoadingMore, 
    onLoadMore, 
    onEditMessage, 
    onDeleteMessage 
}: MessageListProps) {
  const bottomRef = useRef<HTMLDivElement>(null);
  const topRef = useRef<HTMLDivElement>(null);
  const scrollViewportRef = useRef<HTMLDivElement>(null);
  const [editingMessageId, setEditingMessageId] = useState<string | null>(null);
  const [editContent, setEditContent] = useState('');
  const [hoveredMessageId, setHoveredMessageId] = useState<string | null>(null);

  // Auto-scroll to bottom on initial load or new messages
  // For pagination (loading more), we want to keep position
  useEffect(() => {
    // Scroll to bottom when:
    // 1. Initial load (messages.length > 0 and not loading more)
    // 2. New message added (messages.length increased and not loading more)
    if (!isLoadingMore && bottomRef.current && messages.length > 0) {
      // Use setTimeout to ensure DOM is updated
      setTimeout(() => {
        bottomRef.current?.scrollIntoView({ behavior: 'smooth' });
      }, 100);
    }
  }, [messages.length, isLoadingMore]);

  useEffect(() => {
      const observer = new IntersectionObserver(
          (entries) => {
              if (entries[0].isIntersecting && hasMore && !isLoadingMore && onLoadMore) {
                  onLoadMore();
              }
          },
          { threshold: 0.1 }
      );

      if (topRef.current) {
          observer.observe(topRef.current);
      }

      return () => observer.disconnect();
  }, [hasMore, isLoadingMore, onLoadMore]);


  const startEditing = (message: Message) => {
      setEditingMessageId(message._id);
      setEditContent(message.content);
  };

  const cancelEditing = () => {
      setEditingMessageId(null);
      setEditContent('');
  };

  const saveEdit = async (messageId: string) => {
      if (onEditMessage && editContent.trim()) {
          await onEditMessage(messageId, editContent);
          setEditingMessageId(null);
      }
  };

  const handleDelete = async (messageId: string) => {
      if (onDeleteMessage && confirm('Delete this message?')) {
          await onDeleteMessage(messageId);
      }
  };

  return (
    <ScrollArea className="h-full p-4" ref={scrollViewportRef}>
      <div className="space-y-4">
        {hasMore && (
            <div ref={topRef} className="flex justify-center p-2">
                {isLoadingMore && <Loader2 className="h-4 w-4 animate-spin" />}
            </div>
        )}
        
        {messages.map((message) => {
          const isMe = String(message.senderId) === String(currentUser?.id);
          const isEditing = editingMessageId === message._id;
          const isHovered = hoveredMessageId === message._id;
          const isDeleted = message.status === 'DELETED';
          
          // Sender bilgisini bul: önce message.sender, yoksa chat participants'tan
          let sender = message.sender;
          if (!sender && chat) {
            const participant = chat.participants.find(p => String(p.userId) === String(message.senderId));
            sender = participant?.user;
          }
          
          const senderName =
            sender?.username ||
            (sender?.first_name && sender?.last_name 
              ? `${sender.first_name} ${sender.last_name}`
              : sender?.first_name || sender?.last_name || 'Unknown User');
          const senderInitial =
            (sender?.username?.[0] ||
              sender?.first_name?.[0] ||
              sender?.email?.[0] ||
              'U'
            ).toUpperCase();

          return (
            <div
              key={message._id}
              className={`flex gap-3 group ${isMe ? 'flex-row-reverse' : ''}`}
              onMouseEnter={() => setHoveredMessageId(message._id)}
              onMouseLeave={() => setHoveredMessageId(null)}
            >
              {!isMe && (
                  <Avatar className="h-8 w-8">
                    <AvatarImage src={sender?.profile_picture} />
                    <AvatarFallback>{senderInitial}</AvatarFallback>
                  </Avatar>
                )}

                <div
                  className={`flex flex-col max-w-[70%] ${
                    isMe ? 'items-end' : 'items-start'
                  }`}
                >
                  {!isMe && (
                    <span className="text-xs text-muted-foreground mb-1">{senderName}</span>
                  )}
                  <div className={`flex items-center gap-2 ${isMe ? 'flex-row-reverse' : ''}`}>
                    {/* Actions for My Messages */}
                    {isMe && !isDeleted && isHovered && !isEditing && (
                        <div className="flex gap-1 opacity-0 group-hover:opacity-100 transition-opacity">
                            <Button variant="ghost" size="icon" className="h-6 w-6" onClick={() => startEditing(message)}>
                                <Pencil className="h-3 w-3" />
                            </Button>
                            <Button variant="ghost" size="icon" className="h-6 w-6 text-destructive" onClick={() => handleDelete(message._id)}>
                                <Trash2 className="h-3 w-3" />
                            </Button>
                        </div>
                    )}

                    <div
                    className={`rounded-lg p-3 ${
                        isMe
                        ? 'bg-primary text-primary-foreground'
                        : 'bg-muted'
                    }`}
                    >
                    {isDeleted ? (
                        <p className="italic text-sm opacity-50">This message was deleted</p>
                    ) : isEditing ? (
                        <div className="flex items-center gap-2">
                            <Input 
                                value={editContent} 
                                onChange={(e) => setEditContent(e.target.value)}
                                className="h-8 text-black dark:text-white"
                                autoFocus
                            />
                            <Button size="icon" className="h-6 w-6" onClick={() => saveEdit(message._id)}>
                                <Check className="h-3 w-3" />
                            </Button>
                            <Button size="icon" variant="ghost" className="h-6 w-6" onClick={cancelEditing}>
                                <X className="h-3 w-3" />
                            </Button>
                        </div>
                    ) : (
                        <>
                            {message.messageType === 'TEXT' && <p className="whitespace-pre-wrap break-words">{message.content}</p>}
                            {message.messageType === 'FILE' && (
                                <a href={message.fileUrl} target="_blank" rel="noreferrer" className="underline hover:text-blue-200">
                                {message.content || 'Download File'}
                                </a>
                            )}
                            {message.messageType === 'IMAGE' && (
                                <img src={message.fileUrl} alt="Shared" className="max-w-full rounded" />
                            )}
                        </>
                    )}
                    </div>
                </div>
                
                <span className="text-xs text-muted-foreground mt-1">
                  {format(new Date(message.createdAt), 'HH:mm')}
                  {message.updatedAt !== message.createdAt && !isDeleted && <span className="ml-1">(edited)</span>}
                </span>
              </div>
            </div>
          );
        })}
        <div ref={bottomRef} />
      </div>
    </ScrollArea>
  );
}
