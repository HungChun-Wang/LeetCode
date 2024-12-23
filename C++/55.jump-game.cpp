/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // gready, time O(n), space O(1)
    bool canJump(vector<int>& nums) {
        int l_pos_max = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (idx > l_pos_max)
                return false;
            l_pos_max = max(l_pos_max, idx + nums[idx]);
            if (l_pos_max >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

