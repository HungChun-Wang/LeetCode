/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // backtracing, time O(2^n), space O(2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        int l_size;
        vector<int> vec_back;
        vector<vector<int>> vec2d_rst = {{}};

        for (auto num : nums) {
            l_size = vec2d_rst.size();
            for (int l_idx = 0; l_idx < l_size; l_idx++) {
                vec_back = vec2d_rst[l_idx];
                vec_back.push_back(num);
                vec2d_rst.push_back(vec_back);
            }
        }
        return vec2d_rst;
    }
};
// @lc code=end

