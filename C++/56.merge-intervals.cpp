/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // time O(nlogn), space O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size())
            return intervals;

        int idx_merge = 0;

        sort(intervals.begin(), intervals.end());

        for (int idx = 1; idx < intervals.size(); idx++) {
            if (intervals[idx_merge][1] < intervals[idx][0]) {
                idx_merge++;
                intervals[idx_merge] = intervals[idx];
            }
            else
                intervals[idx_merge][1] = max(intervals[idx_merge][1], intervals[idx][1]);
        }

        intervals.resize(idx_merge + 1);

        return intervals;
    }

    // // time O(nlogn), space O(n)
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     if (!intervals.size())
    //         return intervals;

    //     vector<vector<int>> vec2d_rst;

    //     sort(intervals.begin(), intervals.end());

    //     vec2d_rst.push_back({intervals[0]});

    //     for (int idx = 1; idx < intervals.size(); idx++) {
    //         if (vec2d_rst.back()[1] < intervals[idx][0])
    //             vec2d_rst.push_back(intervals[idx]);
    //         else
    //             vec2d_rst.back()[1] = max(vec2d_rst.back()[1], intervals[idx][1]);
    //     }
    //     return vec2d_rst;
    // }
};
// @lc code=end

