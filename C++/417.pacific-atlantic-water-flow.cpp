/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
// dfs, time O(m * n), space O(m * n)
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int idx_r;
        int idx_c;
        ml_len_r = heights.size();
        ml_len_c = heights[0].size();
        vector<vector<bool>> vec2d_pacific(ml_len_r, vector<bool>(ml_len_c, false));
        vector<vector<bool>> vec2d_atlantic(ml_len_r, vector<bool>(ml_len_c, false));
        vector<vector<int>> vec2d_rst;

        for (idx_r = 0; idx_r < ml_len_r; idx_r++) {
            dfs(heights, vec2d_pacific, idx_r, 0);
            dfs(heights, vec2d_atlantic, idx_r, ml_len_c - 1);
        }

        for (idx_c = 0; idx_c < ml_len_c; idx_c++) {
            dfs(heights, vec2d_pacific, 0, idx_c);
            dfs(heights, vec2d_atlantic, ml_len_r - 1, idx_c);
        }

        for (idx_r = 0; idx_r < ml_len_r; idx_r++)
            for (idx_c = 0; idx_c < ml_len_c; idx_c++)
                if (vec2d_pacific[idx_r][idx_c] && vec2d_atlantic[idx_r][idx_c])
                    vec2d_rst.push_back({idx_r, idx_c});
        
        return vec2d_rst;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vec2d_ocean, int idx_r, int idx_c) {
        vec2d_ocean[idx_r][idx_c] = true;
        int l_r, l_c;

        for (int idx_dir = 0; idx_dir < 4; idx_dir++) {
            l_r = idx_r + mvec_dir[idx_dir][0];
            l_c = idx_c + mvec_dir[idx_dir][1];

            if ((l_r < 0) || (l_r >= ml_len_r)
                || (l_c < 0) || (l_c >= ml_len_c)
                || heights[l_r][l_c] < heights[idx_r][idx_c]
                || vec2d_ocean[l_r][l_c])
                continue;
            
            dfs(heights, vec2d_ocean, l_r, l_c);
        }
    }

    int ml_len_r;
    int ml_len_c;
    vector<vector<int>> mvec_dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
// @lc code=end

