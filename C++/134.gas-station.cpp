/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // gready, time O(n), space O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l_gas_total = 0;
        int l_cost_total = 0;
        int l_gas_curr = 0;
        int idx_start = 0;

        for (int idx = 0; idx < gas.size(); idx++) {
            l_gas_total += gas[idx];
            l_cost_total += cost[idx];
            l_gas_curr += gas[idx] - cost[idx];

            if (l_gas_curr < 0) {
                l_gas_curr = 0;
                idx_start = idx + 1;
            }
        }
        return l_cost_total > l_gas_total ? -1 : idx_start;
    }
};
// @lc code=end

