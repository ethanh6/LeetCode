/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules** :

  1. Each of the digits `1-9` must occur exactly once in each row.
  2. Each of the digits `1-9` must occur exactly once in each column.
  3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3`
sub-boxes of the grid.

The `'.'` character indicates empty cells.

 **Example 1:**

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-
by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)



     **Input:** board =
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
**Output:**
[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

 **Constraints:**

  * `board.length == 9`
  * `board[i].length == 9`
  * `board[i][j]` is a digit or `'.'`.
  * It is **guaranteed** that the input board has only one solution.


*/

#include "leetcode.hpp"

class Solution {
public:
  int n = 9;
  unordered_map<int, unordered_set<int>> rows;
  unordered_map<int, unordered_set<int>> cols;
  unordered_map<int, unordered_set<int>> boxes;

  bool is_valid(int r, int c, int v) {
    return rows[r].count(v) + cols[c].count(v) +
               boxes[get_boxid(r, c)].count(v) ==
           0;
  }

  int get_boxid(int r, int c) { return (r / 3) * 3 + c / 3; }

  bool backtrack(int r, int c, vector<vector<char>> &board) {
    // terminal condition
    if (r == n - 1 && c == n) {
      return true;
    }

    // if reach last column of any row other than the last row
    else if (c == n) {
      r++;
      c = 0;
    }

    // if current grid has been filled
    if (board[r][c] != '.') {
      return backtrack(r, c + 1, board);
    }

    int box_id = get_boxid(r, c);

    for (int v = 1; v <= n; ++v) {
      if (!is_valid(r, c, v))
        continue;

      // place an option
      board[r][c] = static_cast<char>(v + '0');
      rows[r].insert(v);
      cols[c].insert(v);
      boxes[box_id].insert(v);

      // backtrack aka go to next step
      if (backtrack(r, c + 1, board))
        return true;

      // revert changes
      board[r][c] = '.';
      rows[r].erase(v);
      cols[c].erase(v);
      boxes[box_id].erase(v);
    }
    return false;
  }

  void solveSudoku(vector<vector<char>> &board) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (board[r][c] == '.')
          continue;

        int v = board[r][c] - '0';
        rows[r].insert(v);
        cols[c].insert(v);
        boxes[get_boxid(r, c)].insert(v);
      }
    }
    backtrack(0, 0, board);
  }
};

TEST_CASE("sudoku-solver", "[0037]") {
  Solution sol;
  vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  vector<vector<char>> output{{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                              {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                              {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                              {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                              {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                              {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                              {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                              {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                              {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
  sol.solveSudoku(board);
  CHECK(board == output);
}
