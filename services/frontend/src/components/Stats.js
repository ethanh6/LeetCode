import React, { useEffect, useState } from "react";
import axios from "axios";

function Stats() {
  const [DS, setDS] = useState(null);
  const [algo, setAlgo] = useState(null);
  const [difficulty, setDifficulty] = useState(null);
  const [allProblem, setAllProblem] = useState(null);
  const [language, setLanguage] = useState(null);

  useEffect(() => {
    axios
      .get("/statistics/data-structure/")
      .then((response) => setDS(response.data))
      .catch((error) => console.error(error));
  }, []);

  useEffect(() => {
    axios
      .get("/statistics/algorithm/")
      .then((response) => setAlgo(response.data))
      .catch((error) => console.error(error));
  }, []);

  useEffect(() => {
    axios
      .get("/statistics/difficulty/")
      .then((response) => setDifficulty(response.data))
      .catch((error) => console.error(error));
  }, []);

  useEffect(() => {
    axios
      .get("/statistics/all-problem/")
      .then((response) => setAllProblem(response.data))
      .catch((error) => console.error(error));
  }, []);

  useEffect(() => {
    axios
      .get("/statistics/language/")
      .then((response) => setLanguage(response.data))
      .catch((error) => console.error(error));
  }, []);

  return (
    <div className="bg-white shadow-custom-light rounded-lg p-8">
      <h2 className="text-2xl font-bold text-deep-blue mb-6">
        LeetCode Statistics
      </h2>
      <div className="grid grid-cols-1 md:grid-cols-4 gap-6">
        {/* Data Structure Statistics */}
        <div className="bg-low-blue p-4 rounded-lg shadow-inner text-dark-blue">
          <h3 className="text-lg font-bold mb-2">Data Structures</h3>
          {DS ? (
            <ul>
              {Object.entries(DS.data).map(([key, value]) => (
                <li key={key} className="text-sm font-medium">
                  {key}: {value}
                </li>
              ))}
            </ul>
          ) : (
            <p>Loading...</p>
          )}
        </div>

        {/* Algorithm Statistics */}
        <div className="bg-low-blue p-4 rounded-lg shadow-inner text-dark-blue">
          <h3 className="text-lg font-bold mb-2">Algorithms</h3>
          {algo ? (
            <ul>
              {Object.entries(algo.data).map(([key, value]) => (
                <li key={key} className="text-sm font-medium">
                  {key}: {value}
                </li>
              ))}
            </ul>
          ) : (
            <p>Loading...</p>
          )}
        </div>

        {/* Difficulty Statistics */}
        <div className="bg-low-blue p-4 rounded-lg shadow-inner text-dark-blue">
          <h3 className="text-lg font-bold mb-2">Difficulty</h3>
          {difficulty ? (
            <ul>
              {Object.entries(difficulty.data).map(([key, value]) => (
                <li key={key} className="text-sm font-medium">
                  {String(key).charAt(0).toUpperCase() + String(key).slice(1)} :{" "}
                  {value} / {allProblem.data[key]} ={" "}
                  {((value * 100) / allProblem.data[key]).toFixed(2)}%
                </li>
              ))}
            </ul>
          ) : (
            <p>Loading...</p>
          )}
        </div>

        {/* Language Statistics */}
        <div className="bg-low-blue p-4 rounded-lg shadow-inner text-dark-blue">
          <h3 className="text-lg font-bold mb-2">Language</h3>
          {difficulty ? (
            <ul>
              {Object.entries(language.data).map(([key, value]) => (
                <li key={key} className="text-sm font-medium">
                  {key}: {value}
                </li>
              ))}
            </ul>
          ) : (
            <p>Loading...</p>
          )}
        </div>
      </div>
    </div>
  );
}

export default Stats;
