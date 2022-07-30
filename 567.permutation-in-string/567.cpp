#include <iostream>
#include <unordered_map>
#include <string>
#include "assert.h"


using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        
        // construct need
        for (char c: s1) {
            need[c] ++;
        }

        // for (auto it = need.begin(); it != need.end(); ++it ) {
        //   cout << "{" << it->first << ": " << it->second << "}" << endl;
        // }
        
        // initialize window pointers 
        int left = 0, right = 0;
        
        // the number of chars in window that is in t (aka need)
        // serves a flag
        int valid = 0;
        
        // record of the best solution
        int start = 0;
        int len = INT_MAX;
        
        while (right < s2.size()) {
            
            // right slide the window
            char c = s2[right];
            right++;

            // ************************* 
            // *** update the window *** 
            // ************************* 
            if (need.count(c)){
                // if the new char is in t
                // update window
                window[c]++;
                
                if (window[c] == need[c]){
                    // increment valid
                    // if number of the char satisfies need
                    valid++;
                }
            }

            // **************************************
            // *** check if need to move left ptr *** 
            // **************************************
            while (right - left >= need.size()) {
              if (valid == need.size()) {
                return true;
              }

              // move the left ptr
              char d = s2[left];
              left++;

                // ************************* 
                // *** update the window *** 
                // ************************* 
                if (need.count(d)) {
                    // if the char is in need 
                    // and if it invalidate the solution
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};

int main() {

  Solution sol;
  string s1, s2;

  s1 = "ab";
  s2 = "eidbaooo";
  cout << "Input: (s, t) = (" << s1 << ", " << s2 << ")" << endl;

  bool ans = sol.checkInclusion(s1, s2);
  assert(ans == true);

  s1 = "ab";
  s2 = "eidboaoo";
  cout << "Input: (s, t) = (" << s1 << ", " << s2 << ")" << endl;

  ans = sol.checkInclusion(s1, s2);
  assert(ans == false);

  return 0;

}
