
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
  double average(vector<int>& salary) {
    int minimum = 1000001;
    int maximum = 0;
    double sum = 0.0;
    
    for(auto x : salary) {
      sum += double(x);
      maximum = max(x, maximum);
      minimum = min(x, minimum);
    }
    return (sum - minimum - maximum) / (salary.size() - 2) ;
  }
};

int main() {

  Solution sol;
  float ans;
  vector<int> input {4000, 3000, 1000, 2000};

  ans = sol.average(input);
  assert(ans == 2500.00000);

  return 0;
}
