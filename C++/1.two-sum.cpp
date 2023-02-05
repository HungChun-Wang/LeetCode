/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    // brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> vec_rst;

        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    vec_rst.push_back(i);
                    vec_rst.push_back(j);
                    return vec_rst;
                }
            }
        }
        return vec_rst;
    }

    // hash table
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int n_idx;
        vector<int> vec_rst;
        unordered_map<int, int> umap;

        // add all to hash table
        for (i = 0; i < nums.size(); i++)
            umap.insert({nums[i], i});
        
        // find complement value, then add index to result vector
        for (i = 0; i < nums.size(); i++) {
            n_idx = target - nums[i];

            // not found
            if (umap.find(n_idx) == umap.end())
                continue;

            // skip self
            if (umap[n_idx] == i)
                continue;

            // add to result vectorS
            vec_rst.push_back(i);
            vec_rst.push_back(umap[n_idx]);
            break;
        }
        return vec_rst;
    }
};
// @lc code=end

