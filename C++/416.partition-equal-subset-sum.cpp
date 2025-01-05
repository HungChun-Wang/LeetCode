/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n * t), space O(t)
    bool canPartition(vector<int>& nums) {
        int l_sum = 0;
        
        for (auto num : nums)
            l_sum += num;

        if (l_sum & 1)
            return false;

        int l_target = l_sum >> 1;

        vector<bool> vec_dp(l_target + 1, false);

        vec_dp[0] = true;

        for (auto num : nums)
            for (int l_val = l_target; l_val >= num; l_val--)
                vec_dp[l_val] = vec_dp[l_val] || vec_dp[l_val - num];

        return vec_dp[l_target];
    }
};
// @lc code=end

