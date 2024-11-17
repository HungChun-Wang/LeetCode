/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    // vector, time O(n), space O(m)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        vector<int> vec_num(26);
        for (auto it : s) vec_num[it - 'a']++;
        for (auto it : t) vec_num[it - 'a']--;
        for (auto num : vec_num)
            if (num != 0)
                return false;
        return true;
    }

    // // sort, time O(nlogn), space O(1)
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }

    // // unorder map, time O(n), space O(n)
    // bool isAnagram(string s, string t) {
    //     unordered_map<char, int> umap;
    //     for (auto it : s) umap[it]++;
    //     for (auto it : t) umap[it]--;
    //     for (auto it : umap)
    //         if (it.second != 0)
    //             return false;
    //     return true;
    // }
};
// @lc code=end

