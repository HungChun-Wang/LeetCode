/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n^2), space O(1)
    string longestPalindrome(string s) {
        int l_size = s.size();
        int l_left;
        int l_right;
        int l_longest_left = 0;
        int l_longest_len = 0;

        // odd length
        for (int idx = 0; idx < l_size; idx++) {
            l_left = idx;
            l_right = idx;
            while (l_left >= 0 && l_right < l_size && (s[l_left] == s[l_right])) {
                if (l_right - l_left + 1 > l_longest_len) {
                    l_longest_len = l_right - l_left + 1;
                    l_longest_left = l_left;
                }
                l_left--;
                l_right++;
            }
        }

        // even length
        for (int idx = 0; idx < l_size; idx++) {
            l_left = idx;
            l_right = idx + 1;
            while (l_left >= 0 && l_right < l_size && (s[l_left] == s[l_right])) {
                if (l_right - l_left + 1 > l_longest_len) {
                    l_longest_len = l_right - l_left + 1;
                    l_longest_left = l_left;
                }
                l_left--;
                l_right++;
            }
        }

        return s.substr(l_longest_left, l_longest_len);
    }

    // // brute force, time O(n^3), space O(1)
    // string longestPalindrome(string s) {
    //     int idx_l, idx_l_st;
    //     int idx_r, idx_r_st;
    //     int idx_left_longest;
    //     int l_len_longest = 0;
    //     int l_len = s.size();

    //     for (idx_l_st = 0; idx_l_st < l_len; idx_l_st++) {
    //         for (idx_r_st = idx_l_st; idx_r_st < l_len; idx_r_st++) {
    //             idx_l = idx_l_st;
    //             idx_r = idx_r_st;

    //             while ((idx_l < idx_r) && (s[idx_l] == s[idx_r])) {
    //                 idx_l++;
    //                 idx_r--;
    //             }
    //             if ((idx_l >= idx_r) && (l_len_longest < idx_r_st - idx_l_st + 1)) {
    //                 l_len_longest = idx_r_st - idx_l_st + 1;
    //                 idx_left_longest = idx_l_st;
    //             }
    //         }
    //     }
    //     return s.substr(idx_left_longest, l_len_longest);
    // }

    // // dp, time O(n^2), space O(n^2)
    // string longestPalindrome(string s) {
    //     int l_len = s.size();
    //     int idx_l;
    //     int idx_r;
    //     int idx_l_longest;
    //     int l_len_longest = 0;
    //     vector<vector<int>> dp(l_len, vector<int>(l_len, 0));
        
    //     for (idx_l = l_len - 1; idx_l >= 0; idx_l--) {
    //         for (idx_r = idx_l; idx_r < l_len; idx_r++) {
    //             if ((s[idx_l] == s[idx_r]) && ((idx_r - idx_l <= 2) || dp[idx_l + 1][idx_r - 1])) {
    //                 dp[idx_l][idx_r] = true;

    //                 if (l_len_longest < idx_r - idx_l + 1) {
    //                     l_len_longest = idx_r - idx_l + 1;
    //                     idx_l_longest = idx_l;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(idx_l_longest, l_len_longest);
    // }
};
// @lc code=end

