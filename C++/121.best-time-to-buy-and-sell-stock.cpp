/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // time O(n), space O(1)
    int maxProfit(vector<int>& prices) {
        int l_min_cost = __INT_MAX__;
        int l_max_profit = 0;

        for (auto l_price : prices) {
            if (l_price < l_min_cost)
                l_min_cost = l_price;
            else if (l_max_profit < l_price - l_min_cost)
                l_max_profit = l_price - l_min_cost;
        }
        return l_max_profit;
    }
};
// @lc code=end

