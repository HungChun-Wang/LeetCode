/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // time O(m * n), space O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        bool b_1st_row_zero = false;
        bool b_1st_col_zero = false;
        int idx_r, l_len_r = matrix.size();
        int idx_c, l_len_c = matrix[0].size();

        for (idx_r = 0; idx_r < l_len_r; idx_r++) 
            if (matrix[idx_r][0] == 0) {
                b_1st_col_zero = true;
                break;
            }
        
        for (idx_c = 0; idx_c < l_len_c; idx_c++)
            if (matrix[0][idx_c] == 0) {
                b_1st_row_zero = true;
                break;
            }
        
        for (idx_r = 1; idx_r < l_len_r; idx_r++)
            for (idx_c = 1; idx_c < l_len_c; idx_c++)
                if (matrix[idx_r][idx_c] == 0) {
                    matrix[idx_r][0] = 0;
                    matrix[0][idx_c] = 0;
                }

        for (idx_r = 1; idx_r < l_len_r; idx_r++) {
            if (matrix[idx_r][0] == 0)
                for (idx_c = 1; idx_c < l_len_c; idx_c++)
                    matrix[idx_r][idx_c] = 0;
            else if (b_1st_col_zero)
                matrix[idx_r][0] = 0;
        }
        
        for (idx_c = 1; idx_c < l_len_c; idx_c++) {
            if (matrix[0][idx_c] == 0)
                for (idx_r = 1; idx_r < l_len_r; idx_r++)
                    matrix[idx_r][idx_c] = 0;
            else if (b_1st_row_zero)
                matrix[0][idx_c] = 0;
        }

        if (b_1st_row_zero || b_1st_col_zero)
            matrix[0][0] = 0;
    }
};
// @lc code=end

