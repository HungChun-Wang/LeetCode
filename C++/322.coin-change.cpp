/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp, time O(m * l), space O(m), m = amount, l = coin type
    int coinChange(vector<int>& coins, int amount) {
        vector<int> vec_dp(amount + 1, amount + 1);

        vec_dp[0] = 0;

        for (int l_val = 1; l_val <= amount; l_val++)
            for (auto coin : coins)
                if (coin <= l_val)
                    vec_dp[l_val] = min(vec_dp[l_val], vec_dp[l_val - coin] + 1);

        return (vec_dp[amount] > amount) ? -1 : vec_dp[amount];
    }
};
// @lc code=end

