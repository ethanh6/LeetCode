import React, { useEffect, useState } from "react";
import axios from "axios";

function Home() {
  const [healthStatus, setHealthStatus] = useState("Checking...");

  useEffect(() => {
    axios
      .get("/health/")
      .then((response) => setHealthStatus(response.data))
      .catch((error) => {
        console.error(error);
        setHealthStatus({ error: error.message });
      });
  }, []);

  return (
    <div className="flex items-center space-x-2">
      <p className="text-sm font-medium mr-2">DB Status:</p>
      <p
        className={`text-lg font-bold ${
          healthStatus === "Healthy"
            ? "text-green-600"
            : healthStatus === "Unavailable"
              ? "text-red-600"
              : "text-yellow-600"
        }`}
      >
        {healthStatus.status}
      </p>
    </div>
  );
}

export default Home;
