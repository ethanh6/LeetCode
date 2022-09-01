
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {

    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> ans = grid;

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        // initialization of first element
        if (i == 0 && j == 0) {
          continue;
        }
        // initialization of first row and col
        else if (i == 0 && j > 0) {
          ans[i][j] = ans[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          ans[i][j] = ans[i - 1][j] + grid[i][j];
        }
        // solve sub-problem by previous ans
        else {
          ans[i][j] = std::min(ans[i][j - 1], ans[i - 1][j]) + grid[i][j];
        }
      }
    }

    return ans[R-1][C-1];
  }
};
int main() {

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int ans = Solution().minPathSum(grid);
  assert(ans == 7);
  cout << "test (1) passed" << endl;

  grid = {{1, 3, 1}, {4, 2, 1}};
  ans = Solution().minPathSum(grid);
  assert(ans == 6);
  cout << "test (2) passed" << endl;
  return 0;
}
