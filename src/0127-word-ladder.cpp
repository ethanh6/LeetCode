/*
A **transformation sequence** from word `beginWord` to word `endWord` using a
dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... ->
sk` such that:

  * Every adjacent pair of words differs by a single letter.
  * Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does
not need to be in `wordList`.
  * `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`,
return _the **number of words** in the **shortest transformation sequence**
from_ `beginWord` _to_ `endWord` _, or_`0` _if no such sequence exists._

 **Example 1:**



     **Input:** beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"] **Output:** 5 **Explanation:** One
shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog",
which is 5 words long.

 **Example 2:**



     **Input:** beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log"] **Output:** 0 **Explanation:** The endWord "cog"
is not in wordList, therefore there is no valid transformation sequence.

 **Constraints:**

  * `1 <= beginWord.length <= 10`
  * `endWord.length == beginWord.length`
  * `1 <= wordList.length <= 5000`
  * `wordList[i].length == beginWord.length`
  * `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English
letters.
  * `beginWord != endWord`
  * All the words in `wordList` are **unique**.


*/

#include "leetcode.hpp"

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    // helper functions
    std::function<bool(const vector<string> &, string &)> containWord =
        [&](const vector<string> &word_list, string &w) {
          return std::count(word_list.cbegin(), word_list.cend(), w) != 0;
        };

    std::function<bool(string, string)> isAdjacent = [&](string w1, string w2) {
      if (w1.size() != w2.size())
        return false;
      for (int i = 0; i < w1.size(); ++i) {
        char c1 = w1[i], c2 = w2[i];
        w1[i] = '.';
        w2[i] = '.';
        if (w1 == w2)
          return true;
        w1[i] = c1;
        w2[i] = c2;
      }
      return false;
    };

    std::function<vector<string>(const vector<string> &, string &)>
        findAdjacentWords = [&](const vector<string> &word_list, string &w) {
          vector<string> res;
          for (const auto &word : word_list) {
            if (word != w && isAdjacent(word, w))
              res.push_back(word);
          }
          return res;
        };

    // sanity check
    if (!containWord(wordList, endWord))
      return 0;

    // perform BFS
    queue<pair<string, int>> q;
    q.push(pair<string, int>{beginWord, 1});
    unordered_set<string> visited;

    while (!q.empty()) {
      pair<string, int> x = q.front();
      q.pop();
      string word = x.first;
      int step = x.second;

      if (visited.count(word) != 0) {
        continue;
      } else {
        visited.insert(word);
      }

      vector<string> adj_words = findAdjacentWords(wordList, word);

      if (containWord(adj_words, endWord)) {
        return step + 1;
      }

      for (const auto &adj_w : adj_words) {
        q.push(pair<string, int>{adj_w, step + 1});
      }
    }

    return 0;
  }
};

TEST_CASE("word-ladder", "[0127]") {
  Solution sol;
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  int output = 5;
  CHECK(sol.ladderLength(beginWord, endWord, wordList) == output);
}

TEST_CASE("word-ladder - 1", "[0127]") {
  Solution sol;
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
  int output = 0;
  CHECK(sol.ladderLength(beginWord, endWord, wordList) == output);
}
