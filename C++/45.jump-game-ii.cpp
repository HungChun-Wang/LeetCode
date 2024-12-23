/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // gready, time O(n), space O(1)
    int jump(vector<int>& nums) {
        int l_dist_round = 0;
        int l_dist_max = 0;
        int l_step = 0;

        for (int idx = 0; idx < nums.size() - 1; idx++) {
            l_dist_max = max(l_dist_max, idx + nums[idx]);
            if (idx == l_dist_round) {
                l_step++;
                l_dist_round = l_dist_max;
            }
        }
        return l_step;
    }
};
// @lc code=end

