/*
Given an array of integers `temperatures` represents the daily temperatures,
return _an array_ `answer` _such that_ `answer[i]` _is the number of days you
have to wait after the_ `ith` _day to get a warmer temperature_. If there is
no future day for which this is possible, keep `answer[i] == 0` instead.

 **Example 1:**



     **Input:** temperatures = [73,74,75,71,69,72,76,73] **Output:**
[1,1,4,2,1,1,0,0]

 **Example 2:**



     **Input:** temperatures = [30,40,50,60] **Output:** [1,1,1,0]

 **Example 3:**



     **Input:** temperatures = [30,60,90] **Output:** [1,1,0]

 **Constraints:**


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
      int cur_temp = temperatures[i];
      while (st.size() and temperatures[st.top()] < cur_temp) {
        int prev_day = st.top(); st.pop();
        answer[prev_day] = i - prev_day;
      }
      st.push(i);
    }

    return answer;
  }
};

TEST_CASE("daily-temperatures", "[0739]") {
  vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> output{1, 1, 4, 2, 1, 1, 0, 0};
  Solution sol;
  CHECK(sol.dailyTemperatures(temperatures) == output);
}

TEST_CASE("daily-temperatures - 1", "[0739]") {
  vector<int> temperatures{30, 40, 50, 60};
  vector<int> output{1, 1, 1, 0};
  Solution sol;
  CHECK(sol.dailyTemperatures(temperatures) == output);
}

TEST_CASE("daily-temperatures - 2", "[0739]") {
  vector<int> temperatures{30, 60, 90};
  vector<int> output{1, 1, 0};
  Solution sol;
  CHECK(sol.dailyTemperatures(temperatures) == output);
}
