
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    cout << p[1] << endl;
    while (i < s.size() && j < p.size()) {
      if (s[i] == p[j] || p[j] == '.') {
        i++;
        j++;
      } else {
        return false;
      }
    }

    return i == j;
  }
};

int main() {

  Solution sol;
  bool ans;
  string s, p;

  s = "aa";  // string
  p = "a";   // pattern
  ans = sol.isMatch(s, p);
  assert(ans == false);
  cout << "(1) passed" << endl;

  s = "aa";
  p = "a*";
  ans = sol.isMatch(s, p);
  assert(ans == true);
  cout << "(2) passed" << endl;

  s = "ab";
  p = ".*";
  ans = sol.isMatch(s, p);
  assert(ans == true);
  cout << "(3) passed" << endl;
  return 0;
}
