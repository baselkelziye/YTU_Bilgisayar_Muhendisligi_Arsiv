// AuthContext.tsx

import React, { createContext, useContext, useState, useEffect, ReactNode } from "react";
import { User } from "@/types/user";
import { getUserFromStorage, saveUserToStorage, clearUserFromStorage } from "../../../lib/auth";
import {fetchFriendsByUUID, fetchSentFriendRequests, fetchReceivedFriendRequests} from "@/api/userapi";
import { PaginatedResponse } from "@/types/friends";
import { BASE_URL } from "@/api/apiClient";

interface AuthContextType {
    user: User | null;
    friends: User[];
    sendingRequests: User[];
    receivedRequests: User[];
    login: (user: User) => void;
    logout: () => void;
    // isteğe bağlı olarak aşağıdakileri de açabilirsin:
    // refreshFriends: () => void;
    // refreshSentRequests: () => void;
    // refreshReceivedRequests: () => void;
}

interface AuthProviderProps {
    children: ReactNode;
}

async function getMe(): Promise<User> { 
    const res = await fetch(`${BASE_URL}api/v1/user/me`, { 
        method: "GET", credentials: "include" 
    }); 
    if (!res.ok) { 
        const errorText = await res.text(); 
        return Promise.reject(errorText) 
    } 
    return res.json() 
}

const AuthContext = createContext<AuthContextType | undefined>(undefined);

export const AuthProvider: React.FC<AuthProviderProps> = ({ children }) => {
    const [user, setUser] = useState<User | null>(null);
    const [uuid, setUuid] = useState<string | null>(null);
    const [friends, setFriends] = useState<User[]>([]);
    const [sendingRequests, setSendingRequests] = useState<User[]>([]);
    const [receivedRequests, setReceivedRequests] = useState<User[]>([]);

    // --- Yardımcı fetch fonksiyonları ---
    const fetchAllPages = async <T,>(
        fetcher: (...args: any[]) => Promise<PaginatedResponse<T>>,
        ...fetcherArgs: any[]
    ): Promise<T[]> => {
        let page = 0;
        const result: T[] = [];
        let hasMore = true;

        while (hasMore) {
            // eğer fetcher ek parametre isterse spread ile iletebilirsin
            const paged: PaginatedResponse<T> = await fetcher(...fetcherArgs, page);
            result.push(...paged.content);
            hasMore = !paged.last;
            page++;
        }

        return result;
    };


    // --- useEffects ---
    // 1) Oturumu local storage’dan yükle
    useEffect(() => {
        const stored = getUserFromStorage();
        if (stored) {
            setUser(stored);
        }
    }, []);


    useEffect(() => {
        getMe().then(setUser)
    }, []);

    // 2) user değiştiğinde uuid’yi ayarla
    useEffect(() => {
        if (user) setUuid(user.uuid);
        else setUuid(null);
    }, [user]);

    // 3) uuid hazır olduğunda hem friends, hem sent hem de received istekleri çek
    useEffect(() => {
        if (!uuid) {
            setFriends([]);
            setSendingRequests([]);
            setReceivedRequests([]);
            return;
        }

        // arkadaşları çek
        fetchAllPages<User>(fetchFriendsByUUID, uuid)
            .then(setFriends)
            .catch(console.error);

        // gönderilmiş istekleri çek
        fetchAllPages<User>(fetchSentFriendRequests)
            .then(setSendingRequests)
            .catch(console.error);

        // gelen istekleri çek (api’de böyle bir fonksiyon olmalı)
        fetchAllPages<User>(fetchReceivedFriendRequests)
            .then(setReceivedRequests)
            .catch(console.error);
    }, [uuid]);

    // const fetchMe = () =>{
    //     fetchUserMe().then((res)=>{
    //         if(!user){
    //             setUser(res)
    //         }else{
    //             if(res.uuid != user.uuid){
    //                 setUser(res)
    //             }
    //         }
    //     });
    // }
    //
    // useEffect(() => {
    //     // İlk hemen çağrı isterseniz:
    //     fetchMe();
    //
    //     const intervalId = setInterval(fetchMe, 5000);
    //     return () => clearInterval(intervalId);
    // }, []);

    // --- login / logout ---
    const login = (u: User) => {
        setUser(u);
        saveUserToStorage(u);
    };
    const logout = () => {
        setUser(null);
        clearUserFromStorage();
    };

    return (
        <AuthContext.Provider
            value={{
                user,
                friends,
                sendingRequests,
                receivedRequests,
                login,
                logout,
                // refreshFriends: () => uuid && fetchAllPages(fetchFriendsByUUID, uuid).then(setFriends),
                // refreshSentRequests: () => fetchAllPages(fetchSentFriendRequests).then(setSendingRequests),
                // refreshReceivedRequests: () => fetchAllPages(fetchReceivedFriendRequests).then(setReceivedRequests),
            }}
        >
            {children}
        </AuthContext.Provider>
    );
};

export const useAuth = (): AuthContextType => {
    const ctx = useContext(AuthContext);
    if (!ctx) throw new Error("useAuth must be used within AuthProvider");
    return ctx;
};
