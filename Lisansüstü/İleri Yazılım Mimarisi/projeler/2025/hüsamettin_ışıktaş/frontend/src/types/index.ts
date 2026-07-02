export interface User {
  id: string;
  email: string;
  username: string;
  first_name: string;
  last_name: string;
  profile_picture?: string;
  status_message?: string;
  created_at?: string;
  updated_at?: string;
}

export interface Chat {
  _id: string;
  type: 'DIRECT' | 'GROUP';
  name?: string;
  avatar?: string; // Backend'den gelen yeni alan
  participants: {
    userId: string;
    role: 'MEMBER' | 'ADMIN';
    joinedAt: string;
    user?: User; // Backend'den gelen zenginleştirilmiş kullanıcı verisi
  }[];
  createdBy: string;
  createdAt: string;
  updatedAt: string;
}

export interface Message {
  _id: string;
  chatId: string;
  senderId: string;
  sender?: User | null;
  content: string;
  messageType: 'TEXT' | 'FILE' | 'IMAGE' | 'VIDEO';
  fileUrl?: string;
  status: 'SENT' | 'DELIVERED' | 'READ' | 'DELETED';
  createdAt: string;
  updatedAt: string;
}

export interface Notification {
  _id: string;
  type: 'MESSAGE' | 'FILE' | 'CHAT_INVITE';
  title: string;
  body: string;
  read: boolean;
  createdAt: string;
  data?: unknown;
}
