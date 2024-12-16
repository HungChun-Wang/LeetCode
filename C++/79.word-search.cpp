/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(m * n * 4^l), space O(l), l = word.size()
public:
    bool exist(vector<vector<char>>& board, string word) {
        int x, y;
        this->l_size_y = board.size();
        this->l_size_x = board[0].size();
        this->l_num_target = word.size();
        this->s_target = word;

        for (y = 0; y < l_size_y; y++)
            for (x = 0; x < l_size_x; x++)
                if (board[y][x] == word[0])
                    if (backtracking(board, x, y, 0))
                        return true;
        return false;
    }

private:
    int l_size_x;
    int l_size_y;
    int l_num_target;
    string s_target;

    bool backtracking(vector<vector<char>> &vec2d_board, int l_x, int l_y, int l_num_match) {
        if (l_num_match == l_num_target)
            return true;

        if (l_x < 0 || l_x >= this->l_size_x 
            || l_y < 0 || l_y >= this->l_size_y
            || vec2d_board[l_y][l_x] != this->s_target[l_num_match])
            return false;
        
        l_num_match++;
        char c_temp = vec2d_board[l_y][l_x];
        vec2d_board[l_y][l_x] = '0';

        if (backtracking(vec2d_board, l_x - 1, l_y, l_num_match)
            || backtracking(vec2d_board, l_x + 1, l_y, l_num_match)
            || backtracking(vec2d_board, l_x, l_y - 1, l_num_match)
            || backtracking(vec2d_board, l_x, l_y + 1, l_num_match))
            return true;

        vec2d_board[l_y][l_x] = c_temp;
        return false;
    }
};
// @lc code=end

