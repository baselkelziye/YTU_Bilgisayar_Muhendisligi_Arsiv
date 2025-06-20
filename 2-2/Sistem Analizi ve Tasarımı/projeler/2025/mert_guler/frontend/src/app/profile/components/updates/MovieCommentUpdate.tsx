import React, { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { UserActivity } from "@/types/user/useractivity";
import { FrontMovie } from "@/types/front";
import { getPosterUrl } from "@/lib/utils";
import { movieToSlug } from "@/app/home/util/slug";
import { Comment } from "@/types/movie";
import { fetchMovieById } from "@/api/movieapi";

interface MovieCommentedUpdateProps {
  activity: Extract<UserActivity, { type: "MOVIE_COMMENT" }>;
}

const MovieCommentedUpdate: React.FC<MovieCommentedUpdateProps> = ({ activity }) => {
  const comment: Comment = activity.content;  // Extract comment data
  let movie_temp: FrontMovie = { movieId: comment.movieId, title: "", poster: "", watchCount: 0, likeCount: 0 }; // Assuming movie data available
  const [movie, setMovie] = useState(movie_temp)
  
  useEffect(()=>{
    fetchMovieById(comment.movieId).then(setMovie);
  }, [])
  
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
          </Link> has a new comment from <strong>{comment.user.username}</strong>:
        </p>
        <p className="comment-message">
          {comment.message}
        </p>
        <p className="activity-time">
          {new Date(comment.sentAt).toLocaleString()}
        </p>
        {comment.isSpoiler && (
          <p className="spoiler-warning">⚠️ This comment contains spoilers.</p>
        )}
      </div>
    </div>
  );
};

export default MovieCommentedUpdate;
