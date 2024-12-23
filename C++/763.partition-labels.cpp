/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    // greedy, time O(n), space O(l), l = char type
    vector<int> partitionLabels(string s) {
        int idx;
        int l_len = 0;
        int idx_label_end = 0;
        vector<int> vec_rst;
        vector<int> vec_last_idx(26);

        for (idx = 0; idx < s.size(); idx++)
            vec_last_idx[s[idx] - 'a'] = idx;
        
        for (idx = 0; idx < s.size(); idx++) {
            l_len++;

            if (idx_label_end < vec_last_idx[s[idx] - 'a'])
                idx_label_end = vec_last_idx[s[idx] - 'a'];
            if (idx == idx_label_end) {
                vec_rst.push_back(l_len);
                l_len = 0;
            }
        }
        return vec_rst;
    }

    // vector<int> partitionLabels(string s) {
    //     int idx;
    //     int l_len = 0;
    //     vector<int> vec_rst;
    //     unordered_map<char, int> umap_freq;
    //     unordered_map<char, int> umap_history;

    //     for (auto c : s)
    //         umap_freq[c - 'a']++;

    //     for (auto c : s) {
    //         idx = c - 'a';
    //         l_len++;
    //         umap_freq[idx]--;

    //         if (umap_freq[idx] == 0) { 
    //             umap_history.erase(idx);
    //             if (umap_history.empty()) {
    //                 vec_rst.push_back(l_len);
    //                 l_len = 0;
    //             }
    //         }
    //         else
    //             umap_history[idx]++;
    //     }
    //     return vec_rst;
    // }
};
// @lc code=end

