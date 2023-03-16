
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    if (nums.size() == 0) {
      return {{}};
    }

    int last = nums.back();
    nums.pop_back();
    vector<vector<int>> result = subsets(nums);

    for (int i = 0; i < result.size(); i++) {
      result.push_back(result[i]);
      result.back().push_back(last);
    }

    return result;
  }
};

int main() {

  Solution sol;
  vector<int> input = {1, 2, 3};

  vector<vector<int>> ans = sol.subsets(input);

  return 0;
}
