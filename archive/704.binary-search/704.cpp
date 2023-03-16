
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (target > nums[mid]) {
        left = mid + 1;
      } else if (target < nums[mid]) {
        right = mid  - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};

int main() {

  Solution sol;
  int ans;
  vector<int> v ;

  v = {-1,0,3,5,9,12};
  ans = sol.search(v, 9);
  assert(ans == 4);
  ans = sol.search(v, 2);
  assert(ans == -1);

  v = {1, 2, 3, 4};
  ans = sol.search(v, 0);
  assert(ans == -1);
  ans = sol.search(v, 1);
  assert(ans == 0);
  ans = sol.search(v, 2);
  assert(ans == 1);
  ans = sol.search(v, 3);
  assert(ans == 2);
  ans = sol.search(v, 4);
  assert(ans == 3);
  ans = sol.search(v, 5);
  assert(ans == -1);

  return 0;
}
