/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // iteration, time O(logn), space O(1)
    int search(vector<int>& nums, int target) {
        int l_mid;
        int l_left = 0;
        int l_right = nums.size() - 1;

        while (l_left <= l_right) {
            l_mid = (l_right + l_left) >> 1;
            if (nums[l_mid] == target)
                return l_mid;
            else if (nums[l_mid] > target)
                l_right = l_mid - 1;
            else
                l_left = l_mid + 1;
        }
        return -1;
    }

    // // recursion, time(logn), space O(logn)
    // int search_recur(vector<int>& nums, int target, int l_left, int l_right) {
    //     if (l_left > l_right)
    //         return -1;

    //     int l_mid = (l_right + l_left) >> 1;

    //     if (nums[l_mid] == target)
    //         return l_mid;
    //     else if (nums[l_mid] < target)
    //         return search_recur(nums, target, l_mid + 1, l_right);
    //     else
    //         return search_recur(nums, target, l_left, l_mid - 1);
    // }

    // int search(vector<int>& nums, int target) {
    //     int l_left = 0;
    //     int l_right = nums.size() - 1;
    //     return search_recur(nums, target, l_left, l_right);
    // }
};
// @lc code=end

