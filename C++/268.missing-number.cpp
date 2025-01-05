/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // // math, time O(n), space O(1)
    // int missingNumber(vector<int>& nums) {
    //     // trapezoid area (1 + n) * n / 2
    //     int l_rst = ((1 + nums.size()) * nums.size()) >> 1;

    //     for (auto num : nums)
    //         l_rst -= num;
        
    //     return l_rst;
    // }

    // bitwise_XOR, time O(n), space O(1)
    int missingNumber(vector<int>& nums) {
        int l_rst = 0;

        for (int idx = 0; idx < nums.size(); idx++) {
            l_rst ^= idx;
            l_rst ^= nums[idx];
        }
        l_rst ^= nums.size();

        return l_rst;
    }
};
// @lc code=end

