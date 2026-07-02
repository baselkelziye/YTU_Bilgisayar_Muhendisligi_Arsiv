import { useState } from 'react';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Send, Paperclip } from 'lucide-react';

interface MessageInputProps {
  onSendMessage: (content: string, type: 'TEXT' | 'FILE' | 'IMAGE' | 'VIDEO', file?: File) => void;
  disabled?: boolean;
}

export function MessageInput({ onSendMessage, disabled }: MessageInputProps) {
  const [message, setMessage] = useState('');
  
  const handleSend = (e: React.FormEvent) => {
    e.preventDefault();
    if (message.trim()) {
      onSendMessage(message, 'TEXT');
      setMessage('');
    }
  };

  const handleFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
      const file = e.target.files?.[0];
      if (file) {
          let type: 'FILE' | 'IMAGE' | 'VIDEO' = 'FILE';
          if (file.type.startsWith('image/')) type = 'IMAGE';
          else if (file.type.startsWith('video/')) type = 'VIDEO';
          
          onSendMessage(file.name, type, file);
          e.target.value = ''; // Reset input
      }
  }

  return (
    <div className="p-4 border-t bg-background">
      <form onSubmit={handleSend} className="flex gap-2">
        <div className="relative">
            <input 
                type="file" 
                className="hidden" 
                id="file-upload" 
                onChange={handleFileChange} 
                disabled={disabled}
            />
            <Button 
                type="button" 
                variant="ghost" 
                size="icon" 
                disabled={disabled}
                onClick={() => document.getElementById('file-upload')?.click()}
            >
                <Paperclip className="h-5 w-5" />
            </Button>
        </div>
        <Input
          placeholder="Type a message..."
          value={message}
          onChange={(e) => setMessage(e.target.value)}
          disabled={disabled}
          className="flex-1"
        />
        <Button type="submit" disabled={!message.trim() || disabled}>
          <Send className="h-5 w-5" />
        </Button>
      </form>
    </div>
  );
}

