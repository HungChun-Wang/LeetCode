/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // bit operation, time O(n), space O(n)
    vector<int> countBits(int n) {
        vector<int> vec_dp(n + 1);

        for (int l_val = 0; l_val <= n; l_val++)
            vec_dp[l_val] = vec_dp[l_val >> 1] + (l_val & 1);
        
        return vec_dp;
    }
};
// @lc code=end

