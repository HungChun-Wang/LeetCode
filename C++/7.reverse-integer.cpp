/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <climits>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long int o_rst = 0;
        int l_digit;

        while (x) {
            l_digit = x % 10;
            x /= 10;
            o_rst = o_rst * 10 + l_digit;

            if (o_rst > (INT_MAX - 1)) return 0;
            if (o_rst < INT_MIN) return 0;
        }
        return o_rst;
    }
};
// @lc code=end

