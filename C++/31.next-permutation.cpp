/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int i_st = nums.size() - 2;

        while (i_st >= 0 && (nums[i_st] >= nums[i_st + 1]))
            i_st--;

        if (i_st >= 0) {
            for (i = nums.size() - 1; i > i_st; i--) {
                if (nums[i_st] < nums[i]) {
                    swap(nums[i_st], nums[i]);
                    break;
                }
            }
        }

        reverse(nums.begin() + i_st + 1, nums.end());
    }
};
// @lc code=end

