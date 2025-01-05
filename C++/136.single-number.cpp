/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // bit operation, time O(n), space O(1)
    int singleNumber(vector<int>& nums) {
        int l_res = 0;

        for (auto num : nums)
            l_res ^= num;
        
        return l_res;
    }
};
// @lc code=end

