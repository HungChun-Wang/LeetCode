/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n^2), space O(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int idx_l, idx_r;
        int l_sum;
        vector<vector<int>> vec2d_rst;
        
        sort(nums.begin(), nums.end());

        for (int idx = 0; idx < nums.size() - 2; idx++) {
            if (idx > 0 && nums[idx] == nums[idx - 1])
                continue;
            
            idx_l = idx + 1;
            idx_r = nums.size() - 1;
            while (idx_l < idx_r) {
                l_sum = nums[idx] + nums[idx_l] + nums[idx_r];

                if (l_sum == 0) {
                    vec2d_rst.push_back(vector<int>{nums[idx], nums[idx_l], nums[idx_r]});
                    while (idx_l < idx_r && nums[idx_l] == nums[idx_l + 1])
                        idx_l++;
                    while (idx_l < idx_r && nums[idx_r] == nums[idx_r - 1])
                        idx_r--;
                    idx_l++;
                    idx_r--;
                }
                else if (l_sum < 0)
                    idx_l++;
                else
                    idx_r--;
            }
        }
        return vec2d_rst;
    }
};
// @lc code=end

