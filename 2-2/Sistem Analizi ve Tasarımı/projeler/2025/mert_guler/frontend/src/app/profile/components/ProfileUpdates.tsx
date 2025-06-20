// src/components/ProfileUpdates.tsx
import React, { useState } from "react"
import { Clock } from "lucide-react"
import { formatTimeAgo } from "@/lib/utils"
import "../style/ProfilePage.css"
import BecomeFriendUpdate from "./updates/BecomeFriendsUpdate"
import { UserActivity } from "@/types/user/useractivity"
import MovieAddWatchlistUpdate from "./updates/MovieAddWatchlistUpdate"
import MovieAddWatchedUpdate from "./updates/MovieAddWatchedUpdate"
import MovieLikedUpdate from "./updates/MovieLikedUpdate"
import MovieCommentedUpdate from "./updates/MovieCommentUpdate"

interface ProfileUpdatesProps {
    profileUpdates: UserActivity[]
}

function renderUpdateComponent(update: UserActivity) {
    switch (update.type) {
        case "BECOME_FRIENDS":
            return <BecomeFriendUpdate activity={update} />
        case "MOVIE_ADD_WATCHLIST":
            return <MovieAddWatchlistUpdate activity={update} />
        case "MOVIE_ADD_WATCHED":
            return <MovieAddWatchedUpdate activity={update} />
        case "MOVIE_LIKED":
            return <MovieLikedUpdate activity={update} />
        case "MOVIE_COMMENT":
            return <MovieCommentedUpdate activity={update} />
        default:
            return null
    }
}

function strTimeToCorrectDate(date: number) {
    const str = formatTimeAgo(date)
    return str === "online" ? "now" : str
}

const ProfileUpdates: React.FC<ProfileUpdatesProps> = ({ profileUpdates }) => {
    const INCREMENT = 5
    const [visibleCount, setVisibleCount] = useState<number>(INCREMENT)

    // CamelCase ve boşluklu tipleri kebab-case'e çevirir
    const toKebab = (str: string) =>
        str
            .replace(/\s+/g, "-")                // boşlukları değiştir
            .replace(/([a-z0-9])([A-Z])/g, "$1-$2") // camelCase ayrımı
            .toLowerCase()

    return (
        <div className="profile-updates">
            <h2>Profile Updates</h2>

            <div className="updates-list">
                {profileUpdates
                    .slice(0, visibleCount)
                    .map(update => {
                        const formattedType = toKebab(update.type)
                        return (
                            <div key={update.id} className={`update-item ${formattedType}`}>
                                <div className="update-content">
                                    {renderUpdateComponent(update)}
                                </div>
                                <div className="update-time">
                                    <Clock size={16} />
                                    <span>{strTimeToCorrectDate(update.time)}</span>
                                </div>
                            </div>
                        )
                    })}
            </div>

            {profileUpdates.length > visibleCount && (
                <button
                    className="show-more"
                    onClick={() => setVisibleCount(c => c + INCREMENT)}
                >
                    Show More
                </button>
            )}
        </div>
    )
}

export default ProfileUpdates
