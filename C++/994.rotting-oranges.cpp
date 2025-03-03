/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    // time O(m * n), space O(m * n)
    int orangesRotting(vector<vector<int>>& grid) {
        int l_time = 0;
        int l_num_fresh = 0;
        int l_len_r = grid.size();
        int l_len_c = grid[0].size();
        int l_r, l_c;
        queue<vector<int>> q_coord;
        vector<int> vec_coord;
        vector<vector<int>> vec2d_dirs = {{1, 0},{-1, 0},{0, 1},{0, -1}};

        for (l_r = 0; l_r < l_len_r; l_r++) {
            for (l_c = 0; l_c < l_len_c; l_c++) {
                if (grid[l_r][l_c] == 1)
                    l_num_fresh++;
                else if (grid[l_r][l_c] == 2)
                    q_coord.push({l_r, l_c});
            }
        }

        while (q_coord.size() && l_num_fresh) {
            int l_size_q = q_coord.size();
            for (int l_cnt_element = 0; l_cnt_element < l_size_q; l_cnt_element++) {
                vec_coord = q_coord.front();
                q_coord.pop();

                for (auto vec_dir : vec2d_dirs) {
                    l_r = vec_coord[0] + vec_dir[0];
                    l_c = vec_coord[1] + vec_dir[1];

                    if ((l_r < 0) || (l_r >= l_len_r)
                        || (l_c < 0) || (l_c >= l_len_c)
                        || (grid[l_r][l_c] != 1))
                        continue;
                    
                    grid[l_r][l_c] = 2;
                    l_num_fresh--;
                    q_coord.push({l_r, l_c});
                }
            }
            l_time++;
        }
        return l_num_fresh ? -1 : l_time;
    }
};
// @lc code=end

