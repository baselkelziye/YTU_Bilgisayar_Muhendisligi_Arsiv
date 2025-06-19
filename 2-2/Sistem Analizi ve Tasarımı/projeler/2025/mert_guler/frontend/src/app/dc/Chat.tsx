import React, { useState, useEffect } from 'react';
import './style/Chat.css';
import type { User } from "@/types/user";
import { SearchBar } from "@/app/genre/components/SearchBar";
import {Navigate} from "react-router-dom";
import {fetchFriendsByUUID, fetchUserMe} from "@/api/userapi";
import ChatSingle from './components/ChatSingle';
import { formatTimeAgo } from '@/lib/utils';
import AdminHeader from "@/app/dc/components/Header";
import UserInfo from "@/app/dc/components/UserInfo";
import {Users} from "lucide-react";

// FriendContainer component
type FriendContainerProps = {
    friend: User;
    isSelected: boolean;
    onClick: (friend: User) => void;
};

const getLastSeen = (user: User): string =>  {
    return formatTimeAgo(user.lastOnline)
}

const FriendContainer: React.FC<FriendContainerProps> = ({ friend, isSelected, onClick }) => (
    <div
        className={`friend-container ${isSelected ? 'selected' : ''}`}
        onClick={() => onClick(friend)}
        style={{
            display: 'flex',
            alignItems: 'center',
            padding: '8px',
            cursor: 'pointer',
            backgroundColor: isSelected ? '#3a3f47' : '#2f3136',
            borderRadius: '8px',
            marginBottom: '4px',
        }}
    >
        <img
            className="avatar"
            src={friend.profilePicture}
            alt={`${friend.firstName} ${friend.lastName}`}
            style={{ width: '40px', height: '40px', borderRadius: '50%' }}
        />
        <div style={{ display: 'flex', flexDirection: 'column', marginLeft: '12px' }}>
            <span style={{ fontWeight: 'bold', fontSize: '1rem' }}>
        {friend.firstName} {friend.lastName}
        </span>
            <span style={{ fontSize: '0.75rem', color: '#4caf50', marginTop: '2px' }}>
            {getLastSeen(friend)}
        </span>
        </div>
    </div>
);



// Main Chat component
const Chat: React.FC = () => {
    const [searchTerm, setSearchTerm] = useState<string>("");
    const [selectedFriend, setSelectedFriend] = useState<User | null>(null);
    const [user, setUser] = useState<User|null>(null);
    const [friends, setFriends] = useState<User[]>([]);
    const [isLoading, setLoading] = useState(true);
    const [isMobileMenuOpen, setIsMobileMenuOpen] = useState(false);

    document.title = `Chat - Listopia`;

    useEffect(() => {
        if(!user){return}
        fetchFriendsByUUID(user.uuid).then((res)=>{
            setFriends(res.content);
        })
    }, [user]);

    useEffect(() => {
        fetchUserMe().then(setUser).finally(()=>{
            setLoading(false);
        })
    }, []);

    useEffect(() => {
        const stored = localStorage.getItem('selectedFriend');
        if (stored) {
            setSelectedFriend(JSON.parse(stored));
            localStorage.removeItem('selectedFriend'); // sadece bir kerelik kullanılsın
        }
    }, []);

    // Toggle mobile menu
    const toggleMobileMenu = () => {
        setIsMobileMenuOpen(!isMobileMenuOpen);
    };

    // Close mobile menu when a friend is selected
    const openChatAndCloseMobileMenu = (friend: User) => {
        if (friend !== selectedFriend) {
            setSelectedFriend(friend);
        }
        setIsMobileMenuOpen(false);
    };

    if(isLoading){
        return <div>Loading...</div>
    }

    if(!user){
        return <Navigate to="/" replace />;
    }

    // Filter friends by search term
    const filteredFriends = friends
        .filter(u => u.uuid !== user.uuid)
        .filter(u =>
            `${u.firstName} ${u.lastName}`.toLowerCase().includes(searchTerm.toLowerCase())
        );

    return (
        <div className="chat-page">
            {/* Hamburger button for mobile */}
            <button
                className="hamburger-menu"
                onClick={toggleMobileMenu}
                aria-label="Toggle menu"
            >
                <span></span>
                <span></span>
                <span></span>
            </button>

            {/* search bar */}
            <div className={`top-left ${isMobileMenuOpen ? 'mobile-open' : ''}`}>
                <SearchBar
                    value={searchTerm}
                    onChange={(v: string) => setSearchTerm(v)}
                    placeholder="Search friends..."
                />
            </div>

            {/* Friends list */}
            <section className={`main-left ${isMobileMenuOpen ? 'mobile-open' : ''}`}>
                <div className="friends-header">
                    <h2>Friends</h2>
                </div>
                <div className="friends-list">
                    {filteredFriends.map(friend => (
                        <FriendContainer
                            key={friend.uuid}
                            friend={friend}
                            isSelected={selectedFriend?.uuid === friend.uuid}
                            onClick={openChatAndCloseMobileMenu}
                        />
                    ))}
                </div>
            </section>

            {/* Overlay for mobile */}
            {isMobileMenuOpen && (
                <div className="mobile-overlay" onClick={() => setIsMobileMenuOpen(false)}></div>
            )}

            {selectedFriend ? (
                <ChatSingle key={selectedFriend.uuid} user={user} friend={selectedFriend} />
                ) : (
                    <div className="empty-state main ">
                        Bir arkadaş seçin ve sohbete başlayın.
                    </div>
                )
            }

            {/* User info panel */}
            {selectedFriend && <UserInfo user={selectedFriend} />}
        </div>
    );
};

export default Chat;
