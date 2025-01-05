/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    // bit operation, time O(1), space O(1), l = bit num
    int getSum(int a, int b) {
        int l_carry;

        while (b) {
            l_carry = (a & b) << 1;
            a ^= b;
            b = l_carry;
        }
        return a;
    }
};
// @lc code=end

