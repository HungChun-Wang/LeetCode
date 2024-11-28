/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // binary search, time O(logn), space O(1)
    int findMin(vector<int>& nums) {
        int l_mid;
        int l_left = 0;
        int l_right = nums.size() - 1;

        while (l_left < l_right) {
            l_mid = (l_right + l_left) >> 1;

            if (nums[l_mid] >= nums[l_right])
                // minimum must exist between middle and right
                l_left = l_mid + 1;
            else
                // minimum must exist between middle and left
                l_right = l_mid;
        }
        return nums[l_left];
    }
};
// @lc code=end

