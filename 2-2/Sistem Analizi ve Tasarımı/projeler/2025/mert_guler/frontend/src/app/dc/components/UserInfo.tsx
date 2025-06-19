// src/components/UserInfo.tsx
import React from 'react';
import { User } from '@/types/user';
import AdminHeader from '@/app/dc/components/Header';

interface UserInfoProps {
    user: User;
}

const UserInfo: React.FC<UserInfoProps> = ({ user }) => {
    return (
        <aside className="main-right" style={{ padding: '50px', backgroundColor: '#2f3136', borderLeft: '1px solid #202225' }}>

            <img
                className="avatar"
                src={user.profilePicture}
                alt={`${user.firstName} ${user.lastName}`}
                style={{ width: '60px', height: '60px', borderRadius: '50%', marginBottom: '12px' }}
            />

            <span style={{ fontWeight: 'bold', display: 'block' }}>
        {user.firstName} {user.lastName}
      </span>

            <span style={{ color: '#aaa', display: 'block', marginBottom: '8px' }}>
        @{user.username}
      </span>

            <AdminHeader userRole={user.role} />

            <div className="about-section mb-4" style={{ width: '100%' }}>
                <p>{user.biography || 'Hello, I am using Listopia.'}</p>
            </div>

            <span style={{ fontSize: '0.8rem', color: '#888' }}>
        Last Seen:{' '}
                {new Date(user.lastOnline).toLocaleString([], {
                    hour: '2-digit',
                    minute: '2-digit',
                    day: '2-digit',
                    month: '2-digit',
                    year: 'numeric',
                })}
      </span>
        </aside>
    );
};

export default UserInfo;
