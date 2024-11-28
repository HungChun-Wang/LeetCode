/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include <vector>
#include <algorithm>

using namespace std;


// @lc code=start
#define M_Ceil_Div(x, y) ((x + y - 1) / y)

class Solution {
public:
    // binary search, time O(nlogm), space(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int l_mid;
        int l_low = 1;
        int l_high = *max_element(piles.begin(), piles.end());
        int l_time;

        while (l_low < l_high) {
            l_mid = (l_high + l_low) >> 1;

            l_time = 0;
            for (auto pile : piles)
                l_time += M_Ceil_Div(pile, l_mid);

            if (l_time <= h)
                l_high = l_mid;
            else
                l_low = l_mid + 1;
        }
        return l_low;
    }
};
// @lc code=end

