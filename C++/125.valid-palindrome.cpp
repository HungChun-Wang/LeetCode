/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n), space O(1)
    inline bool is_alphanumeric(const char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isPalindrome(string s) {
        int idx_l = 0;
        int idx_r = s.length();

        while(idx_l < idx_r) {
            if (!is_alphanumeric(s[idx_l])) {
                idx_l++;
                continue;
            }
            if (!is_alphanumeric(s[idx_r])) {
                idx_r--;
                continue;
            }

            if (tolower(s[idx_l]) != tolower(s[idx_r]))
                return false;
            
            idx_l++;
            idx_r--;
        }
        return true;
    }
};
// @lc code=end

