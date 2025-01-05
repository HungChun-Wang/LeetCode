/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    // bit operation, time O(n), space O(1)
    int hammingWeight(int n) {
        int l_cnt_one = 0;

        while (n > 0) {
            n &= n - 1;
            l_cnt_one++;
        }

        return l_cnt_one;
    }
};
// @lc code=end

