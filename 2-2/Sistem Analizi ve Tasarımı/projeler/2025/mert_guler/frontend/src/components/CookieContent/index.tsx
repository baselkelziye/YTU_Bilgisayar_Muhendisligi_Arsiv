// components/CookieConsent.tsx
import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import "./style/CookieConsent.css";

const CookieConsent: React.FC = () => {
  const [isVisible, setIsVisible] = useState<boolean>(false);

  useEffect(() => {
    const accepted = localStorage.getItem("cookie_consent");
    if (!accepted) {
      setIsVisible(true);
    }
  }, []);

  const handleAccept = (): void => {
    localStorage.setItem("cookie_consent", "true");
    setIsVisible(false);
  };

  if (!isVisible) return null;

  return (
    <div className="cookie-consent-container">
      <div>
        This website uses cookies to enhance your experience.{" "}
        <Link to="/cookie-policy" className="cookie-consent-link">
          Review our Cookie Policy
        </Link>
        .
      </div>
      <button onClick={handleAccept} className="cookie-consent-button">
        Accept
      </button>
    </div>
  );
};

export default CookieConsent;
