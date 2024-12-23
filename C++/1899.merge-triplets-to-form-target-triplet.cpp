/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // gready, time O(n), space O(1)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool b_match_0 = false;
        bool b_match_1 = false;
        bool b_match_2 = false;
        
        for (auto triplet : triplets) {
            if (!b_match_0)
                b_match_0 |= (triplet[0] == target[0]) && (triplet[1] <= target[1]) && (triplet[2] <= target[2]);
            if (!b_match_1)
                b_match_1 |= (triplet[0] <= target[0]) && (triplet[1] == target[1]) && (triplet[2] <= target[2]);
            if (!b_match_2)
                b_match_2 |= (triplet[0] <= target[0]) && (triplet[1] <= target[1]) && (triplet[2] == target[2]);
            if (b_match_0 && b_match_1 && b_match_2) return true;
        }
        return false;
    }
};
// @lc code=end

