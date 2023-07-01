/*
Given an array of strings `words` and an integer `k`, return _the_`k` _most
frequent strings_.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort
the words with the same frequency by their **lexicographical order**.

 **Example 1:**



     **Input:** words = ["i","love","leetcode","i","love","coding"], k = 2
**Output:** ["i","love"] **Explanation:** "i" and "love" are the two most
frequent words.Note that "i" comes before "love" due to a lower alphabetical
order.

 **Example 2:**



     **Input:** words =
["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
**Output:** ["the","is","sunny","day"] **Explanation:** "the", "is", "sunny" and
"day" are the four most frequent words, with the number of occurrence being 4,
3, 2 and 1 respectively.

 **Constraints:**

  * `1 <= words.length <= 500`
  * `1 <= words[i].length <= 10`
  * `words[i]` consists of lowercase English letters.
  * `k` is in the range `[1, The number of **unique** words[i]]`

 **Follow-up:** Could you solve it in `O(n log(k))` time and `O(n)` extra
space?


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> counter;
    for (const string &w : words) {
      counter[w]++;
    }

    // max heap
    // this keeps only top k frequent elements
    priority_queue<pair<int, string>> pq;
    for (auto it = counter.begin(); it != counter.end(); ++it) {
      pq.push(make_pair(-it->second, it->first));

      // pop min elements when reach size k
      if (pq.size() > k)
        pq.pop();
    }

    // convert priority to vector
    vector<pair<int, string>> candidates;
    for (;!pq.empty(); pq.pop()) {
      candidates.push_back(pq.top());
    }

    // sort by frequency and alphabetical order
    sort(candidates.begin(), candidates.end());

    // get the result
    vector<string> res;
    for (const auto &c: candidates) {
      res.push_back(c.second);
    }

    return res;
  }
};

TEST_CASE("top-k-frequent-words", "[0692]") {
  Solution sol;
  vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> output{"i", "love"};
  int k = 2;
  CHECK(sol.topKFrequent(words, k) == output);
}

TEST_CASE("top-k-frequent-words - 1", "[0692]") {
  Solution sol;
  vector<string> words{"the", "day", "is",    "sunny", "the",
                       "the", "the", "sunny", "is",    "is"};
  vector<string> output{"the", "is", "sunny", "day"};
  int k = 4;
  CHECK(sol.topKFrequent(words, k) == output);
}
