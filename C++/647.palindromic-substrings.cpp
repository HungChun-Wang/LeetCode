/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n^2), space O(1)
    int countSubstrings(string s) {
        int l_len = s.size();
        int idx_c;
        int idx_l;
        int idx_r;
        int l_cnt_palindrom = 0;

        for (idx_c = 0; idx_c < l_len; idx_c++) {
            idx_l = idx_c;
            idx_r = idx_c;

            while ((idx_l >= 0) && (idx_r < l_len) && (s[idx_l] == s[idx_r])) {
                idx_l--;
                idx_r++;
                l_cnt_palindrom++;
            }
        }

        for (idx_c = 0; idx_c < l_len; idx_c++) {
            idx_l = idx_c;
            idx_r = idx_c + 1;

            while ((idx_l >= 0) && (idx_r < l_len) && (s[idx_l] == s[idx_r])) {
                idx_l--;
                idx_r++;
                l_cnt_palindrom++;
            }
        }
        return l_cnt_palindrom;
    }
};
// @lc code=end

