/*
There are a total of `numCourses` courses you have to take, labeled from `0`
to `numCourses - 1`. You are given an array `prerequisites` where
`prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi`
first if you want to take course `ai`.

  * For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

 **Example 1:**



     **Input:** numCourses = 2, prerequisites = [[1,0]] **Output:** true **Explanation:** There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

 **Example 2:**



     **Input:** numCourses = 2, prerequisites = [[1,0],[0,1]] **Output:** false **Explanation:** There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 **Constraints:**

  * `1 <= numCourses <= 2000`
  * `0 <= prerequisites.length <= 5000`
  * `prerequisites[i].length == 2`
  * `0 <= ai, bi < numCourses`
  * All the pairs prerequisites[i] are **unique**.


*/

#include "leetcode.hpp"

class CourseNode
{
public:
    int inDegree;
    std::vector<int> outNodes;
    CourseNode() : inDegree(0), outNodes(){};
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // build the graph
        unordered_map<int, CourseNode> graph;
        int totalDependencies = 0;
        for (const auto &preq: prerequisites) {
            int next_course = preq[0], prev_course = preq[1];
            graph[next_course].inDegree++;
            graph[prev_course].outNodes.push_back(next_course);
            totalDependencies++;
        }

        // courses that have no dependencies
        deque<int> notDependentCourses;
        for (const auto &i: graph) {
            if (i.second.inDegree == 0) {
                notDependentCourses.push_back(i.first);
            }
        }


        int removed_edge = 0;
        while (!notDependentCourses.empty()) {
            // pop a node in queue
            int course_id = notDependentCourses.front();
            CourseNode course_node = graph[course_id];
            notDependentCourses.pop_front();

            for (const auto &next_course_id: course_node.outNodes) {
                graph[next_course_id].inDegree--;
                if (graph[next_course_id].inDegree == 0) {
                    notDependentCourses.push_back(next_course_id);
                }
                removed_edge++;
            }
        }
        return removed_edge == prerequisites.size();
    }
};

TEST_CASE("course-schedule", "[0207]")
{
    Solution sol;
    CHECK(true);
}
