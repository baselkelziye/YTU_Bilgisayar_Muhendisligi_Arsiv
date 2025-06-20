// src/components/ReviewList.tsx
import React, { useState, useEffect } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import {
    fetchMovieComments,
    submitMovieComment,
    updateMovieComment,
    deleteMovieComment,
    reportMovieComment,
} from '@/api/movieapi';
import { useAuth } from '@/app/auth/hooks/AuthContext';
import '../style/ReviewList.css';
import { Comment } from '@/types/movie';
import { movieIdFromSlug } from '@/app/home/util/slug';

const COMMENTS_PER_PAGE = 5;

function parseMentions(message: string) {
    const mentionRegex = /@([a-zA-Z0-9_]+)/g;
    return message.split(mentionRegex).map((part, index) => {
        if (index % 2 === 0) {
            return part;
        } else {
            return (
                <a key={index} href={`/profile/${part}`} className="mention-link">
                    @{part}
                </a>
            );
        }
    });
}

const ReviewList: React.FC = () => {
    const { movieSlug } = useParams<{ movieSlug: string }>();
    const navigate = useNavigate();
    const { user } = useAuth();
    const movieId = movieIdFromSlug(movieSlug || '') || 0;

    const [comments, setComments] = useState<Comment[]>([]);
    const [comment, setComment] = useState('');
    const [isSpoiler, setIsSpoiler] = useState(false);
    const [currentPage, setCurrentPage] = useState(0);
    const [totalPages, setTotalPages] = useState(0);
    const [loading, setLoading] = useState(false);

    // editing state
    const [editingCommentId, setEditingCommentId] = useState<number | null>(null);
    const [editingMessage, setEditingMessage] = useState('');
    const [editingIsSpoiler, setEditingIsSpoiler] = useState(false);

    // fetch comments
    const fetchComments = async (page: number) => {
        setLoading(true);
        try {
            const resp = await fetchMovieComments(movieId, page, COMMENTS_PER_PAGE);
            setComments(resp.content);
            if (resp.totalPages == 0){
                setTotalPages(1);
            } else {
                setTotalPages(resp.totalPages);
            }
        } catch (err) {
            console.error(err);
        } finally {
            setLoading(false);
        }
    };

    useEffect(() => {
        if (movieId) fetchComments(currentPage);
    }, [movieId, currentPage]);

    // submit new
    const submitCommentHandler = async () => {
        if (!user) {
            navigate('/login/');
            return;
        }
        try {
            const newComment = await submitMovieComment(
                movieId,
                user.uuid,
                comment,
                isSpoiler
            );
            setComments(prev => [newComment, ...prev]);
            setComment('');
            setIsSpoiler(false);
        } catch (err) {
            console.error(err);
        }
    };

    // pagination
    const handlePageChange = (page: number) => {
        if (page >= 0 && page < totalPages) {
            setCurrentPage(page);
        }
    };

    // toggle spoiler reveal
    const toggleSpoiler = (id: number) => {
        setComments(prev =>
            prev.map(c =>
                c.commentId === id ? { ...c, isSpoiler: !c.isSpoiler } : c
            )
        );
    };

    // edit handlers
    const handleEditClick = (c: Comment) => {
        setEditingCommentId(c.commentId);
        setEditingMessage(c.message);
        setEditingIsSpoiler(c.isSpoiler);
    };
    const handleCancelEdit = () => {
        setEditingCommentId(null);
    };
    const handleSaveEdit = async (id: number) => {
        try {
            const updated = await updateMovieComment(
                id,
                editingMessage,
                editingIsSpoiler
            );
            setComments(prev =>
                prev.map(c => (c.commentId === id ? updated : c))
            );
        } catch (err) {
            console.error(err);
        } finally {
            setEditingCommentId(null);
        }
    };

    // delete handler
    const handleDelete = async (id: number) => {
        if (!window.confirm('Yorumu silmek istediğinize emin misiniz?')) return;
        try {
            await deleteMovieComment(id);
            setComments(prev => prev.filter(c => c.commentId !== id));
        } catch (err) {
            console.error(err);
        }
    };

    // report with confirmation
    const handleReport = async (id: number) => {
        if (!window.confirm('Are you sure you want to report this comment?')) {
            return;
        }
        try {
            await reportMovieComment(id);
            alert('Thank you—this comment has been reported.');
        } catch (err) {
            console.error(err);
        }
    };

    return (
        <section className="review-list">
            <h2>User Reviews</h2>
            {loading && <p>Loading comments…</p>}

            {comments.length > 0 ? (
                comments.map(c => {
                    // format timestamp: ayrı date / time
                    let dateOnly = '';
                    let timeOnly = '';
                    if (c.sentAt) {
                        const ms = c.sentAt > 1e12 ? c.sentAt : c.sentAt * 1000;
                        const dt = new Date(ms);
                        dateOnly = dt.toLocaleDateString();
                        timeOnly = dt.toLocaleTimeString();
                    }

                    return (
                        <div key={c.commentId} className="review-card">
                            <p className="author">
                                <span
                                    className="author-name"
                                    onClick={() =>
                                        navigate(`/profile/${c.user.username}`)
                                    }
                                >
                                    {c.user.firstName} {c.user.lastName}
                                </span>
                                <span className="username">
                                    @{c.user.username}
                                </span>
                            </p>

                            {editingCommentId === c.commentId ? (
                                <div className="edit-section">
                                    <textarea
                                        value={editingMessage}
                                        onChange={e =>
                                            setEditingMessage(e.target.value)
                                        }
                                    />
                                    <label className="spoiler-checkbox">
                                        <input
                                            type="checkbox"
                                            checked={editingIsSpoiler}
                                            onChange={() =>
                                                setEditingIsSpoiler(prev => !prev)
                                            }
                                        />
                                        Spoiler
                                    </label>
                                    <button
                                        className="save-button"
                                        onClick={() => handleSaveEdit(c.commentId)}
                                    >
                                        Save
                                    </button>
                                    <button
                                        className="cancel-button"
                                        onClick={handleCancelEdit}
                                    >
                                        Cancel
                                    </button>
                                </div>
                            ) : (
                                <>
                                    <div className="content-row">
                                        {c.isSpoiler ? (
                                            <button
                                                className="spoiler-button"
                                                onClick={() =>
                                                    toggleSpoiler(c.commentId)
                                                }
                                            >
                                                Show Spoiler
                                            </button>
                                        ) : (
                                            <p className="content">{parseMentions(c.message)}</p>
                                        )}
                                        <div className="comment-actions">
                                            {user?.uuid === c.user.uuid && (
                                                <>
                                                    <button
                                                        className="edit-button"
                                                        onClick={() => handleEditClick(c)}
                                                    >
                                                        Edit
                                                    </button>
                                                    <button
                                                        className="delete-button"
                                                        onClick={() => handleDelete(c.commentId)}
                                                    >
                                                        Delete
                                                    </button>
                                                </>
                                            )}
                                            {user?.uuid !== c.user.uuid &&
                                                (<button
                                                className="report-button"
                                                onClick={() =>
                                                    handleReport(c.commentId)
                                                }
                                            >
                                                Report
                                            </button> )}
                                        </div>
                                    </div>

                                    {/* Tarih ve saati aralarına dash koyarak göster */}
                                    {(dateOnly || timeOnly) && (
                                        <p className="timestamp">
                                            {dateOnly} - {timeOnly}
                                            {c.isUpdated && (
                                                <span className="edited-label"> (edited)</span>
                                            )}
                                        </p>
                                    )}
                                </>
                            )}
                        </div>
                    );
                })
            ) : (
                <p>No comments available.</p>
            )}

            {/* new comment form */}
            <div className="comment-section">
                <textarea
                    value={comment}
                    onChange={e => setComment(e.target.value)}
                    placeholder="Write a comment..."
                />
                <div className="spoiler-checkbox">
                    <label>
                        <input
                            type="checkbox"
                            checked={isSpoiler}
                            onChange={() =>
                                setIsSpoiler(prev => !prev)
                            }
                        />
                        This is a spoiler
                    </label>
                </div>
                <button
                    onClick={submitCommentHandler}
                    className="btn-comment"
                >
                    Submit Comment
                </button>
            </div>

            {/* pagination */}
            <div className="pagination">
                <button
                    onClick={() =>
                        handlePageChange(currentPage - 1)
                    }
                    disabled={currentPage <= 0}
                    className="pagination-button"
                >
                    Previous
                </button>
                <span className="pagination-info">
                    Page {currentPage + 1} of {totalPages}
                </span>
                <button
                    onClick={() =>
                        handlePageChange(currentPage + 1)
                    }
                    disabled={currentPage >= totalPages - 1}
                    className="pagination-button"
                >
                    Next
                </button>
            </div>
        </section>
    );
};

export default ReviewList;
