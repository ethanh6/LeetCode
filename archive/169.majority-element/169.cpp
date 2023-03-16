#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &arr) {
    int curr{}, count{};

    for(const auto& n: arr) {
      if (count == 0) curr = n;

      count += (curr == n) ? 1 : -1;
      cout << n << " " << curr << " " << count << endl;
    }
    return curr;
  }
};

int main() {

  Solution sol;
  auto input = vector<int>{1, 1, 2, 2, 2, 2, 3, 4};

  auto ans = sol.majorityElement(input);
  assert(ans == 2);

  return 0;
}
