#pragma once
#include <algorithm>
#include <bitset>
#include <cassert>
#include <catch2/catch_test_macros.hpp>
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
#include <optional>
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

template <typename T> void print_vector(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  std::cout << std::endl;
}

template <typename T> void print_2d_vector(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print_vector<typename T::value_type>);
}

template <typename Q> void print_queue(Q q) {
  // NB: q is passed by value because there is no way to traverse
  // priority_queue's content without erasing the queue.
  for (; !q.empty(); q.pop())
    std::cout << q.top() << ", ";
  std::cout << endl;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
