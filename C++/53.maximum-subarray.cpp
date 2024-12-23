/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    // gready, time O(n), space O(1)
    int maxSubArray(vector<int>& nums) {
        int l_sum;
        int l_sum_max = INT_MIN;
        
        for (auto num : nums) {
            l_sum += num;
            if (l_sum > l_sum_max)
                l_sum_max = l_sum;
            if (l_sum < 0)
                l_sum = 0;
        }
        return l_sum_max;
    }
};
// @lc code=end

