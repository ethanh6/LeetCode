/*
There are a total of `numCourses` courses you have to take, labeled from `0`
to `numCourses - 1`. You are given an array `prerequisites` where
`prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi`
first if you want to take course `ai`.

  * For example, the pair `[0, 1]`, indicates that to take course `0` you have
to first take course `1`.

Return _the ordering of courses you should take to finish all courses_. If
there are many valid answers, return **any** of them. If it is impossible to
finish all courses, return **an empty array**.

 **Example 1:**



     **Input:** numCourses = 2, prerequisites = [[1,0]] **Output:** [0,1]
**Explanation:** There are a total of 2 courses to take. To take course 1 you
should have finished course 0. So the correct course order is [0,1].

 **Example 2:**



     **Input:** numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
**Output:** [0,2,1,3] **Explanation:** There are a total of 4 courses to take.
To take course 3 you should have finished both courses 1 and 2. Both courses 1
and 2 should be taken after you finished course 0.So one correct course order is
[0,1,2,3]. Another correct ordering is [0,2,1,3].

 **Example 3:**



     **Input:** numCourses = 1, prerequisites = [] **Output:** [0]

 **Constraints:**

  * `1 <= numCourses <= 2000`
  * `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
  * `prerequisites[i].length == 2`
  * `0 <= ai, bi < numCourses`
  * `ai != bi`
  * All the pairs `[ai, bi]` are **distinct**.


*/

#include "leetcode.hpp"

struct CourseNode {
  int inDegree;
  vector<int> nextCourses;
};

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<CourseNode> nodes(numCourses);

    for (const auto &x : prerequisites) {
      int course = x[0], preq = x[1];
      nodes[course].inDegree++;
      nodes[preq].nextCourses.push_back(course);
    }

    // push no-prereq courses into queue
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (nodes[i].inDegree == 0)
        q.push(i);

    vector<int> ans;
    while (!q.empty()) {
      int course_id = q.front();
      q.pop();
      ans.push_back(course_id);
      for (const auto &next_course : nodes[course_id].nextCourses) {
        nodes[next_course].inDegree--;
        if (nodes[next_course].inDegree == 0) 
          q.push(next_course);
      }
    }

    return ans.size() == numCourses ? ans : vector<int>{};
  }
};

TEST_CASE("course-schedule-ii", "[0210]") {
  Solution sol;
  int numCourses = 2;
  vector<vector<int>> prerequisites{{1, 0}};
  vector<int> output{0, 1};
  CHECK(sol.findOrder(numCourses, prerequisites) == output);
}

TEST_CASE("course-schedule-ii - 1", "[0210]") {
  Solution sol;
  int numCourses = 4;
  vector<vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<int> output{0, 1, 2, 3};
  CHECK(sol.findOrder(numCourses, prerequisites) == output);
}

TEST_CASE("course-schedule-ii - 2", "[0210]") {
  Solution sol;
  int numCourses = 1;
  vector<vector<int>> prerequisites{};
  vector<int> output{0};
  CHECK(sol.findOrder(numCourses, prerequisites) == output);
}
