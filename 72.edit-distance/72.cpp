
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1));

    auto mymin = [](int a, int b, int c){return min(min(a, b), c);};
    auto print = [&]() {
      for (int i = 0 ; i < m + 1 ; i++) {
        for (int j = 0 ; j < n + 1 ; j++) {
          cout << dp[i][j] << " " ;
        }
        cout << endl;
      }
    };

    for (int i = 0; i < m + 1 ; i++) {
      for (int j = 0; j < n + 1 ; j++) {

        // base case
        if (i == 0 && j == 0) {
          dp[i][j] = 0;
        } else if (i == 0 && j != 0) {
          dp[i][j] = j;
        } else if (i != 0 && j == 0) {
          dp[i][j] = i;
        }

        // fill the table
        else if (word1[i-1] == word2[j-1]) {
          // no operation required
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = mymin(dp[i-1][j-1] + 1, // replace last char at word2
                         dp[i][j-1] + 1,  // delete last char at word2
                         dp[i-1][j] + 1   // append one char at word2
                         );
        }
      }
    }
    print();
    return dp[m][n];
  }
};

int main() {

  Solution sol;
  int ans;
  string w1, w2;

  w1 = "ros";
  w2 = "horse";
  ans = sol.minDistance(w1, w2);
  assert(ans == 3);

  w1 = "intention";
  w2 = "execution";
  ans = sol.minDistance(w1, w2);
  assert(ans == 5);

  w1 = "altruism";
  w2 = "plasma";
  ans = sol.minDistance(w1, w2);
  assert(ans == 6);

  return 0;
}
