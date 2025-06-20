// src/app/search/SearchPage.tsx
import React, { useState, useEffect } from "react";
import {
    SearchCategory,
    SearchResponse,
    searchUsersMovies
} from "@/api/searchapi";
import SearchInput   from "./components/SearchInput";
import SearchFilters from "./components/SearchFilters";
import SearchResults from "./components/SearchResults";
import "./style/SearchPage.css";

const PAGE_SIZE = 15;

const SearchPage: React.FC = () => {
    const [query,    setQuery]    = useState("");
    const [category, setCategory] = useState<SearchCategory>(SearchCategory.ALL);
    const [page,     setPage]     = useState(0);
    const [loading,  setLoading]  = useState(false);
    const [data,     setData]     = useState<SearchResponse | null>(null);

    const doSearch = () => {
        if (!query.trim()) {
            setData(null);
            return;
        }
        setLoading(true);
        searchUsersMovies(query, category, page, PAGE_SIZE)
            .then(setData)
            .finally(() => setLoading(false));
    };

    // Re-run whenever category or page changes:
    useEffect(doSearch, [category, page]);

    return (
        <div className="search-page-container">
            <aside className="search-filters">
                <SearchFilters
                    category={category}
                    onCategoryChange={c => { setCategory(c); setPage(0); }}
                />
            </aside>
            <main className="search-content">
                <SearchInput
                    query={query}
                    onQueryChange={setQuery}
                    onSearch={() => { setPage(0); doSearch(); }}
                />
                <SearchResults
                    loading={loading}
                    data={data}
                    category={category}
                    onPageChange={setPage}
                />
            </main>
        </div>
    );
};

export default SearchPage;
