import React from "react";
import ReactDOM from "react-dom/client"; // Use `react-dom/client` for React 18
import App from "./App";

// Create a root for rendering the React app
const root = ReactDOM.createRoot(document.getElementById("root"));

// Render the App component
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
);
