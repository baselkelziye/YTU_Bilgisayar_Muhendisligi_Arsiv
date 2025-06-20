interface Sort {
    empty: boolean;
    sorted: boolean;
    unsorted: boolean;
}

interface Pageable {
    offset: number;
    sort: Sort;
    paged: boolean;
    pageNumber: number;
    pageSize: number;
    unpaged: boolean;
}

export interface PaginatedResponse<T> {
    totalPages: number;
    totalElements: number;
    first: boolean;
    last: boolean;
    size: number;
    content: T[];             // İçerik dizisi, generic T
    number: number;           // Mevcut sayfa numarası
    sort: Sort;               // Genel sıralama özeti
    pageable: Pageable;       // Detaylı sayfalama bilgisi
    numberOfElements: number; // Bu sayfadaki öğe sayısı
    empty: boolean;           // Sayfa boş mu?
}
