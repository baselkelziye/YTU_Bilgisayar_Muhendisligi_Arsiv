module.exports = {
  purge: {
    enabled: true,
    content: ["../templates/**/*.jinja2"],
  },
  darkMode: false, // or 'media' or 'class'
  theme: {
    container: {
      center: true,
    },
    extend: {},
  },
  variants: {
    extend: {
      opacity: ['disabled'],
      cursor: ['disabled']
    },
  },
  plugins: [require("@tailwindcss/forms")],
};
