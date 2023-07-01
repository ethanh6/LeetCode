/*
Given a characters array `tasks`, representing the tasks a CPU needs to do,
where each letter represents a different task. Tasks could be done in any
order. Each task is done in one unit of time. For each unit of time, the CPU
could complete either one task or just be idle.

Return _the least number of units of times that the CPU will take to finish
all the given tasks_.

 **Example 1:**



     **Input:** tasks = ["A","A","A","B","B","B"], n = 2 **Output:** 8
**Explanation:** A -> B -> idle -> A -> B -> idle -> A -> BThere is at least 2
units of time between any two same tasks.

 **Example 2:**



     **Input:** tasks = ["A","A","A","B","B","B"], n = 0 **Output:** 6
**Explanation:** On this case any permutation of size 6 would work since n =
0.["A","A","A","B","B","B"]["A","B","A","B","A","B"]["B","B","B","A","A","A"]...And
so on.

 **Example 3:**



     **Input:** tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
**Output:** 16 **Explanation:** One possible solution isA -> B -> C -> A -> D ->
E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

 **Constraints:**

  * `1 <= task.length <= 104`
  * `tasks[i]` is upper-case English letter.
  * The integer `n` is in the range `[0, 100]`.


*/

#include "leetcode.hpp"

class Solution0 {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // build frequency counter
    vector<int> freq(26, 0);
    for (const auto &t : tasks)
      freq[t - 'A'] += 1;

    // push frequency into max heap
    priority_queue<int> max_heap;
    for (const auto &x : freq)
      if (x)
        max_heap.push(x);

    int time = 0;
    queue<pair<int, int>> q; // pair of (count, available time)

    while (!max_heap.empty() || !q.empty()) {
      ++time;

      if (!max_heap.empty()) {
        int count = max_heap.top() - 1;
        max_heap.pop();
        if (count)
          q.push(make_pair(count, time + n));
      }

      if (!q.empty() && q.front().second == time) {
        max_heap.push(q.front().first);
        q.pop();
      }
    }

    return time;
  }
};

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // build frequency counter
    vector<int> freq(26, 0);
    for (const auto &t : tasks)
      freq[t - 'A'] += 1;

    // max freq
    int max_freq = 0;
    for (const int &f : freq)
      max_freq = max(max_freq, f);

    // number of tasks with frequency = max_freq
    int n_max = 0;
    for (const int &f : freq)
      n_max += f == max_freq;

    int case1 = tasks.size();
    int case2 = (max_freq - 1) * (n + 1) + n_max;

    return max(case1, case2);
  }
};

TEST_CASE("task-scheduler", "[0621]") {
  Solution sol;
  vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
  CHECK(sol.leastInterval(tasks, 2) == 8);
}

TEST_CASE("task-scheduler - 1", "[0621]") {
  Solution sol;
  vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
  CHECK(sol.leastInterval(tasks, 0) == 6);
}
