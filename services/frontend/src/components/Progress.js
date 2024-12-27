import React, { useEffect, useState } from "react";
import axios from "axios";

function Progress() {
  const [problemLists, setProblemLists] = useState(null);

  useEffect(() => {
    axios
      .get("/progress/problem-lists/")
      .then((response) => setProblemLists(response.data))
      .catch((error) => console.error(error));
  }, []);

  return (
    <div className="bg-white shadow-custom-light rounded-lg p-8">
      <h2 className="text-2xl font-bold text-deep-blue mb-6">Progress</h2>
      {problemLists ? (
        <div className="grid grid-cols-1 gap-6">
          {problemLists.data
            .filter((list) => list.active)
            .map((list) => (
              <div
                key={list.name}
                className="bg-low-blue p-4 rounded-lg shadow-inner"
              >
                <h3 className="text-lg font-bold mb-2 text-dark-blue">
                  {list.name}
                </h3>
                <ul className="text-sm text-dark-blue">
                  {list.list.map((problem, index) => (
                    <li key={index} className="font-medium">
                      Problem {problem}
                    </li>
                  ))}
                </ul>
              </div>
            ))}
        </div>
      ) : (
        <p>Loading...</p>
      )}
    </div>
  );
}

export default Progress;
