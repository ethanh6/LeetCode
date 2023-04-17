#include "leetcode.hpp"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
    }
};

TEST_CASE("alien-dictionary", "[0269]") {
  Solution sol;
  vector<string> words = { "wrt","wrf","er","ett","rftt" };
  string output("wertf");
  CHECK(sol.alienOrder(words) == output);
}

TEST_CASE("alien-dictionary - 1", "[0269]") {
  Solution sol;
  vector<string> words = {"z","x"};
  string output("zx");
  CHECK(sol.alienOrder(words) == output);
}

TEST_CASE("alien-dictionary - 2", "[0269]") {
  Solution sol;
  vector<string> words = {"z","x","z"};
  string output("");
  CHECK(sol.alienOrder(words) == output);
}
