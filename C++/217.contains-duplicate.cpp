/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // // hash table, time O(n), space O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (auto num : nums)
            if (umap[num] == 0) 
                umap[num]++;
            else
                return true;
        return false;
    }

    // // Sorting, time O(nlogn), space O(1)
    // bool containsDuplicate(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < nums.size() - 1; i++)
    //         if (nums[i] == nums[i + 1])
    //             return true;
    //     return false;
    // }

    // set, time O(nlogn), space O(n)
    // bool containsDuplicate(vector<int>& nums) {
    //     set<int> num_set(nums.begin(), nums.end());
    //     return num_set.size() < nums.size();
    // }

    // // brute force, time O(n^2), space O(1)
    // bool containsDuplicate(vector<int>& nums) {
    //     int i, j;
    //     for (i = 0; i < nums.size() - 1; i++)
    //         for (j = i + 1; j < nums.size(); j++)
    //             if (nums[i] == nums[j])
    //                 return true;
    //     return false;
    // }
};
// @lc code=end

