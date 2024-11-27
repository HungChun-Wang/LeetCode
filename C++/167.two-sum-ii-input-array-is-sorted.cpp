/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n), space O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l_sum;
        int idx_l = 0;
        int idx_r = numbers.size() - 1;

        while (idx_l < idx_r) {
            l_sum = numbers[idx_l] + numbers[idx_r];

            if (l_sum == target)
                break;
            else if (l_sum > target)
                idx_r--;
            else
                idx_l++;
        }
        return vector<int>{idx_l + 1, idx_r + 1};
    }
};
// @lc code=end

