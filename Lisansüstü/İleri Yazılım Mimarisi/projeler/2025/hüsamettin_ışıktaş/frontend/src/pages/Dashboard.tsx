import { useEffect, useState, useCallback, useRef } from 'react';
import { useAuth } from '@/hooks/use-auth';
import { socketService } from '@/lib/socket';
import { ChatList } from '@/components/chat/ChatList';
import { MessageList } from '@/components/chat/MessageList';
import { MessageInput } from '@/components/chat/MessageInput';
import { NewChatDialog } from '@/components/chat/NewChatDialog';
import { Button } from '@/components/ui/button';
import type { Chat, Message } from '@/types';
import api from '@/lib/api';
import { ProfileDialog } from '@/components/profile/ProfileDialog';
import { ChatDetailsDialog } from '@/components/chat/ChatDetailsDialog';
import { NotificationPopover } from '@/components/notification/NotificationPopover';
import { LogOut, Plus } from 'lucide-react';
import { useTheme } from '@/context/ThemeContext';
import { Moon, Sun } from 'lucide-react';

export default function Dashboard() {
  const { user, token, logout } = useAuth();
  const { theme, toggleTheme } = useTheme();
  const [selectedChat, setSelectedChat] = useState<Chat | null>(null);
  const [messages, setMessages] = useState<Message[]>([]);
  const [refreshChats, setRefreshChats] = useState(0);
  
  // Pagination State
  const [page, setPage] = useState(1);
  const [hasMore, setHasMore] = useState(true);
  const [isLoadingMore, setIsLoadingMore] = useState(false);

  // Debug: Check if component is rendering
  console.log('Dashboard rendering', { user, token });
  
  // UI Display State
  const [chatDisplayName, setChatDisplayName] = useState('');
  const [chatDisplayAvatar, setChatDisplayAvatar] = useState<string | undefined>(undefined);

  const socketConnectedRef = useRef(false);

  useEffect(() => {
    if (token && !socketConnectedRef.current) {
      socketService.connect(token);
      socketConnectedRef.current = true;
    }
    return () => {
      if (socketConnectedRef.current) {
        socketService.disconnect();
        socketConnectedRef.current = false;
      }
    };
  }, [token]);


  const fetchMessages = useCallback(async (chatId: string, pageNum = 1) => {
    if (pageNum > 1) setIsLoadingMore(true);
    try {
      const response = await api.get(`/messages/chat/${chatId}?page=${pageNum}&limit=50`);
      // Backend returns { success: true, data: [...] } or direct array
      const messagesData = response.data?.data || response.data || [];
      const messagesArray = Array.isArray(messagesData) ? messagesData : [];
      
      // Assuming 50 is the limit
      setHasMore(messagesArray.length === 50);

      setMessages(prev => {
          if (pageNum === 1) {
              // Initial load: backend already returns oldest first, newest last
              // So we keep them as is - oldest at top, newest at bottom
              return messagesArray;
          } else {
              // Load more: prepend older messages (they come in correct order from backend)
              return [...messagesArray, ...prev];
          }
      });
    } catch (error) {
      console.error('Failed to fetch messages', error);
      if (pageNum === 1) setMessages([]);
    } finally {
        setIsLoadingMore(false);
    }
  }, []);

  const refreshSelectedChat = async () => {
      if (!selectedChat) return;
      try {
          const response = await api.get(`/chats/${selectedChat._id}`);
          if (response.data.success) {
              setSelectedChat(response.data.data);
          }
      } catch (error) {
          console.error('Failed to refresh chat', error);
      }
  };

  const handleChatSelect = (chat: Chat, name?: string, avatar?: string) => {
      setSelectedChat(chat);
      setChatDisplayName(name || chat.name || 'Chat');
      setChatDisplayAvatar(avatar || chat.avatar);
      setMessages([]);
      setPage(1);
      setHasMore(true);
      fetchMessages(chat._id, 1);
  };

  // Get other participant's status for DIRECT chats
  const getOtherParticipantStatus = () => {
      if (!selectedChat || selectedChat.type !== 'DIRECT' || !user) return null;
      const otherParticipant = selectedChat.participants.find(
          p => String(p.userId) !== String(user.id)
      );
      return otherParticipant?.user?.status_message || null;
  };

  const handleLoadMore = () => {
      if (!selectedChat || isLoadingMore || !hasMore) return;
      const nextPage = page + 1;
      setPage(nextPage);
      fetchMessages(selectedChat._id, nextPage);
  };

  const handleEditMessage = async (messageId: string, newContent: string) => {
      try {
          await api.put(`/messages/${messageId}`, { content: newContent });
          // Update local state
          setMessages(prev => prev.map(m => 
              m._id === messageId ? { ...m, content: newContent, updatedAt: new Date().toISOString() } : m
          ));
      } catch (error) {
          console.error('Failed to edit message', error);
          alert('Failed to edit message');
      }
  };

  const handleDeleteMessage = async (messageId: string) => {
      try {
          await api.delete(`/messages/${messageId}`);
          // Update local state - mark as deleted or remove?
          // API returns updated message usually, let's mark as DELETED
          setMessages(prev => prev.map(m => 
              m._id === messageId ? { ...m, status: 'DELETED' } : m
          ));
      } catch (error) {
          console.error('Failed to delete message', error);
          alert('Failed to delete message');
      }
  };

  const listenersSetupRef = useRef(false);

  useEffect(() => {
    // Prevent duplicate listener setup in Strict Mode
    if (listenersSetupRef.current) return;
    listenersSetupRef.current = true;

    console.log('Setting up real-time listeners, selectedChat:', selectedChat?._id);
    
    // Listen for new messages via message.created event (direct from websocket)
    const handleMessageCreated = (data: { message: Message; chatId: string }) => {
      console.log('📨 Message created event received:', data);
      const { message, chatId } = data;
      
      // Seçili chat'e ait mesaj mı kontrol et
      if (selectedChat && selectedChat._id === chatId) {
        setMessages(prev => {
          // Mesaj zaten var mı kontrol et
          const exists = prev.some(m => m._id === message._id);
          if (exists) {
            console.log('Message already exists, skipping');
            return prev;
          }
          
          console.log('Adding new message to state:', message._id);
          
          // Sender bilgisini chat participants'tan bul (eğer yoksa)
          if (!message.sender && selectedChat.participants) {
            const sender = selectedChat.participants.find(p => String(p.userId) === String(message.senderId))?.user;
            if (sender) {
              message.sender = sender;
            }
          }
          
          return [...prev, message];
        });
      }
      
      // Chat listesini de güncelle (son mesaj bilgisi için)
      setRefreshChats(prev => prev + 1);
    };

    // Listen for notifications (fallback)
    const handleNotification = (notification: { 
      type: string; 
      data?: any;
    }) => {
      console.log('🔔 Notification received:', notification);
      
      if (notification.type === 'MESSAGE' && notification.data) {
        const data = notification.data;
        const chatId = data.chatId;
        
        // Seçili chat'e ait mesaj mı kontrol et
        if (selectedChat && selectedChat._id === chatId) {
          // Mesaj verisini oluştur
          const messageData = data.message || data;
          const messageId = messageData._id || data.messageId || messageData.messageId;
          
          if (messageId) {
            setMessages(prev => {
              const exists = prev.some(m => m._id === messageId);
              if (exists) {
                return prev;
              }
              
              const senderId = messageData.senderId || data.senderId;
              const sender = selectedChat.participants.find(p => String(p.userId) === String(senderId))?.user;
              
              const newMessage: Message = {
                _id: messageId,
                chatId,
                senderId: senderId || messageData.senderId,
                content: messageData.content || data.content,
                messageType: (messageData.messageType || data.messageType || 'TEXT') as 'TEXT' | 'FILE' | 'IMAGE' | 'VIDEO',
                fileUrl: messageData.fileUrl || data.fileUrl,
                status: (messageData.status || data.status || 'SENT') as 'SENT' | 'DELIVERED' | 'READ' | 'DELETED',
                createdAt: messageData.createdAt || data.createdAt || new Date().toISOString(),
                updatedAt: messageData.updatedAt || messageData.createdAt || data.createdAt || new Date().toISOString(),
                sender: sender || undefined,
              };
              
              return [...prev, newMessage];
            });
          } else {
            fetchMessages(chatId, 1);
          }
        }
        
        // Chat listesini de güncelle
        setRefreshChats(prev => prev + 1);
      }
    };

    // Listen for chat deletion events
    const handleChatDeleted = (data: { chatId: string; type: string; name?: string }) => {
      console.log('📨 Chat deleted event received:', data);
      // Eğer silinen chat seçili chat ise, seçimi temizle
      if (selectedChat && selectedChat._id === data.chatId) {
        setSelectedChat(null);
        setMessages([]);
        setChatDisplayName('');
        setChatDisplayAvatar(undefined);
      }
      // Chat listesini yenile
      setRefreshChats(prev => prev + 1);
    };

    const handleChatLeft = (data: { chatId: string; leftUserId: string; type: string }) => {
      console.log('📨 Chat left event received:', data);
      // Eğer current user chat'ten çıktıysa ve seçili chat ise, seçimi temizle
      if (user && String(data.leftUserId) === String(user.id) && selectedChat && selectedChat._id === data.chatId) {
        setSelectedChat(null);
        setMessages([]);
        setChatDisplayName('');
        setChatDisplayAvatar(undefined);
      }
      // Chat listesini yenile
      setRefreshChats(prev => prev + 1);
    };

    // Register listeners
    socketService.on('message.created', handleMessageCreated);
    socketService.on('chat.deleted', handleChatDeleted);
    socketService.on('chat.left', handleChatLeft);
    socketService.on('notification', handleNotification);
    
    return () => {
      socketService.off('message.created', handleMessageCreated);
      socketService.off('chat.deleted', handleChatDeleted);
      socketService.off('chat.left', handleChatLeft);
      socketService.off('notification', handleNotification);
      listenersSetupRef.current = false;
    };
  }, [selectedChat, fetchMessages, user]);

  const handleSendMessage = async (content: string, type: 'TEXT' | 'FILE' | 'IMAGE' | 'VIDEO', file?: File) => {
    if (!selectedChat || !user) return;

    console.log('📤 Sending message:', { content, type, chatId: selectedChat._id });

    // Optimistic update - mesajı hemen state'e ekle
    const tempId = `temp-${Date.now()}`;
    const optimisticMessage: Message = {
      _id: tempId,
      chatId: selectedChat._id,
      senderId: user.id,
      content,
      messageType: type,
      fileUrl: file ? URL.createObjectURL(file) : undefined,
      status: 'SENT',
      createdAt: new Date().toISOString(),
      updatedAt: new Date().toISOString(),
      sender: user,
    };

    console.log('📝 Adding optimistic message:', tempId);
    setMessages(prev => [...prev, optimisticMessage]);

    try {
      let fileUrl = '';
      if (file) {
        const formData = new FormData();
        formData.append('file', file);
        const uploadResponse = await api.post('/files/upload', formData, {
          headers: { 'Content-Type': 'multipart/form-data' },
        });
        
        const fileId = uploadResponse.data._id;
        fileUrl = `/api/files/${fileId}/download`; 
      }

      console.log('🌐 Calling API to send message');
      const response = await api.post('/messages', {
        chatId: selectedChat._id,
        content: content,
        messageType: type,
        fileUrl: fileUrl || undefined,
      });
      
      console.log('✅ Message sent successfully, response:', response.data);
      
      // Gerçek mesaj geldiğinde optimistic message'ı gerçek mesajla değiştir
      const realMessage = response.data?.data || response.data;
      if (realMessage) {
        console.log('🔄 Replacing optimistic message with real message:', realMessage._id);
        setMessages(prev => prev.map(m => 
          m._id === tempId ? { ...realMessage, sender: user } : m
        ));
      } else {
        console.log('⚠️ No message data in response, fetching messages');
        // Gerçek mesaj gelmediyse fetch et
        fetchMessages(selectedChat._id, 1);
      }
    } catch (error) {
      console.error('❌ Failed to send message', error);
      // Hata durumunda optimistic message'ı kaldır
      setMessages(prev => prev.filter(m => m._id !== tempId));
      alert('Failed to send message');
    }
  };

  const handleChatCreated = () => {
      setRefreshChats(prev => prev + 1);
  };

  return (
    <div className="flex h-screen bg-background">
      {/* Sidebar */}
      <div className="w-80 border-r flex flex-col">
        <div className="p-4 border-b flex justify-between items-center bg-muted/20">
            <ProfileDialog trigger={
                <div className="flex items-center gap-2 overflow-hidden cursor-pointer hover:opacity-80 transition-opacity flex-1 min-w-0" role="button">
                    <div className="h-8 w-8 rounded-full bg-primary/10 flex items-center justify-center text-primary font-bold shrink-0">
                        {user?.first_name?.[0] || user?.username?.[0] || 'U'}
                    </div>
                    <div className="flex flex-col min-w-0 flex-1">
                        <span className="font-semibold truncate">{user?.username}</span>
                        {user?.status_message && (
                            <span className="text-xs text-muted-foreground truncate">{user.status_message}</span>
                        )}
                    </div>
                </div>
            } />
            <div className="flex items-center gap-1">
                <NotificationPopover />
                <Button
                  variant="ghost"
                  size="icon"
                  onClick={toggleTheme}
                  title={theme === 'dark' ? 'Switch to light mode' : 'Switch to dark mode'}
                >
                  {theme === 'dark' ? <Sun className="h-5 w-5" /> : <Moon className="h-5 w-5" />}
                </Button>
                <Button variant="ghost" size="icon" onClick={logout} title="Logout">
                    <LogOut className="h-5 w-5" />
                </Button>
            </div>
        </div>
        <div className="p-4 pb-0">
             <NewChatDialog onChatCreated={handleChatCreated} trigger={
                 <Button className="w-full flex gap-2">
                     <Plus className="h-4 w-4" /> New Chat
                 </Button>
             } />
        </div>
        <div className="flex-1 overflow-hidden pt-2">
            <ChatList 
                onSelectChat={handleChatSelect} 
                selectedChatId={selectedChat?._id} 
                refreshTrigger={refreshChats}
                currentUser={user}
            />
        </div>
      </div>

      {/* Main Chat Area */}
      <div className="flex-1 flex flex-col">
        {selectedChat ? (
          <>
            <div className="h-16 border-b flex items-center justify-between px-6 bg-muted/10">
                <div className="flex flex-col min-w-0 flex-1">
                    <div className="flex items-center gap-2">
                        <h3 className="font-semibold truncate">{chatDisplayName}</h3>
                        {selectedChat.type === 'GROUP' && <span className="ml-2 text-xs bg-secondary px-2 py-1 rounded shrink-0">Group</span>}
                    </div>
                    {selectedChat.type === 'DIRECT' && getOtherParticipantStatus() && (
                        <p className="text-xs text-muted-foreground truncate">{getOtherParticipantStatus()}</p>
                    )}
                </div>
                <ChatDetailsDialog 
                  chat={selectedChat} 
                  onUpdate={refreshSelectedChat}
                  onDelete={() => {
                    setSelectedChat(null);
                    setMessages([]);
                    setRefreshChats(prev => prev + 1);
                  }}
                />
            </div>
            <div className="flex-1 overflow-hidden">
                <MessageList 
                    messages={messages} 
                    currentUser={user}
                    chat={selectedChat}
                    hasMore={hasMore}
                    isLoadingMore={isLoadingMore}
                    onLoadMore={handleLoadMore}
                    onEditMessage={handleEditMessage}
                    onDeleteMessage={handleDeleteMessage}
                />
            </div>
            <MessageInput onSendMessage={handleSendMessage} />
          </>
        ) : (
          <div className="flex-1 flex items-center justify-center text-muted-foreground flex-col gap-4">
            <div className="h-20 w-20 rounded-full bg-muted flex items-center justify-center">
                <Plus className="h-10 w-10 text-muted-foreground/50" />
            </div>
            <p>Select a chat or start a new one</p>
          </div>
        )}
      </div>
    </div>
  );
}
