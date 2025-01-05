/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n), space O(n)
    int rob(vector<int>& nums) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        return max(rob_linear(nums, 0, nums.size() - 2), rob_linear(nums, 1, nums.size() - 1));
    }

    int rob_linear(vector<int>& nums, int idx_start, int idx_end) {
        int l_len = idx_end - idx_start + 1;
        vector<int> vec_dp(l_len);

        vec_dp[0] = nums[idx_start];
        vec_dp[1] = max(nums[idx_start], nums[idx_start + 1]);

        for (int idx = 2; idx < l_len; idx++)
            vec_dp[idx] = max(vec_dp[idx - 1], vec_dp[idx - 2] + nums[idx_start + idx]);
        
        return vec_dp.back();
    }
};
// @lc code=end

