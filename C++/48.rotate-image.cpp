/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int idx_r;
        int idx_c;
        int l_len = matrix.size();
        int l_len_half = l_len >> 1;

        // transpose
        for (idx_r = 0; idx_r < l_len; idx_r++)
            for (idx_c = idx_r + 1; idx_c < l_len; idx_c++)
                swap(matrix[idx_r][idx_c], matrix[idx_c][idx_r]);

        // literal mirror
        for (idx_r = 0; idx_r < l_len; idx_r++)
            for (idx_c = 0; idx_c < l_len_half; idx_c++)
                swap(matrix[idx_r][idx_c], matrix[idx_r][l_len - idx_c - 1]);
    }
};
// @lc code=end

