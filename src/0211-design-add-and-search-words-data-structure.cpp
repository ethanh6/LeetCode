/*
Design a data structure that supports adding new words and finding if a string
matches any previously added string.

Implement the `WordDictionary` class:

  * `void addWord(word)` Adds `word` to the data structure, it can be matched
later.

 **Example:**



     **Input**
["WordDictionary","addWord","addWord","addWord","search","search","search","search"][[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
**Output** [null,null,null,null,false,true,true,true] **Explanation**
WordDictionary wordDictionary = new
WordDictionary();wordDictionary.addWord("bad");wordDictionary.addWord("dad");wordDictionary.addWord("mad");wordDictionary.search("pad");
// return FalsewordDictionary.search("bad"); // return
TruewordDictionary.search(".ad"); // return TruewordDictionary.search("b.."); //
return True

 **Constraints:**

  * `1 <= word.length <= 25`
  * `word` in `addWord` consists of lowercase English letters.
  * `word` in `search` consist of `'.'` or lowercase English letters.
  * There will be at most `2` dots in `word` for `search` queries.
  * At most `104` calls will be made to `addWord` and `search`.


*/

#include "leetcode.hpp"

struct Node {
  unordered_map<char, Node *> children;
  char letter;
  bool is_leaf;
  Node(char c) : letter(c), is_leaf(false) {}
};

class WordDictionary {
private:
  Node *root;

public:
  WordDictionary() : root(new Node(' ')) {}

  void addWord(string word) {
    Node *n = root;
    for (const auto &c : word) {
      if (n->children.find(c) == n->children.end()) {
        n->children[c] = new Node(c);
      }
      n = n->children[c];
    }
    n->is_leaf = true;
  }

  bool search(string word) { return search_from_node(word, this->root); }

  // recursive helper function
  bool search_from_node(string w, Node *n) {
    for (int i = 0; i < w.size(); ++i) {
      char c = w[i];
      if (c == '.') {
        for (const auto &it : n->children) {
          if (search_from_node(w.substr(i + 1, w.size() - i), it.second))
            return true;
        }
        // none of the children lead to node
        return false;
      } else if (n->children.find(c) == n->children.end()) {
        return false;
      } else {
        n = n->children[c];
      }
    }
    return n->is_leaf;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

TEST_CASE("design-add-and-search-words-data-structure", "[0211]") {
  auto wordDictionary = new WordDictionary();
  wordDictionary->addWord("bad");
  wordDictionary->addWord("dad");
  wordDictionary->addWord("mad");
  CHECK_FALSE(wordDictionary->search("pad"));
  CHECK(wordDictionary->search("bad"));
  CHECK_FALSE(wordDictionary->search("bcd"));
  CHECK_FALSE(wordDictionary->search("b"));
  CHECK(wordDictionary->search(".ad"));
  CHECK(wordDictionary->search("b.."));
}
