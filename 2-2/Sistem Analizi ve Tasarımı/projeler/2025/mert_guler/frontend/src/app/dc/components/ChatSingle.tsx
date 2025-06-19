import {getMessagesWithUser, sendMessageToUser} from "@/api/user/usermessage";
import {User} from "@/types/user";
import {UserMessage} from "@/types/user/usermessage";
import {Send} from "lucide-react";
import {useEffect, useRef, useState} from "react";
import DoubleCheck from "@/app/dc/components/DoubleCheck";
import {Link} from "react-router-dom";
import {userProfilePath} from "@/app/home/util/slug";

interface ChatSingleProps {
    user: User;
    friend: User;
}

interface Message {
    message: UserMessage;
    isServer: boolean;
}

const ChatSingle: React.FC<ChatSingleProps> = ({user, friend}) => {
    const [messages, setMessages] = useState<Message[]>([]);
    const [hasMore, setHasMore] = useState(true);

    // polling için: sadece yeni mesajlar
    const [loadingNew, setLoadingNew] = useState(false);
    // load-more için: eski mesajlar
    const [loadingOld, setLoadingOld] = useState(false);

    const [pageNumber, setPageNumber] = useState(0);

    const inputRef = useRef<HTMLInputElement>(null);
    const messagesEndRef = useRef<HTMLDivElement>(null);
    const hasScrolledToBottom = useRef(false);

    // Ortak ekleme/sıralama
    const mergeMessages = (incoming: UserMessage[]) => {
        setMessages(prev => {
            const wrapped = incoming.map(m => ({message: m, isServer: true}));
            const deduped = wrapped.filter(w => !prev.some(p => p.message.id === w.message.id));
            const all = [...prev, ...deduped];
            return all.sort((a, b) => a.message.sentAt - b.message.sentAt);
        });
    };

    // Yeni mesajları çek (polling)
    const fetchNew = async () => {
        setLoadingNew(true);
        try {
            const res = await getMessagesWithUser(friend.uuid, 0);
            // Sadece sayfa 0'den gelenleri ekle
            mergeMessages(res.content);
        } catch (err) {
            console.error("Yeni mesaj yükleme hatası:", err);
        } finally {
            setLoadingNew(false);
        }
    };

    // Eski mesajları yükle
    const fetchOld = async () => {
        if (!hasMore || loadingOld) return;
        setLoadingOld(true);
        const nextPage = pageNumber + 1;
        try {
            const res = await getMessagesWithUser(friend.uuid, nextPage);
            if (res.content.length === 0) {
                setHasMore(false);
            } else {
                mergeMessages(res.content);
                setPageNumber(nextPage);
            }
        } catch (err) {
            console.error("Eski mesaj yükleme hatası:", err);
        } finally {
            setLoadingOld(false);
        }
    };

    // İlk yükleme ve friend değiştiğinde sıfırlama + polling başlatma
    useEffect(() => {
        setMessages([]);
        setPageNumber(0);
        setHasMore(true);
        hasScrolledToBottom.current = false;

        // İlk defa hem eski (sayfa 0) hem de polling tetiklemesi
        fetchNew();
        const iv = setInterval(fetchNew, 1000);
        return () => clearInterval(iv);
    }, [friend.uuid]);

    // Scroll otomatiği: yeni mesaj gelince en alta in
    useEffect(() => {
        if (!hasScrolledToBottom.current && messages.length) {
            messagesEndRef.current?.scrollIntoView({behavior: "smooth"});
            hasScrolledToBottom.current = true;
        }
    }, [messages]);

    // Mesaj gönderme
    const handleSend = async () => {
        const text = inputRef.current?.value.trim();
        if (!text) return;
        inputRef.current!.value = "";

        // geçici mesaj
        const tempId = Date.now();
        const outgoing: Message = {
            message: {
                id: tempId,
                from: user,
                recipient: friend,
                sentAt: Date.now(),
                message: text,
                isRead: false,
            },
            isServer: false,
        };
        setMessages(prev => [...prev, outgoing]);
        hasScrolledToBottom.current = false;

        try {
            const saved = await sendMessageToUser(text, friend.uuid);
            mergeMessages([saved]);
        } catch (e) {
            console.error("Mesaj gönderilemedi:", e);
        } finally {
            // Geçici mesajı kaldır
            setMessages(prev => prev.filter(m => m.message.id !== tempId));
        }
    };

    return (
        <section className="main chat-panel">
            <Link to={userProfilePath(friend)}>
                <div className="chat-header">
                    <img
                        className="avatar"
                        src={friend.profilePicture}
                        alt={`${friend.firstName} ${friend.lastName}`}
                    />
                    <div>
          <span className="name">
            {friend.firstName} {friend.lastName}
          </span>
                    </div>
                </div>
            </Link>


            <div className="messages">
                {hasMore && (
                    <button
                        onClick={fetchOld}
                        disabled={loadingOld}
                        className="load-more"
                    >
                        {loadingOld ? "Loading older..." : "View old messages"}
                    </button>
                )}

                {messages.map(msg => (
                    <div
                        key={msg.message.id}
                        className={`message-item ${
                            msg.message.from.uuid === user.uuid ? "me" : "them"
                        }`}
                    >
                        <div className="message-text">{msg.message.message}</div>
                        <div className="message-time">
                            {new Date(msg.message.sentAt * 1000).toLocaleTimeString([], {
                                hour: "2-digit",
                                minute: "2-digit",
                            })}
                            {msg.message.from.uuid === user.uuid && (
                                <DoubleCheck read={msg.message.isRead}/>
                            )}
                        </div>
                    </div>
                ))}
                <div ref={messagesEndRef}/>
            </div>

            <div className="message-input">
                <input
                    ref={inputRef}
                    type="text"
                    placeholder="Message..."
                    onKeyDown={e => e.key === "Enter" && handleSend()}
                />
                <button onClick={handleSend} disabled={loadingNew}>
                    <Send size={18}/>
                </button>
            </div>
        </section>
    );
};

export default ChatSingle;
