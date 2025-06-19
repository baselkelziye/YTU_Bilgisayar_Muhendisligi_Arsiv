import React from "react";
import { Link } from "react-router-dom";
import { UserActivity } from "@/types/user/useractivity";
import { FrontMovie } from "@/types/front";
import { getPosterUrl } from "@/lib/utils";
import { movieToSlug } from "@/app/home/util/slug";

interface MovieLikedUpdateProps {
  activity: Extract<UserActivity, { type: "MOVIE_LIKED" }>;
}

const MovieLikedUpdate: React.FC<MovieLikedUpdateProps> = ({ activity }) => {
  const movie: FrontMovie = activity.content;  // Extract movie data

  return (
    <div className="activity-card">
      <div className="activitymovie-poster">
        <Link key={movie.movieId} to={movieToSlug(movie)}>
          <img
            src={getPosterUrl(movie.poster) || '/placeholder.svg'}
            alt={movie.title}
            className="activitymovie-img"
          />
        </Link>
      </div>
      <div className="activity-info">
        <p className="activity-text">
          <Link key={movie.movieId} to={movieToSlug(movie)}>
            <strong>{movie.title}</strong>
          </Link> has been liked.
        </p>
        <p className="activity-time">
          {new Date(activity.time).toLocaleString()}
        </p>
      </div>
    </div>
  );
};

export default MovieLikedUpdate;
