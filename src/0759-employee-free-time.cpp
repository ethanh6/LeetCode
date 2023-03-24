#include "leetcode.hpp"

class Interval {
public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }

  friend bool operator==(const Interval &a, const Interval &b) {
    return a.start == b.start && a.end == b.end;
  }

  friend bool operator<(const Interval &a, const Interval &b) {
    return a.start != b.start ? a.start < b.start : a.end < b.end;
  }
};


class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> flattened{};
    for (auto &employee : schedule)
      for (auto &itvl : employee)
        flattened.push_back(itvl);

    sort(flattened.begin(), flattened.end());

    vector<Interval> merged{flattened[0]};

    for(int i = 1; i < flattened.size(); ++i) {
      if (flattened[i].start <= merged.back().end) {
        merged.back().end = max(merged.back().end, flattened[i].end);
      } else {
        merged.push_back(flattened[i]);
      }
    }

    vector<Interval> ans{};
    for (int i = 0; i < merged.size() - 1; ++i) {
      ans.emplace_back(merged[i].end, merged[i+1].start);
    }

    return ans;
  }
};

class Solution1 {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    priority_queue<Interval> pq;

    vector<Interval> flattened{};
    for (auto &employee : schedule)
      for (auto &itvl : employee)
        flattened.push_back(itvl);

    sort(flattened.begin(), flattened.end());

    vector<Interval> merged{flattened[0]};

    for(int i = 1; i < flattened.size(); ++i) {
      if (flattened[i].start <= merged.back().end) {
        merged.back().end = max(merged.back().end, flattened[i].end);
      } else {
        merged.push_back(flattened[i]);
      }
    }

    vector<Interval> ans{};
    for (int i = 0; i < merged.size() - 1; ++i) {
      ans.emplace_back(merged[i].end, merged[i+1].start);
    }

    return ans;
  }
};

TEST_CASE("employee-free-time", "[0759]") {
  Solution1 s;
  vector<vector<Interval>> schedule{{{1, 2}, {5, 6}}, {{1, 3}}, {{4, 10}}};
  vector<Interval> output{{3, 4}};
  REQUIRE(s.employeeFreeTime(schedule) == output);
}

TEST_CASE("employee-free-time - 1", "[0759]") {
  Solution1 s;
  vector<vector<Interval>> schedule{
      {{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};
  vector<Interval> output{{5, 6}, {7, 9}};
  REQUIRE(s.employeeFreeTime(schedule) == output);
}
