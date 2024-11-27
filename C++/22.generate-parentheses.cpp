/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        backtrace(rst, "", n, 0, 0);
        return rst;
    }

private:
    void backtrace(vector<string> &rst, string s_cur, int n, int l_num_left, int l_num_right) {
        if (l_num_left == n && l_num_right == n) {
            rst.push_back(s_cur);
            return;
        }
        
        if (l_num_left < n)
            backtrace(rst, s_cur + "(", n, l_num_left + 1, l_num_right);
        if (l_num_left > l_num_right)
            backtrace(rst, s_cur + ")", n, l_num_left, l_num_right + 1);        
    }
};
// @lc code=end

