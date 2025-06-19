// src/context/auth.ts
import { User } from '@/types/user';

const STORAGE_KEY = 'authUser';

export function getUserFromStorage(): User | null {
    const data = localStorage.getItem(STORAGE_KEY);
    if (!data) return null;
    try {
        return JSON.parse(data) as User;
    } catch {
        console.error('Stored user data is invalid JSON');
        return null;
    }
}

export function saveUserToStorage(user: User): void {
    try {
        localStorage.setItem(STORAGE_KEY, JSON.stringify(user));
    } catch (err) {
        console.error('Could not save user to storage', err);
    }
}

export function clearUserFromStorage(): void {
    localStorage.removeItem(STORAGE_KEY);
}
