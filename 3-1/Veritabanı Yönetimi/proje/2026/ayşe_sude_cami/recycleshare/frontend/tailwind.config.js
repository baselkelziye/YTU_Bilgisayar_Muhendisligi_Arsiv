/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        // Eco-Minimalist Color Palette
        eco: {
          50: '#f0fdf4',
          100: '#dcfce7',
          200: '#bbf7d0',
          300: '#86efac',
          400: '#4ade80',
          500: '#22c55e',
          600: '#16a34a',
          700: '#15803d',
          800: '#166534',
          900: '#14532d',
          950: '#052e16',
        },
        emerald: {
          50: '#ecfdf5',
          100: '#d1fae5',
          200: '#a7f3d0',
          300: '#6ee7b7',
          400: '#34d399',
          500: '#10b981',
          600: '#059669',
          700: '#047857',
          800: '#065f46',
          900: '#064e3b',
          950: '#022c22',
        }
      },
      fontFamily: {
        sans: ['Inter', 'system-ui', 'sans-serif'],
      },
      boxShadow: {
        'eco': '0 4px 20px -2px rgba(16, 185, 129, 0.15)',
        'eco-lg': '0 10px 40px -10px rgba(16, 185, 129, 0.2)',
      },
      backgroundImage: {
        'eco-gradient': 'linear-gradient(135deg, #059669 0%, #10b981 50%, #34d399 100%)',
        'eco-gradient-subtle': 'linear-gradient(135deg, #f0fdf4 0%, #dcfce7 100%)',
      }
    },
  },
  plugins: [require("daisyui")],
  daisyui: {
    themes: [
      {
        recycleshare: {
          "primary": "#059669",
          "primary-content": "#ffffff",
          "secondary": "#10b981",
          "secondary-content": "#ffffff",
          "accent": "#34d399",
          "accent-content": "#064e3b",
          "neutral": "#1f2937",
          "neutral-content": "#f9fafb",
          "base-100": "#ffffff",
          "base-200": "#f9fafb",
          "base-300": "#f3f4f6",
          "base-content": "#1f2937",
          "info": "#3b82f6",
          "info-content": "#ffffff",
          "success": "#22c55e",
          "success-content": "#ffffff",
          "warning": "#f59e0b",
          "warning-content": "#ffffff",
          "error": "#ef4444",
          "error-content": "#ffffff",
        },
      },
    ],
  },
}
