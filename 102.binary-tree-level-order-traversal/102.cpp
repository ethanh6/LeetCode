#include <assert.h>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  vector<vector<int>> ret;

public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
  }

  void buildVector(TreeNode *root, int depth) {
    if (root == NULL) {
      return;
    }
    if (ret.size() == depth) {
      ret.resize(depth + 1);
    }

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
  }
};

int main() { return 0; }
