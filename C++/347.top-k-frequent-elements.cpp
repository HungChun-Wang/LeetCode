/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // hash table and sort, time O(n + k), space O(k)
    static bool pair_cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int m) {
        vector<int> vec_rst;
        vector<pair<int, int>> vec_cnt;
        unordered_map<int, int> umap;

        if (m == 0)
            return vec_rst;
        
        for (auto num : nums)
            umap[num]++;
        
        for (auto it_umap : umap)
            vec_cnt.push_back(it_umap);

        sort(vec_cnt.begin(), vec_cnt.end(), pair_cmp);

        for (auto it_pair : vec_cnt) {
            vec_rst.push_back(it_pair.first);

            if (vec_rst.size() == m)
                break;
        }

        return vec_rst;
    }
};
// @lc code=end

