/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    // // Brute force
    // // time O(m * n)
    // // space O(1)
    // int islandPerimeter(vector<vector<int>>& grid) {
    //     int ir, len_r = grid.size();
    //     int ic, len_c = grid[0].size();
    //     int perimeter = 0;

    //     for (ir = 0; ir < len_r; ir++)
    //         for (ic = 0; ic < len_c; ic++)
    //             if (grid[ir][ic] == 1)
    //                 perimeter += pixel_perimeter(grid, ir, ic);
    //     return perimeter;
    // }
    // inline int pixel_perimeter(vector<vector<int>>& grid, int ir, int ic) {
    //     int perimeter = 0;
    //     if ((ir == 0) || (ir != 0 && grid[ir - 1][ic] == 0)) perimeter++;
    //     if ((ic == 0) || (ic != 0 && grid[ir][ic - 1] == 0)) perimeter++;
    //     if ((ir == grid.size() - 1) || (ir != grid.size() - 1 && grid[ir + 1][ic] == 0)) perimeter++;
    //     if ((ic == grid[0].size() - 1) || (ic != grid[0].size() - 1 && grid[ir][ic + 1] == 0)) perimeter++;
    //     return perimeter;
    // }


    // DFS
    // time O(m * n)
    // space O(max(m, n))
    int islandPerimeter(vector<vector<int>>& grid) {

    }
};
// @lc code=end

