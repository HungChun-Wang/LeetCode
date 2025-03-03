/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // dfs, time O(m * n), space O(m * n)
    int numIslands(vector<vector<char>>& grid) {
        int l_num_islands = 0;
        int idx_r;
        int idx_c;
        ml_len_r = grid.size();
        ml_len_c = grid[0].size();

        for (idx_r = 0; idx_r < ml_len_r; idx_r++) {
            for (idx_c = 0; idx_c < ml_len_c; idx_c++) {
                if (grid[idx_r][idx_c] == '1') {
                    dfs(grid, idx_r, idx_c);
                    l_num_islands++;
                }
            }
        }
        return l_num_islands;
    }
private:
    void dfs (vector<vector<char>> &grid, int idx_r, int idx_c) {
        if ((idx_r < 0) || (idx_r >= ml_len_r)
            || (idx_c < 0) || (idx_c >= ml_len_c)
            || (grid[idx_r][idx_c] != '1'))
            return;
        
        grid[idx_r][idx_c] = 0;

        dfs(grid, idx_r + 1, idx_c);
        dfs(grid, idx_r - 1, idx_c);
        dfs(grid, idx_r , idx_c + 1);
        dfs(grid, idx_r , idx_c - 1);
    }

    int ml_len_r;
    int ml_len_c;
};
// @lc code=end

