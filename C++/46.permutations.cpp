/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(n!), space [stack depth O(n), result O(n!)]
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec2d_rst;
        backtracking(vec2d_rst, nums, 0);
        return vec2d_rst;
    }  
private:
    void backtracking(vector<vector<int>> &vec2d_rst, vector<int> &vec_nums, int l_idx_start) {
        if (l_idx_start == vec_nums.size()) {
            vec2d_rst.push_back(vec_nums);
            return;
        }

        for (int l_idx = l_idx_start; l_idx < vec_nums.size(); l_idx++) {
            swap(vec_nums[l_idx_start], vec_nums[l_idx]);
            backtracking(vec2d_rst, vec_nums, l_idx_start + 1);
            swap(vec_nums[l_idx_start], vec_nums[l_idx]);
        }
    }
};
// @lc code=end

