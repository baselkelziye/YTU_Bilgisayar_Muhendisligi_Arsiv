// src/features/profile/components/ProfileListFriends.tsx
import React from 'react';
import { userProfilePath } from '@/app/home/util/slug';
import { Link } from 'react-router-dom';
import { ProfileCardSlider } from '../components/ProfileCardSlider';
import '../style/ProfileFriends.css';
import { User } from '@/types/user';

interface ProfileListFriendsProps {
    friends: User[];
    friendsLoading: boolean;
    friendsError: string | null;
}

const ProfileListFriends: React.FC<ProfileListFriendsProps> = ({
                                                                   friends,
                                                                   friendsLoading,
                                                                   friendsError,
                                                               }) => {
    if (!friendsLoading) return <p>Loading friends…</p>;
    if (friendsError) return <p className="error">Error: {friendsError}</p>;
    if (friends.length === 0) return <p>No friends found.</p>;

    return (
        <section className="profile-friends-section">
            <ProfileCardSlider
                items={friends}
                renderItem={friend => (
                    <Link
                        key={friend.uuid}
                        to={userProfilePath(friend)}
                        className="profile-friend-card"
                    >
                        <div className="profile-friend-avatar">
                            <img

                                src={
                                    friend.profilePicture
                                        ? friend.profilePicture
                                        : '/placeholder.svg?height=150&width=100'
                                }
                                alt={friend.username}
                                onError={e => {
                                    (e.target as HTMLImageElement).src =
                                        '/placeholder.svg?height=150&width=100';
                                }}
                            />
                        </div>
                        <div className="profile-friend-info">
                            <h4 className="profile-friend-name">{friend.username}</h4>
                        </div>
                    </Link>
                )}
            />
        </section>
    );
};

export default ProfileListFriends;
