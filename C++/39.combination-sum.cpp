/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(2^n), space O(n?)
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec2d_rst;
        vector<int> vec_candi_sum;
        backtrack(candidates, vec_candi_sum, vec2d_rst, target, 0);
        return vec2d_rst;
    }
private:
    void backtrack(vector<int> &vec_candi, vector<int> &vec_candi_sum, vector<vector<int>> &vec2d_rst, int l_target, int l_idx) {
        if (l_target == 0)
            vec2d_rst.push_back(vec_candi_sum);

        if (l_target <= 0)
            return;

        for (int i = l_idx; i < vec_candi.size(); i++) {
            vec_candi_sum.push_back(vec_candi[i]);
            backtrack(vec_candi, vec_candi_sum, vec2d_rst, l_target - vec_candi[i], i);
            vec_candi_sum.pop_back();
        }
    }
};
// @lc code=end

