import { useEffect, useState, useRef } from 'react';
import type { Chat, User } from '@/types';
import api from '@/lib/api';
import { ScrollArea } from '@/components/ui/scroll-area';
import { Avatar, AvatarFallback, AvatarImage } from '@/components/ui/avatar';
import { socketService } from '@/lib/socket';

interface ChatListProps {
  onSelectChat: (chat: Chat, displayName?: string, displayAvatar?: string) => void;
  selectedChatId?: string;
  refreshTrigger?: number;
  currentUser: User | null;
}

export function ChatList({ onSelectChat, selectedChatId, refreshTrigger, currentUser }: ChatListProps) {
  const [chats, setChats] = useState<Chat[]>([]);
  
  const fetchChats = async () => {
    try {
      const response = await api.get('/chats/user/me');
      // Backend returns { success: true, data: [...] } or direct array
      const chatsData = response.data?.data || response.data || [];
      setChats(Array.isArray(chatsData) ? chatsData : []);
    } catch (error) {
      console.error('Failed to fetch chats', error);
      setChats([]); // Set empty array on error
    }
  };

  useEffect(() => {
    fetchChats();
  }, [refreshTrigger]);

  // Real-time chat updates
  const listenersSetupRef = useRef(false);

  useEffect(() => {
    // Prevent duplicate listener setup in Strict Mode
    if (listenersSetupRef.current) return;
    listenersSetupRef.current = true;

    const handleChatCreated = (data: { chatId: string; createdBy: string; name?: string; type: string; participantIds: string[] }) => {
      console.log('📨 Chat created event received:', data);
      // Chat listesini yenile
      fetchChats();
    };

    const handleChatDeleted = (data: { chatId: string; type: string; name?: string }) => {
      console.log('📨 Chat deleted event received:', data);
      // Chat listesini yenile
      setChats(prev => prev.filter(chat => chat._id !== data.chatId));
      fetchChats(); // Backend'den güncel listeyi al
    };

    const handleChatLeft = (data: { chatId: string; leftUserId: string; type: string }) => {
      console.log('📨 Chat left event received:', data);
      // Eğer current user chat'ten çıktıysa listeden kaldır
      if (currentUser && String(data.leftUserId) === String(currentUser.id)) {
        setChats(prev => prev.filter(chat => chat._id !== data.chatId));
      }
      // Chat listesini yenile
      fetchChats();
    };

    const handleMessageCreated = (data: { message: any; chatId: string }) => {
      console.log('📨 Message created event received:', data);
      // Chat listesini yenile (son mesaj bilgisi için)
      fetchChats();
    };

    socketService.on('chat.created', handleChatCreated);
    socketService.on('chat.deleted', handleChatDeleted);
    socketService.on('chat.left', handleChatLeft);
    socketService.on('message.created', handleMessageCreated);

    return () => {
      socketService.off('chat.created', handleChatCreated);
      socketService.off('chat.deleted', handleChatDeleted);
      socketService.off('chat.left', handleChatLeft);
      socketService.off('message.created', handleMessageCreated);
      listenersSetupRef.current = false;
    };
  }, [currentUser]);

  const getChatDisplay = (chat: Chat) => {
    if (chat.type === 'DIRECT' && currentUser) {
        // String'e çevirerek karşılaştır (userId string, currentUser.id number olabilir)
        const currentUserId = String(currentUser.id);
        const otherParticipant = chat.participants.find(p => String(p.userId) !== currentUserId);
        if (otherParticipant && otherParticipant.user) {
            // Öncelik: İsim Soyisim > Username
            const displayName = (otherParticipant.user.first_name && otherParticipant.user.last_name)
              ? `${otherParticipant.user.first_name} ${otherParticipant.user.last_name}`
              : (otherParticipant.user.username || 'Unknown User');
            return {
                name: displayName,
                avatar: otherParticipant.user.profile_picture,
                fallback: (otherParticipant.user.username?.[0] || otherParticipant.user.first_name?.[0] || '?').toUpperCase()
            };
        }
    }
    return {
        name: chat.name || 'Chat',
        avatar: chat.avatar,
        fallback: (chat.name?.[0] || 'C').toUpperCase()
    };
  };

  return (
    <ScrollArea className="h-full">
      <div className="flex flex-col gap-2 p-4">
        {chats.map((chat) => {
          const { name, avatar, fallback } = getChatDisplay(chat);
          return (
            <div
              key={chat._id}
              className={`flex items-center gap-3 p-3 rounded-lg cursor-pointer hover:bg-accent ${
                selectedChatId === chat._id ? 'bg-accent' : ''
              }`}
              onClick={() => onSelectChat(chat, name, avatar)}
            >
              <Avatar>
                <AvatarImage src={avatar} />
                <AvatarFallback>{fallback}</AvatarFallback>
              </Avatar>
              <div className="flex-1 overflow-hidden">
                <h4 className="font-medium truncate">{name}</h4>
                <p className="text-xs text-muted-foreground truncate">
                  {chat.type === 'DIRECT' ? 'Direct Message' : 'Group Chat'}
                </p>
              </div>
            </div>
          );
        })}
        {chats.length === 0 && (
            <div className="text-center text-muted-foreground p-4">
                No chats yet. Start a new one!
            </div>
        )}
      </div>
    </ScrollArea>
  );
}

