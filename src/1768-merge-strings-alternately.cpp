/*
You are given two strings `word1` and `word2`. Merge the strings by adding
letters in alternating order, starting with `word1`. If a string is longer
than the other, append the additional letters onto the end of the merged
string.

Return _the merged string._

**Example 1:**

    
    
    **Input:** word1 = "abc", word2 = "pqr"**Output:** "apbqcr"word1:  a   b   cword2:    p   q   rmerged: a p b q c r

**Example 2:**

    
    
    **Input:** word1 = "ab", word2 = "pqrs"**Output:** "apbqrs"word1:  a   b word2:    p   q   r   smerged: a p b q   r   s

**Example 3:**

    
    
    **Input:** word1 = "abcd", word2 = "pq"**Output:** "apbqcd"word1:  a   b   c   dword2:    p   q merged: a p b q c   d

**Constraints:**

  * `1 <= word1.length, word2.length <= 100`
  * `word1` and `word2` consist of lowercase English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string result("");
        int i = 0;
        int minlen = min(w1.size(), w2.size());

        for(; i < minlen; ++i) {
            result += w1[i];
            result += w2[i];
        }

        while (i < w1.size()) {
            result += w1[i++];
        }

        while (i < w2.size()) {
            result += w2[i++];
        }

        return result;
    }
};

TEST_CASE("merge-strings-alternately", "[1768]"){
    Solution sol;
    string word1 = "abcdef", word2 = "pqr";
    CHECK(sol.mergeAlternately(word1, word2) == string("apbqcrdef"));
}
