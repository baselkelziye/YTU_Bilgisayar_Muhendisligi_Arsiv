// src/app/components/Navbar.tsx  (veya senin dosya yapına göre konumlandır)
import React, { useState} from 'react';
import { Link, NavLink, useNavigate } from 'react-router-dom';
import { useAuth } from '@/app/auth/hooks/AuthContext';
import './style.css';
import { signOut } from '@/api/userapi';

export const Navbar: React.FC = () => {
    const [isOpen, setIsOpen] = useState(false);
    const navigate = useNavigate();
    const {  logout, user } = useAuth();

    const toggleMenu = () => setIsOpen(open => !open);

    const handleLogout = () => {
        signOut().then(() => {
            console.log("Logout successful");
        }
        ).catch((error) => {
            console.error("Logout failed", error);
        }
        );
        logout();
        navigate('/');
    };

    return (
        <header className="navbar">
            <div className="navbar-container">
                <Link to="/" className="navbar-logo-text">
                    <span>
                        <img
                            alt = "logo"
                            src="/listopia.svg"
                            className=""
                            />
                    </span>Listopia
                </Link>

                <button
                    className="navbar-toggle"
                    onClick={toggleMenu}
                    aria-label="Toggle navigation"
                >
                    ☰
                </button>

                <nav className={`navbar-menu ${isOpen ? 'open' : ''}`}>
                    <NavLink
                        to="/"
                        end
                        className={({ isActive }) =>
                            isActive ? 'navbar-link active' : 'navbar-link'
                        }
                        onClick={() => setIsOpen(false)}
                    >
                        Home
                    </NavLink>
                    <NavLink
                        to="/genres"
                        className={({ isActive }) =>
                            isActive ? 'navbar-link active' : 'navbar-link'
                        }
                        onClick={() => setIsOpen(false)}
                    >
                        Movies
                    </NavLink>
                    <NavLink
                        to="/search"
                        className={({ isActive }) =>
                            isActive ? 'navbar-link active' : 'navbar-link'
                    }
                        onClick={() => setIsOpen(false)}
                    >
                        Search
                    </NavLink>

                    {user ? (
                        <>
                            <NavLink
                                to={`/chat`}
                                className={({ isActive }) =>
                                    isActive ? 'navbar-link active' : 'navbar-link'
                                }
                                onClick={() => setIsOpen(false)}
                            >
                                Chat
                            </NavLink>
                        </>
                    ) : null}

                    {user && user.role == "ADMIN" && (
                        <NavLink
                            to={`/admin/dashboard`}
                            className={({ isActive }) =>
                                isActive ? 'navbar-link active' : 'navbar-link'
                            }
                            onClick={() => setIsOpen(false)}
                        >
                        Admin Dashboard
                        </NavLink>
                    )}
                    
                    {user ? (
                        <>
                            <NavLink
                                to={`/profile/${user.username}`}
                                className={({ isActive }) =>
                                    isActive ? 'navbar-link active' : 'navbar-link'
                                }
                                onClick={() => setIsOpen(false)}
                            >
                                Profile
                            </NavLink>
                            <button 
                                className="navbar-link logout-button"
                                onClick={() => {
                                    handleLogout();
                                    setIsOpen(false);
                                }}
                            >
                                Log Out
                            </button>
                        </>
                    ) : (
                        <NavLink
                            to="/signin"
                            className={({ isActive }) =>
                                isActive ? 'navbar-link active' : 'navbar-link'
                            }
                            onClick={() => setIsOpen(false)}
                        >
                            Sign In
                        </NavLink>
                    )}
                </nav>
            </div>
        </header>
    );
};

export default Navbar;
