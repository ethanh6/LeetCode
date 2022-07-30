#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        
        // construct need
        for (char c: t) {
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

        while (right < s.size()) {
            
            // right slide the window
            char c = s[right];
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
            while (valid == need.size()) {
                
                // a solution exists
                // udpate if it's the best solution
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                
                // further optimize the solution
                
                // move the left ptr
                char d = s[left];
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
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


int main() {

  Solution sol;
  string s = "abcddd";
  string t = "bd";
  cout << "(s, t) = (" << s << ", " << t << ")" << endl;

  string ans = sol.minWindow(s, t);
  cout << "ANS = >>>" << ans << "<<<" << endl;

  return 0;

}
