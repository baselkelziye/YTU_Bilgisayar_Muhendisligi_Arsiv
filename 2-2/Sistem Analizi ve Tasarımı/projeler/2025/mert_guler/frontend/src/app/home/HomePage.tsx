// src/features/home/HomePage.tsx
import React, { useEffect, useState } from 'react';
import { fetchFrontMovies } from '@/api/movieapi';
import { HeroBanner } from './components/HeroBanner';
import { PopularMovies } from './components/PopularMovies';
import { MostVisitedMovies } from './components/MostVisitedMovies';
import { MostLikedMovies } from './components/MostLikedMovies';
import { MostWatchedMovies } from './components/MostWatchedMovies';
import { RecentMovies } from './components/RecentMovies';
import { SidebarSpecial } from './components/SidebarSpecial';
import './style/HomePage.css';
import {FrontMovie} from "@/types/front";

export const HomePage: React.FC = () => {
    const [featured, setFeatured] = useState<FrontMovie | null>(null);
    const [loadingHero, setLoadingHero] = useState(true);

    document.title = "Listopia"

    useEffect(() => {
        fetchFrontMovies({
            sortBy: 'popularity',
            sortOrder: 'dsc',
            pageSize: 1,
        })
            // PagedResponse<FrontMovie>'den content dizisini alıp ilk elemanı veriyoruz
            .then(({ content }) => {
                if (content.length > 0) {
                    setFeatured(content[0]);
                } else{
                    console.log("No featured movies found");
                }
            })
            .catch(console.error)
            .finally(() => setLoadingHero(false));
    }, []);

    return (
        <main className="home-page">
            {/* --- Hero + Sidebar Row --- */}
            <div className="hero-row">
                <div className="hero-container">
                    {loadingHero
                        ? <div className="hero-loading">Loading featured…</div>
                        : featured && <HeroBanner movie={featured} />
                    }
                </div>
                <aside className="hero-sidebar">
                    <SidebarSpecial />
                </aside>
            </div>

            {/* --- Aşağıdaki 5 slider --- */}
            <PopularMovies />
            <RecentMovies />
            <MostVisitedMovies />
            <MostLikedMovies />
            <MostWatchedMovies />
        </main>
    );
};

export default HomePage;
