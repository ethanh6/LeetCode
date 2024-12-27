/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{js,ts,jsx,tsx}"],
  theme: {
    extend: {
      colors: {
        "low-blue": "#7cc7d6", // A light, soft blue for headers and backgrounds
        "mid-blue": "#38bdf8", // A medium blue for hover effects and borders
        "deep-blue": "#0ea5e9", // A deep blue for primary buttons and active states
        "dark-blue": "#0369a1", // A dark blue for footers and secondary actions
        "hover-blue": "#0284c7", // A vibrant blue for hover effects
      },
      fontFamily: {
        sans: ["Inter", "sans-serif"], // A clean and modern sans-serif font
      },
      boxShadow: {
        "custom-light": "0 2px 8px rgba(56, 189, 248, 0.25)", // Light shadow for cards
        "custom-dark": "0 4px 16px rgba(14, 165, 233, 0.35)", // Heavier shadow for modals
      },
      spacing: {
        18: "4.5rem", // Custom spacing for finer layout control
      },
      transitionDuration: {
        400: "400ms", // Smooth transition effect
      },
    },
  },
  plugins: [],
};
