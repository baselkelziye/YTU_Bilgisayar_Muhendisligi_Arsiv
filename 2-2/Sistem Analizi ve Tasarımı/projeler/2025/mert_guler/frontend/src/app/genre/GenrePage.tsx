// src/features/genre/GenrePage.tsx
import React, { useState, useEffect } from 'react';
import { useParams } from 'react-router-dom';
import { fetchFrontMovies, searchFrontMovies } from '@/api/movieapi';
import { FrontMovie, PagedResponse } from '@/types/front';
import { GenreSidebar } from './components/GenreSidebar';
import { SearchBar } from './components/SearchBar';
import { MovieGrid } from './components/MovieGrid';
import { Pagination } from './components/Pagination';
import './style/GenrePage.css';

export const GenrePage: React.FC = () => {
    const { genre } = useParams<{ genre?: string }>();
    const [searchWord, setSearchWord] = useState('');
    const [pageNumber, setPageNumber] = useState(0);
    const [data, setData] = useState<PagedResponse<FrontMovie> | null>(null);
    const [loading, setLoading] = useState(false);

    // Şimdilik sabit bir tür listesi; isterseniz API'den çekmek için ayrı bir fetchGenres() yazabilirsiniz.
    const genres = [
        'All','Action', 'Adventure', 'Animation', 'Comedy',
        'Drama', 'Horror', 'Romance', 'Thriller'
    ];

    useEffect(() => {
        setLoading(true);
        const loader = searchWord.trim()
            ? searchFrontMovies({ word: searchWord, genre, pageNumber })
            : fetchFrontMovies({ genre, pageNumber });

        loader
            .then(res => setData(res))
            .catch(console.error)
            .finally(() => setLoading(false));
    }, [genre, searchWord, pageNumber]);

    const handleSearch = (val: string) => {
        setSearchWord(val);
        setPageNumber(0);
    };

    const handlePageChange = (newPage: number) => {
        setPageNumber(newPage);
    };

    useEffect(() => {
        let name = genre || "";
        document.title = `${name} Movies - Listopia`
      }, [])
    

    return (
        <main className="genre-page">
            <GenreSidebar genres={genres} selected={genre} />
            <div className="genre-content">
                <SearchBar value={searchWord} onChange={handleSearch} placeholder="Search movies..."/>
                {loading
                    ? <div className="loading">Loading…</div>
                    : data && (
                    <>
                        <MovieGrid movies={data.content} />
                        <Pagination
                            pageNumber={data.pageNumber}
                            totalPages={data.totalPages}
                            onPageChange={handlePageChange}
                        />
                    </>
                )
                }
            </div>
        </main>
    );
};
export default GenrePage;
