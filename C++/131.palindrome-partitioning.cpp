/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
// backtracking, time O(l ^ 2), space O(l)
public:
    vector<vector<string>> partition(string s) {
        this->l_size_str = s.size();
        this->s_subject = s;
        vector<vector<string>> vec2d_rst;
        vector<string> vec_cur;
        backtracking(vec2d_rst, vec_cur, 0);
        return vec2d_rst;
    }
private:
    string s_subject;
    int l_size_str;

    bool is_palindrome(string& s, int l_left, int l_right) {
        while(l_left < l_right) {
            if (s[l_left] != s[l_right])
                return false;
            l_left++;
            l_right--;
        }
        return true;
    }

    void backtracking(vector<vector<string>>& vec2d_rst, vector<string>& vec_cur, int l_idx_start) {
        if (l_idx_start == l_size_str) {
            vec2d_rst.push_back(vec_cur);
            return;
        }

        for (int l_idx_end = l_idx_start; l_idx_end < this->l_size_str; l_idx_end++) {
            if (is_palindrome(this->s_subject, l_idx_start, l_idx_end)) {
                vec_cur.push_back(this->s_subject.substr(l_idx_start, l_idx_end - l_idx_start + 1));
                backtracking(vec2d_rst, vec_cur, l_idx_end + 1);
                vec_cur.pop_back();
            }
        }
    }
};
// @lc code=end

