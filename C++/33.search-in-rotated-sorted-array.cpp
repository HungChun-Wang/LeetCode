/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // binary search, time O(logn), space O(1)
    int search(vector<int>& nums, int target) {
        int l_mid;
        int l_left = 0;
        int l_right = nums.size() - 1;

        while (l_left <= l_right) {
            l_mid = (l_right + l_left) >> 1;

            if (nums[l_mid] == target)
                return l_mid;
            
            if (nums[l_left] <= nums[l_mid]) {
                if (nums[l_left] <= target && target < nums[l_mid])
                    l_right = l_mid - 1;
                else
                    l_left = l_mid + 1;
            }
            else
                if (nums[l_mid] < target && target <= nums[l_right])
                    l_left = l_mid + 1;
                else
                    l_right = l_mid - 1;
        }
        return -1;
    }
};
// @lc code=end

