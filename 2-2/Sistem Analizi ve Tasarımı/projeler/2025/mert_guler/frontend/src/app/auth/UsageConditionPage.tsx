import React from 'react';
import { Link } from 'react-router-dom';
import './style/PolicyPage.css';

export const UsageConditionPage: React.FC = () => (
    <div className="policy-container">
        <h1>Usage Conditions</h1>
        <p>
            By using our application, you agree to comply with these conditions. Please read them carefully.
        </p>

        <h2>1. Account Responsibilities</h2>
        <p>
            You are responsible for maintaining the confidentiality of your account information
            and password.
        </p>

        <h2>2. Prohibited Actions</h2>
        <p>
            You must not use the service for any illegal or unauthorized purpose,
            including violating intellectual property rights.
        </p>

        <h2>3. Termination</h2>
        <p>
            We reserve the right to suspend or terminate your access if you breach
            these conditions.
        </p>

        <Link to="/signin" className="btn-back">
            ← Back to Sign Up
        </Link>
    </div>
);