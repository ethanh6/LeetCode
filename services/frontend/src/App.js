import React from "react";
import {
  BrowserRouter as Router,
  Routes,
  Route,
  Link,
  useLocation,
} from "react-router-dom";
import Health from "./components/Health.js";
import Stats from "./components/Stats.js";
import Progress from "./components/Progress";
import Operation from "./components/Operation";
import "./styles/index.css";

function Header() {
  const location = useLocation();

  return (
    <header className="bg-low-blue text-dark-blue shadow-custom-light">
      <div className="container mx-auto px-4 py-6">
        <div className="flex justify-between items-center">
          {/* Header Titles */}
          <div>
            <h1 className="text-3xl font-bold">Leetcode Tracker</h1>
            <h2 className="text-lg mt-2">
              React + FastAPI + TailwindCSS + PostgreSQL
            </h2>
          </div>

          {/* Health Status */}
          <div className="flex items-center">
            <Health />
          </div>
        </div>

        {/* Navigation */}
        <nav className="mt-4">
          <ul className="flex space-x-4">
            <li>
              <Link
                to="/"
                className={`px-6 py-3 rounded-lg shadow-md text-lg font-medium ${
                  location.pathname === "/"
                    ? "bg-white text-deep-blue border-2 border-deep-blue"
                    : "bg-transparent text-dark-blue hover:bg-hover-blue hover:text-white"
                } transition-all duration-300`}
              >
                Home
              </Link>
            </li>
            <li>
              <Link
                to="/operation"
                className={`px-6 py-3 rounded-lg shadow-md text-lg font-medium ${
                  location.pathname === "/operation"
                    ? "bg-white text-deep-blue border-2 border-deep-blue"
                    : "bg-transparent text-dark-blue hover:bg-hover-blue hover:text-white"
                } transition-all duration-300`}
              >
                Operation
              </Link>
            </li>
          </ul>
        </nav>
      </div>
    </header>
  );
}

function HomePage() {
  return (
    <div className="grid grid-cols-1 gap-6 lg:grid-cols-1">
      {/* First Row */}
      <div className="col-span-1 lg:col-span-1 bg-white shadow-custom-light rounded-lg">
        <Stats />
      </div>

      {/* Second Row */}
      <div className="col-span-1 lg:col-span-2 bg-white shadow-custom-light rounded-lg">
        <Progress />
      </div>
    </div>
  );
}

function App() {
  return (
    <Router>
      <div className="App flex flex-col min-h-screen bg-gray-100 text-gray-800">
        <Header />
        <main className="flex-grow container mx-auto px-4 py-8">
          <Routes>
            <Route path="/" element={<HomePage />} />
            <Route path="/operation" element={<Operation />} />
          </Routes>
        </main>
        <footer className="bg-gray-100 text-dark-blue py-6">
          <div className="container mx-auto text-center">
            <p className="text-sm">
              &copy; 2024 LeetCode Tracker made by Ethan Huang. All rights
              reserved.
            </p>
          </div>
        </footer>
      </div>
    </Router>
  );
}

export default App;
