// src/app/api/apiClient.ts
import { toast } from 'react-toastify';

const originalFetch = window.fetch.bind(window);
export const BASE_URL = import.meta.env.VITE_API_BASE_PATH || "https://api.ensargok.com/";

export async function apiFetch(input: RequestInfo, init?: RequestInit) {
    const res = await originalFetch(input, init);
    if (!res.ok) {
        let msg: string = res.statusText || `Error ${res.status}`;
        try {
            // try to pull a JSON “message” field if present
            const payload = await res.clone().json();
            msg = payload?.message ?? msg;
        } catch {
            // fallback to plain text
            const txt = await res.clone().text();
            if (txt) msg = txt;
        }
        toast.error(msg);
    }
    return res;
}
