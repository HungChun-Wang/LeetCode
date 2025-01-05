/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n), space O(n)
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> vec_dp(nums.size());

        vec_dp[0] = nums[0];
        vec_dp[1] = max(nums[0], nums[1]);

        for (int idx = 2; idx < nums.size(); idx++)
            vec_dp[idx] = max(vec_dp[idx - 1], vec_dp[idx - 2] + nums[idx]);
        
        return vec_dp.back();
    }
};
// @lc code=end

