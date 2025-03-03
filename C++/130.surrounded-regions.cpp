/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
// dfs, time O(m * n), space O(m * n)
public:
    void solve(vector<vector<char>>& board) {
        int idx_r;
        int idx_c;
        ml_len_r = board.size();
        ml_len_c = board[0].size();
        vector<vector<bool>> vec2d_surround(ml_len_r, vector<bool>(ml_len_c, true));

        for (idx_r = 0; idx_r < ml_len_r; idx_r++) {
            dfs(board, vec2d_surround, idx_r, 0);
            dfs(board, vec2d_surround, idx_r, ml_len_c - 1);
        }

        for (idx_c = 0; idx_c < ml_len_c; idx_c++) {
            dfs(board, vec2d_surround, 0, idx_c);
            dfs(board, vec2d_surround, ml_len_r - 1, idx_c);
        }

        for (idx_r = 0; idx_r < ml_len_r; idx_r++)
            for (idx_c = 0; idx_c < ml_len_c; idx_c++)
                if (board[idx_r][idx_c] == 'O' && vec2d_surround[idx_r][idx_c])
                    board[idx_r][idx_c] = 'X';
    }

private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &vec2d_surround, int idx_r, int idx_c) {
        if (idx_r < 0 || idx_r >= ml_len_r
            || idx_c < 0 || idx_c >= ml_len_c
            || board[idx_r][idx_c] == 'X'
            || !vec2d_surround[idx_r][idx_c])
            return;

        vec2d_surround[idx_r][idx_c] = false;
        dfs(board, vec2d_surround, idx_r + 1, idx_c);
        dfs(board, vec2d_surround, idx_r - 1, idx_c);
        dfs(board, vec2d_surround, idx_r, idx_c + 1);
        dfs(board, vec2d_surround, idx_r, idx_c - 1);
    }

    int ml_len_r;
    int ml_len_c;
};
// @lc code=end

