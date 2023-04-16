#include "leetcode.hpp"

class Solution0 {
public:
  int getFood(vector<vector<char>> &grid) {
    vector<int> dirs{0, 1, 0, -1, 0};

    // find starting position
    int rows = grid.size(), cols = grid[0].size();
    cout << rows << " " << cols << endl;
    int start_r = 0, start_c = 0;
    for (int k = 0; k < (rows * cols); ++k) {
      if (grid[k / rows][k % rows] == '*') {
        start_r = k / rows;
        start_c = k % rows;
        break;
      }
    }

    std::function<bool(const int &, const int &)> isValidIdx =
        [&](const int &i, const int &j) {
          return 0 <= i && i < rows && 0 <= j && j < cols;
        };
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    vector<pair<int, int>> layer{pair<int, int>{start_r, start_c}};
    int step = 0;

    while (layer.size() != 0) {
      vector<pair<int, int>> next_layer;

      // process a layer
      for (const auto &e : layer) {
        auto [r, c] = e;
        visited[r][c] = true;

        // on each node, explore 4 directions
        for (int k = 0; k < 4; ++k) {
          int rr = r + dirs[k], cc = c + dirs[k + 1];

          // can't go or visited
          if (!isValidIdx(rr, cc) || visited[rr][cc] || grid[rr][cc] == 'X')
            continue;

          // food found
          if (grid[rr][cc] == '#')
            return step + 1;

          // new empty space found
          next_layer.push_back(pair<int, int>{rr, cc});
        }
      }

      // a layer is done
      step++;
      layer = next_layer;
    }

    // food not found until the end
    return -1;
  }
};

class Solution1 {
public:
  int getFood(vector<vector<char>> &grid) {
    vector<int> dirs{0, 1, 0, -1, 0};

    // find starting position
    int rows = grid.size(), cols = grid[0].size();
    int start_r = 0, start_c = 0;
    for (int k = 0; k < (rows * cols); ++k) {
      if (grid[k / rows][k % rows] == '*') {
        start_r = k / rows;
        start_c = k % rows;
        break;
      }
    }

    std::function<bool(const int &, const int &)> isValidIdx =
        [&](const int &i, const int &j) {
          return 0 <= i && i < rows && 0 <= j && j < cols;
        };
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<int, int>> layer;
    layer.push(pair<int, int>{start_r, start_c});
    int step = 0;

    while (!layer.empty()) {
      // process a layer
      int sz = layer.size();
      while (sz--) {
        auto [r, c] = layer.front();
        layer.pop();
        visited[r][c] = true;

        // on each node, explore 4 directions
        for (int k = 0; k < 4; ++k) {
          int rr = r + dirs[k], cc = c + dirs[k + 1];

          // can't go or visited
          if (!isValidIdx(rr, cc) || visited[rr][cc] || grid[rr][cc] == 'X')
            continue;

          // food found
          if (grid[rr][cc] == '#')
            return step + 1;

          // new empty space found
          layer.push(pair<int, int>{rr, cc});
        }
      }

      // a layer is done
      step++;
    }

    // food not found until the end
    return -1;
  }
};

TEST_CASE("shortest-path-to-get-food", "[1730]") {
  Solution0 sol;
  vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X', 'X'},
                               {'X', '*', 'O', 'O', 'O', 'X'},
                               {'X', 'O', 'O', '#', 'O', 'X'},
                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  int output = 3;
  CHECK(sol.getFood(grid) == output);
}

TEST_CASE("shortest-path-to-get-food - 1", "[1730]") {
  Solution0 sol;
  vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X'},
                               {'X', '*', 'X', 'O', 'X'},
                               {'X', 'O', 'X', '#', 'X'},
                               {'X', 'X', 'X', 'X', 'X'}};
  int output = -1;
  CHECK(sol.getFood(grid) == output);
}

TEST_CASE("shortest-path-to-get-food - 2", "[1730]") {
  Solution0 sol;
  vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                               {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
                               {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
                               {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
                               {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};
  int output = 6;
  CHECK(sol.getFood(grid) == output);
}

TEST_CASE("shortest-path-to-get-food - 3", "[1730]") {
  Solution0 sol;
  vector<vector<char>> grid = {{'O'}, {'*'}};
  int output = -1;
  CHECK(sol.getFood(grid) == output);
}
