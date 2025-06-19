// src/features/genre/components/Pagination.tsx
import React from 'react';
import '../style/Pagination.css';

interface Props {
    pageNumber: number;   // 0‑based
    totalPages: number;
    onPageChange: (p: number) => void;
}

export const Pagination: React.FC<Props> = ({
                                                pageNumber,
                                                totalPages,
                                                onPageChange
                                            }) => {

    const getPaginationRange = (): (number | string)[] => {
        const pageNeighbours = 1;               // aktif sayfanın etrafındaki komşu sayfa sayısı
        const totalBlocks   = pageNeighbours * 2 + 5; // first, prev‑neigh, current, next‑neigh, last + 2×‘…’

        // eğer sayfa sayısı küçükse direkt tümünü döndür
        if (totalPages <= totalBlocks) {
            return Array.from({ length: totalPages }, (_, i) => i);
        }

        const range: (number | string)[] = [];
        const left  = Math.max(1, pageNumber - pageNeighbours);
        const right = Math.min(totalPages - 2, pageNumber + pageNeighbours);

        range.push(0); // her zaman ilk sayfa

        if (left > 1) {
            range.push('…');
        }

        for (let i = left; i <= right; i++) {
            range.push(i);
        }

        if (right < totalPages - 2) {
            range.push('…');
        }

        range.push(totalPages - 1); // her zaman son sayfa

        return range;
    };

    const paginationRange = getPaginationRange();

    return (
        <div className="pagination">
            <button
                disabled={pageNumber <= 0}
                onClick={() => onPageChange(pageNumber - 1)}
            >
                ‹ Prev
            </button>

            {paginationRange.map((p, idx) => (
                <button
                    key={`pagination-${String(p)}-${idx}`}      // p ve idx ikilisi hep benzersiz
                    disabled={typeof p === 'string'}             // ellipsis butonu tıklanmasın
                    className={p === pageNumber ? 'active' : ''}
                    onClick={() => typeof p === 'number' && onPageChange(p)}
                >
                    {typeof p === 'string' ? p : p + 1}
                </button>
            ))}

            <button
                disabled={pageNumber >= totalPages - 1}
                onClick={() => onPageChange(pageNumber + 1)}
            >
                Next ›
            </button>
        </div>
    );
};
