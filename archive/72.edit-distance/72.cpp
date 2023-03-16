
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

enum Operation {nop, del, add, rep};

class Node {
public:
  int value;
  Operation op;

  Node(const Node& node) {
    this->value = node.value;
    this->op = nop;
  }

  Node() {
    this->value = 0;
    this->op = nop;
  }

  Node (int val, Operation op) {
    this->value = val;
    this->op = op;
  }

  friend bool operator< (const Node& a, const Node& b) {
    return a.value < b.value;
  }

  friend ostream& operator<< (ostream& os, const Node& n) {
    os << n.value ;
    return os;
  }
};

// find node with minimum value
auto min_node = [](const Node& a, const Node& b, const Node& c){
  // a: dp[i-1][j-1]
  // b: dp[i][j-1]
  // c: dp[i-1][j]
  if (a < b) {
    if (a < c) {
      return Node(a.value + 1, rep);
    } else {
      return Node(c.value + 1, del);
    }
  } else {
    if (b < c) {
      return Node(b.value + 1, add);
    } else {
      return Node(c.value + 1, del);
    }
  }
};

class Solution {
public:
  int minDistance_TraceTrack(string w1, string w2) {
    int m = w1.size(), n = w2.size();
    vector<vector<Node>> dp (m + 1, vector<Node>(n + 1));

    // print the dp table
    auto print = [&]() {
      for (int i = 0 ; i < m + 1 ; i++) {
        for (int j = 0 ; j < n + 1 ; j++) {
          cout << dp[i][j] << " " ;
        }
        cout << endl;
      }
    };

    // print transition
    auto print_trace = [&]() {
      // i and j are index of the table
      int i = m, j = n;
      string w = w1;

      cout << "Changing w1 = \"" << w1 << "\" to w2 = \"" << w2 << "\"" << endl;
      cout << "init.           (" << i << ", " << j << "), word = " << w << endl;

      while (i != 0 && j != 0) {
        switch (dp[i][j].op) {
          case nop :
            cout << "[nop] " << w1[i-1] << "      -> ";
            i--;
            j--;
            break;

          case del :
            cout << "[del] " << w1[i-1] << " ------> ";
            w.erase(w.begin() + i - 1);
            i--;
            break;

          case add :
            cout << "[add] " << w2[j-1] << " ------> ";
            w.insert(i, 1, w2[j-1]);
            j--;
            break;

          case rep:
            cout << "[rep] " << w1[i-1] << " -> " << w2[j-1] << " -> ";
            w[i - 1] = w2[j-1];
            i--;
            j--;
            break;
        }
        cout << "(" << i << ", " << j << "), word = " << w << endl;
      }

      while (i > 0) {
        w.erase(w.begin() + i - 1);
       // cout << "[del] " << w1[i - 1] << " at index " << i - 1 << ", word = " << w << endl;
        cout << "[del] " << w1[i - 1] << " ------> (" ; 
        i--;
        cout << i << ", " << j << "), word = " << w << endl;
      }
      while (j > 0) {
        w.insert(i, 1, w2[j-1]);
        // cout << "[add] " << w2[j - 1] << " at index  " << i << ", word = " << w << endl;
        cout << "[add] " << w2[j - 1] << " ------> (";
        j--;
        cout << i << ", " << j << "), word = " << w << endl;
      }
    };


    // fill the table
    for (int i = 0; i < m + 1 ; i++) {
      for (int j = 0; j < n + 1 ; j++) {

        // base case
        if (i == 0 && j == 0) {
          dp[i][j] = Node(0, nop);
        } else if (i == 0 && j != 0) {
          dp[i][j] = Node(j, add);
        } else if (i != 0 && j == 0) {
          dp[i][j] = Node(i, del);
        }

        // fill the table
        else if (w1[i-1] == w2[j-1]) {
          // no operation required
          dp[i][j] = Node(dp[i-1][j-1].value, nop);
        } else {
          dp[i][j] = min_node(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
        }
      }
    }

    print_trace();
    cout << endl;

    return dp[m][n].value;
  }

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
  // ans = sol.minDistance(w1, w2);
  // assert(ans == 3);
  ans = sol.minDistance_TraceTrack(w1, w2);
  assert(ans == 3);

  w1 = "intention";
  w2 = "execution";
  // ans = sol.minDistance(w1, w2);
  // assert(ans == 5);
  ans = sol.minDistance_TraceTrack(w1, w2);
  assert(ans == 5);

  w1 = "plasma";
  w2 = "altruism";
  // ans = sol.minDistance(w1, w2);
  // assert(ans == 6);
  ans = sol.minDistance_TraceTrack(w1, w2);
  assert(ans == 6);

  w1 = "";
  w2 = "please";
  // ans = sol.minDistance(w1, w2);
  // assert(ans == 6);
  ans = sol.minDistance_TraceTrack(w1, w2);
  assert(ans == 6);

  w1 = "please";
  w2 = "";
  // ans = sol.minDistance(w1, w2);
  // assert(ans == 6);
  ans = sol.minDistance_TraceTrack(w1, w2);
  assert(ans == 6);

  return 0;
}
