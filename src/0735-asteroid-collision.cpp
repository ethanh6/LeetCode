/*
We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign
represents its direction (positive meaning right, negative meaning left). Each
asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids
meet, the smaller one will explode. If both are the same size, both will
explode. Two asteroids moving in the same direction will never meet.

 **Example 1:**



     **Input:** asteroids = [5,10,-5] **Output:** [5,10] **Explanation:** The 10
and -5 collide resulting in 10. The 5 and 10 never collide.

 **Example 2:**



     **Input:** asteroids = [8,-8] **Output:** [] **Explanation:** The 8 and -8
collide exploding each other.

 **Example 3:**



     **Input:** asteroids = [10,2,-5] **Output:** [10] **Explanation:** The 2
and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

 **Constraints:**

  * `2 <= asteroids.length <= 104`
  * `-1000 <= asteroids[i] <= 1000`
  * `asteroids[i] != 0`


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;
    for (const auto &ast : asteroids) {

      // condition to exist while loop
      bool newAstExist = true;

      // collision will happen only when top of stack is -> and new ast is <-
      while (st.size() and st.top() > 0 and ast < 0 and newAstExist) {
        int diff = ast + st.top();

        if (diff > 0) { // new ast destryoed
          newAstExist = false;
        } else if (diff < 0) { // ast on top of stack destryoed
          st.pop();
        } else { // both are destryoed
          st.pop();
          newAstExist = false;
        }
      }

      if (newAstExist)
        st.push(ast);
    }

    vector<int> answer;
    for (; st.size(); st.pop())
      answer.insert(answer.begin(), st.top());
    return answer;
  }
};

TEST_CASE("asteroid-collision", "[0735]") {
  Solution sol;
  vector<int> asteroids{5, 10, -5}, output{5, 10};
  CHECK(sol.asteroidCollision(asteroids) == output);
}

TEST_CASE("asteroid-collision - 1", "[0735]") {
  Solution sol;
  vector<int> asteroids{10, 2, -5}, output{10};
  CHECK(sol.asteroidCollision(asteroids) == output);
}
