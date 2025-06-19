import React from "react";
import { UserActivity } from "@/types/user/useractivity";
import { Link } from "react-router-dom";

interface BecomeFriendUpdateProps {
  activity: Extract<UserActivity, { type: "BECOME_FRIENDS" }>;
}

const BecomeFriendUpdate: React.FC<BecomeFriendUpdateProps> = ({ activity }) => {
  const user = activity.content;

  return (
    <div className="activity-card">
      <div className="avatar-container">
        <img
          src={user.profilePicture}
          alt={user.username}
          onError={e => {
            (e.target as HTMLImageElement).src =
              '/placeholder.svg?height=150&width=100';
          }}
          className="avatar-img"
        />
      </div>
      <div className="activity-info">
        <p className="activity-text">
          <strong>
            <Link to={`/profile/${user.username}`}>
              {user.username}
            </Link>
          </strong> became friends.
        </p>
        <p className="activity-time">
          {new Date(activity.time).toLocaleString()}
        </p>
      </div>
    </div>
  );
};

export default BecomeFriendUpdate;
