/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n), space O(n)
    int numDecodings(string s) {
        int l_len = s.size();
        
        if (l_len == 0) return 0;

        vector<int> vec_dp(l_len + 1);
        vec_dp[l_len] = 1;
        vec_dp[l_len - 1] = (s[l_len - 1] == '0') ? 0 : 1;

        for (int idx = l_len - 2; idx >= 0; idx--) {
            if (s[idx] != '0') {
                vec_dp[idx] = vec_dp[idx + 1];
                if ((s[idx] == '1') || ((s[idx] == '2') && (s[idx + 1] <= '6')))
                    vec_dp[idx] += vec_dp[idx + 2];
            }
            else
                vec_dp[idx] = 0;
        }
        return vec_dp[0];
    }
};
// @lc code=end

