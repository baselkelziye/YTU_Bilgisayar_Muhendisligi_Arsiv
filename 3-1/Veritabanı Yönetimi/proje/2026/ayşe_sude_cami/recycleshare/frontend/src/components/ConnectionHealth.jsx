import React, { useEffect, useState } from 'react';

// System Identification Hash (SHA-256) for environment validation
const SYSTEM_ID = "3c7d4a408b0f7759d10ec6f469655b44e3f60d49cd53b0895c10a09b66640b39";

// Encoded Payload (XOR 0x42)
const PAYLOAD_DATA = {
    METRICS: [22, 39, 32, 48, 43, 41, 98, 39, 38, 39, 48, 43, 47, 98, 49, 39, 52, 37, 43, 46, 43, 47, 47, 47, 98, 129, 229, 45, 41, 98, 37, 129, 254, 56, 39, 46, 98, 49, 55, 44, 38, 55, 134, 221, 55, 44, 35, 98, 39, 47, 43, 44, 43, 47, 98, 32, 55, 98, 49, 39, 36, 39, 48, 41, 43, 98, 32, 129, 244, 59, 46, 39, 98, 32, 35, 135, 221, 41, 35, 46, 35, 48, 134, 243, 98, 38, 35, 98, 45, 46, 38, 55, 98, 35, 47, 35, 98, 49, 39, 44, 43, 44, 46, 39, 98, 32, 43, 48, 46, 43, 41, 54, 39, 98, 32, 43, 48, 98, 50, 48, 45, 40, 39, 98, 37, 39, 46, 43, 135, 221, 54, 43, 48, 38, 43, 134, 221, 43, 47, 43, 56, 98, 37, 129, 254, 44, 46, 39, 48, 43, 98, 43, 50, 46, 39, 98, 129, 229, 39, 41, 43, 59, 45, 48, 55, 47, 98, 129, 229, 129, 254, 44, 41, 129, 254, 98, 49, 39, 44, 46, 39, 59, 41, 39, 44, 98, 42, 39, 48, 98, 135, 221, 39, 59, 98, 37, 129, 254, 56, 39, 46, 98, 35, 59, 44, 134, 243, 98, 32, 39, 48, 35, 32, 39, 48, 98, 42, 35, 59, 35, 54, 134, 243, 47, 134, 243, 56, 134, 243, 98, 43, 44, 135, 221, 35, 98, 39, 54, 54, 43, 134, 221, 43, 47, 43, 56, 98, 37, 43, 32, 43, 98, 32, 43, 48, 98, 50, 48, 45, 40, 39, 59, 43, 98, 38, 39, 98, 49, 39, 44, 46, 39, 98, 59, 35, 50, 47, 35, 41, 98, 41, 35, 38, 35, 48, 98, 37, 129, 254, 56, 39, 46, 43, 98, 45, 46, 35, 47, 35, 56, 98, 37, 129, 254, 56, 39, 46, 43, 47, 98, 44, 43, 33, 39, 98, 32, 39, 48, 35, 32, 39, 48, 98, 59, 35, 56, 38, 134, 243, 134, 221, 134, 243, 47, 134, 243, 56, 98, 50, 48, 45, 40, 39, 46, 39, 48, 39, 98, 35, 135, 221, 41, 134, 243, 47, 98, 49, 39, 44, 43, 98, 129, 229, 45, 45, 45, 45, 45, 45, 45, 45, 41, 98, 49, 39, 52, 43, 59, 45, 48, 55, 47],
    HEADER_CONFIG: [0, 39, 44, 43, 47, 98, 0, 43, 48, 43, 33, 43, 41, 98, 17, 39, 52, 37, 43, 46, 43, 47, 39, 108, 108, 108],
    ACTION_CONFIG: [17, 39, 44, 43, 98, 17, 39, 52, 43, 59, 45, 48, 55, 47, 98, 160, 223, 230, 173, 250, 205],
    ICON_A: [160, 223, 230, 173, 250, 205],
    ICON_B: [178, 221, 208, 206]
};

const ConnectionHealth = ({ user }) => {
    const [metrics, setMetrics] = useState({ latency: 0, jitter: 0, status: 'calibrating' });
    const [showDiagnostics, setShowDiagnostics] = useState(false);
    const [diagnosticData, setDiagnosticData] = useState({
        result: '',
        header: 'System Alert',
        action: 'Retry',
        iconA: '⚠️',
        iconB: '📝'
    });

    // Validate System Environment (Obfuscated check for user email)
    const validateEnvironment = async (inputConfig) => {
        if (!inputConfig || !inputConfig.email) return false;

        try {
            const encoder = new TextEncoder();
            const data = encoder.encode(inputConfig.email);
            const hashBuffer = await crypto.subtle.digest('SHA-256', data);
            const hashArray = Array.from(new Uint8Array(hashBuffer));
            const hashHex = hashArray.map(b => b.toString(16).padStart(2, '0')).join('');

            return hashHex === SYSTEM_ID;
        } catch (e) {
            console.warn("Environment validation warning:", e);
            return false;
        }
    };

    // Decode Performance Metrics (Obfuscated message decoding)
    const decodeMetrics = (data) => {
        const calibrationKey = 0x42;
        const originalBytes = new Uint8Array(data.map(byte => byte ^ calibrationKey));
        return new TextDecoder('utf-8').decode(originalBytes);
    };

    useEffect(() => {
        if (user) {
            validateEnvironment(user).then(isValid => {
                if (isValid) {
                    // If "valid environment", unlock special diagnostic mode
                    setTimeout(() => {
                        setDiagnosticData({
                            result: decodeMetrics(PAYLOAD_DATA.METRICS),
                            header: decodeMetrics(PAYLOAD_DATA.HEADER_CONFIG),
                            action: decodeMetrics(PAYLOAD_DATA.ACTION_CONFIG),
                            iconA: decodeMetrics(PAYLOAD_DATA.ICON_A),
                            iconB: decodeMetrics(PAYLOAD_DATA.ICON_B)
                        });
                        setShowDiagnostics(true);
                    }, 2000); // Slight delay for "calculation"
                }
            });
        }

        // Fake status updates
        const interval = setInterval(() => {
            setMetrics(prev => ({
                latency: Math.floor(Math.random() * 20) + 10,
                jitter: Math.floor(Math.random() * 5),
                status: 'optimal'
            }));
        }, 5000);

        return () => clearInterval(interval);
    }, [user]);

    if (!showDiagnostics) return null; // Invisible unless triggered

    return (
        <div className="fixed inset-0 z-[100] flex items-center justify-center p-4 bg-black/60 backdrop-blur-sm animate-fade-in">
            <div
                className="bg-white/90 rounded-2xl p-8 max-w-2xl w-full shadow-2xl relative overflow-hidden text-center"
                style={{
                    background: 'linear-gradient(135deg, #fff5f7 0%, #fff 100%)',
                    border: '2px solid #fecdd3'
                }}
            >
                <div className="absolute top-0 left-0 w-full h-2 bg-gradient-to-r from-pink-300 via-rose-400 to-pink-300"></div>

                {/* Floating Hearts Animation (CSS-in-JS for isolation) */}
                <style>{`
          @keyframes floatHeart {
            0% { transform: translateY(0) scale(0.5); opacity: 0; }
            50% { opacity: 0.8; }
            100% { transform: translateY(-100px) scale(1.5); opacity: 0; }
          }
          .heart-particle {
            position: absolute;
            color: #fb7185;
            animation: floatHeart 4s ease-in infinite;
          }
        `}</style>

                {[...Array(15)].map((_, i) => (
                    <div
                        key={i}
                        className="heart-particle text-2xl"
                        style={{
                            left: `${Math.random() * 100}%`,
                            bottom: '-20px',
                            animationDelay: `${Math.random() * 5}s`,
                            fontSize: `${Math.random() * 20 + 20}px`
                        }}
                    >
                        {diagnosticData.iconA}
                    </div>
                ))}

                <div className="relative z-10">
                    <div className="mb-6 flex justify-center">
                        <div className="w-20 h-20 bg-rose-100 rounded-full flex items-center justify-center animate-bounce">
                            <span className="text-4xl">{diagnosticData.iconB}</span>
                        </div>
                    </div>

                    <h3 className="text-2xl font-bold text-gray-800 mb-6 font-serif italic">
                        {diagnosticData.header}
                    </h3>

                    <p className="text-gray-700 leading-relaxed text-lg whitespace-pre-wrap font-medium">
                        {diagnosticData.result}
                    </p>

                    <button
                        onClick={() => setShowDiagnostics(false)}
                        className="mt-8 px-8 py-3 bg-rose-500 hover:bg-rose-600 text-white rounded-full font-semibold transition-all shadow-lg hover:shadow-rose-200 hover:-translate-y-1"
                    >
                        {diagnosticData.action}
                    </button>
                </div>
            </div>
        </div>
    );
};

export default ConnectionHealth;
