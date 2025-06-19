// src/app/dashboard/components/AdminStats.tsx
import React, { useState, useEffect } from 'react';
import { fetchAdminStatsAll } from '@/api/adminapi';
import {
    ResponsiveContainer,
    BarChart,
    Bar,
    XAxis,
    YAxis,
    Tooltip,
    Legend,
    PieChart,
    Pie,
    Cell
} from 'recharts';
import {
    AdminStats,
    // MovieStat,
    GenreStat,
    // UserStat
} from '@/types/stats';
import '../styles/AdminStats.css';

const COLORS = ['#bb86fc', '#03dac6', '#cf6679', '#3700b3', '#018786'];

const AdminStats: React.FC = () => {
    const [stats, setStats] = useState<AdminStats | null>(null);
    const [loading, setLoading] = useState<boolean>(true);
    const [error, setError] = useState<string>('');

    useEffect(() => {
        (async () => {
            try {
                const data = await fetchAdminStatsAll();
                setStats(data);
            } catch (e) {
                setError((e as Error).message);
            } finally {
                setLoading(false);
            }
        })();
    }, []);

    if (loading) return <div className="admin-stats__loading">Loading…</div>;
    if (error)   return <div className="admin-stats__error">Error: {error}</div>;
    if (!stats)  return null;

    // sadece ilk 5 elemanı alıyoruz
    const topWatchedMovies = stats.mostWatchedMovies.slice(0, 5);
    const topLikedMovies   = stats.mostLikedMovies.slice(0, 5);
    const topVisitedMovies = stats.mostVisitedMovies.slice(0, 5);

    const topWatchedGenres = stats.mostWatchedGenres.slice(0, 5);
    const topLikedGenres   = stats.mostLikedGenres.slice(0, 5);
    const topVisitedGenres = stats.mostVisitedGenres.slice(0, 5);

    const topUsersByWatched = stats.usersByWatchedListSize.slice(0, 5);
    const topUsersByLiked   = stats.usersByLikedListSize.slice(0, 5);

    return (
        <div className="admin-stats-grid">
            {/* Özet Kartları */}
            <div className="summary-card">
                <h4>Total Movies</h4>
                <span>{stats.movieCount.toLocaleString()}</span>
            </div>
            <div className="summary-card">
                <h4>Total Users</h4>
                <span>{stats.userCount.toLocaleString()}</span>
            </div>

            {/* Movie Bar Charts */}
            <section className="chart-card">
                <h3>Most Watched Movies</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topWatchedMovies}>
                        <XAxis dataKey="title" tick={{ fill: '#e0e0e0', fontSize: 12 }} />
                        <YAxis tick={{ fill: '#e0e0e0' }} />
                        <Tooltip />
                        <Bar dataKey="watchCount" fill={COLORS[0]} name="Views" />
                    </BarChart>
                </ResponsiveContainer>
            </section>

            <section className="chart-card">
                <h3>Most Liked Movies</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topLikedMovies}>
                        <XAxis dataKey="title" tick={{ fill: '#e0e0e0', fontSize: 12 }} />
                        <YAxis tick={{ fill: '#e0e0e0' }} />
                        <Tooltip />
                        <Bar dataKey="likeCount" fill={COLORS[1]} name="Likes" />
                    </BarChart>
                </ResponsiveContainer>
            </section>

            <section className="chart-card">
                <h3>Most Visited Movies</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topVisitedMovies}>
                        <XAxis dataKey="title" tick={{ fill: '#e0e0e0', fontSize: 12 }} />
                        <YAxis tick={{ fill: '#e0e0e0' }} />
                        <Tooltip />
                        <Bar dataKey="clickCount" fill={COLORS[2]} name="Clicks" />
                    </BarChart>
                </ResponsiveContainer>
            </section>

            {/* Genre Pie Charts */}
            <section className="chart-card">
                <h3>Most Watched Genres</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <PieChart>
                        <Pie
                            data={topWatchedGenres}
                            dataKey="watchCount"
                            nameKey="name"
                            outerRadius={80}
                            label
                        >
                            {topWatchedGenres.map((genre: GenreStat, idx: number) => (
                                <Cell
                                    key={genre.genreId}
                                    fill={COLORS[idx % COLORS.length]}
                                />
                            ))}
                        </Pie>
                        <Tooltip />
                        <Legend verticalAlign="bottom" />
                    </PieChart>
                </ResponsiveContainer>
            </section>

            <section className="chart-card">
                <h3>Most Liked Genres</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topLikedGenres}>
                        <XAxis dataKey="name" tick={{ fill: 'var(--text-main)', fontSize: 12 }} />
                        <YAxis tick={{ fill: 'var(--text-main)' }} />
                        <Tooltip />
                        <Legend />
                        <Bar dataKey="likeCount" name="Likes" fill={COLORS[1]} />
                    </BarChart>
                </ResponsiveContainer>
            </section>

            <section className="chart-card">
                <h3>Most Visited Genres</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <PieChart>
                        <Pie
                            data={topVisitedGenres}
                            dataKey="clickCount"
                            nameKey="name"
                            outerRadius={80}
                            label
                        >
                            {topVisitedGenres.map((genre: GenreStat, idx: number) => (
                                <Cell
                                    key={genre.genreId}
                                    fill={COLORS[(idx + 2) % COLORS.length]}
                                />
                            ))}
                        </Pie>
                        <Tooltip />
                        <Legend verticalAlign="bottom" />
                    </PieChart>
                </ResponsiveContainer>
            </section>

            {/* User Bar Charts */}
            <section className="chart-card">
                <h3>Most Active Watchers</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topUsersByWatched}>
                        <XAxis dataKey="username" tick={{ fill: '#e0e0e0', fontSize: 12 }} />
                        <YAxis tick={{ fill: '#e0e0e0' }} />
                        <Tooltip />
                        <Bar dataKey="watchedCount" fill={COLORS[3]} name="Watch Count" />
                    </BarChart>
                </ResponsiveContainer>
            </section>

            <section className="chart-card">
                <h3>Most Active Likers</h3>
                <ResponsiveContainer width="100%" height={200}>
                    <BarChart data={topUsersByLiked}>
                        <XAxis dataKey="username" tick={{ fill: '#e0e0e0', fontSize: 12 }} />
                        <YAxis tick={{ fill: '#e0e0e0' }} />
                        <Tooltip />
                        <Bar dataKey="likedCount" fill={COLORS[4]} name="Like Count" />
                    </BarChart>
                </ResponsiveContainer>
            </section>
        </div>
    );
};

export default AdminStats;
