/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start

// dps, time O(m * n), space O(m * n)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ml_len_r = grid.size();
        ml_len_c = grid[0].size();
        int idx_r, idx_c;
        int l_area_max = 0;

        for (idx_r = 0; idx_r < ml_len_r; idx_r++)
            for (idx_c = 0; idx_c < ml_len_c; idx_c++)
                if (grid[idx_r][idx_c] == 1)
                    l_area_max = max(l_area_max, dfs(grid, idx_r, idx_c));
        return l_area_max;
    }

private:
    int dfs(vector<vector<int>>& grid, int idx_r, int idx_c) {
        if ((idx_r < 0) || (idx_r >= ml_len_r)
            || (idx_c < 0) || (idx_c >= ml_len_c)
            || grid[idx_r][idx_c] != 1)
            return 0;

        int l_area = 1;

        grid[idx_r][idx_c] = 0;

        l_area += dfs(grid, idx_r + 1, idx_c);
        l_area += dfs(grid, idx_r - 1, idx_c);
        l_area += dfs(grid, idx_r, idx_c + 1);
        l_area += dfs(grid, idx_r, idx_c - 1);

        return l_area;
    }

    int ml_len_r;
    int ml_len_c;
};
// @lc code=end

