/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    // bit operation, time O(1), space O(1)
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
// @lc code=end

