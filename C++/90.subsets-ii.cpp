/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // backtracking, time O(2^n), space O(2^n)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vec2d_rst = {{}};
        vector<int> vec_set;
        unordered_map<int, int> umap; // <num, last idx>
        int l_size_rst;
        int l_idx;
        int l_idx_start;

        sort(nums.begin(), nums.end());

        for (auto num : nums) {
            l_idx_start = umap[num];
            l_size_rst = vec2d_rst.size();

            for (l_idx = l_idx_start; l_idx < l_size_rst; l_idx++) {
               vec_set = vec2d_rst[l_idx];
               vec_set.push_back(num);
               vec2d_rst.push_back(vec_set); 
            }

            umap[num] = l_size_rst;
        }
        return vec2d_rst;
    }
};
// @lc code=end

