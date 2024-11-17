/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // sort and map, time O(n + llogl), space O(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        string str_sorted;

        if (strs.empty())
            return ans;

        for (auto str : strs) {
            str_sorted = str;
            sort(str_sorted.begin(), str_sorted.end());
            umap[str_sorted].push_back(str);
        }

        for (auto it_map : umap)
            ans.push_back(it_map.second);

        return ans;
    }
};
// @lc code=end

