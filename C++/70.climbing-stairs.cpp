/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    // fibonnaci sequence, time O(n), space O(1)
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int l_temp;
        int l_last_one = 1;
        int l_last_two = 1;

        for (int idx = 2; idx <= n; idx++) {
            l_temp = l_last_one;
            l_last_one = l_last_one + l_last_two;
            l_last_two = l_temp;
        }
        return l_last_one;
    }
};
// @lc code=end

