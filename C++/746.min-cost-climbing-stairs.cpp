/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(n), space O(n)
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> vec_dp(cost.size() + 1);

        vec_dp[0] = 0;
        vec_dp[1] = 0;

        for (int idx = 2; idx <= cost.size(); idx++)
            vec_dp[idx] = min(vec_dp[idx - 2] + cost[idx - 2], vec_dp[idx - 1] + cost[idx - 1]);

        return vec_dp[cost.size()];
    }
};
// @lc code=end

