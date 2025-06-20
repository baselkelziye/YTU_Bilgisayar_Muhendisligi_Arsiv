// src/main.tsx
import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import { AuthProvider } from './auth/hooks/AuthContext';

// 1️⃣ import ToastContainer + styles
import { ToastContainer } from 'react-toastify';
import './style.css';

ReactDOM.createRoot(document.getElementById('root')!).render(
    <React.StrictMode>
        <AuthProvider>
            <App />
            {/* 2️⃣ single container for all toasts */}
            <ToastContainer
                position="top-right"
                autoClose={4000}
                hideProgressBar={false}
                newestOnTop
                closeOnClick
                pauseOnHover
            />
        </AuthProvider>
    </React.StrictMode>
);
