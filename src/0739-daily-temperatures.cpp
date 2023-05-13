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

class Solution0 {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
      int cur_temp = temperatures[i];
      while (st.size() and temperatures[st.top()] < cur_temp) {
        int prev_day = st.top();
        st.pop();
        answer[prev_day] = i - prev_day;
      }
      st.push(i);
    }

    return answer;
  }
};

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;
    int hottest = 0;

    for (int i = n - 1; i >= 0; --i) {
      int cur_temp = temperatures[i];
      if (cur_temp >= hottest) {
        hottest = cur_temp;
        answer[i] = 0;
        continue;
      }
      int days_gap = 1;
      while (temperatures[i + days_gap] <= cur_temp) {
        days_gap += answer[i + days_gap];
      }

      answer[i] = days_gap;
    }

    return answer;
  }
};

TEST_CASE("daily-temperatures", "[0739]") {
  Solution sol;

  SECTION("0") {
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> output{1, 1, 4, 2, 1, 1, 0, 0};
    CHECK(sol.dailyTemperatures(temperatures) == output);
  }

  SECTION("1") {
    vector<int> temperatures{30, 40, 50, 60};
    vector<int> output{1, 1, 1, 0};
    CHECK(sol.dailyTemperatures(temperatures) == output);
  }

  SECTION("2") {
    vector<int> temperatures{30, 60, 90};
    vector<int> output{1, 1, 0};
    CHECK(sol.dailyTemperatures(temperatures) == output);
  }
}
