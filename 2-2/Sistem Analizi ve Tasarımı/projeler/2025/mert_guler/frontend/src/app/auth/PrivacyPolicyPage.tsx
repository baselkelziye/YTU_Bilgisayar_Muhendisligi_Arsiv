import React from 'react';
import { Link } from 'react-router-dom';
import './style/PolicyPage.css';

export const PrivacyPolicyPage: React.FC = () => (
    <div className="policy-container">
        <h1>Privacy Policy</h1>
        <p>
            We value your privacy and are committed to protecting your personal data.
            This policy explains how we collect, use, and manage your information when you use our services.
        </p>
        <h2>1. Data Collection</h2>
        <p>
            We collect information you provide directly when you register, such as name,
            email address, and any other personal details.
        </p>

        <h2>2. Use of Data</h2>
        <p>
            Your data is used to provide, maintain, and improve our services, communicate with you,
            and comply with legal obligations.
        </p>

        <h2>3. Data Sharing</h2>
        <p>
            We do not sell your personal data. We may share information with service providers
            and partners under strict confidentiality agreements.
        </p>

        <Link to="/signin" className="btn-back">
            ← Back to Sign Up
        </Link>
    </div>
);