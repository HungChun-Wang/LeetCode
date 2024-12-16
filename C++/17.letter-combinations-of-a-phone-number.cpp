/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(l ^ d), space O(d), l = length of letter, d = length of digits
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vec_rst;

        if (digits.size() == 0)
            return vec_rst;
        
        this->s_digits = digits;
        size_digits = digits.size();
        this->vec_letter_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(vec_rst, "", 0);
        return vec_rst;
    }
private:
    vector<string> vec_letter_map;
    string s_digits;
    int size_digits;

    void backtracking(vector<string>& vec_rst, string s_curr, int idx_digit) {
        if (idx_digit == this->size_digits) {
            vec_rst.push_back(s_curr);
            return;
        }

        int l_idx_map = this->s_digits[idx_digit] - '0';

        for (int idx_letter = 0; idx_letter < vec_letter_map[l_idx_map].size(); idx_letter++) {
            s_curr.push_back(vec_letter_map[l_idx_map][idx_letter]);
            backtracking(vec_rst, s_curr, idx_digit + 1);
            s_curr.pop_back();
        }
    }
};
// @lc code=end

