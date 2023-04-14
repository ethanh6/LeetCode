/*
Given an `m x n` grid of characters `board` and a string `word`, return `true`
_if_ `word` _exists in the grid_.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter
cell may not be used more than once.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)



     **Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCCED" **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)



     **Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "SEE" **Output:** true

 **Example 3:**

![](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)



     **Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCB" **Output:** false

 **Constraints:**

  * `m == board.length`
  * `n = board[i].length`
  * `1 <= m, n <= 6`
  * `1 <= word.length <= 15`
  * `board` and `word` consists of only lowercase and uppercase English letters.

 **Follow up:** Could you use search pruning to make your solution faster with
a larger `board`?


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool exist(vector<vector<char>> &board, string word) {
    int rows = board.size(), cols = board[0].size();

    std::function<bool(int, int, int)> dfs = [&](int i, int j, int idx) {
      // invalid index
      if (!(0 <= i && i < rows && 0 <= j && j < cols))
        return false;

      // word mismatch
      if (board[i][j] != word[idx])
        return false;

      // reach the end of target word
      if (idx == word.size() - 1)
        return true;

      char original_char = board[i][j];
      board[i][j] = '.';

      for (const auto &dir : directions) {
        int drow = dir[0], dcol = dir[1];
        int newrow = i + drow, newcol = j + dcol;
        if (dfs(newrow, newcol, idx + 1))
          return true;
      }

      board[i][j] = original_char;
      return false;
    };

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
        if (board[i][j] == word[0])
          if (dfs(i, j, 0))
            return true;

    return false;
  }
};

TEST_CASE("word-search", "[0079]") {
  Solution sol;
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  CHECK(sol.exist(board, word));
}

TEST_CASE("word-search - 1", "[0079]") {
  Solution sol;
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "SEE";
  CHECK(sol.exist(board, word));
}

TEST_CASE("word-search - 2", "[0079]") {
  Solution sol;
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCB";
  CHECK_FALSE(sol.exist(board, word));
}
