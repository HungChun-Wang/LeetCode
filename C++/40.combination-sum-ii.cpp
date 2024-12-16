/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(2^n), space O(n?)
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vec2d_rst;
        vector<int> vec_candi_sum;
        backtracking(vec2d_rst, vec_candi_sum, candidates, target, 0);
        return vec2d_rst;
    }
private:
    void backtracking(vector<vector<int>>& vec2d_rst, vector<int>& vec_candi_sum, vector<int> &vec_candi, int l_target, int l_idx_start) {
        if (l_target == 0)
            vec2d_rst.push_back(vec_candi_sum);

        if (l_target <= 0)
            return;

        for (int l_idx = l_idx_start; l_idx < vec_candi.size(); l_idx++) {
            if ((l_idx > l_idx_start) && (vec_candi[l_idx] == vec_candi[l_idx - 1]))
                continue;
            vec_candi_sum.push_back(vec_candi[l_idx]);
            backtracking(vec2d_rst, vec_candi_sum, vec_candi, l_target - vec_candi[l_idx], l_idx + 1);
            vec_candi_sum.pop_back();
        }
    }
};
// @lc code=end

