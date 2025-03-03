/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // time O(l), l = len of input string
    // space O(1)
    string licenseKeyFormatting(string s, int k) {
        string rst = "";
        int len_s = s.size();
        int cnt_c = 0;

        for (int i = len_s - 1; i >= 0; i--) {
            if (s[i] == '-') continue;

            if (cnt_c > 0 && cnt_c == k) {
                cnt_c = 0;
                rst += '-';
            }
            cnt_c++;
            rst += toupper(s[i]);
        }
        reverse(rst.begin(), rst.end());

        return rst;
    }
};
// @lc code=end

