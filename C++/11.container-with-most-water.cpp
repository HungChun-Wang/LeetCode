/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // two pointer, time O(n), O(1)
    int maxArea(vector<int>& height) {
        int idx_l = 0;
        int idx_r = height.size() - 1;
        int l_area;
        int l_area_max = 0;

        while (idx_l < idx_r) {
            l_area = min(height[idx_l], height[idx_r]) * (idx_r - idx_l);
            
            if (l_area_max < l_area)
                l_area_max = l_area;
            
            if (height[idx_l] < height[idx_r])
                idx_l++;
            else
                idx_r--;
        }
        return l_area_max;
    }
    
    // // brute force, time O(n^2), O(1)
    // int maxArea(vector<int>& height) {
    //     int i, j, l_area, l_area_max = 0;

    //     for (i = 0; i < height.size() - 1; i++) {
    //         for (j = i + 1; j < height.size(); j++) {
    //             l_area = (j - i) * min(height[i], height[j]);
    //             if (l_area_max < l_area)
    //                 l_area_max = l_area;
    //         }
    //     }
    //     return l_area_max;
    // }
};
// @lc code=end

