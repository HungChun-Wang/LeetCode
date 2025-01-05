/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n^2), space O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec_dp(nums.size(), 1);

        for (int idx_r = 1; idx_r < nums.size(); idx_r++)
            for (int idx_l = 0; idx_l < idx_r; idx_l++)
                if (nums[idx_l] < nums[idx_r])
                    vec_dp[idx_r] = max(1 + vec_dp[idx_l], vec_dp[idx_r]);

        return *max_element(vec_dp.begin(), vec_dp.end());
    }
};
// @lc code=end

