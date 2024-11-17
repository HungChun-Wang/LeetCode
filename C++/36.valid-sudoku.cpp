/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start

#define MAX_ROW         (9)
#define MAX_COL         (9)
#define MAX_BLK_ROW     (3)
#define MAX_BLK_COL     (3)
#define MAX_BLK         (MAX_BLK_ROW * MAX_BLK_COL)
#define NUM_TYPE        (9)

class Solution {
public:
    // // set, suit to sparse case, time O(row * col), space O((row + col) * num)
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     unordered_set<string> uset;
    //     int idx_row, idx_col;
    //     char c_num;
    //     string s_num;
    //     string s_num_row, s_num_col, s_num_blk;

    //     for (idx_row = 0; idx_row < MAX_ROW; idx_row++) {
    //         for (idx_col = 0; idx_col < MAX_COL; idx_col++) {
    //             c_num = board[idx_row][idx_col];
    //             if (c_num == '.')
    //                 continue;

    //             s_num = to_string(c_num);
    //             s_num_row = "r" + s_num + to_string(idx_row);
    //             s_num_col = "c" + s_num + to_string(idx_col);
    //             s_num_blk = "b" + s_num + to_string(idx_row / MAX_BLK_ROW) + to_string(idx_col / MAX_BLK_COL);

    //             if (uset.count(s_num_row) || uset.count(s_num_col) || uset.count(s_num_blk))
    //                 return false;

    //             uset.insert(s_num_row);
    //             uset.insert(s_num_col);
    //             uset.insert(s_num_blk);
    //         }
    //     }
    //     return true;
    // }

    // 3 vector, time O(row * col), space O((row + col) * num)
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> vec_row(MAX_ROW, vector<bool>(NUM_TYPE));
        vector<vector<bool>> vec_col(MAX_COL, vector<bool>(NUM_TYPE));
        vector<vector<bool>> vec_blk(MAX_BLK, vector<bool>(NUM_TYPE));
        int idx_row, idx_col, idx_blk;
        int num;

        for (idx_row = 0; idx_row < MAX_ROW; idx_row++) {
            for (idx_col = 0; idx_col < MAX_COL; idx_col++) {
                if (board[idx_row][idx_col] == '.')
                    continue;
                
                num = board[idx_row][idx_col] - '1';
                idx_blk = MAX_BLK_COL * (idx_row / MAX_BLK_ROW) + (idx_col / MAX_BLK_COL);

                if (vec_row[idx_row][num] || vec_col[idx_col][num] || vec_blk[idx_blk][num])
                    return false;
                
                vec_row[idx_row][num] = true;
                vec_col[idx_col][num] = true;
                vec_blk[idx_blk][num] = true;
            }
        }
        return true;
    }
};
// @lc code=end

