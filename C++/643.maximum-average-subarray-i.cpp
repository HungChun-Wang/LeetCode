/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

#include <vector>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    // slide window
    // time O(n)
    // space O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int sum_max = INT_MIN;

        for (int i = 0; i < k; i++)
            sum += nums[i];
        sum_max = sum;

        int il = 0;
        int ir = k;
        while (ir < nums.size()) {
            sum -= nums[il++];
            sum += nums[ir++];
            if (sum_max < sum)
                sum_max = sum;
        }
        return (double)sum_max / k;
    }
};
// @lc code=end

