/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // time O(n)
    // space O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int cnt_max = 0;

        for (auto num : nums) {
            if (num == 1) {
                cnt++;
                if (cnt > cnt_max)
                    cnt_max = cnt;
            }
            else
                cnt = 0;
        }
        return cnt_max;
    }
};
// @lc code=end

