/*
A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or
**prefix tree** is a tree data structure used to efficiently store and
retrieve keys in a dataset of strings. There are various applications of this
data structure, such as autocomplete and spellchecker.

Implement the Trie class:

  * `Trie()` Initializes the trie object.
  * `void insert(String word)` Inserts the string `word` into the trie.
  * `boolean search(String word)` Returns `true` if the string `word` is in the
trie (i.e., was inserted before), and `false` otherwise.
  * `boolean startsWith(String prefix)` Returns `true` if there is a previously
inserted string `word` that has the prefix `prefix`, and `false` otherwise.

 **Example 1:**



     **Input** ["Trie", "insert", "search", "search", "startsWith", "insert",
"search"][[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
**Output** [null, null, true, false, true, null, true] **Explanation** Trie trie
= new Trie();trie.insert("apple");trie.search("apple");   // return
Truetrie.search("app");     // return Falsetrie.startsWith("app"); // return
Truetrie.insert("app");trie.search("app");     // return True

 **Constraints:**

  * `1 <= word.length, prefix.length <= 2000`
  * `word` and `prefix` consist only of lowercase English letters.
  * At most `3 * 104` calls **in total** will be made to `insert`, `search`, and
`startsWith`.


*/

#include "leetcode.hpp"

struct Node {
  unordered_map<char, Node *> children;
  char letter;
  bool is_leaf;
  Node(char c) : letter(c), is_leaf(false) {}
};

class Trie {
private:
  Node *root;

public:
  Trie() : root(new Node(' ')) {}

  void insert(string word) {
    auto cur_node = root;
    for (const auto &c : word) {
      // c not found in cur_node's children list
      if (cur_node->children.find(c) == cur_node->children.end())
        cur_node->children[c] = new Node(c);

      cur_node = cur_node->children[c];
    }
    cur_node->is_leaf = true;
  }

  bool search(string word) {
    auto cur_node = root;
    for (const auto &c : word) {
      // c not found in cur_node's children list
      if (cur_node->children.find(c) == cur_node->children.end())
        return false;

      cur_node = cur_node->children[c];
      if (!cur_node) return false;
    }
    return cur_node->is_leaf;
  }

  bool startsWith(string prefix) {
    auto cur_node = root;
    for (const auto &c : prefix) {
      // c not found in cur_node's children list
      if (cur_node->children.find(c) == cur_node->children.end())
        return false;
      cur_node = cur_node->children[c];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

TEST_CASE("implement-trie-prefix-tree", "[0208]") {
  auto trie = new Trie();
  trie->insert("apple");
  CHECK(trie->search("apple"));
  CHECK_FALSE(trie->search("app"));
  CHECK(trie->startsWith("app"));

  trie->insert("app");

  CHECK(trie->search("app"));
}
