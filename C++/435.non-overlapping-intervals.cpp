/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
// time O(nlogn), space O(1)
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_condition);

        int l_end_last = INT_MIN;
        int l_cnt_erase = 0;

        for (auto interval : intervals) {
            if (l_end_last <= interval[0])
                l_end_last = interval[1];
            else
                l_cnt_erase++;
        }
        return l_cnt_erase;
    }
private:
    static bool sort_condition(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};
// @lc code=end

