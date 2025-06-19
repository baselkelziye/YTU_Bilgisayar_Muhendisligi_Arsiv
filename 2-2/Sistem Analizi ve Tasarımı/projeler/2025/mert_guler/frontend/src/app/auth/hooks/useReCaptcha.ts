import { useEffect, useState } from 'react'

const RECAPTCHA_SITE_KEY = '6Ld7qCorAAAAAPivgChGfO9TKIKm0B7YLlLJD795'

declare global {
  interface Window {
    grecaptcha?: {
      ready: (callback: () => void) => void
      execute: (siteKey: string, options: { action: string }) => Promise<string>
    }
  }
}

export const useReCaptcha = () => {
  const [loaded, setLoaded] = useState(false)

  useEffect(() => {
    if (typeof window === 'undefined') return;
  
    const scriptSrc = `https://www.google.com/recaptcha/api.js?render=${RECAPTCHA_SITE_KEY}`;
    let scriptElement = document.querySelector(`script[src^="https://www.google.com/recaptcha/api.js"]`) as HTMLScriptElement | null;
    let scriptAppended = false;
  
    if (!scriptElement) {
      scriptElement = document.createElement('script');
      scriptElement.src = scriptSrc;
      scriptElement.async = true;
      scriptElement.onload = () => setLoaded(true);
      document.body.appendChild(scriptElement);
      scriptAppended = true;
    } else {
      setLoaded(true);
    }
  
    return () => {
      if (scriptAppended && scriptElement) {
        scriptElement.remove();
      }
  
      const badge = document.querySelector('.grecaptcha-badge') as HTMLElement | null;
      if (badge?.parentElement) {
        badge.parentElement.removeChild(badge);
      }
  
      if (window.grecaptcha) {
        delete window.grecaptcha;
      }
    };
  }, []);
    
  const execute = async (action: string): Promise<string> => {
    return new Promise((resolve, reject) => {
      if (!loaded || !window.grecaptcha) {
        return reject(new Error('ReCAPTCHA not loaded'))
      }

      window.grecaptcha.ready(() => {
        window.grecaptcha!
          .execute(RECAPTCHA_SITE_KEY, { action })
          .then(resolve)
          .catch(reject)
      })
    })
  }

  return { loaded, execute }
}
