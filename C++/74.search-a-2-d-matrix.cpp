/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // treat as 1D, time O(log(m*n)), space O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l_row, l_col;
        int l_num_row = matrix.size();
        int l_num_col = matrix[0].size();
        int l_left = 0;
        int l_right = l_num_row * l_num_col - 1;
        int l_mid;
        int l_val;

        while (l_left <= l_right) {
            l_mid = (l_left + l_right) >> 1;
            l_row = l_mid / l_num_col;
            l_col = l_mid % l_num_col;
            l_val = matrix[l_row][l_col];
            
            if (l_val == target)
                return true;
            else if (l_val < target)
                l_left = l_mid + 1;
            else
                l_right = l_mid - 1;
        }
        return false;
    }
};
// @lc code=end

