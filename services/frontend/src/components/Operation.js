import React, { useState } from "react";
import axios from "axios";

function Operation() {
  const [formData, setFormData] = useState({
    id: "",
  });
  const [response, setResponse] = useState(null);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData((prev) => ({ ...prev, [name]: value }));
  };

  const handleSubmit = async (e) => {
    // Type guard to ensure `id` is an integer
    if (isNaN(Number(formData.id)) || !Number.isInteger(Number(formData.id))) {
      console.error("Invalid input: ID must be an integer.");
      alert("Please enter a valid integer for Problem ID.");
      setFormData({ id: "" });
      return;
    }

    e.preventDefault();
    const data = { ...formData };

    try {
      const res = await axios.post("/operation/add/", data);
      setResponse(res.data);
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div className="max-w-lg mx-auto p-6 bg-white shadow-lg rounded-lg">
      <h2 className="text-2xl font-semibold mb-4">Add Problem</h2>
      <form onSubmit={handleSubmit} className="space-y-4">
        <div>
          <label
            htmlFor="problemId"
            className="block text-lg font-medium text-gray-700"
          >
            Problem ID:
          </label>
          <input
            id="problemId"
            type="text"
            name="id"
            value={formData.id}
            onChange={handleChange}
            className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500"
          />
        </div>
        <button
          type="submit"
          className="w-full py-2 px-4 bg-blue-500 text-white rounded-lg hover:bg-blue-600 focus:outline-none"
        >
          Submit
        </button>
      </form>

      {response && (
        <div className="mt-6 p-4 bg-gray-100 rounded-lg">
          <h3 className="font-medium text-lg mb-2">Response:</h3>
          <pre className="text-sm text-gray-800">
            {JSON.stringify(response, null, 2)}
          </pre>
        </div>
      )}
    </div>
  );
}

export default Operation;
