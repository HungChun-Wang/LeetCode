/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    // dp (optimal space), time O(n), space O(1)
    int maxProduct(vector<int>& nums) {
        int l_min = 1;
        int l_max = 1;
        int l_rst = INT_MIN;
        int l_tmp_max;
        int l_tmp_min;

        for (auto num : nums) {
            l_tmp_max = l_max * num;
            l_tmp_min = l_min * num;
            l_max = max(max(l_tmp_max, l_tmp_min), num);
            l_min = min(min(l_tmp_max, l_tmp_min), num);
            l_rst = max(l_max, l_rst);
        }
        return l_rst;
    }
};
// @lc code=end

