import { useState, useEffect, useRef } from 'react';
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogTrigger,
} from '@/components/ui/dialog';
import { Button } from '@/components/ui/button';
import { ScrollArea } from '@/components/ui/scroll-area';
import { Bell } from 'lucide-react';
import api from '@/lib/api';
import type { Notification } from '@/types';
import { format } from 'date-fns';
import { socketService } from '@/lib/socket';

export function NotificationPopover() {
  const [notifications, setNotifications] = useState<Notification[]>([]);
  const [unreadCount, setUnreadCount] = useState(0);
  const [open, setOpen] = useState(false);

  const fetchNotifications = async () => {
    try {
      const response = await api.get('/notifications');
      const data = response.data.data || response.data || [];
      const notifs = Array.isArray(data) ? data : [];
      setNotifications(notifs);
      setUnreadCount(notifs.filter(n => !n.read).length);
    } catch (error) {
      console.error('Failed to fetch notifications', error);
    }
  };

  useEffect(() => {
    if (open) {
        fetchNotifications();
    }
  }, [open]);

  // Initial fetch for badge
  useEffect(() => {
      fetchNotifications();
  }, []);

  const listenersSetupRef = useRef(false);

  useEffect(() => {
    // Prevent duplicate listener setup in Strict Mode
    if (listenersSetupRef.current) return;
    listenersSetupRef.current = true;

    const handleNotification = () => {
        fetchNotifications();
    };

    socketService.on('notification', handleNotification);
    return () => {
        socketService.off('notification', handleNotification);
        listenersSetupRef.current = false;
    };
  }, []);

  const markAsRead = async (id: string) => {
    try {
      await api.put(`/notifications/${id}/read`);
      setNotifications(prev => prev.map(n => n._id === id ? { ...n, read: true } : n));
      setUnreadCount(prev => Math.max(0, prev - 1));
    } catch (error) {
      console.error('Failed to mark as read', error);
    }
  };

  const markAllAsRead = async () => {
    try {
      await api.put('/notifications/read-all');
      setNotifications(prev => prev.map(n => ({ ...n, read: true })));
      setUnreadCount(0);
    } catch (error) {
      console.error('Failed to mark all as read', error);
    }
  };

  return (
    <Dialog open={open} onOpenChange={setOpen}>
      <DialogTrigger asChild>
        <Button variant="ghost" size="icon" className="relative">
          <Bell className="h-5 w-5" />
          {unreadCount > 0 && (
            <span className="absolute top-1 right-1 h-2.5 w-2.5 rounded-full bg-red-600 animate-pulse ring-2 ring-background" />
          )}
        </Button>
      </DialogTrigger>
      <DialogContent className="sm:max-w-[400px] p-0 gap-0 overflow-hidden">
        <DialogHeader className="p-4 border-b">
          <div className="flex items-center justify-between mr-8">
            <DialogTitle>Notifications</DialogTitle>
             {unreadCount > 0 && (
                <Button variant="ghost" size="sm" className="text-xs h-auto py-1" onClick={markAllAsRead}>
                  Mark all read
                </Button>
              )}
          </div>
        </DialogHeader>
        <ScrollArea className="h-[400px]">
          {notifications.length === 0 ? (
            <div className="p-8 text-center text-sm text-muted-foreground">
              No notifications
            </div>
          ) : (
            <div className="divide-y">
              {notifications.map((notif) => (
                <div 
                    key={notif._id} 
                    className={`p-4 hover:bg-muted/50 transition-colors cursor-pointer ${!notif.read ? 'bg-muted/20' : ''}`}
                    onClick={() => !notif.read && markAsRead(notif._id)}
                >
                  <div className="flex justify-between items-start gap-2">
                    <div className="space-y-1 flex-1">
                      <p className="text-sm font-medium leading-none">{notif.title}</p>
                      <p className="text-xs text-muted-foreground line-clamp-2">{notif.body}</p>
                      <p className="text-[10px] text-muted-foreground pt-1">
                        {format(new Date(notif.createdAt), 'MMM d, HH:mm')}
                      </p>
                    </div>
                    {!notif.read && (
                        <div className="h-2 w-2 rounded-full bg-blue-500 shrink-0 mt-1" />
                    )}
                  </div>
                </div>
              ))}
            </div>
          )}
        </ScrollArea>
      </DialogContent>
    </Dialog>
  );
}
