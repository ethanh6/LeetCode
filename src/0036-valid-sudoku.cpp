/*


**Note:**

  * A Sudoku board (partially filled) could be valid but is not necessarily
solvable.

 **Example 1:**

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-
by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)



     **Input:** board =
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
**Output:** true

 **Example 2:**



     **Input:** board =
[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
**Output:** false **Explanation:** Same as Example 1, except with the **5** in
the top left corner being modified to **8**. Since there are two 8's in the top
left 3x3 sub-box, it is invalid.

 **Constraints:**

  * `board.length == 9`
  * `board[i].length == 9`
  * `board[i][j]` is a digit `1-9` or `'.'`.


*/

#include "leetcode.hpp"

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {

    int n = 9;
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        char x = board[r][c];

        if (x == '.')
          continue;

        // rows
        if (rows[r].count(x) != 0)
          return false;
        else
          rows[r].insert(x);

        // cols
        if (cols[c].count(x) != 0)
          return false;
        else
          cols[c].insert(x);

        // boxes
        int idx = (r / 3) * 3 + (c / 3);
        if (boxes[idx].count(x) != 0)
          return false;
        else 
          boxes[idx].insert(x);

      }
    }

    return true;
  }
};

TEST_CASE("valid-sudoku", "[0036]") {
  Solution sol;
  vector<vector<char>> board{{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};

  CHECK(sol.isValidSudoku(board));
}

TEST_CASE("valid-sudoku - 1", "[0036]") {
  Solution sol;
  vector<vector<char>> board{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  CHECK_FALSE(sol.isValidSudoku(board));
}
