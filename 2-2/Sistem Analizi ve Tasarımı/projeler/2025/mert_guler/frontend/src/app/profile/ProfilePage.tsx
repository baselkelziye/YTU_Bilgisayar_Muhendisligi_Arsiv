"use client"

import type React from "react"
import { useEffect, useState } from "react"
import "./style/ProfilePage.css"
import { Settings, Brush } from "lucide-react"
import {useNavigate, useParams} from "react-router-dom"
import { fetchWatchedMoviesByUser, fetchWatchlistMoviesByUser } from "@/api/movieapi"
import { fetchFriendsByUUID, fetchUserByUsername, fetchUserActivity } from "@/api/userapi"
import type { User } from "@/types/user"
import { useAuth } from "@/app/auth/hooks/AuthContext"

import ProfileLeftColumn from "./components/ProfileLeftColumn"
import ProfileStatistics from "./components/ProfileStatistics"
import ProfileUpdates from "./components/ProfileUpdates"
import { UserActivity } from "@/types/user/useractivity"

const mockStats = {
    watched: 0,
    wantToWatch: 0,
    liked: 0,
    totalFilms: 11,
}

const mockLists = {
    reviews: 3,
}


const ProfilePage: React.FC = () => {
    const [activeTab, setActiveTab] = useState<"requests" | "friends">("requests")
    const { username } = useParams<{ username: string }>()
    const [user, setUser] = useState<User | null>(null)
    const [friends, setFriends] = useState<User[]>([])
    const [loading, setLoading] = useState(true)
    const [profileUpdates, setProfileUpdates] = useState<UserActivity[]>([])

    const { user: userMe, sendingRequests, receivedRequests } = useAuth()

    const isOwn = userMe?.username === username
    const [isFriend, setIsFriend] = useState(false)

    const stats = mockStats // Mock stats kullanılmaya devam ediyor
    const lists = mockLists
    const navigate = useNavigate();


    useEffect(() => {
        if (!username) {
            setLoading(false)
            return
        }

        setLoading(true)
        setUser(null)
        setFriends([])
        setProfileUpdates([])

        fetchUserByUsername(username)
            .then((userData) => {
                setUser(userData)
                document.title = `${userData.username} - Listopia`;

                fetchFriendsByUUID(userData.uuid)
                    .then((retFriends) => {
                        setFriends(retFriends.content)
                        if (userMe) {
                            setIsFriend(retFriends.content.some((f) => f.uuid === userMe.uuid))
                        }
                    })
                    .catch((err) => console.error("Error fetching friends:", err))

                fetchWatchedMoviesByUser(userData.uuid).catch((err) => console.error("Error fetching watched movies:", err))
                fetchWatchlistMoviesByUser(userData.uuid).catch((err) => console.error("Error fetching watchlist movies:", err))


                fetchUserActivity(userData.uuid)
                    .then((resp) => {
                        setProfileUpdates(resp.content)
                    })
                    .catch((err: Error) => {
                        console.error("Error fetching user activity:", err)
                        setProfileUpdates([]) // Hata durumunda boş dizi ata
                    });

                setLoading(false)
            })
            .catch((err: Error) => {
                console.error("Error fetching user profile:", err)
                document.title = `User not found - Listopia`;
                setUser(null)
                setLoading(false)
                navigate('/404', { replace: true });

            })
    }, [username, userMe])

    if (loading) {
        return (
            <div className="profile-page-loading">
                <h1>Loading profile...</h1>
            </div>
        )
    }

    if (!user) {
        return (
            <div className="profile-page-error">
                <h1>User '{username}' not found.</h1>
            </div>
        )
    }

    return (
        <div className="profile-page">
            <div className="profile-header">
                <h1>{user.username}'s Profile</h1>
                {isOwn && (
                    <div className="profile-actions">
                        <button className="action-button">
                            <Brush size={16} /> Change Appearance
                        </button>
                        <button className="action-button">
                            <Settings size={16} /> Profile Settings
                        </button>
                    </div>
                )}
            </div>

            <div className="profile-content">
                <ProfileLeftColumn
                    user={user}
                    friends={friends}
                    sentRequests={sendingRequests}
                    receivedRequests={receivedRequests}
                    isOwn={isOwn}
                    isFriend={isFriend}
                    activeTab={activeTab}
                    setActiveTab={setActiveTab}
                    lists={lists}
                />

                <div className="profile-right-column">
                    <ProfileStatistics stats={stats} userUuid={user.uuid} />
                    <ProfileUpdates profileUpdates={profileUpdates} />
                </div>
            </div>
        </div>
    )
}

export default ProfilePage